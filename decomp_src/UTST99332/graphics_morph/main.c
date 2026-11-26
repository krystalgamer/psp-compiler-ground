/* cflags: -O2 -fmerge-constants */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon2;
struct _anon3;
struct _anon3 { /* size 0x10 */
    unsigned int col;
    float vertex[3];
};
typedef struct _anon3 PRIM;
struct _anon2 { /* size 0x20 */
    PRIM prim0;
    PRIM prim1;
};
typedef struct _anon2 MODEL;
struct _anon1 { /* size 0x10 */
    int type;
    int ctrl[2];
    const MODEL *model;
};
typedef struct _anon1 MODELLIST;
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
extern const MODEL r_front_hair[20];
extern const MODEL l_front_hair[20];
extern const MODEL r_body[36];
extern const MODEL l_body[36];
extern const MODEL face[36];
extern const MODEL head[30];
extern const MODEL horn1[24];
extern const MODEL horn2[20];
extern const MODEL r_ear[16];
extern const MODEL l_ear[16];
extern const MODEL r_hand[16];
extern const MODEL l_hand[16];
extern const MODEL r_back_hair1[20];
extern const MODEL r_back_hair2[20];
extern const MODEL l_back_hair1[20];
extern const MODEL l_back_hair2[20];
extern const MODEL r_leg_out1[20];
extern const MODEL r_leg_out2[16];
extern const MODEL r_leg_in1[20];
extern const MODEL r_leg_in2[16];
extern const MODEL r_foot_out[20];
extern const MODEL r_foot_in[20];
extern const MODEL l_leg_in1[20];
extern const MODEL l_leg_in2[16];
extern const MODEL l_leg_out1[20];
extern const MODEL l_leg_out2[16];
extern const MODEL l_foot_in[20];
extern const MODEL l_foot_out[20];
extern const MODEL r_wing1[16];
extern const MODEL r_wing2[16];
extern const MODEL r_wing_skin[16];
extern const MODEL l_wing1[16];
extern const MODEL l_wing2[16];
extern const MODEL l_wing_skin[16];
extern MODELLIST model_list[34];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;
extern int morph;
extern float weight;
extern float dir;
extern int cont;

static void draw_morph(void);
static void init_all(void);
static int pad_read(void);
int main(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void sceGuClear(int flags);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
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
void sceGuFog(float near, float far, unsigned int color);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuMorphWeight(int index, float weight);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_front_hair);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_front_hair);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_body);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_body);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", face);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", head);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", horn1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", horn2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_ear);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_ear);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_hand);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_hand);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_back_hair1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_back_hair2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_back_hair1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_back_hair2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_leg_out1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_leg_out2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_leg_in1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_leg_in2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_foot_out);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_foot_in);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_leg_in1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_leg_in2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_leg_out1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_leg_out2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_foot_in);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_foot_out);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_wing1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_wing2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_wing_skin);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_wing1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_wing2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_wing_skin);

float step_morph(float d) {
    float temp_f0;
    float var_f12;

    var_f12 = d;
    temp_f0 = weight + var_f12;
    weight = temp_f0;
    if (var_f12 > 0.0f) {
        if (temp_f0 > 1.0f) {
            var_f12 = -0.05f;
            weight = 1.0f;
        }
    } else if (temp_f0 < 0.0f) {
        weight = 0.0f;
        var_f12 = 0.05f;
    }
    return var_f12;
}

#ifndef MAX_MODELLIST /* sample */
#define MAX_MODELLIST	34
#endif
#ifndef TYPE_BEZIER /* sample */
#define TYPE_BEZIER (0)
#endif
#ifndef SCEGU_COLOR_PF8888 /* sample */
#define SCEGU_COLOR_PF8888       ( 7 <<  2 )
#endif
#ifndef SCEGU_VERTEX_FLOAT /* sample */
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#endif
#ifndef SCEGU_VERTEX_2 /* sample */
#define SCEGU_VERTEX_2           ( 1 << 18 )
#endif
#ifndef SCEGU_OPEN_OPEN /* sample */
#define SCEGU_OPEN_OPEN                    3
#endif
static void draw_morph(void)
{
	MODELLIST	*p;
	int			i;

	sceGuMorphWeight(0, weight);
	sceGuMorphWeight(1, 1.0f-weight);
	for (i=0; i<MAX_MODELLIST; i++) {
		p=&model_list[i];
		if (p->type==TYPE_BEZIER) {
			sceGumDrawBezier(SCEGU_COLOR_PF8888|SCEGU_VERTEX_FLOAT|SCEGU_VERTEX_2,
					p->ctrl[0], p->ctrl[1], 0, (void *)p->model);
		}
		else {
			sceGumDrawSpline(SCEGU_COLOR_PF8888|SCEGU_VERTEX_FLOAT|SCEGU_VERTEX_2,
					p->ctrl[0], p->ctrl[1], SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, 0,
					(void *)p->model);
		}
	}
}

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
    draw_morph();
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
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
#ifndef STEP /* sample */
#define STEP		0.05f
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
	sceGuDisable(SCEGU_ALPHA_TEST);

	sceGuDepthFunc(SCEGU_GEQUAL);
	sceGuEnable(SCEGU_DEPTH_TEST);

	sceGuFrontFace(SCEGU_CW);

	sceGuDisable(SCEGU_TEXTURE);

	sceGuSetDither(&dith);
	sceGuEnable(SCEGU_DITHER);
	sceGuEnable(SCEGU_CLIP_PLANE);
	sceGuShadeModel(SCEGU_SMOOTH);

	vec.x=-1.0f;
	vec.y= 1.0f;
	vec.z=-1.0f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xffc0c0c0);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuEnable(SCEGU_LIGHT0);
	sceGuEnable(SCEGU_LIGHTING);

	sceGuFog(24.0f, 60.0f, 0xff000000);
	sceGuDisable(SCEGU_FOG);

	sceGuAmbient(0xff59597f);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
					1.000000f, 100.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0xffc04040);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuColor(0xffe0e0e0);
	sceGuMorphWeight(0, 0.0f);
	sceGuMorphWeight(1, 1.0f);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	pos.x=  0.0f;
	pos.y=-12.0f;
	pos.z=-44.0f;
	rot.x= 16.0f;
	rot.y=310.0f;
	rot.z=  0.0f;

	morph=0;
	weight=0.0f;
	dir=STEP;

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

#define SCE_CTRL_UP					(1<<4)
#define SCE_CTRL_DOWN				(1<<6)
#define SCE_CTRL_LEFT				(1<<7)
#define SCE_CTRL_RIGHT				(1<<5)
#define DROT		2.5f
#define SCE_CTRL_L					(1<<8)
#define SCE_CTRL_L1					SCE_CTRL_L
#define SCE_CTRL_R					(1<<9)
#define SCE_CTRL_R1					SCE_CTRL_R
#define DPOS		2.0f
#define SCE_CTRL_CIRCLE				(1<<13)
#define SCE_CTRL_TRIANGLE			(1<<12)
#define SCE_CTRL_SQUARE				(1<<15)
#define SCE_CTRL_START				(1<<3)
#define STEP		0.05f
#define SCE_CTRL_SELECT				(1<<0)

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
		if (rot.x<0.0f)
			rot.x=360.0f+rot.x;
	}
	if (cont & SCE_CTRL_DOWN) {
		rot.x+=DROT;
		if (rot.x>=360.0f)
			rot.x=rot.x-360.0f;
	}
	if (cont & SCE_CTRL_LEFT) {
		rot.y-=DROT;
		if (rot.y<0.0f)
			rot.y=360.0f+rot.y;
	}
	if (cont & SCE_CTRL_RIGHT) {
		rot.y+=DROT;
		if (rot.y>=360.0f)
			rot.y=rot.y-360.0f;
	}

	if (cont & SCE_CTRL_L1)
		pos.z-=DPOS;
	if (cont & SCE_CTRL_R1)
		pos.z+=DPOS;

	if (padd & SCE_CTRL_CIRCLE)
		morph^=1;

	if (!morph) {
		if (cont & SCE_CTRL_TRIANGLE)
			step_morph(-STEP);
		if (cont & SCE_CTRL_SQUARE)
			step_morph(STEP);
	}

	if (padd & SCE_CTRL_START) {
		pos.x=  0.0f;
		pos.y=-12.0f;
		pos.z=-44.0f;
		rot.x= 16.0f;
		rot.y=310.0f;
		rot.z=  0.0f;

		morph=0;
		weight=0.0f;
		dir=STEP;
		sceGuMorphWeight(0, 0.0f);
		sceGuMorphWeight(1, 1.0f);
	}

	if (padd & SCE_CTRL_SELECT)
		return 0;

	return 1;
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

		if (morph) {
			dir = step_morph(dir);
		}
	}

	sceGuTerm();

	menuTerm(1, 19);

	return 0;
}
