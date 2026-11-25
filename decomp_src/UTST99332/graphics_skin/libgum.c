#include "common.h"
#include "m2c_macros.h"
M2C_UNK __checkUpdate();                            /* extern */


INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", __mulMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", __setMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", __checkUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumSetMatrixStack);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumSetCurMatrix);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGumUpdateMatrix(void);

void sceGumUpdateMatrix(void) {
    __checkUpdate();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumLoadContext);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumStoreContext);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumLoadIdentity);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumRotateX);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumRotateY);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumRotateZ);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumRotateXYZ);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumRotateZYX);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumTranslate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumScale);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumMultMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumPerspective);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumOrtho);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumLookAt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumMatrixMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumPushMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumPopMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumLoadMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumStoreMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumDrawArray);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumDrawArrayN);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumDrawBezier);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumDrawSpline);
