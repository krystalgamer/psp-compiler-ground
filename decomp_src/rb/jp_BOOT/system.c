#include "common.h"

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/system", load_module);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/system", unload_module);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/system", exit_cb);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/system", check_exit);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/system", SystemInit);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/system", SystemTerm);
