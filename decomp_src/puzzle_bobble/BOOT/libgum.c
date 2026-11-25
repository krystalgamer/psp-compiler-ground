#include "common.h"
#include "m2c_macros.h"

M2C_UNK __checkUpdate();                            /* extern */
M2C_UNK sceGuDrawArray(int, int, int, int, int);    /* extern */
M2C_UNK sceGuDrawArrayN(int, int, int, int, int, int); /* extern */
M2C_UNK sceGuDrawBezier(int, int, int, int, int);   /* extern */
M2C_UNK sceGuDrawSpline(int, int, int, int, int, int, int); /* extern */


INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", __mulMatrix);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", __setMatrix);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", __checkUpdate);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumSetMatrixStack);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumSetCurMatrix);

void sceGumUpdateMatrix(void) {
    __checkUpdate();
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumLoadContext);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumStoreContext);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumLoadIdentity);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumRotateX);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumRotateY);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumRotateZ);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumRotateXYZ);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumRotateZYX);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumTranslate);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumScale);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumMultMatrix);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumPerspective);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumOrtho);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumLookAt);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumMatrixMode);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumPushMatrix);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumPopMatrix);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumLoadMatrix);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumStoreMatrix);

void sceGumDrawArray(int arg0, int arg1, int arg2, int arg3, int arg4) {
    __checkUpdate();
    sceGuDrawArray(arg0, arg1, arg2, arg3, arg4);
}

void sceGumDrawArrayN(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    __checkUpdate();
    sceGuDrawArrayN(arg0, arg1, arg2, arg3, arg4, arg5);
}

void sceGumDrawBezier(int arg0, int arg1, int arg2, int arg3, int arg4) {
    __checkUpdate();
    sceGuDrawBezier(arg0, arg1, arg2, arg3, arg4);
}

void sceGumDrawSpline(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    __checkUpdate();
    sceGuDrawSpline(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}
