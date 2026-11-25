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
typedef struct SceGmoMotion SceGmoMotion;
struct SceGmoMotion;
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
struct _anon1;
struct _anon1 { /* size 0x10 */
    int block;
    int cmd;
    int index;
    int fcurve;
};
typedef struct _anon1 SceGmoAnimate;
struct _anon2;
struct _anon2 { /* size 0x10 */
    int format;
    int n_dims;
    int n_keys;
    int reserved;
};
typedef struct _anon2 SceGmoFCurveHeader;
typedef ScePspFQuaternion quat;



SceGmoMotion *sceGmoMotionCreate(const SceGmoChunk *chunk);
SceGmoMotion *sceGmoMotionDuplicate(SceGmoMotion *motion, int flags);
_Bool sceGmoMotionLoad(SceGmoMotion *motion, const SceGmoChunk *load_chunk);
static int SCEGMO_CHUNK_SIZE(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk);
static void *SCEGMO_CHUNK_ARGS(SceGmoChunk *chunk);
void sceGmoMotionUnload(SceGmoMotion *motion);
void sceGmoMotionUpdate(SceGmoMotion *motion, SceGmoModel *model, float step);
static SceGmoSubject *sceGmoBaseGetParent(const SceGmoBase *base);
void sceGmoMotionSetFrameLoop(SceGmoMotion *motion, float start, float end);
void sceGmoMotionSetFrameRepeat(SceGmoMotion *motion, int mode);
static int eval_fcurve(SceGmoChunk *chunk, float frame, float *output);
static float find_root(float f0, float f1, float f2, float f3, float f);
static quat *quat_slerp(quat *dst, const quat *src1, const quat *src2, float rate);


INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", sceGmoMotionCreate);

void sceGmoMotionDelete(SceGmoMotion *motion) {
    int temp_v0;

    if ((motion == NULL) || (temp_v0 = motion->m_reference - 1, motion->m_reference = temp_v0, (temp_v0 != 0))) {

    } else {
        sceGmoMotionUnload(motion);
        sceGmoBaseDestruct(motion);
        sceGmoModelFreeMemory(motion);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", sceGmoMotionDuplicate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", sceGmoMotionLoad);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", sceGmoMotionUnload);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", sceGmoMotionUpdate);

void sceGmoMotionSetParent(SceGmoMotion *motion, SceGmoModel *parent) {
    if (motion != NULL) {
        sceGmoBaseSetParent();
    }
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

SceGmoModel *sceGmoMotionGetParent(SceGmoMotion *motion) {
    SceGmoSubject *var_v0;

    var_v0 = NULL;
    if (motion != NULL) {
        var_v0 = motion->m_base.m_parent.m_subject;
    }
    return (SceGmoModel *) var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", sceGmoMotionSetFrameLoop);

float *sceGmoMotionGetFrameLoop(SceGmoMotion *motion) {
    return (motion == NULL) ? NULL : motion->m_frame_loop;
}

void sceGmoMotionSetFrameRate(SceGmoMotion *motion, float fps) {
    if (motion != NULL) {
        motion->m_frame_rate = fps;
    }
}

float sceGmoMotionGetFrameRate(SceGmoMotion *motion) {
    float var_f0;

    var_f0 = 0.0f;
    if (motion != NULL) {
        var_f0 = motion->m_frame_rate;
    }
    return var_f0;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", sceGmoMotionSetFrameRepeat);

int sceGmoMotionGetFrameRepeat(SceGmoMotion *motion) {
    int var_v0;

    var_v0 = 0;
    if (motion != NULL) {
        var_v0 = (motion->m_flags ^ 1) & 1;
    }
    return var_v0;
}

void sceGmoMotionSetFrame(SceGmoMotion *motion, float frame) {
    if (motion != NULL) {
        motion->m_frame = frame;
    }
}

float sceGmoMotionGetFrame(SceGmoMotion *motion) {
    float var_f0;

    var_f0 = 0.0f;
    if (motion != NULL) {
        var_f0 = motion->m_frame;
    }
    return var_f0;
}

void sceGmoMotionSetWeight(SceGmoMotion *motion, float weight) {
    float var_f12;

    var_f12 = weight;
    if (motion != NULL) {
        if (var_f12 < 0.0f) {
            var_f12 = 0.0f;
        }
        motion->m_weight = var_f12;
    }
}

float sceGmoMotionGetWeight(SceGmoMotion *motion) {
    float var_f0;

    var_f0 = 0.0f;
    if (motion != NULL) {
        var_f0 = motion->m_weight;
    }
    return var_f0;
}

int sceGmoMotionGetAnimationCount(SceGmoMotion *motion) {
    int var_v0;

    var_v0 = 0;
    if (motion != NULL) {
        var_v0 = motion->m_n_anims;
    }
    return var_v0;
}

int sceGmoMotionGetFcurveCount(SceGmoMotion *motion) {
    int var_v0;

    var_v0 = 0;
    if (motion != NULL) {
        var_v0 = motion->m_n_fcurves;
    }
    return var_v0;
}

SceGmoChunk *sceGmoMotionGetAnimation(SceGmoMotion *motion, int idx) {
    SceGmoChunk *var_a2;
    int temp_a1;

    temp_a1 = idx & 0xFFF;
    var_a2 = NULL;
    if ((motion != NULL) && (temp_a1 < motion->m_n_anims)) {
        var_a2 = motion->m_anims[temp_a1];
    }
    return var_a2;
}

SceGmoChunk *sceGmoMotionGetFcurve(SceGmoMotion *motion, int idx) {
    SceGmoChunk *var_a2;
    int temp_a1;

    temp_a1 = idx & 0xFFF;
    var_a2 = NULL;
    if ((motion != NULL) && (temp_a1 < motion->m_n_fcurves)) {
        var_a2 = motion->m_fcurves[temp_a1];
    }
    return var_a2;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", eval_fcurve);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", find_root);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", quat_slerp_8490);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_motion", D_0001DB9C);
