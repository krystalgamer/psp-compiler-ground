/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK psp_loopstart();                            /* extern */
M2C_UNK psp_loopend();                              /* extern */
M2C_UNK classic_inv_init_pos_sub(M2C_UNK);          /* extern */
extern int gcnt_28F36C;
M2C_UNK spr_trans(int, int, int, int, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
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
void classic_inv_expsys_setsub(int a, int b, int c, int d, int e, int f, int g);
#define MAX(a, b) ((a) > (b) ? (a) : (b))

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", nickname_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_game_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_game_stageinit);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", D_0007C028);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", main_classicinv);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", HiScoreSort);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", ScoreAddInit);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", ScoreAddDisp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", ScoreAdd);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", BoxAtari_z);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", BoxAtari_e);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", VramAtariSub);

int VramAtari(signed char *vram, int x, int y)
{
	return VramAtariSub(vram, x, y, 256);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMoveTamaSub);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMoveTamaSub2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMoveTama);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMove);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMoveHitWait);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", SprMoveHitWait2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_tamainit);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_tamainit2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_tamafree);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_init_pos_sub);

#ifndef NULL
#define NULL ((void *)0)
#endif

void classic_inv_init_pos(void) {
    classic_inv_init_pos_sub(0);
    classic_inv_init_pos_sub(1);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_ready);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_movechk);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_shotsub);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_shot);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_demo_moji);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_demo2_moji2);

void classic_inv_demo2_moji(void)
{
	if (demotype == 0)
		classic_inv_demo2_moji2(0);
	else if (demotype == 1)
		classic_inv_demo2_moji2(1);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", inv_classic_fade);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_expsys_setsub);

void classic_inv_expsys_set(int a, int b, int c, int d, int e, int f)
{
	classic_inv_expsys_setsub(a, b, c, d, e, f, 0);
}

void classic_inv_expsys_set_enemy(int a, int b, int c, int d, int e, int f)
{
	classic_inv_expsys_setsub(a, b, c, d, e, f, 1);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_shima", classic_inv_expsys);

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
