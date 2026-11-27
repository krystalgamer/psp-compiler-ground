/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" const float D_00160858, D_0016085C, D_00160860;
extern "C" const char D_0016076C[], D_00160774[], D_001607A8[];
extern "C" {
void sceGuDebugPrint(int, int, unsigned int, const char *);
void sceGuTexFilter(int, int);
void sceGuTexImage(int, int, int, int, const void *);
void sceGuTexMode(int, int, int, int);
void sceGuTexWrap(int, int);
void sceGuTexScale(float, float);
void sceGuTexOffset(float, float);
void sceGuTexFlush(void);
void sceGuAlphaFunc(int, int, int);
void sceGuColor(unsigned int);
void sceGuSpriteMode(int, int, int, int);
void sceGuDrawSprite(int, int, int, int, int, int, int);
extern const float D_00160854, D_0016087C;
}
extern int scratch;
extern int format;
extern float _distort;
struct DepthBlurMode {
    unsigned int blur;
    bool enabled, b5, b6;
    const char *name;
};
extern DepthBlurMode DEPTHBLUR_MODES[];
void GenFrameBufferBlurmap(unsigned int, bool, bool, bool, bool);

unsigned int MakeRGBA8888(float r, float g, float b, float a)
{
    unsigned int c;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lv.s S000, %1\n"
        "lv.s S001, %2\n"
        "lv.s S002, %3\n"
        "lv.s S003, %4\n"
        "vsat0.q C000, C000\n"
        "vf2iz.q C000, C000, 31\n"
        "vi2uc.q S000, C000\n"
        "sv.s S000, %0\n"
        ".set pop\n"
        : "=m"(c) : "m"(r), "m"(g), "m"(b), "m"(a));
    return c;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/MakeRGBA8888", _Z21GenFrameBufferBlurmapjbbbb);

void UseFrameBufferBlurmap()
{
    char *edram = (char *)sceGeEdramGetAddr();
    sceGuEnable(9);
    sceGuTexFilter(7, 1);
    sceGuTexImage(0, 256, 128, 256, edram + scratch);
    if (_depthblur_debug) {
        if (format == 3)
            sceGuTexImage(0, 256, 128, 256, edram + scratch + 0x20000);
        sceGuTexMode(0, 4, 0, 0);
    } else
        sceGuTexMode(format, 4, 0, 0);
    sceGuTexLevelMode(1, 0);
    sceGuTexFunc(0, 1);
    sceGuTexWrap(1, 1);
    sceGuTexScale(D_00160854, D_00160854);
    sceGuTexOffset(0, 0);
    sceGuTexFlush();
}

void DepthBlurSetRange(int r)
{
    _depthrange = r;
}

void DepthBlurIncrRange()
{
    _depthrange++;
    if (_depthrange > 255)
        _depthrange = 255;
}

void DepthBlurDecrRange()
{
    _depthrange--;
    if (_depthrange < 8)
        _depthrange = 8;
}

int DepthBlurGetRange()
{
    return _depthrange;
}

void DepthBlurSetFocus(float f)
{
    _focus = f;
}

void DepthBlurIncrFocus()
{
    _focus += D_00160858;
    if (_focus > D_0016085C)
        _focus = D_0016085C;
}

void DepthBlurDecrFocus()
{
    _focus -= D_00160860;
    if (_focus < 0)
        _focus = 0;
}

float DepthBlurGetFocus()
{
    return _focus;
}

void DepthBlurCycleDebugMode()
{
    _depthblur_debug++;
    if (_depthblur_debug >= 3)
        _depthblur_debug = 0;
}

int DepthBlurGetDebugMode()
{
    return _depthblur_debug;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/MakeRGBA8888", _Z15DepthBlurUpdatev);

void DepthBlurDraw()
{
    UseFrameBufferBlurmap();
    sceGuDisable(5);
    sceGuDisable(10);
    sceGuDisable(4);
    sceGuDisable(1);
    sceGuEnable(9);
    if (!_depthblur_debug)
        sceGuEnable(4);
    sceGuBlendFunc(0, 2, 3, 0, 0);
    sceGuAlphaFunc(1, 0, 0xFF);
    sceGuColor(MakeRGBA8888(D_0016087C, D_0016087C, D_0016087C, _distort));
    sceGuTexLevelMode(1, 0);
    sceGuSpriteMode(0x40, 0x80, 0x78, 0x110);
    sceGuDrawSprite(0, 0, 0, 0, 0, 0, 0);
    sceGuDrawSprite(0x78, 0, 0, 0x40, 0, 0, 0);
    sceGuDrawSprite(0xF0, 0, 0, 0x80, 0, 0, 0);
    sceGuDrawSprite(0x168, 0, 0, 0xC0, 0, 0, 0);
    sceGuColor(MakeRGBA8888(D_0016087C, D_0016087C, D_0016087C, D_0016087C));
    sceGuEnable(9);
    sceGuEnable(1);
    sceGuEnable(10);
    sceGuTexFlush();
}

void DepthBlurNextMode()
{
    depthblur_mode++;
    if (depthblur_mode >= 5)
        depthblur_mode = 0;
}

void DepthBlurSetMode(int m)
{
    if (m >= 5)
        return;
    if (m < 0)
        return;
    depthblur_mode = m;
}

void DepthBlurToggleSpread()
{
    depthspread = !depthspread;
}

void DepthBlurPrint()
{
    char buf[128];
    sprintf(buf, D_00160774, DEPTHBLUR_MODES[depthblur_mode].name, DepthBlurGetFocus(), depthspread ? D_0016076C : D_001607A8, DepthBlurGetRange(), DepthBlurGetDebugMode());
    sceGuDebugPrint(0, 10, 0xFF, buf);
}

void DepthBlurIdle()
{
    const DepthBlurMode &m = DEPTHBLUR_MODES[depthblur_mode];
    if (m.enabled) {
        bool v = psp::vram.f0 == 3;
        GenFrameBufferBlurmap(m.blur, m.b5, !depthspread, v, m.b6);
        DepthBlurUpdate();
        DepthBlurDraw();
    }
}

