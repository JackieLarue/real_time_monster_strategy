#include "s_phys.h"

void phys_apply_acceleration(ecs_iter_t* it) {
    Vel3* v = ecs_field(it, Vel3, 0);
    Accel3* a = ecs_field(it, Accel3, 1);
    f32 dt = it->delta_time;

    for (int i = 0; i < it->count; i++) {
        Vec3fMulAdds(&a[i], dt, &v[i]);
    }
}

void phys_apply_velocity(ecs_iter_t* it) {
    Pos3* p = ecs_field(it, Pos3, 0);
    Vel3* v = ecs_field(it, Vel3, 1);
    f32 dt = it->delta_time;

    for (int i = 0; i < it->count; i++) {
        Vec3fMulAdds(&v[i], dt, &p[i]);
    }
}

void phys_systems_manager(ecs_world_t* world) {
    ECS_MODULE(world, phys_systems);

    ECS_SYSTEM(
        world,
        phys_apply_acceleration,
        UpdateBodies,
        c_common.Vel3,
        c_common.Accel3
    );
    ECS_SYSTEM(
        world,
        phys_apply_velocity,
        UpdateBodies,
        c_common.Pos3,
        c_common.Vel3
    );
}