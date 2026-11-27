/* data-align: 16 */
#include "common.h"
#include "gmo_math_sdk.h"

const SceGmoVec3 sceGmoVec3_One = { 1, 1, 1, 1 } ;
const SceGmoVec4 sceGmoVec4_One = { 1, 1, 1, 1 } ;
const SceGmoMat4 sceGmoMat4_One = {
	{ 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 }
} ;
const SceGmoQuat sceGmoQuat_One = { 0, 0, 0, 1 } ;
const SceGmoRect sceGmoRect_One = { 0, 0, 1, 1 } ;
const SceGmoCol4 sceGmoCol4_One = 0xffffffff ;

SceGmoVec3 *sceGmoVec3Set( SceGmoVec3 *dst, float x, float y, float z ) ;
SceGmoVec4 *sceGmoVec4Set( SceGmoVec4 *dst, float x, float y, float z, float w ) ;
SceGmoMat4 *sceGmoMat4Set( SceGmoMat4 *dst, float tx, float ty, float tz, float sx, float sy, float sz ) ;
SceGmoQuat *sceGmoQuatSet( SceGmoQuat *dst, float x, float y, float z, float w ) ;
SceGmoRect *sceGmoRectSet( SceGmoRect *dst, float x, float y, float w, float h ) ;
SceGmoCol4 *sceGmoCol4Set( SceGmoCol4 *dst, float r, float g, float b, float a ) ;
SceGmoVec2 *sceGmoVec2Load( SceGmoVec2 *dst, const SceGmoVec2F *src ) ;
SceGmoVec3 *sceGmoVec3Load( SceGmoVec3 *dst, const SceGmoVec3F *src ) ;
SceGmoVec4 *sceGmoVec4Load( SceGmoVec4 *dst, const SceGmoVec4F *src ) ;
SceGmoMat4 *sceGmoMat4Load( SceGmoMat4 *dst, const SceGmoMat4F *src ) ;
SceGmoQuat *sceGmoQuatLoad( SceGmoQuat *dst, const SceGmoQuatF *src ) ;
SceGmoRect *sceGmoRectLoad( SceGmoRect *dst, const SceGmoRectF *src ) ;
SceGmoCol4 *sceGmoCol4Load( SceGmoCol4 *dst, const SceGmoCol4F *src ) ;
SceGmoMat4 *sceGmoMat4Multiply( SceGmoMat4 *dst, const SceGmoMat4 *src1, const SceGmoMat4 *src2 ) ;
SceGmoMat4 *sceGmoMat4Scale( SceGmoMat4 *dst, const SceGmoMat4 *src1, const SceGmoVec3 *src2 ) ;
SceGmoMat4 *sceGmoMat4FromQuat( SceGmoMat4 *dst, const SceGmoQuat *src ) ;
SceGmoQuat *sceGmoQuatFromRotZYX( SceGmoQuat *dst, const SceGmoVec3 *src ) ;
SceGmoQuat *sceGmoQuatFromRotYXZ( SceGmoQuat *dst, const SceGmoVec3 *src ) ;
SceGmoQuat *sceGmoQuatSlerp( SceGmoQuat *dst, const SceGmoQuat *src1, const SceGmoQuat *src2, float f ) ;
SceGmoVec2 *sceGmoVec2Multiply( SceGmoVec2 *dst, const SceGmoVec2 *src1, const SceGmoVec2 *src2 ) ;
SceGmoRect *sceGmoRectMultiply( SceGmoRect *dst, const SceGmoRect *src1, const SceGmoRect *src2 ) ;
SceGmoVec4 *sceGmoVec4FromCol4( SceGmoVec4 *dst, const SceGmoCol4 *src ) ;
SceGmoCol4 *sceGmoCol4FromVec4( SceGmoCol4 *dst, const SceGmoVec4 *src ) ;
SceGmoCol4 *sceGmoCol4Multiply( SceGmoCol4 *dst, const SceGmoCol4 *src1, const SceGmoCol4 *src2 ) ;
float *sceGmoFloatLerp( float *dst, const float *src1, const float *src2, int count, float f ) ;
void sceGmoBoneAffineMatrix( SceGmoMat4 *m, const SceGmoVec3 *translate, const SceGmoQuat *rotate, const SceGmoVec3 *scale, int flags ) ;
int sceGmoBoneStackScale( SceGmoMat4 *m, SceGmoVec3 *sscale, const SceGmoVec3 *lscale, int flags, const SceGmoVec3 *sscale2, const SceGmoVec3 *lscale2, int flags2 ) ;
void sceGmoBoneApplyPivot( SceGmoMat4 *m, const SceGmoVec3 *pivot, const SceGmoVec3 *sscale, const SceGmoVec3 *sscale2 ) ;
int sceGmoFCurveEval( const SceGmoChunk *chunk, float frame, float *output ) ;
SceGmoMat4 *sceGmoMat4MultiplyRect( SceGmoMat4 *dst, const SceGmoMat4 *src1, const SceGmoRect *src2 ) ;
SceGmoMat4 *sceGmoMat4Normalize( SceGmoMat4 *dst, const SceGmoMat4 *src ) ;
static __inline__ _Bool _sceGmoCol4IsBlack( const SceGmoCol4 *src )
{
 return ( ( *src & 0x00ffffff ) == 0 ) ;
}
static __inline__ _Bool _sceGmoCol4IsWhite( const SceGmoCol4 *src )
{
 return ( ( *src & 0x00ffffff ) == 0x00ffffff ) ;
}
static __inline__ _Bool _sceGmoCol4IsHollow( const SceGmoCol4 *src )
{
 return ( ( *src & 0xff000000 ) == 0 ) ;
}
static __inline__ _Bool _sceGmoCol4IsOpaque( const SceGmoCol4 *src )
{
 return ( ( *src & 0xff000000 ) == 0xff000000 ) ;
}
static __inline__ float _sceGmoCol4GetR( const SceGmoCol4 *src )
{
 return ( *src & 255 ) * ( 1.0f / 255.0f ) ;
}
static __inline__ float _sceGmoCol4GetG( const SceGmoCol4 *src )
{
 return ( ( *src >> 8 ) & 255 ) * ( 1.0f / 255.0f ) ;
}
static __inline__ float _sceGmoCol4GetB( const SceGmoCol4 *src )
{
 return ( ( *src >> 16 ) & 255 ) * ( 1.0f / 255.0f ) ;
}
static __inline__ float _sceGmoCol4GetA( const SceGmoCol4 *src )
{
 return ( ( *src >> 24 ) & 255 ) * ( 1.0f / 255.0f ) ;
}
enum {
 SCEGMO_CONTEXT_ENABLE_MODEL = 0,
 SCEGMO_CONTEXT_ENABLE_LAYER = 1,
 SCEGMO_CONTEXT_ENABLE_MESH = 2,
 SCEGMO_CONTEXT_ENABLE_COUNT,
 SCEGMO_CONTEXT_WMATRIX_MODEL = 0,
 SCEGMO_CONTEXT_WMATRIX_BONE = 1,
 SCEGMO_CONTEXT_WMATRIX_VERTEX = 2,
 SCEGMO_CONTEXT_WMATRIX_COUNT,
 SCEGMO_CONTEXT_CMATRIX_MODEL = 0,
 SCEGMO_CONTEXT_CMATRIX_BONE = 1,
 SCEGMO_CONTEXT_CMATRIX_COUNT,
 SCEGMO_CONTEXT_TMATRIX_PICTURE = 0,
 SCEGMO_CONTEXT_TMATRIX_LAYER = 1,
 SCEGMO_CONTEXT_TMATRIX_VERTEX = 2,
 SCEGMO_CONTEXT_TMATRIX_COUNT,
 SCEGMO_CONTEXT_SUBDIV_MODEL = 0,
 SCEGMO_CONTEXT_SUBDIV_MESH = 1,
 SCEGMO_CONTEXT_SUBDIV_COUNT,
 SCEGMO_CONTEXT_TEX_GEN_MODEL = 0,
 SCEGMO_CONTEXT_TEX_GEN_LAYER = 1,
 SCEGMO_CONTEXT_TEX_GEN_COUNT
} ;
enum {
 SCEGMO_ENABLE_PRIVATE = 0xffff0000,
 SCEGMO_ENABLE_FLUSH = 0x80000000,
 SCEGMO_ENABLE_SINGLE_COLOR = SCEGMO_OUTPUT_LIGHT_MODEL,
 SCEGMO_ENABLE_SHADE_MAP = SCEGMO_OUTPUT_TEX_GEN
} ;
void sceGmoContextBegin( unsigned int **pkt, unsigned int *size, int draw_flags ) ;
_Bool sceGmoContextEnd( void ) ;
void sceGmoContextUpdate( void ) ;
void sceGmoContextRestore( void ) ;
void sceGmoContextSetOutputMask( int mask ) ;
void sceGmoContextSetBone( SceGmoBone *bone, SceGmoModel *model, const int *idxs, int n_idxs ) ;
int sceGmoContextSetMaterial( SceGmoMaterial *material, SceGmoModel *model, int idx ) ;
void sceGmoContextSetPicture( SceGimPicture *picture ) ;
void sceGmoContextSetEnableBits( int level, int mask, int bits ) ;
void sceGmoContextSetMaterialColor( const SceGmoCol4 *diffuse, const SceGmoCol4 *ambient, const SceGmoCol4 *specular, float shininess ) ;
void sceGmoContextSetBlendFunc( int mode, int src, int dst ) ;
void sceGmoContextSetMorphWeights( const float *weights, int n_weights ) ;
void sceGmoContextSetMorphIndex( float idx ) ;
void sceGmoContextSetBlendOffsets( const SceGmoMat4 *offsets, int n_offsets ) ;
void sceGmoContextSetBlendSubset( const int *idxs, int n_idxs ) ;
void sceGmoContextSetWorldMatrix( int level, const SceGmoMat4 *matrix ) ;
void sceGmoContextSetTextureMatrix( int level, const SceGmoRect *offset ) ;
void sceGmoContextSetColorMatrix( int level, const SceGmoCol4 *color ) ;
void sceGmoContextSetSubdivision( int level, const SceGmoVec2 *subdiv ) ;
void sceGmoContextSetTexGen( int level, int mode, const SceGmoMat4 *matrix ) ;
void sceGmoContextDrawArrays( SceGmoArraysHeader *arrays, SceGmoDrawArrays *cmd ) ;
void sceGmoContextDrawParticle( SceGmoArraysHeader *arrays, SceGmoDrawParticle *cmd ) ;
void sceGmoContextDrawBSpline( SceGmoArraysHeader *arrays, SceGmoDrawBSpline *cmd ) ;
void sceGmoContextDrawRectMesh( SceGmoArraysHeader *arrays, SceGmoDrawRectMesh *cmd ) ;
void sceGmoContextDrawRectPatch( SceGmoArraysHeader *arrays, SceGmoDrawRectPatch *cmd ) ;
void sceGmoContextCallList( const unsigned int *ptr ) ;
void sceGmoContextReturnFromList( void ) ;
unsigned int *sceGmoContextBeginList( void ) ;
void sceGmoContextEndList( unsigned int *begin ) ;
unsigned int *sceGmoContextBeginObject( const SceGmoVec3F *points, int n_points ) ;
void sceGmoContextEndObject( unsigned int *begin ) ;
unsigned int *sceGmoContextBeginPacket( unsigned int *size ) ;
void sceGmoContextEndPacket( unsigned int *pkt ) ;
const SceGmoMat4 *sceGmoContextGetCurrentWorldMatrix() ;
typedef struct SceGmoSubject {
 struct SceGmoObserver *m_observers ;
} SceGmoSubject ;
typedef struct SceGmoObserver {
 struct SceGmoObserver *m_next ;
 struct SceGmoSubject *m_subject ;
 void *m_reserved ;
} SceGmoObserver ;
typedef struct SceGmoBase {
 struct SceGmoSubject m_subject ;
 struct SceGmoObserver m_parent ;
} SceGmoBase ;
void sceGmoSubjectConstruct( SceGmoSubject *subject ) ;
void sceGmoSubjectDestruct( SceGmoSubject *subject ) ;
void sceGmoSubjectCopy( SceGmoSubject *subject, const SceGmoSubject *src ) ;
void sceGmoSubjectAttachObserver( SceGmoSubject *subject, SceGmoObserver *observer ) ;
void sceGmoSubjectDetachObserver( SceGmoSubject *subject, SceGmoObserver *observer ) ;
void sceGmoObserverConstruct( SceGmoObserver *observer ) ;
void sceGmoObserverDestruct( SceGmoObserver *observer ) ;
void sceGmoObserverCopy( SceGmoObserver *observer, const SceGmoObserver *src ) ;
void sceGmoObserverSetSubject( SceGmoObserver *observer, SceGmoSubject *subject ) ;
SceGmoSubject *sceGmoObserverGetSubject( const SceGmoObserver *observer ) ;
void sceGmoBaseConstruct( SceGmoBase *base ) ;
void sceGmoBaseDestruct( SceGmoBase *base ) ;
void sceGmoBaseCopy( SceGmoBase *base, const SceGmoBase *src ) ;
void sceGmoBaseAttachObserver( SceGmoBase *base, SceGmoObserver *observer ) ;
void sceGmoBaseDetachObserver( SceGmoBase *base, SceGmoObserver *observer ) ;
void sceGmoBaseSetParent( SceGmoBase *base, SceGmoSubject *parent ) ;
SceGmoSubject *sceGmoBaseGetParent( const SceGmoBase *base ) ;
static __inline__ SceGmoSubject *_sceGmoObserverGetSubject( const SceGmoObserver *observer )
{
 return observer->m_subject ;
}
static __inline__ SceGmoSubject *_sceGmoBaseGetParent( const SceGmoBase *base )
{
 return base->m_parent.m_subject ;
}
enum {
 SCEGMO_MODEL_HAS_BOUNDING_BOX = 0x0001,
 SCEGMO_MODEL_HAS_VERTEX_OFFSET = 0x0002,
 SCEGMO_MODEL_HAS_TEXCOORD_OFFSET = 0x0004,
 SCEGMO_MODEL_HAS_COLOR = 0x0008,
 SCEGMO_MODEL_HAS_SUBDIV = 0x0010
} ;
struct SceGmoModel {
 SceGmoBase m_base ;
 int m_reference ;
 int m_flags ;
 SceGmoBone **m_bones ;
 SceGmoPart **m_parts ;
 SceGmoMaterial **m_materials ;
 SceGmoTexture **m_textures ;
 SceGmoMotion **m_motions ;
 int m_n_bones ;
 int m_n_parts ;
 int m_n_materials ;
 int m_n_textures ;
 int m_n_motions ;
 int m_current_motion ;
 float m_change_motion ;
 int m_enable_bits ;
 int m_enable_mask ;
 int m_output_mask ;
 int m_option_flags ;
 int m_mesh_mask ;
 SceGmoCol4 m_color ;
 float m_subdiv ;
 SceGmoBoundingPoints *m_bounding_points ;
 SceGmoMat4 m_world_matrix ;
 SceGmoVec3 m_bounding_box[ 2 ] ;
 SceGmoMat4 m_vertex_offset ;
 SceGmoRect m_texcoord_offset ;
} ;
static __inline__ const SceGmoMat4 *_sceGmoModelGetWorldMatrix( SceGmoModel *model )
{
 return &( model->m_world_matrix ) ;
}
static __inline__ int _sceGmoModelGetCurrentMotion( SceGmoModel *model )
{
 return model->m_current_motion ;
}
static __inline__ int _sceGmoModelGetEnableBits( SceGmoModel *model )
{
 return model->m_enable_bits ;
}
static __inline__ int _sceGmoModelGetEnableMask( SceGmoModel *model )
{
 return model->m_enable_mask ;
}
static __inline__ int _sceGmoModelGetOutputMask( SceGmoModel *model )
{
 return model->m_output_mask ;
}
static __inline__ int _sceGmoModelGetOptionFlags( SceGmoModel *model )
{
 return model->m_option_flags ;
}
static __inline__ int _sceGmoModelGetMeshMask( SceGmoModel *model )
{
 return model->m_mesh_mask ;
}
static __inline__ SceGmoCol4 _sceGmoModelGetColor( SceGmoModel *model )
{
 return model->m_color ;
}
static __inline__ float _sceGmoModelGetSubdivision( SceGmoModel *model )
{
 return model->m_subdiv ;
}
static __inline__ const SceGmoVec3 *_sceGmoModelGetBoundingBox( SceGmoModel *model )
{
 if ( !( model->m_flags & SCEGMO_MODEL_HAS_BOUNDING_BOX ) ) return 0 ;
 return model->m_bounding_box ;
}
static __inline__ const SceGmoMat4 *_sceGmoModelGetVertexOffset( SceGmoModel *model )
{
 if ( !( model->m_flags & SCEGMO_MODEL_HAS_VERTEX_OFFSET ) ) return 0 ;
 return &( model->m_vertex_offset ) ;
}
static __inline__ const SceGmoRect *_sceGmoModelGetTexcoordOffset( SceGmoModel *model )
{
 if ( !( model->m_flags & SCEGMO_MODEL_HAS_TEXCOORD_OFFSET ) ) return 0 ;
 return &( model->m_texcoord_offset ) ;
}
static __inline__ int _sceGmoModelGetBoundingPointsCount( SceGmoModel *model )
{
 SceGmoBoundingPoints *bpts = model->m_bounding_points ;
 return ( bpts == 0 ) ? 0 : bpts->n_points ;
}
static __inline__ const SceGmoVec3F *_sceGmoModelGetBoundingPoints( SceGmoModel *model )
{
 SceGmoBoundingPoints *bpts = model->m_bounding_points ;
 return ( bpts == 0 ) ? 0 : bpts->points ;
}
static __inline__ int _sceGmoModelGetBoneCount( SceGmoModel *model )
{
 return model->m_n_bones ;
}
static __inline__ int _sceGmoModelGetPartCount( SceGmoModel *model )
{
 return model->m_n_parts ;
}
static __inline__ int _sceGmoModelGetMaterialCount( SceGmoModel *model )
{
 return model->m_n_materials ;
}
static __inline__ int _sceGmoModelGetTextureCount( SceGmoModel *model )
{
 return model->m_n_textures ;
}
static __inline__ int _sceGmoModelGetMotionCount( SceGmoModel *model )
{
 return model->m_n_motions ;
}
static __inline__ SceGmoBone *_sceGmoModelGetBone( SceGmoModel *model, int idx )
{
 idx = (0x0fff&(idx)) ;
 if ( idx >= model->m_n_bones ) return 0 ;
 return model->m_bones[ idx ] ;
}
static __inline__ SceGmoPart *_sceGmoModelGetPart( SceGmoModel *model, int idx )
{
 idx = (0x0fff&(idx)) ;
 if ( idx >= model->m_n_parts ) return 0 ;
 return model->m_parts[ idx ] ;
}
static __inline__ SceGmoMaterial *_sceGmoModelGetMaterial( SceGmoModel *model, int idx )
{
 idx = (0x0fff&(idx)) ;
 if ( idx >= model->m_n_materials ) return 0 ;
 return model->m_materials[ idx ] ;
}
static __inline__ SceGmoTexture *_sceGmoModelGetTexture( SceGmoModel *model, int idx )
{
 idx = (0x0fff&(idx)) ;
 if ( idx >= model->m_n_textures ) return 0 ;
 return model->m_textures[ idx ] ;
}
static __inline__ SceGmoMotion *_sceGmoModelGetMotion( SceGmoModel *model, int idx )
{
 idx = (0x0fff&(idx)) ;
 if ( idx >= model->m_n_motions ) return 0 ;
 return model->m_motions[ idx ] ;
}
enum {
 SCEGMO_BONE_IS_SCALE_STACKED = 0x80000000,
 SCEGMO_BONE_IS_LOCAL_DIRTY = 0x40000000,
 SCEGMO_BONE_IS_BLEND_DIRTY = 0x20000000,
 SCEGMO_BONE_HAS_TRANSLATE = 0x0001,
 SCEGMO_BONE_HAS_ROTATE = 0x0002,
 SCEGMO_BONE_HAS_SCALE = 0x001c,
 SCEGMO_BONE_HAS_SCALE_1 = 0x0004,
 SCEGMO_BONE_HAS_SCALE_2 = 0x0008,
 SCEGMO_BONE_HAS_SCALE_3 = 0x0010,
 SCEGMO_BONE_HAS_MULT_MATRIX = 0x0040,
 SCEGMO_BONE_HAS_PIVOT = 0x0080,
 SCEGMO_BONE_HAS_MORPH = 0x0300,
 SCEGMO_BONE_HAS_MORPH_WEIGHTS = 0x0100,
 SCEGMO_BONE_HAS_MORPH_INDEX = 0x0200,
 SCEGMO_BONE_HAS_BLEND = 0x0400,
 SCEGMO_BONE_HAS_VISIBILITY = 0x0800,
 SCEGMO_BONE_HAS_COLOR = 0x1000
} ;
enum {
 SCEGMO_BONE_ANIM_MODIFIED = 0x0000ffff,
 SCEGMO_BONE_ANIM_COMPLETE = 0xffff0000,
 SCEGMO_BONE_CHAN_MATRIX = 0,
 SCEGMO_BONE_CHAN_TRANSLATE = 1,
 SCEGMO_BONE_CHAN_ROTATE = 2,
 SCEGMO_BONE_CHAN_SCALE = 3,
 SCEGMO_BONE_CHAN_MORPH = 4,
 SCEGMO_BONE_CHAN_COUNT
} ;
struct SceGmoBone {
 SceGmoBase m_base ;
 SceGmoBone *m_initial ;
 int m_reference ;
 int m_flags ;
 int *m_draw_parts ;
 float *m_morph_weights ;
 int *m_blend_bones ;
 SceGmoMat4 *m_blend_offsets ;
 int m_n_draw_parts ;
 int m_n_morph_weights ;
 int m_n_blend_bones ;
 int m_n_blend_offsets ;
 int m_parent_bone ;
 int m_visibility ;
 float m_morph_index ;
 SceGmoCol4 m_color ;
 int m_z_sort_mode ;
 int m_anim_flags ;
 float m_anim_weights[ SCEGMO_BONE_CHAN_COUNT ] ;
 SceGmoVec3 m_pivot ;
 SceGmoVec3 m_translate ;
 SceGmoQuat m_rotate ;
 SceGmoVec3 m_scale ;
 SceGmoMat4 m_local_matrix ;
 SceGmoMat4 m_stack_matrix ;
 SceGmoVec3 m_stack_scale ;
} ;
static __inline__ int _sceGmoBoneGetFlags( SceGmoBone *bone )
{
 return bone->m_flags ;
}
static __inline__ SceGmoBone *_sceGmoBoneGetInitialState( SceGmoBone *bone )
{
 return bone->m_initial ;
}
static __inline__ SceGmoModel *_sceGmoBoneGetParent( SceGmoBone *bone )
{
 return (SceGmoModel *)_sceGmoBaseGetParent( &( bone->m_base ) ) ;
}
static __inline__ int _sceGmoBoneGetParentBone( SceGmoBone *bone )
{
 return bone->m_parent_bone ;
}
static __inline__ int _sceGmoBoneGetVisibility( SceGmoBone *bone )
{
 return bone->m_visibility ;
}
static __inline__ int _sceGmoBoneGetMorphWeightsCount( SceGmoBone *bone )
{
 return bone->m_n_morph_weights ;
}
static __inline__ const float *_sceGmoBoneGetMorphWeights( SceGmoBone *bone )
{
 return bone->m_morph_weights ;
}
static __inline__ float _sceGmoBoneGetMorphIndex( SceGmoBone *bone )
{
 return bone->m_morph_index ;
}
static __inline__ int _sceGmoBoneGetBlendBonesCount( SceGmoBone *bone )
{
 return bone->m_n_blend_bones ;
}
static __inline__ const int *_sceGmoBoneGetBlendBones( SceGmoBone *bone )
{
 return bone->m_blend_bones ;
}
static __inline__ int _sceGmoBoneGetBlendOffsetsCount( SceGmoBone *bone )
{
 return bone->m_n_blend_offsets ;
}
static __inline__ const SceGmoMat4 *_sceGmoBoneGetBlendOffsets( SceGmoBone *bone )
{
 return bone->m_blend_offsets ;
}
static __inline__ const SceGmoVec3 *_sceGmoBoneGetPivot( SceGmoBone *bone )
{
 if ( !( bone->m_flags & SCEGMO_BONE_HAS_PIVOT ) ) return 0 ;
 return &( bone->m_pivot ) ;
}
static __inline__ const SceGmoVec3 *_sceGmoBoneGetTranslate( SceGmoBone *bone )
{
 if ( !( bone->m_flags & SCEGMO_BONE_HAS_TRANSLATE ) ) return 0 ;
 return &( bone->m_translate ) ;
}
static __inline__ const SceGmoQuat *_sceGmoBoneGetRotate( SceGmoBone *bone )
{
 if ( !( bone->m_flags & SCEGMO_BONE_HAS_ROTATE ) ) return 0 ;
 return &( bone->m_rotate ) ;
}
static __inline__ const SceGmoVec3 *_sceGmoBoneGetScale( SceGmoBone *bone )
{
 if ( !( bone->m_flags & SCEGMO_BONE_HAS_SCALE ) ) return 0 ;
 return &( bone->m_scale ) ;
}
static __inline__ const SceGmoMat4 *_sceGmoBoneGetWorldMatrix( SceGmoBone *bone )
{
 SceGmoMat4 *m = &( bone->m_stack_matrix ) ;
 if ( bone->m_flags & SCEGMO_BONE_IS_SCALE_STACKED ) {
  bone->m_flags &= ~SCEGMO_BONE_IS_SCALE_STACKED ;
  sceGmoMat4Scale( m, m, &( bone->m_stack_scale ) ) ;
 }
 return m ;
}
static __inline__ SceGmoCol4 _sceGmoBoneGetColor( SceGmoBone *bone )
{
 return bone->m_color ;
}
static __inline__ int _sceGmoBoneGetZSortMode( SceGmoBone *bone )
{
 return bone->m_z_sort_mode ;
}
struct SceGmoPart {
 SceGmoBase m_base ;
 SceGmoChunk *m_chunk ;
 int m_reference ;
 int m_flags ;
 struct SceGmoVertexCache *m_vertex_cache ;
 SceGmoMesh **m_meshes ;
 SceGmoChunk **m_arrays ;
 int m_n_meshes ;
 int m_n_arrays ;
} ;
static __inline__ int _sceGmoPartGetFlags( SceGmoPart *part )
{
 return part->m_flags ;
}
static __inline__ SceGmoModel *_sceGmoPartGetParent( SceGmoPart *part )
{
 return (SceGmoModel *)_sceGmoBaseGetParent( &( part->m_base ) ) ;
}
static __inline__ int _sceGmoPartGetMeshCount( SceGmoPart *part )
{
 return part->m_n_meshes ;
}
static __inline__ int _sceGmoPartGetArraysCount( SceGmoPart *part )
{
 return part->m_n_arrays ;
}
static __inline__ SceGmoMesh *_sceGmoPartGetMesh( SceGmoPart *part, int idx )
{
 idx = (0x0fff&(idx)) ;
 if ( idx >= part->m_n_meshes ) return 0 ;
 return part->m_meshes[ idx ] ;
}
static __inline__ SceGmoChunk *_sceGmoPartGetArrays( SceGmoPart *part, int idx )
{
 idx = (0x0fff&(idx)) ;
 if ( idx >= part->m_n_arrays ) return 0 ;
 return part->m_arrays[ idx ] ;
}
enum {
 SCEGMO_MESH_HAS_SUBDIV = 0x0001
} ;
struct SceGmoMesh {
 SceGmoChunk *m_chunk ;
 int m_reference ;
 int m_flags ;
 struct SceGmoPrimitiveCache *m_primitive_cache ;
 int m_material ;
 int *m_blend_subset ;
 int m_n_blend_subset ;
 SceGmoBoundingPoints *m_bounding_points ;
 int m_enable_mask ;
 int m_enable_bits ;
 int m_mesh_mask ;
 SceGmoVec2 m_subdiv ;
} ;
static __inline__ int _sceGmoMeshGetFlags( SceGmoMesh *mesh )
{
 return mesh->m_flags ;
}
static __inline__ int _sceGmoMeshGetMaterial( SceGmoMesh *mesh )
{
 return mesh->m_material ;
}
static __inline__ const SceGmoVec2 *_sceGmoMeshGetSubdivision( SceGmoMesh *mesh )
{
 if ( !( mesh->m_flags & SCEGMO_MESH_HAS_SUBDIV ) ) return 0 ;
 return &( mesh->m_subdiv ) ;
}
static __inline__ int _sceGmoMeshGetBlendSubsetCount( SceGmoMesh *mesh )
{
 return mesh->m_n_blend_subset ;
}
static __inline__ const int *_sceGmoMeshGetBlendSubset( SceGmoMesh *mesh )
{
 return mesh->m_blend_subset ;
}
static __inline__ int _sceGmoMeshGetBoundingPointsCount( SceGmoMesh *mesh )
{
 SceGmoBoundingPoints *bpts = mesh->m_bounding_points ;
 return ( bpts == 0 ) ? 0 : bpts->n_points ;
}
static __inline__ const SceGmoVec3F *_sceGmoMeshGetBoundingPoints( SceGmoMesh *mesh )
{
 SceGmoBoundingPoints *bpts = mesh->m_bounding_points ;
 return ( bpts == 0 ) ? 0 : bpts->points ;
}
static __inline__ int _sceGmoMeshGetEnableBits( SceGmoMesh *mesh )
{
 return mesh->m_enable_bits ;
}
static __inline__ int _sceGmoMeshGetEnableMask( SceGmoMesh *mesh )
{
 return mesh->m_enable_mask ;
}
static __inline__ int _sceGmoMeshGetMeshMask( SceGmoMesh *mesh )
{
 return mesh->m_mesh_mask ;
}
enum {
 SCEGMO_MATERIAL_HAS_EXPLICIT_AMBIENT = 0x80000000,
 SCEGMO_MATERIAL_HAS_IMPLICIT_LAYERS = 0x00ff0000,
 SCEGMO_MATERIAL_HAS_IMPLICIT_DIFFUSE = 0x00010000,
 SCEGMO_MATERIAL_HAS_IMPLICIT_EMISSION = 0x00040000,
 SCEGMO_MATERIAL_HAS_IMPLICIT_REFLECTION = 0x00100000,
 SCEGMO_MATERIAL_HAS_DIFFUSE = 0x0001,
 SCEGMO_MATERIAL_HAS_SPECULAR = 0x0002,
 SCEGMO_MATERIAL_HAS_EMISSION = 0x0004,
 SCEGMO_MATERIAL_HAS_AMBIENT = 0x0008,
 SCEGMO_MATERIAL_HAS_REFLECTION = 0x0010,
 SCEGMO_MATERIAL_HAS_REFRACTION = 0x0020,
 SCEGMO_MATERIAL_HAS_BUMP = 0x0040,
 SCEGMO_MATERIAL_HAS_TEX_CROP = 0x0100,
 SCEGMO_MATERIAL_HAS_TEX_CROPS = 0xff00,
 SCEGMO_MATERIAL_MAX_LAYERS = 8
} ;
enum {
 SCEGMO_MATERIAL_COLOR_BLACK = 0,
 SCEGMO_MATERIAL_COLOR_DIFFUSE = 1,
 SCEGMO_MATERIAL_COLOR_SPECULAR = 2,
 SCEGMO_MATERIAL_COLOR_EMISSION = 3,
 SCEGMO_MATERIAL_COLOR_AMBIENT = 4,
 SCEGMO_MATERIAL_COLOR_REFLECTION = 5,
 SCEGMO_MATERIAL_COLOR_COUNT
} ;
enum {
 SCEGMO_MATERIAL_ANIM_MODIFIED = 0x0000ffff,
 SCEGMO_MATERIAL_ANIM_COMPLETE = 0xffff0000,
 SCEGMO_MATERIAL_CHAN_DIFFUSE = 0,
 SCEGMO_MATERIAL_CHAN_SPECULAR = 1,
 SCEGMO_MATERIAL_CHAN_EMISSION = 2,
 SCEGMO_MATERIAL_CHAN_AMBIENT = 3,
 SCEGMO_MATERIAL_CHAN_REFLECTION = 4,
 SCEGMO_MATERIAL_CHAN_COUNT
} ;
struct SceGmoMaterial {
 SceGmoBase m_base ;
 SceGmoMaterial *m_initial ;
 int m_reference ;
 int m_flags ;
 SceGmoLayer *m_layers[ SCEGMO_MATERIAL_MAX_LAYERS ] ;
 int m_n_layers ;
 int m_enable_mask ;
 int m_enable_bits ;
 SceGmoCol4 m_colors[ SCEGMO_MATERIAL_COLOR_COUNT ] ;
 float m_shininess ;
 float m_refraction ;
 float m_bump ;
 int m_anim_flags ;
 float m_anim_weights[ SCEGMO_MATERIAL_CHAN_COUNT ] ;
} ;
static __inline__ int _sceGmoMaterialGetFlags( SceGmoMaterial *material )
{
 return material->m_flags ;
}
static __inline__ SceGmoModel *_sceGmoMaterialGetParent( SceGmoMaterial *material )
{
 return (SceGmoModel *)_sceGmoBaseGetParent( &( material->m_base ) ) ;
}
static __inline__ int _sceGmoMaterialGetLayerCount( SceGmoMaterial *material )
{
 return material->m_n_layers ;
}
static __inline__ SceGmoLayer *_sceGmoMaterialGetLayer( SceGmoMaterial *material, int idx )
{
 idx = (0x0fff&(idx)) ;
 if ( idx >= material->m_n_layers ) return 0 ;
 return material->m_layers[ idx ] ;
}
static __inline__ SceGmoMaterial *_sceGmoMaterialGetInitialState( SceGmoMaterial *material )
{
 return material->m_initial ;
}
static __inline__ SceGmoCol4 _sceGmoMaterialGetDiffuse( SceGmoMaterial *material )
{
 return material->m_colors[ SCEGMO_MATERIAL_COLOR_DIFFUSE ] ;
}
static __inline__ SceGmoCol4 _sceGmoMaterialGetSpecular( SceGmoMaterial *material )
{
 return material->m_colors[ SCEGMO_MATERIAL_COLOR_SPECULAR ] ;
}
static __inline__ SceGmoCol4 _sceGmoMaterialGetEmission( SceGmoMaterial *material )
{
 return material->m_colors[ SCEGMO_MATERIAL_COLOR_EMISSION ] ;
}
static __inline__ SceGmoCol4 _sceGmoMaterialGetAmbient( SceGmoMaterial *material )
{
 return material->m_colors[ SCEGMO_MATERIAL_COLOR_AMBIENT ] ;
}
static __inline__ float _sceGmoMaterialGetReflection( SceGmoMaterial *material )
{
 return _sceGmoCol4GetA( material->m_colors + SCEGMO_MATERIAL_COLOR_REFLECTION ) ;
}
static __inline__ float _sceGmoMaterialGetShininess( SceGmoMaterial *material )
{
 return material->m_shininess ;
}
static __inline__ float _sceGmoMaterialGetRefraction( SceGmoMaterial *material )
{
 return material->m_refraction ;
}
static __inline__ float _sceGmoMaterialGetBump( SceGmoMaterial *material )
{
 return material->m_bump ;
}
static __inline__ int _sceGmoMaterialGetEnableBits( SceGmoMaterial *material )
{
 return material->m_enable_bits ;
}
static __inline__ int _sceGmoMaterialGetEnableMask( SceGmoMaterial *material )
{
 return material->m_enable_mask ;
}
enum {
 SCEGMO_LAYER_HAS_TEX_CROP = 0x0001
} ;
struct SceGmoLayer {
 SceGmoLayer *m_initial ;
 int m_reference ;
 int m_flags ;
 int m_map_type ;
 float m_map_factor ;
 int m_blend_func[ 3 ] ;
 int m_texture ;
 int m_enable_mask ;
 int m_enable_bits ;
 int m_diffuse ;
 int m_specular ;
 int m_ambient ;
 int m_tex_gen ;
 SceGmoMat4 *m_tex_matrix ;
 SceGmoRect m_tex_crop ;
} ;
static __inline__ int _sceGmoLayerGetFlags( SceGmoLayer *layer )
{
 return layer->m_flags ;
}
static __inline__ int _sceGmoLayerGetTexture( SceGmoLayer *layer )
{
 return layer->m_texture ;
}
static __inline__ int _sceGmoLayerGetMapType( SceGmoLayer *layer )
{
 return layer->m_map_type ;
}
static __inline__ float _sceGmoLayerGetMapFactor( SceGmoLayer *layer )
{
 return layer->m_map_factor ;
}
static __inline__ const int *_sceGmoLayerGetBlendFunc( SceGmoLayer *layer )
{
 return layer->m_blend_func ;
}
static __inline__ const SceGmoRect *_sceGmoLayerGetTexCrop( SceGmoLayer *layer )
{
 if ( !( layer->m_flags & SCEGMO_LAYER_HAS_TEX_CROP ) ) return 0 ;
 return &( layer->m_tex_crop ) ;
}
static __inline__ int _sceGmoLayerGetTexGen( SceGmoLayer *layer )
{
 return layer->m_tex_gen ;
}
static __inline__ const SceGmoMat4 *_sceGmoLayerGetTexMatrix( SceGmoLayer *layer )
{
 return layer->m_tex_matrix ;
}
static __inline__ int _sceGmoLayerGetEnableBits( SceGmoLayer *layer )
{
 return layer->m_enable_bits ;
}
static __inline__ int _sceGmoLayerGetEnableMask( SceGmoLayer *layer )
{
 return layer->m_enable_mask ;
}
struct SceGmoTexture {
 SceGmoBase m_base ;
 SceGimPicture *m_picture ;
 int m_reference ;
 int m_flags ;
} ;
static __inline__ int _sceGmoTextureGetFlags( SceGmoTexture *texture )
{
 return texture->m_flags ;
}
static __inline__ SceGmoModel *_sceGmoTextureGetParent( SceGmoTexture *texture )
{
 return (SceGmoModel *)_sceGmoBaseGetParent( &( texture->m_base ) ) ;
}
static __inline__ SceGimPicture *_sceGmoTextureGetPicture( SceGmoTexture *texture )
{
 return texture->m_picture ;
}
static __inline__ _Bool _sceGmoTextureHasAnimation( SceGmoTexture *texture )
{
 return sceGimPictureHasAnimation( texture->m_picture ) ;
}
struct SceGmoMotion {
 SceGmoBase m_base ;
 SceGmoChunk *m_chunk ;
 int m_reference ;
 int m_flags ;
 SceGmoChunk **m_anims ;
 SceGmoChunk **m_fcurves ;
 int m_n_anims ;
 int m_n_fcurves ;
 float m_frame_loop[ 2 ] ;
 float m_frame_rate ;
 int m_frame_repeat ;
 float m_frame ;
 float m_weight ;
} ;
static __inline__ int _sceGmoMotionGetFlags( SceGmoMotion *motion )
{
 return motion->m_flags ;
}
static __inline__ SceGmoModel *_sceGmoMotionGetParent( SceGmoMotion *motion )
{
 return (SceGmoModel *)_sceGmoBaseGetParent( &( motion->m_base ) ) ;
}
static __inline__ int _sceGmoMotionGetAnimationCount( SceGmoMotion *motion )
{
 return motion->m_n_anims ;
}
static __inline__ int _sceGmoMotionGetFCurveCount( SceGmoMotion *motion )
{
 return motion->m_n_fcurves ;
}
static __inline__ SceGmoChunk *_sceGmoMotionGetAnimation( SceGmoMotion *motion, int idx )
{
 idx = (0x0fff&(idx)) ;
 if ( idx >= motion->m_n_anims ) return 0 ;
 return motion->m_anims[ idx ] ;
}
static __inline__ SceGmoChunk *_sceGmoMotionGetFCurve( SceGmoMotion *motion, int idx )
{
 idx = (0x0fff&(idx)) ;
 if ( idx >= motion->m_n_fcurves ) return 0 ;
 return motion->m_fcurves[ idx ] ;
}
static __inline__ const float *_sceGmoMotionGetFrameLoop( SceGmoMotion *motion )
{
 return motion->m_frame_loop ;
}
static __inline__ float _sceGmoMotionGetFrameRate( SceGmoMotion *motion )
{
 return motion->m_frame_rate ;
}
static __inline__ int _sceGmoMotionGetFrameRepeat( SceGmoMotion *motion )
{
 return motion->m_frame_repeat ;
}
static __inline__ float _sceGmoMotionGetFrame( SceGmoMotion *motion )
{
 return motion->m_frame ;
}
static __inline__ float _sceGmoMotionGetWeight( SceGmoMotion *motion )
{
 return motion->m_weight ;
}
_Bool sceGmoModelAllocPtr( void *ptr_ptr, int size ) ;
_Bool sceGmoModelAllocPtr2( void *ptr_ptr, int size ) ;
_Bool sceGmoModelCopyPtr( void *ptr_ptr, const void *src, int size ) ;
_Bool sceGmoModelCopyPtr2( void *ptr_ptr, const void *src, int size ) ;
static int eval_half_fcurve( const SceGmoChunk *chunk, float frame, float *output ) ;
static float half_to_float( int val ) ;
static float extrap_frame( float frame, float start, float end, int extrap ) ;
static float find_root( float f0, float f1, float f2, float f3, float frame ) ;

SceGmoVec3 *sceGmoVec3Set( SceGmoVec3 *dst, float x, float y, float z )
{
 dst->x = x ;
 dst->y = y ;
 dst->z = z ;
 return dst ;
}

SceGmoVec4 *sceGmoVec4Set( SceGmoVec4 *dst, float x, float y, float z, float w )
{
 dst->x = x ;
 dst->y = y ;
 dst->z = z ;
 dst->w = w ;
 return dst ;
}

SceGmoMat4 *sceGmoMat4Set( SceGmoMat4 *dst, float tx, float ty, float tz, float sx, float sy, float sz )
{
 dst->x.x = sx ; dst->x.y = 0 ; dst->x.z = 0 ; dst->x.w = 0 ;
 dst->y.x = 0 ; dst->y.y = sy ; dst->y.z = 0 ; dst->y.w = 0 ;
 dst->z.x = 0 ; dst->z.y = 0 ; dst->z.z = sz ; dst->z.w = 0 ;
 dst->w.x = tx ; dst->w.y = ty ; dst->w.z = tz ; dst->w.w = 1 ;
 return dst ;
}

SceGmoQuat *sceGmoQuatSet( SceGmoQuat *dst, float x, float y, float z, float w )
{
 dst->x = x ;
 dst->y = y ;
 dst->z = z ;
 dst->w = w ;
 return dst ;
}

SceGmoRect *sceGmoRectSet( SceGmoRect *dst, float x, float y, float w, float h )
{
 dst->x = x ;
 dst->y = y ;
 dst->w = w ;
 dst->h = h ;
 return dst ;
}

SceGmoCol4 *sceGmoCol4Set( SceGmoCol4 *dst, float r, float g, float b, float a )
{
	unsigned int r2 = (unsigned int)( r * 255.0f ) ;
	unsigned int g2 = (unsigned int)( g * 255.0f ) ;
	unsigned int b2 = (unsigned int)( b * 255.0f ) ;
	unsigned int a2 = (unsigned int)( a * 255.0f ) ;
	*dst = ( a2 << 24 ) | ( b2 << 16 ) | ( g2 << 8 ) | r2 ;
	return dst ;
}

SceGmoVec3 *sceGmoVec3Load( SceGmoVec3 *dst, const SceGmoVec3F *src )
{
 return sceGmoVec3Set( dst, src->x, src->y, src->z ) ;
}

SceGmoVec4 *sceGmoVec4Load( SceGmoVec4 *dst, const SceGmoVec4F *src )
{
 return sceGmoVec4Set( dst, src->x, src->y, src->z, src->w ) ;
}

SceGmoMat4 *sceGmoMat4Load( SceGmoMat4 *dst, const SceGmoMat4F *src )
{
 sceGmoVec4Load( &( dst->x ), &( src->x ) ) ;
 sceGmoVec4Load( &( dst->y ), &( src->y ) ) ;
 sceGmoVec4Load( &( dst->z ), &( src->z ) ) ;
 sceGmoVec4Load( &( dst->w ), &( src->w ) ) ;
 return dst ;
}

SceGmoQuat *sceGmoQuatLoad( SceGmoQuat *dst, const SceGmoQuatF *src )
{
 return sceGmoQuatSet( dst, src->x, src->y, src->z, src->w ) ;
}

SceGmoRect *sceGmoRectLoad( SceGmoRect *dst, const SceGmoRectF *src )
{
 return sceGmoRectSet( dst, src->x, src->y, src->w, src->h ) ;
}

SceGmoCol4 *sceGmoCol4Load( SceGmoCol4 *dst, const SceGmoCol4F *src )
{
 return sceGmoCol4Set( dst, src->r, src->g, src->b, src->a ) ;
}

SceGmoMat4 *sceGmoMat4Multiply( SceGmoMat4 *dst, const SceGmoMat4 *src1, const SceGmoMat4 *src2 )
{
 SceGmoMat4 tmp ;
 if ( src1 == dst ) {
  tmp = *src1 ;
  src1 = &tmp ;
 }
 const SceGmoVec4 *sv = &( src2->x ) ;
 SceGmoVec4 *dv = &( dst->x ) ;
 { int i ; for ( i = 0 ; i < 4 ; i ++ ) {
  float x = sv->x ;
  float y = sv->y ;
  float z = sv->z ;
  float w = sv->w ;
  dv->x = src1->x.x * x + src1->y.x * y + src1->z.x * z + src1->w.x * w ;
  dv->y = src1->x.y * x + src1->y.y * y + src1->z.y * z + src1->w.y * w ;
  dv->z = src1->x.z * x + src1->y.z * y + src1->z.z * z + src1->w.z * w ;
  dv->w = src1->x.w * x + src1->y.w * y + src1->z.w * z + src1->w.w * w ;
  sv ++ ;
  dv ++ ;
 } }
 return dst ;
}

SceGmoMat4 *sceGmoMat4Scale( SceGmoMat4 *dst, const SceGmoMat4 *src1, const SceGmoVec3 *src2 )
{
 float x = src2->x ;
 float y = src2->y ;
 float z = src2->z ;
 dst->x.x = src1->x.x * x ;
 dst->x.y = src1->x.y * x ;
 dst->x.z = src1->x.z * x ;
 dst->y.x = src1->y.x * y ;
 dst->y.y = src1->y.y * y ;
 dst->y.z = src1->y.z * y ;
 dst->z.x = src1->z.x * z ;
 dst->z.y = src1->z.y * z ;
 dst->z.z = src1->z.z * z ;
 if ( dst != src1 ) {
  dst->x.w = src1->x.w ;
  dst->y.w = src1->y.w ;
  dst->z.w = src1->z.w ;
  dst->w.x = src1->w.x ;
  dst->w.y = src1->w.y ;
  dst->w.z = src1->w.z ;
  dst->w.w = src1->w.w ;
 }
 return dst ;
}

float *sceGmoFloatLerp( float *dst, const float *src1, const float *src2, int count, float f )
{
 if ( f >= 1.0f ) return (float *)memcpy( dst, src2, sizeof( float ) * count ) ;
 if ( f <= 0.0f ) return (float *)memcpy( dst, src1, sizeof( float ) * count ) ;
 float *dp = dst ;
 { int i ; for ( i = 0 ; i < count ; i ++ ) {
  float a = *( src1 ++ ) ;
  float b = *( src2 ++ ) ;
  *( dp ++ ) = ( b - a ) * f + a ;
 } }
 return dst ;
}

SceGmoMat4 *sceGmoMat4FromQuat( SceGmoMat4 *dst, const SceGmoQuat *src )
{
 float x = src->x ;
 float y = src->y ;
 float z = src->z ;
 float w = src->w ;
 dst->x.x = 1 - 2 * y * y - 2 * z * z ;
 dst->x.y = 2 * x * y + 2 * w * z ;
 dst->x.z = 2 * z * x - 2 * w * y ;
 dst->x.w = 0 ;
 dst->y.x = 2 * x * y - 2 * w * z ;
 dst->y.y = 1 - 2 * x * x - 2 * z * z ;
 dst->y.z = 2 * y * z + 2 * w * x ;
 dst->y.w = 0 ;
 dst->z.x = 2 * z * x + 2 * w * y ;
 dst->z.y = 2 * y * z - 2 * w * x ;
 dst->z.z = 1 - 2 * x * x - 2 * y * y ;
 dst->z.w = 0 ;
 dst->w.x = 0 ;
 dst->w.y = 0 ;
 dst->w.z = 0 ;
 dst->w.w = 1 ;
 return dst ;
}

SceGmoQuat *sceGmoQuatFromRotZYX( SceGmoQuat *dst, const SceGmoVec3 *src )
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

SceGmoQuat *sceGmoQuatFromRotYXZ( SceGmoQuat *dst, const SceGmoVec3 *src )
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

float acosf( float ) ;
float sinf( float ) ;
SceGmoQuat *sceGmoQuatSlerp( SceGmoQuat *dst, const SceGmoQuat *src1, const SceGmoQuat *src2, float f )
{
	float c, angle, s, r1, r2 ;
	int neg ;
	if ( f >= 1.0f ) { *dst = *src2 ; return dst ; }
	if ( f <= 0.0f ) { *dst = *src1 ; return dst ; }
	c = src1->x * src2->x + src1->y * src2->y + src1->z * src2->z + src1->w * src2->w ;
	neg = 0 ;
	if ( c < 0.0f ) { c = -c ; neg = 1 ; }
	if ( !( c < 1.0f ) ) { *dst = *src2 ; return dst ; }
	angle = acosf( c ) ;
	s = sinf( angle ) ;
	if ( s == 0.0f ) { *dst = *src2 ; return dst ; }
	r1 = sinf( ( 1.0f - f ) * angle ) / s ;
	r2 = sinf( f * angle ) / s ;
	if ( neg ) r2 = -r2 ;
	dst->x = src1->x * r1 + src2->x * r2 ;
	dst->y = src1->y * r1 + src2->y * r2 ;
	dst->z = src1->z * r1 + src2->z * r2 ;
	dst->w = src1->w * r1 + src2->w * r2 ;
	return dst ;
}

SceGmoVec4 *sceGmoVec4FromCol4( SceGmoVec4 *dst, const SceGmoCol4 *src )
{
 dst->x = _sceGmoCol4GetR( src ) ;
 dst->y = _sceGmoCol4GetG( src ) ;
 dst->z = _sceGmoCol4GetB( src ) ;
 dst->w = _sceGmoCol4GetA( src ) ;
 return dst ;
}

SceGmoCol4 *sceGmoCol4FromVec4( SceGmoCol4 *dst, const SceGmoVec4 *src )
{
	return sceGmoCol4Set( dst, src->x, src->y, src->z, src->w ) ;
}

int sceGmoCol4IsBlack( const SceGmoCol4 *src )
{
	return ( ( *src & 0x00ffffff ) == 0 ) ;
}

int sceGmoCol4IsHollow( const SceGmoCol4 *src )
{
	return ( ( *src & 0xff000000 ) == 0 ) ;
}

void sceGmoBoneAffineMatrix( SceGmoMat4 *m, const SceGmoVec3 *translate, const SceGmoQuat *rotate, const SceGmoVec3 *scale, int flags )
{
 if ( flags & SCEGMO_BONE_HAS_ROTATE ) {
  sceGmoMat4FromQuat( m, rotate ) ;
 } else {
  sceGmoMat4Set( m, 0, 0, 0, 1, 1, 1 ) ;
 }
 if ( flags & SCEGMO_BONE_HAS_SCALE_1 ) {
  sceGmoMat4Scale( m, m, scale ) ;
 }
 if ( flags & SCEGMO_BONE_HAS_TRANSLATE ) {
  m->w.x = translate->x ;
  m->w.y = translate->y ;
  m->w.z = translate->z ;
 }
}

int sceGmoBoneStackScale( SceGmoMat4 *m, SceGmoVec3 *sscale, const SceGmoVec3 *lscale, int flags, const SceGmoVec3 *sscale2, const SceGmoVec3 *lscale2, int flags2 )
{
 flags &= ~SCEGMO_BONE_IS_SCALE_STACKED ;
 float x, y, z ;
 if ( flags2 & SCEGMO_BONE_IS_SCALE_STACKED ) {
  flags |= SCEGMO_BONE_IS_SCALE_STACKED ;
  m->w.x *= ( x = sscale2->x ) ;
  m->w.y *= ( y = sscale2->y ) ;
  m->w.z *= ( z = sscale2->z ) ;
 } else {
  x = y = z = 1 ;
 }
 if ( flags & ( SCEGMO_BONE_HAS_SCALE_2 | SCEGMO_BONE_HAS_SCALE_3 ) ) {
  flags |= SCEGMO_BONE_IS_SCALE_STACKED ;
  x *= lscale->x ;
  y *= lscale->y ;
  z *= lscale->z ;
 }
 if ( flags2 & SCEGMO_BONE_HAS_SCALE_3 ) {
  if ( lscale2->x != 0.0f ) x /= lscale2->x ;
  if ( lscale2->y != 0.0f ) y /= lscale2->y ;
  if ( lscale2->z != 0.0f ) z /= lscale2->z ;
 }
 sscale->x = x ;
 sscale->y = y ;
 sscale->z = z ;
 return flags ;
}

extern SceGmoMat4 D_00083710;
void sceGmoBoneApplyPivot( SceGmoMat4 *m, const SceGmoVec3 *pivot, const SceGmoVec3 *sscale, const SceGmoVec3 *sscale2 )
{
	SceGmoMat4 tmp ;
	D_00083710.w.x = pivot->x * sscale->x ;
	D_00083710.w.y = pivot->y * sscale->y ;
	D_00083710.w.z = pivot->z * sscale->z ;
	sceGmoMat4Multiply( &tmp, &D_00083710, m ) ;
	D_00083710.w.x = - D_00083710.w.x ;
	D_00083710.w.y = - D_00083710.w.y ;
	D_00083710.w.z = - D_00083710.w.z ;
	sceGmoMat4Multiply( m, &tmp, &D_00083710 ) ;
}
