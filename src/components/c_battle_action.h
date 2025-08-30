#ifndef COMPONENT_BATTLE_ACTION_H
#define COMPONENT_BATTLE_ACTION_H

#include <flecs.h>
#include "types.h"
#include "vectypes.h"
#include "enums.h"

#define MAX_ACTIONS 32
#define MAX_PLANS 8

//Damage formula idea: An component of power can be decided by the force
//of an attack: i.e. the mass of the monster and it's acceleration

//Possible actions:
//Maintain distance from target (parameters: targetidx, f32 distance)
//Use move (parameters: targetidx, others-depends on the move I would think)

//ok so need some system for setting targets and such since that seems to be
//the bulk of the information needed to perform an action

//Action: has target component(s) + additional parameters

typedef struct ActionQueue {
    ecs_entity_t actions[MAX_ACTIONS];
    u8 head;
    u8 tail;
} ActionQueue;

typedef struct ActionPlanEntry {
    ecs_entity_t actions[MAX_ACTIONS];
    u8 actionCount;
} ActionPlanEntry;

typedef struct ActionPlans {
    ActionPlanEntry plans[MAX_PLANS];
    u8 planCount;
} ActionPlans; //may not have this as a component

typedef struct ActivePlan {
    u8 selPlan; //may change this to a relationship
    u8 curIdx;
    bool override;
    //If override == true, the action queue
    //is managed directly. Otherwise, it's
    //filled from the selected plan.
} ActivePlan;

typedef struct CurrentAction {
    ecs_entity_t action;
} CurrentAction;

typedef struct ActKeepDist {
    ecs_entity_t target;
    f32 distance;
} ActKeepDist;

typedef struct ActKeepDistXYZ {
    ecs_entity_t target;
    Vec3f distance;
} ActKeepDistXYZ;

typedef struct ActGoto {
    Vec3f position;
} ActGoto;

extern ECS_COMPONENT_DECLARE(ActionQueue);
extern ECS_COMPONENT_DECLARE(CurrentAction);
extern ECS_COMPONENT_DECLARE(ActionPlanEntry);
extern ECS_COMPONENT_DECLARE(ActionPlans);
extern ECS_COMPONENT_DECLARE(ActivePlan);

extern ECS_COMPONENT_DECLARE(ActKeepDist);
extern ECS_COMPONENT_DECLARE(ActKeepDistXYZ);
extern ECS_COMPONENT_DECLARE(ActGoto);

extern ECS_TAG_DECLARE(ActStateFinished);

void c_baction_manager(ecs_world_t* world);

#endif