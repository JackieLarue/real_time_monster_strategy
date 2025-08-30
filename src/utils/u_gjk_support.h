#ifndef UTILITY_GJK_SUPPORT_H
#define UTILITY_GJK_SUPPORT_H

#include <ccd/ccd.h>
#include <ccd/quat.h>
#include <ccd/vec3.h>
//#include <raymath.h>

#include "stdbool.h"
#include "types.h"
#include "vectypes.h"

#define NUMC_MASK (0xffff)
#define CONTACTS_UNIMPORTANT 0x80000000

typedef struct ccd_obj_t {
    ccd_vec3_t pos;
    ccd_quat_t rot, rot_inv;
} ccd_obj_t;

typedef struct ccd_box_t {
    ccd_obj_t o;
    ccd_real_t dim[3];
} ccd_box_t;

typedef struct ccd_cap_t {
    ccd_obj_t o;
    ccd_real_t radius;
    ccd_vec3_t axis;
    ccd_vec3_t p1;
    ccd_vec3_t p2;
} ccd_cap_t;

typedef struct ccd_cyl_t {
    ccd_obj_t o;
    ccd_real_t radius;
    ccd_vec3_t axis;
    ccd_vec3_t p1;
    ccd_vec3_t p2;
} ccd_cyl_t;

typedef struct ccd_sphere_t {
    ccd_obj_t o;
    ccd_real_t radius;
} ccd_sphere_t;

typedef struct ode_convex_t {
    ccd_real_t* planes;
    ccd_real_t* points;
    u32 planeCount;
    u32 pointCount;
    u32 edgeCount;
    ccd_real_t saabb[6]; //static aabb
} ode_convex_t;

typedef struct ccd_convex_t {
    ccd_obj_t o;
    ode_convex_t* convex;
} ccd_convex_t;

typedef struct ccd_triangle_t {
    ccd_obj_t o;
    ccd_vec3_t vertices[3];
} ccd_triangle_t;

typedef struct dxPosR {
    ccd_vec3_t pos;
    Mat3f R;
} dxPosR;

typedef struct dxGeom {
    int type;
    //int gFlags;
    void* data;
    //dxPosR* finalPosR;
    //dxPosR* offsetPosR;
    //the rest are irrelevant
} dxGeom;

typedef struct dxGeom* dGeomID;

typedef struct dContactGeom {
    ccd_vec3_t pos;    /*< contact position*/
    ccd_vec3_t normal; /*< normal vector*/
    ccd_real_t depth;  /*< penetration depth*/
    dGeomID g1, g2;    /*< the colliding geoms*/
} dContactGeom;

typedef enum ShapeType : u8 {
    SHAPE_BOX,
    SHAPE_CAPSULE,
    SHAPE_CYLINDER,
    SHAPE_SPHERE,
    SHAPE_TRIANGLE,
    SHAPE_CONVEX
} ShapeType;

void ccdSupportBox(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v);
void ccdSupportCap(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v);
void ccdSupportCyl(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v);
void ccdSupportSphere(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v);
void ccdSupportConvex(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v);
void ccdSupportTriangle(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v);

ccd_support_fn ccdGetSupportFunc(ShapeType type);

#endif