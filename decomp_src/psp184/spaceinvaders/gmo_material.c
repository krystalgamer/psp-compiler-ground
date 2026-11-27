#include "common.h"

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
static SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk);
static void *SCEGMO_CHUNK_ARGS(SceGmoChunk *chunk);
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
_Bool sceGmoLayerLoadCache( SceGmoLayer *layer, SceGmoMaterial *material ) ;
void sceGmoModelFreeMemory2( void *addr ) ;
void *sceGmoModelAllocUncachedBuffer( void *ptr_ptr, int size ) ;
void sceGuStart( int cid, void *list, int size ) ;
int sceGuFinish( void ) ;
void sceGuMaterial( int mode, unsigned int color ) ;
void sceGuSpecular( float power ) ;
void sceGuBlendFunc( int op, int src, int dst, unsigned int srcfix, unsigned int destfix ) ;

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", sceGmoMaterialCreate);

void sceGmoMaterialDelete( SceGmoMaterial *material )
{
 if ( material == 0 ) return ;
 if ( -- material->m_reference == 0 ) {
  sceGmoMaterialUnload( material ) ;
  sceGmoBaseDestruct( &( material->m_base ) ) ;
  sceGmoModelFreeMemory( material ) ;
 }
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", sceGmoMaterialDuplicate);

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
        complement_animation_5CAE0();
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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", complement_animation_5CAE0);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", reconfigure_material);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", sceGmoLayerCreate);

void sceGmoLayerDelete( SceGmoLayer *layer )
{
 if ( layer == 0 ) return ;
 if ( -- layer->m_reference == 0 ) {
  sceGmoLayerUnload( layer ) ;
  sceGmoModelFreeMemory( layer ) ;
 }
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", sceGmoLayerDuplicate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", sceGmoLayerLoad);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", sceGmoLayerActivate);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_material", reconfigure_layer);
