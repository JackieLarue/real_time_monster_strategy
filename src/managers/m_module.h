#ifndef MODULE_IMPORTER_H
#define MODULE_IMPORTER_H

//help autocomplete out
#include <flecs.h>

//component includes
#include "..\components\c_common.h"
#include "..\components\c_battle_action.h"

//system includes
#include "..\systems\s_app.h"
#include "..\systems\s_gfx.h"
#include "..\systems\s_battle_action.h"

//manager includes
#include "m_battle_main.h"

#define ECS_IMPORT_M(world, id) ecs_import_c(world, id##_manager, #id)

void import_modules(ecs_world_t* world);

#endif