#include "s_battle_action.h"

s32 get_base_damage(u8 level, u16 basePower, u16 attack, u16 defense) {
    return (s32)((s32)(((s32)(((2 * level) / 5.0f + 2) * basePower) * attack) / (f32)defense)
                     / 50.0f
                 + 2);
}

bool enqueue_action_entity(ActionQueue* q, ecs_entity_t action) {
    u8 next_tail = (q->tail + 1) % MAX_ACTIONS;
    if (next_tail != q->head) {
        q->actions[q->tail] = action;
        q->tail = next_tail;
        return true;
    } else {
        //ecs_delete(world, action);
        return false;
    }
}

ecs_entity_t create_keep_dist_xyz_action(ecs_world_t* world, ecs_entity_t target, Vec3f distance) {
    ecs_entity_t action = ecs_new(world);
    ecs_set(world, action, ActKeepDistXYZ, { .target = target, .distance = distance });
    return action;
}

void action_processor(ecs_iter_t* it) {
    ActionQueue* queues = ecs_field(it, ActionQueue, 0);
    CurrentAction* currents = ecs_field(it, CurrentAction, 1);

    for (int i = 0; i < it->count; i++) {
        ActionQueue* q = &queues[i];
        CurrentAction* c = &currents[i];

        if (ecs_is_alive(it->world, c->action)) {
            if (ecs_has(it->world, c->action, ActStateFinished)) {
                ecs_delete(it->world, c->action);
            } else {
                continue;
            }
        }

        if (q->head != q->tail) {
            ecs_entity_t action = q->actions[q->head];
            q->head = (q->head + 1) % MAX_ACTIONS;
            c->action = action;
        }
    }
}

void baction_systems_manager(ecs_world_t* world) {
    ECS_MODULE(world, baction_systems);

    ECS_SYSTEM(
        world,
        action_processor,
        EcsOnUpdate,
        c_baction.ActionQueue,
        c_baction.CurrentAction
    );
}