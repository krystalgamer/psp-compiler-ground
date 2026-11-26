/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/obj", _Z41__static_initialization_and_destruction_0ii_32040);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_32040");
/* _GLOBAL__I_/_D_ (local names) */
void func_000320BC(void);
void func_000320DC(void);
}

void func_000320BC(void)
{
    static_init(1, 0xFFFF);
}

void func_000320DC(void)
{
    static_init(0, 0xFFFF);
}
