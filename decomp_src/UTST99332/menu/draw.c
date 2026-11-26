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
extern unsigned int *clut_4bit;
extern unsigned int *clut_8bit;
extern unsigned int *pix_4bit;
extern unsigned int *pix_8bit;
extern unsigned int *pix_info;
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

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", SwapDice);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", GetDice);

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

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DiceTexture);

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

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawDice);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawShadow);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawBG);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawCategoryString);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawInfoString);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawItemBar);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawItemFrame);

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

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", InitItemList);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", GetItemTex);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", GetItemSelect);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", SetItemListAnim);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawItemListOpen);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawItemListAnim);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawItemList);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", SetItemSelect);

void InitLR(void) {
    lr.flag = 0;
    lr.cnt = 0;
}

void SetLRAnim(int flag) {
    lr.flag = flag;
    lr.cnt = 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawLR);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawSelect);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/draw", DrawStar);

void InitStar(void) {
    star.y = 0xD9;
    star.x = 0x1E1;
    star.col = 0;
    star.cnt = 0;
    star.wait = 0;
    star.step = 0;
    star.wait = (rand() % 60) + 0x1E;
}
