#include "common.h"

/* declarations recovered from DWARF */
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
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
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
int sceDisplayWaitVblankStart(void);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_moonball/nonmatchings/main", D_00013FE0);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_moonball/nonmatchings/main", InitFunc);

void SpriteScale(int x, int y) {
    __sscale_x = x;
    __sscale_y = y;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_moonball/nonmatchings/main", DrawSprite);

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
void sceGuDisable(int state);
void sceGuColor(unsigned int color);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
extern Gu2dV16 D_00026848[2];
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
		D_00026848[0].p[0] = 0;
		D_00026848[0].p[1] = 0;
		D_00026848[0].p[2] = 0;
		D_00026848[1].p[0] = 480;
		D_00026848[1].p[1] = 272;
		D_00026848[1].p[2] = 0;
		sceGumDrawArray(6, 0x800100, 2, NULL, D_00026848);
		__fadestep += 16;
		if (__fadestep < 255)
			return;
		__fadestep = 255;
	}
	__fade = 0;
}

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

int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
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

int main(void) {
    menuInit();
    InitFunc();
    if (exitflag == 0) {
        do {
            ProgramSwitch();
            KeyFunc();
            DrawFunc();
            sceDisplayWaitVblankStart();
            sceGuSwapBuffers();
            vcount = (vcount + 1) & 0xFFFF;
        } while (exitflag == 0);
    }
    sceGuTerm();
    menuTerm(1, 0x12);
    return 0;
}
