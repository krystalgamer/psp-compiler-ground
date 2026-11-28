/* cflags: -O2 -fno-strict-aliasing */
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

typedef struct { int p0; float (*mats)[16]; int p1; unsigned short p2; unsigned short num; } I3dSkinMesh;
int I3dViewStatus__ObbClipTestA(void *, float *);
int I3dViewStatus__ObbClipTest_SkinMeshA(void *vs, unsigned short **pidx, I3dSkinMesh *mesh, float *obb, float (*bones)[16])
{
	float m[16] __attribute__((aligned(16)));
	unsigned int i, n = mesh->num;
	float (*mats)[16] = mesh->mats;
	unsigned short *idx = *pidx;

	for (i = 0; i < n; i++) {
		__asm__ volatile(
			"lv.q C100.q,0(%0)\n"
			"lv.q C110.q,16(%0)\n"
			"lv.q C120.q,32(%0)\n"
			"lv.q C130.q,48(%0)\n"
			"lv.q C200.q,0(%1)\n"
			"lv.q C210.q,16(%1)\n"
			"lv.q C220.q,32(%1)\n"
			"lv.q C230.q,48(%1)\n"
			"vmmul.q M300.q,M100.q,M200.q\n"
			: : "r"(bones[idx[i]]), "r"(mats[i]) : "memory");
		if (i == 0) {
			__asm__ volatile(
				"vmov.q C010.q,C330.q\n"
				"vmov.q C020.q,C330.q\n"
				: : : "memory");
		}
		__asm__ volatile(
			"vpfxs -w,-w,-w,w\n"
			"vmov.q C000.q,C730.q\n"
			"vtfm4.q C100.q,E300.q,C000.q\n"
			"vpfxs w,-w,-w,w\n"
			"vmov.q C000.q,C730.q\n"
			"vtfm4.q C110.q,E300.q,C000.q\n"
			"vpfxs -w,w,-w,w\n"
			"vmov.q C000.q,C730.q\n"
			"vtfm4.q C120.q,E300.q,C000.q\n"
			"vpfxs w,w,-w,w\n"
			"vmov.q C000.q,C730.q\n"
			"vtfm4.q C130.q,E300.q,C000.q\n"
			"vpfxs -w,-w,w,w\n"
			"vmov.q C000.q,C730.q\n"
			"vtfm4.q C200.q,E300.q,C000.q\n"
			"vpfxs w,-w,w,w\n"
			"vmov.q C000.q,C730.q\n"
			"vtfm4.q C210.q,E300.q,C000.q\n"
			"vpfxs -w,w,w,w\n"
			"vmov.q C000.q,C730.q\n"
			"vtfm4.q C220.q,E300.q,C000.q\n"
			"vpfxs w,w,w,w\n"
			"vmov.q C000.q,C730.q\n"
			"vtfm4.q C230.q,E300.q,C000.q\n"
			"vmax.t C300.t,C100.t,C110.t\n"
			"vmin.t C310.t,C100.t,C110.t\n"
			"vmax.t C320.t,C120.t,C130.t\n"
			"vmin.t C330.t,C120.t,C130.t\n"
			"vmax.t C100.t,C200.t,C210.t\n"
			"vmin.t C110.t,C200.t,C210.t\n"
			"vmax.t C120.t,C220.t,C230.t\n"
			"vmin.t C130.t,C220.t,C230.t\n"
			"vmax.t C200.t,C300.t,C320.t\n"
			"vmin.t C210.t,C310.t,C330.t\n"
			"vmax.t C220.t,C100.t,C120.t\n"
			"vmin.t C230.t,C110.t,C130.t\n"
			"vmax.t C100.t,C200.t,C220.t\n"
			"vmin.t C110.t,C210.t,C230.t\n"
			"vmax.t C010.t,C010.t,C100.t\n"
			"vmin.t C020.t,C020.t,C110.t\n"
			: : : "memory");
	}
	__asm__ volatile(
		"vsub.q C100.q,C010.q,C020.q\n"
		"vadd.q C110.q,C010.q,C020.q\n"
		"mtv %0,S030.s\n"
		"vscl.q C100.q,C100.q,S030.s\n"
		"vscl.q C110.q,C110.q,S030.s\n"
		"vone.s S113.s\n"
		"lv.q C200.q,0(%1)\n"
		"lv.q C210.q,16(%1)\n"
		"lv.q C220.q,32(%1)\n"
		"lv.q C230.q,48(%1)\n"
		"vscl.q C300.q,C200.q,S100.s\n"
		"vscl.q C310.q,C210.q,S101.s\n"
		"vscl.q C320.q,C220.q,S102.s\n"
		"vtfm4.q C330.q,E200.q,C110.q\n"
		"sv.q C300.q,0(%2)\n"
		"sv.q C310.q,16(%2)\n"
		"sv.q C320.q,32(%2)\n"
		"sv.q C330.q,48(%2)\n"
		: : "r"(0x3f000000), "r"(obb), "r"(m) : "memory");
	return I3dViewStatus__ObbClipTestA(vs, m);
}

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
