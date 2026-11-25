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

/* SDK functions */
void sceGuTerm(void);
void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStart(void);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

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
extern int texflag;
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

static void draw_frame(void);
static void init_all(void);
static int pad_read(void);


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
    DrawDragon(texflag);
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

void sceGuSpecular(float power);
void sceGuFog(float near, float far, unsigned int color);
void sceGumPerspective(float fovy, float aspect, float near, float far);

#ifdef NON_MATCHING
/* the two light vectors' constants load in a different order ($f21 holds 1.0f) */
static void init_all(void)
{
	ScePspIMatrix4 dith = {
		{ -4, 0, -3, 1 },
		{ 2, -2, 3, -1 },
		{ -3, 1, -4, 0 },
		{ 3, -1, 2, -2 },
	};
	ScePspFVector3 vec;

	sceGuInit();
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(1, NULL, 0x200);
	sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
	sceGuDepthBuffer((void *)0x88000, 0x200);
	sceGuOffset(0x710, 0x778);
	sceGuViewport(0x800, 0x800, 0x1E0, 0x110);
	sceGuDepthRange(0xC350, 0x2710);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
	sceGuScissor(0, 0, 0x1E0, 0x110);
	sceGuEnable(2);
	sceGuAlphaFunc(6, 0, 0xFF);
	sceGuEnable(0);
	sceGuDepthFunc(7);
	sceGuEnable(1);
	sceGuFrontFace(0);
	sceGuEnable(0x14);
	sceGuTexFunc(0, 1);
	sceGuTexFilter(7, 0);
	sceGuTexWrap(0, 0);
	sceGuDisable(9);
	sceGuSetDither(&dith);
	sceGuEnable(6);
	sceGuEnable(8);
	sceGuShadeModel(1);
	vec.x = 10.0f;
	vec.y = 4.0f;
	vec.z = 10.0f;
	sceGuLightColor(0, 2, 0xff008000);
	sceGuLightColor(0, 4, 0xffffffff);
	sceGuLight(0, 0, 6, &vec);
	sceGuEnable(0xB);
	vec.x = -1.0f;
	vec.y = -2.0f;
	vec.z = 1.0f;
	sceGuLightColor(1, 2, 0xff000080);
	sceGuLight(1, 0, 2, &vec);
	sceGuEnable(0xC);
	sceGuEnable(0xA);
	sceGuSpecular(60.0f);
	sceGuFog(24.0f, 60.0f, 0xff000000);
	sceGuEnable(7);
	sceGuAmbient(0xffc0c0c0);
	sceGumSetMatrixStack(matrix_stack, 8, 8, 0x20, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
	sceGumMatrixMode(2);
	sceGuClearColor(0xff202020);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	pos.x = 0.0f;
	pos.y = -12.0f;
	pos.z = -44.0f;
	rot.x = 16.0f;
	rot.y = 310.0f;
	rot.z = 0.0f;
	sceGuDisplay(1);
}
#else
INCLUDE_ASM("tmp/asm/UTST99332/graphics_dragon/nonmatchings/main", init_all);
#endif

static int pad_read(void)
{
	u_int32 prev, padd;
	SceCtrlData buf;

	prev = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd = cont & (cont ^ prev);
	if (cont & 0x0010) {
		rot.x -= 4.0f;
		if (rot.x < 0.0f)
			rot.x += 360.0f;
	}
	if (cont & 0x0040) {
		rot.x += 4.0f;
		if (rot.x >= 360.0f)
			rot.x -= 360.0f;
	}
	if (cont & 0x0080) {
		rot.y -= 4.0f;
		if (rot.y < 0.0f)
			rot.y += 360.0f;
	}
	if (cont & 0x0020) {
		rot.y += 4.0f;
		if (rot.y >= 360.0f)
			rot.y -= 360.0f;
	}
	if (cont & 0x0100)
		pos.z -= 2.0f;
	if (cont & 0x0200)
		pos.z += 2.0f;
	if (padd & 0x2000)
		texflag ^= 1;
	if (padd & 0x0008) {
		pos.x = 0.0f;
		pos.y = -12.0f;
		pos.z = -44.0f;
		rot.x = 16.0f;
		rot.y = 310.0f;
		rot.z = 0.0f;
	}
	if (padd & 0x0001)
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
    menuTerm(1, 6);
    return 0;
}

/* init_all's dith initializer: ScePspIMatrix4 is 16-byte aligned */
__asm__(".section .rodata\n\t.align 4\n.section .text");
INCLUDE_RODATA("tmp/asm/UTST99332/graphics_dragon/nonmatchings/main", D_00011F30);
