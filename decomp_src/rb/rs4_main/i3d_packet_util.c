#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dPk3dSprite__SetTransformMatrix(int, int); /* extern */
int I3dRenderStage__GetCurrentViewStatus(int);      /* extern */
int I3dViewStatus__GetViewToWorldMatrixA(int);      /* extern */
M2C_UNK iI3dGuDrawSpline_PSP_61A38();               /* extern */
M2C_UNK I3dGuSetMatrix_PSP();                       /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", AddVertexV);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", AddVertexVTU);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", AddVertexCV);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", AddVertexCVTU);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawSpriteF);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawSpriteFTU);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawTriF);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawTriFTU);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawTriG);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawTriGTU);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawLineF);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawLineFTU);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawLineG);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawLineGTU);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawPointF);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawPointFTU);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_SetOffset);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_SetScale);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", CreateArray);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dPrim__SetTransform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dPrim__DrawTriStrip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dPrim__DrawTriStripQ_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dPrim__DrawLineStrip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawSphere);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dSprite__SetTransformMatrix);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dSprite__SetStParam);

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dPk3dSprite__SetBillBoardMatrix(int arg0, int arg1) {
    I3dPk3dSprite__SetTransformMatrix(arg0, I3dViewStatus__GetViewToWorldMatrixA(I3dRenderStage__GetCurrentViewStatus(arg1)));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dSprite__SetBillBoardMatrixWithZoom);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dSprite__Init);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dPk3dSprite__Term(int arg0) {
    return arg0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dSprite__Draw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawScissorStripA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawScissorStripFA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawScissorLineStripA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawScissorLineStripFA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawArray_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawBezier_PSP);

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dPkDrawSpline_PSP(void) {
    iI3dGuDrawSpline_PSP_61A38();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkPatchDivide_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkPatchPrim_PSP);

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dPkSetMatrix_PSP(void) {
    I3dGuSetMatrix_PSP();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawSphereMarkerA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawBoxMarkerA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawObbMarkerA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", iI3dGuDrawSpline_PSP_61A38);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__SetSoftwareScissor_PSP(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x1C0) = (int) (arg1 & 0xFF);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dRenderInitMain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDefaultTermTag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dRender__SetTexBuff_PSP);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_00109170);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_00109200);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_00109210);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_00109220);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aSphereIndex);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aSphereVertex);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aPosTable);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aDefaultArrayTex);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aArrayNoTex);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_001093D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_001093E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aiVtx);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aSkip);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aPosTbl);
