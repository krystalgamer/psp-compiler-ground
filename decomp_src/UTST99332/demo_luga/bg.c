#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGuDisable(int state);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/bg", init_bg);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/bg", proc_bg);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/bg", draw_bg);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/bg", D_00021580);
