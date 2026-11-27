/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN4math9factorialEi");
__asm__(".globl _GLOBAL__D__ZN4math9factorialEi");

/* constants and strings stay in the module's .rodata (asm) */
extern const float D_00173A88;      /* 1 */
extern const float D_00173A8C;      /* 4 pi */

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_factorial", _ZN4math2SH1PEiif);

float math::SH::K(int l, int m)
{
    int am = abs(m);
    return sqrtf((2.0f * l + D_00173A88) * factorial(l - am) / (factorial(l + am) * D_00173A8C));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_factorial", _ZN4math2SH4EvalEiiff);

int math::SH::N(unsigned int l)
{
    return (l + 1) * (l + 1);
}
