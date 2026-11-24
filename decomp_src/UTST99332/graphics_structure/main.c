#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", draw_frame);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", star_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", star_tex);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", main);
