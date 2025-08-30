#include "m_module.h"

void import_modules(ecs_world_t* world) {
    //Components import
    ECS_IMPORT_M(world, c_common);
    ECS_IMPORT_M(world, c_baction);

    //Phase Import
    ECS_IMPORT_M(world, c_phases);

    //Systems import
    ECS_IMPORT_M(world, app_systems);
    ECS_IMPORT_M(world, battle_main);
    ECS_IMPORT_M(world, gfx_systems);
    ECS_IMPORT_M(world, baction_systems);

}