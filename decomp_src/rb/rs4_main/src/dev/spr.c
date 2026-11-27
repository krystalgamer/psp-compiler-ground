/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", sprInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA6F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA6F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA708);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA724);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA734);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", sprTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", sprCall);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", sprFree);

int sprGetSize(void) {
    return 0x800;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA7B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA7C0);
