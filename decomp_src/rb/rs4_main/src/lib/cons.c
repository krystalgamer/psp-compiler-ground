/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
extern int LogIdx;
extern int pLogBuf;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", consInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAA78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAA94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAAA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAAAC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAAC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAACC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", consTerm);

void consPrintf(const char *fmt, ...)
{
}

int consLog(unsigned int arg0) {
    int var_v1;

    var_v1 = 0;
    if ((pLogBuf != 0) & (arg0 < 0x10U)) {
        var_v1 = pLogBuf + (((LogIdx + arg0) & 0xF) << 6);
    }
    return var_v1;
}
