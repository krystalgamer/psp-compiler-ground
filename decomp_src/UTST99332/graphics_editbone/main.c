/* cflags: -O2 -fmerge-constants */
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

#ifndef MAXEFF /* sample */
#define MAXEFF		4
#endif
#ifndef SCEGU_PI /* sample */
#define SCEGU_PI                           3.1415926535897932384626433832f
#endif
#ifndef SCEGU_RAD /* sample */
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#endif
static void calc_bone(void)
{
	ScePspFMatrix4	bonemat;
	int				i;

	sceGumPushMatrix();
	{
		sceGumLoadIdentity();
		for (i=0; i<MAXEFF; i++) {
			sceGumTranslate(&effector[i].pos);
			sceGumRotateX(SCEGU_RAD(effector[i].rot.x));
			sceGumRotateY(SCEGU_RAD(effector[i].rot.y));
			sceGumRotateZ(SCEGU_RAD(effector[i].rot.z));
			sceGumStoreMatrix(&bonemat);
			sceGuBoneMatrix(i, &bonemat);
		}
	}
	sceGumPopMatrix();
}

#define SCEGU_PRIM_LINE_STRIP              2
#define SCEGU_PRIM_TRIANGLE_STRIP          4
#define SCEGU_WEIGHT_4           ( 3 << 14 )
#define SCEGU_WEIGHT_FLOAT       ( 3 <<  9 )
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#define SCEGU_OPEN_OPEN                    3

static void draw_cylinder(void)
{
	if (!mode)
		sceGuPatchPrim(SCEGU_PRIM_LINE_STRIP);
	else
		sceGuPatchPrim(SCEGU_PRIM_TRIANGLE_STRIP);

	sceGuColor(0xffffff80);
	sceGumDrawSpline(SCEGU_WEIGHT_4|SCEGU_WEIGHT_FLOAT|SCEGU_VERTEX_FLOAT,
		4, 7, SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, 0, &cylinder[0]);
	sceGumDrawSpline(SCEGU_WEIGHT_4|SCEGU_WEIGHT_FLOAT|SCEGU_VERTEX_FLOAT,
		4, 7, SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, 0, &cylinder[28*7]);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", draw_effector);

#ifndef SCEGU_IMMEDIATE /* sample */
#define SCEGU_IMMEDIATE                    0
#endif
#ifndef SCEGU_CLEAR_ALL /* sample */
#define SCEGU_CLEAR_ALL               0x0007
#endif
#ifndef MAXEFF /* sample */
#define MAXEFF		4
#endif
#ifndef SCEGU_PI /* sample */
#define SCEGU_PI                           3.1415926535897932384626433832f
#endif
#ifndef SCEGU_RAD /* sample */
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#endif
#ifndef SCEGU_SYNC_FINISH /* sample */
#define SCEGU_SYNC_FINISH                  0
#endif
#ifndef SCEGU_SYNC_WAIT /* sample */
#define SCEGU_SYNC_WAIT                    0
#endif
static void draw_frame(void)
{
	ScePspFVector3	vec;
	int				c;
	int				i;

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuClear(SCEGU_CLEAR_ALL);

	sceGuDebugPrint(8, 8, 0x00ffffff, char_mode[mode]);

	calc_bone();

	sceGumPushMatrix();
	sceGumLoadIdentity();

	sceGumTranslate(&world.pos);
	sceGumRotateX(SCEGU_RAD(world.rot.x));
	sceGumRotateY(SCEGU_RAD(world.rot.y));
	sceGumRotateZ(SCEGU_RAD(world.rot.z));

	draw_cylinder();

	if (!mode) {
		for (i=0; i<MAXEFF; i++) {
			vec.x=effector[i].pos.x+(!i?6.0f:-3.0f);
			vec.y=effector[i].pos.y;
			vec.z=effector[i].pos.z;
			sceGumTranslate(&vec);
			sceGumRotateX(SCEGU_RAD(effector[i].rot.x));
			sceGumRotateY(SCEGU_RAD(effector[i].rot.y));
			sceGumRotateZ(SCEGU_RAD(effector[i].rot.z));
			if (i==select)	c=0xffff80ff;
			else if (!i)	c=0xffffff80;
			else			c=0xff80ffff;
			draw_effector(c);
		}
		sceKernelDcacheWritebackAll();
	}

	sceGumPopMatrix();

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
}

#ifndef SCEGU_IMMEDIATE /* sample */
#define SCEGU_IMMEDIATE                    0
#endif
#ifndef SCEGU_PF5551 /* sample */
#define SCEGU_PF5551                       1
#endif
#ifndef SCEGU_VRAM_BP_0 /* sample */
#define SCEGU_VRAM_BP_0       (void *)(SCEGU_VRAM_TOP)
#endif
#ifndef SCEGU_VRAM_BP_1 /* sample */
#define SCEGU_VRAM_BP_1       (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE)
#endif
#ifndef SCEGU_VRAM_TOP /* sample */
#define SCEGU_VRAM_TOP        0x00000000
#endif
#ifndef SCEGU_VRAM_BUFSIZE /* sample */
#define SCEGU_VRAM_BUFSIZE    (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)
#endif
#ifndef SCEGU_VRAM_BP_2 /* sample */
#define SCEGU_VRAM_BP_2       (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE*2))
#endif
#ifndef SCEGU_VRAM_WIDTH /* sample */
#define SCEGU_VRAM_WIDTH      512
#endif
#ifndef SCEGU_SCR_OFFSETX /* sample */
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#endif
#ifndef SCEGU_SCR_OFFSETY /* sample */
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)
#endif
#ifndef SCEGU_ADD /* sample */
#define SCEGU_ADD                          0
#endif
#ifndef SCEGU_SRC_ALPHA /* sample */
#define SCEGU_SRC_ALPHA                    2
#endif
#ifndef SCEGU_ONE_MINUS_SRC_ALPHA /* sample */
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#endif
#ifndef SCEGU_BLEND /* sample */
#define SCEGU_BLEND                        4
#endif
#ifndef SCEGU_SCISSOR_TEST /* sample */
#define SCEGU_SCISSOR_TEST                 2
#endif
#ifndef SCEGU_GREATER /* sample */
#define SCEGU_GREATER                      6
#endif
#ifndef SCEGU_ALPHA_TEST /* sample */
#define SCEGU_ALPHA_TEST                   0
#endif
#ifndef SCEGU_GEQUAL /* sample */
#define SCEGU_GEQUAL                       7
#endif
#ifndef SCEGU_DEPTH_TEST /* sample */
#define SCEGU_DEPTH_TEST                   1
#endif
#ifndef SCEGU_CW /* sample */
#define SCEGU_CW                           0
#endif
#ifndef SCEGU_NORMAL_REVERSE_PATCH /* sample */
#define SCEGU_NORMAL_REVERSE_PATCH        20
#endif
#ifndef SCEGU_TEXTURE /* sample */
#define SCEGU_TEXTURE                      9
#endif
#ifndef SCEGU_DITHER /* sample */
#define SCEGU_DITHER                       6
#endif
#ifndef SCEGU_CLIP_PLANE /* sample */
#define SCEGU_CLIP_PLANE                   8
#endif
#ifndef SCEGU_SMOOTH /* sample */
#define SCEGU_SMOOTH                       1
#endif
#ifndef SCEGU_LIGHT_DIRECTION /* sample */
#define SCEGU_LIGHT_DIRECTION              0
#endif
#ifndef SCEGU_DIFFUSE /* sample */
#define SCEGU_DIFFUSE                      2
#endif
#ifndef SCEGU_LIGHT0 /* sample */
#define SCEGU_LIGHT0                      11
#endif
#ifndef SCEGU_LIGHTING /* sample */
#define SCEGU_LIGHTING                    10
#endif
#ifndef SCEGU_FOG /* sample */
#define SCEGU_FOG                          7
#endif
#ifndef SCEGU_MATRIX_PROJECTION /* sample */
#define SCEGU_MATRIX_PROJECTION            0
#endif
#ifndef SCEGU_PI /* sample */
#define SCEGU_PI                           3.1415926535897932384626433832f
#endif
#ifndef SCEGU_RAD /* sample */
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#endif
#ifndef SCEGU_SCR_WIDTH /* sample */
#define SCEGU_SCR_WIDTH       480
#endif
#ifndef SCEGU_SCR_HEIGHT /* sample */
#define SCEGU_SCR_HEIGHT      272
#endif
#ifndef SCEGU_SCR_ASPECT /* sample */
#define SCEGU_SCR_ASPECT      ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#endif
#ifndef SCEGU_MATRIX_WORLD /* sample */
#define SCEGU_MATRIX_WORLD                 2
#endif
#ifndef SCEGU_SYNC_FINISH /* sample */
#define SCEGU_SYNC_FINISH                  0
#endif
#ifndef SCEGU_SYNC_WAIT /* sample */
#define SCEGU_SYNC_WAIT                    0
#endif
#ifndef SCEGU_DISPLAY_ON /* sample */
#define SCEGU_DISPLAY_ON		1
#endif
static void init_all(void)
{
	ScePspIMatrix4	dith={	{-4,  0, -3,  1},
							{ 2, -2,  3, -1},
							{-3,  1, -4,  0},
							{ 3, -1,  2, -2}};
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

	sceGuBlendFunc(SCEGU_ADD, SCEGU_SRC_ALPHA, SCEGU_ONE_MINUS_SRC_ALPHA, 0, 0);
	sceGuDisable(SCEGU_BLEND);

	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuEnable(SCEGU_SCISSOR_TEST);

	sceGuAlphaFunc(SCEGU_GREATER, 0x00, 0xff);
	sceGuEnable(SCEGU_ALPHA_TEST);

	sceGuDepthFunc(SCEGU_GEQUAL);
	sceGuEnable(SCEGU_DEPTH_TEST);

	sceGuFrontFace(SCEGU_CW);
	sceGuEnable(SCEGU_NORMAL_REVERSE_PATCH);

	sceGuDisable(SCEGU_TEXTURE);

	sceGuSetDither(&dith);
	sceGuEnable(SCEGU_DITHER);
	sceGuEnable(SCEGU_CLIP_PLANE);
	sceGuShadeModel(SCEGU_SMOOTH);

	vec.x=0.614497f;
	vec.y=0.691714f;
	vec.z=0.379372f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuEnable(SCEGU_LIGHT0);

	sceGuEnable(SCEGU_LIGHTING);

	sceGuDisable(SCEGU_FOG);

	sceGuAmbient(0xffdddddd);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
					1.000000f, 1000.00000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0x00800000);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuPatchDivide(8, 8);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	world.pos.x=0.0f;
	world.pos.y=0.0f;
	world.pos.z=-10.0f;
	world.rot.x=0.0f;
	world.rot.y=0.0f;
	world.rot.z=0.0f;

	init_effector();

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

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
