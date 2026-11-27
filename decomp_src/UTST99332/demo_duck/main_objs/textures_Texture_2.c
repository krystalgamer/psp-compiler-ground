/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" {
void glBindTexture(unsigned int, unsigned int);
void glTexParameteri(unsigned int, unsigned int, int);
void glTexEnvi(unsigned int, unsigned int, int);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _Z41__static_initialization_and_destruction_0ii_106860);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture6initGlEi);

void textures::Texture::setGlFiltering(int name)
{
    glBindTexture(0xDE1, name);
    int f = getFiltering() == 1 ? 0x2600 : 0x2601;
    glTexParameteri(0xDE1, 0x2800, f);
    glTexParameteri(0xDE1, 0x2801, f);
}

void textures::Texture::setGlWrapS(int name)
{
    glBindTexture(0xDE1, name);
    glTexParameteri(0xDE1, 0x2802, !getWrapS() ? 0x2900 : 0x2901);
}

void textures::Texture::setGlWrapT(int name)
{
    glBindTexture(0xDE1, name);
    glTexParameteri(0xDE1, 0x2803, !getWrapT() ? 0x2900 : 0x2901);
}

void textures::Texture::setGlTextureFunc()
{
    int mode = 0x2100;
    switch (getTextureFunc()) {
    case 0:
        mode = 0x2100;
        break;
    case 1:
        mode = 0x2101;
        break;
    case 2:
        mode = 0xBE2;
        break;
    case 3:
        mode = 0x1E01;
        break;
    }
    glTexEnvi(0x2300, 0x2200, mode);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture7setupGlEib);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture6drawGLEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_106860");
void _GLOBAL__I__ZN8textures7Texture6initGlEi(void);
void _GLOBAL__D__ZN8textures7Texture6initGlEi(void);
}

void _GLOBAL__I__ZN8textures7Texture6initGlEi(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN8textures7Texture6initGlEi(void)
{
    static_init(0, 0xFFFF);
}

