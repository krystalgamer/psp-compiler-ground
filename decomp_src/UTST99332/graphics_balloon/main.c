#include "common.h"

/* declarations recovered from DWARF */
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

extern int texture_mode;
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
extern int frame;
extern int change;
extern int indicator;
extern int prev_state;
extern int prev_texture;
extern int texture_next;
extern const char char_mode[16][16];
extern u_int32 cont;


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

static void draw_mode(void);
static void draw_frame(void);
static void init_all(void);
static int pad_read(void);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_balloon/nonmatchings/main", char_mode);

void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
#define SCEGU_SCR_HEIGHT      272

static void draw_mode(void)
{
	char	buf[8]=">>>>";
	int		size,i;
	if (change) {
		if (!check_clouds()) {
			for(size=0,i=0;i<12;size++,i++) {
				if(!char_mode[prev_texture][i])
					break;
			}
			size*=8;
			buf[3-indicator]=' ';
			sceGuDebugPrint(8   , SCEGU_SCR_HEIGHT-16, 0x00ffffff,
							char_mode[prev_texture]);
			sceGuDebugPrint(16+size, SCEGU_SCR_HEIGHT-16, 0x00ffffff,
							buf);
			sceGuDebugPrint(16+size+40, SCEGU_SCR_HEIGHT-16, 0x00ffffff,
							char_mode[texture_mode]);
			if (frame%2)
				indicator=indicator+1<4?indicator+1:0;
		}
		else
			change=0;
	}

	if (!change) {
		sceGuDebugPrint(8, SCEGU_SCR_HEIGHT-16, 0x00ffffff,
						char_mode[texture_mode]);
		indicator=0;
	}

}

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10, 0x14], gap at: 0x8. */
void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    draw_mode();
    sceGumPushMatrix();
    sceGumLoadIdentity();
    sceGumTranslate(&pos);
    sceGumRotateX((rot.x * 3.1415927f) / 180.0f);
    sceGumRotateY((rot.y * 3.1415927f) / 180.0f);
    sceGumRotateZ((rot.z * 3.1415927f) / 180.0f);
    draw_balloon();
    draw_clouds();
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

void sceGumPerspective(float fovy, float aspect, float near, float far);

#ifdef NON_MATCHING
/* load order of the light vector constants differs */
static void init_all(void)
{
	ScePspFVector3 vec;

	sceGuInit();
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(3, NULL, 0x200);
	sceGuDispBuffer(0x1E0, 0x110, (void *)0x88000, 0x200);
	sceGuDepthBuffer((void *)0x110000, 0x200);
	sceGuOffset(0x710, 0x778);
	sceGuViewport(0x800, 0x800, 0x1E0, 0x110);
	sceGuDepthRange(0xC350, 0x2710);
	sceGuScissor(0, 0, 0x1E0, 0x110);
	sceGuEnable(2);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
	sceGuDepthFunc(7);
	sceGuEnable(1);
	sceGuFrontFace(0);
	sceGuShadeModel(1);
	sceGuEnable(8);
	vec.x = -1.0f;
	vec.y = 1.0f;
	vec.z = 1.0f;
	sceGuLightColor(0, 2, 0xffc0c0c0);
	sceGuLightColor(0, 4, 0xffffffff);
	sceGuLight(0, 0, 6, &vec);
	sceGuEnable(0xB);
	sceGuEnable(0xA);
	sceGuAmbient(0xff808080);
	sceGuColor(0xffffffff);
	sceGumSetMatrixStack(matrix_stack, 8, 8, 0x20, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
	sceGumMatrixMode(2);
	sceGuClearColor(0xffff4040);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = -15.0f;
	rot.x = 0.0f;
	rot.y = 0.0f;
	rot.z = 0.0f;
	texture_mode = 0;
	change = 0;
	init_balloon();
	init_clouds();
	sceGuDisplay(1);
}
#else
int check_clouds(void);
void draw_balloon(void);
void draw_clouds(void);
int get_balloon(void);
void init_balloon(void);
void init_clouds(void);
void menuInit(void);
void menuTerm(int cat, int num);
int proc_balloon(void);
void proc_clouds(void);
int sceCtrlReadBufferPositive(SceCtrlData *pData, int nBufs);
int sceDisplayWaitVblankStart(void);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int r_near, int r_far);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int n, int type, int comp, const ScePspFVector3 *vec);
void sceGuLightColor(int n, int type, unsigned int col);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuShadeModel(int mode);
void * sceGuSwapBuffers(void);
void sceGuTerm(void);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumMatrixMode(int mode);
void sceGumSetMatrixStack(ScePspFMatrix4 *m, int proj, int view, int world, int tex);
void set_balloon(int mode);
#define SCEGU_IMMEDIATE                    0
#define SCEGU_PF8888                       3
#define SCEGU_VRAM_BP32_0     (void *)(SCEGU_VRAM_TOP)
#define SCEGU_VRAM_BP32_1     (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE32)
#define SCEGU_VRAM_TOP        0x00000000
#define SCEGU_VRAM_BUFSIZE32  (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*4)
#define SCEGU_VRAM_BP32_2     (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE32*2))
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
#define SCEGU_SMOOTH                       1
#define SCEGU_CLIP_PLANE                   8
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
#define SCEGU_SCR_ASPECT      ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#define SCEGU_MATRIX_WORLD                 2
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0
#define SCEGU_DISPLAY_ON		1

static void init_all(void)
{
	ScePspFVector3	vec;

	sceGuInit();

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(SCEGU_PF8888, SCEGU_VRAM_BP32_0, SCEGU_VRAM_WIDTH);
	sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT,
					SCEGU_VRAM_BP32_1, SCEGU_VRAM_WIDTH);
	sceGuDepthBuffer(SCEGU_VRAM_BP32_2, SCEGU_VRAM_WIDTH);

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

	sceGuShadeModel(SCEGU_SMOOTH);
	sceGuEnable(SCEGU_CLIP_PLANE);

	vec.x=-1.0f;
	vec.y= 1.0f;
	vec.z= 1.0f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xffc0c0c0);
	sceGuLightColor(0, SCEGU_SPECULAR, 0xffffffff);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR, &vec);
	sceGuEnable(SCEGU_LIGHT0);
	sceGuEnable(SCEGU_LIGHTING);

	sceGuAmbient(0xff808080);
	sceGuColor(0xffffffff);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
					1.000000f, 100.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0xffff4040);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	pos.x=  0.0f;
	pos.y=  0.0f;
	pos.z=-15.0f;
	rot.x=  0.0f;
	rot.y=  0.0f;
	rot.z=  0.0f;

	change=0;
	texture_mode=0;

	init_balloon();
	init_clouds();

	sceGuDisplay(SCEGU_DISPLAY_ON);
}
#endif

static int pad_read(void)
{
	u_int32 prev;
	u_int32 padd;
	SceCtrlData buf;

	prev = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd = cont & (cont ^ prev);
	if (!change) {
		if (padd & 0x0080) {
			texture_next = texture_mode - 1;
			if (texture_next < 0)
				texture_next = 15;
			set_balloon(2);
		}
		if (padd & 0x0020) {
			texture_next = texture_mode + 1;
			if (texture_next >= 16)
				texture_next = 0;
			set_balloon(2);
		}
		if (padd & 0x0010) {
			if (texture_mode >= 0 && texture_mode < 6)
				texture_next = 6;
			else if (texture_mode >= 6 && texture_mode < 12)
				texture_next = 12;
			else if (texture_mode >= 12 && texture_mode < 16)
				texture_next = 0;
			set_balloon(2);
		}
		if (padd & 0x0040) {
			if (texture_mode >= 0 && texture_mode < 6)
				texture_next = 12;
			else if (texture_mode >= 6 && texture_mode < 12)
				texture_next = 0;
			else if (texture_mode >= 12 && texture_mode < 16)
				texture_next = 6;
			set_balloon(2);
		}
	}
	if (padd & 0x0009)
		return 0;
	return 1;
}

void frame_update(void) {
    int temp_v0;

    proc_balloon();
    temp_v0 = get_balloon();
    if ((prev_state != 2) & (temp_v0 == 2)) {
        change = 1;
        prev_texture = texture_mode;
        texture_mode = texture_next;
    }
    prev_state = temp_v0;
    proc_clouds();
    frame += 1;
}

int main(void) {
    menuInit();
    init_all();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        frame_update();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0);
    return 0;
}
