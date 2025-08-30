#include "u_gjk_support.h"

void ccdSupportBox(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v) {
    const ccd_box_t* o = (const ccd_box_t*)obj;
    ccd_vec3_t dir;

    ccdVec3Copy(&dir, _dir);
    ccdQuatRotVec(&dir, &o->o.rot_inv);

    ccdVec3Set(
        v,
        ccdSign(ccdVec3X(&dir)) * o->dim[0],
        ccdSign(ccdVec3Y(&dir)) * o->dim[1],
        ccdSign(ccdVec3Z(&dir)) * o->dim[2]
    );

    // transform support vertex
    ccdQuatRotVec(v, &o->o.rot);
    ccdVec3Add(v, &o->o.pos);
}

void ccdSupportCap(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v) {
    const ccd_cap_t* o = (const ccd_cap_t*)obj;

    ccdVec3Copy(v, _dir);
    ccdVec3Scale(v, o->radius);

    if (ccdVec3Dot(_dir, &o->axis) > 0.0) {
        ccdVec3Add(v, &o->p1);
    } else {
        ccdVec3Add(v, &o->p2);
    }
}

void ccdSupportCyl(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v) {
    const ccd_cyl_t* cyl = (const ccd_cyl_t*)obj;
    ccd_vec3_t dir;
    ccd_real_t len;

    ccd_real_t dot = ccdVec3Dot(_dir, &cyl->axis);
    if (dot > 0.0) {
        ccdVec3Copy(v, &cyl->p1);
    } else {
        ccdVec3Copy(v, &cyl->p2);
    }
    // project dir onto cylinder's 'top'/'bottom' plane
    ccdVec3Copy(&dir, &cyl->axis);
    ccdVec3Scale(&dir, -dot);
    ccdVec3Add(&dir, _dir);
    len = CCD_SQRT(ccdVec3Len2(&dir));
    if (!ccdIsZero(len)) {
        ccdVec3Scale(&dir, cyl->radius / len);
        ccdVec3Add(v, &dir);
    }
}

void ccdSupportSphere(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v) {
    const ccd_sphere_t* s = (const ccd_sphere_t*)obj;

    ccdVec3Copy(v, _dir);
    ccdVec3Scale(v, s->radius);
    ccdVec3Add(v, &s->o.pos);
}

void ccdSupportConvex(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v) {
    const ccd_convex_t* c = (const ccd_convex_t*)obj;
    ccd_vec3_t dir, p;
    ccd_real_t maxdot, dot;
    u32 i;
    const ccd_real_t* curp;

    ccdVec3Copy(&dir, _dir);
    ccdQuatRotVec(&dir, &c->o.rot_inv);

    maxdot = -CCD_REAL_MAX;
    curp = c->convex->points;
    for (i = 0; i < c->convex->pointCount; i++, curp += 3) {
        ccdVec3Set(&p, curp[0], curp[1], curp[2]);
        dot = ccdVec3Dot(&dir, &p);
        if (dot > maxdot) {
            ccdVec3Copy(v, &p);
            maxdot = dot;
        }
    }

    // transform support vertex
    ccdQuatRotVec(v, &c->o.rot);
    ccdVec3Add(v, &c->o.pos);
}

void ccdSupportTriangle(const void* obj, const ccd_vec3_t* _dir, ccd_vec3_t* v) {
    const ccd_triangle_t* o = (ccd_triangle_t*)obj;
    ccd_real_t maxdot, dot;
    maxdot = -CCD_REAL_MAX;
    for (unsigned i = 0; i != 3; i++) {
        dot = ccdVec3Dot(_dir, &o->vertices[i]);
        if (dot > maxdot) {
            ccdVec3Copy(v, &o->vertices[i]);
            maxdot = dot;
        }
    }
}

ccd_support_fn ccdGetSupportFunc(ShapeType type) {
    switch(type) {
        case SHAPE_BOX: return &ccdSupportBox;
        case SHAPE_CAPSULE: return &ccdSupportCap;
        case SHAPE_CYLINDER: return &ccdSupportCyl;
        case SHAPE_SPHERE: return &ccdSupportSphere;
        case SHAPE_TRIANGLE: return &ccdSupportTriangle;
        case SHAPE_CONVEX: return &ccdSupportConvex;
        default: return NULL;
    }
}