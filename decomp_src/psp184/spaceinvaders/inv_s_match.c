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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_continue_main);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", BoxAtari_k4m);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", SprMoveEnemySub);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", SprMoveEnemy);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_enemyshort);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_winlose_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_ufodispjudge);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_ufodisp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_uforeverse);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CD58);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CD98);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_rankjudge);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_reinforce);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_reinforce_alloc);

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
