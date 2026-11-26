#include "common.h"
#include "m2c_macros.h"


void loadingInit(void) {
}

void loadingTerm(void) {
}

void loadingSetup(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", loadingDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", localeChangeDirect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", localeChange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", localeInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", localeGetCntx);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", localeGetRegionCntx);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", localeIsUse);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", localeSetKeyConfig);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", empty_start);

#ifndef NULL
#define NULL ((void *)0)
#endif
int empty_stop(void) {
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", D_000FDB38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", D_000FDB44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", D_000FDB50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", D_000FDB54);
