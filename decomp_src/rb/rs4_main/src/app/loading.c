/* cflags: -Os -fno-strength-reduce */
#include "common.h"

void loadingInit(void) {
}

void loadingTerm(void) {
}

void loadingSetup(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", loadingDraw);
