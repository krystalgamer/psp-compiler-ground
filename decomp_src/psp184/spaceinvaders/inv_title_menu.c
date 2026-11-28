/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
void inv_logo(void);
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
typedef struct { int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40; } TITLE_MAIN;
#define TMS (*(TITLE_MAIN *)&title_main)
extern int D_00349230;
extern int D_00349268;

extern int memory_buf;
extern int malloc_max_size;
typedef struct { int f0; int f4; int f8; int fC; } BG_T;
typedef struct { int f0; int f4; int f8[6]; int f20[6]; } SEL_T;

extern int title_main;
void title_main_start(void);
void title_main_select(void);
void game_cnt_option_555B8(void);
void game_cnt_hiscore_5710C(void);
void game_cnt_help(void);
void title_main_return(void);
typedef struct { int f0; int f4; int f8[6]; int f20[6]; } SELC_T;

extern int game_cpu_disp;
int bmp_file_load(char *name);
int bmp_file_load16(char *name);
void title_bg_star_start(void *star);
unsigned long genrand_int32(void);
void *memset(void *, int, unsigned int);
typedef struct { int f0; int f4; int f8; u8 pad[0x1C - 0xC]; } TSTAR_T;

int inv_title_main(void) {
    inv_title_memcheck();
    inv_logo();
    inv_title_init();
    inv_title_roop();
    inv_title_free();
    return D_003491E4;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", inv_title_memcheck);

extern int logo;
extern char *logo_filename[];
void psp_loopstart(void);
void psp_loopend(void);
int pad_sw(void);
int pad_ret_button(void);
int pad_cansel_button(void);
int bmp_file_unload(int no);
void inv_logo(void)
{
	int alpha[2], tex[2];
	int no = 0, cnt = 0;
	int mode = 0, loop = 1;
	int i, j;

	if (logo == 1)
		return;
	for (j = 0; j < 2; j++) {
		alpha[j] = 0;
		tex[j] = -1;
	}
	do {
		psp_loopstart();
		if (mode == 0) {
			tex[no] = bmp_file_load(logo_filename[no]);
			alpha[no] = 0;
			mode = 1;
		} else if (mode == 1) {
			alpha[no] += 8;
			if (alpha[no] > 255)
				alpha[no] = 255;
			if (alpha[no] == 255) {
				if (no > 0)
					alpha[no - 1] = 0;
				mode = 2;
				cnt = 0;
			}
		} else if (mode == 2) {
			if (pad_sw() & (pad_ret_button() | pad_cansel_button()))
				cnt = 300;
			cnt++;
			if (cnt >= 300) {
				mode = 0;
				no++;
				if (no >= 2) {
					no--;
					mode = 10;
				}
			}
		} else if (mode == 10) {
			alpha[no] -= 8;
			if (alpha[no] < 0)
				alpha[no] = 0;
			if (alpha[no] == 0)
				mode = 11;
		} else {
			loop = 0;
		}
		for (i = 0; i < 2; i++) {
			if (tex[i] >= 0)
				sprite_set(tex[i], 0, 0, 480, 272, 0, 0, 100, 100, 0, 0, 255, 255, 255, 255, i, 2, 1, alpha[i]);
		}
		psp_loopend();
	} while (loop);
	psp_loopstart();
	psp_loopend();
	psp_loopstart();
	psp_loopend();
	for (i = 0; i < 2; i++) {
		if (tex[i] >= 0)
			bmp_file_unload(tex[i]);
	}
	logo = 1;
}

void title_init(void);
void select_init(void);
void title_bg_star_init(void);
void game_bg_init(void);
M2C_UNK inv_title_init(void)
{
	game_cpu_disp = 0;
	memset(&TMS, 0, 0xEDC);
	TMS.f0 = 0;
	TMS.fc = 1;
	TMS.f4 = 0;
	TMS.f8 = 0;
	TMS.f28 = bmp_file_load16("menu_bg.bmp");
	TMS.f2c = bmp_file_load("title.bmp");
	TMS.f30 = bmp_file_load("copyright_jp.bmp");
	TMS.f34 = bmp_file_load16("m_bg01.bmp");
	TMS.f38 = bmp_file_load16("m_bg02.bmp");
	TMS.f3c = bmp_file_load16("m_bg03.bmp");
	TMS.f40 = bmp_file_load16("m_bg04.bmp");
	TMS.f20 = 255;
	TMS.f24 = 255;
	TMS.f1c = 0;
	title_init();
	select_init();
	title_bg_star_init();
	game_bg_init();
}

void title_bg_star_disp(int a);
void game_bg_disp(void);
void title_control(void);
void select_control(void);
void psp_loopstart(void);
void psp_loopend(void);
void se_stop(void);
M2C_UNK inv_title_roop(void)
{
	while (TMS.fc) {
		if (!TMS.f1c) {
			psp_loopstart();
			title_main_control();
			title_bg_star_disp(TMS.f28);
			game_bg_disp();
			title_control();
			select_control();
			poly_set(0, 0, 480, 272, 0, 0, 0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 255, 20000, 2, 1, TMS.f20);
			psp_loopend();
			TMS.f18++;
		} else {
			TMS.f1c = 0;
		}
	}
	se_stop();
}

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

void title_main_control(void)
{
	switch (title_main) {
	case 0:
		title_main_start();
		break;
	case 1:
		title_main_select();
		break;
	case 2:
		game_cnt_option_555B8();
		break;
	case 3:
		game_cnt_hiscore_5710C();
		break;
	case 4:
		game_cnt_help();
		break;
	case 5:
		title_main_return();
		break;
	}
}

void title_start(void);
int title_start_check(void);
void select_start(void);
int select_start_check(void);
void select_set(int no);
void title_main_start(void)
{
	switch (TMS.f4) {
	case 0:
		TMS.f20 -= 16;
		if (TMS.f20 < 0)
			TMS.f20 = 0;
		if (TMS.f20 == 0)
			TMS.f4++;
		break;
	case 1:
		title_start();
		TMS.f4++;
	case 2:
		if (title_start_check())
			TMS.f4 = 10;
		break;
	case 10:
		select_start();
		TMS.f4++;
	case 11:
		if (select_start_check())
			TMS.f4 = 200;
		break;
	default:
		TMS.f4 = 0;
		TMS.f8 = 0;
		TMS.f14 = 0;
		TMS.f0 = 1;
		select_set(0);
		break;
	}
}

int pad_rp(void);
int pad_sw(void);
int pad_ret_button(void);
void se_start(int no);
void title_main_select(void)
{
	if ((pad_rp() & 0x100010) || (pad_rp() & 0x200040)) {
		if (pad_rp() & 0x100010)
			TMS.f14--;
		else if (pad_rp() & 0x200040)
			TMS.f14++;
		if (TMS.f14 < 0)
			TMS.f14 = 5;
		else if (TMS.f14 >= 6)
			TMS.f14 = 0;
		select_set(TMS.f14);
		if (pad_rp() & 0x100010)
			se_start(0x13);
		else if (pad_rp() & 0x200040)
			se_start(0x13);
	}
	if (TMS.f14 < 4)
		game_bg_start(TMS.f14);
	else
		game_bg_end(-1);
	if (pad_sw() & pad_ret_button()) {
		se_start(0x14);
		if (TMS.f14 < 4) {
			TMS.f0 = 5;
			TMS.f4 = 0;
			TMS.f8 = 0;
		} else if (TMS.f14 == 4) {
			TMS.f0 = 2;
			TMS.f4 = 0;
			TMS.f8 = 0;
		} else if (TMS.f14 == 5) {
			TMS.f0 = 3;
			TMS.f4 = 0;
			TMS.f8 = 0;
		}
	}
}

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

typedef struct { int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24; u8 pad[0xD4 - 0x28]; float speed; } TM_RET;
#define TMR (*(TM_RET *)&title_main)
typedef struct { int on, f4, f8, f0c, f10, w, h, f1c, f20, f24, f28, f2c, r, g, b, a; } SBLUR_T;
extern SBLUR_T screen_blur;
extern int D_00349170;
typedef struct { int x, y; } SELPOS_T;
extern SELPOS_T select_pos[];
extern char *select_text[];
float sinf_nb(float) __asm__("sinf");
void inv_font_ascii_posf(char *str, int x, int y, int w, int h, int r, int g, int b, int a, int mode);
void title_main_return(void)
{
	int k, x;

	if (TMR.f4 == 0) {
		if (TMR.f8 == 0) {
			/* volatile: the original emits these stores in source order (no reg-pressure reordering) */
			volatile SBLUR_T *b = &screen_blur;
			b->on = 1;
			b->f8 = 2;
			b->f0c = -12;
			b->f10 = -7;
			b->f28 = 105;
			b->w = 480;
			b->h = 272;
			*(volatile int *)&D_00349170 = 255;
			b->f1c = 0;
			b->f20 = 0;
			b->f2c = 0;
			b->r = 255;
			b->g = 255;
			b->b = 255;
			b->a = 0;
			b->f24 = 105;
		}
		TMR.f8 += 6;
		if (TMR.f8 > 90)
			TMR.f8 = 90;
		if (TMR.f8 >= 90) {
			TMR.f4++;
			TMR.f8 = 0;
		}
	} else if (TMR.f4 == 1) {
		TMR.f8++;
		if (TMR.f8 > 90)
			TMR.f8 = 90;
		if (TMR.f8 >= 90) {
			TMR.f4 = 2;
			TMR.f8 = 0;
		}
	} else if (TMR.f4 == 2) {
		TMR.f8 += 2;
		if (TMR.f8 > 90)
			TMR.f8 = 90;
		TMR.f20 = sinf_nb(TMR.f8 / 180.0f * 3.1415927f) * 255.0f;
		D_00349170 = sinf_nb((90 - TMR.f8) / 180.0f * 3.1415927f) * 255.0f;
		if (TMR.f8 == 90) {
			screen_blur.on = 0;
			TMR.fc = 0;
			TMR.f10 = TMR.f14;
		}
	}
	TMR.speed += 0.1f;
	screen_blur.a += 4;
	if (screen_blur.a > 255)
		screen_blur.a = 255;
	TMR.f24 -= 16;
	if (TMR.f24 < 0)
		TMR.f24 = 0;
	k = TMR.f8;
	if (TMR.f4 > 0)
		k = 90;
	x = select_pos[TMR.f14 + 2].x;
	inv_font_ascii_posf(select_text[TMR.f14 + 2], x,
		sinf_nb((90 - k) / 180.0f * 3.1415927f) * (select_pos[TMR.f14 + 2].y - 148) + 148.0f,
		100, 100, 0, 255, 255, D_00349170, 4);
}

void title_init(void)
{
	int *p = (int *)&D_00349218;


	p[3] = 0;
	p[0] = 0;
	p[1] = 0;
	p[2] = 0;
	
}

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

typedef struct { int on, cnt, ang, alpha; } TITLE_T;
extern int D_005FB7BC;
extern char D_0007EA60[], D_0007EA68[], D_0007EA74[];
int sprintf(char *buf, const char *fmt, ...);
void sprite_center_set(int tex, int x, int y, int w, int h, int u, int v, int sw, int sh, int a9, int a10, int r, int g, int b, int a, int pri, int mode, int a17, int alpha);
void inv_font_ascii_posf(char *str, int x, int y, int w, int h, int r, int g, int b, int a, int mode);
/* the two sinf((90 - ang) ...) calls are not CSEd: sinf is not the const builtin here */
float sinf_nb(float) __asm__("sinf");
void title_control(void)
{
	TITLE_T *t = (TITLE_T *)&D_00349218;
	int x, y, a;
	char buf[256];

	if (t->on) {
		t->alpha = sinf_nb(t->cnt / 180.0f * 3.1415927f) * 255.0f;
		if (t->alpha < 0)
			t->alpha = 0;
		else if (t->alpha > 255)
			t->alpha = 255;
		y = 60;
		x = 80;
		if (t->cnt < 90) {
			y = 100;
			x = 240;
		} else if (t->cnt == 90 && t->ang != 90) {
			t->ang += 2;
			if (t->ang < 0)
				t->ang = 0;
			else if (t->ang > 90)
				t->ang = 90;
			y = (int)(sinf_nb((90 - t->ang) / 180.0f * 3.1415927f) * 40.0f) + 60;
			x = (int)(sinf_nb((90 - t->ang) / 180.0f * 3.1415927f) * 160.0f) + 80;
		}
		if (t->alpha > 16) {
			a = t->alpha;
			if (TMS.f24 != 255)
				a = TMS.f24;
			sprite_center_set(TMS.f2c, x, 136, 256, 256, 0, 0, y, y, 0, 0, 255, 255, 255, 255, 100, 2, 2, a);
			sprite_set(TMS.f30, 0, 238, 480, 32, 0, 0, 100, 100, 0, 0, 255, 255, 255, 255, 100, 2, 2, a);
			if (D_005FB7BC == 1) {
				sprintf(buf, D_0007EA60, D_0007EA68, D_0007EA74);
				inv_font_ascii_posf(buf, 480, 0, 75, 75, 255, 255, 255, a, 2);
			}
		}
	}
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void select_init(void) {
    D_00349230 = 0;
}

void select_start(void)
{
	int i;
	SEL_T *s = (SEL_T *)&D_00349230;

	s->f0 = 1;
	s->f4 = -1;
	for (i = 0; i < 6; i++) {
		s->f20[i] = 0;
		s->f8[i] = 0;
	}
}

int select_start_check(void)
{
	int i;
	SELC_T *s = (SELC_T *)&D_00349230;

	for (i = 0; i < 6; i++) {
		if (i == 0) {
			s->f8[i] += 8;
		} else {
			if (s->f8[i - 1] >= 0x40)
				s->f8[i] += 8;
		}
		if (s->f8[i] > 0xFF)
			s->f8[i] = 0xFF;
	}
	if (s->f8[5] >= 0xFF)
		return 1;
	return 0;
}

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

typedef struct { int f0, f4, f8; float x, y, dx, dy; } STAR_T;

double genrand_real2(void);
double genrand_real3(void);
extern const double D_0007EC00, D_0007EC08, D_0007EC10, D_0007EC18, D_0007EC20;
void title_bg_star_start(void *star)
{
	STAR_T *s = star;
	float z;

	if (genrand_int32() % 50 == 0)
		s->f0 = 4;
	else
		s->f0 = genrand_int32() & 3;
	s->x = (genrand_real3() - D_0007EC00) * D_0007EC08 + D_0007EC08;
	s->y = (genrand_real3() - D_0007EC00) * D_0007EC10 + D_0007EC10;
	z = genrand_real2() * D_0007EC18 + D_0007EC20;
	s->f8 = 0;
	s->f4 = 0;
	s->dx = (s->x - 240.0f) / z;
	s->dy = (s->y - 136.0f) / z;
}

void title_bg_star_init(void)
{
	int i;
	u8 *t = (u8 *)&title_main;
	TSTAR_T *s;

	*(float *)(t + 0xD4) = 1.0f;
	*(int *)(t + 0xD8) = 1;
	s = (TSTAR_T *)(t + 0xDC);
	for (i = 0; i < 128; i++, s++) {
		title_bg_star_start(s);
		s->f4 = genrand_int32() % 120;
		s->f8 = 0xFF;
	}
}

typedef struct { u8 pad[0xD4]; float speed; int on; STAR_T star[128]; } TM_STAR;
#define TMST (*(TM_STAR *)&title_main)
void sprite_set(int tex, int x, int y, int w, int h, int u, int v, int sw, int sh, int a9, int a10, int r, int g, int b, int a, int pri, int mode, int a17, int alpha);
void title_bg_star_disp(int tex)
{
	int i;
	STAR_T *s;

	if (TMST.on) {
		for (i = 0; i < 128; i++) {
			s = &TMST.star[i];
			s->x += s->dx * TMST.speed;
			s->f4++;
			s->y += s->dy * TMST.speed;
			if (s->f4 < 60)
				s->f8 = s->f4 * 255 / 60;
			if (s->f4 > 120)
				s->f8 = 255 - (s->f4 * 255 - 30600) / 60;
			if (TMST.speed != 1.0f)
				s->f8 = s->f8 * TMST.speed;
			if (s->f8 < 0)
				s->f8 = 0;
			else if (s->f8 > 255)
				s->f8 = 255;
			if (s->f0 >= 0)
				sprite_set(tex, s->x, s->y, 8, 8, s->f0 * 8, 0, 100, 100, 0, 0, 255, 255, 255, 255, 10, 2, 1, s->f8);
			if (s->f4 > 180 || s->x < -8.0f || s->x > 480.0f || s->y < -8.0f || s->y > 272.0f)
				title_bg_star_start(s);
		}
	}
}

void game_bg_init(void)
{
	int i;
	BG_T *bg = (BG_T *)&D_00349268;

	for (i = 0; i < 4; i++) {
		bg[i].f0 = ((int *)&D_00349268 - 24)[i];
		bg[i].f4 = 0;
	}
}

void game_bg_start(int no)
{
	int i;
	BG_T *bg = (BG_T *)&D_00349268;

	for (i = 0; i < 4; i++) {
		if (i == no) {
			if (bg[i].f4 == 0 || bg[i].f4 == 3) {
				bg[i].f4 = 1;
				bg[i].f8 = 0;
				bg[i].fC = 0;
			}
		} else {
			if (bg[i].f4 == 1 || bg[i].f4 == 2)
				bg[i].f4 = 3;
		}
	}
}

void game_bg_end(int no)
{
	int i;
	BG_T *bg = (BG_T *)&D_00349268;

	for (i = 0; i < 4; i++) {
		if (i == no || no == -1) {
			if (bg[i].f4 == 1 || bg[i].f4 == 2)
				bg[i].f4 = 3;
		}
	}
}

float sinf(float x);
void game_bg_disp(void)
{
	int i, x, a;
	BG_T *bg;

	for (i = 0; i < 4; i++) {
		bg = &((BG_T *)&D_00349268)[i];
		if (bg->f4 == 0)
			continue;
		x = 320;
		if (bg->f4 == 1) {
			bg->f8 += 8;
			if (bg->f8 > 90)
				bg->f8 = 90;
			x += 160.0f - sinf(bg->f8 / 180.0f * 3.1415927f) * 160.0f;
			bg->fC = sinf(bg->f8 / 180.0f * 3.1415927f) * 128.0f;
			if (bg->f8 == 90)
				bg->f4 = 2;
		} else if (bg->f4 == 3) {
			bg->fC -= 8;
			if (bg->fC < 0)
				bg->fC = 0;
			if (bg->fC == 0)
				bg->f4 = 0;
		}
		a = bg->fC;
		if (TMS.f24 != 255)
			a = a * TMS.f24 / 255;
		sprite_set(bg->f0, x, 56, 256, 256, 0, 0, 60, 60, 0, 0, 255, 255, 255, 255, 20, 2, 1, a);
	}
}


/* alignment padding before the doubles (.rodata.cst8 in the original) */
const int D_0007EBFC = 0;

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
