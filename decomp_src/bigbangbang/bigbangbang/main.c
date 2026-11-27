#include "common.h"

/* declarations recovered from DWARF */
typedef struct ScePspIMatrix4 ScePspIMatrix4;
struct ScePspIMatrix4;
typedef struct ScePspIVector4 ScePspIVector4;
struct ScePspIVector4;
struct ScePspIVector4 { /* size 0x10 */
    int x;
    int y;
    int z;
    int w;
};
struct ScePspIMatrix4 { /* size 0x40 */
    ScePspIVector4 x;
    ScePspIVector4 y;
    ScePspIVector4 z;
    ScePspIVector4 w;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
struct _anon1;
typedef short unsigned int u_short16;
struct _anon1 { /* size 0xa */
    u_short16 u;
    u_short16 v;
    short int p[3];
} __attribute__((packed)); /* DrawSprite stores it bytewise */
typedef struct _anon1 Gu2dV16T;
struct _anon2;
struct _anon2 { /* size 0x6 */
    short int p[3];
};
typedef struct _anon2 Gu2dV16;
typedef unsigned int u_int32;
typedef struct SceCtrlData SceCtrlData;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef int SceUID;
struct _anon3;
struct _anon3 { /* size 0x8 */
    int flag;
    int mode;
};
typedef struct _anon3 PROG;
struct _anon4;
typedef void voidfunc(void);
typedef void voidfuncuint2(u_int32, u_int32);
struct _anon4 { /* size 0x10 */
    voidfunc *init;
    voidfunc *run;
    voidfunc *draw;
    voidfuncuint2 *key;
};
typedef struct _anon4 FUNCLIST;
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    void *ent_top;
    void *ent_end;
    void *stub_top;
    void *stub_end;
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

extern int exitflag;
extern u_int32 cont;
extern u_int32 vcount;
extern PROG program;
extern FUNCLIST func[1];
extern float sphere[84];
extern float rsphere[18];
extern u_int32 clut_scope[8];
extern u_int32 chr_scope[128];
extern u_int32 clut_water[8];
extern u_int32 chr_water[2048];
extern u_int32 clut_moon[8];
extern u_int32 chr_moon[2048];
extern u_int32 clut_ball[8];
extern u_int32 chr_ball[128];
extern u_int32 clut_mission[8];
extern u_int32 chr_mission[4096];
extern u_int32 clut_ready[128];
extern u_int32 chr_ready[8192];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern const unsigned int __PSPEXP__module_info[2];
extern const unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char displist[327680];
extern ScePspFMatrix4 matrix_stack[48];
extern int __sscale_x;
extern int __sscale_y;
extern int __fade;
extern int __fadestep;
extern int __fadecolor;

static void InitFunc(void);
void DrawSprite(int x, int y, int w, int h, int u, int v, Gu2dV16T *model);
void FadeDraw(void);
static void DrawFunc(void);
static void KeyFunc(void);
static void ProgramSwitch(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStartCB(void);
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelRegisterExitCallback(int cbid);
void sceKernelExitGame(void);



void sceGuSpecular(float power);
void sceGumPerspective(float fovy, float aspect, float near, float far);

int sceCtrlSetSamplingCycle(int cycle);
void sceGuInit(void);
void sceGuStart(int cid, void *list, int size);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGuDepthRange(int near, int far);
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuDepthFunc(int func);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuAlphaFunc(int func, int value, int mask);
void sceGuFrontFace(int order);
void sceGuSetDither(const ScePspIMatrix4 *matrix);
void sceGuShadeModel(int mode);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuSpecular(float power);
void sceGuAmbient(unsigned int color);
void sceGuColor(unsigned int color);
void sceGumSetMatrixStack(ScePspFMatrix4 *m, int proj, int view, int world, int tex);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
int sceDisplayWaitVblankStart(void);
void InitParticle(void);
int sceGuDisplay(int state);
static void InitFunc(void)
{
	const ScePspIMatrix4 dith = {
		{-4, 0, -3, 1},
		{2, -2, 3, -1},
		{-3, 1, -4, 0},
		{3, -1, 2, -2}
	};
	ScePspFVector3 vec;

	sceCtrlSetSamplingCycle(0);
	sceGuInit();
	sceGuStart(0, displist, sizeof(displist));
	sceGuDrawBuffer(1, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x44000, 512);
	sceGuDepthBuffer((void *)0x88000, 512);
	sceGuOffset(2048 - (480 / 2), 2048 - (272 / 2));
	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(50000, 10000);
	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);
	sceGuDepthFunc(7);
	sceGuEnable(1);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
	sceGuAlphaFunc(6, 0, 0xff);
	sceGuDisable(0);
	sceGuFrontFace(0);
	sceGuDisable(9);
	sceGuSetDither(&dith);
	sceGuEnable(6);
	sceGuEnable(8);
	sceGuShadeModel(1);
	vec.x = 0.614497f;
	vec.y = 0.691714f;
	vec.z = 0.379372f;
	sceGuLightColor(0, 2, 0xff808080);
	sceGuLight(0, 0, 2, &vec);
	sceGuEnable(11);
	vec.x = 0.614497f;
	vec.y = 0.691714f;
	vec.z = 0.379372f;
	sceGuLightColor(1, 2, 0x00000000);
	sceGuLightColor(1, 4, 0xffffffff);
	sceGuLight(1, 0, 6, &vec);
	sceGuEnable(12);
	vec.x = -0.614497f;
	vec.y = -0.391714f;
	vec.z = -0.379372f;
	sceGuLightColor(2, 2, 0xffc0c0c0);
	sceGuLight(2, 0, 2, &vec);
	sceGuDisable(13);
	sceGuEnable(10);
	sceGuSpecular(20.0f);
	sceGuDisable(7);
	sceGuAmbient(0xff808080);
	sceGuColor(0xffffffff);
	sceGumSetMatrixStack(matrix_stack, 8, 8, 32, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(3.1415927f / 4.0f, 480.0f / 272.0f, 1.0f, 1000.0f);
	sceGumMatrixMode(2);
	sceGuClearColor(0);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	InitParticle();
	program.flag = 0;
	program.mode = 0;
	sceGuDisplay(1);
}

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/main", D_0000B680);

void SpriteScale(int x, int y) {
    __sscale_x = x;
    __sscale_y = y;
}

void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void DrawSprite(int x, int y, int w, int h, int u, int v, Gu2dV16T *model)
{
	sceGuEnable(9);

	model[0].u=u, model[0].v=v+h;
	model[0].p[0]=(short)x;
	model[0].p[1]=(short)y+(h*__sscale_y);
	model[0].p[2]=0;

	model[1].u=u, model[1].v=v;
	model[1].p[0]=(short)x;
	model[1].p[1]=(short)y;
	model[1].p[2]=0;

	model[2].u=u+w, model[2].v=v+h;
	model[2].p[0]=(short)x+(w*__sscale_x);
	model[2].p[1]=(short)y+(h*__sscale_y);
	model[2].p[2]=0;

	model[3].u=u+w, model[3].v=v;
	model[3].p[0]=(short)x+(w*__sscale_x);
	model[3].p[1]=(short)y;
	model[3].p[2]=0;

	sceGumDrawArray(4,
		0x800102,
		4, 0, (void *)model);
}

void FadeSetup(int mode, int c) {
    __fade = mode;
    __fadecolor = c;
    __fadestep = 0;
}

int FadeState(void) {
    return __fade;
}

void sceGuDisable(int state);
void sceGuColor(unsigned int color);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
extern Gu2dV16 D_0001D908[2];
void FadeDraw(void)
{
	u_int32 c;
	u_int32 a;

	if (__fadestep < 255 && __fade != 0) {
		if (__fade == 1)
			a = 255 - __fadestep;
		else
			a = __fadestep;
		sceGuDisable(9);
		c = (a << 24) | __fadecolor;
		sceGuColor(c);
		D_0001D908[0].p[0] = 0;
		D_0001D908[0].p[1] = 0;
		D_0001D908[0].p[2] = 0;
		D_0001D908[1].p[0] = 480;
		D_0001D908[1].p[1] = 272;
		D_0001D908[1].p[2] = 0;
		sceGumDrawArray(6, 0x800100, 2, NULL, D_0001D908);
		__fadestep += 16;
		if (__fadestep < 255)
			return;
		__fadestep = 255;
	}
	__fade = 0;
}

void sceGuClear(int flags);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
static void DrawFunc(void)
{
	sceGuStart(0, displist, sizeof(displist));
	sceGuClear(7);
	if (func[program.mode].draw)
		func[program.mode].draw();
	sceGuFinish();
	sceGuSync(0, 0);
}

static void KeyFunc(void)
{
	u_int32 prev;
	u_int32 padd;
	SceCtrlData buf;

	prev = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd = cont & (cont ^ prev);
	if (func[program.mode].key)
		func[program.mode].key(padd, cont);
}

static void ProgramSwitch(void)
{
	switch (program.flag) {
	case 0:
		if (func[program.mode].init)
			func[program.mode].init();
		program.flag = 1;
		break;
	case 1:
		if (func[program.mode].run)
			func[program.mode].run();
		break;
	}
}

int ExitFunction(int count, int arg_impose, int arg_self) {
    sceKernelExitGame();
    return 0;
}

extern signed char D_0000B680;

int main(void) {
    InitFunc();
    sceKernelRegisterExitCallback(sceKernelCreateCallback(&D_0000B680, ExitFunction, NULL));
    if (exitflag == 0) {
        do {
            ProgramSwitch();
            KeyFunc();
            DrawFunc();
            sceDisplayWaitVblankStartCB();
            sceGuSwapBuffers();
            vcount = (vcount + 1) & 0xFFFF;
        } while (exitflag == 0);
    }
    sceGuTerm();
    return 0;
}
