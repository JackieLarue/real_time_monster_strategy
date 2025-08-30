#include "m_battle_main.h"

void battle_main_manager(ecs_world_t* world) {
    ECS_MODULE(world, battle_main);

    ecs_entity_t e0 = ecs_insert(world, ecs_value(Pos3, { .x = 0.0f, .y = 2.5f, .z = 0.0f }));
    ecs_add(world, e0, RenderTag);
    ecs_set(world, e0, BoxSize, { 2.0f, 5.0f, 2.0f });
    ecs_set(world, e0, Color, RED_);
}