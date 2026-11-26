#include "common.h"
#include <psptypes.h>
#include <libgu.h>
#include <libgum.h>

/* types and file-scope data from the SDK sample's stainglass.c (data defined in the asm data files) */
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef int bool;
#define true 1
#define false 0

typedef struct
{
	u_short   s, t;
	u_int     c;
	float     vx, vy, vz;
} __attribute__((packed)) VTypeT16C32V32;

extern float _scale;
extern float _sx;
extern float _sy;

extern int _num_vertices;
extern VTypeT16C32V32* _vertices;
extern ScePspFVector2 *_offsets;
extern ScePspMatrix4 _transform;

extern bool refraction_texture_fast;

extern unsigned int mipmap_vram[5];


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

u_int32 MakeRGBA8888(float rf,float gf,float bf, float af)
{
	u_int32 result;
	__asm__(
		"lv.s		s000, %1		\n"
		"lv.s		s001, %2		\n"
		"lv.s		s002, %3		\n"
		"lv.s		s003, %4		\n"
		"vsat0.q		c000, c000		\n"	
		"vf2iz.q		c000, c000, 31		\n"	
		"vi2uc.q		c000, c000		\n"	
		"sv.s		s000, %0		\n"
		: "=m" (result)
		: "m" (rf)
		, "m" (gf)
		, "m" (bf)
		, "m" (af)
		);
	return result;
}

u_short float2ushort( float val )
{
	int retval;

	__asm__ (
		".set			push\n"		
		".set			noreorder\n"	
		"lv.s s000, %1			\n"
		"vsat0.s s000,s000	     \n"
		"vf2iz.s s000,s000,15	\n"
		"sv.s s000, %0			\n"
		".set			pop\n"		
		: "=m" (retval)
		: "m" (val));

	return retval;
}

void MatrixVectorMultiply(
	ScePspFVector4 *retval, const ScePspFMatrix4 *m, const ScePspFVector4 *v)
{
	__asm__ volatile (
		".set			push\n"					
		".set			noreorder\n"			
		"lv.q			c100,  0+%1\n"
		"lv.q			c110, 16+%1\n"
		"lv.q			c120, 32+%1\n"
		"lv.q			c130, 48+%1\n"
		"lv.q			c200,  %2\n"
		"vtfm4.q		c000, e100, c200\n"
		"sv.q			c000,  %0\n"
		".set			pop\n"					
		: "=m" (*retval)
		: "m"(*m), "m" (*v)
		);
}

void MatrixMatrixMultiply(void) {
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", _nx);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", _ny);

#define _nx 48
#define _ny 48

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
