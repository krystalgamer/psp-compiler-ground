/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", powerInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA67C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA68C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA6A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA6B8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", powerTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", powerProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", powerState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", sprInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA6F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA6F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA708);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA724);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA734);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", sprTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", sprCall);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", sprFree);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sprGetSize(void) {
    return 0x800;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA7B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA7C0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", umdInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA7E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA7F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA7FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA818);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA828);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA848);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA85C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA864);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA870);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA88C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA898);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", umdTerm);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA8A4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", umdActive);
