#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
typedef int bool;
typedef short unsigned int u_int16;

extern u_int32 _zclut[256];
extern u_int32 _idclut[32];
extern u_int32 _redclut[32];
extern u_int32 _16to32clut[32];
extern float _distort;
extern float _focus;
extern unsigned int scratch;
extern unsigned int format;

u_int32 MakeRGBA8888(float rf, float gf, float bf, float af);
void GenFrameBufferBlurmap(unsigned int _TexFormat, bool _Copy, bool _CheapZ, bool _32bitframe, bool _Final32);
void UseFrameBufferBlurmap(void);
void DepthBlurUpdate(void);
void DepthBlurDraw(void);


INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", MakeRGBA8888);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", GenFrameBufferBlurmap);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", UseFrameBufferBlurmap);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", DepthBlurUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", DepthBlurDraw);

void DepthBlurSetFocus(float _Focus) {
    _focus = _Focus;
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_00017890);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_00017894);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_00017898);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_0001789C);
