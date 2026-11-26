/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _Z41__static_initialization_and_destruction_0ii_A2C44);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _ZN3sgl3BoxC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _ZN3sgl3BoxC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _ZN3sgl3BoxC2EN4math11vector_xyzwES2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _ZN3sgl3BoxC1EN4math11vector_xyzwES2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _ZN3sgl3Box5firstEN4math11vector_xyzwE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _ZN3sgl3Box3addEN4math11vector_xyzwE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _ZN3sgl3Box6finishEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _ZNK3sgl3Box6volumeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _ZNK3sgl3Box4drawEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Box", _ZNK3sgl3Box4drawEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_A2C44");
void _GLOBAL__I__ZN3sgl3BoxC2Ev(void);
void _GLOBAL__D__ZN3sgl3BoxC2Ev(void);
}

void _GLOBAL__I__ZN3sgl3BoxC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl3BoxC2Ev(void)
{
    static_init(0, 0xFFFF);
}
