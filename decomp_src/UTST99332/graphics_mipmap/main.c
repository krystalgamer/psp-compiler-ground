/* cflags: -O2 -fmerge-constants */
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
struct _anon1;
struct _anon1 { /* size 0x8 */
    int num;
    const unsigned int *clut;
};
typedef struct _anon1 CLUT_INFO;
struct _anon2;
struct _anon2 { /* size 0x10 */
    int tw;
    int th;
    int w;
    const unsigned int *tex;
};
typedef struct _anon2 TEX_INFO;
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
struct _anon3;
struct _anon3 { /* size 0x24 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
    ScePspFVector3 scale;
};
typedef struct _anon3 POS;
struct _anon4;
struct _anon4 { /* size 0x24 */
    ScePspFVector3 eye;
    ScePspFVector3 center;
    ScePspFVector3 up;
};
typedef struct _anon4 VIEW;
struct _anon5;
struct _anon5 { /* size 0x8 */
    float u;
    float v;
};
typedef struct _anon5 TEXD;
struct _anon6;
struct _anon6 { /* size 0x8 */
    int tmode;
    int cmode;
};
typedef struct _anon6 TEXMODE;
struct _anon7;
struct _anon7 { /* size 0x30 */
    int ofx;
    int ofy;
    int sx;
    int sy;
    char str[32];
};
typedef struct _anon7 MIPMAP;
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

extern const unsigned int grid_clut[64];
extern const unsigned int way_clut[128];
extern const unsigned int grid_1_tex[2048];
extern const unsigned int grid_2_tex[512];
extern const unsigned int grid_3_tex[128];
extern const unsigned int grid_4_tex[64];
extern const unsigned int grid_5_tex[32];
extern const unsigned int grid_6_tex[16];
extern const unsigned int grid_7_tex[16];
extern const unsigned int grid_8_tex[4];
extern const unsigned int way_1_tex[4096];
extern const unsigned int way_2_tex[1024];
extern const unsigned int way_3_tex[256];
extern const unsigned int way_4_tex[64];
extern const unsigned int way_5_tex[32];
extern const unsigned int way_6_tex[16];
extern const unsigned int way_7_tex[8];
extern const unsigned int way_8_tex[4];
extern const CLUT_INFO cinfo[2];
extern const TEX_INFO tinfo[2][8];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern POS pos;
extern VIEW view;
extern TEXD toffset;
extern int moving;
extern int maxlod;
extern int mode;
extern const u_int32 bg_col[2];
extern const TEXMODE tmode[2];
extern const float road_poly[20];
extern const MIPMAP mipmap[4];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[16];


/* SDK functions (tools/sdk_protos.h) */
void sceGuInit(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGuDepthRange(int near, int far);
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuAmbient(unsigned int color);
void sceGuShadeModel(int mode);
void sceGuFrontFace(int order);
void sceGuDepthFunc(int function);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);

static void draw_frame(void);
static void init_all(void);
static void init_param(void);
static int pad_read(void);
int main(void);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexLevelMode(unsigned int mode, float bias);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexSlope(float slope);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateXYZ(const ScePspFVector3 *v);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);
int sprintf(char *buf, const char *fmt, ...);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_1_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_2_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_3_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_4_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_5_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_6_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_7_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_8_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_1_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_2_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_3_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_4_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_5_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_6_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_7_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_8_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", cinfo);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", tinfo);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", bg_col);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", tmode);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", road_poly);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", mipmap);

extern int D_0001BE04;

void frame_update(void) {
    int temp_v1;

    temp_v1 = D_0001BE04 + 1;
    toffset.v += -0.005524693f;
    D_0001BE04 = temp_v1;
    if (temp_v1 >= 0x5A0) {
        D_0001BE04 = 0;
        toffset.v = -0.044444f;
    }
}

#define SCEGU_IMMEDIATE                    0
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)
#define SCEGU_CLEAR_ALL               0x0007
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define MAXLOD			(8)
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272
#define SCEGU_LOD_AUTO                     0
#define SCEGU_LOD_CONSTANT                 1
#define SCEGU_LOD_SLOPE                    2
#define SCEGU_TEXBUF_NORMAL                0
#define SCEGU_PRIM_TRIANGLE_STRIP          4
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#define SCEGU_TEXTURE_FLOAT      ( 3 <<  0 )
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0

static void draw_frame(void)
{
	ScePspFVector3	vec;
	int				i, n;
	char			str[16];

	sceGuStart(SCEGU_IMMEDIATE, (void *)disp_list, sizeof(disp_list));

	sceGuOffset(SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY);
	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuClearColor(bg_col[mode]);
	sceGuClear(SCEGU_CLEAR_ALL);

	sceGuTexOffset(toffset.u, toffset.v);

	sceGumPushMatrix();
	sceGumLoadIdentity();

	sceGumTranslate(&pos.trans);
	vec.x = SCEGU_RAD(pos.rot.x);
	vec.y = SCEGU_RAD(pos.rot.y);
	vec.z = SCEGU_RAD(pos.rot.z);
	sceGumRotateXYZ(&vec);
	sceGumScale(&pos.scale);

	for (i = 0; i < MAXLOD; i++) {
		sceGuTexImage(i, tinfo[mode][i].tw, tinfo[mode][i].th,
				tinfo[mode][i].w, (void *)tinfo[mode][i].tex);
	}
	sceGuClutLoad(cinfo[mode].num, (void *)cinfo[mode].clut);

	for (i = 0; i < 4; i++) {
		sceGuOffset(mipmap[i].ofx, mipmap[i].ofy);
		sceGuScissor(mipmap[i].sx, mipmap[i].sy,
				SCEGU_SCR_WIDTH/2, SCEGU_SCR_HEIGHT/2);
		sceGumPushMatrix();
		switch (i) {
		case 1:
			n = maxlod-1;
			sceGuTexLevelMode(SCEGU_LOD_AUTO, 0.0f);
			break;
		case 2:
			n = maxlod-1;
			sceGuTexLevelMode(SCEGU_LOD_CONSTANT, 2.0f);
			break;
		case 3:
			n = maxlod-1;
			sceGuTexLevelMode(SCEGU_LOD_SLOPE, 0.0f);
			sceGuTexSlope(0.3f);
			break;
		case 0:
		default:
			n = 0;
			break;
		}
		sceGuTexMode(tmode[mode].tmode, n, tmode[mode].cmode,
				SCEGU_TEXBUF_NORMAL);
		sceGumDrawArray(SCEGU_PRIM_TRIANGLE_STRIP,
			SCEGU_VERTEX_FLOAT|SCEGU_TEXTURE_FLOAT, 4, 0, road_poly);
		sceGumPopMatrix();
		sceGuDebugPrint(mipmap[i].sx, mipmap[i].sy, 0x00ffffff, mipmap[i].str);
	}
	sceGumPopMatrix();

	sprintf(str, "LOD:%d\n", maxlod);
	sceGuDebugPrint(420, 260, 0x00ffffff, str);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
}

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x10000);
    sceGuDrawBuffer(1, NULL, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
    sceGuDepthBuffer((void *)0x88000, 0x200);
    sceGuViewport(0x800, 0x800, 0xF0, 0x88);
    sceGuDepthRange(0xC350, 0x2710);
    sceGuScissor(0, 0, 0xF0, 0x88);
    sceGuEnable(2);
    sceGuDepthFunc(7);
    sceGuEnable(1);
    sceGuFrontFace(1);
    sceGuShadeModel(1);
    sceGuDisable(4);
    sceGuEnable(6);
    sceGuDisable(0xA);
    sceGuAmbient(0xFF404040U);
    sceGuColor(-1U);
    sceGuTexFilter(7, 1);
    sceGuTexFunc(0, 0);
    sceGuTexWrap(0, 0);
    sceGuTexScale(2.0f, 1.0f);
    sceGuTexOffset(toffset.u, toffset.v);
    sceGuClutMode(1U, 0U, 0xFFU, 0U);
    sceGuEnable(9);
    sceGumSetMatrixStack(matrix_stack, 4, 4, 8, 0);
    sceGumMatrixMode(0);
    sceGumLoadIdentity();
    sceGumPerspective(1.0471976f, 1.7647059f, 1.0f, 100.0f);
    sceGumMatrixMode(1);
    sceGumLoadIdentity();
    sceGumLookAt(&view.eye, &view.center, &view.up);
    sceGumMatrixMode(2);
    sceGumLoadIdentity();
    sceGuClearDepth(0U);
    sceGuClearStencil(0U);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGuDisplay(1);
}

static void init_param(void)
{
	view.eye.x = 0.0f;
	view.eye.y = 2.0f;
	view.eye.z = 0.0f;
	view.center.x = 0.0f;
	view.center.y = 0.0f;
	view.center.z = -3.0f;
	view.up.x = 0.0f;
	view.up.y = 1.0f;
	view.up.z = 0.0f;

	pos.rot.x = 0.0f;
	pos.rot.y = 0.0f;
	pos.rot.z = 0.0f;
	pos.trans.x = 0.0f;
	pos.trans.y = 0.0f;
	pos.trans.z = -16.0f;
	pos.scale.x = 4.0f;
	pos.scale.y = 1.0f;
	pos.scale.z = 4.0f;

	toffset.u = 0.0f;
	toffset.v = -0.044444f;
	moving = 1;
	maxlod = 8;
}

extern u_int32 D_0001BE08; /* static u_int32 opadd in pad_read (bss is asm) */

static int pad_read(void)
{
	u_int32 padd;
	SceCtrlData buf;

	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;

	if (padd != D_0001BE08) {
		if (padd & 0x8) {
			moving ^= 1;
		}

		if (padd & 0x10) {
			maxlod++;
			if (maxlod >= 8) {
				maxlod = 8;
			}
		}

		if (padd & 0x40) {
			maxlod--;
			if (maxlod < 2) {
				maxlod = 1;
			}
		}

		if (padd & 0x2000) {
			mode ^= 1;
		}
	}

	if (padd & 0x1) {
		return 0;
	}

	D_0001BE08 = padd;

	return 1;
}

void menuInit(void);
void menuTerm(int cat, int num);

int main(void)
{
	menuInit();
	init_param();
	init_all();

	while (pad_read()) {
		if (moving) {
			frame_update();
		}

		draw_frame();

		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
	}

	sceGuTerm();

	menuTerm(1, 15);

	return 0;
}
