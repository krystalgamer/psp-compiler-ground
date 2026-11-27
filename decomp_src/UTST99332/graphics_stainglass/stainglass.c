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

static u_int ColorAt( ScePspFVector2 st );
static ScePspFVector2 OffsetAt( ScePspFVector2 st, int index );


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

const int _nx = 48;
const int _ny = 48;

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

static u_int ColorAt( ScePspFVector2 st )
{






	st.x -= 0.5f;
	st.y -= 0.5f;

	float d = 2.f*sqrtf( st.x * st.x + st.y * st.y );

	if ( d > 1.f )	d = 1.f;

	float r=1.0f;
	float g=0.2f;
	float b=0.5f;

	float t = ( 3 * d * d - 2 * d * d * d );

	r = ( 1.f - r ) * t + r;
	g = ( 1.f - g ) * t + g;
	b = ( 1.f - b ) * t + b;

	return MakeRGBA8888(
		st.x>0.f?r:g,
		st.y>0.f?b:g, b, 0.f);
}

static ScePspFVector2 OffsetAt( ScePspFVector2 st, int index )
{
	ScePspFVector2 retval;


	RandSeed( index );
	retval = Rand();

	return retval;
}

#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)

void StainGlassInit(void)
{

	ScePspFVector2 tmp_v;


	_num_vertices=6*_nx*_ny;

	_vertices=(VTypeT16C32V32*)malloc(sizeof(VTypeT16C32V32)*_num_vertices);

	_offsets=(ScePspFVector2*)malloc(sizeof(ScePspFVector2)*_num_vertices);



	sceGumPushMatrix();
	sceGumLoadIdentity();
	ScePspFVector3 t;
	t.x=0.f;
	t.y=0.f;
	t.z=-35.f;
	sceGumTranslate(&t);
	sceGumRotateX(SCEGU_RAD(10.f));
	sceGumRotateY(SCEGU_RAD(30.f));
	sceGumStoreMatrix(&_transform.fm);
	sceGumPopMatrix();



	{
		VTypeT16C32V32* v = _vertices;
		ScePspFVector2 *r=_offsets;
		int i,j,k;

		const float dx = 1.f / (float)_nx;
		const float dy = 1.f / (float)_ny;

		for ( j=0; j < _ny; ++j )
		{
			for ( i=0; i < _nx; ++i )
			{
				

				VTypeT16C32V32 tile_v[4]; 
				ScePspFVector2 rnd[4];	 
				ScePspFVector2 st[4];	 

				st[0].x = i * dx;
				st[0].y = j * dy;

				st[1].x = i * dx + dx;
				st[1].y = j * dy;

				st[2].x = i * dx;    
				st[2].y = j * dy + dy;

				st[3].x = i * dx + dx;
				st[3].y = j * dy + dy;

				
				
				

				for ( k=0;k!=4;++k )
				{
					tile_v[k].vx = _scale * ( st[k].x - 0.5f );
					tile_v[k].vy = _scale * ( st[k].y - 0.5f );
					tile_v[k].vz = 0.f;

					

					tile_v[k].c = ColorAt( st[k] );
				}

				

				rnd[0] = OffsetAt( st[0], i+j*_ny );
				rnd[1] = OffsetAt( st[1], i+1+j*_ny );
				rnd[2] = OffsetAt( st[2], i+(j+1)*_ny );
				rnd[3] = OffsetAt( st[3], i+1+(j+1)*_ny );

				

				for ( k=0;k!=4;++k )
				{
					tile_v[k].vx += rnd[k].x;
					tile_v[k].vy += rnd[k].y;
				}
			
				tmp_v = Rand();


				if ( 0 )			 

				{
					

					*v++ = tile_v[0]; *r++ = rnd[0];
					*v++ = tile_v[2]; *r++ = rnd[2];
					*v++ = tile_v[1]; *r++ = rnd[1];

					*v++ = tile_v[2]; *r++ = rnd[2];  
					*v++ = tile_v[3]; *r++ = rnd[3];  
					*v++ = tile_v[1]; *r++ = rnd[1];  
				}
				else
				{
					

					*v++ = tile_v[0]; *r++ = rnd[0];
					*v++ = tile_v[2]; *r++ = rnd[2];
					*v++ = tile_v[3]; *r++ = rnd[3];

					*v++ = tile_v[0]; *r++ = rnd[0];  
					*v++ = tile_v[3]; *r++ = rnd[3];  
					*v++ = tile_v[1]; *r++ = rnd[1];  
				}
			}
		}
	}
}

void StainGlassRelease(void)
{
	free(_vertices);
	free(_offsets);
}

void sceGumStoreMatrix(ScePspFMatrix4 *m);
#define SCEGU_MATRIX_PROJECTION            0
#define SCEGU_MATRIX_VIEW                  1
#define SCEGU_MATRIX_WORLD                 2

void StainGlassUpdate(void)
{
	ScePspMatrix4 all; 

	
	
	{
		ScePspMatrix4 projection,view,world;

		sceGumMatrixMode( SCEGU_MATRIX_PROJECTION );
		sceGumStoreMatrix( &projection.fm );

		sceGumMatrixMode( SCEGU_MATRIX_VIEW );
		sceGumStoreMatrix( &view.fm );

		sceGumMatrixMode( SCEGU_MATRIX_WORLD );
		sceGumStoreMatrix( &world.fm );

		ScePspMatrix4 transform_cpy;
		transform_cpy.fm = _transform.fm;		
										
		__asm__ volatile
			(
			".set push				\n"
			".set noreorder		\n"
			"lv.q	c000, 0+%1	\n"	 
			"lv.q	c010, 16+%1	\n" 
			"lv.q	c020, 32+%1	\n" 
			"lv.q	c030, 48+%1	\n" 
			"lv.q	c100, 0+%2	\n"	 
			"lv.q	c110, 16+%2	\n" 
			"lv.q	c120, 32+%2	\n" 
			"lv.q	c130, 48+%2	\n" 
			"vmmul.q	m200, m000, m100 \n" 

			"lv.q	c000, 0+%3	\n"	 
			"lv.q	c010, 16+%3	\n" 
			"lv.q	c020, 32+%3	\n" 
			"lv.q	c030, 48+%3	\n" 
			"vmmul.q	m100, m200, m000 \n" 

			"lv.q	c200, 0+%4	\n"	 
			"lv.q	c210, 16+%4	\n" 
			"lv.q	c220, 32+%4	\n" 
			"lv.q	c230, 48+%4	\n" 
			"vmmul.q	m000, m100, m200 \n" 

			"sv.q	c000, 0+%0	\n"	 
			"sv.q	c010, 16+%0	\n"
			"sv.q	c020, 32+%0	\n"
			"sv.q	c030, 48+%0	\n"
			".set pop				\n"

			: "=m" (all.fm)
			: "m" (projection.fm)
			, "m" (view.fm)
			, "m" (world.fm)
			, "m" (transform_cpy.fm)
			);
	}

	

	{
		VTypeT16C32V32* v = _vertices;
		ScePspFVector2 *r=_offsets;
		int j;

		__asm__
			(
			".set push		\n"
			".set noreorder	\n"
			".set pop			\n"
			"lv.q c200, 0+%0	\n"
			"lv.q c210, 16+%0	\n"
			"lv.q c220, 32+%0	\n"
			"lv.q c230, 48+%0	\n"
			"vone.p	c300		\n" 
			"lv.s     s302, %1	\n"
			"lv.s     s303, %2	\n"
			: 
		: "m" (all.fm), "m" (_sx), "m" (_sy)
			);

		for ( j=0; j < _num_vertices; ++j, ++v, ++r )
		{
			__asm__
				(
				".set push				\n"
				".set noreorder			\n"

				"lv.s	s100, 8+%1		\n" 
				"lv.s	s101, 12+%1		\n" 
				"lv.s	s102, 16+%1		\n" 
				"vone.s	s103				\n" 
				"vtfm4.q	c000, e200, c100	\n" 

				"vrcp.s	s003, s003		\n" 
				"vscl.p	c000, c000, s003	\n" 
				"vneg.s	s001, s001		\n" 

				"vadd.p	c000, c000, c300	\n" 

				"vfim.s	s030, 0.5    		\n" 
				"vscl.p	c000, c000, s030	\n" 

				"lv.s	s100, 0+%2		\n" 
				"lv.s	s101, 4+%2		\n" 

				"vmul.p	c100, c100, c302	\n"

				"vadd.p	c000, c000, c100	\n" 
				"vsat0.p	c000, c000	     \n"
				"vf2iz.p	c000, c000,31		\n"
				"vi2s.p	s010, c000		\n"	
				"sv.s	s010, 0+%0		\n"

				".set pop					\n"
				: "=m" (*v)
				: "m" (*v), "m" (*r) 
				);     


		}
	}
}

#define SCEGU_CULL_FACE                    5
#define SCEGU_BLEND                        4
#define SCEGU_PRIM_TRIANGLES               3
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#define SCEGU_TEXTURE_USHORT     ( 2 <<  0 )
#define SCEGU_COLOR_PF8888       ( 7 <<  2 )
#define SCEGU_NORMAL_NONE        ( 0 <<  5 )
#define SCEGU_INDEX_NONE         ( 0 << 11 )
#define SCEGU_LIGHTING                    10

void StainGlassDraw( bool textured  )
{
	if ( _ny <= 1 || _nx <= 1 ) return;

	if ( textured )
	{
		sceGuTexScale(  1.f, 1.f );
		sceGuTexOffset( 0.f, 0.f );
	}

	sceGumPushMatrix();
	sceGumMultMatrix(&_transform.fm);

	sceGuDisable( SCEGU_CULL_FACE );

	if ( textured )
	{
		sceGuTexFlush();
	}

	sceGuDisable( SCEGU_LIGHTING );
	sceGuDisable( SCEGU_BLEND );

	if ( textured )
	{
		

		UseFrameBufferMipmap();
	}

	sceGumDrawArray(
		SCEGU_PRIM_TRIANGLES,
		SCEGU_VERTEX_FLOAT 
		| SCEGU_TEXTURE_USHORT
		| SCEGU_COLOR_PF8888
		| SCEGU_NORMAL_NONE
		| SCEGU_INDEX_NONE
		, _num_vertices, NULL, (void*)_vertices );

	sceGuEnable( SCEGU_LIGHTING );

	if ( textured )
	{
		sceGuTexFlush();

		sceGuTexFilter( SCEGU_LINEAR, SCEGU_LINEAR );
	}

	sceGumPopMatrix();
}

void StainGlassSetTransform( const ScePspFMatrix4 *m )
{
	_transform.fm = *m;
}

void StainGlassSetDistorsion( const float _Distort )
{
	_sx = _Distort;
	_sy = _Distort;
}
