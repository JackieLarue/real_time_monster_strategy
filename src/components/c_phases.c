#include "c_phases.h"

ECS_PHASE_DECLARE(UpdateBodies);
ECS_PHASE_DECLARE(CollisionDetection);
ECS_PHASE_DECLARE(CollisionResolution);
ECS_PHASE_DECLARE(CollisionCleanup);

void c_phases_manager(ecs_world_t* world) {
    ECS_MODULE(world, c_phases);

    ECS_PHASE_DEFINE(world, UpdateBodies, EcsOnUpdate);
    ECS_PHASE_DEFINE(world, CollisionDetection, EcsOnUpdate);
    ECS_PHASE_DEFINE(world, CollisionResolution, EcsOnUpdate);
    ECS_PHASE_DEFINE(world, CollisionCleanup, EcsOnUpdate);
}