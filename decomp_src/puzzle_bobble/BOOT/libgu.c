#include "common.h"
#include "m2c_macros.h"

M2C_UNK send_commandf();                            /* extern */
M2C_UNK send_commandi();                            /* extern */
M2C_UNK sceGeUnsetCallback(int);                    /* extern */
M2C_UNK sceKernelDeleteEventFlag(int);              /* extern */
extern int D_00559210;
extern int intrCode;
extern int call_mode;
M2C_UNK sceGeContinue();                            /* extern */
extern void *pList;
extern unsigned int __gu_status;
M2C_UNK flush_font();                               /* extern */


INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", callback_fin);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", send_commandi);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", send_commandi_stall);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", send_commandf);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", draw_region);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", reset_static_value);

void sceGuSendCommandf(void) {
    send_commandf();
}

void sceGuSendCommandi(void) {
    send_commandi();
}

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

void sceGuTerm(void) {
    sceKernelDeleteEventFlag(D_00559210);
    sceGeUnsetCallback(intrCode);
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_00030828);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_00030868);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_0003087C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_000308D4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", D_0003092C);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuFinishId);

void sceGuCallMode(int arg0) {
    call_mode = arg0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuBreak);

void sceGuContinue(void) {
    sceGeContinue();
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSendList);

int sceGuCheckList(void) {
    return M2C_FIELD(pList, int *, 4) - M2C_FIELD(pList, int *, 0);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDisable);

int sceGuGetStatus(int arg0) {
    int var_v1;

    var_v1 = 0;
    if (arg0 < 0x16) {
        var_v1 = ((unsigned int) __gu_status >> arg0) & 1;
    }
    return var_v1;
}

int sceGuGetAllStatus(void) {
    return __gu_status;
}

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

void sceGuPatchDivide(int arg0, int arg1) {
    send_commandi(0x36, (arg1 << 8) | arg0);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuPatchPrim);

void sceGuAmbient(unsigned int arg0) {
    send_commandi(0x5C, arg0 & 0xFFFFFF);
    send_commandi(0x5D, arg0 >> 0x18);
}

void sceGuColor(int arg0) {
    sceGuMaterial(7, arg0);
}

void sceGuColorMaterial(int arg0) {
    send_commandi(0x53, arg0);
}

void sceGuMaterial(int arg0, unsigned int arg1) {
    if (!(arg0 & 1)) {

    } else {
        send_commandi(0x55, arg1 & 0xFFFFFF);
        send_commandi(0x58, arg1 >> 0x18);
    }
    if (!(arg0 & 2)) {

    } else {
        send_commandi(0x56, arg1 & 0xFFFFFF);
    }
    if (!(arg0 & 4)) {

    } else {
        send_commandi(0x57, arg1 & 0xFFFFFF);
    }
}

void sceGuAmbientColor(unsigned int arg0) {
    send_commandi(0x55, arg0 & 0xFFFFFF);
    send_commandi(0x58, arg0 >> 0x18);
}

void sceGuModelColor(int arg0, int arg1, int arg2, int arg3) {
    send_commandi(0x54, arg0 & 0xFFFFFF);
    send_commandi(0x56, arg2 & 0xFFFFFF);
    send_commandi(0x55, arg1 & 0xFFFFFF);
    send_commandi(0x57, arg3 & 0xFFFFFF);
}

void sceGuSpecular(void) {
    send_commandf(0x5B);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuFrontFace);

void sceGuPatchFrontFace(int arg0) {
    send_commandi(0x38, arg0);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuLight);

void sceGuLightMode(int arg0) {
    send_commandi(0x5E, arg0 & 1);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexMode);

void sceGuTexFilter(int arg0, int arg1) {
    send_commandi(0xC6, (arg1 << 8) | arg0);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexFunc);

void sceGuTexEnvColor(int arg0) {
    send_commandi(0xCA, arg0 & 0xFFFFFF);
}

void sceGuTexWrap(int arg0, int arg1) {
    send_commandi(0xC7, (arg1 << 8) | arg0);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexProjMapMode);

void sceGuTexSync(void) {
    send_commandi(0xCC, 0);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuTexFlush);

void sceGuTexSlope(void) {
    send_commandf(0xD0);
}

void sceGuClutMode(int arg0, int arg1, int arg2, int arg3) {
    int temp_a2;
    int temp_a3;

    temp_a2 = arg2 << 8;
    temp_a3 = (arg3 << 0x10) | temp_a2 | (arg1 * 4) | arg0;
    send_commandi(0xC5, temp_a3, temp_a2, temp_a3);
}

void sceGuClutLoad(int arg0, unsigned int arg1) {
    send_commandi(0xB0, arg1 & 0xFFFFFF);
    send_commandi(0xB1, (arg1 >> 8) & 0xF0000);
    send_commandi(0xC4, arg0);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuFog);

void sceGuColorFunc(int arg0, int arg1, int arg2) {
    send_commandi(0xD8, arg0 & 3);
    send_commandi(0xD9, arg1 & 0xFFFFFF);
    send_commandi(0xDA, arg2 & 0xFFFFFF);
}

void sceGuAlphaFunc(int arg0, int arg1, int arg2) {
    int temp_a2;

    temp_a2 = ((arg2 & 0xFF) << 0x10) | ((arg1 & 0xFF) << 8) | arg0;
    send_commandi(0xDB, temp_a2, temp_a2);
}

void sceGuDepthFunc(int arg0) {
    send_commandi(0xDE, arg0);
}

void sceGuDepthMask(int arg0) {
    send_commandi(0xE7, arg0);
}

void sceGuPixelMask(unsigned int arg0) {
    send_commandi(0xE8, arg0 & 0xFFFFFF);
    send_commandi(0xE9, arg0 >> 0x18);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuScissor);

void sceGuStencilFunc(int arg0, int arg1, int arg2) {
    int temp_a2;

    temp_a2 = ((arg2 & 0xFF) << 0x10) | ((arg1 & 0xFF) << 8) | arg0;
    send_commandi(0xDC, temp_a2, temp_a2);
}

void sceGuLogicalOp(int arg0) {
    send_commandi(0xE6, arg0 & 0xF);
}

void sceGuStencilOp(int arg0, int arg1, int arg2) {
    int temp_a2;

    temp_a2 = (arg2 << 0x10) | (arg1 << 8) | arg0;
    send_commandi(0xDD, temp_a2, temp_a2);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuBoneMatrix);

void sceGuMorphWeight(int arg0) {
    send_commandf(arg0 + 0x2C);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuDebugPrint);

void sceGuDebugFlush(void) {
    flush_font();
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgu", sceGuSetCallback);
