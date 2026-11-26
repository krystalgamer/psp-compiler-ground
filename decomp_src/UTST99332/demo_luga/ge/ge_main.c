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

void geDrawStart(void)
{
	if (ge_start != 0) {
		ge_start++;
		return;
	}

	ge_start = 1;
	sceGuStart(2, ge_displist[ge_cdb], sizeof(ge_displist[0]));
	if (pCont->vramdepth == 1) {
		sceGuDrawBufferList(1, ge_fbp[0][ge_cdb], 512);
	} else if (pCont->vramdepth == 3) {
		sceGuDrawBufferList(3, ge_fbp[1][ge_cdb], 512);
	}
}

int geSetModule(int num, geMODULE *module)
{
	int id;
	unsigned int i;

	if (num >= 128) {
		return -1;
	}

	if (num == -1) {
		id = pProg->num_module;
		if (id >= 128) {
			return -1;
		}
		pProg->num_module = id + 1;
	} else {
		id = num;
	}

	for (i = 0; i < 6; i++) {
		((u32 *)&geModule[id])[i] = ((u32 *)module)[i];
	}

	return id;
}

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

void geSendProc(void (*func)(void))
{
	geDrawStart();
	if (func != NULL) {
		func();
	}

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

void geInit(void)
{
	ge_start = 0;
	pProg = &geProgram;
	pCont = &geContext;

	sceCtrlSetSamplingMode(1);
	sceCtrlSetSamplingCycle(0);
	sceGuInit();

	geSetContext(&def_context);
	geSetCamera(-1, &def_camera);

	geCommonInit();

	geModelInit(1);

	sceGuDisplay(1);

	pProg->cont = 0;
	pProg->mode = 0;
	pProg->pad_margin = 16;
	pProg->flag = 0;
}

void geTerm(void) {
    geModelTerm();
    sceGuTerm();
}

static inline void pre_func(void)
{
	if (geModuleCommon.pre != NULL) {
		geModuleCommon.pre();
	}
	if (geModule[pProg->mode].pre != NULL) {
		geModule[pProg->mode].pre();
	}
}

static inline void post_func(void)
{
	if (geModuleCommon.post != NULL) {
		geModuleCommon.post();
	}
	if (geModule[pProg->mode].post != NULL) {
		geModule[pProg->mode].post();
	}
}

int geMainLoop(void)
{
	pProg->vcount = 0;
	pProg->exitflag = 0;

	do {
		program_switch();
		pre_func();

		pad_func();
		draw_func();

		post_func();

		sceGuSwapBuffers();
		pProg->vcount = (pProg->vcount + 1) & 0x7fffffff;
	} while (pProg->exitflag == 0);

	return 0;
}

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

static void draw_func(void)
{
	geDrawStart();

	sceGuClear(0x17);

	if (geModule[pProg->mode].draw != NULL) {
		geModule[pProg->mode].draw();
	}

	geFadeDraw();

	if (geModuleCommon.draw != NULL) {
		geModuleCommon.draw();
	}

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

typedef struct SceCtrlData {
	unsigned int TimeStamp;
	unsigned int Buttons;
	unsigned char Lx;
	unsigned char Ly;
	unsigned char Rsrv[6];
} SceCtrlData;

int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

static void pad_func(void)
{
	SceCtrlData buf;
	uchar analog[2];
	uint old;
	uint padd;
	int i;

	old = pProg->cont;

	if (sceCtrlReadBufferPositive(&buf, 1) != 0) {
		pProg->cont = buf.Buttons;
		analog[0] = buf.Lx;
		analog[1] = buf.Ly;
	} else {
		pProg->cont = 0;
		analog[0] = 127;
		analog[1] = 127;
	}

	padd = pProg->cont & (pProg->cont ^ old);

	for (i = 0; i < 2; i++) {
		if ((127 - pProg->pad_margin) < analog[i] && analog[i] < (127 + pProg->pad_margin)) {
			analog[i] = 127;
		}
	}

	if (geModuleCommon.pad != NULL) {
		geModuleCommon.pad(padd, pProg->cont, analog);
	}

	if (geModule[pProg->mode].pad != NULL) {
		if (geModule[pProg->mode].pad(padd, pProg->cont, analog)) {
			pProg->exitflag = 1;
		}
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_main", program_switch);
