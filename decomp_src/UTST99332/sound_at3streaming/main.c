#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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
typedef int SceUID;
typedef int SceInt32;
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
struct _anon1;
struct _anon1 { /* size 0x18 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
};
typedef struct _anon1 POS;

extern ScePspFVector3 light_vec;
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[16];
extern POS pos;

static void draw_frame(void);
static void init_pos(void);
static int pad_read(void);
int main(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuInit(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGuDepthRange(int near, int far);
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuAmbient(unsigned int color);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuFog(float near, float far, unsigned int color);
void sceGuShadeModel(int mode);
void sceGuDepthFunc(int function);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuStencilFunc(int func, int ref, int mask);
void sceGuStencilOp(int fail, int zfail, int zpass);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);


void DrawData(void);

/* SDK prototypes (tools/sdk_protos.h) */
int printf(const char *fmt, ...);
int sceDisplayWaitVblankStart(void);
void *sceGuSwapBuffers(void);
void sceGuTerm(void);
int sceKernelDeleteThread(int thid);

static void draw_frame(void)
{
	ScePspFVector3 vec;

	sceGuStart(0, disp_list, 0x10000);

	sceGuClear(7);

	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos.trans);
	vec.x = pos.rot.x * 3.1415927f / 180.0f;
	vec.y = pos.rot.y * 3.1415927f / 180.0f;
	vec.z = pos.rot.z * 3.1415927f / 180.0f;
	sceGumRotateXYZ(&vec);

	DrawData();

	sceGumPopMatrix();

	sceGuFinish();
	sceGuSync(0, 0);
}

void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x10000);
    sceGuDrawBuffer(1, NULL, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
    sceGuDepthBuffer((void *)0x88000, 0x200);
    sceGuOffset(0x710U, 0x778U);
    sceGuViewport(0x800, 0x800, 0x1E0, 0x110);
    sceGuDepthRange(0xFFFF, 0);
    sceGuScissor(0, 0, 0x1E0, 0x110);
    sceGuEnable(2);
    sceGuDepthFunc(7);
    sceGuEnable(1);
    sceGuEnable(8);
    sceGuStencilFunc(2, 0, 0xFF);
    sceGuStencilOp(0, 0, 4);
    sceGuEnable(0x14);
    sceGuShadeModel(1);
    sceGuEnable(6);
    light_vec.x = 1.0f;
    light_vec.y = 0.0f;
    light_vec.z = 0.0f;
    sceGuLightColor(2, 2, -1U);
    sceGuLight(2, 0, 2, &light_vec);
    sceGuDisable(0xD);
    light_vec.y = 1.0f;
    light_vec.x = 0.0f;
    light_vec.z = 0.0f;
    sceGuLightColor(3, 2, -1U);
    sceGuLight(3, 0, 2, &light_vec);
    sceGuDisable(0xE);
    light_vec.y = 1.0f;
    light_vec.z = 1.0f;
    light_vec.x = 0.0f;
    sceGuLightColor(0, 2, -1U);
    sceGuLight(0, 0, 2, &light_vec);
    sceGuEnable(0xB);
    sceGuEnable(0xA);
    sceGuAmbient(0xFF7F7F7FU);
    sceGuBlendFunc(0, 2, 3, 0U, 0U);
    sceGuDisable(4);
    sceGuTexFilter(7, 1);
    sceGuTexFunc(0, 1);
    sceGuTexWrap(0, 0);
    sceGuTexOffset(0.0f, 0.0f);
    sceGuTexScale(10.0f, 10.0f);
    sceGuTexMapMode(0, 0U, 1U);
    sceGuClutMode(1U, 0U, 0xFFU, 0U);
    sceGuDisable(9);
    sceGuFog(20.0f, 30.0f, 0U);
    sceGuEnable(7);
    sceGumSetMatrixStack(matrix_stack, 4, 4, 8, 0);
    sceGumMatrixMode(0);
    sceGumLoadIdentity();
    sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
    sceGumMatrixMode(2);
    sceGuClearColor(0U);
    sceGuClearDepth(0U);
    sceGuClearStencil(0U);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGuDisplay(1);
}

static void init_pos(void)
{
	pos.rot.x = 10.0f;
	pos.rot.y = 0.0f;
	pos.rot.z = 0.0f;
	pos.trans.x = 0.0f;
	pos.trans.y = -1.0f;
	pos.trans.z = -12.0f;
}

#define SCE_CTRL_UP					(1<<4)
#define SCE_CTRL_DOWN				(1<<6)
#define SCE_CTRL_LEFT				(1<<7)
#define SCE_CTRL_RIGHT				(1<<5)
#define PANG	10.0f
#define LIMIT_ANG		60.0f
#define SCE_CTRL_L					(1<<8)
#define SCE_CTRL_L1					SCE_CTRL_L
#define LIMIT_FAR		-25.0f
#define SCE_CTRL_R					(1<<9)
#define SCE_CTRL_R1					SCE_CTRL_R
#define PTRANS	1.0f
#define LIMIT_NEAR		-6.0f
#define SCE_CTRL_START				(1<<3)
#define SCE_CTRL_SELECT				(1<<0)

static int pad_read(void)
{
	extern u_int32	D_00020EC0;
	u_int32			padd;
	SceCtrlData		buf;

	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;

	if (padd & SCE_CTRL_UP) {
		pos.rot.x = pos.rot.x - PANG;
		if (pos.rot.x <= 0.0f) {
			pos.rot.x = 0.0f;
		}
	}
	if (padd & SCE_CTRL_DOWN) {
		pos.rot.x = pos.rot.x + PANG;
		if (pos.rot.x >= LIMIT_ANG) {
			pos.rot.x = LIMIT_ANG;
		}
	}
	if (padd & SCE_CTRL_LEFT) {
		pos.rot.y = pos.rot.y - PANG;
		if (pos.rot.y <= -LIMIT_ANG) {
			pos.rot.y = -LIMIT_ANG;
		}
	}
	if (padd & SCE_CTRL_RIGHT) {
		pos.rot.y = pos.rot.y + PANG;
		if (pos.rot.y >= LIMIT_ANG) {
			pos.rot.y = LIMIT_ANG;
		}
	}
	if (padd & SCE_CTRL_L1) {
		pos.trans.z = pos.trans.z - PTRANS;
		if (pos.trans.z <= LIMIT_FAR) {
			pos.trans.z = LIMIT_FAR;
		}
	}
	if (padd & SCE_CTRL_R1) {
		pos.trans.z = pos.trans.z + PTRANS;
		if (pos.trans.z >= LIMIT_NEAR) {
			pos.trans.z = LIMIT_NEAR;
		}
	}
	if (padd & SCE_CTRL_START) {
		init_pos();
	}
	if (padd & SCE_CTRL_SELECT) {
		return 0;
	}
	D_00020EC0 = padd;

	return 1;
}

#define MS_PHYSDEV_NAME "msstor0p1:/"
#define MS_FSDEV_NAME   "fatms0:"
#define SCE_MT_RDONLY	      0x01
#define SCE_KERNEL_ERROR_OK    0x0
#define FILENAME "disc0:/PSP_GAME/USRDIR/DATA/sound/wave/overload-loop.at3"
#define MS_ASIGN_NAME   "prfat0:"
#define SCE_KERNEL_NO_RESIDENT          (1)
#define SCE_KERNEL_NO_RESIDENT_END      SCE_KERNEL_NO_RESIDENT

int main(void)
{
	SceUID thid;
	SceInt32 status;

	menuInit();
	if (loadModuleAt3plus() < 0) {
		return -1;
	}
	if ((status = sceWaveInit()) != 0) {
		printf("sceWaveInit error:%08X\n", status);
		goto wave_exit;
	}
	if ((thid = at3_bgm_play("disc0:/PSP_GAME/USRDIR/DATA/sound/wave/overload_loop.at3")) < 0) {
		printf("something failed...:%x\n", thid);
		goto wave_exit;
	}
	init_all();
	init_pos();
	InitString();
	while (pad_read()) {
		draw_frame();
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
	}
	sceGuTerm();
	at3_bgm_play_end(1);
	if ((status = sceKernelWaitThreadEnd(thid, NULL)) != 0) {
		printf("sceKernelWaitThread: %08X\n", status);
	}
	if ((status = sceKernelDeleteThread(thid)) != 0) {
		printf("sceKernelDeleteThread: %08X\n", status);
		goto wave_exit;
	}
wave_exit:
	if ((status = sceWaveExit()) != 0) {
		printf("sceWaveExit error:%08X\n", status);
	}
	unloadModuleAt3plus();
	menuTerm(4, 2);
	return SCE_KERNEL_NO_RESIDENT_END;
}
