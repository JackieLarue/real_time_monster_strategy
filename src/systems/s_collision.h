#ifndef SYSTEM_COLLISION_H
#define SYSTEM_COLLISION_H

#include "vectypes.h"
#include "..\components\c_collision.h"

bool test_aabb_aabb(AABB* a, AABB* b);
void update_aabb(AABB a, Mat3f m, Vec3f t, AABB* b);
void col_bvh_intersect(ecs_iter_t* it);

extern ECS_SYSTEM_DECLARE(col_bvh_intersect);

#endif