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
extern int mode;
extern int prim;
extern int current;
extern ScePspFVector3 control[16];
extern const int primflag[3];
extern const char char_prim[3][16];
extern const char char_mode[2][8];
extern const float bezier[48];
extern const float dot[12];
extern u_int32 cont;


/* SDK functions (tools/sdk_protos.h) */
void sceGuColor(unsigned int color);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuPatchPrim(int prim);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
int sceKernelDcacheWritebackAll(void);

static void draw_bezier(void);
static void draw_dot(void);
static void draw_frame(void);
static void init_all(void);
static int pad_read(void);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);

void draw_bezier(void) {
    sceGuPatchDivide(0x10U, 0x10U);
    sceGuPatchPrim(primflag[prim]);
    sceGumPushMatrix();
    sceGuColor(-0x7F01U);
    sceGumDrawBezier(0x180, 4, 4, NULL, control);
    sceKernelDcacheWritebackAll();
    sceGumPopMatrix();
}

static void draw_dot(void)
{
	int i;

	for (i = 0; i < 16; i++) {
		if (i == current) {
			sceGuColor(0xffffff80);
		} else {
			sceGuColor(0xff80ffff);
		}

		sceGumPushMatrix();

		sceGumTranslate(&control[i]);
		sceGumDrawArray(4, 0x180, 4, 0, dot);

		sceGumPopMatrix();
	}
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", primflag);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", draw_frame);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", bezier);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", dot);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", D_00011E20);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", D_00011E60);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", D_00011E64);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", init_all);

#define DTRANS		0.01f;
#define SCE_CTRL_CIRCLE				(1<<13)
#define SCE_CTRL_CROSS				(1<<14)
#define SCE_CTRL_UP					(1<<4)
#define SCE_CTRL_DOWN				(1<<6)
#define SCE_CTRL_LEFT				(1<<7)
#define SCE_CTRL_RIGHT				(1<<5)
#define SCE_CTRL_L					(1<<8)
#define SCE_CTRL_L1					SCE_CTRL_L
#define SCE_CTRL_R					(1<<9)
#define SCE_CTRL_R1					SCE_CTRL_R
#define VTRANS		1.0f;
#define SCE_CTRL_TRIANGLE			(1<<12)
#define MAXMODE		2
#define SCE_CTRL_SQUARE				(1<<15)
#define MAXPRIM		3
#define SCE_CTRL_START				(1<<3)
#define MAXCONTROL	16
#define SCE_CTRL_SELECT				(1<<0)

static int pad_read(void)
{
	u_int32		prev=cont;
	u_int32		padd;
	SceCtrlData	buf;

	int			i;

	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd=cont&(cont^prev);

	if (!mode) {
		ScePspFVector3	*cur_pt=&control[current];

		if (cont & SCE_CTRL_UP) {
			cur_pt->y+=DTRANS;
		}
		if (cont & SCE_CTRL_DOWN) {
			cur_pt->y-=DTRANS;
		}
		if (cont & SCE_CTRL_LEFT) {
			cur_pt->x-=DTRANS;
		}
		if (cont & SCE_CTRL_RIGHT) {
			cur_pt->x+=DTRANS;
		}
		if (cont & SCE_CTRL_L1) {
			cur_pt->z+=DTRANS;
		}
		if (cont & SCE_CTRL_R1) {
			cur_pt->z-=DTRANS;
		}

		if (padd & SCE_CTRL_CIRCLE)
			current=(current+1>=MAXCONTROL?0:current+1);
		if (padd & SCE_CTRL_CROSS)
			current=(current-1<0?MAXCONTROL-1:current-1);
	}
	else {
		if (cont & SCE_CTRL_UP) {
			rot.x+=VTRANS;
			if (rot.x>=360.0f)
				rot.x=0.0f;
		}
		if (cont & SCE_CTRL_DOWN) {
			rot.x-=VTRANS;
			if (rot.x<0.0f)
				rot.x+=360.0f;
		}
		if (cont & SCE_CTRL_LEFT) {
			rot.y+=VTRANS;
			if (rot.y>=360.0f)
				rot.y=0.0f;
		}
		if (cont & SCE_CTRL_RIGHT) {
			rot.y-=VTRANS;
			if (rot.y<0.0f)
				rot.y+=360.0f;
		}
		if (cont & SCE_CTRL_L1) {
			pos.z+=VTRANS;
		}
		if (cont & SCE_CTRL_R1) {
			pos.z-=VTRANS;
		}
	}

	if (padd & SCE_CTRL_TRIANGLE)
		mode=(mode+1>=MAXMODE?0:mode+1);
	if (padd & SCE_CTRL_SQUARE)
		prim=(prim+1>=MAXPRIM?0:prim+1);

	if (padd & SCE_CTRL_START) {
		for (i=0; i<MAXCONTROL; i++) {
			control[i].x=bezier[i*3+0];
			control[i].y=bezier[i*3+1];
			control[i].z=bezier[i*3+2];
		}
	}
	if (padd & SCE_CTRL_SELECT)
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
    menuTerm(1, 8);
    return 0;
}
