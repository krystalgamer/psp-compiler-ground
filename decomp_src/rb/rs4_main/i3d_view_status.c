#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", Set_matWorld_to_Cone);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dViewStatus__GetWorldToViewMatrixA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dViewStatus__GetViewToClipMatrixA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dViewStatus__GetClipToScreenMatrixA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dViewStatus__GetViewToWorldMatrixA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", Lerp);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dViewStatus__CreateSortKeyA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dRender__CreateViewStatusA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", I3dRender__CreateOrthoViewStatusA);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", g_avecI3dObbProt);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", D_00109580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", D_001095C0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", ColorFromRGBA4444);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", ColorFromRGBA5551);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_view_status", ColorFromRGB565);
