/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" const char D_00169D7C[], D_00169D88[], D_00169D90[], D_00169D98[], D_00169DF4[], D_00169E20[], D_00169E24[], D_00169E30[], D_00169DDC[], D_00169E3C[], D_00169E4C[], D_00169E54[], D_00169DD0[], D_00169DAC[];

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph_2", _Z41__static_initialization_and_destruction_0ii_73D6C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph_2", _ZN5scene5Graph10dot_outputESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph_2", _ZN5scene5Group10dot_outputERSo);

void scene::Material::dot_output(std::ostream &o)
{
    std::string color = D_00169DD0;
    std::string fontcolor = D_00169DD0;
    output_string(o, getName(), true);
    o << D_00169DDC << color << D_00169D7C << (isMapped() ? D_00169D88 : D_00169D90) << D_00169D98 << std::endl;
}

void scene::Node::dot_output(std::ostream &o)
{
    output_string(o, getName(), true);
    o << D_00169DF4 << D_00169D7C << (isMapped() ? D_00169D88 : D_00169D90) << D_00169D98 << std::endl;
}

void scene::Node::output_string(std::ostream &o, const std::string &s, bool quote)
{
    const char *p = s.c_str();
    if (quote)
        o << D_00169E24;
    for (; *p; p++) {
        if (*p == '\\')
            o << D_00169E20;
        else
            o << *p;
    }
    if (quote)
        o << D_00169E24;
}

/* the pass list's initializer stays in the module's .rodata */
struct ShapePasses {
    scene::Pass p[2];
};
extern "C" const ShapePasses D_00169E28;
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph_2", _ZN5scene5Shape10dot_outputERSo);

void scene::Texture::dot_output(std::ostream &o)
{
    std::string color = D_00169E30;
    std::string fontcolor = D_00169E30;
    output_string(o, getName(), true);
    o << D_00169DDC << color << D_00169D7C << fontcolor << D_00169E3C;
    output_string(o, getName(), false);
    o << D_00169E4C;
    output_string(o, getPath(), false);
    o << D_00169E54 << std::endl;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph_2", _ZN5scene13DefaultShader10dot_outputERSo);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_73D6C");
void _GLOBAL__I__ZN5scene5Graph10dot_outputESs(void);
void _GLOBAL__D__ZN5scene5Graph10dot_outputESs(void);
}

void _GLOBAL__I__ZN5scene5Graph10dot_outputESs(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene5Graph10dot_outputESs(void)
{
    static_init(0, 0xFFFF);
}
