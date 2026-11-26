/* cflags: -O2 -frename-registers -fmerge-constants */
#include "gmo_private.h"
#include "include_asm.h"
#define quat_slerp quat_slerp_BDD8
extern char D_0014787C[];
#define Elements D_0014787C

static int eval_fcurve( SceGmoChunk *chunk, float frame, float *output ) ;
static float find_root( float f0, float f1, float f2, float f3, float frame ) ;
static quat *quat_slerp( quat *dst, const quat *src1, const quat *src2, float rate ) ;

enum {
 NOREPEAT = 0x0001,
} ;

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

_Bool sceGmoMotionLoad( SceGmoMotion *motion, const SceGmoChunk *load_chunk )
{
 SceGmoChunk *chunk ;
 if ( motion == 0 ) return 0 ;
 if ( load_chunk == 0 ) return 0 ;

 sceGmoMotionUnload( motion ) ;

 if ( !sceGmoModelCopyPtr( &( motion->m_chunk ), load_chunk, SCEGMO_CHUNK_SIZE( (SceGmoChunk *)load_chunk ) ) ) {
  ;
  return 0 ;
 }
 chunk = motion->m_chunk ;
 chunk->type = 1 ;

 int n_anims = sceGmoModelCountChunk( chunk, SCEGMO_ANIMATE ) ;
 int n_fcurves = sceGmoModelCountChunk( chunk, SCEGMO_FCURVE ) ;
 if ( !sceGmoModelAllocPtr( &( motion->m_anims ), n_anims * sizeof( void * ) )
   || !sceGmoModelAllocPtr( &( motion->m_fcurves ), n_fcurves * sizeof( void * ) ) ) {
  ;
 }

 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  void *args = SCEGMO_CHUNK_ARGS( chunk ) ;

  switch ( SCEGMO_CHUNK_TYPE( chunk ) ) {
      case SCEGMO_FRAME_RATE : {
   motion->m_frame_rate = ( (SceGmoFrameRate *)args )->fps ;
   break ;
      }
      case SCEGMO_FRAME_LOOP : {
   motion->m_frame_loop[ 0 ] = ( (SceGmoFrameLoop *)args )->start ;
   motion->m_frame_loop[ 1 ] = ( (SceGmoFrameLoop *)args )->end ;
   break ;
      }
      case SCEGMO_ANIMATE : {
   motion->m_anims[ motion->m_n_anims ++ ] = chunk ;
   break ;
      }
      case SCEGMO_FCURVE : {
   motion->m_fcurves[ motion->m_n_fcurves ++ ] = chunk ;
   break ;
      }
  }
 }
 return 1 ;
}

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

void sceGmoMotionUpdate( SceGmoMotion *motion, SceGmoModel *model, float step )
{
 if ( motion == 0 ) return ;

 float weight = motion->m_weight ;
 if ( weight == 0.0f ) return ;

 float frame = motion->m_frame + motion->m_frame_rate * step ;
 float start = motion->m_frame_loop[ 0 ] ;
 float end = motion->m_frame_loop[ 1 ] ;
 if ( frame >= end && motion->m_frame < end ) {
  frame = ( motion->m_flags & NOREPEAT ) ? end : start ;
 } else if ( frame < start && motion->m_frame >= start ) {
  frame = ( motion->m_flags & NOREPEAT ) ? start : end ;
 }
 motion->m_frame = frame ;

 SceGmoSubject *parent = sceGmoBaseGetParent( &( motion->m_base ) ) ;
 if ( parent != 0 ) model = (SceGmoModel *)parent ;

 float tmp[ 16 ] ;
 { int i ; for ( i = 0 ; i < motion->m_n_anims ; i ++ ) {
  SceGmoAnimate *anim = (SceGmoAnimate *)SCEGMO_CHUNK_ARGS( motion->m_anims[ i ] ) ;

  int index = (0x0fff&(anim->fcurve)) ;
  if ( index >= motion->m_n_fcurves ) continue ;
  SceGmoChunk *fcurve = motion->m_fcurves[ index ] ;

  int n_dims = eval_fcurve( fcurve, frame, tmp ) ;

  int block = anim->block ;
  switch ( (0x7fff&((block)>>16)) ) {
      case SCEGMO_BONE : {
   SceGmoBone *bone = sceGmoModelGetBone( model, block ) ;
   sceGmoBoneAnimate( bone, anim->cmd, anim->index, tmp, n_dims, weight ) ;
   break ;
      }
      case SCEGMO_MATERIAL : {
   SceGmoMaterial *material = sceGmoModelGetMaterial( model, block ) ;
   sceGmoMaterialAnimate( material, anim->cmd, anim->index, tmp, n_dims, weight ) ;
   break ;
      }
  }
 } }
}

int eval_fcurve( SceGmoChunk *chunk, float frame, float *output )
{
  SceGmoFCurveHeader *fcurve = (SceGmoFCurveHeader *)SCEGMO_CHUNK_ARGS( chunk ) ;
 int format = fcurve->format ;
 int n_dims = fcurve->n_dims ;
 int n_elems = Elements[ format ] ;
 int stride = n_elems * n_dims + 1 ;

 float *data = (float *)( fcurve + 1 ) ;
 int lower = 0 ;
 int upper = fcurve->n_keys - 1 ;
 while ( upper - lower > 1 ) {
  int index = ( upper + lower ) / 2 ;
  float frame2 = data[ stride * index ] ;
  if ( frame < frame2 ) {
   upper = index ;
  } else {
   lower = index ;
  }
 }

 float *k1 = data + stride * lower ;
 float *k2 = data + stride * upper ;
 float f1 = *( k1 ++ ) ;
 float f2 = *( k2 ++ ) ;
 float t = f2 - f1 ;
 if ( t != 0.0f ) t = ( frame - f1 ) / t ;
 if ( t <= 0.0f ) {
  format = SCEGMO_FCURVE_CONSTANT ;
 } else if ( t >= 1.0f ) {
  format = SCEGMO_FCURVE_CONSTANT ;
  k1 = k2 ;
 }

 switch ( format ) {
     case SCEGMO_FCURVE_CONSTANT : {
  { int i ; for ( i = 0 ; i < n_dims ; i ++ ) {
   *( output ++ ) = *k1 ;
   k1 += n_elems ;
  } }
  break ;
     }
     case SCEGMO_FCURVE_LINEAR : {
  { int i ; for ( i = 0 ; i < n_dims ; i ++ ) {
   float v1 = *( k1 ++ ) ;
   float v2 = *( k2 ++ ) ;
   *( output ++ ) = ( v2 - v1 ) * t + v1 ;
  } }
  break ;
     }
     case SCEGMO_FCURVE_HERMITE : {
  float s = 1.0f - t ;
  float t2 = t * t ;
  float s2 = s * s ;
  float b1 = s2 * t * 3.0f ;
  float b2 = t2 * s * 3.0f ;
  float b0 = s2 * s + b1 ;
  float b3 = t2 * t + b2 ;
  { int i ; for ( i = 0 ; i < n_dims ; i ++ ) {
   *( output ++ ) = k1[ 0 ] * b0 + k1[ 2 ] * b1 + k2[ 1 ] * b2 + k2[ 0 ] * b3 ;
   k1 += 3 ;
   k2 += 3 ;
  } }
  break ;
     }
     case SCEGMO_FCURVE_CUBIC : {
  { int i ; for ( i = 0 ; i < n_dims ; i ++ ) {
   float fa = f1 + k1[ 3 ] ;
   float fb = f2 + k2[ 1 ] ;
   float t = find_root( f1, fa, fb, f2, frame ) ;
   float s = 1.0f - t ;
   float t2 = t * t ;
   float s2 = s * s ;
   float b1 = s2 * t * 3.0f ;
   float b2 = t2 * s * 3.0f ;
   float b0 = s2 * s + b1 ;
   float b3 = t2 * t + b2 ;
   *( output ++ ) = k1[ 0 ] * b0 + k1[ 4 ] * b1 + k2[ 2 ] * b2 + k2[ 0 ] * b3 ;
   k1 += 5 ;
   k2 += 5 ;
  } }
  break ;
     }
     case SCEGMO_FCURVE_SPHERICAL : {
  quat_slerp( (quat *)output, (quat *)k1, (quat *)k2, t ) ;
  break ;
     }
 }
 return n_dims ;
}

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

quat *quat_slerp( quat *dst, const quat *src1, const quat *src2, float rate )
{
 if ( rate >= 1.0f ) return (quat *)memcpy( dst, src2, sizeof( quat ) ) ;
 if ( rate <= 0.0f ) return (quat *)memcpy( dst, src1, sizeof( quat ) ) ;
 float c = src1->x * src2->x + src1->y * src2->y + src1->z * src2->z + src1->w * src2->w ;
 int reverse = 0 ;
 if ( c < 0.0f ) {
  c = - c ;
  reverse = 1 ;
 }
 if ( c < 1.0f ) {
  float angle = acosf( c ) ;
  float s = sinf( angle ) ;
  if ( s != 0.0f ) {
   float r1 = sinf( ( 1 - rate ) * angle ) / s ;
   float r2 = sinf( rate * angle ) / s ;
   if ( reverse ) r2 = - r2 ;
   dst->x = src1->x * r1 + src2->x * r2 ;
   dst->y = src1->y * r1 + src2->y * r2 ;
   dst->z = src1->z * r1 + src2->z * r2 ;
   dst->w = src1->w * r1 + src2->w * r2 ;
   return dst ;
  }
 }
 *dst = *src2 ;
 return dst ;
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
