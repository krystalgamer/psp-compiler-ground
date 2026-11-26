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


/* SDK prototypes (tools/sdk_protos.h) */
float powf(float x, float y);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuColor(unsigned int color);
void sceGuDepthMask(int mask);
void sceGuDisable(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);
void sceGuEnable(int state);
unsigned int sceGuGetAllStatus(void);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuPixelMask(unsigned int mask);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetAllStatus(unsigned int status);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void sceGuTexFilter(int min, int mag);
void sceGuTexFlush(void);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexLevelMode(unsigned int mode, float bias);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuTexSync(void);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", MakeRGBA8888);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", GenFrameBufferBlurmap);

#ifndef SCEGU_TEXTURE /* sample */
#define SCEGU_TEXTURE                      9
#endif
#ifndef SCEGU_LINEAR_MIPMAP_LINEAR /* sample */
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#endif
#ifndef SCEGU_LINEAR /* sample */
#define SCEGU_LINEAR                       1
#endif
#ifndef SCEGU_SINGLE_CLUT /* sample */
#define SCEGU_SINGLE_CLUT                  0
#endif
#ifndef SCEGU_TEXBUF_NORMAL /* sample */
#define SCEGU_TEXBUF_NORMAL                0
#endif
#ifndef SCEGU_LOD_CONSTANT /* sample */
#define SCEGU_LOD_CONSTANT                 1
#endif
#ifndef SCEGU_TEX_MODULATE /* sample */
#define SCEGU_TEX_MODULATE                 0
#endif
#ifndef SCEGU_RGBA /* sample */
#define SCEGU_RGBA                         1
#endif
#ifndef SCEGU_CLAMP /* sample */
#define SCEGU_CLAMP                        1
#endif
void UseFrameBufferBlurmap(void)
{
	const unsigned int vram_top = (unsigned int)sceGeEdramGetAddr();

	sceGuEnable( SCEGU_TEXTURE );

	sceGuTexFilter( SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR );
	sceGuTexImage( 0, 256, 128, 256, (void*)(vram_top+scratch));
	sceGuTexMode( format, 4, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL );
	sceGuTexLevelMode( SCEGU_LOD_CONSTANT, 0.0f );
	sceGuTexFunc( SCEGU_TEX_MODULATE, SCEGU_RGBA );
	sceGuTexWrap( SCEGU_CLAMP, SCEGU_CLAMP );
	sceGuTexScale(  1.f, 1.f );
	sceGuTexOffset( 0.f, 0.f );
	sceGuTexFlush();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", DepthBlurUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", DepthBlurDraw);

void DepthBlurSetFocus(float _Focus) {
    _focus = _Focus;
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_00017890);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_00017894);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_00017898);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/depthblur", D_0001789C);
