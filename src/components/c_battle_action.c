#include "c_battle_action.h"

ECS_COMPONENT_DECLARE(ActionQueue);
ECS_COMPONENT_DECLARE(CurrentAction);
ECS_COMPONENT_DECLARE(ActionPlanEntry);
ECS_COMPONENT_DECLARE(ActionPlans);
ECS_COMPONENT_DECLARE(ActivePlan);

ECS_COMPONENT_DECLARE(ActKeepDist);
ECS_COMPONENT_DECLARE(ActKeepDistXYZ);
ECS_COMPONENT_DECLARE(ActGoto);

ECS_TAG_DECLARE(ActStateFinished);

void c_baction_manager(ecs_world_t* world) {
    ECS_MODULE(world, c_baction);

    ECS_COMPONENT_DEFINE(world, ActionQueue);
    ECS_COMPONENT_DEFINE(world, CurrentAction);
    ECS_COMPONENT_DEFINE(world, ActionPlanEntry);
    ECS_COMPONENT_DEFINE(world, ActionPlans);
    ECS_COMPONENT_DEFINE(world, ActivePlan);

    ECS_COMPONENT_DEFINE(world, ActKeepDist);
    ECS_COMPONENT_DEFINE(world, ActKeepDistXYZ);
    ECS_COMPONENT_DEFINE(world, ActGoto);

    ECS_TAG_DEFINE(world, ActStateFinished);
}