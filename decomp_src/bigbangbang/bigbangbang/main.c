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
};
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


INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/main", D_0000B640);

INCLUDE_RODATA("tmp/asm/bigbangbang/bigbangbang/nonmatchings/main", D_0000B680);

void sceGuSpecular(float power);
void sceGumPerspective(float fovy, float aspect, float near, float far);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/main", InitFunc);

void SpriteScale(int x, int y) {
    __sscale_x = x;
    __sscale_y = y;
}

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/main", DrawSprite);

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
