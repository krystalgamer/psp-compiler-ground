/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_GetDeltaTime", _Z41__static_initialization_and_destruction_0ii_FD508);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_GetDeltaTime", _ZN3sys5timer12GetDeltaTimeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_GetDeltaTime", _ZN3sys5timer7GetTimeEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_FD508");
void _GLOBAL__I__ZN3sys5timer12GetDeltaTimeEv(void);
void _GLOBAL__D__ZN3sys5timer12GetDeltaTimeEv(void);
}

void _GLOBAL__I__ZN3sys5timer12GetDeltaTimeEv(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sys5timer12GetDeltaTimeEv(void)
{
    static_init(0, 0xFFFF);
}

