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
typedef struct SceGmoModel SceGmoModel;
struct SceGmoModel;
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
typedef ScePspFMatrix4 mat4;

extern const unsigned char __psp_libinfo__[24];
extern mat4 g_identity;

SceGmoModel *sceGmoModelCreate(const SceGmoChunk *chunk);
void sceGmoModelDelete(SceGmoModel *model);
SceGmoModel *sceGmoModelDuplicate(SceGmoModel *model, int flags);
_Bool sceGmoModelLoadFile(SceGmoModel *model, const void *buf, int size, int idx);
_Bool sceGmoModelLoad(SceGmoModel *model, const SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk);
static void *SCEGMO_CHUNK_ARGS(SceGmoChunk *chunk);
static int SCEGMO_CHUNK_TYPE(SceGmoChunk *chunk);
void sceGmoModelUnload(SceGmoModel *model);
void sceGmoModelAnimate(SceGmoModel *model, float step);
void sceGmoModelUpdate(SceGmoModel *model);
void sceGmoModelDraw(SceGmoModel *model);
SceGmoBone *sceGmoModelSetBone(SceGmoModel *model, int idx, SceGmoBone *bone, int flags);
SceGmoPart *sceGmoModelSetPart(SceGmoModel *model, int idx, SceGmoPart *part, int flags);
SceGmoMaterial *sceGmoModelSetMaterial(SceGmoModel *model, int idx, SceGmoMaterial *material, int flags);
SceGmoTexture *sceGmoModelSetTexture(SceGmoModel *model, int idx, SceGmoTexture *texture, int flags);
SceGmoMotion *sceGmoModelSetMotion(SceGmoModel *model, int idx, SceGmoMotion *motion, int flags);
static void change_motion(SceGmoModel *model, float step);
void sceGmoModelSetWorldMatrix(SceGmoModel *model, const mat4 *m);
void sceGmoModelSetCurrentMotion(SceGmoModel *model, int idx, float delay);
SceGmoMotion *sceGmoModelGetMotion(SceGmoModel *model, int idx);
void sceGmoModelSetEnableBits(SceGmoModel *model, int bits, int value);
int sceGmoModelGetEnableBits(SceGmoModel *model);
void sceGmoModelSetEnableMask(SceGmoModel *model, int mask, int value);
int sceGmoModelGetEnableMask(SceGmoModel *model);
const struct ScePspFVector3 *sceGmoModelGetBoundingBox(SceGmoModel *model);
const struct ScePspFMatrix4 *sceGmoModelGetVertexOffset(SceGmoModel *model);
const struct ScePspFRect *sceGmoModelGetTexcoordOffset(SceGmoModel *model);
SceGmoBone *sceGmoModelGetBone(SceGmoModel *model, int idx);
SceGmoPart *sceGmoModelGetPart(SceGmoModel *model, int idx);
SceGmoMaterial *sceGmoModelGetMaterial(SceGmoModel *model, int idx);
SceGmoTexture *sceGmoModelGetTexture(SceGmoModel *model, int idx);


INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", __psp_libinfo___2171C);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", D_00021734);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", D_00021744);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelCreate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelDelete);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelDuplicate);

_Bool sceGmoModelLoadFile( SceGmoModel *model, const void *buf, int size, int index )
{
 if ( model == 0 ) return 0 ;
 if ( buf == 0 ) return 0 ;

 if ( !sceGmoModelCheckFileHeader( buf, size ) ) return 0 ;

 SceGmoChunk *chunk = sceGmoModelGetChunk( buf, size, index ) ;
 if ( chunk == 0 ) {
  ;
  return 0 ;
 }
 ;
 return sceGmoModelLoad( model, chunk ) ;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelLoad);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelUnload);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelAnimate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelDraw);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelSetBone);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelSetPart);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelSetMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelSetTexture);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelSetMotion);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", change_motion);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelSetWorldMatrix);

ScePspFMatrix4 *sceGmoModelGetWorldMatrix(SceGmoModel *model) {
    return (ScePspFMatrix4 *) ((model == NULL) ? NULL : &model->m_world_matrix.x.z);
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelSetCurrentMotion);

int sceGmoModelGetCurrentMotion(SceGmoModel *model) {
    int var_v0;

    var_v0 = 0;
    if (model != NULL) {
        var_v0 = model->m_current_motion;
    }
    return var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelSetEnableBits);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelGetEnableBits);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelSetEnableMask);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelGetEnableMask);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelGetBoundingBox);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelGetVertexOffset);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelGetTexcoordOffset);

int sceGmoModelGetBoneCount(SceGmoModel *model) {
    int var_v0;

    var_v0 = 0;
    if (model != NULL) {
        var_v0 = model->m_n_bones;
    }
    return var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

int sceGmoModelGetPartCount(SceGmoModel *model) {
    int var_v0;

    var_v0 = 0;
    if (model != NULL) {
        var_v0 = model->m_n_parts;
    }
    return var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

int sceGmoModelGetMaterialCount(SceGmoModel *model) {
    int var_v0;

    var_v0 = 0;
    if (model != NULL) {
        var_v0 = model->m_n_materials;
    }
    return var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

int sceGmoModelGetTextureCount(SceGmoModel *model) {
    int var_v0;

    var_v0 = 0;
    if (model != NULL) {
        var_v0 = model->m_n_textures;
    }
    return var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

int sceGmoModelGetMotionCount(SceGmoModel *model) {
    int var_v0;

    var_v0 = 0;
    if (model != NULL) {
        var_v0 = model->m_n_motions;
    }
    return var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelGetBone);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelGetPart);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelGetMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelGetTexture);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_model", sceGmoModelGetMotion);
