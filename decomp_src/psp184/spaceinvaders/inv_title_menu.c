/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK inv_logo();                                 /* extern */
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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", inv_logo);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", inv_title_init);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_main_start);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_main_return);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_control);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_bg_star_start);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", title_bg_star_disp);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_title_menu", game_bg_disp);

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
