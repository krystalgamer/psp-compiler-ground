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
typedef struct SceGmoPart SceGmoPart;
struct SceGmoPart;
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
struct _anon1;
struct _anon1 { /* size 0x14 */
    int arrays;
    int mode;
    int n_verts;
    int n_prims;
    short int indices[1];
};
typedef struct _anon1 SceGmoDrawArrays;
struct _anon2;
struct _anon2 { /* size 0x14 */
    int arrays;
    int mode;
    int width;
    int height;
    short int indices[1];
};
typedef struct _anon2 SceGmoDrawBSpline;
struct _anon3;
struct _anon3 { /* size 0x14 */
    int arrays;
    int mode;
    int width;
    int height;
    short int indices[1];
};
typedef struct _anon3 SceGmoDrawRectMesh;
struct _anon4;
struct _anon4 { /* size 0x14 */
    int arrays;
    int mode;
    int width;
    int height;
    short int indices[1];
};
typedef struct _anon4 SceGmoDrawRectPatch;
struct _anon5;
struct _anon5 { /* size 0x10 */
    int format;
    int n_verts;
    int n_morphs;
    int format2;
};
typedef struct _anon5 SceGmoArraysHeader;

extern SceGmoPart *g_current_part;
extern SceGmoArraysHeader *g_current_arrays;
extern int g_current_index;

SceGmoPart *sceGmoPartCreate(const SceGmoChunk *chunk);
void sceGmoPartDelete(SceGmoPart *part);
_Bool sceGmoPartLoad(SceGmoPart *part, const SceGmoChunk *load_chunk);
static int SCEGMO_CHUNK_SIZE(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk);
static int SCEGMO_CHUNK_TYPE(SceGmoChunk *chunk);
void sceGmoPartUnload(SceGmoPart *part);
void sceGmoPartDraw(SceGmoPart *part, SceGmoModel *model, SceGmoBone *bone);
static SceGmoSubject *sceGmoBaseGetParent(const SceGmoBase *base);
SceGmoMesh *sceGmoMeshCreate(const SceGmoChunk *chunk);
void sceGmoMeshDelete(SceGmoMesh *mesh);
_Bool sceGmoMeshLoad(SceGmoMesh *mesh, const SceGmoChunk *chunk);
static void *SCEGMO_CHUNK_ARGS(SceGmoChunk *chunk);
void sceGmoMeshUnload(SceGmoMesh *mesh);
void sceGmoMeshDraw(SceGmoMesh *mesh, SceGmoModel *model, SceGmoBone *bone, SceGmoPart *part);
static void draw_mesh(SceGmoMesh *mesh);
static void reset_arrays(SceGmoPart *part);
static _Bool set_arrays(int idx);
SceGmoChunk *sceGmoPartGetArrays(SceGmoPart *part, int idx);
static void draw_arrays(SceGmoDrawArrays *cmd);
static void draw_b_spline(SceGmoDrawBSpline *cmd);
static void draw_rect_mesh(SceGmoDrawRectMesh *cmd);
static void draw_rect_patch(SceGmoDrawRectPatch *cmd);
SceGmoPart *sceGmoPartDuplicate(SceGmoPart *part, int flags);
SceGmoMesh *sceGmoPartGetMesh(SceGmoPart *part, int idx);
SceGmoMesh *sceGmoMeshDuplicate(SceGmoMesh *mesh, int flags);


INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", sceGmoPartCreate);

void sceGmoPartDelete(SceGmoPart *part) {
    int temp_v1;

    if ((part == NULL) || (temp_v1 = part->m_reference - 1, part->m_reference = temp_v1, (temp_v1 != 0))) {

    } else {
        sceGmoPartUnload(part);
        sceGmoBaseDestruct(part);
        sceGmoModelFreeMemory(part);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", sceGmoPartLoad);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", sceGmoPartUnload);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", sceGmoPartDraw);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", sceGmoMeshCreate);

void sceGmoMeshDelete(SceGmoMesh *mesh) {
    int temp_v1;

    if ((mesh == NULL) || (temp_v1 = mesh->m_reference - 1, mesh->m_reference = temp_v1, (temp_v1 != 0))) {

    } else {
        sceGmoMeshUnload(mesh);
        sceGmoModelFreeMemory(mesh);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", sceGmoMeshLoad);

void sceGmoMeshUnload( SceGmoMesh *mesh )
{
 if ( mesh == 0 ) return ;

 mesh->m_chunk = 0 ;
 mesh->m_blend_subset = 0 ;
 mesh->m_n_blend_subset = 0 ;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", sceGmoMeshDraw);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", draw_mesh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", reset_arrays);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", set_arrays);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", draw_arrays);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", draw_b_spline);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", draw_rect_mesh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", draw_rect_patch);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", sceGmoPartDuplicate);

void sceGmoPartSetParent(SceGmoPart *part, SceGmoModel *parent) {
    if (part != NULL) {
        sceGmoBaseSetParent();
    }
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

SceGmoModel *sceGmoPartGetParent(SceGmoPart *part) {
    SceGmoSubject *var_v0;

    var_v0 = NULL;
    if (part != NULL) {
        var_v0 = part->m_base.m_parent.m_subject;
    }
    return (SceGmoModel *) var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

int sceGmoPartGetMeshCount(SceGmoPart *part) {
    int var_v0;

    var_v0 = 0;
    if (part != NULL) {
        var_v0 = part->m_n_meshes;
    }
    return var_v0;
}

int sceGmoPartGetArraysCount(SceGmoPart *part) {
    int var_v0;

    var_v0 = 0;
    if (part != NULL) {
        var_v0 = part->m_n_arrays;
    }
    return var_v0;
}

SceGmoMesh *sceGmoPartGetMesh(SceGmoPart *part, int idx) {
    SceGmoMesh *var_a2;
    int temp_a1;

    temp_a1 = idx & 0xFFF;
    var_a2 = NULL;
    if ((part != NULL) && (temp_a1 < part->m_n_meshes)) {
        var_a2 = part->m_meshes[temp_a1];
    }
    return var_a2;
}

SceGmoChunk *sceGmoPartGetArrays(SceGmoPart *part, int idx) {
    SceGmoChunk *var_a2;
    int temp_a1;

    temp_a1 = idx & 0xFFF;
    var_a2 = NULL;
    if ((part != NULL) && (temp_a1 < part->m_n_arrays)) {
        var_a2 = part->m_arrays[temp_a1];
    }
    return var_a2;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_part", sceGmoMeshDuplicate);
