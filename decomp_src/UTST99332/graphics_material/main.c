/* cflags: -O2 -fmerge-constants */
#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
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
extern float array_cone[204];
extern ScePspFVector3 array_sphere[28];
extern int primflag;
extern int description;
extern const int mat_mod[6][3];
extern const short int line[18];
extern const char mat_names[3][12];
extern const char mod_names[3][8];
extern u_int32 cont;


/* SDK functions (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

static void draw_description(void);
static void draw_primitive(void);
static void draw_frame(void);
static void init_all(void);
static int pad_read(void);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
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
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuSpecular(float power);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumOrtho(float left, float right, float bottom, float top, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumTranslate(const ScePspFVector3 *v);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_material/nonmatchings/main", mat_mod);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_material/nonmatchings/main", line);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_material/nonmatchings/main", draw_description);

void DrawCone(float *array, float r, float h);
void DrawSphere(ScePspFVector3 *array, float r);

static void draw_primitive(void)
{
	if (primflag == 0) {
		DrawCone(array_cone, 1.0f, 2.0f);
	} else {
		DrawSphere(array_sphere, 1.0f);
	}
}

#define SCEGU_IMMEDIATE                    0
#define SCEGU_CLEAR_ALL               0x0007
#define SCEGU_PRIM_LINES                   1
#define SCEGU_THROUGH            ( 1 << 23 )
#define SCEGU_VERTEX_SHORT       ( 2 <<  7 )
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define ROT			-25.0f
#define SCEGU_DIFFUSE                      2
#define SCEGU_SPECULAR                     4
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0

static void draw_frame(void)
{
	u_int32			no_mat = 0xff000000;
	u_int32			mat_ambient = 0xffb3b3b3;
	u_int32			mat_ambient_color = 0xff33cccc;
	u_int32			mat_diffuse = 0xffcc8019;
	u_int32			mat_specular = 0xffffffff;
	ScePspFVector3	vec;

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuClear(SCEGU_CLEAR_ALL);

	sceGuColor(0xffffffff);
	sceGumDrawArray(SCEGU_PRIM_LINES,
					SCEGU_THROUGH|SCEGU_VERTEX_SHORT, 6, 0, (void *)line);

	if (description)
		draw_description();

	sceGuColor(0xffc0c0c0);





	sceGumPushMatrix();
	vec.x=-4.0f, vec.y= 1.45f, vec.z=0.0f;
	sceGumTranslate(&vec);
	sceGumRotateX(SCEGU_RAD(ROT));
	sceGuAmbient(no_mat);
	sceGuLightColor(0, SCEGU_DIFFUSE, mat_diffuse);
	sceGuLightColor(0, SCEGU_SPECULAR, no_mat);
	draw_primitive();
	sceGumPopMatrix();





	sceGumPushMatrix();
	vec.x=-4.0f, vec.y=-2.0f, vec.z=0.0f;
	sceGumTranslate(&vec);
	sceGumRotateX(SCEGU_RAD(ROT));
	sceGuAmbient(no_mat);
	sceGuLightColor(0, SCEGU_DIFFUSE, mat_diffuse);
	sceGuLightColor(0, SCEGU_SPECULAR, mat_specular);
	draw_primitive();
	sceGumPopMatrix();





	sceGumPushMatrix();
	vec.x= 0.0f, vec.y= 1.45f, vec.z=0.0f;
	sceGumTranslate(&vec);
	sceGumRotateX(SCEGU_RAD(ROT));
	sceGuAmbient(mat_ambient);
	sceGuLightColor(0, SCEGU_DIFFUSE, mat_diffuse);
	sceGuLightColor(0, SCEGU_SPECULAR, no_mat);
	draw_primitive();
	sceGumPopMatrix();





	sceGumPushMatrix();
	vec.x= 0.0f, vec.y=-2.0f, vec.z=0.0f;
	sceGumTranslate(&vec);
	sceGumRotateX(SCEGU_RAD(ROT));
	sceGuAmbient(mat_ambient);
	sceGuLightColor(0, SCEGU_DIFFUSE, mat_diffuse);
	sceGuLightColor(0, SCEGU_SPECULAR, mat_specular);
	draw_primitive();
	sceGumPopMatrix();





	sceGumPushMatrix();
	vec.x= 4.0f, vec.y= 1.45f, vec.z=0.0f;
	sceGumTranslate(&vec);
	sceGumRotateX(SCEGU_RAD(ROT));
	sceGuAmbient(mat_ambient_color);
	sceGuLightColor(0, SCEGU_DIFFUSE, mat_diffuse);
	sceGuLightColor(0, SCEGU_SPECULAR, no_mat);
	draw_primitive();
	sceGumPopMatrix();





	sceGumPushMatrix();
	vec.x= 4.0f, vec.y=-2.0f, vec.z=0.0f;
	sceGumTranslate(&vec);
	sceGumRotateX(SCEGU_RAD(ROT));
	sceGuAmbient(mat_ambient_color);
	sceGuLightColor(0, SCEGU_DIFFUSE, mat_diffuse);
	sceGuLightColor(0, SCEGU_SPECULAR, mat_specular);
	draw_primitive();
	sceGumPopMatrix();

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
}

#define SCEGU_PF5551                       1
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
#define SCEGU_TEXTURE                      9
#define SCEGU_DITHER                       6
#define SCEGU_CLIP_PLANE                   8
#define SCEGU_SMOOTH                       1
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#define SCEGU_LIGHT0                      11
#define SCEGU_LIGHTING                    10
#define SCEGU_FOG                          7
#define SCEGU_MATRIX_PROJECTION            0
#define SCEGU_SCR_HEIGHT      272
#define SCEGU_SCR_WIDTH       480
#define SCEGU_MATRIX_WORLD                 2
#define SCEGU_DISPLAY_ON		1

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

	sceGuSetDither(&dith);
	sceGuEnable(SCEGU_DITHER);
	sceGuEnable(SCEGU_CLIP_PLANE);
	sceGuShadeModel(SCEGU_SMOOTH);

	vec.x=0.0f;
	vec.y=1.0f;
	vec.z=1.0f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
	sceGuLightColor(0, SCEGU_SPECULAR, 0xffffffff);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR, &vec);
	sceGuEnable(SCEGU_LIGHT0);
	sceGuEnable(SCEGU_LIGHTING);

	sceGuSpecular(10.0f);
	sceGuDisable(SCEGU_FOG);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumOrtho(-6.0f, 6.0f,
		-3.0f*((float)SCEGU_SCR_HEIGHT*2)/(float)SCEGU_SCR_WIDTH,
		3.0f*((float)SCEGU_SCR_HEIGHT*2)/(float)SCEGU_SCR_WIDTH,
		-10.0f, 10.0f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0x00000000);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuPatchDivide(32, 32);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

int pad_read(void) {
    SceCtrlData buf;
    int temp_a0;
    unsigned int temp_s0;

    temp_s0 = cont;
    sceCtrlReadBufferPositive(&buf, 1);
    temp_a0 = buf.Buttons & (buf.Buttons ^ temp_s0);
    cont = buf.Buttons;
    if (temp_a0 & 0x2000) {
        primflag ^= 1;
    }
    if (cont & 0x1000) {
        description = 1;
    } else {
        description = 0;
    }
    return (temp_a0 & 9) == 0;
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
    menuTerm(1, 0xE);
    return 0;
}
