/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dQtSlerp(int, int, int);                  /* extern */
M2C_UNK I3dVecInterA(int, int, int, float);           /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", GetBlendPosture);

#ifndef NULL
#define NULL ((void *)0)
#endif
float I3mRoot__GetMaxTime(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x18);
}

typedef struct { int a[3]; } I3mNodeAnimX;
typedef struct { float m[12]; } I3mPostureX;
int I3mNodeAnim__GetSectionByTime(I3mNodeAnimX *, int, float);
int I3mSection__GetPostureA(int, I3mPostureX *, float, int, void *);
void I3mRoot__GetMotionA(char *m, I3mPostureX *out, int a2, float t)
{
    int n = *(unsigned short *)(m + 0x14);
    int i;
    for (i = 0; i < n; i++) {
        int s = I3mNodeAnim__GetSectionByTime(&(*(I3mNodeAnimX **)(m + 0x1C))[i], *(int *)(m + 0x24), t);
        I3mSection__GetPostureA(s, &out[i], t, a2, m);
    }
}

void I3mRoot__GetMotionTA(char *m, I3mPostureX *out, float *t, int a2)
{
    int n = *(unsigned short *)(m + 0x14);
    int i;
    for (i = 0; i < n; i++) {
        int s = I3mNodeAnim__GetSectionByTime(&(*(I3mNodeAnimX **)(m + 0x1C))[i], *(int *)(m + 0x24), t[i]);
        I3mSection__GetPostureA(s, &out[i], t[i], a2, m);
    }
}

void GetBlendPosture(I3mPostureX *, void *, I3mNodeAnimX *, float, void *, I3mNodeAnimX *, float, float, int);
void I3mRoot__GetBlendMotionA(char *m, I3mPostureX *out, char *m2, int a3, float f0, float f1, float f2)
{
    int n = *(unsigned short *)(m + 0x14);
    int i;
    for (i = 0; i < n; i++)
        GetBlendPosture(out + i, m, &(*(I3mNodeAnimX **)(m + 0x1C))[i], f0, m2, &(*(I3mNodeAnimX **)(m2 + 0x1C))[i], f1, f2, a3);
}

void I3mRoot__GetBlendMotionBA(char *m, I3mPostureX *out, char *m2, float *w, int a4, float t1, float t2)
{
    int n = *(unsigned short *)(m + 0x14);
    int i;
    for (i = 0; i < n; i++)
        GetBlendPosture(out + i, m, &(*(I3mNodeAnimX **)(m + 0x1C))[i], t1, m2, &(*(I3mNodeAnimX **)(m2 + 0x1C))[i], t2, w[i], a4);
}

void I3mRoot__GetBlendMotionTA(char *m, I3mPostureX *out, float *t1, char *m2, float *t2, int a5, float w)
{
    int n = *(unsigned short *)(m + 0x14);
    int i;
    for (i = 0; i < n; i++)
        GetBlendPosture(out + i, m, &(*(I3mNodeAnimX **)(m + 0x1C))[i], t1[i], m2, &(*(I3mNodeAnimX **)(m2 + 0x1C))[i], t2[i], w, a5);
}

void I3mRoot__GetBlendMotionBTA(char *m, I3mPostureX *out, float *t1, char *m2, float *t2, float *w, int a6)
{
    int n = *(unsigned short *)(m + 0x14);
    int i;
    for (i = 0; i < n; i++)
        GetBlendPosture(out + i, m, &(*(I3mNodeAnimX **)(m + 0x1C))[i], t1[i], m2, &(*(I3mNodeAnimX **)(m2 + 0x1C))[i], t2[i], w[i], a6);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__BlendMotionA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__BlendMotionBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__BlendMotionTA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__BlendMotionBTA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__IsBlendPossible);

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3mPosture__InterPolateA(int arg0, int arg1, int arg2, float fparg0) {
    I3dQtSlerp(arg0 + 0x10, arg1 + 0x10, arg2 + 0x10);
    I3dVecInterA(arg0, arg1, arg2, fparg0);
    I3dVecInterA(arg0 + 0x20, arg1 + 0x20, arg2 + 0x20, fparg0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mPosture__ConvertToMatrixA);
