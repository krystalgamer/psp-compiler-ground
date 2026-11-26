#include "common.h"

/* declarations recovered from DWARF (UTST99332 graphics_model gmo_motion) */
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
void sceGmoMotionDelete(SceGmoMotion *motion);
SceGmoMotion *sceGmoMotionDuplicate(SceGmoMotion *motion, int flags);
_Bool sceGmoMotionLoad(SceGmoMotion *motion, const SceGmoChunk *load_chunk);
static int SCEGMO_CHUNK_SIZE(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk);
static void *SCEGMO_CHUNK_ARGS(SceGmoChunk *chunk);
void sceGmoMotionUnload(SceGmoMotion *motion);
void sceGmoMotionUpdate(SceGmoMotion *motion, SceGmoModel *model, float step);
static SceGmoSubject *sceGmoBaseGetParent(const SceGmoBase *base);
void sceGmoMotionSetParent(SceGmoMotion *motion, SceGmoModel *parent);
SceGmoModel *sceGmoMotionGetParent(SceGmoMotion *motion);
void sceGmoMotionSetFrameLoop(SceGmoMotion *motion, float start, float end);
const float *sceGmoMotionGetFrameLoop(SceGmoMotion *motion);
void sceGmoMotionSetFrameRate(SceGmoMotion *motion, float fps);
float sceGmoMotionGetFrameRate(SceGmoMotion *motion);
void sceGmoMotionSetFrameRepeat(SceGmoMotion *motion, int mode);
int sceGmoMotionGetFrameRepeat(SceGmoMotion *motion);
void sceGmoMotionSetFrame(SceGmoMotion *motion, float frame);
float sceGmoMotionGetFrame(SceGmoMotion *motion);
void sceGmoMotionSetWeight(SceGmoMotion *motion, float weight);
float sceGmoMotionGetWeight(SceGmoMotion *motion);
int sceGmoMotionGetAnimationCount(SceGmoMotion *motion);
int sceGmoMotionGetFcurveCount(SceGmoMotion *motion);
SceGmoChunk *sceGmoMotionGetAnimation(SceGmoMotion *motion, int idx);
SceGmoChunk *sceGmoMotionGetFcurve(SceGmoMotion *motion, int idx);
static int eval_fcurve(SceGmoChunk *chunk, float frame, float *output);
static float find_root(float f0, float f1, float f2, float f3, float f);
static quat *quat_slerp(quat *dst, const quat *src1, const quat *src2, float rate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoVec3Set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoVec4Set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoMat4Set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoQuatSet);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoRectSet);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoCol4Set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoVec3Load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoVec4Load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoMat4Load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoQuatLoad);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoRectLoad);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoCol4Load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoMat4Multiply);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoMat4Scale);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoFloatLerp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoMat4FromQuat);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoQuatFromRotZYX);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoQuatFromRotYXZ);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoQuatSlerp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoVec4FromCol4);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoCol4FromVec4);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoCol4IsBlack);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoCol4IsHollow);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoBoneAffineMatrix);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoBoneStackScale);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_math", sceGmoBoneApplyPivot);
