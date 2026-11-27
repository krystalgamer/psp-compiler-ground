/* cflags: -O2 */
#include "common.h"

void spr8x8_trans(unsigned char *src, unsigned char *dst, int x, int y, int u, int v)
{
	unsigned char *s, *d;
	int i;

	if (x > 256 || y > 256 || x < 0 || y < 0)
		return;
	s = src + u + v * 256;
	d = dst + x + y * 256;
	for (i = 0; i < 8; i++) {
		if (y + i > 256)
			break;
		memcpy(s, d, 8);
		s += 256;
		d += 256;
	}
}

void *memset(void *s, int c, unsigned int n);

void *memcpy(void *d, const void *s, unsigned int n);
void spr_trans(unsigned char *src, unsigned char *dst, int x, int y, int u, int v, int w, int h)
{
	unsigned char *s, *d;
	int i;

	if (x > 256 || y > 256 || x < 0 || y < 0)
		return;
	s = src + u + v * 256;
	d = dst + x + y * 256;
	for (i = 0; i < h; i++) {
		if (y + i > 256)
			break;
		memcpy(d, s, (x + w > 256) ? 256 - x : w);
		s += 256;
		d += 256;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_trans", spr_trans_or);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_trans", spr_trans_pal);

void spr8x8_boxfill(unsigned char *buf, int x, int y, int col)
{
	unsigned char *p;
	int i;

	if (x > 256 || y > 256 || x < 0 || y < 0)
		return;
	p = buf + x + y * 256;
	for (i = 0; i < 8; i++) {
		if (y + i > 256)
			break;
		memset(p, col, (x + 8 > 256) ? 256 - x : 8);
		p += 256;
	}
}

void spr_boxfill(unsigned char *buf, int x, int y, int w, int h, int col)
{
	unsigned char *p;
	int i;

	if (x > 256 || y > 256 || x < 0 || y < 0)
		return;
	p = buf + x + y * 256;
	for (i = 0; i < h; i++) {
		if (y + i > 256)
			break;
		memset(p, col, (x + w > 256) ? 256 - x : w);
		p += 256;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_trans", spr_boxmask);
