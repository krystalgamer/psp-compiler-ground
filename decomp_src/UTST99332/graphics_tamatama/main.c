#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
typedef unsigned char u_char8;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
typedef unsigned int u_int32;
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
struct _anon2;
struct _anon2 { /* size 0x14 */
    ScePspFVector3 vec;
    float d;
    int t;
};
typedef struct _anon2 SPOS;
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
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

extern float ground[1875];
extern float sphere[84];
extern unsigned int checkcolor[1];
extern unsigned int check32x32[128];
extern unsigned int check16x16[64];
extern unsigned int check8x8[32];
extern unsigned int check4x4[16];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern ScePspFVector3 ground_v[81];
extern ScePspFVector3 ground_t[625];
extern POS pos;
extern SPOS spos[81];
extern u_char8 order[81];
extern int cnt;
extern float fog;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];

static void fmemcpy(float *dst, float *src, int n);
int rand(void);
static void translate_patch(void);
static void draw_frame(void);
static void init_all(void);
static void frame_update(void);
static void init_pos(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStart(void);


static void fmemcpy(float *dst, float *src, int n)
{
	int i;

	for (i = 0; i < n; i++)
		*dst++ = *src++;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_tamatama/nonmatchings/main", translate_patch);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_tamatama/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_tamatama/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_tamatama/nonmatchings/main", frame_update);

static void init_pos(void)
{
	int i, j;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			spos[i * 9 + j].vec.x = (j - 4) * 0.25f;
			spos[i * 9 + j].vec.y = 0.0f;
			spos[i * 9 + j].vec.z = (4 - i) * 0.25f;
			spos[i * 9 + j].d = (rand() % 10) * 0.007f + 0.05f;
			spos[i * 9 + j].t = 0;
		}
	}
	for (i = 0; i < 81; i++) {
		ground_v[i].x = 0.0f;
		ground_v[i].y = 0.0f;
		ground_v[i].z = 0.0f;
	}
	pos.rot.x = 0.0f;
	pos.rot.y = 0.0f;
	pos.rot.z = 0.0f;
	pos.trans.x = 0.0f;
	pos.trans.y = -1.5f;
	pos.trans.z = -5.0f;
}

static int pad_read(void)
{
	SceCtrlData buf;
	int i;

	sceCtrlReadBufferPositive(&buf, 1);
	if (buf.Buttons & 0x0010) {
		pos.rot.x -= 2.0f;
		if (pos.rot.x <= -360.0f)
			pos.rot.x = 0.0f;
	}
	if (buf.Buttons & 0x0040) {
		pos.rot.x += 2.0f;
		if (pos.rot.x >= 360.0f)
			pos.rot.x = 0.0f;
	}
	if (buf.Buttons & 0x0080) {
		pos.rot.y += 2.0f;
		if (pos.rot.y >= 360.0f)
			pos.rot.y = 0.0f;
	}
	if (buf.Buttons & 0x0020) {
		pos.rot.y -= 2.0f;
		if (pos.rot.y <= -360.0f)
			pos.rot.y = 0.0f;
	}
	if (buf.Buttons & 0x2000) {
		pos.trans.z -= 1.0f;
		if (pos.trans.z < -100.0f)
			pos.trans.z = -100.0f;
	}
	if (buf.Buttons & 0x4000) {
		pos.trans.z += 1.0f;
		if (pos.trans.z > -5.0f)
			pos.trans.z = -5.0f;
	}
	if (buf.Buttons & 0x1000) {
		if (++cnt >= 81)
			cnt = 81;
	}
	if (buf.Buttons & 0x8000) {
		if (--cnt < 2)
			cnt = 1;
		for (i = cnt; i < 81; i++)
			(ground_v + order[i])->y = 0.0f;
	}
	if (buf.Buttons & 0x0100)
		fog -= 0.05f;
	if (buf.Buttons & 0x0200)
		fog += 0.05f;
	if (buf.Buttons & 0x0008) {
		pos.rot.x = 0.0f;
		pos.rot.y = 0.0f;
		pos.rot.z = 0.0f;
		pos.trans.x = 0.0f;
		pos.trans.y = -1.5f;
		pos.trans.z = -5.0f;
		fog = 3.0f;
	}
	if (buf.Buttons & 0x0001)
		return 0;
	return 1;
}

int main(void) {
    menuInit();
    init_all();
    init_pos();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        frame_update();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0x20);
    return 0;
}
