/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define SGL_LINKONCE_PolarFunction 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZNK2sh13PolarFunction4evalEffRfS1_S1_");
__asm__(".globl _GLOBAL__D__ZNK2sh13PolarFunction4evalEffRfS1_S1_");

void sh::PolarFunction::eval(float theta, float phi, float &r, float &g, float &b) const
{
    r = g = b = eval(theta, phi);
}
