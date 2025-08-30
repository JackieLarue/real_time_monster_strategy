#include "u_math.h"

void Vec3fCopy(Vec3f* source, Vec3f* target) {
    target->x = source->x;
    target->y = source->y;
    target->z = source->z;
}

void Vec3fAdd(Vec3f* a, Vec3f* b, Vec3f* dest) {
    dest->v[0] = a->v[0] + b->v[0];
    dest->v[1] = a->v[1] + b->v[1];
    dest->v[2] = a->v[2] + b->v[2];
}

void Vec3fMulAdds(Vec3f* add, f32 s, Vec3f* dest) {
    dest->x += add->x * s;
    dest->y += add->y * s;
    dest->z += add->z * s;
}