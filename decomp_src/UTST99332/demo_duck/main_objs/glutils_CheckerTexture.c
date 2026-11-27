/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

namespace gl {
void DeleteTextures(int, const unsigned int *);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_CheckerTexture", _Z41__static_initialization_and_destruction_0ii_23318);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_CheckerTexture", _ZN7glutils14CheckerTexture10check_initEv);

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

void glutils::CheckerTexture::reset()
{
    if (_init) {
        if (_name) {
            gl::DeleteTextures(1, &_name);
            _name = 0;
        }
        _checker_texture.reset(true);
        _init = false;
    }
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_23318");
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_CheckerTexture", _ZN6common7t_arrayIhE4addrEv);
