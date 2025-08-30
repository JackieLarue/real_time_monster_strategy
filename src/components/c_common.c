#include "c_common.h"

ECS_COMPONENT_DECLARE(Pos2);
ECS_COMPONENT_DECLARE(Vel2);
ECS_COMPONENT_DECLARE(Accel2);

ECS_COMPONENT_DECLARE(Pos3);
ECS_COMPONENT_DECLARE(Vel3);
ECS_COMPONENT_DECLARE(Accel3);

ECS_COMPONENT_DECLARE(BoxSize);
ECS_COMPONENT_DECLARE(Color);

ECS_TAG_DECLARE(RenderTag);

void c_common_manager(ecs_world_t* world) {
    ECS_MODULE(world, c_common);

    ECS_COMPONENT_DEFINE(world, Pos2);
    ECS_COMPONENT_DEFINE(world, Vel2);
    ECS_COMPONENT_DEFINE(world, Accel2);

    ECS_COMPONENT_DEFINE(world, Pos3);
    ECS_COMPONENT_DEFINE(world, Vel3);
    ECS_COMPONENT_DEFINE(world, Accel3);

    ECS_COMPONENT_DEFINE(world, BoxSize);
    ECS_COMPONENT_DEFINE(world, Color);

    ECS_TAG_DEFINE(world, RenderTag);

}