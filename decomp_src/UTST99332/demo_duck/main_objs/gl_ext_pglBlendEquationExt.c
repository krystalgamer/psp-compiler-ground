/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN6gl_ext19pglBlendEquationExtE\n_GLOBAL__I__ZN6gl_ext19pglBlendEquationExtE = _GLOBAL__I__ZN6gl_ext16BlendEquationEXTEj");

#include "UTST99332/demo_duck/gl.hpp"

namespace gl_ext {
extern void (*pglBlendEquationExt)(unsigned int);
extern void (*pglBlendColorEXT)(float, float, float, float);
template<class F> void InitExtension(std::vector<std::string> &, F &, const char *);
void BlendColorEXT(float, float, float, float);
std::vector<std::string> Initialize();
}
extern "C" const char D_001670FC[], D_00167110[];

extern "C" const char D_0016703C[], D_001670D0[], D_001670EC[], D_001670F0[];
namespace gl_ext { void BlendEquationEXT(unsigned int); }
extern const char BlendEquationEXT_name[] __asm__("_ZZN6gl_ext16BlendEquationEXTEjE19__PRETTY_FUNCTION__");
void gl_ext::BlendEquationEXT(unsigned int _Mode)
{
    if (pglBlendEquationExt && use_extensions) {
        SGL_ASSERT(_Mode == 0x8007 || _Mode == 0x8008 || _Mode == 0x800A || _Mode == 0x800B || _Mode == 0x8006, D_001670F0, D_0016703C, D_001670D0, BlendEquationEXT_name, 0x42, D_001670EC);
        pglBlendEquationExt(_Mode);
        VAIOBugCheck();
    }
}

void gl_ext::BlendColorEXT(float r, float g, float b, float a)
{
    if (pglBlendColorEXT && use_extensions)
        pglBlendColorEXT(r, g, b, a);
}

std::vector<std::string> gl_ext::Initialize()
{
    std::vector<std::string> v;
    InitExtension(v, pglBlendEquationExt, D_001670FC);
    InitExtension(v, pglBlendColorEXT, D_00167110);
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

/* the object's weak tail (linkonce copies), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext13InitExtensionIPFvjEEEvRSt6vectorISsSaISsEERT_PKc);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl_ext_pglBlendEquationExt", _ZN6gl_ext13InitExtensionIPFvffffEEEvRSt6vectorISsSaISsEERT_PKc);
