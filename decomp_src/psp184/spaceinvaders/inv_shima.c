/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK psp_loopstart();                            /* extern */
M2C_UNK psp_loopend();                              /* extern */
M2C_UNK classic_inv_init_pos_sub(M2C_UNK);          /* extern */
extern int gcnt_28F36C;
void spr_trans(int, int, int, int, int, int, int, int);
extern void *D_0028F38C;
extern void *ptexsrc_28F380;
extern unsigned char sexp;


#ifndef NULL
#define NULL ((void *)0)
#endif

extern int scoredisp[5];
extern int *ptexdis1[];
extern int demotype;
void spr_boxfill(int tex, int x, int y, int w, int h, int col);
void classic_inv_demo2_moji2(int type);
#define MAX(a, b) ((a) > (b) ? (a) : (b))

extern int nowplay;
extern int screen_sw;
extern int *ptexdis2[];
extern int wwx, wwy, wwh, www;
void classic_inv_shotsub(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);

typedef struct { int f0; int f4; int f8; int fC; int f10; int f14; int f18; int f1C; } SEXP_T;
typedef struct { int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44; } SPR_T;
extern SPR_T *spr[];
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SPR_NEXT(s) (*(SPR_T **)((u8 *)(s) + 0x94))
SPR_T *SprHeadGet(void);

extern int classic_fade_x;
extern int D_0039AED0;
void poly_set(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
	int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7,
	int s8, int s9, int s10, int s11, int s12, int s13, int s14, int s15, int s16);

void psp_xstart(void) {
    psp_loopstart();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void psp_xend(void) {
    ASC_Reset();
    psp_loopend();
}

typedef struct { int f0, f4, f8, fC; void *f10; } TAMA;
extern TAMA ztama[], etama[];

void SprFree(void *p);

char *GetMessageNickName(void);
int strlen(const char *s);
char *strcat(char *d, const char *s);
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
extern char D_005FB7D4[][9];
void nickname_set(int no)
{
	if (strlen(GetMessageNickName()) < 8) {
		memcpy(D_005FB7D4[no], GetMessageNickName(), 8);
	} else {
		memset(D_005FB7D4[no], 0, 9);
		memcpy(D_005FB7D4[no], GetMessageNickName(), 5);
		strcat(D_005FB7D4[no], "...");
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_game_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_game_stageinit);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", main_classicinv);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", HiScoreSort);

void ScoreAddInit(int a, int b, int c, int d)
{
	u8 *s = (u8 *)&scoredisp;


	*(int *)(s + 0x0) = 1;
	*(int *)(s + 0x4) = d;
	*(int *)(s + 0x10) = c;
	*(int *)(s + 0x8) = a;
	*(int *)(s + 0xC) = b;
	
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", ScoreAddDisp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", ScoreAdd);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", BoxAtari_z);

void ScoreAdd(SPR_T *s);
extern int rt;
int BoxAtari_e(int side, int x, int y, int w, int h)
{
	SPR_T *s;
	int d1, d2, d3, d4;

	for (s = SprHeadGet(); s != NULL; s = SPR_NEXT(s)) {
		if (s->fc != 0 && s->f14 == side) {
		if (s->f10 >= 1 && s->f10 <= 6) {
			d1 = ABS(s->f28 - x);
			d2 = ABS(s->f2c - y);
			d3 = ABS(s->f28 + s->f40 - (x + w));
			d4 = ABS(s->f2c + s->f44 - (y + h));
			if (d1 < s->f40 && d2 < s->f44 && d3 < s->f40 && d4 < s->f44) {
				ScoreAdd(s);
				if (s->f14 == 0) {
					rt = 24;
					s->f14 = 4;
				} else if (s->f14 == 1) {
					rt = 24;
					s->f14 = 5;
				}
				return 1;
			}
		}
		}
	}
	return 0;
}

int VramAtariSub(s8 *buf, int x, int y, int w)
{
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	return *(buf + x + y * w);
}

int VramAtari(signed char *vram, int x, int y)
{
	return VramAtariSub(vram, x, y, 256);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMoveTamaSub);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMoveTamaSub2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMoveTama);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMove);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMoveHitWait);

static void SprMoveHitWait2(int x)
{
	int tex;

	if (nowplay == 0)
		tex = ptexdis1[screen_sw][7];
	else
		tex = ptexdis2[screen_sw][7];
	if (x == 1)
		spr_boxfill(tex, wwx, wwy, wwh, www, 0);
}

void classic_inv_tamainit(void)
{
	ztama[0].f0 = 0;
	ztama[0].f10 = 0;
	ztama[1].f10 = 0;
	ztama[1].f0 = 0;
	etama[0].f0 = 0;
	etama[0].f10 = 0;
	etama[0].fC = -1;
	etama[1].f10 = 0;
	etama[1].f0 = 0;
	etama[1].fC = -1;
	etama[2].f10 = 0;
	etama[2].f0 = 0;
	etama[2].fC = -1;
	etama[3].f10 = 0;
	etama[3].f0 = 0;
	etama[3].fC = -1;
	etama[4].f10 = 0;
	etama[4].f0 = 0;
	etama[4].fC = -1;
	etama[5].f10 = 0;
	etama[5].f0 = 0;
	etama[5].fC = -1;
}

void classic_inv_tamainit2(void)
{
	if (ztama[0].f10)
		SprFree(ztama[0].f10);
	ztama[0].f0 = 0;
	ztama[0].f10 = 0;
	if (ztama[1].f10)
		SprFree(ztama[1].f10);
	ztama[1].f0 = 0;
	ztama[1].f10 = 0;
	if (etama[0].f10)
		SprFree(etama[0].f10);
	etama[0].f0 = 0;
	etama[0].f10 = 0;
	etama[0].fC = -1;
	if (etama[1].f10)
		SprFree(etama[1].f10);
	etama[1].f10 = 0;
	etama[1].f0 = 0;
	etama[1].fC = -1;
	if (etama[2].f10)
		SprFree(etama[2].f10);
	etama[2].f10 = 0;
	etama[2].f0 = 0;
	etama[2].fC = -1;
	if (etama[3].f10)
		SprFree(etama[3].f10);
	etama[3].f10 = 0;
	etama[3].f0 = 0;
	etama[3].fC = -1;
	if (etama[4].f10)
		SprFree(etama[4].f10);
	etama[4].f10 = 0;
	etama[4].f0 = 0;
	etama[4].fC = -1;
	if (etama[5].f10)
		SprFree(etama[5].f10);
	etama[5].f10 = 0;
	etama[5].f0 = 0;
	etama[5].fC = -1;
}

typedef struct { u8 pad[0x30]; int x, y; u8 pad2[0x50 - 0x38]; int ox, oy, w, h; } SPRBOX_T;
void classic_inv_tamafree(int tex)
{
	int i;
	SPRBOX_T *p;

	if (ztama[0].f10) {
		p = ztama[0].f10;
		spr_boxfill(tex, p->x + p->ox, p->y + p->oy, p->w, p->h, 0);
		SprFree(ztama[0].f10);
		ztama[0].f0 = 0;
		ztama[0].f10 = 0;
	}
	if (ztama[1].f10) {
		p = ztama[1].f10;
		spr_boxfill(tex, p->x + p->ox, p->y + p->oy, p->w, p->h, 0);
		SprFree(ztama[1].f10);
		ztama[1].f10 = 0;
		ztama[1].f0 = 0;
	}
	for (i = 0; i < 3; i++) {
		if (etama[i].f10) {
			p = etama[i].f10;
			spr_boxfill(tex, p->x + p->ox, p->y + p->oy, p->w, p->h, 0);
			SprFree(etama[i].f10);
			etama[i].f10 = 0;
			etama[i].f0 = 0;
			etama[i].fC = -1;
		}
	}
	for (i = 0; i < 3; i++) {
		if (etama[i + 3].f10) {
			p = etama[i + 3].f10;
			spr_boxfill(tex, p->x + p->ox, p->y + p->oy, p->w, p->h, 0);
			SprFree(etama[i + 3].f10);
			etama[i + 3].f10 = 0;
			etama[i + 3].f0 = 0;
			etama[i + 3].fC = -1;
		}
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_init_pos_sub);

#ifndef NULL
#define NULL ((void *)0)
#endif

void classic_inv_init_pos(void) {
    classic_inv_init_pos_sub(0);
    classic_inv_init_pos_sub(1);
}

extern int enemove_c_1p, enemove_c_2p;
int classic_inv_ready(void)
{
	int ret = 0;

	if (gcnt_28F36C >= 7) {
		if (nowplay == 0) {
			spr[enemove_c_1p]->f14 = 0;
			spr[enemove_c_1p]->f30++;
			enemove_c_1p--;
			if (enemove_c_1p <= 0) {
				ret = 1;
				enemove_c_1p = 55;
			}
		} else {
			spr[enemove_c_2p]->f14 = 1;
			spr[enemove_c_2p]->f30++;
			enemove_c_2p--;
			if (enemove_c_2p < 62) {
				enemove_c_2p = 116;
				ret = 1;
			}
		}
	}
	return ret;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C05C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C060);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C080);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C08C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C098);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C0A4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C0B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C0BC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C0D4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C0D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C0DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C0E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C0EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C0F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C100);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C10C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C110);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C11C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C12C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C13C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C14C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C15C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C170);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C184);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C198);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C1AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C1C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C1D4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C1E8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C224);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C250);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C264);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C278);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C28C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C2A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C2B4);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_score);

extern int enemove_v_1p, enemove_v_2p;
int classic_inv_movechk(int start, int end)
{
	int i, side = 0, sub = 0, ret = 0;
	SPR_T *s;

	if (start == 1)
		sub = enemove_v_1p & 15;
	else if (start == 62) {
		side = 1;
		sub = enemove_v_2p & 15;
	}
	for (i = start; i < end; i++) {
		s = spr[i];
		if (s->f14 != side)
			continue;
		if (s->f2c + s->f44 >= 208) {
			ret = 3;
			continue;
		}
		if (sub == 0) {
			if (s->f28 + s->f40 >= 216) {
				if (ret != 3)
					ret = 1;
			}
		} else if (sub == 1) {
			if (s->f28 < 9) {
				if (ret != 3)
					ret = 2;
			}
		}
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_shotsub);

extern int nowplay;
extern int screen_sw;
extern int *ptexdis2[];
extern int wwx, wwy, wwh, www;
void classic_inv_shotsub(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
void classic_inv_shot(int a, int b, int d, int e, int f, int g, int h, int i, int j)
{
	classic_inv_shotsub(a, b, 9, d, e, f, g, h, i, j);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_eshot);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_main);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_draw);

#ifndef NULL
#define NULL ((void *)0)
#endif
int classic_inv_enemy_chk(int arg0) {
    int temp_v0;
    int var_a0;
    int var_v1;

    temp_v0 = SprHeadGet();
    var_v1 = temp_v0;
    var_a0 = 0;
    if (temp_v0 != 0) {
        do {
            if (M2C_FIELD(var_v1, int *, 0xC) != 0) {
                if (M2C_FIELD(var_v1, int *, 0x14) == arg0) {
                    var_a0 += (unsigned int) (M2C_FIELD(var_v1, int *, 0x10) - 1) < 5U;
                }
            }
            var_v1 = M2C_FIELD(var_v1, int *, 0x94);
        } while (var_v1 != 0);
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_enemyshot);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C34C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C38C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C3CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C3D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C3E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C3EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C3FC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C414);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C418);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C420);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C428);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C430);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C438);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C444);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C450);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C45C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C460);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C464);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C46C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C474);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C47C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C488);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C494);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4A4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4E8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C4FC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C504);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C510);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C51C);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_demo_mojisub);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C548);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_demo_mojisub2);

void classic_inv_demo_mojisub(void);
void classic_inv_demo_mojisub2(void);
void classic_inv_demo_moji(void)
{
	if (demotype == 0)
		classic_inv_demo_mojisub();
	else if (demotype == 1)
		classic_inv_demo_mojisub2();
	spr_trans(((int *)ptexsrc_28F380)[7], ptexdis1[screen_sw][7], 62, 128, 0, 56, 16, 8);
	spr_trans(((int *)ptexsrc_28F380)[7], ptexdis1[screen_sw][7], 66, 144, 0, 0, 8, 8);
	spr_trans(((int *)ptexsrc_28F380)[7], ptexdis1[screen_sw][7], 62, 160, 0, 24, 16, 8);
	spr_trans(((int *)ptexsrc_28F380)[7], ptexdis1[screen_sw][7], 62, 176, 32, 8, 16, 8);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_demo2_moji2);

void classic_inv_demo2_moji(void)
{
	if (demotype == 0)
		classic_inv_demo2_moji2(0);
	else if (demotype == 1)
		classic_inv_demo2_moji2(1);
}

int inv_classic_fade(void)
{
	classic_fade_x += 8;
	if (classic_fade_x > 480) {
		classic_fade_x = 480;
		return 1;
	}
	poly_set(D_0039AED0, 8, classic_fade_x, 0x100, 0, 0, 0, 0,
		0x80, 0, 0, 0, 0x80, 0, 0, 0, 0x80, 0, 0, 0, 0x80, 0xFF, 2, 0, 0xFF);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_classic_gcntget(void) {
    return gcnt_28F36C;
}

void classic_inv_screen_clr(int no, int x, int y, int w, int h)
{
	spr_boxfill(ptexdis1[no][7], x, y, w, h, 0);
}

void classic_inv_screen_allclr(int no)
{
	classic_inv_screen_clr(no, 0, 0, 256, 256);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void classic_inv_name_entry_cur(int arg0, int arg1) {
    spr_trans(M2C_FIELD(ptexsrc_28F380, int *, 0x1C), M2C_FIELD(D_0028F38C, int *, 0x1C), arg0, arg1, 0xB8, 0x28, 8, 8);
}

void classic_inv_name_entry_cur_erase(int x, int y)
{
	spr_boxfill(((int *)D_0028F38C)[7], x, y, 8, 8, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void classic_inv_expsys_init(void) {
    memset(&sexp, 0, 0x140U);
}

void classic_inv_expsys_setsub(int a, int b, int c, int d, int e, int f, int g)
{
	int i;
	SEXP_T *p = (SEXP_T *)&sexp;

	for (i = 0; i < 10; i++, p++) {
		if (p->f0 == 0) {
			if (nowplay == 0)
				p->f4 = ptexdis1[0][7];
			else
				p->f4 = ptexdis2[0][7];
			p->f8 = g;
			p->f0 = f;
			p->fC = a;
			p->f10 = b;
			p->f14 = c;
			p->f18 = d;
			p->f1C = e;
			return;
		}
	}
}

void classic_inv_expsys_set(int a, int b, int c, int d, int e, int f)
{
	classic_inv_expsys_setsub(a, b, c, d, e, f, 0);
}

void classic_inv_expsys_set_enemy(int a, int b, int c, int d, int e, int f)
{
	classic_inv_expsys_setsub(a, b, c, d, e, f, 1);
}

extern int *maskbuf;
void spr_boxmask(int tex, int x, int y, int w, int a, int b, int c, int d);
void classic_inv_expsys(void)
{
	int i;
	SEXP_T *p = (SEXP_T *)&sexp;

	for (i = 0; i < 10; i++, p++) {
		if (p->f0 != 0) {
			if (p->f1C) {
				p->f1C--;
			} else {
				switch (p->f0) {
				case 1:
					spr_boxfill(p->f4, p->fC, p->f10, p->f14, p->f18, 0);
					p->f0 = 0;
					break;
				case 2:
					spr_boxmask(maskbuf[7], p->f4, p->fC, p->f10, 16, 16, 256, 256);
					p->f0 = 0;
					break;
				default:
					p->f0 = 0;
					break;
				}
			}
		}
	}
}

int classic_inv_expsys_chksub(int no)
{
	int i;
	int *p = (int *)&sexp;

	for (i = 0; i < 10; i++) {
		if (p[0] != 0 && p[2] == no)
			return 0;
		p += 8;
	}
	return 1;
}
