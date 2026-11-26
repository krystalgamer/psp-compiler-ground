#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
int sceKernelDcacheWritebackAll(void);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_material/nonmatchings/cone", DrawCone);
