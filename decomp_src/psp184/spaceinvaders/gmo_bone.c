#include "common.h"
#define complement_animation complement_animation_5AB88
#include "gmo_bone_sdk.h"

SceGmoBone *sceGmoBoneCreate( const SceGmoChunk *chunk )
{
	SceGmoBone *bone = (SceGmoBone *)sceGmoModelAllocMemory( sizeof( SceGmoBone ) ) ;
	if ( bone == 0 ) {
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

	bone->m_anim_flags = 0 ;
	memset( bone->m_anim_weights, 0, sizeof( bone->m_anim_weights ) ) ;

	sceGmoVec3Set( &( bone->m_pivot ), 0, 0, 0 ) ;
	sceGmoVec3Set( &( bone->m_translate ), 0, 0, 0 ) ;
	sceGmoQuatSet( &( bone->m_rotate ), 0, 0, 0, 1 ) ;
	sceGmoVec3Set( &( bone->m_scale ), 1, 1, 1 ) ;

	sceGmoMat4Set( &( bone->m_local_matrix ), 0, 0, 0, 1, 1, 1 ) ;
	sceGmoMat4Set( &( bone->m_stack_matrix ), 0, 0, 0, 1, 1, 1 ) ;
	sceGmoVec3Set( &( bone->m_stack_scale ), 1, 1, 1 ) ;
	sceGmoMat4Set( &( bone->m_world_matrix ), 0, 0, 0, 1, 1, 1 ) ;

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneDuplicate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneLoad);

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

void sceGmoBoneUpdate( SceGmoBone *bone, SceGmoModel *model )
{
	if ( bone == 0 ) return ;
	complement_animation( bone ) ;
	calc_bone_matrix( bone, model ) ;
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
			const SceGmoMat4 *world = sceGmoBoneGetWorldMatrix( bone2 ) ;
			SceGmoMat4 *offset = initial->m_blend_offsets + i ;
			SceGmoMat4 *offset2 = bone->m_blend_offsets + i ;
			sceGmoMat4Multiply( offset2, world, offset ) ;
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

	const SceGmoMat4 *voffs = sceGmoModelGetVertexOffset( model ) ;
	SceGmoMat4 tmp ;

	int n_bones = bone->m_n_blend_bones ;
	if ( n_bones == 0 ) {
		const SceGmoMat4 *m = sceGmoBoneGetWorldMatrix( bone ) ;
		if ( voffs != 0 ) m = sceGmoMat4Multiply( &tmp, m, voffs ) ;
		sceGuSetMatrix( 2, m ) ;
		return ;
	}

	sceGuSetMatrix( 2, &sceGmoMat4_One ) ;
	if ( n_indices == 0 ) {
		if ( n_bones > 8 ) n_bones = 8 ;
		{ int i ; for ( i = 0 ; i < n_bones ; i ++ ) {
			const SceGmoMat4 *m = bone->m_blend_offsets + i ;
			if ( voffs != 0 ) m = sceGmoMat4Multiply( &tmp, m, voffs ) ;
			sceGuBoneMatrix( i, m ) ;
		} }
	} else {
		if ( n_indices > 8 ) n_indices = 8 ;
		{ int i ; for ( i = 0 ; i < n_indices ; i ++ ) {
			const SceGmoMat4 *m = bone->m_blend_offsets + indices[ i ] ;
			if ( voffs != 0 ) m = sceGmoMat4Multiply( &tmp, m, voffs ) ;
			sceGuBoneMatrix( i, m ) ;
		} }
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneControl);

void sceGmoBoneSetParent( SceGmoBone *bone, SceGmoModel *parent )
{
 if ( bone == 0 ) return ;
 sceGmoBaseSetParent( &( bone->m_base ), (SceGmoSubject *)parent ) ;
}

SceGmoModel *sceGmoBoneGetParent( SceGmoBone *bone )
{
 if ( bone == 0 ) return 0 ;
 return _sceGmoBoneGetParent( bone ) ;
}

const SceGmoMat4 *sceGmoBoneGetWorldMatrix( SceGmoBone *bone )
{
	if ( bone == 0 ) return 0 ;
	if ( !( bone->m_flags & SCEGMO_BONE_IS_SCALE_STACKED ) ) {
		return &( bone->m_stack_matrix ) ;
	} else {
		SceGmoMat4 *m = &( bone->m_world_matrix ) ;
		if ( bone->m_flags & SCEGMO_BONE_IS_BLEND_DIRTY ) {
			bone->m_flags &= ~SCEGMO_BONE_IS_BLEND_DIRTY ;
			sceGmoMat4Scale( m, &( bone->m_stack_matrix ), &( bone->m_stack_scale ) ) ;
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

_Bool set_blend_offsets( SceGmoBone *bone, const SceGmoMat4 *offsets, int n_offsets )
{
 if ( bone->m_n_blend_offsets != n_offsets ) {
  int size = sizeof( SceGmoMat4 ) * n_offsets ;
  if ( !sceGmoModelAllocPtr( &( bone->m_blend_offsets ), size ) ) {
   bone->m_n_blend_offsets = 0 ;
   return 0 ;
  }
  bone->m_n_blend_offsets = n_offsets ;
 }
 if ( offsets != 0 ) {
  memcpy( bone->m_blend_offsets, offsets, sizeof( SceGmoMat4 ) * n_offsets ) ;
 }
 return 1 ;
}

_Bool set_morph_weights( SceGmoBone *bone, const float *weights, int n_weights )
{
 if ( n_weights > MAX_MORPHS ) n_weights = MAX_MORPHS ;
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

static void calc_morph_index( float *weights, int n_weights, float index )
{
	memset( weights, 0, sizeof( float ) * n_weights ) ;
	int index2 = (int)floorf( index ) ;
	if ( index2 < 0 ) index2 = 0 ;
	if ( index2 > n_weights - 2 ) index2 = n_weights - 2 ;
	index -= (float)index2 ;
	weights[ index2 + 0 ] = 1.0f - index ;
	weights[ index2 + 1 ] = index ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", complement_animation_5AB88);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", calc_bone_matrix);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", D_0007ECBC);
