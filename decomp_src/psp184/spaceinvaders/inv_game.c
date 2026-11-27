/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int D_005FB738;
extern int D_005E860C;
extern signed char D_0035393C;
int tex_make(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern int D_005FB3B0;
M2C_UNK bmp_file_unload(int);                       /* extern */
M2C_UNK df_quake_control();                         /* extern */
M2C_UNK df_blur_disp();                             /* extern */
M2C_UNK df_cap_disp();                              /* extern */
M2C_UNK df_fade_disp();                             /* extern */
M2C_UNK df_flash_disp();                            /* extern */
extern unsigned char D_005FB76C;
extern int D_005FB784;
extern int D_005FB77C;
extern int D_005FB788;
M2C_UNK sprite_set(int, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, int, int, int, int, int, int, int, int, int, int, int); /* extern */
extern int D_004B4D04;
extern unsigned char D_005FB7A8;


extern int D_005A06D8;
extern int D_005E86B0;
extern int D_005E8F30;
extern int D_005EAB30;
extern int D_005FB714;
extern int D_005FB770;
extern int D_004B5010;
extern int game_cpu_disp;
extern int screen_blur;

extern int inv_status;
extern int load_disp;
extern int load_stage_pos;
extern int D_005FB44C;
extern int D_005FB78C;
extern float D_004B60A4;
extern char D_0007DF78[];
typedef struct { float x, y, z; } L2V3;
typedef struct {
	int f0;
	int f4;
	int f8;
	int fC;
	int f10;
	int f14;
	float f18;
	L2V3 p;
	L2V3 q;
} LASER2;
extern LASER2 laser2_w __asm__("D_005E860C");
int bmp_file_load16(char *name);
void debug_text(int x, int y, char *str);
void screen_capture(int buf, int mode);

#include "gmain.h"
#include "inv_game.h"
extern int D_005A06A8;
extern int D_004B500C;
extern int netdata;
M2C_UNK bmp_file_unload(int);
void gmo_file_unload(int no);
void inv_star_dispset(int f);
void sound_volume_set(int vol);
void sound_volume_set1(int vol);
int pos_fast_length_xyz_check(float x, float y, float z, float len);
void ziki_damage(void *z, float *pos);
int get_now_sound_block(void);

extern int D_005FB330;
typedef struct { u8 pad[0x188]; s8 a[32]; s8 b[32]; int c[32]; int d[32]; } STC_T;

extern int D_005E728C;
extern int D_003538BC;
void inv_laser_all_init(void);
void inv_laser_priset(void);
void inv_ring_all_init(void);
void inv_ring_priset(void);
void inv_laser_texno(int no);
void inv_ring_texno(int no);
typedef struct { int f0; u8 pad[0x98]; } LZ_T;
typedef struct { u8 f0; u8 pad[0x7F]; } RG_T;

extern int game_model_load;
extern u8 gmo[];
extern int PD_TBL[6] __asm__("D_005A06A8");
typedef struct { int f0; int f4; u8 pad[0x60]; } GMO_T;
typedef struct { u8 p0[0x10]; int f10; int f14; int f18; int f1C; u8 p1[0xD8 - 0x20]; } EUNIT_T;
typedef struct { int alive; u8 pad[0x40]; EUNIT_T u[4][11]; } ENEMY_T;

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", maingame_all_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", maingame_init);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DB9C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DBA0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DBAC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DBBC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DBD4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DBE4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DBF8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DC28);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DC30);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DC38);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DC44);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DC84);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DCDC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DCE0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DD18);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DD20);

/* local {x, y} initializer shared (one constant) by game_cnt_stageclear/gameover/dead/netdead */
typedef struct { int x, y; } POS2_T;
const POS2_T D_0007DD50 = { 240, 136 };

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DD58);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DD78);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DDE8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DE1C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DE30);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DE40);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DE48);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DE50);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DE70);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DE90);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DEA0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DEAC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DEB8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DEC4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DED0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DEDC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DEE8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DEF4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF00);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF0C);

/* cam_init's vector initializers (local aggregates in the original; a same-file const
   global reproduces both the code and the .rodata position). D_0007DF3C is an unused
   initializer whose constant was still emitted. */
typedef struct { float x, y, z; } V3;
const V3 D_0007DF18 = { 0.0f, 0.0f, -2800.0f };

const V3 D_0007DF24 = { -90.0f, 0.0f, 0.0f };

const V3 D_0007DF30 = { 0.0f, 700.0f, 0.0f };
const V3 D_0007DF3C = { 0.0f, 1.0f, 0.0f };

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF48);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF58);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF64);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF6C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF74);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF78);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF88);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF98);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", maingame_main);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", maingame_free);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", maingame_movie);

void dispeffect_all_free(void);
void maingame_all_free(void)
{
	int i;

	dispeffect_all_free();
	for (i = 0xF64 / 4; i < 0xF64 / 4 + 45; i++) {
		if (((int *)&gmain)[i] > 0)
			bmp_file_unload(((int *)&gmain)[i]);
	}
	sound_volume_set(0x8000);
	sound_volume_set1(0x8000);
}

void game_control(void)
{
	if (gmain.f.f0 == 1)
		game_cnt_title();
	else if (gmain.f.f0 == 2)
		game_cnt_option_3559C();
	else if (gmain.f.f0 == 3)
		game_cnt_option2();
	else if (gmain.f.f0 == 4)
		game_cnt_stagestart();
	else if (gmain.f.f0 == 5)
		game_cnt_game();
	else if (gmain.f.f0 == 6)
		game_cnt_pause();
	else if (gmain.f.f0 == 7)
		game_cnt_stageclear();
	else if (gmain.f.f0 == 8)
		game_cnt_result();
	else if (gmain.f.f0 == 9)
		game_cnt_gameover();
	else if (gmain.f.f0 == 10)
		game_cnt_dead();
	else if (gmain.f.f0 == 11)
		game_cnt_netdead();
	else if (gmain.f.f0 == 12)
		game_cnt_ending();
	else if (gmain.f.f0 == 13)
		game_cnt_nameentry();
	else if (gmain.f.f0 == 14)
		game_cnt_hiscore_3B97C();
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_title);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_option_3559C);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_option2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_stagestart);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_game);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_pause);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_stageclear);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_result);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_gameover);

extern int game_pause, D_005A06EC, D_003490D0, D_003490D4;
extern char *D_000828EC;
void beat_help_off(void);
int inv_netgame_linkcheck2(int st);
void inv_font_ascii_posf(char *str, int x, int y, int w, int h, int r, int g, int b, int a, int mode);
void poly_set(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
	int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7,
	int s8, int s9, int s10, int s11, int s12, int s13, int s14, int s15, int s16);
extern int D_003490C8, D_003490CC;
void se_stop(void);
int sound_stop(void);
int df_fade_check(void);
void df_fade_start(int a, int b, int c, int d, int e);
void game_cnt_dead(void)
{
	POS2_T pos = D_0007DD50;
	int st;

	st = gmain.f.f4;
	game_pause = 0;
	D_005A06EC = 1;
	gmain.f.f1058 = 0;
	gmain.f.f1068 = 0;
	gmain.f.f1070 = 0;
	if (st == 0) {
		if (gmain.f.f8 == 0) {
			beat_help_off();
			se_stop();
			gmain.f.f10ac = 14;
			gmain.f.f10b0 = 127;
			gmain.f.f10b4 = 127;
		}
		gmain.f.f8 += 8;
		if (gmain.f.f8 > 255)
			gmain.f.f8 = 255;
		D_003490CC = gmain.f.f8;
		D_003490C8 = gmain.f.f8;
		if (gmain.f.f8 == 255) {
			gmain.f.f8 = 0;
			gmain.f.f4++;
		}
	} else if (st == 1) {
		IST.f0--;
		if (IST.f0 > 0)
			gmain.f.f4 = 20;
		else
			gmain.f.f4 = 10;
	} else if (st == 10) {
		gmain.f.f8 += 8;
		if (gmain.f.f8 > 255)
			gmain.f.f8 = 255;
		D_003490CC = 255 - gmain.f.f8;
		D_003490C8 = 255 - gmain.f.f8;
		if (gmain.f.f8 == 255) {
			gmain.f.f4 = 11;
			gmain.f.f8 = 0;
		}
	} else if (st == 11) {
		gmain.f.f0 = 9;
		gmain.f.f4 = 0;
		gmain.f.f8 = 0;
		gmain.f.f1058 = 0;
	} else if (st == 20) {
		df_fade_start(0, 0, 0, 1, 60);
		gmain.f.f4++;
	} else if (st == 21) {
		if (df_fade_check())
			gmain.f.f4++;
	} else if (st == 22) {
		sound_stop();
		gmain.f.f105c = 1;
		gmain.f.f1060 = gmain.f.ff28;
		gmain.f.fc = 0;
	}
	if (D_003490C8 > 0)
		inv_font_ascii_posf(D_000828EC, pos.x, pos.y, 100, 100, 255, 255, 255, D_003490C8, 4);
	if (D_003490CC > 0)
		poly_set(0, 0, 480, 272, 0, 128, 128, 128, 255, 128, 128, 128, 255, 128, 128, 128, 255, 128, 128, 128, 255, 2000, 2, 2, D_003490CC);
}

extern const POS2_T D_0007DD50;
extern int game_pause, D_005A06EC, D_003490D0, D_003490D4;
extern char *D_000828EC;
void beat_help_off(void);
int inv_netgame_linkcheck2(int st);
void inv_font_ascii_posf(char *str, int x, int y, int w, int h, int r, int g, int b, int a, int mode);
void poly_set(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
	int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7,
	int s8, int s9, int s10, int s11, int s12, int s13, int s14, int s15, int s16);
void game_cnt_netdead(void)
{
	POS2_T pos = D_0007DD50;
	int st, r;

	st = gmain.f.f4;
	game_pause = 0;
	D_005A06EC = 1;
	gmain.f.f1058 = 0;
	gmain.f.f1068 = 0;
	gmain.f.f1070 = 0;
	if (st == 0) {
		if (gmain.f.f8 == 0) {
			beat_help_off();
			gmain.f.f10ac = 14;
			gmain.f.f10b0 = 127;
			gmain.f.f10b4 = 127;
		}
		gmain.f.f8 += 8;
		if (gmain.f.f8 > 255)
			gmain.f.f8 = 255;
		D_003490D4 = gmain.f.f8;
		D_003490D0 = gmain.f.f8;
		if (gmain.f.f8 == 255) {
			gmain.f.f8 = 0;
			gmain.f.f4++;
		}
	} else if (st == 1) {
		r = inv_netgame_linkcheck2(3);
		if (r == 1) {
			gmain.f.f0 = 9;
			gmain.f.f4 = 0;
			gmain.f.f8 = 0;
			gmain.f.f1058 = 0;
		} else if (r == 2) {
			gmain.f.f0 = 7;
			gmain.f.f4 = st;
			gmain.f.f8 = 0;
			gmain.f.f1058 = 0;
		}
	}
	if (D_003490D0 > 0)
		inv_font_ascii_posf(D_000828EC, pos.x, pos.y, 100, 100, 255, 255, 255, D_003490D0, 4);
	if (D_003490D4 > 0)
		poly_set(0, 0, 480, 272, 0, 128, 128, 128, 255, 128, 128, 128, 255, 128, 128, 128, 255, 128, 128, 128, 255, 2000, 2, 2, D_003490D4);
}



INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_ending);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", end_result_font_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_nameentry);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_hiscore_3B97C);

extern int D_005A0790[4][11][3];
extern int D_005E6F38[16];
extern int D_005A09B0[2];
extern int D_005A0CF0;
extern int D_005A06FC;
typedef struct { u8 p[0xEB78C]; int a[4]; u8 q[0xEB9B8 - 0xEB79C]; int b; } GMPC0_T;
#define GMPC0 (*(GMPC0_T *)&gmain)
void inv_polydisp_clear(void)
{
	int i, j, k, m, n, l;
	int *p;

	if (game_model_load == 0)
		return;
	p = PD_TBL;
	if (p[0] == 1) {
		for (l = 0; l < 5; l++)
			if (p[1 + l] >= 0)
				((GMO_T *)gmo)[p[1 + l]].f4 = 0;
		inv_star_dispset(0);
	}
	if (gmain.f.f1080 == 1 && D_005A06FC >= 0)
		((GMO_T *)gmo)[D_005A06FC].f4 = 0;
	if (gmain.f.f1084 == 1) {
		for (m = 0; m < 16; m++)
			if (D_005E6F38[m] >= 0)
				((GMO_T *)gmo)[D_005E6F38[m]].f4 = 0;
	}
	if (gmain.f.f1088 == 1) {
		for (i = 0; i < 4; i++) {
			GMPC0.a[i] = 0;
			for (j = 0; j < 11; j++) {
				int *z = D_005A0790[i][j];
				for (k = 0; k < 3; k++)
					if (z[k] >= 0)
						((GMO_T *)gmo)[z[k]].f4 = 0;
			}
		}
		GMPC0.b = 0;
		for (n = 0; n < 2; n++)
			if (D_005A09B0[n] >= 0)
				((GMO_T *)gmo)[D_005A09B0[n]].f4 = 0;
		if (gmain.f.ff28 == 13 && D_005A0CF0 >= 0)
			((GMO_T *)gmo)[D_005A0CF0].f4 = 0;
	}
	inv_laser_all_init();
	inv_ring_all_init();
}

void inv_polydisp_clear_off(void)
{
	int i;
	int *p;

	if (game_model_load == 0)
		return;
	p = PD_TBL;
	if (p[0] != 1)
		return;
	for (i = 0; i < 5; i++) {
		if (p[1 + i] >= 0)
			((GMO_T *)gmo)[p[1 + i]].f4 = 1;
	}
	inv_star_dispset(1);
}

extern int D_005A0790[4][11][3];
extern int D_005E6F38[16];
extern int D_005A09B0[2];
extern int D_005A0CF0;
extern int D_005A06FC;
typedef struct { u8 p[0xEB78C]; int a[4]; u8 q[0xEB9B8 - 0xEB79C]; int b; } GMPC_T;
#define GMPC (*(GMPC_T *)&gmain)
void inv_polydisp_clear2(void)
{
	int i, j, k, m, n;

	if (game_model_load == 0)
		return;
	if (gmain.f.f1080 == 1 && D_005A06FC >= 0)
		((GMO_T *)gmo)[D_005A06FC].f4 = 0;
	if (gmain.f.f1084 == 1) {
		for (m = 0; m < 16; m++)
			if (D_005E6F38[m] >= 0)
				((GMO_T *)gmo)[D_005E6F38[m]].f4 = 0;
	}
	if (gmain.f.f1088 == 1) {
		for (i = 0; i < 4; i++) {
			GMPC.a[i] = 0;
			for (j = 0; j < 11; j++) {
				int *z = D_005A0790[i][j];
				for (k = 0; k < 3; k++)
					if (z[k] >= 0)
						((GMO_T *)gmo)[z[k]].f4 = 0;
			}
		}
		GMPC.b = 0;
		for (n = 0; n < 2; n++)
			if (D_005A09B0[n] >= 0)
				((GMO_T *)gmo)[D_005A09B0[n]].f4 = 0;
		if (gmain.f.ff28 == 13 && D_005A0CF0 >= 0)
			((GMO_T *)gmo)[D_005A0CF0].f4 = 0;
	}
	inv_laser_all_init();
	inv_ring_all_init();
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bg_init);

typedef struct { int on; int gmo[5]; float rs[5]; } BG_T;
typedef struct { int f0, f4; u8 p8[0x2c - 8]; float rx, ry, rz; u8 p38[0x68 - 0x38]; } GMO_R;
void bg_control(void)
{
	BG_T *b = (BG_T *)PD_TBL;
	int i;
	GMO_R *g;

	if (b->on == 0)
		return;
	for (i = 0; i < 5; i++) {
		if (b->gmo[i] >= 0) {
			g = &((GMO_R *)gmo)[b->gmo[i]];
			g->ry += b->rs[i];
			while (g->ry < 0.0f)
				g->ry += 361.0f;
			while (g->ry > 360.0f)
				g->ry -= 361.0f;
		}
	}
}

void bg_free(void)
{
	int i;
	u8 *g;

	if (D_005A06A8 == 0)
		return;
	inv_star_dispset(0);
	g = (u8 *)&gmain;
	for (i = 0; i < 5; i++) {
		if (((int *)(g + 0xF3C))[i] != -1)
			bmp_file_unload(((int *)(g + 0xF3C))[i]);
		if (((int *)(g + 0xF50))[i] != -1)
			gmo_file_unload(((int *)(g + 0xF50))[i]);
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ziki_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ziki_control);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ziki_disp);

extern int D_005FB894;
void ziki_damage(void *zz, float *pos)
{
	u8 *z = zz;
	L2V3 v = *(L2V3 *)pos;
	u8 *st;

	if (D_005FB894 == 1)
		return;
	st = (u8 *)&inv_status;
	(*(int *)(st + 0x4C))++;
	if (*(int *)(st + 0x4C) > 2000000000)
		*(int *)(st + 0x4C) = 2000000000;
	*(int *)(z + 0x18) = 1;
	*(int *)(z + 0x2C) = 0;
	*(int *)(z + 0x8) = 1;
	*(int *)(z + 0x10) = 1;
	*(int *)(z + 0x14) = 1;
	status_font_set(1, 0x21, 0x78, 0, 0x14);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ziki_break_check);

int ziki_break_success_check(void)
{
	u8 *z = (u8 *)&D_005FB714;
	u8 *a = (u8 *)&D_005A06D8;

	if (*(int *)(z + 0x24) == 3 && *(int *)(z + 0x20) == 3 && *(int *)(z + 0x1C) >= 0) {
		if (*(int *)(a + 0x4C) >= 180)
			return 1;
	}
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ziki_break_errer_check(void) {
    return D_005FB738 < 2;
}

M2C_UNK ziki_beat_check(void)
{
	u8 *b_D_005A06D8 = (u8 *)&D_005A06D8;
	u8 *b_gmain = gmain.b;
	int ret;

	ret = 0;
	if ((*(int *)(b_D_005A06D8 + 0x30)) <= 0) {
		if ((unsigned)((*(int *)(b_gmain + 0x14676C)) - 45) >= 96) {
			if ((*(int *)(b_D_005A06D8 + 0x54)) > 0 && (*(int *)(b_D_005A06D8 + 0x58)) > 0 && (*(int *)(b_D_005A06D8 + 0x5C)) > 0)
				ret = (*(int *)(b_D_005A06D8 + 0x60)) > 0;
		}
	}
	return ret;
}

M2C_UNK ziki_beat_check2(void)
{
	u8 *b_D_005A06D8 = (u8 *)&D_005A06D8;
	int ret;

	ret = 0;
	if (*(int *)(b_D_005A06D8 + 0x54) > 0 && *(int *)(b_D_005A06D8 + 0x58) > 0 && *(int *)(b_D_005A06D8 + 0x5C) > 0) {
		ret = *(int *)(b_D_005A06D8 + 0x60) > 0;
	}
	return ret;
}

M2C_UNK ziki_beat_miss_check(void)
{
	u8 *b_D_005A06D8 = (u8 *)&D_005A06D8;
	int ret;

	ret = 0;
	if ((*(int *)(b_D_005A06D8 + 0x30)) <= 0) {
		if ((*(int *)(b_D_005A06D8 + 0x54)) > 0 && (*(int *)(b_D_005A06D8 + 0x58)) > 0 && (*(int *)(b_D_005A06D8 + 0x5C)) > 0) {
			ret = (*(int *)(b_D_005A06D8 + 0x60)) > 0;
		}
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_init_once);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_control_once);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_normal_anime);

typedef struct { int f0; float f4; int f8, fc; float f10; int f14, f18, f1c, f20; } STAGE_FORMAT;
extern STAGE_FORMAT stage_format[];
unsigned long genrand_int32(void);
int zako_shot_count(void)
{
	int n = (float)(genrand_int32() % 3000) * stage_format[gmain.f.ff28].f10;

	if (n < 180)
		n = 180;
	return n;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_shot);

float target_root_check(float base, float x, float w)
{
	float g = D_004B60A4;

	if (x < base - g * 0.5f)
		x += g;
	else if (base + g * 0.5f < x)
		x -= g;
	if (x < base - w)
		return base - w;
	if (base + w < x)
		return base + w;
	return base;
}

M2C_UNK target_area_check(float base, float x, float w)
{
	float g = D_004B60A4;

	if (x < base - g * 0.5f)
		x += g;
	else if (base + g * 0.5f < x)
		x -= g;
	if (x < base + w && base - w < x)
		return 1;
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_in_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_attack_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_start_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_end_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_disp);

typedef struct { int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c; float f40; int _p44[(0x6C - 0x44) / 4]; L2V3 pos; int _p78[2]; float f80; int _p84[(0x9C - 0x84) / 4]; L2V3 rot; } ZDO_T;
typedef struct { int f0, f4; u8 _p8[0x20 - 8]; L2V3 pos; L2V3 rot; u8 _p38[0x68 - 0x38]; } ZDO_GMO;
typedef struct { u8 p[0xEB78C]; int cnt[7]; int gmo[7][11][3]; } ZDO_GM;
#define ZDOG (*(ZDO_GM *)&gmain)
extern int zako_gmo_w[][11][3] __asm__("D_005A0790");
extern unsigned char zako_type_color[][4];
int sprite_set_3d(int tex, int a1, int r, int g, int b, int a, int f64, int f18, float x, float y, float z, float u0, float v0, float u1, float v1, float f48, float f4c, float f50, int f1c);
void gmo_anime_direct(int no, int a1, float f);
void zako_disp_once(ENEMY *p)
{
	int lod, g;
	int *row;
	ZDO_GMO *m;
	ZDO_T *e = (ZDO_T *)p;

	if (ZDOG.cnt[e->f30] >= 11)
		return;
	if (e->f3c == 0)
		return;
	if (e->f18 == 5)
		return;
	if (e->f4 == 1)
		return;
	lod = 2;
	if (e->f80 < 850.0f)
		lod = 0;
	else if (e->f80 < 1150.0f)
		lod = 1;
	row = zako_gmo_w[e->f30][ZDOG.cnt[e->f30]];
	g = row[lod];
	if (g < 0)
		return;
	m = &((ZDO_GMO *)gmo)[g];
	m->pos = e->pos;
	m->f4 = 1;
	m->rot = e->rot;
	if (e->f28 == 0)
		m->rot.y += e->f2c;
	else
		m->rot.y -= e->f2c;
	if (lod < 2 && e->f40 != 0.0f)
		gmo_anime_direct(row[lod], 0, e->f40);
	sprite_set_3d(gmain.f.ff64[3], 0, zako_type_color[e->f30][0], zako_type_color[e->f30][1], zako_type_color[e->f30][2], zako_type_color[e->f30][3], 4 - e->f0, 2,
		e->pos.x, e->pos.y, e->pos.z, texpos_inv_effect[64].w, texpos_inv_effect[64].h, texpos_inv_effect[64].u, texpos_inv_effect[64].v, 3.0f, 3.0f, 0, e->fc);
	ZDOG.cnt[e->f30]++;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_death);

void efc_bom2_start(float x, float y, float z);
void se_play_3d(int no, float *pos, float dist);
void zako_shot(ENEMY *e);
void zako_damage(ENEMY *e, int dmg, int a, int b)
{
	if (e->dead == 1)
		return;
	IST.f20++;
	if (IST.f20 > 2000000000)
		IST.f20 = 2000000000;
	e->f2c = 0;
	e->dmg += dmg;
	e->f28 = genrand_int32() & 1;
	if (e->dmg < e->hp) {
		if (e->disp == 1) {
			efc_bom2_start(e->x, e->y, e->z);
			se_play_3d(16, &e->x, 7000.0f);
		}
		if (IST.fc >= 3)
			zako_shot(e);
	} else {
		zako_death(e, a, b);
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_mov_count);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_init_once);

extern int game_count;
void netgame_ufo_pos_set(int no, float x);
void netgame_ufo_life_set(int no, int life, int n);
void ufo_control(void)
{
	int i;
	int *u;

	if (gmain.f.feb9d0 == 0)
		return;
	if (gmain.f.f1088 == 0)
		return;
	for (i = 0; i < gmain.f.feb9d0; i++) {
		u = UFO_W(i);
		ufo_control_once(u);
		if (game_count % 5 == 0)
			netgame_ufo_pos_set(i, ((float *)u)[17]);
		else if (game_count % 5 == 1)
			netgame_ufo_life_set(i, u[9], 0);
		else if (game_count % 5 == 2)
			netgame_ufo_life_set(i, u[9], 1);
		else if (game_count % 5 == 3)
			netgame_ufo_life_set(i, u[9], 2);
		else if (game_count % 5 == 4)
			netgame_ufo_life_set(i, u[9], 3);
	}
}

void ufo_normal_anime(int *u);
void ufo_dead_anime(int *u);
void ufo_warpin_anime(int *u);
void ufo_warpout_anime(int *u);
void ufo_control_once(int *u)
{
	if (u[2] == 1)
		return;
	if (u[11] > 0)
		u[11]--;
	if (u[13] == 0) {
		ufo_normal_anime(u);
	} else if (u[13] == 2) {
		ufo_warpin_anime(u);
	} else if (u[13] == 3) {
		ufo_warpout_anime(u);
	} else if (u[13] == 1) {
		ufo_dead_anime(u);
	} else if (u[5] == 1 && genrand_int32() % 300 == 0) {
		u[13] = 2;
		((float *)u)[17] = ((float *)u)[21];
		u[14] = 0;
		u[12] = 0;
	}
	ufo_tex_anime(u);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_normal_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_warpin_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_warpout_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_dead_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_disp_once);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_damage);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_all_dead_check);

void ufo_tex_anime(int *u)
{
	int n;

	if (u[2] == 1)
		return;
	if (u[1] == 0)
		return;
	if (u[9] >= u[10] * 4 / 5)
		n = 4;
	else if (u[9] >= u[10] * 3 / 5)
		n = 3;
	else if (u[9] >= u[10] * 2 / 5)
		n = 2;
	else if (u[9] >= u[10] / 5)
		n = 1;
	else
		n = 0;
	if (u[8] > 0) {
		n += u[8] / 8 + 1;
		u[8]--;
	}
	if (n > 4)
		n = 4;
	u[7] = n;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", boss_ufo_init);

extern int bufo_w[] __asm__("D_005A0CF4");
void bufo_in_anime(u8 *u);
void bufo_r_move_anime(void *u);
void bufo_l_move_anime(void *u);
void bufo_b_move_anime(void *u);
void bufo_f_move_anime(void *u);
void bufo_enemy_start(void *u);
void bufo_dead_anime(void *u);
void bufo_move(void *u);
void boss_ufo_tex_anime(int *u);
void boss_ufo_control(void)
{
	int *u;

	if (gmain.f.f1088 == 0)
		return;
	if (gmain.f.ff28 != 13)
		return;
	u = bufo_w;
	if (u[1] == 1)
		return;
	if (u[6] > 0)
		u[6]--;
	if (u[12] == 2)
		bufo_in_anime((u8 *)u);
	else if (u[12] == 5) {
		bufo_r_move_anime(u);
		bufo_enemy_start(u);
	} else if (u[12] == 6) {
		bufo_l_move_anime(u);
		bufo_enemy_start(u);
	} else if (u[12] == 8) {
		bufo_b_move_anime(u);
		bufo_enemy_start(u);
	} else if (u[12] == 7) {
		bufo_f_move_anime(u);
		bufo_enemy_start(u);
	} else if (u[12] == 1)
		bufo_dead_anime(u);
	bufo_move(u);
	boss_ufo_tex_anime(u);
	if (game_count % 5 == 0)
		netgame_ufo_pos_set(0, ((float *)u)[18]);
	else if (game_count % 5 == 1)
		netgame_ufo_life_set(0, u[8], 0);
	else if (game_count % 5 == 2)
		netgame_ufo_life_set(0, u[8], 1);
	else if (game_count % 5 == 3)
		netgame_ufo_life_set(0, u[8], 2);
	else if (game_count % 5 == 4)
		netgame_ufo_life_set(0, u[8], 3);
}

void bufo_in_anime(u8 *u)
{
	if (*(int *)(u + 0x34) == 0) {
		*(int *)(u + 0x8) = 1;
		*(int *)(u + 0x38) = 1;
		*(int *)(u + 0x34) = 1;
	} else if (*(int *)(u + 0x34) == 1) {
		if (*(float *)(u + 0x5C) <= 7000.0f)
			*(int *)(u + 0x34) = 2;
	} else {
		*(int *)(u + 0x30) = 5;
		*(int *)(u + 0x34) = 0;
		*(int *)(u + 0x28) = 0;
		*(int *)(u + 0x8) = 0;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bufo_enemy_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bufo_move);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bufo_r_move_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bufo_l_move_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bufo_b_move_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bufo_f_move_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bufo_dead_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", boss_ufo_disp);

typedef struct { float x, y, z; } BV3;
typedef struct {
	int f0, f4, f8, fc, f10, f14, f18, f1c;
	int dmg, hp, f28, f2c, f30, f34, f38, f3c;
	int f40, f44;
	float f48, f4c;
	int f50[5];
	float pos[3];
} BUFO_D;
void efc_ufohit_start(int dmg, float a, float x, float y, float z);
void se_play_3d(int no, float *pos, float dist);
void boss_ufo_damage(BUFO_D *u, BV3 p, int dmg, int net, int flag)
{
	if (u->f4 == 1)
		return;
	u->dmg += dmg;
	if (u->dmg >= u->hp) {
		status_font_set(1, 32, 300, 0, 100);
		u->f34 = 0;
		u->f28 = 0;
		u->f30 = 1;
		if (net == 0)
			inv_score_add(1000000);
	}
	u->f40++;
	u->f4c = 0;
	u->f14 = 16;
	u->f18 = 60;
	if (u->f0 == 1 && flag == 1) {
		se_play_3d(23, u->pos, u->f4c);
		efc_ufohit_start(dmg, u->f48, p.x, p.y, p.z);
	}
}

void boss_ufo_tex_anime(int *u)
{
	int n;

	if (u[1] == 1)
		return;
	if (u[0] == 0)
		return;
	if (u[8] >= u[9] * 4 / 5)
		n = 4;
	else if (u[8] >= u[9] * 3 / 5)
		n = 3;
	else if (u[8] >= u[9] * 2 / 5)
		n = 2;
	else if (u[8] >= u[9] / 5)
		n = 1;
	else
		n = 0;
	if (u[5] > 0) {
		n += u[5] / 8 + 1;
		u[5]--;
	}
	if (n > 4)
		n = 4;
	u[4] = n;
}

typedef struct { u8 b[0xD8]; } ZAKO_W;
typedef struct {
	int f0, f4;
	float x0, x1;
	int n, f14;
	float x[11];
	ZAKO_W z[4][11];
} EGP_T;
extern EGP_T D_005A0D80[30];
typedef struct { u8 p[0xEBD94]; int n; } GMEG_T;
#define GMEG_N ((*(GMEG_T *)&gmain).n)
void zako_init_once(void *z, int i, int type, int j, float x);
void enemy_gp_init(void)
{
	int i, j, k, l, x;
	EGP_T *e;
	float x0, x1;

	GMEG_N = 0;
	for (i = 0; i < 30; i++)
		D_005A0D80[i].f0 = 0;
	if (gmain.f.f1088 == 0)
		return;
	GMEG_N = 0;
	for (i = 0, x = 0; i < 30; i++, x += 90) {
		x1 = x + 70;
		x0 = x;
		if (gmain.f.f10bc < x1)
			return;
		e = &D_005A0D80[i];
		e->f0 = 1;
		e->f4 = 1;
		e->x0 = x0;
		e->x1 = x1;
		e->n = 0;
		e->f14 = 0;
		for (l = 0; l < 11; l++)
			e->x[l] = (10 - l) * (e->x1 - e->x0) / 11.0f + e->x0;
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 11; k++) {
				zako_init_once(&e->z[j][k], i, (i + j) % 4, j, e->x[k]);
				e->n++;
			}
		}
		GMEG_N++;
	}
}

void zako_control_once(ENEMY *e);
extern float cam_f4c __asm__("D_005FB37C");
void enemy_gp_control(void)
{
	int r[2];
	int wrap;
	int i, j, k;
	EGP_T *g;
	ENEMY *e;

	if (gmain.f.f1088 == 0)
		return;
	wrap = 0;
	r[1] = r[0] = cam_f4c;
	while (r[0] <= 0)
		r[0] += gmain.f.f10bc - 0.0f;
	while (r[0] >= gmain.f.f10bc)
		r[0] -= gmain.f.f10bc - 0.0f;
	while (r[1] <= 0)
		r[1] += gmain.f.f10bc - 0.0f;
	while (r[1] >= gmain.f.f10bc)
		r[1] -= gmain.f.f10bc - 0.0f;
	if (r[0] < gmain.f.f10bc - 40 && 40 < r[0]) {
		r[0] -= 40;
		r[1] += 40;
	} else {
		wrap = 1;
		if (gmain.f.f10bc - 40 <= r[0]) {
			r[0] -= 40;
			r[1] += 40 - gmain.f.f10bc;
		} else {
			r[0] -= 40 - gmain.f.f10bc;
			r[1] += 40;
		}
	}
	for (i = 0; i < gmain.f.febd94; i++) {
		g = &D_005A0D80[i];
		if (g->f0 == 0)
			return;
		g->f4 = 1;
		if (wrap == 0) {
			if (g->x1 < r[0] || r[1] < g->x0)
				g->f4 = 0;
		} else {
			if (r[1] <= g->x0 && g->x1 <= r[0])
				g->f4 = 0;
		}
		g->f14 = 0;
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 11; k++) {
				e = (ENEMY *)&g->z[j][k];
				zako_control_once(e);
				if (e->dead == 1)
					g->f14++;
			}
		}
	}
}

void zako_disp_once(ENEMY *e);
void enemy_gp_disp(void)
{
	int i, j, k;
	EGROUP *g;
	ENEMY *e;

	if (gmain.f.f1088 == 0)
		return;
	for (i = 0; i < gmain.f.febd94; i++) {
		g = &egroup[i];
		if (g->active == 0)
			return;
		if (g->disp == 0)
			continue;
		for (j = 0; j < 4; j++) {
			e = g->e[j];
			for (k = 0; k < 11; k++, e++)
				zako_disp_once(e);
		}
	}
}

void enemy_gp_start(int line)
{
	int i, k;
	EGROUP *g;
	ENEMY *e;

	if (gmain.f.f1088 == 0)
		return;
	for (i = 0; i < gmain.f.febd94; i++) {
		g = &egroup[i];
		if (g->active == 0)
			return;
		e = (ENEMY *)(line * sizeof(g->e[0]) + (int)g->e);
		for (k = 0; k < 11; k++, e++) {
			e->f18 = 2;
			e->f1c = 0;
			e->f10 = 0;
		}
	}
}

void enemy_gp_end(void)
{
	int i, j, k;
	EGROUP *g;
	ENEMY *e;

	if (gmain.f.f1088 == 0)
		return;
	for (i = 0; i < gmain.f.febd94; i++) {
		g = &egroup[i];
		if (g->active == 0)
			return;
		for (j = 0; j < 4; j++) {
			e = g->e[j];
			for (k = 0; k < 11; k++, e++) {
				e->f18 = 3;
				e->f1c = 0;
				e->f10 = 0;
			}
		}
	}
}

void zako_death(ENEMY *e, int a, int b);
void enemy_gp_dead(void)
{
	int i, j, k;
	EGROUP *g;
	ENEMY *e;

	if (gmain.f.f1088 == 0)
		return;
	for (i = 0; i < gmain.f.febd94; i++) {
		g = &egroup[i];
		if (g->active == 0)
			return;
		for (j = 0; j < 4; j++) {
			e = g->e[j];
			for (k = 0; k < 11; k++, e++)
				zako_death(e, 0, 0);
		}
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", shield_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", shield_control);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", shield_update);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", shield_disp);

void shield_damage(u8 *p, int n)
{
	int dummy[2];

	*(int *)(p + 0xC) = 1;
	*(int *)(p + 0x10) = 0;
}

void laser_init(void)
{
	int i;
	u8 *g;

	inv_laser_all_init();
	inv_laser_priset();
	inv_ring_all_init();
	inv_ring_priset();
	for (i = 0; i < 32; i++)
		((LZ_T *)&D_005E728C)[i].f0 = 0;
	g = gmain.b;
	inv_laser_texno(*(int *)(g + 0xF70));
	inv_ring_texno(*(int *)(g + 0xF70));
	for (i = 1; i < 3; i++)
		((RG_T *)&D_003538BC)[i].f0 = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", laser_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", laser_control);

extern int D_005FB890;
extern int rank_shot_attack[][2];
int bgm_rank(void);
int hit_check_enemy(float *pos, int dmg, int flag, float r);
int hit_check_ufo(float *pos, int dmg, float r);
int hit_check_shield(float *pos, float r);
int hit_check_player(float *pos, float r);
void inv_laser_end(int no);
void efc_shot_del(float x, float y, float z);
typedef struct { u8 pad[0x64]; int atk; } ZIKI_ATK;
void laser_hit_check(int *l)
{
	int atk, dmg;
	float r;

	if (l[2] == 0) {
		if (hit_check_enemy((float *)&l[9], 2, 1, 15.0f) >= 0) {
			IST.f30++;
			if (IST.f30 > 2000000000)
				IST.f30 = 2000000000;
			l[0] = 0;
			inv_laser_end(l[1]);
		}
	} else if (l[2] == 4) {
		if (hit_check_enemy((float *)&l[9], 1, 1, 15.0f) >= 0) {
			IST.f30++;
			if (IST.f30 > 2000000000)
				IST.f30 = 2000000000;
			l[0] = 0;
			inv_laser_end(l[1]);
		}
	} else if (l[2] == 1) {
		if (hit_check_shield((float *)&l[9], 15.0f) >= 0 || hit_check_player((float *)&l[9], 10.0f) >= 0) {
			l[0] = 0;
			inv_laser_end(l[1]);
			efc_shot_del(((float *)l)[9], ((float *)l)[10], ((float *)l)[11]);
		}
	} else if (l[2] == 2) {
		atk = ((ZIKI_ATK *)&D_005A06D8)->atk;
		if (D_005FB890 == 1)
			atk = 0;
		dmg = rank_shot_attack[bgm_rank()][0] * ((ZIKI_ATK *)&D_005A06D8)->atk;
		r = (int)((bgm_rank() + 1) * 15.0f * 5.0f * 0.125f + 15.0f);
		if (hit_check_enemy((float *)&l[9], dmg, atk, r) >= 0)
			l[3]++;
		if (hit_check_ufo((float *)&l[9], dmg, 200.0f) >= 0) {
			l[0] = 0;
			l[3]++;
			inv_laser_end(l[1]);
		}
	}
}

typedef struct { float x, y, z; } LDV;
typedef struct { int f0, f4; u8 _p8[0x20 - 8]; float f20; LDV pos; LDV f30; LDV p[8]; } LD_T;
typedef struct { int f0, f4; u8 _p8[0x28 - 8]; float f28; u8 _p2c[0x7C - 0x2C]; LDV pos; LDV v[8]; } LDI_T;
extern LDI_T inv_laser_w[] __asm__("inv_laser");
void laser_disp(void)
{
	int i, j;
	LD_T *l;

	for (i = 0; i < 32; i++) {
		l = &((LD_T *)&D_005E728C)[i];
		if (l->f0 == 0)
			continue;
		inv_laser_w[l->f4].pos = l->pos;
		inv_laser_w[l->f4].f4 = 1;
		inv_laser_w[l->f4].f28 = l->f20;
		for (j = 0; j < 8; j++)
			inv_laser_w[l->f4].v[j] = l->p[j];
	}
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void laser2_init(void) {
    D_005E860C = 0;
}

void laser2_start(float a, float x, float y, float z)
{
	laser2_w.f0 = 1;
	laser2_w.f18 = a;
	laser2_w.p.x = x;
	laser2_w.p.y = y;
	laser2_w.p.z = z;
	laser2_w.q = laser2_w.p;
	laser2_w.f10 = 0;
	laser2_w.fC = 0;
}

void laser2_c_set(float a, float x, float y, float z)
{
	laser2_w.p.x = x;
	laser2_w.p.y = y;
	laser2_w.p.z = z;
	laser2_w.q = laser2_w.p;
	laser2_w.f18 = a;
}

void laser2_start2(void)
{
	u8 *b_D_005E860C = (u8 *)&D_005E860C;
	*(int *)(b_D_005E860C + 0xC) = 1;
	*(int *)(b_D_005E860C + 0x10) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void laser2_end(void) {
    D_0035393C = 0;
    D_005E860C = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", laser2_control);

M2C_UNK laser2_end_check(void)
{
	if (laser2_w.f0 == 0)
		return 1;
	if (laser2_w.fC == 2 && laser2_w.f10 >= 30)
		return 1;
	return 0;
}

void netgame_zako_dead_set(int i, int j, int k);
int laser2_hit_check_enemy(float x, float w)
{
	int i, j, k;
	int ret = 0, wrap = 0, hit;
	float r[2];
	EGROUP *g;
	ENEMY *e;

	r[0] = x;
	r[1] = x;
	if (x < gmain.f.f10bc - w && w < x) {
		r[0] = x - w;
		r[1] = x + w;
	} else {
		wrap = 1;
		if (gmain.f.f10bc - w <= r[0]) {
			r[0] = r[0] - w;
			r[1] = r[1] + (w - gmain.f.f10bc);
		} else {
			r[0] = r[0] - (w - gmain.f.f10bc);
			r[1] = r[1] + w;
		}
	}
	for (i = 0; i < GMEG_N; i++) {
		g = &egroup[i];
		if (g->active == 0)
			break;
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 11; k++) {
				e = &g->e[j][k];
				if (e->dead == 1)
					continue;
				hit = 1;
				if (wrap == 0) {
					if (e->f68 < r[0] || r[1] < e->f68)
						hit = 0;
				} else {
					if (r[1] <= e->f68 && e->f68 <= r[0])
						hit = 0;
				}
				if (hit) {
					zako_death(e, save_data.fd8 == 0, 0);
					ret = 1;
					netgame_zako_dead_set(i, j, k);
				}
			}
		}
	}
	return ret;
}

void ufo_damage(void *u, BV3 p, int dmg, int net, int flag);
void netgame_ufo_damage_set3(int no, int dmg, int life) __asm__("netgame_ufo_damage_set");
typedef struct { u8 p[0xEB9D0]; int n; } GMU4_T;
#define GMU4_N ((*(GMU4_T *)&gmain).n)
extern BUFO_D D_005A0CF4;
int laser2_hit_check_ufo(float x, float w)
{
	int i, hit;
	int ret = 0, wrap = 0;
	float r[2];
	UFO_T *u;
	BUFO_D *b;

	r[0] = x;
	r[1] = x;
	if (x < gmain.f.f10bc - w && w < x) {
		r[0] = x - w;
		r[1] = x + w;
	} else {
		wrap = 1;
		if (gmain.f.f10bc - w <= r[0]) {
			r[0] = r[0] - w;
			r[1] = r[1] + (w - gmain.f.f10bc);
		} else {
			r[0] = r[0] - (w - gmain.f.f10bc);
			r[1] = r[1] + w;
		}
	}
	if (gmain.f.ff28 != 13) {
		for (i = 0; i < GMU4_N; i++) {
			u = &ufo_t[i];
			if (u->f[1] == 0)
				continue;
			if (u->f[2] == 1)
				continue;
			if (u->f[4] == 1)
				continue;
			if (u->f[13] == 1)
				continue;
			hit = 1;
			if (wrap == 0) {
				if (((float *)u->f)[17] < r[0] || r[1] < ((float *)u->f)[17])
					hit = 0;
			} else {
				if (r[1] <= ((float *)u->f)[17] && ((float *)u->f)[17] <= r[0])
					hit = 0;
			}
			if (hit) {
				int dmg = rank_shot_attack[bgm_rank()][1];
				ufo_damage(u, *(BV3 *)&u->f[0x5C / 4], dmg, 0, 1);
				netgame_ufo_damage_set3(i, dmg, u->f[9]);
			}
		}
	} else {
		b = &D_005A0CF4;
		if (b->f0 == 0)
			return ret;
		if (b->f4 == 1)
			return ret;
		if (b->f8 == 1)
			return ret;
		if (b->f30 == 1)
			return ret;
		hit = 1;
		if (wrap == 0) {
			if (b->f48 < r[0] || r[1] < b->f48)
				hit = 0;
		} else {
			if (r[1] <= b->f48 && b->f48 <= r[0])
				hit = 0;
		}
		if (hit) {
			int dmg;
			ret = 1;
			dmg = rank_shot_attack[bgm_rank()][1];
			boss_ufo_damage(b, *(BV3 *)b->pos, dmg, 0, 1);
			netgame_ufo_damage_set3(0, dmg, b->dmg);
		}
	}
	return ret;
}

void boss_laser_init(void)
{
	int i;
	int *p = &D_005E86B0;

	for (i = 0; i < 32; i++) {
		*p = 0;
		p += 0x11;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", boss_laser_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", boss_laser_control);

void item_init(void)
{
	int i;
	int *p = &D_005E8F30;

	for (i = 0; i < 128; i++) {
		*p = 0;
		p += 0xE;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", item_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", item_control);

void particle_init(void)
{
	int i;
	int *p = &D_005EAB30;

	for (i = 0; i < 512; i++) {
		p[4] = i;
		p[0] = 0;
		p += 0x21;
	}
}

typedef struct {
	int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28;
	float f2c, f30;
	int f34, f38, f3c, f40;
	float f44, f48, f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c, f80;
} PARTICLE2;
int particle_set(int tex, int no)
{
	int i;
	PARTICLE2 *p;

	for (i = 0; i < 512; i++) {
		p = &((PARTICLE2 *)&D_005EAB30)[i];
		if (p->f0 == 0)
			break;
	}
	if (i >= 512)
		return -1;
	p->f0 = 1;
	p->f18 = tex;
	p->f4 = 0;
	p->f8 = 0;
	p->fc = 0;
	p->f14 = 0;
	p->f1c = texpos_inv_effect[no].u;
	p->f20 = texpos_inv_effect[no].v;
	p->f24 = texpos_inv_effect[no].w;
	p->f28 = texpos_inv_effect[no].h;
	p->f2c = 255.0f;
	p->f30 = 0;
	p->f34 = 255;
	p->f38 = 255;
	p->f3c = 255;
	p->f44 = 0;
	p->f48 = 0;
	p->f4c = 0;
	p->f50 = 0;
	p->f54 = 0;
	p->f58 = 0;
	p->f5c = 1.0f;
	p->f60 = 1.0f;
	p->f64 = 0;
	p->f68 = 0;
	p->f6c = 0;
	p->f70 = 0;
	p->f74 = 0;
	p->f78 = 0;
	p->f7c = 0;
	p->f80 = 0;
	return i;
}

typedef struct {
	int f0, f4, f8, fc, f10, f14;
	u8 _p18[0x2C - 0x18];
	float f2c, f30;
	u8 _p34[0x44 - 0x34];
	float f44, f48, f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c, f80;
} PARTICLE;
#define PTC ((PARTICLE *)&D_005EAB30)
void particle_control(void)
{
	int i;
	PARTICLE *p;

	for (i = 0; i < 512; i++) {
		p = &PTC[i];
		if (p->f0 == 0)
			continue;
		if (p->f14) {
			p->f14--;
			continue;
		}
		p->f2c += p->f30;
		if (p->f2c <= 0.0f) {
			p->f0 = 0;
			continue;
		}
		p->f5c += p->f64;
		p->f60 += p->f68;
		if (p->f5c < 0.0f || p->f60 < 0.0f) {
			p->f0 = 0;
			continue;
		}
		p->f44 += p->f50;
		p->f48 += p->f54;
		p->f4c += p->f58;
		if (p->f4) {
			p->f6c += p->f78;
			p->f70 += p->f7c;
			p->f74 += p->f80;
		}
	}
}

void mat_local2screen(V3 *v, V3 *o);
void inv_screffect_start(int x, int y, int z, int w, int h, int u, int v, float sx, float sy, int r, int g, int b, int a);
void inv_screffect_start2(int x, int y, int w, int h, int u, int v, int r, int g, float sx, float sy, int b, int a);
void sprite_set_3d_efc_rot(int tex, int a1, float x, float y, float z, int r, int g, int b, int c0, int c1, int c2, float u0, float v0, float u1, float v1, float sx, float sy, float rx, float ry, float rz, int a);
void particle_disp(void)
{
	int i, a;
	PARTICLE2 *p;
	V3 v;

	for (i = 0; i < 512; i++) {
		p = &((PARTICLE2 *)&D_005EAB30)[i];
		if (p->f0 == 0)
			continue;
		if (p->f14 != 0)
			continue;
		if (p->f2c <= 0.0f)
			continue;
		if (p->f5c <= 0.0f)
			continue;
		if (p->f60 <= 0.0f)
			continue;
		a = p->f2c;
		if (a > 255)
			a = 255;
		if (p->fc == 0) {
			if (p->f4 == 0) {
				if (p->f8 == 0) {
					mat_local2screen((V3 *)&p->f44, &v);
					inv_screffect_start(v.x, v.y, v.z, p->f24, p->f28, p->f1c, p->f20, p->f5c, p->f60, p->f34, p->f38, p->f3c, a);
				} else {
					inv_screffect_start(p->f44, p->f48, p->f4c, p->f24, p->f28, p->f1c, p->f20, p->f5c, p->f60, p->f34, p->f38, p->f3c, a);
				}
			} else {
				sprite_set_3d_efc_rot(p->f18, 0, p->f44, p->f48, p->f4c, p->f34, p->f38, p->f3c, 255, 100, 2, p->f24, p->f28, p->f1c, p->f20, p->f5c, p->f60, p->f6c, p->f70, p->f74, a);
			}
		} else {
			inv_screffect_start2(p->f44, p->f48, p->f24, p->f28, p->f1c, p->f20, p->f34, p->f38, p->f5c, p->f60, p->f3c, a);
		}
	}
}

M2C_UNK particle_check(int no)
{
	if ((unsigned)no >= 512)
		return 1;
	return (&D_005EAB30)[no * 0x21] == 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", efc_bom_start);

extern const double D_0007E7F8, D_0007E800, D_0007E808, D_0007E810, D_0007E818;
double genrand_real2(void);
double genrand_real3(void);
void efc_bom2_start(float x, float y, float z)
{
	int i, n;
	PARTICLE *p;

	for (i = 0; i < 8; i++) {
		n = particle_set(gmain.f.ff64[3], 0x30);
		if (n < 0)
			continue;
		p = &PTC[n];
		p->f14 = 8;
		p->f2c = genrand_real2() * D_0007E7F8 + D_0007E7F8;
		p->f30 = -(genrand_real2() * D_0007E800 + D_0007E800);
		p->f44 = x;
		p->f48 = y;
		p->f4c = z;
		p->f50 = (genrand_real3() - D_0007E808) * D_0007E810;
		p->f54 = (genrand_real3() - D_0007E808) * D_0007E810;
		p->f58 = (genrand_real3() - D_0007E808) * D_0007E810;
		p->f60 = p->f5c = genrand_real2() * D_0007E808 + D_0007E818;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", efc_laser_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", efc_ufohit_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", efc_shot_del);

typedef struct {
	int f0, f4, f8, fc, f10, f14;
	V3 eye, f24, f30;
	int f3c;
	V3 f40;
	float f4c, f50, f54, f58, f5c;
} CAMERA;
#define CAM (*(CAMERA *)&D_005FB330)
extern float camera_mode[4];
void cam_init(void)
{
	CAM.f0 = 0;
	{
		V3 v = D_0007DF18;
		CAM.eye = v;
	}
	{
		V3 v = D_0007DF24;
		CAM.f30 = v;
	}
	CAM.f50 = camera_mode[0];
	CAM.f54 = camera_mode[1];
	CAM.f58 = camera_mode[2];
	CAM.f5c = camera_mode[3];
	CAM.f3c = 1;
	{
		V3 v = D_0007DF30;
		CAM.f40 = v;
	}
	CAM.f24.x = 0;
	CAM.f24.y = 0;
	CAM.f24.z = 0;
	CAM.f8 = 0;
	CAM.fc = 0;
	CAM.f4c = stage_format[gmain.f.ff28].f4;
	CAM.f14 = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", cam_control);

#ifndef NULL
#define NULL ((void *)0)
#endif

void dispeffect_all_init(void) {
    D_005FB3B0 = tex_make(5, 0, 0x100, 0x100);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void dispeffect_all_free(void) {
    if (D_005FB3B0 >= 0) {
        bmp_file_unload(D_005FB3B0);
    }
}

void dispeffect_init(void)
{
	u8 *d = (u8 *)&D_005FB3B0;

	screen_blur = 0;
	*(int *)(d + 0x10) = 0;
	*(int *)(d + 0x4) = 0;
	*(int *)(d + 0x8) = 0;
	*(int *)(d + 0xC) = 0;
	*(int *)(d + 0x14) = 0;
	*(int *)(d + 0x18) = 0;
	*(int *)(d + 0x1C) = 0;
	*(int *)(d + 0x20) = 0;
	*(int *)(d + 0x24) = 0;
	*(int *)(d + 0x28) = 0;
	*(int *)(d + 0x2C) = 0;
	*(int *)(d + 0x30) = 0;
	*(int *)(d + 0x34) = 0;
	*(int *)(d + 0x38) = 0;
	*(int *)(d + 0x3C) = 0;
	*(int *)(d + 0x40) = 0;
	*(int *)(d + 0x44) = 0;
	*(int *)(d + 0x48) = 0;
	*(int *)(d + 0x4C) = 0;
	*(int *)(d + 0x50) = 0;
	*(int *)(d + 0x54) = 0;
	*(int *)(d + 0x58) = 0;
	*(int *)(d + 0x5C) = 0;
	*(int *)(d + 0x60) = 0;
	*(int *)(d + 0x64) = 0;
	*(int *)(d + 0x68) = 0;
	*(int *)(d + 0x6C) = 0;
	*(int *)(d + 0x70) = 0;
	*(int *)(d + 0x74) = 0;
	*(int *)(d + 0x78) = 0;
	*(int *)(d + 0x7C) = 0;
	*(int *)(d + 0x80) = 0;
	*(int *)(d + 0x84) = 0;
	*(int *)(d + 0x88) = 0;
	*(int *)(d + 0x8C) = 0;
	*(int *)(d + 0x90) = 0;
	*(int *)(d + 0x94) = 0;
	*(int *)(d + 0x98) = 0;
}

void df_quake_start(int a, int t)
{
	u8 *b_D_005FB3B0 = (u8 *)&D_005FB3B0;
	if (t < *(int *)(b_D_005FB3B0 + 0xC) - *(int *)(b_D_005FB3B0 + 0x8))
		return;
	*(int *)(b_D_005FB3B0 + 0xC) = t;
	*(int *)(b_D_005FB3B0 + 0x4) = a;
	*(int *)(b_D_005FB3B0 + 0x8) = 0;
}

extern const double D_0007E898;
double genrand_real3(void);
M2C_UNK df_quake_control(void)
{
	int n;

	if (DE.f8 < DE.fc) {
		DE.f8++;
		if (DE.f8 >= DE.fc) {
			DE.f10 = 0.0f;
			DE.f14 = 0.0f;
			DE.f18 = 0.0f;
		} else {
			n = DE.f4 * (DE.fc - DE.f8) / DE.fc;
			DE.f10 = (genrand_real3() - D_0007E898) * n;
			DE.f14 = (genrand_real3() - D_0007E898) * n;
			DE.f18 = (genrand_real3() - D_0007E898) * n;
		}
	}
}

void df_quake_disp(void)
{
	u8 *s = (u8 *)&D_005FB3B0;
	u8 *d = s - 0x80;

	*(float *)(d + 0x24) = *(float *)(s + 0x10);
	*(float *)(d + 0x28) = *(float *)(s + 0x14);
	*(float *)(d + 0x2C) = *(float *)(s + 0x18);
}

void df_blur_start(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
	u8 *w = (u8 *)&D_005FB3B0;
	int cur;

	cur = 0;
	if (*(int *)(w + 0x44))
		cur = *(int *)(w + 0x38) * (*(int *)(w + 0x44) - *(int *)(w + 0x40)) / *(int *)(w + 0x44);
	if (h < cur)
		return;
	*(int *)(w + 0x44) = j;
	*(int *)(w + 0x20) = b;
	*(int *)(w + 0x24) = c;
	*(int *)(w + 0x28) = d;
	*(int *)(w + 0x2C) = e;
	*(int *)(w + 0x30) = f;
	*(int *)(w + 0x34) = g;
	*(int *)(w + 0x38) = h;
	*(int *)(w + 0x3C) = i;
	*(int *)(w + 0x40) = 0;
	*(int *)(w + 0x1C) = a;
}

void df_blur_end(void)
{
	u8 *b_D_005FB3B0 = (u8 *)&D_005FB3B0;
	screen_blur = 0;
	*(int *)(b_D_005FB3B0 + 0x40) = *(int *)(b_D_005FB3B0 + 0x44);
}

void df_blur_scrpos_set(int x, int y)
{
	u8 *w = (u8 *)&D_005FB3B0;
	int sx, sy;
	int pos[2];

	if (x < 0) x = 0;
	else if (x > 479) x = 479;
	if (y < 0) y = 0;
	else if (y > 271) y = 271;
	sx = (*(int *)(w + 0x24) - 100) * 480 / 100;
	sy = (*(int *)(w + 0x28) - 100) * 272 / 100;
	*(int *)(w + 0x1C) = (480 - x) * sx / 480 - sx;
	*(int *)(w + 0x20) = (272 - y) * sy / 272 - sy;
}

void df_blur_control(void)
{
	u8 *b_D_005FB3B0 = (u8 *)&D_005FB3B0;
	if (*(int *)(b_D_005FB3B0 + 0x40) < *(int *)(b_D_005FB3B0 + 0x44))
		(*(int *)(b_D_005FB3B0 + 0x40))++;
}

typedef struct {
	int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
} SCREEN_BLUR;
#define SB (*(SCREEN_BLUR *)&screen_blur)
extern int game_pause;
M2C_UNK df_blur_disp(void)
{
	if (DE.f40 < DE.f44) {
		if (game_pause == 1) {
			SB.f0 = 0;
		} else if (DE.f40 < DE.f44 - 1) {
			SB.f0 = 1;
			SB.f8 = DE.f3c;
			SB.fc = DE.f1c;
			SB.f10 = DE.f20;
			SB.f14 = 480;
			SB.f18 = 272;
			SB.f1c = 0;
			SB.f20 = 0;
			SB.f30 = DE.f2c;
			SB.f34 = DE.f30;
			SB.f2c = 0;
			SB.f38 = DE.f34;
			SB.f3c = DE.f38 * (DE.f44 - DE.f40) / DE.f44;
			SB.f24 = DE.f24;
			SB.f28 = DE.f28;
		} else {
			SB.f0 = 0;
		}
	}
}

void df_cap_start(int a, int b, int c, int d, int e, int t)
{
	u8 *b_D_005FB3B0 = (u8 *)&D_005FB3B0;
	(*(int *)(b_D_005FB3B0 + 0x48)) = a;
	(*(int *)(b_D_005FB3B0 + 0x4C)) = b;
	(*(int *)(b_D_005FB3B0 + 0x50)) = c;
	(*(int *)(b_D_005FB3B0 + 0x54)) = d;
	(*(int *)(b_D_005FB3B0 + 0x58)) = e;
	(*(int *)(b_D_005FB3B0 + 0x5C)) = 0;
	(*(int *)(b_D_005FB3B0 + 0x60)) = t;
	screen_capture((*(int *)(b_D_005FB3B0 + 0)), 1);
}

void df_cap_control(void)
{
	u8 *b_D_005FB3B0 = (u8 *)&D_005FB3B0;
	if (*(int *)(b_D_005FB3B0 + 0x5C) < *(int *)(b_D_005FB3B0 + 0x60))
		(*(int *)(b_D_005FB3B0 + 0x5C))++;
}

M2C_UNK df_cap_disp(void)
{
	if (DE.f5c < DE.f60)
		sprite_set(DE.f0, 0, 0, 0xF0, 0x88, 0, 0, 200, 200, 0, 0, DE.f48, DE.f4c, DE.f50, DE.f54, 1000, 2, DE.f58, (DE.f60 - DE.f5c) * 255 / DE.f60);
}

void df_flash_start(int a, int b, int c, int d, int e, int t)
{
	u8 *b_D_005FB3B0 = (u8 *)&D_005FB3B0;
	*(int *)(b_D_005FB3B0 + 0x64) = a;
	*(int *)(b_D_005FB3B0 + 0x68) = b;
	*(int *)(b_D_005FB3B0 + 0x6C) = c;
	*(int *)(b_D_005FB3B0 + 0x70) = d;
	*(int *)(b_D_005FB3B0 + 0x74) = e;
	*(int *)(b_D_005FB3B0 + 0x78) = 0;
	*(int *)(b_D_005FB3B0 + 0x7C) = t;
}

void df_flash_control(void)
{
	u8 *b_D_005FB3B0 = (u8 *)&D_005FB3B0;
	if (*(int *)(b_D_005FB3B0 + 0x78) < *(int *)(b_D_005FB3B0 + 0x7C))
		(*(int *)(b_D_005FB3B0 + 0x78))++;
}

M2C_UNK df_flash_disp(void)
{
	if (DE.f78 < DE.f7c)
		poly_set(0, 0, 480, 272, 0, DE.f64, DE.f68, DE.f6c, DE.f70, DE.f64, DE.f68, DE.f6c, DE.f70, DE.f64, DE.f68, DE.f6c, DE.f70, DE.f64, DE.f68, DE.f6c, DE.f70, 1001, 2, DE.f74, (DE.f7c - DE.f78) * 255 / DE.f7c);
}

void df_fade_start(int a, int b, int c, int d, int t)
{
	u8 *b_D_005FB3B0 = (u8 *)&D_005FB3B0;
	*(int *)(b_D_005FB3B0 + 0x80) = a;
	*(int *)(b_D_005FB3B0 + 0x84) = b;
	*(int *)(b_D_005FB3B0 + 0x88) = c;
	*(int *)(b_D_005FB3B0 + 0x8C) = 0xFF;
	*(int *)(b_D_005FB3B0 + 0x90) = d;
	*(int *)(b_D_005FB3B0 + 0x94) = 0;
	*(int *)(b_D_005FB3B0 + 0x98) = t;
}

M2C_UNK df_fade_check(void)
{
	u8 *b_D_005FB3B0 = (u8 *)&D_005FB3B0;
	if (*(int *)(b_D_005FB3B0 + 0x94) < *(int *)(b_D_005FB3B0 + 0x98))
		return 0;
	return 1;
}

void df_fade_control(void)
{
	u8 *b_D_005FB3B0 = (u8 *)&D_005FB3B0;
	if ((*(int *)(b_D_005FB3B0 + 0x90)) == 0) {
		if ((*(int *)(b_D_005FB3B0 + 0x94)) < (*(int *)(b_D_005FB3B0 + 0x98))) {
			(*(int *)(b_D_005FB3B0 + 0x94))++;
			if ((*(int *)(b_D_005FB3B0 + 0x94)) > (*(int *)(b_D_005FB3B0 + 0x98)))
				(*(int *)(b_D_005FB3B0 + 0x94)) = (*(int *)(b_D_005FB3B0 + 0x98));
		}
	} else {
		(*(int *)(b_D_005FB3B0 + 0x94))++;
		if ((*(int *)(b_D_005FB3B0 + 0x94)) > (*(int *)(b_D_005FB3B0 + 0x98)))
			(*(int *)(b_D_005FB3B0 + 0x94)) = (*(int *)(b_D_005FB3B0 + 0x98));
	}
}

M2C_UNK df_fade_disp(void)
{
	if (DE.f90 == 0) {
		if (DE.f94 < DE.f98)
			poly_set(0, 0, 480, 272, 0, DE.f80, DE.f84, DE.f88, DE.f8c, DE.f80, DE.f84, DE.f88, DE.f8c, DE.f80, DE.f84, DE.f88, DE.f8c, DE.f80, DE.f84, DE.f88, DE.f8c, 20000, 2, 1, (DE.f98 - DE.f94) * 255 / DE.f98);
	} else {
		poly_set(0, 0, 480, 272, 0, DE.f80, DE.f84, DE.f88, DE.f8c, DE.f80, DE.f84, DE.f88, DE.f8c, DE.f80, DE.f84, DE.f88, DE.f8c, DE.f80, DE.f84, DE.f88, DE.f8c, 20000, 2, 1, DE.f94 * 255 / DE.f98);
	}
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void disp_effect_control(void) {
    df_quake_control();
    df_blur_control();
    df_cap_control();
    df_flash_control();
    df_fade_control();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void disp_effect_disp(void) {
    df_quake_disp();
    df_blur_disp();
    df_cap_disp();
    df_flash_disp();
    df_fade_disp();
}

void timer_init(int a)
{
	u8 *b_D_005FB714 = (u8 *)&D_005FB714;
	(*(int *)(b_D_005FB714 + 0x18)) = a;
	(*(int *)(b_D_005FB714 + 0)) = 0;
	(*(int *)(b_D_005FB714 + 0xC)) = 0;
	(*(int *)(b_D_005FB714 + 0x10)) = 0;
	(*(int *)(b_D_005FB714 + 0x14)) = 0;
	(*(int *)(b_D_005FB714 + 0x1C)) = 0;
	(*(int *)(b_D_005FB714 + 0x20)) = 0;
	(*(int *)(b_D_005FB714 + 0x24)) = 0;
	(*(int *)(b_D_005FB714 + 0x28)) = 0;
	(*(int *)(b_D_005FB714 + 0x4)) = 0;
	(*(int *)(b_D_005FB714 + 0x8)) = game_cpu_disp;
}

void timer_play(int a)
{
	u8 *b_D_005FB714 = (u8 *)&D_005FB714;
	if ((*(int *)(b_D_005FB714 + 0)) == a)
		return;
	(*(int *)(b_D_005FB714 + 0)) = a;
	(*(int *)(b_D_005FB714 + 0x30)) = -1;
	(*(int *)(b_D_005FB714 + 0x2C)) = 0;
	(*(int *)(b_D_005FB714 + 0x34)) = 0;
	(*(int *)(b_D_005FB714 + 0x38)) = 0;
	(*(int *)(b_D_005FB714 + 0x3C)) = 0;
	(*(int *)(b_D_005FB714 + 0x4)) = 0;
}

void timer_stop(int a)
{
	u8 *b_D_005FB714 = (u8 *)&D_005FB714;
	*(int *)(b_D_005FB714 + 0x4) = a;
	*(int *)(b_D_005FB714 + 0x30) = -1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", timer_control);

typedef struct { int no, mode, f8, fc, f10, f14, f18; } BGMWORK;
void bgm_init(int no)
{
	BGMWORK *b = (BGMWORK *)&D_005FB76C;
	b->no = no;
	b->f18 = 0;
	b->f14 = 0;
	if (no != -1)
		b->mode = 8;
	else
		b->mode = 10;
	b->f8 = 0;
	b->fc = 0;
	b->f10 = 0;
	sound_volume_set(gmain.f.ff30);
	sound_volume_set1(gmain.f.ff34);
}

extern u8 rank_up_break[][2];
void bgm_control(void)
{
	BGMWORK *b = (BGMWORK *)&D_005FB76C;

	if (b->no == -1)
		return;
	if (b->f18 == 1)
		return;
	if (b->f10 == get_now_sound_block() - 1)
		return;
	if (b->f8 == -1) {
		status_font_set(1, 23, 60, 0, 50);
		gmain.f.ff30 = 0x8000;
		sound_volume_set(0x8000);
	} else if (b->f8 == 1) {
		status_font_set(1, 22, 60, 0, 50);
		gmain.f.ff30 = 0x8000;
		sound_volume_set(0x8000);
	}
	b->f14 = 0;
	b->f8 = 0;
	gmain.f.f10a0 = 0;
	gmain.f.f10a4 = rank_up_break[b->fc][0] * rank_up_break[b->fc][1];
	b->f10 = get_now_sound_block() - 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void bgm_rankdown(void) {
    if (M2C_FIELD(&D_005FB76C, int *, 0) != -1) {
        if ((M2C_FIELD(&D_005FB76C, int *, 0xC) > 0) && (get_now_sound_block() != 0xB)) {
            if (M2C_FIELD(&D_005FB76C, int *, 8) == 0) {
                M2C_FIELD(&D_005FB76C, int *, 8) = -1;
                M2C_FIELD(&D_005FB76C, int *, 0xC) = (int) (M2C_FIELD(&D_005FB76C, int *, 0x10) - 1);
                sound_next_block_set(M2C_FIELD(&D_005FB76C, int *, 0x10));
            }
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void bgm_rankup(void) {
    if (M2C_FIELD(&D_005FB76C, int *, 0) != -1) {
        if (M2C_FIELD(&D_005FB76C, int *, 0xC) != (M2C_FIELD(&D_005FB76C, int *, 4) - 1)) {
            if (get_now_sound_block() != 0xB) {
                if (M2C_FIELD(&D_005FB76C, int *, 8) != 1) {
                    M2C_FIELD(&D_005FB76C, int *, 8) = 1;
                    M2C_FIELD(&D_005FB76C, int *, 0xC) = (int) (M2C_FIELD(&D_005FB76C, int *, 0x10) + 1);
                    M2C_FIELD(&D_005FB76C, int *, 0x14) = 0;
                    sound_next_block_set(M2C_FIELD(&D_005FB76C, int *, 0x10) + 2);
                }
            }
        }
    }
}

void bgm_rank_start(void)
{
	u8 *b_D_005FB76C = (u8 *)&D_005FB76C;
	*(int *)(b_D_005FB76C + 0x8) = 0;
	*(int *)(b_D_005FB76C + 0xC) = 0;
	sound_next_block_set(1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void bgm_clear_play(void) {
    D_005FB784 = 1;
    sound_next_block_set(9);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int bgm_clear_play_check(void) {
    return get_now_sound_block() == 9;
}

M2C_UNK bgm_rank_max_check(void)
{
	u8 *b_D_005FB76C = (u8 *)&D_005FB76C;
	int ret;

	ret = 0;
	if (*(int *)(b_D_005FB76C + 0) != -1)
		ret = *(int *)(b_D_005FB76C + 0x10) == *(int *)(b_D_005FB76C + 0x4) - 1;
	return ret;
}

M2C_UNK bgm_rank_max(void)
{
	return (D_005FB770 == 1) ? 1 : D_005FB770 - 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int bgm_rank(void) {
    return D_005FB77C;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void debprint_init(void) {
    D_005FB788 = 0;
}

void debprint_set(char *str)
{
	if (game_cpu_disp) {
		if (D_005FB788 < 20) {
			debug_text(0, D_005FB788 * 10, str);
			D_005FB788++;
		}
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", status_disp_init);

void status_font_set(int i, int a, int b, int c, int pri)
{
	int *p = &D_005FB44C + i;

	if (p[2] == -1 || pri >= p[4]) {
		p[2] = a;
		p[4] = pri;
		p[8] = b;
		p[6] = b;
		p[10] = c;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", status_disp_cnt);

void status_target_clear(void)
{
	int i;
	STC_T *t = (STC_T *)&D_005FB44C;

	for (i = 0; i < 32; i++) {
		t->a[i] = 0;
		t->b[i] = 0;
		t->c[i] = -1;
		t->d[i] = 0;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", status_target_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", status_disp);

extern TEXPOS texpos_inv_beat[];
typedef struct { u8 pad[0x68]; int c68, c6c, c70; u8 pad2[0x7E - 0x74]; short a7e; } SNSCOL_T;
#define SNC (*(SNSCOL_T *)&D_005FB44C)
typedef struct { u8 p[8]; int score; int st; u8 q[0x3A0 - 0x10]; } NETSC_T;
#define NETSC ((NETSC_T *)&D_004B500C)
int inv_scrdisp_start(int x, int y, int w, int h, int u, int v, float rot, float sx, float sy, int a, int b, int c, int d);
void status_score_disp(int x, int y, int a, int b, int c, int d, int val);
int inv_netgame_member_max(void);
void status_net_score_disp(void)
{
	int i, x, y, r, g, b, a;
	SNSCOL_T *c = (SNSCOL_T *)&D_005FB44C;

	x = 0x1E8 - (texpos_inv_beat[97].w + texpos_inv_beat[86].w * 10);
	for (i = 0, y = 2; i < inv_netgame_member_max(); y += 8, i++) {
		NETSC_T *n = &NETSC[i];
		b = c->c6c;
		r = c->c70;
		g = c->c68;
		a = 255;
		if (gmain.f.f20 == i)
			a = c->a7e;
		else if (n->st == 3) {
			b = 0;
			r = 0;
		}
		inv_scrdisp_start(x, y, texpos_inv_beat[97 + i].w, texpos_inv_beat[97 + i].h, texpos_inv_beat[97 + i].u, texpos_inv_beat[97 + i].v, 0.0f, 100.0f, 100.0f, g, b, r, a);
		status_score_disp(x + texpos_inv_beat[97].w, y, g, b, r, a, n->score);
	}
}




extern TEXPOS texpos_inv_beat[];
int num_digit_get(int v, int n);
int inv_scrdisp_start(int x, int y, int w, int h, int u, int v, float rot, float sx, float sy, int a, int b, int c, int d);
void status_score_disp(int x, int y, int a, int b, int c, int d, int val)
{
	int i, n;

	for (i = 10; i > 0; i--) {
		n = num_digit_get(val, i);
		if (n >= 0)
			inv_scrdisp_start(x, y, texpos_inv_beat[86 + n].w, texpos_inv_beat[86 + n].h,
					  texpos_inv_beat[86 + n].u, texpos_inv_beat[86 + n].v, 0, 100.0f, 100.0f, a, b, c, d);
		x += texpos_inv_beat[86].w - 1;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", status_score_disp2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", deb_status_disp);

int clippint_check(float x, float w)
{
	int r[2];
	int wrap = 0;
	int ret;

	r[1] = r[0] = CAM.f4c;
	while (r[0] <= 0.0f)
		r[0] += gmain.f.f10bc - 0.0f;
	while (r[0] >= gmain.f.f10bc)
		r[0] -= gmain.f.f10bc - 0.0f;
	while (r[1] <= 0.0f)
		r[1] += gmain.f.f10bc - 0.0f;
	while (r[1] >= gmain.f.f10bc)
		r[1] -= gmain.f.f10bc - 0.0f;
	if (r[0] < gmain.f.f10bc - w && w < r[0]) {
		r[0] -= w;
		r[1] += w;
	} else {
		wrap = 1;
		if (gmain.f.f10bc - w <= r[0]) {
			r[0] -= w;
			r[1] += w - gmain.f.f10bc;
		} else {
			r[0] -= w - gmain.f.f10bc;
			r[1] += w;
		}
	}
	ret = 1;
	if (wrap == 0) {
		if (x < r[0] || r[1] < x)
			ret = 0;
	} else {
		if (r[1] <= x && x <= r[0])
			ret = 0;
	}
	return ret;
}

void inv_spr_set(int type, int no, int x, int y, int pri, int c1, int c2)
{
	int w, h, u, v;

	switch (type) {
	case 0:
		w = 256; h = 256; u = 0; v = 0;
		break;
	case 3:
		w = texpos_inv_effect[no].w;
		h = texpos_inv_effect[no].h;
		u = texpos_inv_effect[no].u;
		v = texpos_inv_effect[no].v;
		break;
	default:
		return;
	}
	sprite_set(gmain.f.ff64[type], x, y, w, h, u, v, 100, 100, 0, 0, 255, 255, 255, 255, pri, 2, c1, c2);
}

void inv_spr_set_col(int type, int no, int x, int y, int r, int g, int b, int pri, int c1, int c2)
{
	int w, h, u, v;

	switch (type) {
	case 0:
		w = 320; h = 64; u = 0; v = 0;
		break;
	case 3:
		w = texpos_inv_effect[no].w;
		h = texpos_inv_effect[no].h;
		u = texpos_inv_effect[no].u;
		v = texpos_inv_effect[no].v;
		break;
	default:
		return;
	}
	sprite_set(gmain.f.ff64[type], x, y, w, h, u, v, 100, 100, 0, 0, r, g, b, 255, pri, 2, c1, c2);
}

typedef struct { float x, y, z; L2V3 rot; } ROUTE_R;
typedef struct { u8 p[0x10C0]; ROUTE_R r[1]; } GMRR_T;
#define GMRR (*(GMRR_T *)&gmain)
void root_pos_get(L2V3 *out, L2V3 *ofs, float pos, float len)
{
	int a, b;
	float f, s;
	L2V3 p0, p1, d;

	a = pos;
	f = pos - (float)a;
	b = a + 1;
	while (a <= 0)
		a = (float)a + (gmain.f.f10bc - 0.0f);
	while ((float)a >= gmain.f.f10bc)
		a = (float)a - (gmain.f.f10bc - 0.0f);
	while (b <= 0)
		b = (float)b + (gmain.f.f10bc - 0.0f);
	while ((float)b >= gmain.f.f10bc)
		b = (float)b - (gmain.f.f10bc - 0.0f);
	p0.x = GMRR.r[a].x;
	p0.y = GMRR.r[a].y;
	p0.z = GMRR.r[a].z;
	p1.x = GMRR.r[b].x;
	p1.y = GMRR.r[b].y;
	p1.z = GMRR.r[b].z;
	d.x = p0.x + (p1.x - p0.x) * f;
	d.y = p0.y + (p1.y - p0.y) * f;
	d.z = p0.z + (p1.z - p0.z) * f;
	s = len / 500.0f;
	out->x = d.x * s;
	out->y = d.y * s;
	out->z = d.z * s;
	out->x += ofs->x;
	out->y += ofs->y;
	out->z += ofs->z;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", root_rot_get);

void root_pos_get(L2V3 *out, L2V3 *ofs, float pos, float len);
void vec_axis_rot(L2V3 *a, L2V3 *b, L2V3 *out, float ang);
void vec_one(L2V3 *in, L2V3 *out);
void root_uprot_get(L2V3 *out, float pos, float ang)
{
	L2V3 p0, p1, r, d, z0, z1;

	z0.x = 0;
	z0.y = 0;
	z0.z = 0;
	root_pos_get(&p0, &z0, pos, 360.0f);
	z1.x = 0;
	z1.y = 0;
	z1.z = 0;
	root_pos_get(&p1, &z1, pos + 1.0f, 360.0f);
	vec_axis_rot(&p1, &p0, &r, ang + 90.0f);
	d.x = r.x - p0.x;
	d.y = r.y - p0.y;
	d.z = r.z - p0.z;
	vec_one(&d, out);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", root_offset_get);

void inv_nowloading_tex_load(char *name)
{
	u8 *b_load_disp = (u8 *)&load_disp;
	(*(int *)(b_load_disp + 0)) = bmp_file_load16(name);
	(*(int *)(b_load_disp + 0x1C)) = bmp_file_load16(D_0007DF78);
}

void inv_nowloading_starge_set(int no)
{
	u8 *d = (u8 *)&load_disp;
	u8 *s = (u8 *)&load_stage_pos + no * 16;

	*(int *)(d + 0x8) = *(s8 *)(s + 0);
	*(float *)(d + 0xC) = *(short *)(s + 2);
	*(float *)(d + 0x10) = *(short *)(s + 4);
	*(float *)(d + 0x14) = *(float *)(s + 8);
	*(float *)(d + 0x18) = *(float *)(s + 0xC);
	*(int *)(d + 0x20) = no;
}

typedef struct { int f0, f4; u8 _p8[0x1C]; s16 x[128]; s16 y[128]; u8 a[128]; } LOAD_DISP;
#define LD (*(LOAD_DISP *)&load_disp)
unsigned long genrand_int32(void);
void inv_nowloading_reset(void)
{
	int i;

	LD.f4 = 0;
	for (i = 0; i < 128; i++) {
		LD.x[i] = genrand_int32() % 459;
		LD.y[i] = genrand_int32() % 271;
		LD.a[i] = genrand_int32() % 191 + 64;
	}
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_nowloading_disp2(void) {
    sprite_set(D_004B4D04, 0x19E, 0x107, 0x40, 8, 0, 0, 0x64, 0x64, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xA, 2, 1, 0xFF);
}

typedef struct { int tex, f4, f8; float x, y, dx, dy; int tex2, state; } LOADDISP_T;
#define LD (*(LOADDISP_T *)&load_disp)
void inv_nowloading_disp(int mode)
{
	sprite_set(LD.tex2, 0x19E, 0x107, 64, 8, 0, 0, 100, 100, 0, 0, 255, 255, 255, 255, 10, 2, 1, 255);
	if (LD.state == 14)
		return;
	if (mode == 1) {
		LD.x += LD.dx;
		LD.y += LD.dy;
	}
	sprite_set(LD.tex, 240.0f - LD.x, 136.0f - LD.y, 512, 256, 0, LD.f8 << 8, 100, 100, 0, 0, 255, 255, 255, 255, 0, 2, 0, 255);
}

extern char text_buf[];
extern char D_0007DF88[];
extern u8 D_004B60A8[];
int sprintf(char *s, const char *fmt, ...);
void *memcpy(void *d, const void *s, unsigned int n);
void *file_bind_addr(int bind, char *name);
unsigned int file_bind_size(int bind, char *name);
void root_init(int no, int bind)
{
	void *p;
	unsigned int size;

	sprintf(text_buf, D_0007DF88, no);
	p = file_bind_addr(bind, text_buf);
	if (p == 0)
		return;
	size = file_bind_size(bind, text_buf);
	gmain.f.f10bc = size / 24 + stage_format[no].f0 - 1;
	memcpy(D_004B60A8, p, size);
}

typedef struct { int f0, f4; float f8, fc; int f10, f14, f18; } RISARJU;
#define risarju (*(RISARJU *)&D_005FB78C)
void risarju_init(void)
{
	risarju.fc = 500.0f;
	risarju.f14 = 4;
	risarju.f18 = 3;
	risarju.f0 = 0;
	risarju.f4 = 0;
	risarju.f10 = 0;
	risarju.f8 = D_004B60A4;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", risarju_control);

void beat_help_init(void)
{
	u8 *b_D_005FB7A8 = (u8 *)&D_005FB7A8;
	*(int *)(b_D_005FB7A8 + 0) = 0;
	*(int *)(b_D_005FB7A8 + 0x4) = 0;
	*(int *)(b_D_005FB7A8 + 0x8) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void beat_help_set(int arg0) {
    if (M2C_FIELD(&D_005FB7A8, int *, 0) != 1) {
        M2C_FIELD(&D_005FB7A8, int *, 0) = 1;
        M2C_FIELD(&D_005FB7A8, int *, 4) = arg0;
        M2C_FIELD(&D_005FB7A8, int *, 8) = 0;
    }
}

void beat_help_off(void)
{
	u8 *b_D_005FB7A8 = (u8 *)&D_005FB7A8;
	*(int *)(b_D_005FB7A8 + 0) = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", beat_help_sync_disp);

extern int D_005E6F78;
#define SHI(p, o) (*(int *)((p) + (o)))
#define SHF(p, o) (*(float *)((p) + (o)))
int hit_check_shield(float *pos, float r)
{
	u8 *p = (u8 *)&D_005E6F78;
	u8 *s;
	int i, n = 0;

	for (i = 0; i < 16; i++, p += 0x30) {
		s = p + 0x14;
		if (SHI(p, 0x14) == 0)
			continue;
		if (SHI(p, 0x18) != 1 && SHI(p, 0x20) == 0 &&
		    pos_fast_length_xyz_check(pos[0] - SHF(p, 0x2C), pos[1] - SHF(p, 0x30), pos[2] - SHF(p, 0x34), r) == 1) {
			n++;
			shield_damage(s, (int)pos);
		}
	}
	return n ? n : -1;
}

int hit_check_player(float *pos, float r)
{
	u8 *z = (u8 *)&D_005A06D8;

	if (*(int *)(z + 0x14) != 0)
		return -1;
	if (pos_fast_length_xyz_check(pos[0] - *(float *)(z + 0x6C), pos[1] - *(float *)(z + 0x70), pos[2] - *(float *)(z + 0x74), r) != 1)
		return -1;
	ziki_damage(z, pos);
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", hit_check_enemy);

void ufo_damage(void *u, BV3 p, int dmg, int net, int flag);
extern BUFO_D D_005A0CF4;
typedef struct { u8 p[0xEB9D0]; int n; } GMU3_T;
#define GMU3_N ((*(GMU3_T *)&gmain).n)
void netgame_ufo_damage_set3(int no, int dmg, int life) __asm__("netgame_ufo_damage_set");
int hit_check_ufo(float *pos, int dmg, float r)
{
	int i;
	UFO_T *u;
	BUFO_D *b;

	if (gmain.f.ff28 != 13) {
		for (i = 0; i < GMU3_N; i++) {
			u = &ufo_t[i];
			if (u->f[1] == 0)
				continue;
			if (u->f[2] == 1)
				continue;
			if (u->f[4] == 1)
				continue;
			if (u->f[13] == 1)
				continue;
			if (pos_fast_length_xyz_check(pos[0] - ((float *)u->f)[23], pos[1] - ((float *)u->f)[24], pos[2] - ((float *)u->f)[25], r) != 1)
				continue;
			status_font_set(1, 24, 30, 0, 10);
			ufo_damage(u, *(BV3 *)pos, dmg, 0, 1);
			netgame_ufo_damage_set3(i, dmg, u->f[9]);
			return i;
		}
	} else {
		r *= 5.0f;
		b = &D_005A0CF4;
		if (b->f0 == 0)
			return -1;
		if (b->f4 == 1)
			return -1;
		if (b->f8 == 1)
			return -1;
		if (b->f30 == 1)
			return -1;
		if (pos_fast_length_xyz_check(pos[0] - b->pos[0], pos[1] - b->pos[1], pos[2] - b->pos[2], r) == 1) {
			status_font_set(1, 24, 30, 0, 10);
			boss_ufo_damage(b, *(BV3 *)pos, dmg, 0, 1);
			netgame_ufo_damage_set3(0, dmg, b->dmg);
			return 0;
		}
	}
	return -1;
}

typedef struct { int f0, f4, f8; u8 _pc[0x24 - 0xC]; float x, y, z; u8 _p30[0x9C - 0x30]; } LASER_T;
void inv_laser_end(int no);
void efc_shot_del(float x, float y, float z);
#define LZ ((LASER_T *)&D_005E728C)
int hit_check_laser(float *pos, float r)
{
	int i;

	for (i = 0; i < 32; i++) {
		if (LZ[i].f0 == 0)
			continue;
		if (LZ[i].f8 != 1)
			continue;
		if (pos_fast_length_xyz_check(pos[0] - LZ[i].x, pos[1] - LZ[i].y, pos[2] - LZ[i].z, r) == 1) {
			LZ[i].f0 = 0;
			inv_laser_end(LZ[i].f4);
			efc_shot_del(LZ[i].x, LZ[i].y, LZ[i].z);
		}
	}
	return 0;
}

void *memset(void *s, int c, unsigned int n);
void inv_stagestart_set(void);
void inv_gamestart_set(int mode)
{
	memset(&inv_status, 0, sizeof(INV_STATUS));
	if (save_data.fd0 == 0)
		IST.f0 = 3;
	if (save_data.fd0 == 1)
		IST.f0 = 5;
	if (save_data.fd0 == 2)
		IST.f0 = 7;
	if (save_data.fd0 == 3)
		IST.f0 = 9;
	IST.f4 = 0;
	IST.f10 = save_data.fcc;
	IST.fc = mode;
	if (mode != 1) {
		IST.f14 = 1;
		IST.f18 = 1;
	}
	if (gmain.f.f1c == 1) {
		IST.f0 = gmain.f.f1c;
		IST.f10 = gmain.f.f1c;
	}
}

void inv_gamecontinue_set(void)
{
	IST.f10 = save_data.f108;
	IST.f0 = save_data.f10c;
	IST.f4 = save_data.f110;
	IST.fc = save_data.f100;
	IST.f14 = save_data.f114;
	IST.f18 = save_data.f118;
	if (save_data.f108 == -1)
		IST.f10 = save_data.fcc;
	if (IST.f0 == -1) {
		if (save_data.fd0 == 0)
			IST.f0 = 3;
		if (save_data.fd0 == 1)
			IST.f0 = 5;
		if (save_data.fd0 == 2)
			IST.f0 = 7;
		if (save_data.fd0 == 3)
			IST.f0 = 9;
	}
	inv_stagestart_set();
}

void inv_stagestart_set(void)
{
	u8 *b = (u8 *)&inv_status;

	*(int *)(b + 0x8) = *(int *)(b + 0x4);
	*(int *)(b + 0x20) = 0;
	*(int *)(b + 0x24) = 0;
	*(int *)(b + 0x2C) = 0;
	*(int *)(b + 0x30) = 0;
	*(int *)(b + 0x38) = 0;
	*(int *)(b + 0x3C) = 0;
	*(int *)(b + 0x40) = 0;
	*(int *)(b + 0x44) = 0;
	*(int *)(b + 0x48) = 0;
	*(int *)(b + 0x4C) = 0;
	*(int *)(b + 0x50) = 0;
	*(int *)(b + 0x54) = 0;
	*(int *)(b + 0x58) = 0;
	*(int *)(b + 0x1C) = 0;
}

void inv_score_add(int n)
{
	u8 *b_inv_status = (u8 *)&inv_status;
	(*(int *)(b_inv_status + 0x4)) += n;
	if ((*(int *)(b_inv_status + 0x4)) > 2000000000)
		(*(int *)(b_inv_status + 0x4)) = 2000000000;
	(*(int *)(b_inv_status + 0x58)) += n;
	if ((*(int *)(b_inv_status + 0x58)) > 2000000000)
		(*(int *)(b_inv_status + 0x58)) = 2000000000;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", inv_stageend_set);

typedef struct { int f0, f4; int d[250]; } NETDATA;
typedef struct { int f0, f4, f8, fc; u8 _p[0x3A0 - 0x10]; } NETPL;
#define netpl ((NETPL *)&D_004B500C)
void inv_netgame_init(void)
{
	int i, j, k;
	NETDATA *n;

	for (i = 0; i < 4; i++) {
		n = &((NETDATA *)&netdata)[i];
		netpl[i].fc = 0;
		for (j = 0; j < 250; j++)
			n->d[j] = 0;
	}
	gmain.f.fea4 = 0;
	for (k = 0; k < 32; k++)
		GM_INT(0xEA8 + k * 4) = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", inv_netgame_loop);

M2C_UNK inv_netgame_member_max(void)
{
	int n = 4;
	if (D_004B5010 != 0)
		n = D_004B5010;
	return n;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", inv_netgame_linkcheck);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", inv_netgame_linkcheck2);

void netgame_zako_damage_set(int a, int b, int c, int dmg)
{
	int *p;

	if (gmain.f.f1c == 0)
		return;
	p = (int *)&gmain.b[0x24 + gmain.f.f20 * 0x3A0];
	for (;;) {
		if (*p >= 38)
			return;
		if (NE(p, 0x10) == 0)
			break;
		(*p)++;
	}
	NE(p, 0x10) = 1;
	NE(p, 0x14) = (a << 16) + (b << 8) + c;
	NE(p, 0x18) = dmg;
	NE(p, 0x1C) = genrand_int32();
	NE(p, 0x20) = 4;
	(*p)++;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", netgame_zako_damage_get);

void netgame_zako_dead_set(int a, int b, int c)
{
	int *p;

	if (gmain.f.f1c == 0)
		return;
	p = (int *)&gmain.b[0x24 + gmain.f.f20 * 0x3A0];
	for (;;) {
		if (*p >= 38)
			return;
		if (NE(p, 0x10) == 0)
			break;
		(*p)++;
	}
	NE(p, 0x10) = 2;
	NE(p, 0x14) = (a << 16) + (b << 8) + c;
	NE(p, 0x18) = 0;
	NE(p, 0x1C) = genrand_int32();
	NE(p, 0x20) = 4;
	(*p)++;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", netgame_zako_dead_get);

extern int D_005A0D14;
void netgame_ufo_damage_set(int no, int dmg)
{
	int *p;

	if (gmain.f.f1c == 0)
		return;
	p = (int *)&gmain.b[0x24 + gmain.f.f20 * 0x3A0];
	for (;;) {
		if (*p >= 38)
			return;
		if (NE(p, 0x10) == 0)
			break;
		(*p)++;
	}
	NE(p, 0x10) = 3;
	NE(p, 0x14) = no;
	NE(p, 0x18) = dmg;
	NE(p, 0x1C) = genrand_int32();
	NE(p, 0x20) = 4;
	if (gmain.f.ff28 != 13)
		NE(p, 0x24) = ufo_t[no].f[9];
	else
		NE(p, 0x24) = D_005A0D14;
	(*p)++;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", netgame_ufo_damage_get);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", netgame_ufo_pos_set);

typedef struct { u8 p[0xEB9D0]; int n; } GMU2_T;
#define GMU2_N ((*(GMU2_T *)&gmain).n)
typedef struct { u8 pad[0x44]; float x; u8 pad2[4]; float max, vx; u8 rest[0xA4 - 0x54]; } UFOP_T;
void netgame_ufo_pos_get(u8 *q, int k)
{
	int i;
	float half, t;
	UFOP_T *u;

	if (gmain.f.f20 == 0)
		return;
	half = gmain.f.f10bc * 0.5f;
	if (gmain.f.ff28 == 13)
		return;
	for (i = 0; i < GMU2_N; i++) {
		t = ((int *)(q + k * 0x18 + 0x14))[i] / 100.0f;
		u = &((UFOP_T *)&D_005A09BC)[i];
		if (t < u->x - half)
			t += gmain.f.f10bc;
		else if (u->x + half < t)
			t -= gmain.f.f10bc;
		if (t < u->x - 1.0f)
			u->vx += u->max / 100.0f;
		else if (u->x + 1.0f < t)
			u->vx -= u->max / 100.0f;
		else if (u->vx > 0)
			u->vx -= u->max / 100.0f;
		else if (u->vx < 0)
			u->vx += u->max / 100.0f;
		if (u->vx < -u->max)
			u->vx = -u->max;
		else if (u->vx > 0)
			u->vx = 0;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", netgame_ufo_life_set);

void ufo_damage(void *u, BV3 p, int dmg, int net, int flag);
extern BUFO_D D_005A0CF4;
typedef struct { u8 p[0xEB9D0]; int n; } GMU_T;
#define GMU_N ((*(GMU_T *)&gmain).n)
void netgame_ufo_life_get(u8 *q, int k, int pl)
{
	int i, *v;

	if (gmain.f.f20 == pl)
		return;
	if (pl >= 4)
		return;
	if (gmain.f.f0 == 4)
		return;
	if (gmain.f.ff28 == 13) {
		v = (int *)(k * 0x18 + (int)q + 0x14);
		if (D_005A0CF4.dmg < *v)
			boss_ufo_damage(&D_005A0CF4, *(BV3 *)((u8 *)&D_005A0CF4 + 0x64), *v - D_005A0CF4.dmg, 1, 0);
	} else {
		for (i = 0; i < GMU_N; i++) {
			UFO_T *u;
			int x = ((int *)(q + k * 0x18 + 0x14))[i];
			u = &ufo_t[i];
			if (x > u->f[9])
				ufo_damage(u, *(BV3 *)&u->f[0x5C / 4], ((int *)(q + k * 0x18 + 0x14))[i] - u->f[9], 1, 0);
		}
	}
}

void se_play_3d(int no, float *pos, float dist)
{
	V3 p, s;
	int vol;

	p = *(V3 *)pos;
	mat_local2screen(&p, &s);
	if (no == -1)
		return;
	if (s.x < 0.0f)
		return;
	if (s.x >= 480.0f)
		return;
	if (s.y < 0.0f)
		return;
	if (s.y >= 272.0f)
		return;
	if (s.z <= 0.0f)
		return;
	if (dist != 0.0f && dist <= s.z)
		return;
	if (gmain.f.f10ac == 12)
		return;
	if (gmain.f.f10ac == 22)
		return;
	vol = 127;
	if (dist != 0.0f) {
		vol = 127.0f - s.z * 127.0f / dist;
		if (vol < 32)
			return;
	}
	gmain.f.f10b0 = 0;
	gmain.f.f10b4 = 0;
	if (dist != 0.0f) {
		if (s.x < 360.0f)
			gmain.f.f10b0 = (int)(360.0f - s.x) * vol / 360;
		if (120.0f < s.x)
			gmain.f.f10b4 = (int)(s.x - 120.0f) * vol / 360;
	} else {
		gmain.f.f10b0 = vol;
		gmain.f.f10b4 = vol;
		if (s.x < 240.0f)
			gmain.f.f10b4 = vol * s.x / 240.0f;
		if (240.0f < s.x)
			gmain.f.f10b0 = vol * (240.0f - (s.x - 240.0f)) / 240.0f;
	}
	gmain.f.f10ac = no;
}

/* an unreferenced 0.0f pool word (0x7E564) precedes zako_init_once's rodata */
__asm__(".pushsection .rodata\n\t.word 0\n.popsection");

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E568);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E56C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E570);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E574);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E578);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E57C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E580);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E584);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E588);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E58C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E590);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E594);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E598);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E59C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5A4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5BC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5C4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5C8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5D4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5E8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5F0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5F8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E5FC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E600);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E604);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E608);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E60C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E610);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E614);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E618);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E61C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E620);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E624);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E628);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E62C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E630);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E634);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E638);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E63C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E640);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E644);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E648);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E64C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E650);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E654);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E658);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E65C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E660);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E664);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E668);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E66C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E670);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E674);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E678);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E67C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E680);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E684);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E688);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E68C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E690);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E694);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E698);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E69C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6A4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6BC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6C4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6C8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6D4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6E8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6F0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6F8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E6FC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E700);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E704);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E708);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E70C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E710);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E714);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E718);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E71C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E720);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E724);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E728);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E72C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E730);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E734);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E738);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E73C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E740);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E744);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E748);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E74C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E750);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E754);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E758);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E75C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E760);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E764);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E768);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E76C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E770);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E774);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E778);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E77C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E780);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E784);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E788);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E78C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E790);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E794);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E798);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E79C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7A4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7BC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7C4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7C8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7D4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7E8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7F0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7F8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E7FC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E800);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E804);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E808);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E80C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E810);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E814);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E818);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E81C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E820);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E824);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E828);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E82C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E830);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E834);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E838);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E83C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E840);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E844);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E848);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E84C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E850);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E854);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E858);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E85C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E860);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E864);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E868);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E86C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E870);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E874);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E878);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E87C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E880);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E884);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E888);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E88C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E890);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E894);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E898);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007E89C);
