#include "common.h"

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", env_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", env_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", toon_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", toon_tex);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", init_pos);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", term_all);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", vsync_frame);
