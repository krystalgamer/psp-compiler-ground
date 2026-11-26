/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_HasBVdata", _Z41__static_initialization_and_destruction_0ii_5CBE8);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_HasBVdata", _ZN5scene9HasBVdata11frustumTestERN3sgl7FrustumE);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_5CBE8");
void _GLOBAL__I__ZN5scene9HasBVdata7enabledE(void);
void _GLOBAL__D__ZN5scene9HasBVdata7enabledE(void);
}

void _GLOBAL__I__ZN5scene9HasBVdata7enabledE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene9HasBVdata7enabledE(void)
{
    static_init(0, 0xFFFF);
}
