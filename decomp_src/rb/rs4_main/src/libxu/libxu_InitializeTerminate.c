#include "common.h"

void xuInit(void) {
}

void xuTerm(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_InitializeTerminate", xuFinish);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_InitializeTerminate", xuSignal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_InitializeTerminate", xuCallList);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_InitializeTerminate", xuJumpList);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_InitializeTerminate", xuReturn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_InitializeTerminate", xuNop);
