#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", Set_matWorld_to_Cone);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dViewStatus__GetWorldToViewMatrixA(int arg0) {
    return arg0 + 0xC0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dViewStatus__GetViewToClipMatrixA(int arg0) {
    return arg0 + 0x240;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dViewStatus__GetClipToScreenMatrixA(int arg0) {
    return arg0 + 0x2C0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dViewStatus__GetViewToWorldMatrixA(int arg0) {
    return arg0 + 0x3C0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float Lerp(float fparg0, float fparg1, float fparg2) {
    return fparg0 + ((fparg1 - fparg0) * fparg2);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", Extrapolation);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dViewWindow__Modify);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dViewFrustum__Modify);

void I3dViewRectangular__Modify(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", SetAxisAlignScaleTransMatrices);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", SetClipMatrices);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", SetOrthoClipMatrices);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dViewStatus__ObbClipTestA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dViewStatus__ObbClipTest_SkinMeshA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dViewStatus__SphereClipTestA);

void I3dViewStatus__CreateSortKeyA()
{
	__asm__ volatile(
		"addiu $4,$4,896\n"
		"lv.q C100.q,0($5)\n"
		"lv.q C200.q,0($4)\n"
		"lv.q C210.q,16($4)\n"
		"lv.q C220.q,32($4)\n"
		"lv.q C230.q,48($4)\n"
		"vdot.q S002.s,R202.q,C100.q\n"
		"mfv $2,S002.s\n"
		"mtc1 $2,$f0\n"
		: : : "memory");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dRender__CreateViewStatusA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dRender__CreateOrthoViewStatusA);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", g_avecI3dObbProt);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", D_00109580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", D_001095C0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", ColorFromRGBA4444);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", ColorFromRGBA5551);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", ColorFromRGB565);
