/* cflags: -O3 */
#include "common.h"

/* declarations recovered from DWARF */
typedef struct SceGimPicture SceGimPicture;
struct SceGimPicture;
struct _anon1;
struct _anon1 { /* size 0x30 */
    short unsigned int header_size;
    short unsigned int reference;
    short unsigned int format;
    short unsigned int order;
    short unsigned int width;
    short unsigned int height;
    short unsigned int bpp;
    short unsigned int pitch_align;
    short unsigned int height_align;
    short unsigned int dim_count;
    short unsigned int reserved;
    short unsigned int reserved2;
    unsigned int offsets;
    unsigned int images;
    unsigned int total;
    unsigned int plane_mask;
    short unsigned int level_type;
    short unsigned int level_count;
    short unsigned int frame_type;
    short unsigned int frame_count;
};
typedef struct _anon1 SceGimImageHeader;
struct _anon2;
struct _anon2 { /* size 0x20 */
    short unsigned int header_size;
    short unsigned int reference;
    short unsigned int frame_start;
    short unsigned int frame_end;
    short unsigned int frame_rate;
    short unsigned int reserved;
    short unsigned int n_constants;
    short unsigned int n_functions;
    unsigned int constants;
    unsigned int functions;
    unsigned int keyframes;
    unsigned int total;
};
typedef struct _anon2 SceGimSequenceHeader;
struct SceGimPicture { /* size 0x54 */
    int m_reference;
    int m_flags;
    SceGimImageHeader *m_image;
    SceGimImageHeader *m_palette;
    SceGimSequenceHeader *m_sequence;
    int m_buf_width;
    int m_clut_load;
    float m_frame_loop[2];
    float m_frame_rate;
    float m_frame;
    int m_enable_bits;
    int m_image_frame;
    int m_image_frame2;
    int m_palette_frame;
    int m_palette_frame2;
    float m_dissolve;
    float m_image_crop[4];
};
struct _anon3;
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
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
} __attribute__((aligned(16)));
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef unsigned int uint;
struct _anon3 { /* size 0xb0 */
    int type;
    int model;
    int motion;
    float step;
    ScePspFVector3 t;
    ScePspFVector3 r;
    ScePspFVector3 s;
    ScePspFMatrix4 m;
    ScePspFVector3 co[2];
    uint swflag;
    int dummy[3];
};
typedef struct _anon3 geOBJECT;
typedef struct SceGmoModel SceGmoModel;
struct SceGmoModel;

extern char ge_heap_buf[2097152];
extern SceGmoModel *ge_model[128];
extern int ge_tex_mode;
extern void (*ge_tex_callback)(SceGimPicture *);
extern int (*ObjProc[128])(void *);

void geModelNormalTexFunc(SceGimPicture *picture);
void geObjectDraw(geOBJECT *obj);
float geModelMotionFrame(int num);
void geModelDraw(int num, float step);
int geModelLoad(int num, int *model, int size);
void geModelDelete(int num);
void geModelMotion(int num, int motion);
void geModelInit(int heap);
void geModelTexFunc(int mode);
void geModelTerm(void);
void geModelSetTexFunc(void (*callback)(SceGimPicture *));
int geModelDoTextureFunc(SceGimPicture *picture);
void geObjectSetProc(int n, int (*proc)(void *));
void geObjectSwitch(geOBJECT *obj, int num);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuEnable(int state);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexWrap(int u, int v);
void sceGumMatrixMode(int mode);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumStoreMatrix(ScePspFMatrix4 *m);
void sceGumTranslate(const ScePspFVector3 *v);

/* module functions defined in other units */
void geDrawFinWait(void);
void geDrawStart(void);
void sceGmoModelAnimate(SceGmoModel *model, float step);
void sceGmoModelDelete(SceGmoModel *model);
void sceGmoModelDraw(SceGmoModel *model);
void sceGmoModelSetCurrentMotion(SceGmoModel *model, int idx, float delay);
void sceGmoModelUpdate(SceGmoModel *model);

/* module functions defined in other units */
int sceGmoModelGetCurrentMotion(SceGmoModel *model);

void geModelNormalTexFunc(SceGimPicture *picture)
{
	if (picture == 0)
		return;
	if (picture->m_flags == 0) {
		SceGimImageHeader *image = picture->m_image;
		if (image != 0) {
			void **offsets;
			sceGuTexMode(image->format, 0, 0, image->order);
			offsets = (void **)((char *)image + image->offsets);
			sceGuTexImage(0, image->width, image->height, picture->m_buf_width, *offsets);
		}
		{
		SceGimImageHeader *palette = picture->m_palette;
		if (palette != 0) {
			void **offsets;
			sceGuClutMode(palette->format, 0, 255, 0);
			offsets = (void **)((char *)palette + palette->offsets);
			sceGuClutLoad(picture->m_clut_load, *offsets);
		}
		}
		return;
	}
}

SceGmoModel *sceGmoModelCreate(void *chunk);
int sceGmoModelLoadFile(SceGmoModel *model, const void *buf, int size, int index);

int geModelLoad(int num, int *data, int size)
{
	SceGmoModel *model;

	ge_model[num] = model = sceGmoModelCreate(NULL);
	if (!sceGmoModelLoadFile(model, data, size, 0)) {
		sceGmoModelDelete(model);
		ge_model[num] = NULL;
		return -1;
	}
	sceGmoModelSetCurrentMotion(model, 0, 0.1f);
	return num;
}

void geModelDelete(int num)
{
	sceGmoModelDelete(ge_model[num]);
	ge_model[num] = NULL;
}

void sceGmoModelSetWorldMatrix(SceGmoModel *model, const ScePspFMatrix4 *matrix);

void geModelDraw(int num, float step)
{
	ScePspFMatrix4 m;
	SceGmoModel *model = ge_model[num];

	if (model != NULL) {
		sceGumMatrixMode(2);
		sceGumStoreMatrix(&m);
		sceGmoModelSetWorldMatrix(model, &m);
		sceGmoModelAnimate(model, step);
		sceGmoModelUpdate(model);
		sceGmoModelDraw(model);
	}
}

void geModelMotion(int num, int motion)
{
	sceGmoModelSetCurrentMotion(ge_model[num], motion, 0.1f);
}

struct SceGmoMotion *sceGmoModelGetMotion(SceGmoModel *model, int idx);
float sceGmoMotionGetFrame(struct SceGmoMotion *motion);

float geModelMotionFrame(int num)
{
	SceGmoModel *model = ge_model[num];

	return sceGmoMotionGetFrame(sceGmoModelGetMotion(model, sceGmoModelGetCurrentMotion(model)));
}

void vram_heap__init(int mode);
void *vram_heap__alloc(unsigned int size);
void vram_heap__free(void *ptr);
void my_heap__init(void *addr, unsigned int size);
void *my_heap__alloc(unsigned int size);
void my_heap__free(void *ptr);
void sceGimPictureSetMemoryManager(void *(*alloc)(unsigned int), void (*free)(void *));
void sceGimPictureSetMemoryManager2(void *(*alloc)(unsigned int), void (*free)(void *));
void sceGmoModelSetMemoryManager(void *(*alloc)(unsigned int), void (*free)(void *));
void sceGmoModelSetMemoryManager2(void *(*alloc)(unsigned int), void (*free)(void *));
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuEnable(int state);

void geModelInit(int heap)
{
	int i;

	vram_heap__init(heap);
	sceGimPictureSetMemoryManager(vram_heap__alloc, vram_heap__free);
	sceGimPictureSetMemoryManager2(vram_heap__alloc, vram_heap__free);

	my_heap__init(ge_heap_buf, sizeof(ge_heap_buf));
	sceGmoModelSetMemoryManager(my_heap__alloc, my_heap__free);
	sceGmoModelSetMemoryManager2(my_heap__alloc, my_heap__free);

	for (i = 0; i < 128; i++) {
		ge_model[i] = NULL;
	}

	ge_tex_callback = NULL;
	ge_tex_mode = 0;

	geDrawStart();
	sceGuEnable(9);
	sceGuTexFilter(5, 1);
	sceGuTexFunc(0, 1);
	sceGuTexWrap(0, 0);
	geDrawFinWait();
}

void geModelTerm(void)
{
	int i;

	for (i = 0; i < 128; i++) {
		if (ge_model[i] != NULL) {
			sceGmoModelDelete(ge_model[i]);
			ge_model[i] = NULL;
		}
	}
}

void geModelTexFunc(int mode) {
    ge_tex_mode = mode;
}

void geModelSetTexFunc(void (*callback)(SceGimPicture *)) {
    ge_tex_callback = callback;
}

int geModelDoTextureFunc(SceGimPicture *picture) {
    int var_a1;

    var_a1 = 0;
    switch (ge_tex_mode) {                          /* irregular */
    case 0:
        break;
    case 1:
        if (ge_tex_callback != NULL) {
            ge_tex_callback(picture);
            var_a1 = 1;
        }
        break;
    }
    return var_a1;
}

void geObjectSetProc(int n, int (*proc)(void *)) {
    ObjProc[n] = proc;
}

void geObjectDraw(geOBJECT *obj)
{
	sceGumPushMatrix();

	sceGumTranslate(&obj->t);
	sceGumRotateX(obj->r.x * 3.14159265f / 180.0f);
	sceGumRotateY(obj->r.y * 3.14159265f / 180.0f);
	sceGumRotateZ(obj->r.z * 3.14159265f / 180.0f);
	sceGumScale(&obj->s);

	switch (obj->type) {
	case 0:
		if (obj->swflag & 0x80000000) {
			if (geModelMotionFrame(obj->model) <= 1.0f) {
				obj->model = obj->swflag & 0x7fffffff;
				obj->swflag = 0x40000000;
			}
		} else if (obj->swflag & 0x40000000) {
			obj->swflag = 0;
		}
		sceGumStoreMatrix(&obj->m);
		geModelDraw(obj->model, obj->step);
		break;
	case 1:
		ObjProc[obj->model](obj);
		break;
	}

	sceGumPopMatrix();
}

void geObjectSwitch(geOBJECT *obj, int num) {
    int temp_a2;

    if (obj->type == 0) {
        temp_a2 = obj->swflag;
        if ((temp_a2 >= 0) && !(temp_a2 & 0x40000000)) {
            obj->swflag = num | 0x80000000;
        }
    }
}
