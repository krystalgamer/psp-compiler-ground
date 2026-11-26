/* cflags: -O2 */
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

extern s8 font_w[];

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

extern s8 font_w[];
int inv_font_ascii_check_w(u8 *s, int size)
{
	int total;
	u8 c;
	u8 n;

	if (size <= 0)
		return 0;
	total = 0;
	for (;;) {
		c = *s++;
		n = c - 0x20;
		if (c == 0)
			break;
		if (n >= 0x70)
			break;
		total += ((font_w[n] - 1) * size) / 100;
	}
	return total;
}

int inv_font_etc_check_w(int c, int size)
{
	if (size <= 0)
		return 0;
	if (c == 0)
		return 0;
	if ((unsigned int)(c - 0x20) >= 0x70)
		return 0;
	return ((font_w[(u8)(c - 0x20)] - 1) * size) / 100;
}

typedef struct { int used, x, x2, y, y2; float u0, u1, v0, v1; short pri; } FONT_T;
void inv_font_set(FONT_T *f, int c, int x, int y, int sx, int sy, short pri)
{
	float u, v;

	f->used = 1;
	f->x = x;
	f->y = y;
	f->x2 = x + (font_w[c] * sx) / 100;
	u = (c % 16) * 24;
	v = (c / 16) * 24;
	f->u0 = u;
	f->v0 = v;
	f->y2 = y + (sy * 24) / 100;
	f->u1 = u + font_w[c];
	f->pri = pri;
	f->v1 = v + 24.0f;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_ascii_posf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_etc_posf);
