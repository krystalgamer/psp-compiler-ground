#include "common.h"
#include "m2c_macros.h"
extern float g_I3cIntersectEpsilon;
extern signed char g_bI3cStrictScale;
float I3dcs_GetSqrDistLineSegA(int, int, void *, int, M2C_UNK, M2C_UNK); /* extern */
float I3dcs_GetSqrDistRaySegA(int, int, void *, int, M2C_UNK, M2C_UNK); /* extern */
float I3dcs_GetSqrDistSegSegA(int, int, void *, int, M2C_UNK, M2C_UNK); /* extern */
int I3dcs_GetIntersectLineCylA(int, int, int, int, M2C_UNK, M2C_UNK); /* extern */
int I3dcs_GetIntersectRayCylA(int, int, int, int, M2C_UNK, M2C_UNK); /* extern */
int I3dcs_GetIntersectSegCylA(int, int, int, int, M2C_UNK, M2C_UNK); /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cLineParam_CnvAxis);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", IntersectSub_LineTri);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cLine_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cRay_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cSegment_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cSphere_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersectSub_RadiusPrim);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cRLine_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cRRay_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cCapsule_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_ScanAABB_Node);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_Main);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_SphereA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_LineA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_RayA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_SegmentA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_RLineA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_RRayA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_CapsuleA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cSSS_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cRSS_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_SSSA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_RSSA);

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3cIntersect_SetEpsilon(float fparg0) {
    g_I3cIntersectEpsilon = fparg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

float I3cIntersect_GetEpsilon(void) {
    return g_I3cIntersectEpsilon;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3cIntersect_SetStrictScale(signed char arg0) {
    g_bI3cStrictScale = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

unsigned char I3cIntersect_GetStrictScale(void) {
    return g_bI3cStrictScale;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", CalcBlendRatio);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cCbService_GetIntersectPointParam);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistPointPointA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistPointLineA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistPointRayA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistPointSegA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistLineLineA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistLineRayA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistLineSegA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistRayRayA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistRaySegA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistSegSegA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectSphereBoxA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectSegBoxA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectLineBoxA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectRayBoxA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectCapBoxA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectRRayBoxA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectRLineBoxA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectSphereSphereA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectSphereLineA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectSphereRayA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectSphereSegA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectSphereRLineA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectSphereRRayA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectSphereCapA);

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
int I3dcs_IsIntersectCapLineA(void *arg0, int arg1, int arg2, int arg3) {
    float temp_f20;
    float temp_f20_2;
    int var_v0;

    temp_f20 = M2C_FIELD(arg0, float *, 0xC);
    temp_f20_2 = temp_f20 * temp_f20;
    var_v0 = 1;
    if (!(I3dcs_GetSqrDistLineSegA(arg2, arg3, arg0, arg1, 0, 0) <= temp_f20_2)) {
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
int I3dcs_IsIntersectCapRayA(void *arg0, int arg1, int arg2, int arg3) {
    float temp_f20;
    float temp_f20_2;
    int var_v0;

    temp_f20 = M2C_FIELD(arg0, float *, 0xC);
    temp_f20_2 = temp_f20 * temp_f20;
    var_v0 = 1;
    if (!(I3dcs_GetSqrDistRaySegA(arg2, arg3, arg0, arg1, 0, 0) <= temp_f20_2)) {
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
int I3dcs_IsIntersectCapSegA(void *arg0, int arg1, int arg2, int arg3) {
    float temp_f20;
    float temp_f20_2;
    int var_v0;

    temp_f20 = M2C_FIELD(arg0, float *, 0xC);
    temp_f20_2 = temp_f20 * temp_f20;
    var_v0 = 1;
    if (!(I3dcs_GetSqrDistSegSegA(arg2, arg3, arg0, arg1, 0, 0) <= temp_f20_2)) {
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
int I3dcs_IsIntersectCapRLineA(void *arg0, int arg1, void *arg2, int arg3) {
    float temp_f20;
    int var_v0;

    temp_f20 = M2C_FIELD(arg0, float *, 0xC) + M2C_FIELD(arg2, float *, 0xC);
    var_v0 = 1;
    if (!(I3dcs_GetSqrDistLineSegA(arg2, arg3, arg0, arg1, 0, 0) <= (temp_f20 * temp_f20))) {
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
int I3dcs_IsIntersectCapRRayA(void *arg0, int arg1, void *arg2, int arg3) {
    float temp_f20;
    int var_v0;

    temp_f20 = M2C_FIELD(arg0, float *, 0xC) + M2C_FIELD(arg2, float *, 0xC);
    var_v0 = 1;
    if (!(I3dcs_GetSqrDistRaySegA(arg2, arg3, arg0, arg1, 0, 0) <= (temp_f20 * temp_f20))) {
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectCapCapA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetIntersectLineSphereA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetIntersectRaySphereA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetIntersectSegSphereA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetIntersectCapSphereA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetIntersectRLineSphereA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetIntersectRRaySphereA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectCylSphereA);

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dcs_IsIntersectCylLineA(int arg0, int arg1, int arg2, int arg3) {
    return I3dcs_GetIntersectLineCylA(arg2, arg3, arg0, arg1, 0, 0) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dcs_IsIntersectCylRayA(int arg0, int arg1, int arg2, int arg3) {
    return I3dcs_GetIntersectRayCylA(arg2, arg3, arg0, arg1, 0, 0) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dcs_IsIntersectCylSegA(int arg0, int arg1, int arg2, int arg3) {
    return I3dcs_GetIntersectSegCylA(arg2, arg3, arg0, arg1, 0, 0) != 0;
}
