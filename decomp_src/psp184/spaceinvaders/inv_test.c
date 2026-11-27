/* cflags: -O2 */
#include "common.h"

int bmp_file_load_normal(char *name);
int bmp_file_load16_normal(char *name);
void bmp_file_unload(int no);
void psp_loopstart(void);
void psp_loopend(void);
int pad_sw(void);
int pad_tr(void);
float pad_xf(void);
float pad_yf(void);
int sprite_set(int tex, int u, int v, int w, int h, int x, int y, int sx, int sy, int rot, int f, int r, int g, int b, int a, int pri, int alpha, int z, int al);
int sprite_center_set(int tex, int x, int y, int w, int h, int u, int v, int sx, int sy, int rot, int f, int r, int g, int b, int a, int pri, int alpha, int z, int al);
void sprite_nearest(int s);
void poly_set(int x, int y, int w, int h, int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20);
int sprintf(char *s, const char *fmt, ...);
void debug_text(int x, int y, char *s);
void maintest_loop(void)
{
	int loop, x, y, rot, sc;
	float fx, fy;
	int tex1, tex2;
	char buf[64];

	loop = 1;
	x = 240;
	y = 136;
	rot = 0;
	sc = 100;
	fy = fx = 0.0f;
	tex1 = bmp_file_load_normal("effect.bmp");
	tex2 = bmp_file_load16_normal("evologo.bmp");
	do {
		psp_loopstart();
		if (pad_sw() & 8)
			loop = 0;
		sprite_set(tex1, 0x80, 0x80, 0x100, 0x80, 0, 0, 100, 100, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 10, 2, 1, 0xFF);
		if (pad_tr() & 0x10)
			y--;
		if (pad_tr() & 0x40)
			y++;
		if (pad_tr() & 0x80)
			x--;
		if (pad_tr() & 0x20)
			x++;
		if (pad_sw() & 0x100)
			sc -= 10;
		if (pad_sw() & 0x200)
			sc += 10;
		if (pad_tr() & 0x1000)
			rot += 1000;
		if (pad_tr() & 0x8000)
			rot -= 1000;
		sprite_nearest(sprite_center_set(tex2, x, y, 0x100, 0x80, 0, 0, sc, sc, rot, 0, 0xFF, 0xFF, 0xFF, 0xFF, 11, 2, 1, 0xFF));
		fx += pad_xf();
		fy += pad_yf();
		poly_set(fx, fy, 0x80, 0x40, 0, 0xFF, 0, 0, 0x80, 0, 0xFF, 0, 0x80, 0, 0, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0x80, 0, 2, 1, 0xFF);
		sprintf(buf, "SPR %d:%d [%d]", x, y, sc);
		debug_text(10, 10, buf);
		sprintf(buf, "POLY %.2f:%.2f", fx, fy);
		debug_text(10, 20, buf);
		psp_loopend();
	} while (loop);
	bmp_file_unload(tex1);
	bmp_file_unload(tex2);
}
