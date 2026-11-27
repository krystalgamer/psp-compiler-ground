#include "common.h"
#define eval_fcurve eval_fcurve_5E514
#include "gmo_motion_sdk.h"

SceGmoMotion *sceGmoMotionCreate( SceGmoChunk *chunk )
{
 SceGmoMotion *motion = (SceGmoMotion *)sceGmoModelAllocMemory( sizeof( SceGmoMotion ) ) ;
 if ( motion == 0 ) {
  ;
  return 0 ;
 }
 sceGmoBaseConstruct( &( motion->m_base ) ) ;
 motion->m_chunk = 0 ;
 motion->m_reference = 1 ;
 motion->m_flags = 0 ;
 motion->m_anims = 0 ;
 motion->m_fcurves = 0 ;
 motion->m_n_anims = 0 ;
 motion->m_n_fcurves = 0 ;
 motion->m_frame_loop[ 0 ] = -1000000.0f ;
 motion->m_frame_loop[ 1 ] = 1000000.0f ;
 motion->m_frame_rate = 60.0f ;
 motion->m_frame = 0.0f ;
 motion->m_weight = 0.0f ;
 if ( chunk != 0 && !sceGmoMotionLoad( motion, chunk ) ) {
  sceGmoMotionDelete( motion ) ;
  return 0 ;
 }
 return motion ;
}

void sceGmoMotionDelete( SceGmoMotion *motion )
{
 if ( motion == 0 ) return ;
 if ( -- motion->m_reference == 0 ) {
  sceGmoMotionUnload( motion ) ;
  sceGmoBaseDestruct( &( motion->m_base ) ) ;
  sceGmoModelFreeMemory( motion ) ;
 }
}

SceGmoMotion *sceGmoMotionDuplicate( SceGmoMotion *motion, int flags )
{
 if ( motion == 0 ) return 0 ;
 if ( !( SCEGMO_DUPLICATE_AUTOMATIC & flags )
   && !( SCEGMO_DUPLICATE_STRUCTURE & flags )
   && !( SCEGMO_DUPLICATE_MOTION & flags ) ) {
  motion->m_reference ++ ;
  return motion ;
 }
 SceGmoMotion *motion2 = sceGmoMotionCreate( 0 ) ;
 if ( motion2 == 0 ) return 0 ;
 sceGmoBaseCopy( &( motion2->m_base ), &( motion->m_base ) ) ;
 SceGmoChunk *chunk = motion->m_chunk ;
 if ( chunk != 0 ) {
  motion2->m_chunk = chunk ;
  chunk->type ++ ;
 }
 if ( !sceGmoModelCopyPtr( &( motion2->m_anims ), motion->m_anims,
     motion->m_n_anims * sizeof( void * ) )
   || !sceGmoModelCopyPtr( &( motion2->m_fcurves ), motion->m_fcurves,
     motion->m_n_fcurves * sizeof( void * ) ) ) {
  ;
  sceGmoMotionDelete( motion2 ) ;
  return 0 ;
 }
 motion2->m_flags = motion->m_flags ;
 motion2->m_n_anims = motion->m_n_anims ;
 motion2->m_n_fcurves = motion->m_n_fcurves ;
 motion2->m_frame_loop[ 0 ] = motion->m_frame_loop[ 0 ] ;
 motion2->m_frame_loop[ 1 ] = motion->m_frame_loop[ 1 ] ;
 motion2->m_frame_rate = motion->m_frame_rate ;
 motion2->m_frame = motion->m_frame ;
 motion2->m_weight = motion->m_weight ;
 return motion2 ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", sceGmoMotionLoad);

void sceGmoMotionUnload( SceGmoMotion *motion )
{
 if ( motion == 0 ) return ;
 SceGmoChunk *chunk = motion->m_chunk ;
 if ( chunk != 0 ) {
  if ( -- chunk->type == 0 ) sceGmoModelFreeMemory( chunk ) ;
  motion->m_chunk = 0 ;
 }
 sceGmoModelFreeMemory( motion->m_anims ) ;
 sceGmoModelFreeMemory( motion->m_fcurves ) ;
 motion->m_anims = 0 ;
 motion->m_fcurves = 0 ;
}

void sceGmoMotionAnimate( SceGmoMotion *motion, SceGmoModel *model, float step )
{
	if ( motion == 0 ) return ;

	float weight = motion->m_weight ;
	if ( weight == 0.0f ) return ;

	float frame0 = motion->m_frame ;
	float frame1 = frame0 + motion->m_frame_rate * step ;
	float start = motion->m_frame_loop[ 0 ] ;
	float end = motion->m_frame_loop[ 1 ] ;
	if ( frame1 >= end && frame0 < end ) {
		frame1 = ( motion->m_flags & NOREPEAT ) ? end : start ;
	} else if ( frame1 < start && frame0 >= start ) {
		frame1 = ( motion->m_flags & NOREPEAT ) ? start : end ;
	}
	motion->m_frame = frame1 ;

	SceGmoSubject *parent = sceGmoBaseGetParent( &( motion->m_base ) ) ;
	if ( parent != 0 ) model = (SceGmoModel *)parent ;

	float tmp[ 16 ] ;
	{ int i ; for ( i = 0 ; i < motion->m_n_anims ; i ++ ) {
		SceGmoAnimate *anim = (SceGmoAnimate *)SCEGMO_CHUNK_ARGS( motion->m_anims[ i ] ) ;

		int idx = anim->fcurve & 0x0fff ;
		if ( idx >= motion->m_n_fcurves ) continue ;
		SceGmoChunk *fcurve = motion->m_fcurves[ idx ] ;

		int n_dims = eval_fcurve( fcurve, frame1, tmp ) ;

		int block = anim->block ;
		switch ( ( block >> 16 ) & 0x7fff ) {
		    case 4 : {
			SceGmoBone *bone = sceGmoModelGetBone( model, block ) ;
			sceGmoBoneControl( bone, anim->cmd, anim->index, tmp, n_dims, weight ) ;
			break ;
		    }
		    case 8 : {
			SceGmoMaterial *material = sceGmoModelGetMaterial( model, block ) ;
			sceGmoMaterialControl( material, anim->cmd, anim->index, tmp, n_dims, weight ) ;
			break ;
		    }
		}
	} }
}

void sceGmoMotionSetParent( SceGmoMotion *motion, SceGmoModel *parent )
{
 if ( motion == 0 ) return ;
 sceGmoBaseSetParent( &( motion->m_base ), (SceGmoSubject *)parent ) ;
}

SceGmoModel *sceGmoMotionGetParent( SceGmoMotion *motion )
{
 if ( motion == 0 ) return 0 ;
 return (SceGmoModel *)sceGmoBaseGetParent( &( motion->m_base ) ) ;
}

void sceGmoMotionSetFrameLoop( SceGmoMotion *motion, float start, float end )
{
 if ( motion == 0 ) return ;
 motion->m_frame_loop[ 0 ] = start ;
 motion->m_frame_loop[ 1 ] = end ;
}

const float *sceGmoMotionGetFrameLoop( SceGmoMotion *motion )
{
 if ( motion == 0 ) return 0 ;
 return motion->m_frame_loop ;
}

void sceGmoMotionSetFrameRate( SceGmoMotion *motion, float fps )
{
 if ( motion == 0 ) return ;
 motion->m_frame_rate = fps ;
}

float sceGmoMotionGetFrameRate( SceGmoMotion *motion )
{
 if ( motion == 0 ) return 0.0f ;
 return motion->m_frame_rate ;
}

void sceGmoMotionSetFrameRepeat( SceGmoMotion *motion, int mode )
{
 if ( motion == 0 ) return ;
 if ( mode == 0 ) {
  motion->m_flags |= NOREPEAT ;
 } else {
  motion->m_flags &= ~NOREPEAT ;
 }
}

int sceGmoMotionGetFrameRepeat( SceGmoMotion *motion )
{
 if ( motion == 0 ) return 0 ;
 return ( motion->m_flags & NOREPEAT ) ? 0 : 1 ;
}

void sceGmoMotionSetFrame( SceGmoMotion *motion, float frame )
{
 if ( motion == 0 ) return ;
 motion->m_frame = frame ;
}

float sceGmoMotionGetFrame( SceGmoMotion *motion )
{
 if ( motion == 0 ) return 0.0f ;
 return motion->m_frame ;
}

void sceGmoMotionSetWeight( SceGmoMotion *motion, float weight )
{
 if ( motion == 0 ) return ;
 if ( weight < 0.0f ) weight = 0.0f ;
 motion->m_weight = weight ;
}

float sceGmoMotionGetWeight( SceGmoMotion *motion )
{
 if ( motion == 0 ) return 0.0f ;
 return motion->m_weight ;
}

int sceGmoMotionGetAnimationCount( SceGmoMotion *motion )
{
 if ( motion == 0 ) return 0 ;
 return motion->m_n_anims ;
}

int sceGmoMotionGetFcurveCount( SceGmoMotion *motion )
{
 if ( motion == 0 ) return 0 ;
 return motion->m_n_fcurves ;
}

SceGmoChunk *sceGmoMotionGetAnimation( SceGmoMotion *motion, int index )
{
 if ( motion == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= motion->m_n_anims ) return 0 ;
 return motion->m_anims[ index ] ;
}

SceGmoChunk *sceGmoMotionGetFcurve( SceGmoMotion *motion, int index )
{
 if ( motion == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= motion->m_n_fcurves ) return 0 ;
 return motion->m_fcurves[ index ] ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", eval_fcurve_5E514);

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

static float extrap_frame( float frame, float start, float end, int extrap )
{
	frame -= start ;
	end -= start ;

	if ( frame < 0.0f ) {
		switch ( 0x0f00 & extrap ) {
		    case 0x0000 :
			frame = 0.0f ;
			break ;
		    case 0x0100 :
			frame = fmodf( frame, end ) + end ;
			break ;
		    case 0x0200 :
			end += end ;
			frame = fmodf( frame, end ) + end ;
			if ( frame > end - frame ) frame = end - frame ;
			break ;
		    case 0x0300 :
		    case 0x0400 :
			frame = 0.0f ;
			break ;
		}
	} else if ( frame >= end ) {
		switch ( 0xf000 & extrap ) {
		    case 0x0000 :
			frame = end ;
			break ;
		    case 0x1000 :
			frame = fmodf( frame, end ) ;
			break ;
		    case 0x2000 :
			end += end ;
			frame = fmodf( frame, end ) ;
			if ( frame > end - frame ) frame = end - frame ;
			break ;
		    case 0x3000 :
		    case 0x4000 :
			frame = end ;
			break ;
		}
	}
	return start + frame ;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_motion", D_0007F040);
