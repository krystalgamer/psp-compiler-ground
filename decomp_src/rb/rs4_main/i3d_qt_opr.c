/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"


extern const float D_001096D4;
extern const float D_001096D8;
void I3dQtSlerpNoInv(float *out, const float *p, const float *q, float t)
{
	float c;

	__asm__ volatile(
		"lv.q C010.q,0(%1)\n"
		"lv.q C020.q,0(%2)\n"
		"vdot.q S003.s,C010.q,C020.q\n"
		"mfv $6,S003.s\n"
		"mtc1 $6,%0\n"
		"mtv %3,S030.s\n"
		"vocp.s S031.s,S030.s\n"
		: "=f"(c) : "r"(p), "r"(q), "r"(t) : "$6", "memory");
	if (c < D_001096D4 || D_001096D8 < c) {
		__asm__ volatile(
			"vscl.q C100.q,C010.q,S030.s\n"
			"vscl.q C110.q,C020.q,S031.s\n"
			: : : "memory");
	} else {
		__asm__ volatile(
			"vasin.s S032.s,S003.s\n"
			"vmul.s S032.s,S032.s,S702.s\n"
			"vsub.s S100.s,S702.s,S032.s\n"
			"vmul.s S101.s,S100.s,S030.s\n"
			"vmul.s S102.s,S100.s,S031.s\n"
			"vscl.t C110.t,C100.t,S703.s\n"
			"vsin.t C120.t,C110.t\n"
			"vrcp.s S130.s,S120.s\n"
			"vscl.q C100.q,C010.q,S121.s\n"
			"vscl.q C110.q,C020.q,S122.s\n"
			"vscl.q C100.q,C100.q,S130.s\n"
			"vscl.q C110.q,C110.q,S130.s\n"
			: : : "memory");
	}
	__asm__ volatile(
		"vadd.q C010.q,C100.q,C110.q\n"
		"vdot.q S032.s,C010.q,C010.q\n"
		"vrsq.s S033.s,S032.s\n"
		"vscl.q C000.q,C010.q,S033.s\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(out) : "memory");
}

const float D_001096D4 = -0.9f;

const float D_001096D8 = 0.9f;

extern const float D_001096DC;
void I3dQtSquad(float *out, const float *p, const float *q, const float *a, const float *b, float t)
{
	float t0[4], t1[4];
	I3dQtSlerpNoInv(t0, p, q, t);
	if (a != b || a[3] != a[3] || a[0] != a[0] || a[1] != a[1] || a[2] != a[2]) {
		I3dQtSlerpNoInv(t1, a, b, t);
		I3dQtSlerpNoInv(out, t1, t0, (t + t) * (D_001096DC - t));
	} else {
		I3dQtSlerpNoInv(out, a, t0, (t + t) * (D_001096DC - t));
	}
}
const float D_001096DC = 1.0f;

void I3dQtToMatrix()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"vadd.t C110.t,C100.t,C100.t\n"
		"vzero.t R003.t\n"
		"vscl.t C200.t,C110.t,S100.s\n"
		"vscl.t C210.t,C110.t,S101.s\n"
		"vscl.t C220.t,C110.t,S102.s\n"
		"vscl.t C230.t,C110.t,S103.s\n"
		"vsub.s S030.s,S733.s,S222.s\n"
		"vadd.s S001.s,S201.s,S232.s\n"
		"vsub.s S002.s,S202.s,S231.s\n"
		"vsub.s S000.s,S030.s,S211.s\n"
		"vsub.s S010.s,S201.s,S232.s\n"
		"vsub.s S011.s,S030.s,S200.s\n"
		"vadd.s S012.s,S212.s,S230.s\n"
		"vsub.s S022.s,S733.s,S200.s\n"
		"vadd.s S020.s,S202.s,S231.s\n"
		"vsub.s S021.s,S212.s,S230.s\n"
		"vsub.s S022.s,S022.s,S211.s\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"addiu $4,$4,48\n"
		"lv.q C000.q,0($6)\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_qt_opr", I3dQtFromMatrix);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_qt_opr", I3dQtGetSplineCP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_qt_opr", I3dQtFromEuler);

#ifndef NULL
#define NULL ((void *)0)
#endif
int strcmp(const char *a, const char *b);
int I3mRoot__CheckIdString(signed char *arg0) {
    return (strcmp(arg0, "I3D_I3M") == 0) ? 0 : 3;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_qt_opr", apfuncI3rAnimVector4_SectionParam__Solve);
