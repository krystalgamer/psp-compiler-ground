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

u_int32 MakeRGBA8888(float rf,float gf,float bf, float af)
{
	u_int32 result;
	__asm__(
		"lv.s		s000, %1		\n"
		"lv.s		s001, %2		\n"
		"lv.s		s002, %3		\n"
		"lv.s		s003, %4		\n"
		"vsat0.q	c000, c000		\n"	
		"vf2iz.q	c000, c000, 31	\n"	
		"vi2uc.q	c000, c000		\n"	
		"sv.s		s000, %0		\n"
		: "=m" (result)
		: "m" (rf)
		, "m" (gf)
		, "m" (bf)
		, "m" (af)
		);
	return result;
}

#ifndef SCEGU_VRAM_BUFSIZE32 /* sample */
#define SCEGU_VRAM_BUFSIZE32  (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*4)
#endif
#ifndef SCEGU_VRAM_BUFSIZE /* sample */
#define SCEGU_VRAM_BUFSIZE    (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)
#endif
#ifndef SCEGU_PF4444 /* sample */
#define SCEGU_PF4444                       2
#endif
#ifndef SCEGU_TEX_MODULATE /* sample */
#define SCEGU_TEX_MODULATE                 0
#endif
#ifndef SCEGU_RGBA /* sample */
#define SCEGU_RGBA                         1
#endif
#ifndef SCEGU_LOD_CONSTANT /* sample */
#define SCEGU_LOD_CONSTANT                 1
#endif
#ifndef SCEGU_TEXTURE /* sample */
#define SCEGU_TEXTURE                      9
#endif
#ifndef SCEGU_GREATER /* sample */
#define SCEGU_GREATER                      6
#endif
#ifndef SCEGU_ALPHA_TEST /* sample */
#define SCEGU_ALPHA_TEST                   0
#endif
#ifndef SCEGU_NEAREST /* sample */
#define SCEGU_NEAREST                      0
#endif
#ifndef SCEGU_PFIDX16 /* sample */
#define SCEGU_PFIDX16                      6
#endif
#ifndef SCEGU_LINEAR_MIPMAP_LINEAR /* sample */
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#endif
#ifndef SCEGU_LINEAR /* sample */
#define SCEGU_LINEAR                       1
#endif
#ifndef SCEGU_ADD /* sample */
#define SCEGU_ADD                          0
#endif
#ifndef SCEGU_FIX_VALUE /* sample */
#define SCEGU_FIX_VALUE                   10
#endif
#ifndef SCEGU_BLEND /* sample */
#define SCEGU_BLEND                        4
#endif
#ifndef SCEGU_SINGLE_CLUT /* sample */
#define SCEGU_SINGLE_CLUT                  0
#endif
#ifndef SCEGU_TEXBUF_NORMAL /* sample */
#define SCEGU_TEXBUF_NORMAL                0
#endif
#ifndef SCEGU_VRAM_TOP /* sample */
#define SCEGU_VRAM_TOP        0x00000000
#endif
#ifndef SCEGU_NOFLIP /* sample */
#define SCEGU_NOFLIP                       0
#endif
#ifndef SCEGU_NOROTATE /* sample */
#define SCEGU_NOROTATE                     0
#endif
#ifndef SCEGU_DITHER /* sample */
#define SCEGU_DITHER                       6
#endif
#ifndef SCEGU_DEPTH_TEST /* sample */
#define SCEGU_DEPTH_TEST                   1
#endif
#ifndef SCEGU_SCR_OFFSETX /* sample */
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#endif
#ifndef SCEGU_SCR_OFFSETY /* sample */
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)
#endif
#ifndef SCEGU_PF8888 /* sample */
#define SCEGU_PF8888                       3
#endif
#ifndef SCEGU_PF5650 /* sample */
#define SCEGU_PF5650                       0
#endif
#ifndef SCEGU_VRAM_WIDTH /* sample */
#define SCEGU_VRAM_WIDTH      512
#endif
#ifndef SCEGU_SCR_WIDTH /* sample */
#define SCEGU_SCR_WIDTH       480
#endif
#ifndef SCEGU_SCR_HEIGHT /* sample */
#define SCEGU_SCR_HEIGHT      272
#endif
void GenFrameBufferBlurmap(unsigned int _TexFormat,bool _Copy,bool _CheapZ,
	bool _32bitframe, bool _Final32)
{
	sceGuTexFlush();

	extern int D_00019138;

	const unsigned int vram_top = (unsigned int)sceGeEdramGetAddr();
	const unsigned int disp_addr_rel =
		(_32bitframe ? SCEGU_VRAM_BUFSIZE32 : SCEGU_VRAM_BUFSIZE) * D_00019138;
	const unsigned int disp_addr = vram_top + disp_addr_rel;
	
	scratch = _32bitframe ? (SCEGU_VRAM_BUFSIZE32*2+SCEGU_VRAM_BUFSIZE)
			: (SCEGU_VRAM_BUFSIZE*3);
	const unsigned int zread = _32bitframe ? SCEGU_VRAM_BUFSIZE32*2 + 0x600000
			: (SCEGU_VRAM_BUFSIZE*2)+0x200000;
	
	D_00019138=1-D_00019138;
	
	
	unsigned int tex_format = _TexFormat; 
	unsigned int tex_depth = (_TexFormat == SCEGU_PF8888 ? 4 : 2);
	bool thirtytwo = _Final32; 
	unsigned int final_format = ( thirtytwo ) ? SCEGU_PF8888 : SCEGU_PF4444; 
	format = final_format;
	bool tex_copy = _Copy;
	unsigned int blur_top = tex_copy ? 256*128*tex_depth :
		( thirtytwo ) ? 256*128*4 : 256*128*2;
	unsigned int tex_buffer = (tex_copy) ? 256*128*(thirtytwo ? 4 : 2) : 0;
	bool z_copy = thirtytwo;
	unsigned int z_work = ( thirtytwo ) ? 256*128*4 : 0;
	
	
	_distort = fabs(_focus-0.5f)*0.2f+0.8;
	unsigned int blur = _distort*255;
	blur = blur | (blur << 8) | (blur << 16) | (blur << 24);
	
	
	
	unsigned int blat = (_focus*2.5f*255);
	if(blat > 255)
		blat = 255;

	sceGuTexScale( 1.f, 1.f );
	sceGuTexOffset( 0.f, 0.f );

	sceGuDisable( SCEGU_DEPTH_TEST );
	sceGuDepthMask( 1 );
	
	sceGuEnable( SCEGU_TEXTURE );
	sceGuTexFunc( SCEGU_TEX_MODULATE, SCEGU_RGBA );
	sceGuColor( 0xffffffff );
	
	
	sceGuDisable( SCEGU_DITHER );
	
	sceGuTexLevelMode( SCEGU_LOD_CONSTANT, 0 );
	
	sceGuTexImage(0,512,512,512,((char*)zread+vram_top));
	sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR);
	
	
	
	
	sceGuClutLoad( 32, _zclut );
	sceGuClutMode( SCEGU_PF8888,7,0xff,0);
 	sceGuTexMode(SCEGU_PFIDX16,0,SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
	
	
	sceGuDrawBuffer(SCEGU_PF5650, (void*)(SCEGU_VRAM_TOP+scratch+z_work), 256);
	sceGuSpriteMode( 120, 272, 64, 128 );
	sceGuViewport(0, 0, 256, 128);
	sceGuScissor(0, 0, 256, 128);
	
	
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDrawSprite( 64, 0, 0, 120, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDrawSprite( 128, 0, 0, 240, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDrawSprite( 192, 0, 0, 360, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 

	sceGuTexFlush();
	if(!_CheapZ)
	{
		
		
		sceGuTexMode(SCEGU_PFIDX16,0,SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuClutLoad( 4, _idclut );
		sceGuClutMode( SCEGU_PF8888,0,0x1f,0);
		 
		sceGuTexImage(0,256,128,256,
			((char*)SCEGU_VRAM_TOP+scratch+z_work)+vram_top);
		sceGuDrawBuffer(SCEGU_PF5650,
			(void*)(SCEGU_VRAM_TOP+scratch+z_work)+256*128*2, 128);
		sceGuSpriteMode( 128, 128, 64, 64 );
		sceGuViewport(0, 0, 128, 64);
		sceGuScissor(0, 0, 128, 64);
		sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
		sceGuDrawSprite( 64, 0, 0, 128, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
		sceGuTexFlush();
	
	
		
		
		
		sceGuTexImage(0,128,64,128,
			((char*)SCEGU_VRAM_TOP+scratch+z_work)+vram_top+256*128*2);
		sceGuDrawBuffer(SCEGU_PF5650,
			(void*)(SCEGU_VRAM_TOP+scratch+z_work+256*128*2), 128);
		
		sceGuViewport(0, 0, 128, 64);
		sceGuScissor(0, 0, 128, 64);
		sceGuSpriteMode( 128, 64, 128, 64 );
		
		sceGuPixelMask(0xffffff00);
		
		sceGuEnable(SCEGU_BLEND);
		sceGuBlendFunc( SCEGU_ADD , SCEGU_FIX_VALUE,SCEGU_FIX_VALUE,
			0x60606060,0xffffffff);
		sceGuEnable(SCEGU_ALPHA_TEST);
		sceGuAlphaFunc(SCEGU_GREATER,blat,0xff);
		
		
		sceGuColor(0xffffffff);
		
		sceGuDrawSprite( 0, 2, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
		sceGuDrawSprite( 2, -2, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
		sceGuDrawSprite( -2, -2, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
		sceGuTexSync();
		
		sceGuTexFlush();
		sceGuPixelMask(0x00000000);
		
		sceGuColor(0xffffffff);
		sceGuDisable(SCEGU_BLEND);
		sceGuDisable(SCEGU_ALPHA_TEST);
		sceGuEnable(SCEGU_TEXTURE);
		
		sceGuTexFlush();
		
		
		sceGuTexMode(SCEGU_PFIDX16,0,SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuClutLoad( 2, _redclut );
		sceGuClutMode( SCEGU_PF8888,1,0xf,0);
		
		sceGuTexImage(0,128,64,128,
			((char*)SCEGU_VRAM_TOP+scratch+z_work)+vram_top+256*128*2);
		
		
		
		sceGuEnable(SCEGU_ALPHA_TEST);
		
		sceGuAlphaFunc(SCEGU_GREATER,blat,0xff);
		
		sceGuViewport(0, 0, 256, 128);
		sceGuScissor(0, 0, 256, 128);
		sceGuDrawBuffer(SCEGU_PF5650,
			(void*)(SCEGU_VRAM_TOP+scratch+z_work), 256);
		sceGuSpriteMode( 128, 64, 256, 128 );
		sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
		sceGuDisable(SCEGU_ALPHA_TEST);

	}
	
	if(z_copy)
	{
		sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_NEAREST);
		
		
		sceGuTexMode(SCEGU_PFIDX16,0,SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuClutLoad( 4, _16to32clut );
		sceGuClutMode( SCEGU_PF8888,11,0x1f,0);
		
		
		sceGuTexImage(0,256,128,256,
			((char*)SCEGU_VRAM_TOP+scratch+z_work)+vram_top);
		sceGuViewport(0, 0, 256, 128);
		sceGuScissor(0, 0, 256, 128);
		sceGuDrawBuffer(SCEGU_PF5650, (void*)(SCEGU_VRAM_TOP+scratch), 512);
		sceGuSpriteMode( 128,128, 256, 128 );
		sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
		
		sceGuDrawBuffer(SCEGU_PF5650,
			(void*)(SCEGU_VRAM_TOP+scratch+256*2), 512);
		
		
		sceGuDrawSprite( 0, 0, 0, 128, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
		
		
		sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR);
	}
	
	if(!thirtytwo)
	{
		sceGuEnable( SCEGU_DITHER );
	}
	sceGuTexMode( _32bitframe ? SCEGU_PF8888 : SCEGU_PF5650, 0,
			SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL );

	
	sceGuTexImage( 0, SCEGU_VRAM_WIDTH, 512, SCEGU_VRAM_WIDTH,
		(void*)disp_addr );
	sceGuDrawBuffer(tex_copy ? tex_format : final_format,
		(void*)(SCEGU_VRAM_TOP+scratch+tex_buffer), 256);
	sceGuViewport(0, 0, 256, 128);
	sceGuScissor(0, 0, 256, 128);
	
	sceGuSpriteMode( 120, 272, 64, 128 );
	
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDrawSprite( 64, 0, 0, 120, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDrawSprite( 128, 0, 0, 240, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDrawSprite( 192, 0, 0, 360, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	
	sceGuTexFlush();
	
	
	sceGuTexMode( tex_copy ? tex_format : final_format, 0, SCEGU_SINGLE_CLUT,
		SCEGU_TEXBUF_NORMAL );

	sceGuTexImage( 0, 256, 128, 256, (void*)(vram_top+scratch+tex_buffer)  );
	sceGuDrawBuffer(tex_format,
		(void*)(SCEGU_VRAM_TOP+scratch+tex_buffer+blur_top), 128);
	sceGuViewport(0, 0, 128, 64);
	sceGuScissor(0, 0, 128, 64);
	sceGuSpriteMode( 128, 128, 64, 64 );
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDrawSprite( 64, 0, 0, 128, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	
	sceGuTexFlush();
	
	sceGuTexMode( tex_format, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL );

	
	sceGuTexImage( 0, 128, 64, 128,
		(void*)(vram_top+(int)scratch+tex_buffer+blur_top ) );
	sceGuDrawBuffer(tex_format,
		(void*)(SCEGU_VRAM_TOP+scratch+tex_buffer+blur_top+128*64*tex_depth), 64);
	sceGuViewport(0, 0, 64, 32);
	sceGuScissor(0, 0, 64, 32);
	sceGuSpriteMode( 128, 64, 64, 32 );
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuTexFlush();
	
	
	sceGuEnable(SCEGU_BLEND);
	sceGuBlendFunc( SCEGU_ADD , SCEGU_FIX_VALUE,SCEGU_FIX_VALUE,blur,~blur);
	sceGuTexMode( tex_format, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL );
	sceGuTexImage( 0, 64, 32, 64,
		(void*)(vram_top+(int)scratch+tex_buffer+blur_top + 128*64*tex_depth));
	sceGuDrawBuffer(tex_format,
		(void*)(SCEGU_VRAM_TOP+scratch+tex_buffer+blur_top), 128);
	sceGuSpriteMode( 64, 32, 128, 64 );
	sceGuViewport(0, 0, 128, 64);
	sceGuScissor(0, 0, 128, 64);
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDisable(SCEGU_BLEND);

	sceGuTexFlush();
	
	
	
	
	
	
	
	sceGuEnable(SCEGU_BLEND);
	sceGuBlendFunc( SCEGU_ADD , SCEGU_FIX_VALUE,SCEGU_FIX_VALUE,blur,~blur);
	sceGuTexMode( tex_format, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL );
	sceGuTexImage( 0, 128, 64, 128,
		(void*)(vram_top+(int)scratch+tex_buffer+blur_top ) );
	sceGuDrawBuffer((tex_copy ? tex_format : final_format),
		(void*)(SCEGU_VRAM_TOP+scratch+tex_buffer), 256);
	sceGuViewport(0, 0, 256, 128);
	sceGuScissor(0, 0, 256, 128);
	
	sceGuSpriteMode( 128, 64, 256, 128 );
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDisable(SCEGU_BLEND);

	sceGuTexFlush();
	
	if(tex_copy)
	{
		
		sceGuTexMode( tex_format, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL );
		sceGuTexImage( 0, 256, 128, 256,
			(void*)(vram_top+(int)scratch+tex_buffer ) );
		sceGuDrawBuffer(final_format, (void*)(SCEGU_VRAM_TOP+scratch), 256);
		sceGuViewport(0, 0, 256, 128);
		sceGuScissor(0, 0, 256, 128);
		sceGuSpriteMode( 128, 128, 128, 128 );
		sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
		sceGuDrawSprite( 128, 0, 0, 128, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 

		sceGuTexFlush();
	}
	
	sceGuEnable( SCEGU_DITHER );
	
	sceGuEnable( SCEGU_DEPTH_TEST );
	sceGuOffset(SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY);
	sceGuViewport(2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDrawBuffer(_32bitframe ? SCEGU_PF8888 : SCEGU_PF5650,
		(void*)disp_addr_rel,SCEGU_VRAM_WIDTH );
	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDepthMask( 0 );
}

#define SCEGU_TEXTURE                      9
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#define SCEGU_LINEAR                       1
#define SCEGU_SINGLE_CLUT                  0
#define SCEGU_TEXBUF_NORMAL                0
#define SCEGU_LOD_CONSTANT                 1
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGBA                         1
#define SCEGU_CLAMP                        1

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

void DepthBlurUpdate(void)
{
	
	int i;
	
	int notch = _focus*16;
	float depth;
	float blur;
	
	
	
	
	for(i = 0; i < notch; i++)
	{
		depth = (i/15.0f);
		blur = (notch-i)/(float)(notch+1);
		if(blur > 1.0f)
			blur = 1.0f;
		if(blur < 0.0f)
			blur = 0.0f;
		_zclut[i] = MakeRGBA8888(depth,depth,blur,1);
		
	}
	
	for(i = notch; i < 16; i++)
	{
		depth = (i/15.0f);
		blur = powf((i-notch)/(float)(16-notch),0.4f+_focus*0.6f);
		if(blur > 1.0f)
			blur = 1.0f;
		if(blur < 0.0f)
			blur = 0.0f;
		_zclut[i] = MakeRGBA8888(depth,depth,blur,1);
	}
	
	for(i = 16; i < 256; i++)
	{
		_zclut[i] = _zclut[15];
	}
	
	
	
	
	
	for(i = 0;i < 16; i++)
	{
		int d=i;
		int b=(_zclut[i]>>16)&0xff;
		
		_redclut[i] = b|b<<8|b<<16|d<<27;
	}
	
	
	
	for(i = 0; i< 32; i++)
	{
		_idclut[i] = i<<3|i<<11|i<<19|i<<27;
	}
	
	
	for(i = 0; i< 32; i++)
	{
		unsigned char val = (i/31.0f)*255;
		u_int16 twochan = val|(val<<8);
		_16to32clut[i] =((twochan&0x1f)<<3)|((twochan&0x7e0)<<(11-5))
						|((twochan&0xf800)<<(19-5-6));
	}
}

#ifndef SCEGU_CULL_FACE /* sample */
#define SCEGU_CULL_FACE                    5
#endif
#ifndef SCEGU_BLEND /* sample */
#define SCEGU_BLEND                        4
#endif
#ifndef SCEGU_ADD /* sample */
#define SCEGU_ADD                          0
#endif
#ifndef SCEGU_SRC_ALPHA /* sample */
#define SCEGU_SRC_ALPHA                    2
#endif
#ifndef SCEGU_ONE_MINUS_SRC_ALPHA /* sample */
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#endif
#ifndef SCEGU_ALWAYS /* sample */
#define SCEGU_ALWAYS                       1
#endif
#ifndef SCEGU_LOD_CONSTANT /* sample */
#define SCEGU_LOD_CONSTANT                 1
#endif
#ifndef SCEGU_NOFLIP /* sample */
#define SCEGU_NOFLIP                       0
#endif
#ifndef SCEGU_NOROTATE /* sample */
#define SCEGU_NOROTATE                     0
#endif
#ifndef SCEGU_TEXTURE /* sample */
#define SCEGU_TEXTURE                      9
#endif
#ifndef SCEGU_DEPTH_TEST /* sample */
#define SCEGU_DEPTH_TEST                   1
#endif
#ifndef SCEGU_LIGHTING /* sample */
#define SCEGU_LIGHTING                    10
#endif
void DepthBlurDraw(void)
{
	unsigned int status = sceGuGetAllStatus();
	
	UseFrameBufferBlurmap();

	sceGuDisable( SCEGU_CULL_FACE );
	sceGuDisable( SCEGU_LIGHTING );
	sceGuDisable( SCEGU_BLEND );
	sceGuDisable( SCEGU_DEPTH_TEST );
	sceGuEnable(SCEGU_TEXTURE);
	
	sceGuEnable( SCEGU_BLEND );
	sceGuBlendFunc( SCEGU_ADD , SCEGU_SRC_ALPHA,SCEGU_ONE_MINUS_SRC_ALPHA,0,0);
	sceGuAlphaFunc( SCEGU_ALWAYS,0,0xff );
	sceGuColor(MakeRGBA8888(1,1,1,_distort));
	
	sceGuTexLevelMode( SCEGU_LOD_CONSTANT, 0.0f );
	
	
	sceGuSpriteMode( 64,128,120, 272 );
	sceGuDrawSprite( 0, 0, 0, 0, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDrawSprite( 120, 0, 0, 64, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDrawSprite( 240, 0, 0, 128, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuDrawSprite( 360, 0, 0, 192, 0, SCEGU_NOFLIP, SCEGU_NOROTATE ); 
	sceGuColor(MakeRGBA8888(1,1,1,1));
	
	sceGuEnable( SCEGU_TEXTURE );
	sceGuEnable( SCEGU_DEPTH_TEST );	
	sceGuEnable( SCEGU_LIGHTING );
	sceGuTexFlush();
	sceGuSetAllStatus(status);
}

void DepthBlurSetFocus(float _Focus) {
    _focus = _Focus;
}

