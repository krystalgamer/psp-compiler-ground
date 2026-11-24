#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", MakeRGBA8888);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", float2ushort);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", MatrixVectorMultiply);

void MatrixMatrixMultiply(void) {
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", _nx);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", _ny);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", GenFrameBufferMipmap);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", UseFrameBufferMipmap);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", RandSeed);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", Rand);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", ColorAt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", OffsetAt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassInit);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassRelease);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassDraw);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassSetTransform);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassSetDistorsion);
