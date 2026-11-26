/* SDK gim_picture library: devkit 0.6.0's src/gim_picture/load_tm2.c, preprocessed (macros expanded) */
#include "umdt/graphics_model/gim_private.h"

typedef struct {
 int fileid ;
 char version ;
 char format ;
 short n_pictures ;
 char zero[ 8 ] ;
} Tm2Header ;

typedef struct {
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

typedef struct {
 int gs_miptbp1[ 2 ] ;
 int gs_miptbp2[ 2 ] ;
 int sizes[ 8 ] ;
} Tm2MipMap ;

enum {
 TM2_RGBA_5551 = 1,
 TM2_RGBA_8880 = 2,
 TM2_RGBA_8888 = 3,
 TM2_INDEX_4 = 4,
 TM2_INDEX_8 = 5,
} ;

extern int PixelFormats[];

static void copy_pixels( void *dst, const void *src, int width, int height, int type ) ;
static void sort_clut( void *clut, int format, int width ) ;

_Bool sceGimPictureLoadTm2( SceGimPicture *picture, const void *buf, int size, int index )
{
 if ( picture == 0 ) return 0 ;
 sceGimPictureUnload( picture ) ;

 Tm2Header *header = (Tm2Header *)buf ;
 if ( index < 0 || index >= header->n_pictures ) return 0 ;
 Tm2Pict *pict = (Tm2Pict *)( header + 1 ) ;
 if ( header->format ) pict = (Tm2Pict *)( (char *)header + 128 ) ;
 { int i ; for ( i = 0 ; i < index ; i ++ ) {
  pict = (Tm2Pict *)( (char *)pict + pict->total_size ) ;
 } }

 if ( pict->n_mipmaps != 0 ) {
  int format = PixelFormats[ (int)( pict->image_type ) ] ;
  int width = pict->image_width ;
  int height = pict->image_height ;
  int level = pict->n_mipmaps ;
  if ( !sceGimPictureReallocImage( picture, format, width, height, level, 1, 0 ) ) return 0 ;

  Tm2MipMap *mipmap = 0 ;
  if ( pict->n_mipmaps > 1 ) mipmap = (Tm2MipMap *)( pict + 1 ) ;
  void *ptr = (char *)pict + pict->header_size ;

  { int j ; for ( j = 0 ; j < pict->n_mipmaps ; j ++ ) {
   void *ptr2 = sceGimPictureGetImagePixels( picture, j, 0 ) ;
   copy_pixels( ptr2, ptr, width, height, pict->image_type ) ;
   if ( mipmap != 0 ) {
    width = ( width + 1 ) / 2 ;
    height = ( height + 1 ) / 2 ;
    ptr = (char *)ptr + mipmap->sizes[ j ] ;
   }
  } }
 }

 int clut_type = 7 & pict->clut_type ;
 if ( clut_type != 0 ) {
  int clut_format = PixelFormats[ clut_type ] ;
  int clut_width = pict->clut_colors ;

  void *ptr = (char *)pict + pict->header_size + pict->image_size ;
  sceGimPictureReallocPalette( picture, clut_format, clut_width, 1, 1, 0 ) ;
  void *ptr2 = sceGimPictureGetPalettePixels( picture, 0, 0 ) ;
  if ( ptr2 == 0 ) return 0 ;
  copy_pixels( ptr2, ptr, clut_width, 1, clut_type ) ;

  if ( ( 0x80 & pict->clut_type ) == 0 ) {
   sort_clut( ptr2, clut_format, clut_width ) ;
  }
 }
 sceKernelDcacheWritebackAll();
 return 1 ;
}

void copy_pixels( void *dst, const void *src, int width, int height, int type )
{
 unsigned char *dp = (unsigned char *)dst ;
 const unsigned char *sp = (unsigned char *)src ;

 switch ( type ) {
     case TM2_RGBA_5551 : {
  int pitch = ( width * 2 + 15 ) & ~15 ;
  { int i ; for ( i = 0 ; i < height ; i ++ ) {
   unsigned char *dp2 = (unsigned char *)dp ;
   { int j ; for ( j = 0 ; j < width ; j ++ ) {
    dp2[ 0 ] = sp[ 0 ] ;
    dp2[ 1 ] = sp[ 1 ] ;
    dp2 += 2 ;
    sp += 2 ;
   } }
   dp += pitch ;
  } }
  break ;
     }
     case TM2_RGBA_8880 : {
  int pitch = ( width * 4 + 15 ) & ~15 ;
  { int i ; for ( i = 0 ; i < height ; i ++ ) {
   unsigned char *dp2 = (unsigned char *)dp ;
   { int j ; for ( j = 0 ; j < width ; j ++ ) {
    dp2[ 0 ] = sp[ 0 ] ;
    dp2[ 1 ] = sp[ 1 ] ;
    dp2[ 2 ] = sp[ 2 ] ;
    dp2[ 3 ] = 0xff ;
    dp2 += 4 ;
    sp += 3 ;
   } }
   dp += pitch ;
  } }
  break ;
     }
     case TM2_RGBA_8888 : {
  int pitch = ( width * 4 + 15 ) & ~15 ;
  { int i ; for ( i = 0 ; i < height ; i ++ ) {
   unsigned char *dp2 = (unsigned char *)dp ;
   { int j ; for ( j = 0 ; j < width ; j ++ ) {
    int a = sp[ 3 ] * 255 / 128 ;
    if ( a > 255 ) a = 255 ;
    dp2[ 0 ] = sp[ 0 ] ;
    dp2[ 1 ] = sp[ 1 ] ;
    dp2[ 2 ] = sp[ 2 ] ;
    dp2[ 3 ] = a ;
    dp2 += 4 ;
    sp += 4 ;
   } }
   dp += pitch ;
  } }
  break ;
     }
     case TM2_INDEX_4 : {
  width = ( width + 1 ) / 2 ;
  int pitch = ( width + 15 ) & ~15 ;
  { int i ; for ( i = 0 ; i < height ; i ++ ) {
   unsigned char *dp2 = (unsigned char *)dp ;
   { int j ; for ( j = 0 ; j < width ; j ++ ) {
    *( dp2 ++ ) = *( sp ++ ) ;
   } }
   dp += pitch ;
  } }
  break ;
     }
     case TM2_INDEX_8 : {
  int pitch = ( width + 15 ) & ~15 ;
  { int i ; for ( i = 0 ; i < height ; i ++ ) {
   unsigned char *dp2 = (unsigned char *)dp ;
   { int j ; for ( j = 0 ; j < width ; j ++ ) {
    *( dp2 ++ ) = *( sp ++ ) ;
   } }
   dp += pitch ;
  } }
  break ;
     }
 }
}

void sort_clut( void *clut, int format, int width )
{
 if ( width != 256 ) return ;

 int *ptr = (int *)clut ;
 switch ( format ) {
     case 1 : {
  { int i ; for ( i = 0 ; i < 8 ; i ++ ) {
   { int j ; for ( j = 0 ; j < 4 ; j ++ ) {
    int tmp = ptr[ 4 + j ] ;
    ptr[ 4 + j ] = ptr[ 8 + j ] ;
    ptr[ 8 + j ] = tmp ;
   } }
   ptr += 16 ;
  } }
  break ;
     }
     case 3 : {
  { int i ; for ( i = 0 ; i < 8 ; i ++ ) {
   { int j ; for ( j = 0 ; j < 8 ; j ++ ) {
    int tmp = ptr[ 8 + j ] ;
    ptr[ 8 + j ] = ptr[ 16 + j ] ;
    ptr[ 16 + j ] = tmp ;
   } }
   ptr += 32 ;
  } }
  break ;
     }
 }
}
