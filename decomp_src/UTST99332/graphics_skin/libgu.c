#include "common.h"
#include "m2c_macros.h"
M2C_UNK sceGeUnsetCallback(int);                    /* extern */
M2C_UNK sceKernelDeleteEventFlag(int);              /* extern */
extern int D_00029ED8;
extern int intrCode;
extern int call_mode;
M2C_UNK sceGeContinue();                            /* extern */
extern void *pList;
extern unsigned int __gu_status;
extern int __aw_list_mode;
extern unsigned char _ctx;
M2C_UNK flush_font();                               /* extern */


INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", callback_fin);

#ifndef NULL
#define NULL ((void *)0)
#endif
int get_exp(int arg0) {
    int var_v1;

    var_v1 = 9;
loop_1:
    if (!((arg0 >> var_v1) & 1)) {
        var_v1 -= 1;
        if (var_v1 > 0) {
            goto loop_1;
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", reset_static_value);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSendCommandf);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSendCommandi);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuInit);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuTerm(void);

void sceGuTerm(void) {
    sceKernelDeleteEventFlag(D_00029ED8);
    sceGeUnsetCallback(intrCode);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuFinishId);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuCallMode(int mode);

void sceGuCallMode(int mode) {
    call_mode = mode;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuBreak);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sceGuContinue(void) {
    sceGeContinue();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSendList);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceGuCheckList(void);

int sceGuCheckList(void) {
    return M2C_FIELD(pList, int *, 4) - M2C_FIELD(pList, int *, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDisable);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceGuGetStatus(int state);

int sceGuGetStatus(int state) {
    int var_v1;

    var_v1 = 0;
    if (state < 0x16) {
        var_v1 = ((unsigned int) __gu_status >> state) & 1;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int sceGuGetAllStatus(void);

unsigned int sceGuGetAllStatus(void) {
    return __gu_status;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuSetStatus(int state, int status);
void sceGuSetStatus(int state, int status) {
    if (status == 0) {
        sceGuDisable(state);
    } else {
        sceGuEnable(state);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSetAllStatus);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDepthRange);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuDepthRange(int near, int far);
void sceGuDepthOffset(unsigned int offset);

void sceGuDepthOffset(unsigned int offset) {
    void *temp_v1;

    temp_v1 = (__aw_list_mode * 0x5C) + &_ctx;
    M2C_FIELD(temp_v1, unsigned int *, 0x28) = offset;
    sceGuDepthRange(M2C_FIELD(temp_v1, int *, 0x20), M2C_FIELD(temp_v1, int *, 0x24));
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuAmbient);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuColor(unsigned int color);
void sceGuMaterial(int mode, unsigned int color);
void sceGuColor(unsigned int color) {
    sceGuMaterial(7, color);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuPatchFrontFace);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuDebugPrint);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuDebugFlush(void);

void sceGuDebugFlush(void) {
    flush_font();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgu", sceGuSetCallback);
