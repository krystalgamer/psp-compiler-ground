/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/libc_fix_ItoA", _Z41__static_initialization_and_destruction_0ii_1517C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/libc_fix_ItoA", _ZN8libc_fix4ItoAEiPci);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/libc_fix_ItoA", _ZN8libc_fix4FtoAEfPc);

float libc_fix::AtoF(const char *s)
{
    return atof(s);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/libc_fix_ItoA", _ZN8libc_fix4ItoAEPcji);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/libc_fix_ItoA", _ZN8libc_fix5ItoAXEPcji);

int libc_fix::AtoI(const char *s)
{
    return atoi(s);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/libc_fix_ItoA", _GLOBAL__I__ZN8libc_fix4ItoAEiPci);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/libc_fix_ItoA", _GLOBAL__D__ZN8libc_fix4ItoAEiPci);
