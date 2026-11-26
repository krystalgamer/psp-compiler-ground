/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_ZYZ", _Z41__static_initialization_and_destruction_0ii_4EC9C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_ZYZ", _ZNK4math3ZYZ15transformMatrixEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_4EC9C");
void _GLOBAL__I__ZNK4math3ZYZ15transformMatrixEv(void);
}

void _GLOBAL__I__ZNK4math3ZYZ15transformMatrixEv(void)
{
    static_init(1, 0xFFFF);
}
