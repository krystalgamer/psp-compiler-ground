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
};
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
extern float bg[6];
extern gePRIM bg_inf;

void init_bg(void);
int proc_bg(void *p);
void draw_bg(void);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuDisable(int state);

/* module functions defined in other units */
void geDrawArray(gePRIM *p);
void geObjectDraw(geOBJECT *obj);
void geObjectSetProc(int n, int (*proc)(void *));

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/bg", init_bg);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/bg", proc_bg);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/bg", draw_bg);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/bg", D_00021580);
