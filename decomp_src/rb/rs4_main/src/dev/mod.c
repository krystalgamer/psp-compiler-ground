/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK semaLock(int);                              /* extern */
extern int SemaMod;
M2C_UNK semaUnlock(int);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", modInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA398);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA404);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA42C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA45C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA484);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", modTerm);

void modLock(void) {
    if (SemaMod > 0) {
        semaLock(SemaMod);
    }
}

void modUnlock(void) {
    if (SemaMod > 0) {
        semaUnlock(SemaMod);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", modLoad);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA4C8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", modUnload);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA50C);
