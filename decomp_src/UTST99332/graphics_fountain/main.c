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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", init_all);

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
