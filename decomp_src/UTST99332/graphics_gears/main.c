/* data-align: 16 */
#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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
/* Sony's psptypes.h aligns it to 16 bytes, which DWARF does not record */
typedef struct ScePspIMatrix4 ScePspIMatrix4 __attribute__((aligned(16)));
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
typedef unsigned char u_char8;
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

extern float gear0_top[48];
extern float gear0_bottom[48];
extern float gear0_in[48];
extern float gear0_out[348];
extern u_char8 gear0_out_idx0[6];
extern u_char8 gear0_out_idx1[5];
extern u_char8 gear0_out_idx2[5];
extern u_char8 gear0_out_idx3[5];
extern u_char8 gear0_out_idx4[5];
extern u_char8 gear0_out_idx5[48];
extern float gear1_top[48];
extern float gear1_bottom[48];
extern float gear1_in[48];
extern float gear1_out[156];
extern u_char8 gear1_out_idx0[5];
extern u_char8 gear1_out_idx1[5];
extern u_char8 gear1_out_idx2[5];
extern u_char8 gear1_out_idx3[5];
extern u_char8 gear1_out_idx4[12];
extern float gear2_top[48];
extern float gear2_bottom[48];
extern float gear2_in[48];
extern float gear2_out[348];
extern u_char8 gear2_out_idx0[6];
extern u_char8 gear2_out_idx1[5];
extern u_char8 gear2_out_idx2[5];
extern u_char8 gear2_out_idx3[5];
extern u_char8 gear2_out_idx4[5];
extern u_char8 gear2_out_idx5[48];
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
extern float angle;
extern int rotate;
extern u_int32 cont;

static void draw_gear0(void);
static void draw_gear1(void);
static void draw_gear2(void);
static void draw_frame(void);
static void init_all(void);
static int pad_read(void);
static void frame_update(void);
int main(void);

/* SDK functions */
void sceGuInit(void);
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
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
void sceGuClear(int flags);
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
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuSetDither(const void *matrix);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
int sceDisplayWaitVblankStart(void);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

static void draw_gear0(void)
{
	int i;

	sceGumPushMatrix();
	for (i = 0; i < 8; i++) {
		sceGumDrawBezier(0x180, 4, 4, NULL, gear0_top);
		sceGumDrawBezier(0x180, 4, 4, NULL, gear0_bottom);
		sceGumDrawBezier(0x180, 4, 4, NULL, gear0_in);
		sceGumDrawArray(4, 0x9E0, 6, gear0_out_idx0, gear0_out);
		sceGumDrawArray(4, 0x9E0, 5, gear0_out_idx1, gear0_out);
		sceGumDrawArray(4, 0x9E0, 5, gear0_out_idx2, gear0_out);
		sceGumDrawArray(4, 0x9E0, 5, gear0_out_idx3, gear0_out);
		sceGumDrawArray(4, 0x9E0, 5, gear0_out_idx4, gear0_out);
		sceGumDrawArray(3, 0x9E0, 48, gear0_out_idx5, gear0_out);
		sceGumRotateY(3.14159265f / 4.0f);
	}
	sceGumPopMatrix();
}

static void draw_gear1(void)
{
	int i;

	sceGumPushMatrix();
	for (i = 0; i < 8; i++) {
		sceGumDrawBezier(0x180, 4, 4, NULL, gear1_top);
		sceGumDrawBezier(0x180, 4, 4, NULL, gear1_bottom);
		sceGumDrawBezier(0x180, 4, 4, NULL, gear1_in);
		sceGumDrawArray(4, 0x9E0, 5, gear1_out_idx0, gear1_out);
		sceGumDrawArray(4, 0x9E0, 5, gear1_out_idx1, gear1_out);
		sceGumDrawArray(4, 0x9E0, 5, gear1_out_idx2, gear1_out);
		sceGumDrawArray(4, 0x9E0, 5, gear1_out_idx3, gear1_out);
		sceGumDrawArray(3, 0x9E0, 12, gear1_out_idx4, gear1_out);
		sceGumRotateY(3.14159265f / 4.0f);
	}
	sceGumPopMatrix();
}

static void draw_gear2(void)
{
	int i;

	sceGumPushMatrix();
	for (i = 0; i < 6; i++) {
		sceGumDrawBezier(0x180, 4, 4, NULL, gear2_top);
		sceGumDrawBezier(0x180, 4, 4, NULL, gear2_bottom);
		sceGumDrawBezier(0x180, 4, 4, NULL, gear2_in);
		sceGumDrawArray(4, 0x9E0, 6, gear2_out_idx0, gear2_out);
		sceGumDrawArray(4, 0x9E0, 5, gear2_out_idx1, gear2_out);
		sceGumDrawArray(4, 0x9E0, 5, gear2_out_idx2, gear2_out);
		sceGumDrawArray(4, 0x9E0, 5, gear2_out_idx3, gear2_out);
		sceGumDrawArray(4, 0x9E0, 5, gear2_out_idx4, gear2_out);
		sceGumDrawArray(3, 0x9E0, 48, gear2_out_idx5, gear2_out);
		sceGumRotateY(3.14159265f / 3.0f);
	}
	sceGumPopMatrix();
}



static void draw_frame(void)
{
	ScePspFVector3 vec;

	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);
	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos);
	sceGumRotateX(rot.x * 3.14159265f / 180.0f);
	sceGumRotateY(rot.y * 3.14159265f / 180.0f);
	sceGumRotateZ(rot.z * 3.14159265f / 180.0f);

	sceGumPushMatrix();
	sceGumRotateY(angle * 3.14159265f / 180.0f);
	sceGuColor(0xffffff80);
	draw_gear0();
	sceGumPopMatrix();

	sceGumPushMatrix();
	vec.x = 8.3f;
	vec.y = 0.0f;
	vec.z = -3.35f;
	sceGumTranslate(&vec);
	sceGumRotateY((20.0f - 2.0f * angle) * 3.14159265f / 180.0f);
	sceGuColor(0xffff80ff);
	draw_gear1();
	sceGumPopMatrix();

	sceGumPushMatrix();
	sceGumRotateY(1.0853983f);
	sceGumRotateX(3.14159265f / 2.0f);
	vec.x = 0.55f;
	vec.y = -4.9f;
	vec.z = -3.6f;
	sceGumTranslate(&vec);
	sceGumRotateY(-1.333333f * angle * 3.14159265f / 180.0f);
	sceGuColor(0xff80ffff);
	draw_gear2();
	sceGumPopMatrix();

	sceGumPushMatrix();
	vec.x = -9.0f;
	vec.y = 8.2f;
	vec.z = -5.0f;
	sceGumTranslate(&vec);
	sceGumRotateY((angle + 8.0f) * 3.14159265f / 180.0f);
	sceGuColor(0xff8080ff);
	draw_gear0();
	sceGumPopMatrix();

	sceGumPopMatrix();
	sceGuFinish();
	sceGuSync(0, 0);
}

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
	sceGuDisable(9);
	sceGuSetDither(&dith);
	sceGuEnable(6);
	sceGuEnable(8);
	sceGuShadeModel(1);
	vec.x = 0.614497f;
	vec.y = 0.691714f;
	vec.z = 0.379372f;
	sceGuLightColor(0, 2, 0xffffffff);
	sceGuLight(0, 0, 2, &vec);
	sceGuEnable(0xB);
	sceGuEnable(0xA);
	sceGuDisable(7);
	sceGuAmbient(0xffdddddd);
	sceGumSetMatrixStack(matrix_stack, 8, 8, 0x20, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 1000.0f);
	sceGumMatrixMode(2);
	sceGuClearColor(0x601c1c);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	pos.x = 2.5f;
	pos.y = -3.0f;
	pos.z = -22.0f;
	rot.x = 35.0f;
	rot.z = 0.0f;
	rot.y = 0.0f;
	rotate = 1;
	angle = 0.0f;
	sceGuDisplay(1);
}

static int pad_read(void)
{
	u_int32 prev;
	u_int32 padd;
	SceCtrlData buf;

	prev = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd = cont & (cont ^ prev);
	if (cont & 0x0010) {
		rot.x -= 2.0f;
		if (rot.x < 0.0f)
			rot.x += 360.0f;
	}
	if (cont & 0x0040) {
		rot.x += 2.0f;
		if (rot.x >= 360.0f)
			rot.x -= 360.0f;
	}
	if (cont & 0x0080) {
		rot.y += 2.0f;
		if (rot.y >= 360.0f)
			rot.y -= 360.0f;
	}
	if (cont & 0x0020) {
		rot.y -= 2.0f;
		if (rot.y < 0.0f)
			rot.y += 360.0f;
	}
	if (padd & 0x2000)
		rotate ^= 1;
	if (cont & 0x0100)
		pos.z -= 1.0f;
	if (cont & 0x0200)
		pos.z += 1.0f;
	if (padd & 0x0009)
		return 0;
	return 1;
}

static void frame_update(void)
{
	if (rotate) {
		angle += 2.0f;
		if (angle >= 360.0f)
			angle -= 360.0f;
	}
}

int main(void)
{
	menuInit();
	init_all();
	while (pad_read()) {
		draw_frame();
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
		frame_update();
	}
	sceGuTerm();
	menuTerm(1, 12);
	return 0;
}

