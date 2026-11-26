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
