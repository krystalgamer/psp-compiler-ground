#include "common.h"
#define complement_animation complement_animation_5CAE0

/* declarations recovered from DWARF (UTST99332 graphics_model gmo_material) */
typedef struct SceGmoChunk SceGmoChunk;
struct SceGmoChunk;
struct SceGmoChunk { /* size 0x10 */
    short unsigned int type;
    short unsigned int args_offs;
    unsigned int next_offs;
    unsigned int child_offs;
    unsigned int data_offs;
};
typedef struct SceGmoMaterial SceGmoMaterial;
struct SceGmoMaterial;
typedef struct SceGmoBase SceGmoBase;
struct SceGmoBase;
struct SceGmoSubject;
struct SceGmoObserver;
struct SceGmoObserver { /* size 0xc */
    struct SceGmoObserver *m_next;
    struct SceGmoSubject *m_subject;
    void *m_reserved;
};
struct SceGmoSubject { /* size 0x4 */
    struct SceGmoObserver *m_observers;
};
struct SceGmoBase { /* size 0x10 */
    struct SceGmoSubject m_subject;
    struct SceGmoObserver m_parent;
};
typedef struct SceGmoLayer SceGmoLayer;
struct SceGmoLayer;
typedef struct ScePspFRect ScePspFRect;
struct ScePspFRect;
struct ScePspFRect { /* size 0x10 */
    float x;
    float y;
    float w;
    float h;
};
struct SceGmoLayer { /* size 0x60 (gmo_model 1.5.0: material cache) */
    SceGmoLayer *m_initial;
    int m_reference;
    int m_flags;
    void *m_cache;
    int m_map_type;
    float m_map_factor;
    int m_blend_func[5];
    int m_texture;
    int m_enable_mask;
    int m_enable_bits;
    int m_diffuse;
    int m_specular;
    int m_ambient;
    int m_unk44[3];
    ScePspFRect m_tex_crop;
};
struct SceGmoMaterial { /* size 0x84 */
    SceGmoBase m_base;
    SceGmoMaterial *m_initial;
    int m_reference;
    int m_flags;
    SceGmoLayer *m_layers[8];
    int m_n_layers;
    int m_enable_mask;
    int m_enable_bits;
    int m_colors[6];
    float m_shininess;
    float m_refraction;
    float m_bump;
    int m_anim_flags;
    float m_anim_weights[5];
};
struct _anon1;
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
struct _anon1 { /* size 0x20 */
    ScePspFVector4 color;
    float shininess;
};
typedef struct _anon1 SceGmoSpecular;
struct _anon2;
struct _anon2 { /* size 0x10 */
    ScePspFVector4 color;
};
typedef struct _anon2 SceGmoDiffuse;
struct _anon3;
struct _anon3 { /* size 0x8 */
    int state;
    int value;
};
typedef struct _anon3 SceGmoRenderState;
struct _anon4;
struct _anon4 { /* size 0x4 */
    float bump;
};
typedef struct _anon4 SceGmoBump;
struct _anon5;
struct _anon5 { /* size 0x4 */
    float refraction;
};
typedef struct _anon5 SceGmoRefraction;
struct _anon6;
struct _anon6 { /* size 0x10 */
    ScePspFVector4 color;
};
typedef struct _anon6 SceGmoAmbient;
struct _anon7;
struct _anon7 { /* size 0x4 */
    float reflection;
};
typedef struct _anon7 SceGmoReflection;
struct _anon8;
struct _anon8 { /* size 0x10 */
    ScePspFVector4 color;
};
typedef struct _anon8 SceGmoEmission;
typedef struct SceGmoModel SceGmoModel;
struct SceGmoModel;
typedef struct SceGmoBone SceGmoBone;
struct SceGmoBone;
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFQuaternion ScePspFQuaternion;
struct ScePspFQuaternion;
struct ScePspFQuaternion { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct ScePspFMatrix4;
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
struct SceGmoBone { /* size 0x170 */
    SceGmoBase m_base;
    SceGmoBone *m_initial;
    int m_reference;
    int m_flags;
    int m_parent_bone;
    int m_visibility;
    ScePspFVector3 m_pivot;
    ScePspFVector3 m_translate;
    ScePspFQuaternion m_rotate;
    ScePspFVector3 m_scale;
    ScePspFMatrix4 m_local_matrix;
    ScePspFMatrix4 m_stack_matrix;
    ScePspFVector3 m_stack_scale;
    ScePspFMatrix4 m_world_matrix;
    int *m_draw_parts;
    float *m_morph_weights;
    int *m_blend_bones;
    ScePspFMatrix4 *m_blend_offsets;
    int m_n_draw_parts;
    int m_n_morph_weights;
    int m_n_blend_bones;
    int m_n_blend_offsets;
    int m_anim_flags;
    float m_anim_weights[5];
};
typedef struct SceGmoPart SceGmoPart;
struct SceGmoPart;
typedef struct SceGmoMesh SceGmoMesh;
struct SceGmoMesh;
struct SceGmoMesh { /* size 0x18 */
    SceGmoChunk *m_chunk;
    int m_reference;
    int m_flags;
    int m_material;
    int *m_blend_subset;
    int m_n_blend_subset;
};
struct SceGmoPart { /* size 0x2c */
    SceGmoBase m_base;
    SceGmoChunk *m_chunk;
    int m_reference;
    int m_flags;
    SceGmoMesh **m_meshes;
    SceGmoChunk **m_arrays;
    int m_n_meshes;
    int m_n_arrays;
};
typedef struct SceGmoTexture SceGmoTexture;
struct SceGmoTexture;
typedef struct SceGimPicture SceGimPicture;
struct SceGimPicture;
struct SceGmoTexture { /* size 0x1c */
    SceGmoBase m_base;
    SceGimPicture *m_picture;
    int m_reference;
    int m_flags;
};
typedef struct SceGmoMotion SceGmoMotion;
struct SceGmoMotion;
struct SceGmoMotion { /* size 0x40 */
    SceGmoBase m_base;
    SceGmoChunk *m_chunk;
    int m_reference;
    int m_flags;
    SceGmoChunk **m_anims;
    SceGmoChunk **m_fcurves;
    int m_n_anims;
    int m_n_fcurves;
    float m_frame_loop[2];
    float m_frame_rate;
    float m_frame;
    float m_weight;
};
struct SceGmoModel { /* size 0x100 */
    SceGmoBase m_base;
    int m_reference;
    int m_flags;
    SceGmoBone **m_bones;
    SceGmoPart **m_parts;
    SceGmoMaterial **m_materials;
    SceGmoTexture **m_textures;
    SceGmoMotion **m_motions;
    int m_n_bones;
    int m_n_parts;
    int m_n_materials;
    int m_n_textures;
    int m_n_motions;
    int m_current_motion;
    float m_change_motion;
    ScePspFMatrix4 m_world_matrix;
    int m_enable_bits;
    int m_enable_mask;
    ScePspFVector3 m_bounding_box[2];
    ScePspFMatrix4 m_vertex_offset;
    ScePspFRect m_texcoord_offset;
};
typedef struct SceGmoSubject SceGmoSubject;
typedef ScePspFVector4 vec4;
typedef ScePspFRect rect;
struct _anon9;
struct _anon9 { /* size 0x4 */
    int type;
};
typedef struct _anon9 SceGmoMapType;
struct _anon10;
struct _anon10 { /* size 0x4 */
    int texture;
};
typedef struct _anon10 SceGmoSetTexture;
struct _anon11;
struct _anon11 { /* size 0x10 */
    ScePspFRect crop;
};
typedef struct _anon11 SceGmoTexCrop;
struct _anon12;
struct _anon12 { /* size 0xc */
    int mode;
    int src;
    int dst;
};
typedef struct _anon12 SceGmoBlendFunc;



SceGmoMaterial *sceGmoMaterialCreate(const SceGmoChunk *chunk);
void sceGmoMaterialDelete(SceGmoMaterial *material);
SceGmoMaterial *sceGmoMaterialDuplicate(SceGmoMaterial *material, int flags);
_Bool sceGmoMaterialLoad(SceGmoMaterial *material, const SceGmoChunk *chunk);
static __inline__ int SCEGMO_CHUNK_TYPE( const SceGmoChunk *chunk )
{
 return ( ~0x8000 & chunk->type ) ;
}
static __inline__ SceGmoChunk *SCEGMO_CHUNK_NEXT( const SceGmoChunk *chunk )
{
 return (SceGmoChunk *)( (char *)chunk + chunk->next_offs ) ;
}
static __inline__ SceGmoChunk *SCEGMO_CHUNK_CHILD( const SceGmoChunk *chunk )
{
 if ( 0x8000 & chunk->type ) return SCEGMO_CHUNK_NEXT( chunk ) ;
 return (SceGmoChunk *)( (char *)chunk + chunk->child_offs ) ;
}
static __inline__ void *SCEGMO_CHUNK_ARGS( const SceGmoChunk *chunk )
{
 if ( 0x8000 & chunk->type ) return (char *)chunk + 8 ;
 return (char *)chunk + chunk->args_offs ;
}
void sceGmoMaterialUnload(SceGmoMaterial *material);
void sceGmoMaterialUpdate(SceGmoMaterial *material, SceGmoModel *model);
int sceGmoMaterialActivate(SceGmoMaterial *material, SceGmoModel *model, int idx);
static SceGmoSubject *sceGmoBaseGetParent(const SceGmoBase *base);
void sceGmoMaterialAnimate(SceGmoMaterial *material, int type, int idx, const float *val, int cnt, float weight);
void sceGmoMaterialSetParent(SceGmoMaterial *material, SceGmoModel *parent);
SceGmoModel *sceGmoMaterialGetParent(SceGmoMaterial *material);
int sceGmoMaterialGetLayerCount(SceGmoMaterial *material);
SceGmoLayer *sceGmoMaterialGetLayer(SceGmoMaterial *material, int idx);
static void complement_animation(SceGmoMaterial *material);
static _Bool reconfigure_material(SceGmoMaterial *material);
SceGmoLayer *sceGmoLayerCreate(const SceGmoChunk *chunk);
void sceGmoLayerDelete(SceGmoLayer *layer);
SceGmoLayer *sceGmoLayerDuplicate(SceGmoLayer *layer, int flags);
_Bool sceGmoLayerLoad(SceGmoLayer *layer, const SceGmoChunk *chunk);
void sceGmoLayerUnload(SceGmoLayer *layer);
int sceGmoLayerActivate(SceGmoLayer *layer, SceGmoModel *model, SceGmoMaterial *material);
void sceGmoLayerSetMapType(SceGmoLayer *layer, int type);
int sceGmoLayerGetMapType(SceGmoLayer *layer);
void sceGmoLayerSetTexCrop(SceGmoLayer *layer, const rect *crop);
const struct ScePspFRect *sceGmoLayerGetTexCrop(SceGmoLayer *layer);
static _Bool reconfigure_layer(SceGmoLayer *layer);
static vec4 *vec4_col32(vec4 *dst, unsigned int src);
static unsigned int col32_vec4(const vec4 *src);
static unsigned int col32_lerp(unsigned int src1, unsigned int src2, float rate);
static float *float_lerp(float *dst, const float *src1, const float *src2, int dim, float rate);
void sceGmoLayerUnloadCache( SceGmoLayer *layer ) ;
ScePspFRect *sceGmoRectSet( ScePspFRect *r, float x, float y, float w, float h ) ;
void sceGuCallList( const void *list ) ;
vec4 *sceGmoVec4FromCol4( vec4 *dst, const int *src ) ;
void sceGmoMaterialControl( SceGmoMaterial *material, int type, int idx, const float *val, int cnt, float weight ) ;
int sceGmoCol4IsBlack( const int *col ) ;
int sceGmoCol4IsHollow( const int *col ) ;
void sceGmoBaseCopy( SceGmoBase *dst, const SceGmoBase *src ) ;
ScePspFRect *sceGmoRectLoad( ScePspFRect *dst, const void *src ) ;
void sceGmoBaseConstruct( SceGmoBase *base ) ;
unsigned int *sceGmoCol4Set( unsigned int *dst, float r, float g, float b, float a ) ;
SceGmoTexture *sceGmoModelGetTexture( SceGmoModel *model, int index ) ;
void sceGmoContextSetTexture( SceGmoTexture *texture, SceGmoModel *model ) ;
void sceGmoContextSetTexCrop( const rect *crop ) ;
void sceGmoContextSetEnableBits( int mask, int bits ) ;
_Bool sceGmoLayerLoadCache( SceGmoLayer *layer, SceGmoMaterial *material ) ;
void sceGmoModelFreeMemory2( void *addr ) ;
void *sceGmoModelAllocUncachedBuffer( void *ptr_ptr, int size ) ;
void sceGuStart( int cid, void *list, int size ) ;
int sceGuFinish( void ) ;
void sceGuMaterial( int mode, unsigned int color ) ;
void sceGuSpecular( float power ) ;
void sceGuBlendFunc( int op, int src, int dst, unsigned int srcfix, unsigned int destfix ) ;

extern const signed char D_000836FC[] ;
SceGmoMaterial *sceGmoMaterialCreate( const SceGmoChunk *chunk )
{
	SceGmoMaterial *material = (SceGmoMaterial *)sceGmoModelAllocMemory( sizeof( SceGmoMaterial ) ) ;
	if ( material == 0 ) {
		return 0 ;
	}
	sceGmoBaseConstruct( &( material->m_base ) ) ;
	material->m_initial = 0 ;
	material->m_reference = 1 ;
	material->m_flags = 0 ;

	material->m_n_layers = 0 ;

	material->m_enable_mask = 0 ;
	material->m_enable_bits = 0 ;
	sceGmoCol4Set( (unsigned int *)&( material->m_colors[ 0 ] ), 0, 0, 0, 1 ) ;
	sceGmoCol4Set( (unsigned int *)&( material->m_colors[ 2 ] ), 0, 0, 0, 1 ) ;
	sceGmoCol4Set( (unsigned int *)&( material->m_colors[ 3 ] ), 0, 0, 0, 1 ) ;
	sceGmoCol4Set( (unsigned int *)&( material->m_colors[ 1 ] ), 1, 1, 1, 1 ) ;
	sceGmoCol4Set( (unsigned int *)&( material->m_colors[ 4 ] ), 1, 1, 1, 1 ) ;
	sceGmoCol4Set( (unsigned int *)&( material->m_colors[ 5 ] ), 1, 1, 1, 0 ) ;
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
 if ( !( 0x0001 & flags )
   && !( 0x0100 & flags )
   && !( 0x0200 & flags ) ) {
  material->m_reference ++ ;
  return material ;
 }

 SceGmoMaterial *material2 = sceGmoMaterialCreate( 0 ) ;
 if ( material2 == 0 ) return 0 ;
 sceGmoBaseCopy( &( material2->m_base ), &( material->m_base ) ) ;

 flags &= ~0x0001 ;
 flags |= 0x0002 ;
 { int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
  SceGmoLayer *src = material->m_layers[ i ] ;
  SceGmoLayer *dst = sceGmoLayerDuplicate( src, flags ) ;
  if ( dst == 0 && src != 0 ) {
   sceGmoMaterialDelete( material2 ) ;
   return 0 ;
  }
  material2->m_layers[ material2->m_n_layers ++ ] = dst ;
 } }
 material2->m_initial = sceGmoMaterialDuplicate( material->m_initial, 0 ) ;
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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", sceGmoMaterialLoad);

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

_Bool sceGmoMaterialLoadCache( SceGmoMaterial *material )
{
	if ( material == 0 ) return 0 ;
	{ int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
		if ( !sceGmoLayerLoadCache( material->m_layers[ i ], material ) ) return 0 ;
	} }
	return 1 ;
}

void sceGmoMaterialUnloadCache( SceGmoMaterial *material )
{
	if ( material == 0 ) return ;
	{ int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
		sceGmoLayerUnloadCache( material->m_layers[ i ] ) ;
	} }
}

void sceGmoMaterialUpdate(SceGmoMaterial *material, SceGmoModel *model) {
    if (material != NULL) {
        complement_animation( material );
    }
}

int sceGmoMaterialActivate( SceGmoMaterial *material, SceGmoModel *model, int index )
{
	if ( material == 0 ) return 0 ;
	if ( index >= material->m_n_layers ) return 0 ;

	SceGmoSubject *parent = material->m_base.m_parent.m_subject ;
	if ( parent != 0 ) model = (SceGmoModel *)parent ;

	return sceGmoLayerActivate( material->m_layers[ index ], model, material ) ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", sceGmoMaterialControl);

void sceGmoMaterialSetParent(SceGmoMaterial *material, SceGmoModel *parent) {
    if (material != NULL) {
        sceGmoBaseSetParent();
    }
}

SceGmoModel *sceGmoMaterialGetParent(SceGmoMaterial *material) {
    SceGmoSubject *var_v0;

    var_v0 = NULL;
    if (material != NULL) {
        var_v0 = material->m_base.m_parent.m_subject;
    }
    return (SceGmoModel *) var_v0;
}

int sceGmoMaterialGetLayerCount(SceGmoMaterial *material) {
    int var_v0;

    var_v0 = 0;
    if (material != NULL) {
        var_v0 = material->m_n_layers;
    }
    return var_v0;
}

SceGmoLayer *sceGmoMaterialGetLayer( SceGmoMaterial *material, int index )
{
 if ( material == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= material->m_n_layers ) return 0 ;
 return material->m_layers[ index ] ;
}

static void complement_animation( SceGmoMaterial *material )
{
	int flags = material->m_anim_flags ;
	int reset = 0xffff0000 ;
	int modified = ( flags & 0x0000ffff ) ;
	int complete = ( flags & 0xffff0000 ) >> 16 ;
	int incomplete = modified & ~complete ;
	if ( incomplete ) {
		float val[ 5 ] ;
		SceGmoMaterial *initial = material->m_initial ;
		if ( incomplete & 0x0001 ) {
			float w = 1.0f - material->m_anim_weights[ 0 ] ;
			sceGmoVec4FromCol4( (vec4 *)val, &( initial->m_colors[ 1 ] ) ) ;
			sceGmoMaterialControl( material, 0x82, 0, val, 4, w ) ;
			if ( w > 0.99f ) reset |= 0x0001 ;
		}
		if ( incomplete & 0x0002 ) {
			float w = 1.0f - material->m_anim_weights[ 1 ] ;
			sceGmoVec4FromCol4( (vec4 *)val, &( initial->m_colors[ 2 ] ) ) ;
			val[ 4 ] = initial->m_shininess ;
			sceGmoMaterialControl( material, 0x83, 0, val, 5, w ) ;
			if ( w > 0.99f ) reset |= 0x0002 ;
		}
		if ( incomplete & 0x0004 ) {
			float w = 1.0f - material->m_anim_weights[ 2 ] ;
			sceGmoVec4FromCol4( (vec4 *)val, &( initial->m_colors[ 3 ] ) ) ;
			sceGmoMaterialControl( material, 0x84, 0, val, 4, w ) ;
			if ( w > 0.99f ) reset |= 0x0004 ;
		}
		if ( incomplete & 0x0008 ) {
			float w = 1.0f - material->m_anim_weights[ 3 ] ;
			sceGmoVec4FromCol4( (vec4 *)val, &( initial->m_colors[ 4 ] ) ) ;
			sceGmoMaterialControl( material, 0x85, 0, val, 4, w ) ;
			if ( w > 0.99f ) reset |= 0x0008 ;
		}
		if ( incomplete & 0x0010 ) {
			float w = 1.0f - material->m_anim_weights[ 4 ] ;
			sceGmoVec4FromCol4( (vec4 *)val, &( initial->m_colors[ 5 ] ) ) ;
			sceGmoMaterialControl( material, 0x86, 0, val + 3, 1, w ) ;
			if ( w > 0.99f ) reset |= 0x0010 ;
		}
		if ( incomplete & 0x0020 ) {
			material->m_refraction = initial->m_refraction ;
			reset |= 0x0020 ;
		}
		if ( incomplete & 0x0040 ) {
			material->m_bump = initial->m_bump ;
			reset |= 0x0040 ;
		}
		if ( incomplete & 0xff00 ) {
			{ int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
				if ( incomplete & ( 0x0100 << i ) ) {
					SceGmoLayer *layer1 = material->m_layers[ i ] ;
					SceGmoLayer *layer2 = layer1->m_initial ;
					const rect *crop = sceGmoLayerGetTexCrop( layer2 ) ;
					sceGmoLayerSetTexCrop( layer1, crop ) ;
					reset |= 0x0100 << i ;
				}
			} }
		}
	}
	material->m_anim_flags &= ~reset ;
	if ( modified ) {
		memset( material->m_anim_weights, 0, sizeof( material->m_anim_weights ) ) ;
	}
}

static _Bool reconfigure_material( SceGmoMaterial *material )
{
	if ( !( material->m_flags & 0x0001 ) ) {
		material->m_flags |= 0x0001 | 0x80000000 ;
		SceGmoLayer *layer = sceGmoLayerCreate( 0 ) ;
		if ( layer == 0 ) return 0 ;
		{ int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
			material->m_layers[ i + 1 ] = material->m_layers[ i ] ;
		} }
		material->m_layers[ 0 ] = layer ;
		material->m_n_layers ++ ;
	}
	if ( !sceGmoCol4IsBlack( &( material->m_colors[ 3 ] ) ) ) {
		if ( !( material->m_flags & 0x0004 ) ) {
			material->m_flags |= 0x0004 ;
			SceGmoLayer *layer = sceGmoLayerCreate( 0 ) ;
			if ( layer == 0 ) return 0 ;
			material->m_layers[ material->m_n_layers ++ ] = layer ;
			sceGmoLayerSetMapType( layer, 0x84 ) ;
		}
	}
	if ( !sceGmoCol4IsHollow( &( material->m_colors[ 5 ] ) ) ) {
		if ( !( material->m_flags & 0x0010 ) ) {
			material->m_flags |= 0x0010 ;
			SceGmoLayer *layer = sceGmoLayerCreate( 0 ) ;
			if ( layer == 0 ) return 0 ;
			material->m_layers[ material->m_n_layers ++ ] = layer ;
			sceGmoLayerSetMapType( layer, 0x86 ) ;
		}
	}

	SceGmoLayer *topmost = 0 ;
	{ int i ; for ( i = 0 ; i < material->m_n_layers ; i ++ ) {
		SceGmoLayer *layer = material->m_layers[ i ] ;
		if ( sceGmoLayerGetMapType( layer ) == 0x82 ) topmost = layer ;
	} }

	if ( topmost != 0 ) {
		int flags = material->m_flags ;
		if ( !( flags & 0x0002 ) ) {
			topmost->m_specular = 2 ;
			topmost->m_enable_mask |= 0x00010000 ;
			topmost->m_enable_bits |= 0x00010000 ;
		} else {
			topmost->m_specular = 0 ;
			topmost->m_enable_mask |= 0x00010000 ;
			topmost->m_enable_bits &= ~0x00010000 ;
		}
		if ( !( flags & 0x0008 ) ) {
			topmost->m_ambient = 4 ;
		} else {
			topmost->m_ambient = 0 ;
		}
	}
	return 1 ;
}

SceGmoLayer *sceGmoLayerCreate( const SceGmoChunk *chunk )
{
	SceGmoLayer *layer = (SceGmoLayer *)sceGmoModelAllocMemory( sizeof( SceGmoLayer ) ) ;
	if ( layer == 0 ) {
		return 0 ;
	}
	layer->m_initial = 0 ;
	layer->m_reference = 1 ;
	layer->m_flags = 0 ;
	layer->m_cache = 0 ;

	layer->m_map_type = 0x82 ;
	layer->m_map_factor = 1.0f ;
	layer->m_blend_func[ 0 ] = 0 ;
	layer->m_blend_func[ 1 ] = 2 ;
	layer->m_blend_func[ 2 ] = 3 ;
	layer->m_blend_func[ 3 ] = 0x00000000 ;
	layer->m_blend_func[ 4 ] = 0x00000000 ;
	layer->m_texture = -1 ;

	layer->m_enable_mask = 0 ;
	layer->m_enable_bits = 0 ;
	layer->m_diffuse = 1 ;
	layer->m_specular = 0 ;
	layer->m_ambient = 0 ;

	sceGmoRectSet( &( layer->m_tex_crop ), 0, 0, 1, 1 ) ;

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
 if ( !( 0x0001 & flags )
   && !( 0x0200 & flags ) ) {
  layer->m_reference ++ ;
  return layer ;
 }

 SceGmoLayer *layer2 = sceGmoLayerCreate( 0 ) ;
 if ( layer2 == 0 ) return 0 ;
 layer2->m_initial = sceGmoLayerDuplicate( layer->m_initial, 0 ) ;
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

_Bool sceGmoLayerLoad( SceGmoLayer *layer, const SceGmoChunk *chunk )
{
 if ( layer == 0 ) return 0 ;
 if ( chunk == 0 ) return 0 ;

 sceGmoLayerUnload( layer ) ;

 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  void *args = SCEGMO_CHUNK_ARGS( chunk ) ;

  switch ( SCEGMO_CHUNK_TYPE( chunk ) ) {
      case 0x0091 : {
   SceGmoSetTexture *cmd = (SceGmoSetTexture *)args ;
   layer->m_texture = cmd->texture ;
   break ;
      }
      case 0x0092 : {
   SceGmoMapType *cmd = (SceGmoMapType *)args ;
   sceGmoLayerSetMapType( layer, cmd->type ) ;
   break ;
      }
      case 0x0094 : {
      SceGmoBlendFunc *cmd = (SceGmoBlendFunc *)args ;
   layer->m_blend_func[ 0 ] = cmd->mode ;
   layer->m_blend_func[ 1 ] = D_000836FC[ cmd->src ] ;
   layer->m_blend_func[ 2 ] = D_000836FC[ cmd->dst ] ;
   layer->m_blend_func[ 3 ] = ( cmd->src == 0 ) ? 0 : 0xffffffff ;
   layer->m_blend_func[ 4 ] = ( cmd->dst == 0 ) ? 0 : 0xffffffff ;
   break ;
      }
      case 0x0098 : {
   SceGmoTexCrop *cmd = (SceGmoTexCrop *)args ;
   sceGmoRectLoad( &( layer->m_tex_crop ), &( cmd->crop ) ) ;
   layer->m_flags |= 1 ;
   break ;
      }
  }
 }

 layer->m_initial = sceGmoLayerDuplicate( layer, 0x0200 ) ;
 return ( layer->m_initial != 0 ) ;
}

void sceGmoLayerUnload( SceGmoLayer *layer )
{
	if ( layer == 0 ) return ;

	sceGmoLayerUnloadCache( layer ) ;
	sceGmoLayerDelete( layer->m_initial ) ;
	layer->m_initial = 0 ;
}

_Bool sceGmoLayerLoadCache( SceGmoLayer *layer, SceGmoMaterial *material )
{
	if ( layer == 0 || material == 0 ) return 0 ;
	if ( layer->m_cache != 0 ) return 1 ;
	void *cache = sceGmoModelAllocUncachedBuffer( &( layer->m_cache ), 0x2c ) ;
	if ( cache == 0 ) return 0 ;
	sceGuStart( 1, cache, 0x2c ) ;
	sceGuMaterial( 2, material->m_colors[ layer->m_diffuse ] ) ;
	sceGuMaterial( 4, material->m_colors[ layer->m_specular ] ) ;
	sceGuMaterial( 1, material->m_colors[ layer->m_ambient ] ) ;
	sceGuSpecular( material->m_shininess ) ;
	int *blend = layer->m_blend_func ;
	sceGuBlendFunc( blend[ 0 ], blend[ 1 ], blend[ 2 ], blend[ 3 ], blend[ 4 ] ) ;
	sceGuFinish() ;
	return 1 ;
}

void sceGmoLayerUnloadCache( SceGmoLayer *layer )
{
	if ( layer == 0 ) return ;
	sceGmoModelFreeMemory2( layer->m_cache ) ;
	layer->m_cache = 0 ;
}

int sceGmoLayerActivate( SceGmoLayer *layer, SceGmoModel *model, SceGmoMaterial *material )
{
	if ( layer == 0 ) return 0 ;
	if ( material == 0 ) return 0 ;
	int ambient = material->m_colors[ layer->m_ambient ] ;
	if ( ( 0xff000000 & ambient ) == 0 ) return 0 ;

	SceGmoTexture *texture = sceGmoModelGetTexture( model, layer->m_texture ) ;

	sceGmoContextSetTexture( texture, model ) ;

	rect *crop = !( layer->m_flags & 1 ) ? 0 : &( layer->m_tex_crop ) ;
	sceGmoContextSetTexCrop( crop ) ;

	int mask = layer->m_enable_mask | material->m_enable_mask ;
	int bits = layer->m_enable_bits | ( ~layer->m_enable_mask & material->m_enable_bits ) ;
	sceGmoContextSetEnableBits( mask, bits ) ;

	if ( layer->m_cache != 0 ) {
		sceGuCallList( layer->m_cache ) ;
	} else {
		sceGuMaterial( 2, material->m_colors[ layer->m_diffuse ] ) ;
		sceGuMaterial( 4, material->m_colors[ layer->m_specular ] ) ;
		sceGuMaterial( 1, ambient ) ;
		sceGuSpecular( material->m_shininess ) ;

		int *blend = layer->m_blend_func ;
		sceGuBlendFunc( blend[ 0 ], blend[ 1 ], blend[ 2 ], blend[ 3 ], blend[ 4 ] ) ;
	}

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
		layer->m_flags &= ~1 ;
	} else {
		layer->m_flags |= 1 ;
		layer->m_tex_crop = *crop ;
	}
}

const rect *sceGmoLayerGetTexCrop( SceGmoLayer *layer )
{
	if ( layer == 0 ) return 0 ;
	if ( !( layer->m_flags & 1 ) ) return 0 ;
	return &( layer->m_tex_crop ) ;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", D_0007EF5C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", D_0007EF78);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", D_0007EF98);

static _Bool reconfigure_layer( SceGmoLayer *layer )
{
	layer->m_blend_func[ 0 ] = 0 ;
	layer->m_blend_func[ 1 ] = 2 ;
	layer->m_blend_func[ 2 ] = 3 ;
	layer->m_blend_func[ 3 ] = 0xffffffff ;
	layer->m_blend_func[ 4 ] = 0xffffffff ;

	layer->m_diffuse = 0 ;
	layer->m_specular = 0 ;
	layer->m_ambient = 0 ;

	layer->m_enable_mask = 0x00010000 ;
	layer->m_enable_bits = 0 ;

	switch ( layer->m_map_type ) {
	    case 0x82 : {
		layer->m_blend_func[ 1 ] = 2 ;
		layer->m_blend_func[ 2 ] = 3 ;
		layer->m_diffuse = 1 ;
		break ;
	    }
	    case 0x83 : {
		layer->m_blend_func[ 1 ] = 2 ;
		layer->m_blend_func[ 2 ] = 10 ;
		layer->m_specular = 2 ;
		break ;
	    }
	    case 0x84 : {
		layer->m_blend_func[ 1 ] = 10 ;
		layer->m_blend_func[ 2 ] = 10 ;
		layer->m_ambient = 3 ;
		layer->m_enable_mask |= 0x0001 ;
		layer->m_enable_bits &= ~0x0001 ;
		break ;
	    }
	    case 0x85 : {
		layer->m_blend_func[ 1 ] = 2 ;
		layer->m_blend_func[ 2 ] = 10 ;
		layer->m_ambient = 4 ;
		break ;
	    }
	    case 0x86 : {
		layer->m_ambient = 5 ;
		layer->m_enable_mask |= 0x0001 ;
		layer->m_enable_bits &= ~0x0001 ;
		layer->m_enable_mask |= 0x00020000 ;
		layer->m_enable_bits |= 0x00020000 ;
		break ;
	    }
	}
	return 1 ;
}
