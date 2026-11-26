/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK ASC_SetStringRGBA(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
int pad_cansel_button();                            /* extern */
int pad_ret_button();                               /* extern */
M2C_UNK se_start(M2C_UNK);                          /* extern */
extern unsigned char D_0007CCD8;
extern int RT;
extern int Anm;
extern int gcnt_28FC04;


extern int inv;

typedef struct { u8 *spr; int f4; int f8; int fC; int f10; int f14; int f18; int f1C; } INV_W;
extern int ufocnt_28FBC8;
extern int ufocntmax;
extern int ufodisp;
int hato(int cur, int target, int shift);
unsigned long genrand_int32(void);

extern int *screensrc;
extern u8 D_00080F88[];
int VramAtariSub(s8 *buf, int x, int y, int w);
void spr_boxmask(void *mask, int tex, int x, int y, int w, int h, int mw, int mh);

typedef struct { int *p; int f4[7]; } INV_T;
extern INV_T invt[] __asm__("inv");
extern int enemove_c_1p_max;
extern int enemove_c_2p_max;

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_main);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_init);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_matchup_demo(void) {
    int temp_s0;
    int temp_s1;

    ASC_SetStringRGBA(2, &D_0007CCD8, 0xBC, 0xC8, 0x40, 0xFF, 0xFF, 0xFF);
    temp_s1 = pad_sw();
    temp_s0 = pad_ret_button();
    if (temp_s1 & (temp_s0 | pad_cansel_button())) {
        se_start(1);
        RT = 9;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_matchup_start(void) {
    RT = 3;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_startdemo);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_handycap);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_startdemo2);

void inv_matchup_continue_main(void)
{
	int i;
	INV_W *w = (INV_W *)&inv;
	u8 *p;

	for (i = 0; i < 48; i++, w++) {
		p = w->spr;
		if (p) {
			if (w->f4 == 1)
				*(int *)(p + 0x78) = hato(*(int *)(p + 0x78), 270, 2);
			else if (w->f4 == 2)
				*(int *)(p + 0x78) = hato(*(int *)(p + 0x78), 90, 2);
		}
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_continue_cont);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_zankidisp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_continue);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_matchup_winlose(void) {
    RT = 8;
    gcnt_28FC04 = 0;
    Anm = 0;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CCD8);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_result);

void inv_matchup_fade(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_menu_start);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CD18);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CD20);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_menu_pause);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_menu_option);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_menu_handy);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", BoxAtari_ek4m);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", BoxAtari_e4m);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", BoxAtari_ez4m);

extern int *screensrc;
extern u8 D_00080F88[];
int VramAtariSub(s8 *buf, int x, int y, int w);
void spr_boxmask(void *mask, int tex, int x, int y, int w, int h, int mw, int mh);
int BoxAtari_k4m(int a0, int a1, int x, int y)
{
	if (VramAtariSub((s8 *)screensrc[7], x + 4, y + 4, 0x200) == 0)
		return 0;
	spr_boxmask(D_00080F88, screensrc[7], x, y, 8, 8, 0x200, 0x200);
	return 1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", BoxAtari_z4m);

extern int inv;
static int SprMoveEnemyChk(int a, int b)
{
	int i;
	int *p = &inv;

	for (i = 0; i < 48; i++) {
		if (p[0] != 0 && (unsigned)(*(int *)(p[0] + 0x10) - 5) < 2) {
			if (p[4] == b && p[3] == a)
				return 0;
		}
		p += 8;
	}
	return 1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", SprMoveEnemyNomal);

void SprMoveEnemySub(void)
{
	int i;
	int *s;

	for (i = 0; i < 48; i++) {
		s = invt[i].p;
		if (s && (s[3] & 2) && (s[4] == 5 || s[4] == 6)) {
			s[10] = hato(s[10], invt[i].f4[2] * 8, 2);
			s = invt[i].p;
			s[11] = hato(s[11], invt[i].f4[3] * 2, 2);
		}
	}
}

void SprMoveEnemySub(void);
int SprMoveEnemy(void)
{
	int i, f = 0;
	INV_W *w;

	SprMoveEnemySub();
	for (i = 0, w = (INV_W *)&inv; i < 48; i++, w++) {
		if (w->spr) {
			switch (*(int *)(w->spr + 0x10)) {
			case 5:
				if (w->fC < 3)
					f |= 1;
				else if (w->fC >= 57)
					f |= 2;
				break;
			case 6:
				if (w->fC >= 57)
					f |= 2;
				else if (w->fC < 3)
					f |= 1;
				break;
			}
		}
	}
	if (f == 3)
		return 2;
	if (f == 1)
		return 0;
	if (f == 2)
		return 1;
	return 3;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_enemyshort);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_winlose_set);

static void matchup_inv_ufodispjudge(void)
{
	int t;

	ufodisp = 0;
	ufocnt_28FBC8++;
	if (ufocnt_28FBC8 > ufocntmax) {
		t = genrand_int32() % 15 + 25;
		ufocnt_28FBC8 = 0;
		ufocntmax = t * 60;
		ufodisp = 1;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_ufodisp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_uforeverse);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CD58);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CD98);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_rankjudge);

int matchup_inv_reinforce(int pl)
{
	int i;
	int ret = 0;
	int *s;

	for (i = 0; i < 48; i++) {
		s = invt[i].p;
		if (s && (s[3] & 2) && s[4] == pl) {
			if (pl == 5) {
				if (invt[i].f4[2] < 0x18)
					ret = 1;
			} else if (pl == 6) {
				if (invt[i].f4[2] >= 0x23)
					ret = 1;
			}
		}
	}
	return ret == 0;
}

extern INV_T invt[] __asm__("inv");
extern int enemove_c_1p_max;
extern int enemove_c_2p_max;
void matchup_inv_reinforce_alloc(int pl)
{
	int i;
	int start = 0;
	int *s;

	if (pl == 5) {
		if (enemove_c_1p_max >= 0x18)
			return;
		enemove_c_1p_max += 8;
		start = 0x10;
	} else if (pl == 6) {
		if (enemove_c_2p_max >= 0x30)
			return;
		enemove_c_2p_max += 8;
		start = 0x28;
	}
	for (i = start; i < start + 8; i++) {
		s = invt[i].p;
		if (s) {
			s[3] |= 0xA;
			s[26] = s[10];
			s[27] = s[11];
		}
	}
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE04);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE08);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE0C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE10);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE14);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE18);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE1C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE20);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE24);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE28);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE2C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE30);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE34);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE38);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE3C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE40);
