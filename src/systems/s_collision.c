#include "s_collision.h"

bool test_aabb_aabb(AABB* a, AABB* b) {
    // Exit with no intersection if separated along an axis
    if (a->max.x < b->min.x || a->min.x > b->max.x) return false;
    if (a->max.y < b->min.y || a->min.y > b->max.y) return false;
    if (a->max.z < b->min.z || a->min.z > b->max.z) return false;
    // Overlapping on all axes means AABBs are intersecting
    return true;
}

// Transform AABB a by the matrix m and translation t,
// find maximum extents, and store result into AABB b.
void update_aabb(AABB a, Mat3f m, Vec3f t, AABB* b) {
    for (int i = 0; i < 3; i++) {
        // Start by adding in translation
        b->min.v[i] = b->max.v[i] = t.v[i];
        // Form extent by summing smaller and larger terms respectively
        for (int j = 0; j < 3; j++) {
            f32 e = m[i][j] * a.min.v[j];
            f32 f = m[i][j] * a.max.v[j];
            if (e < f) {
                b->min.v[i] += e;
                b->max.v[i] += f;
            } else {
                b->min.v[i] += f;
                b->max.v[i] += e;
            }
        }
    }
}

void col_bvh_intersect(ecs_iter_t* it) {
    //BPCollisionRecordList* records = ecs_field(it, BPCollisionRecordList, 0);
    AABB* boxes = ecs_field(it, AABB, 1);
    for (int i = 0; i < it->count - 1; i++) {
        bool collided = test_aabb_aabb(&boxes[i], &boxes[i + 1]);
        if (collided) {

        }
    }
}

// void col_find_intersect(ecs_iter_t* it) {
//     ccd_t ccd;
//     CCD_INIT(&ccd);
//     //ccd.support1 = supp1;
//     //ccd.support2 = supp2;
//     ccd.max_iterations = 500;
//     ccd.epa_tolerance = 0.0001;

//     void *obj1, *obj2;
//     if (ccdGJKIntersect(obj1, obj2, &ccd)) {
//         //return 1;
//     } else {
//         //return 0;
//     }
// }

// void col_find_penetrate(ecs_iter_t* it) {
//     ccd_t ccd;
//     int res;
//     ccd_real_t depth;
//     ccd_vec3_t dir, pos;
//     void *obj1, *obj2;
//     ContactGeom* contact;

//     CCD_INIT(&ccd);
//     //ccd.support1 = supp1;
//     //ccd.support2 = supp2;
//     ccd.max_iterations = 500;
//     ccd.epa_tolerance = 0.0001;

//     res = ccdGJKPenetration(obj1, obj2, &ccd, &depth, &dir, &pos);
//     if (res == 0) {
//         contact->g1 = o1;
//         contact->g2 = o2;

//         contact->depth = depth;

//         contact->pos.v[0] = ccdVec3X(&pos);
//         contact->pos.v[1] = ccdVec3Y(&pos);
//         contact->pos.v[2] = ccdVec3Z(&pos);

//         ccdVec3Scale(&dir, -1.);
//         contact->normal.v[0] = ccdVec3X(&dir);
//         contact->normal.v[1] = ccdVec3Y(&dir);
//         contact->normal.v[2] = ccdVec3Z(&dir);

//         return 1;
//     }

//     return 0;
// }