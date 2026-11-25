#include "common.h"

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", read_header_DCA8);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", read_short_DD84);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", read_int);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", copy_idx4);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", copy_idx8);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", copy_5551);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", copy_5650);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", copy_8880);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", copy_8888);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", copy_rle4);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", copy_rle8);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_bmp", sceGimPictureLoadTga);
