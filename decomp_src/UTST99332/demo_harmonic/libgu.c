#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", callback_fin);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", reset_static_value);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSendCommandf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSendCommandi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuInit);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTerm);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuFinishId);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuCallMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuBreak);

void sceGuContinue(void)
{
	sceGeContinue();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSendList);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuCheckList);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDisable);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuGetStatus);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuGetAllStatus);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDepthRange);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDepthOffset);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuAmbient);

void sceGuColor(unsigned int color);
void sceGuMaterial(int mode, unsigned int color);
void sceGuColor(unsigned int color)
{
	sceGuMaterial(7, color);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuPatchFrontFace);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuDebugPrint);

void sceGuDebugFlush(void);
void sceGuDebugFlush(void)
{
	flush_font();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/libgu", sceGuSetCallback);
