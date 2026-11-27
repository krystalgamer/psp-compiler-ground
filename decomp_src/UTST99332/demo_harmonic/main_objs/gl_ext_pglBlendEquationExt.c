/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

#include "UTST99332/demo_duck/gl.hpp"

namespace gl_ext {
extern void (*pglBlendEquationExt)(unsigned int);
extern void (*pglBlendColorEXT)(float, float, float, float);
template<class F> void InitExtension(std::vector<std::string> &, F &, const char *);
void BlendColorEXT(float, float, float, float);
std::vector<std::string> Initialize();
}
extern "C" const char D_001641DC[], D_001641F0[];

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _Z41__static_initialization_and_destruction_0ii_3A600);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext16BlendEquationEXTEj);

void gl_ext::BlendColorEXT(float r, float g, float b, float a)
{
    if (pglBlendColorEXT && use_extensions)
        pglBlendColorEXT(r, g, b, a);
}

std::vector<std::string> gl_ext::Initialize()
{
    std::vector<std::string> v;
    InitExtension(v, pglBlendEquationExt, D_001641DC);
    InitExtension(v, pglBlendColorEXT, D_001641F0);
    return v;
}

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

