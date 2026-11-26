#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGuDisable(int state);
void sceGuEnable(int state);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/logo", init_logo);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/logo", proc_logo);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/logo", draw_logo);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/logo", D_00021630);
