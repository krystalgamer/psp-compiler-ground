#include "common.h"

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", callback_fin);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", get_exp);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", reset_static_value);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSendCommandf);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSendCommandi);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", fonttex);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", initList);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", tbpcmd_tbl);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", tbwcmd_tbl);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", tsizecmd_tbl);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", lcmd);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", color_material);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", D_000313EC);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuInit);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTerm);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuFinishId);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuCallMode);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuBreak);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuContinue);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSendList);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuCheckList);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", D_00031418);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDisable);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuGetStatus);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuGetAllStatus);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSetStatus);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSetAllStatus);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDepthRange);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDepthOffset);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuAmbient);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuColor);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuPatchFrontFace);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", D_00031538);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDebugPrint);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuDebugFlush);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/libgu", sceGuSetCallback);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/libgu", D_00031540);
