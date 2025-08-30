#include "s_gfx.h"

void gfx_loop(ecs_iter_t* it) {
    Pos3* p = ecs_field(it, Pos3, 0);
    BoxSize* bs = ecs_field(it, BoxSize, 1);
    Color* c = ecs_field(it, Color, 2);

    DrawGrid(100, 1.0f);
    for (int i = 0; i < it->count; i++) {
        DrawCube(VEC3_CAST(p[i]), bs[i].w, bs[i].h, bs[i].l, c[i]);
    }
}

void gfx_frame_start(ecs_iter_t* it) {
    Camera3D* camera = ecs_field(it, Camera3D, 0);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(*camera);
}

void gfx_frame_end(ecs_iter_t* it) {
    it = it;

    EndMode3D();
    EndDrawing();
}

void gfx_systems_manager(ecs_world_t* world) {
    ECS_MODULE(world, gfx_systems);

    ECS_COMPONENT(world, Camera3D);
    ecs_singleton_set(
        world,
        Camera3D,
        {
            .position = (Vector3) { 0.0f, 10.0f, 10.0f },
            .target = (Vector3) { 0.0f, 0.0f, 0.0f },
            .up = (Vector3) { 0.0f, 1.0f, 0.0f },
            .fovy = 45.0f,
            .projection = CAMERA_PERSPECTIVE,
        }
    );

    ecs_entity_t PreDraw = ecs_new_w_id(world, EcsPhase);
    ecs_entity_t PostDraw = ecs_new_w_id(world, EcsPhase);
    ecs_entity_t LoopDraw = ecs_new_w_id(world, EcsPhase);

    ecs_add_pair(world, PreDraw, EcsDependsOn, EcsOnStore);
    ecs_add_pair(world, LoopDraw, EcsDependsOn, PreDraw);
    ecs_add_pair(world, PostDraw, EcsDependsOn, LoopDraw);

    ECS_SYSTEM(world, gfx_frame_start, PreDraw, Camera3D);
    ECS_SYSTEM(world, gfx_frame_end, PostDraw, 0);

    ECS_SYSTEM(
        world,
        gfx_loop,
        LoopDraw,
        c_common.Pos3,
        c_common.BoxSize,
        c_common.Color,
        c_common.RenderTag
    );
}