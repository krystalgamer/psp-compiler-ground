#include "common.h"

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/newlib/libc/reent/reent", cleanup_glue);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/newlib/libc/reent/reent", _reclaim_reent);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/newlib/libc/reent/reent", _wrapup_reent);
