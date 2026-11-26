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

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/item", DrawItem2D);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/item", DrawItem);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/item", D_000170D0);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/item", RunItem);

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
