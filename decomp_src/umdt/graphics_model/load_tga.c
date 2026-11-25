#include "common.h"

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tga", read_header_E754);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tga", read_char);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tga", read_short_E818);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tga", copy_pixels_E848);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tga", sceGimPictureLoadTm2);
