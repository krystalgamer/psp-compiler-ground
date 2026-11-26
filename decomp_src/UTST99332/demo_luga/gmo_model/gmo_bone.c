/* cflags: -O2 -frename-registers -fmerge-constants */
/* SDK gmo_model library: devkit 0.6.0's src/gmo_model/gmo_bone.c, preprocessed (macros expanded), with the newer
   revision's SCEGMO_SCALE_3 (0xe1) support: HAS_SCALE_3 flag, vec3_div, flags renumbered */
#include "gmo_private.h"
#include "include_asm.h"
#define complement_animation complement_animation_7FB0
#define float_lerp float_lerp_79CC
#define quat_slerp quat_slerp_7D50
#define g_identity g_identity_1477D0

extern float D_00147810[]; /* Weights.0 (complement_animation), Pivot.1 (calc_stack_matrix) at +0x20 */
#define Pivot ( *(mat4 *)&D_00147810[ 8 ] )
static void complement_animation( SceGmoBone *bone ) ;
static void calc_local_matrix( SceGmoBone *bone ) ;
static void calc_stack_matrix( SceGmoBone *bone, SceGmoModel *model ) ;

static _Bool set_blend_bones( SceGmoBone *bone, const int *bones, int n_bones ) ;
static _Bool set_blend_offsets( SceGmoBone *bone, const mat4 *offsets, int n_offsets ) ;
static _Bool set_morph_weights( SceGmoBone *bone, const float *weights, int n_weights ) ;
static void calc_morph_index( float *weights, int n_weights, float index ) ;

static mat4 *mat4_mul( mat4 *dst, const mat4 *src1, const mat4 *src2 ) ;
static vec4 *mat4_app( vec4 *dst, const mat4 *src1, const vec4 *src2 ) ;
static vec3 *vec3_mul( vec3 *dst, const vec3 *src1, const vec3 *src2 ) ;
static vec3 *vec3_div( vec3 *dst, const vec3 *src1, const vec3 *src2 ) ;
static vec4 *vec4_scale( vec4 *dst, const vec4 *src1, float src2 ) ;
static float *float_lerp( float *dst, const float *src1, const float *src2, int dim, float rate ) ;

static mat4 *mat4_from_quat( mat4 *dst, const quat *src ) ;
static quat *quat_from_rotzyx( quat *dst, const vec3 *src ) ;
static quat *quat_from_rotyxz( quat *dst, const vec3 *src ) ;
static quat *quat_slerp( quat *dst, const quat *src1, const quat *src2, float rate ) ;
enum {
 STACK_SCALE_ACTIVE = 0x80000000,
 LOCAL_MATRIX_DIRTY = 0x40000000,
 WORLD_MATRIX_DIRTY = 0x20000000,

 HAS_PIVOT = 0x0001,
 HAS_MULT_MATRIX = 0x0002,
 HAS_TRANSLATE = 0x0004,
 HAS_ROTATE = 0x0008,
 HAS_SCALE = 0x0010,
 HAS_SCALE_2 = 0x0020,
 HAS_SCALE_3 = 0x0040,
 HAS_MORPH_WEIGHTS = 0x0100,
 HAS_VISIBILITY = 0x0200,
} ;

enum {
 ANIM_MODIFIED = 0x0000ffff,
 ANIM_COMPLETE = 0xffff0000,
} ;

extern mat4 g_identity;

SceGmoBone *sceGmoBoneCreate( SceGmoChunk *chunk )
{
 SceGmoBone *bone = (SceGmoBone *)sceGmoModelAllocMemory( sizeof( SceGmoBone ) ) ;
 if ( bone == 0 ) {
  ;
  return 0 ;
 }
 sceGmoBaseConstruct( &( bone->m_base ) ) ;
 bone->m_initial = 0 ;
 bone->m_reference = 1 ;
 bone->m_flags = 0 ;

 bone->m_draw_parts = 0 ;
 bone->m_morph_weights = 0 ;
 bone->m_blend_bones = 0 ;
 bone->m_blend_offsets = 0 ;
 bone->m_n_draw_parts = 0 ;
 bone->m_n_morph_weights = 0 ;
 bone->m_n_blend_bones = 0 ;
 bone->m_n_blend_offsets = 0 ;

 bone->m_parent_bone = -1 ;
 bone->m_visibility = 0 ;
 bone->m_pivot = (vec3){ 0, 0, 0 } ;
 bone->m_translate = (vec3){ 0, 0, 0 } ;
 bone->m_rotate = (quat){ 0, 0, 0, 1 } ;
 bone->m_scale = (vec3){ 1, 1, 1 } ;

 bone->m_local_matrix = g_identity ;
 bone->m_stack_matrix = g_identity ;
 bone->m_stack_scale = (vec3){ 1, 1, 1 } ;
 bone->m_world_matrix = g_identity ;

 bone->m_anim_flags = 0 ;
 memset( bone->m_anim_weights, 0, sizeof( bone->m_anim_weights ) ) ;

 if ( chunk != 0 && !sceGmoBoneLoad( bone, chunk ) ) {
  sceGmoBoneDelete( bone ) ;
  return 0 ;
 }
 return bone ;
}

void sceGmoBoneDelete( SceGmoBone *bone )
{
 if ( bone == 0 ) return ;
 if ( -- bone->m_reference == 0 ) {
  sceGmoBoneUnload( bone ) ;
  sceGmoBaseDestruct( &( bone->m_base ) ) ;
  sceGmoModelFreeMemory( bone ) ;
 }
}

SceGmoBone *sceGmoBoneDuplicate( SceGmoBone *bone, int flags )
{

 if ( bone == 0 ) return 0 ;
 if ( !( SCEGMO_DUPLICATE_STRUCTURE & flags )
   && !( SCEGMO_DUPLICATE_BONE & flags ) ) {
  bone->m_reference ++ ;
  return bone ;
 }

 SceGmoBone *bone2 = sceGmoBoneCreate( 0 ) ;
 if ( bone2 == 0 ) return 0 ;
 sceGmoBaseCopy( &( bone2->m_base ), &( bone->m_base ) ) ;

 if ( !sceGmoModelCopyPtr( &( bone2->m_draw_parts ), bone->m_draw_parts,
     bone->m_n_draw_parts * sizeof( int ) )
   || !sceGmoModelCopyPtr( &( bone2->m_morph_weights ), bone->m_morph_weights,
     bone->m_n_morph_weights * sizeof( float ) )
   || !sceGmoModelCopyPtr( &( bone2->m_blend_bones ), bone->m_blend_bones,
     bone->m_n_blend_bones * sizeof( int ) )
   || !sceGmoModelCopyPtr( &( bone2->m_blend_offsets ), bone->m_blend_offsets,
     bone->m_n_blend_offsets * sizeof( mat4 ) ) ) {
  sceGmoBoneDelete( bone2 ) ;
  return 0 ;
 }
 bone2->m_initial = sceGmoBoneDuplicate( bone->m_initial, SCEGMO_DUPLICATE_REFERENCE ) ;
 bone2->m_flags = bone->m_flags ;

 bone2->m_parent_bone = bone->m_parent_bone ;
 bone2->m_visibility = bone->m_visibility ;
 bone2->m_pivot = bone->m_pivot ;
 bone2->m_translate = bone->m_translate ;
 bone2->m_rotate = bone->m_rotate ;
 bone2->m_scale = bone->m_scale ;

 bone2->m_local_matrix = bone->m_local_matrix ;
 bone2->m_stack_matrix = bone->m_stack_matrix ;
 bone2->m_stack_scale = bone->m_stack_scale ;
 bone2->m_world_matrix = bone->m_world_matrix ;

 bone2->m_n_draw_parts = bone->m_n_draw_parts ;
 bone2->m_n_morph_weights = bone->m_n_morph_weights ;
 bone2->m_n_blend_bones = bone->m_n_blend_bones ;
 bone2->m_n_blend_offsets = bone->m_n_blend_offsets ;

 bone2->m_anim_flags = bone->m_anim_flags ;
 memcpy( bone2->m_anim_weights, bone->m_anim_weights, sizeof( bone->m_anim_weights ) ) ;
 return bone2 ;
}

_Bool sceGmoBoneLoad( SceGmoBone *bone, SceGmoChunk *chunk )
{
 if ( bone == 0 ) return 0 ;
 if ( chunk == 0 ) return 0 ;

 sceGmoBoneUnload( bone ) ;

 int n_parts = sceGmoModelCountChunk( chunk, SCEGMO_DRAW_PART ) ;
 if ( !sceGmoModelAllocPtr( &( bone->m_draw_parts ), n_parts * sizeof( void * ) ) ) {
  ;
  return 0 ;
 }

 SceGmoBlendOffsets *blend_offsets = 0 ;
 _Bool has_draw_part = 0 ;

 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  void *args = SCEGMO_CHUNK_ARGS( chunk ) ;

  switch ( SCEGMO_CHUNK_TYPE( chunk ) ) {
      case SCEGMO_PARENT_BONE : {
   bone->m_parent_bone = ( (SceGmoParentBone *)args )->bone ;
   break ;
      }
      case SCEGMO_VISIBILITY : {
   bone->m_visibility = ( (SceGmoVisibility *)args )->visibility ;
   bone->m_flags |= HAS_VISIBILITY ;
   break ;
      }
      case SCEGMO_MORPH_WEIGHTS : {
   SceGmoMorphWeights *cmd = (SceGmoMorphWeights *)args ;
   if ( !set_morph_weights( bone, cmd->weights, cmd->n_weights ) ) {
    ;
    return 0 ;
   }
   bone->m_flags |= HAS_MORPH_WEIGHTS ;
   break ;
      }
      case SCEGMO_MORPH_INDEX : {
   SceGmoMorphIndex *cmd = (SceGmoMorphIndex *)args ;
   if ( !set_morph_weights( bone, 0, (8) ) ) {
    ;
    return 0 ;
   }
   calc_morph_index( bone->m_morph_weights, (8), cmd->index ) ;
   bone->m_flags |= HAS_MORPH_WEIGHTS ;
   break ;
      }
      case SCEGMO_BLEND_BONES : {
   SceGmoBlendBones *cmd = (SceGmoBlendBones *)args ;
   if ( !set_blend_bones( bone, cmd->bones, cmd->n_bones ) ) {
    ;
    return 0 ;
   }
   break ;
      }
      case SCEGMO_BLEND_OFFSETS : {
   blend_offsets = (SceGmoBlendOffsets *)args ;
   break ;
      }
      case SCEGMO_PIVOT : {
   bone->m_pivot = ( (SceGmoPivot *)args )->pivot ;
   bone->m_flags |= HAS_PIVOT ;
   break ;
      }
      case SCEGMO_MULT_MATRIX : {
   bone->m_local_matrix = ( (SceGmoMultMatrix *)args )->matrix ;
   bone->m_flags |= HAS_MULT_MATRIX ;
   break ;
      }
      case SCEGMO_TRANSLATE : {
   bone->m_translate = ( (SceGmoTranslate *)args )->translate ;
   bone->m_flags |= HAS_TRANSLATE ;
   break ;
      }
      case SCEGMO_ROTATE_ZYX : {
   SceGmoRotateZYX *cmd = (SceGmoRotateZYX *)args ;
   quat_from_rotzyx( &( bone->m_rotate ), &( cmd->rotate ) ) ;
   bone->m_flags |= HAS_ROTATE ;
   break ;
      }
      case SCEGMO_ROTATE_YXZ : {
   SceGmoRotateYXZ *cmd = (SceGmoRotateYXZ *)args ;
   quat_from_rotyxz( &( bone->m_rotate ), &( cmd->rotate ) ) ;
   bone->m_flags |= HAS_ROTATE ;
   break ;
      }
      case SCEGMO_ROTATE_Q : {
   bone->m_rotate = ( (SceGmoRotateQ *)args )->rotate ;
   bone->m_flags |= HAS_ROTATE ;
   break ;
      }
      case SCEGMO_SCALE : {
   bone->m_scale = ( (SceGmoScale *)args )->scale ;
   bone->m_flags |= HAS_SCALE ;
   break ;
      }
      case SCEGMO_SCALE_2 : {
   bone->m_scale = ( (SceGmoScale *)args )->scale ;
   bone->m_flags |= HAS_SCALE_2 ;
   break ;
      }
      case 0x00e1 : {
   bone->m_scale = ( (SceGmoScale *)args )->scale ;
   bone->m_flags |= HAS_SCALE_3 ;
   break ;
      }
      case SCEGMO_DRAW_PART : {
   SceGmoDrawPart *cmd = (SceGmoDrawPart *)args ;
   bone->m_draw_parts[ bone->m_n_draw_parts ++ ] = cmd->part ;
   has_draw_part = 1 ;
   break ;
      }
  }
 }
 bone->m_flags |= LOCAL_MATRIX_DIRTY ;
 if ( !( bone->m_flags & HAS_VISIBILITY ) ) {
  bone->m_visibility = has_draw_part ? -1 : 0 ;
 }
 if ( bone->m_n_blend_bones > 0 ) {
  if ( !set_blend_offsets( bone, 0, bone->m_n_blend_bones ) ) {
   ;
   return 0 ;
  }
  { int i ; for ( i = 0 ; i < bone->m_n_blend_bones ; i ++ ) {
   if ( blend_offsets != 0 && i < blend_offsets->n_offsets ) {
    bone->m_blend_offsets[ i ] = blend_offsets->offsets[ i ] ;
   } else {
    bone->m_blend_offsets[ i ] = g_identity ;
   }
  } }
 }
 bone->m_initial = sceGmoBoneDuplicate( bone, SCEGMO_DUPLICATE_BONE ) ;
 if ( bone->m_initial == 0 ) return 0 ;
 return 1 ;
}

void sceGmoBoneUnload( SceGmoBone *bone )
{
 if ( bone == 0 ) return ;

 sceGmoBoneDelete( bone->m_initial ) ;
 bone->m_initial = 0 ;

 sceGmoModelFreeMemory( bone->m_draw_parts ) ;
 sceGmoModelFreeMemory( bone->m_morph_weights ) ;
 sceGmoModelFreeMemory( bone->m_blend_bones ) ;
 sceGmoModelFreeMemory( bone->m_blend_offsets ) ;
 bone->m_draw_parts = 0 ;
 bone->m_morph_weights = 0 ;
 bone->m_blend_bones = 0 ;
 bone->m_blend_offsets = 0 ;
 bone->m_n_draw_parts = 0 ;
 bone->m_n_morph_weights = 0 ;
 bone->m_n_blend_bones = 0 ;
 bone->m_n_blend_offsets = 0 ;
}

void sceGmoBoneDraw( SceGmoBone *bone, SceGmoModel *model )
{
 if ( bone == 0 ) return ;
 if ( bone->m_visibility == 0 ) return ;

 { int i ; for ( i = 0 ; i < bone->m_n_morph_weights ; i ++ ) {
  sceGuMorphWeight( i, bone->m_morph_weights[ i ] ) ;
 } }

 if ( bone->m_n_blend_bones > 0 ) {
  SceGmoBone *initial = bone->m_initial ;
  { int i ; for ( i = 0 ; i < bone->m_n_blend_bones ; i ++ ) {
   int index = bone->m_blend_bones[ i ] ;
   SceGmoBone *bone2 = sceGmoModelGetBone( model, index ) ;
   if ( bone2 == 0 ) continue ;
   const mat4 *world = sceGmoBoneGetWorldMatrix( bone2 ) ;
   mat4 *offset = initial->m_blend_offsets + i ;
   mat4 *offset2 = bone->m_blend_offsets + i ;
   mat4_mul( offset2, world, offset ) ;
  } }
 }

 SceGmoSubject *parent = sceGmoBaseGetParent( &( bone->m_base ) ) ;
 if ( parent != 0 ) model = (SceGmoModel *)parent ;

 { int i ; for ( i = 0 ; i < bone->m_n_draw_parts ; i ++ ) {
  if ( ( ( 1 << i ) & bone->m_visibility ) == 0 ) continue ;
  SceGmoPart *part = sceGmoModelGetPart( model, bone->m_draw_parts[ i ] ) ;
  sceGmoPartDraw( part, model, bone ) ;
 } }
}

void sceGmoBoneActivate( SceGmoBone *bone, SceGmoModel *model, const int *indices, int n_indices )
{
 if ( bone == 0 ) return ;

 const mat4 *voffs = sceGmoModelGetVertexOffset( model ) ;
 mat4 tmp ;

 int n_bones = bone->m_n_blend_bones ;
 if ( n_bones == 0 ) {
  const mat4 *m = sceGmoBoneGetWorldMatrix( bone ) ;
  if ( voffs != 0 ) m = mat4_mul( &tmp, m, voffs ) ;
  sceGuSetMatrix( 2, m ) ;
  return ;
 }

 sceGuSetMatrix( 2, &g_identity ) ;
 if ( n_indices == 0 ) {
  if ( n_bones > (8) ) n_bones = (8) ;
  { int i ; for ( i = 0 ; i < n_bones ; i ++ ) {
   mat4 *m = bone->m_blend_offsets + i ;
   if ( voffs != 0 ) m = mat4_mul( &tmp, m, voffs ) ;
   sceGuBoneMatrix( i, (ScePspFMatrix4 *)m ) ;
  } }
 } else {
  if ( n_indices > (8) ) n_indices = (8) ;
  { int i ; for ( i = 0 ; i < n_indices ; i ++ ) {
   mat4 *m = bone->m_blend_offsets + indices[ i ] ;
   if ( voffs != 0 ) m = mat4_mul( &tmp, m, voffs ) ;
   sceGuBoneMatrix( i, (ScePspFMatrix4 *)m ) ;
  } }
 }
}

void sceGmoBoneAnimate( SceGmoBone *bone, int type, int idx, const float *val, int cnt, float weight )
{
 if ( bone == 0 ) return ;

 float *dst ;
 int flags ;
 int channel ;
 quat rotate ;
 float weights[ (8) ] ;
 switch ( type ) {
     case SCEGMO_TRANSLATE :
  dst = (float *)&( bone->m_translate ) ;
  flags = HAS_TRANSLATE ;
  channel = 1 ;
  break ;
     case SCEGMO_ROTATE_Q :
  dst = (float *)&( bone->m_rotate ) ;
  flags = HAS_ROTATE ;
  channel = 2 ;
  break ;
     case SCEGMO_ROTATE_ZYX :
  dst = (float *)&( bone->m_rotate ) ;
  flags = HAS_ROTATE ;
  channel = 2 ;
  quat_from_rotzyx( &rotate, (vec3 *)val ) ;
  val = (float *)&rotate ;
  break ;
     case SCEGMO_ROTATE_YXZ :
  dst = (float *)&( bone->m_rotate ) ;
  flags = HAS_ROTATE ;
  channel = 2 ;
  quat_from_rotyxz( &rotate, (vec3 *)val ) ;
  val = (float *)&rotate ;
  break ;
     case SCEGMO_SCALE :
  dst = (float *)&( bone->m_scale ) ;
  flags = HAS_SCALE ;
  channel = 3 ;
  break ;
     case SCEGMO_SCALE_2 :
  dst = (float *)&( bone->m_scale ) ;
  flags = HAS_SCALE_2 ;
  channel = 3 ;
  break ;
     case 0x00e1 :
  dst = (float *)&( bone->m_scale ) ;
  flags = HAS_SCALE_3 ;
  channel = 3 ;
  break ;
     case SCEGMO_MULT_MATRIX :
  dst = (float *)&( bone->m_local_matrix ) ;
  flags = HAS_MULT_MATRIX ;
  channel = 0 ;
  break ;
     case SCEGMO_MORPH_WEIGHTS :
  set_morph_weights( bone, 0, cnt ) ;
  dst = bone->m_morph_weights ;
  flags = HAS_MORPH_WEIGHTS ;
  channel = 4 ;
  break ;
     case SCEGMO_MORPH_INDEX :
  calc_morph_index( weights, (8), *val ) ;
  set_morph_weights( bone, weights, (8) ) ;
  val = weights ;
  cnt = (8) ;
  dst = bone->m_morph_weights ;
  flags = HAS_MORPH_WEIGHTS ;
  channel = 4 ;
  break ;

     case SCEGMO_VISIBILITY :
  bone->m_flags |= HAS_VISIBILITY ;
  bone->m_anim_flags |= HAS_VISIBILITY | ( HAS_VISIBILITY << 16 ) ;
  bone->m_visibility = (int)( val[ 0 ] + 0.5f ) ;
  return ;
     default :
  return ;
 }

 float sum = bone->m_anim_weights[ channel ] + weight ;
 bone->m_anim_weights[ channel ] = sum ;
 weight /= sum ;
 if ( channel != 2 ) {
  float_lerp( dst, dst, val, cnt, weight ) ;
 } else {
  quat_slerp( (quat *)dst, (quat *)dst, (quat *)val, weight ) ;
 }
 bone->m_flags |= flags | LOCAL_MATRIX_DIRTY ;
 if ( sum > 0.99f ) flags |= ( flags << 16 ) ;
 bone->m_anim_flags |= flags ;
}

const mat4 *sceGmoBoneGetWorldMatrix( SceGmoBone *bone )
{
 if ( bone == 0 ) return 0 ;
 if ( !( bone->m_flags & STACK_SCALE_ACTIVE ) ) {
  return &( bone->m_stack_matrix ) ;
 } else {
  mat4 *m = &( bone->m_world_matrix ) ;
  if ( bone->m_flags & WORLD_MATRIX_DIRTY ) {
   bone->m_flags &= ~WORLD_MATRIX_DIRTY ;
   mat4 *m2 = &( bone->m_stack_matrix ) ;
   vec4_scale( &( m->x ), &( m2->x ), bone->m_stack_scale.x ) ;
   vec4_scale( &( m->y ), &( m2->y ), bone->m_stack_scale.y ) ;
   vec4_scale( &( m->z ), &( m2->z ), bone->m_stack_scale.z ) ;
   m->w = m2->w ;
  }
  return m ;
 }
}

_Bool set_blend_bones( SceGmoBone *bone, const int *bones, int n_bones )
{
 if ( bone->m_n_blend_bones != n_bones ) {
  int size = sizeof( int ) * n_bones ;
  if ( !sceGmoModelAllocPtr( &( bone->m_blend_bones ), size ) ) {
   bone->m_n_blend_bones = 0 ;
   return 0 ;
  }
  bone->m_n_blend_bones = n_bones ;
 }
 if ( bones != 0 ) {
  memcpy( bone->m_blend_bones, bones, sizeof( int ) * n_bones ) ;
 }
 return 1 ;
}

_Bool set_blend_offsets( SceGmoBone *bone, const mat4 *offsets, int n_offsets )
{
 if ( bone->m_n_blend_offsets != n_offsets ) {
  int size = sizeof( mat4 ) * n_offsets ;
  if ( !sceGmoModelAllocPtr( &( bone->m_blend_offsets ), size ) ) {
   bone->m_n_blend_offsets = 0 ;
   return 0 ;
  }
  bone->m_n_blend_offsets = n_offsets ;
 }
 if ( offsets != 0 ) {
  memcpy( bone->m_blend_offsets, offsets, sizeof( mat4 ) * n_offsets ) ;
 }
 return 1 ;
}

_Bool set_morph_weights( SceGmoBone *bone, const float *weights, int n_weights )
{
 if ( n_weights > (8) ) n_weights = (8) ;
 if ( bone->m_n_morph_weights < n_weights ) {
  int size = sizeof( float ) * n_weights ;
  if ( !sceGmoModelAllocPtr( &( bone->m_morph_weights ), size ) ) {
   bone->m_n_morph_weights = 0 ;
   return 0 ;
  }
  bone->m_n_morph_weights = n_weights ;
 }
 if ( weights != 0 ) {
  memcpy( bone->m_morph_weights, weights, sizeof( float ) * n_weights ) ;
 }
 return 1 ;
}

void calc_morph_index( float *weights, int n_weights, float index )
{
 memset( weights, 0, sizeof( float ) * n_weights ) ;
 int index2 = (int)floorf( index ) ;
 if ( index2 < 0 ) index2 = 0 ;
 if ( index2 > n_weights - 2 ) index2 = n_weights - 2 ;
 index -= (float)index2 ;
 weights[ index2 + 0 ] = 1.0f - index ;
 weights[ index2 + 1 ] = index ;
}

mat4 *mat4_mul( mat4 *dst, const mat4 *src1, const mat4 *src2 )
{
 mat4 tmp ;
 if ( src1 == dst ) {
  tmp = *src1 ;
  src1 = &tmp ;
 }
 mat4_app( &( dst->x ), src1, &( src2->x ) ) ;
 mat4_app( &( dst->y ), src1, &( src2->y ) ) ;
 mat4_app( &( dst->z ), src1, &( src2->z ) ) ;
 mat4_app( &( dst->w ), src1, &( src2->w ) ) ;
 return dst ;
}

vec4 *mat4_app( vec4 *dst, const mat4 *src1, const vec4 *src2 )
{
 float x = src2->x ;
 float y = src2->y ;
 float z = src2->z ;
 float w = src2->w ;
 const float *m = (const float *)src1 ;
 dst->x = m[ 0 ] * x + m[ 4 ] * y + m[ 8 ] * z + m[ 12 ] * w ;
 dst->y = m[ 1 ] * x + m[ 5 ] * y + m[ 9 ] * z + m[ 13 ] * w ;
 dst->z = m[ 2 ] * x + m[ 6 ] * y + m[ 10 ] * z + m[ 14 ] * w ;
 dst->w = m[ 3 ] * x + m[ 7 ] * y + m[ 11 ] * z + m[ 15 ] * w ;
 return dst ;
}

vec3 *vec3_mul( vec3 *dst, const vec3 *src1, const vec3 *src2 )
{
 dst->x = src1->x * src2->x ;
 dst->y = src1->y * src2->y ;
 dst->z = src1->z * src2->z ;
 return dst ;
}

vec3 *vec3_div( vec3 *dst, const vec3 *src1, const vec3 *src2 )
{
 dst->x = ( src2->x == 0.0f ) ? src1->x : src1->x / src2->x ;
 dst->y = ( src2->y == 0.0f ) ? src1->y : src1->y / src2->y ;
 dst->z = ( src2->z == 0.0f ) ? src1->z : src1->z / src2->z ;
 return dst ;
}

vec4 *vec4_scale( vec4 *dst, const vec4 *src1, float src2 )
{
 dst->x = src1->x * src2 ;
 dst->y = src1->y * src2 ;
 dst->z = src1->z * src2 ;
 dst->w = src1->w * src2 ;
 return dst ;
}

float *float_lerp( float *dst, const float *src1, const float *src2, int dim, float rate )
{
 if ( rate >= 1.0f ) return (float *)memcpy( dst, src2, sizeof( float ) * dim ) ;
 if ( rate <= 0.0f ) return (float *)memcpy( dst, src1, sizeof( float ) * dim ) ;
 float *dp = dst ;
 { int i ; for ( i = 0 ; i < dim ; i ++ ) {
  float a = *( src1 ++ ) ;
  float b = *( src2 ++ ) ;
  *( dp ++ ) = ( b - a ) * rate + a ;
 } }
 return dst ;
}

mat4 *mat4_from_quat( mat4 *dst, const quat *src )
{
 float x = src->x ;
 float y = src->y ;
 float z = src->z ;
 float w = src->w ;
 float *m = (float *)dst ;
 m[ 0 ] = 1 - 2 * y * y - 2 * z * z ;
 m[ 1 ] = 2 * x * y + 2 * w * z ;
 m[ 2 ] = 2 * z * x - 2 * w * y ;
 m[ 3 ] = 0 ;
 m[ 4 ] = 2 * x * y - 2 * w * z ;
 m[ 5 ] = 1 - 2 * x * x - 2 * z * z ;
 m[ 6 ] = 2 * y * z + 2 * w * x ;
 m[ 7 ] = 0 ;
 m[ 8 ] = 2 * z * x + 2 * w * y ;
 m[ 9 ] = 2 * y * z - 2 * w * x ;
 m[ 10 ] = 1 - 2 * x * x - 2 * y * y ;
 m[ 11 ] = 0 ;
 m[ 12 ] = 0 ;
 m[ 13 ] = 0 ;
 m[ 14 ] = 0 ;
 m[ 15 ] = 1 ;
 return dst ;
}

quat *quat_from_rotzyx( quat *dst, const vec3 *src )
{
 float x = src->x * 0.5f ;
 float y = src->y * 0.5f ;
 float z = src->z * 0.5f ;
 float cx = cosf( x ) ;
 float sx = sinf( x ) ;
 float cy = cosf( y ) ;
 float sy = sinf( y ) ;
 float cz = cosf( z ) ;
 float sz = sinf( z ) ;
 dst->x = cz * cy * sx - cx * sz * sy ;
 dst->y = cx * cz * sy + cy * sz * sx ;
 dst->z = cx * cy * sz - cz * sy * sx ;
 dst->w = cz * cy * cx + sz * sy * sx ;
 return dst ;
}

quat *quat_from_rotyxz( quat *dst, const vec3 *src )
{
 float x = src->x * 0.5f ;
 float y = src->y * 0.5f ;
 float z = src->z * 0.5f ;
 float cx = cosf( x ) ;
 float sx = sinf( x ) ;
 float cy = cosf( y ) ;
 float sy = sinf( y ) ;
 float cz = cosf( z ) ;
 float sz = sinf( z ) ;
 dst->x = cy * cz * sx + sy * cx * sz ;
 dst->y = sy * cx * cz - cy * sx * sz ;
 dst->z = cy * cx * sz - sy * cz * sx ;
 dst->w = cy * cx * cz + sy * sx * sz ;
 return dst ;
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

void sceGmoBoneUpdate( SceGmoBone *bone, SceGmoModel *model )
{
 if ( bone == 0 ) return ;
 complement_animation( bone ) ;
 calc_local_matrix( bone ) ;
 calc_stack_matrix( bone, model ) ;
}

void sceGmoBoneSetParent( SceGmoBone *bone, SceGmoModel *parent )
{
 if ( bone == 0 ) return ;
 sceGmoBaseSetParent( &( bone->m_base ), (SceGmoSubject *)parent ) ;
}

SceGmoModel *sceGmoBoneGetParent( SceGmoBone *bone )
{
 if ( bone == 0 ) return 0 ;
 return (SceGmoModel *)sceGmoBaseGetParent( &( bone->m_base ) ) ;
}

void complement_animation( SceGmoBone *bone )
{
 int flags = bone->m_anim_flags ;
 int reset = ANIM_COMPLETE ;
 int modified = ( flags & ANIM_MODIFIED ) ;
 int complete = ( flags & ANIM_COMPLETE ) >> 16 ;
 int incomplete = modified & ~complete ;
 if ( incomplete ) {
  SceGmoBone *initial = bone->m_initial ;
  if ( incomplete & HAS_MULT_MATRIX ) {
   float w = 1.0f - bone->m_anim_weights[ 0 ] ;
   float *val = (float *)&( initial->m_local_matrix ) ;
   sceGmoBoneAnimate( bone, SCEGMO_MULT_MATRIX, 0, val, 16, w ) ;
   if ( w > 0.99f ) reset |= HAS_MULT_MATRIX ;
  }
  if ( incomplete & HAS_TRANSLATE ) {
   float w = 1.0f - bone->m_anim_weights[ 1 ] ;
   float *val = (float *)&( initial->m_translate ) ;
   sceGmoBoneAnimate( bone, SCEGMO_TRANSLATE, 0, val, 3, w ) ;
   if ( w > 0.99f ) reset |= HAS_TRANSLATE ;
  }
  if ( incomplete & HAS_ROTATE ) {
   float w = 1.0f - bone->m_anim_weights[ 2 ] ;
   float *val = (float *)&( initial->m_rotate ) ;
   sceGmoBoneAnimate( bone, SCEGMO_ROTATE_Q, 0, val, 4, w ) ;
   if ( w > 0.99f ) reset |= HAS_ROTATE ;
  }
  if ( incomplete & HAS_SCALE ) {
   float w = 1.0f - bone->m_anim_weights[ 3 ] ;
   float *val = (float *)&( initial->m_scale ) ;
   sceGmoBoneAnimate( bone, SCEGMO_SCALE, 0, val, 3, w ) ;
   if ( w > 0.99f ) reset |= HAS_SCALE ;
  }
  if ( incomplete & HAS_SCALE_2 ) {
   float w = 1.0f - bone->m_anim_weights[ 3 ] ;
   float *val = (float *)&( initial->m_scale ) ;
   sceGmoBoneAnimate( bone, SCEGMO_SCALE_2, 0, val, 3, w ) ;
   if ( w > 0.99f ) reset |= HAS_SCALE_2 ;
  }
  if ( incomplete & HAS_SCALE_3 ) {
   float w = 1.0f - bone->m_anim_weights[ 3 ] ;
   float *val = (float *)&( initial->m_scale ) ;
   sceGmoBoneAnimate( bone, 0x00e1, 0, val, 3, w ) ;
   if ( w > 0.99f ) reset |= HAS_SCALE_3 ;
  }
  if ( incomplete & HAS_MORPH_WEIGHTS ) {
   float w = 1.0f - bone->m_anim_weights[ 4 ] ;
   float *val = initial->m_morph_weights ;
   int cnt = initial->m_n_morph_weights ;
   if ( cnt == 0 ) {
    val = D_00147810 ;
    cnt = (8) ;
   }
   sceGmoBoneAnimate( bone, SCEGMO_MORPH_WEIGHTS, 0, val, cnt, w ) ;
   if ( w > 0.99f ) reset |= HAS_MORPH_WEIGHTS ;
  }
  if ( incomplete & HAS_VISIBILITY ) {
   bone->m_visibility = initial->m_visibility ;
   reset |= HAS_VISIBILITY ;
  }
 }
 bone->m_anim_flags &= ~reset ;
 if ( modified ) {
  memset( bone->m_anim_weights, 0, sizeof( bone->m_anim_weights ) ) ;
 }
}

void calc_local_matrix( SceGmoBone *bone )
{
 int flags = bone->m_flags ;
 if ( !( flags & LOCAL_MATRIX_DIRTY ) ) return ;
 bone->m_flags = flags & ~LOCAL_MATRIX_DIRTY ;

 if ( flags & HAS_MULT_MATRIX ) return ;

 mat4 *local = &( bone->m_local_matrix ) ;
 if ( flags & HAS_ROTATE ) {
  mat4_from_quat( local, &( bone->m_rotate ) ) ;
 } else {
  *local = g_identity ;
 }
 if ( flags & HAS_SCALE ) {
  vec4_scale( &( local->x ), &( local->x ), bone->m_scale.x ) ;
  vec4_scale( &( local->y ), &( local->y ), bone->m_scale.y ) ;
  vec4_scale( &( local->z ), &( local->z ), bone->m_scale.z ) ;
 }
 if ( flags & HAS_TRANSLATE ) {
  *(vec3 *)&( local->w ) = bone->m_translate ;
 }
}

void calc_stack_matrix( SceGmoBone *bone, SceGmoModel *model )
{
 SceGmoBone *parent = sceGmoModelGetBone( model, bone->m_parent_bone ) ;

 mat4 *stack = &( bone->m_stack_matrix ) ;
 *stack = bone->m_local_matrix ;
 int stack_scaled = 0 ;
 if ( parent != 0 ) {
  stack_scaled = ( parent->m_flags & STACK_SCALE_ACTIVE ) ;
  if ( stack_scaled ) {
   bone->m_flags |= STACK_SCALE_ACTIVE ;
   if ( parent->m_flags & HAS_SCALE_3 ) {
    vec3_div( &( bone->m_stack_scale ), &( parent->m_stack_scale ), &( parent->m_scale ) ) ;
   } else {
    bone->m_stack_scale = parent->m_stack_scale ;
   }
   vec3 *s = (vec3 *)&( stack->w ) ;
   vec3_mul( s, s, &( parent->m_stack_scale ) ) ;
  }
 }
 if ( bone->m_flags & HAS_PIVOT ) {
  vec3 *t = (vec3 *)&( Pivot.w ) ;
  *t = bone->m_pivot ;
  if ( stack_scaled ) vec3_mul( t, t, &( parent->m_stack_scale ) ) ;

  mat4 tmp ;
  mat4_mul( &tmp, &Pivot, stack ) ;
  *t = (vec3){ - t->x, - t->y, - t->z } ;
  mat4_mul( stack, &tmp, &Pivot ) ;
 }
 if ( parent == 0 ) {
  mat4_mul( stack, sceGmoModelGetWorldMatrix( model ), stack ) ;
 } else {
  mat4_mul( stack, &( parent->m_stack_matrix ), stack ) ;
 }

 if ( bone->m_flags & ( HAS_SCALE_2 | HAS_SCALE_3 ) ) {
  if ( stack_scaled ) {
   vec3 *s = &( bone->m_stack_scale ) ;
   vec3_mul( s, s, &( bone->m_scale ) ) ;
  } else {
   bone->m_stack_scale = bone->m_scale ;
   bone->m_flags |= STACK_SCALE_ACTIVE ;
  }
 }

 bone->m_flags |= WORLD_MATRIX_DIRTY ;
}
