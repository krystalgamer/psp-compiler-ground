/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_VerticesVector", _Z41__static_initialization_and_destruction_0ii_F4D1C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_VerticesVector", _ZN2sh14VerticesVector4loadESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_VerticesVector", _ZN2sh14VerticesVector4saveESs);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F4D1C");
void _GLOBAL__I__ZN2sh14VerticesVector4loadESs(void);
void _GLOBAL__D__ZN2sh14VerticesVector4loadESs(void);
}

void _GLOBAL__I__ZN2sh14VerticesVector4loadESs(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN2sh14VerticesVector4loadESs(void)
{
    static_init(0, 0xFFFF);
}
