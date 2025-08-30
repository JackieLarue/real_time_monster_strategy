#ifndef COMPONENT_COMMON_H
#define COMPONENT_COMMON_H

#include <flecs.h>
#include <raylib.h>

#include "types.h"
#include "vectypes.h"
#include "defines.h"

#include "c_phases.h"

typedef Vec2f Pos2, Vel2, Accel2;
typedef Vec3f Pos3, Vel3, Accel3;

typedef struct BoxSize {
    f32 w, h, l;
} BoxSize;

extern ECS_COMPONENT_DECLARE(Pos2);
extern ECS_COMPONENT_DECLARE(Vel2);
extern ECS_COMPONENT_DECLARE(Accel2);

extern ECS_COMPONENT_DECLARE(Pos3);
extern ECS_COMPONENT_DECLARE(Vel3);
extern ECS_COMPONENT_DECLARE(Accel3);

extern ECS_COMPONENT_DECLARE(BoxSize);

extern ECS_COMPONENT_DECLARE(Color);

extern ECS_TAG_DECLARE(RenderTag);

void c_common_manager(ecs_world_t* world);

#endif