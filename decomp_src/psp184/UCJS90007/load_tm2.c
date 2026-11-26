/* SDK 2.5.0 libgim_picture load_tm2.o, built -O2 by 1.8.4.internal from the SDK 6.6.0
   src/gim_picture/load_tm2.c; PixelFormats is the module's .data.
   Sony compiled it with -std=gnu9x, which the cflags line cannot carry: the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile. */
/* cflags: -O2 */
#include "gim_sdk.h"


//----------------------------------------------------------------
//  file structure
//----------------------------------------------------------------

typedef	struct {
	int fileid ;
	char version ;
	char format ;
	short n_pictures ;
	char zero[ 8 ] ;
} Tm2Header ;

typedef	struct {
	int total_size ;
	int clut_size ;
	int image_size ;
	short header_size ;
	short clut_colors ;
	char pict_format ;
	char n_mipmaps ;
	char clut_type ;
	char image_type ;
	short image_width ;
	short image_height ;
	int gs_tex0[ 2 ] ;
	int gs_tex1[ 2 ] ;
	int gs_regs ;
	int gs_texclut ;
} Tm2Pict ;

typedef	struct {
	int gs_miptbp1[ 2 ] ;
	int gs_miptbp2[ 2 ] ;
	int sizes[ 8 ] ;
} Tm2MipMap ;

enum {
	TM2_FORMAT_RGBA5551	= 1,
	TM2_FORMAT_RGBA8880	= 2,
	TM2_FORMAT_RGBA8888	= 3,
	TM2_FORMAT_INDEX4	= 4,
	TM2_FORMAT_INDEX8	= 5
} ;

extern int PixelFormats[] ;

static void copy_pixels( void *dst, const void *src, int width, int height, int type ) ;
static void sort_clut( void *clut, int format, int width ) ;

//----------------------------------------------------------------
//  load from TM2
//----------------------------------------------------------------

bool sceGimPictureLoadTm2( SceGimPicture *picture, const void *buf, int size, int idx )
{
	{if ( picture == 0 ) {return false ;}}
	sceGimPictureUnload( picture ) ;

	// find picture

	Tm2Header *header = (Tm2Header *)buf ;
	{if ( idx < 0 || idx >= header->n_pictures ) {return false ;}}
	Tm2Pict *pict = (Tm2Pict *)( header + 1 ) ;
	{if ( header->format ) {pict = (Tm2Pict *)( (char *)header + 128 ) ;}}
	{int i = 0 ; for ( ; i < idx ; i ++ ) {{
		pict = (Tm2Pict *)( (char *)pict + pict->total_size ) ;
	}}}

	// picture header

	{if ( pict->n_mipmaps != 0 ) {{
		int format = PixelFormats[ (int)( pict->image_type ) ] ;
		int width = pict->image_width ;
		int height = pict->image_height ;
		int level = pict->n_mipmaps ;
		{if ( !sceGimPictureReallocImage( picture, format, width, height, level, 1, 0 ) ) {return false ;}}

		Tm2MipMap *mipmap = 0 ;
		{if ( pict->n_mipmaps > 1 ) {mipmap = (Tm2MipMap *)( pict + 1 ) ;}}
		void *ptr = (char *)pict + pict->header_size ;

		{int j = 0 ; for ( ; j < pict->n_mipmaps ; j ++ ) {{
			void *ptr2 = sceGimPictureGetImagePixels( picture, j, 0 ) ;
			copy_pixels( ptr2, ptr, width, height, pict->image_type ) ;
			{if ( mipmap != 0 ) {{
				width = ( width + 1 ) / 2 ;
				height = ( height + 1 ) / 2 ;
				ptr = (char *)ptr + mipmap->sizes[ j ] ;
			}}}
		}}}
	}}}

	int clut_type = 7 & pict->clut_type ;
	{if ( clut_type != 0 ) {{
		int clut_format = PixelFormats[ clut_type ] ;
		int clut_width = pict->clut_colors ;

		void *ptr = (char *)pict + pict->header_size + pict->image_size ;
		sceGimPictureReallocPalette( picture, clut_format, clut_width, 1, 1, 0 ) ;
		void *ptr2 = sceGimPictureGetPalettePixels( picture, 0, 0 ) ;
		{if ( ptr2 == 0 ) {return false ;}}
		copy_pixels( ptr2, ptr, clut_width, 1, clut_type ) ;

		{if ( ( 0x80 & pict->clut_type ) == 0 ) {{
			sort_clut( ptr2, clut_format, clut_width ) ;
		}}}
	}}}
	sceKernelDcacheWritebackAll();
	return true ;
}

//----------------------------------------------------------------
//  sub routines
//----------------------------------------------------------------

void copy_pixels( void *dst, const void *src, int width, int height, int type )
{
	unsigned char *dp = (unsigned char *)dst ;
	const unsigned char *sp = (unsigned char *)src ;

	{switch ( type ) {{
	    case TM2_FORMAT_RGBA5551 : {
		int pitch = ( width * 2 + 15 ) & ~15 ;
		{int i = 0 ; for ( ; i < height ; i ++ ) {{
			unsigned char *dp2 = (unsigned char *)dp ;
			{int j = 0 ; for ( ; j < width ; j ++ ) {{
				dp2[ 0 ] = sp[ 0 ] ;
				dp2[ 1 ] = sp[ 1 ] ;
				dp2 += 2 ;
				sp += 2 ;
			}}}
			dp += pitch ;
		}}}
		break ;
	    }
	    case TM2_FORMAT_RGBA8880 : {
		int pitch = ( width * 4 + 15 ) & ~15 ;
		{int i = 0 ; for ( ; i < height ; i ++ ) {{
			unsigned char *dp2 = (unsigned char *)dp ;
			{int j = 0 ; for ( ; j < width ; j ++ ) {{
				dp2[ 0 ] = sp[ 0 ] ;
				dp2[ 1 ] = sp[ 1 ] ;
				dp2[ 2 ] = sp[ 2 ] ;
				dp2[ 3 ] = 0xff ;
				dp2 += 4 ;
				sp += 3 ;
			}}}
			dp += pitch ;
		}}}
		break ;
	    }
	    case TM2_FORMAT_RGBA8888 : {
		int pitch = ( width * 4 + 15 ) & ~15 ;
		{int i = 0 ; for ( ; i < height ; i ++ ) {{
			unsigned char *dp2 = (unsigned char *)dp ;
			{int j = 0 ; for ( ; j < width ; j ++ ) {{
				int a = sp[ 3 ] * 255 / 128 ;
				{if ( a > 255 ) {a = 255 ;}}
				dp2[ 0 ] = sp[ 0 ] ;
				dp2[ 1 ] = sp[ 1 ] ;
				dp2[ 2 ] = sp[ 2 ] ;
				dp2[ 3 ] = a ;
				dp2 += 4 ;
				sp += 4 ;
			}}}
			dp += pitch ;
		}}}
		break ;
	    }
	    case TM2_FORMAT_INDEX4 : {
		width = ( width + 1 ) / 2 ;
		int pitch = ( width + 15 ) & ~15 ;
		{int i = 0 ; for ( ; i < height ; i ++ ) {{
			unsigned char *dp2 = (unsigned char *)dp ;
			{int j = 0 ; for ( ; j < width ; j ++ ) {{
				*( dp2 ++ ) = *( sp ++ ) ;
			}}}
			dp += pitch ;
		}}}
		break ;
	    }
	    case TM2_FORMAT_INDEX8 : {
		int pitch = ( width + 15 ) & ~15 ;
		{int i = 0 ; for ( ; i < height ; i ++ ) {{
			unsigned char *dp2 = (unsigned char *)dp ;
			{int j = 0 ; for ( ; j < width ; j ++ ) {{
				*( dp2 ++ ) = *( sp ++ ) ;
			}}}
			dp += pitch ;
		}}}
		break ;
	    }
	}}}
}

void sort_clut( void *clut, int format, int width )
{
	{if ( width != 256 ) {return ;}}

	int *ptr = (int *)clut ;
	{switch ( format ) {{
	    case SCEGIM_FORMAT_RGBA5551 : {
		{int i = 0 ; for ( ; i < 8 ; i ++ ) {{
			{int j = 0 ; for ( ; j < 4 ; j ++ ) {{
				int tmp = ptr[ 4 + j ] ;
				ptr[ 4 + j ] = ptr[ 8 + j ] ;
				ptr[ 8 + j ] = tmp ;
			}}}
			ptr += 16 ;
		}}}
		break ;
	    }
	    case SCEGIM_FORMAT_RGBA8888 : {
		{int i = 0 ; for ( ; i < 8 ; i ++ ) {{
			{int j = 0 ; for ( ; j < 8 ; j ++ ) {{
				int tmp = ptr[ 8 + j ] ;
				ptr[ 8 + j ] = ptr[ 16 + j ] ;
				ptr[ 16 + j ] = tmp ;
			}}}
			ptr += 32 ;
		}}}
		break ;
	    }
	}}}
}
