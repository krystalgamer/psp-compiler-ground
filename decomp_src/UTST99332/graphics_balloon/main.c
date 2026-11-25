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

#ifdef NON_MATCHING
/* block layout around check_clouds/indicator differs */
static void draw_mode(void)
{
	char buf[8] = ">>>>";
	int size;
	int i;

	if (change) {
		if (check_clouds()) {
			change = 0;
		} else {
			size = 0;
			for (i = 0; i < 12; i++) {
				if (char_mode[prev_texture][i] == 0)
					break;
				size++;
			}
			buf[3 - indicator] = ' ';
			sceGuDebugPrint(8, 256, 0xffffff, char_mode[prev_texture]);
			sceGuDebugPrint(size * 8 + 16, 256, 0xffffff, buf);
			sceGuDebugPrint(size * 8 + 56, 256, 0xffffff, char_mode[texture_mode]);
			if (frame & 1) {
				if (++indicator >= 4)
					indicator = 0;
			}
		}
	}
	if (!change) {
		sceGuDebugPrint(8, 256, 0xffffff, char_mode[texture_mode]);
		indicator = 0;
	}
}
#else
INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/main", draw_mode);
#endif

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
INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/main", init_all);
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
