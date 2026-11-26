/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
extern int MsReady;
extern int MsState;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", msProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", msLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", msUnlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", msPref);

#ifndef NULL
#define NULL ((void *)0)
#endif

int msReady(void) {
    int temp_v0;

    temp_v0 = MsReady;
    MsReady = MsState;
    return temp_v0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA5E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA5F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA5F8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", msDump);
