#include "common.h"

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", callback_fin);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", send_commandi);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", send_commandi_stall);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", send_commandf);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", draw_region);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", get_exp);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", reset_static_value);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSendCommandf);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSendCommandi);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", fonttex);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", initList);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", tbpcmd_tbl);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", tbwcmd_tbl);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", tsizecmd_tbl);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", lcmd);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", color_material);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_000307FC);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTerm);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_00030828);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_00030868);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_0003087C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_000308D4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_0003092C);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuFinishId);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuCallMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuBreak);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuContinue);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSendList);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuCheckList);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDisable);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuGetStatus);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuGetAllStatus);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSetStatus);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSetAllStatus);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDepthRange);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDepthOffset);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuAmbient);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuColor);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuPatchFrontFace);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDebugPrint);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDebugFlush);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSetCallback);
