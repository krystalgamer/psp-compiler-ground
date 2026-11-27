/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK semaLock(int);                              /* extern */
extern int MsSema;
M2C_UNK semaUnlock(int);                            /* extern */

extern int MsReady;
extern int MsState;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", msProc);

#ifndef NULL
#define NULL ((void *)0)
#endif

void msLock(void) {
    if (MsSema > 0) {
        semaLock(MsSema);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void msUnlock(void) {
    if (MsSema > 0) {
        semaUnlock(MsSema);
    }
}

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
