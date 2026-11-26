#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
struct _anon1;
struct _anon1 { /* size 0x6 */
    short int p[3];
};
typedef struct _anon1 Gu2dV16;
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
struct _anon2;
struct _anon2 { /* size 0x24 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
    int cat;
    int num;
    int ret;
};
typedef struct _anon2 *PMENUDATA;
struct _anon3;
struct _anon3 { /* size 0x28 */
    int step;
    int cnt;
    float scale;
    int alpha;
    int xstep;
    int ystep;
    int max;
    int select;
    int repeat;
    int crossfade;
};
typedef struct _anon3 ITEMDATA;

extern PMENUDATA menu;
extern int catlist[6];
extern ITEMDATA item;

void InitItem(void);
static void _DrawItemFade(u_int32 c);
static void DrawItem2D(void);
void DrawItem(void);
void RunItem(void);
void KeyItem(u_int32 padd, u_int32 cont, float *axis);

void InitItemList(int max);
void InitLR(void);
void InitStar(void);
void SetDice(int cat);
void SetItemSelect(int num);
void FadeSetup(int mode, int step, int color);
void SetLRAnim(int flag);

/* SDK prototypes (tools/sdk_protos.h) */
void sceGuColor(unsigned int color);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);

void InitItem(void)
{
	item.alpha = 255;
	item.max = 0;
	item.cnt = 0;
	item.xstep = 0;
	item.ystep = 0;
	item.select = 0;
	item.repeat = 0;
	item.crossfade = 0;
	item.step = 0;
	item.scale = 1.0f;
	item.max = catlist[menu->cat];
	InitItemList(item.max);
	InitLR();
	InitStar();
	if (menu->ret) {
		SetDice(menu->cat);
		SetItemSelect(menu->num);
		item.step = 9;
		menu->ret = 0;
		item.scale = 1.7f;
		FadeSetup(1, 8, 0);
		item.crossfade = 1;
	} else {
		SetLRAnim(1);
	}
}

extern Gu2dV16 D_001A3E54[];
static void _DrawItemFade(u_int32 c)
{
	sceGuDisable(9);
	sceGuColor(c);
	sceGumDrawArray(6, 0x800100, 2, NULL, D_001A3E54);
}

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_0001708C);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_00017090);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_00017094);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_00017098);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_0001709C);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_000170A0);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_000170A4);

void DrawCategoryString(int mode);
void DrawItemBar(void);
void DrawItemFrame(int xstep, int ystep);
int DrawItemListOpen(int cnt);
void DrawItemSelect(void);
int DrawItemListAnim(void);
void DrawItemList(void);
void DrawLR(void);
void DrawSelect(void);
void DrawInfoString(void);
void DrawStar(void);
int GetItemTex(void);
static void DrawItem2D(void)
{
	if (item.step == 7)
		DrawCategoryString(0);
	else
		DrawCategoryString(1);
	DrawItemBar();
	switch (item.step) {
	case 0:
	case 6:
	case 7:
		break;
	case 1:
	case 2:
		DrawItemFrame(item.xstep, item.ystep);
		break;
	case 3:
		DrawItemFrame(item.xstep, item.ystep);
		if (DrawItemListOpen(item.cnt))
			item.step = 4;
		break;
	case 5:
		DrawItemFrame(0, 0);
		DrawItemSelect();
		if (DrawItemListAnim()) {
			item.step = 4;
			menu->num = GetItemTex();
		}
		DrawLR();
		DrawSelect();
		DrawInfoString();
		InitStar();
		break;
	case 4:
	case 8:
	case 9:
		DrawItemFrame(0, 0);
		DrawItemSelect();
		DrawItemList();
		DrawLR();
		DrawSelect();
		DrawInfoString();
		DrawStar();
		break;
	}
}

extern const ScePspFVector3 D_000170D0;
extern const float D_0001708C, D_00017090;
void DrawBG(void);
void DrawDice(float scale);
void DiceTexture(void);
void DrawShadow(float scale);
void FadeDraw(void);
int FadeState(void);
void DrawItem(void)
{
	ScePspFVector3 vec;
	ScePspFVector3 t;

	sceGuDisable(1);
	sceGuDisable(9);
	DrawBG();
	sceGuEnable(1);
	sceGumLoadIdentity();
	t = D_000170D0;
	vec = t;
	sceGumTranslate(&vec);
	sceGumPushMatrix();
	sceGumRotateX(menu->rot.x * D_0001708C / D_00017090);
	sceGumRotateY(menu->rot.y * D_0001708C / D_00017090);
	sceGumRotateZ(menu->rot.z * D_0001708C / D_00017090);
	DrawDice(item.scale);
	sceGuColor((item.alpha << 24) | 0xFFFFFF);
	DiceTexture();
	sceGumPopMatrix();
	DrawShadow(item.scale);
	sceGuDisable(1);
	DrawItem2D();
	switch (item.step) {
	case 8:
		if (FadeState() == 0)
			_DrawItemFade(0xFF000000);
		FadeDraw();
		break;
	case 9:
		if (item.crossfade == 1) {
			if (FadeState() == 0) {
				FadeSetup(1, 8, 0xFFFFFF);
				item.crossfade = 0;
			} else
				_DrawItemFade(0xFFFFFFFF);
		}
		FadeDraw();
		break;
	}
}

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_000170D0);

extern const float D_00017094, D_00017098, D_0001709C;
int FadeState(void);
void ProgramChange(int mode);
void PrxExec(int cat, int num);
void RunItem(void)
{
	switch (item.step) {
	case 0:
		item.scale += D_00017094;
		item.alpha -= 38;
		if (item.alpha < 0)
			item.alpha = 0;
		if (item.scale >= D_00017098) {
			item.step = 1;
			item.scale = D_00017098;
			item.xstep = 101;
			item.ystep = 57;
		}
		break;
	case 1:
		item.xstep -= 10;
		if (item.xstep < 0) {
			item.step = 2;
			item.xstep = 0;
		}
		break;
	case 2:
		item.ystep -= 6;
		if (item.ystep < 0) {
			item.step = 3;
			item.ystep = 0;
			item.cnt = 0;
		}
		break;
	case 3:
		item.cnt++;
		break;
	case 7:
		item.scale -= D_00017094;
		item.alpha += 38;
		if (item.alpha >= 256)
			item.alpha = 255;
		if (item.scale <= D_0001709C) {
			item.scale = D_0001709C;
			ProgramChange(0);
		}
		break;
	case 8:
		if (++item.cnt > 60) {
			if (FadeState() == 0)
				PrxExec(menu->cat, menu->num);
		}
		break;
	case 9:
		if (FadeState() == 0) {
			if (item.crossfade == 0)
				item.step = 4;
		}
		break;
	}
}

extern const float D_000170A0, D_000170A4;
int SetItemListAnim(int dir);
void PlaySE(int num);
void KeyItem(u_int32 padd, u_int32 cont, float *axis)
{
	if (axis[0] < D_000170A0) {
		padd |= 0x100;
		cont |= 0x100;
	}
	if (axis[0] > D_000170A4) {
		padd |= 0x200;
		cont |= 0x200;
	}
	if (cont & 0x80)
		cont |= 0x100;
	if (padd & 0x80)
		padd |= 0x100;
	if (cont & 0x20)
		cont |= 0x200;
	if (padd & 0x20)
		padd |= 0x200;
	if (!(cont & 0x300))
		item.repeat = 0;
	if (item.step == 4) {
		if (cont & 0x100) {
			if (++item.repeat >= 11)
				padd |= 0x100;
		}
		if (cont & 0x200) {
			if (++item.repeat >= 11)
				padd |= 0x200;
		}
		if (padd & 0x100) {
			if (SetItemListAnim(1) == 0) {
				item.step = 5;
				SetLRAnim(2);
				PlaySE(2);
			}
		}
		if (padd & 0x200) {
			if (SetItemListAnim(0) == 0) {
				item.step = 5;
				SetLRAnim(3);
				PlaySE(2);
			}
		}
	}
	if (padd & 0x2000) {
		PlaySE(3);
		FadeSetup(2, 6, 0);
		item.step = 8;
		item.cnt = 0;
	}
	if (padd & 0x4000) {
		menu->num = 0;
		item.step = 7;
	}
}
