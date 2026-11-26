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
typedef struct SceGmoBone SceGmoBone;
struct SceGmoBone;
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
typedef struct SceGmoModel SceGmoModel;
struct SceGmoModel;
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
typedef struct SceGmoMaterial SceGmoMaterial;
struct SceGmoMaterial;
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
typedef ScePspFMatrix4 mat4;
typedef ScePspFVector4 vec4;
typedef ScePspFVector3 vec3;
typedef ScePspFQuaternion quat;

extern mat4 g_identity;

SceGmoBone *sceGmoBoneCreate(const SceGmoChunk *chunk);
void sceGmoBoneDelete(SceGmoBone *bone);
SceGmoBone *sceGmoBoneDuplicate(SceGmoBone *bone, int flags);
_Bool sceGmoBoneLoad(SceGmoBone *bone, const SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk);
static void *SCEGMO_CHUNK_ARGS(SceGmoChunk *chunk);
static int SCEGMO_CHUNK_TYPE(SceGmoChunk *chunk);
void sceGmoBoneUnload(SceGmoBone *bone);
void sceGmoBoneDraw(SceGmoBone *bone, SceGmoModel *model);
static SceGmoSubject *sceGmoBaseGetParent(const SceGmoBase *base);
void sceGmoBoneActivate(SceGmoBone *bone, SceGmoModel *model, const int *indices, int n_indices);
void sceGmoBoneAnimate(SceGmoBone *bone, int type, int idx, const float *val, int cnt, float weight);
const struct ScePspFMatrix4 *sceGmoBoneGetWorldMatrix(SceGmoBone *bone);
static _Bool set_blend_bones(SceGmoBone *bone, const int *bones, int n_bones);
static _Bool set_blend_offsets(SceGmoBone *bone, const mat4 *offsets, int n_offsets);
static _Bool set_morph_weights(SceGmoBone *bone, const float *weights, int n_weights);
static void calc_morph_index(float *weights, int n_weights, float idx);
static mat4 *mat4_mul(mat4 *dst, const mat4 *src1, const mat4 *src2);
static vec4 *mat4_app(vec4 *dst, const mat4 *src1, const vec4 *src2);
static vec3 *vec3_mul(vec3 *dst, const vec3 *src1, const vec3 *src2);
static vec4 *vec4_scale(vec4 *dst, const vec4 *src1, float src2);
static float *float_lerp(float *dst, const float *src1, const float *src2, int dim, float rate);
static mat4 *mat4_from_quat(mat4 *dst, const quat *src);
static quat *quat_from_rotzyx(quat *dst, const vec3 *src);
static quat *quat_from_rotyxz(quat *dst, const vec3 *src);
static quat *quat_slerp(quat *dst, const quat *src1, const quat *src2, float rate);
static void complement_animation(SceGmoBone *bone);
static void calc_local_matrix(SceGmoBone *bone);
static void calc_stack_matrix(SceGmoBone *bone, SceGmoModel *model);


INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", D_00021798);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", D_000217A4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", sceGmoBoneCreate);

void sceGmoBoneDelete(SceGmoBone *bone) {
    int temp_v1;

    if ((bone == NULL) || (temp_v1 = bone->m_reference - 1, bone->m_reference = temp_v1, (temp_v1 != 0))) {

    } else {
        sceGmoBoneUnload(bone);
        sceGmoBaseDestruct(bone);
        sceGmoModelFreeMemory(bone);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", sceGmoBoneDuplicate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", sceGmoBoneLoad);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", sceGmoBoneUnload);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", sceGmoBoneDraw);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", sceGmoBoneActivate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", sceGmoBoneAnimate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", sceGmoBoneGetWorldMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", set_blend_bones);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", set_blend_offsets);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", set_morph_weights);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", calc_morph_index);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", mat4_mul);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", mat4_app);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", vec3_mul);

ScePspFVector3 *vec3_div(ScePspFVector3 *dst, ScePspFVector3 *src1, ScePspFVector3 *src2) {
    float temp_f1;
    float temp_f1_2;
    float temp_f1_3;
    float var_f0;
    float var_f0_2;
    float var_f0_3;

    temp_f1 = src2->x;
    var_f0 = src1->x;
    if (temp_f1 != 0.0f) {
        var_f0 /= temp_f1;
    }
    temp_f1_2 = src2->y;
    dst->x = var_f0;
    var_f0_2 = src1->y;
    if (temp_f1_2 != 0.0f) {
        var_f0_2 /= temp_f1_2;
    }
    temp_f1_3 = src2->z;
    dst->y = var_f0_2;
    var_f0_3 = src1->z;
    if (temp_f1_3 != 0.0f) {
        var_f0_3 /= temp_f1_3;
    }
    dst->z = var_f0_3;
    return dst;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", vec4_scale);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", float_lerp_79CC);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", mat4_from_quat);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", quat_from_rotzyx);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", quat_from_rotyxz);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", quat_slerp_7D50);

void sceGmoBoneUpdate(SceGmoBone *bone, SceGmoModel *model) {
    if (bone != NULL) {
        complement_animation_7FB0();
        calc_local_matrix(bone);
        calc_stack_matrix(bone, model);
    }
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

void sceGmoBoneSetParent(SceGmoBone *bone, SceGmoModel *parent) {
    if (bone != NULL) {
        sceGmoBaseSetParent();
    }
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

SceGmoModel *sceGmoBoneGetParent(SceGmoBone *bone) {
    SceGmoSubject *var_v0;

    var_v0 = NULL;
    if (bone != NULL) {
        var_v0 = bone->m_base.m_parent.m_subject;
    }
    return (SceGmoModel *) var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", complement_animation_7FB0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", calc_local_matrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_bone", calc_stack_matrix);
