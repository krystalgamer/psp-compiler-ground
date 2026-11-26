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
struct _anon1;
struct _anon1 { /* size 0x18 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
};
typedef struct _anon1 POS;
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

extern const unsigned int env_clut[128];
extern const unsigned int env_tex[256];
extern const unsigned int toon_clut[8];
extern const unsigned int toon_tex[128];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern POS pos;
extern float angle;
extern int changed;
extern int autoflag;
extern int mode;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];

static void draw_frame(int frame);
static void init_pos(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
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
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuSpecular(float power);
void sceGuShadeModel(int mode);
void sceGuFrontFace(int order);
void sceGuDepthFunc(int function);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
int sceDisplayWaitVblankStart(void);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", env_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", env_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", toon_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", toon_tex);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", draw_frame);

void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x10000);
    sceGuDrawBuffer(1, NULL, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
    sceGuDepthBuffer((void *)0x88000, 0x200);
    sceGuOffset(0x710U, 0x778U);
    sceGuViewport(0x800, 0x800, 0x1E0, 0x110);
    sceGuDepthRange(0xC350, 0x2710);
    sceGuDisable(4);
    sceGuScissor(0, 0, 0x1E0, 0x110);
    sceGuEnable(2);
    sceGuDepthFunc(6);
    sceGuEnable(1);
    sceGuFrontFace(1);
    sceGuEnable(0x14);
    sceGuDisable(9);
    sceGuShadeModel(1);
    sceGuEnable(6);
    sceGuEnable(0xA);
    sceGuSpecular(75.0f);
    sceGumSetMatrixStack(matrix_stack, 8, 8, 0x20, 0);
    sceGumMatrixMode(0);
    sceGumLoadIdentity();
    sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
    sceGuClearColor(0xFF645A1EU);
    sceGuClearDepth(0U);
    sceGuClearStencil(0U);
    sceGumMatrixMode(2);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGuDisplay(1);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_pot/nonmatchings/main", init_pos);

extern u_int32 D_000153C8; /* static u_int32 opadd in pad_read (bss is asm) */

static int pad_read(void)
{
	u_int32 padd;
	SceCtrlData buf;

	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;

	if (padd & 0x10) {
		pos.rot.x -= 15.0f;
		if (pos.rot.x <= -360.0f) {
			pos.rot.x = 0.0f;
		}
	}

	if (padd & 0x40) {
		pos.rot.x += 15.0f;
		if (pos.rot.x >= 360.0f) {
			pos.rot.x = 0.0f;
		}
	}

	if (padd & 0x80) {
		pos.rot.y -= 15.0f;
		if (pos.rot.y <= -360.0f) {
			pos.rot.y = 0.0f;
		}
	}

	if (padd & 0x20) {
		pos.rot.y += 15.0f;
		if (pos.rot.y >= 360.0f) {
			pos.rot.y = 0.0f;
		}
	}

	if (padd & 0x100) {
		pos.trans.z -= 3.0f;
		if (pos.trans.z < -100.0f) {
			pos.trans.z = -100.0f;
		}
	}

	if (padd & 0x200) {
		pos.trans.z += 3.0f;
		if (pos.trans.z > -5.0f) {
			pos.trans.z = -5.0f;
		}
	}

	if (padd & 0x2000) {
		mode = 1;
		changed = 1;
	}

	if (padd & 0x4000) {
		mode = 2;
		changed = 1;
	}

	if (padd & 0x1000) {
		mode = 3;
		changed = 1;
	}

	if (padd & 0x8000) {
		mode = 0;
		changed = 1;
	}

	if (padd & 0x8) {
		if (D_000153C8 != padd) {
			init_pos();
			autoflag ^= 1;
		}
	}

	if (padd & 0x1) {
		return 0;
	}

	D_000153C8 = padd;

	return 1;
}

int main(void) {
    int temp_a0;
    int var_s0;

    menuInit();
    var_s0 = 0;
    init_all();
    init_pos();
loop_1:
    temp_a0 = var_s0;
    var_s0 += 1;
    if (pad_read() != 0) {
        draw_frame(temp_a0);
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0x17);
    return 0;
}
