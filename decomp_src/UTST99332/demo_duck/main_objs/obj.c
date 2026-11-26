/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/obj", _Z41__static_initialization_and_destruction_0ii_344BC);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_344BC");
/* _GLOBAL__I_/_D_ (local names) */
void func_00034538(void);
void func_00034558(void);
}

void func_00034538(void)
{
    static_init(1, 0xFFFF);
}

void func_00034558(void)
{
    static_init(0, 0xFFFF);
}
