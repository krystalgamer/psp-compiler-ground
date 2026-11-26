#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", callback_fin);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", reset_static_value);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSendCommandf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSendCommandi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuInit);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTerm);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuFinishId);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuCallMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuBreak);

void sceGuContinue(void)
{
	sceGeContinue();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSendList);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuCheckList);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDisable);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuGetStatus);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuGetAllStatus);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDepthRange);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDepthOffset);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuAmbient);

void sceGuColor(unsigned int color);
void sceGuMaterial(int mode, unsigned int color);
void sceGuColor(unsigned int color)
{
	sceGuMaterial(7, color);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuPatchFrontFace);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuDebugPrint);

void sceGuDebugFlush(void);
void sceGuDebugFlush(void)
{
	flush_font();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgu", sceGuSetCallback);
