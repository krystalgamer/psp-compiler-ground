/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" const char D_0015E6C4[], D_0015E6C8[], D_0015E6CC[];

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/libc_fix_ItoA", _Z41__static_initialization_and_destruction_0ii_1A854);

int libc_fix::ItoA(int v, char *buf, int)
{
    sprintf(buf, D_0015E6C4, v);
    return 0;
}

int libc_fix::FtoA(float f, char *buf)
{
    sprintf(buf, D_0015E6C8, f);
    return 0;
}

float libc_fix::AtoF(const char *s)
{
    return atof(s);
}

void libc_fix::ItoA(char *buf, unsigned int, int v)
{
    sprintf(buf, D_0015E6C4, v);
}

void libc_fix::ItoAX(char *buf, unsigned int, int v)
{
    sprintf(buf, D_0015E6CC, v);
}

int libc_fix::AtoI(const char *s)
{
    return atoi(s);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_1A854");
void _GLOBAL__I__ZN8libc_fix4ItoAEiPci(void);
void _GLOBAL__D__ZN8libc_fix4ItoAEiPci(void);
}

void _GLOBAL__I__ZN8libc_fix4ItoAEiPci(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN8libc_fix4ItoAEiPci(void)
{
    static_init(0, 0xFFFF);
}
