#include "common.h"

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", init_ai);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", update_sp_status);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/ai", D_00030878);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/ai", D_000308BC);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", set_sp_status);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", is_bisang);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", get_rest_pae);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", set_pae_priority);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", get_pae_priority);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", set_priority);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", judge);
