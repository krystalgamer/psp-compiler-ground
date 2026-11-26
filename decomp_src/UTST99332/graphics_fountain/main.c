#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1 { /* size 0x184 */
    ScePspFVector3 array[28];
    ScePspFVector3 pos;
    ScePspFVector3 dpos;
    float rot;
    float scale;
    int t;
    int a;
    int d;
    int c;
    int w;
};
typedef struct _anon1 GRAIN_DAT;
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
struct _anon2;
struct _anon2 { /* size 0x1c */
    u_int32 col;
    ScePspFVector3 normal;
    ScePspFVector3 vertex;
};
typedef struct _anon2 MODEL;

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
extern GRAIN_DAT grain[500];
extern int num_of_grain;
extern int autoflag;
extern const float orifice[96];
extern const MODEL ground[18];
extern u_int32 cont;


/* SDK functions (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

static void set_divide(int pt);
static void init_grain(int i);
static void move_grain(void);
static void draw_grain(void);
static void init_all(void);
static int pad_read(void);
int main(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGuSpecular(float power);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);


/* SDK prototypes (tools/sdk_protos.h) */
float cosf(float x);
int rand(void);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
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
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuPatchPrim(int prim);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
float sinf(float x);

static void set_divide(int pt)
{
	int d;

	if (pt < 30) {
		d = 3;
	} else if (pt < 60) {
		d = 4;
	} else if (pt < 90) {
		d = 6;
	} else {
		d = 8;
	}

	sceGuPatchDivide(d, d);
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", orifice);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", ground);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", D_000122E0);

#define DY			(0.2f+0.001f*(rand()%100))
#define SCALE		0.12f

static void init_grain(int i)
{
	GRAIN_DAT	*p;
	float		r=(float)(rand()%360);

	p=&grain[i];
	p->pos.x=0.0f;
	p->pos.y=0.0f;
	p->pos.z=0.0f;
	p->dpos.x=cosf(r)*(0.01f*(rand()%10));
	p->dpos.y=DY;
	p->dpos.z=sinf(r)*(0.01f*(rand()%10));
	p->rot=(float)(rand()%360);
	p->scale=SCALE;
	p->t=0;
	p->a=0xd0;
	p->d=(rand()%3)+1;
	p->c=((0xc0+(rand()%0x40))<<16)|0x0000a060;
	p->w=rand()%100;
}

#define GRAV		0.0025f

static void move_grain(void)
{
	GRAIN_DAT	*p;
	int			i;

	for (i=0; i<num_of_grain; i++) {
		p=&grain[i];

		if (p->w) {
			p->w--;
			continue;
		}

		p->t++;
		p->pos.x+=p->dpos.x;
		p->pos.y =p->dpos.y*p->t-GRAV*p->t*p->t;
		p->pos.z+=p->dpos.z;
		p->rot+=0.5f;
		p->scale+=0.001f;
		p->a-=p->d;

		if (p->pos.y<=-0.001f || p->a<=0) {
			init_grain(i);
		}
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", draw_grain);

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
    sceGuSpecular(50.0f);
    sceGumDrawArray(5, 0x1FC, 0x12, NULL, ground);
    sceGuColor(0xFFE0E0E0U);
    sceGumDrawArray(4, 0x1E0, 0xA, NULL, orifice);
    sceGumDrawArray(4, 0x1E0, 0xA, NULL, &orifice[0xC]);
    sceGumDrawArray(4, 0x1E0, 0xA, NULL, &orifice[0x18]);
    sceGumDrawArray(4, 0x1E0, 0xA, NULL, &orifice[0x24]);
    sceGuSpecular(10.0f);
    draw_grain();
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

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
#define SCEGU_ADD                          0
#define SCEGU_SRC_ALPHA                    2
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#define SCEGU_BLEND                        4
#define SCEGU_GEQUAL                       7
#define SCEGU_DEPTH_TEST                   1
#define SCEGU_CW                           0
#define SCEGU_DITHER                       6
#define SCEGU_CLIP_PLANE                   8
#define SCEGU_SMOOTH                       1
#define SCEGU_DIFFUSE                      2
#define SCEGU_SPECULAR                     4
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#define SCEGU_LIGHT0                      11
#define SCEGU_LIGHTING                    10
#define SCEGU_MATRIX_PROJECTION            0
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272
#define SCEGU_SCR_ASPECT      ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#define SCEGU_MATRIX_WORLD                 2
#define SCEGU_PRIM_LINE_STRIP              2
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0
#define MAX_GRAIN	500
#define SCEGU_DISPLAY_ON		1

extern const ScePspIMatrix4 D_000122E0;
static void init_all(void)
{
	ScePspIMatrix4 dith = D_000122E0;
	ScePspFVector3	vec;
	int				i;

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

	sceGuBlendFunc(SCEGU_ADD, SCEGU_SRC_ALPHA, SCEGU_ONE_MINUS_SRC_ALPHA, 0, 0);
	sceGuEnable(SCEGU_BLEND);

	sceGuDepthFunc(SCEGU_GEQUAL);
	sceGuEnable(SCEGU_DEPTH_TEST);

	sceGuFrontFace(SCEGU_CW);

	sceGuSetDither(&dith);
	sceGuEnable(SCEGU_DITHER);
	sceGuEnable(SCEGU_CLIP_PLANE);
	sceGuShadeModel(SCEGU_SMOOTH);

	vec.x=-1.0f;
	vec.y= 1.0f;
	vec.z= 1.0f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xffc0c0c0);
	sceGuLightColor(0, SCEGU_SPECULAR, 0xffffffff);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR, &vec);
	sceGuEnable(SCEGU_LIGHT0);
	sceGuEnable(SCEGU_LIGHTING);

	sceGuAmbient(0xff4c4c4c);
	sceGuColor(0xffe0e0e0);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
					1.000000f, 100.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0xffffe0e0);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuPatchPrim(SCEGU_PRIM_LINE_STRIP);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	pos.x=  0.0f;
	pos.y= -4.0f;
	pos.z=-14.0f;
	rot.x=  0.0f;
	rot.y=  0.0f;
	rot.z=  0.0f;

	num_of_grain=MAX_GRAIN;

	for (i=0; i<num_of_grain; i++)
		init_grain(i);

	autoflag=1;

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

int pad_read(void) {
    SceCtrlData buf;
    int temp_s0;
    unsigned int temp_s0_2;

    temp_s0_2 = cont;
    sceCtrlReadBufferPositive(&buf, 1);
    temp_s0 = buf.Buttons & (buf.Buttons ^ temp_s0_2);
    cont = buf.Buttons;
    if (temp_s0 & 0x2000) {
        autoflag ^= 1;
    }
    return (temp_s0 & 9) == 0;
}

void menuInit(void);
void menuTerm(int cat, int num);

int main(void)
{
	menuInit();

	init_all();

	while (pad_read()) {
		draw_frame();
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();

		move_grain();
		if (autoflag) {
			rot.y += 2.0f;
		}
	}

	sceGuTerm();

	menuTerm(1, 11);

	return 0;
}
