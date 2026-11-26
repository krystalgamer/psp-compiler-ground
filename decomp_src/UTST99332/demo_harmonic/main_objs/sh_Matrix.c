/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_Matrix", _Z41__static_initialization_and_destruction_0ii_E0294);

sh::Matrix::Matrix() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_Matrix", _ZN2sh6Matrix8IdentityEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_Matrix", _ZNK2sh6MatrixmlERKNS_6VectorE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_Matrix", _ZNK2sh6Matrix9transposeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_Matrix", _ZNK2sh6Matrix5equalES0_f);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_Matrix", _ZNK2sh6Matrix5printEb);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_E0294");
void _GLOBAL__I__ZN2sh6MatrixC2Ev(void);
void _GLOBAL__D__ZN2sh6MatrixC2Ev(void);
}

void _GLOBAL__I__ZN2sh6MatrixC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN2sh6MatrixC2Ev(void)
{
    static_init(0, 0xFFFF);
}

