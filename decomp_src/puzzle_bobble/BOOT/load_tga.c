#include "common.h"
#include "m2c_macros.h"



INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_tga", sceGimPictureLoadTga);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_tga", read_header_183EC);

void *read_char(unsigned char *arg0, unsigned char *arg1) {
    *arg1 = *arg0;
    return arg0 + 1;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_tga", read_short_184B0);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_tga", copy_pixels_184E0);
