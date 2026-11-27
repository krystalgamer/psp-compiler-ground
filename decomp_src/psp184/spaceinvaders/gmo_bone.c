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

SceGmoBone *sceGmoBoneDuplicate( SceGmoBone *bone, int flags )
{
	if ( bone == 0 ) return 0 ;
	if ( !( 0x0001 & flags )
	  && !( 0x0010 & flags ) ) {
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
			bone->m_n_blend_offsets * sizeof( SceGmoMat4 ) ) ) {
		sceGmoBoneDelete( bone2 ) ;
		return 0 ;
	}
	bone2->m_initial = sceGmoBoneDuplicate( bone->m_initial, 0 ) ;
	bone2->m_flags = bone->m_flags ;

	bone2->m_n_draw_parts = bone->m_n_draw_parts ;
	bone2->m_n_morph_weights = bone->m_n_morph_weights ;
	bone2->m_n_blend_bones = bone->m_n_blend_bones ;
	bone2->m_n_blend_offsets = bone->m_n_blend_offsets ;

	bone2->m_parent_bone = bone->m_parent_bone ;
	bone2->m_visibility = bone->m_visibility ;

	bone2->m_anim_flags = bone->m_anim_flags ;
	memcpy( bone2->m_anim_weights, bone->m_anim_weights, sizeof( bone->m_anim_weights ) ) ;

	bone2->m_pivot = bone->m_pivot ;
	bone2->m_translate = bone->m_translate ;
	bone2->m_rotate = bone->m_rotate ;
	bone2->m_scale = bone->m_scale ;

	bone2->m_local_matrix = bone->m_local_matrix ;
	bone2->m_stack_matrix = bone->m_stack_matrix ;
	bone2->m_stack_scale = bone->m_stack_scale ;
	bone2->m_world_matrix = bone->m_world_matrix ;
	return bone2 ;
}

_Bool sceGmoBoneLoad( SceGmoBone *bone, const SceGmoChunk *chunk )
{
	if ( bone == 0 ) return 0 ;
	if ( chunk == 0 ) return 0 ;

	sceGmoBoneUnload( bone ) ;

	int n_parts = sceGmoModelCountChunk( chunk, SCEGMO_DRAW_PART ) ;
	if ( !sceGmoModelAllocPtr( &( bone->m_draw_parts ), n_parts * sizeof( void * ) ) ) {
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
			bone->m_flags |= 0x0200 ;
			break ;
		    }
		    case SCEGMO_MORPH_WEIGHTS : {
			SceGmoMorphWeights *cmd = (SceGmoMorphWeights *)args ;
			if ( !set_morph_weights( bone, cmd->weights, cmd->n_weights ) ) {
				return 0 ;
			}
			bone->m_flags |= 0x0100 ;
			break ;
		    }
		    case SCEGMO_MORPH_INDEX : {
			SceGmoMorphIndex *cmd = (SceGmoMorphIndex *)args ;
			if ( !set_morph_weights( bone, 0, 8 ) ) {
				return 0 ;
			}
			calc_morph_index( bone->m_morph_weights, 8, cmd->index ) ;
			bone->m_flags |= 0x0100 ;
			break ;
		    }
		    case SCEGMO_BLEND_BONES : {
			SceGmoBlendBones *cmd = (SceGmoBlendBones *)args ;
			if ( !set_blend_bones( bone, cmd->bones, cmd->n_bones ) ) {
				return 0 ;
			}
			break ;
		    }
		    case SCEGMO_BLEND_OFFSETS : {
			blend_offsets = (SceGmoBlendOffsets *)args ;
			break ;
		    }
		    case SCEGMO_PIVOT : {
			sceGmoVec3Load( &( bone->m_pivot ), (SceGmoVec3F *)args ) ;
			bone->m_flags |= 0x0080 ;
			break ;
		    }
		    case SCEGMO_MULT_MATRIX : {
			sceGmoMat4Load( &( bone->m_local_matrix ), (SceGmoMat4F *)args ) ;
			bone->m_flags |= 0x0040 ;
			break ;
		    }
		    case SCEGMO_TRANSLATE : {
			sceGmoVec3Load( &( bone->m_translate ), (SceGmoVec3F *)args ) ;
			bone->m_flags |= 0x0001 ;
			break ;
		    }
		    case SCEGMO_ROTATE_ZYX : {
			SceGmoVec3 rotate ;
			sceGmoVec3Load( &rotate, (SceGmoVec3F *)args ) ;
			sceGmoQuatFromRotZYX( &( bone->m_rotate ), &rotate ) ;
			bone->m_flags |= 0x0002 ;
			break ;
		    }
		    case SCEGMO_ROTATE_YXZ : {
			SceGmoVec3 rotate ;
			sceGmoVec3Load( &rotate, (SceGmoVec3F *)args ) ;
			sceGmoQuatFromRotYXZ( &( bone->m_rotate ), &rotate ) ;
			bone->m_flags |= 0x0002 ;
			break ;
		    }
		    case SCEGMO_ROTATE_Q : {
			sceGmoQuatLoad( &( bone->m_rotate ), (SceGmoQuatF *)args ) ;
			bone->m_flags |= 0x0002 ;
			break ;
		    }
		    case SCEGMO_SCALE : {
			sceGmoVec3Load( &( bone->m_scale ), (SceGmoVec3F *)args ) ;
			bone->m_flags |= 0x0004 ;
			break ;
		    }
		    case SCEGMO_SCALE_2 : {
			sceGmoVec3Load( &( bone->m_scale ), (SceGmoVec3F *)args ) ;
			bone->m_flags |= 0x0008 ;
			break ;
		    }
		    case SCEGMO_SCALE_3 : {
			sceGmoVec3Load( &( bone->m_scale ), (SceGmoVec3F *)args ) ;
			bone->m_flags |= 0x0010 ;
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
	bone->m_flags |= 0x40000000 ;
	if ( !( bone->m_flags & 0x0200 ) ) {
		bone->m_visibility = has_draw_part ? -1 : 0 ;
	}
	if ( bone->m_n_blend_bones > 0 ) {
		if ( !set_blend_offsets( bone, 0, bone->m_n_blend_bones ) ) {
			return 0 ;
		}
		{ int i ; for ( i = 0 ; i < bone->m_n_blend_bones ; i ++ ) {
			if ( blend_offsets != 0 && i < blend_offsets->n_offsets ) {
				sceGmoMat4Load( &( bone->m_blend_offsets[ i ] ), &( blend_offsets->offsets[ i ] ) ) ;
			} else {
				sceGmoMat4Set( &( bone->m_blend_offsets[ i ] ), 0, 0, 0, 1, 1, 1 ) ;
			}
		} }
	}
	bone->m_initial = sceGmoBoneDuplicate( bone, 0x0010 ) ;
	return ( bone->m_initial != 0 ) ;
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

extern float D_000836DC[] ;
void sceGmoBoneControl( SceGmoBone *bone, int type, int idx, const float *val, int cnt, float weight )
{
	if ( bone == 0 ) return ;

	float *dst ;
	int flags ;
	int channel ;
	SceGmoQuat rotate ;
	float weights[ 8 ] ;
	switch ( type ) {
	    case SCEGMO_TRANSLATE :
		dst = (float *)&( bone->m_translate ) ;
		flags = 0x0001 ;
		channel = 1 ;
		break ;
	    case SCEGMO_ROTATE_Q :
		dst = (float *)&( bone->m_rotate ) ;
		flags = 0x0002 ;
		channel = 2 ;
		break ;
	    case SCEGMO_ROTATE_ZYX :
		dst = (float *)&( bone->m_rotate ) ;
		flags = 0x0002 ;
		channel = 2 ;
		sceGmoQuatFromRotZYX( &rotate, (SceGmoVec3 *)val ) ;
		val = (float *)&rotate ;
		break ;
	    case SCEGMO_ROTATE_YXZ :
		dst = (float *)&( bone->m_rotate ) ;
		flags = 0x0002 ;
		channel = 2 ;
		sceGmoQuatFromRotYXZ( &rotate, (SceGmoVec3 *)val ) ;
		val = (float *)&rotate ;
		break ;
	    case SCEGMO_SCALE :
		dst = (float *)&( bone->m_scale ) ;
		flags = 0x0004 ;
		channel = 3 ;
		break ;
	    case SCEGMO_SCALE_2 :
		dst = (float *)&( bone->m_scale ) ;
		flags = 0x0008 ;
		channel = 3 ;
		break ;
	    case SCEGMO_SCALE_3 :
		dst = (float *)&( bone->m_scale ) ;
		flags = 0x0010 ;
		channel = 3 ;
		break ;
	    case SCEGMO_MULT_MATRIX :
		dst = (float *)&( bone->m_local_matrix ) ;
		flags = 0x0040 ;
		channel = 0 ;
		break ;
	    case SCEGMO_MORPH_WEIGHTS :
		set_morph_weights( bone, 0, cnt ) ;
		dst = bone->m_morph_weights ;
		flags = 0x0100 ;
		channel = 4 ;
		break ;
	    case SCEGMO_MORPH_INDEX :
		calc_morph_index( weights, 8, *val ) ;
		set_morph_weights( bone, weights, 8 ) ;
		val = weights ;
		cnt = 8 ;
		dst = bone->m_morph_weights ;
		flags = 0x0100 ;
		channel = 4 ;
		break ;

	    case SCEGMO_VISIBILITY :
		bone->m_flags |= 0x0200 ;
		bone->m_anim_flags |= 0x0200 | ( 0x0200 << 16 ) ;
		bone->m_visibility = (int)( val[ 0 ] + 0.5f ) ;
		return ;
	    default :
		return ;
	}

	float sum = bone->m_anim_weights[ channel ] + weight ;
	bone->m_anim_weights[ channel ] = sum ;
	weight /= sum ;
	if ( channel != 2 ) {
		sceGmoFloatLerp( dst, dst, val, cnt, weight ) ;
	} else {
		sceGmoQuatSlerp( (SceGmoQuat *)dst, (SceGmoQuat *)dst, (SceGmoQuat *)val, weight ) ;
	}
	bone->m_flags |= flags | 0x40000000 ;
	if ( sum > 0.99f ) flags |= ( flags << 16 ) ;
	bone->m_anim_flags |= flags ;
}

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

static void complement_animation( SceGmoBone *bone )
{
 int flags = bone->m_anim_flags ;
 int reset = 0xffff0000 ;
 int modified = ( flags & 0x0000ffff ) ;
 int complete = ( flags & 0xffff0000 ) >> 16 ;
 int incomplete = modified & ~complete ;
 if ( incomplete ) {
  SceGmoBone *initial = bone->m_initial ;
  if ( incomplete & 0x0040 ) {
   float w = 1.0f - bone->m_anim_weights[ 0 ] ;
   float *val = (float *)&( initial->m_local_matrix ) ;
   sceGmoBoneControl( bone, SCEGMO_MULT_MATRIX, 0, val, 16, w ) ;
   if ( w > 0.99f ) reset |= 0x0040 ;
  }
  if ( incomplete & 0x0001 ) {
   float w = 1.0f - bone->m_anim_weights[ 1 ] ;
   float *val = (float *)&( initial->m_translate ) ;
   sceGmoBoneControl( bone, SCEGMO_TRANSLATE, 0, val, 3, w ) ;
   if ( w > 0.99f ) reset |= 0x0001 ;
  }
  if ( incomplete & 0x0002 ) {
   float w = 1.0f - bone->m_anim_weights[ 2 ] ;
   float *val = (float *)&( initial->m_rotate ) ;
   sceGmoBoneControl( bone, SCEGMO_ROTATE_Q, 0, val, 4, w ) ;
   if ( w > 0.99f ) reset |= 0x0002 ;
  }
  if ( incomplete & 0x0004 ) {
   float w = 1.0f - bone->m_anim_weights[ 3 ] ;
   float *val = (float *)&( initial->m_scale ) ;
   sceGmoBoneControl( bone, SCEGMO_SCALE, 0, val, 3, w ) ;
   if ( w > 0.99f ) reset |= 0x0004 ;
  }
  if ( incomplete & 0x0008 ) {
   float w = 1.0f - bone->m_anim_weights[ 3 ] ;
   float *val = (float *)&( initial->m_scale ) ;
   sceGmoBoneControl( bone, SCEGMO_SCALE_2, 0, val, 3, w ) ;
   if ( w > 0.99f ) reset |= 0x0008 ;
  }
  if ( incomplete & 0x0010 ) {
   float w = 1.0f - bone->m_anim_weights[ 3 ] ;
   float *val = (float *)&( initial->m_scale ) ;
   sceGmoBoneControl( bone, 0x00e1, 0, val, 3, w ) ;
   if ( w > 0.99f ) reset |= 0x0010 ;
  }
  if ( incomplete & 0x0100 ) {
   float w = 1.0f - bone->m_anim_weights[ 4 ] ;
   float *val = initial->m_morph_weights ;
   int cnt = initial->m_n_morph_weights ;
   if ( cnt == 0 ) {
    val = D_000836DC ;
    cnt = (8) ;
   }
   sceGmoBoneControl( bone, SCEGMO_MORPH_WEIGHTS, 0, val, cnt, w ) ;
   if ( w > 0.99f ) reset |= 0x0100 ;
  }
  if ( incomplete & 0x0200 ) {
   bone->m_visibility = initial->m_visibility ;
   reset |= 0x0200 ;
  }
 }
 bone->m_anim_flags &= ~reset ;
 if ( modified ) {
  memset( bone->m_anim_weights, 0, sizeof( bone->m_anim_weights ) ) ;
 }
}

static void calc_bone_matrix( SceGmoBone *bone, SceGmoModel *model )
{
	int flags = bone->m_flags ;
	if ( flags & IS_LOCAL_DIRTY ) {
		flags &= ~IS_LOCAL_DIRTY ;
		if ( !( flags & 0x0040 ) ) {
			sceGmoBoneAffineMatrix( &( bone->m_local_matrix ),
				&( bone->m_translate ),
				&( bone->m_rotate ),
				&( bone->m_scale ), flags ) ;
		}
	}

	SceGmoMat4 *stack = &( bone->m_stack_matrix ) ;
	*stack = bone->m_local_matrix ;

	SceGmoBone *parent = sceGmoModelGetBone( model, bone->m_parent_bone ) ;
	int flags2 = ( parent == 0 ) ? 0 : parent->m_flags ;
	if ( ( flags | flags2 ) & ( IS_SCALE_STACKED | 0x0008 | 0x0010 ) ) {
		flags = sceGmoBoneStackScale( stack,
				&( bone->m_stack_scale ), &( bone->m_scale ), flags,
				&( parent->m_stack_scale ), &( parent->m_scale ), flags2 ) ;
	}

	if ( flags & 0x0080 ) {
		const SceGmoVec3 *s2 = &( parent->m_stack_scale ) ;
		if ( parent == 0 ) s2 = &sceGmoVec3_One ;
		sceGmoBoneApplyPivot( stack, &( bone->m_pivot ), s2 ) ;
	}

	const SceGmoMat4 *m ;
	if ( parent != 0 ) {
		m = &( parent->m_stack_matrix ) ;
	} else {
		m = sceGmoModelGetWorldMatrix( model ) ;
	}
	sceGmoMat4Multiply( stack, m, stack ) ;

	bone->m_flags = flags | IS_BLEND_DIRTY ;
}

