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
void sceGuTerm(void);
void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStart(void);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;
extern int texflag;
extern u_int32 cont;


/* SDK functions (tools/sdk_protos.h) */
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void sceGuClear(int flags);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);

static void draw_frame(void);
static void init_all(void);
static int pad_read(void);


/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10, 0x14], gap at: 0x8. */
void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    sceGumPushMatrix();
    sceGumLoadIdentity();
    sceGumTranslate(&pos);
    sceGumRotateX((rot.x * 3.1415927f) / 180.0f);
    sceGumRotateY((rot.y * 3.1415927f) / 180.0f);
    sceGumRotateZ((rot.z * 3.1415927f) / 180.0f);
    DrawDragon(texflag);
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

void sceGuSpecular(float power);
void sceGuFog(float near, float far, unsigned int color);
void sceGumPerspective(float fovy, float aspect, float near, float far);

#ifdef NON_MATCHING
/* the two light vectors' constants load in a different order ($f21 holds 1.0f) */
static void init_all(void)
{
	ScePspIMatrix4 dith = {
		{ -4, 0, -3, 1 },
		{ 2, -2, 3, -1 },
		{ -3, 1, -4, 0 },
		{ 3, -1, 2, -2 },
	};
	ScePspFVector3 vec;

	sceGuInit();
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(1, NULL, 0x200);
	sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
	sceGuDepthBuffer((void *)0x88000, 0x200);
	sceGuOffset(0x710, 0x778);
	sceGuViewport(0x800, 0x800, 0x1E0, 0x110);
	sceGuDepthRange(0xC350, 0x2710);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
	sceGuScissor(0, 0, 0x1E0, 0x110);
	sceGuEnable(2);
	sceGuAlphaFunc(6, 0, 0xFF);
	sceGuEnable(0);
	sceGuDepthFunc(7);
	sceGuEnable(1);
	sceGuFrontFace(0);
	sceGuEnable(0x14);
	sceGuTexFunc(0, 1);
	sceGuTexFilter(7, 0);
	sceGuTexWrap(0, 0);
	sceGuDisable(9);
	sceGuSetDither(&dith);
	sceGuEnable(6);
	sceGuEnable(8);
	sceGuShadeModel(1);
	vec.x = 10.0f;
	vec.y = 4.0f;
	vec.z = 10.0f;
	sceGuLightColor(0, 2, 0xff008000);
	sceGuLightColor(0, 4, 0xffffffff);
	sceGuLight(0, 0, 6, &vec);
	sceGuEnable(0xB);
	vec.x = -1.0f;
	vec.y = -2.0f;
	vec.z = 1.0f;
	sceGuLightColor(1, 2, 0xff000080);
	sceGuLight(1, 0, 2, &vec);
	sceGuEnable(0xC);
	sceGuEnable(0xA);
	sceGuSpecular(60.0f);
	sceGuFog(24.0f, 60.0f, 0xff000000);
	sceGuEnable(7);
	sceGuAmbient(0xffc0c0c0);
	sceGumSetMatrixStack(matrix_stack, 8, 8, 0x20, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
	sceGumMatrixMode(2);
	sceGuClearColor(0xff202020);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	pos.x = 0.0f;
	pos.y = -12.0f;
	pos.z = -44.0f;
	rot.x = 16.0f;
	rot.y = 310.0f;
	rot.z = 0.0f;
	sceGuDisplay(1);
}
#else
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumMatrixMode(int mode);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
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
#define SCEGU_ADD                          0
#define SCEGU_SRC_ALPHA                    2
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#define SCEGU_BLEND                        4
#define SCEGU_SCISSOR_TEST                 2
#define SCEGU_GREATER                      6
#define SCEGU_ALPHA_TEST                   0
#define SCEGU_GEQUAL                       7
#define SCEGU_DEPTH_TEST                   1
#define SCEGU_CW                           0
#define SCEGU_NORMAL_REVERSE_PATCH        20
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGBA                         1
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#define SCEGU_NEAREST                      0
#define SCEGU_REPEAT                       0
#define SCEGU_TEXTURE                      9
#define SCEGU_DITHER                       6
#define SCEGU_CLIP_PLANE                   8
#define SCEGU_SMOOTH                       1
#define SCEGU_SPECULAR                     4
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#define SCEGU_LIGHT0                      11
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE                      2
#define SCEGU_LIGHT1                      12
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

extern const ScePspIMatrix4 D_00011F30;
static void init_all(void)
{
	ScePspIMatrix4 dith = D_00011F30;
	ScePspFVector3	vec;

	sceGuInit();

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(SCEGU_PF5551, SCEGU_VRAM_BP_0, SCEGU_VRAM_WIDTH);
	sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT, SCEGU_VRAM_BP_1, SCEGU_VRAM_WIDTH);
	sceGuDepthBuffer(SCEGU_VRAM_BP_2, SCEGU_VRAM_WIDTH);

	sceGuOffset(SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY);
	sceGuViewport(2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDepthRange(50000, 10000);

	sceGuBlendFunc(SCEGU_ADD, SCEGU_SRC_ALPHA, SCEGU_ONE_MINUS_SRC_ALPHA, 0, 0);
	sceGuEnable(SCEGU_BLEND);

	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuEnable(SCEGU_SCISSOR_TEST);

	sceGuAlphaFunc(SCEGU_GREATER, 0x00, 0xff);
	sceGuEnable(SCEGU_ALPHA_TEST);

	sceGuDepthFunc(SCEGU_GEQUAL);
	sceGuEnable(SCEGU_DEPTH_TEST);

	sceGuFrontFace(SCEGU_CW);
	sceGuEnable(SCEGU_NORMAL_REVERSE_PATCH);

	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGBA);
	sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_NEAREST);
	sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
	sceGuDisable(SCEGU_TEXTURE);

	sceGuSetDither(&dith);
	sceGuEnable(SCEGU_DITHER);
	sceGuEnable(SCEGU_CLIP_PLANE);
	sceGuShadeModel(SCEGU_SMOOTH);

	vec.x=10.0f;
	vec.y= 4.0f;
	vec.z=10.0f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xff008000);
	sceGuLightColor(0, SCEGU_SPECULAR, 0xffffffff);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR, &vec);
	sceGuEnable(SCEGU_LIGHT0);

	vec.x=-1.0f;
	vec.y=-2.0f;
	vec.z= 1.0f;
	sceGuLightColor(1, SCEGU_DIFFUSE, 0xff000080);
	sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuEnable(SCEGU_LIGHT1);
	sceGuEnable(SCEGU_LIGHTING);

	sceGuSpecular(60.0f);

	sceGuFog(24.0f, 60.0f, 0xff000000);
	sceGuEnable(SCEGU_FOG);

	sceGuAmbient(0xffc0c0c0);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT, 1.000000f, 100.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0xff202020);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	pos.x=  0.0f;
	pos.y=-12.0f;
	pos.z=-44.0f;
	rot.x= 16.0f;
	rot.y=310.0f;
	rot.z=  0.0f;

	sceGuDisplay(SCEGU_DISPLAY_ON);
}
#endif

static int pad_read(void)
{
	u_int32 prev, padd;
	SceCtrlData buf;

	prev = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd = cont & (cont ^ prev);
	if (cont & 0x0010) {
		rot.x -= 4.0f;
		if (rot.x < 0.0f)
			rot.x += 360.0f;
	}
	if (cont & 0x0040) {
		rot.x += 4.0f;
		if (rot.x >= 360.0f)
			rot.x -= 360.0f;
	}
	if (cont & 0x0080) {
		rot.y -= 4.0f;
		if (rot.y < 0.0f)
			rot.y += 360.0f;
	}
	if (cont & 0x0020) {
		rot.y += 4.0f;
		if (rot.y >= 360.0f)
			rot.y -= 360.0f;
	}
	if (cont & 0x0100)
		pos.z -= 2.0f;
	if (cont & 0x0200)
		pos.z += 2.0f;
	if (padd & 0x2000)
		texflag ^= 1;
	if (padd & 0x0008) {
		pos.x = 0.0f;
		pos.y = -12.0f;
		pos.z = -44.0f;
		rot.x = 16.0f;
		rot.y = 310.0f;
		rot.z = 0.0f;
	}
	if (padd & 0x0001)
		return 0;
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
    menuTerm(1, 6);
    return 0;
}

/* init_all's dith initializer: ScePspIMatrix4 is 16-byte aligned */
__asm__(".section .rodata\n\t.align 4\n.section .text");
INCLUDE_RODATA("tmp/asm/UTST99332/graphics_dragon/nonmatchings/main", D_00011F30);
