#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", MakeRGBA8888);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", GenFrameBufferBlurmap);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", UseFrameBufferBlurmap);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", DepthBlurUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", DepthBlurDraw);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", DepthBlurSetFocus);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_00017890);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_00017894);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_00017898);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_0001789C);
