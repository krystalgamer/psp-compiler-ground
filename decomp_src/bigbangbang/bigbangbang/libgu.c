#include "common.h"

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", callback_fin);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", send_commandi);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", send_commandi_stall);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", send_commandf);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", draw_region);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", get_exp);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", reset_static_value);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSendCommandf);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSendCommandi);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", fonttex);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", initList);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", tbpcmd_tbl);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", tbwcmd_tbl);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", tsizecmd_tbl);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", lcmd);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", color_material);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", D_0000BEE4);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuInit);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTerm);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", D_0000BF10);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", D_0000BF50);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", D_0000BF64);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", D_0000BFBC);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", D_0000C014);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuFinishId);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuCallMode);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuBreak);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuContinue);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSendList);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuCheckList);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDisable);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuGetStatus);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuGetAllStatus);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSetStatus);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSetAllStatus);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDepthRange);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDepthOffset);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuAmbient);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuColor);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuPatchFrontFace);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDebugPrint);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuDebugFlush);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/libgu", sceGuSetCallback);
