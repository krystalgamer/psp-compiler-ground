#include "common.h"
#include "m2c_macros.h"
extern unsigned char D_00109C00;
extern unsigned char D_00109C50;
M2C_UNK sgxFlush();                                 /* extern */
M2C_UNK sgxTickProc(float);                           /* extern */
extern int gSgxMallocFunc;
extern int gSgxFreeFunc;
extern int gSgxPrintFunc;
extern int gSgxDebugFlags;
extern int D_0011FBE4;
extern int D_0011FBE8;
extern int D_0011FBF0;
extern int D_0011FC00;

void I3dVecClearA()
{
	__asm__ volatile(
		"sv.q C720.q,0($4)\n"
		: : : "memory");
}

void I3dMatClearA()
{
	__asm__ volatile(
		"sv.q C720.q,0($4)\n"
		"sv.q C720.q,16($4)\n"
		"sv.q C720.q,32($4)\n"
		"sv.q C720.q,48($4)\n"
		: : : "memory");
}

void I3dVecCopyA()
{
	__asm__ volatile(
		"lv.q C000.q,0($5)\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dMatCopyA()
{
	__asm__ volatile(
		"lv.q C000.q,0($5)\n"
		"lv.q C010.q,16($5)\n"
		"lv.q C020.q,32($5)\n"
		"lv.q C030.q,48($5)\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatUnitA()
{
	__asm__ volatile(
		"vmidt.q M000.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dVecScaleA()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"mfc1 $6,$f12\n"
		"mtv $6,S020.s\n"
		"vscl.q C000.q,C010.q,S020.s\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecScaleXYZA()
{
	__asm__ volatile(
		"lv.q C000.q,0($5)\n"
		"mfc1 $6,$f12\n"
		"mtv $6,S010.s\n"
		"vscl.t C000.t,C000.t,S010.s\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecTransformA()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C110.q,16($5)\n"
		"lv.q C120.q,32($5)\n"
		"lv.q C130.q,48($5)\n"
		"lv.q C200.q,0($6)\n"
		"vtfm4.q C000.q,E100.q,C200.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecAddA()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vadd.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecSubA()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vsub.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecNegA()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vneg.q C000.q,C010.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecMulA()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vmul.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecInterA()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"mfc1 $7,$f12\n"
		"mtv $7,S030.s\n"
		"vocp.s S031.s,S030.s\n"
		"vscl.q C100.q,C010.q,S030.s\n"
		"vscl.q C110.q,C020.q,S031.s\n"
		"vadd.q C000.q,C100.q,C110.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecClampA()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"mfc1 $6,$f12\n"
		"mtv $6,S020.s\n"
		"vpfxt x,x,x,x\n"
		"vmax.q C000.q,C010.q,C020.q\n"
		"mfc1 $6,$f13\n"
		"mtv $6,S030.s\n"
		"vpfxt x,x,x,x\n"
		"vmin.q C000.q,C000.q,C030.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecCrossA()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vcrsp.t C710.t,C010.t,C020.t\n"
		"sv.q C710.q,0($4)\n"
		: : : "memory");
}

void I3dVecDotA()
{
	__asm__ volatile(
		"lv.q C010.q,0($4)\n"
		"lv.q C020.q,0($5)\n"
		"vdot.t S003.s,C010.t,C020.t\n"
		"mfv $6,S003.s\n"
		"mtc1 $6,$f0\n"
		: : : "memory");
}

void I3dVecNormalizeXYZA()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vdot.t S020.s,C010.t,C010.t\n"
		"vrsq.s S021.s,S020.s\n"
		"vscl.t C710.t,C010.t,S021.s\n"
		"sv.q C710.q,0($4)\n"
		: : : "memory");
}

void I3dVecFTOI0A()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vf2iz.q C000.q,C010.q,0\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecFTOI4A()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vf2iz.q C000.q,C010.q,4\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecITOF0A()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vi2f.q C000.q,C010.q,0\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecITOF4A()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vi2f.q C000.q,C010.q,4\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dMatTranslateA()
{
	__asm__ volatile(
		".set noreorder\n"
		"beq $4,$5,1f\n"
		"nop\n"
		".set reorder\n"
		"lv.q C000.q,0($5)\n"
		"lv.q C010.q,16($5)\n"
		"lv.q C020.q,32($5)\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"1:\n"
		"lv.q C030.q,48($5)\n"
		"lv.q C100.q,0($6)\n"
		"vadd.t C030.t,C030.t,C100.t\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatInverseA()
{
	__asm__ volatile(
		"lv.q C000.q,0($5)\n"
		"lv.q C010.q,16($5)\n"
		"lv.q C020.q,32($5)\n"
		"lv.q C030.q,48($5)\n"
		"vmov.q R203.q,C730.q\n"
		"vcrsp.t C120.t,C000.t,C010.t\n"
		"vcrsp.t C100.t,C010.t,C020.t\n"
		"vcrsp.t C110.t,C020.t,C000.t\n"
		"vdot.t S133.s,C120.t,C020.t\n"
		"vrcp.s S133.s,S133.s\n"
		"vscl.t C200.t,R100.t,S133.s\n"
		"vscl.t C210.t,R101.t,S133.s\n"
		"vscl.t C220.t,R102.t,S133.s\n"
		"vdot.t S230.s,C030.t,R200.t\n"
		"vdot.t S231.s,C030.t,R201.t\n"
		"vdot.t S232.s,C030.t,R202.t\n"
		"vneg.t C230.t,C230.t\n"
		"sv.q C200.q,0($4)\n"
		"sv.q C210.q,16($4)\n"
		"sv.q C220.q,32($4)\n"
		"sv.q C230.q,48($4)\n"
		: : : "memory");
}

void I3dMatInverseFastA()
{
	__asm__ volatile(
		"lv.q R000.q,0($5)\n"
		"lv.q R001.q,16($5)\n"
		"lv.q R002.q,32($5)\n"
		"lv.q R003.q,48($5)\n"
		"vdot.t S030.s,R000.t,R003.t\n"
		"vdot.t S031.s,R001.t,R003.t\n"
		"vdot.t S032.s,R002.t,R003.t\n"
		"vneg.t C030.t,C030.t\n"
		"vmov.q R003.q,C730.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatTransposeA()
{
	__asm__ volatile(
		"lv.q R000.q,0($5)\n"
		"lv.q R001.q,16($5)\n"
		"lv.q R002.q,32($5)\n"
		"lv.q R003.q,48($5)\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatMulA()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C110.q,16($5)\n"
		"lv.q C120.q,32($5)\n"
		"lv.q C130.q,48($5)\n"
		"lv.q C200.q,0($6)\n"
		"lv.q C210.q,16($6)\n"
		"lv.q C220.q,32($6)\n"
		"lv.q C230.q,48($6)\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

float sinf(float);
float cosf(float);
void I3dMatRotateXA(float *out, float *in, float ang)
{
	float m[16];
	I3dMatUnitA(m);
	m[5] = cosf(ang);
	m[6] = -sinf(ang);
	m[9] = sinf(ang);
	m[10] = cosf(ang);
	I3dMatMulA(out, m, in);
}

float sinf(float);
float cosf(float);
void I3dMatRotateYA(float *out, float *in, float ang)
{
	float m[16];
	I3dMatUnitA(m);
	m[0] = cosf(ang);
	m[8] = sinf(ang);
	m[2] = -sinf(ang);
	m[10] = cosf(ang);
	I3dMatMulA(out, m, in);
}

float sinf(float);
float cosf(float);
void I3dMatRotateZA(float *out, float *in, float ang)
{
	float m[16];
	I3dMatUnitA(m);
	m[0] = cosf(ang);
	m[1] = -sinf(ang);
	m[4] = sinf(ang);
	m[5] = cosf(ang);
	I3dMatMulA(out, m, in);
}

void I3dMatRotateZYXA(float *out, float *in, float *ang)
{
	I3dMatRotateZA(out, in, ang[2]);
	I3dMatRotateYA(out, out, ang[1]);
	I3dMatRotateXA(out, out, ang[0]);
}

void I3dMatScaleA()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C110.q,16($5)\n"
		"lv.q C120.q,32($5)\n"
		"lv.q C130.q,48($5)\n"
		"lv.q C200.q,0($6)\n"
		"vscl.q C000.q,C100.q,S200.s\n"
		"vscl.q C010.q,C110.q,S201.s\n"
		"vscl.q C020.q,C120.q,S202.s\n"
		"vscl.q C030.q,C130.q,S203.s\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatScaleXYZA()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C110.q,16($5)\n"
		"lv.q C120.q,32($5)\n"
		"lv.q C200.q,0($6)\n"
		"vscl.q C000.q,C100.q,S200.s\n"
		"vscl.q C010.q,C110.q,S201.s\n"
		"vscl.q C020.q,C120.q,S202.s\n"
		"lv.q C030.q,48($5)\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_geom_a", I3dVecRotTransPersA_PS2);

void I3dMatLookAtRHA(float *out, const float *eye, const float *dir, const float *up)
{
	float m[16] __attribute__((aligned(16)));
	float x[4] __attribute__((aligned(16)));
	I3dMatUnitA(m);
	I3dVecCrossA(x, up, dir);
	I3dVecNormalizeXYZA(&m[0], x);
	I3dVecNormalizeXYZA(&m[8], dir);
	I3dVecCrossA(&m[4], &m[8], &m[0]);
	I3dMatTranslateA(m, m, eye);
	I3dMatInverseA(out, m);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *I3dMatGetUnitPtrA(void) {
    return &D_00109C00;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_geom_a", D_00109C00);
