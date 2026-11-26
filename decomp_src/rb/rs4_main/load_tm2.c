#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_tm2", sceGimPictureLoadTm2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_tm2", copy_pixels_9A71C);

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

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/load_tm2", D_0010C0F0);
