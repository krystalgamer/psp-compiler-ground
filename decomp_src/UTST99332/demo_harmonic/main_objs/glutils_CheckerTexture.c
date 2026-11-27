/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN7glutils14CheckerTexture16_checker_textureE");
__asm__(".globl _GLOBAL__D__ZN7glutils14CheckerTexture16_checker_textureE");

textures::Texture glutils::CheckerTexture::_checker_texture;
/* textures::Texture is 0x54 bytes (demo/base.hpp declares 0x50) */
__asm__(".section .bss\n\t.space 4\n\t.previous");
unsigned int glutils::CheckerTexture::_name;
bool glutils::CheckerTexture::_init;

namespace gl {
void DeleteTextures(int, const unsigned int *);
}

void glutils::CheckerTexture::check_init()
{
    if (_init)
        return;
    _checker_texture.makeDummy(32, 32);
    unsigned char *p = _checker_texture.image.addr();
    for (int y = 0; y < _checker_texture.height(); y++)
        for (int x = 0; x < _checker_texture.width(); x++) {
            unsigned char c = 255 - ((x + y) & 1) * 63;
            p[0] = p[1] = p[2] = p[3] = c;
            p += 4;
        }
    _checker_texture.setWrapS(textures::Wrapping(1));
    _checker_texture.setWrapT(textures::Wrapping(1));
    gl::GenTextures(1, &_name);
    _checker_texture.initGl(_name);
    _init = true;
}

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
