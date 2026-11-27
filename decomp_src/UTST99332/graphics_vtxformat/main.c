#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x18 */
    float u;
    float v;
    unsigned int col;
    float vtx[3];
};
typedef struct _anon1 MODEL;
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

/* SDK functions */
void sceGuTerm(void);
void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStart(void);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

extern short unsigned int texture[65536];
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
extern int frame;
extern int colflag;
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;
extern float uvpos[2];
extern const float uv[7];
extern const unsigned int coltbl[8];
extern MODEL model[49];
extern int cont;

static void init_bezier(void);
void menuInit(void);
void menuTerm(int cat, int num);
static void draw_bezier(void);
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
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
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
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);

const float uv[7] = {
	0.000000000f,
	0.166666667f,
	0.333333333f,
	0.500000000f,
	0.666666667f,
	0.833333333f,
	1.000000000f,
};

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_vtxformat/nonmatchings/main", coltbl);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_vtxformat/nonmatchings/main", D_00011E5C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_vtxformat/nonmatchings/main", D_00011E80);

extern const struct zz7 { float v[7]; } D_00011E5C;
static void init_bezier(void)
{
	const struct zz7 zz = D_00011E5C;

	MODEL	*p;
	int		i;

	for (i=0; i<7*7; i++) {
		p=&model[i];
		p->u=uv[i%7];
		p->v=uv[i/7];
		p->col=0xffffffff;
		p->vtx[0]=-6.0f+(2.0f*(float)(i%7));
		p->vtx[1]= 6.0f-(2.0f*(float)(i/7));
		if ((i%7)==0 || (i%7)==6)
			p->vtx[2]=zz.v[i/7];
		else
			p->vtx[2]=zz.v[i%7];
	}
}

#define SCEGU_TEXTURE_FLOAT      ( 3 <<  0 )
#define SCEGU_COLOR_PF5551       ( 5 <<  2 )
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )

static void draw_bezier(void)
{
	float	newuv[7];
	int		i;

	
	newuv[0]=uv[0];
	newuv[6]=uv[6];
	newuv[3]=uv[3]+uvpos[0];
	newuv[1]=newuv[3]/3.0f;
	newuv[2]=newuv[3]/3.0f*2.0f;
	newuv[4]=newuv[3]+(newuv[6]-newuv[3])/3.0f;
	newuv[5]=newuv[3]+(newuv[6]-newuv[3])/3.0f*2.0f;
	for (i=0; i<7*7; i++) {
		model[i].u=newuv[i%7];
	}

	
	newuv[0]=uv[0];
	newuv[6]=uv[6];
	newuv[3]=uv[3]+uvpos[1];
	newuv[1]=newuv[3]/3.0f;
	newuv[2]=newuv[3]/3.0f*2.0f;
	newuv[4]=newuv[3]+(newuv[6]-newuv[3])/3.0f;
	newuv[5]=newuv[3]+(newuv[6]-newuv[3])/3.0f*2.0f;
	for (i=0; i<7*7; i++) {
		model[i].v=newuv[i/7];
	}

	
	for (i=0; i<7*7; i++) {
		if (colflag)
			model[i].col=coltbl[((frame/2)+i)%8];
		else
			model[i].col=0xffffffff;
	}

	sceKernelDcacheWritebackInvalidateRange((char *)model, sizeof(model));
	sceGumDrawBezier(SCEGU_TEXTURE_FLOAT|SCEGU_COLOR_PF5551|SCEGU_VERTEX_FLOAT,
						7, 7, 0, (void *)model);
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
    draw_bezier();
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

#define SCEGU_IMMEDIATE                    0
#define SCEGU_VRAM_BP_0       (void *)(SCEGU_VRAM_TOP)
#define SCEGU_VRAM_BP_1       (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE)
#define SCEGU_VRAM_TOP        0x00000000
#define SCEGU_VRAM_BUFSIZE    (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)
#define SCEGU_VRAM_BP_2       (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE*2))
#define SCEGU_VRAM_WIDTH      512
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)
#define SCEGU_ADD                          0
#define SCEGU_SRC_ALPHA                    2
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#define SCEGU_BLEND                        4
#define SCEGU_SCISSOR_TEST                 2
#define SCEGU_GREATER                      6
#define SCEGU_ALPHA_TEST                   0
#define SCEGU_GEQUAL                       7
#define SCEGU_DEPTH_TEST                   1
#define SCEGU_CW                           0
#define SCEGU_NORMAL_REVERSE_PATCH        20
#define SCEGU_PF5551                       1
#define SCEGU_SINGLE_CLUT                  0
#define SCEGU_TEXBUF_NORMAL                0
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#define SCEGU_NEAREST                      0
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGBA                         1
#define SCEGU_CLAMP                        1
#define SCEGU_TEXTURE                      9
#define SCEGU_DITHER                       6
#define SCEGU_CLIP_PLANE                   8
#define SCEGU_SMOOTH                       1
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE                      2
#define SCEGU_LIGHT0                      11
#define SCEGU_LIGHTING                    10
#define SCEGU_FOG                          7
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

extern const ScePspIMatrix4 D_00011E80;
static void init_all(void)
{
	ScePspIMatrix4	dith = D_00011E80;
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
	sceGuEnable(SCEGU_NORMAL_REVERSE_PATCH);

	sceGuTexMode(SCEGU_PF5551, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
	sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_NEAREST);
	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGBA);
	sceGuTexWrap(SCEGU_CLAMP, SCEGU_CLAMP);
	sceGuTexImage(0, 256, 256, 256, texture);
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
	sceGuAmbient(0xffdddddd);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
					1.000000f, 100.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0x00ff4040);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	pos.x=  0.0f;
	pos.y=  0.0f;
	pos.z=-18.0f;
	rot.x= 20.0f;
	rot.y=-10.0f;
	rot.z=  0.0f;

	uvpos[0]=0.0f;
	uvpos[1]=0.0f;

	init_bezier();

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

static int pad_read(void)
{
	int prev, padd;
	SceCtrlData buf;

	prev = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd = cont & (cont ^ prev);
	if (cont & 0x0010) {
		rot.x -= 1.0f;
		if (rot.x < 0.0f)
			rot.x += 360.0f;
	}
	if (cont & 0x0040) {
		rot.x += 1.0f;
		if (rot.x >= 360.0f)
			rot.x -= 360.0f;
	}
	if (cont & 0x0080) {
		rot.y -= 1.0f;
		if (rot.y < 0.0f)
			rot.y += 360.0f;
	}
	if (cont & 0x0020) {
		rot.y += 1.0f;
		if (rot.y >= 360.0f)
			rot.y -= 360.0f;
	}
	if (cont & 0x2000) {
		uvpos[0] -= 0.01f;
		if (uvpos[0] <= -0.25f)
			uvpos[0] = -0.25f;
	}
	if (cont & 0x8000) {
		uvpos[0] += 0.01f;
		if (uvpos[0] >= 0.25f)
			uvpos[0] = 0.25f;
	}
	if (cont & 0x4000) {
		uvpos[1] -= 0.01f;
		if (uvpos[1] <= -0.25f)
			uvpos[1] = -0.25f;
	}
	if (cont & 0x1000) {
		uvpos[1] += 0.01f;
		if (uvpos[1] >= 0.25f)
			uvpos[1] = 0.25f;
	}
	if (padd & 0x0008) {
		pos.x = 0.0f;
		pos.y = 0.0f;
		pos.z = -18.0f;
		rot.x = 20.0f;
		rot.y = -10.0f;
		rot.z = 0.0f;
		uvpos[0] = 0.0f;
		uvpos[1] = 0.0f;
		colflag = 0;
	}
	if (padd & 0x0100)
		colflag ^= 1;
	if (padd & 0x0001)
		return 0;
	return 1;
}

int main(void)
{
	menuInit();
	init_all();
	for (;;) {
		if (!pad_read())
			break;
		draw_frame();
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
		frame++;
	}
	sceGuTerm();
	menuTerm(1, 36);
	return 0;
}
