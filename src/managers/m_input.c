#include "..\components\c_input.h"

ECS_COMPONENT_DECLARE(Input);

void c_input_manager(ecs_world_t* world) {
    ECS_MODULE(world, c_input);

    ECS_COMPONENT_DEFINE(world, Input);
}

void s_input_manager(ecs_world_t* world) {
    ECS_MODULE(world, s_input);

}