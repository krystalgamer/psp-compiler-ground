#include "common.h"

/* declarations recovered from DWARF */
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
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1;
typedef unsigned int u_int32;
struct _anon1 { /* size 0x68 */
    u_int32 amb;
    u_int32 diff;
    u_int32 spec;
    ScePspFVector3 pos;
    ScePspFVector3 dir;
    float exp;
    float cut;
    float atte[3];
    ScePspFVector3 trans;
    ScePspFVector3 rot;
    ScePspFVector3 angle;
    ScePspFVector3 speed;
};
typedef struct _anon1 LIGHT_INFO;
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
struct _anon2;
struct _anon2 { /* size 0x18 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
};
typedef struct _anon2 POS;

/* SDK functions */
void sceGuSpecular(float power);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuLightAtt(int light, float atten0, float atten1, float atten2);
void sceGuLightSpot(int light, const ScePspFVector3 *direction, float exponent, float cutoff);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

extern LIGHT_INFO spots[3];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern POS pos;
extern int auto_flag;
extern int line_flag;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[16];

static void light_update(void);
float sinf(float);
float cosf(float);
static void draw_frame(void);
static void init_light(void);
static void init_pos(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
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
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuAmbient(unsigned int color);
void sceGuShadeModel(int mode);
void sceGuFrontFace(int order);
void sceGuDepthFunc(int function);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
int sceDisplayWaitVblankStart(void);


void mult_matvec(ScePspFMatrix4 *m, ScePspFVector4 *vi, ScePspFVector3 *vo) {
    vo->x = (m->x.x * vi->x) + (m->y.x * vi->y) + (m->z.x * vi->z) + (m->w.x * vi->w);
    vo->y = (m->x.y * vi->x) + (m->y.y * vi->y) + (m->z.y * vi->z) + (m->w.y * vi->w);
    vo->z = (m->x.z * vi->x) + (m->y.z * vi->y) + (m->z.z * vi->z) + (m->w.z * vi->w);
}

static void light_update(void)
{
	int i;
	LIGHT_INFO *lp;

	for (i = 0; i < 3; i++) {
		lp = &spots[i];
		lp->angle.x += lp->speed.x;
		if (lp->angle.x > 360.0f)
			lp->angle.x -= 360.0f;
		lp->angle.y += lp->speed.y;
		if (lp->angle.y > 360.0f)
			lp->angle.y -= 360.0f;
		lp->angle.z += lp->speed.z;
		if (lp->angle.z > 360.0f)
			lp->angle.z -= 360.0f;
		lp->rot.x = sinf(lp->angle.x * 3.1415927f / 180.0f) * 0.5235988f;
		lp->rot.y = sinf(lp->angle.y * 3.1415927f / 180.0f) * 0.5235988f;
		lp->rot.z = sinf(lp->angle.z * 3.1415927f / 180.0f) * 0.5235988f;
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_spots/nonmatchings/main", draw_frame);

static void init_light(void)
{
	ScePspFVector3 vec;
	ScePspFVector3 dir;
	int i;

	sceGuSpecular(10.0f);
	vec.x = 0.0f;
	vec.y = 0.0f;
	vec.z = 0.0f;
	for (i = 0; i < 3; i++) {
		sceGuLightColor(i, 1, spots[i].amb);
		sceGuLightColor(i, 2, spots[i].diff);
		sceGuLightColor(i, 4, spots[i].spec);
		sceGuLight(i, 2, 6, &vec);
		dir.x = -spots[i].dir.x;
		dir.y = -spots[i].dir.y;
		dir.z = -spots[i].dir.z;
		sceGuLightSpot(i, &dir, spots[i].exp, cosf(spots[i].cut * 3.1415927f / 180.0f));
		sceGuLightAtt(i, spots[i].atte[0], spots[i].atte[1], spots[i].atte[2]);
		sceGuEnable(11 + i);
	}
	sceGuLightColor(3, 2, 0xffffffff);
	vec.x = 1.0f;
	vec.y = -1.0f;
	vec.z = -1.0f;
	sceGuLight(3, 0, 2, &vec);
	sceGuEnable(14);
	sceGuEnable(10);
}

static void init_pos(void)
{
	pos.rot.x = 28.0f;
	pos.rot.y = 0.0f;
	pos.rot.z = 0.0f;
	pos.trans.x = 0.0f;
	pos.trans.y = -2.2f;
	pos.trans.z = -9.0f;
}

void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x10000);
    sceGuDrawBuffer(1, NULL, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
    sceGuDepthBuffer((void *)0x88000, 0x200);
    sceGuOffset(0x710U, 0x778U);
    sceGuViewport(0x800, 0x800, 0x1E0, 0x110);
    sceGuDepthRange(0xC350, 0x2710);
    sceGuDisable(4);
    sceGuScissor(0, 0, 0x1E0, 0x110);
    sceGuEnable(2);
    sceGuDepthFunc(7);
    sceGuEnable(1);
    sceGuFrontFace(0);
    sceGuDisable(9);
    sceGuShadeModel(1);
    sceGuEnable(6);
    sceGuAmbient(0x404040U);
    sceGuColor(0xC0C0C0U);
    sceGumSetMatrixStack(matrix_stack, 4, 4, 8, 0);
    sceGumMatrixMode(0);
    sceGumLoadIdentity();
    sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
    sceGumMatrixMode(2);
    sceGumLoadIdentity();
    sceGuClearColor(0U);
    sceGuClearDepth(0U);
    sceGuClearStencil(0U);
    InitRing();
    init_light();
    sceGuFinish();
    sceGuSync(0, 0);
    sceGuDisplay(1);
}

#define opadd D_000151C4	/* pad_read's static */
extern u_int32 opadd;

static int pad_read(void)
{
	u_int32 padd;
	SceCtrlData buf;

	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;
	if (padd & 0x0080) {
		pos.rot.y -= 0.5f;
		if (pos.rot.y < 0.0f)
			pos.rot.y += 360.0f;
	}
	if (padd & 0x0020) {
		pos.rot.y += 0.5f;
		if (pos.rot.y >= 360.0f)
			pos.rot.y -= 360.0f;
	}
	if (padd != opadd) {
		if (padd & 0x2000)
			line_flag ^= 1;
		if (padd & 0x0008) {
			auto_flag ^= 1;
			init_pos();
		}
	}
	if (padd & 0x0001)
		return 0;
	opadd = padd;
	return 1;
}

int main(void) {
    menuInit();
    init_all();
    init_pos();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0x1A);
    return 0;
}
