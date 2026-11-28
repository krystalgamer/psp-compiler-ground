/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK iI3dGuDrawSpline_PSP_6ADC0();               /* extern */
typedef union {
    unsigned int w;
    struct { unsigned int b0:8, b1:8, b2:8, cmd:8; } f8;
} I3dGeCmd;


extern int g_I3dGuEmuWork[];
unsigned int *I3dGuDepthRange_PSP(unsigned int *, int, int);
#define INS __builtin_allegrex_ins

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

unsigned int *I3dGuClutMode_PSP(unsigned int *p, int cpsm, int shift, int mask, int a3)
{
    unsigned int v = 0xC5000000 | cpsm;
    v = __builtin_allegrex_ins(v, shift, 2, 5);
    v = __builtin_allegrex_ins(v, mask, 8, 8);
    v = __builtin_allegrex_ins(v, a3, 16, 5);
    *p = v;
    return p + 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuClutLoad_PSP);

unsigned int *I3dGuAlphaFunc_PSP(unsigned int *p, int func, int value, int mask)
{
    unsigned int v = 0xDB000000 | func;
    v = __builtin_allegrex_ins(v, value, 8, 8);
    v = __builtin_allegrex_ins(v, mask, 16, 8);
    *p = v;
    return p + 1;
}

unsigned int *I3dGuAmbient_PSP(unsigned int *p, unsigned int color)
{
    unsigned int v = 0x5C000000;
    v = __builtin_allegrex_ins(v, color, 0, 24);
    color >>= 24;
    p[0] = v;
    p[1] = 0x5D000000 | color;
    return p + 2;
}

unsigned int *I3dGuEnableLighting_PSP(unsigned int *p, int flag)
{
    *p = 0x17000000 | flag;
    return p + 1;
}

unsigned int *I3dGuEnableFog_PSP(unsigned int *p, int flag)
{
    *p = 0x1F000000 | flag;
    return p + 1;
}

unsigned int *I3dGuEnableDither_PSP(unsigned int *p, int flag)
{
    *p = 0x20000000 | flag;
    return p + 1;
}

unsigned int *I3dGuEnableBlend_PSP(unsigned int *p, int flag)
{
    *p = 0x21000000 | flag;
    return p + 1;
}

unsigned int *I3dGuEnableAlphaTest_PSP(unsigned int *p, int flag)
{
    *p = 0x22000000 | flag;
    return p + 1;
}

unsigned int *I3dGuEnableDepthTest_PSP(unsigned int *p, int flag)
{
    *p = 0x23000000 | flag;
    return p + 1;
}

unsigned int *I3dGuEnableStencilTest_PSP(unsigned int *p, int flag)
{
    *p = 0x24000000 | flag;
    return p + 1;
}

unsigned int *I3dGuEnableLight_PSP(unsigned int *p, int light, int flag)
{
    *p = ((light + 0x18) << 24) | flag;
    return p + 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEnableScissor_PSP);

unsigned int *I3dGuEnableTexture_PSP(unsigned int *p, int flag)
{
    *p = 0x1E000000 | flag;
    return p + 1;
}

unsigned int *I3dGuTexFlush_PSP(unsigned int *p)
{
    *p = 0xCB000000;
    return p + 1;
}

unsigned int *I3dGuTexMode_PSP(unsigned int *p, int tpsm, int maxmips, int a2, int swizzle)
{
    unsigned int v = 0xC2000000 | swizzle;
    v = __builtin_allegrex_ins(v, a2, 8, 1);
    v = __builtin_allegrex_ins(v, maxmips, 16, 3);
    p[0] = v;
    p[1] = 0xC3000000 | tpsm;
    p[2] = 0xCB000000;
    return p + 3;
}

unsigned int *I3dGuTexFilter_PSP(unsigned int *p, int x, int y)
{
    unsigned int v = 0xC6000000 | x;
    v = __builtin_allegrex_ins(v, y, 8, 1);
    *p = v;
    return p + 1;
}

unsigned int *I3dGuTexFunc_PSP(unsigned int *p, int x, int y, int z)
{
    unsigned int v = 0xC9000000 | x;
    v = __builtin_allegrex_ins(v, y, 8, 1);
    v = __builtin_allegrex_ins(v, z, 16, 1);
    *p = v;
    return p + 1;
}

unsigned int *I3dGuTexWrap_PSP(unsigned int *p, int x, int y)
{
    unsigned int v = 0xC7000000 | x;
    v = __builtin_allegrex_ins(v, y, 8, 1);
    *p = v;
    return p + 1;
}

unsigned int *I3dGuTexEnvColor_PSP(unsigned int *p, unsigned int color)
{
    unsigned int v = 0xCA000000;
    v = __builtin_allegrex_ins(v, color, 0, 24);
    *p = v;
    return p + 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexImage_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuTexMapMode_PSP);

unsigned int *I3dGuTexProjMapMode_PSP(unsigned int *p, int mode)
{
    unsigned int v;
    g_I3dGuEmuWork[0x28 / 4] = mode;
    v = g_I3dGuEmuWork[0x24 / 4] | 0xC0000000;
    v = INS(v, mode, 8, 2);
    *p = v;
    return p + 1;
}

unsigned int *I3dGuTexOffset_PSP(unsigned int *p, float u, float v)
{
    p[0] = 0x4A000000 | (*(unsigned int *)&u >> 8);
    p[1] = 0x4B000000 | (*(unsigned int *)&v >> 8);
    return p + 2;
}

unsigned int *I3dGuTexScale_PSP(unsigned int *p, float u, float v)
{
    p[0] = 0x48000000 | (*(unsigned int *)&u >> 8);
    p[1] = 0x49000000 | (*(unsigned int *)&v >> 8);
    return p + 2;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuSetMatrix_PSP);

unsigned int *I3dGuSetBoneMatrixIndex_PSP(unsigned int *p, int index)
{
    *p = 0x2A000000 | (index * 12);
    return p + 1;
}

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

unsigned int *I3dGuPatchDivide_PSP(unsigned int *p, int x, int y)
{
    unsigned int v = 0x36000000 | x;
    v = __builtin_allegrex_ins(v, y, 8, 7);
    *p = v;
    return p + 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuPatchPrim_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuDrawBezier_PSP);

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dGuDrawSpline_PSP(void) {
    iI3dGuDrawSpline_PSP_6ADC0();
}

unsigned int *I3dGuLightMode_PSP(unsigned int *p, int flag)
{
    *p = 0x5E000000 | flag;
    return p + 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuLight_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuLightSpot_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuLightColor_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuDepthRange_PSP);

unsigned int *I3dGuDepthOffset_PSP(unsigned int *p, int off)
{
    g_I3dGuEmuWork[0x14 / 4] = off;
    return I3dGuDepthRange_PSP(p, g_I3dGuEmuWork[0x18 / 4], g_I3dGuEmuWork[0x1C / 4]);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuOffset_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuViewport_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuScissor_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuBlendFunc_PSP);

unsigned int *I3dGuSpecular_PSP(unsigned int *p, float power)
{
    *p = 0x5B000000 | (*(unsigned int *)&power >> 8);
    return p + 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuFog_PSP);

unsigned int *I3dGuRet_PSP(unsigned int *p)
{
    *p = 0x0B000000;
    return p + 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuCall_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuJump_PSP);

unsigned int *I3dGuEnd_PSP(unsigned int *p)
{
    *p = 0x0C000000;
    return p + 1;
}

unsigned int *I3dGuSignal_PSP(unsigned int *p, int behavior, int signal)
{
    unsigned int v = 0x0E000000 | (signal & 0xFFFF);
    v = __builtin_allegrex_ins(v, behavior, 16, 8);
    p[0] = v;
    p[1] = 0x0C000000;
    return p + 2;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuBeginObject_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuEndObject_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", I3dGuGetMemory_PSP);

unsigned int *I3dGuPixelMask_PSP(unsigned int *p, unsigned int mask)
{
    unsigned int v = 0xE8000000;
    v = __builtin_allegrex_ins(v, mask, 0, 24);
    mask >>= 24;
    p[0] = v;
    p[1] = 0xE9000000 | mask;
    return p + 2;
}

unsigned int *I3dGuStencilOp_PSP(unsigned int *p, int x, int y, int z)
{
    unsigned int v = 0xDD000000 | x;
    v = __builtin_allegrex_ins(v, y, 8, 3);
    v = __builtin_allegrex_ins(v, z, 16, 3);
    *p = v;
    return p + 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_scissor.psp", D_0010966C);
