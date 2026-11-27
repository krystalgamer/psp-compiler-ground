#include "common.h"
#include "gmo_model_sdk.h"

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_model", D_0007EC44);
SceGmoModel *sceGmoModelCreate( SceGmoChunk *chunk )
{
	SceGmoModel *model = (SceGmoModel *)sceGmoModelAllocMemory( sizeof( SceGmoModel ) ) ;
	if ( model == 0 ) {
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
	model->m_enable_bits = SCEGMO_ENABLE_ALL ;
	model->m_enable_mask = 0 ;

	sceGmoMat4Set( &( model->m_world_matrix ), 0, 0, 0, 1, 1, 1 ) ;
	sceGmoVec3Set( &( model->m_bounding_box[ 0 ] ), 0, 0, 0 ) ;
	sceGmoVec3Set( &( model->m_bounding_box[ 1 ] ), 0, 0, 0 ) ;
	sceGmoMat4Set( &( model->m_vertex_offset ), 0, 0, 0, 1, 1, 1 ) ;
	sceGmoRectSet( &( model->m_texcoord_offset ), 0, 0, 1, 1 ) ;

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_model", sceGmoModelDuplicate);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_model", sceGmoModelLoad);

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

_Bool sceGmoModelLoadCache( SceGmoModel *model )
{
	if ( model == 0 ) return 0 ;
	{ int i ; for ( i = 0 ; i < model->m_n_parts ; i ++ ) {
		if ( !sceGmoPartLoadCache( model->m_parts[ i ] ) ) return 0 ;
	} }
	{ int i ; for ( i = 0 ; i < model->m_n_materials ; i ++ ) {
		if ( !sceGmoMaterialLoadCache( model->m_materials[ i ] ) ) return 0 ;
	} }
	return 1 ;
}

void sceGmoModelUnloadCache( SceGmoModel *model )
{
	if ( model == 0 ) return ;
	{ int i ; for ( i = 0 ; i < model->m_n_parts ; i ++ ) {
		sceGmoPartUnloadCache( model->m_parts[ i ] ) ;
	} }
	{ int i ; for ( i = 0 ; i < model->m_n_materials ; i ++ ) {
		sceGmoMaterialUnloadCache( model->m_materials[ i ] ) ;
	} }
}

void sceGmoModelAnimate( SceGmoModel *model, float step )
{
	if ( model == 0 ) return ;

	change_motion( model, step ) ;

	{ int i ; for ( i = 0 ; i < model->m_n_motions ; i ++ ) {
		sceGmoMotionAnimate( model->m_motions[ i ], model, step ) ;
	} }
	{ int i ; for ( i = 0 ; i < model->m_n_textures ; i ++ ) {
		sceGmoTextureAnimate( model->m_textures[ i ], model, step ) ;
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
	sceGmoContextSetTexOffs( 0 ) ;
	{ int i ; for ( i = 0 ; i < model->m_n_bones ; i ++ ) {
		sceGmoBoneDraw( model->m_bones[ i ], model ) ;
	} }
	sceGmoContextEnd() ;

	sceGumMatrixMode( 2 ) ;
	sceGumSetCurMatrix() ;
}

void sceGmoModelSetWorldMatrix( SceGmoModel *model, const mat4 *m )
{
	if ( model == 0 ) return ;
	if ( m == 0 ) {
		sceGmoMat4Set( &( model->m_world_matrix ), 0, 0, 0, 1, 1, 1 ) ;
	} else {
		model->m_world_matrix = *m ;
	}
}

const mat4 *sceGmoModelGetWorldMatrix( SceGmoModel *model )
{
 if ( model == 0 ) return 0 ;
 return &( model->m_world_matrix ) ;
}

void sceGmoModelSetCurrentMotion( SceGmoModel *model, int index, float delay )
{
 if ( model == 0 ) return ;
 model->m_current_motion = index ;
 model->m_change_motion = delay ;
 sceGmoMotionSetFrame( sceGmoModelGetMotion( model, index ), 0.0f ) ;
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

_Bool sceGmoModelHasAnimation( SceGmoModel *model )
{
	if ( model == 0 ) return 0 ;
	if ( model->m_n_motions > 0 ) return 1 ;
	{ int i ; for ( i = 0 ; i < model->m_n_textures ; i ++ ) {
		SceGmoTexture *texture = model->m_textures[ i ] ;
		if ( texture != 0 && sceGmoTextureHasAnimation( texture ) ) return 1 ;
	} }
	return 0 ;
}

const ScePspFVector4 *sceGmoModelGetBoundingBox( SceGmoModel *model )
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

