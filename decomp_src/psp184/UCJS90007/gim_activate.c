/* SDK 2.5.0 libgim_picture gim_activate.o, built -O2 by 1.8.4.internal from the SDK 6.6.0
   src/gim_picture/gim_activate.c without sceGimPictureGetActiveImage/GetActivePalette, its tables
   non-const (the module's .data), texture filter arguments in min, mag order.
   Sony compiled it with -std=gnu9x, which the cflags line cannot carry: the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile. */
/* cflags: -O2 */
#include "gim_sdk.h"


//----------------------------------------------------------------
//  packet size
//----------------------------------------------------------------

//  texture	: TMODE TPF FLUSH (TBPx2 TSIZE)x8 CLUT (CBPx2 CLOAD)x2
//  renderstate	: TLEVEL TU TV SU SV BLEND FIXA FIXB TFUNC TFILTER TWRAP

#define MAX_TEXTURE_PACKET (34)
#define MAX_RENDERSTATE_PACKET (11)

//----------------------------------------------------------------
//  cache structure
//----------------------------------------------------------------

typedef struct SceGimTextureCache SceGimTextureCache ;
typedef struct SceGimPixelCache SceGimPixelCache ;

struct SceGimTextureCache {
	unsigned int m_packet[ 1 ] ;
} ;

struct SceGimPixelCache {
	SceGimImageHeader *m_image ;
	SceGimPaletteHeader *m_palette ;
	int pad[ 2 ] ;
} ;

//----------------------------------------------------------------
//  functions
//----------------------------------------------------------------

static bool set_null( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags ) ;
static bool set_texture( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags ) ;
static bool set_renderstate( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags ) ;
static SceGimImageHeader *copy_image( SceGimImageHeader *dst, const SceGimImageHeader *src ) ;

//----------------------------------------------------------------
//  cache
//----------------------------------------------------------------

bool sceGimPictureLoadCache( SceGimPicture *picture )
{
	return sceGimPictureLoadCacheEx( picture, SCEGIM_CACHE_ALL ) ;
}

bool sceGimPictureLoadCacheEx( SceGimPicture *picture, int flags )
{
	{if ( picture == 0 ) {return false ;}}

	bool res = true ;

		{if ( flags & SCEGIM_CACHE_PIXEL ) {{
		{if ( picture->m_pixel_cache == 0 ) {{
			SceGimImageHeader *image = picture->m_image ;
			SceGimPaletteHeader *palette = picture->m_palette ;
			int size1 = ( image == 0 ) ? 0 : image->total ;
			int size2 = ( palette == 0 ) ? 0 : palette->total ;
			int size = sizeof( SceGimPixelCache ) + size1 + size2 ;
			SceGimPixelCache *buf = (SceGimPixelCache *)MALLOC3( size ) ;
			{if ( buf == 0 ) {{
				res = false ;
			}} else {{
				SceGimImageHeader *ptr = (SceGimImageHeader *)( buf + 1 ) ;
				buf->m_image = copy_image( ptr, image ) ;
				ptr = (SceGimImageHeader *)( (char *)ptr + size1 ) ;
				buf->m_palette = copy_image( ptr, palette ) ;
				{if ( sceKernelIsCachedAddr( buf ) ) {{
					sceKernelDcacheWritebackRange( buf, size ) ;
				}}}
				picture->m_pixel_cache = buf ;
			}}}
		}}}
	}}}
	
		{if ( flags & SCEGIM_CACHE_TEXTURE ) {{
		{if ( picture->m_texture_cache == 0
		 && !( picture->m_flags & SCEGIM_PICTURE_IS_ANIMATED ) ) {{

			unsigned int tmp[ MAX_TEXTURE_PACKET + 1 ] ;
			unsigned int *ptr = tmp ;
			unsigned int *end = tmp + sizeof( tmp ) / 4 ;
			set_texture( picture, &ptr, end, SCEGIM_ACTIVATE_ALL ) ;
			sceGimPutRet( &ptr ) ;

			int size = (char *)ptr - (char *)tmp ;
			SceGimTextureCache *buf = (SceGimTextureCache *)MALLOC2( size ) ;
			{if ( buf == 0 ) {{
				res = false ;
			}} else {{
				MEMCPY( buf, tmp, size ) ;	// relocatable
				{if ( sceKernelIsCachedAddr( buf ) ) {{
					sceKernelDcacheWritebackRange( buf, size ) ;
				}}}
				picture->m_texture_cache = buf ;
			}}}
		}}}
	}}}
	
	return res ;
}

void sceGimPictureUnloadCache( SceGimPicture *picture )
{
	sceGimPictureUnloadCacheEx( picture, SCEGIM_CACHE_ALL ) ;
}

void sceGimPictureUnloadCacheEx( SceGimPicture *picture, int flags )
{
	{if ( picture == 0 ) {return ;}}

		{if ( flags & SCEGIM_CACHE_PIXEL ) {{
		{if ( picture->m_pixel_cache != 0 ) {flags |= SCEGIM_CACHE_TEXTURE ;}}
		FREE3( picture->m_pixel_cache ) ;
		picture->m_pixel_cache = 0 ;
	}}}
	
		{if ( flags & ( SCEGIM_CACHE_TEXTURE ) ) {{
		FREE2( picture->m_texture_cache ) ;
		picture->m_texture_cache = 0 ;
	}}}
	}

//----------------------------------------------------------------
//  buffers
//----------------------------------------------------------------



//----------------------------------------------------------------
//  activate
//----------------------------------------------------------------

bool sceGimPictureActivateEx( SceGimPicture *picture, unsigned int **pkt, unsigned int *size, int flags )
{
	unsigned int *ptr = *pkt ;
	unsigned int *end = ( size == 0 ) ? (unsigned int *)0xfffffffc : ptr + *size / 4 ;

	//  null

	{if ( picture == 0 ) {{
		{if ( !set_null( picture, &ptr, end, flags ) ) {return false ;}}
		flags = 0 ;
	}}}

	//  texture

	{if ( flags & SCEGIM_ACTIVATE_TEXTURE ) {{
		SceGimTextureCache *cache = picture->m_texture_cache ;
		{if ( cache != 0 ) {{
						{if ( ptr + 2 > end ) {return false ;}}
						sceGimPutCall( &ptr, cache->m_packet ) ;
		}} else {{
			{if ( !set_texture( picture, &ptr, end, flags ) ) {return false ;}}
		}}}
	}}}

	//  renderstate

	{if ( flags & SCEGIM_ACTIVATE_RENDERSTATE ) {{
		{if ( !set_renderstate( picture, &ptr, end, flags ) ) {return false ;}}
	}}}

	*pkt = ptr ;
	{if ( size != 0 ) {*size = (char *)end - (char *)ptr ;}}
	return true ;
}

//----------------------------------------------------------------
//  null texture
//----------------------------------------------------------------

bool set_null( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags )
{
	extern unsigned short NullTexture[] __asm__("D_00030E30") ;
		{if ( *pkt + 6 > end ) {return false ;}}
		sceGimPutTexMode( pkt, SCEGU_PF5650, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL ) ;
	sceGimPutTexImage( pkt, 0, 1, 1, 8, NullTexture ) ;
	sceGimPutTexFlush( pkt ) ;
	return true ;
}

//----------------------------------------------------------------
//  texture
//----------------------------------------------------------------

bool set_texture( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags )
{
	{if ( picture == 0 ) {return false ;}}

		{if ( *pkt + MAX_TEXTURE_PACKET > end ) {return false ;}}
	
	//  simple texture

	SceGimPixelCache *cache = picture->m_pixel_cache ;
	SceGimImageHeader *img = ( cache != 0 ) ? cache->m_image : picture->m_image ;
	SceGimPaletteHeader *pal = ( cache != 0 ) ? cache->m_palette : picture->m_palette ;

	{if ( picture->m_flags == 0 ) {{
		{if ( img != 0 ) {{
			sceGimPutTexMode( pkt, img->format, 0, SCEGU_SINGLE_CLUT, img->order ) ;
			void **offsets = (void **)( (char *)img + img->offsets ) ;
			sceGimPutTexImage( pkt, 0, img->width, img->height, picture->m_buf_width, *offsets ) ;
		}}}
		sceGimPutTexFlush( pkt ) ;

		{if ( pal != 0 ) {{
						sceGimPutClutMode( pkt, pal->format,
				picture->m_palette_offset[ 0 ],
				picture->m_palette_offset[ 1 ],
				picture->m_palette_offset[ 2 ] ) ;
			
			void **offsets = (void **)( (char *)pal + pal->offsets ) ;
			sceGimPutClutLoad( pkt, picture->m_clut_load, *offsets ) ;
		}}}
		return true ;
	}}}

	//  complex texture ( mipmap, sequence, nonpow2, ... etc )

	{if ( img != 0 ) {{
		int w = img->width ;
		int h = img->height ;
		int w2 = sceGimPicturePow2( w ) ;
		int h2 = sceGimPicturePow2( h ) ;
		int align = img->pitch_align * 8 / img->bpp - 1 ;
		int n_levels = img->level_count ;
		void **offsets = (void **)( (char *)img + img->offsets ) ;

				int n_frames = img->frame_count ;
		int frame = picture->m_image_frame % n_frames ;
		{if ( frame < 0 ) {frame += n_frames ;}}

		{if ( picture->m_enable_bits & SCEGIM_ENABLE_DISSOLVE ) {{
			int clut = SCEGU_SINGLE_CLUT ;
			{if ( picture->m_flags & SCEGIM_PICTURE_HAS_PALETTE_FRAMES ) {{
				clut = SCEGU_MULTI_CLUT ;
			}}}
			sceGimPutTexMode( pkt, img->format, 1, clut, img->order ) ;
			w = ( w + align ) & ~align ;
			void *buf = offsets[ frame * n_levels ] ;
			sceGimPutTexImage( pkt, 0, w2, h2, w, buf ) ;
			frame = picture->m_image_frame2 % n_frames ;
			{if ( frame < 0 ) {frame = frame + n_frames ;}}
			buf = offsets[ frame * n_levels ] ;
			sceGimPutTexImage( pkt, 1, w2, h2, w, buf ) ;
		}} else {{
			offsets += frame * n_levels ;
		
			int clut = SCEGU_SINGLE_CLUT ;
			{if ( picture->m_flags & SCEGIM_PICTURE_HAS_PALETTE_LEVELS ) {{
				clut = SCEGU_MULTI_CLUT ;
			}}}
			sceGimPutTexMode( pkt, img->format, n_levels - 1, clut, img->order ) ;
			{int i = 0 ; for ( ; i < n_levels ; i ++ ) {{
				void *buf = *( offsets ++ ) ;
				sceGimPutTexImage( pkt, i, w2, h2, ( w + align ) & ~align, buf ) ;
				{if ( img->level_type == SCEGIM_TYPE_MIPMAP ) {{
					w = ( w + 1 ) / 2 ;
					w2 = ( w2 + 1 ) / 2 ;
					h2 = ( h2 + 1 ) / 2 ;
				}}}
			}}}

				}}}
		
		sceGimPutTexFlush( pkt ) ;
	}}}

	{if ( pal != 0 ) {{
				sceGimPutClutMode( pkt, pal->format,
			picture->m_palette_offset[ 0 ],
			picture->m_palette_offset[ 1 ],
			picture->m_palette_offset[ 2 ] ) ;
		
		void **offsets = (void **)( (char *)pal + pal->offsets ) ;

				int n_levels = pal->level_count ;
		int n_frames = pal->frame_count ;
		int frame = picture->m_palette_frame % n_frames ;
		{if ( frame < 0 ) {frame = frame + n_frames ;}}
		{if ( !( picture->m_enable_bits & SCEGIM_ENABLE_DISSOLVE ) ) {{
			sceGimPutClutLoad( pkt, picture->m_clut_load, offsets[ frame * n_levels ] ) ;
		}} else {{
			int count = pal->width / 16 ;
			{if ( pal->format == SCEGU_PF8888 ) {count *= 2 ;}}
			int frame2 = picture->m_palette_frame2 % n_frames ;
			{if ( frame2 < 0 ) {frame2 = frame2 + n_frames ;}}
			{if ( frame2 == frame + 1 && n_levels == 1 && count <= 16 ) {{
				sceGimPutClutLoad( pkt, count * 2, offsets[ frame * n_levels ] ) ;
			}} else {{
				sceGimPutClutLoad( pkt, count * 2, (char *)offsets[ frame2 * n_levels ]
								- count * 32 ) ;
				sceGimPutClutLoad( pkt, count, offsets[ frame * n_levels ] ) ;
			}}}
		}}}
			}}}

	return true ;
}

//----------------------------------------------------------------
//  renderstate
//----------------------------------------------------------------

bool set_renderstate( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags )
{
	{if ( picture == 0 ) {return false ;}}

	int enable = picture->m_enable_bits ;
	{if ( enable == 0 ) {return true ;}}

		{if ( *pkt + MAX_RENDERSTATE_PACKET > end ) {return false ;}}
	
	//  dissolve factor

	{if ( enable & SCEGIM_ENABLE_FACTOR ) {{
				{if ( enable & SCEGIM_ENABLE_DISSOLVE ) {{
			sceGimPutTexLevelMode( pkt, SCEGU_LOD_CONSTANT, picture->m_dissolve ) ;
		}} else {{
			sceGimPutTexLevelMode( pkt, SCEGU_LOD_AUTO, 0 ) ;
		}}}
			}}}

	//  image crop

	{if ( enable & SCEGIM_ENABLE_CROP ) {{
		extern float NoCrop[] __asm__("D_00030E40") ;
		const float *crop = picture->m_image_crop ;
		{if ( !( picture->m_flags & SCEGIM_PICTURE_IS_CROPPED ) ) {crop = NoCrop ;}}
		sceGimPutTexOffset( pkt, crop[ 0 ], crop[ 1 ] ) ;
		sceGimPutTexScale( pkt, crop[ 2 ], crop[ 3 ] ) ;
	}}}

	//  render state

		{if ( enable & SCEGIM_ENABLE_BLEND ) {{
		extern int BlendFuncModes[][ 4 ] __asm__("D_00030E50") ;
		const int *modes = BlendFuncModes[ picture->m_blend[ 0 ] ] ;
		sceGimPutBlendFunc( pkt, modes[ 0 ], modes[ 1 ], modes[ 2 ], 0xffffffff, modes[ 3 ] ) ;
	}}}
	{if ( enable & SCEGIM_ENABLE_FUNC ) {{
		sceGimPutTexFunc( pkt, picture->m_func[ 0 ], picture->m_func[ 1 ] ) ;
	}}}
	{if ( enable & SCEGIM_ENABLE_FILTER ) {{
		sceGimPutTexFilter( pkt, picture->m_filter[ 0 ], picture->m_filter[ 1 ] ) ;
	}}}
	{if ( enable & SCEGIM_ENABLE_WRAP ) {{
		sceGimPutTexWrap( pkt, picture->m_wrap[ 0 ], picture->m_wrap[ 1 ] ) ;
	}}}
	
	return true ;
}

//----------------------------------------------------------------
//  copy image
//----------------------------------------------------------------


SceGimImageHeader *copy_image( SceGimImageHeader *dst, const SceGimImageHeader *src )
{
	{if ( src == 0 ) {return 0 ;}}

	//  memcpy

		MEMCPY( dst, src, src->total ) ;
	
	//  offsets

	int begin = (int)src ;
	int end = begin + src->total ;
	int offset = (int)dst - (int)src ;
	int *offsets = (int *)( (char *)dst + dst->offsets ) ;
	{int i = src->level_count * src->frame_count ; for ( ; i > 0 ; -- i ) {{
		int ptr = *( offsets ++ ) ;
		{if ( ptr >= begin && ptr < end ) {offsets[ -1 ] = ptr + offset ;}}
	}}}

	return dst ;
}

