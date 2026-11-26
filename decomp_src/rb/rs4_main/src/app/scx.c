/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *);           /* extern */
M2C_UNK sgxResCloseAll();                           /* extern */
M2C_UNK sgxSndStopAll(M2C_UNK);                     /* extern */
M2C_UNK sgxTerm();                                  /* extern */
extern unsigned char D_000FE5F4;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxMalloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxMfree);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE5A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE5F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE5F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE604);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE620);

#ifndef NULL
#define NULL ((void *)0)
#endif

int scxTerm(void) {
    consPrintf(&D_000FE5F4, "scxTerm");
    sgxSndStopAll(0);
    sgxResCloseAll();
    sgxTerm();
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE62C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE634);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE640);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE64C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE654);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE65C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE678);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE69C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6BC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxAsm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxRelease);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxPlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxStop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxPause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxState);

#ifndef NULL
#define NULL ((void *)0)
#endif

void scxStopAll(void) {
    sgxSndStopAll(0);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6F8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", ttrGetIndexNum);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE718);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", ttrGetMaxNumber);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE730);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", ttrGetStringByNumber);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", ttrGetStringByIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", ttrGetString);
