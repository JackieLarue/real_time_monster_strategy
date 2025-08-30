#ifndef COMPONENT_INPUT_H
#define COMPONENT_INPUT_H

#include <flecs.h>
#include <raylib.h>
#include "types.h"
#include "vectypes.h"

typedef struct Input {
    bool quit;
    bool select;
    bool drag;
    bool togglePause;
    bool toggleDebug;
    bool toggleFullscreen;
    Vec2f joystick;
    Vec2f mousePosVec;
    Vec2i mousePosPix;
} Input;

extern ECS_COMPONENT_DECLARE(Input);

#endif