#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dResourceTag__PurgeCache();               /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", RemapOnMemorySub);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", RemapOnMemoryHalf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", RemapOnMemoryFull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", RemapOnStack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dPicture__SetupFromTim2Sub_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dPicture__SetupFromTim2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dPicture__SetupFromTim2_WithImageConvertBuffer_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dClut__SetupFromTim2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dPicture__Get_wPixel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dPicture__Get_hPixel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dClut__Construct);

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dClut__Destruct(void *arg0) {
    M2C_FIELD(arg0, signed char *, 0x26) = 0;
    I3dClut__FlushCache();
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dPicture__FlushCache(void) {
    I3dResourceTag__PurgeCache();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dClut__FlushCache(void) {
    I3dResourceTag__PurgeCache();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dLzc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dFogStatusParam__ClearA);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", D_001090AC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dRender__CreateFogStatusA);
