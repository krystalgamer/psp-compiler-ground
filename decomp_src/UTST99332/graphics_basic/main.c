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
struct _anon1;
struct _anon1 { /* size 0x1c */
    u_int32 c;
    float normal[3];
    float vertex[3];
};
typedef struct _anon1 PRIM;

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
extern float angle;
extern int moving;
extern PRIM model[6];
extern short int line[18];
extern int prims[6];
extern char prim_names[6][16];
extern u_int32 cont;

/* SDK functions */
void sceGuInit(void);
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGuDepthRange(int near, int far);
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuAmbient(unsigned int color);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuShadeModel(int mode);
void sceGuFrontFace(int order);
void sceGuDepthFunc(int function);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumRotateY(float angle);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
int sceDisplayWaitVblankStart(void);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
void menuInit(void);
void menuTerm(int cat, int num);

static void draw_frame(void);
static void init_all(void);
static int pad_read(void);


static void draw_frame(void)
{
	ScePspFVector3 vec;
	int i;

	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);
	sceGuColor(0xffffffff);
	sceGumDrawArray(1, 0x800100, 6, NULL, line);
	sceGumPushMatrix();
	sceGumLoadIdentity();
	vec.x = 0.0f;
	vec.y = 0.0f;
	vec.z = -10.0f;
	sceGumTranslate(&vec);
	for (i = 0; i < 6; i++) {
		sceGuDebugPrint((i % 3) * 160 + 8, (i / 3) * 136 + 8, 0xffffff, prim_names[i]);
		sceGumPushMatrix();
		vec.x = -4.9f + (i % 3) * 4.9f;
		vec.y = 2.0f - (i / 3) * 4.3f;
		vec.z = 0.0f;
		sceGumTranslate(&vec);
		sceGumRotateY((angle * 3.1415927f) / 180.0f);
		sceGumDrawArray(prims[i], 0x1fc, 6, NULL, model);
		sceGumPopMatrix();
	}
	sceGumPopMatrix();
	sceGuFinish();
	sceGuSync(0, 0);
}

static void init_all(void)
{
	ScePspFVector3 vec;

	sceGuInit();
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(1, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x44000, 512);
	sceGuDepthBuffer((void *)0x88000, 512);
	sceGuOffset(2048 - 480 / 2, 2048 - 272 / 2);
	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(50000, 10000);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);
	sceGuAlphaFunc(6, 0, 255);
	sceGuEnable(0);
	sceGuDepthFunc(7);
	sceGuEnable(1);
	sceGuFrontFace(0);
	sceGuDisable(9);
	sceGuShadeModel(1);
	sceGuEnable(8);
	vec.x = 0.614497f;
	vec.y = 0.691714f;
	vec.z = 0.379372f;
	sceGuLightColor(0, 2, 0xffffffff);
	sceGuLight(0, 0, 2, &vec);
	sceGuEnable(11);
	sceGuEnable(10);
	sceGuDisable(7);
	sceGuAmbient(0xffdddddd);
	sceGumSetMatrixStack(matrix_stack, 8, 8, 32, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
	sceGumMatrixMode(2);
	sceGuClearColor(0);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	angle = 0.0f;
	moving = 0;
	sceGuDisplay(1);
}

static int pad_read(void)
{
	u_int32 prev, padd;
	SceCtrlData buf;

	prev = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons & (buf.Buttons ^ prev);
	cont = buf.Buttons;
	if (padd & 0x2000)
		moving ^= 1;
	return (padd & 9) == 0;
}

void frame_update(void) {
    float temp_f0;

    if (moving != 0) {
        temp_f0 = angle + 1.0f;
        angle = temp_f0;
        if (temp_f0 >= 360.0f) {
            angle = temp_f0 - 360.0f;
            return;
        }
        return;
    }
    angle = 0.0f;
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
    menuTerm(1, 1);
    return 0;
}
