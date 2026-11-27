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
typedef short unsigned int ushort;
struct _anon4 { /* size 0xa */
    ushort u;
    ushort v;
    short int p[3];
};
typedef struct _anon4 ge2DV16T;
struct _anon5;
struct _anon5 { /* size 0x14 */
    int prim;
    int type;
    int count;
    void *index;
    void *p;
};
typedef struct _anon5 gePRIM;

extern PMAINDATA md;
extern ge2DV16T logo[2];
extern gePRIM logo_inf;

void init_logo(void);
int proc_logo(void *p);
void draw_logo(void);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuDisable(int state);
void sceGuEnable(int state);

/* module functions defined in other units */
void geDrawArray(gePRIM *p);
void geObjectDraw(geOBJECT *obj);
void geObjectSetProc(int n, int (*proc)(void *));
int geTexSend(int n);

void init_logo(void)
{
	geObjectSetProc(3, proc_logo);
	md->obj[14] = (geOBJECT){ 1, 3, 0, 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };
}

int proc_logo(void *p) {
    sceGuDisable(1);
    geTexSend(7);
    geColor(0xFF, 0xFF, 0xFF, 0xFF);
    geDrawArray(&logo_inf);
    sceGuEnable(1);
    return 0;
}

void draw_logo(void) {
    geObjectDraw(&md->obj[14]);
}

