#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_qt_opr", I3dQtSlerpNoInv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_qt_opr", I3dQtSquad);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_qt_opr", I3dQtToMatrix);

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
