/* lang: c++ */
/* cflags: -O2 -frename-registers */
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/MakeRGBA8888", _Z12MakeRGBA8888ffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/MakeRGBA8888", _Z21GenFrameBufferBlurmapjbbbb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/MakeRGBA8888", _Z21UseFrameBufferBlurmapv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/MakeRGBA8888", _Z18DepthBlurIncrFocusv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/MakeRGBA8888", _Z18DepthBlurDecrFocusv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/MakeRGBA8888", _Z15DepthBlurUpdatev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/MakeRGBA8888", _Z13DepthBlurDrawv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/MakeRGBA8888", _Z14DepthBlurPrintv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/MakeRGBA8888", _Z13DepthBlurIdlev);

