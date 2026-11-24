#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__init);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__alloc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__free);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__draw_status);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__term);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__get_total_size);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__get_total_free);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__get_max_free);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__get_alloc_count);
