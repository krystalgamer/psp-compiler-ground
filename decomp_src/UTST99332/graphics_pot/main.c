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

extern const unsigned int env_clut[128];
extern const unsigned int env_tex[256];
extern const unsigned int toon_clut[8];
extern const unsigned int toon_tex[128];
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
extern int autoflag;
extern int mode;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];

static void draw_frame(int frame);
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
void sceGuSpecular(float power);
void sceGuShadeModel(int mode);
void sceGuFrontFace(int order);
void sceGuDepthFunc(int function);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
int sceDisplayWaitVblankStart(void);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuAmbient(unsigned int color);
void sceGuClear(int flags);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuColor(unsigned int color);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexWrap(int u, int v);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateXYZ(const ScePspFVector3 *v);
void sceGumRotateY(float angle);
void sceGumTranslate(const ScePspFVector3 *v);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", env_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", env_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", toon_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", toon_tex);

#define SCEGU_IMMEDIATE                    0
#define SCEGU_CLEAR_ALL               0x0007
#define MODE_SPECULAR ((0)+1)
#define SCEGU_SPECULAR                     4
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#define MODE_TOON ((0)+3)
#define SCEGU_PFIDX4                       4
#define SCEGU_TEX_REPLACE                  3
#define MODE_ENVMAP ((0)+2)
#define SCEGU_PFIDX8                       5
#define SCEGU_SINGLE_CLUT                  0
#define SCEGU_TEXBUF_NORMAL                0
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#define SCEGU_LINEAR                       1
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGB                          0
#define SCEGU_REPEAT                       0
#define SCEGU_PF5551                       1
#define SCEGU_SHADE_MAP                    2
#define MODE_DIFFUSE (0)
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE                      2
#define SCEGU_LIGHT0                      11
#define SCEGU_LIGHT1                      12
#define SCEGU_TEXTURE                      9
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0

static void draw_frame(int frame)
{
	ScePspFVector3	vec;

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));

	sceGuClear(SCEGU_CLEAR_ALL);

	if (changed) {
		changed = 0;
		switch (mode) {
		case MODE_SPECULAR:
			
			sceGuColor(0xffb2b2a5);
			sceGuAmbient(0xff866557);

			
			vec.x = -1.299999f;
			vec.y = 4.125459f;
			vec.z = 3.799998f;
			sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT0);
			vec.x = 3.949999f;
			vec.y = 8.825475f;
			vec.z = 4.900001f;
			sceGuLightColor(1, SCEGU_DIFFUSE, 0x00000000);
			sceGuLightColor(1, SCEGU_SPECULAR, 0xffffffff);
			sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR,
					&vec);
			sceGuEnable(SCEGU_LIGHT1);

			
			sceGuDisable(SCEGU_TEXTURE);
			break;
		case MODE_TOON:
			
			vec.x = 1.0f;
			vec.y = 0.0f;
			vec.z = 0.0f;
			sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT0);
			vec.x = 0.0f;
			vec.y = 1.0f;
			vec.z = 0.0f;
			sceGuLightColor(1, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT1);

			
			sceGuTexImage(0, 32, 32, 32, toon_tex);
			sceGuTexMode(SCEGU_PFIDX4, 0, SCEGU_SINGLE_CLUT,
					SCEGU_TEXBUF_NORMAL);
			sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR);
			sceGuTexFunc(SCEGU_TEX_REPLACE, SCEGU_RGB);
			sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
			sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
			sceGuClutLoad(1, toon_clut);
			sceGuTexMapMode(SCEGU_SHADE_MAP, 0, 1);
			sceGuEnable(SCEGU_TEXTURE);
			break;
		case MODE_ENVMAP:
			
			sceGuColor(0xff97c5d0);
			sceGuAmbient(0xff648296);

			
			vec.x = 1.0f;
			vec.y = 0.0f;
			vec.z = 0.0f;
			sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT0);
			vec.x = 0.0f;
			vec.y = 1.0f;
			vec.z = 0.0f;
			sceGuLightColor(1, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT1);

			
			sceGuTexImage(0, 32, 32, 32, env_tex);
			sceGuTexMode(SCEGU_PFIDX8, 0, SCEGU_SINGLE_CLUT,
					SCEGU_TEXBUF_NORMAL);
			sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR);
			sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGB);
			sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
			sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
			sceGuClutLoad(16, env_clut);
			sceGuTexMapMode(SCEGU_SHADE_MAP, 0, 1);
			sceGuEnable(SCEGU_TEXTURE);
			break;
		case MODE_DIFFUSE:
		default:
			
			sceGuColor(0xff99bfcc);
			sceGuAmbient(0xff667272);

			
			vec.x = -1.299999f;
			vec.y = 4.125459f;
			vec.z = 3.799998f;
			sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT0);
			sceGuDisable(SCEGU_LIGHT1);

			
			sceGuDisable(SCEGU_TEXTURE);
			break;
		}
	}

	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos.trans);
	if (autoflag) {
		angle = SCEGU_RAD((float)((frame*3)%360));
		vec.x = angle;
		vec.y = angle;
		vec.z = angle;
		sceGumRotateXYZ(&vec);
	} else {
		sceGumRotateX(SCEGU_RAD(pos.rot.x));
		sceGumRotateY(SCEGU_RAD(pos.rot.y));
	}
	DrawPot();

	sceGumPopMatrix();

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
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
    sceGuDepthFunc(6);
    sceGuEnable(1);
    sceGuFrontFace(1);
    sceGuEnable(0x14);
    sceGuDisable(9);
    sceGuShadeModel(1);
    sceGuEnable(6);
    sceGuEnable(0xA);
    sceGuSpecular(75.0f);
    sceGumSetMatrixStack(matrix_stack, 8, 8, 0x20, 0);
    sceGumMatrixMode(0);
    sceGumLoadIdentity();
    sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
    sceGuClearColor(0xFF645A1EU);
    sceGuClearDepth(0U);
    sceGuClearStencil(0U);
    sceGumMatrixMode(2);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGuDisplay(1);
}

static void init_pos(void)
{
	pos.rot.x = 30.0f;
	pos.rot.y = pos.rot.z = 0.0f;
	pos.trans.x = 0.0f;
	pos.trans.y = 0.0f;
	pos.trans.z = -10.0f;
}

extern u_int32 D_000153C8; /* static u_int32 opadd in pad_read (bss is asm) */

static int pad_read(void)
{
	u_int32 padd;
	SceCtrlData buf;

	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;

	if (padd & 0x10) {
		pos.rot.x -= 15.0f;
		if (pos.rot.x <= -360.0f) {
			pos.rot.x = 0.0f;
		}
	}

	if (padd & 0x40) {
		pos.rot.x += 15.0f;
		if (pos.rot.x >= 360.0f) {
			pos.rot.x = 0.0f;
		}
	}

	if (padd & 0x80) {
		pos.rot.y -= 15.0f;
		if (pos.rot.y <= -360.0f) {
			pos.rot.y = 0.0f;
		}
	}

	if (padd & 0x20) {
		pos.rot.y += 15.0f;
		if (pos.rot.y >= 360.0f) {
			pos.rot.y = 0.0f;
		}
	}

	if (padd & 0x100) {
		pos.trans.z -= 3.0f;
		if (pos.trans.z < -100.0f) {
			pos.trans.z = -100.0f;
		}
	}

	if (padd & 0x200) {
		pos.trans.z += 3.0f;
		if (pos.trans.z > -5.0f) {
			pos.trans.z = -5.0f;
		}
	}

	if (padd & 0x2000) {
		mode = 1;
		changed = 1;
	}

	if (padd & 0x4000) {
		mode = 2;
		changed = 1;
	}

	if (padd & 0x1000) {
		mode = 3;
		changed = 1;
	}

	if (padd & 0x8000) {
		mode = 0;
		changed = 1;
	}

	if (padd & 0x8) {
		if (D_000153C8 != padd) {
			init_pos();
			autoflag ^= 1;
		}
	}

	if (padd & 0x1) {
		return 0;
	}

	D_000153C8 = padd;

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
    menuTerm(1, 0x17);
    return 0;
}
