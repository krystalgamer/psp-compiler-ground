#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef unsigned int u_int32;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1 { /* size 0x10 */
    u_int32 c;
    ScePspFVector3 vtx;
};
typedef struct _anon1 MODEL;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct _anon2;
struct _anon2 { /* size 0x14 */
    int x;
    int y;
    u_int32 c;
    int comp;
    float high;
};
typedef struct _anon2 OBJECT;
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
struct _anon3;
struct _anon3 { /* size 0x18 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
};
typedef struct _anon3 POS;

/* SDK functions */
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
extern POS world;
extern MODEL model[961];
extern OBJECT obj[2];

static void set_object(float *analog);
static void init_param(void);
static void init_all(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
int sceDisplayWaitVblankStart(void);
int sceCtrlSetSamplingMode(int mode);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", D_00011BE0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", D_00011C04);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", set_object);

void draw_model(void) {
    sceGumPushMatrix();
    sceGuColor(-1U);
    sceGumDrawBezier(0x19C, 0x1F, 0x1F, NULL, model);
    sceGumPopMatrix();
}

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10, 0x14], gap at: 0x8. */
void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    sceGumPushMatrix();
    sceGumLoadIdentity();
    sceGumTranslate(&world.pos);
    sceGumRotateX((world.rot.x * 3.1415927f) / 180.0f);
    sceGumRotateY((world.rot.y * 3.1415927f) / 180.0f);
    sceGumRotateZ((world.rot.z * 3.1415927f) / 180.0f);
    draw_model();
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

#ifdef NON_MATCHING
/* Close: the original stores world's zeros from a float register. */
static void init_param(void)
{
	obj[0].x = 21;
	obj[0].y = 18;
	obj[0].c = 0xff0000ff;
	obj[0].comp = 0;
	obj[0].high = 2.0f;
	obj[1].x = 9;
	obj[1].y = 18;
	obj[1].c = 0xffff0000;
	obj[1].comp = 0;
	obj[1].high = 2.0f;
	world.pos.x = 0.0f;
	world.pos.y = 0.0f;
	world.pos.z = -10.0f;
	world.rot.x = 300.0f;
	world.rot.y = 0.0f;
	world.rot.z = 0.0f;
}
#else
INCLUDE_ASM("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", init_param);
#endif

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", init_all);

#define cont D_00013800	/* pad_read's static */
extern u_int32 cont;

static int pad_read(void)
{
	u_int32 prev, padd;
	SceCtrlData buf;
	float axis[2];
	OBJECT *p;

	prev = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	axis[0] = (buf.Lx - 128) * 0.01f;
	axis[1] = (buf.Ly - 128) * -0.01f;
	padd = buf.Buttons & (buf.Buttons ^ prev);
	cont = buf.Buttons;
	p = obj;
	if (cont & 0x1000) {
		p->y -= 3;
		if (p->y < 3)
			p->y = 3;
	}
	if (cont & 0x4000) {
		p->y += 3;
		if (p->y >= 28)
			p->y -= 3;
	}
	if (cont & 0x8000) {
		p->x -= 3;
		if (p->x < 3)
			p->x = 3;
	}
	if (cont & 0x2000) {
		p->x += 3;
		if (p->x >= 28)
			p->x -= 3;
	}
	p->comp = 0;
	if (cont & 0x0200)
		p->comp = 1;
	p = &obj[1];
	if (cont & 0x0010) {
		p->y -= 3;
		if (p->y < 3)
			p->y = 3;
	}
	if (cont & 0x0040) {
		p->y += 3;
		if (p->y >= 28)
			p->y -= 3;
	}
	if (cont & 0x0080) {
		p->x -= 3;
		if (p->x < 3)
			p->x = 3;
	}
	if (cont & 0x0020) {
		p->x += 3;
		if (p->x >= 28)
			p->x -= 3;
	}
	p->comp = 0;
	if (cont & 0x0100)
		p->comp = 1;
	set_object(axis);
	if (padd & 0x0008)
		init_param();
	if (padd & 0x0001)
		return 0;
	return 1;
}

int main(void) {
    menuInit();
    sceCtrlSetSamplingMode(1);
    init_all();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0x1D);
    return 0;
}
