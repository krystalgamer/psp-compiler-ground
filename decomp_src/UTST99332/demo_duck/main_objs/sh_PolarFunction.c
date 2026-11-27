/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SGL_LINKONCE_PolarFunction 1
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_PolarFunction", _Z41__static_initialization_and_destruction_0ii_E9668);

void sh::PolarFunction::eval(float theta, float phi, float &r, float &g, float &b) const
{
    r = g = b = eval(theta, phi);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_E9668");
void _GLOBAL__I__ZNK2sh13PolarFunction4evalEffRfS1_S1_(void);
void _GLOBAL__D__ZNK2sh13PolarFunction4evalEffRfS1_S1_(void);
}

void _GLOBAL__I__ZNK2sh13PolarFunction4evalEffRfS1_S1_(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZNK2sh13PolarFunction4evalEffRfS1_S1_(void)
{
    static_init(0, 0xFFFF);
}
