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
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuFog(float near, float far, unsigned int color);
void *sceGuGetMemory(int size);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);

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

static void translate_patch(void)
{
	int i, j;
	ScePspFVector3 *vec_org, *vec_new, *wgt;

	vec_org = (ScePspFVector3 *)ground;
	vec_new = ground_t;
	wgt = ground_v;
	for (i = 0; i < 25; i += 3) {
		for (j = 0; j < 25; j += 3) {
			vec_new[0].x = vec_org[0].x + wgt->x;
			vec_new[0].y = vec_org[0].y + wgt->y;
			vec_new[0].z = vec_org[0].z + wgt->z;
			if (j > 0) {
				vec_new[-1].x = vec_org[-1].x + wgt->x;
				vec_new[-1].y = vec_org[-1].y + wgt->y;
				vec_new[-1].z = vec_org[-1].z + wgt->z;
			}
			if (j < 24) {
				vec_new[1].x = vec_org[1].x + wgt->x;
				vec_new[1].y = vec_org[1].y + wgt->y;
				vec_new[1].z = vec_org[1].z + wgt->z;
			}
			if (i > 0) {
				vec_new[-25].x = vec_org[-25].x + wgt->x;
				vec_new[-25].y = vec_org[-25].y + wgt->y;
				vec_new[-25].z = vec_org[-25].z + wgt->z;
			}
			if (i < 24) {
				vec_new[25].x = vec_org[25].x + wgt->x;
				vec_new[25].y = vec_org[25].y + wgt->y;
				vec_new[25].z = vec_org[25].z + wgt->z;
			}
			if (j < 24 && i < 24) {
				vec_new[26].x = vec_org[26].x + wgt->x;
				vec_new[26].y = vec_org[26].y + wgt->y;
				vec_new[26].z = vec_org[26].z + wgt->z;
			}
			if (j > 0 && i < 24) {
				vec_new[24].x = vec_org[24].x + wgt->x;
				vec_new[24].y = vec_org[24].y + wgt->y;
				vec_new[24].z = vec_org[24].z + wgt->z;
			}
			if (j < 24 && i > 0) {
				vec_new[-24].x = vec_org[-24].x + wgt->x;
				vec_new[-24].y = vec_org[-24].y + wgt->y;
				vec_new[-24].z = vec_org[-24].z + wgt->z;
			}
			if (j > 0 && i > 0) {
				vec_new[-26].x = vec_org[-26].x + wgt->x;
				vec_new[-26].y = vec_org[-26].y + wgt->y;
				vec_new[-26].z = vec_org[-26].z + wgt->z;
			}
			wgt++;
			vec_org += 3;
			vec_new += 3;
		}
		vec_org += 48;
		vec_new += 48;
	}
}

static void draw_frame(void)
{
	ScePspFVector3 vec;
	float *vp;
	int num;
	int i;

	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);
	sceGuLightColor(0, 4, 0);
	sceGuEnable(9);
	sceGuColor(0xffffffff);
	sceGuFog(fog, fog + 3.0f, 0x800000);
	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos.trans);
	sceGumRotateX(pos.rot.x * 3.1415927f / 180.0f);
	sceGumRotateY(pos.rot.y * 3.1415927f / 180.0f);
	vec.x = 2.5f;
	vec.y = 2.5f;
	vec.z = 2.5f;
	sceGumScale(&vec);
	translate_patch();
	vp = sceGuGetMemory(sizeof(ground_t));
	fmemcpy(vp, (float *)ground_t, sizeof(ground_t));
	sceGumDrawBezier(0x180, 25, 25, NULL, vp);
	sceGuLightColor(0, 4, 0xffffffff);
	sceGuDisable(9);
	sceGuColor(0xff80a0a0);
	for (i = 0; i < cnt; i++) {
		num = order[i];
		sceGumPushMatrix();
		sceGumTranslate(&spos[num].vec);
		vec.x = 0.08f;
		vec.y = 0.08f;
		vec.z = 0.08f;
		sceGumScale(&vec);
		sceGumDrawBezier(0x180, 4, 7, NULL, sphere);
		sceGumPopMatrix();
	}
	sceGumPopMatrix();
	sceGuFinish();
	sceGuSync(0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_tamatama/nonmatchings/main", init_all);

static void frame_update(void)
{
	int num;
	int i;

	for (i = 0; i < cnt; i++) {
		num = order[i];
		if (spos[num].vec.y <= 0.001f)
			spos[num].t = 0;
		spos[num].t++;
		spos[num].vec.y = spos[num].d * spos[num].t - 0.002f * spos[num].t * spos[num].t;
		if (spos[num].vec.y <= 0.08f)
			ground_v[num].y -= spos[num].d * 0.5f;
		else if (spos[num].vec.y > 0.088f)
			ground_v[num].y *= 0.5f;
	}
}

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
