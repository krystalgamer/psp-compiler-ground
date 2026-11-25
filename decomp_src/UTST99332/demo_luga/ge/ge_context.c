#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
typedef unsigned int uint;
struct _anon1 { /* size 0x3c */
    int type;
    int comp;
    ScePspFVector3 vec;
    uint diff_col;
    uint spec_col;
    float spot_s;
    float spot_c;
    ScePspFVector3 spot_vec;
    float att_a;
    float att_b;
    float att_c;
};
typedef struct _anon1 geLIGHT;
struct _anon2;
struct _anon2 { /* size 0x34 */
    float cam_fovy;
    float cam_aspect;
    float cam_near;
    float cam_far;
    ScePspFVector3 cam_eye;
    ScePspFVector3 cam_center;
    ScePspFVector3 cam_up;
};
typedef struct _anon2 geCAMERA;
struct _anon3;
struct _anon4;
struct _anon4 { /* size 0xc */
    float zs;
    float ze;
    uint col;
};
typedef struct _anon4 geFOG;
struct _anon5;
struct _anon5 { /* size 0xc */
    int func;
    int aref;
    int amsk;
};
typedef struct _anon5 geALPHA;
struct _anon6;
struct _anon6 { /* size 0x14 */
    int equ;
    int asel;
    int bsel;
    int afix;
    int bfix;
};
typedef struct _anon6 geBLEND;
struct _anon3 { /* size 0x80 */
    int vramdepth;
    int offset_x;
    int offset_y;
    int depth_min;
    int depth_max;
    uint col_clear;
    uint col_ambient;
    uint col_model;
    int depth_test;
    int shade_mode;
    int front_face;
    int clip_plane;
    int normal_patch;
    int normal_prim;
    int cull_face;
    int dither;
    int col_material;
    float specular;
    int fog;
    geFOG fog_param;
    int alpha;
    geALPHA alpha_param;
    int blend;
    geBLEND blend_param;
};
typedef struct _anon3 geCONTEXT;
struct _anon7;
struct _anon7 { /* size 0x24 */
    ScePspFVector3 trans;
    ScePspFVector3 rotate;
    ScePspFVector3 scale;
};
typedef struct _anon7 geWORLD;
typedef unsigned char uchar;
struct ScePspFMatrix4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct ScePspIMatrix4;
struct ScePspIVector4;
struct ScePspIVector4 { /* size 0x10 */
    int x;
    int y;
    int z;
    int w;
};
typedef struct ScePspIVector4 ScePspIVector4;
struct ScePspIMatrix4 { /* size 0x40 */
    ScePspIVector4 x;
    ScePspIVector4 y;
    ScePspIVector4 z;
    ScePspIVector4 w;
};
typedef struct ScePspIMatrix4 ScePspIMatrix4;

extern ScePspFMatrix4 ge_matrix_stack[32];
extern ScePspIMatrix4 ge_dith;
extern geCONTEXT *pCont;

void geSetLight(int n, int param, geLIGHT *light);
void geSetCamera(int param, geCAMERA *camera);
void geSetContext(geCONTEXT *context);
void geGetContext(geCONTEXT *context);
void geSetWorld(geWORLD *world);
void geColor(uchar r, uchar g, uchar b, uchar a);
static void init_context(void);
static void set_mode(int mode, int state);


INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_context", geSetLight);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_context", geSetCamera);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_context", geSetContext);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_context", geGetContext);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_context", geSetWorld);

void gePush(void) {
    sceGumPushMatrix();
}

void gePop(void) {
    sceGumPopMatrix();
}

void geIdentity(void) {
    sceGumLoadIdentity();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_context", geColor);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_context", init_context);
