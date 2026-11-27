#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dVecCopyA(int, int);                      /* extern */
M2C_UNK I3rArrayKeyFrameVector4Entity__Solve(int);  /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", BinSearchSection_FloatArray);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", I3rArrayKeyFrameFloatEntity__Solve);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", I3rAnimFloat__Solve);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", I3rArrayKeyFrameVector4Entity__Solve);

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rAnimVector4__Solve(void *arg0, int arg1) {
    int temp_v0;

    temp_v0 = *M2C_FIELD(arg0, int **, 8);
    if (temp_v0 != 0) {
        I3rArrayKeyFrameVector4Entity__Solve(temp_v0);
    } else {
        I3dVecCopyA(arg1, M2C_FIELD(arg0, int *, 0));
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", I3rArrayAnimVector4__Solve);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", I3rArrayAnimVector4__SolveAndMadd);
