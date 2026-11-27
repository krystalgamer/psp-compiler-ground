#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_qt_opr", I3dQtSlerpNoInv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_qt_opr", I3dQtSquad);

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
