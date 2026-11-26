/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_SquareMap", _Z41__static_initialization_and_destruction_0ii_F00A4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_SquareMap", _ZN2sh9SquareMapC2EPKcf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_SquareMap", _ZN2sh9SquareMapC1EPKcf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_SquareMap", _ZNK2sh9SquareMap4evalEffRfS1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_SquareMap", _ZN2sh9SquareMap4loadEPKc);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F00A4");
void _GLOBAL__I__ZN2sh9SquareMapC2EPKcf(void);
void _GLOBAL__D__ZN2sh9SquareMapC2EPKcf(void);
}

void _GLOBAL__I__ZN2sh9SquareMapC2EPKcf(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN2sh9SquareMapC2EPKcf(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_SquareMap", _ZN2sh9SquareMapD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_SquareMap", _ZN2sh9SquareMapD0Ev);
