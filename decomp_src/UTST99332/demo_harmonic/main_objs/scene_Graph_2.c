/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN5scene5Graph10dot_outputESs\n_GLOBAL__I__ZN5scene5Graph10dot_outputESs = _GLOBAL__I__ZN5scene5Graph10dot_outputESs__asm");
__asm__(".globl _GLOBAL__D__ZN5scene5Graph10dot_outputESs\n_GLOBAL__D__ZN5scene5Graph10dot_outputESs = _GLOBAL__D__ZN5scene5Graph10dot_outputESs__asm");

extern "C" const char D_00166E58[], D_00166E64[], D_00166E6C[], D_00166E74[], D_00166ED0[], D_00166EFC[], D_00166F00[], D_00166F0C[], D_00166EB8[], D_00166F18[], D_00166F28[], D_00166F30[], D_00166EAC[], D_00166E88[];

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_2", _ZN5scene5Graph10dot_outputESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_2", _ZN5scene5Group10dot_outputERSo);

void scene::Material::dot_output(std::ostream &o)
{
    std::string color = D_00166EAC;
    std::string fontcolor = D_00166EAC;
    output_string(o, getName(), true);
    o << D_00166EB8 << color << D_00166E58 << (isMapped() ? D_00166E64 : D_00166E6C) << D_00166E74 << std::endl;
}

void scene::Node::dot_output(std::ostream &o)
{
    output_string(o, getName(), true);
    o << D_00166ED0 << D_00166E58 << (isMapped() ? D_00166E64 : D_00166E6C) << D_00166E74 << std::endl;
}

void scene::Node::output_string(std::ostream &o, const std::string &s, bool quote)
{
    const char *p = s.c_str();
    if (quote)
        o << D_00166F00;
    for (; *p; p++) {
        if (*p == '\\')
            o << D_00166EFC;
        else
            o << *p;
    }
    if (quote)
        o << D_00166F00;
}

/* the pass list's initializer stays in the module's .rodata */
struct ShapePasses {
    scene::Pass p[2];
};
extern "C" const ShapePasses D_00166F04;
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_2", _ZN5scene5Shape10dot_outputERSo);

void scene::Texture::dot_output(std::ostream &o)
{
    std::string color = D_00166F0C;
    std::string fontcolor = D_00166F0C;
    output_string(o, getName(), true);
    o << D_00166EB8 << color << D_00166E58 << fontcolor << D_00166F18;
    output_string(o, getName(), false);
    o << D_00166F28;
    output_string(o, getPath(), false);
    o << D_00166F30 << std::endl;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_2", _ZN5scene13DefaultShader10dot_outputERSo);
