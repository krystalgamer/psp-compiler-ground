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


void IntersectSubOBBA()
{
	__asm__ volatile(
		"lv.q C010.q,0($4)\n"
		"lv.q C020.q,0($5)\n"
		"lv.q C030.q,0($6)\n"
		"lv.q C100.q,0($7)\n"
		"lv.q C110.q,16($7)\n"
		"lv.q C120.q,32($7)\n"
		"vabs.t C020.t,C020.t\n"
		"vdot.t S000.s,C010.t,C100.t\n"
		"vdot.t S001.s,C010.t,C110.t\n"
		"vdot.t S002.s,C010.t,C120.t\n"
		"vabs.t C000.t,C000.t\n"
		"vcrs.t C300.t,C020.t,C030.t\n"
		"vcrs.t C310.t,C030.t,C020.t\n"
		"vadd.t C320.t,C300.t,C310.t\n"
		"vcmp.t GT,C000.t,C320.t\n"
		".set noreorder\n"
		"bvfl 4,1f\n"
		"li $2,1\n"
		".set reorder\n"
		"li $2,0\n"
		"1:\n"
		"sltiu $2,$2,1\n"
		: : : "memory");
}

void I3dcsSub_ProjectVectorXYZA()
{
	__asm__ volatile(
		"lv.q C010.q,0($6)\n"
		"lv.q C100.q,0($5)\n"
		"lv.q C110.q,16($5)\n"
		"lv.q C120.q,32($5)\n"
		"vdot.t S000.s,C010.t,C100.t\n"
		"vdot.t S001.s,C010.t,C110.t\n"
		"vdot.t S002.s,C010.t,C120.t\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_IsIntersectLineOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_IsIntersectRayOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_IsIntersectSegOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_IsIntersectRLineOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_IsIntersectRRayOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_IsIntersectCapOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_IsIntersectSphereOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_IsIntersectOBBOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", Clip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", BoxClipCheckA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", GetIntersectOBBSubA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_GetIntersectLineOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_GetIntersectRayOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_GetIntersectSegOBBA);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dMatRotateXA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dMatRotateYA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dMatRotateZA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dMatRotateZYXA);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dVecRotTransPersA_PS2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dMatLookAtRHA);

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *I3dMatGetUnitPtrA(void) {
    return &D_00109C00;
}

void I3dGeomInit()
{
	__asm__ volatile(
		"viim.s S701.s,255\n"
		"vcst.s S702.s,VFPU_PI_2\n"
		"vcst.s S703.s,VFPU_2_PI\n"
		"vzero.s S713.s\n"
		"vzero.q C720.q\n"
		"vidt.q C730.q\n"
		: : : "memory");
}

void I3dVecClear()
{
	__asm__ volatile(
		"sv.q C720.q,0($4)\n"
		: : : "memory");
}

void I3dColClear()
{
	__asm__ volatile(
		"sv.q C720.q,0($4)\n"
		: : : "memory");
}

void I3dVecClearW1()
{
	__asm__ volatile(
		"sv.q C730.q,0($4)\n"
		: : : "memory");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dVecSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dColSet);

void I3dMatClear()
{
	__asm__ volatile(
		"sv.q C720.q,0($4)\n"
		"sv.q C720.q,16($4)\n"
		"sv.q C720.q,32($4)\n"
		"sv.q C720.q,48($4)\n"
		: : : "memory");
}

unsigned char I3dVecIsEqual()
{
	register int r __asm__("$2");

	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"move $2,$0\n"
		"vcmp.q EQ,C000.q,C010.q\n"
		".set noreorder\n"
		"bvtl 5,1f\n"
		"li $2,1\n"
		".set reorder\n"
		"1:\n"
		: "=r"(r) : : "memory");
	return r;
}

unsigned char I3dColIsEqual()
{
	register int r __asm__("$2");

	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"move $2,$0\n"
		"vcmp.q EQ,C000.q,C010.q\n"
		".set noreorder\n"
		"bvtl 5,1f\n"
		"li $2,1\n"
		".set reorder\n"
		"1:\n"
		: "=r"(r) : : "memory");
	return r;
}

unsigned char I3dMatIsEqual()
{
	register int r __asm__("$2");

	__asm__ volatile(
		"li $2,1\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C100.q,0($5)\n"
		"vcmp.q EQ,C000.q,C100.q\n"
		".set noreorder\n"
		"bvfl 5,1f\n"
		"li $2,0\n"
		".set reorder\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C110.q,16($5)\n"
		"vcmp.q EQ,C010.q,C110.q\n"
		".set noreorder\n"
		"bvfl 5,1f\n"
		"li $2,0\n"
		".set reorder\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C120.q,32($5)\n"
		"vcmp.q EQ,C020.q,C120.q\n"
		".set noreorder\n"
		"bvfl 5,1f\n"
		"li $2,0\n"
		".set reorder\n"
		"lv.q C030.q,48($4)\n"
		"lv.q C130.q,48($5)\n"
		"vcmp.q EQ,C030.q,C130.q\n"
		".set noreorder\n"
		"bvfl 5,1f\n"
		"li $2,0\n"
		".set reorder\n"
		"1:\n"
		: "=r"(r) : : "memory");
	return r;
}

void I3dVecCopy()
{
	__asm__ volatile(
		"lv.q C000.q,0($5)\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dColCopy()
{
	__asm__ volatile(
		"lv.q C000.q,0($5)\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dMatCopy()
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

void I3dMatSet()
{
	__asm__ volatile(
		"lv.q C000.q,0($5)\n"
		"lv.q C010.q,0($6)\n"
		"lv.q C020.q,0($7)\n"
		"lv.q C030.q,0($8)\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatUnit()
{
	__asm__ volatile(
		"vmidt.q M000.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dVecScale()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"mfc1 $6,$f12\n"
		"mtv $6,S020.s\n"
		"vscl.q C000.q,C010.q,S020.s\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dColScale()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"mfc1 $6,$f12\n"
		"mtv $6,S020.s\n"
		"vscl.q C000.q,C010.q,S020.s\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecScaleXYZ()
{
	__asm__ volatile(
		"lv.q C000.q,0($5)\n"
		"mfc1 $6,$f12\n"
		"mtv $6,S010.s\n"
		"vscl.t C000.t,C000.t,S010.s\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecTransform()
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

void I3dVecAdd()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vadd.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dColAdd()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vadd.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecSub()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vsub.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dColSub()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vsub.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecMul()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vmul.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dColMul()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vmul.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecNeg()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vneg.q C000.q,C010.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecInter()
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

void I3dColInter()
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

void I3dVecClamp()
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

void I3dColClamp()
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

void I3dColPackA8B8G8R8()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"vsat0.q C000.q,C000.q\n"
		"vscl.q C000.q,C000.q,S701.s\n"
		"vf2iz.q C000.q,C000.q,23\n"
		"vi2uc.q S000.s,C000.q\n"
		"mfv $2,S000.s\n"
		: : : "memory");
}

void I3dVecCross()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vcrsp.t C710.t,C010.t,C020.t\n"
		"sv.q C710.q,0($4)\n"
		: : : "memory");
}

void I3dVecDot()
{
	__asm__ volatile(
		"lv.q C010.q,0($4)\n"
		"lv.q C020.q,0($5)\n"
		"vdot.t S003.s,C010.t,C020.t\n"
		"mfv $6,S003.s\n"
		"mtc1 $6,$f0\n"
		: : : "memory");
}

void I3dVecLengthXYZ()
{
	__asm__ volatile(
		"lv.q C010.q,0($4)\n"
		"vdot.t S003.s,C010.t,C010.t\n"
		"vsqrt.s S003.s,S003.s\n"
		"mfv $6,S003.s\n"
		"mtc1 $6,$f0\n"
		: : : "memory");
}

void I3dVecNormalizeXYZ()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vdot.t S020.s,C010.t,C010.t\n"
		"vrsq.s S021.s,S020.s\n"
		"vscl.t C710.t,C010.t,S021.s\n"
		"sv.q C710.q,0($4)\n"
		: : : "memory");
}

void I3dVecFTOI0()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vf2iz.q C000.q,C010.q,0\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecFTOI4()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vf2iz.q C000.q,C010.q,4\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecITOF0()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vi2f.q C000.q,C010.q,0\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecITOF4()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vi2f.q C000.q,C010.q,4\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dMatTranslate()
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

void I3dMatInverse()
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

void I3dMatInverseFast()
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

void I3dMatTranspose()
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

void I3dMatMul()
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

void I3dMatRotateX()
{
	__asm__ volatile(
		"lv.q C200.q,0($5)\n"
		"lv.q C210.q,16($5)\n"
		"lv.q C220.q,32($5)\n"
		"lv.q C230.q,48($5)\n"
		"mfc1 $6,$f12\n"
		"mtv $6,S301.s\n"
		"vmul.s S300.s,S301.s,S703.s\n"
		"vmidt.q M100.q\n"
		"vrot.q C110.q,S300.s,[0,c,s,0]\n"
		"vrot.q C120.q,S300.s,[0,-s,c,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatRotateY()
{
	__asm__ volatile(
		"lv.q C200.q,0($5)\n"
		"lv.q C210.q,16($5)\n"
		"lv.q C220.q,32($5)\n"
		"lv.q C230.q,48($5)\n"
		"mfc1 $6,$f12\n"
		"mtv $6,S301.s\n"
		"vmul.s S300.s,S301.s,S703.s\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S300.s,[c,0,-s,0]\n"
		"vrot.q C120.q,S300.s,[s,0,c,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatRotateZ()
{
	__asm__ volatile(
		"lv.q C200.q,0($5)\n"
		"lv.q C210.q,16($5)\n"
		"lv.q C220.q,32($5)\n"
		"lv.q C230.q,48($5)\n"
		"mfc1 $6,$f12\n"
		"mtv $6,S301.s\n"
		"vmul.s S300.s,S301.s,S703.s\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S300.s,[c,s,0,0]\n"
		"vrot.q C110.q,S300.s,[-s,c,0,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatRotateZYX()
{
	__asm__ volatile(
		"move $2,$6\n"
		"lv.q C200.q,0($5)\n"
		"lv.q C210.q,16($5)\n"
		"lv.q C220.q,32($5)\n"
		"lv.q C230.q,48($5)\n"
		"lv.q C300.q,0($2)\n"
		"vscl.t C300.t,C300.t,S703.s\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S302.s,[c,s,0,0]\n"
		"vrot.q C110.q,S302.s,[-s,c,0,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S301.s,[c,0,-s,0]\n"
		"vrot.q C120.q,S301.s,[s,0,c,0]\n"
		"vmmul.q M200.q,M100.q,M000.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C110.q,S300.s,[0,c,s,0]\n"
		"vrot.q C120.q,S300.s,[0,-s,c,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatRotateZXY()
{
	__asm__ volatile(
		"move $2,$6\n"
		"lv.q C200.q,0($5)\n"
		"lv.q C210.q,16($5)\n"
		"lv.q C220.q,32($5)\n"
		"lv.q C230.q,48($5)\n"
		"lv.q C300.q,0($2)\n"
		"vscl.t C300.t,C300.t,S703.s\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S302.s,[c,s,0,0]\n"
		"vrot.q C110.q,S302.s,[-s,c,0,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C110.q,S300.s,[0,c,s,0]\n"
		"vrot.q C120.q,S300.s,[0,-s,c,0]\n"
		"vmmul.q M200.q,M100.q,M000.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S301.s,[c,0,-s,0]\n"
		"vrot.q C120.q,S301.s,[s,0,c,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatRotateXYZ()
{
	__asm__ volatile(
		"move $2,$6\n"
		"lv.q C200.q,0($5)\n"
		"lv.q C210.q,16($5)\n"
		"lv.q C220.q,32($5)\n"
		"lv.q C230.q,48($5)\n"
		"lv.q C300.q,0($2)\n"
		"vscl.t C300.t,C300.t,S703.s\n"
		"vmidt.q M100.q\n"
		"vrot.q C110.q,S300.s,[0,c,s,0]\n"
		"vrot.q C120.q,S300.s,[0,-s,c,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S301.s,[c,0,-s,0]\n"
		"vrot.q C120.q,S301.s,[s,0,c,0]\n"
		"vmmul.q M200.q,M100.q,M000.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S302.s,[c,s,0,0]\n"
		"vrot.q C110.q,S302.s,[-s,c,0,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatRotateXZY()
{
	__asm__ volatile(
		"move $2,$6\n"
		"lv.q C200.q,0($5)\n"
		"lv.q C210.q,16($5)\n"
		"lv.q C220.q,32($5)\n"
		"lv.q C230.q,48($5)\n"
		"lv.q C300.q,0($2)\n"
		"vscl.t C300.t,C300.t,S703.s\n"
		"vmidt.q M100.q\n"
		"vrot.q C110.q,S300.s,[0,c,s,0]\n"
		"vrot.q C120.q,S300.s,[0,-s,c,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S302.s,[c,s,0,0]\n"
		"vrot.q C110.q,S302.s,[-s,c,0,0]\n"
		"vmmul.q M200.q,M100.q,M000.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S301.s,[c,0,-s,0]\n"
		"vrot.q C120.q,S301.s,[s,0,c,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatRotateYXZ()
{
	__asm__ volatile(
		"move $2,$6\n"
		"lv.q C200.q,0($5)\n"
		"lv.q C210.q,16($5)\n"
		"lv.q C220.q,32($5)\n"
		"lv.q C230.q,48($5)\n"
		"lv.q C300.q,0($2)\n"
		"vscl.t C300.t,C300.t,S703.s\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S301.s,[c,0,-s,0]\n"
		"vrot.q C120.q,S301.s,[s,0,c,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C110.q,S300.s,[0,c,s,0]\n"
		"vrot.q C120.q,S300.s,[0,-s,c,0]\n"
		"vmmul.q M200.q,M100.q,M000.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S302.s,[c,s,0,0]\n"
		"vrot.q C110.q,S302.s,[-s,c,0,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatRotateYZX()
{
	__asm__ volatile(
		"move $2,$6\n"
		"lv.q C200.q,0($5)\n"
		"lv.q C210.q,16($5)\n"
		"lv.q C220.q,32($5)\n"
		"lv.q C230.q,48($5)\n"
		"lv.q C300.q,0($2)\n"
		"vscl.t C300.t,C300.t,S703.s\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S301.s,[c,0,-s,0]\n"
		"vrot.q C120.q,S301.s,[s,0,c,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C100.q,S302.s,[c,s,0,0]\n"
		"vrot.q C110.q,S302.s,[-s,c,0,0]\n"
		"vmmul.q M200.q,M100.q,M000.q\n"
		"vmidt.q M100.q\n"
		"vrot.q C110.q,S300.s,[0,c,s,0]\n"
		"vrot.q C120.q,S300.s,[0,-s,c,0]\n"
		"vmmul.q M000.q,M100.q,M200.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void I3dMatScale()
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

void I3dMatScaleXYZ()
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

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", D_00109C00);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dVecRotTransPers_PS2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dMatLookAtRH);

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *I3dMatGetUnitPtr(void) {
    return &D_00109C50;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", D_00109C50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", D_00109C90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", D_00109C94);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxPrintfPref);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxPrintf);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", D_00109CA8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxMalloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxNextToken);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxNextLine);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxGetLineCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxConfReadStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxConfReadInt);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sgxStrCpyN(unsigned char *arg0, unsigned char *arg1, int arg2) {
    int temp_a2;
    int var_a3;
    unsigned char *var_a0;
    unsigned char *var_a1;
    unsigned char var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v0 = *var_a1;
    var_a3 = 0;
    if (var_v0 != 0) {
        temp_a2 = arg2 - 1;
        if (temp_a2 > 0) {
loop_2:
            *var_a0 = var_v0;
            var_a1 += 1;
            var_a3 += 1;
            var_v0 = *var_a1;
            var_a0 += 1;
            if (var_v0 != 0) {
                if (var_a3 < temp_a2) {
                    goto loop_2;
                }
            }
        }
    }
    *var_a0 = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);

void sgxStrCatN(signed char *arg0, int arg1, int arg2) {
    unsigned int temp_v0;

    temp_v0 = strlen(arg0);
    sgxStrCpyN(&arg0[temp_v0], arg1, arg2 - temp_v0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxIsStrMatch);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxIsStrMatchWC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxIsStrIncWC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxListArrayInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxListEnumID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxAttrSetValueSafe);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxAttrSetUpdateSafe);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxAttrCopyUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxAttrCopyEnable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxAttrMergeEnable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxStackMemOpen);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sgxStackMemClose(void *arg0) {
    return M2C_FIELD(arg0, int *, 4) + M2C_FIELD(arg0, int *, 8);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxStackMemAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxStackMemAllocStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxStackMemAlign);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", D_00109CE0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxFlush);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxTickProc);

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
void sgxProc(float fparg0) {
    sgxFlush();
    sgxTickProc(fparg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetMallocFunc(int arg0) {
    int temp_v0;

    temp_v0 = gSgxMallocFunc;
    gSgxMallocFunc = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetFreeFunc(int arg0) {
    int temp_v0;

    temp_v0 = gSgxFreeFunc;
    gSgxFreeFunc = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetPrintFunc(int arg0) {
    int temp_v0;

    temp_v0 = gSgxPrintFunc;
    gSgxPrintFunc = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetDebugFlags(int arg0) {
    int temp_v0;

    temp_v0 = gSgxDebugFlags;
    gSgxDebugFlags = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetDebugFlags(void) {
    return gSgxDebugFlags;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxSetMainThreadID);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetMainThreadID(void) {
    return D_0011FBE4;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxSetSyncMode);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetSyncMode(void) {
    return D_0011FBE8;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxSetOutputMode);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetOutputMode(void) {
    return D_0011FBF0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxIsOutputSurround(void) {
    return D_0011FC00;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", sgxCent128ToPitch);
