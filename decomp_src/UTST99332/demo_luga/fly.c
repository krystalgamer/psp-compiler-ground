/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon2;
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
struct _anon2 { /* size 0x24 */
    ScePspFVector3 trans;
    ScePspFVector3 rotate;
    ScePspFVector3 scale;
};
typedef struct _anon2 geWORLD;
struct _anon3;
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
struct _anon1 { /* size 0xb50 */
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
typedef struct _anon1 *PMAINDATA;
struct _anon4;
struct _anon4 { /* size 0x14 */
    int prim;
    int type;
    int count;
    void *index;
    void *p;
};
typedef struct _anon4 gePRIM;

extern PMAINDATA md;
extern float fly[10];
extern gePRIM fly_inf;

void post_fly(void);
void init_fly(void);
int proc_fly(void *p);
void draw_fly(void);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGumScale(const ScePspFVector3 *v);

/* module functions defined in other units */
void geDrawArray(gePRIM *p);
void geObjectDraw(geOBJECT *obj);
void geObjectSetProc(int n, int (*proc)(void *));
int geTexSend(int n);

/* module functions defined in other units */
void geColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void gePop(void);
void gePush(void);

void post_fly(void)
{
	int i;
	geOBJECT *obj;

	for (i = 0; i < 6; i++) {
		obj = &md->obj[6 + i];
		obj->motion -= 5;
		if (obj->motion < 0) {
			obj->motion = 0;
		}

		switch (md->walkmode) {
		case 0:
			obj->t.z += 6.0f;
			if (obj->t.z > 10.0f) {
				obj->motion = 255;
				obj->t.z -= 200.0f;
			}
			break;
		case 1:
			obj->t.z -= 6.0f;
			if (obj->t.z < -200.0f) {
				obj->motion = 255;
				obj->t.z = 10.0f;
			}
			break;
		}
	}
}

void init_fly(void)
{
	geObjectSetProc(2, proc_fly);

	md->obj[6] = (geOBJECT){ 1, 2, 255, 0.0f, { 8.0f, 16.0f, -100.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };
	md->obj[7] = (geOBJECT){ 1, 2, 255, 0.0f, { -8.0f, 16.0f, -300.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };
	md->obj[8] = (geOBJECT){ 1, 2, 255, 0.0f, { 12.0f, 12.0f, -240.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };
	md->obj[9] = (geOBJECT){ 1, 2, 255, 0.0f, { -12.0f, 12.0f, -180.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };
	md->obj[10] = (geOBJECT){ 1, 2, 255, 0.0f, { -2.0f, 22.0f, -90.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };
	md->obj[11] = (geOBJECT){ 1, 2, 255, 0.0f, { 2.0f, 22.0f, -130.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };
}

int proc_fly(void *p)
{
	geOBJECT *obj = (geOBJECT *)p;
	ScePspFVector3 scale;

	geTexSend(0);
	geColor(0xFF, 0xFF, 0xFF, obj->motion);
	geDrawArray(&fly_inf);

	gePush();
	scale = (ScePspFVector3){ 2.0f, 2.0f, 2.0f };
	geColor(0xFF, 0xFF, 0xFF, 0x40);
	sceGumScale(&scale);
	geDrawArray(&fly_inf);
	gePop();

	return 0;
}

void draw_fly(void)
{
	int i;

	for (i = 0; i < 6; i++) {
		geObjectDraw(&md->obj[6 + i]);
	}
}







