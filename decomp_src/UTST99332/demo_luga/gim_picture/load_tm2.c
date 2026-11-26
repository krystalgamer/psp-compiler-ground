#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
int sceKernelDcacheWritebackAll(void);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_tm2", sceGimPictureLoadTm2);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_tm2", copy_pixels_F380);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_tm2", sort_clut);
