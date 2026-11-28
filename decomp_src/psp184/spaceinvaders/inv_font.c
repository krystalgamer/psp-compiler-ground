/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
typedef struct { int used, x, x2, y, y2; float u0, u1, v0, v1; unsigned short pri; } FONT_T;
void inv_font_set(FONT_T *f, int c, int x, int y, int sx, int sy, unsigned short pri);
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

void inv_font_ascii_w(unsigned char *str, int x, int y, int w, int sx, int sy, int r, int g, int b, int a)
{
	int cx, cy, cw;
	unsigned short col;
	unsigned char c;
	unsigned int n;
	unsigned char *s;

	if (a <= 0)
		return;
	if (sx <= 0)
		return;
	if (sy <= 0)
		return;
	cx = x;
	cy = y;
	col = ((a >> 4) << 12) | (((b * a / 255) << 4) & 0xF00) | ((g * a / 255) & 0xF0) | ((u8)(r * a / 255) >> 4);
	s = str;
	for (;;) {
		if (font_max >= 512)
			return;
		c = *s;
		n = (u8)(c - 0x20);
		if (c == 0)
			return;
		if (c == '\n') {
			cx = x;
			cy += sy * 24 / 100;
			continue;
		}
		if (n >= 0x70)
			continue;
		if (c == ' ') {
			cx += w * sx / 100;
			s++;
			continue;
		}
		s++;
		inv_font_set(&((FONT_T *)&inv_font)[font_max], n, cx + (w * sx / 100 - (font_w[n] - 2) * sx / 100) / 2, cy, sx, sy, col);
		cx += w * sx / 100;
		font_max++;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_font", inv_font_ascii_no);

void inv_font_etc(int c, int x, int y, int sx, int sy, int r, int g, int b, int a)
{
	unsigned int n;

	if (a <= 0)
		return;
	if (sx <= 0)
		return;
	if (sy <= 0)
		return;
	n = c - 0x20;
	if (font_max >= 512)
		return;
	if (n >= 0x70)
		return;
	if (c == 0x20)
		return;
	inv_font_set(&((FONT_T *)&inv_font)[font_max], n & 0xff, x, y, sx, sy,
		     ((a >> 4) << 12) | (((b * a / 255) << 4) & 0xF00) | ((g * a / 255) & 0xF0) | ((u8)(r * a / 255) >> 4));
	font_max++;
}

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

void inv_font_set(FONT_T *f, int c, int x, int y, int sx, int sy, unsigned short pri)
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

typedef struct __attribute__((packed)) { unsigned short u, v; unsigned short color; short x, y, z; } FVTX;
extern int inv_font_disp_max, inv_font_disp_time;
extern int g_packet;
extern FVTX font_vtx[2][2048] __asm__("p_2903F4");
unsigned int sceKernelGetSystemTimeLow(void);
void sceGuEnable(int);
void sceGuDisable(int);
void sceGuTexFunc(int, int);
void sceGuTexMapMode(int, int, int);
void sceGuTexWrap(int, int);
void sceGuTexFilter(int, int);
void set_texture(int);
void sceGuAlphaFunc(int, int, int);
void sceGuBlendFunc(int, int, int, int, int);
int sceKernelDcacheWritebackInvalidateRange(const void *, unsigned int);
void sceGumDrawArrayN(int, int, int, int, const void *, const void *);
int inv_font_disp(void)
{
	FVTX *v;
	FONT_T *f;
	unsigned int t;
	int i, n, j;

	inv_font_disp_max = 0;
	inv_font_disp_time = 0;
	if (font_max == 0)
		return 0;
	t = sceKernelGetSystemTimeLow();
	if (!g_packet)
		v = font_vtx[0];
	else
		v = font_vtx[1];
	n = 0;
	for (i = 0; i < font_max; i++) {
		f = &((FONT_T *)&inv_font)[i];
		if (f->used) {
			f->used = 0;
			j = n;
			n += 4;
			v[j].u = (unsigned int)f->u0;
			v[j].v = (unsigned int)f->v0;
			v[j + 1].u = (unsigned int)f->u0;
			v[j + 1].v = (unsigned int)f->v1;
			v[j + 2].u = (unsigned int)f->u1;
			v[j + 2].v = (unsigned int)f->v0;
			v[j + 3].u = (unsigned int)f->u1;
			v[j + 3].v = (unsigned int)f->v1;
			v[j].color = f->pri;
			v[j + 1].color = f->pri;
			v[j + 2].color = f->pri;
			v[j + 3].color = f->pri;
			v[j].x = f->x;
			v[j].y = f->y;
			v[j].z = pri;
			v[j + 1].x = f->x;
			v[j + 1].y = f->y2;
			v[j + 1].z = pri;
			v[j + 2].x = f->x2;
			v[j + 2].y = f->y;
			v[j + 2].z = pri;
			v[j + 3].x = f->x2;
			v[j + 3].y = f->y2;
			v[j + 3].z = pri;
		}
	}
	inv_font_disp_max = font_max;
	font_max = 0;
	if (texture_no_29C3F8 != -1) {
		sceGuEnable(9);
		sceGuTexFunc(0, 1);
		sceGuTexMapMode(0, 0, 0);
		sceGuTexWrap(1, 1);
		sceGuTexFilter(1, 1);
		set_texture(texture_no_29C3F8);
	} else
		sceGuDisable(9);
	sceGuAlphaFunc(1, 0, 0xFF);
	sceGuEnable(0);
	if (alpha_mode_29C3FC == 0) {
		sceGuDisable(4);
	} else if (alpha_mode_29C3FC == 1) {
		sceGuBlendFunc(0, 2, 3, 0, 0);
		sceGuEnable(4);
	} else if (alpha_mode_29C3FC == 2) {
		sceGuBlendFunc(0, 10, 10, -1, -1);
		sceGuEnable(4);
	} else if (alpha_mode_29C3FC == 3) {
		sceGuBlendFunc(4, 0, 0, 0, 0);
		sceGuEnable(4);
	} else if (alpha_mode_29C3FC == 4) {
		sceGuBlendFunc(2, 10, 10, -1, -1);
		sceGuEnable(4);
	}
	sceKernelDcacheWritebackInvalidateRange(v, inv_font_disp_max * 48);
	sceGumDrawArrayN(4, 0x80011A, 4, inv_font_disp_max, 0, v);
	inv_font_disp_time = sceKernelGetSystemTimeLow() - t;
	return 1;
}

void inv_font_ascii(u8 *str, int x, int y, int sx, int sy, int r, int g, int b, int a);
void inv_font_ascii_posf(u8 *c, int x, int y, int sx, int sy, int r, int g, int b, int a, int pos)
{
	if (pos == 0) {
		y -= sy * 6 / 100;
	} else if (pos == 1) {
		x -= inv_font_ascii_check_w(c, sx) / 2;
		y -= sy * 6 / 100;
	} else if (pos == 2) {
		x -= inv_font_ascii_check_w(c, sx);
		y -= sy * 6 / 100;
	} else if (pos == 3) {
		y -= sy * 12 / 100;
	} else if (pos == 4) {
		x -= inv_font_ascii_check_w(c, sx) / 2;
		y -= sy * 12 / 100;
	} else if (pos == 5) {
		x -= inv_font_ascii_check_w(c, sx);
		y -= sy * 12 / 100;
	} else if (pos == 6) {
		y -= sy * 19 / 100;
	} else if (pos == 7) {
		x -= inv_font_ascii_check_w(c, sx) / 2;
		y -= sy * 19 / 100;
	} else if (pos == 8) {
		x -= inv_font_ascii_check_w(c, sx);
		y -= sy * 19 / 100;
	}
	inv_font_ascii(c, x, y, sx, sy, r, g, b, a);
}

void inv_font_etc_posf(int c, int x, int y, int sx, int sy, int r, int g, int b, int a, int pos)
{
	if (pos == 0) {
		y -= sy * 6 / 100;
	} else if (pos == 1) {
		x -= inv_font_etc_check_w(c, sx) / 2;
		y -= sy * 6 / 100;
	} else if (pos == 2) {
		x -= inv_font_etc_check_w(c, sx);
		y -= sy * 6 / 100;
	} else if (pos == 3) {
		y -= sy * 12 / 100;
	} else if (pos == 4) {
		x -= inv_font_etc_check_w(c, sx) / 2;
		y -= sy * 12 / 100;
	} else if (pos == 5) {
		x -= inv_font_etc_check_w(c, sx);
		y -= sy * 12 / 100;
	} else if (pos == 6) {
		y -= sy * 19 / 100;
	} else if (pos == 7) {
		x -= inv_font_etc_check_w(c, sx) / 2;
		y -= sy * 19 / 100;
	} else if (pos == 8) {
		x -= inv_font_etc_check_w(c, sx);
		y -= sy * 19 / 100;
	}
	inv_font_etc(c, x, y, sx, sy, r, g, b, a);
}
