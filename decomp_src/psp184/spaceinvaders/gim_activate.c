#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_activate", sceGimPictureLoadCache);

void sceGimPictureUnloadCache(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_activate", sceGimPictureActivate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_activate", sceGimPictureActivateTexture);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_activate", sceGimPictureActivateRenderState);
