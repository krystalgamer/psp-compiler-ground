/* SDK 2.5.0 libgim_picture gim_realloc.o, built -O2 by 1.8.4.internal from the SDK 6.6.0
   src/gim_picture/gim_realloc.c with the devkit 0.6.0 sceGimPictureReallocImage/Palette bodies
   (no sceGimPictureReallocImageEx), Bpps tables in the module's .data.
   Sony compiled it with -std=gnu9x, which the cflags line cannot carry: the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile. */
/* cflags: -O2 */
#include "gim_sdk.h"


//----------------------------------------------------------------
//  realloc image
//----------------------------------------------------------------

bool sceGimPictureReallocImage( SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels )
{
	{if ( picture == 0 ) {return false ;}}
	{if ( w <= 0 || h <= 0 ) {return false ;}}
	{if ( w > 512 || h > 512 ) {return false ;}}
	{if ( level <= 0 || level > 8 ) {return false ;}}
	{if ( frame <= 0 ) {return false ;}}

	int size1 = sizeof( SceGimImageHeader ) + level * frame * 4 ;
	size1 = ( size1 + 15 ) & ~15 ;

	extern char Bpps[] __asm__("D_00030ED8") ;
	int bpp = Bpps[ 7 & format ] ;
	int level_sizes[ 8 ] ;
	int size2 = 0 ;
	int w2 = w ;
	int h2 = h ;
	{int i = 0 ; for ( ; i < level ; i ++ ) {{
		int level_size = ( ( ( bpp * w2 + 7 ) / 8 + 15 ) & ~15 ) * h2 ;
		level_sizes[ i ] = level_size ;
		size2 += level_size ;
		w2 = ( w2 + 1 ) / 2 ;
		h2 = ( h2 + 1 ) / 2 ;
	}}}
	size2 *= frame ;
	{if ( pixels != 0 ) {size2 = 0 ;}}

	FREE2( picture->m_image ) ;
	picture->m_image = (SceGimImageHeader *)MALLOC2( size1 + size2 ) ;
	{if ( picture->m_image == 0 ) {{
		WARNING( "cannot alloc image\n" ) ;
		return false ;
	}}}

	SceGimImageHeader *img = picture->m_image ;
	img->header_size = sizeof( SceGimImageHeader ) ;
	img->reference = 1 ;
	img->format = format ;
	img->order = SCEGIM_ORDER_NORMAL ;
	img->width = w ;
	img->height = h ;
	img->bpp = bpp ;
	img->pitch_align = 16 ;
	img->height_align = 1 ;
	img->dim_count = 2 ;
	img->reserved = 0 ;
	img->reserved2 = 0 ;
	img->offsets = sizeof( SceGimImageHeader ) ;
	img->images = size1 ;
	img->total = size1 + size2 ;
	img->plane_mask = 0 ;
	img->level_type = SCEGIM_TYPE_MIPMAP ;
	img->level_count = level ;
	img->frame_type = SCEGIM_TYPE_SEQUENCE ;
	img->frame_count = frame ;

	char *offset = ( pixels != 0 ) ? (char *)pixels : (char *)img + size1 ;
	int *offsets = (int *)( img + 1 ) ;
	int count = level * frame ;
	{int i = 0 ; for ( ; i < count ; i ++ ) {{
		*( offsets ++ ) = (int)offset ;
		offset += level_sizes[ i % level ] ;
	}}}
	sceGimPictureReconfigure( picture ) ;
	return true ;
}

bool sceGimPictureReallocPalette( SceGimPicture *picture, int format, int w, int level, int frame, void *pixels )
{
	{if ( picture == 0 ) {return false ;}}
	{if ( w <= 0 || w > 256 ) {return false ;}}
	{if ( level <= 0 || level > 8 ) {return false ;}}
	{if ( frame <= 0 ) {return false ;}}

	int size1 = sizeof( SceGimPaletteHeader ) + level * frame * 4 ;
	size1 = ( size1 + 15 ) / 16 * 16 ;

	extern char Bpps[] __asm__("D_00030EE0") ;
	int bpp = Bpps[ 7 & format ] ;
	int level_size = ( ( bpp * w + 7 ) / 8 + 15 ) & ~15 ;
	int size2 = ( pixels != 0 ) ? 0 : level_size * frame ;

	FREE2( picture->m_palette ) ;
	picture->m_palette = (SceGimPaletteHeader *)MALLOC2( size1 + size2 ) ;
	{if ( picture->m_palette == 0 ) {{
		WARNING( "cannot alloc palette\n" ) ;
		return false ;
	}}}

	SceGimPaletteHeader *pal = picture->m_palette ;
	pal->header_size = sizeof( SceGimPaletteHeader ) ;
	pal->reference = 1 ;
	pal->format = format ;
	pal->order = SCEGIM_ORDER_NORMAL ;
	pal->width = w ;
	pal->height = 1 ;
	pal->bpp = bpp ;
	pal->pitch_align = 16 ;
	pal->height_align = 1 ;
	pal->dim_count = 2 ;
	pal->reserved = 0 ;
	pal->reserved2 = 0 ;
	pal->offsets = sizeof( SceGimPaletteHeader ) ;
	pal->images = size1 ;
	pal->total = size1 + size2 ;
	pal->plane_mask = 0 ;
	pal->level_type = SCEGIM_TYPE_MIPMAP2 ;
	pal->level_count = level ;
	pal->frame_type = SCEGIM_TYPE_SEQUENCE ;
	pal->frame_count = frame ;

	char *offset = ( pixels != 0 ) ? (char *)pixels : (char *)pal + size1 ;
	int *offsets = (int *)( pal + 1 ) ;
	int count = level * frame ;
	{int i = 0 ; for ( ; i < count ; i ++ ) {{
		*( offsets ++ ) = (int)offset ;
		offset += level_size ;
	}}}
	sceGimPictureReconfigure( picture ) ;
	return true ;
}


