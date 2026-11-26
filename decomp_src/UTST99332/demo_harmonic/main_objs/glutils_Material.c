/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_Material", _Z41__static_initialization_and_destruction_0ii_2CA74);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_Material", _ZN7glutils8Material5setupEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_Material", _ZN7glutils8Material5printERSo);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_2CA74");
void _GLOBAL__I__ZN7glutils8Material5setupEv(void);
void _GLOBAL__D__ZN7glutils8Material5setupEv(void);
}

void _GLOBAL__I__ZN7glutils8Material5setupEv(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7glutils8Material5setupEv(void)
{
    static_init(0, 0xFFFF);
}
