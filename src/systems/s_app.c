#include "s_app.h"

void cleanup_flecs(ecs_world_t* world, void* ctx) {
    //To make the compiler shutup lmao
    world = world;
    ctx = ctx;

    if (IsAudioDeviceReady()) {
        CloseAudioDevice();
    }
    CloseWindow();
}

void flecs_should_close(ecs_iter_t* it) {
    if (WindowShouldClose()) {
        ecs_quit(it->world);
    }
}

void app_systems_manager(ecs_world_t* world) {
    ECS_MODULE(world, app_systems);

    ECS_SYSTEM(world, flecs_should_close, EcsPostUpdate);
}