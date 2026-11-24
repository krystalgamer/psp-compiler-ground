#include "common.h"

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", env_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", env_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", toon_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", toon_tex);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", init_pos);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", main);
