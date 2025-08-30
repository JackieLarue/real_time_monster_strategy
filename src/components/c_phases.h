#ifndef COMPONENT_PHASES_H
#define COMPONENT_PHASES_H

#include <flecs.h>
#include "defines.h"

extern ECS_PHASE_DECLARE(UpdateBodies);
extern ECS_PHASE_DECLARE(CollisionDetection);
extern ECS_PHASE_DECLARE(CollisionResolution);
extern ECS_PHASE_DECLARE(CollisionCleanup);

void c_phases_manager(ecs_world_t* world);

#endif