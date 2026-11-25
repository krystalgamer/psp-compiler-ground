#include "common.h"
#include "m2c_macros.h"
M2C_UNK sceGeUnsetCallback(int);                    /* extern */
M2C_UNK sceKernelDeleteEventFlag(int);              /* extern */
extern int D_00024418;
extern int intrCode;
extern int call_mode;
M2C_UNK sceGeContinue();                            /* extern */
extern void *pList;
extern unsigned int __gu_status;
extern int __aw_list_mode;
extern unsigned char _ctx;
M2C_UNK flush_font();                               /* extern */


INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", callback_fin);

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", reset_static_value);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSendCommandf);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSendCommandi);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", fonttex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", initList);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", tbpcmd_tbl);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", tbwcmd_tbl);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", tsizecmd_tbl);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", lcmd);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", color_material);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_000120E8);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuInit);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuTerm(void);

void sceGuTerm(void) {
    sceKernelDeleteEventFlag(D_00024418);
    sceGeUnsetCallback(intrCode);
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_00012114);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_00012154);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_00012168);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_000121C0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_00012218);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuFinishId);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuCallMode(int mode);

void sceGuCallMode(int mode) {
    call_mode = mode;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuBreak);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sceGuContinue(void) {
    sceGeContinue();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSendList);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceGuCheckList(void);

int sceGuCheckList(void) {
    return M2C_FIELD(pList, int *, 4) - M2C_FIELD(pList, int *, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDisable);

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSetAllStatus);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDepthRange);

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuAmbient);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuColor(unsigned int color);
void sceGuMaterial(int mode, unsigned int color);
void sceGuColor(unsigned int color) {
    sceGuMaterial(7, color);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuPatchFrontFace);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDebugPrint);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuDebugFlush(void);

void sceGuDebugFlush(void) {
    flush_font();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSetCallback);
