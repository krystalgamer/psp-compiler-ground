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
typedef struct SceGmoTexture SceGmoTexture;
struct SceGmoTexture;
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
typedef struct SceGimPicture SceGimPicture;
struct SceGimPicture;
struct SceGmoTexture { /* size 0x1c */
    SceGmoBase m_base;
    SceGimPicture *m_picture;
    int m_reference;
    int m_flags;
};
struct _anon1;
struct _anon1 { /* size 0x1 */
    char name[1];
};
typedef struct _anon1 SceGmoFileName;
struct _anon2;
struct _anon2 { /* size 0x8 */
    int size;
    int data[1];
};
typedef struct _anon2 SceGmoFileImage;
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



SceGmoTexture *sceGmoTextureCreate(const SceGmoChunk *chunk);
void sceGmoTextureDelete(SceGmoTexture *texture);
SceGmoTexture *sceGmoTextureDuplicate(SceGmoTexture *texture, int flags);
_Bool sceGmoTextureLoad(SceGmoTexture *texture, const SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk);
static void *SCEGMO_CHUNK_ARGS(SceGmoChunk *chunk);
void sceGmoTextureUnload(SceGmoTexture *texture);
void sceGmoTextureUpdate(SceGmoTexture *texture, SceGmoModel *model, float step);
void sceGmoTextureActivate(SceGmoTexture *texture, SceGmoModel *model);
void sceGmoTextureSetParent(SceGmoTexture *texture, SceGmoModel *parent);
SceGmoModel *sceGmoTextureGetParent(SceGmoTexture *texture);
static SceGmoSubject *sceGmoBaseGetParent(const SceGmoBase *base);
void sceGmoTextureSetPicture(SceGmoTexture *texture, SceGimPicture *picture, int flags);
SceGimPicture *sceGmoTextureGetPicture(SceGmoTexture *texture);
_Bool sceGmoTextureHasAnimation(SceGmoTexture *texture);

void *sceGmoModelAllocMemory(unsigned int size);
void sceGmoModelFreeMemory(void *addr);
SceGimPicture *sceGmoModelImportPicture(const char *filename);
void sceGmoModelExportPicture(const char *filename, SceGimPicture *picture);
void sceGmoBaseConstruct(SceGmoBase *base);
void sceGmoBaseDestruct(SceGmoBase *base);
void sceGmoBaseCopy(SceGmoBase *base, const SceGmoBase *src);
void sceGmoBaseSetParent(SceGmoBase *base, SceGmoSubject *parent);
void sceGmoContextSetTexTrim(const float *trim);
SceGimPicture *sceGimPictureCreate(const void *chunk);
void sceGimPictureDelete(SceGimPicture *picture);
SceGimPicture *sceGimPictureDuplicate(SceGimPicture *picture, int flags);
_Bool sceGimPictureLoadFile(SceGimPicture *picture, const void *buf, int size, int idx);
void sceGimPictureAnimate(SceGimPicture *picture, float step);
void sceGimPictureActivate(SceGimPicture *picture);
const float *sceGimPictureGetImageCrop(SceGimPicture *picture);
_Bool sceGimPictureHasAnimation(SceGimPicture *picture);

static __inline__ SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk)
{
	return (SceGmoChunk *)((char *)chunk + chunk->next_offs);
}

static __inline__ SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk)
{
	if (chunk->type & 0x8000)
		return SCEGMO_CHUNK_NEXT(chunk);
	return (SceGmoChunk *)((char *)chunk + chunk->child_offs);
}

static __inline__ void *SCEGMO_CHUNK_ARGS(SceGmoChunk *chunk)
{
	if (chunk->type & 0x8000)
		return (char *)chunk + 8;
	return (char *)chunk + chunk->args_offs;
}

static __inline__ SceGmoSubject *sceGmoBaseGetParent(const SceGmoBase *base)
{
	return base->m_parent.m_subject;
}

SceGmoTexture *sceGmoTextureCreate(const SceGmoChunk *chunk)
{
	SceGmoTexture *texture;

	texture = (SceGmoTexture *)sceGmoModelAllocMemory(sizeof(SceGmoTexture));
	if (texture == NULL)
		return NULL;
	sceGmoBaseConstruct(&texture->m_base);
	texture->m_reference = 1;
	texture->m_picture = NULL;
	texture->m_flags = 0;
	if (chunk != NULL && !sceGmoTextureLoad(texture, chunk)) {
		sceGmoTextureDelete(texture);
		return NULL;
	}
	return texture;
}

void sceGmoTextureDelete(SceGmoTexture *texture)
{
	if (texture == NULL)
		return;
	if (--texture->m_reference != 0)
		return;
	sceGmoTextureUnload(texture);
	sceGmoBaseDestruct(&texture->m_base);
	sceGmoModelFreeMemory(texture);
}

SceGmoTexture *sceGmoTextureDuplicate(SceGmoTexture *texture, int flags)
{
	SceGmoTexture *texture2;
	SceGimPicture *src;
	SceGimPicture *dst;

	if (texture == NULL)
		return NULL;
	if (flags & 2) {
		if (sceGmoTextureHasAnimation(texture))
			flags |= 1;
	}
	if (!(flags & 0x401)) {
		texture->m_reference++;
		return texture;
	}
	texture2 = sceGmoTextureCreate(NULL);
	if (texture2 == NULL)
		return NULL;
	sceGmoBaseCopy(&texture2->m_base, &texture->m_base);
	src = texture->m_picture;
	dst = sceGimPictureDuplicate(src, 2);
	if (dst == NULL && src != NULL) {
		sceGmoTextureDelete(texture2);
		return NULL;
	}
	texture2->m_picture = dst;
	texture2->m_flags = texture->m_flags;
	return texture2;
}

_Bool sceGmoTextureLoad(SceGmoTexture *texture, const SceGmoChunk *chunk)
{
	char *filename;
	void *fileimage;
	int filesize;
	SceGmoChunk *end;

	if (texture == NULL)
		return 0;
	if (chunk == NULL)
		return 0;
	sceGmoTextureUnload(texture);
	filename = NULL;
	fileimage = NULL;
	filesize = 0;
	end = SCEGMO_CHUNK_NEXT((SceGmoChunk *)chunk);
	for (chunk = SCEGMO_CHUNK_CHILD((SceGmoChunk *)chunk); chunk < end; chunk = SCEGMO_CHUNK_NEXT((SceGmoChunk *)chunk)) {
		void *args = SCEGMO_CHUNK_ARGS((SceGmoChunk *)chunk);
		switch (chunk->type & ~0x8000) {
		case 0x12: {
			SceGmoFileName *cmd = (SceGmoFileName *)args;
			filename = cmd->name;
			break;
		}
		case 0x13: {
			SceGmoFileImage *cmd = (SceGmoFileImage *)args;
			filesize = cmd->size;
			fileimage = cmd->data;
			break;
		}
		}
	}
	if (fileimage != NULL) {
		SceGimPicture *picture = sceGimPictureCreate(NULL);
		if (!sceGimPictureLoadFile(picture, fileimage, filesize, 0)) {
			sceGimPictureDelete(picture);
		} else {
			texture->m_picture = picture;
			sceGmoModelExportPicture(filename, picture);
		}
	}
	if (texture->m_picture == NULL) {
		SceGimPicture *picture = sceGmoModelImportPicture(filename);
		texture->m_picture = sceGimPictureDuplicate(picture, 2);
	}
	return 1;
}

void sceGmoTextureUnload(SceGmoTexture *texture)
{
	if (texture == NULL)
		return;
	sceGimPictureDelete(texture->m_picture);
	texture->m_picture = NULL;
}

void sceGmoTextureUpdate(SceGmoTexture *texture, SceGmoModel *model, float step)
{
	if (texture == NULL)
		return;
	sceGimPictureAnimate(texture->m_picture, step);
}

void sceGmoTextureActivate(SceGmoTexture *texture, SceGmoModel *model)
{
	SceGimPicture *picture;

	if (texture == NULL)
		return;
	picture = texture->m_picture;
	sceGimPictureActivate(picture);
	sceGmoContextSetTexTrim(sceGimPictureGetImageCrop(picture));
}

void sceGmoTextureSetParent(SceGmoTexture *texture, SceGmoModel *parent)
{
	if (texture == NULL)
		return;
	sceGmoBaseSetParent(&texture->m_base, (SceGmoSubject *)parent);
}

SceGmoModel *sceGmoTextureGetParent(SceGmoTexture *texture)
{
	if (texture == NULL)
		return NULL;
	return (SceGmoModel *)sceGmoBaseGetParent(&texture->m_base);
}

void sceGmoTextureSetPicture(SceGmoTexture *texture, SceGimPicture *picture, int flags)
{
	if (texture == NULL)
		return;
	if (picture == texture->m_picture)
		return;
	sceGimPictureDelete(texture->m_picture);
	texture->m_picture = sceGimPictureDuplicate(picture, flags);
}

SceGimPicture *sceGmoTextureGetPicture(SceGmoTexture *texture)
{
	if (texture == NULL)
		return NULL;
	return texture->m_picture;
}

_Bool sceGmoTextureHasAnimation(SceGmoTexture *texture)
{
	if (texture == NULL)
		return 0;
	return sceGimPictureHasAnimation(texture->m_picture);
}

