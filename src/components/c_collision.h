#ifndef COMPONENT_COLLISION_H
#define COMPONENT_COLLISION_H

#include <flecs.h>

#include "types.h"
#include "vectypes.h"

typedef struct AABB {
    Vec3f min;
    Vec3f max;
} AABB;

//reference collider:
/*
typedef struct Collider {
    float radius;
    bool correct_position;
    CollisionFilter collision_type;
    CollisionFilter collision_filter;
} Collider;
*/

typedef struct CollisionRecord {
    Vec3f pos;         // contact position
    Vec3f normal;      // normal vector
    f32 depth;         // penetration depth
    ecs_entity_t a, b; // the colliding entities
} CollisionRecord;

typedef struct BPCollisionRecord {
    ecs_entity_t a, b;
} BPCollisionRecord;

typedef struct CollisionRecordList {
    CollisionRecord* records;
    CollisionRecord* significant_collisions;
} CollisionRecordList;

typedef struct BPCollisionRecordList {
    BPCollisionRecord* records;
    BPCollisionRecord* significant_collisions;
} BPCollisionRecordList;

extern ECS_COMPONENT_DECLARE(AABB);
extern ECS_COMPONENT_DECLARE(CollisionRecordList);
extern ECS_COMPONENT_DECLARE(BPCollisionRecordList);

extern ECS_TAG_DECLARE(CollidedBroadPhase);
extern ECS_TAG_DECLARE(CollidedNarrowPhase);
extern ECS_TAG_DECLARE(GenerateManifoldTrue);
extern ECS_TAG_DECLARE(GenerateManifoldFalse);

#endif