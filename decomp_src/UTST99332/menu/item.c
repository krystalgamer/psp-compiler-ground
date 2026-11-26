#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGuColor(unsigned int color);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/item", InitItem);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/item", _DrawItemFade);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_0001708C);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_00017090);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_00017094);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_00017098);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_0001709C);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_000170A0);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_000170A4);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/item", DrawItem2D);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/item", DrawItem);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_000170D0);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/item", RunItem);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/item", KeyItem);
