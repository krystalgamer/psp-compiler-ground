#include "common.h"

/* declarations recovered from DWARF */
typedef struct SceGmoContext SceGmoContext;
struct SceGmoContext;
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
typedef struct SceGmoChunk SceGmoChunk;
struct SceGmoChunk;
struct SceGmoChunk { /* size 0x10 */
    short unsigned int type;
    short unsigned int args_offs;
    unsigned int next_offs;
    unsigned int child_offs;
    unsigned int data_offs;
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
typedef ScePspFRect rect;
struct SceGmoContext { /* size 0x88 */
    int m_flags;
    SceGmoModel *m_model;
    SceGmoBone *m_bone;
    SceGmoMaterial *m_material;
    SceGmoTexture *m_texture;
    int m_layer_index;
    int m_layer_state;
    int m_default_mask;
    int m_default_bits;
    int m_current_bits;
    rect m_default_offs;
    rect m_current_offs;
    rect m_default_crop;
    rect m_current_crop;
    rect m_default_trim;
    rect m_current_trim;
};

extern rect g_nocrop;
extern SceGmoContext g_context;

void sceGmoContextBegin(void);
void sceGmoContextEnd(void);
void sceGmoContextSetBone(SceGmoBone *bone, SceGmoModel *model, const int *indices, int n_indices);
int sceGmoContextSetMaterial(SceGmoMaterial *material, SceGmoModel *model, int idx);
void sceGmoContextSetTexture(SceGmoTexture *texture, SceGmoModel *model);
void sceGmoContextDefaultEnableBits(int mask, int bits);
void sceGmoContextSetEnableBits(int mask, int bits);
void sceGmoContextDefaultTexOffs(const rect *offs);
void sceGmoContextDefaultTexCrop(const rect *crop);
void sceGmoContextDefaultTexTrim(const rect *trim);
void sceGmoContextSetTexOffs(const rect *offs);
void sceGmoContextSetTexCrop(const rect *crop);
void sceGmoContextSetTexTrim(const rect *trim);
static void activate_enable_bits(int mask, int bits);
static void activate_tex_crop(void);

/* SDK functions */
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuMaterial(int mode, unsigned int color);
void sceGuSpecular(float power);
void sceGuLightMode(int mode);
void sceGuDepthMask(int mask);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuPixelMask(unsigned int mask);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);

extern SceGmoContext g_context;
void sceGmoBoneActivate(SceGmoBone *bone, SceGmoModel *model, const int *indices, int n_indices);
int sceGmoMaterialActivate(SceGmoMaterial *material, SceGmoModel *model, int idx);
void sceGmoTextureActivate(SceGmoTexture *texture, SceGmoModel *model);

void sceGmoContextBegin(void)
{
	SceGmoContext *c = &g_context;

	c->m_flags = 7;
	c->m_model = (SceGmoModel *)-1;
	c->m_bone = (SceGmoBone *)-1;
	c->m_material = (SceGmoMaterial *)-1;
	c->m_texture = (SceGmoTexture *)-1;
	c->m_layer_index = 0;
	c->m_layer_state = 0;
	c->m_default_mask = 0;
	c->m_default_bits = 0x1ffff;
	c->m_current_bits = 0x80000000;
	c->m_default_offs = g_nocrop;
	c->m_current_offs = g_nocrop;
	c->m_default_crop = g_nocrop;
	c->m_current_crop = g_nocrop;
	c->m_default_trim = g_nocrop;
	c->m_current_trim = g_nocrop;
}

void sceGmoContextEnd(void)
{
	SceGmoContext *c = &g_context;
	int enable;
	int current;

	enable = 0x1ffff;
	current = c->m_current_bits;
	activate_enable_bits(enable ^ current, enable);
	sceGuTexOffset(0.0f, 0.0f);
	sceGuTexScale(1.0f, 1.0f);
	sceGuMaterial(2, 0xffffffff);
	sceGuMaterial(1, 0xffffffff);
	sceGuMaterial(4, 0);
	sceGuSpecular(0.0f);
	sceGuBlendFunc(0, 2, 3, 0, 0);
}

void sceGmoContextSetBone(SceGmoBone *bone, SceGmoModel *model, const int *indices, int n_indices)
{
	SceGmoContext *c = &g_context;

	if (n_indices == 0) {
		if (c->m_bone == bone && c->m_model == model)
			return;
		c->m_model = model;
		c->m_bone = bone;
	} else {
		c->m_bone = NULL;
	}
	sceGmoBoneActivate(bone, model, indices, n_indices);
}

int sceGmoContextSetMaterial(SceGmoMaterial *material, SceGmoModel *model, int idx)
{
	SceGmoContext *c = &g_context;

	if (c->m_material != material || c->m_layer_index != idx || c->m_model != model) {
		c->m_model = model;
		c->m_material = material;
		c->m_layer_index = idx;
		c->m_layer_state = sceGmoMaterialActivate(material, model, idx);
	}
	return c->m_layer_state;
}

void sceGmoContextSetTexture(SceGmoTexture *texture, SceGmoModel *model)
{
	SceGmoContext *c = &g_context;

	if (c->m_texture == texture && c->m_model == model)
		return;
	{
		int enable;
		int change;

		enable = (texture == NULL) ? 0 : 4;
		c->m_model = model;
		c->m_texture = texture;
		if (c->m_default_mask & 4)
			c->m_default_bits = (c->m_default_bits & ~4) | enable;
		change = c->m_current_bits ^ enable;
		if (change & 0x80000004)
			sceGmoContextSetEnableBits(4, enable);
		sceGmoTextureActivate(texture, model);
	}
}

#ifdef NON_MATCHING
/* v0/v1 swap between the &g_context address and the 0x10000 constant */
void sceGmoContextDefaultEnableBits(int mask, int bits)
{
	SceGmoContext *c = &g_context;

	c->m_default_mask = ~((mask & 0xffff) | 0x80000000);
	c->m_default_bits = (bits & 0xffff) | 0x10000;
}
#else
INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/gmo_context", sceGmoContextDefaultEnableBits);
#endif

void sceGmoContextSetEnableBits(int mask, int bits)
{
	SceGmoContext *c = &g_context;
	int enable;
	int current;
	int change;

	mask &= c->m_default_mask;
	enable = c->m_default_bits;
	enable = (~mask & enable) | (mask & bits);
	current = c->m_current_bits;
	change = enable ^ current;
	if (change != 0) {
		if (current < 0)
			change = -1;
		activate_enable_bits(change, enable);
		c->m_current_bits = enable;
	}
}

void sceGmoContextDefaultTexOffs(const rect *offs)
{
	if (offs == NULL)
		offs = &g_nocrop;
	g_context.m_default_offs = *offs;
}

void sceGmoContextDefaultTexCrop(const rect *crop)
{
	if (crop == NULL)
		crop = &g_nocrop;
	g_context.m_default_crop = *crop;
}

void sceGmoContextDefaultTexTrim(const rect *trim)
{
	if (trim == NULL)
		trim = &g_nocrop;
	g_context.m_default_trim = *trim;
}

void sceGmoContextSetTexOffs(const rect *offs)
{
	SceGmoContext *c = &g_context;

	if (offs != NULL) {
		c->m_current_offs = *offs;
		c->m_flags |= 1;
	} else {
		if (!(c->m_flags & 1))
			return;
		c->m_flags &= ~1;
	}
	activate_tex_crop();
}

void sceGmoContextSetTexCrop(const rect *crop)
{
	SceGmoContext *c = &g_context;

	if (crop != NULL) {
		c->m_current_crop = *crop;
		c->m_flags |= 2;
	} else {
		if (!(c->m_flags & 2))
			return;
		c->m_flags &= ~2;
	}
	activate_tex_crop();
}

void sceGmoContextSetTexTrim(const rect *trim)
{
	SceGmoContext *c = &g_context;

	if (trim != NULL) {
		c->m_current_trim = *trim;
		c->m_flags |= 4;
	} else {
		if (!(c->m_flags & 4))
			return;
		c->m_flags &= ~4;
	}
	activate_tex_crop();
}

static void activate_enable_bits(int mask, int bits)
{
	if (mask & 0x01) {
		if (bits & 0x01)
			sceGuEnable(10);
		else
			sceGuDisable(10);
	}
	if (mask & 0x02) {
		if (bits & 0x02)
			sceGuEnable(7);
		else
			sceGuDisable(7);
	}
	if (mask & 0x04) {
		if (bits & 0x04)
			sceGuEnable(9);
		else
			sceGuDisable(9);
	}
	if (mask & 0x08) {
		if (bits & 0x08)
			sceGuEnable(5);
		else
			sceGuDisable(5);
	}
	if (mask & 0x10) {
		if (bits & 0x10)
			sceGuEnable(1);
		else
			sceGuDisable(1);
	}
	if (mask & 0x20) {
		int depth_mask = (bits & 0x20) ? 0 : 1;
		sceGuDepthMask(depth_mask);
	}
	if (mask & 0x40) {
		if (bits & 0x40)
			sceGuEnable(0);
		else
			sceGuDisable(0);
	}
	if (mask & 0x80) {
		unsigned int alpha_mask = (bits & 0x80) ? 0 : 0xff000000;
		sceGuPixelMask(alpha_mask);
	}
	if (mask & 0x10000) {
		if (bits & 0x10000)
			sceGuLightMode(1);
		else
			sceGuLightMode(0);
	}
	if (mask & 0x20000) {
		if (bits & 0x20000)
			sceGuTexMapMode(2, 2, 3);
		else
			sceGuTexMapMode(0, 0, 0);
	}
}

static void activate_tex_crop(void)
{
	SceGmoContext *c = &g_context;
	int state;
	rect *offs;
	rect *crop;
	rect *trim;
	float wc;
	float hc;
	float wt;
	float ht;

	state = c->m_flags;
	offs = (state & 1) ? &c->m_current_offs : &c->m_default_offs;
	crop = (state & 2) ? &c->m_current_crop : &c->m_default_crop;
	trim = (state & 4) ? &c->m_current_trim : &c->m_default_trim;
	wc = crop->w;
	hc = crop->h;
	wt = trim->w;
	ht = trim->h;
	sceGuTexScale(offs->w * wc * wt, offs->h * hc * ht);
	sceGuTexOffset((offs->x * wc + crop->x) * wt + trim->x, (offs->y * hc + crop->y) * ht + trim->y);
}
