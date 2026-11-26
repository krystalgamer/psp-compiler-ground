/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

#include "UTST99332/demo_duck/gl.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _Z41__static_initialization_and_destruction_0ii_3A600);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext16BlendEquationEXTEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext13BlendColorEXTEffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext10InitializeEv);

void gl_ext::Toggle()
{
    use_extensions = !use_extensions;
}

bool gl_ext::Enabled()
{
    return use_extensions;
}

/* the function's static stays in the module's .bss (asm) */
extern int VAIOBugCheck_count __asm__("_ZZN6gl_ext12VAIOBugCheckEvE5count");

void gl_ext::VAIOBugCheck()
{
    if (glGetError())
        VAIOBugCheck_count++;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_3A600");
void _GLOBAL__I__ZN6gl_ext19pglBlendEquationExtE(void);
}

void _GLOBAL__I__ZN6gl_ext19pglBlendEquationExtE(void)
{
    static_init(1, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext13InitExtensionIPFvjEEEvRSt6vectorISsSaISsEERT_PKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext13InitExtensionIPFvffffEEEvRSt6vectorISsSaISsEERT_PKc);

