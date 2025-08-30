#ifndef RTMS_MACROS_H
#define RTMS_MACROS_H

#define ECS_PHASE_DECLARE(id) ECS_DECLARE(id)
#define ECS_PHASE_DEFINE(world, id, phase) \
    id = ecs_new_w_id(world, EcsPhase); \
    ecs_add_pair(world, id, EcsDependsOn, phase); \
    ecs_set_name(world, id, #id)

#endif