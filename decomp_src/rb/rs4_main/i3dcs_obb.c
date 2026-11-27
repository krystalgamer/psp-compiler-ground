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
