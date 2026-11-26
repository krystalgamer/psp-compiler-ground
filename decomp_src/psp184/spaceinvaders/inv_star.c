/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int inv_bg;


typedef struct { int disp, f4, no, fc, f10, f14, f18, f1c, f20; } INV_BG;
typedef struct __attribute__((packed)) { float f[10]; } P_BG;
extern P_BG p_bg;
void inv_star_init(void)
{
	INV_BG *b = (INV_BG *)&inv_bg;

	b->f4 = 0;
	b->disp = 0;
	b->fc = 0;
	b->f10 = 0;
	b->f14 = 0;
	b->f18 = 0;
	b->f1c = 0;
	b->f20 = 0;
	p_bg.f[0] = 0;
	b->no = -1;
	p_bg.f[1] = 0;
	p_bg.f[5] = 1.0f;
	p_bg.f[6] = 1.0f;
	p_bg.f[2] = -1.0f;
	p_bg.f[3] = -1.0f;
	p_bg.f[4] = 0;
	p_bg.f[7] = 1.0f;
	p_bg.f[8] = 1.0f;
	p_bg.f[9] = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_star", inv_star_set);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_star_dispset(int arg0) {
    inv_bg = arg0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_star", inv_star_disp);
