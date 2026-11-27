/* cflags: -Os -fno-strength-reduce */
#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/core", coreInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/core", coreTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/core", coreFunc);
