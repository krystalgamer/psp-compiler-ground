#include "common.h"
#include "m2c_macros.h"
M2C_UNK iI3dGuDrawSpline_PSP_6ADC0();               /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", CalculateVertexSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", ClipCheck);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", ScissorInter);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", DrawScissorTriangle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", ConvertToFloat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", ConvertColor);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", ConvertToScissorVertex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", PreCheck);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", DrawScissorTriangles);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", D_00109620);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", D_00109630);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dDrawArrayWithScissor_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuMaterial_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuColor_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuClutMode_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuClutLoad_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuAlphaFunc_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuAmbient_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableLighting_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableFog_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableDither_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableBlend_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableAlphaTest_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableDepthTest_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableStencilTest_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableLight_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableScissor_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableTexture_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexFlush_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexMode_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexFilter_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexFunc_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexWrap_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexEnvColor_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexImage_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexMapMode_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexProjMapMode_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexOffset_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexScale_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuSetMatrix_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuSetBoneMatrixIndex_PSP);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *I3dGuSetBoneMatrix_PSP(void *arg0, void *arg1) {
    M2C_FIELD(arg0, int *, 0) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 0) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 4) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 4) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 8) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 8) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 0xC) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 0x10) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 0x10) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 0x14) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 0x14) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 0x18) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 0x18) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 0x20) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 0x1C) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 0x24) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 0x20) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 0x28) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 0x24) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 0x30) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 0x28) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 0x34) >> 8) | 0x2B000000);
    M2C_FIELD(arg0, int *, 0x2C) = (int) (((unsigned int) M2C_FIELD(arg1, unsigned int *, 0x38) >> 8) | 0x2B000000);
    return arg0 + 0x30;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *I3dGuBoneMatrix_PSP(void *arg0, int arg1, void *arg2) {
    void *temp_a3;

    M2C_FIELD(arg0, int *, 0) = (int) ((arg1 * 0xC) | 0x2A000000);
    temp_a3 = arg0 + 4;
    M2C_FIELD(arg0, int *, 4) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 0) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 4) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 4) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 8) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 8) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 0xC) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 0x10) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 0x10) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 0x14) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 0x14) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 0x18) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 0x18) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 0x20) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 0x1C) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 0x24) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 0x20) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 0x28) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 0x24) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 0x30) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 0x28) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 0x34) >> 8) | 0x2B000000);
    M2C_FIELD(temp_a3, int *, 0x2C) = (int) (((unsigned int) M2C_FIELD(arg2, unsigned int *, 0x38) >> 8) | 0x2B000000);
    return arg0 + 0x34;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuDrawArray_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuPatchDivide_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuPatchPrim_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuDrawBezier_PSP);

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dGuDrawSpline_PSP(void) {
    iI3dGuDrawSpline_PSP_6ADC0();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuLightMode_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuLight_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuLightSpot_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuLightColor_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuDepthRange_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuDepthOffset_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuOffset_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuViewport_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuScissor_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuBlendFunc_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuSpecular_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuFog_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuRet_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuCall_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuJump_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnd_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuSignal_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuBeginObject_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEndObject_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuGetMemory_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuPixelMask_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuStencilOp_PSP);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", D_0010966C);
