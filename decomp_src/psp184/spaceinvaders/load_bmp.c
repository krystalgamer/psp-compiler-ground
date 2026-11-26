#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/load_bmp", sceGimPictureLoadBmp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/load_bmp", read_header_62DDC);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/load_bmp", read_short_62EB8);

void *read_int( void *src, int *val )
{
 if ( 3 & (int)src ) {
  unsigned char *cp = (unsigned char *)src ;
  *val = ( cp[ 3 ] << 24 ) | ( cp[ 2 ] << 16 ) | ( cp[ 1 ] << 8 ) | cp[ 0 ] ;
 } else {
  *val = *(int *)src ;
 }
 return (int *)src + 1 ;
}

void copy_idx4( void *dst, void *src, int width, int height )
{
 width = ( width + 1 ) / 2 ;
 int pitch = ( width + 3 ) & ~3 ;
 int pitch2 = ( width + 15 ) & ~15 ;
 char *sp = (char *)src ;
 char *dp = (char *)dst + pitch2 * ( height - 1 ) ;
 { int i ; for ( i = 0 ; i < height ; i ++ ) {
  char *sp2 = sp ;
  char *dp2 = dp ;
  { int j ; for ( j = 0 ; j < width ; j ++ ) {
   int src = 0xff & sp2[ 0 ] ;
   dp2[ 0 ] = ( src << 4 ) | ( src >> 4 ) ;
   dp2 ++ ;
   sp2 ++ ;
  } }
  sp += pitch ;
  dp -= pitch2 ;
 } }
}

void copy_idx8( void *dst, void *src, int width, int height )
{
 int pitch = ( width + 3 ) & ~3 ;
 int pitch2 = ( width + 15 ) & ~15 ;
 char *sp = (char *)src ;
 char *dp = (char *)dst + pitch2 * ( height - 1 ) ;
 { int i ; for ( i = 0 ; i < height ; i ++ ) {
  char *sp2 = sp ;
  char *dp2 = dp ;
  { int j ; for ( j = 0 ; j < width ; j ++ ) {
   dp2[ 0 ] = sp2[ 0 ] ;
   dp2 ++ ;
   sp2 ++ ;
  } }
  sp += pitch ;
  dp -= pitch2 ;
 } }
}

void copy_5551( void *dst, void *src, int width, int height )
{
 int pitch = ( width + 1 ) & ~1 ;
 int pitch2 = ( width + 7 ) & ~7 ;
 short *sp = (short *)src ;
 short *dp = (short *)dst + pitch2 * ( height - 1 ) ;
 { int i ; for ( i = 0 ; i < height ; i ++ ) {
  short *sp2 = sp ;
  short *dp2 = dp ;
  { int j ; for ( j = 0 ; j < width ; j ++ ) {
   int src = *( sp2 ++ ) ;
   int r = ( 0x7c00 & src ) >> 10 ;
   int b = ( 0x001f & src ) << 10 ;
   *( dp2 ++ ) = 0x8000 | ( 0x03e0 & src ) | r | b ;
  } }
  sp += pitch ;
  dp -= pitch2 ;
 } }
}

void copy_5650( void *dst, void *src, int width, int height )
{
 int pitch = ( width + 1 ) & ~1 ;
 int pitch2 = ( width + 7 ) & ~7 ;
 short *sp = (short *)src ;
 short *dp = (short *)dst + pitch2 * ( height - 1 ) ;
 { int i ; for ( i = 0 ; i < height ; i ++ ) {
  short *sp2 = sp ;
  short *dp2 = dp ;
  { int j ; for ( j = 0 ; j < width ; j ++ ) {
   int src = *( sp2 ++ ) ;
   int r = ( 0xf800 & src ) >> 11 ;
   int b = ( 0x001f & src ) << 11 ;
   *( dp2 ++ ) = r | ( 0x07e0 & src ) | b ;
  } }
  sp += pitch ;
  dp -= pitch2 ;
 } }
}

void copy_8880( void *dst, void *src, int width, int height )
{
 int pitch = ( width * 3 + 3 ) & ~3 ;
 int pitch2 = ( width * 4 + 15 ) & ~15 ;
 char *sp = (char *)src ;
 char *dp = (char *)dst + pitch2 * ( height - 1 ) ;
 { int i ; for ( i = 0 ; i < height ; i ++ ) {
  char *sp2 = sp ;
  char *dp2 = dp ;
  { int j ; for ( j = 0 ; j < width ; j ++ ) {
   dp2[ 0 ] = sp2[ 2 ] ;
   dp2[ 1 ] = sp2[ 1 ] ;
   dp2[ 2 ] = sp2[ 0 ] ;
   dp2[ 3 ] = (char)0xff ;
   dp2 += 4 ;
   sp2 += 3 ;
  } }
  sp += pitch ;
  dp -= pitch2 ;
 } }
}

void copy_8888( void *dst, void *src, int width, int height, int alpha )
{
 int pitch = width * 4 ;
 int pitch2 = ( width * 4 + 15 ) & ~15 ;
 char *sp = (char *)src ;
 char *dp = (char *)dst + pitch2 * ( height - 1 ) ;
 { int i ; for ( i = 0 ; i < height ; i ++ ) {
  char *sp2 = sp ;
  char *dp2 = dp ;
  { int j ; for ( j = 0 ; j < width ; j ++ ) {
   dp2[ 0 ] = sp2[ 2 ] ;
   dp2[ 1 ] = sp2[ 1 ] ;
   dp2[ 2 ] = sp2[ 0 ] ;
   dp2[ 3 ] = sp2[ 3 ] | alpha ;
   dp2 += 4 ;
   sp2 += 4 ;
  } }
  sp += pitch ;
  dp -= pitch2 ;
 } }
}

void copy_rle4( void *dst, void *src, int width, int height )
{
 int pitch2 = ( ( width + 1 ) / 2 + 15 ) & ~15 ;
 char *sp = (char *)src ;
 char *dp = (char *)dst + pitch2 * ( height - 1 ) ;

 int x_pos = 0 ;
 int y_pos = 0 ;
 char *dp2 = dp ;
 while ( y_pos < height ) {
  int count = 255 & *( sp ++ ) ;
  _Bool run = 1 ;
  if ( count == 0 ) {
   count = 255 & *( sp ++ ) ;
   if ( count < 3 ) {
    if ( count == 1 ) break ;
    if ( count == 0 ) {
     dp2 = ( dp -= pitch2 ) ;
     y_pos ++ ;
     x_pos = 0 ;
    } else {

     sp += 2 ;
    }
    continue ;
   }
   run = 0 ;
  }
  if ( count >= width - x_pos ) count = width - x_pos ;
  if ( run ) {
   { int i ; for ( i = 0 ; i < count ; i ++ ) {
    int col = *sp ;
    if ( ( 1 & i ) == 0 ) col >>= 4 ;
    col &= 0x0f ;
    if ( ( 1 & x_pos ) == 0 ) {
     *dp2 = col ;
    } else {
     *dp2 |= ( col << 4 ) ;
     dp2 ++ ;
    }
    x_pos ++ ;
   } }
   sp ++ ;
  } else {
   { int i ; for ( i = 0 ; i < count ; i ++ ) {
    int col = *sp ;
    if ( ( 1 & i ) == 0 ) {
     col >>= 4 ;
    } else {
     sp ++ ;
    }
    col &= 0x0f ;
    if ( ( 1 & x_pos ) == 0 ) {
     *dp2 = col ;
    } else {
     *dp2 |= ( col << 4 ) ;
     dp2 ++ ;
    }
    x_pos ++ ;
   } }
   sp += 1 & count ;
   sp += 1 & ( ( count + 1 ) / 2 ) ;
  }
 }
}

void copy_rle8( void *dst, void *src, int width, int height )
{
 int pitch2 = ( width + 15 ) & ~15 ;
 char *sp = (char *)src ;
 char *dp = (char *)dst + pitch2 * ( height - 1 ) ;

 int x_pos = 0 ;
 int y_pos = 0 ;
 char *dp2 = dp ;
 while ( y_pos < height ) {
  int count = 255 & *( sp ++ ) ;
  _Bool run = 1 ;
  if ( count == 0 ) {
   count = 255 & *( sp ++ ) ;
   if ( count < 3 ) {
    if ( count == 1 ) break ;
    if ( count == 0 ) {
     dp2 = ( dp -= pitch2 ) ;
     y_pos ++ ;
     x_pos = 0 ;
    } else {

     sp += 2 ;
    }
    continue ;
   }
   run = 0 ;
  }
  if ( count >= width - x_pos ) count = width - x_pos ;
  if ( run ) {
   { int i ; for ( i = 0 ; i < count ; i ++ ) {
    *( dp2 ++ ) = *sp ;
   } }
   sp ++ ;
  } else {
   { int i ; for ( i = 0 ; i < count ; i ++ ) {
    *( dp2 ++ ) = *( sp ++ ) ;
   } }
   sp += ( 1 & count ) ;
  }
  x_pos += count ;
 }
}
