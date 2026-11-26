#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void free(void *p);
void *malloc(unsigned int size);
void sceGuColor(unsigned int color);
void sceGuDepthMask(int mask);
void sceGuDisable(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);
void sceGuEnable(int state);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void sceGuTexFilter(int min, int mag);
void sceGuTexFlush(void);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexLevelMode(unsigned int mode, float bias);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
float sqrtf(float x);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", MakeRGBA8888);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", float2ushort);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", MatrixVectorMultiply);

void MatrixMatrixMultiply(void) {
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", _nx);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", _ny);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", GenFrameBufferMipmap);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", UseFrameBufferMipmap);

void RandSeed( unsigned int val )
{
	__asm__ volatile (
		".set			push\n"					
		".set			noreorder\n"			
		"lv.s s000, %0	        \n"
		"vrnds.s s000          \n"
		".set			pop\n"					
		: : "m" (val)
		);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", Rand);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", ColorAt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", OffsetAt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassInit);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassRelease);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassDraw);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassSetTransform);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassSetDistorsion);
