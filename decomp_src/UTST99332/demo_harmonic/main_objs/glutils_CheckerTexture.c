/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_CheckerTexture", _Z41__static_initialization_and_destruction_0ii_289F0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_CheckerTexture", _ZN7glutils14CheckerTexture10check_initEv);

textures::Texture *glutils::CheckerTexture::get()
{
    check_init();
    return &_checker_texture;
}

unsigned int glutils::CheckerTexture::name()
{
    check_init();
    return _name;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_CheckerTexture", _ZN7glutils14CheckerTexture5resetEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_289F0");
void _GLOBAL__I__ZN7glutils14CheckerTexture16_checker_textureE(void);
void _GLOBAL__D__ZN7glutils14CheckerTexture16_checker_textureE(void);
}

void _GLOBAL__I__ZN7glutils14CheckerTexture16_checker_textureE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7glutils14CheckerTexture16_checker_textureE(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_CheckerTexture", _ZN6common7t_arrayIhE4addrEv);
