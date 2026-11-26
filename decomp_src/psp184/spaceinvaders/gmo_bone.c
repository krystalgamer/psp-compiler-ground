#include "common.h"

/* declarations recovered from DWARF (UTST99332 graphics_model gmo_bone) */
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
struct _anon1;
struct _anon1 { /* size 0x44 */
    int n_offsets;
    ScePspFMatrix4 offsets[1];
};
typedef struct _anon1 SceGmoBlendOffsets;
struct _anon2;
struct _anon2 { /* size 0x8 */
    int n_weights;
    float weights[1];
};
typedef struct _anon2 SceGmoMorphWeights;
struct _anon3;
struct _anon3 { /* size 0x4 */
    float index;
};
typedef struct _anon3 SceGmoMorphIndex;
struct _anon4;
struct _anon4 { /* size 0x8 */
    int n_bones;
    int bones[1];
};
typedef struct _anon4 SceGmoBlendBones;
struct _anon5;
struct _anon5 { /* size 0xc */
    ScePspFVector3 rotate;
};
typedef struct _anon5 SceGmoRotateZYX;
struct _anon6;
struct _anon6 { /* size 0xc */
    ScePspFVector3 rotate;
};
typedef struct _anon6 SceGmoRotateYXZ;
struct _anon7;
struct _anon7 { /* size 0x4 */
    int part;
};
typedef struct _anon7 SceGmoDrawPart;
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
typedef ScePspFQuaternion quat;
typedef ScePspFVector3 vec3;
typedef ScePspFVector4 vec4;

extern mat4 g_identity;

SceGmoBone *sceGmoBoneCreate(const SceGmoChunk *chunk);
void sceGmoBoneDelete(SceGmoBone *bone);
SceGmoBone *sceGmoBoneDuplicate(SceGmoBone *bone, int flags);
_Bool sceGmoBoneLoad(SceGmoBone *bone, const SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk);
static void *SCEGMO_CHUNK_ARGS(SceGmoChunk *chunk);
void sceGmoBoneUnload(SceGmoBone *bone);
void sceGmoBoneUpdate(SceGmoBone *bone, SceGmoModel *model);
void sceGmoBoneDraw(SceGmoBone *bone, SceGmoModel *model);
static SceGmoSubject *sceGmoBaseGetParent(const SceGmoBase *base);
void sceGmoBoneActivate(SceGmoBone *bone, SceGmoModel *model, const int *indices, int n_indices);
void sceGmoBoneAnimate(SceGmoBone *bone, int type, int idx, const float *val, int cnt, float weight);
void sceGmoBoneSetParent(SceGmoBone *bone, SceGmoModel *parent);
SceGmoModel *sceGmoBoneGetParent(SceGmoBone *bone);
const struct ScePspFMatrix4 *sceGmoBoneGetWorldMatrix(SceGmoBone *bone);
static void complement_animation(SceGmoBone *bone);
static void calc_local_matrix(SceGmoBone *bone);
static void calc_stack_matrix(SceGmoBone *bone, SceGmoModel *model);
static _Bool set_blend_bones(SceGmoBone *bone, const int *bones, int n_bones);
static _Bool set_blend_offsets(SceGmoBone *bone, const mat4 *offsets, int n_offsets);
static _Bool set_morph_weights(SceGmoBone *bone, const float *weights, int n_weights);
static void calc_morph_index(float *weights, int n_weights, float idx);
static mat4 *mat4_mul(mat4 *dst, const mat4 *src1, const mat4 *src2);
static vec4 *mat4_app(vec4 *dst, const mat4 *src1, const vec4 *src2);
static vec3 *vec3_mul(vec3 *dst, const vec3 *src1, const vec3 *src2);
static vec3 *vec3_div(vec3 *dst, const vec3 *src1, const vec3 *src2);
static vec4 *vec4_scale(vec4 *dst, const vec4 *src1, float src2);
static float *float_lerp(float *dst, const float *src1, const float *src2, int dim, float rate);
static mat4 *mat4_from_quat(mat4 *dst, const quat *src);
static quat *quat_from_rotzyx(quat *dst, const vec3 *src);
static quat *quat_from_rotyxz(quat *dst, const vec3 *src);
static quat *quat_slerp(quat *dst, const quat *src1, const quat *src2, float rate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneCreate);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneUnload);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneUpdate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneDraw);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneActivate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneControl);

void sceGmoBoneSetParent(SceGmoBone *bone, SceGmoModel *parent) {
    if (bone != NULL) {
        sceGmoBaseSetParent();
    }
}

SceGmoModel *sceGmoBoneGetParent(SceGmoBone *bone) {
    SceGmoSubject *var_v0;

    var_v0 = NULL;
    if (bone != NULL) {
        var_v0 = bone->m_base.m_parent.m_subject;
    }
    return (SceGmoModel *) var_v0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneGetWorldMatrix);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", set_blend_bones);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", set_blend_offsets);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", set_morph_weights);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", calc_morph_index);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", complement_animation_5AB88);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", calc_bone_matrix);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", D_0007ECBC);
