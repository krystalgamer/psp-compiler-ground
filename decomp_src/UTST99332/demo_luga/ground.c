/* cflags: -O3 -fno-inline */
/* data-align: 16 */
#include "common.h"

/* declarations recovered from DWARF */
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
typedef struct SceGimPicture SceGimPicture;
typedef unsigned int uint;
struct _anon3;
struct _anon4;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon4 { /* size 0x24 */
    ScePspFVector3 trans;
    ScePspFVector3 rotate;
    ScePspFVector3 scale;
};
typedef struct _anon4 geWORLD;
struct _anon5;
struct ScePspFMatrix4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
} __attribute__((aligned(16)));
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct _anon5 { /* size 0xb0 */
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
typedef struct _anon5 geOBJECT;
struct _anon3 { /* size 0xb50 */
    int walkmode;
    int nextgnd;
    int count;
    int light_dir;
    int light_flag;
    int light_cnt;
    int obj_num;
    int tex_num;
    int face;
    int face_cnt;
    int face_wait;
    geWORLD world;
    geOBJECT obj[16];
};
typedef struct _anon3 *PMAINDATA;

extern unsigned char map_0[81000];
extern unsigned char map_1[107088];
extern unsigned char map_2[107996];
extern unsigned char map_3[88468];
extern unsigned char map_4[100296];
extern unsigned char map_5[57536];
extern PMAINDATA md;

int post_ground(void);
void set_nextgnd(void);
void texture_gorund(SceGimPicture *picture);
void init_ground(void);
void draw_ground(void);
static void __sort_gnd(int *lst)
{
	geOBJECT *o0, *o1;
	int tmp;
	int i, j;

	for (i = 0; i < 4; i++)
		lst[i] = i;

	for (i = 0; i < 3; i++) {
		for (j = i + 1; j < 4; j++) {
			o0 = &md->obj[i + 2];
			o1 = &md->obj[j + 2];
			if (o0->t.z > o1->t.z) {
				tmp = lst[i];
				lst[i] = lst[j];
				lst[j] = tmp;
			}
		}
	}
}

static uint set_ground_light(float z)
{
	uint c;

	z += 240.0f;
	if (0.0f < z && z <= 126.0f) {
		c = 255.0f - z;
		c *= 0x20202;
		return c | 0xff000000;
	} else if (126.0f < z && z <= 264.0f) {
		c = 0xff030303;
		return c;
	} else if (264.0f < z && z <= 390.0f) {
		c = 255.0f - (390.0f - z);
		c *= 0x20202;
		return c | 0xff000000;
	}
	return 0xffffffff;
}


/* module functions defined in other units */
int geModelLoad(int num, int *model, int size);
void geModelNormalTexFunc(SceGimPicture *picture);
void geModelSetTexFunc(void (*callback)(SceGimPicture *));
void geModelTexFunc(int mode);
void geObjectDraw(geOBJECT *obj);
int geTexSend(int n);
void light_ctrl(uint c);

int post_ground(void)
{
	int i;
	int ret = 0;
	geOBJECT *obj;

	for (i = 0; i < 4; i++) {
		obj = &md->obj[i + 2];

		switch (md->walkmode) {
		case 0:
			obj->t.z += 2.0f;
			if (obj->t.z >= 150.0f) {
				obj->t.z -= 800.0f;
				obj->model = md->nextgnd;
				md->nextgnd++;
				if (md->nextgnd >= 9)
					md->nextgnd = 3;
				ret = 1;
			}
			break;
		case 1:
			obj->t.z -= 2.0f;
			if (obj->t.z <= -650.0f) {
				obj->t.z += 800.0f;
				obj->model = md->nextgnd;
				md->nextgnd--;
				if (md->nextgnd < 3)
					md->nextgnd = 8;
				ret = 1;
			}
			break;
		}
	}

	for (i = 0; i < 4; i++) {
		if (md->obj[i + 2].model == 8)
			break;
	}

	if (i < 4) {
		obj = &md->obj[i + 2];
		light_ctrl(set_ground_light(obj->t.z));
	} else {
		light_ctrl(-1);
	}

	return ret;
}

void set_nextgnd(void)
{
	int lst[4];
	int n;

	__sort_gnd(lst);

	switch (md->walkmode) {
	case 0:
		n = lst[0] + 2;
		md->nextgnd = md->obj[n].model + 1;
		if (md->nextgnd >= 9)
			md->nextgnd = 3;
		break;
	case 1:
		n = lst[3] + 2;
		md->nextgnd = md->obj[n].model - 1;
		if (md->nextgnd < 3)
			md->nextgnd = 8;
		break;
	}
}

void texture_gorund(SceGimPicture *picture)
{
	switch (md->obj_num) {
	case 3:
		if (md->tex_num == 0) {
			geTexSend(1);
		} else {
			geModelNormalTexFunc(picture);
		}
		break;
	case 4:
		if (md->tex_num == 0) {
			geTexSend(1);
		} else {
			geModelNormalTexFunc(picture);
		}
		break;
	case 5:
		if (md->tex_num == 0) {
			geTexSend(1);
		} else {
			geModelNormalTexFunc(picture);
		}
		break;
	case 6:
		if (md->tex_num == 0) {
			geTexSend(1);
		} else {
			geModelNormalTexFunc(picture);
		}
		break;
	case 7:
		if (md->tex_num == 0) {
			geTexSend(1);
		} else {
			geModelNormalTexFunc(picture);
		}
		break;
	case 8:
		if (md->tex_num == 0) {
			geTexSend(1);
		} else {
			geModelNormalTexFunc(picture);
		}
		break;
	default:
		geModelNormalTexFunc(picture);
		break;
	}
	md->tex_num++;
}

void init_ground(void)
{
	geModelLoad(3, (int *)map_0, sizeof(map_0) / 4);
	geModelLoad(4, (int *)map_1, sizeof(map_1) / 4);
	geModelLoad(5, (int *)map_2, sizeof(map_2) / 4);
	geModelLoad(6, (int *)map_3, sizeof(map_3) / 4);
	geModelLoad(7, (int *)map_4, sizeof(map_4) / 4);
	geModelLoad(8, (int *)map_5, sizeof(map_5) / 4);

	md->obj[2] = (geOBJECT){ 0, 3, 0, 0.0f, { 0.0f, 0.0f, -100.0f }, { 0.0f, 180.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };
	md->obj[3] = (geOBJECT){ 0, 4, 0, 0.0f, { 0.0f, 0.0f, -300.0f }, { 0.0f, 180.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };
	md->obj[4] = (geOBJECT){ 0, 5, 0, 0.0f, { 0.0f, 0.0f, -500.0f }, { 0.0f, 180.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };
	md->obj[5] = (geOBJECT){ 0, 6, 0, 0.0f, { 0.0f, 0.0f, -700.0f }, { 0.0f, 180.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };

	md->nextgnd = 6;
}

void draw_ground(void)
{
	int lst[4];
	int i;

	__sort_gnd(lst);

	geModelTexFunc(1);
	geModelSetTexFunc(texture_gorund);
	for (i = 0; i < 4; i++) {
		md->obj_num = md->obj[lst[i] + 2].model;
		md->tex_num = 0;
		geObjectDraw(&md->obj[lst[i] + 2]);
	}
	geModelTexFunc(0);
	geModelSetTexFunc(NULL);
}

void term_ground(void) {
    geModelDelete(3);
    geModelDelete(4);
    geModelDelete(5);
    geModelDelete(6);
    geModelDelete(7);
    geModelDelete(8);
}






