/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Vector", _Z41__static_initialization_and_destruction_0ii_F50B4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Vector", _ZNK2sh6Vector5printEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Vector", _ZNK2sh9VectorRGB4evalEffRfS1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Vector", _ZN2sh9VectorRGB4saveEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Vector", _ZN2sh9VectorRGB4loadEPKc);

void sh::VectorRGB::print(const char *) const {
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F50B4");
void _GLOBAL__I__ZNK2sh6Vector5printEPKc(void);
void _GLOBAL__D__ZNK2sh6Vector5printEPKc(void);
}

void _GLOBAL__I__ZNK2sh6Vector5printEPKc(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZNK2sh6Vector5printEPKc(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Vector", _ZNK2sh6Vector4evalEffi);
