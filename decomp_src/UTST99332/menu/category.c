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
struct _anon1;
struct _anon1 { /* size 0x24 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
    int cat;
    int num;
    int ret;
};
typedef struct _anon1 *PMENUDATA;
struct _anon2;
struct _anon2 { /* size 0x20 */
    int cnt_rot;
    int flag_rot;
    float scale;
    float sbuf[3];
    int scnt;
    float t;
};
typedef struct _anon2 CATDATA;

extern PMENUDATA menu;
extern CATDATA cat;

void InitCategory(void);
void DrawCategory(void);
static void InitSpline(void);
static void CtrlSpline(void);
void RunCategory(void);
void KeyCategory(u_int32 padd, u_int32 cont, float *axis);


/* SDK prototypes (tools/sdk_protos.h) */
int rand(void);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGumLoadIdentity(void);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);

void InitCategory(void)
{
	cat.cnt_rot = 0;
	cat.flag_rot = 0;
	cat.sbuf[0] = 0.0f;
	cat.sbuf[1] = 0.0f;
	cat.sbuf[2] = 0.0f;
	cat.scnt = 0;
	cat.t = 0.0f;
	cat.scale = 1.0f;
	InitSpline();
}

extern const ScePspFVector3 D_00017078;
void DrawBG(void);
void DrawDice(float scale);
void DiceTexture(void);
void DrawShadow(float scale);
void DrawCategoryString(int mode);
void DrawItemBar(void);
void DrawCategory(void)
{
	ScePspFVector3 vec;
	ScePspFVector3 t;

	sceGuDisable(1);
	sceGuDisable(9);
	DrawBG();
	sceGuEnable(1);
	sceGumLoadIdentity();
	t = D_00017078;
	vec = t;
	sceGumTranslate(&vec);
	sceGumPushMatrix();
	sceGumTranslate(&menu->pos);
	sceGumRotateX(menu->rot.x * 3.1415927f / 180.0f);
	sceGumRotateY(menu->rot.y * 3.1415927f / 180.0f);
	sceGumRotateZ(menu->rot.z * 3.1415927f / 180.0f);
	DrawDice(1.0f);
	DiceTexture();
	sceGumPopMatrix();
	sceGumPushMatrix();
	sceGumRotateY(menu->rot.y * 3.1415927f / 180.0f);
	t.x = 1.0f;
	t.y = 1.0f;
	t.z = cat.scale;
	vec = t;
	sceGumScale(&vec);
	DrawShadow(1.0f);
	sceGumPopMatrix();
	sceGuDisable(1);
	DrawCategoryString(0);
	DrawItemBar();
}

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/category", InitSpline);

float Spline(float t, float pos0, float pos1, float pos2) {
    float temp_f13;
    float temp_f15;
    float temp_f1;

    temp_f13 = (pos1 + pos0) * 0.5f;
    temp_f15 = (pos2 + pos1) * 0.5f;
    temp_f1 = ((temp_f13 + temp_f15 + pos1) / 3.0f) * 4.0f;
    return ((((2.0f * temp_f15) + (2.0f * temp_f13)) - temp_f1) * t * t) + (((temp_f1 - temp_f15) - (temp_f13 * 3.0f)) * t) + temp_f13;
}

static __inline__ float srnd(float f)
{
	return (rand() & 1) ? -f : f;
}
static void CtrlSpline(void)
{
	float p[3];
	int cnt;

	cnt = cat.scnt;
	p[0] = cat.sbuf[cnt];
	p[1] = cat.sbuf[(cnt == 0) ? 1 : ((cnt == 1) ? 2 : 0)];
	p[2] = cat.sbuf[(cnt == 0) ? 2 : ((cnt == 1) ? 0 : 1)];
	menu->pos.y = Spline(cat.t, p[0], p[1], p[2]);
	cat.t += 0.02f;
	if (cat.t >= 1.0f) {
		cat.t = 0.0f;
		cat.sbuf[cat.scnt] = srnd(0.0f + (rand() % 100) * 0.0005f);
		cat.scnt = (cat.scnt + 1 >= 3) ? 0 : cat.scnt + 1;
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/category", RunCategory);

void PlaySE(int num);
void ProgramChange(int mode);
void KeyCategory(u_int32 padd, u_int32 cont, float *axis)
{
	if (axis[0] < -80.0f || (padd & 0x80)) {
		if (cat.flag_rot == 0) {
			cat.flag_rot = 1;
			PlaySE(0);
		}
	}
	if (axis[0] > 80.0f || (padd & 0x20)) {
		if (cat.flag_rot == 0) {
			cat.flag_rot = 2;
			PlaySE(0);
		}
	}
	if (axis[1] < -80.0f || (padd & 0x10)) {
		if (cat.flag_rot == 0) {
			cat.flag_rot = 4;
			PlaySE(0);
		}
	}
	if (axis[1] > 80.0f || (padd & 0x40)) {
		if (cat.flag_rot == 0) {
			cat.flag_rot = 8;
			PlaySE(0);
		}
	}
	if ((padd & 0x2000) && cat.flag_rot == 0) {
		menu->num = 0;
		ProgramChange(1);
		PlaySE(1);
	}
}

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/category", D_00017078);
