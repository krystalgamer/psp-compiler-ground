#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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
void sceGuBoneMatrix(unsigned int index, const ScePspFMatrix4 *matrix);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

extern const unsigned int star_clut[128];
extern const unsigned int star_tex[256];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern int pause_flag;
extern int rot_flag;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[16];

static void init_all(void);
void InitData(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
void sceGuClear(int flags);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
int sceDisplayWaitVblankStart(void);


extern int rot_flag_294C4;

void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    sceGumPushMatrix();
    sceGumLoadIdentity();
    DrawData(pause_flag, rot_flag_294C4);
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", star_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", star_tex);

static void init_all(void)
{
	ScePspFVector3 vec;
	ScePspFMatrix4 mat;

	sceGuInit();
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(1, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x44000, 512);
	sceGuDepthBuffer((void *)0x88000, 512);
	sceGuOffset(2048 - 480 / 2, 2048 - 272 / 2);
	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(0xffff, 0);
	sceGuDisable(4);
	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);
	sceGuDepthFunc(7);
	sceGuEnable(1);
	sceGuFrontFace(0);
	sceGuDisable(9);
	sceGuShadeModel(1);
	sceGuEnable(6);
	vec.x = 1.0f;
	vec.y = 1.0f;
	vec.z = 1.0f;
	sceGuLightColor(0, 2, 0xffffffff);
	sceGuLight(0, 0, 2, &vec);
	sceGuEnable(11);
	sceGuEnable(10);
	sceGuAmbient(0xff808080);
	sceGuColor(0xffffffff);
	sceGuTexMode(5, 0, 0, 0);
	sceGuTexFilter(7, 1);
	sceGuTexFunc(0, 0);
	sceGuTexWrap(0, 0);
	sceGuTexOffset(0.0f, 0.0f);
	sceGuTexScale(1.0f, 1.0f);
	sceGuTexImage(0, 32, 32, 32, star_tex);
	sceGuClutMode(1, 0, 0xff, 0);
	sceGuClutLoad(16, star_clut);
	sceGumSetMatrixStack(matrix_stack, 4, 4, 8, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(1.5707964f, 1.7647059f, 1.0f, 100.0f);
	sceGumMatrixMode(2);
	mat.x.x = 1.0f;
	mat.x.y = 0.0f;
	mat.x.z = 0.0f;
	mat.x.w = 0.0f;
	mat.y.x = 0.0f;
	mat.y.y = 1.0f;
	mat.y.z = 0.0f;
	mat.y.w = 0.0f;
	mat.z.x = 0.0f;
	mat.z.y = 0.0f;
	mat.z.z = 1.0f;
	mat.z.w = 0.0f;
	mat.w.x = 0.0f;
	mat.w.y = 0.0f;
	mat.w.z = 0.0f;
	mat.w.w = 1.0f;
	sceGuBoneMatrix(0, &mat);
	sceGuClearColor(0xff000000);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	InitData();
	sceGuDisplay(1);
}

#define opadd D_000294C8	/* pad_read's static */
extern u_int32 opadd;

static int pad_read(void)
{
	u_int32 padd;
	SceCtrlData buf;

	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;
	if (opadd != padd) {
		if (padd & 0x2000)
			rot_flag_294C4 ^= 1;
		if (padd & 0x0008)
			pause_flag ^= 1;
	}
	if (padd & 0x0001)
		return 0;
	opadd = padd;
	return 1;
}

int main(void) {
    menuInit();
    init_all();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0x1F);
    return 0;
}
