/* SDK 2.5.0 libgim_picture load_bmp.o, built -O2 by 1.8.4.internal from the SDK 0.6.0 (devkit)
   src/gim_picture/load_bmp.c.
   Sony compiled it with -std=gnu9x, which the cflags line cannot carry: the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile. */
/* cflags: -O2 */
#include "gim_sdk.h"


//----------------------------------------------------------------
//  file structure
//----------------------------------------------------------------

typedef	struct {
	short type ;
	int size ;
	short res1 ;
	short res2 ;
	int bits ;

	int size2 ;
	int width ;
	int height ;
	short plane_count ;
	short bit_count ;
	int compress ;
	int image_size ;
	int xppm ;
	int yppm ;
	int used_cols ;
	int important ;
} BmpHeader ;

static void *read_header( void *src, BmpHeader *header ) ;
static void *read_short( void *src, short *val ) ;
static void *read_int( void *src, int *val ) ;

static void copy_idx4( void *dst, void *src, int width, int height ) ;
static void copy_idx8( void *dst, void *src, int width, int height ) ;
static void copy_5551( void *dst, void *src, int width, int height ) ;
static void copy_5650( void *dst, void *src, int width, int height ) ;
static void copy_8880( void *dst, void *src, int width, int height ) ;
static void copy_8888( void *dst, void *src, int width, int height, int alpha ) ;
static void copy_rle4( void *dst, void *src, int width, int height ) ;
static void copy_rle8( void *dst, void *src, int width, int height ) ;

//----------------------------------------------------------------
//  load from BMP
//----------------------------------------------------------------

bool sceGimPictureLoadBmp( SceGimPicture *picture, const void *buf, int size )
{
	{if ( picture == 0 ) {return false ;}}
	sceGimPictureUnload( picture ) ;

	BmpHeader header ;
	read_header( (void *)buf, &header ) ;

	// palette

	int clut_size = ( header.bits - 54 ) / 4 ;
	{if ( clut_size > 0 && header.bit_count < 16 ) {{
		int width = ( clut_size <= 16 ) ? 16 : 256 ;
		sceGimPictureReallocPalette( picture, SCEGU_PF8888, width, 1, 1, 0 ) ;
		void *dst = sceGimPictureGetPalettePixels( picture, 0, 0 ) ;
		{if ( dst == 0 ) {return false ;}}
		void *src = (char *)buf + 54 ;
		copy_8888( dst, src, clut_size, 1, 255 ) ;
	}}}

	// image

	void *src = (char *)buf + header.bits ;
	int width = header.width ;
	int height = header.height ;
	{switch ( header.bit_count ) {{
	    case 4 : {
		sceGimPictureReallocImage( picture, SCEGU_PFIDX4, width, height, 1, 1, 0 ) ;
		void *dst = sceGimPictureGetImagePixels( picture, 0, 0 ) ;
		{if ( dst == 0 ) {return false ;}}
		{if ( header.compress == 0 ) {{
			copy_idx4( dst, src, width, height ) ;
		}} else {{
			copy_rle4( dst, src, width, height ) ;
		}}}
		break ;
	    }
	    case 8 : {
		sceGimPictureReallocImage( picture, SCEGU_PFIDX8, width, height, 1, 1, 0 ) ;
		void *dst = sceGimPictureGetImagePixels( picture, 0, 0 ) ;
		{if ( dst == 0 ) {return false ;}}
		{if ( header.compress == 0 ) {{
			copy_idx8( dst, src, width, height ) ;
		}} else {{
			copy_rle8( dst, src, width, height ) ;
		}}}
		break ;
	    }
	    case 16 : {
		sceGimPictureReallocImage( picture, SCEGU_PF5551, width, height, 1, 1, 0 ) ;
		void *dst = sceGimPictureGetImagePixels( picture, 0, 0 ) ;
		{if ( dst == 0 ) {return false ;}}
		{if ( header.compress == 0 ) {{
			copy_5551( dst, src, width, height ) ;
		}} else {{
			picture->m_image->format = SCEGU_PF5650 ;
			copy_5650( dst, src, width, height ) ;
		}}}
		break ;
	    }
	    case 24 : {
		sceGimPictureReallocImage( picture, SCEGU_PF8888, width, height, 1, 1, 0 ) ;
		void *dst = sceGimPictureGetImagePixels( picture, 0, 0 ) ;
		{if ( dst == 0 ) {return false ;}}
		copy_8880( dst, src, width, height ) ;
		break ;
	    }
	    case 32 : {
		sceGimPictureReallocImage( picture, SCEGU_PF8888, width, height, 1, 1, 0 ) ;
		void *dst = sceGimPictureGetImagePixels( picture, 0, 0 ) ;
		{if ( dst == 0 ) {return false ;}}
		copy_8888( dst, src, width, height, 0 ) ;
		break ;
	    }
	    default : {
		WARNING1( "unsupported BMP ( %dbit )\n", header.bit_count ) ;
		return false ;
	    }
	}}}
	sceKernelDcacheWritebackAll();
	return true ;
}

//----------------------------------------------------------------
//  sub routines
//----------------------------------------------------------------

void *read_header( void *src, BmpHeader *header )
{
	src = read_short( src, &header->type ) ;
	src = read_int( src, &header->size ) ;
	src = read_short( src, &header->res1 ) ;
	src = read_short( src, &header->res2 ) ;
	src = read_int( src, &header->bits ) ;

	src = read_int( src, &header->size2 ) ;
	src = read_int( src, &header->width ) ;
	src = read_int( src, &header->height ) ;
	src = read_short( src, &header->plane_count ) ;
	src = read_short( src, &header->bit_count ) ;
	src = read_int( src, &header->compress ) ;
	src = read_int( src, &header->image_size ) ;
	src = read_int( src, &header->xppm ) ;
	src = read_int( src, &header->yppm ) ;
	src = read_int( src, &header->used_cols ) ;
	src = read_int( src, &header->important ) ;
	return src ;
}

void *read_short( void *src, short *val )
{
	{if ( 1 & (int)src ) {{
		unsigned char *cp = (unsigned char *)src ;
		*val = ( cp[ 1 ] << 8 ) | cp[ 0 ] ;
	}} else {{
		*val = *(short *)src ;
	}}}
	return (short *)src + 1 ;
}

void *read_int( void *src, int *val )
{
	{if ( 3 & (int)src ) {{
		unsigned char *cp = (unsigned char *)src ;
		*val = ( cp[ 3 ] << 24 ) | ( cp[ 2 ] << 16 ) | ( cp[ 1 ] << 8 ) | cp[ 0 ] ;
	}} else {{
		*val = *(int *)src ;
	}}}
	return (int *)src + 1 ;
}

void copy_idx4( void *dst, void *src, int width, int height )
{
	width = ( width + 1 ) / 2 ;
	int pitch = ( width + 3 ) & ~3 ;
	int pitch2 = ( width + 15 ) & ~15 ;
	char *sp = (char *)src ;
	char *dp = (char *)dst + pitch2 * ( height - 1 ) ;
	{int i = 0 ; for ( ; i < height ; i ++ ) {{
		char *sp2 = sp ;
		char *dp2 = dp ;
		{int j = 0 ; for ( ; j < width ; j ++ ) {{
			int src = 0xff & sp2[ 0 ] ;
			dp2[ 0 ] = ( src << 4 ) | ( src >> 4 ) ;
			dp2 ++ ;
			sp2 ++ ;
		}}}
		sp += pitch ;
		dp -= pitch2 ;
	}}}
}

void copy_idx8( void *dst, void *src, int width, int height )
{
	int pitch = ( width + 3 ) & ~3 ;
	int pitch2 = ( width + 15 ) & ~15 ;
	char *sp = (char *)src ;
	char *dp = (char *)dst + pitch2 * ( height - 1 ) ;
	{int i = 0 ; for ( ; i < height ; i ++ ) {{
		char *sp2 = sp ;
		char *dp2 = dp ;
		{int j = 0 ; for ( ; j < width ; j ++ ) {{
			dp2[ 0 ] = sp2[ 0 ] ;
			dp2 ++ ;
			sp2 ++ ;
		}}}
		sp += pitch ;
		dp -= pitch2 ;
	}}}
}

void copy_5551( void *dst, void *src, int width, int height )
{
	int pitch = ( width + 1 ) & ~1 ;
	int pitch2 = ( width + 7 ) & ~7 ;
	short *sp = (short *)src ;
	short *dp = (short *)dst + pitch2 * ( height - 1 ) ;
	{int i = 0 ; for ( ; i < height ; i ++ ) {{
		short *sp2 = sp ;
		short *dp2 = dp ;
		{int j = 0 ; for ( ; j < width ; j ++ ) {{
			int src = *( sp2 ++ ) ;
			int r = ( 0x7c00 & src ) >> 10 ;
			int b = ( 0x001f & src ) << 10 ;
			*( dp2 ++ ) = 0x8000 | ( 0x03e0 & src ) | r | b ;
		}}}
		sp += pitch ;
		dp -= pitch2 ;
	}}}
}

void copy_5650( void *dst, void *src, int width, int height )
{
	int pitch = ( width + 1 ) & ~1 ;
	int pitch2 = ( width + 7 ) & ~7 ;
	short *sp = (short *)src ;
	short *dp = (short *)dst + pitch2 * ( height - 1 ) ;
	{int i = 0 ; for ( ; i < height ; i ++ ) {{
		short *sp2 = sp ;
		short *dp2 = dp ;
		{int j = 0 ; for ( ; j < width ; j ++ ) {{
			int src = *( sp2 ++ ) ;
			int r = ( 0xf800 & src ) >> 11 ;
			int b = ( 0x001f & src ) << 11 ;
			*( dp2 ++ ) = r | ( 0x07e0 & src ) | b ;
		}}}
		sp += pitch ;
		dp -= pitch2 ;
	}}}
}

void copy_8880( void *dst, void *src, int width, int height )
{
	int pitch = ( width * 3 + 3 ) & ~3 ;
	int pitch2 = ( width * 4 + 15 ) & ~15 ;
	char *sp = (char *)src ;
	char *dp = (char *)dst + pitch2 * ( height - 1 ) ;
	{int i = 0 ; for ( ; i < height ; i ++ ) {{
		char *sp2 = sp ;
		char *dp2 = dp ;
		{int j = 0 ; for ( ; j < width ; j ++ ) {{
			dp2[ 0 ] = sp2[ 2 ] ;
			dp2[ 1 ] = sp2[ 1 ] ;
			dp2[ 2 ] = sp2[ 0 ] ;
			dp2[ 3 ] = (char)0xff ;
			dp2 += 4 ;
			sp2 += 3 ;
		}}}
		sp += pitch ;
		dp -= pitch2 ;
	}}}
}

void copy_8888( void *dst, void *src, int width, int height, int alpha )
{
	int pitch = width * 4 ;
	int pitch2 = ( width * 4 + 15 ) & ~15 ;
	char *sp = (char *)src ;
	char *dp = (char *)dst + pitch2 * ( height - 1 ) ;
	{int i = 0 ; for ( ; i < height ; i ++ ) {{
		char *sp2 = sp ;
		char *dp2 = dp ;
		{int j = 0 ; for ( ; j < width ; j ++ ) {{
			dp2[ 0 ] = sp2[ 2 ] ;
			dp2[ 1 ] = sp2[ 1 ] ;
			dp2[ 2 ] = sp2[ 0 ] ;
			dp2[ 3 ] = sp2[ 3 ] | alpha ;
			dp2 += 4 ;
			sp2 += 4 ;
		}}}
		sp += pitch ;
		dp -= pitch2 ;
	}}}
}

void copy_rle4( void *dst, void *src, int width, int height )
{
	int pitch2 = ( ( width + 1 ) / 2 + 15 ) & ~15 ;
	char *sp = (char *)src ;
	char *dp = (char *)dst + pitch2 * ( height - 1 ) ;

	int x_pos = 0 ;
	int y_pos = 0 ;
	char *dp2 = dp ;
	{while ( y_pos < height ) {{
		int count = 255 & *( sp ++ ) ;
		bool run = true ;
		{if ( count == 0 ) {{
			count = 255 & *( sp ++ ) ;
			{if ( count < 3 ) {{
				{if ( count == 1 ) {break ;}}
				{if ( count == 0 ) {{
					dp2 = ( dp -= pitch2 ) ;
					y_pos ++ ;
					x_pos = 0 ;
				}} else {{
					// not supported
					sp += 2 ;
				}}}
				continue ;
			}}}
			run = false ;
		}}}
		{if ( count >= width - x_pos ) {count = width - x_pos ;}}
		{if ( run ) {{
			{int i = 0 ; for ( ; i < count ; i ++ ) {{
				int col = *sp ;
				{if ( ( 1 & i ) == 0 ) {col >>= 4 ;}}
				col &= 0x0f ;
				{if ( ( 1 & x_pos ) == 0 ) {{
					*dp2 = col ;
				}} else {{
					*dp2 |= ( col << 4 ) ;
					dp2 ++ ;
				}}}
				x_pos ++ ;
			}}}
			sp ++ ;
		}} else {{
			{int i = 0 ; for ( ; i < count ; i ++ ) {{
				int col = *sp ;
				{if ( ( 1 & i ) == 0 ) {{
					col >>= 4 ;
				}} else {{
					sp ++ ;
				}}}
				col &= 0x0f ;
				{if ( ( 1 & x_pos ) == 0 ) {{
					*dp2 = col ;
				}} else {{
					*dp2 |= ( col << 4 ) ;
					dp2 ++ ;
				}}}
				x_pos ++ ;
			}}}
			sp += 1 & count ;
			sp += 1 & ( ( count + 1 ) / 2 ) ;
		}}}
	}}}
}

void copy_rle8( void *dst, void *src, int width, int height )
{
	int pitch2 = ( width + 15 ) & ~15 ;
	char *sp = (char *)src ;
	char *dp = (char *)dst + pitch2 * ( height - 1 ) ;

	int x_pos = 0 ;
	int y_pos = 0 ;
	char *dp2 = dp ;
	{while ( y_pos < height ) {{
		int count = 255 & *( sp ++ ) ;
		bool run = true ;
		{if ( count == 0 ) {{
			count = 255 & *( sp ++ ) ;
			{if ( count < 3 ) {{
				{if ( count == 1 ) {break ;}}
				{if ( count == 0 ) {{
					dp2 = ( dp -= pitch2 ) ;
					y_pos ++ ;
					x_pos = 0 ;
				}} else {{
					// not supported
					sp += 2 ;
				}}}
				continue ;
			}}}
			run = false ;
		}}}
		{if ( count >= width - x_pos ) {count = width - x_pos ;}}
		{if ( run ) {{
			{int i = 0 ; for ( ; i < count ; i ++ ) {{
				*( dp2 ++ ) = *sp ;
			}}}
			sp ++ ;
		}} else {{
			{int i = 0 ; for ( ; i < count ; i ++ ) {{
				*( dp2 ++ ) = *( sp ++ ) ;
			}}}
			sp += ( 1 & count ) ;
		}}}
		x_pos += count ;
	}}}
}

