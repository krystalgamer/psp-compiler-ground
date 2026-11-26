#include "common.h"

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", callback_fin);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", send_commandi);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", send_commandi_stall);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", send_commandf);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", draw_region);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", get_exp);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", reset_static_value);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSendCommandf);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSendCommandi);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", fonttex);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", initList);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", tbpcmd_tbl);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", tbwcmd_tbl);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", tsizecmd_tbl);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", lcmd);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", color_material);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", D_0001742C);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuInit);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTerm);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", D_00017458);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", D_00017498);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", D_000174AC);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", D_00017504);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", D_0001755C);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuFinishId);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuCallMode);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuBreak);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuContinue);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSendList);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuCheckList);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDisable);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuGetStatus);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuGetAllStatus);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSetStatus);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSetAllStatus);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDepthRange);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDepthOffset);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuAmbient);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuColor);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuPatchFrontFace);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDebugPrint);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuDebugFlush);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libgu", sceGuSetCallback);
