#include "common.h"
#define read_header read_header_63878
#define read_short read_short_6393C
#define copy_pixels copy_pixels_6396C
#include "load_tga_sdk.h"

_Bool sceGimPictureLoadTga( SceGimPicture *picture, const void *buf, int size )
{
 if ( picture == 0 ) return 0 ;
 sceGimPictureUnload( picture ) ;
 TgaHeader header ;
 void *ptr = read_header( (void *)buf, &header ) ;
 int type = ~IMAGE_TYPE_RUNLENGTH & header.image_type ;
 if ( type != IMAGE_TYPE_INDEXED && type != IMAGE_TYPE_DIRECT ) {
  ;
  return 0 ;
 }
 if ( header.clut_type != 0 ) {
  int clut_count = header.clut_count ;
  sceGimPictureReallocPalette( picture, SCEGIM_FORMAT_RGBA8888, clut_count, 1, 1, 0 ) ;
  void *ptr2 = sceGimPictureGetPalettePixels( picture, 0, 0 ) ;
  if ( ptr2 == 0 ) return 0 ;
  unsigned char *sp = (unsigned char *)ptr ;
  unsigned int *dp = (unsigned int *)ptr2 ;
  if ( header.entry_size == 24 ) {
   { int i ; for ( i = 0 ; i < clut_count ; i ++ ) {
    *( dp ++ ) = 0xff000000 | ( sp[ 0 ] << 16 ) | ( sp[ 1 ] << 8 ) | sp[ 2 ] ;
    sp += 3 ;
   } }
  } else {
   { int i ; for ( i = 0 ; i < clut_count ; i ++ ) {
    *( dp ++ ) = ( sp[ 3 ] << 24 ) | ( sp[ 0 ] << 16 ) | ( sp[ 1 ] << 8 ) | sp[ 2 ] ;
    sp += 4 ;
   } }
  }
  ptr = sp ;
 }
 int format, src_step, dst_step ;
 if ( header.depth <= 8 ) {
  format = SCEGIM_FORMAT_INDEX8 ;
  src_step = 1 ;
  dst_step = 1 ;
 } else if ( header.depth <= 16 ) {
  format = SCEGIM_FORMAT_RGBA5551 ;
  src_step = 2 ;
  dst_step = 2 ;
 } else if ( header.depth <= 24 ) {
  format = SCEGIM_FORMAT_RGBA8888 ;
  src_step = 3 ;
  dst_step = 4 ;
 } else {
  format = SCEGIM_FORMAT_RGBA8888 ;
  src_step = 4 ;
  dst_step = 4 ;
 }
 int width = header.width ;
 int height = header.height ;
 sceGimPictureReallocImage( picture, format, width, height, 1, 1, 0 ) ;
 void *ptr2 = sceGimPictureGetImagePixels( picture, 0, 0 ) ;
 if ( ptr2 == 0 ) return 0 ;
 int pitch = width * src_step ;
 int pitch2 = ( width * dst_step + 15 ) & ~15 ;
 char *sp = (char *)ptr ;
 char *dp = (char *)ptr2 ;
 if ( ( IMAGE_DESC_FLIP_V & header.image_desc ) == 0 ) {
  dp += pitch2 * ( height - 1 ) ;
  pitch2 = -pitch2 ;
 }
 if ( !( IMAGE_TYPE_RUNLENGTH & header.image_type ) ) {
  { int i ; for ( i = 0 ; i < height ; i ++ ) {
   copy_pixels( dp, sp, width, src_step, 0 ) ;
   sp += pitch ;
   dp += pitch2 ;
  } }
 } else {
  int x_pos = 0 ;
  int y_pos = 0 ;
  while ( y_pos < height ) {
   int count = *( sp ++ ) ;
   _Bool run = ( ( 0x80 & count ) != 0 ) ;
   count = ( 0x7f & count ) + 1 ;
   while ( count > 0 ) {
    int step = count ;
    if ( step >= width - x_pos ) step = width - x_pos ;
    copy_pixels( dp, sp, step, src_step, run ) ;
    if ( !run ) sp += step * src_step ;
    dp += step * dst_step ;
    count -= step ;
    x_pos += step ;
    if ( x_pos >= width ) {
     dp -= x_pos * dst_step ;
     dp += pitch2 ;
     y_pos ++ ;
     x_pos = 0 ;
    }
   }
   if ( run ) sp += src_step ;
  }
 }
 sceKernelDcacheWritebackAll();
 return 1 ;
}

void *read_header( void *src, TgaHeader *header )
{
 src = read_char( src, &header->id_size ) ;
 src = read_char( src, &header->clut_type ) ;
 src = read_char( src, &header->image_type ) ;
 src = read_short( src, &header->first_entry ) ;
 src = read_short( src, &header->clut_count ) ;
 src = read_char( src, &header->entry_size ) ;
 src = read_short( src, &header->org_x ) ;
 src = read_short( src, &header->org_y ) ;
 src = read_short( src, &header->width ) ;
 src = read_short( src, &header->height ) ;
 src = read_char( src, &header->depth ) ;
 src = read_char( src, &header->image_desc ) ;
 return (char *)src + header->id_size ;
}

void *read_char( void *src, unsigned char *val )
{
 *val = *(unsigned char *)src ;
 return (unsigned char *)src + 1 ;
}

void *read_short( void *src, unsigned short *val )
{
 if ( 1 & (int)src ) {
  unsigned char *cp = (unsigned char *)src ;
  *val = ( cp[ 1 ] << 8 ) | cp[ 0 ] ;
 } else {
  *val = *(unsigned short *)src ;
 }
 return (unsigned short *)src + 1 ;
}

void copy_pixels( char *dp, char *sp, int count, int src_step, _Bool run )
{
 int step = run ? 0 : src_step ;
 switch ( src_step ) {
     case 1 : {
  { int i ; for ( i = 0 ; i < count ; i ++ ) {
   dp[ 0 ] = sp[ 0 ] ;
   sp += step ;
   dp += 1 ;
  } }
  break ;
     }
     case 2 : {
  unsigned char *sp2 = (unsigned char *)sp ;
  unsigned short *dp2 = (unsigned short *)dp ;
  { int i ; for ( i = 0 ; i < count ; i ++ ) {
   int src = ( sp2[ 1 ] << 8 ) | sp2[ 0 ] ;
   int r = ( 0x7c00 & src ) >> 10 ;
   int b = ( 0x001f & src ) << 10 ;
   dp2[ 0 ] = 0x8000 | ( 0x83e0 & src ) | r | b ;
   sp2 += step ;
   dp2 += 1 ;
  } }
  break ;
     }
     case 3 : {
  { int i ; for ( i = 0 ; i < count ; i ++ ) {
   dp[ 0 ] = sp[ 2 ] ;
   dp[ 1 ] = sp[ 1 ] ;
   dp[ 2 ] = sp[ 0 ] ;
   dp[ 3 ] = (char)0xff ;
   sp += step ;
   dp += 4 ;
  } }
  break ;
     }
     case 4 : {
  { int i ; for ( i = 0 ; i < count ; i ++ ) {
   dp[ 0 ] = sp[ 2 ] ;
   dp[ 1 ] = sp[ 1 ] ;
   dp[ 2 ] = sp[ 0 ] ;
   dp[ 3 ] = sp[ 3 ] ;
   sp += step ;
   dp += 4 ;
  } }
  break ;
     }
 }
}

