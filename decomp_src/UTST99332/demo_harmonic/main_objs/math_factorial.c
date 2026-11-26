/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_factorial", _Z41__static_initialization_and_destruction_0ii_EC6B4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_factorial", _ZN4math9factorialEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_factorial", _ZN4math16double_factorialEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_factorial", _ZN4math2SH1PEiif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_factorial", _ZN4math2SH1KEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_factorial", _ZN4math2SH4EvalEiiff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_factorial", _ZN4math2SH1NEj);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_EC6B4");
void _GLOBAL__I__ZN4math9factorialEi(void);
void _GLOBAL__D__ZN4math9factorialEi(void);
}

void _GLOBAL__I__ZN4math9factorialEi(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN4math9factorialEi(void)
{
    static_init(0, 0xFFFF);
}
