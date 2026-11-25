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
struct _anon1;
struct _anon1 { /* size 0x18 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
};
typedef struct _anon1 POS;
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

/* SDK functions */
void sceGuInit(void);
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
void sceGuColor(unsigned int color);
void sceGuAmbient(unsigned int color);
void sceGuSpecular(float power);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuShadeModel(int mode);
void sceGuFrontFace(int order);
void sceGuDepthFunc(int function);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);

/* SDK functions */
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void sceGuClear(int flags);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateZYX(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);

/* SDK functions */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

extern unsigned int checkcolor[1];
extern unsigned int check32x32[128];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern const int mapmode[3];
extern const char mapstr[3][16];
extern POS pos;
extern int mode;
extern int autoflag;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[32];
extern float array[147];

static void draw_frame(int frame);
void DrawTorus(float *array, float in, float out);
static void init_all(void);
static void init_pos(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStart(void);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_texmat/nonmatchings/main", mapmode);

const char mapstr[3][16] = { "[UV    MAP]", "[PROJ  MAP]", "[SHADE MAP]" };

static void draw_frame(int frame)
{
	ScePspFVector3 vec;
	float angle;

	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);
	if (autoflag) {
		angle = (float)((frame * 2) % 360) * 3.1415927f / 180.0f;
		vec.z = vec.y = vec.x = angle;
	} else {
		vec.x = pos.rot.x * 3.1415927f / 180.0f;
		vec.y = pos.rot.y * 3.1415927f / 180.0f;
		vec.z = pos.rot.z * 3.1415927f / 180.0f;
	}
	sceGuTexMapMode(mapmode[mode], 0, 1);
	if (mode == 1) {
		sceGumMatrixMode(3);
		sceGumPushMatrix();
		sceGumTranslate(&pos.trans);
		sceGumRotateZYX(&vec);
		sceGumMatrixMode(2);
	}
	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos.trans);
	sceGumRotateZYX(&vec);
	DrawTorus(array, 1.0f, 2.0f);
	if (mode == 1) {
		sceGumMatrixMode(3);
		sceGumPopMatrix();
		sceGumMatrixMode(2);
	}
	sceGumPopMatrix();
	sceGuDebugPrint(0, 0, 0xffffffff, mapstr[mode]);
	sceGuFinish();
	sceGuSync(0, 0);
}

static void init_all(void)
{
	ScePspFVector3 vec;

	sceGuInit();
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(1, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x44000, 512);
	sceGuDepthBuffer((void *)0x88000, 512);
	sceGuOffset(2048 - 480 / 2, 2048 - 272 / 2);
	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(50000, 10000);
	sceGuDisable(4);
	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);
	sceGuDepthFunc(6);
	sceGuEnable(1);
	sceGuFrontFace(0);
	sceGuEnable(5);
	sceGuTexImage(0, 32, 32, 32, check32x32);
	sceGuTexMode(4, 0, 0, 0);
	sceGuTexFilter(7, 1);
	sceGuTexFunc(0, 0);
	sceGuTexWrap(0, 0);
	sceGuTexScale(1.0f, 1.0f);
	sceGuTexOffset(0.0f, 0.0f);
	sceGuClutMode(1, 0, 0xff, 0);
	sceGuClutLoad(1, checkcolor);
	sceGuEnable(9);
	sceGuShadeModel(1);
	sceGuEnable(6);
	sceGuColor(0xff808080);
	sceGuAmbient(0xff404040);
	vec.x = 1.0f;
	vec.y = 0.0f;
	vec.z = 0.0f;
	sceGuLightColor(0, 2, 0);
	sceGuLight(0, 0, 2, &vec);
	sceGuEnable(11);
	vec.x = 0.0f;
	vec.y = 1.0f;
	vec.z = 0.0f;
	sceGuLightColor(1, 2, 0);
	sceGuLight(1, 0, 2, &vec);
	sceGuEnable(12);
	vec.x = -1.3f;
	vec.y = 4.0f;
	vec.z = 3.8f;
	sceGuLightColor(2, 2, 0xffffffff);
	sceGuLightColor(2, 4, 0xffffffff);
	sceGuLight(2, 0, 6, &vec);
	sceGuEnable(13);
	sceGuEnable(10);
	sceGuSpecular(10.0f);
	sceGumSetMatrixStack(matrix_stack, 8, 8, 8, 8);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
	sceGumMatrixMode(3);
	sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
	sceGumMatrixMode(2);
	sceGumLoadIdentity();
	sceGuClearColor(0xff808080);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	sceGuDisplay(1);
}

static void init_pos(void)
{
	pos.rot.x = 0.0f;
	pos.rot.y = 0.0f;
	pos.rot.z = 0.0f;
	pos.trans.x = 0.0f;
	pos.trans.y = 0.0f;
	pos.trans.z = -10.0f;
}

#define opadd D_00013BC4	/* pad_read's static */
extern u_int32 opadd;

static int pad_read(void)
{
	u_int32 padd;
	SceCtrlData buf;

	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;
	if (padd & 0x0010) {
		pos.rot.x -= 1.0f;
		if (pos.rot.x <= -360.0f)
			pos.rot.x = 0.0f;
	}
	if (padd & 0x0040) {
		pos.rot.x += 1.0f;
		if (pos.rot.x >= 360.0f)
			pos.rot.x = 0.0f;
	}
	if (padd & 0x0080) {
		pos.rot.y -= 1.0f;
		if (pos.rot.y <= -360.0f)
			pos.rot.y = 0.0f;
	}
	if (padd & 0x0020) {
		pos.rot.y += 1.0f;
		if (pos.rot.y >= 360.0f)
			pos.rot.y = 0.0f;
	}
	if (padd & 0x0100) {
		pos.trans.z -= 1.0f;
		if (pos.trans.z < -100.0f)
			pos.trans.z = -100.0f;
	}
	if (padd & 0x0200) {
		pos.trans.z += 1.0f;
		if (pos.trans.z > -5.0f)
			pos.trans.z = -5.0f;
	}
	if (padd & 0x2000)
		mode = 0;
	if (padd & 0x4000)
		mode = 1;
	if (padd & 0x1000)
		mode = 2;
	if (padd & 0x0008) {
		if (padd != opadd) {
			autoflag ^= 1;
			init_pos();
		}
	}
	if (padd & 0x0001)
		return 0;
	opadd = padd;
	return 1;
}

int main(void) {
    int temp_a0;
    int var_s0;

    menuInit();
    var_s0 = 0;
    init_all();
    init_pos();
loop_1:
    temp_a0 = var_s0;
    var_s0 += 1;
    if (pad_read() != 0) {
        draw_frame(temp_a0);
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0x22);
    return 0;
}
