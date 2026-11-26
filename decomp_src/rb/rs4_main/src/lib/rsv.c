/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *);           /* extern */
extern unsigned char D_000FB370;


#ifndef NULL
#define NULL ((void *)0)
#endif
int rsvDummy(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", rsvMove);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", rsvLoop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", rsvKeyState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", semaInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB2C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB2D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB2F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB300);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB308);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", semaTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", semaLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", semaUnlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", sortInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB370);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB374);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB390);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB3A0);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sortTerm(void) {
    consPrintf(&D_000FB370, "sortTerm");
    return 1;
}
