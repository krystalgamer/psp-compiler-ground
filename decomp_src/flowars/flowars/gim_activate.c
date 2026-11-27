#include "common.h"

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/gim_activate", sceGimPictureLoadCache);

void sceGimPictureUnloadCache(void) {
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/gim_activate", sceGimPictureActivate);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/gim_activate", sceGimPictureActivateTexture);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/gim_activate", sceGimPictureActivateRenderState);
