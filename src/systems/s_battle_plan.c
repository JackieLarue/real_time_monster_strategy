#include "s_battle_action.h"

//i dont trust this code. chatgpt wrote it
//so i definitely need to review this stuff

bool enqueue_action(ecs_world_t* world, ecs_entity_t battler, ecs_entity_t action) {
    ActionQueue* q = ecs_get_mut(world, battler, ActionQueue);
    u8 next_tail = (q->tail + 1) % MAX_ACTIONS;
    if (next_tail != q->head) {
        q->actions[q->tail] = action;
        q->tail = next_tail;
        return true;
    } else {
        ecs_delete(world, action); //queue full
        return false;
    }
}

void load_active_plan_to_queue(ecs_world_t* world, ecs_entity_t battler) {
    ActionPlans* plans = ecs_get_mut(world, battler, ActionPlans);
    ActivePlan* ap = ecs_get_mut(world, battler, ActivePlan);
    ActionQueue* queue = ecs_get_mut(world, battler, ActionQueue);

    if (!plans || !ap || !queue || ap->selPlan >= plans->planCount) {
        return;
    }
    ActionPlanEntry* plan = &plans->plans[ap->selPlan];

    for (int i = 0; i < plan->actionCount; i++) {
        int next = (queue->tail + 1) % MAX_ACTIONS;
        if (next == queue->head) {
            break; // full
        }

        queue->actions[queue->tail] = plan->actions[i];
        queue->tail = next;
    }

    ap->curIdx = 0;
}

bool add_action_to_plan(ecs_world_t* world, ecs_entity_t battler, int plan_index, ecs_entity_t action) {
    ActionPlans* plans = ecs_get_mut(world, battler, ActionPlans);
    if (!plans || plan_index >= plans->planCount) {
        return false;
    }
    ActionPlanEntry* entry = &plans->plans[plan_index];
    if (entry->actionCount >= MAX_ACTIONS) {
        return false;
    }
    entry->actions[entry->actionCount++] = action;
    return true;
}

int create_new_plan(ecs_world_t* world, ecs_entity_t battler) {
    ActionPlans* plans = ecs_get_mut(world, battler, ActionPlans);
    if (!plans || plans->planCount >= MAX_PLANS)
        return -1;

    int new_index = plans->planCount++;
    plans->plans[new_index].actionCount = 0;
    return new_index;
}

void select_plan(ecs_world_t* world, ecs_entity_t battler, int plan_index) {
    ActivePlan* ap = ecs_get_mut(world, battler, ActivePlan);
    if (!ap) return;

    ap->selPlan = plan_index;
    ap->override = false;

    // Optionally flush old queue:
    ActionQueue* q = ecs_get_mut(world, battler, ActionQueue);
    if (q) q->head = q->tail = 0;

    load_active_plan_to_queue(world, battler);
}

void override_with_action(ecs_world_t* world, ecs_entity_t battler, ecs_entity_t action) {
    ActivePlan* ap = ecs_get_mut(world, battler, ActivePlan);
    if (ap) ap->override = true;

    ActionQueue* q = ecs_get_mut(world, battler, ActionQueue);
    if (!q) return;

    q->head = q->tail = 0;
    enqueue_action(world, battler, action);
}