/* cflags: -O2 -frename-registers -fmerge-constants */
/* SDK gmo_model library: devkit 0.6.0's src/gmo_model/gmo_model.c, preprocessed (macros expanded) */
#include "gmo_private.h"
#include "include_asm.h"

static const char __psp_libinfo__[24] __attribute__((used)) = "Lib-PSP libgmo_model....";
#define g_identity g_identity_147790

static void change_motion( SceGmoModel *model, float step ) ;

extern mat4 g_identity;

SceGmoModel *sceGmoModelCreate( SceGmoChunk *chunk )
{
 SceGmoModel *model = (SceGmoModel *)sceGmoModelAllocMemory( sizeof( SceGmoModel ) ) ;
 if ( model == 0 ) {
  ;
  return 0 ;
 }
 sceGmoBaseConstruct( &( model->m_base ) ) ;
 model->m_reference = 1 ;
 model->m_flags = 0 ;

 model->m_bones = 0 ;
 model->m_parts = 0 ;
 model->m_materials = 0 ;
 model->m_textures = 0 ;
 model->m_motions = 0 ;
 model->m_n_bones = 0 ;
 model->m_n_parts = 0 ;
 model->m_n_materials = 0 ;
 model->m_n_textures = 0 ;
 model->m_n_motions = 0 ;

 model->m_current_motion = -1 ;
 model->m_change_motion = -1.0f ;
 model->m_world_matrix = g_identity ;
 model->m_enable_bits = SCEGMO_ENABLE_ALL ;
 model->m_enable_mask = 0 ;
 model->m_bounding_box[ 0 ] = (vec3){ 0, 0, 0 } ;
 model->m_bounding_box[ 1 ] = (vec3){ 0, 0, 0 } ;
 model->m_vertex_offset = g_identity ;
 model->m_texcoord_offset = (rect){ 0, 0, 1, 1 } ;

 if ( chunk != 0 && !sceGmoModelLoad( model, chunk ) ) {
  sceGmoModelDelete( model ) ;
  return 0 ;
 }
 return model ;
}

void sceGmoModelDelete( SceGmoModel *model )
{
 if ( model == 0 ) return ;
 if ( -- model->m_reference == 0 ) {
  sceGmoModelUnload( model ) ;
  sceGmoBaseDestruct( &( model->m_base ) ) ;
  sceGmoModelFreeMemory( model ) ;
 }
}

SceGmoModel *sceGmoModelDuplicate( SceGmoModel *model, int flags )
{
 if ( model == 0 ) return 0 ;

 if ( flags & SCEGMO_DUPLICATE_AUTOMATIC ) {
  flags &= ~SCEGMO_DUPLICATE_AUTOMATIC ;
  if ( model->m_n_motions > 0 ) flags |= SCEGMO_DUPLICATE_STRUCTURE ;
  { int i ; for ( i = 0 ; i < model->m_n_textures ; i ++ ) {
   SceGmoTexture *texture = model->m_textures[ i ] ;
   if ( texture != 0 && sceGmoTextureHasAnimation( texture ) ) {
    flags |= SCEGMO_DUPLICATE_STRUCTURE ;
   }
  } }
 }
 if ( flags == SCEGMO_DUPLICATE_REFERENCE ) {
  model->m_reference ++ ;
  return model ;
 }

 SceGmoModel *model2 = sceGmoModelCreate( 0 ) ;
 if ( model2 == 0 ) return 0 ;
 sceGmoBaseCopy( &( model2->m_base ), &( model->m_base ) ) ;
 if ( !sceGmoModelAllocPtr( &( model2->m_bones ), model->m_n_bones * sizeof( void * ) )
   || !sceGmoModelAllocPtr( &( model2->m_parts ), model->m_n_parts * sizeof( void * ) )
   || !sceGmoModelAllocPtr( &( model2->m_materials ), model->m_n_materials * sizeof( void * ) )
   || !sceGmoModelAllocPtr( &( model2->m_textures ), model->m_n_textures * sizeof( void * ) )
   || !sceGmoModelAllocPtr( &( model2->m_motions ), model->m_n_motions * sizeof( void * ) ) ) {
  ;
  sceGmoModelDelete( model2 ) ;
  return 0 ;
 }
 flags &= ~SCEGMO_DUPLICATE_STRUCTURE ;
 flags |= SCEGMO_DUPLICATE_AUTOMATIC ;
 _Bool error = 0 ;
 { int i ; for ( i = 0 ; i < model->m_n_bones ; i ++ ) {
  SceGmoBone *src = model->m_bones[ i ] ;
  SceGmoBone *dst = sceGmoBoneDuplicate( src, flags ) ;
  if ( dst == 0 && src != 0 ) error = 1 ;
  model2->m_bones[ model2->m_n_bones ++ ] = dst ;
 } }
 { int i ; for ( i = 0 ; i < model->m_n_parts ; i ++ ) {
  SceGmoPart *src = model->m_parts[ i ] ;
  SceGmoPart *dst = sceGmoPartDuplicate( src, flags ) ;
  if ( dst == 0 && src != 0 ) error = 1 ;
  model2->m_parts[ model2->m_n_parts ++ ] = dst ;
 } }
 { int i ; for ( i = 0 ; i < model->m_n_materials ; i ++ ) {
  SceGmoMaterial *src = model->m_materials[ i ] ;
  SceGmoMaterial *dst = sceGmoMaterialDuplicate( src, flags ) ;
  if ( dst == 0 && src != 0 ) error = 1 ;
  model2->m_materials[ model2->m_n_materials ++ ] = dst ;
 } }
 { int i ; for ( i = 0 ; i < model->m_n_textures ; i ++ ) {
  SceGmoTexture *src = model->m_textures[ i ] ;
  SceGmoTexture *dst = sceGmoTextureDuplicate( src, flags ) ;
  if ( dst == 0 && src != 0 ) error = 1 ;
  model2->m_textures[ model2->m_n_textures ++ ] = dst ;
 } }
 { int i ; for ( i = 0 ; i < model->m_n_motions ; i ++ ) {
  SceGmoMotion *src = model->m_motions[ i ] ;
  SceGmoMotion *dst = sceGmoMotionDuplicate( src, flags ) ;
  if ( dst == 0 && src != 0 ) error = 1 ;
  model2->m_motions[ model2->m_n_motions ++ ] = dst ;
 } }
 if ( error ) {
  sceGmoModelDelete( model2 ) ;
  return 0 ;
 }
 model2->m_flags = model->m_flags ;
 model2->m_current_motion = model->m_current_motion ;
 model2->m_change_motion = model->m_change_motion ;
 model2->m_world_matrix = model->m_world_matrix ;
 model2->m_enable_bits = model->m_enable_bits ;
 model2->m_enable_mask = model->m_enable_mask ;
 model2->m_bounding_box[ 0 ] = model->m_bounding_box[ 0 ] ;
 model2->m_bounding_box[ 1 ] = model->m_bounding_box[ 1 ] ;
 model2->m_vertex_offset = model->m_vertex_offset ;
 model2->m_texcoord_offset = model->m_texcoord_offset ;
 return model2 ;
}

_Bool sceGmoModelLoadFile( SceGmoModel *model, const void *buf, int size, int index )
{
 if ( model == 0 ) return 0 ;
 if ( buf == 0 ) return 0 ;

 if ( !sceGmoModelCheckFileHeader( buf, size ) ) return 0 ;

 SceGmoChunk *chunk = sceGmoModelGetChunk( buf, size, index ) ;
 if ( chunk == 0 ) {
  ;
  return 0 ;
 }
 ;
 return sceGmoModelLoad( model, chunk ) ;
}

_Bool sceGmoModelLoad( SceGmoModel *model, SceGmoChunk *chunk )
{
 if ( model == 0 ) return 0 ;
 if ( chunk == 0 ) return 0 ;

 sceGmoModelUnload( model ) ;

 int n_bones = sceGmoModelCountChunk( chunk, SCEGMO_BONE ) ;
 int n_parts = sceGmoModelCountChunk( chunk, SCEGMO_PART ) ;
 int n_materials = sceGmoModelCountChunk( chunk, SCEGMO_MATERIAL ) ;
 int n_textures = sceGmoModelCountChunk( chunk, SCEGMO_TEXTURE ) ;
 int n_motions = sceGmoModelCountChunk( chunk, SCEGMO_MOTION ) ;
 if ( !sceGmoModelAllocPtr( &( model->m_bones ), n_bones * sizeof( void * ) )
   || !sceGmoModelAllocPtr( &( model->m_parts ), n_parts * sizeof( void * ) )
   || !sceGmoModelAllocPtr( &( model->m_materials ), n_materials * sizeof( void * ) )
   || !sceGmoModelAllocPtr( &( model->m_textures ), n_textures * sizeof( void * ) )
   || !sceGmoModelAllocPtr( &( model->m_motions ), n_motions * sizeof( void * ) ) ) {
  ;
  return 0 ;
 }

 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  switch ( SCEGMO_CHUNK_TYPE( chunk ) ) {
      case SCEGMO_BONE : {
   SceGmoBone *bone = sceGmoBoneCreate( chunk ) ;
   if ( bone == 0 ) return 0 ;
   model->m_bones[ model->m_n_bones ++ ] = bone ;
   break ;
      }
      case SCEGMO_PART : {
   SceGmoPart *part = sceGmoPartCreate( chunk ) ;
   if ( part == 0 ) return 0 ;
   model->m_parts[ model->m_n_parts ++ ] = part ;
   break ;
      }
      case SCEGMO_MATERIAL : {
   SceGmoMaterial *material = sceGmoMaterialCreate( chunk ) ;
   if ( material == 0 ) return 0 ;
   model->m_materials[ model->m_n_materials ++ ] = material ;
   break ;
      }
      case SCEGMO_TEXTURE : {
   SceGmoTexture *texture = sceGmoTextureCreate( chunk ) ;
   if ( texture == 0 ) return 0 ;
   model->m_textures[ model->m_n_textures ++ ] = texture ;
   break ;
      }
      case SCEGMO_MOTION : {
   SceGmoMotion *motion = sceGmoMotionCreate( chunk ) ;
   if ( motion == 0 ) return 0 ;
   model->m_motions[ model->m_n_motions ++ ] = motion ;
   break ;
      }
      case SCEGMO_BOUNDING_BOX : {
   SceGmoBoundingBox *cmd = (SceGmoBoundingBox *)SCEGMO_CHUNK_ARGS( chunk ) ;
   model->m_flags |= SCEGMO_MODEL_HAS_BOUNDING_BOX ;
   model->m_bounding_box[ 0 ] = cmd->lower ;
   model->m_bounding_box[ 1 ] = cmd->upper ;
   break ;
      }
      case SCEGMO_VERTEX_OFFSET : {
   SceGmoVertexOffset *cmd = (SceGmoVertexOffset *)SCEGMO_CHUNK_ARGS( chunk ) ;
   switch ( cmd->format ) {
       case ( 3 << 7 ) :
    model->m_flags |= SCEGMO_MODEL_HAS_VERTEX_OFFSET ;
    model->m_vertex_offset = g_identity ;
    model->m_vertex_offset.w.x = cmd->offset[ 0 ] ;
    model->m_vertex_offset.w.y = cmd->offset[ 1 ] ;
    model->m_vertex_offset.w.z = cmd->offset[ 2 ] ;
    model->m_vertex_offset.x.x = cmd->offset[ 3 ] ;
    model->m_vertex_offset.y.y = cmd->offset[ 4 ] ;
    model->m_vertex_offset.z.z = cmd->offset[ 5 ] ;
    break ;
       case ( 3 << 0 ) :
    model->m_flags |= SCEGMO_MODEL_HAS_TEXCOORD_OFFSET ;
    model->m_texcoord_offset = *(rect *)( cmd->offset ) ;
    break ;
   }
   break ;
      }
  }
 }
 sceKernelDcacheWritebackAll();
 return 1 ;
}

void sceGmoModelUnload( SceGmoModel *model )
{
 if ( model == 0 ) return ;

 { int i ; for ( i = 0 ; i < model->m_n_bones ; i ++ ) {
  sceGmoBoneDelete( model->m_bones[ i ] ) ;
 } }
  { int i ; for ( i = 0 ; i < model->m_n_parts ; i ++ ) {
  sceGmoPartDelete( model->m_parts[ i ] ) ;
 } }
 { int i ; for ( i = 0 ; i < model->m_n_materials ; i ++ ) {
  sceGmoMaterialDelete( model->m_materials[ i ] ) ;
 } }
 { int i ; for ( i = 0 ; i < model->m_n_textures ; i ++ ) {
  sceGmoTextureDelete( model->m_textures[ i ] ) ;
 } }
 { int i ; for ( i = 0 ; i < model->m_n_motions ; i ++ ) {
  sceGmoMotionDelete( model->m_motions[ i ] ) ;
 } }
 sceGmoModelFreeMemory( model->m_bones ) ;
 sceGmoModelFreeMemory( model->m_parts ) ;
 sceGmoModelFreeMemory( model->m_materials ) ;
 sceGmoModelFreeMemory( model->m_textures ) ;
 sceGmoModelFreeMemory( model->m_motions ) ;
 model->m_bones = 0 ;
 model->m_parts = 0 ;
 model->m_materials = 0 ;
 model->m_textures = 0 ;
 model->m_motions = 0 ;
 model->m_n_bones = 0 ;
 model->m_n_parts = 0 ;
 model->m_n_materials = 0 ;
 model->m_n_textures = 0 ;
 model->m_n_motions = 0 ;

 model->m_flags = 0 ;
}

void sceGmoModelAnimate( SceGmoModel *model, float step )
{
 if ( model == 0 ) return ;

 change_motion( model, step ) ;

 { int i ; for ( i = 0 ; i < model->m_n_motions ; i ++ ) {
  sceGmoMotionUpdate( model->m_motions[ i ], model, step ) ;
 } }
 { int i ; for ( i = 0 ; i < model->m_n_textures ; i ++ ) {
  sceGmoTextureUpdate( model->m_textures[ i ], model, step ) ;
 } }
}

void sceGmoModelUpdate( SceGmoModel *model )
{
 if ( model == 0 ) return ;

 { int i ; for ( i = 0 ; i < model->m_n_bones ; i ++ ) {
  sceGmoBoneUpdate( model->m_bones[ i ], model ) ;
 } }
 { int i ; for ( i = 0 ; i < model->m_n_materials ; i ++ ) {
  sceGmoMaterialUpdate( model->m_materials[ i ], model ) ;
 } }
}

void sceGmoModelDraw( SceGmoModel *model )
{
 if ( model == 0 ) return ;

 sceGumUpdateMatrix() ;

 sceGmoContextBegin() ;
 sceGmoContextDefaultEnableBits( model->m_enable_mask, model->m_enable_bits ) ;
 if ( model->m_flags & SCEGMO_MODEL_HAS_TEXCOORD_OFFSET ) {
  sceGmoContextDefaultTexOffs( &( model->m_texcoord_offset ) ) ;
 }
 { int i ; for ( i = 0 ; i < model->m_n_bones ; i ++ ) {
  sceGmoBoneDraw( model->m_bones[ i ], model ) ;
 } }
 sceGmoContextEnd() ;

 sceGumMatrixMode( 2 ) ;
 sceGumSetCurMatrix() ;
}

SceGmoBone *sceGmoModelSetBone( SceGmoModel *model, int index, SceGmoBone *bone, int flags )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_bones ) return 0 ;
 SceGmoBone *bone1 = model->m_bones[ index ] ;
 SceGmoBone *bone2 = sceGmoBoneDuplicate( bone, flags ) ;
 if ( bone2 == 0 ) return 0 ;
 sceGmoBoneDelete( bone1 ) ;
 model->m_bones[ index ] = bone2 ;
 return bone2 ;
}

SceGmoPart *sceGmoModelSetPart( SceGmoModel *model, int index, SceGmoPart *part, int flags )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_parts ) return 0 ;
 SceGmoPart *part1 = model->m_parts[ index ] ;
 SceGmoPart *part2 = sceGmoPartDuplicate( part, flags ) ;
 if ( part2 == 0 ) return 0 ;
 sceGmoPartDelete( part1 ) ;
 model->m_parts[ index ] = part2 ;
 return part2 ;
}

SceGmoMaterial *sceGmoModelSetMaterial( SceGmoModel *model, int index, SceGmoMaterial *material, int flags )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_materials ) return 0 ;
 SceGmoMaterial *material1 = model->m_materials[ index ] ;
 SceGmoMaterial *material2 = sceGmoMaterialDuplicate( material, flags ) ;
 if ( material2 == 0 ) return 0 ;
 sceGmoMaterialDelete( material1 ) ;
 model->m_materials[ index ] = material2 ;
 return material2 ;
}

SceGmoTexture *sceGmoModelSetTexture( SceGmoModel *model, int index, SceGmoTexture *texture, int flags )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_textures ) return 0 ;
 SceGmoTexture *texture1 = model->m_textures[ index ] ;
 SceGmoTexture *texture2 = sceGmoTextureDuplicate( texture, flags ) ;
 if ( texture2 == 0 ) return 0 ;
 sceGmoTextureDelete( texture1 ) ;
 model->m_textures[ index ] = texture2 ;
 return texture2 ;
}

SceGmoMotion *sceGmoModelSetMotion( SceGmoModel *model, int index, SceGmoMotion *motion, int flags )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_motions ) return 0 ;
 SceGmoMotion *motion1 = model->m_motions[ index ] ;
 SceGmoMotion *motion2 = sceGmoMotionDuplicate( motion, flags ) ;
 if ( motion2 == 0 ) return 0 ;
 sceGmoMotionDelete( motion1 ) ;
 model->m_motions[ index ] = motion2 ;
 return motion2 ;
}

void change_motion( SceGmoModel *model, float step )
{
 float change = model->m_change_motion ;
 if ( change < 0.0f ) return ;
 if ( step < 0.0f ) step = -step ;
 float left = change - step ;
 if ( left > 0.0f ) {
  float decay = left / change ;
  { int i ; for ( i = 0 ; i < model->m_n_motions ; i ++ ) {
   SceGmoMotion *motion = model->m_motions[ i ] ;
   if ( motion == 0 ) continue ;
   float w = sceGmoMotionGetWeight( motion ) ;
   if ( i == model->m_current_motion ) {
    w += ( 1.0f - w ) * step / change ;
   } else {
    w *= decay ;
   }
   sceGmoMotionSetWeight( motion, w ) ;
  } }
  model->m_change_motion = left ;
 } else {
  { int i ; for ( i = 0 ; i < model->m_n_motions ; i ++ ) {
   SceGmoMotion *motion = model->m_motions[ i ] ;
   if ( motion == 0 ) continue ;
   float w = ( i == model->m_current_motion ) ? 1.0f : 0.0f ;
   sceGmoMotionSetWeight( motion, w ) ;
  } }
  model->m_change_motion = -1.0f ;
 }
}

void sceGmoModelSetWorldMatrix( SceGmoModel *model, const mat4 *m )
{
 if ( model == 0 ) return ;
 if ( m == 0 ) m = &g_identity ;
 model->m_world_matrix = *m ;
}

const mat4 *sceGmoModelGetWorldMatrix( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 return &( model->m_world_matrix ) ;
}

/* the release inlines sceGmoModelGetMotion here, so its body was visible before this point */
static inline SceGmoMotion *model_get_motion_inline( SceGmoModel *model, int index )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_motions ) return 0 ;
 return model->m_motions[ index ] ;
}
void sceGmoModelSetCurrentMotion( SceGmoModel *model, int index, float delay )
{
 if ( model == 0 ) return ;
 model->m_current_motion = index ;
 model->m_change_motion = delay ;
 sceGmoMotionSetFrame( model_get_motion_inline( model, index ), 0.0f ) ;
}

int sceGmoModelGetCurrentMotion( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 return model->m_current_motion ;
}

void sceGmoModelSetEnableBits( SceGmoModel *model, int bits, int value )
{
 if ( model == 0 ) return ;
 model->m_enable_bits &= ~bits ;
 model->m_enable_bits |= ( bits & value ) ;
}

int sceGmoModelGetEnableBits( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 return model->m_enable_bits ;
}

void sceGmoModelSetEnableMask( SceGmoModel *model, int mask, int value )
{
 if ( model == 0 ) return ;
 model->m_enable_mask &= ~mask ;
 model->m_enable_mask |= ( mask & value ) ;
}

int sceGmoModelGetEnableMask( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 return model->m_enable_mask ;
}

const vec3 *sceGmoModelGetBoundingBox( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 if ( !( model->m_flags & SCEGMO_MODEL_HAS_BOUNDING_BOX ) ) return 0 ;
 return model->m_bounding_box ;
}

const mat4 *sceGmoModelGetVertexOffset( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 if ( !( model->m_flags & SCEGMO_MODEL_HAS_VERTEX_OFFSET ) ) return 0 ;
 return &( model->m_vertex_offset ) ;
}

const rect *sceGmoModelGetTexcoordOffset( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 if ( !( model->m_flags & SCEGMO_MODEL_HAS_TEXCOORD_OFFSET ) ) return 0 ;
 return &( model->m_texcoord_offset ) ;
}

int sceGmoModelGetBoneCount( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 return model->m_n_bones ;
}

int sceGmoModelGetPartCount( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 return model->m_n_parts ;
}

int sceGmoModelGetMaterialCount( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 return model->m_n_materials ;
}

int sceGmoModelGetTextureCount( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 return model->m_n_textures ;
}

int sceGmoModelGetMotionCount( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 return model->m_n_motions ;
}

SceGmoBone *sceGmoModelGetBone( SceGmoModel *model, int index )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_bones ) return 0 ;
 return model->m_bones[ index ] ;
}

SceGmoPart *sceGmoModelGetPart( SceGmoModel *model, int index )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_parts ) return 0 ;
 return model->m_parts[ index ] ;
}

SceGmoMaterial *sceGmoModelGetMaterial( SceGmoModel *model, int index )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_materials ) return 0 ;
 return model->m_materials[ index ] ;
}

SceGmoTexture *sceGmoModelGetTexture( SceGmoModel *model, int index )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_textures ) return 0 ;
 return model->m_textures[ index ] ;
}

SceGmoMotion *sceGmoModelGetMotion( SceGmoModel *model, int index )
{
 if ( model == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= model->m_n_motions ) return 0 ;
 return model->m_motions[ index ] ;
}
