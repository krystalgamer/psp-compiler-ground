/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
void ufo_control_once(int *u);
void ufo_tex_anime(int *u);
void status_font_set(int i, int a, int b, int c, int pri);
void inv_score_add(int n);
extern signed char D_0035393C;
int tex_make(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK bmp_file_unload(int);                       /* extern */
M2C_UNK df_quake_control();                         /* extern */
M2C_UNK df_blur_disp();                             /* extern */
M2C_UNK df_cap_disp();                              /* extern */
M2C_UNK df_fade_disp();                             /* extern */
M2C_UNK df_flash_disp();                            /* extern */
M2C_UNK sprite_set(int, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, int, int, int, int, int, int, int, int, int, int, int); /* extern */
extern int D_004B4D04;


extern int game_cpu_disp;
extern int screen_blur;

extern int inv_status;
extern int load_disp;
extern int load_stage_pos;
extern char D_0007DF78[];
int bmp_file_load16(char *name);
void debug_text(int x, int y, char *str);
void screen_capture(int buf, int mode);

#include "gmain.h"
#include "inv_game.h"
double genrand_real2(void);
double genrand_real3(void);
extern int netdata;
M2C_UNK bmp_file_unload(int);
void gmo_file_unload(int no);
void inv_star_dispset(int f);
void sound_volume_set(int vol);
void sound_volume_set1(int vol);
int pos_fast_length_xyz_check(float x, float y, float z, float len);
void ziki_damage(void *z, float *pos);
int get_now_sound_block(void);


extern int D_003538BC;
void inv_laser_all_init(void);
void inv_laser_priset(void);
void inv_ring_all_init(void);
void inv_ring_priset(void);
void inv_laser_texno(int no);
void inv_ring_texno(int no);
typedef struct { u8 f0; u8 pad[0x7F]; } RG_T;

extern int game_model_load;
extern u8 gmo[];
typedef struct { int f0; int f4; u8 pad[0x60]; } GMO_T;

void *memset(void *s, int c, unsigned int n);
void inv_gamestart_set(int mode);
void inv_netgame_init(void);
void inv_nowloading_starge_set(int no);
void inv_nowloading_reset(void);
void inv_nowloading_disp2(void);
void dispeffect_all_init(void);
int file_load_async(char *name, int mode);
int file_load_check(int no);
int file_load_addr(int no);
void file_load_end(int no);
void psp_loopstart(void);
void psp_loopend(void);
int sceGuSync(int mode, int what);
int error_code_daialogget(void);
int inv_netgame_loop();
void *file_bind_addr(int bind, char *name);
int bmp_addr_load_normal(void *buf);
int bmp_addr_load16(void *buf);
void psp_free(void *p);
void inv_screffect_tex_set(int tex, int mode);
void inv_scrdisp_tex_set(int tex, int mode);
extern char *tex_filename[];
void maingame_all_init(int net)
{
	int i, j, st, fd, bind, mode;
	void *p;

	memset(&gmain, 0, sizeof(gmain));
	for (j = 0; j < 45; j++)
		gmain.ff64[j] = -1;
	gmain.de.f0 = -1;
	gmain.f1060 = 200;
	gmain.f0 = 0;
	gmain.f1c = net;
	gmain.f14 = 0;
	gmain.f18 = 1;
	gmain.ff38 = 0;
	if (net == 1) {
		gmain.f1060 = 1;
		inv_gamestart_set(1);
		inv_netgame_init();
	}
	gmain.fc = 1;
	mode = gmain.f1c != 1;
	inv_nowloading_starge_set(0);
	fd = -1;
	inv_nowloading_reset();
	st = 0;
	bind = 0;
	while (gmain.fc) {
		switch (st) {
		case 0:
			fd = file_load_async("bind_bmp.dat", mode);
			st = 1;
			break;
		case 1:
			if (file_load_check(fd) == 1) {
				bind = file_load_addr(fd);
				st = 2;
			}
			break;
		case 2:
			gmain.fc = 0;
			break;
		}
		psp_loopstart();
		inv_nowloading_disp2();
		if (gmain.f1c == 1) {
			sceGuSync(0, 0);
			if (error_code_daialogget() && gmain.fc == 0)
				gmain.fc = 1;
			if (inv_netgame_loop() == 1) {
				if (fd != -1)
					file_load_end(fd);
				gmain.f1064 = 1;
				gmain.fc = 0;
				psp_loopend();
				break;
			}
		}
		psp_loopend();
	}
	if (gmain.f1c == 1) {
		if (gmain.f1064 == gmain.f1c)
			return;
	} else {
		psp_loopstart();
		psp_loopend();
		psp_loopstart();
		psp_loopend();
	}
	gmain.fc = 1;
	for (i = 0; i < 45; i++) {
		p = file_bind_addr(bind, tex_filename[i]);
		if (p) {
			if (i == 5)
				gmain.ff64[5] = bmp_addr_load_normal(p);
			else
				gmain.ff64[i] = bmp_addr_load16(p);
		}
	}
	psp_free((void *)bind);
	dispeffect_all_init();
	inv_screffect_tex_set(gmain.ff64[3], 2);
	inv_scrdisp_tex_set(gmain.ff64[1], 2);
}

typedef struct { int f0; float f4; int f8, fc; float f10; int f14, f18, f1c, f20; } STAGE_FORMAT;
extern STAGE_FORMAT stage_format[];
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

const L2V3 D_0007DEAC = { 0.7f, 0.7f, 0.7f };

const L2V3 D_0007DEB8 = { 0.0f, 180.0f, 0.0f };

const L2V3 D_0007DEC4 = { 2.0f, 2.0f, 2.0f };

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DED0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DEDC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DEE8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DEF4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF00);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", D_0007DF0C);

/* cam_init's vector initializers (local aggregates in the original; a same-file const
   global reproduces both the code and the .rodata position). D_0007DF3C is an unused
   initializer whose constant was still emitted. */
typedef L2V3 V3;
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

extern int game_model_load;
int sound_stop1(void);
void se_stop(void);
void gmo_all_unload(void);
void inv_particle_all_init(void);
void sound_relece(void);
void psp_edram_init(void);
void psp_loopstart(void);
void psp_loopend(void);
void bg_free(void);
void df_fade_start(int a, int b, int c, int d, int e);
void dispeffect_init(void);
int sound_stop(void);
void maingame_free(void)
{
	int i;

	game_model_load = 0;
	sound_stop1();
	sound_stop();
	se_stop();
	bg_free();
	gmo_all_unload();
	inv_particle_all_init();
	if (gmain.ff28 >= 1 && gmain.ff28 <= 14)
		sound_relece();
	if (gmain.f108c == 1) {
		for (i = 0; i < 16; i++)
			gmo_file_unload(gmain.gmo_id[i]);
	}
	psp_edram_init();
	dispeffect_init();
	df_fade_start(0, 0, 0, 1, 1);
	psp_loopstart();
	psp_loopend();
	psp_loopstart();
	psp_loopend();
	psp_loopstart();
	psp_loopend();
	psp_loopstart();
	psp_loopend();
}

typedef struct { int used, f4, f8, type, f10, f14; void *p18, *p1c; int f20, f24; } TEXF_T;
extern TEXF_T tex_file[];
extern char text_buf[];
extern char *future_result_list[];
extern char *movie_filename[];
extern char D_0007DB9C[], D_0007DBA0[], D_0007DBAC[], D_0007DBBC[], D_0007DBD4[], D_0007DBE4[];
int sprintf(char *s, const char *fmt, ...);
void inv_movie_result_tex_addr(void *p);
void inv_movie_result_flag(int f);
void inv_movie_result_reset(void);
void inv_movie_result_memset(void);
void inv_movie_result_disp_counter_set(int n);
void inv_movie_result_txt_set(char *s);
void inv_movie_result_free(void);
void se_stop(void);
void sound_close(void);
void mpeg_main(char *name, int f);
void sound_init2(void);
void psp_init2(void);
void maingame_movie(void)
{
	int t;

	if (gmain.ff38 < 2 || gmain.ff38 > 13) {
		inv_movie_result_flag(0);
	} else {
		inv_movie_result_tex_addr(tex_file[gmain.ff64[5]].p1c);
		inv_movie_result_flag(1);
		inv_movie_result_reset();
		inv_movie_result_memset();
		if (gmain.ff38 == 13)
			inv_movie_result_disp_counter_set(150);
		sprintf(text_buf, D_0007DB9C, future_result_list[0]);
		sprintf(text_buf, D_0007DBA0, text_buf, future_result_list[1], IST.f1c);
		sprintf(text_buf, D_0007DBAC, text_buf, future_result_list[2], IST.f28);
		sprintf(text_buf, D_0007DBA0, text_buf, future_result_list[3], IST.f20);
		sprintf(text_buf, D_0007DBAC, text_buf, future_result_list[4], IST.f34);
		sprintf(text_buf, D_0007DBA0, text_buf, future_result_list[6], IST.f3c);
		sprintf(text_buf, D_0007DBAC, text_buf, future_result_list[7], IST.f40);
		sprintf(text_buf, D_0007DBA0, text_buf, future_result_list[8], IST.f44);
		sprintf(text_buf, D_0007DBAC, text_buf, future_result_list[9], IST.f48);
		sprintf(text_buf, D_0007DBA0, text_buf, future_result_list[10], IST.f4c);
		t = IST.f54;
		if (t >= 10000)
			sprintf(text_buf, D_0007DBBC, text_buf, future_result_list[13], t / 10000, t / 100 % 100, t % 100);
		else
			sprintf(text_buf, D_0007DBE4, text_buf, future_result_list[13], t / 100 % 100, t % 100);
		sprintf(text_buf, D_0007DBA0, text_buf, future_result_list[11], IST.f50);
		sprintf(text_buf, D_0007DBD4, text_buf, future_result_list[12], IST.f58);
		inv_movie_result_txt_set(text_buf);
	}
	sound_stop1();
	sound_stop();
	se_stop();
	sound_close();
	psp_loopstart();
	psp_loopend();
	psp_loopstart();
	psp_loopend();
	mpeg_main(movie_filename[gmain.ff38], 1);
	if (gmain.ff38 >= 2 && gmain.ff38 <= 13) {
		inv_movie_result_flag(0);
		inv_movie_result_free();
	}
	if (gmain.ff38 == 15) {
		gmain.ff38 = 1;
		psp_loopstart();
		psp_loopend();
		psp_loopstart();
		psp_loopend();
		mpeg_main(movie_filename[gmain.ff38], 1);
	}
	sound_init2();
	psp_init2();
	gmain.f1060 -= 200;
}

void dispeffect_all_free(void);
void maingame_all_free(void)
{
	int i;

	dispeffect_all_free();
	for (i = 0; i < 45; i++) {
		if (gmain.ff64[i] > 0)
			bmp_file_unload(gmain.ff64[i]);
	}
	sound_volume_set(0x8000);
	sound_volume_set1(0x8000);
}

void game_control(void)
{
	if (gmain.f0 == 1)
		game_cnt_title();
	else if (gmain.f0 == 2)
		game_cnt_option_3559C();
	else if (gmain.f0 == 3)
		game_cnt_option2();
	else if (gmain.f0 == 4)
		game_cnt_stagestart();
	else if (gmain.f0 == 5)
		game_cnt_game();
	else if (gmain.f0 == 6)
		game_cnt_pause();
	else if (gmain.f0 == 7)
		game_cnt_stageclear();
	else if (gmain.f0 == 8)
		game_cnt_result();
	else if (gmain.f0 == 9)
		game_cnt_gameover();
	else if (gmain.f0 == 10)
		game_cnt_dead();
	else if (gmain.f0 == 11)
		game_cnt_netdead();
	else if (gmain.f0 == 12)
		game_cnt_ending();
	else if (gmain.f0 == 13)
		game_cnt_nameentry();
	else if (gmain.f0 == 14)
		game_cnt_hiscore_3B97C();
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_title);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_option_3559C);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_option2);

typedef struct { POS2_T p[7]; } POS7_T;
extern const POS7_T D_0007DCE0;
extern char D_0007DD18[], D_0007DB9C[], text_buf[];
extern char *future_name_list[];
extern int D_00349084[3], D_00349090[4];
void inv_font_ascii(char *str, int x, int y, int w, int h, int r, int g, int b, int a);
int inv_font_ascii_check_w(char *s, int size);
void inv_font_ascii_posf(char *str, int x, int y, int w, int h, int r, int g, int b, int a, int mode);
int net_mynumget(void);
void inv_stagestart_set(void);
int inv_netgame_linkcheck(int st);
void sound_start(int no);
void timer_init(int a);
void timer_play(int a);
void df_fade_start(int a, int b, int c, int d, int e);
void enemy_gp_start(int line);
void bgm_rank_start(void);
int sprintf(char *, const char *, ...);
void game_cnt_stagestart(void)
{
	TIMER_W *tm = &gmain.timer;
	POS7_T pos = D_0007DCE0;
	int w;
	char **s;

	if (gmain.f4 == 0) {
		inv_stagestart_set();
		gmain.f4++;
		D_00349090[0] = 0;
		D_00349090[1] = 0;
		D_00349090[2] = 0;
		D_00349090[3] = 0;
		D_00349084[0] = 0;
		D_00349084[1] = 0;
		D_00349084[2] = 0;
	} else if (gmain.f4 == 1) {
		if (gmain.f1c != 1 || inv_netgame_linkcheck(1) == 1)
			gmain.f4 = 10;
	} else if (gmain.f4 == 10) {
		sound_start(0);
		timer_init(stage_format[gmain.ff28].fc);
		timer_play(1);
		df_fade_start(0, 0, 0, 0, 60);
		gmain.f4++;
	} else if (gmain.f4 == 11) {
		if (tm->f[10] == 1)
			gmain.f4 = 12;
	} else if (gmain.f4 == 12) {
		if (gmain.f1c != 1 || inv_netgame_linkcheck(0) == 1) {
			gmain.f1070 = 1;
			gmain.f0 = 5;
			gmain.f8 = 0;
			gmain.f4 = 0;
		}
	}
	if (gmain.f4 == 11) {
		if (tm->f[9] == 0)
			D_00349084[0] = gmain.timer.f[21];
		else if (tm->f[9] == 1)
			D_00349084[1] = gmain.timer.f[21];
		else if (tm->f[9] == 2)
			D_00349084[0] = D_00349084[1] = 255 - gmain.timer.f[21];
		else if (tm->f[9] == 3) {
			D_00349084[0] = 0;
			D_00349084[1] = 0;
			D_00349084[2] = 255 - gmain.timer.f[21];
		}
		if (D_00349084[0] > 0) {
			int n = gmain.ff28 + 73;
			inv_font_ascii(future_name_list[n], pos.p[0].x - inv_font_ascii_check_w(future_name_list[n], 100) / 2, pos.p[0].y, 100, 100, 255, 255, 255, D_00349084[0]);
			if (IST.fc >= 2) {
				sprintf(text_buf, D_0007DD18, future_name_list[124], IST.fc);
				inv_font_ascii_posf(text_buf, pos.p[3].x, pos.p[3].y, 100, 100, 255, 255, 255, D_00349084[0], 8);
			}
			if (gmain.f1c == 1) {
				sprintf(text_buf, D_0007DB9C, future_name_list[116 + net_mynumget()]);
				inv_font_ascii_posf(text_buf, pos.p[6].x, pos.p[6].y, 100, 100, 255, 255, 255, D_00349084[0], 0);
			} else {
				sprintf(text_buf, D_0007DD18, future_name_list[23], IST.f0);
				inv_font_ascii_posf(text_buf, pos.p[4].x, pos.p[4].y, 100, 100, 255, 255, 255, D_00349084[0], 8);
			}
			sprintf(text_buf, D_0007DD18, future_name_list[106], IST.f4);
			inv_font_ascii_posf(text_buf, pos.p[5].x, pos.p[5].y, 100, 100, 255, 255, 255, D_00349084[0], 8);
		}
		if (D_00349084[1] > 0) {
			int n = gmain.ff28 + 91;
			inv_font_ascii(future_name_list[n], pos.p[1].x - inv_font_ascii_check_w(future_name_list[n], 100) / 2, pos.p[1].y, 100, 100, 255, 255, 255, D_00349084[1]);
		}
		if (D_00349084[2] > 0) {
			inv_font_ascii(future_name_list[87], pos.p[2].x - inv_font_ascii_check_w(future_name_list[87], 100) / 2, pos.p[2].y, 100, 100, 255, 255, 255, D_00349084[2]);
		}
		if (D_00349090[0] == 0 && tm->f[9] == 0 && tm->f[8] == 0) {
			enemy_gp_start(0);
			D_00349090[0] = 1;
		}
		if (D_00349090[1] == 0 && tm->f[9] == 0 && tm->f[8] == 2) {
			enemy_gp_start(1);
			D_00349090[1] = 1;
		}
		if (D_00349090[2] == 0 && tm->f[9] == 1 && tm->f[8] == 0) {
			enemy_gp_start(2);
			D_00349090[2] = 1;
		}
		if (D_00349090[3] == 0 && tm->f[9] == 1 && tm->f[8] == 2) {
			enemy_gp_start(3);
			D_00349090[3] = 1;
			bgm_rank_start();
		}
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_game);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_pause);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_stageclear);

typedef struct { POS2_T p[4]; } POS4_T;
extern const POS4_T D_0007DD58;
extern int D_003490B0, D_003490B4, D_003490B8, game_count;
extern char D_0007DB9C[], D_0007DCDC[], text_buf[];
extern char *future_name_list[];
extern char *future_result_list[];
void inv_font_ascii_posf(char *str, int x, int y, int w, int h, int r, int g, int b, int a, int mode);
int net_mynumget(void);
int inv_netgame_member_max(void);
int df_fade_check(void);
void df_fade_start(int a, int b, int c, int d, int e);
void df_blur_start(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
void df_blur_scrpos_set(int x, int y);
int sound_stop1(void);
float sinf(float);
int sprintf(char *, const char *, ...);
void game_cnt_result(void)
{
	POS4_T pos = D_0007DD58;
	int id[4], sc[4];
	int i, j, n, m, v, k, me, b, y;

	if (gmain.f4 == 0) {
		gmain.f8 += 4;
		if (gmain.f8 > 255)
			gmain.f8 = 255;
		D_003490B0 = gmain.f8;
		D_003490B4 = gmain.f8;
		D_003490B8 = 0;
		if (gmain.f8 >= 255) {
			gmain.f4 = 10;
			gmain.f8 = 0;
		}
	} else if (gmain.f4 == 10) {
		gmain.f8 += 4;
		if (gmain.f8 >= 255) {
			gmain.f4 = 20;
			gmain.f8 = 0;
		}
	} else if (gmain.f4 == 20) {
		gmain.f8 += 8;
		if (gmain.f8 > 255)
			gmain.f8 = 255;
		df_blur_start(-7, 0, 103, 103, 255, 255, 255, gmain.f8, 2, 180);
		df_blur_scrpos_set(240, 136);
		if (gmain.f8 == 255) {
			df_fade_start(0, 0, 0, 1, 60);
			gmain.f4++;
			gmain.f8 = 0;
		}
	} else if (gmain.f4 == 21) {
		gmain.f8++;
		if (gmain.f8 > 255)
			gmain.f8 = 255;
		D_003490B8 = gmain.f8;
		if (df_fade_check()) {
			sound_stop1();
			gmain.f4++;
		}
	} else {
		gmain.f1060 = gmain.ff28 + 201;
		gmain.f105c = 1;
		gmain.fc = 0;
		gmain.ff38 = gmain.ff28 + 1;
		if (gmain.f1c == 1) {
			gmain.f1060 = gmain.ff28 + 1;
			if (gmain.ff28 + 1 >= 14) {
				gmain.f1060 = 1;
				IST.fc++;
			}
		}
	}
	if (D_003490B0 > 0) {
		poly_set(0, 0, 480, 272, 0, 0, 0, 0, 160, 0, 0, 0, 160, 0, 0, 0, 64, 0, 0, 0, 64, 2000, 2, 1, D_003490B0);
		inv_font_ascii_posf(future_result_list[0], pos.p[0].x, pos.p[0].y, 100, 100, 255, 255, 255, D_003490B0, 3);
		poly_set(0, pos.p[0].y + 12, 480, 1, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 2100, 2, 1, D_003490B0);
	}
	if (D_003490B4 > 0) {
		me = net_mynumget();
		for (i = 0; i < inv_netgame_member_max(); i++) {
			id[i] = i;
			sc[i] = (&gmain.netpl[i])->score;
		}
		for (n = 1; n < inv_netgame_member_max(); n++) {
			k = id[n];
			v = sc[n];
			for (j = n - 1; j >= 0 && sc[j] < v; j--) {
				id[j + 1] = id[j];
				sc[j + 1] = sc[j];
			}
			id[j + 1] = k;
			sc[j + 1] = v;
		}
		for (m = 0, y = 0; m < inv_netgame_member_max(); m++, y += 40) {
			if (id[m] != me)
				b = 255;
			else {
				b = 128;
				sinf((game_count % 180) / 180.0f * 3.1415927f);
			}
			sprintf(text_buf, D_0007DB9C, future_name_list[110 + m]);
			inv_font_ascii_posf(text_buf, pos.p[1].x, pos.p[1].y + y, 100, 100, 255, 255, b, D_003490B4, 4);
			sprintf(text_buf, D_0007DB9C, future_name_list[116 + id[m]]);
			inv_font_ascii_posf(text_buf, pos.p[2].x, pos.p[2].y + y, 100, 100, 255, 255, b, D_003490B4, 3);
			sprintf(text_buf, D_0007DCDC, sc[m]);
			inv_font_ascii_posf(text_buf, pos.p[3].x, pos.p[3].y + y + 16, 100, 100, 255, 255, b, D_003490B4, 5);
		}
	}
	if (D_003490B8 > 0)
		poly_set(0, 0, 480, 272, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 19999, 2, 2, D_003490B8);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", game_cnt_gameover);

extern int game_pause, D_003490D0, D_003490D4;
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

	st = gmain.f4;
	game_pause = 0;
	(&gmain.ziki)->f14 = 1;
	gmain.f1058 = 0;
	gmain.f1068 = 0;
	gmain.f1070 = 0;
	if (st == 0) {
		if (gmain.f8 == 0) {
			beat_help_off();
			se_stop();
			gmain.f10ac = 14;
			gmain.f10b0 = 127;
			gmain.f10b4 = 127;
		}
		gmain.f8 += 8;
		if (gmain.f8 > 255)
			gmain.f8 = 255;
		D_003490CC = gmain.f8;
		D_003490C8 = gmain.f8;
		if (gmain.f8 == 255) {
			gmain.f8 = 0;
			gmain.f4++;
		}
	} else if (st == 1) {
		IST.f0--;
		if (IST.f0 > 0)
			gmain.f4 = 20;
		else
			gmain.f4 = 10;
	} else if (st == 10) {
		gmain.f8 += 8;
		if (gmain.f8 > 255)
			gmain.f8 = 255;
		D_003490CC = 255 - gmain.f8;
		D_003490C8 = 255 - gmain.f8;
		if (gmain.f8 == 255) {
			gmain.f4 = 11;
			gmain.f8 = 0;
		}
	} else if (st == 11) {
		gmain.f0 = 9;
		gmain.f4 = 0;
		gmain.f8 = 0;
		gmain.f1058 = 0;
	} else if (st == 20) {
		df_fade_start(0, 0, 0, 1, 60);
		gmain.f4++;
	} else if (st == 21) {
		if (df_fade_check())
			gmain.f4++;
	} else if (st == 22) {
		sound_stop();
		gmain.f105c = 1;
		gmain.f1060 = gmain.ff28;
		gmain.fc = 0;
	}
	if (D_003490C8 > 0)
		inv_font_ascii_posf(D_000828EC, pos.x, pos.y, 100, 100, 255, 255, 255, D_003490C8, 4);
	if (D_003490CC > 0)
		poly_set(0, 0, 480, 272, 0, 128, 128, 128, 255, 128, 128, 128, 255, 128, 128, 128, 255, 128, 128, 128, 255, 2000, 2, 2, D_003490CC);
}

extern const POS2_T D_0007DD50;
extern int game_pause, D_003490D0, D_003490D4;
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

	st = gmain.f4;
	game_pause = 0;
	(&gmain.ziki)->f14 = 1;
	gmain.f1058 = 0;
	gmain.f1068 = 0;
	gmain.f1070 = 0;
	if (st == 0) {
		if (gmain.f8 == 0) {
			beat_help_off();
			gmain.f10ac = 14;
			gmain.f10b0 = 127;
			gmain.f10b4 = 127;
		}
		gmain.f8 += 8;
		if (gmain.f8 > 255)
			gmain.f8 = 255;
		D_003490D4 = gmain.f8;
		D_003490D0 = gmain.f8;
		if (gmain.f8 == 255) {
			gmain.f8 = 0;
			gmain.f4++;
		}
	} else if (st == 1) {
		r = inv_netgame_linkcheck2(3);
		if (r == 1) {
			gmain.f0 = 9;
			gmain.f4 = 0;
			gmain.f8 = 0;
			gmain.f1058 = 0;
		} else if (r == 2) {
			gmain.f0 = 7;
			gmain.f4 = st;
			gmain.f8 = 0;
			gmain.f1058 = 0;
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

void inv_polydisp_clear(void)
{
	int i, j, k, m, n, l;
	BG_T *b;

	if (game_model_load == 0)
		return;
	b = &gmain.bg;
	if (b->on == 1) {
		for (l = 0; l < 5; l++)
			if (b->gmo[l] >= 0)
				((GMO_T *)gmo)[b->gmo[l]].f4 = 0;
		inv_star_dispset(0);
	}
	if (gmain.f1080 == 1 && (&gmain.ziki)->gmo >= 0)
		((GMO_T *)gmo)[(&gmain.ziki)->gmo].f4 = 0;
	if (gmain.f1084 == 1) {
		for (m = 0; m < 16; m++)
			if ((*&gmain.shield_gmo[m]) >= 0)
				((GMO_T *)gmo)[(*&gmain.shield_gmo[m])].f4 = 0;
	}
	if (gmain.f1088 == 1) {
		for (i = 0; i < 4; i++) {
			gmain.zcnt[i] = 0;
			for (j = 0; j < 11; j++) {
				int *z = (*&gmain.zako_gmo[i][j]);
				for (k = 0; k < 3; k++)
					if (z[k] >= 0)
						((GMO_T *)gmo)[z[k]].f4 = 0;
			}
		}
		gmain.ucnt = 0;
		for (n = 0; n < 2; n++)
			if ((*&gmain.ufo_gmo[n]) >= 0)
				((GMO_T *)gmo)[(*&gmain.ufo_gmo[n])].f4 = 0;
		if (gmain.ff28 == 13 && (*&gmain.bufo_gmo) >= 0)
			((GMO_T *)gmo)[(*&gmain.bufo_gmo)].f4 = 0;
	}
	inv_laser_all_init();
	inv_ring_all_init();
}

void inv_polydisp_clear_off(void)
{
	int i;
	BG_T *b;

	if (game_model_load == 0)
		return;
	b = &gmain.bg;
	if (b->on != 1)
		return;
	for (i = 0; i < 5; i++) {
		if (b->gmo[i] >= 0)
			((GMO_T *)gmo)[b->gmo[i]].f4 = 1;
	}
	inv_star_dispset(1);
}

void inv_polydisp_clear2(void)
{
	int i, j, k, m, n;

	if (game_model_load == 0)
		return;
	if (gmain.f1080 == 1 && (&gmain.ziki)->gmo >= 0)
		((GMO_T *)gmo)[(&gmain.ziki)->gmo].f4 = 0;
	if (gmain.f1084 == 1) {
		for (m = 0; m < 16; m++)
			if ((*&gmain.shield_gmo[m]) >= 0)
				((GMO_T *)gmo)[(*&gmain.shield_gmo[m])].f4 = 0;
	}
	if (gmain.f1088 == 1) {
		for (i = 0; i < 4; i++) {
			gmain.zcnt[i] = 0;
			for (j = 0; j < 11; j++) {
				int *z = (*&gmain.zako_gmo[i][j]);
				for (k = 0; k < 3; k++)
					if (z[k] >= 0)
						((GMO_T *)gmo)[z[k]].f4 = 0;
			}
		}
		gmain.ucnt = 0;
		for (n = 0; n < 2; n++)
			if ((*&gmain.ufo_gmo[n]) >= 0)
				((GMO_T *)gmo)[(*&gmain.ufo_gmo[n])].f4 = 0;
		if (gmain.ff28 == 13 && (*&gmain.bufo_gmo) >= 0)
			((GMO_T *)gmo)[(*&gmain.bufo_gmo)].f4 = 0;
	}
	inv_laser_all_init();
	inv_ring_all_init();
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bg_init);

typedef struct { int f0, f4; u8 p8[0x2c - 8]; float rx, ry, rz; u8 p38[0x68 - 0x38]; } GMO_R;
void bg_control(void)
{
	BG_T *b = &gmain.bg;
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

	if ((&gmain.bg)->on == 0)
		return;
	inv_star_dispset(0);
	for (i = 0; i < 5; i++) {
		if (gmain.ff3c[i] != -1)
			bmp_file_unload(gmain.ff3c[i]);
		if (gmain.ff50[i] != -1)
			gmo_file_unload(gmain.ff50[i]);
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ziki_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ziki_control);

void ziki_disp(void)
{
	GMO_T *g;

	if (gmain.f1080 && (&gmain.ziki)->gmo >= 0) {
		g = &((GMO_T *)gmo)[(&gmain.ziki)->gmo];
		*(L2V3 *)((int *)g + 8) = (&gmain.ziki)->pos;
		*(L2V3 *)((int *)g + 11) = (&gmain.ziki)->rot;
		g->f4 = 1;
		((int *)g)[3] = gmain.ff64[(&gmain.ziki)->f20 + 7];
		sprite_set(gmain.ff64[4], 216, 0, 48, 10, 0, 0, 100, 100, 0, 0, 255, 255, 255, 255, 0, 2, 1, 255);
	}
}

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
	TIMER_W *z = &gmain.timer;
	ZIKI *a = &gmain.ziki;

	if (z->f[9] == 3 && z->f[8] == 3 && z->f[7] >= 0) {
		if (a->f4c >= 180)
			return 1;
	}
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ziki_break_errer_check(void) {
    return (&gmain.timer)->f[9] < 2;
}

M2C_UNK ziki_beat_check(void)
{
	ZIKI *z = &gmain.ziki;
	int ret;

	ret = 0;
	if ((z->f30) <= 0) {
		if ((unsigned)(gmain.timer.f[16] - 45) >= 96) {
			if ((z->item[0]) > 0 && (z->item[1]) > 0 && (z->item[2]) > 0)
				ret = (z->item[3]) > 0;
		}
	}
	return ret;
}

M2C_UNK ziki_beat_check2(void)
{
	ZIKI *z = &gmain.ziki;
	int ret;

	ret = 0;
	if (z->item[0] > 0 && z->item[1] > 0 && z->item[2] > 0) {
		ret = z->item[3] > 0;
	}
	return ret;
}

M2C_UNK ziki_beat_miss_check(void)
{
	ZIKI *z = &gmain.ziki;
	int ret;

	ret = 0;
	if ((z->f30) <= 0) {
		if ((z->item[0]) > 0 && (z->item[1]) > 0 && (z->item[2]) > 0) {
			ret = (z->item[3]) > 0;
		}
	}
	return ret;
}

/* gmo objects written through a union view (alias set 0): orders the dead stack copy of v after the field stores */
typedef union { struct { int f0, f4, f8, fc; u8 f10; u8 pad11[3]; int f14, f18, f1c, f20, f24, f28, f2c, f30, f34; L2V3 scale; u8 pad[0x68 - 0x44]; } s; u8 raw[0x68]; } GMOZ_T;
int gmo_load(int no);
typedef struct { u8 pad[0xFA0]; int tex[4][3]; u8 pad2[0x101C - 0xFD0]; int model[4][3]; } GMZ_T;
#define GMZ (*(GMZ_T *)&gmain)
void zako_init(void)
{
	int i, j, k, n;
	GMOZ_T *g;

	if (gmain.f1088 == 0)
		return;
	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 11; j++) {
			int *z = gmain.zako_gmo[i][j];
			for (k = 0; k < 3; k++) {
				n = gmo_load(GMZ.model[i][k]);
				z[k] = n;
				if (n >= 0) {
					L2V3 v;
					g = &((GMOZ_T *)gmo)[n];
					g->s.fc = GMZ.tex[i][k];
					g->s.f20 = 0;
					g->s.f24 = 0;
					g->s.f28 = 0;
					g->s.f2c = 0;
					g->s.f30 = 0;
					g->s.f34 = 0;
					g->s.f4 = 0;
					v = D_0007DEAC;
					g->s.scale = v;
					g->s.f10 = 1;
				}
			}
		}
	}
}

extern const double D_0007E568, D_0007E570, D_0007E578, D_0007E580, D_0007E588, D_0007E590;
void root_pos_get(L2V3 *out, L2V3 *ofs, float pos, float len);
void root_rot_get(L2V3 *out, L2V3 *ofs, float pos);
int zako_shot_count(void);
void zako_init_once(ENEMY *z, int i, int type, int j, float x)
{
	int n;
	L2V3 o, r, d;

	z->type = type;
	z->f0 = j;
	z->f34 = 0;
	z->dead = 0;
	z->f8 = 0;
	z->dmg = 0;
	z->f68 = x;
	n = IST.f10 + 1;
	z->hp = n;
	if (IST.fc >= 2)
		z->hp = n + IST.fc - 1;
	z->f2c = 0;
	z->f40 = 0;
	if (gmain.ff28 == 0) {
		z->f18 = 0;
		z->f10 = zako_shot_count();
	} else {
		z->f18 = 5;
		z->f10 = 0;
	}
	z->grp = i;
	z->f1c = 0;
	z->f44 = genrand_real2() * D_0007E568;
	z->f48 = z->f4c = genrand_real2() + D_0007E570;
	z->f50 = (genrand_real3() - D_0007E578) * D_0007E580;
	z->f54 = (genrand_real3() - D_0007E578) * D_0007E588;
	z->f58 = (genrand_real3() - D_0007E578) * D_0007E590;
	if (z->f50 < 50.0f && -50.0f < z->f50) {
		if (0.0f < z->f50)
			z->f50 = z->f50 + 50.0f;
		else
			z->f50 = z->f50 - 50.0f;
	}
	if (z->f54 < 50.0f && -50.0f < z->f54) {
		if (0.0f < z->f54)
			z->f54 = z->f54 + 50.0f;
		else
			z->f54 = z->f54 - 50.0f;
	}
	if (z->f58 < 50.0f && -50.0f < z->f58) {
		if (0.0f < z->f58)
			z->f58 = z->f58 + 50.0f;
		else
			z->f58 = z->f58 - 50.0f;
	}
	o.x = 0;
	o.y = 0;
	o.z = 0;
	root_pos_get(&z->base, &o, z->f68, z->f0 * 300.0f + 1000.0f);
	r = D_0007DEB8;
	root_rot_get(&z->rot, &r, z->f68);
	z->ofs.x = 0;
	z->ofs.y = 0;
	z->ofs.z = 0;
	z->fa8[0] = 0;
	z->fa8[1] = 0;
	z->fa8[2] = 0;
}

int particle_set(int tex, int no);
void mat_local2screen(V3 *v, V3 *o);
extern unsigned char zako_type_color[][4];
void zako_normal_anime(ENEMY *e, int vis);
void zako_in_anime(ENEMY *e, int vis);
void zako_start_anime(ENEMY *e, int vis);
void zako_end_anime(ENEMY *e, int vis);
void zako_attack_anime(ENEMY *e, int vis);
void zako_control_once(ENEMY *e)
{
	int vis, n;
	float r;
	PARTICLE *q;

	if (e->dead == 1)
		return;
	vis = 1;
	if ((&gmain.egroup[e->grp])->disp == 0) {
		vis = 0;
		e->disp = 0;
	} else if (gmain.zwrap == 0) {
		if (e->f68 < gmain.zclip[0] || gmain.zclip[1] < e->f68) {
			vis = 0;
			e->disp = 0;
		}
	} else {
		if (gmain.zclip[1] <= e->f68 && e->f68 <= gmain.zclip[0]) {
			e->disp = 0;
			vis = 0;
		}
	}
	if (e->f18 == 0)
		zako_normal_anime(e, vis);
	else if (e->f18 == 1)
		zako_in_anime(e, vis);
	else if (e->f18 == 2)
		zako_start_anime(e, vis);
	else if (e->f18 == 3)
		zako_end_anime(e, vis);
	else if (e->f18 == 4)
		zako_attack_anime(e, vis);
	if (e->hp != 1 && e->dmg >= e->hp - 1) {
		e->f2c++;
		if (e->f2c > 45)
			e->f2c = 45;
	}
	if (vis == 0)
		return;
	mat_local2screen((V3 *)&e->pos, (V3 *)&e->scr);
	e->disp = 1;
	if (e->scr.z <= 0.0f)
		e->disp = 0;
	else if (e->scr.x < 0.0f || 480.0f < e->scr.x || e->scr.y < 0.0f || 272.0f < e->scr.y) {
		r = (int)(10000.0f / e->scr.z);
		if (e->scr.x + r < 0.0f || 480.0f < e->scr.x - r || e->scr.y + r < 0.0f || 272.0f < e->scr.y - r)
			e->disp = 0;
	}
	if (e->disp == 0)
		return;
	if (e->f8 <= 0)
		return;
	n = particle_set(gmain.ff64[3], 0x40);
	if (n < 0)
		return;
	q = &gmain.part[n];
	q->f8 = 1;
	q->pos = e->scr;
	q->f2c = e->f8;
	q->f30 = -32.0f;
	q->f60 = q->f5c = 0.5f;
	q->f34 = zako_type_color[e->type][0];
	q->f38 = zako_type_color[e->type][1];
	q->f3c = zako_type_color[e->type][2];
}

extern int D_004B4F9C;
float sinf(float);
float cosf(float);
void zako_mov_count(ENEMY *e, int vis);
int zako_shot_count(void);
void zako_shot(ENEMY *e);
void root_offset_get(L2V3 *out, float pos, float x, float y, float len);
void root_pos_get(L2V3 *out, L2V3 *ofs, float pos, float len);
void zako_normal_anime(ENEMY *e, int vis)
{
	L2V3 o;
	int st;

	if ((&gmain.egroup[e->grp])->disp == 0)
		return;
	zako_mov_count(e, vis);
	if (vis == 1) {
		root_offset_get(&o, e->f68, sinf(e->f44 / 180.0f * 3.1415927f) * e->f60, 0.0f,
			e->f0 * 300.0f + 1000.0f + cosf(e->f44 / 180.0f * 3.1415927f) * e->f60);
		e->ofs.x = o.x - e->base.x;
		e->ofs.y = o.y - e->base.y;
		e->ofs.z = o.z - e->base.z;
		e->fc = sinf(e->f44 / 180.0f * 3.1415927f) * 64.0f + 64.0f;
		root_pos_get(&e->pos, &e->ofs, e->f68, e->f0 * 300.0f + 1000.0f);
	}
	st = gmain.f10;
	e->f10 -= st;
	if (e->f10 < 0.0f)
		e->f10 = 0.0f;
	if (vis == 1 && D_004B4F9C > 0) {
		if (e->f68 < (&gmain.ziki)->x + 10.0f && (&gmain.ziki)->x - 10.0f < e->f68) {
			if (D_004B4F9C == 1)
				e->f10 -= st;
			else
				e->f10 -= st * 2;
		}
	}
	if (e->f10 < 0.0f)
		e->f10 = 0.0f;
	if (e->hp != 1 && e->dmg >= e->hp - 1)
		e->f10 = 255.0f;
	if (e->f10 < 90.0f)
		e->f8 = sinf((90.0f - e->f10) / 180.0f * 3.1415927f) * 255.0f;
	else if (e->f8 > 0) {
		e->f8 -= 8;
		if (e->f8 < 0)
			e->f8 = 0;
	}
	if (e->f10 <= 0.0f) {
		e->f10 = zako_shot_count();
		zako_shot((ENEMY *)e);
	}
}

unsigned long genrand_int32(void);
int zako_shot_count(void)
{
	int n = (float)(genrand_int32() % 3000) * stage_format[gmain.ff28].f10;

	if (n < 180)
		n = 180;
	return n;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_shot);

float target_root_check(float base, float x, float w)
{
	float g = gmain.f10bc;

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
	float g = gmain.f10bc;

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

typedef struct { int f0, f4; u8 _p8[0x20 - 8]; L2V3 pos; L2V3 rot; u8 _p38[0x68 - 0x38]; } ZDO_GMO;
extern unsigned char zako_type_color[][4];
int sprite_set_3d(int tex, int a1, int r, int g, int b, int a, int f64, int f18, float x, float y, float z, float u0, float v0, float u1, float v1, float f48, float f4c, float f50, int f1c);
void gmo_anime_direct(int no, int a1, float f);
void zako_disp_once(ENEMY *e)
{
	int lod, g;
	int *row;
	ZDO_GMO *m;

	if (gmain.zcnt[e->type] >= 11)
		return;
	if (e->disp == 0)
		return;
	if (e->f18 == 5)
		return;
	if (e->dead == 1)
		return;
	lod = 2;
	if (e->scr.z < 850.0f)
		lod = 0;
	else if (e->scr.z < 1150.0f)
		lod = 1;
	row = gmain.zako_gmo[e->type][gmain.zcnt[e->type]];
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
	sprite_set_3d(gmain.ff64[3], 0, zako_type_color[e->type][0], zako_type_color[e->type][1], zako_type_color[e->type][2], zako_type_color[e->type][3], 4 - e->f0, 2,
		e->pos.x, e->pos.y, e->pos.z, texpos_inv_effect[64].w, texpos_inv_effect[64].h, texpos_inv_effect[64].u, texpos_inv_effect[64].v, 3.0f, 3.0f, 0, e->fc);
	gmain.zcnt[e->type]++;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", zako_death);

void zako_death(ENEMY *e, int a, int b);

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
			efc_bom2_start(e->pos.x, e->pos.y, e->pos.z);
			se_play_3d(16, &e->pos.x, 7000.0f);
		}
		if (IST.fc >= 3)
			zako_shot(e);
	} else {
		zako_death(e, a, b);
	}
}

int bgm_rank(void);
int bgm_rank_max(void);
void zako_mov_count(ENEMY *e, int vis)
{
	float sp, a, t, b;
	float w[2];

	sp = e->f4c;
	if (bgm_rank() == 7)
		sp = 1.0f;
	else if (bgm_rank() + 1 >= 6) {
		if (1.2f < sp)
			sp = 1.2f;
	} else if (bgm_rank() + 1 >= 4) {
		if (1.5f < sp)
			sp = 1.5f;
	}
	if ((135.0f <= e->f44 && e->f44 < 180.0f) || (315.0f <= e->f44 && e->f44 < 360.0f)) {
		e->f48 -= 0.03f;
		if (e->f48 < sp * 0.5f)
			e->f48 = sp * 0.5f;
	} else if ((45.0f <= e->f44 && e->f44 < 90.0f) || (225.0f <= e->f44 && e->f44 < 270.0f)) {
		e->f48 += 0.03f;
		if (sp + sp < e->f48)
			e->f48 = sp + sp;
	}
	e->f44 += e->f48;
	while (e->f44 < 0.0f)
		e->f44 += 360.0f;
	while (359.0f < e->f44)
		e->f44 -= 360.0f;
	if (vis != 1)
		return;
	t = (bgm_rank_max() + 5.0f - bgm_rank()) / (bgm_rank_max() + 5.0f);
	w[1] = e->f58 * t;
	if (e->f60 != w[1]) {
		if (w[1] < e->f60) {
			e->f60 -= 1.0f;
			if (e->f60 < w[1])
				e->f60 = w[1];
		} else {
			e->f60 += 1.0f;
			if (w[1] < e->f60)
				e->f60 = w[1];
		}
	}
	b = e->f8 / 255.0f;
	if (b < 0.0f)
		b = 0.0f;
	else if (0.9f < b)
		b = 0.9f;
	if (bgm_rank() == 7) {
		if ((&gmain.timer)->f[8] == 0 || (&gmain.timer)->f[8] == 2) {
			e->f40 += 0.05f;
			if (0.9f < e->f40)
				e->f40 = 0.9f;
		} else if (b < e->f40) {
			e->f40 -= 0.01f;
			if (e->f40 < b)
				e->f40 = b;
		} else if (e->f40 < b) {
			e->f40 += 0.01f;
			if (b < e->f40)
				e->f40 = b;
		}
	} else if (b < e->f40) {
		e->f40 -= 0.05f;
		if (e->f40 < b)
			e->f40 = b;
	} else if (e->f40 < b) {
		e->f40 += 0.05f;
		if (b < e->f40)
			e->f40 = b;
	}
}

void ufo_init_once(UFO_T *u, int no);
void ufo_init(int n)
{
	int i, k, r;
	GMOZ_T *g;

	if (gmain.f1088 == 0)
		return;
	for (k = 0; k < 2; k++) {
		r = gmo_load(gmain.gmo_id[13]);
		*(&gmain.ufo_gmo[k]) = r;
		if (r >= 0) {
			L2V3 v;
			g = &((GMOZ_T *)gmo)[r];
			g->s.fc = gmain.ff64[27];
			g->s.f20 = 0;
			g->s.f24 = 0;
			g->s.f28 = 0;
			g->s.f2c = 0;
			g->s.f30 = 0;
			g->s.f34 = 0;
			g->s.f4 = 0;
			v = D_0007DEC4;
			g->s.scale = v;
			g->s.f10 = 1;
		}
	}
	gmain.ufo_n = n;
	if (n == 0)
		return;
	for (i = 0; i < gmain.ufo_n; i++) {
		ufo_init_once(&gmain.ufo[i], -1);
		(&gmain.ufo[i])->x = gmain.f10bc * i / n;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", ufo_init_once);

extern int game_count;
void netgame_ufo_pos_set(int no, float x);
void netgame_ufo_life_set(int no, int life, int n);
void ufo_control(void)
{
	int i;
	int *u;

	if (gmain.ufo_n == 0)
		return;
	if (gmain.f1088 == 0)
		return;
	for (i = 0; i < gmain.ufo_n; i++) {
		u = ((int *)&gmain.ufo[i]);
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

int ufo_all_dead_check(void)
{
	int i, n = 0;

	if (gmain.ff28 != 13) {
		for (i = 0; i < gmain.ufo_n; i++)
			if ((&gmain.ufo[i])->dead == 1)
				n++;
		if (n >= gmain.ufo_n)
			return 1;
	} else {
		if ((&gmain.bufo)->f4 == 1)
			return 1;
	}
	return 0;
}

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

	if (gmain.f1088 == 0)
		return;
	if (gmain.ff28 != 13)
		return;
	u = (int *)&gmain.bufo;
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

typedef struct { u8 pad[0x6C]; L2V3 pos; } ZIKI_P;
typedef struct { int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44; float f48, f4c, f50, f54, f58, f5c, f60; L2V3 pos; } BUFO_MV;
unsigned long genrand_int32(void);
void boss_laser_start(L2V3 *st, L2V3 *ed, float step);
void bufo_r_move_anime(void *up)
{
	BUFO_MV *u = up;
	float s;
	int n;

	if (u->f34 == 0) {
		u->f28 = 0;
		u->f2c = genrand_int32() % 5 * 60 + 300;
		u->f38 = 4;
		u->f34++;
	} else if (u->f34 == 1) {
		u->f28++;
		if (u->f28 >= u->f2c)
			u->f34 = 2;
	} else {
		if ((genrand_int32() & 1) == 0) {
			if (u->f5c <= 3000.0f)
				u->f30 = 8;
			else
				u->f30 = 7;
		}
		u->f34 = 0;
		u->f28 = 0;
	}
	if (gmain.timer.f[0x44 / 4] < 5 && u->f0 == 1) {
		n = IST.fc;
		if (n >= 2) {
			s = 0.5f;
			s = n * s;
			if (s > 3.0f)
				s = 3.0f;
			{ ZIKI_P *z = (ZIKI_P *)&gmain.ziki; boss_laser_start(&u->pos, &z->pos, s); }
		}
	}
}

void bufo_l_move_anime(void *up)
{
	BUFO_MV *u = up;
	float s;
	int n;

	if (u->f34 == 0) {
		u->f28 = 0;
		u->f2c = genrand_int32() % 5 * 60 + 300;
		u->f38 = 3;
		u->f34++;
	} else if (u->f34 == 1) {
		u->f28++;
		if (u->f28 >= u->f2c)
			u->f34 = 2;
	} else {
		if ((genrand_int32() & 1) == 0) {
			if (u->f5c <= 3000.0f)
				u->f30 = 8;
			else
				u->f30 = 7;
		}
		u->f34 = 0;
		u->f28 = 0;
	}
	if (gmain.timer.f[0x44 / 4] < 5 && u->f0 == 1) {
		n = IST.fc;
		if (n >= 2) {
			s = 0.5f;
			s = n * s;
			if (s > 3.0f)
				s = 3.0f;
			{ ZIKI_P *z = (ZIKI_P *)&gmain.ziki; boss_laser_start(&u->pos, &z->pos, s); }
		}
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bufo_b_move_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bufo_f_move_anime);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", bufo_dead_anime);

typedef struct { int gmo; BUFO_D b; } BOSSW;
void boss_ufo_disp(void)
{
	BOSSW *w;
	BUFO_D *b;
	GMO_T *g;

	if (gmain.f1088 == 0 || gmain.ff28 != 13)
		return;
	gmain.uwrap = 0;
	gmain.uclip[1] = gmain.uclip[0] = (&gmain.cam)->f4c;
	while (gmain.uclip[0] <= 0.0f)
		gmain.uclip[0] += gmain.f10bc - 0.0f;
	while (gmain.uclip[0] >= gmain.f10bc)
		gmain.uclip[0] -= gmain.f10bc - 0.0f;
	while (gmain.uclip[1] <= 0.0f)
		gmain.uclip[1] += gmain.f10bc - 0.0f;
	while (gmain.uclip[1] >= gmain.f10bc)
		gmain.uclip[1] -= gmain.f10bc - 0.0f;
	if (gmain.uclip[0] < gmain.f10bc - 40.0f && 40.0f < gmain.uclip[0]) {
		gmain.uclip[0] -= 40.0f;
		gmain.uclip[1] += 40.0f;
	} else {
		gmain.uwrap = 1;
		if (gmain.f10bc - 40.0f <= gmain.uclip[0]) {
			gmain.uclip[0] -= 40.0f;
			gmain.uclip[1] += 40.0f - gmain.f10bc;
		} else {
			gmain.uclip[0] -= 40.0f - gmain.f10bc;
			gmain.uclip[1] += 40.0f;
		}
	}
	w = (BOSSW *)&gmain.bufo_gmo;
	if (w->gmo >= 0)
		((GMO_T *)gmo)[w->gmo].f4 = 0;
	b = &w->b;
	if (b->f4 == 1)
		return;
	b->f0 = 1;
	if (gmain.uwrap == 0) {
		if (b->f48 < gmain.uclip[0] || gmain.uclip[1] < b->f48)
			b->f0 = 0;
	} else {
		if (gmain.uclip[1] <= b->f48 && b->f48 <= gmain.uclip[0])
			b->f0 = 0;
	}
	if (b->f0 != 0 && w->gmo >= 0) {
		g = &((GMO_T *)gmo)[w->gmo];
		((int *)g)[3] = gmain.ff64[b->f10 + 32];
		g->f4 = 1;
		*(L2V3 *)((int *)g + 8) = *(L2V3 *)&b->pos;
		*(L2V3 *)((int *)g + 11) = *(L2V3 *)&b->rot;
		((float *)g)[12] += b->f60;
	}
}

typedef L2V3 BV3;
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

void zako_init_once(ENEMY *z, int i, int type, int j, float x);
void enemy_gp_init(void)
{
	int i, j, k, l, x;
	EGROUP *e;
	float x0, x1;

	gmain.egroup_n = 0;
	for (i = 0; i < 30; i++)
		(&gmain.egroup[i])->active = 0;
	if (gmain.f1088 == 0)
		return;
	gmain.egroup_n = 0;
	for (i = 0, x = 0; i < 30; i++, x += 90) {
		x1 = x + 70;
		x0 = x;
		if (gmain.f10bc < x1)
			return;
		e = &gmain.egroup[i];
		e->active = 1;
		e->disp = 1;
		e->x0 = x0;
		e->x1 = x1;
		e->n = 0;
		e->dead = 0;
		for (l = 0; l < 11; l++)
			e->x[l] = (10 - l) * (e->x1 - e->x0) / 11.0f + e->x0;
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 11; k++) {
				zako_init_once(&e->e[j][k], i, (i + j) % 4, j, e->x[k]);
				e->n++;
			}
		}
		gmain.egroup_n++;
	}
}

void zako_control_once(ENEMY *e);
void enemy_gp_control(void)
{
	int r[2];
	int wrap;
	int i, j, k;
	EGROUP *g;
	ENEMY *e;

	if (gmain.f1088 == 0)
		return;
	wrap = 0;
	r[1] = r[0] = (&gmain.cam)->f4c;
	while (r[0] <= 0)
		r[0] += gmain.f10bc - 0.0f;
	while (r[0] >= gmain.f10bc)
		r[0] -= gmain.f10bc - 0.0f;
	while (r[1] <= 0)
		r[1] += gmain.f10bc - 0.0f;
	while (r[1] >= gmain.f10bc)
		r[1] -= gmain.f10bc - 0.0f;
	if (r[0] < gmain.f10bc - 40 && 40 < r[0]) {
		r[0] -= 40;
		r[1] += 40;
	} else {
		wrap = 1;
		if (gmain.f10bc - 40 <= r[0]) {
			r[0] -= 40;
			r[1] += 40 - gmain.f10bc;
		} else {
			r[0] -= 40 - gmain.f10bc;
			r[1] += 40;
		}
	}
	for (i = 0; i < gmain.egroup_n; i++) {
		g = &gmain.egroup[i];
		if (g->active == 0)
			return;
		g->disp = 1;
		if (wrap == 0) {
			if (g->x1 < r[0] || r[1] < g->x0)
				g->disp = 0;
		} else {
			if (r[1] <= g->x0 && g->x1 <= r[0])
				g->disp = 0;
		}
		g->dead = 0;
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 11; k++) {
				e = &g->e[j][k];
				zako_control_once(e);
				if (e->dead == 1)
					g->dead++;
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

	if (gmain.f1088 == 0)
		return;
	for (i = 0; i < gmain.egroup_n; i++) {
		g = &gmain.egroup[i];
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

	if (gmain.f1088 == 0)
		return;
	for (i = 0; i < gmain.egroup_n; i++) {
		g = &gmain.egroup[i];
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

	if (gmain.f1088 == 0)
		return;
	for (i = 0; i < gmain.egroup_n; i++) {
		g = &gmain.egroup[i];
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

	if (gmain.f1088 == 0)
		return;
	for (i = 0; i < gmain.egroup_n; i++) {
		g = &gmain.egroup[i];
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
	LASER_T *l = gmain.laser;

	inv_laser_all_init();
	inv_laser_priset();
	inv_ring_all_init();
	inv_ring_priset();
	for (i = 0; i < 32; i++)
		l[i].f0 = 0;
	inv_laser_texno(gmain.ff64[3]);
	inv_ring_texno(gmain.ff64[3]);
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
		atk = (&gmain.ziki)->atk;
		if (D_005FB890 == 1)
			atk = 0;
		dmg = rank_shot_attack[bgm_rank()][0] * (&gmain.ziki)->atk;
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

typedef L2V3 LDV;
typedef struct { int f0, f4; u8 _p8[0x28 - 8]; float f28; u8 _p2c[0x7C - 0x2C]; LDV pos; LDV v[8]; } LDI_T;
extern LDI_T inv_laser_w[] __asm__("inv_laser");
void laser_disp(void)
{
	int i, j;
	LASER_T *l;

	for (i = 0; i < 32; i++) {
		l = &gmain.laser[i];
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
    (&gmain.laser2)->f0 = 0;
}

void laser2_start(float a, float x, float y, float z)
{
	(&gmain.laser2)->f0 = 1;
	(&gmain.laser2)->f18 = a;
	(&gmain.laser2)->p.x = x;
	(&gmain.laser2)->p.y = y;
	(&gmain.laser2)->p.z = z;
	(&gmain.laser2)->q = (&gmain.laser2)->p;
	(&gmain.laser2)->f10 = 0;
	(&gmain.laser2)->fC = 0;
}

void laser2_c_set(float a, float x, float y, float z)
{
	(&gmain.laser2)->p.x = x;
	(&gmain.laser2)->p.y = y;
	(&gmain.laser2)->p.z = z;
	(&gmain.laser2)->q = (&gmain.laser2)->p;
	(&gmain.laser2)->f18 = a;
}

void laser2_start2(void)
{
	LASER2 *l = &gmain.laser2;
	l->fC = 1;
	l->f10 = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void laser2_end(void) {
    D_0035393C = 0;
    (&gmain.laser2)->f0 = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", laser2_control);

M2C_UNK laser2_end_check(void)
{
	if ((&gmain.laser2)->f0 == 0)
		return 1;
	if ((&gmain.laser2)->fC == 2 && (&gmain.laser2)->f10 >= 30)
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
	if (x < gmain.f10bc - w && w < x) {
		r[0] = x - w;
		r[1] = x + w;
	} else {
		wrap = 1;
		if (gmain.f10bc - w <= r[0]) {
			r[0] = r[0] - w;
			r[1] = r[1] + (w - gmain.f10bc);
		} else {
			r[0] = r[0] - (w - gmain.f10bc);
			r[1] = r[1] + w;
		}
	}
	for (i = 0; i < gmain.egroup_n; i++) {
		g = &gmain.egroup[i];
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
int laser2_hit_check_ufo(float x, float w)
{
	int i, hit;
	int ret = 0, wrap = 0;
	float r[2];
	UFO_T *u;
	BUFO_D *b;

	r[0] = x;
	r[1] = x;
	if (x < gmain.f10bc - w && w < x) {
		r[0] = x - w;
		r[1] = x + w;
	} else {
		wrap = 1;
		if (gmain.f10bc - w <= r[0]) {
			r[0] = r[0] - w;
			r[1] = r[1] + (w - gmain.f10bc);
		} else {
			r[0] = r[0] - (w - gmain.f10bc);
			r[1] = r[1] + w;
		}
	}
	if (gmain.ff28 != 13) {
		for (i = 0; i < gmain.ufo_n; i++) {
			u = &gmain.ufo[i];
			if (u->active == 0)
				continue;
			if (u->dead == 1)
				continue;
			if (u->f10 == 1)
				continue;
			if (u->mode == 1)
				continue;
			hit = 1;
			if (wrap == 0) {
				if (u->x < r[0] || r[1] < u->x)
					hit = 0;
			} else {
				if (r[1] <= u->x && u->x <= r[0])
					hit = 0;
			}
			if (hit) {
				int dmg = rank_shot_attack[bgm_rank()][1];
				ufo_damage(u, *(BV3 *)u->pos, dmg, 0, 1);
				netgame_ufo_damage_set3(i, dmg, u->life);
			}
		}
	} else {
		b = &gmain.bufo;
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
	BLZ_T *l = gmain.blaser;

	for (i = 0; i < 32; i++, l++)
		l->active = 0;
}

/* the laser and particle arrays live inside gmain: same base symbol, so the compiler may not disambiguate them */
extern const double D_0007E788, D_0007E790;
void boss_laser_start(L2V3 *st, L2V3 *ed, float step)
{
	int i;
	BLZ_T *l;

	if (gmain.f1058 == 0)
		return;
	for (i = 0; i < 32; i++) {
		l = &gmain.blaser[i];
		if (l->active == 0) {
			l->step = step;
			l->max = 90.0f;
			l->ang = 0;
			l->active = 1;
			l->st = *st;
			l->cnt = 0;
			l->ed = *ed;
			l->amp.x = (genrand_real3() - D_0007E788) * D_0007E790;
			l->amp.y = (genrand_real3() - D_0007E788) * D_0007E790;
			l->amp.z = (genrand_real3() - D_0007E788) * D_0007E790;
			l->pos = *st;
			return;
		}
	}
}

int hit_check_shield(float *pos, float r);
int hit_check_player(float *pos, float r);
void boss_laser_control(void)
{
	int i, n;
	BLZ_T *l;
	PARTICLE *p;

	for (i = 0; i < 32; i++) {
		l = &gmain.blaser[i];
		if (l->active != 1)
			continue;
		l->ang += l->step;
		if (l->max < l->ang)
			l->ang = l->max;
		l->pos.x = l->st.x + sinf(l->ang / 180.0f * 3.1415927f) * (l->ed.x - l->st.x);
		l->pos.y = l->st.y + sinf(l->ang / 180.0f * 3.1415927f) * (l->ed.y - l->st.y);
		l->pos.z = l->st.z + sinf(l->ang / 180.0f * 3.1415927f) * (l->ed.z - l->st.z);
		l->pos.x += sinf(2.0f * l->ang / 180.0f * 3.1415927f) * l->amp.x;
		l->pos.y += sinf(2.0f * l->ang / 180.0f * 3.1415927f) * l->amp.y;
		l->pos.z += sinf(2.0f * l->ang / 180.0f * 3.1415927f) * l->amp.z;
		if (--l->cnt <= 0) {
			n = particle_set(gmain.ff64[3], 63);
			if (n >= 0) {
				p = &gmain.part[n];
				p->f2c = 255.0f;
				p->f30 = -16.0f;
				p->f3c = 64;
				p->pos = l->pos;
				p->f34 = 255;
				p->f38 = 128;
				p->f60 = 0.4f;
				p->f64 = 0.2f;
				p->f68 = 0.2f;
				p->f5c = 0.4f;
			}
			l->cnt = 2;
		}
		if (hit_check_shield(&l->pos.x, 15.0f) >= 0 || hit_check_player(&l->pos.x, 10.0f) >= 0)
			l->active = 0;
		if (l->ang >= l->max)
			l->active = 0;
	}
}

void item_init(void)
{
	int i;
	ITEM_T *l = gmain.item;

	for (i = 0; i < 128; i++, l++)
		l->on = 0;
}

extern const double D_0007E798, D_0007E7A0, D_0007E7A8;
void item_start(int type, float x, float y, float z)
{
	int i;
	ITEM_T *p;

	for (i = 0; i < 128; i++) {
		p = &gmain.item[i];
		if (p->on == 0) {
			p->kind = type;
			p->on = 1;
			p->t = 0;
			p->spd = genrand_real2() + D_0007E798;
			p->pos.x = x;
			p->pos.y = y;
			p->pos.z = z;
			p->ax = (genrand_real3() - D_0007E7A0) * D_0007E7A8;
			p->ay = (genrand_real3() - D_0007E7A0) * D_0007E7A8;
			p->f24 = 0;
			p->f28 = 0;
			p->cur = p->pos;
			return;
		}
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", item_control);

void particle_init(void)
{
	int i;
	PARTICLE *p = gmain.part;

	for (i = 0; i < 512; i++) {
		p->f10 = i;
		p->f0 = 0;
		p++;
	}
}

int particle_set(int tex, int no)
{
	int i;
	PARTICLE *p;

	for (i = 0; i < 512; i++) {
		p = &gmain.part[i];
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
	p->pos.x = 0;
	p->pos.y = 0;
	p->pos.z = 0;
	p->vel.x = 0;
	p->vel.y = 0;
	p->vel.z = 0;
	p->f5c = 1.0f;
	p->f60 = 1.0f;
	p->f64 = 0;
	p->f68 = 0;
	p->rot.x = 0;
	p->rot.y = 0;
	p->rot.z = 0;
	p->drot.x = 0;
	p->drot.y = 0;
	p->drot.z = 0;
	return i;
}

void particle_control(void)
{
	int i;
	PARTICLE *p;

	for (i = 0; i < 512; i++) {
		p = &gmain.part[i];
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
		p->pos.x += p->vel.x;
		p->pos.y += p->vel.y;
		p->pos.z += p->vel.z;
		if (p->f4) {
			p->rot.x += p->drot.x;
			p->rot.y += p->drot.y;
			p->rot.z += p->drot.z;
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
	PARTICLE *p;
	V3 v;

	for (i = 0; i < 512; i++) {
		p = &gmain.part[i];
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
					mat_local2screen((V3 *)&p->pos, &v);
					inv_screffect_start(v.x, v.y, v.z, p->f24, p->f28, p->f1c, p->f20, p->f5c, p->f60, p->f34, p->f38, p->f3c, a);
				} else {
					inv_screffect_start(p->pos.x, p->pos.y, p->pos.z, p->f24, p->f28, p->f1c, p->f20, p->f5c, p->f60, p->f34, p->f38, p->f3c, a);
				}
			} else {
				sprite_set_3d_efc_rot(p->f18, 0, p->pos.x, p->pos.y, p->pos.z, p->f34, p->f38, p->f3c, 255, 100, 2, p->f24, p->f28, p->f1c, p->f20, p->f5c, p->f60, p->rot.x, p->rot.y, p->rot.z, a);
			}
		} else {
			inv_screffect_start2(p->pos.x, p->pos.y, p->f24, p->f28, p->f1c, p->f20, p->f34, p->f38, p->f5c, p->f60, p->f3c, a);
		}
	}
}

M2C_UNK particle_check(int no)
{
	if ((unsigned)no >= 512)
		return 1;
	return (&gmain.part[no])->f0 == 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", efc_bom_start);

extern const double D_0007E7F8, D_0007E800, D_0007E808, D_0007E810, D_0007E818;
void efc_bom2_start(float x, float y, float z)
{
	int i, n;
	PARTICLE *p;

	for (i = 0; i < 8; i++) {
		n = particle_set(gmain.ff64[3], 0x30);
		if (n < 0)
			continue;
		p = &gmain.part[n];
		p->f14 = 8;
		p->f2c = genrand_real2() * D_0007E7F8 + D_0007E7F8;
		p->f30 = -(genrand_real2() * D_0007E800 + D_0007E800);
		p->pos.x = x;
		p->pos.y = y;
		p->pos.z = z;
		p->vel.x = (genrand_real3() - D_0007E808) * D_0007E810;
		p->vel.y = (genrand_real3() - D_0007E808) * D_0007E810;
		p->vel.z = (genrand_real3() - D_0007E808) * D_0007E810;
		p->f60 = p->f5c = genrand_real2() * D_0007E808 + D_0007E818;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", efc_laser_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", efc_ufohit_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", efc_shot_del);

extern float camera_mode[4];
void cam_init(void)
{
	(&gmain.cam)->f0 = 0;
	{
		V3 v = D_0007DF18;
		(&gmain.cam)->eye = v;
	}
	{
		V3 v = D_0007DF24;
		(&gmain.cam)->f30 = v;
	}
	(&gmain.cam)->f50 = camera_mode[0];
	(&gmain.cam)->f54 = camera_mode[1];
	(&gmain.cam)->f58 = camera_mode[2];
	(&gmain.cam)->f5c = camera_mode[3];
	(&gmain.cam)->f3c = 1;
	{
		V3 v = D_0007DF30;
		(&gmain.cam)->f40 = v;
	}
	(&gmain.cam)->f24.x = 0;
	(&gmain.cam)->f24.y = 0;
	(&gmain.cam)->f24.z = 0;
	(&gmain.cam)->f8 = 0;
	(&gmain.cam)->fc = 0;
	(&gmain.cam)->f4c = stage_format[gmain.ff28].f4;
	(&gmain.cam)->f14 = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", cam_control);

#ifndef NULL
#define NULL ((void *)0)
#endif

void dispeffect_all_init(void) {
    (&gmain.de)->f0 = tex_make(5, 0, 0x100, 0x100);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void dispeffect_all_free(void) {
    if ((&gmain.de)->f0 >= 0) {
        bmp_file_unload((&gmain.de)->f0);
    }
}

void dispeffect_init(void)
{
	DISPEFF *d = &gmain.de;

	screen_blur = 0;
	d->f10 = 0;
	d->f4 = 0;
	d->f8 = 0;
	d->fc = 0;
	d->f14 = 0;
	d->f18 = 0;
	d->f1c = 0;
	d->f20 = 0;
	d->f24 = 0;
	d->f28 = 0;
	d->f2c = 0;
	d->f30 = 0;
	d->f34 = 0;
	d->f38 = 0;
	d->f3c = 0;
	d->f40 = 0;
	d->f44 = 0;
	d->f48 = 0;
	d->f4c = 0;
	d->f50 = 0;
	d->f54 = 0;
	d->f58 = 0;
	d->f5c = 0;
	d->f60 = 0;
	d->f64 = 0;
	d->f68 = 0;
	d->f6c = 0;
	d->f70 = 0;
	d->f74 = 0;
	d->f78 = 0;
	d->f7c = 0;
	d->f80 = 0;
	d->f84 = 0;
	d->f88 = 0;
	d->f8c = 0;
	d->f90 = 0;
	d->f94 = 0;
	d->f98 = 0;
}

void df_quake_start(int a, int t)
{
	DISPEFF *d = &gmain.de;
	if (t < d->fc - d->f8)
		return;
	d->fc = t;
	d->f4 = a;
	d->f8 = 0;
}

extern const double D_0007E898;
M2C_UNK df_quake_control(void)
{
	int n;

	if ((&gmain.de)->f8 < (&gmain.de)->fc) {
		(&gmain.de)->f8++;
		if ((&gmain.de)->f8 >= (&gmain.de)->fc) {
			(&gmain.de)->f10 = 0.0f;
			(&gmain.de)->f14 = 0.0f;
			(&gmain.de)->f18 = 0.0f;
		} else {
			n = (&gmain.de)->f4 * ((&gmain.de)->fc - (&gmain.de)->f8) / (&gmain.de)->fc;
			(&gmain.de)->f10 = (genrand_real3() - D_0007E898) * n;
			(&gmain.de)->f14 = (genrand_real3() - D_0007E898) * n;
			(&gmain.de)->f18 = (genrand_real3() - D_0007E898) * n;
		}
	}
}

void df_quake_disp(void)
{
	DISPEFF *d = &gmain.de;
	CAMERA *c = &gmain.cam;

	c->f24.x = d->f10;
	c->f24.y = d->f14;
	c->f24.z = d->f18;
}

void df_blur_start(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
	DISPEFF *w = &gmain.de;
	int cur;

	cur = 0;
	if (w->f44)
		cur = w->f38 * (w->f44 - w->f40) / w->f44;
	if (h < cur)
		return;
	w->f44 = j;
	w->f20 = b;
	w->f24 = c;
	w->f28 = d;
	w->f2c = e;
	w->f30 = f;
	w->f34 = g;
	w->f38 = h;
	w->f3c = i;
	w->f40 = 0;
	w->f1c = a;
}

void df_blur_end(void)
{
	DISPEFF *d = &gmain.de;
	screen_blur = 0;
	d->f40 = d->f44;
}

void df_blur_scrpos_set(int x, int y)
{
	DISPEFF *w = &gmain.de;
	int sx, sy;
	int pos[2];

	if (x < 0) x = 0;
	else if (x > 479) x = 479;
	if (y < 0) y = 0;
	else if (y > 271) y = 271;
	sx = (w->f24 - 100) * 480 / 100;
	sy = (w->f28 - 100) * 272 / 100;
	w->f1c = (480 - x) * sx / 480 - sx;
	w->f20 = (272 - y) * sy / 272 - sy;
}

void df_blur_control(void)
{
	DISPEFF *d = &gmain.de;
	if (d->f40 < d->f44)
		(d->f40)++;
}

typedef struct {
	int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
} SCREEN_BLUR;
#define SB (*(SCREEN_BLUR *)&screen_blur)
extern int game_pause;
M2C_UNK df_blur_disp(void)
{
	if ((&gmain.de)->f40 < (&gmain.de)->f44) {
		if (game_pause == 1) {
			SB.f0 = 0;
		} else if ((&gmain.de)->f40 < (&gmain.de)->f44 - 1) {
			SB.f0 = 1;
			SB.f8 = (&gmain.de)->f3c;
			SB.fc = (&gmain.de)->f1c;
			SB.f10 = (&gmain.de)->f20;
			SB.f14 = 480;
			SB.f18 = 272;
			SB.f1c = 0;
			SB.f20 = 0;
			SB.f30 = (&gmain.de)->f2c;
			SB.f34 = (&gmain.de)->f30;
			SB.f2c = 0;
			SB.f38 = (&gmain.de)->f34;
			SB.f3c = (&gmain.de)->f38 * ((&gmain.de)->f44 - (&gmain.de)->f40) / (&gmain.de)->f44;
			SB.f24 = (&gmain.de)->f24;
			SB.f28 = (&gmain.de)->f28;
		} else {
			SB.f0 = 0;
		}
	}
}

void df_cap_start(int a, int b, int c, int d, int e, int t)
{
	DISPEFF *w = &gmain.de;
	(w->f48) = a;
	(w->f4c) = b;
	(w->f50) = c;
	(w->f54) = d;
	(w->f58) = e;
	(w->f5c) = 0;
	(w->f60) = t;
	screen_capture((w->f0), 1);
}

void df_cap_control(void)
{
	DISPEFF *d = &gmain.de;
	if (d->f5c < d->f60)
		(d->f5c)++;
}

M2C_UNK df_cap_disp(void)
{
	if ((&gmain.de)->f5c < (&gmain.de)->f60)
		sprite_set((&gmain.de)->f0, 0, 0, 0xF0, 0x88, 0, 0, 200, 200, 0, 0, (&gmain.de)->f48, (&gmain.de)->f4c, (&gmain.de)->f50, (&gmain.de)->f54, 1000, 2, (&gmain.de)->f58, ((&gmain.de)->f60 - (&gmain.de)->f5c) * 255 / (&gmain.de)->f60);
}

void df_flash_start(int a, int b, int c, int d, int e, int t)
{
	DISPEFF *w = &gmain.de;
	w->f64 = a;
	w->f68 = b;
	w->f6c = c;
	w->f70 = d;
	w->f74 = e;
	w->f78 = 0;
	w->f7c = t;
}

void df_flash_control(void)
{
	DISPEFF *d = &gmain.de;
	if (d->f78 < d->f7c)
		(d->f78)++;
}

M2C_UNK df_flash_disp(void)
{
	if ((&gmain.de)->f78 < (&gmain.de)->f7c)
		poly_set(0, 0, 480, 272, 0, (&gmain.de)->f64, (&gmain.de)->f68, (&gmain.de)->f6c, (&gmain.de)->f70, (&gmain.de)->f64, (&gmain.de)->f68, (&gmain.de)->f6c, (&gmain.de)->f70, (&gmain.de)->f64, (&gmain.de)->f68, (&gmain.de)->f6c, (&gmain.de)->f70, (&gmain.de)->f64, (&gmain.de)->f68, (&gmain.de)->f6c, (&gmain.de)->f70, 1001, 2, (&gmain.de)->f74, ((&gmain.de)->f7c - (&gmain.de)->f78) * 255 / (&gmain.de)->f7c);
}

void df_fade_start(int a, int b, int c, int d, int t)
{
	DISPEFF *w = &gmain.de;
	w->f80 = a;
	w->f84 = b;
	w->f88 = c;
	w->f8c = 0xFF;
	w->f90 = d;
	w->f94 = 0;
	w->f98 = t;
}

M2C_UNK df_fade_check(void)
{
	DISPEFF *d = &gmain.de;
	if (d->f94 < d->f98)
		return 0;
	return 1;
}

void df_fade_control(void)
{
	DISPEFF *d = &gmain.de;
	if ((d->f90) == 0) {
		if ((d->f94) < (d->f98)) {
			(d->f94)++;
			if ((d->f94) > (d->f98))
				(d->f94) = (d->f98);
		}
	} else {
		(d->f94)++;
		if ((d->f94) > (d->f98))
			(d->f94) = (d->f98);
	}
}

M2C_UNK df_fade_disp(void)
{
	if ((&gmain.de)->f90 == 0) {
		if ((&gmain.de)->f94 < (&gmain.de)->f98)
			poly_set(0, 0, 480, 272, 0, (&gmain.de)->f80, (&gmain.de)->f84, (&gmain.de)->f88, (&gmain.de)->f8c, (&gmain.de)->f80, (&gmain.de)->f84, (&gmain.de)->f88, (&gmain.de)->f8c, (&gmain.de)->f80, (&gmain.de)->f84, (&gmain.de)->f88, (&gmain.de)->f8c, (&gmain.de)->f80, (&gmain.de)->f84, (&gmain.de)->f88, (&gmain.de)->f8c, 20000, 2, 1, ((&gmain.de)->f98 - (&gmain.de)->f94) * 255 / (&gmain.de)->f98);
	} else {
		poly_set(0, 0, 480, 272, 0, (&gmain.de)->f80, (&gmain.de)->f84, (&gmain.de)->f88, (&gmain.de)->f8c, (&gmain.de)->f80, (&gmain.de)->f84, (&gmain.de)->f88, (&gmain.de)->f8c, (&gmain.de)->f80, (&gmain.de)->f84, (&gmain.de)->f88, (&gmain.de)->f8c, (&gmain.de)->f80, (&gmain.de)->f84, (&gmain.de)->f88, (&gmain.de)->f8c, 20000, 2, 1, (&gmain.de)->f94 * 255 / (&gmain.de)->f98);
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
	TIMER_W *t = &gmain.timer;
	(t->f[6]) = a;
	(t->f[0]) = 0;
	(t->f[3]) = 0;
	(t->f[4]) = 0;
	(t->f[5]) = 0;
	(t->f[7]) = 0;
	(t->f[8]) = 0;
	(t->f[9]) = 0;
	(t->f[10]) = 0;
	(t->f[1]) = 0;
	(t->f[2]) = game_cpu_disp;
}

void timer_play(int a)
{
	TIMER_W *t = &gmain.timer;
	if ((t->f[0]) == a)
		return;
	(t->f[0]) = a;
	(t->f[12]) = -1;
	(t->f[11]) = 0;
	(t->f[13]) = 0;
	(t->f[14]) = 0;
	(t->f[15]) = 0;
	(t->f[1]) = 0;
}

void timer_stop(int a)
{
	TIMER_W *t = &gmain.timer;
	t->f[1] = a;
	t->f[12] = -1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", timer_control);

void bgm_init(int no)
{
	BGMWORK *b = &gmain.bgm;
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
	sound_volume_set(gmain.ff30);
	sound_volume_set1(gmain.ff34);
}

extern u8 rank_up_break[][2];
void bgm_control(void)
{
	BGMWORK *b = &gmain.bgm;

	if (b->no == -1)
		return;
	if (b->f18 == 1)
		return;
	if (b->f10 == get_now_sound_block() - 1)
		return;
	if (b->f8 == -1) {
		status_font_set(1, 23, 60, 0, 50);
		gmain.ff30 = 0x8000;
		sound_volume_set(0x8000);
	} else if (b->f8 == 1) {
		status_font_set(1, 22, 60, 0, 50);
		gmain.ff30 = 0x8000;
		sound_volume_set(0x8000);
	}
	b->f14 = 0;
	b->f8 = 0;
	gmain.f10a0 = 0;
	gmain.f10a4 = rank_up_break[b->fc][0] * rank_up_break[b->fc][1];
	b->f10 = get_now_sound_block() - 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void bgm_rankdown(void) {
    if ((&gmain.bgm)->no != -1) {
        if (((&gmain.bgm)->fc > 0) && (get_now_sound_block() != 0xB)) {
            if ((&gmain.bgm)->f8 == 0) {
                (&gmain.bgm)->f8 = -1;
                (&gmain.bgm)->fc = (int) ((&gmain.bgm)->f10 - 1);
                sound_next_block_set((&gmain.bgm)->f10);
            }
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void bgm_rankup(void) {
    if ((&gmain.bgm)->no != -1) {
        if ((&gmain.bgm)->fc != ((&gmain.bgm)->mode - 1)) {
            if (get_now_sound_block() != 0xB) {
                if ((&gmain.bgm)->f8 != 1) {
                    (&gmain.bgm)->f8 = 1;
                    (&gmain.bgm)->fc = (int) ((&gmain.bgm)->f10 + 1);
                    (&gmain.bgm)->f14 = 0;
                    sound_next_block_set((&gmain.bgm)->f10 + 2);
                }
            }
        }
    }
}

void bgm_rank_start(void)
{
	BGMWORK *b = &gmain.bgm;
	b->f8 = 0;
	b->fc = 0;
	sound_next_block_set(1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void bgm_clear_play(void) {
    (&gmain.bgm)->f18 = 1;
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
	BGMWORK *b = &gmain.bgm;
	int ret;

	ret = 0;
	if (b->no != -1)
		ret = b->f10 == b->mode - 1;
	return ret;
}

M2C_UNK bgm_rank_max(void)
{
	return ((&gmain.bgm)->mode == 1) ? 1 : (&gmain.bgm)->mode - 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int bgm_rank(void) {
    return (&gmain.bgm)->f10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void debprint_init(void) {
    (*&gmain.debprint_n) = 0;
}

void debprint_set(char *str)
{
	if (game_cpu_disp) {
		if ((*&gmain.debprint_n) < 20) {
			debug_text(0, (*&gmain.debprint_n) * 10, str);
			(*&gmain.debprint_n)++;
		}
	}
}

void status_disp_init(void)
{
	STATUS_W *t = &gmain.st;
	int i, j;

	t->f4 = 0;
	t->f0 = 0;
	for (i = 0; i < 2; i++) {
		t->i8[i] = -1;
		t->i10[i] = 0;
		t->i18[i] = 0;
		t->i20[i] = 1;
		t->i28[i] = 0;
	}
	for (j = 0; j < 32; j++) {
		t->ta[j] = 0;
		t->tb[j] = 0;
		t->tc[j] = -1;
		t->td[j] = 0;
	}
	t->f40 = 0;
	t->f44 = 0;
	t->f4c = 0;
	t->f50 = 0;
	t->a7e = 255;
	t->s80[0] = 255;
	t->s80[1] = 255;
	t->s74[0] = 0;
	t->s74[1] = 0;
	t->s74[2] = 0;
	t->s74[3] = 0;
	t->f48 = 999;
	t->s80[2] = 255;
	for (j = 0; j < 32; j++) {
		t->s86[j] = 0;
		t->sc6[j] = 0;
		t->s106[j] = 0;
		t->s146[j] = 0;
	}
	for (i = 0; i < 5; i++)
		t->i54[i] = -1;
	t->c68 = 0xf5;
	t->c6c = 0x96;
	t->c70 = 0x35;
}

void status_font_set(int i, int a, int b, int c, int pri)
{
	int *p = &gmain.st.f0 + i;

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
	STATUS_W *t = &gmain.st;

	for (i = 0; i < 32; i++) {
		t->ta[i] = 0;
		t->tb[i] = 0;
		t->tc[i] = -1;
		t->td[i] = 0;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", status_target_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", status_disp);

extern TEXPOS texpos_inv_beat[];
int inv_scrdisp_start(int x, int y, int w, int h, int u, int v, float rot, float sx, float sy, int a, int b, int c, int d);
void status_score_disp(int x, int y, int a, int b, int c, int d, int val);
int inv_netgame_member_max(void);
void status_net_score_disp(void)
{
	int i, x, y, r, g, b, a;
	STATUS_W *c = &gmain.st;

	x = 0x1E8 - (texpos_inv_beat[97].w + texpos_inv_beat[86].w * 10);
	for (i = 0, y = 2; i < inv_netgame_member_max(); y += 8, i++) {
		NETPL *n = &gmain.netpl[i];
		b = c->c6c;
		r = c->c70;
		g = c->c68;
		a = 255;
		if (gmain.f20 == i)
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

extern TEXPOS texpos_inv_beat[];
int num_digit_get(int v, int n);
int inv_scrdisp_start(int x, int y, int w, int h, int u, int v, float rot, float sx, float sy, int a, int b, int c, int d);
extern TEXPOS texpos_inv_beat[];
int num_digit_get(int v, int n);
int inv_scrdisp_start(int x, int y, int w, int h, int u, int v, float rot, float sx, float sy, int a, int b, int c, int d);
void status_score_disp2(int x, int y, int a, int b, int c, int d, int val)
{
	int i, n, px;

	px = x;
	for (i = 10; i > 0; i--) {
		n = num_digit_get(val, i);
		if (n >= 0) {
			inv_scrdisp_start(px, y, texpos_inv_beat[86 + n].w, texpos_inv_beat[86 + n].h, texpos_inv_beat[86 + n].u, texpos_inv_beat[86 + n].v, 0, 100.0f, 100.0f, a, b, c, d);
			px += texpos_inv_beat[86].w - 1;
		}
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", deb_status_disp);

int clippint_check(float x, float w)
{
	int r[2];
	int wrap = 0;
	int ret;

	r[1] = r[0] = (&gmain.cam)->f4c;
	while (r[0] <= 0.0f)
		r[0] += gmain.f10bc - 0.0f;
	while (r[0] >= gmain.f10bc)
		r[0] -= gmain.f10bc - 0.0f;
	while (r[1] <= 0.0f)
		r[1] += gmain.f10bc - 0.0f;
	while (r[1] >= gmain.f10bc)
		r[1] -= gmain.f10bc - 0.0f;
	if (r[0] < gmain.f10bc - w && w < r[0]) {
		r[0] -= w;
		r[1] += w;
	} else {
		wrap = 1;
		if (gmain.f10bc - w <= r[0]) {
			r[0] -= w;
			r[1] += w - gmain.f10bc;
		} else {
			r[0] -= w - gmain.f10bc;
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
	sprite_set(gmain.ff64[type], x, y, w, h, u, v, 100, 100, 0, 0, 255, 255, 255, 255, pri, 2, c1, c2);
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
	sprite_set(gmain.ff64[type], x, y, w, h, u, v, 100, 100, 0, 0, r, g, b, 255, pri, 2, c1, c2);
}

void root_pos_get(L2V3 *out, L2V3 *ofs, float pos, float len)
{
	int a, b;
	float f, s;
	L2V3 p0, p1, d;

	a = pos;
	f = pos - (float)a;
	b = a + 1;
	while (a <= 0)
		a = (float)a + (gmain.f10bc - 0.0f);
	while ((float)a >= gmain.f10bc)
		a = (float)a - (gmain.f10bc - 0.0f);
	while (b <= 0)
		b = (float)b + (gmain.f10bc - 0.0f);
	while ((float)b >= gmain.f10bc)
		b = (float)b - (gmain.f10bc - 0.0f);
	p0.x = gmain.route[a].x;
	p0.y = gmain.route[a].y;
	p0.z = gmain.route[a].z;
	p1.x = gmain.route[b].x;
	p1.y = gmain.route[b].y;
	p1.z = gmain.route[b].z;
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
	gmain.f10bc = size / 24 + stage_format[no].f0 - 1;
	memcpy(gmain.route, p, size);
}

void risarju_init(void)
{
	(&gmain.risarju)->fc = 500.0f;
	(&gmain.risarju)->f14 = 4;
	(&gmain.risarju)->f18 = 3;
	(&gmain.risarju)->f0 = 0;
	(&gmain.risarju)->f4 = 0;
	(&gmain.risarju)->f10 = 0;
	(&gmain.risarju)->f8 = gmain.f10bc;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", risarju_control);

void beat_help_init(void)
{
	BHS_T *b = &gmain.bhs;
	b->on = 0;
	b->mode = 0;
	b->cnt = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void beat_help_set(int arg0) {
    if ((&gmain.bhs)->on != 1) {
        (&gmain.bhs)->on = 1;
        (&gmain.bhs)->mode = arg0;
        (&gmain.bhs)->cnt = 0;
    }
}

void beat_help_off(void)
{
	BHS_T *b = &gmain.bhs;
	b->on = 0;
}

extern char D_0007DB9C[];
extern char *D_0008297C;
extern char *future_name_list[];
int sprintf(char *s, const char *fmt, ...);
int inv_font_ascii_check_w(char *s, int size);
void inv_font_ascii_posf(char *str, int x, int y, int w, int h, int r, int g, int b, int a, int mode);
int poly_g4_set(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3,
	int r0, int g0, int b0, int a0, int r1, int g1, int b1, int a1,
	int r2, int g2, int b2, int a2, int r3, int g3, int b3, int a3,
	int z, int f10, int mode, int alpha);
float sinf(float);
void beat_help_sync_disp(void)
{
	int a, alpha, w;
	int p[3][2];
	BHS_T *b = &gmain.bhs;

	if (b->on == 0)
		return;
	b->cnt++;
	if (b->cnt >= 360) {
		b->on = 0;
		return;
	}
	a = b->cnt;
	while (a < 0)
		a += 180;
	while (a >= 180)
		a -= 180;
	alpha = sinf(a / 180.0f * 3.1415927f) * 512.0f;
	alpha = alpha < 255 ? alpha : 255;
	if (b->mode == 0) {
		sprintf(text_buf, D_0007DB9C, D_0008297C);
		text_buf[6] = 0x84;
		w = inv_font_ascii_check_w(text_buf, 100);
		inv_font_ascii_posf(text_buf, 240, 136, 100, 100, 255, 255, 255, alpha, 7);
	} else {
		sprintf(text_buf, D_0007DB9C, future_name_list[127]);
		text_buf[11] = 0x84;
		w = inv_font_ascii_check_w(text_buf, 75);
		inv_font_ascii_posf(text_buf, 240, 128, 75, 75, 255, 255, 255, alpha, 7);
		sprintf(text_buf, D_0007DB9C, future_name_list[128]);
		inv_font_ascii_posf(text_buf, 240, 144, 75, 75, 255, 255, 255, alpha, 7);
	}
	p[0][0] = 27;
	p[0][1] = 55;
	p[1][0] = 240 - w / 2;
	p[1][1] = b->mode * 12 + 136;
	p[2][0] = p[1][0] + w;
	p[2][1] = p[1][1];
	poly_g4_set(p[0][0], p[0][1], p[0][0] - 1, p[0][1] + 1, p[1][0], p[1][1], p[1][0] - 1, p[1][1] + 1,
		64, 64, 64, 255, 64, 64, 64, 255, 255, 255, 255, 255, 255, 255, 255, 255, 2100, 2, 2, alpha);
	poly_g4_set(p[1][0], p[1][1], p[1][0] - 1, p[1][1] + 1, p[2][0], p[2][1], p[2][0], p[2][1] + 1,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 2100, 2, 2, alpha);
}

#define SHI(p, o) (*(int *)((p) + (o)))
#define SHF(p, o) (*(float *)((p) + (o)))
int hit_check_shield(float *pos, float r)
{
	u8 *p = (u8 *)&gmain.shield;
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
	ZIKI *z = &gmain.ziki;

	if (z->f14 != 0)
		return -1;
	if (pos_fast_length_xyz_check(pos[0] - z->pos.x, pos[1] - z->pos.y, pos[2] - z->pos.z, r) != 1)
		return -1;
	ziki_damage(z, pos);
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", hit_check_enemy);

void ufo_damage(void *u, BV3 p, int dmg, int net, int flag);
void netgame_ufo_damage_set3(int no, int dmg, int life) __asm__("netgame_ufo_damage_set");
int hit_check_ufo(float *pos, int dmg, float r)
{
	int i;
	UFO_T *u;
	BUFO_D *b;

	if (gmain.ff28 != 13) {
		for (i = 0; i < gmain.ufo_n; i++) {
			u = &gmain.ufo[i];
			if (u->active == 0)
				continue;
			if (u->dead == 1)
				continue;
			if (u->f10 == 1)
				continue;
			if (u->mode == 1)
				continue;
			if (pos_fast_length_xyz_check(pos[0] - u->pos[0], pos[1] - u->pos[1], pos[2] - u->pos[2], r) != 1)
				continue;
			status_font_set(1, 24, 30, 0, 10);
			ufo_damage(u, *(BV3 *)pos, dmg, 0, 1);
			netgame_ufo_damage_set3(i, dmg, u->life);
			return i;
		}
	} else {
		r *= 5.0f;
		b = &gmain.bufo;
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

void inv_laser_end(int no);
void efc_shot_del(float x, float y, float z);
int hit_check_laser(float *pos, float r)
{
	int i;

	for (i = 0; i < 32; i++) {
		if ((&gmain.laser[i])->f0 == 0)
			continue;
		if ((&gmain.laser[i])->f8 != 1)
			continue;
		if (pos_fast_length_xyz_check(pos[0] - (&gmain.laser[i])->pos.x, pos[1] - (&gmain.laser[i])->pos.y, pos[2] - (&gmain.laser[i])->pos.z, r) == 1) {
			(&gmain.laser[i])->f0 = 0;
			inv_laser_end((&gmain.laser[i])->f4);
			efc_shot_del((&gmain.laser[i])->pos.x, (&gmain.laser[i])->pos.y, (&gmain.laser[i])->pos.z);
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
	if (gmain.f1c == 1) {
		IST.f0 = gmain.f1c;
		IST.f10 = gmain.f1c;
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
void inv_netgame_init(void)
{
	int i, j, k;
	NETDATA *n;

	for (i = 0; i < 4; i++) {
		n = &((NETDATA *)&netdata)[i];
		(&gmain.netpl[i])->st = 0;
		for (j = 0; j < 250; j++)
			n->d[j] = 0;
	}
	gmain.fea4 = 0;
	for (k = 0; k < 32; k++)
		gmain.fea8[k] = 0;
}

extern int D_004B4F90;
int net_mynumget(void);
int net_entryget(void);
int net_gamecomm_pack(void);
int net_gamecomm_packend(void);
int inv_netgame_loop()
{
	int me, i, j, k, sum, a, b, c, s, t, m;
	NETPL *p;
	NETDATA *n;

	me = net_mynumget();
	p = &gmain.netpl[me];
	n = &((NETDATA *)&netdata)[me];
	if (me == 0)
		p->f4 = net_entryget() + 1;
	p->score = D_004B4F90;
	for (j = 0; j < 250; j++)
		n->d[j] = 0;
	n->d[0] = p->f4;
	n->d[1] = p->score;
	n->d[2] = p->st;
	for (a = 3, b = 0; b < 38; b++) {
		n->d[a++] = p->q[b].kind;
		for (c = 0; c < 5; c++)
			n->d[a++] = p->q[b].d[c];
		if ((unsigned)(p->q[b].kind - 1) < 3) {
			if (--p->q[b].d[3] < 0)
				p->q[b].kind = 0;
		} else {
			p->q[b].kind = 0;
		}
	}
	s = 0;
	for (j = 0; j < 249; j++)
		s += n->d[j];
	n->d[249] = s;
	p->n = 0;
	net_gamecomm_pack();
	if (net_gamecomm_packend() != 0)
		return 1;
	for (i = 0; i < 4; i++) {
		if (me == i)
			continue;
		p = &gmain.netpl[i];
		n = &((NETDATA *)&netdata)[i];
		sum = 0;
		for (j = 0; j < 249; j++)
			sum += n->d[j];
		if (sum != n->d[249])
			continue;
		p->f4 = n->d[0];
		p->score = n->d[1];
		p->st = n->d[2];
		for (a = 3, b = 0; b < 38; b++) {
			p->q[b].kind = n->d[a++];
			for (c = 0; c < 5; c++)
				p->q[b].d[c] = n->d[a++];
		}
		for (k = 0; k < 38; k++) {
			if (p->q[k].kind == 1)
				netgame_zako_damage_get(p, k);
			else if (p->q[k].kind == 2)
				netgame_zako_dead_get(p, k);
			else if (p->q[k].kind == 3)
				netgame_ufo_damage_get(p, k);
			else if (p->q[k].kind == 4)
				netgame_ufo_pos_get(p, k);
			else if (p->q[k].kind >= 5)
				netgame_ufo_life_get(p, k, p->q[k].kind - 5);
		}
	}
	gmain.f20 = me;
	return 0;
}

M2C_UNK inv_netgame_member_max(void)
{
	int n = 4;
	if (gmain.netpl[0].f4 != 0)
		n = gmain.netpl[0].f4;
	return n;
}

int inv_netgame_linkcheck(int st)
{
	int i, n, max;

	n = 0;
	i = 0;
	(&gmain.netpl[gmain.f20])->st = st;
	max = inv_netgame_member_max();
	for (;;) {
		if (i >= max)
			break;
		n += gmain.netpl[i].st == st;
		i++;
	}
	if (n < inv_netgame_member_max())
		return 0;
	return 1;
}

int inv_netgame_linkcheck2(int st)
{
	int i, a, b, max;

	b = 0;
	a = 0;
	i = 0;
	(&gmain.netpl[gmain.f20])->st = st;
	max = inv_netgame_member_max();
	for (;;) {
		if (i >= max)
			break;
		if (gmain.netpl[i].st == 2)
			b++;
		else if (gmain.netpl[i].st == 3)
			a++;
		i++;
	}
	if (b + a >= inv_netgame_member_max())
		return !b ? 1 : 2;
	return 0;
}

void netgame_zako_damage_set(int a, int b, int c, int dmg)
{
	NETPL *p;

	if (gmain.f1c == 0)
		return;
	p = &gmain.netpl[gmain.f20];
	for (;;) {
		if (p->n >= 38)
			return;
		if (p->q[p->n].kind == 0)
			break;
		p->n++;
	}
	p->q[p->n].kind = 1;
	p->q[p->n].d[0] = (a << 16) + (b << 8) + c;
	p->q[p->n].d[1] = dmg;
	p->q[p->n].d[2] = genrand_int32();
	p->q[p->n].d[3] = 4;
	p->n++;
}

void netgame_zako_damage_get(NETPL *q, int k)
{
	int i, found = 0;
	int id = q->q[k].d[2];
	EGROUP *g;

	for (i = 0; i < 32; i++) {
		if (gmain.fea8[i] == id)
			found = 1;
	}
	if (found == 1)
		return;
	gmain.fea8[gmain.fea4] = q->q[k].d[2];
	gmain.fea4++;
	if (gmain.fea4 >= 32)
		gmain.fea4 = 0;
	g = &gmain.egroup[((u8 *)&q->q[k].d[0])[2]];
	zako_damage(&g->e[((u8 *)&q->q[k].d[0])[1]][((u8 *)&q->q[k].d[0])[0]], q->q[k].d[1], 0, 1);
}

void netgame_zako_dead_set(int a, int b, int c)
{
	NETPL *p;

	if (gmain.f1c == 0)
		return;
	p = &gmain.netpl[gmain.f20];
	for (;;) {
		if (p->n >= 38)
			return;
		if (p->q[p->n].kind == 0)
			break;
		p->n++;
	}
	p->q[p->n].kind = 2;
	p->q[p->n].d[0] = (a << 16) + (b << 8) + c;
	p->q[p->n].d[1] = 0;
	p->q[p->n].d[2] = genrand_int32();
	p->q[p->n].d[3] = 4;
	p->n++;
}

void netgame_zako_dead_get(NETPL *q, int k)
{
	int i, found = 0;
	int id = q->q[k].d[2];
	EGROUP *g;

	for (i = 0; i < 32; i++) {
		if (gmain.fea8[i] == id)
			found = 1;
	}
	if (found == 1)
		return;
	gmain.fea8[gmain.fea4] = q->q[k].d[2];
	gmain.fea4++;
	if (gmain.fea4 >= 32)
		gmain.fea4 = 0;
	g = &gmain.egroup[((u8 *)&q->q[k].d[0])[2]];
	zako_death(&g->e[((u8 *)&q->q[k].d[0])[1]][((u8 *)&q->q[k].d[0])[0]], 0, 1);
}

void netgame_ufo_damage_set(int no, int dmg)
{
	NETPL *p;

	if (gmain.f1c == 0)
		return;
	p = &gmain.netpl[gmain.f20];
	for (;;) {
		if (p->n >= 38)
			return;
		if (p->q[p->n].kind == 0)
			break;
		p->n++;
	}
	p->q[p->n].kind = 3;
	p->q[p->n].d[0] = no;
	p->q[p->n].d[1] = dmg;
	p->q[p->n].d[2] = genrand_int32();
	p->q[p->n].d[3] = 4;
	if (gmain.ff28 != 13)
		p->q[p->n].d[4] = (&gmain.ufo[no])->life;
	else
		p->q[p->n].d[4] = (&gmain.bufo)->dmg;
	p->n++;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", netgame_ufo_damage_get);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_game", netgame_ufo_pos_set);

void netgame_ufo_pos_get(u8 *q, int k)
{
	int i;
	float half, t;
	UFO_T *u;

	if (gmain.f20 == 0)
		return;
	half = gmain.f10bc * 0.5f;
	if (gmain.ff28 == 13)
		return;
	for (i = 0; i < gmain.ufo_n; i++) {
		t = ((int *)(q + k * 0x18 + 0x14))[i] / 100.0f;
		u = &gmain.ufo[i];
		if (t < u->x - half)
			t += gmain.f10bc;
		else if (u->x + half < t)
			t -= gmain.f10bc;
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
/* The ufo loop is the THEN arm (ff28 != 13): cse2's path then still knows the
   gmain base register, so &gmain.ufo[i] is not rewritten relative to the split
   gmain+0xE8000 register of gmain.ufo_n (the else-arm form gets addiu s1,a2,14804). */
void netgame_ufo_life_get(u8 *q, int k, int pl)
{
	int i, *v;

	if (gmain.f20 == pl)
		return;
	if (pl >= 4)
		return;
	if (gmain.f0 == 4)
		return;
	if (gmain.ff28 != 13) {
		for (i = 0; i < gmain.ufo_n; i++) {
			UFO_T *u;
			int x = ((int *)(q + k * 0x18 + 0x14))[i];
			u = &gmain.ufo[i];
			if (x > u->life)
				ufo_damage(u, *(BV3 *)u->pos, ((int *)(q + k * 0x18 + 0x14))[i] - u->life, 1, 0);
		}
	} else {
		BUFO_D *b = &gmain.bufo;

		v = (int *)(k * 0x18 + (int)q + 0x14);
		if (b->dmg < *v)
			boss_ufo_damage(b, *(BV3 *)b->pos, *v - b->dmg, 1, 0);
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
	if (gmain.f10ac == 12)
		return;
	if (gmain.f10ac == 22)
		return;
	vol = 127;
	if (dist != 0.0f) {
		vol = 127.0f - s.z * 127.0f / dist;
		if (vol < 32)
			return;
	}
	gmain.f10b0 = 0;
	gmain.f10b4 = 0;
	if (dist != 0.0f) {
		if (s.x < 360.0f)
			gmain.f10b0 = (int)(360.0f - s.x) * vol / 360;
		if (120.0f < s.x)
			gmain.f10b4 = (int)(s.x - 120.0f) * vol / 360;
	} else {
		gmain.f10b0 = vol;
		gmain.f10b4 = vol;
		if (s.x < 240.0f)
			gmain.f10b4 = vol * s.x / 240.0f;
		if (240.0f < s.x)
			gmain.f10b0 = vol * (240.0f - (s.x - 240.0f)) / 240.0f;
	}
	gmain.f10ac = no;
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
