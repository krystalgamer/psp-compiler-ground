#include "common.h"
#include "m2c_macros.h"
extern int alpha_mode_348800;
extern int texture_no_3487FC;
extern int alpha_mode2;
extern int texture_no2;
extern int e_pri;
extern int d_pri;


INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_scr_effect", inv_screffect_all_init);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_screffect_tex_set(int arg0, int arg1) {
    texture_no_3487FC = arg0;
    alpha_mode_348800 = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_scrdisp_tex_set(int arg0, int arg1) {
    texture_no2 = arg0;
    alpha_mode2 = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_screffect_pri_set(int arg0) {
    e_pri = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_screffect_pri_get(void) {
    return e_pri;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_scrdisp_pri_set(int arg0) {
    d_pri = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_scrdisp_pri_get(void) {
    return d_pri;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_scr_effect", inv_screffect_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_scr_effect", inv_screffect_start2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_scr_effect", inv_scrdisp_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_scr_effect", inv_screffect_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_scr_effect", inv_scrdisp_disp);
