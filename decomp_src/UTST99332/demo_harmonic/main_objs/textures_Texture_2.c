/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN8textures7Texture6initGlEi\n_GLOBAL__I__ZN8textures7Texture6initGlEi = _GLOBAL__I__ZN8textures7Texture6initGlEi__asm");
__asm__(".globl _GLOBAL__D__ZN8textures7Texture6initGlEi\n_GLOBAL__D__ZN8textures7Texture6initGlEi = _GLOBAL__D__ZN8textures7Texture6initGlEi__asm");

extern "C" {
void glBindTexture(unsigned int, unsigned int);
void glTexParameteri(unsigned int, unsigned int, int);
void glTexEnvi(unsigned int, unsigned int, int);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture6initGlEi);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture7setupGlEib);

extern "C" {
void glClear(unsigned int);
void glMatrixMode(unsigned int);
void glPushMatrix(void);
void glPopMatrix(void);
void glLoadIdentity(void);
void gluOrtho2D(double, double, double, double);
void glRasterPos2i(int, int);
void glDrawPixels(int, int, unsigned int, unsigned int, const void *);
}
extern const double D_001742B0;

void textures::Texture::drawGL()
{
    if (is32()) {
        glClear(0x4100);
        glMatrixMode(0x1701);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, D_001742B0, 0, D_001742B0);
        glMatrixMode(0x1700);
        glPushMatrix();
        glLoadIdentity();
        glRasterPos2i(0, 0);
        glDrawPixels(width(), height(), 0x1908, 0x1401, imagedata());
        glMatrixMode(0x1701);
        glPopMatrix();
        glMatrixMode(0x1700);
        glPopMatrix();
    }
}
