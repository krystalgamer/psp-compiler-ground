#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
int sceKernelDcacheWritebackAll(void);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_material/nonmatchings/sphere", DrawSphere);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_material/nonmatchings/sphere", D_00011F08);
