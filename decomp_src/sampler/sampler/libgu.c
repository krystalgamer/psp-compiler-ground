#include "common.h"

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", callback_fin);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", send_commandi);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", send_commandi_stall);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", send_commandf);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", draw_region);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", get_exp);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", reset_static_value);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSendCommandf);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSendCommandi);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", fonttex);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", initList);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", tbpcmd_tbl);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", tbwcmd_tbl);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", tsizecmd_tbl);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", lcmd);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", color_material);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", D_0001735C);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuInit);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTerm);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", D_00017388);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", D_000173C8);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", D_000173DC);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", D_00017434);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libgu", D_0001748C);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuFinishId);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuCallMode);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuBreak);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuContinue);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSendList);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuCheckList);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDisable);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuGetStatus);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuGetAllStatus);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSetStatus);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSetAllStatus);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDepthRange);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDepthOffset);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuAmbient);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuColor);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuPatchFrontFace);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDebugPrint);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuDebugFlush);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libgu", sceGuSetCallback);
