/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _Z41__static_initialization_and_destruction_0ii_3CA7C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext16BlendEquationEXTEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext13BlendColorEXTEffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext10InitializeEv);

void gl_ext::Toggle()
{
    use_extensions = !use_extensions;
}

bool gl_ext::Enabled()
{
    return use_extensions;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext12VAIOBugCheckEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_3CA7C");
void _GLOBAL__I__ZN6gl_ext19pglBlendEquationExtE(void);
}

void _GLOBAL__I__ZN6gl_ext19pglBlendEquationExtE(void)
{
    static_init(1, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext13InitExtensionIPFvjEEEvRSt6vectorISsSaISsEERT_PKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext13InitExtensionIPFvffffEEEvRSt6vectorISsSaISsEERT_PKc);

