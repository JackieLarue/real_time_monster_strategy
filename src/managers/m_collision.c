#include "..\components\c_collision.h"
#include "..\components\c_phases.h"
#include "..\systems\s_collision.h"
#include "flecs/addons/flecs_c.h"

ECS_COMPONENT_DECLARE(AABB);
ECS_COMPONENT_DECLARE(CollisionRecordList);
ECS_COMPONENT_DECLARE(BPCollisionRecordList);

ECS_TAG_DECLARE(CollidedBroadPhase);
ECS_TAG_DECLARE(CollidedNarrowPhase);
ECS_TAG_DECLARE(GenerateManifoldTrue);
ECS_TAG_DECLARE(GenerateManifoldFalse);

ECS_SYSTEM_DECLARE(col_bvh_intersect);

void c_collision_manager(ecs_world_t* world) {
    ECS_MODULE(world, c_collision);

    ECS_COMPONENT_DEFINE(world, AABB);
    ECS_COMPONENT_DEFINE(world, CollisionRecordList);
    ECS_COMPONENT_DEFINE(world, BPCollisionRecordList);

    ecs_singleton_set(world, CollisionRecordList, { nullptr, nullptr });

    ECS_TAG_DEFINE(world, GenerateManifoldTrue);
    ECS_TAG_DEFINE(world, GenerateManifoldFalse);
    ECS_TAG_DEFINE(world, CollidedBroadPhase);
    ECS_TAG_DEFINE(world, CollidedNarrowPhase);
}

void s_collision_manager(ecs_world_t* world) {
    ECS_MODULE(world, s_collision);

    ECS_SYSTEM_DEFINE(
        world,
        col_bvh_intersect,
        CollisionDetection,
        c_collision.BPCollisionRecordList($),
        c_collision.AABB
    );
}