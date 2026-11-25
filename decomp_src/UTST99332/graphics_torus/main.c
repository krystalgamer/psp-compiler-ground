/* data-align: 16 */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x14 */
    unsigned int c;
    float in;
    float out;
    float speed;
    int div;
};
typedef struct _anon1 TORUS_DATA;
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
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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
extern int autoflag;
extern float array[6][147];
extern TORUS_DATA data[6];
extern int cont;

static void draw_frame(void);
static void init_all(void);
static int pad_read(void);
int main(void);

/* SDK functions */
void menuInit(void);
void menuTerm(int cat, int num);
void DrawTorus(float *array, float in, float out);
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
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
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
int sceDisplayWaitVblankStart(void);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

static void draw_frame(void)
{
	TORUS_DATA *p;
	int i;

	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);
	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos);
	sceGumRotateX(rot.x * 3.1415927f / 180.0f);
	sceGumRotateY(rot.y * 3.1415927f / 180.0f);
	sceGumRotateZ(rot.z * 3.1415927f / 180.0f);
	for (i = 0; i < 6; i++) {
		p = &data[i];
		sceGumPushMatrix();
		sceGuColor(p->c);
		sceGumRotateX(angle * p->speed * 3.1415927f / 180.0f);
		sceGuPatchDivide(p->div, p->div);
		DrawTorus(array[i], p->in, p->out);
		sceGumPopMatrix();
	}
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
	sceGuDrawBuffer(1, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x44000, 512);
	sceGuDepthBuffer((void *)0x88000, 512);
	sceGuOffset(2048 - 480 / 2, 2048 - 272 / 2);
	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(50000, 10000);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);
	sceGuAlphaFunc(6, 0, 255);
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
	sceGuEnable(11);
	sceGuEnable(10);
	sceGuDisable(7);
	sceGuAmbient(0xffdddddd);
	sceGumSetMatrixStack(matrix_stack, 8, 8, 32, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 1000.0f);
	sceGumMatrixMode(2);
	sceGuClearColor(0x00601c1c);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = -100.0f;
	rot.x = 0.0f;
	rot.z = 0.0f;
	rot.y = 30.0f;
	sceGuDisplay(1);
}

static int pad_read(void)
{
	int prev, padd;
	SceCtrlData buf;

	prev = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd = cont & (cont ^ prev);
	if (!autoflag) {
		if (cont & 0x0010) {
			rot.x -= 1.0f;
			if (rot.x < 0.0f)
				rot.x += 360.0f;
		}
		if (cont & 0x0040) {
			rot.x += 1.0f;
			if (rot.x >= 360.0f)
				rot.x -= 360.0f;
		}
		if (cont & 0x0080) {
			rot.y += 1.0f;
			if (rot.y >= 360.0f)
				rot.y -= 360.0f;
		}
		if (cont & 0x0020) {
			rot.y -= 1.0f;
			if (rot.y < 0.0f)
				rot.y += 360.0f;
		}
		if (cont & 0x0100)
			pos.z -= 1.0f;
		if (cont & 0x0200)
			pos.z += 1.0f;
	}
	if (padd & 0x2000)
		autoflag ^= 1;
	return (padd & 0x0009) == 0;
}

int main(void)
{
	menuInit();
	init_all();
	for (;;) {
		if (!pad_read())
			break;
		draw_frame();
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
		if (autoflag) {
			angle += 1.0f;
			if (angle >= 360.0f)
				angle = 0.0f;
			rot.y += 1.0f;
			if (rot.y >= 360.0f)
				rot.y = 0.0f;
			rot.z += 1.0f;
			if (rot.z >= 360.0f)
				rot.z = 0.0f;
		}
	}
	sceGuTerm();
	menuTerm(1, 35);
	return 0;
}

