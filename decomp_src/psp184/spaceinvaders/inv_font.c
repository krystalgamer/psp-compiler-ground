/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
extern int alpha_mode_29C3FC;
extern int font_max;
extern unsigned char inv_font;
extern unsigned char p_2903F4;
extern int pri;
extern int texture_no_29C3F8;


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void inv_font_all_init(void) {
    memset(&inv_font, 0, 0x5000U);
    memset(&p_2903F4, 0, 0xC000U);
    pri = 0x2710;
    texture_no_29C3F8 = -1;
    alpha_mode_29C3FC = 3;
    font_max = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_font_tex_set(int arg0, int arg1) {
    texture_no_29C3F8 = arg0;
    alpha_mode_29C3FC = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_font_pri_set(int arg0) {
    pri = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_font_pri_get(void) {
    return pri;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_ascii);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_ascii_w);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_ascii_no);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_etc);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_ascii_check_w);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_etc_check_w);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_ascii_posf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_etc_posf);
