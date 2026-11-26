#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionCreate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionDelete);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionDuplicate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionLoad);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionUnload);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionAnimate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionSetParent);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionGetParent);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionSetFrameLoop);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionGetFrameLoop);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionSetFrameRate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionGetFrameRate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionSetFrameRepeat);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionGetFrameRepeat);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionSetFrame);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionGetFrame);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionSetWeight);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionGetWeight);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionGetAnimationCount);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionGetFcurveCount);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionGetAnimation);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionGetFcurve);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", eval_fcurve_5E514);

float sqrtf(float x);
float find_root( float f0, float f1, float f2, float f3, float f )
{
 float E = ( f3 - f0 ) * 0.01f ;
 if ( E < 0.0001f ) E = 0.0001f ;
 float t0 = 0.0f ;
 float t3 = 1.0f ;
 { int i ; for ( i = 0 ; i < 8 ; i ++ ) {
  float d = f3 - f0 ;
  if ( d > -E && d < E ) break ;
  float r = ( f2 - f1 ) / d - ( 1.0f / 3.0f ) ;
  if ( r > -0.01f && r < 0.01f ) break ;
  float fc = ( f0 + f1 * 3.0f + f2 * 3.0f + f3 ) / 8.0f ;
  if ( f < fc ) {
   f3 = fc ;
   f2 = ( f1 + f2 ) * 0.5f ;
   f1 = ( f0 + f1 ) * 0.5f ;
   f2 = ( f1 + f2 ) * 0.5f ;
   t3 = ( t0 + t3 ) * 0.5f ;
  } else {
   f0 = fc ;
   f1 = ( f1 + f2 ) * 0.5f ;
   f2 = ( f2 + f3 ) * 0.5f ;
   f1 = ( f1 + f2 ) * 0.5f ;
   t0 = ( t0 + t3 ) * 0.5f ;
  }
 } }
 float c = f0 - f ;
 float b = 3.0f * ( f1 - f0 ) ;
 float a = f3 - f0 - b ;
 float x ;
 if ( a == 0.0f ) {
  x = ( b == 0.0f ) ? 0.5f : -c / b ;
 } else {
  float D2 = b * b - 4.0f * a * c ;
  if ( D2 < 0.0f ) D2 = 0.0f ;
  D2 = sqrtf( D2 ) ;
  if ( a + b < 0.0f ) D2 = -D2 ;
  x = ( -b + D2 ) / ( 2.0f * a ) ;
 }
 return ( t3 - t0 ) * x + t0 ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", extrap_frame);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", D_0007F040);






