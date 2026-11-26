#include "common.h"


struct _anon1;
struct _anon1 { /* size 0x6c */
    int jabbuck_kind[2];
    int bbuck;
    int shake;
    int go;
    unsigned char turn_event;
    int sp_success[10];
    int sp_bisang[10];
    int game_money;
};
typedef struct _anon1 UserStat;
struct _anon2;
struct _anon3;
struct _anon3 { /* size 0x18 */
    int total;
    int gwang;
    int mung;
    int dan;
    int pi;
    int last_go;
};
typedef struct _anon3 UserScore;
struct _anon2 { /* size 0x44 */
    UserScore score;
    long int money_sum;
    int p_bak;
    int g_bak;
    int m_bak;
    int go_bak;
    int go_add;
    int go_baesu;
    int shake_baesu;
    int mission_baesu;
    int nagari_baesu;
    int total_baesu;
};
typedef struct _anon2 ResultScore;
struct _anon4;
struct _anon4 { /* size 0x48 */
    void (*init)(void);
    void (*update)(void);
    int (*is_jabbuck)(int, int);
    int (*check_event)(int, int);
    unsigned char (*get_event)(int);
    int (*bbuck)(int, int);
    int (*get_bbuck_count)(int);
    int (*shake)(int);
    int (*get_shake_count)(int);
    int (*go)(int);
    int (*get_go_count)(int);
    void (*get_score)(int, UserScore *);
    void (*get_stat)(int, UserStat *);
    void (*set_game_money)(int, int);
    void (*add_game_money)(int, int);
    int (*get_game_money)(int);
    void (*set_result_score)(int, int);
    void (*set_sp_success)(int, int);
};
typedef struct _anon4 UserManager;
struct _anon5;
struct _anon5 { /* size 0x4c */
    int (*load_character)(int, int, int);
    int (*load_skin)(int, int);
    void (*term)(void);
    void (*set_char_feel)(int, int);
    int (*draw_character)(int, int, int, int);
    int (*draw_face)(int);
    int (*draw_stage)(void);
    void (*draw_level_mission)(int, int, int, int);
    int (*draw_num_go)(int, int, int);
    int (*draw_num_jum)(int, int, int);
    int (*draw_title_mission)(int, int);
    int (*draw_title_bingo)(int, int);
    int (*draw_num_mission)(int, int, int);
    int (*draw_x2_mission)(int, int);
    int (*draw_num_bingo)(int, int, int);
    void (*draw_status)(int, int, int, int, int, int);
    void (*change_skin)(int, int);
    void (*draw_turn)(int);
    void (*draw_sun)(int);
};
typedef struct _anon5 SkinManager;
struct _anon6;
typedef long long int long64;
struct _anon6 { /* size 0xe8 */
    int level;
    int player_party;
    int player_character;
    char player_name[128];
    int success_level_mission[11];
    long64 my_money;
    long64 opp_money;
    long64 opp2_money;
    int win;
    int lose;
    int intro;
    int active_player;
    int hidden_character;
    int hidden_game_rest;
};
typedef struct _anon6 L_Mod_Player;
struct _anon7;
struct _anon7 { /* size 0x1c */
    void (*load_data)();
    void (*update_data)();
    void (*update_level_mission)();
    int (*is_level_cleared)();
    void (*level_initialize)();
    void (*next_level)();
    void (*show_level_mission)(void);
};
typedef struct _anon7 LevelManager;
struct _anon8;
struct _anon8 { /* size 0x8f0 */
    int level[10];
    int player_party[10];
    int player_character[10];
    char player_name[10][128];
    int success_level_mission[10][11];
    long64 my_money[10];
    long64 opp_money[10];
    unsigned int win[10];
    unsigned int lose[10];
    int intro[10];
    int active_player;
    int hidden_character[10];
    int hidden_game_rest[10];
    int hidden1_activated[10];
    int hidden2_activated[10];
};
typedef struct _anon8 ModPlayer;
struct _anon9;
struct _anon9 { /* size 0x78 */
    unsigned char server_mac[6];
    unsigned char server_ip[16];
    int opp_party;
    int opp_character;
    long64 opp_money;
    char opp_name[13];
    int opp_party2;
    int opp_character2;
    long64 opp_money2;
    char opp_name2[13];
    int game_type;
    long64 money;
    int bet;
    int play_time;
    int player_index;
    int result;
};
typedef struct _anon9 ModGame;

extern int g_stage_status;
extern ResultScore g_result_score;
extern UserManager userManager;
extern SkinManager skinManager;
extern int g_opp_party[1];
extern int g_opp_char[1];
extern int g_bet_money;
extern int g_end_condition;
extern int g_level_mission[11];
extern int tmp_level_mission[11];
extern L_Mod_Player l_mod_player;
extern L_Mod_Player tmp_mod_player;
extern LevelManager levelManager;
/* mod_game, mod_player (and mod_system) are imported: their references are relocated against address 0; distinct symbols keep gcc from sharing the address */
extern ModPlayer mod_player __asm__("_init");
extern ModGame mod_game __asm__("PRX_ZERO");
extern int g_enemy_party[5];
extern long64 g_level_pan_money[12][2];
extern int g_level_bet_money[12];
extern int g_level_mission_list[12][11];

static void load_data();
static void update_data();
static void update_level_mission();
static int is_level_cleared();
static void level_initialize();
static void next_level();
static void show_level_mission();
void print_nothing(const char *fmt, ...);


extern int D_00065EAC;


INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/level", load_data);

static void update_data()
{
	if (mod_game.game_type == 1) {
		mod_player.level[mod_player.active_player] = l_mod_player.level;
		mod_player.my_money[mod_player.active_player] = l_mod_player.my_money;
		mod_player.opp_money[mod_player.active_player] = l_mod_player.opp_money;
		mod_player.win[mod_player.active_player] = l_mod_player.win;
		mod_player.lose[mod_player.active_player] = l_mod_player.lose;
		mod_player.hidden_character[mod_player.active_player] = l_mod_player.hidden_character;
		mod_player.hidden_game_rest[mod_player.active_player] = l_mod_player.hidden_game_rest;
		memcpy(mod_player.success_level_mission[mod_player.active_player], l_mod_player.success_level_mission, sizeof(l_mod_player.success_level_mission));
	}
}

__asm__(".globl update_data");

static void update_level_mission()
{
	UserStat ustat;

	userManager.get_stat(0, &ustat);
	if (ustat.sp_success[2])
		l_mod_player.success_level_mission[0]++;
	if (ustat.sp_success[1])
		l_mod_player.success_level_mission[1]++;
	if (ustat.sp_success[3])
		l_mod_player.success_level_mission[2]++;
	if (ustat.sp_success[4])
		l_mod_player.success_level_mission[3]++;
	if (ustat.sp_success[5])
		l_mod_player.success_level_mission[4]++;
	if (g_result_score.g_bak && g_result_score.m_bak && g_result_score.p_bak)
		l_mod_player.success_level_mission[0]++;
	if (ustat.go >= 5)
		l_mod_player.success_level_mission[6]++;
	if (ustat.go >= 6)
		l_mod_player.success_level_mission[7]++;
	if (ustat.go >= 7)
		l_mod_player.success_level_mission[8]++;
	if (ustat.sp_success[7])
		l_mod_player.success_level_mission[9]++;
	if (ustat.shake >= 2)
		l_mod_player.success_level_mission[10]++;
	if (ustat.sp_success[5] && ustat.go >= 6) {
		if (l_mod_player.hidden_character != 1 || l_mod_player.hidden_game_rest <= 0) {
			l_mod_player.hidden_character = 1;
			l_mod_player.hidden_game_rest = 10;
		}
	}
	if (ustat.sp_success[2] && ustat.sp_success[1] && ustat.sp_success[4] && ustat.go >= 6) {
		if (l_mod_player.hidden_character != 2 || l_mod_player.hidden_game_rest <= 0) {
			l_mod_player.hidden_character = 2;
			l_mod_player.hidden_game_rest = 10;
		}
	}
}

__asm__(".globl update_level_mission");

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/level", is_level_cleared);

static void level_initialize()
{
	if (mod_player.level[mod_player.active_player] < 13) {
		int indexLevel;

		indexLevel = mod_player.level[mod_player.active_player] - 1;
		if (l_mod_player.my_money <= 0)
			l_mod_player.my_money = g_level_pan_money[indexLevel][0];
		l_mod_player.opp_money = g_level_pan_money[indexLevel][1];
		memcpy(g_level_mission, g_level_mission_list[indexLevel], sizeof(g_level_mission));
		g_bet_money = g_level_bet_money[indexLevel];
		memset(l_mod_player.success_level_mission, 0, sizeof(l_mod_player.success_level_mission));
	}
}

__asm__(".globl level_initialize");

static void next_level()
{
	mod_player.level[mod_player.active_player]++;
	if (mod_player.level[mod_player.active_player] < 13) {
		load_data();
		level_initialize();
	} else
		l_mod_player.level = mod_player.level[mod_player.active_player];
}

__asm__(".globl next_level");

static void show_level_mission()
{
	int i;
	int index = 0;
	int suc;
	int tot;

	if (g_stage_status >= 92) {
		for (i = 0; i < 11; i++) {
			tot = tmp_level_mission[i];
			if (tot > 0) {
				suc = tmp_mod_player.success_level_mission[i];
				if (suc > tot)
					suc = tot;
				skinManager.draw_level_mission(index++, i, suc, tot);
			}
		}
	} else {
		for (i = 0; i < 11; i++) {
			tot = g_level_mission[i];
			if (tot > 0) {
				suc = l_mod_player.success_level_mission[i];
				if (suc > tot)
					suc = tot;
				skinManager.draw_level_mission(index++, i, suc, tot);
			}
		}
	}
}

__asm__(".globl show_level_mission");
