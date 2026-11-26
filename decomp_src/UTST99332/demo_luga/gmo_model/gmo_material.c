/* cflags: -O2 -frename-registers -fmerge-constants */
/* data-align: 16 */
#include "gmo_private.h"
#include "include_asm.h"
#define complement_animation complement_animation_AA18
#define float_lerp float_lerp_A894
extern char D_00147870[];
#define Factors D_00147870

static void complement_animation( SceGmoMaterial *material ) ;
static _Bool reconfigure_material( SceGmoMaterial *material ) ;

static _Bool reconfigure_layer( SceGmoLayer *layer ) ;

static vec4 *vec4_col32( vec4 *dst, unsigned int src ) ;
static unsigned int col32_vec4( const vec4 *src ) ;
static unsigned int col32_lerp( unsigned int src1, unsigned int src2, float rate ) ;
static float *float_lerp( float *dst, const float *src1, const float *src2, int dim, float rate ) ;

enum {
 IMPLICIT_BASELAYER = 0x80000000,
 EXPLICIT_AMBIENT = 0x40000000,

 HAS_DIFFUSE = 0x0001,
 HAS_SPECULAR = 0x0002,
 HAS_EMISSION = 0x0004,
 HAS_AMBIENT = 0x0008,
 HAS_REFLECTION = 0x0010,
 HAS_REFRACTION = 0x0020,
 HAS_BUMP = 0x0040,
 HAS_TEX_CROP = 0x0100,
 HAS_TEX_CROPS = 0xff00,
} ;

enum {
 ANIM_MODIFIED = 0x0000ffff,
 ANIM_COMPLETE = 0xffff0000,
} ;

enum {
 COLOR_BLACK = 0,
 COLOR_DIFFUSE = 1,
 COLOR_SPECULAR = 2,
 COLOR_EMISSION = 3,
 COLOR_AMBIENT = 4,
 COLOR_REFLECTION = 5,
} ;

enum {
 LAYER_HAS_TEX_CROP = 0x0001,
} ;

SceGmoMaterial *sceGmoMaterialCreate( SceGmoChunk *chunk )
{
 SceGmoMaterial *material = (SceGmoMaterial *)sceGmoModelAllocMemory( sizeof( SceGmoMaterial ) ) ;
 if ( material == 0 ) {
  ;
  return 0 ;
 }
 sceGmoBaseConstruct( &( material->m_base ) ) ;
 material->m_initial = 0 ;
 material->m_reference = 1 ;
 material->m_flags = 0 ;

 material->m_n_layers = 0 ;

 material->m_enable_mask = 0 ;
 material->m_enable_bits = 0 ;
 material->m_colors[ COLOR_BLACK ] = 0xff000000 ;
 material->m_colors[ COLOR_DIFFUSE ] = 0xffffffff ;
 material->m_colors[ COLOR_SPECULAR ] = 0xff000000 ;
 material->m_colors[ COLOR_EMISSION ] = 0xff000000 ;
 material->m_colors[ COLOR_AMBIENT ] = 0xffffffff ;
 material->m_colors[ COLOR_REFLECTION ] = 0x00ffffff ;
 material->m_shininess = 0.0f ;
 material->m_refraction = 1.0f ;
 material->m_bump = 0.0f ;

 material->m_anim_flags = 0 ;
 memset( material->m_anim_weights, 0, sizeof( material->m_anim_weights ) ) ;

 if ( chunk != 0 && !sceGmoMaterialLoad( material, chunk ) ) {
  sceGmoMaterialDelete( material ) ;
  return 0 ;
 }
 return material ;
}

void sceGmoMaterialDelete( SceGmoMaterial *material )
{
 if ( material == 0 ) return ;
 if ( -- material->m_reference == 0 ) {
  sceGmoMaterialUnload( material ) ;
  sceGmoBaseDestruct( &( material->m_base ) ) ;
  sceGmoModelFreeMemory( material ) ;
 }
}

SceGmoMaterial *sceGmoMaterialDuplicate( SceGmoMaterial *material, int flags )
{

 if ( material == 0 ) return 0 ;
 if ( !( SCEGMO_DUPLICATE_STRUCTURE & flags )
   && !( SCEGMO_DUPLICATE_MATERIAL & flags )
   && !( SCEGMO_DUPLICATE_LAYER & flags ) ) {
  material->m_reference ++ ;
  return material ;
 }

 SceGmoMaterial *material2 = sceGmoMaterialCreate( 0 ) ;
 if ( material2 == 0 ) return 0 ;
 sceGmoBaseCopy( &( material2->m_base ), &( material->m_base ) ) ;

 flags &= ~SCEGMO_DUPLICATE_STRUCTURE ;
 flags |= SCEGMO_DUPLICATE_AUTOMATIC ;
 { int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
  SceGmoLayer *src = material->m_layers[ i ] ;
  SceGmoLayer *dst = sceGmoLayerDuplicate( src, flags ) ;
  if ( dst == 0 && src != 0 ) {
   sceGmoMaterialDelete( material2 ) ;
   return 0 ;
  }
  material2->m_layers[ material2->m_n_layers ++ ] = dst ;
 } }
 material2->m_initial = sceGmoMaterialDuplicate( material->m_initial, SCEGMO_DUPLICATE_REFERENCE ) ;
 material2->m_flags = material->m_flags ;

 material2->m_enable_mask = material->m_enable_mask ;
 material2->m_enable_bits = material->m_enable_bits ;
 memcpy( material2->m_colors, material->m_colors, sizeof( material->m_colors ) ) ;
 material2->m_shininess = material->m_shininess ;
 material2->m_refraction = material->m_refraction ;
 material2->m_bump = material->m_bump ;

 material2->m_anim_flags = material->m_anim_flags ;
 memcpy( material2->m_anim_weights, material->m_anim_weights, sizeof( material->m_anim_weights ) ) ;
 return material2 ;
}

_Bool sceGmoMaterialLoad( SceGmoMaterial *material, SceGmoChunk *chunk )
{
 if ( material == 0 ) return 0 ;
 if ( chunk == 0 ) return 0 ;

 sceGmoMaterialUnload( material ) ;

 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  void *args = SCEGMO_CHUNK_ARGS( chunk ) ;

  switch ( SCEGMO_CHUNK_TYPE( chunk ) ) {
      case SCEGMO_LAYER : {
   SceGmoLayer *layer = sceGmoLayerCreate( chunk ) ;
   if ( layer == 0 ) return 0 ;

   int flag = 0 ;
   switch ( sceGmoLayerGetMapType( layer ) ) {
       case SCEGMO_DIFFUSE : flag = HAS_DIFFUSE ; break ;
       case SCEGMO_SPECULAR : flag = HAS_SPECULAR ; break ;
       case SCEGMO_EMISSION : flag = HAS_EMISSION ; break ;
       case SCEGMO_AMBIENT : flag = HAS_AMBIENT ; break ;
       case SCEGMO_REFLECTION : flag = HAS_REFLECTION ; break ;
       case SCEGMO_REFRACTION :
       case SCEGMO_BUMP : {
    sceGmoLayerDelete( layer ) ;
    layer = 0 ;
    break ;
       }
   }
   material->m_flags |= flag ;
   if ( layer != 0 ) {
    material->m_layers[ material->m_n_layers ++ ] = layer ;
   }
   break ;
      }
      case SCEGMO_RENDER_STATE : {
   SceGmoRenderState *cmd = (SceGmoRenderState *)args ;
   int flag = 0 ;
   switch ( cmd->state ) {
       case SCEGMO_STATE_LIGHTING :
    flag = SCEGMO_ENABLE_LIGHTING ;
    break ;
       case SCEGMO_STATE_FOG :
    flag = SCEGMO_ENABLE_FOG ;
    break ;
       case SCEGMO_STATE_CULL_FACE :
    flag = SCEGMO_ENABLE_CULL_FACE ;
    break ;
       case SCEGMO_STATE_DEPTH_TEST :
    flag = SCEGMO_ENABLE_DEPTH_TEST ;
    break ;
       case SCEGMO_STATE_DEPTH_MASK :
    flag = SCEGMO_ENABLE_DEPTH_MASK ;
    break ;
       case SCEGMO_STATE_ALPHA_TEST :
    flag = SCEGMO_ENABLE_ALPHA_TEST ;
    break ;
       case SCEGMO_STATE_ALPHA_MASK :
    flag = SCEGMO_ENABLE_ALPHA_MASK ;
    break ;
   }
   material->m_enable_mask |= flag ;
   material->m_enable_bits |= !( cmd->value ) ? 0 : flag ;
   break ;
      }
      case SCEGMO_DIFFUSE : {
   SceGmoDiffuse *cmd = (SceGmoDiffuse *)args ;
   material->m_colors[ COLOR_DIFFUSE ] = col32_vec4( &( cmd->color ) ) ;
   break ;
      }
      case SCEGMO_SPECULAR : {
   SceGmoSpecular *cmd = (SceGmoSpecular *)args ;
   material->m_colors[ COLOR_SPECULAR ] = col32_vec4( &( cmd->color ) ) ;
   material->m_shininess = cmd->shininess ;
   break ;
      }
      case SCEGMO_EMISSION : {
   SceGmoEmission *cmd = (SceGmoEmission *)args ;
   material->m_colors[ COLOR_EMISSION ] = col32_vec4( &( cmd->color ) ) ;
   break ;
      }
      case SCEGMO_AMBIENT : {
   SceGmoAmbient *cmd = (SceGmoAmbient *)args ;
   material->m_colors[ COLOR_AMBIENT ] = col32_vec4( &( cmd->color ) ) ;
   material->m_flags |= EXPLICIT_AMBIENT ;
   break ;
      }
      case SCEGMO_REFLECTION : {
   SceGmoReflection *cmd = (SceGmoReflection *)args ;
   unsigned int alpha = 255 * cmd->reflection ;
   unsigned int color = ( alpha << 24 ) | 0x00ffffff ;
   material->m_colors[ COLOR_REFLECTION ] = color ;
   break ;
      }
      case SCEGMO_REFRACTION : {
   SceGmoRefraction *cmd = (SceGmoRefraction *)args ;
   material->m_refraction = cmd->refraction ;
   break ;
      }
      case SCEGMO_BUMP : {
   SceGmoBump *cmd = (SceGmoBump *)args ;
   material->m_bump = cmd->bump ;
   break ;
      }
  }
 }

 if ( !( material->m_flags & EXPLICIT_AMBIENT ) ) {
  material->m_colors[ COLOR_AMBIENT ] = material->m_colors[ COLOR_DIFFUSE ] ;
 }
 if ( !reconfigure_material( material ) ) return 0 ;

 material->m_initial = sceGmoMaterialDuplicate( material, SCEGMO_DUPLICATE_MATERIAL ) ;
 if ( material->m_initial == 0 ) return 0 ;
 return 1 ;
}

void sceGmoMaterialUnload( SceGmoMaterial *material )
{
 if ( material == 0 ) return ;

 sceGmoMaterialDelete( material->m_initial ) ;
 material->m_initial = 0 ;

 { int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
  sceGmoLayerDelete( material->m_layers[ i ] ) ;
 } }
 material->m_n_layers = 0 ;
}

void sceGmoMaterialAnimate( SceGmoMaterial *material, int type, int idx, const float *val, int cnt, float weight )
{
 if ( material == 0 ) return ;
 if ( val == 0 ) return ;

 int *dst ;
 int flags ;
 int channel ;
 vec4 reflection ;
 switch ( type ) {
     case SCEGMO_DIFFUSE :
  if ( !( material->m_flags & EXPLICIT_AMBIENT ) ) {
   sceGmoMaterialAnimate( material, SCEGMO_AMBIENT, idx, val, cnt, weight ) ;
  }
  dst = material->m_colors + COLOR_DIFFUSE ;
  flags = HAS_DIFFUSE ;
  channel = 0 ;
  break ;
     case SCEGMO_SPECULAR :
  dst = material->m_colors + COLOR_SPECULAR ;
  flags = HAS_SPECULAR ;
  channel = 1 ;
  break ;
     case SCEGMO_EMISSION :
  dst = material->m_colors + COLOR_EMISSION ;
  flags = HAS_EMISSION ;
  channel = 2 ;
  break ;
     case SCEGMO_AMBIENT :
  material->m_flags |= EXPLICIT_AMBIENT ;
  dst = material->m_colors + COLOR_AMBIENT ;
  flags = HAS_AMBIENT ;
  channel = 3 ;
  break ;
     case SCEGMO_REFLECTION :
  reflection = (vec4){ 1, 1, 1, 1 } ;
  reflection.w = *val ;
  val = (float *)&reflection ;
  dst = material->m_colors + COLOR_REFLECTION ;
  flags = HAS_REFLECTION ;
  channel = 4 ;
  break ;

     case SCEGMO_REFRACTION :
  material->m_anim_flags = HAS_REFRACTION | ( HAS_REFRACTION << 16 ) ;
  material->m_refraction = *val ;
  return ;
     case SCEGMO_BUMP :
  material->m_anim_flags = HAS_BUMP | ( HAS_BUMP << 16 ) ;
  material->m_bump = *val ;
  return ;
     case SCEGMO_TEX_CROP : {
  if ( material->m_flags & IMPLICIT_BASELAYER ) idx ++ ;
  if ( idx < 0 || idx >= material->m_n_layers ) return ;
  flags = HAS_TEX_CROP | ( HAS_TEX_CROP << 16 ) ;
  material->m_anim_flags = flags << idx ;
  SceGmoLayer *layer = material->m_layers[ idx ] ;
  sceGmoLayerSetTexCrop( layer, (rect *)val ) ;
  return ;
     }
     default :
  return ;
 }

 float sum = material->m_anim_weights[ channel ] + weight ;
 material->m_anim_weights[ channel ] = sum ;
 weight /= sum ;
 *dst = col32_lerp( *dst, col32_vec4( (const vec4 *)val ), weight ) ;
 if ( channel == 1 ) {
  float *fp = &( material->m_shininess ) ;
  float_lerp( fp, fp, val + 4, 1, weight ) ;
 }
 if ( sum > 0.99f ) flags |= ( flags << 16 ) ;
 material->m_anim_flags |= flags ;
}

_Bool reconfigure_material( SceGmoMaterial *material )
{

 if ( !( material->m_flags & HAS_DIFFUSE ) ) {
  material->m_flags |= HAS_DIFFUSE | IMPLICIT_BASELAYER ;
  SceGmoLayer *layer = sceGmoLayerCreate( 0 ) ;
  if ( layer == 0 ) return 0 ;
  { int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
   material->m_layers[ i + 1 ] = material->m_layers[ i ] ;
  } }
  material->m_layers[ 0 ] = layer ;
  material->m_n_layers ++ ;
 }
 if ( ( 0x00ffffff & material->m_colors[ COLOR_EMISSION ] ) != 0 ) {
  if ( !( material->m_flags & HAS_EMISSION ) ) {
   material->m_flags |= HAS_EMISSION ;
   SceGmoLayer *layer = sceGmoLayerCreate( 0 ) ;
   if ( layer == 0 ) return 0 ;
   material->m_layers[ material->m_n_layers ++ ] = layer ;
   sceGmoLayerSetMapType( layer, SCEGMO_EMISSION ) ;
  }
 }
 if ( ( 0xff000000 & material->m_colors[ COLOR_REFLECTION ] ) != 0 ) {
  if ( !( material->m_flags & HAS_REFLECTION ) ) {
   material->m_flags |= HAS_REFLECTION ;
   SceGmoLayer *layer = sceGmoLayerCreate( 0 ) ;
   if ( layer == 0 ) return 0 ;
   material->m_layers[ material->m_n_layers ++ ] = layer ;
   sceGmoLayerSetMapType( layer, SCEGMO_REFLECTION ) ;
  }
 }

 SceGmoLayer *topmost = 0 ;
 { int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
  SceGmoLayer *layer = material->m_layers[ i ] ;
  if ( sceGmoLayerGetMapType( layer ) == SCEGMO_DIFFUSE ) topmost = layer ;
 } }

 if ( topmost != 0 ) {
  int flags = material->m_flags ;
  if ( !( flags & HAS_SPECULAR ) ) {
   topmost->m_specular = COLOR_SPECULAR ;
   topmost->m_enable_mask |= SCEGMO_ENABLE_SEPARATE_SPECULAR ;
   topmost->m_enable_bits |= SCEGMO_ENABLE_SEPARATE_SPECULAR ;
  } else {
   topmost->m_specular = COLOR_BLACK ;
   topmost->m_enable_mask |= SCEGMO_ENABLE_SEPARATE_SPECULAR ;
   topmost->m_enable_bits &= ~SCEGMO_ENABLE_SEPARATE_SPECULAR ;
  }
  if ( !( flags & HAS_AMBIENT ) ) {
   topmost->m_ambient = COLOR_AMBIENT ;
  } else {
   topmost->m_ambient = COLOR_BLACK ;
  }
 }
 return 1 ;
}

SceGmoLayer *sceGmoLayerCreate( SceGmoChunk *chunk )
{
 SceGmoLayer *layer = (SceGmoLayer *)sceGmoModelAllocMemory( sizeof( SceGmoLayer ) ) ;
 if ( layer == 0 ) {
  ;
  return 0 ;
 }
 layer->m_initial = 0 ;
 layer->m_reference = 1 ;
 layer->m_flags = 0 ;

 layer->m_map_type = SCEGMO_DIFFUSE ;
 layer->m_map_factor = 1.0f ;
 layer->m_blend_func[ 0 ] = 0 ;
 layer->m_blend_func[ 1 ] = 2 ;
 layer->m_blend_func[ 2 ] = 3 ;
 layer->m_blend_func[ 3 ] = 0x00000000 ;
 layer->m_blend_func[ 4 ] = 0x00000000 ;
 layer->m_texture = -1 ;
 layer->m_tex_crop = (rect){ 0, 0, 1, 1 } ;

 layer->m_enable_mask = 0 ;
 layer->m_enable_bits = 0 ;
 layer->m_diffuse = COLOR_DIFFUSE ;
 layer->m_specular = COLOR_BLACK ;
 layer->m_ambient = COLOR_BLACK ;

 if ( chunk != 0 && !sceGmoLayerLoad( layer, chunk ) ) {
  sceGmoLayerDelete( layer ) ;
  return 0 ;
 }
 return layer ;
}

void sceGmoLayerDelete( SceGmoLayer *layer )
{
 if ( layer == 0 ) return ;
 if ( -- layer->m_reference == 0 ) {
  sceGmoLayerUnload( layer ) ;
  sceGmoModelFreeMemory( layer ) ;
 }
}

SceGmoLayer *sceGmoLayerDuplicate( SceGmoLayer *layer, int flags )
{

 if ( layer == 0 ) return 0 ;
 if ( !( SCEGMO_DUPLICATE_STRUCTURE & flags )
   && !( SCEGMO_DUPLICATE_LAYER & flags ) ) {
  layer->m_reference ++ ;
  return layer ;
 }

 SceGmoLayer *layer2 = sceGmoLayerCreate( 0 ) ;
 if ( layer2 == 0 ) return 0 ;
 layer2->m_initial = sceGmoLayerDuplicate( layer->m_initial, SCEGMO_DUPLICATE_REFERENCE ) ;
 layer2->m_flags = layer->m_flags ;

 layer2->m_map_type = layer->m_map_type ;
 layer2->m_map_factor = layer->m_map_factor ;
 memcpy( layer2->m_blend_func, layer->m_blend_func, sizeof( layer->m_blend_func ) ) ;
 layer2->m_texture = layer->m_texture ;
 layer2->m_tex_crop = layer->m_tex_crop ;

 layer2->m_enable_mask = layer->m_enable_mask ;
 layer2->m_enable_bits = layer->m_enable_bits ;
 layer2->m_diffuse = layer->m_diffuse ;
 layer2->m_specular = layer->m_specular ;
 layer2->m_ambient = layer->m_ambient ;
 return layer2 ;
}

_Bool sceGmoLayerLoad( SceGmoLayer *layer, SceGmoChunk *chunk )
{
 if ( layer == 0 ) return 0 ;
 if ( chunk == 0 ) return 0 ;

 sceGmoLayerUnload( layer ) ;

 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  void *args = SCEGMO_CHUNK_ARGS( chunk ) ;

  switch ( SCEGMO_CHUNK_TYPE( chunk ) ) {
      case SCEGMO_SET_TEXTURE : {
   SceGmoSetTexture *cmd = (SceGmoSetTexture *)args ;
   layer->m_texture = cmd->texture ;
   break ;
      }
      case SCEGMO_MAP_TYPE : {
   SceGmoMapType *cmd = (SceGmoMapType *)args ;
   sceGmoLayerSetMapType( layer, cmd->type ) ;
   break ;
      }
      case SCEGMO_BLEND_FUNC : {
      SceGmoBlendFunc *cmd = (SceGmoBlendFunc *)args ;
   layer->m_blend_func[ 0 ] = cmd->mode ;
   layer->m_blend_func[ 1 ] = Factors[ cmd->src ] ;
   layer->m_blend_func[ 2 ] = Factors[ cmd->dst ] ;
   layer->m_blend_func[ 3 ] = ( cmd->src == 0 ) ? 0 : 0xffffffff ;
   layer->m_blend_func[ 4 ] = ( cmd->dst == 0 ) ? 0 : 0xffffffff ;
   break ;
      }
      case SCEGMO_TEX_CROP : {
   SceGmoTexCrop *cmd = (SceGmoTexCrop *)args ;
   sceGmoLayerSetTexCrop( layer, &( cmd->crop ) ) ;
   break ;
      }
  }
 }

 layer->m_initial = sceGmoLayerDuplicate( layer, SCEGMO_DUPLICATE_LAYER ) ;
 if ( layer->m_initial == 0 ) return 0 ;
 return 1 ;
}

void sceGmoLayerUnload( SceGmoLayer *layer )
{
 if ( layer == 0 ) return ;

 sceGmoLayerDelete( layer->m_initial ) ;
 layer->m_initial = 0 ;
}

int sceGmoLayerActivate( SceGmoLayer *layer, SceGmoModel *model, SceGmoMaterial *material )
{
 if ( layer == 0 ) return 0 ;
 if ( material == 0 ) return 0 ;
 int ambient = material->m_colors[ layer->m_ambient ] ;
 if ( ( 0xff000000 & ambient ) == 0 ) return 0 ;

 SceGmoTexture *texture = sceGmoModelGetTexture( model, layer->m_texture ) ;

 sceGmoContextSetTexture( texture, model ) ;

 rect *crop = !( layer->m_flags & LAYER_HAS_TEX_CROP ) ? 0 : &( layer->m_tex_crop ) ;
 sceGmoContextSetTexCrop( crop ) ;

 int mask = layer->m_enable_mask | material->m_enable_mask ;
 int bits = layer->m_enable_bits | ( ~layer->m_enable_mask & material->m_enable_bits ) ;
 sceGmoContextSetEnableBits( mask, bits ) ;

 sceGuMaterial( 2, material->m_colors[ layer->m_diffuse ] ) ;
 sceGuMaterial( 4, material->m_colors[ layer->m_specular ] ) ;
 sceGuMaterial( 1, ambient ) ;
 sceGuSpecular( material->m_shininess ) ;

 int *blend = layer->m_blend_func ;
 sceGuBlendFunc( blend[ 0 ], blend[ 1 ], blend[ 2 ], blend[ 3 ], blend[ 4 ] ) ;

 return layer->m_map_type ;
}

void sceGmoLayerSetMapType( SceGmoLayer *layer, int type )
{
 if ( layer == 0 ) return ;
 layer->m_map_type = type ;
 reconfigure_layer( layer ) ;
}

int sceGmoLayerGetMapType( SceGmoLayer *layer )
{
 if ( layer == 0 ) return 0 ;
 return layer->m_map_type ;
}

void sceGmoLayerSetTexCrop( SceGmoLayer *layer, const rect *crop )
{
 if ( layer == 0 ) return ;
 if ( crop == 0 ) {
  layer->m_flags &= ~LAYER_HAS_TEX_CROP ;
 } else {
  layer->m_flags |= LAYER_HAS_TEX_CROP ;
  layer->m_tex_crop = *crop ;
 }
}

const rect *sceGmoLayerGetTexCrop( SceGmoLayer *layer )
{
 if ( layer == 0 ) return 0 ;
 if ( !( layer->m_flags & LAYER_HAS_TEX_CROP ) ) return 0 ;
 return &( layer->m_tex_crop ) ;
}

_Bool reconfigure_layer( SceGmoLayer *layer )
{
 layer->m_blend_func[ 0 ] = 0 ;
 layer->m_blend_func[ 1 ] = 2 ;
 layer->m_blend_func[ 2 ] = 3 ;
 layer->m_blend_func[ 3 ] = 0xffffffff ;
 layer->m_blend_func[ 4 ] = 0xffffffff ;

 layer->m_diffuse = COLOR_BLACK ;
 layer->m_specular = COLOR_BLACK ;
 layer->m_ambient = COLOR_BLACK ;

 layer->m_enable_mask = SCEGMO_ENABLE_SEPARATE_SPECULAR ;
 layer->m_enable_bits = 0 ;

 switch ( layer->m_map_type ) {
     case SCEGMO_DIFFUSE : {

  layer->m_diffuse = COLOR_DIFFUSE ;
  break ;
     }
     case SCEGMO_SPECULAR : {

  layer->m_blend_func[ 2 ] = 10 ;
  layer->m_specular = COLOR_SPECULAR ;
  break ;
     }
     case SCEGMO_EMISSION : {
  layer->m_blend_func[ 1 ] = 10 ;
  layer->m_blend_func[ 2 ] = 10 ;
  layer->m_ambient = COLOR_EMISSION ;
  layer->m_enable_mask |= SCEGMO_ENABLE_LIGHTING ;

  break ;
     }
     case SCEGMO_AMBIENT : {

  layer->m_blend_func[ 2 ] = 10 ;
  layer->m_ambient = COLOR_AMBIENT ;
  break ;
     }
     case SCEGMO_REFLECTION : {
  layer->m_ambient = COLOR_REFLECTION ;
  layer->m_enable_mask |= SCEGMO_ENABLE_LIGHTING ;

  layer->m_enable_mask |= SCEGMO_ENABLE_SHADE_MAP ;
  layer->m_enable_bits |= SCEGMO_ENABLE_SHADE_MAP ;
  break ;
     }
 }
 return 1 ;
}

vec4 *vec4_col32( vec4 *dst, unsigned int src )
{
 dst->x = ( 255 & src ) * ( 1.0f / 255.0f ) ;
 dst->y = ( 255 & ( src >> 8 ) ) * ( 1.0f / 255.0f ) ;
 dst->z = ( 255 & ( src >> 16 ) ) * ( 1.0f / 255.0f ) ;
 dst->w = ( 255 & ( src >> 24 ) ) * ( 1.0f / 255.0f ) ;
 return dst ;
}

unsigned int col32_vec4( const vec4 *src )
{
 unsigned int r = (unsigned int)( src->x * 255.0f ) ;
 unsigned int g = (unsigned int)( src->y * 255.0f ) ;
 unsigned int b = (unsigned int)( src->z * 255.0f ) ;
 unsigned int a = (unsigned int)( src->w * 255.0f ) ;
 return ( a << 24 ) | ( b << 16 ) | ( g << 8 ) | r ;
}

unsigned int col32_lerp( unsigned int src1, unsigned int src2, float rate )
{
 if ( rate >= 1.0f ) return src2 ;
 if ( rate <= 0.0f ) return src1 ;
 unsigned int col = 0 ;
 { int i ; for ( i = 0 ; i < 32 ; i += 8 ) {
  float a = ( 255 & src1 ) ;
  float b = ( 255 & src2 ) ;
  float c = ( b - a ) * rate + a ;
  col |= (unsigned int)c << i ;
  src1 >>= 8 ;
  src2 >>= 8 ;
 } }
 return col ;
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

void sceGmoMaterialUpdate( SceGmoMaterial *material, SceGmoModel *model )
{
 if ( material == 0 ) return ;
 complement_animation( material ) ;
}

int sceGmoMaterialActivate( SceGmoMaterial *material, SceGmoModel *model, int index )
{
 if ( material == 0 ) return 0 ;
 if ( index >= material->m_n_layers ) return 0 ;

 SceGmoSubject *parent = sceGmoBaseGetParent( &( material->m_base ) ) ;
 if ( parent != 0 ) model = (SceGmoModel *)parent ;

 return sceGmoLayerActivate( material->m_layers[ index ], model, material ) ;
}

void sceGmoMaterialSetParent( SceGmoMaterial *material, SceGmoModel *parent )
{
 if ( material == 0 ) return ;
 sceGmoBaseSetParent( &( material->m_base ), (SceGmoSubject *)parent ) ;
}

SceGmoModel *sceGmoMaterialGetParent( SceGmoMaterial *material )
{
 if ( material == 0 ) return 0 ;
 return (SceGmoModel *)sceGmoBaseGetParent( &( material->m_base ) ) ;
}

int sceGmoMaterialGetLayerCount( SceGmoMaterial *material )
{
 if ( material == 0 ) return 0 ;
 return material->m_n_layers ;
}

SceGmoLayer *sceGmoMaterialGetLayer( SceGmoMaterial *material, int index )
{
 if ( material == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= material->m_n_layers ) return 0 ;
 return material->m_layers[ index ] ;
}

void complement_animation( SceGmoMaterial *material )
{
 int flags = material->m_anim_flags ;
 int reset = ANIM_COMPLETE ;
 int modified = ( flags & ANIM_MODIFIED ) ;
 int complete = ( flags & ANIM_COMPLETE ) >> 16 ;
 int incomplete = modified & ~complete ;
 if ( incomplete ) {
  float val[ 5 ] ;
  SceGmoMaterial *initial = material->m_initial ;
  if ( incomplete & HAS_DIFFUSE ) {
   float w = 1.0f - material->m_anim_weights[ 0 ] ;
   vec4_col32( (vec4 *)val, initial->m_colors[ COLOR_DIFFUSE ] ) ;
   sceGmoMaterialAnimate( material, SCEGMO_DIFFUSE, 0, val, 4, w ) ;
   if ( w > 0.99f ) reset |= HAS_DIFFUSE ;
  }
  if ( incomplete & HAS_SPECULAR ) {
   float w = 1.0f - material->m_anim_weights[ 1 ] ;
   vec4_col32( (vec4 *)val, initial->m_colors[ COLOR_SPECULAR ] ) ;
   val[ 4 ] = initial->m_shininess ;
   sceGmoMaterialAnimate( material, SCEGMO_SPECULAR, 0, val, 5, w ) ;
   if ( w > 0.99f ) reset |= HAS_SPECULAR ;
  }
  if ( incomplete & HAS_EMISSION ) {
   float w = 1.0f - material->m_anim_weights[ 2 ] ;
   vec4_col32( (vec4 *)val, initial->m_colors[ COLOR_EMISSION ] ) ;
   sceGmoMaterialAnimate( material, SCEGMO_EMISSION, 0, val, 4, w ) ;
   if ( w > 0.99f ) reset |= HAS_EMISSION ;
  }
  if ( incomplete & HAS_AMBIENT ) {
   float w = 1.0f - material->m_anim_weights[ 3 ] ;
   vec4_col32( (vec4 *)val, initial->m_colors[ COLOR_AMBIENT ] ) ;
   sceGmoMaterialAnimate( material, SCEGMO_AMBIENT, 0, val, 4, w ) ;
   if ( w > 0.99f ) reset |= HAS_AMBIENT ;
  }
  if ( incomplete & HAS_REFLECTION ) {
   float w = 1.0f - material->m_anim_weights[ 4 ] ;
   vec4_col32( (vec4 *)val, initial->m_colors[ COLOR_REFLECTION ] ) ;
   sceGmoMaterialAnimate( material, SCEGMO_REFLECTION, 0, val + 3, 1, w ) ;
   if ( w > 0.99f ) reset |= HAS_REFLECTION ;
  }
  if ( incomplete & HAS_REFRACTION ) {
   material->m_refraction = initial->m_refraction ;
   reset |= HAS_REFRACTION ;
  }
  if ( incomplete & HAS_BUMP ) {
   material->m_bump = initial->m_bump ;
   reset |= HAS_BUMP ;
  }
  if ( incomplete & HAS_TEX_CROPS ) {
   { int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
    if ( incomplete & ( HAS_TEX_CROP << i ) ) {
     SceGmoLayer *layer1 = material->m_layers[ i ] ;
     SceGmoLayer *layer2 = layer1->m_initial ;
     const rect *crop = sceGmoLayerGetTexCrop( layer2 ) ;
     sceGmoLayerSetTexCrop( layer1, crop ) ;
     reset |= HAS_TEX_CROP << i ;
    }
   } }
  }
 }
 material->m_anim_flags &= ~reset ;
 if ( modified ) {
  memset( material->m_anim_weights, 0, sizeof( material->m_anim_weights ) ) ;
 }
}
