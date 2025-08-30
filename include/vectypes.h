#ifndef VEC_TYPES_H
#define VEC_TYPES_H

#include <types.h>

typedef union Vec2f {
   struct { f32 x, y; };
   f32 v[2];
} Vec2f;

typedef union Vec2i {
   struct { s32 x, y; };
   s32 v[2];
} Vec2i;

typedef union Vec3f {
   struct { f32 x, y, z; };
   f32 v[3];
} Vec3f;

typedef union Vec3i {
   struct { s32 x, y, z; };
   s32 v[3];
} Vec3i;

typedef union Vec4f {
   struct { f32 x, y, z, w; };
   f32 v[4];
} Vec4f;

typedef union Vec4i {
   struct { s32 x, y, z, w; };
   s32 v[4];
} Vec4i;

typedef Vec4f Quatf;

typedef f32 Mat3f[3][3];
typedef f32 Mat4f[4][4];

#define VEC2_CAST(vec) (Vector2) { vec.v[0], vec.v[1] }
#define VEC3_CAST(vec) (Vector3) { vec.v[0], vec.v[1], vec.v[2] }
#define VEC4_CAST(vec) (Vector4) { vec.v[0], vec.v[1], vec.v[2], vec.v[3] }

#endif