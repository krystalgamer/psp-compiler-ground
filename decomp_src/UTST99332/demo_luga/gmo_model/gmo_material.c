/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
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
struct SceGmoLayer { /* size 0x50 */
    SceGmoLayer *m_initial;
    int m_reference;
    int m_flags;
    int m_map_type;
    float m_map_factor;
    int m_blend_func[5];
    int m_texture;
    ScePspFRect m_tex_crop;
    int m_enable_mask;
    int m_enable_bits;
    int m_diffuse;
    int m_specular;
    int m_ambient;
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
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
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
typedef ScePspFRect rect;
typedef ScePspFVector4 vec4;
typedef struct SceGmoSubject SceGmoSubject;



SceGmoMaterial *sceGmoMaterialCreate(const SceGmoChunk *chunk);
void sceGmoMaterialDelete(SceGmoMaterial *material);
SceGmoMaterial *sceGmoMaterialDuplicate(SceGmoMaterial *material, int flags);
_Bool sceGmoMaterialLoad(SceGmoMaterial *material, const SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk);
static void *SCEGMO_CHUNK_ARGS(SceGmoChunk *chunk);
static int SCEGMO_CHUNK_TYPE(SceGmoChunk *chunk);
void sceGmoMaterialUnload(SceGmoMaterial *material);
void sceGmoMaterialAnimate(SceGmoMaterial *material, int type, int idx, const float *val, int cnt, float weight);
static _Bool reconfigure_material(SceGmoMaterial *material);
SceGmoLayer *sceGmoLayerCreate(const SceGmoChunk *chunk);
void sceGmoLayerDelete(SceGmoLayer *layer);
SceGmoLayer *sceGmoLayerDuplicate(SceGmoLayer *layer, int flags);
_Bool sceGmoLayerLoad(SceGmoLayer *layer, const SceGmoChunk *chunk);
int sceGmoLayerActivate(SceGmoLayer *layer, SceGmoModel *model, SceGmoMaterial *material);
void sceGmoLayerSetTexCrop(SceGmoLayer *layer, const rect *crop);
const struct ScePspFRect *sceGmoLayerGetTexCrop(SceGmoLayer *layer);
static _Bool reconfigure_layer(SceGmoLayer *layer);
static vec4 *vec4_col32(vec4 *dst, unsigned int src);
static unsigned int col32_vec4(const vec4 *src);
static unsigned int col32_lerp(unsigned int src1, unsigned int src2, float rate);
static float *float_lerp(float *dst, const float *src1, const float *src2, int dim, float rate);
int sceGmoMaterialActivate(SceGmoMaterial *material, SceGmoModel *model, int idx);
static SceGmoSubject *sceGmoBaseGetParent(const SceGmoBase *base);
SceGmoLayer *sceGmoMaterialGetLayer(SceGmoMaterial *material, int idx);
static void complement_animation(SceGmoMaterial *material);


/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuMaterial(int mode, unsigned int color);
void sceGuSpecular(float power);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoMaterialCreate);

void sceGmoMaterialDelete(SceGmoMaterial *material) {
    int temp_v1;

    if ((material == NULL) || (temp_v1 = material->m_reference - 1, material->m_reference = temp_v1, (temp_v1 != 0))) {

    } else {
        sceGmoMaterialUnload(material);
        sceGmoBaseDestruct(material);
        sceGmoModelFreeMemory(material);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoMaterialDuplicate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoMaterialLoad);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoMaterialUnload);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoMaterialAnimate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", reconfigure_material);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoLayerCreate);

void sceGmoLayerDelete(SceGmoLayer *layer) {
    int temp_v1;

    if ((layer == NULL) || (temp_v1 = layer->m_reference - 1, layer->m_reference = temp_v1, (temp_v1 != 0))) {

    } else {
        sceGmoLayerUnload(layer);
        sceGmoModelFreeMemory(layer);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoLayerDuplicate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoLayerLoad);

void sceGmoLayerUnload(SceGmoLayer *layer) {
    if (layer != NULL) {
        sceGmoLayerDelete(layer->m_initial);
        layer->m_initial = NULL;
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoLayerActivate);

void sceGmoLayerSetMapType(SceGmoLayer *layer, int type) {
    if (layer != NULL) {
        layer->m_map_type = type;
        reconfigure_layer(layer);
    }
}

int sceGmoLayerGetMapType(SceGmoLayer *layer) {
    int var_v0;

    var_v0 = 0;
    if (layer != NULL) {
        var_v0 = layer->m_map_type;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoLayerSetTexCrop);

const ScePspFRect *sceGmoLayerGetTexCrop(SceGmoLayer *layer)
{
    const ScePspFRect *var_v0;

    var_v0 = NULL;
    if (layer != NULL) {
        var_v0 = !(layer->m_flags & 1) ? NULL : &layer->m_tex_crop;
    }
    return var_v0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021A8C);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021A90);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021A94);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021A98);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021A9C);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021AA0);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021AA4);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021AA8);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021AB0);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021ACC);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021AF0);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021B00);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", D_00021B5C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", reconfigure_layer);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", vec4_col32);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", col32_vec4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", col32_lerp);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", float_lerp_A894);

void sceGmoMaterialUpdate(SceGmoMaterial *material, SceGmoModel *model) {
    if (material != NULL) {
        complement_animation_AA18();
    }
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

int sceGmoMaterialActivate(SceGmoMaterial *material, SceGmoModel *model, int idx) {
    SceGmoSubject *temp_a3;
    int var_a4;

    var_a4 = 0;
    if ((material != NULL) && (idx < material->m_n_layers)) {
        temp_a3 = material->m_base.m_parent.m_subject;
        var_a4 = sceGmoLayerActivate(material->m_layers[idx], (SceGmoModel *) ((temp_a3 != NULL) ? temp_a3 : (SceGmoSubject *) model), material);
    }
    return var_a4;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

void sceGmoMaterialSetParent(SceGmoMaterial *material, SceGmoModel *parent) {
    if (material != NULL) {
        sceGmoBaseSetParent();
    }
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

SceGmoModel *sceGmoMaterialGetParent(SceGmoMaterial *material) {
    SceGmoSubject *var_v0;

    var_v0 = NULL;
    if (material != NULL) {
        var_v0 = material->m_base.m_parent.m_subject;
    }
    return (SceGmoModel *) var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

int sceGmoMaterialGetLayerCount(SceGmoMaterial *material) {
    int var_v0;

    var_v0 = 0;
    if (material != NULL) {
        var_v0 = material->m_n_layers;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", sceGmoMaterialGetLayer);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_material", complement_animation_AA18);
