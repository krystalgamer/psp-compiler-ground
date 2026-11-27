/* cflags: -O2 -frename-registers */
/* data-align: 16 */
#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int uint;
typedef unsigned char uchar;
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

extern unsigned char run[162720];
extern unsigned char roll[173468];
extern unsigned char jump[200912];
extern PMAINDATA md;

int pad_char(uint padd, uint cont, uchar *axis);
void post_char(void);
void init_char(void);
void set_char_pos(void);
void texture_char(SceGimPicture *picture);
void draw_char(void);


/* module functions defined in other units */
int geModelLoad(int num, int *model, int size);
void geModelNormalTexFunc(SceGimPicture *picture);
void geModelSetTexFunc(void (*callback)(SceGimPicture *));
void geModelTexFunc(int mode);
void geObjectDraw(geOBJECT *obj);
void geObjectSwitch(geOBJECT *obj, int num);
int geRandom(void);
int geTexSend(int n);

int pad_char(uint padd, uint cont, uchar *axis)
{
	geOBJECT *obj = &md->obj[0];

	obj->t.x += ((float)axis[0] - 127.0f) * 0.0025f;

	obj->t.z += ((float)axis[1] - 127.0f) * 0.0025f;

	if (cont & 0x10)
		obj->t.z -= 0.2f;

	if (cont & 0x40)
		obj->t.z += 0.2f;

	if (cont & 0x80)
		obj->t.x -= 0.2f;

	if (cont & 0x20)
		obj->t.x += 0.2f;

	if (obj->t.z < -60.0f)
		obj->t.z = -60.0f;
	if (obj->t.z > -10.0f)
		obj->t.z = -10.0f;

	if (obj->t.x < -14.0f)
		obj->t.x = -14.0f;
	if (obj->t.x > 14.0f)
		obj->t.x = 14.0f;

	if (obj->model == 0) {
		if (padd & 0x2000)
			geObjectSwitch(obj, 1);

		if (padd & 0x4000)
			geObjectSwitch(obj, 2);
	} else {
		geObjectSwitch(obj, 0);
	}

	return 0;
}

void post_char(void)
{
	PMAINDATA m = md;
	int wait[5] = { 0, 15, 50, 50, 70 };

	if (m->obj[0].model != 0) {
		m->face = 3;
		m->face_cnt = wait[3] - 1;
	} else {
		m->face_cnt++;
		if (m->face == 0) {
			if (m->face_cnt > m->face_wait) {
				m->face_cnt = 0;
				m->face = geRandom() % 4 + 1;
			}
		} else {
			if (m->face_cnt > wait[m->face]) {
				m->face_cnt = 0;
				m->face = 0;
				m->face_wait = geRandom() % 10 * 10 + 180;
			}
		}
	}
}

void init_char(void)
{
	geModelLoad(0, (int *)run, sizeof(run) / 4);
	geModelLoad(1, (int *)roll, sizeof(roll) / 4);
	geModelLoad(2, (int *)jump, sizeof(jump) / 4);

	md->obj[0] = (geOBJECT){ 0, 0, 0, 1.0f / 30.0f, { 6.0f, 0.0f, -20.0f }, { 0.0f, 180.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };

	md->face_cnt = 0;
	md->face = 0;
	md->face_wait = geRandom() % 10 * 10 + 180;
}

void set_char_pos(void)
{
	geOBJECT *obj = &md->obj[0];

	switch (md->walkmode) {
	case 0:
		obj->t.x = 6.0f;
		obj->t.z = -20.0f;
		obj->r.y = 180.0f;
		break;
	case 1:
		obj->t.x = -6.0f;
		obj->t.z = -42.0f;
		obj->r.y = 0.0f;
		break;
	}
}

void texture_char(SceGimPicture *picture)
{
	if (md->tex_num == 5) {
		geTexSend(md->face + 2);
	} else {
		geModelNormalTexFunc(picture);
	}
	md->tex_num++;
}

void draw_char(void) {
    geModelTexFunc(1);
    geModelSetTexFunc(texture_char);
    md->tex_num = 0;
    geObjectDraw(md->obj);
    geModelTexFunc(0);
    geModelSetTexFunc(NULL);
}

void term_char(void) {
    geModelDelete(0);
}


