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
typedef unsigned char u_char8;
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
typedef struct ScePspIMatrix4 ScePspIMatrix4;
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
struct _anon1;
struct _anon1 { /* size 0x18 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
};
typedef struct _anon1 POS;
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

extern const float pole[96];
extern const float sphere[96];
extern const float cylinder[392];
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
extern POS effector[4];
extern int select;
extern int mode;
extern const char char_mode[2][8];
extern u_int32 cont;
extern int analog;

static void init_effector(void);
static void calc_bone(void);
static void draw_cylinder(void);
static void draw_effector(int c);
static void draw_frame(void);
static void init_all(void);
static int pad_read(void);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuBoneMatrix(unsigned int index, const ScePspFMatrix4 *matrix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
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
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuPatchPrim(int prim);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumStoreMatrix(ScePspFMatrix4 *m);
void sceGumTranslate(const ScePspFVector3 *v);
int sceKernelDcacheWritebackAll(void);

static void init_effector(void)
{
	int i;

	for (i = 0; i < 4; i++) {
		effector[i].pos.x = effector[i].pos.y = effector[i].pos.z = 0.0f;
		effector[i].rot.x = effector[i].rot.y = effector[i].rot.z = 0.0f;
	}
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", pole);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", sphere);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", cylinder);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", char_mode);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", D_00012750);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", D_00012770);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", calc_bone);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", draw_cylinder);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", draw_effector);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", init_all);

#define MAXEFF		4
#define SCE_CTRL_UP					(1<<4)
#define SCE_CTRL_DOWN				(1<<6)
#define SCE_CTRL_LEFT				(1<<7)
#define SCE_CTRL_RIGHT				(1<<5)
#define DROT		1.0f
#define SCE_CTRL_CIRCLE				(1<<13)
#define SCE_CTRL_SQUARE				(1<<15)
#define SCE_CTRL_CROSS				(1<<14)
#define SCE_CTRL_TRIANGLE			(1<<12)
#define SCE_CTRL_L					(1<<8)
#define SCE_CTRL_L1					SCE_CTRL_L
#define SCE_CTRL_R					(1<<9)
#define SCE_CTRL_R1					SCE_CTRL_R
#define DPOS		1.0f
#define SCE_CTRL_START				(1<<3)
#define MAXMODE		2
#define SCE_CTRL_SELECT				(1<<0)

static int pad_read(void)
{
	SceCtrlData	buf;
	u_int32		prev=cont;
	u_int32		padd;
	int			prevanalog=analog;
	POS			*p;

	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd=cont&(cont^prev);

	if (!mode) {
		
		p=&effector[select];

		if (buf.Lx<0x40)
			analog=-1;
		else if (buf.Lx>0xc0)
			analog= 1;
		else
			analog= 0;

		if (!analog) {
			if (prevanalog==-1)
				select=select+1>=MAXEFF?1:select+1;
			else if (prevanalog==1)
				select=select-1<1?MAXEFF-1:select-1;
		}
	}
	else {
		
		p=&world;

		if ((cont & SCE_CTRL_L1) && (cont & SCE_CTRL_R1))
			init_effector();
	}

	
	if (cont & SCE_CTRL_UP) {
		p->rot.z-=DROT;
		if (p->rot.z<0.0f)
			p->rot.z=360.0f+p->rot.z;
	}
	if (cont & SCE_CTRL_DOWN) {
		p->rot.z+=DROT;
		if (p->rot.z>=360.0f)
			p->rot.z=p->rot.z-360.0f;
	}
	if (cont & SCE_CTRL_LEFT) {
		p->rot.y-=DROT;
		if (p->rot.y<0.0f)
			p->rot.y=360.0f+p->rot.y;
	}
	if (cont & SCE_CTRL_RIGHT) {
		p->rot.y+=DROT;
		if (p->rot.y>=360.0f)
			p->rot.y=p->rot.y-360.0f;
	}

	
	if (cont & SCE_CTRL_CIRCLE)
		p->pos.x+=DPOS;
	if (cont & SCE_CTRL_SQUARE)
		p->pos.x-=DPOS;

	if (cont & SCE_CTRL_CROSS)
		p->pos.y-=DPOS;
	if (cont & SCE_CTRL_TRIANGLE)
		p->pos.y+=DPOS;

	if (cont & SCE_CTRL_L1)
		p->pos.z-=DPOS;
	if (cont & SCE_CTRL_R1)
		p->pos.z+=DPOS;

	
	if (padd & SCE_CTRL_START)
		mode=(mode+1>=MAXMODE?0:mode+1);

	
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
    menuTerm(1, 7);
    return 0;
}
