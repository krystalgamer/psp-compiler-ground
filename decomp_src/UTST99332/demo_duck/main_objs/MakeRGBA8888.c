/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" const float D_001632F8, D_001632FC, D_00163300;

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

void DepthBlurIncrFocus()
{
    _focus += D_001632F8;
    if (_focus > D_001632FC)
        _focus = D_001632FC;
}

void DepthBlurDecrFocus()
{
    _focus -= D_00163300;
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

