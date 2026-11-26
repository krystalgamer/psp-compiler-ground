/* cflags: -O2 -fno-merge-constants */
#include "common.h"

/* declarations recovered from DWARF */
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

extern float parts[245];
extern ScePspFVector3 bone0[399];
extern ScePspFVector3 bone1[397];
extern ScePspFVector3 bone2[399];
extern ScePspFVector3 bone3[399];
extern ScePspFVector3 *bone_tbl[4];
extern short unsigned int mesh_pixel[256];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[80];
extern int frame;
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;
extern ScePspFMatrix4 bone_m[4];
extern int cont;

static void boneCalc(void);
static void init_all(void);
extern const ScePspIMatrix4 dith_init;
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
void sceGuClear(int flags);
void sceGuBoneMatrix(unsigned int index, const ScePspFMatrix4 *matrix);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
int sceDisplayWaitVblankStart(void);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
void sceGuAmbient(unsigned int color);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexScale(float u, float v);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumStoreMatrix(ScePspFMatrix4 *m);

static void boneCalc(void)
{
	ScePspFVector3	*tbl;
	ScePspFVector3	vec;
	int				i;

	sceGumPushMatrix();
	sceGumLoadIdentity();

	vec.x=-10.0, vec.y=0.0f, vec.z=0.0f;
	sceGumTranslate(&vec);

	for (i=0; i<4; i++) {
		tbl=bone_tbl[i];
		tbl=tbl+frame;

		sceGumRotateX(tbl->x);
		sceGumRotateY(tbl->y);
		sceGumRotateZ(tbl->z);
		sceGumStoreMatrix(&bone_m[i]);

		vec.x=5.0, vec.y=0.0f, vec.z=0.0f;
		sceGumTranslate(&vec);
	}

	sceGumPopMatrix();

	frame++;
	if (frame>=400) {
		frame=0;
	}
}

#define SCEGU_IMMEDIATE                    0
#define SCEGU_CLEAR_ALL               0x0007
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define SCEGU_WEIGHT_4           ( 3 << 14 )
#define SCEGU_WEIGHT_FLOAT       ( 3 <<  9 )
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#define SCEGU_CLOSE_CLOSE                  0
#define SCEGU_OPEN_OPEN                    3
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0

static void draw_frame(void)
{
	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuClear(SCEGU_CLEAR_ALL);

	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos);
	sceGumRotateX(SCEGU_RAD(rot.x));
	sceGumRotateY(SCEGU_RAD(rot.y));
	sceGumRotateZ(SCEGU_RAD(rot.z));

	boneCalc();
	sceGuBoneMatrix(0, &bone_m[0]);
	sceGuBoneMatrix(1, &bone_m[1]);
	sceGuBoneMatrix(2, &bone_m[2]);
	sceGuBoneMatrix(3, &bone_m[3]);

	sceGumDrawSpline(SCEGU_WEIGHT_4|SCEGU_WEIGHT_FLOAT|SCEGU_VERTEX_FLOAT,
				7, 5, SCEGU_CLOSE_CLOSE, SCEGU_OPEN_OPEN, 0, parts);

	sceGumPopMatrix();

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
}

#ifndef SCEGU_IMMEDIATE /* sample */
#define SCEGU_IMMEDIATE                    0
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
#ifndef SCEGU_SCISSOR_TEST /* sample */
#define SCEGU_SCISSOR_TEST                 2
#endif
#ifndef SCEGU_BLEND /* sample */
#define SCEGU_BLEND                        4
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
#ifndef SCEGU_PF5551 /* sample */
#define SCEGU_PF5551                       1
#endif
#ifndef SCEGU_SINGLE_CLUT /* sample */
#define SCEGU_SINGLE_CLUT                  0
#endif
#ifndef SCEGU_TEXBUF_NORMAL /* sample */
#define SCEGU_TEXBUF_NORMAL                0
#endif
#ifndef SCEGU_TEX_MODULATE /* sample */
#define SCEGU_TEX_MODULATE                 0
#endif
#ifndef SCEGU_RGBA /* sample */
#define SCEGU_RGBA                         1
#endif
#ifndef SCEGU_REPEAT /* sample */
#define SCEGU_REPEAT                       0
#endif
#ifndef SCEGU_LINEAR_MIPMAP_LINEAR /* sample */
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#endif
#ifndef SCEGU_NEAREST /* sample */
#define SCEGU_NEAREST                      0
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
	ScePspIMatrix4	dith = dith_init;
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

	sceGuDisable(SCEGU_BLEND);
	sceGuDisable(SCEGU_ALPHA_TEST);

	sceGuDepthFunc(SCEGU_GEQUAL);
	sceGuEnable(SCEGU_DEPTH_TEST);

	sceGuFrontFace(SCEGU_CW);

	sceGuTexMode(SCEGU_PF5551, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGBA);
	sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
	sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_NEAREST);
	sceGuTexImage(0, 16, 16, 16, mesh_pixel);
	sceGuTexScale(1.0f, 4.0f);
	sceGuEnable(SCEGU_TEXTURE);

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

	sceGuColor(0xffffffff);
	sceGuAmbient(0xffdddddd);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 64, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
					1.000000f, 1000.00000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0xffffc0c0);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	pos.x=0.0f;
	pos.y=0.0f;
	pos.z=-45.0f;
	rot.x=rot.y=rot.z=0.0f;

	frame=0;

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

#ifndef SCE_CTRL_UP /* sample */
#define SCE_CTRL_UP					(1<<4)
#endif
#ifndef SCE_CTRL_DOWN /* sample */
#define SCE_CTRL_DOWN				(1<<6)
#endif
#ifndef SCE_CTRL_LEFT /* sample */
#define SCE_CTRL_LEFT				(1<<7)
#endif
#ifndef SCE_CTRL_RIGHT /* sample */
#define SCE_CTRL_RIGHT				(1<<5)
#endif
#ifndef DROT /* sample */
#define DROT		1.0f
#endif
#ifndef SCE_CTRL_CIRCLE /* sample */
#define SCE_CTRL_CIRCLE				(1<<13)
#endif
#ifndef SCE_CTRL_SQUARE /* sample */
#define SCE_CTRL_SQUARE				(1<<15)
#endif
#ifndef SCE_CTRL_CROSS /* sample */
#define SCE_CTRL_CROSS				(1<<14)
#endif
#ifndef SCE_CTRL_TRIANGLE /* sample */
#define SCE_CTRL_TRIANGLE			(1<<12)
#endif
#ifndef SCE_CTRL_L /* sample */
#define SCE_CTRL_L					(1<<8)
#endif
#ifndef SCE_CTRL_L1 /* sample */
#define SCE_CTRL_L1					SCE_CTRL_L
#endif
#ifndef SCE_CTRL_R /* sample */
#define SCE_CTRL_R					(1<<9)
#endif
#ifndef SCE_CTRL_R1 /* sample */
#define SCE_CTRL_R1					SCE_CTRL_R
#endif
#ifndef DPOS /* sample */
#define DPOS		1.0f
#endif
#ifndef SCE_CTRL_START /* sample */
#define SCE_CTRL_START				(1<<3)
#endif
#ifndef SCE_CTRL_SELECT /* sample */
#define SCE_CTRL_SELECT				(1<<0)
#endif
static int pad_read(void)
{
	unsigned int	prev=cont;
	unsigned int	padd;
	SceCtrlData		buf;

	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd=cont&(cont^prev);

	if (cont & SCE_CTRL_UP) {
		rot.x-=DROT;
		if (rot.x<0.0f)	rot.x=360.0f+rot.x;
	}
	if (cont & SCE_CTRL_DOWN) {
		rot.x+=DROT;
		if (rot.x>=360.0f)	rot.x=rot.x-360.0f;
	}
	if (cont & SCE_CTRL_LEFT) {
		rot.y-=DROT;
		if (rot.y<0.0f)	rot.y=360.0f+rot.y;
	}
	if (cont & SCE_CTRL_RIGHT) {
		rot.y+=DROT;
		if (rot.y>=360.0f)	rot.y=rot.y-360.0f;
	}

	if (cont & SCE_CTRL_CIRCLE)
		pos.x+=DPOS;
	if (cont & SCE_CTRL_SQUARE)
		pos.x-=DPOS;

	if (cont & SCE_CTRL_CROSS)
		pos.y-=DPOS;
	if (cont & SCE_CTRL_TRIANGLE)
		pos.y+=DPOS;

	if (cont & SCE_CTRL_L1)
		pos.z-=DPOS;
	if (cont & SCE_CTRL_R1)
		pos.z+=DPOS;

	if (padd & (SCE_CTRL_START|SCE_CTRL_SELECT))
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
    menuTerm(1, 0x19);
    return 0;
}

const ScePspIMatrix4 dith_init __attribute__((aligned(16))) = {	{-4,  0, -3,  1},
							{ 2, -2,  3, -1},
							{-3,  1, -4,  0},
							{ 3, -1,  2, -2}};
