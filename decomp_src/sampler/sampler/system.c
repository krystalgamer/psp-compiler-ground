#include "common.h"

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/system", load_module);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/system", unload_module);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/system", exit_cb);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/system", check_exit);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/system", SystemInit);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/system", SystemTerm);
