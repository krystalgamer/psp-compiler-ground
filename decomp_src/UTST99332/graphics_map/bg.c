#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuColor(unsigned int color);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
int sceKernelDcacheWritebackAll(void);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_map/nonmatchings/bg", DrawBG);
