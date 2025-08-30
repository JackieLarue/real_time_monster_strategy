#ifndef SYSTEM_BATTLE_ACTION_H
#define SYSTEM_BATTLE_ACTION_H

#include "types.h"
#include "..\utils\u_math.h"
#include "..\components\c_common.h"
#include "..\components\c_battle_action.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

bool enqueue_action_entity(ActionQueue* q, ecs_entity_t action);

void baction_systems_manager(ecs_world_t* world);

#endif