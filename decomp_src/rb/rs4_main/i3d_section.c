#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", UnpackKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", UnpackKey2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", UnpackSection);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", g_MatHermite);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3mSectionSub_InterPosture);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3mSection__GetPostureA);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3mNodeAnim__GetName(int *arg0) {
    return *arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned short I3mNodeAnim__Get_nSection(void *arg0) {
    return M2C_FIELD(arg0, unsigned short *, 6);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3mNodeAnim__GetSectionByTime);

void I3dQtMul()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vqmul.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dQtLog()
{
	__asm__ volatile(
		".set noreorder\n"
		"lv.q C010.q,0($5)\n"
		"vasin.s S021.s,S013.s\n"
		"vmul.s S021.s,S021.s,S702.s\n"
		"vsub.s S022.s,S702.s,S021.s\n"
		"vmul.s S022.s,S022.s,S703.s\n"
		"vsin.s S023.s,S022.s\n"
		"vcmp.s LE,S023.s,S720.s\n"
		"bvtl 0,1f\n"
		"sv.q C720.q,0($4)\n"
		"vdiv.s S020.s,S022.s,S023.s\n"
		"vscl.t C710.t,C010.t,S020.s\n"
		"sv.q C710.q,0($4)\n"
		"1:\n"
		".set reorder\n"
		: : : "memory");
}

void I3dQtExp()
{
	__asm__ volatile(
		".set noreorder\n"
		"lv.q C010.q,0($5)\n"
		"vdot.t S020.s,C010.t,C010.t\n"
		"vrsq.s S021.s,S020.s\n"
		"vcmp.s LE,S021.s,S720.s\n"
		"bvtl 0,1f\n"
		"sv.q C730.q,0($4)\n"
		"vmul.s S022.s,S021.s,S703.s\n"
		"vsin.s S023.s,S022.s\n"
		"vdiv.s S020.s,S023.s,S021.s\n"
		"vscl.t C000.t,C010.t,S020.s\n"
		"vcos.s S003.s,S022.s\n"
		"sv.q C000.q,0($4)\n"
		"1:\n"
		".set reorder\n"
		: : : "memory");
}

void I3dQtDotProduct()
{
	__asm__ volatile(
		"lv.q C010.q,0($4)\n"
		"lv.q C020.q,0($5)\n"
		"vdot.q S003.s,C010.q,C020.q\n"
		"mfv $6,S003.s\n"
		"mtc1 $6,$f0\n"
		: : : "memory");
}

void I3dQtNormalize()
{
	__asm__ volatile(
		"lv.q C010.q,0($5)\n"
		"vdot.q S020.s,C010.q,C010.q\n"
		"vrsq.s S021.s,S020.s\n"
		"vscl.q C000.q,C010.q,S021.s\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

extern const float D_001096CC;
void I3dQtSlerp(float *out, const float *p, const float *q, float t)
{
	float c;

	__asm__ volatile(
		"lv.q C010.q,0(%1)\n"
		"lv.q C020.q,0(%2)\n"
		"vdot.q S003.s,C010.q,C020.q\n"
		"vsge.s S002.s,S003.s,S720.s\n"
		"vsge.s S001.s,S003.s,S720.s\n"
		"vadd.s S000.s,S001.s,S002.s\n"
		"vsub.s S000.s,S000.s,S733.s\n"
		"vmul.s S003.s,S003.s,S000.s\n"
		"vscl.q C010.q,C010.q,S000.s\n"
		"mfv $6,S003.s\n"
		"mtc1 $6,%0\n"
		"mtv %3,S000.s\n"
		"vocp.s S001.s,S000.s\n"
		: "=f"(c) : "r"(p), "r"(q), "r"(t) : "$6", "memory");
	if (c < D_001096CC) {
		__asm__ volatile(
			"vasin.s S031.s,S003.s\n"
			"vmul.s S031.s,S031.s,S702.s\n"
			"vsub.s S100.s,S702.s,S031.s\n"
			"vmul.s S101.s,S100.s,S000.s\n"
			"vmul.s S102.s,S100.s,S001.s\n"
			"vscl.t C110.t,C100.t,S703.s\n"
			"vsin.t C120.t,C110.t\n"
			"vrcp.s S130.s,S120.s\n"
			"vscl.q C010.q,C010.q,S121.s\n"
			"vscl.q C020.q,C020.q,S122.s\n"
			"vadd.q C010.q,C010.q,C020.q\n"
			: : : "memory");
	} else {
		__asm__ volatile(
			"vscl.q C010.q,C010.q,S000.s\n"
			"vscl.q C020.q,C020.q,S001.s\n"
			"vadd.q C010.q,C010.q,C020.q\n"
			"vdot.q S020.s,C010.q,C010.q\n"
			"vrsq.s S130.s,S020.s\n"
			: : : "memory");
	}
	__asm__ volatile(
		"vscl.q C000.q,C010.q,S130.s\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(out) : "memory");
}

const float D_001096CC = 0.9f;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3dQtLerp);
