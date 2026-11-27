/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* constants and strings stay in the module's .rodata (asm) */
extern const float D_00170B60;      /* 1 */
extern const float D_00170B64;      /* 4 pi */

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_factorial", _Z41__static_initialization_and_destruction_0ii_EC6B4);

int math::factorial(int n)
{
    if (n == 0)
        return 1;
    int r = 1;
    for (; n > 1; n--)
        r *= n;
    return r;
}

int math::double_factorial(int n)
{
    if (n == 0 || n == -1)
        return 1;
    int r = 1;
    for (; n > 1; n -= 2)
        r *= n;
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_factorial", _ZN4math2SH1PEiif);

float math::SH::K(int l, int m)
{
    int am = abs(m);
    return sqrtf((2.0f * l + D_00170B60) * factorial(l - am) / (factorial(l + am) * D_00170B64));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_factorial", _ZN4math2SH4EvalEiiff);

int math::SH::N(unsigned int l)
{
    return (l + 1) * (l + 1);
}

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

