/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _Z41__static_initialization_and_destruction_0ii_21EC0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZN3psp4VramC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZN3psp4VramC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZN3psp4Vram4initENS_11PixelFormatE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZNK3psp4Vram3logEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZN3psp4Vram14copyImageBeginEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZN3psp4Vram14copyImageSrcPfENS_11PixelFormatE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZN3psp4Vram14copyImageDstPfENS_11PixelFormatE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZN3psp4Vram12copyImageEndEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZN3psp4Vram9copyImageEiiiiPvS1_);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_21EC0");
void _GLOBAL__I__ZN3psp4vramE(void);
void _GLOBAL__D__ZN3psp4vramE(void);
}

void _GLOBAL__I__ZN3psp4vramE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3psp4vramE(void)
{
    static_init(0, 0xFFFF);
}
