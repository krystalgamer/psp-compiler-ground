/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sound_relece();                             /* extern */
M2C_UNK sound_stop();                               /* extern */
extern int soundflg;
extern int option_return;
extern int ret;
extern int se_tmp;


INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_sound_load);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_classic_sound_free(void) {
    if (soundflg != 0) {
        sound_stop();
        sound_relece();
        soundflg = 0;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_classic_soundflg_init(void) {
    soundflg = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_sound_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_musicdisp_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_menu_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_menu);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_hiscoreinit);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_hiscore);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_classic_optioninit(int arg0) {
    option_return = arg0;
    ret = 0;
    se_tmp = 0;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007C9D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007C9D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007C9E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007C9E8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007C9F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA00);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA0C);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_option_sub);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_option_pause);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_option);

void inv_classic_menu_free(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_music_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_name_entry_init);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA20);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA30);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA38);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA40);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA48);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA50);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA5C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA68);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA70);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA74);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA78);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA7C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA80);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA88);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA90);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CAAC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CAC8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CADC);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_name_entry);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CB68);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CB78);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CB88);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CB98);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBA8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBB8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBC8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBD8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBE8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBF8);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_name_entry2);
