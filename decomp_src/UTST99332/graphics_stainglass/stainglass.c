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

#define SCEGU_TEXTURE                      9
#define SCEGU_SINGLE_CLUT                  0
#define SCEGU_TEXBUF_NORMAL                0
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGB                          0
#define SCEGU_VRAM_TOP        0x00000000
#define SCEGU_VRAM_BUFSIZE32  (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*4)
#define SCEGU_VRAM_BUFSIZE    (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)
#define SCEGU_NOFLIP                       0
#define SCEGU_NOROTATE                     0
#define SCEGU_DEPTH_TEST                   1
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)
#define SCEGU_PF8888                       3
#define SCEGU_VRAM_WIDTH      512
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272

void GenFrameBufferMipmap(void)
{
	sceGuTexFlush();

	sceGuOffset(0,0);

	extern int D_00016C3C;

	const unsigned int vram_top = (unsigned int)sceGeEdramGetAddr();
	const unsigned int disp_addr_rel = SCEGU_VRAM_BUFSIZE32 * D_00016C3C;
	const unsigned int disp_addr = vram_top + disp_addr_rel;
	
    D_00016C3C=1-D_00016C3C;

	sceGuTexScale( 1.f, 1.f );
	sceGuTexOffset( 0.f, 0.f );

	sceGuDisable( SCEGU_DEPTH_TEST );
	sceGuDepthMask( 1 );

	sceGuEnable( SCEGU_TEXTURE );
	sceGuTexMode( SCEGU_PF8888, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL );
	sceGuTexFunc( SCEGU_TEX_MODULATE, SCEGU_RGB );
	sceGuColor( 0xffffffff );


	
	mipmap_vram[0]=SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE32*2+SCEGU_VRAM_BUFSIZE;


	

	sceGuDrawBuffer(SCEGU_PF8888, (void*)( mipmap_vram[0] ), 256);
	sceGuViewport(0, 0, 256, 256);
	sceGuScissor(0, 0, 256, 256);
	
	sceGuTexImage( 0, SCEGU_VRAM_WIDTH, 512, SCEGU_VRAM_WIDTH, (void*)(disp_addr));
	sceGuSpriteMode( 120, 272, 64, 256 );
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	
	sceGuSpriteMode( 120, 272, 64, 256 );
	sceGuDrawSprite( 64, 0, 0, 120, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	
	sceGuSpriteMode( 120, 272, 64, 256 );
	sceGuDrawSprite( 128, 0, 0, 240, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	
	sceGuSpriteMode( 120, 272, 64, 256 );
	sceGuDrawSprite( 192, 0, 0, 360, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	

	sceGuTexFlush();

	


	mipmap_vram[1] = mipmap_vram[0] + 256 * 256 * 4; 
	
	sceGuTexImage( 0, 256, 256, 256, (void*)( vram_top + mipmap_vram[0] ) );
	sceGuDrawBuffer(SCEGU_PF8888, (void*)( mipmap_vram[1] ), 128);
	sceGuViewport(0, 0, 128, 128);
	sceGuScissor(0, 0, 128, 128);
	sceGuSpriteMode( 256, 256, 128, 128 );
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 

	sceGuTexFlush();


	
	mipmap_vram[2] = mipmap_vram[1] + 128 * 128 * 4; 

	sceGuTexImage( 0, 128, 128, 128, (void*)( vram_top + mipmap_vram[1] ) );
	sceGuDrawBuffer(SCEGU_PF8888, (void*)( mipmap_vram[2] ), 64);
	sceGuSpriteMode( 128, 128, 64, 64 );
	sceGuViewport(0, 0, 64, 64);
	sceGuScissor(0, 0, 64, 64);
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 

	sceGuTexFlush();


	
	mipmap_vram[3] = mipmap_vram[2] + 64 * 64 * 4; 

	sceGuTexImage( 0, 64, 64, 64, (void*)( vram_top + mipmap_vram[2] ) );
	sceGuDrawBuffer(SCEGU_PF8888, (void*)( mipmap_vram[3] ), 32);
	sceGuSpriteMode( 64, 64, 32, 32 );
	sceGuViewport(0, 0, 32, 32);
	sceGuScissor(0, 0, 32, 32);
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 

	sceGuTexFlush();


	
	mipmap_vram[4] = mipmap_vram[3] + 32 * 32 * 4; 

	sceGuTexImage( 0, 32, 32, 32, (void*)( vram_top + mipmap_vram[3] ) );
	sceGuDrawBuffer(SCEGU_PF8888, (void*)( mipmap_vram[4] ), 16);
	sceGuViewport(0, 0, 16, 16);
	sceGuScissor(0, 0, 16, 16);
	sceGuSpriteMode( 32, 32, 16, 16 );
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 

	sceGuTexFlush();
	



	sceGuEnable( SCEGU_DEPTH_TEST );
	sceGuOffset(SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY);
	sceGuViewport(2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDrawBuffer(SCEGU_PF8888, (void*)disp_addr_rel,SCEGU_VRAM_WIDTH );
	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDepthMask( 0 );
}

#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#define SCEGU_LINEAR                       1
#define SCEGU_TEXBUF_FAST                  1
#define SCEGU_LOD_AUTO                     0
#define SCEGU_CLAMP                        1

void UseFrameBufferMipmap(void)
{
	const unsigned int vram_top = (unsigned int)sceGeEdramGetAddr();

	sceGuEnable( SCEGU_TEXTURE );

	sceGuTexFilter( SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR );
	sceGuTexImage( 0, 256, 256, 256, (void*)( vram_top + mipmap_vram[0] ) );
	sceGuTexImage( 1, 128, 128, 128, (void*)( vram_top + mipmap_vram[1] ) );
	sceGuTexImage( 2, 64, 64, 64, (void*)( vram_top + mipmap_vram[2] ) );
	sceGuTexImage( 3, 32, 32, 32, (void*)( vram_top + mipmap_vram[3] ) );
	sceGuTexImage( 4, 16, 16, 16, (void*)( vram_top + mipmap_vram[4] ) );
	sceGuTexMode( SCEGU_PF8888, 4, SCEGU_SINGLE_CLUT, (refraction_texture_fast)?SCEGU_TEXBUF_FAST:SCEGU_TEXBUF_NORMAL );
	sceGuTexLevelMode( SCEGU_LOD_AUTO, 0.0f );
	sceGuTexFunc( SCEGU_TEX_MODULATE, SCEGU_RGB );
	sceGuTexWrap( SCEGU_CLAMP, SCEGU_CLAMP );
}

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

ScePspFVector2 Rand()
{
	ScePspFVector2 retval;

	__asm__ volatile (
		".set			push\n"					
		".set			noreorder\n"			
		"vfim.s	s010, 1.5    		\n"
		"vfim.s	s011, 1.5    		\n"
		"vrndf1.p c000				\n"
		"vsub.p	c000, c000, c010	\n"
		"sv.s	s000, %0			\n"     
		"sv.s	s001, %1			\n"     
		".set			pop\n"					
		: "=m" (retval.x), "=m" (retval.y) :
	);

	return retval;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", ColorAt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", OffsetAt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassInit);

void StainGlassRelease(void)
{
	free(_vertices);
	free(_offsets);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassDraw);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassSetTransform);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/stainglass", StainGlassSetDistorsion);
