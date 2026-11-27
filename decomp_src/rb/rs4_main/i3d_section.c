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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3dQtMul);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3dQtLog);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3dQtExp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3dQtDotProduct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3dQtNormalize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3dQtSlerp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_section", I3dQtLerp);
