/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN8libc_fix4ItoAEiPci");
__asm__(".globl _GLOBAL__D__ZN8libc_fix4ItoAEiPci");


int libc_fix::ItoA(int v, char *buf, int)
{
    sprintf(buf, "%i", v);
    return 0;
}

int libc_fix::FtoA(float f, char *buf)
{
    sprintf(buf, "%g", f);
    return 0;
}

float libc_fix::AtoF(const char *s)
{
    return atof(s);
}

void libc_fix::ItoA(char *buf, unsigned int, int v)
{
    sprintf(buf, "%i", v);
}

void libc_fix::ItoAX(char *buf, unsigned int, int v)
{
    sprintf(buf, "0x%08X", v);
}

int libc_fix::AtoI(const char *s)
{
    return atoi(s);
}
