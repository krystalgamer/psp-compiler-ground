/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN8textures7Texture6initGlEi");
__asm__(".globl _GLOBAL__D__ZN8textures7Texture6initGlEi");

extern "C" {
void glBindTexture(unsigned int, unsigned int);
void glTexParameteri(unsigned int, unsigned int, int);
void glTexEnvi(unsigned int, unsigned int, int);
}

extern "C" void *sceGeEdramGetAddr(void);
/* Vram.h's inline Area::load (its __PRETTY_FUNCTION__ stays in the module's .rodata) */
inline unsigned int psp::Vram::Area::load(void *data, unsigned int _Bytesize)
{
    unsigned int p = _cur + _base;
    memcpy((void *)p, data, _Bytesize);
    SGL_ASSERT(_cur + _Bytesize < _end, " *** error ", "_cur + _Bytesize < _end", "../lib/gl_psp/Vram.h", __PRETTY_FUNCTION__, 115, _name.c_str());
    _cur += _Bytesize;
    return p;
}
#define TGL_ASSERT(c, t, l, m) SGL_ASSERT(c, " *** error ", t, "../lib/textures/TextureGL.cpp", __PRETTY_FUNCTION__, l, m)
void textures::Texture::initGl(int)
{
    TGL_ASSERT(width() <= 512, "width() <= 512", 85, "512x512 limit on psp");
    TGL_ASSERT(height() <= 512, "height() <= 512", 86, "512x512 limit on psp");
    unsigned int image_addr = (unsigned int)imagedata();
    /* STAND-IN: textures::Texture's last word (0x50, the VRAM copy's address) is not declared: the class is
       0x50 bytes in demo/base.hpp (CubeMap::Face::Texture declares it as its own _f50) */
    unsigned int &vaddr = *(unsigned int *)((char *)this + 0x50);
    psp::Vram &v = psp::vram;
    vaddr = v.a18.load((void *)imagedata(), image.bytesize());
    common::Log() << "transferred texture to vram+";
    common::Log().useHexa(true);
    common::Log() << (vaddr - (unsigned int)sceGeEdramGetAddr());
    common::Log().useHexa(false);
    common::Log() << " ";
    common::Log() << (int)((vaddr - (unsigned int)sceGeEdramGetAddr()) * 100.0f / 2097152.0f) << "%";
    common::Log() << " (size=" << image.bytesize() << "," << (int)(image.bytesize() * 100.0f / 2097152.0f) << "%)\n";
    TGL_ASSERT(image_addr % 16 == 0, "image_addr % 16 == 0", 114, "IMAGE DATA NOT 128 ALIGNED");
    unsigned int clut_addr = (unsigned int)clutdata();
    TGL_ASSERT(clut_addr % 16 == 0, "clut_addr % 16 == 0", 119, "CLUT DATA NOT 128 ALIGNED");
}

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

extern "C" {
void glEnable(unsigned int);
void glBlendFunc(unsigned int, unsigned int);
void glAlphaFunc(unsigned int, float);
void sceGuTexImage(int, int, int, int, const void *);
void sceGuTexMode(int, int, int, int);
void sceGuClutMode(unsigned int, unsigned int, unsigned int, unsigned int);
void sceGuClutLoad(int, const void *);
}
#define TGS_ASSERT(c, t, l) SGL_ASSERT(c, " *** error ", t, "../lib/textures/TextureGL.cpp", __PRETTY_FUNCTION__, l, " ")
static inline void tgl_TexMode(int mode, int swizzle)
{
    sceGuTexMode(mode, 0, 0, swizzle != 0);
}
bool textures::Texture::setupGl(int name, bool alpha)
{
    if (!image.addr())
        return false;
    TGS_ASSERT(valid(), "valid()", 209);
    glEnable(0xDE1);
    glBindTexture(0xDE1, name);
    setGlTextureFunc();
    if (alpha) {
        if (m.alpha_flags & 2) {
            glEnable(0xBE2);
            glBlendFunc(0x302, 0x303);
        }
        if (m.alpha_flags & 4) {
            glEnable(0xBC0);
            glAlphaFunc(0x204, 0);
        }
    }
    /* STAND-IN: textures::Texture's undeclared last word (0x50), see initGl */
    void *vaddr = *(void **)((char *)this + 0x50);
    switch (m.format) {
    case 0:
        return false;
    case 1:
    case 2:
        sceGuTexImage(0, width(), height(), width(), vaddr);
        tgl_TexMode(3, m.loaded);
        TGS_ASSERT(width() % 4 == 0, "width() % 4 == 0", 255);
        break;
    case 3:
        sceGuTexImage(0, width(), height(), width(), vaddr);
        tgl_TexMode(1, m.loaded);
        TGS_ASSERT(width() % 8 == 0, "width() % 8 == 0", 264);
        break;
    case 4:
        sceGuTexImage(0, width(), height(), width(), vaddr);
        sceGuClutMode(3, 0, 0xFF, 0);
        sceGuClutLoad(32, clutdata());
        tgl_TexMode(5, m.loaded);
        TGS_ASSERT(width() % 16 == 0, "width() % 16 == 0", 275);
        break;
    case 5:
        sceGuTexImage(0, width(), height(), width(), vaddr);
        sceGuClutMode(3, 0, 0xFF, 0);
        sceGuClutLoad(2, clutdata());
        tgl_TexMode(4, m.loaded);
        TGS_ASSERT(width() % 32 == 0, "width() % 32 == 0", 286);
        break;
    }
    setGlWrapS(name);
    setGlWrapT(name);
    setGlFiltering(name);
    return true;
}

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

void textures::Texture::drawGL()
{
    if (is32()) {
        glClear(0x4100);
        glMatrixMode(0x1701);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, 1.0, 0, 1.0);
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
