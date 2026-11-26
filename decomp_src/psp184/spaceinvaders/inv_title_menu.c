/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK inv_logo();                                 /* extern */
M2C_UNK inv_title_init();                           /* extern */
M2C_UNK inv_title_memcheck();                       /* extern */
M2C_UNK inv_title_roop();                           /* extern */
extern int D_003491E4;
extern unsigned char D_00349218;
extern int D_00349230;
extern int D_00349234;


#ifndef NULL
#define NULL ((void *)0)
#endif

extern int title_main;
extern int D_00349230;
extern int D_00349268;

int inv_title_main(void) {
    inv_title_memcheck();
    inv_logo();
    inv_title_init();
    inv_title_roop();
    inv_title_free();
    return D_003491E4;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", inv_title_memcheck);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", inv_logo);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", inv_title_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", inv_title_roop);

extern int title_main;
extern int D_00349230;
extern int D_00349268;
M2C_UNK inv_title_free(void)
{
	u8 *t = (u8 *)&title_main;

	bmp_file_unload(*(int *)(t + 0x40));
	bmp_file_unload(*(int *)(t + 0x3C));
	bmp_file_unload(*(int *)(t + 0x38));
	bmp_file_unload(*(int *)(t + 0x34));
	bmp_file_unload(*(int *)(t + 0x30));
	bmp_file_unload(*(int *)(t + 0x2C));
	bmp_file_unload(*(int *)(t + 0x28));
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_main_control);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_main_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_main_select);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EA60);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EA68);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EA74);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EA80);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EAD0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EAD4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EAD8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EB20);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EB28);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EB34);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_main_return);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_init);

#ifndef NULL
#define NULL ((void *)0)
#endif

void title_start(void) {
    M2C_FIELD(&D_00349218, int *, 0) = 1;
    M2C_FIELD(&D_00349218, int *, 4) = 0;
}

M2C_UNK title_start_check(void)
{
	int *p = (int *)&D_00349218;

	p[1]++;
	if (p[1] < 0)
		p[1] = 0;
	else if (p[1] > 90)
		p[1] = 90;
	return p[1] == 90;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_control);

#ifndef NULL
#define NULL ((void *)0)
#endif

void select_init(void) {
    D_00349230 = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", select_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", select_start_check);

#ifndef NULL
#define NULL ((void *)0)
#endif

void select_set(int arg0) {
    D_00349234 = arg0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", select_control);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", game_cnt_option_555B8);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", game_cnt_help);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", game_cnt_hiscore_5710C);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_bg_star_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_bg_star_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_bg_star_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", game_bg_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", game_bg_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", game_bg_end);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", game_bg_disp);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EC00);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EC04);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EC08);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EC0C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EC10);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EC14);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EC18);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EC1C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EC20);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", D_0007EC24);
