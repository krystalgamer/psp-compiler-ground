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


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuSpecular(float power);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);

void InitParticle(void);
#define SCEGU_IMMEDIATE                    0
#define SCEGU_PF5551                       1
#define SCEGU_VRAM_BP_0       (void *)(SCEGU_VRAM_TOP)
#define SCEGU_VRAM_BP_1       (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE)
#define SCEGU_VRAM_TOP        0x00000000
#define SCEGU_VRAM_BUFSIZE    (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)
#define SCEGU_VRAM_BP_2       (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE*2))
#define SCEGU_VRAM_WIDTH      512
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)
#define SCEGU_SCISSOR_TEST                 2
#define SCEGU_GEQUAL                       7
#define SCEGU_DEPTH_TEST                   1
#define SCEGU_ADD                          0
#define SCEGU_SRC_ALPHA                    2
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#define SCEGU_BLEND                        4
#define SCEGU_GREATER                      6
#define SCEGU_ALPHA_TEST                   0
#define SCEGU_CW                           0
#define SCEGU_TEXTURE                      9
#define SCEGU_DITHER                       6
#define SCEGU_CLIP_PLANE                   8
#define SCEGU_SMOOTH                       1
#define SCEGU_LIGHT0                      11
#define SCEGU_SPECULAR                     4
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#define SCEGU_LIGHT1                      12
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE                      2
#define SCEGU_LIGHT2                      13
#define SCEGU_LIGHTING                    10
#define SCEGU_FOG                          7
#define SCEGU_MATRIX_PROJECTION            0
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272
#define SCEGU_SCR_ASPECT      ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#define SCEGU_MATRIX_WORLD                 2
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0
#define SCEGU_DISPLAY_ON		1

static void InitFunc(void)
{
	const ScePspIMatrix4	dith={	{-4,  0, -3,  1},
									{ 2, -2,  3, -1},
									{-3,  1, -4,  0},
									{ 3, -1,  2, -2}};
	ScePspFVector3	vec;

	sceGuInit();

	sceGuStart(SCEGU_IMMEDIATE, displist, sizeof(displist));
	sceGuDrawBuffer(SCEGU_PF5551, SCEGU_VRAM_BP_0, SCEGU_VRAM_WIDTH);
	sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT,
					SCEGU_VRAM_BP_1, SCEGU_VRAM_WIDTH);
	sceGuDepthBuffer(SCEGU_VRAM_BP_2, SCEGU_VRAM_WIDTH);

	sceGuOffset(SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY);
	sceGuViewport(2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDepthRange(50000, 10000);

	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuEnable(SCEGU_SCISSOR_TEST);

	sceGuDepthFunc(SCEGU_GEQUAL);
	sceGuEnable(SCEGU_DEPTH_TEST);

	sceGuBlendFunc(SCEGU_ADD, SCEGU_SRC_ALPHA, SCEGU_ONE_MINUS_SRC_ALPHA, 0, 0);
	sceGuEnable(SCEGU_BLEND);

	sceGuAlphaFunc(SCEGU_GREATER, 0x00, 0xff);
	sceGuDisable(SCEGU_ALPHA_TEST);

	sceGuFrontFace(SCEGU_CW);

	sceGuDisable(SCEGU_TEXTURE);

	sceGuSetDither(&dith);
	sceGuEnable(SCEGU_DITHER);
	sceGuEnable(SCEGU_CLIP_PLANE);
	sceGuShadeModel(SCEGU_SMOOTH);


	vec.x=0.614497f;
	vec.y=0.691714f;
	vec.z=0.379372f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xff808080);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuEnable(SCEGU_LIGHT0);

	vec.x=0.614497f;
	vec.y=0.691714f;
	vec.z=0.379372f;
	sceGuLightColor(1, SCEGU_DIFFUSE, 0x00000000);
	sceGuLightColor(1, SCEGU_SPECULAR, 0xffffffff);
	sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR, &vec);
	sceGuEnable(SCEGU_LIGHT1);

	vec.x=-0.614497f;
	vec.y=-0.391714f;
	vec.z=-0.379372f;
	sceGuLightColor(2, SCEGU_DIFFUSE, 0xffc0c0c0);
	sceGuLight(2, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuDisable(SCEGU_LIGHT2);

	sceGuEnable(SCEGU_LIGHTING);
	sceGuSpecular(20.0f);

	sceGuDisable(SCEGU_FOG);
	sceGuAmbient(0xff808080);
	sceGuColor(0xffffffff);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
					1.000000f, 1000.00000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0x00000000);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	InitParticle();

	program.flag=0;
	program.mode=0;

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

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
