/* data-align: 16 */
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
struct _anon1 { /* size 0x1c */
    float speed;
    float theta;
    ScePspFVector3 v;
    float angle;
    unsigned int col;
};
typedef struct _anon1 ORIZURUDAT;
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
} __attribute__((aligned(16)));
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
struct _anon2;
struct _anon2 { /* size 0x8 */
    short unsigned int col;
    short int vec[3];
};
typedef struct _anon2 PRIM_BG;

extern unsigned char neck_index[12];
extern unsigned char body_index0[7];
extern unsigned char body_index1[6];
extern unsigned char body_index2[5];
extern unsigned char body_index3[5];
extern unsigned char body_index4[5];
extern unsigned char body_index5[30];
extern float neck[48];
extern float body[210];
extern float face[36];
extern float tail[36];
extern float rwing[30];
extern float lwing[30];
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
extern int moving;
extern ORIZURUDAT orizuru[128];
extern PRIM_BG background[4];
extern int cont;

static void tick(void);
static void add_orizuru(void);
static void remove_orizuru(void);
static void draw_orizuru(void);
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
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
float sinf(float x);
float cosf(float x);


/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10, 0x14], gap at: 0x8. */
/* SDK prototypes (tools/sdk_protos.h) */
int rand(void);
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
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumRotateY(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);

void tick_per_orizuru(int i) {
    ORIZURUDAT *temp_s0;
    float temp_f0;
    float temp_f20;

    temp_s0 = &orizuru[i];
    temp_f20 = temp_s0->theta + temp_s0->speed;
    temp_s0->theta = temp_f20;
    temp_s0->v.z = (cosf(temp_f20) * 6.0f) + -13.0f;
    temp_s0->v.x = sinf(2.0f * temp_f20) * 10.0f;
    temp_s0->v.y = sinf(temp_f20 / 3.4f) * 6.0f;
    temp_f0 = (((sinf(temp_f20) * 2.6779454f) - 1.5707964f) * 180.0f) / 3.1415927f;
    temp_s0->angle = temp_f0;
    if (temp_s0->speed < 0.0f) {
        temp_s0->angle = temp_f0 + 180.0f;
    }
}

static void tick(void)
{
	int i;

	for (i = 0; i < 128; i++) {
		if (orizuru[i].speed == 0.0f) {
			break;
		}

		tick_per_orizuru(i);
	}
}

#ifndef MAX_ORIZURU /* sample */
#define MAX_ORIZURU		128
#endif
static void add_orizuru(void)
{
	ORIZURUDAT	*p;
	int			i;

	for (i=0; i<MAX_ORIZURU; i++) {
		p=&orizuru[i];
		if (p->speed!=0)
			continue;

		switch (rand()%6) {
		case 0:	
			p->col=0xffffffff;
			break;
		case 1:	
			p->col=0xff8080ff;
			break;
		case 2:	
			p->col=0xff80ffff;
			break;
		case 3:	
			p->col=0xff80ff80;
			break;
		case 4:	
			p->col=0xffff80ff;
			break;
		case 5:	
			p->col=0xffff8080;
			break;
		}

		p->speed=((float)(rand()%20))*0.001f+0.02f;
		if (rand() & 0x1)
			p->speed *=-1.0f;
		p->theta=((float)(rand()%257))*0.1111f;

		tick_per_orizuru(i);
		break;
	}
}

static void remove_orizuru(void)
{
	int i;

	for (i = 127; i > 0; i--) {
		if (orizuru[i].speed != 0.0f) {
			orizuru[i].speed = 0.0f;
			return;
		}
	}
}

void model_orizuru(void) {
    sceGumDrawArray(4, 0x9E0, 0xC, neck_index, neck);
    sceGumDrawArray(4, 0x9E0, 7, body_index0, body);
    sceGumDrawArray(4, 0x9E0, 6, body_index1, body);
    sceGumDrawArray(4, 0x9E0, 5, body_index2, body);
    sceGumDrawArray(4, 0x9E0, 5, body_index3, body);
    sceGumDrawArray(4, 0x9E0, 5, body_index4, body);
    sceGumDrawArray(4, 0x9E0, 0x1E, body_index5, body);
    sceGumDrawArray(4, 0x1E0, 6, NULL, face);
    sceGumDrawArray(4, 0x1E0, 6, NULL, tail);
    sceGumDrawArray(4, 0x1E0, 5, NULL, rwing);
    sceGumDrawArray(4, 0x1E0, 5, NULL, lwing);
}

#define SCEGU_SMOOTH                       1
#define SCEGU_PRIM_TRIANGLE_STRIP          4
#define SCEGU_THROUGH            ( 1 << 23 )
#define SCEGU_COLOR_PF5551       ( 5 <<  2 )
#define SCEGU_VERTEX_SHORT       ( 2 <<  7 )
#define SCEGU_DEPTH_TEST                   1
#define SCEGU_FLAT                         0
#define MAX_ORIZURU		128
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)

static void draw_orizuru(void)
{
	ORIZURUDAT		*p;
	ScePspFVector3	vec;
	int				i;

	sceGuDisable(SCEGU_DEPTH_TEST);
	sceGuShadeModel(SCEGU_SMOOTH);
	sceGumDrawArray(SCEGU_PRIM_TRIANGLE_STRIP,
					SCEGU_THROUGH|SCEGU_COLOR_PF5551|SCEGU_VERTEX_SHORT,
					4, 0, background);

	sceGuEnable(SCEGU_DEPTH_TEST);
	sceGuShadeModel(SCEGU_FLAT);

	for (i=0; i<MAX_ORIZURU; i++) {
		p=&orizuru[i];
		if (p->speed==0.0f)
			break;

		sceGumPushMatrix();

		sceGumTranslate(&p->v);
		sceGumRotateY(SCEGU_RAD(p->angle));
		vec.x=(1.0f/4.0f), vec.y=(1.0f/4.0f), vec.z=(1.0f/4.0f);
		sceGumScale(&vec);
		sceGuColor(p->col);
		model_orizuru();

		sceGumPopMatrix();
	}
}

void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    sceGumPushMatrix();
    sceGumLoadIdentity();
    sceGumTranslate(&pos);
    draw_orizuru();
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
#ifndef SCEGU_SMOOTH /* sample */
#define SCEGU_SMOOTH                       1
#endif
#ifndef SCEGU_DITHER /* sample */
#define SCEGU_DITHER                       6
#endif
#ifndef SCEGU_CLIP_PLANE /* sample */
#define SCEGU_CLIP_PLANE                   8
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
	sceGuEnable(SCEGU_BLEND);

	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuEnable(SCEGU_SCISSOR_TEST);

	sceGuAlphaFunc(SCEGU_GREATER, 0x00, 0xff);
	sceGuEnable(SCEGU_ALPHA_TEST);

	sceGuDepthFunc(SCEGU_GEQUAL);
	sceGuEnable(SCEGU_DEPTH_TEST);

	sceGuFrontFace(SCEGU_CW);

	sceGuDisable(SCEGU_TEXTURE);
	sceGuShadeModel(SCEGU_SMOOTH);

	sceGuSetDither(&dith);
	sceGuEnable(SCEGU_DITHER);
	sceGuEnable(SCEGU_CLIP_PLANE);

	vec.x= 0.614497f;
	vec.y=-0.691714f;
	vec.z= 0.379372f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuEnable(SCEGU_LIGHT0);
	sceGuEnable(SCEGU_LIGHTING);

	sceGuDisable(SCEGU_FOG);
	sceGuAmbient(0xffdddddd);

	sceGumSetMatrixStack(matrix_stack, 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
				1.000000f, 100.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0x00ffffff);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	pos.x=pos.y=pos.z=0.0f;
	pos.z=-10.0f;

	add_orizuru();

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

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
#ifndef SCE_CTRL_CIRCLE /* sample */
#define SCE_CTRL_CIRCLE				(1<<13)
#endif
#ifndef SCE_CTRL_CROSS /* sample */
#define SCE_CTRL_CROSS				(1<<14)
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

	sceCtrlReadBufferPositive( &buf, 1 );
	cont = buf.Buttons;
	padd=cont&(cont^prev);

	if (cont & SCE_CTRL_L1)
		pos.z-=0.01f;
	if (cont & SCE_CTRL_R1)
		pos.z+=0.01f;

	if (padd & SCE_CTRL_CIRCLE)
		add_orizuru();

	if (padd & SCE_CTRL_CROSS)
		remove_orizuru();

	if (padd & SCE_CTRL_START)
		moving^=1;

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

		if (moving) {
			tick();
		}
	}

	sceGuTerm();

	menuTerm(1, 20);

	return 0;
}


