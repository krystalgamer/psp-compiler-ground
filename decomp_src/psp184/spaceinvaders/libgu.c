#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", callback_fin);

int get_exp(int val)
{
	int i;

	i = 9;
	do {
		if ((val >> i) & 1)
			break;
		i--;
	} while (i > 0);
	return i;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", reset_static_value);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSendCommandf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSendCommandi);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", fonttex);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", initList);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", tbpcmd_tbl);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", tbwcmd_tbl);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", tsizecmd_tbl);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", lcmd);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", color_material);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", D_0007F9D0);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuInit);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTerm);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", D_0007F9FC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", D_0007FA3C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", D_0007FA50);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", D_0007FAA8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", D_0007FB00);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuFinishId);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuCallMode);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuBreak);

void sceGuContinue(void)
{
	sceGeContinue();
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSendList);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuCheckList);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDisable);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuGetStatus);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuGetAllStatus);

void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuSetStatus(int state, int status);
void sceGuSetStatus(int state, int status)
{
	if (status == 0)
		sceGuDisable(state);
	else
		sceGuEnable(state);
}

void sceGuSetAllStatus(unsigned int status);
void sceGuSetAllStatus(unsigned int status)
{
	int i;

	for (i = 0; i < 22; i++) {
		if ((status >> i) & 1)
			sceGuEnable(i);
		else
			sceGuDisable(i);
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDepthRange);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDepthOffset);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuAmbient);

void sceGuColor(unsigned int color);
void sceGuMaterial(int mode, unsigned int color);
void sceGuColor(unsigned int color)
{
	sceGuMaterial(7, color);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuPatchFrontFace);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuDebugPrint);

void sceGuDebugFlush(void);
void sceGuDebugFlush(void)
{
	flush_font();
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgu", sceGuSetCallback);
