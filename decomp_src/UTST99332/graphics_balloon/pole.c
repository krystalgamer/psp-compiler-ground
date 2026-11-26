#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
int sceKernelDcacheWritebackAll(void);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/pole", DrawPole);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_balloon/nonmatchings/pole", D_00013258);
