/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef unsigned int uint;
typedef unsigned char uchar;
struct _anon1 { /* size 0x18 */
    void (*init)(void);
    void (*pre)(void);
    int (*pad)(uint, uint, uchar *);
    void (*draw)(void);
    void (*post)(void);
    void (*deinit)(void);
};
typedef struct _anon1 geMODULE;
struct _anon2;
typedef unsigned int u_int32;
struct _anon2 { /* size 0x20 */
    int flag;
    int mode;
    int num_module;
    int exitflag;
    int pad_margin;
    u_int32 cont;
    u_int32 vcount;
    u_int32 rand_data;
};
typedef struct _anon2 gePROGRAM;
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
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon7 { /* size 0x34 */
    float cam_fovy;
    float cam_aspect;
    float cam_near;
    float cam_far;
    ScePspFVector3 cam_eye;
    ScePspFVector3 cam_center;
    ScePspFVector3 cam_up;
};
typedef struct _anon7 geCAMERA;

extern char ge_displist[2][327680];
extern int ge_cdb;
extern void *ge_fbp[2][2];
extern int ge_start;
extern gePROGRAM geProgram;
extern geCONTEXT geContext;
extern geMODULE geModule[128];
extern gePROGRAM *pProg;
extern geCONTEXT *pCont;
extern geMODULE geModuleCommon;
extern geCONTEXT def_context;
extern geCAMERA def_camera;

void geDrawStart(void);
int geSetModule(int num, geMODULE *module);
void geDrawFinWait(void);
void geSendProc(void (*func)(void));
void geInit(void);
int geMainLoop(void);
static void pre_func(void);
static void post_func(void);
void geExit(void);
void geRandomSeed(uint seed);
int geRandom(void);
static void draw_func(void);
static void pad_func(void);
static void program_switch(void);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlSetSamplingCycle(int cycle);
int sceCtrlSetSamplingMode(int mode);
int sceDisplayWaitVblankStartCB(void);
void sceGuClear(int flags);
int sceGuDisplay(int state);
void sceGuDrawBufferList(int psm, void *fbp, int frame_width);
int sceGuFinish(void);
void sceGuInit(void);
void sceGuSendList(int mode, const void *list, void *context);
void sceGuStart(int type, void *list, int size);
void *sceGuSwapBuffers(void);
int sceGuSync(int mode, int what);

/* module functions defined in other units */
void geCommonInit(void);
void geFadeDraw(void);
void geModelInit(int heap);
void geSetCamera(int param, geCAMERA *camera);
void geSetContext(geCONTEXT *context);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_main", geDrawStart);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_main", geSetModule);

void geDrawFinWait(void) {
    if (ge_start != 0) {
        if (ge_start != 1) {
            ge_start -= 1;
        } else {
            sceGuFinish();
            sceGuSync(0, 0);
            sceDisplayWaitVblankStartCB();
            sceGuSendList(0, ge_displist[ge_cdb], NULL);
            ge_start = 0;
            ge_cdb ^= 1;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_main", geSendProc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_main", geInit);

void geTerm(void) {
    geModelTerm();
    sceGuTerm();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_main", geMainLoop);

void geExit(void) {
    pProg->exitflag = 1;
}

void geRandomSeed(unsigned int seed) {
    pProg->rand_data = seed;
}

int geRandom(void) {
    unsigned int temp_a0;

    temp_a0 = (pProg->rand_data * 0x4E6D) + 0x3039;
    pProg->rand_data = temp_a0;
    return (int) (temp_a0 >> 4);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_main", draw_func);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_main", pad_func);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_main", program_switch);
