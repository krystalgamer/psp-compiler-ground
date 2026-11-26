#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef unsigned int u_int32;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1 { /* size 0x10 */
    u_int32 c;
    ScePspFVector3 vtx;
};
typedef struct _anon1 MODEL;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct _anon2;
struct _anon2 { /* size 0x14 */
    int x;
    int y;
    u_int32 c;
    int comp;
    float high;
};
typedef struct _anon2 OBJECT;
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
struct _anon3;
struct _anon3 { /* size 0x18 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
};
typedef struct _anon3 POS;

/* SDK functions */
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
extern POS world;
extern MODEL model[961];
extern OBJECT obj[2];

static void set_object(float *analog);
static void init_param(void);
static void init_all(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
int sceDisplayWaitVblankStart(void);
int sceCtrlSetSamplingMode(int mode);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuAmbient(unsigned int color);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuScissor(int x, int y, int w, int h);
void sceGuShadeModel(int mode);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
int sceKernelDcacheWritebackAll(void);

#define MAXCONTROL	(MAX_U*MAX_V)
#define MAX_V		31
#define MAX_OBJ		2
#define MAX_U		31
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
#define SCEGU_SCISSOR_TEST                 2
#define SCEGU_GEQUAL                       7
#define SCEGU_DEPTH_TEST                   1
#define SCEGU_CLIP_PLANE                   8
#define SCEGU_CULL_PATCH                  16
#define SCEGU_SMOOTH                       1
#define SCEGU_NORMAL_REVERSE_PATCH        20
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE                      2
#define SCEGU_LIGHT0                      11
#define SCEGU_LIGHTING                    10
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

static void set_object(float *analog)
{
	MODEL		*p;
	int			i,j;
	int			n;
	float		h;
	u_int32		c;

	const	int	tbl_m[9]={
		-MAX_U-1,
		-MAX_U,
		-MAX_U+1,
		-1,
		 0,
		 1,
		 MAX_U-1,
		 MAX_U,
		 MAX_U+1,
	};

	const	int	tbl_c[12]={
		-MAX_U*2-1,
		-MAX_U*2,
		-MAX_U*2+1,
		-MAX_U-2,
		-MAX_U+2,
		-2,
		 2,
		 MAX_U-2,
		 MAX_U+2,
		 MAX_U*2+1,
		 MAX_U*2,
		 MAX_U*2-1,
	};

	for (i=0; i<MAXCONTROL; i++) {
		p=&model[i];
		p->vtx.x=((float)-(MAX_U/2)+(float)(i%MAX_U))*0.3f;
		p->vtx.y=((float) (MAX_V/2)-(float)(i/MAX_V))*0.3f;
		p->vtx.z=0.0f;

		p->c=0xffffffff;
	}

	for (i=0; i<MAX_OBJ; i++) {
		n=obj[i].y*MAX_U+obj[i].x;
		c=obj[i].c;
		h=obj[i].high*(!obj[i].comp?1.0f:0.5f);
		for (j=0; j<9; j++) {
			p=&model[n+tbl_m[j]];
			p->vtx.x+=analog[0];
			p->vtx.y+=analog[1];
			p->vtx.z=h;
			p->c=c;
		}
		for (j=0; j<12; j++) {
			p=&model[n+tbl_c[j]];
			p->c=c;
		}
	}
	sceKernelDcacheWritebackAll();
}

void draw_model(void) {
    sceGumPushMatrix();
    sceGuColor(-1U);
    sceGumDrawBezier(0x19C, 0x1F, 0x1F, NULL, model);
    sceGumPopMatrix();
}

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10, 0x14], gap at: 0x8. */
void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    sceGumPushMatrix();
    sceGumLoadIdentity();
    sceGumTranslate(&world.pos);
    sceGumRotateX((world.rot.x * 3.1415927f) / 180.0f);
    sceGumRotateY((world.rot.y * 3.1415927f) / 180.0f);
    sceGumRotateZ((world.rot.z * 3.1415927f) / 180.0f);
    draw_model();
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

static void init_param(void)
{
	world.pos.x = world.pos.y = 0.0f;
	world.rot.y = world.rot.z = 0.0f;

	world.pos.z = -10.0f;
	world.rot.x = 300.0f;

	obj[0].x = 21;
	obj[0].y = 18;
	obj[0].c = 0xff0000ff;
	obj[0].comp = 0;
	obj[0].high = 2.0f;

	obj[1].x = 9;
	obj[1].y = 18;
	obj[1].c = 0xffff0000;
	obj[1].comp = 0;
	obj[1].high = 2.0f;
}

static void init_all(void)
{
	ScePspFVector3	vec;

	sceGuInit();

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(SCEGU_PF5551, SCEGU_VRAM_BP_0, SCEGU_VRAM_WIDTH);
	sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT,
					SCEGU_VRAM_BP_1, SCEGU_VRAM_WIDTH);
	sceGuDepthBuffer(SCEGU_VRAM_BP_2, SCEGU_VRAM_WIDTH);

	sceGuOffset(SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY);
	sceGuViewport(2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDepthRange(50000, 10000);

	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuEnable(SCEGU_SCISSOR_TEST);

	sceGuDepthFunc(SCEGU_GEQUAL);
	sceGuEnable(SCEGU_DEPTH_TEST);

	sceGuEnable(SCEGU_CLIP_PLANE);
	sceGuEnable(SCEGU_CULL_PATCH);
	sceGuShadeModel(SCEGU_SMOOTH);

	sceGuEnable(SCEGU_NORMAL_REVERSE_PATCH);
	sceGuPatchDivide(16, 16);

	vec.x=0.614497f;
	vec.y=0.691714f;
	vec.z=0.379372f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuEnable(SCEGU_LIGHT0);
	sceGuEnable(SCEGU_LIGHTING);

	sceGuAmbient(0xffc0c0c0);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
					1.000000f, 100.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0x00202020);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	init_param();

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

#define cont D_00013800	/* pad_read's static */
extern u_int32 cont;

static int pad_read(void)
{
	u_int32 prev, padd;
	SceCtrlData buf;
	float axis[2];
	OBJECT *p;

	prev = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	axis[0] = (buf.Lx - 128) * 0.01f;
	axis[1] = (buf.Ly - 128) * -0.01f;
	padd = buf.Buttons & (buf.Buttons ^ prev);
	cont = buf.Buttons;
	p = obj;
	if (cont & 0x1000) {
		p->y -= 3;
		if (p->y < 3)
			p->y = 3;
	}
	if (cont & 0x4000) {
		p->y += 3;
		if (p->y >= 28)
			p->y -= 3;
	}
	if (cont & 0x8000) {
		p->x -= 3;
		if (p->x < 3)
			p->x = 3;
	}
	if (cont & 0x2000) {
		p->x += 3;
		if (p->x >= 28)
			p->x -= 3;
	}
	p->comp = 0;
	if (cont & 0x0200)
		p->comp = 1;
	p = &obj[1];
	if (cont & 0x0010) {
		p->y -= 3;
		if (p->y < 3)
			p->y = 3;
	}
	if (cont & 0x0040) {
		p->y += 3;
		if (p->y >= 28)
			p->y -= 3;
	}
	if (cont & 0x0080) {
		p->x -= 3;
		if (p->x < 3)
			p->x = 3;
	}
	if (cont & 0x0020) {
		p->x += 3;
		if (p->x >= 28)
			p->x -= 3;
	}
	p->comp = 0;
	if (cont & 0x0100)
		p->comp = 1;
	set_object(axis);
	if (padd & 0x0008)
		init_param();
	if (padd & 0x0001)
		return 0;
	return 1;
}

int main(void) {
    menuInit();
    sceCtrlSetSamplingMode(1);
    init_all();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0x1D);
    return 0;
}
