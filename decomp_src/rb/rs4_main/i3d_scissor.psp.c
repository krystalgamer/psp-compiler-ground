#include "common.h"
#include "m2c_macros.h"
M2C_UNK iI3dGuDrawSpline_PSP_6ADC0();               /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", CalculateVertexSize);

void ClipCheck()
{
	__asm__ volatile(
		".set noreorder\n"
		"lv.q C000.q,0($4)\n"
		"vabs.s S100.s,S003.s\n"
		"vpfxt x,x,x,0\n"
		"vcmp.t GT,C000.t,C100.t\n"
		"vsync\n"
		"mfvc $6,$131\n"
		"andi $2,$6,0x7\n"
		"vpfxt -x,-x,-x,0\n"
		"vcmp.t LT,C000.t,C100.t\n"
		"vsync\n"
		"mfvc $6,$131\n"
		"ins $2,$6,0x3,0x3\n"
		".set reorder\n"
		: : : "memory");
}

void ScissorInter()
{
	__asm__ volatile(
		"mfc1 $2,$f12\n"
		"lv.q C100.q,0($5)\n"
		"lv.q C110.q,16($5)\n"
		"lv.q C120.q,32($5)\n"
		"lv.q C130.q,48($5)\n"
		"mtv $2,S030.s\n"
		"vmscl.q M100.q,M100.q,S030.s\n"
		"lv.q C200.q,0($6)\n"
		"lv.q C210.q,16($6)\n"
		"lv.q C220.q,32($6)\n"
		"lv.q C230.q,48($6)\n"
		"vocp.s S031.s,S030.s\n"
		"vmscl.q M200.q,M200.q,S031.s\n"
		"vadd.q C100.q,C100.q,C200.q\n"
		"vadd.q C110.q,C110.q,C210.q\n"
		"vadd.q C120.q,C120.q,C220.q\n"
		"vadd.q C130.q,C130.q,C230.q\n"
		"lv.q C200.q,64($5)\n"
		"lv.q C210.q,64($6)\n"
		"vscl.q C200.q,C200.q,S030.s\n"
		"vscl.q C210.q,C210.q,S031.s\n"
		"vadd.q C200.q,C200.q,C210.q\n"
		"sv.q C100.q,0($4)\n"
		"sv.q C110.q,16($4)\n"
		"sv.q C120.q,32($4)\n"
		"sv.q C130.q,48($4)\n"
		"sv.q C200.q,64($4)\n"
		: : : "memory");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", DrawScissorTriangle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", ConvertToFloat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", ConvertColor);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", ConvertToScissorVertex);

void PreCheck()
{
	__asm__ volatile(
		"ins $6,$0,0x0,0x2\n"
		"addu $5,$5,$6\n"
		"lw $7,-12($5)\n"
		"lw $8,-8($5)\n"
		"lw $9,-4($5)\n"
		"mtv $7,S200.s\n"
		"mtv $8,S201.s\n"
		"mtv $9,S202.s\n"
		"vone.s S203.s\n"
		"vtfm4.q C000.q,E300.q,C200.q\n"
		"sv.q C200.q,0($4)\n"
		"sv.q C000.q,64($4)\n"
		"vabs.s S100.s,S003.s\n"
		"vpfxt x,x,x,0\n"
		"vcmp.t GT,C000.t,C100.t\n"
		"vsync\n"
		"mfvc $6,$131\n"
		"andi $2,$6,0x7\n"
		"vpfxt -x,-x,-x,0\n"
		"vcmp.t LT,C000.t,C100.t\n"
		"vsync\n"
		"mfvc $6,$131\n"
		"ins $2,$6,0x3,0x3\n"
		"andi $2,$2,0xff\n"
		: : : "memory");
}

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
