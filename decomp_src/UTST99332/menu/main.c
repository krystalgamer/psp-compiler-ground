#include "common.h"

/* declarations recovered from DWARF */
struct SceKernelLoadExecParam;
typedef unsigned int SceSize;
struct SceKernelLoadExecParam { /* size 0x10 */
    SceSize size;
    SceSize args;
    const void *argp;
    const char *key;
};
typedef struct SceKernelLoadExecParam SceKernelLoadExecParam;
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
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1;
typedef short unsigned int u_short16;
struct __attribute__((packed)) _anon1 { /* size 0x10 */
    u_short16 u;
    u_short16 v;
    float p[3];
};
typedef struct _anon1 Gu2dV32T;
struct _anon2;
struct _anon2 { /* size 0x6 */
    short int p[3];
};
typedef struct _anon2 Gu2dV16;
typedef unsigned int u_int32;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct _anon3;
struct _anon3 { /* size 0x24 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
    int cat;
    int num;
    int ret;
};
typedef struct _anon3 MENUDATA;
typedef struct _anon3 *PMENUDATA;
struct _anon4;
struct _anon4 { /* size 0xc */
    int flag;
    int mode;
    int next;
};
typedef struct _anon4 PROG;
struct _anon5;
typedef void voidfunc(void);
typedef void voidfuncuint2(u_int32, u_int32, float *);
struct _anon5 { /* size 0x10 */
    voidfunc *init;
    voidfunc *run;
    voidfunc *draw;
    voidfuncuint2 *key;
};
typedef struct _anon5 FUNCLIST;
struct _anon6;
struct _anon6 { /* size 0x8 */
    unsigned char *p;
    int size;
};
typedef struct _anon6 SE;
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
};
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

extern MENUDATA menudata;
extern PMENUDATA menu;
extern int exitflag;
extern u_int32 cont;
extern u_int32 vcount;
extern PROG program;
extern FUNCLIST func[2];
extern int catlist[6];
extern char filelist[62][31];
extern unsigned char cube_m[4944];
extern unsigned char decide1_m[15296];
extern unsigned char decide2_m[31024];
extern unsigned char slide_m[4048];
extern SE se[4];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char displist[327680];
extern ScePspFMatrix4 matrix_stack[48];
extern int __fade;
extern int __fadecount;
extern int __fadecolor;
extern int __fadestep;

int GetItem(int cat, int num);
void PrxExec(int cat, int num);
static void InitSE(void);
void PlaySE(int num);
static void InitFunc(void);
void DrawSprite(float x, float y, float w, float h, int u, int v);
void FadeDraw(void);
static void DrawFunc(void);
static void KeyFunc(void);
static int ProgramSwitch(void);
int main(int argc, char **argv);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceCtrlSetSamplingMode(int mode);
int sceDisplayWaitVblankStart(void);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
void sceGuFrontFace(int order);
void *sceGuGetMemory(int size);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuSpecular(float power);
void *sceGuSwapBuffers(void);
void sceGuTerm(void);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
int sceKernelLoadExec(const char *file, SceKernelLoadExecParam *param);
char *strcat(char *d, const char *s);

int GetItem(int cat, int num)
{
	int i, n;

	n = 0;
	for (i = 0; i < cat; i++)
		n += catlist[i];
	n += num;
	return n;
}

void PrxExec(int cat, int num)
{
	SceKernelLoadExecParam param;
	char fname[64];
	int n;

	n = GetItem(cat, num);
	strcpy(fname, "disc0:");
	strcat(fname, "/PSP_GAME/USRDIR/PRX/");
	strcat(fname, filelist[n]);
	param.size = sizeof(param);
	param.args = 0;
	param.argp = NULL;
	param.key = NULL;
	sceKernelLoadExec(fname, &param);
}

static void InitSE(void)
{
	int i;

	sceWaveInit();
	for (i = 0; i < 4; i++)
		sceWaveSetVoice(i, se[i].p + 0x30, se[i].size - 0x30, 0);
	sceWaveStart(16);
}

void PlaySE(int num)
{
	sceWavePlay(num, 127, 127);
}

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/main", D_00016F80);

extern const ScePspIMatrix4 D_00016F80;
static void InitFunc(void)
{
	const ScePspIMatrix4 dith = D_00016F80;
	ScePspFVector3 vec;

	InitSE();
	sceCtrlSetSamplingMode(1);
	sceGuInit();
	sceGuStart(0, displist, sizeof(displist));
	sceGuDrawBuffer(3, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x88000, 512);
	sceGuDepthBuffer((void *)0x110000, 512);
	sceGuOffset(2048 - 480 / 2, 2048 - 272 / 2);
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
	sceGuLightColor(2, 2, 0xff808080);
	sceGuLight(2, 0, 2, &vec);
	sceGuEnable(13);
	sceGuEnable(10);
	sceGuSpecular(30.0f);
	sceGuDisable(7);
	sceGuAmbient(0xff808080);
	sceGuColor(0xffffffff);
	sceGumSetMatrixStack(matrix_stack, 8, 8, 32, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 1000.0f);
	sceGumMatrixMode(2);
	sceGuClearColor(0xffffff);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuTexWrap(0, 0);
	sceGuTexFilter(0, 0);
	sceGuTexFunc(0, 1);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	sceGuDisplay(1);
}

void sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
void DrawSprite(float x, float y, float w, float h, int u, int v)
{
	Gu2dV32T *model;

	model = sceGuGetMemory(sizeof(Gu2dV32T) * 4);
	model[0].u = 0;
	model[0].v = v;
	model[0].p[0] = x;
	model[0].p[1] = y + h;
	model[0].p[2] = 0.0f;
	model[1].u = 0;
	model[1].v = 0;
	model[1].p[0] = x;
	model[1].p[1] = y;
	model[1].p[2] = 0.0f;
	model[2].u = u;
	model[2].v = v;
	model[2].p[0] = x + w;
	model[2].p[1] = y + h;
	model[2].p[2] = 0.0f;
	model[3].u = u;
	model[3].v = 0;
	model[3].p[0] = x + w;
	model[3].p[1] = y;
	model[3].p[2] = 0.0f;
	sceKernelDcacheWritebackInvalidateRange(model, sizeof(Gu2dV32T) * 4);
	sceGumDrawArray(4, 0x800182, 4, NULL, model);
}

void FadeSetup(int mode, int step, int c) {
    __fade = mode;
    __fadecolor = c;
    __fadestep = step;
    __fadecount = 0;
}

int FadeState(void) {
    return __fade;
}

extern Gu2dV16 D_001A3E48[];
void FadeDraw(void)
{
	u_int32 c, a;

	if (__fadecount >= 255 || __fade == 0) {
		__fade = 0;
		__fadecount = 0;
		return;
	}
	if (__fade == 1)
		a = 255 - __fadecount;
	else
		a = __fadecount;
	sceGuDisable(9);
	c = (a << 24) | __fadecolor;
	sceGuColor(c);
	sceGumDrawArray(6, 0x800100, 2, NULL, D_001A3E48);
	__fadecount += __fadestep;
	if (__fadecount >= 255) {
		__fade = 0;
		__fadecount = 0;
	}
}

void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void sceGuClear(int flags);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
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

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", KeyFunc);

static int ProgramSwitch(void)
{
	int flag = 0;

	if (program.next != -1) {
		program.mode = program.next;
		program.next = -1;
		program.flag = 0;
	}
	switch (program.flag) {
	case 0:
		flag = 1;
		if (func[program.mode].init)
			func[program.mode].init();
		program.flag = 1;
		break;
	case 1:
		if (func[program.mode].run)
			func[program.mode].run();
		break;
	}
	return flag;
}

void ProgramChange(int mode) {
    if (program.next != mode) {
        program.next = mode;
    }
}

int main(int argc, char **argv)
{
	menu->pos = (ScePspFVector3){0.0f, 0.0f, 0.0f};
	menu->rot = (ScePspFVector3){0.0f, 0.0f, 0.0f};
	if (argc < 2) {
		menu->cat = 0;
		menu->num = 0;
		menu->ret = 0;
		program.next = -1;
		program.flag = 0;
		program.mode = 0;
	} else {
		char *stop;

		menu->cat = strtoul(argv[0], &stop, 10);
		menu->num = strtoul(argv[1], &stop, 10);
		menu->ret = 1;
		program.flag = 0;
		program.mode = 1;
		program.next = -1;
	}
	menuInit();
	InitFunc();
	while (!exitflag) {
		if (ProgramSwitch() == 0) {
			KeyFunc();
			DrawFunc();
			sceDisplayWaitVblankStart();
			sceGuSwapBuffers();
			vcount = (vcount + 1) & 0xffff;
		}
	}
	sceGuTerm();
	return 0;
}
