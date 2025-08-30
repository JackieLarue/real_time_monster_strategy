#ifndef UTILITY_MATH_H
#define UTILITY_MATH_H

#include "types.h"
#include "vectypes.h"
#include <math.h>

void Vec3fCopy(Vec3f* source, Vec3f* target);
void Vec3fAdd(Vec3f* a, Vec3f* b, Vec3f* dest);
void Vec3fMulAdds(Vec3f* add, f32 s, Vec3f* dest);

#endif