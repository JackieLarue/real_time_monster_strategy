#ifndef SYSTEM_APPLICATION_H
#define SYSTEM_APPLICATION_H

#include <flecs.h>
#include <raylib.h>
#include <stdio.h>

void cleanup_flecs(ecs_world_t* world, void* ctx);
void flecs_should_close(ecs_iter_t* it);

void app_systems_manager(ecs_world_t* world);

#endif