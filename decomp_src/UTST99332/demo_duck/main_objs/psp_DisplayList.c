/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_DisplayList", _Z41__static_initialization_and_destruction_0ii_15328);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_15328");
/* _GLOBAL__I_/_D_ (local names) */
void func_000153A4(void);
void func_000153C4(void);
}

void func_000153A4(void)
{
    static_init(1, 0xFFFF);
}

void func_000153C4(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_DisplayList", _ZN3psp11DisplayList6resizeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_DisplayList", _ZN3psp11DisplayList8set_nameEPKc);
