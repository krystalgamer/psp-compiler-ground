/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_DebugMap", _Z41__static_initialization_and_destruction_0ii_D6804);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_DebugMap", _ZNK2sh8DebugMap4evalEffRfS1_S1_);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_D6804");
void _GLOBAL__I__ZNK2sh8DebugMap4evalEffRfS1_S1_(void);
void _GLOBAL__D__ZNK2sh8DebugMap4evalEffRfS1_S1_(void);
}

void _GLOBAL__I__ZNK2sh8DebugMap4evalEffRfS1_S1_(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZNK2sh8DebugMap4evalEffRfS1_S1_(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_DebugMap", _ZN2sh8DebugMapD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_DebugMap", _ZN2sh8DebugMapD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_DebugMap", _ZN2sh14SphericalRGBFnD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_DebugMap", _ZN2sh14SphericalRGBFnD0Ev);
