/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int alpha_mode_348800;
extern int texture_no_3487FC;
extern int alpha_mode2;
extern int texture_no2;
extern int e_pri;
extern int d_pri;


void *memset(void *s, int c, unsigned int n);
extern unsigned char inv_screfc, p_3307FC, inv_scrdisp, p2;
extern int e_co, d_co;
void inv_screffect_all_init(void)
{
	memset(&inv_screfc, 0, 0x7000);
	memset(&p_3307FC, 0, 0xC000);
	memset(&inv_scrdisp, 0, 0x7000);
	memset(&p2, 0, 0xC000);
	alpha_mode_348800 = 2;
	texture_no_3487FC = -1;
	texture_no2 = -1;
	alpha_mode2 = 3;
	d_pri = 500;
	e_co = 0;
	d_co = 0;
	e_pri = 0;
}

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
