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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__GetMotionA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__GetMotionTA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__GetBlendMotionA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__GetBlendMotionBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__GetBlendMotionTA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_i3m", I3mRoot__GetBlendMotionBTA);

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
