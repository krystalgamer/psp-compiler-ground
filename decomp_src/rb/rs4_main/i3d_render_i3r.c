/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3dRenderStage__RenderI3r_SolidGroup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3dRenderStage__RenderI3r_SkinGroup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMeshInstance__MakeMorphInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", iI3dGuSetMatrix_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3dRenderStage__RenderI3r_MaterialOperationGroup__Solid);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3dRenderStage__RenderI3r_MaterialOperationGroup__SoftBind);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3dRenderStage__RenderI3r_MaterialOperationGroup__RigidBind);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMaterialOperationGroup__DrawClusters__FullSpec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMaterialOperationGroup__DrawClusters__VertexAnimOff_Solid_SortOff_ClipOn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMaterialOperationGroup__DrawClusters__VertexAnimOff_Solid_SortOn_ClipOn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMaterialOperationGroup__DrawClusters__VertexAnimOff_RigidBind_SortOff_ClipOn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMaterialOperationGroup__DrawClusters__VertexAnimOff_RigidBind_SortOn_ClipOn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", MakePresetPacket_SendScissorStrip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", iI3dPkDrawLayers_ScissorOn);
