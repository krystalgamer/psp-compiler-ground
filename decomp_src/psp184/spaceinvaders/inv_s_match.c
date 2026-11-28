/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
void ASC_SetStringRGBA(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
int pad_cansel_button();                            /* extern */
int pad_ret_button();                               /* extern */
void se_start(int);
extern unsigned char D_0007CCD8;
extern int RT;
extern int Anm;
extern int gcnt_28FC04;


extern int inv;

typedef struct { u8 *spr; int f4; int f8; int fC; int f10; int f14; int f18; int f1C; } INV_W;
extern int ufocnt_28FBC8;
extern int ufocntmax;
extern int ufodisp;
int hato(int cur, int target, int shift);
unsigned long genrand_int32(void);

extern int *screensrc;
extern u8 D_00080F88[];
int VramAtariSub(s8 *buf, int x, int y, int w);
void spr_boxmask(void *mask, int tex, int x, int y, int w, int h, int mw, int mh);

typedef struct { int *p; int f4[7]; } INV_T;
extern INV_T invt[] __asm__("inv");
extern int enemove_c_1p_max;
extern int enemove_c_2p_max;

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_main);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_init);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_matchup_demo(void) {
    int temp_s0;
    int temp_s1;

    ASC_SetStringRGBA(2, &D_0007CCD8, 0xBC, 0xC8, 0x40, 0xFF, 0xFF, 0xFF);
    temp_s1 = pad_sw();
    temp_s0 = pad_ret_button();
    if (temp_s1 & (temp_s0 | pad_cansel_button())) {
        se_start(1);
        RT = 9;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_matchup_start(void) {
    RT = 3;
}

typedef struct { int f[0x80 / 4]; } MSPR;
extern MSPR *m_inv[];
extern int demo_type, handycap[2];
void inv_matchup_startdemo(void)
{
	switch (demo_type) {
	case 0:
		demo_type = 1;
		break;
	case 1:
		m_inv[0]->f[0x28 / 4] -= 2;
		m_inv[3]->f[0x28 / 4] += 2;
		if (m_inv[0]->f[0x28 / 4] < 153 && m_inv[3]->f[0x28 / 4] >= 256) {
			m_inv[0]->f[0x28 / 4] = 152;
			m_inv[3]->f[0x28 / 4] = 256;
			demo_type = 2;
		}
		break;
	case 2:
		m_inv[0]->f[0x78 / 4] -= 4;
		m_inv[3]->f[0x78 / 4] += 4;
		if (m_inv[0]->f[0x78 / 4] < 271 && m_inv[3]->f[0x78 / 4] >= 90) {
			m_inv[0]->f[0x78 / 4] = 270;
			m_inv[3]->f[0x78 / 4] = 90;
			demo_type = 3;
		}
		break;
	case 3:
		RT = 4;
		handycap[0] = 0;
		handycap[1] = 0;
		gcnt_28FC04 = 0;
		break;
	}
	ASC_SetStringRGBA(2, &D_0007CCD8, 188, 200, 64, 255, 255, 255);
}

int pad_sw(void);
void inv_matchup_zankidisp(void);
extern int classic_tex_28FBE4;
extern INV_W ziki[];
int sprite_set(int tex, int x, int y, int w, int h, int u, int v, int sw, int sh, int a9, int a10, int r, int g, int b, int a, int pri, int mode, int a17, int alpha);
void inv_matchup_handycap(void)
{
	int r0, g0, b0, r1, g1, b1;

	if (pad_sw() & 0x100010) {
		if (!(handycap[0] & 0x10)) {
			se_start(0);
			if (--handycap[0] < 0)
				handycap[0] = 0;
		}
	} else if (pad_sw() & 0x200040) {
		if (!(handycap[0] & 0x10)) {
			se_start(0);
			if (++handycap[0] >= 3)
				handycap[0] = 2;
		}
	} else if (pad_sw() & 0x100) {
		if (!(handycap[0] & 0x10)) {
			se_start(1);
			handycap[0] |= 0x10;
		}
	} else if (pad_sw() & 0x400080) {
		handycap[0] &= ~0x10;
	}
	if (pad_sw() & 0x1000) {
		if (!(handycap[1] & 0x10)) {
			se_start(0);
			if (++handycap[1] >= 3)
				handycap[1] = 2;
		}
	} else if (pad_sw() & 0x4000) {
		if (!(handycap[1] & 0x10)) {
			se_start(0);
			if (--handycap[1] < 0)
				handycap[1] = 0;
		}
	} else if (pad_sw() & 0x200) {
		if (!(handycap[1] & 0x10)) {
			se_start(1);
			handycap[1] |= 0x10;
		}
	} else if (pad_sw() & 0x2000) {
		handycap[1] &= ~0x10;
	}
	if (handycap[0] == 0)
		ziki[0].f8 = 3;
	else if (handycap[0] == 1)
		ziki[0].f8 = 5;
	else if (handycap[0] == 2)
		ziki[0].f8 = 7;
	if (handycap[1] == 0)
		ziki[1].f8 = 3;
	else if (handycap[1] == 1)
		ziki[1].f8 = 5;
	else if (handycap[1] == 2)
		ziki[1].f8 = 7;
	if ((handycap[0] & 0x10) && (handycap[1] & 0x10)) {
		RT = 5;
		gcnt_28FC04 = 0;
		return;
	}
	if (!(handycap[0] & 0x10)) {
		r0 = 255;
		g0 = 255;
		b0 = 255;
	} else {
		r0 = 255;
		g0 = 0;
		b0 = 0;
	}
	if (!(handycap[1] & 0x10)) {
		r1 = 255;
		g1 = 255;
		b1 = 255;
	} else {
		r1 = 255;
		g1 = 0;
		b1 = 0;
	}
	sprite_set(classic_tex_28FBE4, 72, 72, 8, 128, 240, 0, 100, 100, 0, 0, r0, g0, b0, 255, 0, 2, 1, 255);
	sprite_set(classic_tex_28FBE4, 400, 72, 8, 128, 248, 0, 100, 100, 0, 0, r1, g1, b1, 255, 0, 2, 1, 255);
	if (handycap[0] == 0)
		sprite_set(classic_tex_28FBE4, 72, 160, 8, 8, 136, 160, 100, 100, 0, 0, 40, 255, 255, 255, 50, 2, 1, 255);
	else if (handycap[0] == 1)
		sprite_set(classic_tex_28FBE4, 72, 176, 8, 8, 152, 160, 100, 100, 0, 0, 40, 255, 255, 255, 50, 2, 1, 255);
	else if (handycap[0] == 2)
		sprite_set(classic_tex_28FBE4, 72, 192, 8, 8, 168, 160, 100, 100, 0, 0, 40, 255, 255, 255, 50, 2, 1, 255);
	if (handycap[1] == 0)
		sprite_set(classic_tex_28FBE4, 400, 104, 8, 8, 136, 168, 100, 100, 0, 0, 40, 255, 255, 255, 50, 2, 1, 255);
	else if (handycap[1] == 1)
		sprite_set(classic_tex_28FBE4, 400, 88, 8, 8, 152, 168, 100, 100, 0, 0, 40, 255, 255, 255, 50, 2, 1, 255);
	else if (handycap[1] == 2)
		sprite_set(classic_tex_28FBE4, 400, 72, 8, 8, 168, 168, 100, 100, 0, 0, 40, 255, 255, 255, 50, 2, 1, 255);
	inv_matchup_zankidisp();
}

extern INV_W ziki[];
void sound_start(int no);
void inv_matchup_startdemo2(void)
{
	int i;
	u8 *p;
	int q;

	if (gcnt_28FC04 >= 181) {
		sound_start(0);
		RT = 6;
		return;
	}
	for (i = 0; i < 2; i++) {
		p = ziki[i].spr;
		*(int *)(p + 0x88) = hato(*(int *)(p + 0x88), 255, 6);
	}
	for (i = 0; i < 48; i++) {
		q = (int)((INV_W *)&inv)[i].spr;
		if (q)
			*(int *)(q + 0x88) = hato(*(int *)(q + 0x88), 255, 6);
	}
}

void inv_matchup_continue_main(void)
{
	int i;
	INV_W *w = (INV_W *)&inv;
	u8 *p;

	for (i = 0; i < 48; i++, w++) {
		p = w->spr;
		if (p) {
			if (w->f4 == 1)
				*(int *)(p + 0x78) = hato(*(int *)(p + 0x78), 270, 2);
			else if (w->f4 == 2)
				*(int *)(p + 0x78) = hato(*(int *)(p + 0x78), 90, 2);
		}
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_continue_cont);

extern INV_W ziki[];
extern int classic_tex_28FBE4;
int sprite_set(int tex, int x, int y, int w, int h, int u, int v, int sw, int sh, int a9, int a10, int r, int g, int b, int a, int pri, int mode, int a17, int alpha);
void inv_matchup_zankidisp(void)
{
	int y, i;

	for (y = 8, i = 0; i < ziki[0].f8 - 1; i++, y += 16)
		sprite_set(classic_tex_28FBE4, 0, y, 8, 16, 0x88, 8, 100, 100, 0, 0, 40, 255, 255, 255, 10, 2, 2, 255);
	sprite_set(classic_tex_28FBE4, 0, 0, 8, 8, ziki[0].f8 * 8 + 0x70, 0xA0, 100, 100, 0, 0, 255, 255, 255, 255, 10, 2, 2, 255);
	for (y = 0xF8, i = 0; i < ziki[1].f8 - 1; i++, y -= 16)
		sprite_set(classic_tex_28FBE4, 0x1D8, y, 8, 16, 0x90, 8, 100, 100, 0, 0, 40, 255, 255, 255, 10, 2, 2, 255);
	sprite_set(classic_tex_28FBE4, 0x1D8, 0x108, 8, 8, ziki[1].f8 * 8 + 0x70, 0xA8, 100, 100, 0, 0, 255, 255, 255, 255, 10, 2, 2, 255);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_continue);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_matchup_winlose(void) {
    RT = 8;
    gcnt_28FC04 = 0;
    Anm = 0;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CCD8);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", inv_matchup_result);

void inv_matchup_fade(void) {
}

extern int matchup_menu_choice, RT_END;
extern unsigned char D_0007CD20, D_0007CD18;
extern const float D_0007CE04, D_0007CE08, D_0007CE0C, D_0007CE10;
int ASC_StringRen(void *s);
float sinf(float);
void inv_matchup_menu_start(void)
{
	int a, w;

	if (pad_sw() & pad_ret_button()) {
		se_start(1);
		switch (matchup_menu_choice) {
		case 0:
			RT = 2;
			break;
		case 1:
			RT = 12;
			matchup_menu_choice = 0;
			break;
		case 2:
			RT_END = 1;
			break;
		}
	} else if (pad_sw() & 0x100010) {
		se_start(0);
		matchup_menu_choice--;
		if (matchup_menu_choice < 0)
			matchup_menu_choice = 2;
	} else if (pad_sw() & 0x200040) {
		se_start(0);
		matchup_menu_choice++;
		if (matchup_menu_choice >= 3)
			matchup_menu_choice = 0;
	}
	w = ASC_StringRen(&D_0007CCD8);
	ASC_SetStringRGBA(1, &D_0007CCD8, (480 - w) / 2, 40, 255, 255, 255, 255);
	a = sinf(gcnt_28FC04 % 45 * 4 / D_0007CE04 * D_0007CE08) * D_0007CE0C + D_0007CE10;
	switch (matchup_menu_choice) {
	case 0:
		w = ASC_StringRen("START");
		ASC_SetStringRGBA(1, "START", (480 - w) / 2, 128, 64, 255, 255, a);
		break;
	case 1:
		w = ASC_StringRen(&D_0007CD18);
		ASC_SetStringRGBA(1, &D_0007CD18, (480 - w) / 2, 152, 64, 255, 255, a);
		break;
	case 2:
		w = ASC_StringRen(&D_0007CD20);
		ASC_SetStringRGBA(1, &D_0007CD20, (480 - w) / 2, 176, 64, 255, 255, a);
		break;
	}
	w = ASC_StringRen("START");
	ASC_SetStringRGBA(1, "START", (480 - w) / 2, 128, 255, 255, 255, 255);
	w = ASC_StringRen(&D_0007CD18);
	ASC_SetStringRGBA(1, &D_0007CD18, (480 - w) / 2, 152, 255, 255, 255, 255);
	w = ASC_StringRen(&D_0007CD20);
	ASC_SetStringRGBA(1, &D_0007CD20, (480 - w) / 2, 176, 255, 255, 255, 255);
	poly_set(0, 0, 480, 272, 0, 16, 16, 16, 160, 16, 16, 16, 160, 16, 16, 16, 160, 16, 16, 16, 160, 10, 2, 1, 255);
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CD18);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CD20);

extern const float D_0007CE14, D_0007CE18, D_0007CE1C, D_0007CE20;
void inv_matchup_menu_pause(void)
{
	int a, w;

	if (pad_sw() & pad_ret_button()) {
		se_start(1);
		switch (matchup_menu_choice) {
		case 0:
			RT = 6;
			matchup_menu_choice = 0;
			break;
		case 1:
			RT_END = 1;
			break;
		}
	} else if (pad_sw() & 0x100010) {
		se_start(0);
		matchup_menu_choice--;
		if (matchup_menu_choice < 0)
			matchup_menu_choice = 1;
	} else if (pad_sw() & 0x200040) {
		se_start(0);
		matchup_menu_choice++;
		if (matchup_menu_choice >= 2)
			matchup_menu_choice = 0;
	}
	w = ASC_StringRen(&D_0007CCD8);
	ASC_SetStringRGBA(1, &D_0007CCD8, (480 - w) / 2, 40, 255, 255, 255, 255);
	a = sinf(gcnt_28FC04 % 45 * 4 / D_0007CE14 * D_0007CE18) * D_0007CE1C + D_0007CE20;
	switch (matchup_menu_choice) {
	case 0:
		w = ASC_StringRen("CONTINUE");
		ASC_SetStringRGBA(1, "CONTINUE", (480 - w) / 2, 128, 64, 255, 255, a);
		break;
	case 1:
		w = ASC_StringRen(&D_0007CD20);
		ASC_SetStringRGBA(1, &D_0007CD20, (480 - w) / 2, 176, 64, 255, 255, a);
		break;
	}
	w = ASC_StringRen("CONTINUE");
	ASC_SetStringRGBA(1, "CONTINUE", (480 - w) / 2, 128, 255, 255, 255, 255);
	w = ASC_StringRen(&D_0007CD20);
	ASC_SetStringRGBA(1, &D_0007CD20, (480 - w) / 2, 176, 255, 255, 255, 255);
	poly_set(0, 0, 480, 272, 0, 16, 16, 16, 160, 16, 16, 16, 160, 16, 16, 16, 160, 16, 16, 16, 160, 10, 2, 1, 255);
}

extern const float D_0007CE24, D_0007CE28, D_0007CE2C, D_0007CE30;
void ms_save(void);
void ms_load(void);
void inv_matchup_menu_option(void)
{
	int a, w;

	if (pad_sw() & pad_ret_button()) {
		se_start(1);
		switch (matchup_menu_choice) {
		case 0:
			ms_save();
			matchup_menu_choice = 0;
			break;
		case 1:
			ms_load();
			matchup_menu_choice = 0;
			break;
		case 2:
			RT = 9;
			matchup_menu_choice = 0;
			break;
		}
	} else if (pad_sw() & 0x100010) {
		se_start(0);
		matchup_menu_choice--;
		if (matchup_menu_choice < 0)
			matchup_menu_choice = 2;
	} else if (pad_sw() & 0x200040) {
		se_start(0);
		matchup_menu_choice++;
		if (matchup_menu_choice >= 3)
			matchup_menu_choice = 0;
	}
	a = sinf(gcnt_28FC04 % 45 * 4 / D_0007CE24 * D_0007CE28) * D_0007CE2C + D_0007CE30;
	switch (matchup_menu_choice) {
	case 0:
		w = ASC_StringRen("SAVE");
		ASC_SetStringRGBA(1, "SAVE", (480 - w) / 2, 104, 64, 255, 255, a);
		break;
	case 1:
		w = ASC_StringRen("LOAD");
		ASC_SetStringRGBA(1, "LOAD", (480 - w) / 2, 128, 64, 255, 255, a);
		break;
	case 2:
		w = ASC_StringRen(&D_0007CD20);
		ASC_SetStringRGBA(1, &D_0007CD20, (480 - w) / 2, 152, 64, 255, 255, a);
		break;
	}
	w = ASC_StringRen(&D_0007CD18);
	ASC_SetStringRGBA(1, &D_0007CD18, (480 - w) / 2, 40, 255, 255, 255, 255);
	w = ASC_StringRen("SAVE");
	ASC_SetStringRGBA(1, "SAVE", (480 - w) / 2, 104, 255, 255, 255, 255);
	w = ASC_StringRen("LOAD");
	ASC_SetStringRGBA(1, "LOAD", (480 - w) / 2, 128, 255, 255, 255, 255);
	w = ASC_StringRen(&D_0007CD20);
	ASC_SetStringRGBA(1, &D_0007CD20, (480 - w) / 2, 152, 255, 255, 255, 255);
	poly_set(0, 0, 480, 272, 0, 16, 16, 16, 160, 16, 16, 16, 160, 16, 16, 16, 160, 16, 16, 16, 160, 10, 2, 1, 255);
}

typedef struct { u8 _p[0x78]; int lv1, lv2; } MH_SAVE;
extern MH_SAVE mh_save __asm__("save_data");
extern const float D_0007CE34, D_0007CE38, D_0007CE3C, D_0007CE40;
void inv_matchup_menu_handy(void)
{
	int i, x, a;

	if ((pad_sw() & pad_ret_button()) || (pad_sw() & pad_cansel_button())) {
		se_start(1);
		RT = 12;
	} else if (pad_sw() & 0x100010) {
		se_start(0);
		matchup_menu_choice--;
		if (matchup_menu_choice < 0)
			matchup_menu_choice = 1;
	} else if (pad_sw() & 0x200040) {
		se_start(0);
		matchup_menu_choice++;
		if (matchup_menu_choice >= 2)
			matchup_menu_choice = 0;
	} else if (pad_sw() & 0x400080) {
		se_start(0);
		if (matchup_menu_choice == 0) {
			mh_save.lv1--;
			if (mh_save.lv1 <= 0)
				mh_save.lv1 = 1;
		} else if (matchup_menu_choice == 1) {
			mh_save.lv2--;
			if (mh_save.lv2 <= 0)
				mh_save.lv2 = 1;
		}
	} else if (pad_sw() & 0x800020) {
		se_start(0);
		if (matchup_menu_choice == 0) {
			mh_save.lv1++;
			if (mh_save.lv1 >= 9)
				mh_save.lv1 = 8;
		} else if (matchup_menu_choice == 1) {
			mh_save.lv2++;
			if (mh_save.lv2 >= 9)
				mh_save.lv2 = 8;
		}
	}
	if (mh_save.lv1) {
		for (i = 0; i < mh_save.lv1; i++)
			ASC_SetStringRGBA(1, "*", 208 + i * 8, 104, 255, 255, 255, 255);
	}
	if (mh_save.lv2) {
		for (i = 0; i < mh_save.lv2; i++)
			ASC_SetStringRGBA(1, "*", 208 + i * 8, 112, 255, 255, 255, 255);
	}
	ASC_SetStringRGBA(1, &D_0007CD18, (480 - ASC_StringRen(&D_0007CD18)) / 2, 40, 255, 255, 255, 255);
	a = sinf(gcnt_28FC04 % 45 * 4 / D_0007CE34 * D_0007CE38) * D_0007CE3C + D_0007CE40;
	switch (matchup_menu_choice) {
	case 0:
		ASC_SetStringRGBA(1, "1P", 184, 104, 64, 255, 255, a);
		break;
	case 1:
		ASC_SetStringRGBA(1, "2P", 184, 112, 64, 255, 255, a);
		break;
	}
	ASC_SetStringRGBA(1, "LEVEL", 96, 104, 255, 255, 255, 255);
	ASC_SetStringRGBA(1, "1P", 184, 104, 255, 255, 255, 255);
	ASC_SetStringRGBA(1, "2P", 184, 112, 255, 255, 255, 255);
	ASC_SetStringRGBA(1, &D_0007CD20, 96, 128, 255, 255, 255, 255);
	poly_set(0, 0, 480, 272, 0, 16, 16, 16, 160, 16, 16, 16, 160, 16, 16, 16, 160, 16, 16, 16, 160, 10, 2, 1, 255);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", BoxAtari_ek4m);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", BoxAtari_e4m);

#define ABS(x) ((x) < 0 ? -(x) : (x))
extern INV_W ziki[];
int BoxAtari_ez4m(int a0, int a1, int x, int y, int w, int h)
{
	int i, dy, dh, dx, dw, sx, sy, sx2, sy2, ex, ey;
	int s;

	for (i = 0; i < 2; i++) {
		s = (int)ziki[i].spr;
		if (s) {
			sy = *(int *)(s + 0x2C);
			sx = *(int *)(s + 0x28);
			dx = ABS(sx - x);
			dy = ABS(sy - y);
			sx2 = sx + 8;
			sy2 = sy + 16;
			ex = x + w;
			ey = y + h;
			dw = ABS(ex - sx2);
			dh = ABS(ey - sy2);
			if (dy < 16) {
				if (dh < 16) {
					if (dx < 8) {
						if (dw < 8) {
							if (i == 0) {
								if (ziki[0].f1C == 0 && *(int *)(ziki[0].spr + 0x14) != 4) {
									*(int *)(ziki[0].spr + 0x14) = 4;
									ziki[0].f14 = 180;
									return 1;
								}
							} else {
								if (ziki[i].f1C == 0 && *(int *)(s + 0x14) != 5) {
									*(int *)(s + 0x14) = 5;
									ziki[i].f14 = 180;
									return 2;
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

extern int *screensrc;
extern u8 D_00080F88[];
int VramAtariSub(s8 *buf, int x, int y, int w);
void spr_boxmask(void *mask, int tex, int x, int y, int w, int h, int mw, int mh);
int BoxAtari_k4m(int a0, int a1, int x, int y)
{
	if (VramAtariSub((s8 *)screensrc[7], x + 4, y + 4, 0x200) == 0)
		return 0;
	spr_boxmask(D_00080F88, screensrc[7], x, y, 8, 8, 0x200, 0x200);
	return 1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", BoxAtari_z4m);

extern int inv;
static int SprMoveEnemyChk(int a, int b)
{
	int i;
	int *p = &inv;

	for (i = 0; i < 48; i++) {
		if (p[0] != 0 && (unsigned)(*(int *)(p[0] + 0x10) - 5) < 2) {
			if (p[4] == b && p[3] == a)
				return 0;
		}
		p += 8;
	}
	return 1;
}

void SprMoveEnemyNomal(int *pi, int *pd)
{
	int d = *pd;
	int x;
	int i = *pi;
	INV_W *w;

	if (d & 0x10) {
		w = &((INV_W *)&inv)[i];
		if (w->f4 == 1) {
			x = w->fC - 1;
			if (SprMoveEnemyChk(x, w->f10))
				w->fC -= 2;
			else
				w->fC -= 1;
		} else {
			x = w->fC + 1;
			if (SprMoveEnemyChk(x, w->f10))
				w->fC += 2;
			else
				w->fC += 1;
		}
		i--;
		*pi = i;
	} else if (d & 0x20) {
		w = &((INV_W *)&inv)[i];
		if (w->f4 == 2) {
			x = w->fC + 1;
			if (SprMoveEnemyChk(x, w->f10))
				w->fC += 2;
			else
				w->fC += 1;
		} else {
			x = w->fC - 1;
			if (SprMoveEnemyChk(x, w->f10))
				w->fC -= 2;
			else
				w->fC -= 1;
		}
		i--;
		*pi = i;
	} else {
		if (((INV_W *)&inv)[i].spr) {
			if (d == 0)
				((INV_W *)&inv)[i].f10++;
			else if (d == 1)
				((INV_W *)&inv)[i].f10--;
			i--;
		*pi = i;
		}
	}
}

void SprMoveEnemySub(void)
{
	int i;
	int *s;

	for (i = 0; i < 48; i++) {
		s = invt[i].p;
		if (s && (s[3] & 2) && (s[4] == 5 || s[4] == 6)) {
			s[10] = hato(s[10], invt[i].f4[2] * 8, 2);
			s = invt[i].p;
			s[11] = hato(s[11], invt[i].f4[3] * 2, 2);
		}
	}
}

void SprMoveEnemySub(void);
int SprMoveEnemy(void)
{
	int i, f = 0;
	INV_W *w;

	SprMoveEnemySub();
	for (i = 0, w = (INV_W *)&inv; i < 48; i++, w++) {
		if (w->spr) {
			switch (*(int *)(w->spr + 0x10)) {
			case 5:
				if (w->fC < 3)
					f |= 1;
				else if (w->fC >= 57)
					f |= 2;
				break;
			case 6:
				if (w->fC >= 57)
					f |= 2;
				else if (w->fC < 3)
					f |= 1;
				break;
			}
		}
	}
	if (f == 3)
		return 2;
	if (f == 1)
		return 0;
	if (f == 2)
		return 1;
	return 3;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", matchup_inv_enemyshort);

extern int WinLose;
extern int WinLose;
void matchup_inv_winlose_set(int no)
{
	int i, n;

	if (no != 3) {
		if (--ziki[no].f8 != 0) {
			se_start(4);
		} else {
			se_start(4);
			se_start(4);
			se_start(4);
			if (no == 0)
				WinLose = 0;
			else
				WinLose = 1;
			RT = 7;
		}
	} else {
		n = 0;
		for (i = 0; i < 2; i++) {
			if (--ziki[i].f8 == 0)
				n++;
			else
				se_start(4);
		}
		if (n == 2) {
			WinLose = n;
			RT = 7;
		} else if (ziki[0].f8 == 0) {
			se_start(4);
			se_start(4);
			se_start(4);
			RT = 7;
			WinLose = 0;
		} else if (ziki[1].f8 == 0) {
			se_start(4);
			se_start(4);
			se_start(4);
			WinLose = 1;
			RT = 7;
		}
	}
}

static void matchup_inv_ufodispjudge(void)
{
	int t;

	ufodisp = 0;
	ufocnt_28FBC8++;
	if (ufocnt_28FBC8 > ufocntmax) {
		t = genrand_int32() % 15 + 25;
		ufocnt_28FBC8 = 0;
		ufocntmax = t * 60;
		ufodisp = 1;
	}
}

extern MSPR *ufo;
extern int ufodisp, ufoaddy, gcnt_28FC04, ufocnt_28FBC8;
void matchup_inv_ufodisp(void)
{
	if (ufodisp) {
		ufo->f[0xC / 4] |= 2;
		if (ufoaddy == 0) {
			if (genrand_int32() % 100 < 50) {
				ufo->f[0x48 / 4] = 16;
				ufo->f[0x4C / 4] = 0x38;
				ufo->f[0x2C / 4] = 0;
				ufo->f[0x78 / 4] = 0;
				ufoaddy = 1;
			} else {
				ufo->f[0x4C / 4] = 0x38;
				ufo->f[0x78 / 4] = 0;
				ufo->f[0x2C / 4] = 0x110;
				ufo->f[0x48 / 4] = 0x18;
				ufoaddy = -1;
			}
		}
	}
	if (ufoaddy == 0)
		return;
	if (gcnt_28FC04 % 3 == 0) {
		ufo->f[0x2C / 4] += ufoaddy;
		if (ufoaddy == -1) {
			if (ufo->f[0x2C / 4] <= 0) {
				ufo->f[0xC / 4] &= ~2;
				ufoaddy = 0;
			}
		} else if (ufoaddy == 1) {
			if (ufo->f[0x2C / 4] >= 0x110) {
				ufo->f[0xC / 4] &= ~2;
				ufoaddy = 0;
			}
		}
	}
	if (ufocnt_28FBC8 % 152 == 0)
		se_start(5);
}

typedef struct { int f0, f4, f8, fc; u8 pad[0x28 - 0x10]; int f28, f2c; u8 pad2[0x68 - 0x30]; int f68, f6c; } UFRS_T;
typedef struct { UFRS_T *spr; int f4, f8, y; int f10[4]; } UFRI_T;
void matchup_inv_uforeverse(int mode)
{
	int y, st, end, step, i, cnt;
	UFRI_T *p;

	st = 0;
	end = 60;
	step = 1;
	if (mode == 3)
		;
	else if (mode == 4) {
		st = 60;
		end = 0;
		step = -1;
	}
	cnt = 0;
	y = st;
	do {
		if (step == 1) {
			if (y >= end)
				return;
		} else if (step == -1) {
			if (end >= y)
				return;
		}
		for (i = 0; i < 48; i++) {
			p = &((UFRI_T *)invt)[i];
			if (p->spr) {
				if (p->y == y) {
					if (mode == 3) {
						if (p->f4 == 1) {
							cnt++;
							p->spr->fc |= 8;
							p->f4 = 2;
							p->spr->f68 = p->spr->f28;
							p->spr->f6c = p->spr->f2c;
						}
					} else if (mode == 4) {
						if (p->f4 == 2) {
							cnt++;
							p->spr->fc |= 8;
							p->f4 = 1;
							p->spr->f68 = p->spr->f28;
							p->spr->f6c = p->spr->f2c;
						}
					}
					if (cnt >= 8)
						break;
				}
			}
		}
		y += step;
	} while (cnt < 8);
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CD58);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CD98);

extern int ranktbl[];
int sprintf(char *s, const char *fmt, ...);
void debug_text(int x, int y, char *s);
int matchup_inv_rankjudge(int lose)
{
	char buf[64];
	int i, hit;

	sprintf(buf, "lose=%d\n", lose);
	debug_text(10, 20, buf);
	hit = 0;
	if (lose == 1) {
		for (i = 0; i < 48; i++) {
			if (invt[i].p && invt[i].f4[2] < 31)
				if (invt[i].p[3] & 2)
					hit++;
		}
	} else if (lose == 0) {
		for (i = 0; i < 48; i++) {
			if (invt[i].p && invt[i].f4[2] >= 30)
				if (invt[i].p[3] & 2)
					hit++;
		}
	}
	sprintf(buf, "hit=%d\n", hit);
	debug_text(10, 28, buf);
	for (i = 0; i < 5; i++) {
		if (hit >= ranktbl[i]) {
			sprintf(buf, "rank=%d ranktbl[%d]=%d\n", i, i, ranktbl[i]);
			debug_text(10, 36, buf);
			return i;
		}
	}
	return 4;
}

int matchup_inv_reinforce(int pl)
{
	int i;
	int ret = 0;
	int *s;

	for (i = 0; i < 48; i++) {
		s = invt[i].p;
		if (s && (s[3] & 2) && s[4] == pl) {
			if (pl == 5) {
				if (invt[i].f4[2] < 0x18)
					ret = 1;
			} else if (pl == 6) {
				if (invt[i].f4[2] >= 0x23)
					ret = 1;
			}
		}
	}
	return ret == 0;
}

extern INV_T invt[] __asm__("inv");
extern int enemove_c_1p_max;
extern int enemove_c_2p_max;
void matchup_inv_reinforce_alloc(int pl)
{
	int i;
	int start = 0;
	int *s;

	if (pl == 5) {
		if (enemove_c_1p_max >= 0x18)
			return;
		enemove_c_1p_max += 8;
		start = 0x10;
	} else if (pl == 6) {
		if (enemove_c_2p_max >= 0x30)
			return;
		enemove_c_2p_max += 8;
		start = 0x28;
	}
	for (i = start; i < start + 8; i++) {
		s = invt[i].p;
		if (s) {
			s[3] |= 0xA;
			s[26] = s[10];
			s[27] = s[11];
		}
	}
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE04);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE08);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE0C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE10);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE14);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE18);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE1C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE20);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE24);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE28);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE2C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE30);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE34);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE38);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE3C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_match", D_0007CE40);
