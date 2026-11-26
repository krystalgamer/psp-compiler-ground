#include "common.h"


/* declarations recovered from DWARF */
typedef struct SceRtcTick SceRtcTick;
struct SceRtcTick;
typedef long long unsigned int u_long64;
struct SceRtcTick { /* size 0x8 */
    u_long64 tick;
};
struct _anon1;
struct _anon1 { /* size 0x18 */
    int total;
    int gwang;
    int mung;
    int dan;
    int pi;
    int last_go;
};
typedef struct _anon1 UserScore;
struct _anon2;
struct _anon2 { /* size 0x6c */
    int jabbuck_kind[2];
    int bbuck;
    int shake;
    int go;
    unsigned char turn_event;
    int sp_success[10];
    int sp_bisang[10];
    int game_money;
};
typedef struct _anon2 UserStat;
typedef struct _GRAPHICS Graphics;
struct _GRAPHICS;
typedef long long int long64;
struct _GRAPHICS { /* size 0xb4 */
    void (*init)(void);
    void (*load)(void);
    void (*draw_pae)(int, int, int, float, int);
    void (*draw_pae2)(int, int, int, float, int);
    void (*draw_pae_mark)(int, int, int);
    void (*draw_ox)(int, int, int);
    void (*draw_flying_pae)(int, int, int, float, int);
    void (*draw_flying_pae2)(int, int, int, float, float, int);
    void (*draw_back_pae)(int, int, float, int);
    void (*draw_checked_pae)(int, int, int, float);
    void (*draw_cursor)(int);
    void (*draw_loading)(int);
    void (*draw_my_hand)(void);
    void (*draw_my_collection)(void);
    void (*draw_opp_hand)(void);
    void (*draw_opp_collection)(void);
    void (*draw_dialog_box)(int, int *);
    void (*printDebugMsg)(int, int, const char *);
    void (*printDebugMsg2)(int, int, int, const char *);
    void (*init_sprite)();
    void (*sync_sprite)();
    void (*destroy)();
    void (*swap_buffers)();
    void (*show_gostop_info)();
    void (*show_result_dialog)();
    void (*draw_number)(long64, int, int, int, int, int);
    void (*draw_number2)(char *, int, int, int, int, int);
    int (*draw_animation)(int, int, int, int);
    void (*init_animation)(int);
    void (*draw_timer)(int);
    void (*draw_win_lose)(int, int, unsigned int, unsigned int);
    void (*draw_vs_menu)(void);
    void (*stop_vs_menu)(void);
    void (*draw_collect_paes)(int);
    void (*draw_pause)(void);
    void (*fade_out)(unsigned int);
    void (*draw_char_name)(int, int, const char *);
    void (*draw_all_in)(int);
    void (*draw_save)(void);
    void (*show_warning)(const char *, unsigned int);
    int (*get_img_loaded)(void);
    void (*draw_button)(int, int, int);
    void (*draw_error)(const char *);
    void (*draw_sprite)(int, int, int, int, int);
    void (*draw_sprite2)(int, int, int, int, int, int, int);
};
typedef struct _SOUND_UTIL SoundUtil;
struct _SOUND_UTIL;
struct _SOUND_UTIL { /* size 0x18 */
    void (*init)();
    void (*load)();
    int (*get_sound_loaded)();
    void (*play)(int, int);
    void (*playAll)();
    void (*destroy)();
};
typedef struct _INPUT_MANAGER InputManager;
struct _INPUT_MANAGER;
struct _INPUT_MANAGER { /* size 0x18 */
    int g_cursor_pos;
    int (*pad_read)();
    void (*init)();
    void (*press_circle)(void);
    void (*set_key_enable)(int, int);
    int (*get_key_enable)(int);
};
struct _anon3;
struct _anon3 { /* size 0x20 */
    int pos;
    int count;
    int pae[6];
};
typedef struct _anon3 PanPaes;
typedef struct _HAND HandManager;
struct _HAND;
struct _HAND { /* size 0x2c */
    void (*init)();
    int (*count)(int);
    int (*count_kind)(int, int);
    int (*get_first_kind)(int, int, int *, int *);
    int (*get_kind)(int, int, int *);
    int (*get_pae_at)(int, int);
    void (*remove_pae_at)(int, int);
    void (*sort)(int);
    int (*is_fixed)(int, int);
    void (*add)(int, int);
    int (*check_chongtong)(int);
};
typedef struct _COLLECT CollectManager;
struct _COLLECT;
struct _COLLECT { /* size 0x2c */
    void (*init)(void);
    void (*add)(int, int);
    void (*take_from)(int, int, int);
    void (*set_lastcollect_pos)(int, int, int, int);
    void (*get_lastcollect_pos)(int, int, int *, int *);
    int (*find_gukjin)(int);
    void (*move_gukjin)(int);
    int (*count)(int, int *, int *, int *, int *);
    void (*count_not_flying)(int, int *, int *, int *, int *);
    int (*count_not_flying_pi)(int);
    int (*count_kind)(int, int);
};
typedef struct _DECK DeckManager;
struct _DECK;
struct _DECK { /* size 0x24 */
    void (*init)(void);
    int (*get_pae)(void);
    int (*get_swap_pae)(int);
    int (*count)(void);
    int (*count_all)(void);
    void (*shuffle)(void);
    int (*show_pae)(void);
    void (*get_back_pos)(int *, int *);
    void (*set_pae)(int, int);
};
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
struct _anon5 { /* size 0x38 */
    void (*init)(void);
    void (*add_pae)(int, int, int, int, int, int, int);
    void (*add_pae_bomb)(int, int, int, int, int, int, int);
    void (*me_to_pan)(void);
    void (*me_to_bomb)(void);
    void (*pan_to_collect)(void);
    void (*pan_to_hand)(void);
    void (*collect_to_collect)(void);
    void (*play_bonus_pae)(void);
    int (*is_flying)(int);
    void (*clear)(void);
    void (*add_ani)(int, int, int, int, int, int);
    void (*start_ani)(void);
    int (*count_ani)(void);
};
typedef struct _anon5 Animator;
struct _anon6;
struct _anon6 { /* size 0x10 */
    void (*init)(void);
    void (*process_stage)(void);
    void (*goto_stage)(int);
    void (*wait_stage)(int, int, void (*)());
};
typedef struct _anon6 GameManager;
typedef int SceUID;
struct _anon7;
struct _anon7 { /* size 0x18 */
    void (*init)();
    void (*set_mission_state)(int);
    void (*assign)(int);
    int (*check_mission_success)(int);
    int (*reg_mission_pae)(int, int);
    int (*count_bingo_line)(int);
};
typedef struct _anon7 MissionManager;
struct _anon8;
struct _anon8 { /* size 0x4 */
    int user_level;
};
typedef struct _anon8 UserInfo;
struct _anon9;
struct _anon9 { /* size 0x4c */
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
typedef struct _anon9 SkinManager;
struct _anon10;
struct _anon10 { /* size 0xe8 */
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
typedef struct _anon10 L_Mod_Player;
struct _anon11;
struct _anon11 { /* size 0x1c */
    void (*load_data)();
    void (*update_data)();
    void (*update_level_mission)();
    int (*is_level_cleared)();
    void (*level_initialize)();
    void (*next_level)();
    void (*show_level_mission)(void);
};
typedef struct _anon11 LevelManager;
struct _anon12;
struct _anon12 { /* size 0x14 */
    void (*init)(void);
    void (*set_sp_status)(int, int, int);
    int (*judge)(int);
    int (*get_pae_priority)(int);
    void (*update_sp_status)(void);
};
typedef struct _anon12 AiManager;
struct _anon13;
struct _anon13 { /* size 0x90 */
    SceUID caller_id;
    int return_value;
    int prev_menu;
    char movie_file[128];
    int network_type;
};
typedef struct _anon13 ModSystem;
struct _anon14;
struct _anon14 { /* size 0x8f0 */
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
typedef struct _anon14 ModPlayer;
struct _anon15;
struct _anon15 { /* size 0x78 */
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
typedef struct _anon15 ModGame;
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
};

extern int g_stage_status;
extern int g_confirm;
extern int g_confirm2;
extern int g_fps;
extern int g_continue;
extern int g_timer_pause;
extern int g_show_collect_paes;
extern int g_check_saved;
extern int g_save_error;
extern Graphics graphics;
extern int g_draw_vs_switch;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern SoundUtil soundUtil;
extern InputManager inputManager;
extern PanPaes g_pan[13];
extern HandManager handManager;
extern CollectManager collectManager;
extern int g_my_collection_gwang[5];
extern int g_opp_collection_gwang[5];
extern DeckManager deckManager;
extern UserManager userManager;
extern Animator animator;
extern int g_game_count;
extern int g_round_count;
extern void (*g_wait_func)(void);
extern GameManager gameManager;
extern SceUID idload;
extern int dialog_param[];
extern int dialog_param2[];
extern int g_win_player;
extern int g_nagari_count;
extern int g_player_index;
extern int g_turn;
extern int g_draw_sun;
extern int g_gukjin_checked;
extern int g_game_paused;
extern int all_in_player;
extern int g_show_cursor;
extern int g_mission_state;
extern int g_mission_type;
extern int g_mission_baesu;
extern int g_mission_pae_num;
extern int g_mission_pae[9];
extern int g_mission_who[9];
extern MissionManager missionManager;
extern UserInfo g_user_info;
extern SkinManager skinManager;
extern int g_opp_party[1];
extern int g_opp_char[1];
extern L_Mod_Player l_mod_player;
extern L_Mod_Player tmp_mod_player;
extern LevelManager levelManager;
extern char enemy_name[6][3][12];
extern AiManager aiManager;
extern ModSystem mod_system __asm__("PRX_ZERO");
extern ModPlayer mod_player __asm__("_init");
extern ModGame mod_game __asm__("PRX_ZERO");
extern int _gp[];
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern int show_dialog_result;
extern char *stageName[113];
extern SceUID g_power_cb;
extern char warning_msg[100];
extern int g_show_wait;
extern int g_power;
extern int g_timer_switch;
extern int g_timer_limit_sec;
extern SceRtcTick g_timer_tick_now;
extern SceRtcTick g_timer_tick_old;
extern u_long64 g_timer_tick_spend;
extern char g_char_name[2][13];
extern int g_hidden_skin_on;
extern char *g_save_error_msg[9];

static void image_load();
int main(void);
static void process_stage(void);
static void process_stage_11DF0(void);
void show_debug_info(void);
static void draw_frame(void);
void init_all(void);
void start_timer(int sec);
void check_dialog_finish(void);
int sceUtilitySavedataGetStatus(void);
int sceUtilitySavedataShutdownStart(void);
int modSaveResult(void);
int modSaveResultAborted(void);
extern int D_0005AE44;
extern char D_00032190[];
extern char D_0003219C[];
void pae_init(void);
void srand(unsigned int seed);
long time(long *t);
char *strncpy(char *dst, const char *src, unsigned int n);

/* SDK functions (tools/sdk_protos.h) */
void sceKernelExitGame(void);


int exit_handler(void) {
    sceKernelExitGame();
    return 0;
}

static void image_load()
{
	skinManager.load_character(0, l_mod_player.player_party, l_mod_player.player_character);
	strncpy(g_char_name[0], l_mod_player.player_name, 12);
	if (mod_game.game_type == 1 && l_mod_player.hidden_game_rest > 0) {
		if (l_mod_player.hidden_character == 1) {
			skinManager.load_skin(5, 0);
			skinManager.load_character(1, 5, 0);
			strncpy(g_char_name[1], D_00032190, 12);
			mod_player.hidden1_activated[mod_player.active_player] = 1;
		} else if (l_mod_player.hidden_character == 2) {
			skinManager.load_skin(5, 1);
			skinManager.load_character(1, 5, 1);
			strncpy(g_char_name[1], D_0003219C, 12);
			mod_player.hidden2_activated[mod_player.active_player] = 1;
		}
		g_hidden_skin_on = 1;
	} else {
		skinManager.load_skin(g_opp_party[0], g_opp_char[0]);
		skinManager.load_character(1, g_opp_party[0], g_opp_char[0]);
		if (mod_game.game_type == 1 || mod_game.game_type == 2)
			strncpy(g_char_name[1], enemy_name[g_opp_party[0]][g_opp_char[0]], 12);
		else
			strncpy(g_char_name[1], mod_game.opp_name, 12);
		g_hidden_skin_on = 0;
	}
	graphics.load();
}

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/main", D_00030550);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/main", D_0003055C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/main", D_00030598);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/main", D_000305C8);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/main", D_00030600);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/main", D_00030634);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/main", D_00030668);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/main", D_00030698);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/main", D_000306C8);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/main", main);

static void process_stage_11DF0(void)
{
	gameManager.process_stage();
}

void show_debug_info(void)
{
	char str[256] = "";

	memset(str, 0, sizeof(str));
}


INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/main", D_00030810);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/main", draw_frame);

void init_all(void)
{
	g_round_count = 0;
	g_game_count++;
	g_gukjin_checked = 0;
	pae_init();
	handManager.init();
	collectManager.init();
	deckManager.init();
	userManager.init();
	inputManager.init();
	animator.init();
	gameManager.init();
	missionManager.init();
	aiManager.init();
	if (g_win_player != -1)
		g_nagari_count = 0;
	g_wait_func = 0;
	srand(time(0));
	all_in_player = 0;
	if (mod_game.game_type == 1) {
		if (l_mod_player.hidden_game_rest > 0) {
			if (!g_hidden_skin_on) {
				if (l_mod_player.hidden_character == 1) {
					skinManager.change_skin(5, 0);
					strncpy(g_char_name[1], D_00032190, 12);
					mod_player.hidden1_activated[mod_player.active_player] = 1;
				} else if (l_mod_player.hidden_character == 2) {
					skinManager.change_skin(5, 1);
					strncpy(g_char_name[1], D_0003219C, 12);
					mod_player.hidden2_activated[mod_player.active_player] = 1;
				}
				g_hidden_skin_on = 1;
			}
			l_mod_player.hidden_game_rest--;
		} else if (g_hidden_skin_on == 1) {
			int op;
			int oc;

			op = g_opp_party[0];
			oc = g_opp_char[0];
			skinManager.change_skin(op, oc);
			strncpy(g_char_name[1], enemy_name[op][oc], 12);
			g_hidden_skin_on = 0;
		}
	}
}

void start_timer(int sec)
{
	g_timer_switch = 1;
	g_timer_tick_spend = 0;
	g_timer_limit_sec = sec;
	g_timer_pause = 0;
	sceRtcGetCurrentTick(&g_timer_tick_now);
	g_timer_tick_old = g_timer_tick_now;
}

void stop_timer(void) {
    g_timer_switch = 0;
}

void check_dialog_finish(void)
{
	int status;

	status = sceUtilitySavedataGetStatus();
	if (status == 3) {
		int ret;

		ret = sceUtilitySavedataShutdownStart();
		if (ret != 0)
			g_save_error = 7;
	}
	if (status == 0 && g_check_saved == 0) {
		int r;

		r = modSaveResult();
		g_check_saved = 1;
		if (r == 0) {
			g_save_error = 0;
			show_dialog_result = 0;
			gameManager.goto_stage(95);
		} else if (r == (int)0x80110382)
			g_save_error = 1;
		else if (r == (int)0x80110383)
			g_save_error = 2;
		else if (r == (int)0x80110384)
			g_save_error = 3;
		else if (r == (int)0x80110385)
			g_save_error = 4;
		else if (r == (int)0x8011038B)
			g_save_error = 5;
		else if (r == (int)0x80110381)
			g_save_error = 6;
		else if (r == 2) {
			if (modSaveResultAborted())
				g_save_error = 7;
			else
				g_save_error = 8;
		} else
			g_save_error = 8;
	}
	D_0005AE44 = status;	/* static int last_status */
}

int power_handler(int a, int b, void *p) {
    if (b & 0x20000) {
        g_power = 0;
    }
    return 0;
}
