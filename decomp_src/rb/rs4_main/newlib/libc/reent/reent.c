#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/newlib/libc/reent/reent", cleanup_glue);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/newlib/libc/reent/reent", reclaim_smbf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/newlib/libc/reent/reent", _reclaim_reent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/newlib/libc/reent/reent", _wrapup_reent);
