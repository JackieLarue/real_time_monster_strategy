#ifndef SYSTEM_PHYSICS_H
#define SYSTEM_PHYSICS_H

#include <flecs.h>
#include <raylib.h>
#include "..\components\c_common.h"
#include "..\utils\u_math.h"

void phys_apply_acceleration(ecs_iter_t* it);
void phys_apply_velocity(ecs_iter_t* it);

#endif