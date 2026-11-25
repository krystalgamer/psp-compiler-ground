#include "common.h"

/* declarations recovered from DWARF */
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
typedef unsigned int u_int32;
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

extern u_int32 texture_data0[512];
extern u_int32 texture_data1[128];
extern u_int32 dogtexture_data0[512];
extern u_int32 dogtexture_data1[128];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern POS pos;
extern float angle;
extern int changed;
extern int alphaflag;
extern int texflag;
extern int fogflag;
extern int dogflag;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[16];

static void draw_frame(int frame);
static void init_all(void);
static int pad_read(void);
int main(void);

/* SDK functions */
void menuInit(void);
void menuTerm(int cat, int num);
void DrawCube(float size);
int abs(int);
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
void sceGuFog(float near, float far, unsigned int color);
void sceGuShadeModel(int mode);
void sceGuFrontFace(int order);
void sceGuDepthFunc(int function);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
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

static void draw_frame(int frame)
{
	ScePspFVector3 vec;
	int i, j, k;

	angle = (float)((frame * 2) % 360) * 3.1415927f / 180.0f;
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);
	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos.trans);
	sceGumRotateX(pos.rot.x * 3.1415927f / 180.0f);
	sceGumRotateY(pos.rot.y * 3.1415927f / 180.0f);
	if (changed) {
		changed = 0;
		if (alphaflag)
			sceGuEnable(4);
		else
			sceGuDisable(4);
		if (fogflag)
			sceGuEnable(7);
		else
			sceGuDisable(7);
		if (texflag) {
			if (dogflag) {
				sceGuTexImage(0, 32, 32, 32, dogtexture_data0);
				sceGuTexImage(1, 16, 16, 16, dogtexture_data1);
			} else {
				sceGuTexImage(0, 32, 32, 32, texture_data0);
				sceGuTexImage(1, 16, 16, 16, texture_data1);
			}
			sceGuEnable(9);
		} else {
			sceGuDisable(9);
		}
	}
	for (k = -2; k < 3; k++) {
		for (j = -2; j < 3; j++) {
			for (i = -2; i < 3; i++) {
				if (abs(i) + abs(j) + abs(k) == 2) {
					sceGumPushMatrix();
					vec.x = i * 3.2f;
					vec.y = j * 3.2f;
					vec.z = k * 3.2f;
					sceGumTranslate(&vec);
					sceGumRotateZ((i + 2) * angle);
					sceGumRotateY((j + 2) * angle);
					sceGumRotateX((k + 2) * angle);
					DrawCube(1.0f);
					sceGumPopMatrix();
				}
			}
		}
	}
	sceGumPopMatrix();
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
	sceGuDepthFunc(7);
	sceGuEnable(1);
	sceGuFrontFace(0);
	sceGuDisable(9);
	sceGuShadeModel(1);
	sceGuEnable(6);
	vec.x = 0.0f;
	vec.y = 0.0f;
	vec.z = 1.0f;
	sceGuLightColor(0, 2, 0xffffffff);
	sceGuLight(0, 0, 2, &vec);
	vec.x = 1.0f;
	vec.y = 0.0f;
	vec.z = 0.0f;
	sceGuLightColor(1, 2, 0xff00ffff);
	sceGuLight(1, 0, 2, &vec);
	vec.x = -1.0f;
	vec.y = 0.0f;
	vec.z = 0.0f;
	sceGuLightColor(2, 2, 0xffff00ff);
	sceGuLight(2, 0, 2, &vec);
	sceGuEnable(11);
	sceGuEnable(12);
	sceGuEnable(13);
	sceGuEnable(10);
	sceGuFog(14.5f, 25.0f, 0x007f00ff);
	sceGuAmbient(0xcc004cb2);
	sceGuColor(0x80ffffff);
	sceGuTexMode(1, 1, 0, 0);
	sceGuTexFilter(5, 1);
	sceGuTexFunc(0, 0);
	sceGuTexWrap(0, 0);
	sceGumSetMatrixStack(matrix_stack, 4, 4, 8, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
	sceGumMatrixMode(2);
	sceGuClearColor(0x007f00ff);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	pos.rot.x = 0.0f;
	pos.rot.y = 0.0f;
	pos.rot.z = 0.0f;
	pos.trans.x = 0.0f;
	pos.trans.y = 0.0f;
	pos.trans.z = -22.0f;
	sceGuDisplay(1);
}

static int pad_read(void)
{
	SceCtrlData buf;
	u_int32 padd;
	int l_down;

	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;
	l_down = 0;
	if (padd & 0x0010) {
		pos.rot.x -= 1.0f;
		if (pos.rot.x == -360.0f)
			pos.rot.x = 0.0f;
	}
	if (padd & 0x0040) {
		pos.rot.x += 1.0f;
		if (pos.rot.x == 360.0f)
			pos.rot.x = 0.0f;
	}
	if (padd & 0x0080) {
		pos.rot.y -= 1.0f;
		if (pos.rot.y == -360.0f)
			pos.rot.y = 0.0f;
	}
	if (padd & 0x0020) {
		pos.rot.y += 1.0f;
		if (pos.rot.y == 360.0f)
			pos.rot.y = 0.0f;
	}
	if (padd & 0x0100) {
		if (padd & 0x0200) {
			changed = 1;
			texflag = 0;
			dogflag = 0;
		}
		l_down = 1;
	}
	if (padd & 0x2000) {
		if (l_down) {
			alphaflag = 1;
			changed = 1;
		} else {
			pos.trans.z -= 1.0f;
			if (pos.trans.z < -100.0f)
				pos.trans.z = -100.0f;
		}
	}
	if (padd & 0x4000) {
		if (l_down) {
			alphaflag = 0;
			changed = 1;
		} else {
			pos.trans.z += 1.0f;
			if (pos.trans.z > -2.0f)
				pos.trans.z = -2.0f;
		}
	}
	if (padd & 0x1000) {
		if (l_down) {
			fogflag = 1;
			changed = 1;
		} else {
			texflag = 1;
			dogflag = 1;
			changed = 1;
		}
	}
	if (padd & 0x8000) {
		if (l_down) {
			fogflag = 0;
			changed = 1;
		} else {
			texflag = 1;
			dogflag = 0;
			changed = 1;
		}
	}
	if (padd & 0x0008) {
		pos.rot.x = 0.0f;
		pos.rot.y = 0.0f;
		pos.rot.z = 0.0f;
		pos.trans.x = 0.0f;
		pos.trans.y = 0.0f;
		pos.trans.z = -22.0f;
	}
	if (padd & 0x0001)
		return 0;
	return 1;
}

int main(void)
{
	int i;

	menuInit();
	init_all();
	for (i = 0;; i++) {
		if (!pad_read())
			break;
		draw_frame(i);
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
	}
	sceGuTerm();
	menuTerm(1, 4);
	return 0;
}
