#ifndef SYSTEM_GFX_H
#define SYSTEM_GFX_H

#include <flecs.h>
#include <raylib.h>
#include "..\components\c_common.h"

void gfx_loop(ecs_iter_t* it);
void gfx_frame_start(ecs_iter_t* it);
void gfx_frame_end(ecs_iter_t* it);

//importer
void gfx_systems_manager(ecs_world_t* world);

#endif