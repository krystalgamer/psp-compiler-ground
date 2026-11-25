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


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_vtxformat/nonmatchings/main", uv);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_vtxformat/nonmatchings/main", coltbl);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_vtxformat/nonmatchings/main", D_00011E5C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_vtxformat/nonmatchings/main", D_00011E80);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_vtxformat/nonmatchings/main", init_bezier);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_vtxformat/nonmatchings/main", draw_bezier);

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_vtxformat/nonmatchings/main", init_all);

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
