#include "common.h"

/* declarations recovered from DWARF */
typedef short unsigned int u_short16;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1;
typedef unsigned int u_int32;
struct _anon1 { /* size 0xc */
    u_int32 c;
    short int p[3];
};
typedef struct _anon1 Gu2dV16C;
struct _anon2;
struct _anon2 { /* size 0xa */
    u_short16 u;
    u_short16 v;
    short int p[3];
};
typedef struct _anon2 Gu2dV16T;
struct _anon3;
struct _anon3 { /* size 0x6 */
    short int p[3];
};
typedef struct _anon3 Gu2dV16;
struct _anon4;
struct _anon5;
struct _anon5 { /* size 0xc */
    float p[3];
};
typedef struct _anon5 Gu2dV32;
struct _anon4 { /* size 0x38 */
    Gu2dV32 prim[2];
    float x;
    float y;
    float w;
    float h;
    u_int32 c;
    int tex;
    int pos;
    float move;
};
typedef struct _anon4 DRAWITEM;
struct _anon6;
struct _anon6 { /* size 0x24 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
    int cat;
    int num;
    int ret;
};
typedef struct _anon6 *PMENUDATA;
struct _anon7;
struct _anon7 { /* size 0xc */
    int anim;
    int dir;
    int max;
};
typedef struct _anon7 ITEMLIST;
struct _anon8;
struct _anon8 { /* size 0x8 */
    int flag;
    int cnt;
};
typedef struct _anon8 LR;
struct _anon9;
struct _anon9 { /* size 0x18 */
    int x;
    int y;
    int col;
    int cnt;
    int wait;
    int step;
};
typedef struct _anon9 STAR;

extern PMENUDATA menu;
extern float plane_1[48];
extern float plane_2[48];
extern float plane_3[48];
extern float plane_5[48];
extern float plane_4[48];
extern float plane_6[48];
extern float round2_1[48];
extern float round2_2[48];
extern float round2_3[48];
extern float round2_4[48];
extern float corner2_1[48];
extern float corner2_2[48];
extern float corner2_3[48];
extern float corner2_4[48];
extern float corner1_1[48];
extern float corner1_2[48];
extern float corner1_3[48];
extern float corner1_4[48];
extern float round1_1[48];
extern float round1_2[48];
extern float round1_3[48];
extern float round1_4[48];
extern float round3_1[48];
extern float round3_2[48];
extern float round3_3[48];
extern float round3_4[48];
extern float plane_title_1[48];
extern float plane_title_2[48];
extern float plane_title_3[48];
extern float plane_title_4[48];
extern float plane_title_5[48];
extern float plane_title_6[48];
extern float nurbsplane1[48];
extern float *array_dice[26];
extern unsigned int clut_ref[8];
extern unsigned int pix_ref[512];
extern short unsigned int pix_demo[4096];
extern short unsigned int pix_graphics[4096];
extern short unsigned int pix_mpeg[4096];
extern short unsigned int pix_network[4096];
extern short unsigned int pix_sound[4096];
extern short unsigned int pix_utility[4096];
extern short unsigned int pix_shadow[1024];
extern short unsigned int pix_l[1024];
extern short unsigned int pix_r[1024];
extern unsigned int clut_category[8];
extern unsigned int pix_category[2048];
extern unsigned int *clut_4bit[];
extern unsigned int *clut_8bit;
extern unsigned int *pix_4bit[];
extern unsigned int *pix_8bit;
extern unsigned int *pix_info[];
extern DRAWITEM drawitem[11];
extern ITEMLIST itemlist;
extern LR lr;
extern int table_dice[6];
extern const float table_item[5];
extern const u_int32 itemlist_col[9];
extern STAR star;

void SwapDice(int dir);
int GetDice(void);
void DiceTexture(void);
void DrawDice(float scale);
void DrawShadow(float scale);
void DrawBG(void);
void DrawCategoryString(int mode);
void DrawInfoString(void);
void DrawItemBar(void);
void DrawItemFrame(int xstep, int ystep);
static float _RetItemMove(int pos);
static void _UpdateItemPos(void);
void InitItemList(int max);
int GetItemTex(void);
int GetItemSelect(void);
int SetItemListAnim(int dir);
int DrawItemListOpen(int count);
int DrawItemListAnim(void);
void DrawItemList(void);
void SetItemSelect(int n);
void DrawLR(void);
void DrawSelect(void);
void DrawStar(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuEnable(int state);
void sceGuColor(unsigned int color);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);
int rand(void);


/* SDK prototypes (tools/sdk_protos.h) */
void *memset(void *s, int c, unsigned int n);
void sceGuDisable(int state);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);

void SwapDice(int dir)
{
	int tmp;

	if (dir & 1) {
		tmp = table_dice[2];
		table_dice[2] = table_dice[3];
		table_dice[3] = table_dice[4];
		table_dice[4] = table_dice[1];
		table_dice[1] = tmp;
	}
	if (dir & 2) {
		tmp = table_dice[4];
		table_dice[4] = table_dice[3];
		table_dice[3] = table_dice[2];
		table_dice[2] = table_dice[1];
		table_dice[1] = tmp;
	}
	if (dir & 4) {
		tmp = table_dice[1];
		table_dice[1] = table_dice[5];
		table_dice[5] = table_dice[3];
		table_dice[3] = table_dice[0];
		table_dice[0] = tmp;
	}
	if (dir & 8) {
		tmp = table_dice[3];
		table_dice[3] = table_dice[5];
		table_dice[5] = table_dice[1];
		table_dice[1] = table_dice[0];
		table_dice[0] = tmp;
	}
}

extern const struct tcat6 { int v[6]; } D_0001713C;
int GetDice(void)
{
	struct tcat6 table_cat = D_0001713C;

	return table_cat.v[table_dice[3]];
}

void SetDice(int n) {
    int var_s0;
    int var_s0_2;

    var_s0 = 0;
loop_1:
    SwapDice(4);
    var_s0 += 1;
    if (n != GetDice()) {
        if (var_s0 >= 4) {
            var_s0_2 = 0;
loop_4:
            SwapDice(1);
            var_s0_2 += 1;
            if (n != GetDice()) {
                if (var_s0_2 < 4) {
                    goto loop_4;
                }
            }
        } else {
            goto loop_1;
        }
    }
}

extern const struct ttitle6 { float *v[6]; } D_00017154;
extern const struct ttex6 { u_short16 *v[6]; } D_0001716C;
void DiceTexture(void)
{
	struct ttitle6 table_title = D_00017154;
	struct ttex6 table_tex = D_0001716C;
	int i, n;

	sceGuTexMode(2, 0, 0, 1);
	for (i = 0; i < 6; i++) {
		n = table_dice[i];
		sceGuTexImage(0, 64, 64, 64, table_tex.v[n]);
		sceGumDrawSpline(0x180, 4, 4, 3, 3, NULL, table_title.v[i]);
	}
}

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", table_item);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", itemlist_col);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", D_0001713C);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", D_00017154);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", D_0001716C);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", D_00017184);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", D_00017190);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", D_0001719C);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", D_000171A8);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", D_000171D0);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", D_000171F8);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/draw", D_0001721C);

extern const ScePspFVector3 D_00017184, D_00017190;
void DrawDice(float scale)
{
	ScePspFVector3 vec;
	ScePspFVector3 t;
	int i;

	sceGumPushMatrix();
	t = D_00017184;
	vec = t;
	sceGuLightColor(0, 2, 0xffffffff);
	sceGuLight(0, 0, 2, &vec);
	sceGuEnable(11);
	t = D_00017190;
	vec = t;
	sceGuLightColor(1, 2, 0xffffffff);
	sceGuLight(1, 0, 2, &vec);
	sceGuEnable(12);
	sceGuColor(0xffffffff);
	sceGuEnable(9);
	sceGuClutMode(1, 0, 0xff, 0);
	sceGuClutLoad(1, clut_ref);
	sceGuTexMode(4, 0, 0, 0);
	sceGuTexImage(0, 64, 64, 64, pix_ref);
	sceGuTexFunc(0, 0);
	sceGuTexMapMode(2, 0, 1);
	sceGumPushMatrix();
	t.x = scale;
	t.y = 1.0f;
	t.z = 1.0f;
	vec = t;
	sceGumScale(&vec);
	for (i = 0; i < 26; i++)
		sceGumDrawSpline(0x180, 4, 4, 3, 3, NULL, array_dice[i]);
	sceGuTexFunc(0, 1);
	sceGuTexMapMode(0, 0, 0);
	sceGumPopMatrix();
	sceGumPopMatrix();
}

extern const ScePspFVector3 D_0001719C;
void DrawShadow(float scale)
{
	ScePspFVector3 vec;
	ScePspFVector3 t;

	sceGumPushMatrix();
	t = D_0001719C;
	vec = t;
	sceGumTranslate(&vec);
	t.x = scale * 1.431355f;
	t.y = 1.431355f;
	t.z = 1.431355f;
	vec = t;
	sceGumScale(&vec);
	sceGuColor(0x80FFFFFF);
	sceGuEnable(9);
	sceGuTexMode(2, 0, 0, 1);
	sceGuTexImage(0, 32, 32, 32, pix_shadow);
	sceGumDrawSpline(0x180, 4, 4, 3, 3, NULL, nurbsplane1);
	sceGumPopMatrix();
}

extern Gu2dV16C D_001B57E8[];
void DrawBG(void)
{
	sceGuColor(0xFFFFFFFF);
	sceGuDisable(9);
	sceGumDrawArray(4, 0x80011C, 4, NULL, D_001B57E8);
}

void sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
extern Gu2dV16T D_001B5818[];
extern Gu2dV16 D_001B5840[];
void DrawCategoryString(int mode)
{
	D_001B5818[0].v = menu->cat * 20 + 20;
	D_001B5818[1].v = menu->cat * 20;
	D_001B5818[2].v = menu->cat * 20 + 20;
	D_001B5818[3].v = menu->cat * 20;
	sceKernelDcacheWritebackInvalidateRange(D_001B5818, sizeof(Gu2dV16T) * 4);
	if (mode) {
		D_001B5840[1].p[0] = 0x74;
		D_001B5840[2].p[0] = 0x83;
	} else {
		D_001B5840[1].p[0] = 0xA4;
		D_001B5840[2].p[0] = 0xB3;
	}
	sceKernelDcacheWritebackInvalidateRange(D_001B5840, sizeof(Gu2dV16) * 3);
	sceGuEnable(9);
	sceGuClutMode(1, 0, 0xFF, 0);
	sceGuClutLoad(1, clut_category);
	sceGuTexMode(4, 0, 0, 0);
	sceGuTexImage(0, 128, 128, 128, pix_category);
	sceGuColor(0xFFFFFFFF);
	sceGumDrawArray(4, 0x800102, 4, NULL, D_001B5818);
	sceGuDisable(9);
	sceGuColor(0xFFFFFFFF);
	sceGumDrawArray(2, 0x800100, 3, NULL, D_001B5840);
}

extern Gu2dV16T D_001B5854[];
extern Gu2dV16 D_001B587C[];
extern Gu2dV16 D_001B5890[];
void DrawInfoString(void)
{
	int n;

	n = GetItem(menu->cat, menu->num);
	sceGuEnable(9);
	sceGuTexMode(2, 0, 0, 1);
	sceGuTexImage(0, 256, 64, 144, pix_info[n]);
	sceGuColor(0xFFFFFFFF);
	sceGumDrawArray(4, 0x800102, 4, NULL, D_001B5854);
	sceGuDisable(9);
	sceGuColor(0xFF000000);
	sceGumDrawArray(2, 0x800100, 3, NULL, D_001B587C);
	sceGumDrawArray(2, 0x800100, 2, NULL, D_001B5890);
}

extern Gu2dV16C D_001B589C[];
extern Gu2dV16 D_001B58E4[];
extern Gu2dV16 D_001B58FC[];
void DrawItemBar(void)
{
	sceGuDisable(9);
	sceGumDrawArray(4, 0x80011C, 6, NULL, D_001B589C);
	sceGuColor(0xFF0000D9);
	sceGumDrawArray(4, 0x800100, 4, NULL, D_001B58E4);
	sceGuColor(0xFF515151);
	sceGumDrawArray(2, 0x800100, 5, NULL, D_001B58FC);
}

extern Gu2dV16 D_001B591C[];
extern Gu2dV16 D_001B5934[];
void DrawItemFrame(int xstep, int ystep)
{
	int x, y;

	x = 0x65 - xstep;
	y = 0x39 - ystep;
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (x > 0x65) x = 0x65;
	if (y > 0x39) y = 0x39;
	D_001B591C[0].p[0] = 0xF0 - x;
	D_001B591C[1].p[0] = 0xF0 - x;
	D_001B591C[1].p[1] = 0x5C - y;
	D_001B591C[3].p[1] = 0x5C - y;
	D_001B591C[2].p[0] = 0xF0 + x;
	D_001B591C[0].p[1] = 0x5D + y;
	D_001B591C[2].p[1] = 0x5D + y;
	D_001B591C[3].p[0] = 0xF0 + x;
	D_001B5934[0].p[0] = 0xF0 - x;
	D_001B5934[0].p[1] = 0x5C + y;
	D_001B5934[1].p[0] = 0xF0 - x;
	D_001B5934[1].p[1] = 0x5C - y;
	D_001B5934[2].p[0] = 0xEF + x;
	D_001B5934[3].p[0] = 0xEF + x;
	D_001B5934[2].p[1] = 0x5C - y;
	D_001B5934[3].p[1] = 0x5C + y;
	D_001B5934[4].p[0] = 0xF0 - x;
	D_001B5934[4].p[1] = 0x5C + y;
	sceKernelDcacheWritebackInvalidateRange(D_001B591C, sizeof(Gu2dV16) * 4);
	sceKernelDcacheWritebackInvalidateRange(D_001B5934, sizeof(Gu2dV16) * 5);
	sceGuColor(0xFF656B62);
	sceGumDrawArray(4, 0x800100, 4, NULL, D_001B591C);
	sceGuColor(0xFF000000);
	sceGumDrawArray(2, 0x800100, 5, NULL, D_001B5934);
}

void DrawItemSelect(void) {
    int temp_s0;

    temp_s0 = GetItem(menu->cat, menu->num);
    sceGuEnable(9);
    sceGuClutMode(1U, 0U, 0xFFU, 0U);
    sceGuClutLoad(0x10, (&clut_8bit)[temp_s0]);
    sceGuTexMode(5, 0, 0, 0);
    sceGuTexImage(0, 0x100, 0x80, 0xD0, (&pix_8bit)[temp_s0]);
    sceGuColor(-1U);
    sceGuSpriteMode(0xC8, 0x71, 0xC8, 0x71);
    sceGuDrawSprite(0x8C, 0x24, 0, 0, 0, 0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", _RetItemMove);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", _UpdateItemPos);

void InitItemList(int max)
{
	DRAWITEM *p;
	int i;

	memset(drawitem, 0, sizeof(drawitem));
	itemlist.anim = 0;
	itemlist.dir = 0;
	itemlist.max = 0;
	p = drawitem;
	for (i = 0; i < 11; i++) {
		p->tex = i;
		p->pos = i + 4;
		p->x = 496.0f;
		p->y = 254.0f;
		p->w = 32.0f;
		p->h = 18.0f;
		p->c = -1;
		p->move = 0;
		p++;
	}
	itemlist.max = max;
}

int GetItemTex(void)
{
	int i;

	for (i = 0; i < 13; i++) {
		if (drawitem[i].pos == 4)
			return drawitem[i].tex;
	}
	return -1;
}

int GetItemSelect(void)
{
	int i;

	for (i = 0; i < 13; i++) {
		if (drawitem[i].pos == 4)
			return i;
	}
	return -1;
}

int SetItemListAnim(int dir)
{
	DRAWITEM *p;
	int n;

	p = drawitem;
	if (p->pos == 4 && p->tex == 0 && dir)
		return -1;
	n = GetItemSelect();
	p = &drawitem[n];
	if (p->tex == itemlist.max - 1 && dir == 0)
		return -1;
	itemlist.anim = 0;
	itemlist.dir = dir;
	return 0;
}

void PlaySE(int num);
void DrawSprite(float x, float y, float w, float h, int u, int v);
int GetItem(int cat, int num);
int DrawItemListOpen(int count)
{
	DRAWITEM *p;
	int ret = 0;
	int max;
	int i, n;

	max = 5;
	if (itemlist.max < 5)
		max = itemlist.max;
	if (count == 0) {
		drawitem[0].move = 16.0f;
		PlaySE(2);
	} else if (count == 6) {
		drawitem[1].move = 16.0f;
		PlaySE(2);
	} else if (count == 10) {
		drawitem[2].move = 16.0f;
		PlaySE(2);
	} else if (count == 14) {
		drawitem[3].move = 16.0f;
		PlaySE(2);
	} else if (count == 18) {
		drawitem[4].move = 16.0f;
		PlaySE(2);
	}
	for (i = 0; i < max; i++) {
		p = &drawitem[i];
		p->x -= p->move;
		if (p->move != 0.0f && p->x <= table_item[i]) {
			p->x = table_item[i];
			p->move = 0.0f;
			if (i == max - 1)
				ret = 1;
		}
	}
	sceGuEnable(9);
	for (i = 0; i < max; i++) {
		p = &drawitem[i];
		n = GetItem(menu->cat, p->tex);
		sceGuClutMode(1, 0, 0xff, 0);
		sceGuClutLoad(1, clut_4bit[n]);
		sceGuTexMode(4, 0, 0, 0);
		sceGuTexImage(0, 64, 64, 64, pix_4bit[n]);
		sceGuColor(itemlist_col[p->pos]);
		DrawSprite(p->x - p->w * 0.5f, p->y - p->h * 0.5f, p->w, p->h, 64, 36);
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawItemListAnim);

void DrawSprite(float x, float y, float w, float h, int u, int v);
int GetItem(int cat, int num);
void DrawItemList(void)
{
	DRAWITEM *p;
	int i, n;
	float x, y, w, h, d;

	sceGuEnable(9);
	for (i = 0; i < 11; i++) {
		p = &drawitem[i];
		if (p->pos < 0 || p->pos >= 10)
			continue;
		{
			switch (p->pos) {
			case 3:
				w = 48.0f;
				h = 27.0f;
				d = 9.0f;
				break;
			case 5:
				if (p->x >= 496.0f) {
					w = p->w;
					h = p->h;
					d = 0.0f;
				} else {
					w = 48.0f;
					h = 27.0f;
					d = 9.0f;
				}
				break;
			case 4:
				w = 64.0f;
				h = 36.0f;
				d = 18.0f;
				break;
			default:
				w = p->w;
				h = p->h;
				d = 0.0f;
				break;
			}
			x = p->x - w * 0.5f;
			y = p->y - p->h * 0.5f - d;
			n = GetItem(menu->cat, p->tex);
			sceGuClutMode(1, 0, 0xff, 0);
			sceGuClutLoad(1, clut_4bit[n]);
			sceGuTexMode(4, 0, 0, 0);
			sceGuTexImage(0, 64, 64, 64, pix_4bit[n]);
			sceGuColor(itemlist_col[p->pos]);
			DrawSprite(x, y, w, h, 64, 36);
		}
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", SetItemSelect);

void InitLR(void) {
    lr.flag = 0;
    lr.cnt = 0;
}

void SetLRAnim(int flag) {
    lr.flag = flag;
    lr.cnt = 0;
}

extern Gu2dV16T D_001B5954[];
extern Gu2dV16T D_001B597C[];
void DrawLR(void)
{
	switch (lr.flag) {
	case 1:
		if (lr.cnt == 0) {
			D_001B5954[0].p[0] = -32;
			D_001B5954[1].p[0] = -32;
			D_001B5954[2].p[0] = 0;
			D_001B5954[3].p[0] = 0;
			D_001B597C[0].p[0] = 480;
			D_001B597C[1].p[0] = 480;
			D_001B597C[2].p[0] = 512;
			D_001B597C[3].p[0] = 512;
		} else {
			D_001B5954[0].p[0] = lr.cnt * 4 - 32;
			D_001B5954[1].p[0] = lr.cnt * 4 - 32;
			D_001B5954[2].p[0] = lr.cnt * 4;
			D_001B5954[3].p[0] = lr.cnt * 4;
			D_001B597C[0].p[0] = 480 - lr.cnt * 4;
			D_001B597C[1].p[0] = 480 - lr.cnt * 4;
			D_001B597C[2].p[0] = 512 - lr.cnt * 4;
			D_001B597C[3].p[0] = 512 - lr.cnt * 4;
		}
		sceKernelDcacheWritebackInvalidateRange(D_001B5954, sizeof(Gu2dV16T) * 4);
		sceKernelDcacheWritebackInvalidateRange(D_001B597C, sizeof(Gu2dV16T) * 4);
		if (++lr.cnt >= 9)
			lr.flag = 0;
		break;
	case 2:
		if (lr.cnt == 0) {
			D_001B5954[0].p[0] = 0;
			D_001B5954[1].p[0] = 0;
			D_001B5954[2].p[0] = 32;
			D_001B5954[3].p[0] = 32;
		} else {
			D_001B5954[0].p[0] = lr.cnt * 2;
			D_001B5954[1].p[0] = lr.cnt * 2;
			D_001B5954[2].p[0] = lr.cnt * 2 + 32;
			D_001B5954[3].p[0] = lr.cnt * 2 + 32;
		}
		if (++lr.cnt >= 5) {
			lr.flag = 0;
			D_001B5954[0].p[0] = 0;
			D_001B5954[1].p[0] = 0;
			D_001B5954[2].p[0] = 32;
			D_001B5954[3].p[0] = 32;
		}
		sceKernelDcacheWritebackInvalidateRange(D_001B5954, sizeof(Gu2dV16T) * 4);
		break;
	case 3:
		if (lr.cnt == 0) {
			D_001B597C[0].p[0] = 448;
			D_001B597C[1].p[0] = 448;
			D_001B597C[2].p[0] = 480;
			D_001B597C[3].p[0] = 480;
		} else {
			D_001B597C[0].p[0] = 448 - lr.cnt * 2;
			D_001B597C[1].p[0] = 448 - lr.cnt * 2;
			D_001B597C[2].p[0] = 480 - lr.cnt * 2;
			D_001B597C[3].p[0] = 480 - lr.cnt * 2;
		}
		if (++lr.cnt >= 5) {
			D_001B597C[0].p[0] = 448;
			D_001B597C[1].p[0] = 448;
			lr.flag = 0;
			D_001B597C[2].p[0] = 480;
			D_001B597C[3].p[0] = 480;
		}
		sceKernelDcacheWritebackInvalidateRange(D_001B597C, sizeof(Gu2dV16T) * 4);
		break;
	}
	sceGuEnable(9);
	sceGuTexMode(2, 0, 0, 1);
	sceGuTexImage(0, 32, 32, 32, pix_l);
	sceGuColor(0xffffffff);
	sceGumDrawArray(4, 0x800102, 4, NULL, D_001B5954);
	sceGuTexMode(2, 0, 0, 1);
	sceGuTexImage(0, 32, 32, 32, pix_r);
	sceGuColor(0xffffffff);
	sceGumDrawArray(4, 0x800102, 4, NULL, D_001B597C);
}

extern Gu2dV16 D_001B59A4[];
void DrawSelect(void)
{
	sceGuDisable(9);
	sceGuColor(0xFF00FFFF);
	sceGumDrawArray(2, 0x800100, 5, NULL, D_001B59A4);
}

extern const struct pstar6 { Gu2dV16 v[6]; } D_000171F8;
extern const struct col8 { u_int32 v[8]; } D_0001721C;
extern Gu2dV16 D_002D87C8[6];
int rand(void);
void DrawStar(void)
{
	const struct pstar6 primstar = D_000171F8;
	struct col8 col = D_0001721C;
	int i;

	for (i = 0; i < 6; i++) {
		D_002D87C8[i].p[0] = star.x + primstar.v[i].p[0] - 3;
		D_002D87C8[i].p[1] = star.y + primstar.v[i].p[1] - 3;
		D_002D87C8[i].p[2] = primstar.v[i].p[2];
	}
	sceKernelDcacheWritebackInvalidateRange(D_002D87C8, sizeof(Gu2dV16) * 6);
	sceGuDisable(9);
	sceGuColor(col.v[star.col % 8]);
	sceGumDrawArray(1, 0x800100, 6, NULL, D_002D87C8);
	star.col++;
	switch (star.step) {
	case 0:
		if (++star.cnt > star.wait)
			star.step = 1;
		break;
	case 1:
		star.x -= 3;
		if (star.x < 255) {
			star.x = 255;
			star.step = 2;
		}
		break;
	case 2:
		star.x--;
		star.y++;
		if (star.y >= 233) {
			star.y = 217;
			star.x = 481;
			star.cnt = 0;
			star.wait = rand() % 60 + 30;
			star.step = 0;
		}
		break;
	}
}

void InitStar(void) {
    star.y = 0xD9;
    star.x = 0x1E1;
    star.col = 0;
    star.cnt = 0;
    star.wait = 0;
    star.step = 0;
    star.wait = (rand() % 60) + 0x1E;
}
