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
struct _anon2 { /* size 0x8 */
    int x;
    int y;
};
typedef struct _anon2 Point;
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
struct _anon4;
struct _anon4 { /* size 0x28 */
    int (*get_pae_kind)(int);
    int (*get_pae_value)(int);
    int (*is_gwang)(int);
    int (*is_mung)(int);
    int (*is_dan)(int);
    int (*is_pi)(int);
    int (*is_hong)(int);
    int (*is_chung)(int);
    int (*is_cho)(int);
    int (*is_godori)(int);
};
typedef struct _anon4 PaeManager;
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
typedef struct _PAN PanManager;
struct _PAN;
struct _PAN { /* size 0x38 */
    int (*count)(void);
    int (*get_kind_pos)(int);
    int (*get_kind)(int, int *);
    int (*count_kind)(int);
    int (*get_empty_pos)(void);
    int (*remove_pos)(int);
    int (*remove_pae)(int);
    int (*remove_bonus_pae)(int);
    int (*add)(int, Point *, int *);
    int (*add_kind)(int, int, Point *, int *);
    void (*compact)(void);
    int (*get_max_depth)(int);
    int (*check_chongtong)(void);
    int (*is_exec)(int);
};
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
struct _anon6;
struct _anon6 { /* size 0x44 */
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
typedef struct _anon6 ResultScore;
struct _anon7;
struct _anon7 { /* size 0x48 */
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
typedef struct _anon7 UserManager;
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
struct _anon8;
struct _anon8 { /* size 0x18 */
    void (*init)();
    void (*set_mission_state)(int);
    void (*assign)(int);
    int (*check_mission_success)(int);
    int (*reg_mission_pae)(int, int);
    int (*count_bingo_line)(int);
};
typedef struct _anon8 MissionManager;
struct _anon9;
struct _anon9 { /* size 0x4 */
    int user_level;
};
typedef struct _anon9 UserInfo;
struct _anon10;
struct _anon10 { /* size 0x4c */
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
typedef struct _anon10 SkinManager;
struct _anon11;
struct _anon11 { /* size 0xe8 */
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
typedef struct _anon11 L_Mod_Player;
struct _anon12;
struct _anon12 { /* size 0x1c */
    void (*load_data)();
    void (*update_data)();
    void (*update_level_mission)();
    int (*is_level_cleared)();
    void (*level_initialize)();
    void (*next_level)();
    void (*show_level_mission)(void);
};
typedef struct _anon12 LevelManager;
struct _anon13;
struct _anon13 { /* size 0x14 */
    void (*init)(void);
    void (*set_sp_status)(int, int, int);
    int (*judge)(int);
    int (*get_pae_priority)(int);
    void (*update_sp_status)(void);
};
typedef struct _anon13 AiManager;
struct _anon14;
struct _anon14 { /* size 0x10 */
    void (*init)(void);
    void (*process_stage)(void);
    void (*goto_stage)(int);
    void (*wait_stage)(int, int, void (*)());
};
typedef struct _anon14 GameManager;
typedef int SceUID;
struct _anon15;
struct _anon15 { /* size 0x90 */
    SceUID caller_id;
    int return_value;
    int prev_menu;
    char movie_file[128];
    int network_type;
};
typedef struct _anon15 ModSystem;
struct _anon16;
struct _anon16 { /* size 0x78 */
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
typedef struct _anon16 ModGame;
typedef struct SceRtcTick SceRtcTick;
struct SceRtcTick;
typedef long long unsigned int u_long64;
struct SceRtcTick { /* size 0x8 */
    u_long64 tick;
};

extern int g_stage_status;
extern int g_delay;
extern int g_confirm;
extern int g_confirm2;
extern int g_continue;
extern int g_timer_pause;
extern int g_check_saved;
extern int g_save_error;
extern int g_queue_stage;
extern SoundUtil soundUtil;
extern PaeManager paeManager;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern InputManager inputManager;
extern PanManager panManager;
extern HandManager handManager;
extern Animator animator;
extern DeckManager deckManager;
extern Graphics graphics;
extern int g_draw_vs_switch;
extern ResultScore g_result_score;
extern UserManager userManager;
extern CollectManager collectManager;
extern MissionManager missionManager;
extern UserInfo g_user_info;
extern SkinManager skinManager;
extern int g_opp_party[1];
extern int g_opp_char[1];
extern int g_bet_money;
extern int g_level_mission[11];
extern int tmp_level_mission[11];
extern L_Mod_Player l_mod_player;
extern L_Mod_Player tmp_mod_player;
extern LevelManager levelManager;
extern AiManager aiManager;
extern int g_game_count;
extern int g_round_count;
extern int g_next_stage;
extern void (*g_wait_func)(void);
extern GameManager gameManager;
extern SceUID idload;
extern int dialog_param[4];
extern int dialog_param2[4];
extern int g_win_player;
extern int g_nagari_count;
extern int g_take_don;
extern int g_player_index;
extern int g_turn;
extern int g_sun;
extern int g_draw_sun;
extern int g_player_pae_pos;
extern int g_gukjin_checked;
extern int g_game_paused;
extern int all_in_player;
extern int g_show_cursor;
extern ModSystem mod_system;
extern ModGame mod_game;
extern SceRtcTick rtc_tick;
extern u_long64 g_old_tick;
extern int i_am_server;
extern int g_chongtong_kind[4];
extern int g_shake_kind[9];
extern int flag_ai;
extern int flag_sort_done;
extern unsigned char g_event;
extern int g_steal;
extern int g_flag_bonus_chongtong;
extern int g_show_wait;
extern int show_dialog_result;
extern char g_bgm_file[20];
extern int g_timer_switch;
extern int g_pan_pae_count;
extern u_long64 stage_start_tick;

void set_char_feel(int flagPlayer, int player_feel, int other_feel);
void printGlobal(char *msg);
static void process_network_input();
static void init_game();
#define init init_D330
u_long64 get_tick();
extern int D_00055818;
static void init();
static void give_pae(int to_player, int pae, int pos, int kind);
static void judge_game(int player);
static void process_stage();
static void clear_stage();
static void goto_stage(int stage);
static void wait_stage(int stage, int delay, void (*func)());
double pow(double x, double y);
int rand(void);
void *memset(void *s, int c, unsigned int n);
void exit(int status);


void set_char_feel(int flagPlayer, int player_feel, int other_feel)
{
	int i;

	for (i = 0; i < 2; i++) {
		if (i == flagPlayer)
			skinManager.set_char_feel(i, player_feel);
		else
			skinManager.set_char_feel(i, other_feel);
	}
}


void printGlobal(char *msg)
{
	int player;
	int kind;
	int kind_count;
	int pos;
	int kind2;
	int kind_count2;
	int pos2;

	print_nothing("=========================  GLOBAL \272\257\274\366\265\351 =========================\n");
	print_nothing("%s\n", msg);
	print_nothing("g_stage_status:%d\n", g_stage_status);
	print_nothing("g_confirm:%d\n", g_confirm);
	print_nothing("g_confirm2:%d\n", g_confirm2);
	print_nothing("g_pan_pae_count:%d\n", g_pan_pae_count);
	print_nothing("g_player_pae_pos:%d\n", g_player_pae_pos);
	print_nothing("g_player_index:%d\n", g_player_index);
	print_nothing("g_turn:%d\n", g_turn);
	print_nothing("deck remain:%d\n", deckManager.count());
	print_nothing("g_cursor_pos:%d\n", inputManager.g_cursor_pos);
	player = g_player_index != g_turn;
	print_nothing("current pae:%d\n", handManager.get_pae_at(player, g_player_pae_pos));
	kind = paeManager.get_pae_kind(g_last_pae);
	kind_count = panManager.count_kind(kind);
	pos = panManager.get_kind_pos(kind);
	print_nothing("g_last_pae:%d\n", g_last_pae);
	print_nothing("kind:%d\n", kind);
	print_nothing("kind_count:%d\n", kind_count);
	print_nothing("pos:%d\n", pos);
	kind2 = paeManager.get_pae_kind(g_last_turn_pae);
	kind_count2 = panManager.count_kind(kind2);
	pos2 = panManager.get_kind_pos(kind2);
	print_nothing("g_last_turn_pae:%d\n", g_last_turn_pae);
	print_nothing("kind2:%d\n", kind2);
	print_nothing("kind_count2:%d\n", kind_count2);
	print_nothing("pos2:%d\n", pos2);
	print_nothing("=========================  GLOBAL \272\257\274\366 \263\241 =========================\n");
}

void process_network_input(void) {
}

void init_game(void) {
}

static void init()
{
	g_confirm = 0;
	g_confirm2 = 0;
	g_flag_bonus_chongtong = 0;
}

__asm__(".globl init_D330");

static void give_pae(int to_player, int pae, int pos, int kind)
{
	int depth;
	int sx;
	int sy;
	int dx;
	int dy;

	collectManager.add(to_player, pae);
	depth = panManager.get_max_depth(kind) + 1;
	sx = g_pan_pos[pos][0] + depth * 5;
	sy = g_pan_pos[pos][1];
	collectManager.get_lastcollect_pos(to_player, paeManager.get_pae_value(pae), &dx, &dy);
	if (to_player == 1)
		animator.add_pae(pae, sx, sy, dx + 1, dy, 0, -1);
	else if (to_player == 2)
		animator.add_pae(pae, sx, sy, dx + 1, dy, 0, -1);
	else
		animator.add_pae(pae, sx, sy, dx + 4, dy, 0, -1);
}



static void judge_game(int player)
{
	int index;
	int pae;
	int depth;
	int p;





	int kind = paeManager.get_pae_kind(g_last_pae);
	int kind_count = panManager.count_kind(kind);
	int pos = panManager.get_kind_pos(kind);





	int kind2 = paeManager.get_pae_kind(g_last_turn_pae);
	int kind_count2 = panManager.count_kind(kind2);
	int pos2 = panManager.get_kind_pos(kind2);

	g_steal = 0;














	if (g_last_pae == 51) {
		while ((pos = panManager.get_kind_pos(13)) != -1) {


			int pae = panManager.remove_pos(pos);
			give_pae(player, pae, pos, 13);
			panManager.compact();
		}
	}




	if (kind != kind2) {

		switch (kind_count) {
		case 1:

			while ((pae = panManager.remove_bonus_pae(kind)) > 0)
				give_pae(player, pae, pos, kind);
			break;




		case 2:
			while ((pae = panManager.remove_pos(pos)) > 0)
				give_pae(player, pae, pos, kind);
			break;




		case 3:
			if (g_confirm == 1)
				p = dialog_param[0];
			else if (g_confirm == 2)
				p = dialog_param[1];
			else {
				print_nothing("error! g_confirm is invalid:%d\n", g_confirm);
				printGlobal("from judge put");
				exit(0);
			}


			print_nothing("[%03d]\xbc\xb1\xc5\xc3-player:%d, pae:%d,%d, confirm:%d\n", g_game_count, player, dialog_param[0], dialog_param[1], g_confirm);
			g_confirm = 0;
			memset(dialog_param, 0, sizeof(dialog_param));


			while ((pae = panManager.remove_bonus_pae(kind)) > 0)
				give_pae(player, pae, pos, kind);



			pae = panManager.remove_pos(pos);

			give_pae(player, pae, pos, kind);


			pae = panManager.remove_pae(p);

			give_pae(player, pae, pos, kind);

			break;


		case 4:
			depth = panManager.get_max_depth(kind);
			for (index = 0; index < depth; index++) {
				pae = panManager.remove_pos(pos);
				give_pae(player, pae, pos, kind);
			}


			g_steal++;
			set_char_feel(player, 1, 3);

			if (userManager.is_jabbuck(player, kind))
				g_steal++;
			break;
		}




		switch (kind_count2) {
		case 1:
			break;


		case 2:
			while ((pae = panManager.remove_pos(pos2)) > 0)
				give_pae(player, pae, pos2, kind2);
			break;






		case 3:
			if (g_confirm2 == 1)
				p = dialog_param2[0];
			else if (g_confirm2 == 2)
				p = dialog_param2[1];
			else {
				print_nothing("error! g_confirm2 is invalid:%d\n", g_confirm2);
				printGlobal("from judge turnover");
				exit(0);
			}


			print_nothing("[%03d]\xbc\xb1\xc5\xc3-player:%d, pae:%d,%d, confirm:%d\n", g_game_count, player, dialog_param[0], dialog_param[1], g_confirm);
			g_confirm2 = 0;
			memset(dialog_param2, 0, sizeof(dialog_param2));


			while ((pae = panManager.remove_bonus_pae(kind2)) > 0)
				give_pae(player, pae, pos2, kind2);



			pae = panManager.remove_pos(pos2);

			give_pae(player, pae, pos2, kind2);


			pae = panManager.remove_pae(p);

			give_pae(player, pae, pos2, kind2);

			break;


		case 4:
			g_confirm = 0;
			depth = panManager.get_max_depth(kind2);
			for (index = 0; index < depth; index++) {
				pae = panManager.remove_pos(pos2);
				give_pae(player, pae, pos2, kind2);
			}


			g_steal++;
			set_char_feel(player, 1, 3);

			if (userManager.is_jabbuck(player, kind2))
				g_steal++;
			break;
		}
	} else {
		switch (kind_count) {
		case 2:
			print_nothing("[%03d]\xc2\xca-player:%d, kind:%d\n", g_game_count, player, kind);
			if (handManager.count(player) > 0) {
				soundUtil.play(54, 127);
				g_steal++;
			}


			depth = panManager.get_max_depth(kind);
			for (index = 0; index < depth; index++) {
				set_char_feel(player, 1, 3);
				pae = panManager.remove_pos(pos);
				give_pae(player, pae, pos, kind);
			}


			break;



		case 3:
			if (handManager.count(player) == 0) {
				int paeTemp = panManager.remove_pos(pos);


				while ((pae = panManager.remove_bonus_pae(kind)) > 0)
					give_pae(player, pae, pos, kind);


				pae = panManager.remove_pos(pos);
				give_pae(player, pae, pos, kind);
				pae = panManager.remove_pos(pos);
				give_pae(player, pae, pos, kind);

				panManager.add(paeTemp, 0, 0);

			} else {
				print_nothing("[%03d]\xbb\xb6-player:%d, kind:%d\n", g_game_count, player, kind);

				userManager.bbuck(player, kind);


				skinManager.set_char_feel(player, 2);

				UserStat stat;
				userManager.get_stat(player, &stat);

				if (stat.bbuck == 3) {






					wait_stage(81, 300, 0);

					userManager.set_sp_success(player, 7);
					return;
				}




				if (stat.bbuck == g_round_count) {
					int money_take = g_bet_money * stat.bbuck * (int)pow(2.0, g_nagari_count) * 7;

					if (rand() % 2 == 0)
						animator.add_ani(14, 179, 80, 0, 30, 43);
					else
						animator.add_ani(13, 179, 80, 0, 30, 43);
















































					if (player == 0) {
						g_take_don = money_take;

						if (l_mod_player.opp_money < money_take)
							money_take = l_mod_player.opp_money;
						l_mod_player.my_money += money_take;
						l_mod_player.opp_money -= money_take;
					} else {
						g_take_don = -money_take;

						if (l_mod_player.my_money < money_take)
							money_take = l_mod_player.opp_money;
						l_mod_player.my_money -= money_take;
						l_mod_player.opp_money += money_take;
					}
				} else {





					g_take_don = 0;
					if (rand() % 2 == 0)
						animator.add_ani(14, 179, 80, 0, 30, 43);
					else
						animator.add_ani(13, 139, 80, 0, 30, 43);
				}
			}
			break;


		case 4:
			g_confirm = 0;
			memset(dialog_param, 0, sizeof(dialog_param));

			if (handManager.count(player) > 0) {
				print_nothing("[%03d]\xb5\xfb\xb4\xda-player:%d, kind:%d\n", g_game_count, player, kind);
				animator.add_ani(11, 139, 41, 0, 30, 60);
				g_steal++;

				set_char_feel(player, 1, 3);

				if (g_round_count == 1) {
					int money_take = g_bet_money * g_round_count * (int)pow(2.0, g_nagari_count) * 7;

					userManager.bbuck(player, kind);














































					if (player == 0) {
						g_take_don = money_take;

						if (l_mod_player.opp_money < money_take)
							money_take = l_mod_player.opp_money;
						l_mod_player.my_money += money_take;
						l_mod_player.opp_money -= money_take;
					} else {
						g_take_don = -money_take;

						if (l_mod_player.my_money < money_take)
							money_take = l_mod_player.opp_money;
						l_mod_player.my_money -= money_take;
						l_mod_player.opp_money += money_take;
					}
				}
			}





			depth = panManager.get_max_depth(kind);
			for (index = 0; index < depth; index++) {
				pae = panManager.remove_pos(pos);
				give_pae(player, pae, pos, kind);
			}
			break;
		}
	}








	panManager.compact();


	if (panManager.count() == 0 && handManager.count(player) > 0) {

		print_nothing("[%03d]\xbe\xb5-player:%d\n", g_game_count, player);
		animator.add_ani(10, 146, 54, 0, 30, 42);
		set_char_feel(player, 1, 3);

		g_steal++;
	}



	userManager.update();


	g_last_pae = 0;
	g_last_turn_pae = 0;

	if (animator.count_ani() > 0)
		wait_stage(21, 1000, animator.start_ani);
	else
		goto_stage(21);



}

__asm__(".globl judge_game");

/* judge_game (C) emits this string; process_stage (asm) uses it too */
__asm__(".globl D_0002FBCC\nD_0002FBCC = 0x0002FBCC");









#ifdef NON_MATCHING
/* Close: every stage block has the original size and instructions; ~460 lines
 * differ only in register choice (our GCSE keeps hi(panManager) in s8 across
 * stages 6/17/19, so flagBbuck is spilled; game_type compare regs swapped). */
#define process_stage process_stage_E1E0
extern int D_00055810;	/* static int inform_frame */
extern int D_00055814;	/* static int levelResult */
#define inform_frame D_00055810
#define levelResult D_00055814
extern ModSystem mod_system_z __asm__("mod_system_zero");
__asm__("mod_system_zero = 0");
extern ModGame mod_game_z __asm__("PRX_ZERO");
#define mod_system mod_system_z
#define mod_game mod_game_z
extern char g_bgm_file_a[20] __asm__("g_bgm_file") __attribute__((aligned(4)));
#define g_bgm_file g_bgm_file_a
int find_array(int seed, int *a, int a_size);
int count_array(int *a, int a_size);
void start_timer(int sec);
void stop_timer(void);
void modAtracPlay(char *file);
void modAtracStop(void);
void modSaveData(void);
int sceKernelTerminateDeleteThread(SceUID thid);
int sceRtcGetCurrentTick(SceRtcTick *tick);
char *strcpy(char *d, const char *s);
void *memcpy(void *d, const void *s, unsigned int n);
static void process_stage()
{
	int player;
	int my_turn;
	Point pt;
	int sound;

	my_turn = g_player_index == g_turn;
	player = !my_turn;

	int stage = g_stage_status;

	if (stage == 11) {
		sceRtcGetCurrentTick(&rtc_tick);
		g_old_tick = rtc_tick.tick;
		goto_stage(12);
	}

	if (stage == 12) {
		sceRtcGetCurrentTick(&rtc_tick);
		if ((int)(rtc_tick.tick - g_old_tick) / 1000 > g_delay) {
			animator.clear();
			g_wait_func = 0;
			goto_stage(g_next_stage);
		}
	}

	if (stage == 3) {
		clear_stage();
		sceKernelTerminateDeleteThread(idload);
		init_game();
		goto_stage(4);
	}

	if (stage == 4) {
		clear_stage();
		print_nothing("STAGE_INIT...\n");
		init_all();
		memset(g_chongtong_kind, 0, sizeof(g_chongtong_kind));
		memset(g_shake_kind, 0, sizeof(g_shake_kind));
		deckManager.shuffle();
		if (mod_game.game_type == 1 && g_game_count == 2)
			goto_stage(8);
		else
			wait_stage(6, 300, 0);
		if ((mod_game.game_type == 1 && l_mod_player.hidden_game_rest > 0) || g_opp_party[0] == 5)
			strcpy(g_bgm_file, "snd/bgm_ch.at3");
		else
			sprintf(g_bgm_file, "snd/bgm_c%d%d.at3", g_opp_party[0] + 1, 3 - g_opp_char[0]);
		modAtracPlay(g_bgm_file);
	}

	if (stage == 6) {
		clear_stage();
		print_nothing("STAGE_DEAL...\n");
		g_sun = g_turn;
		int index;
		for (index = 0; index < 10; index++)
			handManager.add(1, deckManager.get_pae());
		for (index = 0; index < 10; index++)
			handManager.add(0, deckManager.get_pae());
		handManager.sort(0);
		for (index = 0; index < 8; index++)
			panManager.add(deckManager.get_pae(), 0, 0);
		missionManager.assign(l_mod_player.level);
		wait_stage(7, 300, 0);
	}

	if (stage == 8) {
		if (inform_frame > 300) {
			inform_frame = 0;
			graphics.stop_vs_menu();
			goto_stage(6);
			return;
		}
		inform_frame++;
		g_draw_vs_switch = 1;
		g_timer_pause = 1;
		return;
	}

	if (stage == 7) {
		g_draw_sun = player;
		int chongtong_kind = panManager.check_chongtong();
		if (chongtong_kind > 0) {
			dialog_param[0] = chongtong_kind * 4 - 3;
			dialog_param[1] = chongtong_kind * 4 - 2;
			dialog_param[2] = chongtong_kind * 4 - 1;
			dialog_param[3] = chongtong_kind * 4;
			goto_stage(34);
			return;
		}
		int pos = panManager.get_kind_pos(13);
		if (pos != -1) {
			int pae = panManager.remove_pos(pos);
			give_pae(player, pae, pos, 13);
			panManager.compact();
			int newpae = deckManager.get_pae();
			int sx = 0, sy = 0;
			deckManager.get_back_pos(&sx, &sy);
			panManager.add(newpae, &pt, 0);
			animator.add_pae(newpae, sx, sy, pt.x, pt.y, 0, -1);
			wait_stage(7, 3000, animator.play_bonus_pae);
			return;
		} else {
			goto_stage(51);
		}
	}

	if (stage == 51) {
		print_nothing("[STAGE_READY_TURN]\n");
		if (g_player_index != 0 && g_player_index != 1) {
			printGlobal("from stage_ready_turn");
			exit(0);
		}
		if (g_turn == g_sun) {
			g_round_count++;
			print_nothing("[%03d]Round : %d--------------------------\n", g_game_count, g_round_count);
			if (g_round_count == 2) {
				missionManager.set_mission_state(1);
				soundUtil.play(26, 127);
			}
		}
		if (my_turn)
			soundUtil.play(10, 127);
		inputManager.set_key_enable(1, 0);
		inputManager.set_key_enable(7, 0);
		goto_stage(14);
	}

	if (stage == 14) {
		inputManager.set_key_enable(1, 0);
		inputManager.set_key_enable(7, 0);
		skinManager.set_char_feel(player, 0);
		flag_sort_done = 0;
		handManager.sort(g_turn);
		flag_sort_done = 1;
		inputManager.set_key_enable(1, 1);
		inputManager.set_key_enable(7, 1);
		if (g_round_count == 1 || g_flag_bonus_chongtong == 1) {
			int chongtong_kind = handManager.check_chongtong(player);
			if (chongtong_kind > 0 && find_array(chongtong_kind, g_chongtong_kind, 4) == -1) {
				dialog_param[0] = chongtong_kind * 4 - 3;
				dialog_param[1] = chongtong_kind * 4 - 2;
				dialog_param[2] = chongtong_kind * 4 - 1;
				dialog_param[3] = chongtong_kind * 4;
				if (my_turn) {
					switch (g_confirm) {
					case 2:
						g_flag_bonus_chongtong = 0;
						g_confirm = 0;
						g_chongtong_kind[count_array(g_chongtong_kind, 4)] = chongtong_kind;
						return;
					case 1:
						g_flag_bonus_chongtong = 0;
						g_confirm = 0;
						g_chongtong_kind[count_array(g_chongtong_kind, 4)] = chongtong_kind;
						goto_stage(34);
						return;
					case 0:
						handManager.get_kind(0, chongtong_kind, dialog_param);
						if (!g_timer_switch) start_timer(10);
						goto_stage(27);
						return;
					}
					return;
				} else {
					g_flag_bonus_chongtong = 0;
					g_confirm = 0;
					goto_stage(34);
					return;
				}
			}
		}
		if (!my_turn) {
			if (flag_ai)
				g_player_pae_pos = aiManager.judge(player);
			flag_ai = 1;
			if (g_player_pae_pos < 0)
				g_player_pae_pos = 0;
			goto_stage(15);
		} else {
			if (!g_timer_switch) {
				if (flag_ai)
					g_player_pae_pos = aiManager.judge(player);
				flag_ai = 1;
				inputManager.g_cursor_pos = g_player_pae_pos;
				g_show_cursor = 1;
				start_timer(15);
			}
		}
	}

	if (stage == 15) {
		print_nothing("[STAGE_CONFIRM_SHAKE]\n");
		clear_stage();
		if (g_player_index != 0 && g_player_index != 1) {
			printGlobal("from stage_confirm_shake");
			exit(0);
		}
		int pae = handManager.get_pae_at(player, g_player_pae_pos);
		if (pae == 0) {
			print_nothing("pae is zero.\n");
			return;
		}
		int kind = paeManager.get_pae_kind(pae);
		int pos = panManager.get_kind_pos(kind);
		int hand_pae_count = handManager.count_kind(player, kind);
		if (pae < 49 && hand_pae_count >= 3 && pos == -1 && find_array(kind, g_shake_kind, 9) == -1) {
			print_nothing("\xc8\xe7\xb5\xe9\xb1\xe2\xc8\xae\xc0\xce:player-%d, g_confirm-%d, kind-%d, count-%d\n", player, g_confirm, kind, hand_pae_count);
			if (my_turn) {
				flag_ai = 0;
				switch (g_confirm) {
				case 2:
					print_nothing("[%03d]\xc8\xe7\xb5\xe9\xbe\xfa\xc0\xbd-player:%d, kind:%d, pae:%d\n", g_game_count, player, kind, pae);
					g_confirm = 0;
					g_shake_kind[count_array(g_shake_kind, 9)] = kind;
					userManager.shake(0);
					flag_sort_done = 0;
					if (hand_pae_count == 4)
						goto_stage(36);
					else
						goto_stage(33);
					return;
				case 1:
					g_confirm = 0;
					g_shake_kind[count_array(g_shake_kind, 9)] = kind;
					memset(dialog_param, 0, sizeof(dialog_param));
					inputManager.set_key_enable(1, 0);
					inputManager.set_key_enable(7, 0);
					flag_sort_done = 0;
					goto_stage(14);
					return;
				case 0:
					print_nothing("[%03d]\xc8\xe7\xb5\xe9\xb1\xee \xb0\xed\xb9\xce\xc1\xdf-player:%d, kind:%d, pae:%d\n", g_game_count, player, kind, pae);
					handManager.get_kind(0, kind, dialog_param);
					if (!g_timer_switch) start_timer(10);
					goto_stage(28);
					return;
				}
			} else {
				if (player == 1) {
					handManager.get_kind(1, kind, dialog_param);
					g_shake_kind[count_array(g_shake_kind, 9)] = kind;
					userManager.shake(1);
					if (hand_pae_count == 4)
						goto_stage(36);
					else
						goto_stage(33);
					return;
				}
				handManager.get_kind(2, kind, dialog_param);
				g_shake_kind[count_array(g_shake_kind, 9)] = kind;
				userManager.shake(2);
				if (hand_pae_count == 4)
					goto_stage(36);
				else
					goto_stage(33);
				return;
			}
		}
		goto_stage(16);
	}

	if (stage == 33) {
		if (inform_frame > 90) {
			inform_frame = 0;
			memset(dialog_param, 0, sizeof(dialog_param));
			goto_stage(14);
		} else {
			if (inform_frame == 0)
				soundUtil.play(58, 127);
			inform_frame++;
		}
	}

	if (stage == 36) {
		if (inform_frame > 90) {
			inform_frame = 0;
			memset(dialog_param, 0, sizeof(dialog_param));
			goto_stage(14);
		} else {
			if (inform_frame == 0)
				soundUtil.play(58, 127);
			inform_frame++;
		}
	}

	if (stage == 16) {
		print_nothing("[STAGE_READY_PUT]\n");
		clear_stage();
		flag_sort_done = 0;
		int pae = handManager.get_pae_at(player, g_player_pae_pos);
		print_nothing("[%03d]\xc6\xd0\xb4\xf8\xc1\xfc : player-%d, pos-%d, pae-%d\n", g_game_count, player, g_player_pae_pos, pae);
		print_nothing("[%03d]player hand - ", g_game_count);
		int i;
		for (i = 0; i < handManager.count(player); i++)
			print_nothing("[%d]", handManager.get_pae_at(player, i));
		print_nothing(" [");
		for (i = 0; i < 9; i++)
			print_nothing("%d,", g_shake_kind[i]);
		print_nothing("]\n");
		if (my_turn) {
			int limit = handManager.count(player);
			if (inputManager.g_cursor_pos >= limit)
				inputManager.g_cursor_pos = limit - 1;
		}
		if (pae == 51) {
			handManager.remove_pae_at(player, g_player_pae_pos);
			g_last_pae = pae;
			goto_stage(18);
			return;
		}
		if (pae == 49 || pae == 50) {
			handManager.remove_pae_at(player, g_player_pae_pos);
			collectManager.add(player, pae);
			int newpae = deckManager.get_pae();
			handManager.add(player, newpae);
			print_nothing("[%03d]\xc6\xd0 \xb0\xa1\xc1\xae\xbf\xc8 : player-%d, pae-%d\n", g_game_count, newpae);
			int sx = 0, sy = 0;
			deckManager.get_back_pos(&sx, &sy);
			if (my_turn) {
				int dx = (g_player_pae_pos % 5) * 26 + 348;
				int dy = (g_player_pae_pos / 5) * 40 + 190;
				animator.add_pae(newpae, sx, sy, dx, dy, 0, 53);
			} else if (player == 1) {
				int dx = (g_player_pae_pos % 5) * 6 + 133;
				int dy = (g_player_pae_pos / 5) * 26 + 3;
				animator.add_pae(52, sx, sy, dx, dy, 0, 53);
			} else {
				int dx = g_player_pae_pos * 6 + 298;
				int dy = 3;
				animator.add_pae(52, sx, sy, dx, dy, 0, 53);
			}
			wait_stage(23, 3000, animator.pan_to_hand);
			return;
		}
		goto_stage(17);
	}

	if (stage == 23) {
		int chongtong_kind = handManager.check_chongtong(player);
		if (chongtong_kind > 0 && find_array(chongtong_kind, g_chongtong_kind, 4) == -1) {
			print_nothing("[%03d]\xba\xb8\xb3\xca\xbd\xba\xc8\xc4 \xc3\xd1\xc5\xeb \xbc\xba\xb8\xb3:player-%d, kind-%d\n", g_game_count, player, chongtong_kind);
			g_flag_bonus_chongtong = 1;
			dialog_param[0] = chongtong_kind * 4 - 3;
			dialog_param[1] = chongtong_kind * 4 - 2;
			dialog_param[2] = chongtong_kind * 4 - 1;
			dialog_param[3] = chongtong_kind * 4;
			if (my_turn) {
				switch (g_confirm) {
				case 2:
					inputManager.set_key_enable(1, 0);
					inputManager.set_key_enable(7, 0);
					g_flag_bonus_chongtong = 0;
					g_confirm = 0;
					g_chongtong_kind[count_array(g_chongtong_kind, 4)] = chongtong_kind;
					return;
				case 1:
					inputManager.set_key_enable(1, 0);
					inputManager.set_key_enable(7, 0);
					g_flag_bonus_chongtong = 0;
					g_confirm = 0;
					g_chongtong_kind[count_array(g_chongtong_kind, 4)] = chongtong_kind;
					goto_stage(34);
					return;
				case 0:
					handManager.get_kind(0, chongtong_kind, dialog_param);
					if (!g_timer_switch) start_timer(10);
					goto_stage(27);
					return;
				}
				return;
			} else {
				g_flag_bonus_chongtong = 0;
				g_confirm = 0;
				goto_stage(34);
				return;
			}
		}
		userManager.update();
		inputManager.set_key_enable(1, 0);
		inputManager.set_key_enable(7, 0);
		wait_stage(14, 300, 0);
		return;
	}

	if (stage == 17) {
		print_nothing("[STAGE_PUT]\n");
		clear_stage();
		int bomb = 0;
		int pae, k, index, pos;
		int sx = 0, sy;
		pae = handManager.get_pae_at(player, g_player_pae_pos);
		if (pae == 0) {
			print_nothing("\xc0\xdf\xb8\xf8\xb5\xc8 \xc6\xd0:%d,%d,%d\n", pae, player, g_player_pae_pos);
			return;
		}
		k = paeManager.get_pae_kind(pae);
		int hand_pae_count = handManager.count_kind(player, k);
		g_pan_pae_count = panManager.get_kind(k, dialog_param);
		pos = panManager.get_kind_pos(k);
		print_nothing("\xc6\xf8\xc5\xba\xc8\xae\xc0\xce-player:%d, pos:%d, pae:%d, hand:%d, pan:%d\n", player, g_player_pae_pos, pae, hand_pae_count, g_pan_pae_count);
		if (hand_pae_count == 3 && pos != -1) {
			if (find_array(k, g_shake_kind, 9) == -1)
				bomb = 1;
			else
				bomb = find_array(k, g_chongtong_kind, 4) != -1;
		}
		print_nothing("\xc6\xf8\xc5\xba\xc8\xae\xc0\xce \xb0\xe1\xb0\xfa:%d\n", bomb);
		if (bomb) {
			int pos, p;
			print_nothing("[%03d]\xc6\xf8\xc5\xba!!-player:%d, pae:%d, kind:%d\n", g_game_count, player, pae, k);
			index = 0;
			while (handManager.get_first_kind(player, k, &pos, &p)) {
				if (my_turn) {
					if (index == 0)
						sx = (pos % 5) * 26 + 348;
					else
						sx += index * 10;
					sy = (pos / 5) * 40 + 190;
				} else if (player == 1) {
					if (index == 0)
						sx = (pos % 5) * 6 + 133;
					else
						sx += index * 10;
					sy = (pos / 5) * 26 + 3;
				} else {
					if (index == 0)
						sx = pos * 6 + 298;
					else
						sx += index * 10;
					sy = 3;
				}
				panManager.add(p, &pt, &sound);
				handManager.remove_pae_at(player, pos);
				animator.add_pae_bomb(p, sx, sy, pt.x, pt.y, index * 20, 9);
				index++;
			}
			handManager.add(player, 51);
			handManager.add(player, 51);
			handManager.sort(player);
		} else {
			if (my_turn) {
				sx = (g_player_pae_pos % 5) * 26 + 348;
				sy = (g_player_pae_pos / 5) * 40 + 190;
			} else if (player == 1) {
				sx = (g_player_pae_pos % 5) * 6 + 133;
				sy = (g_player_pae_pos / 5) * 26 + 3;
			} else {
				sx = g_player_pae_pos * 6 + 298;
				sy = 3;
			}
			panManager.add(pae, &pt, &sound);
			handManager.remove_pae_at(player, g_player_pae_pos);
			animator.add_pae(pae, sx, sy, pt.x, pt.y, 0, sound);
		}
		g_last_pae = pae;
		if (my_turn) {
			int limit = handManager.count(player) - 1;
			inputManager.g_cursor_pos = inputManager.g_cursor_pos > limit ? limit : inputManager.g_cursor_pos;
		}
		if (g_pan_pae_count == 2) {
			if (paeManager.is_pi(dialog_param[0]) == 1 && paeManager.is_pi(dialog_param[1]) == 1) {
				g_confirm = 2;
			} else if (my_turn) {
				if (!g_timer_switch) start_timer(10);
				wait_stage(31, 3000, animator.me_to_pan);
				return;
			} else {
				if (aiManager.get_pae_priority(dialog_param[0]) < aiManager.get_pae_priority(dialog_param[1]))
					g_confirm = 1;
				else
					g_confirm = 2;
			}
		}
		if (bomb) {
			wait_stage(18, 3000, animator.me_to_bomb);
			set_char_feel(player, 1, 2);
		} else {
			wait_stage(18, 3000, animator.me_to_pan);
		}
	}

	if (stage == 18) {
		print_nothing("[STAGE_TURNOVER]\n");
		clear_stage();
		g_turn_pae = deckManager.get_pae();
		print_nothing("[%03d]\xb5\xda\xc1\xfd\xc0\xbd-player:%d, pae:%d\n", g_game_count, player, g_turn_pae);
		if (g_turn_pae != 49 && g_turn_pae != 50)
			g_last_turn_pae = g_turn_pae;
		goto_stage(19);
	}

	if (stage == 19) {
		print_nothing("[STAGE_PUT_TURN_PAE]\n");
		clear_stage();
		int kind = paeManager.get_pae_kind(g_turn_pae);
		int kind_count = panManager.get_kind(kind, dialog_param2);
		int sx = 0, sy = 0;
		deckManager.get_back_pos(&sx, &sy);
		int flagBbuck = 0;
		if (kind == 13) {
			if (g_last_pae == 51) {
				panManager.add(g_turn_pae, &pt, &sound);
				animator.add_pae(g_turn_pae, sx, sy, pt.x, pt.y, 0, sound);
			} else {
				panManager.add_kind(g_turn_pae, paeManager.get_pae_kind(g_last_pae), &pt, &sound);
				animator.add_pae(g_turn_pae, sx, sy, pt.x, pt.y, 0, 16);
			}
			wait_stage(18, 3000, animator.me_to_pan);
			return;
		}
		if (kind_count == 2 && paeManager.get_pae_kind(g_last_pae) == kind) {
			print_nothing("[%03d]\xbb\xb6-player:%d, kind:%d\n", g_game_count, player, kind);
			flagBbuck = handManager.count(player) > 0;
		}
		if (kind_count == 2 && paeManager.get_pae_kind(g_last_pae) != kind) {
			if (paeManager.is_pi(dialog_param2[0]) == 1 && paeManager.is_pi(dialog_param2[1]) == 1) {
				g_confirm2 = 2;
			} else {
				panManager.add(g_turn_pae, &pt, &sound);
				animator.add_pae(g_turn_pae, sx, sy, pt.x, pt.y, 0, sound);
				g_turn_pae = 0;
				if (!my_turn) {
					if (aiManager.get_pae_priority(dialog_param2[0]) < aiManager.get_pae_priority(dialog_param2[1]))
						g_confirm2 = 1;
					else
						g_confirm2 = 2;
					wait_stage(20, 3000, animator.me_to_pan);
					return;
				} else {
					if (!g_timer_switch) start_timer(10);
					wait_stage(32, 3000, animator.me_to_pan);
					return;
				}
			}
		}
		panManager.add(g_turn_pae, &pt, &sound);
		if (flagBbuck) {
			set_char_feel(player, 2, 0);
			sound = 7;
		}
		animator.add_pae(g_turn_pae, sx, sy, pt.x, pt.y, 0, sound);
		g_turn_pae = 0;
		wait_stage(20, 3000, animator.me_to_pan);
	}

	if (stage == 20) {
		print_nothing("[STAGE_JUDGE]\n");
		clear_stage();
		judge_game(player);
		print_nothing("[END_OF_JUDGE]\n");
	}

	if (stage == 21) {
		wait_stage(22, 3000, animator.pan_to_collect);
	}

	if (stage == 22) {
		g_event = userManager.get_event(player);
		if (g_event & 0x40)
			animator.add_ani(18, 140, 53, 0, 30, 50);
		if (g_event & 0x20)
			animator.add_ani(16, 140, 53, 0, 30, 45);
		if (g_event & 0x10)
			animator.add_ani(17, 140, 53, 0, 30, 46);
		if (g_event & 0x08)
			animator.add_ani(19, 142, 45, 1, 100, 49);
		if (g_event & 0x04)
			animator.add_ani(20, 105, 6, 0, 30, 48);
		if (g_event & 0x02) {
			if (g_turn == 1)
				animator.add_ani(21, 89, 24, 0, 30, 56);
			else if (g_turn == 2)
				animator.add_ani(21, 389, 24, 0, 30, 56);
			else
				animator.add_ani(21, 89, 112, 0, 30, 56);
		}
		if (animator.count_ani() > 0)
			wait_stage(41, 3000, animator.start_ani);
		else
			goto_stage(41);
	}

	if (stage == 41) {
		clear_stage();
		int delay = 1000;
		if (g_event == 0)
			delay = 0;
		if (g_steal > 0) {
			int sound = -1;
			int n_ani = 0;
			if (g_steal == 1) {
				sound = 57;
				n_ani = 12;
			} else if (g_steal == 2) {
				sound = 61;
				n_ani = 12;
			} else if (g_steal >= 3) {
				sound = 55;
				n_ani = 12;
			}
			animator.add_ani(n_ani, 147, 50, 0, 10, sound);
			wait_stage(43, delay, animator.start_ani);
		} else
			wait_stage(43, delay, 0);
	}

	if (stage == 43) {
		clear_stage();
		int delay;
		if (my_turn) {
			collectManager.take_from(1, 0, g_steal);
			delay = 300;
		} else {
			collectManager.take_from(0, 1, g_steal);
			delay = 0;
		}
		userManager.update();
		if (g_steal > 0 && handManager.count(player) > 0)
			delay = 3000;
		wait_stage(45, delay, animator.collect_to_collect);
	}

	if (stage == 45) {
		clear_stage();
		wait_stage(61, 300, 0);
	}

	if (stage == 61) {
		print_nothing("[STAGE_JUDGE_END]\n");
		clear_stage();
		int Network;
		UserScore score;
		UserStat stat;
		userManager.get_score(player, &score);
		if (!g_gukjin_checked && collectManager.find_gukjin(player)) {
			int cflag = 0, m_cnt = 0, pi_cnt = 0;
			collectManager.count(player, 0, &m_cnt, 0, &pi_cnt);
			if (my_turn) {
				if (score.total == 5) {
					if (pi_cnt >= 9 && m_cnt < 5)
						cflag = 1;
				} else if (score.total == 6) {
					if ((pi_cnt >= 8 && m_cnt < 5) || (pi_cnt >= 9 && m_cnt >= 5))
						cflag = 1;
				} else if (score.total >= 7) {
					if (pi_cnt >= 8)
						cflag = 1;
				}
				print_nothing("gukjin - player:%d, cflag:%d, score:%d, m_cnt:%d, p_cnt:%d\n", player, cflag, score.total, m_cnt, pi_cnt);
				if (cflag) {
					switch (g_confirm) {
					case 2:
						print_nothing("[%03d]\xb1\xb9\xc1\xf8\xc0\xcc\xb5\xbf-player:%d\n", g_game_count, player);
						g_gukjin_checked = 1;
						g_confirm = 0;
						collectManager.move_gukjin(player);
						userManager.update();
						userManager.get_score(player, &score);
						memset(dialog_param, 0, sizeof(dialog_param));
						break;
					case 1:
						g_gukjin_checked = 1;
						g_confirm = 0;
						memset(dialog_param, 0, sizeof(dialog_param));
						break;
					case 0:
						print_nothing("[%03d]\xb1\xb9\xc1\xf8\xc0\xcc\xb5\xbf\xb4\xeb\xb1\xe2-player:%d\n", g_game_count, player);
						memset(dialog_param, 0, sizeof(dialog_param));
						dialog_param[0] = 33;
						if (!g_timer_switch) start_timer(10);
						goto_stage(29);
						return;
					}
				}
			} else {
				cflag = 0;
				if (score.total == 5) {
					if (pi_cnt >= 9 && m_cnt < 5)
						cflag = 1;
				} else if (score.total == 6) {
					if ((pi_cnt >= 8 && m_cnt < 5) || (pi_cnt >= 9 && m_cnt >= 5))
						cflag = 1;
				} else if (score.total >= 7) {
					if (pi_cnt >= 8)
						cflag = 1;
				}
				print_nothing("gukjin - player:%d, cflag:%d, score:%d, m_cnt:%d, p_cnt:%d\n", player, cflag, score.total, m_cnt, pi_cnt);
				if (cflag) {
					g_confirm = 0;
					g_gukjin_checked = 1;
					collectManager.move_gukjin(player);
					userManager.update();
					userManager.get_score(player, &score);
					memset(dialog_param, 0, sizeof(dialog_param));
				}
			}
		}
		if (score.total >= 7) {
			print_nothing("win. jum = %d, back remain : %d\n", score.total, deckManager.count());
			if (score.last_go < score.total) {
				if (handManager.count(player) == 0) {
					print_nothing("auto stop\n");
					goto_stage(72);
					return;
				}
				set_char_feel(player, 1, 2);
				if (my_turn) {
					print_nothing("bigger than last go. confirm is %d\n", g_confirm);
					switch (g_confirm) {
					case 2:
						g_confirm = 0;
						userManager.go(player);
						userManager.get_stat(player, &stat);
						print_nothing("[%03d]\xb0\xed!!-player%d, jum:%d, go:%d\n", g_game_count, player, score.total, stat.go);
						animator.add_ani(stat.go, 124, 59, 0, 30, stat.go + 32);
						g_turn = !g_turn;
						inputManager.set_key_enable(1, 0);
						inputManager.set_key_enable(7, 0);
						wait_stage(14, 1000, animator.start_ani);
						if (stat.go == 1) {
							modAtracStop();
							if ((mod_game.game_type == 1 && l_mod_player.hidden_game_rest > 0) || g_opp_party[0] == 5)
								strcpy(g_bgm_file, "snd/bgm_goh.at3");
							else
								sprintf(g_bgm_file, "snd/bgm_go%d.at3", g_opp_party[0] + 1);
							modAtracPlay(g_bgm_file);
						}
						return;
					case 1:
						g_confirm = 0;
						print_nothing("[%03d]\xbd\xba\xc5\xe9!!-player%d, jum:%d, go:%d\n", g_game_count, player, score.total, stat.go);
						soundUtil.play(59, 127);
						goto_stage(72);
						return;
					case 0:
						print_nothing("[%03d]\xb0\xed,\xbd\xba\xc5\xe9 \xb0\xed\xb9\xce\xc1\xdf-player%d, jum:%d\n", g_game_count, player, score.total);
						if (!g_timer_switch) start_timer(10);
						userManager.update();
						userManager.set_result_score(player, 1);
						goto_stage(71);
						return;
					}
				} else {
					print_nothing("opp bigger than last go. confirm is %d\n", g_confirm);
					userManager.get_score(0, &score);
					if (score.total >= 4) {
						soundUtil.play(59, 127);
						goto_stage(72);
						return;
					}
					userManager.go(1);
					userManager.get_stat(1, &stat);
					animator.add_ani(stat.go, 124, 59, 0, 30, stat.go + 32);
					if (stat.go == 1) {
						modAtracStop();
						if ((mod_game.game_type == 1 && l_mod_player.hidden_game_rest > 0) || g_opp_party[0] == 5)
							strcpy(g_bgm_file, "snd/bgm_goh.at3");
						else
							sprintf(g_bgm_file, "snd/bgm_go%d.at3", g_opp_party[0] + 1);
						modAtracPlay(g_bgm_file);
					}
				}
			}
		}
		if (handManager.count(0) == 0 && handManager.count(1) == 0 && handManager.count(2) == 0) {
			goto_stage(91);
			return;
		}
		g_turn = !g_turn;
		wait_stage(51, 1000, animator.start_ani);
		print_nothing("[ENDOF_JUDGE_END next:%d,%d]\n", g_stage_status, g_next_stage);
	}

	if (stage == 91) {
		print_nothing("[STAGE_NAGARI]\n");
		clear_stage();
		soundUtil.play(27, 127);
		print_nothing("[%03d]\xb3\xaa\xb0\xa1\xb8\xae..\n", g_game_count);
		print_nothing("*** NAGARI\n");
		g_win_player = -1;
		g_turn = !g_turn;
		tmp_mod_player = l_mod_player;
		memcpy(tmp_level_mission, g_level_mission, sizeof(g_level_mission));
		wait_stage(92, 300, 0);
	}

	if (stage == 72) {
		print_nothing("[STAGE_STOP]\n");
		int pi_cnt;
		clear_stage();
		g_sun = g_turn;
		if (my_turn) {
			collectManager.count(1, 0, 0, 0, &pi_cnt);
			if (!g_gukjin_checked && pi_cnt > 0 && pi_cnt < 8)
				collectManager.move_gukjin(1);
			soundUtil.play(15, 127);
			g_win_player = 0;
		} else if (player == 1) {
			collectManager.count(0, 0, 0, 0, &pi_cnt);
			if (!g_gukjin_checked && pi_cnt > 0 && pi_cnt < 8)
				collectManager.move_gukjin(0);
			soundUtil.play(22, 127);
			g_win_player = 1;
		} else {
			collectManager.count(0, 0, 0, 0, &pi_cnt);
			if (!g_gukjin_checked && pi_cnt > 0 && pi_cnt < 8)
				collectManager.move_gukjin(0);
			collectManager.count(1, 0, 0, 0, &pi_cnt);
			if (!g_gukjin_checked && pi_cnt > 0 && pi_cnt < 8)
				collectManager.move_gukjin(1);
			soundUtil.play(22, 127);
			g_win_player = 2;
		}
		tmp_mod_player = l_mod_player;
		memcpy(tmp_level_mission, g_level_mission, sizeof(g_level_mission));
		wait_stage(92, 300, 0);
	}

	if (stage == 81) {
		print_nothing("[STAGE_3BBUCK]\n");
		clear_stage();
		g_sun = g_turn;
		if (my_turn) {
			soundUtil.play(15, 127);
			g_win_player = 0;
		} else {
			soundUtil.play(22, 127);
			g_win_player = player;
		}
		tmp_mod_player = l_mod_player;
		memcpy(tmp_level_mission, g_level_mission, sizeof(g_level_mission));
		wait_stage(92, 300, 0);
	}

	if (stage == 34) {
		if (inform_frame > 90) {
			inform_frame = 0;
			memset(dialog_param, 0, sizeof(dialog_param));
			goto_stage(83);
		} else {
			if (inform_frame == 0)
				soundUtil.play(47, 127);
			inform_frame++;
		}
	}

	if (stage == 83) {
		clear_stage();
		g_sun = g_turn;
		userManager.set_sp_success(player, 8);
		if (my_turn) {
			soundUtil.play(15, 127);
			g_win_player = 0;
		} else {
			soundUtil.play(22, 127);
			g_win_player = player;
		}
		tmp_mod_player = l_mod_player;
		memcpy(tmp_level_mission, g_level_mission, sizeof(g_level_mission));
		wait_stage(92, 300, 0);
	}

	if (stage == 92) {
		print_nothing("[STAGE_END]\n");
		clear_stage();
		userManager.update();
		userManager.set_result_score(g_win_player, 0);
		if (g_win_player == 0) {
			l_mod_player.win++;
			if (l_mod_player.win > 49999)
				l_mod_player.win = 0;
			if (l_mod_player.opp_money <= g_result_score.money_sum) {
				l_mod_player.my_money += l_mod_player.opp_money;
				l_mod_player.opp_money = 0;
				all_in_player = 2;
				levelResult = 1;
			} else {
				l_mod_player.my_money += g_result_score.money_sum;
				l_mod_player.opp_money -= g_result_score.money_sum;
				levelResult = 0;
			}
			if (mod_game.game_type == 1) {
				levelManager.update_level_mission();
				if (levelManager.is_level_cleared()) {
					if (l_mod_player.hidden_game_rest > 0) {
						l_mod_player.hidden_character = 0;
						l_mod_player.hidden_game_rest = 0;
					}
					levelResult = 1;
				}
			}
		} else if (g_win_player != -1) {
			l_mod_player.lose++;
			if (l_mod_player.lose > 49999)
				l_mod_player.lose = 0;
			if (l_mod_player.my_money <= g_result_score.money_sum) {
				l_mod_player.my_money = 0;
				l_mod_player.opp_money += l_mod_player.my_money;
				all_in_player = 1;
				if (mod_game.game_type == 1 && l_mod_player.hidden_game_rest > 0) {
					l_mod_player.hidden_character = 0;
					l_mod_player.hidden_game_rest = 0;
				}
				levelResult = 2;
			} else {
				l_mod_player.opp_money += g_result_score.money_sum;
				l_mod_player.my_money -= g_result_score.money_sum;
			}
		} else {
			g_result_score.money_sum = 0;
		}
		modAtracStop();
		if (mod_game.game_type == 1) {
			if (levelResult == 1) {
				levelManager.update_data();
				memcpy(tmp_mod_player.success_level_mission, l_mod_player.success_level_mission, sizeof(l_mod_player.success_level_mission));
				levelManager.next_level();
			} else if (levelResult == 2) {
				levelManager.level_initialize();
			}
			levelManager.update_data();
			goto_stage(93);
		} else
			goto_stage(95);
	}

	if (stage == 93) {
		g_check_saved = 0;
		g_save_error = 0;
		show_dialog_result = 1;
		inputManager.set_key_enable(-1, 0);
		modSaveData();
		goto_stage(94);
	}

	if (stage == 96) {
		clear_stage();
		g_show_wait = 0;
		if (g_timer_switch) stop_timer();
		if (levelResult == 1) {
			if (mod_game.game_type == 1) {
				mod_game.result = 1;
				mod_system.return_value = 29;
			} else if (mod_game.game_type == 3 || mod_game.game_type == 4) {
				mod_system.return_value = 22;
			} else {
				mod_system.return_value = 7;
			}
			g_continue = 0;
		} else if (levelResult == 2) {
			if (mod_game.game_type == 1) {
				mod_system.return_value = 29;
				mod_game.result = 0;
			} else if (mod_game.game_type == 3 || mod_game.game_type == 4) {
				mod_system.return_value = 22;
			} else {
				mod_system.return_value = 7;
			}
			g_continue = 0;
		} else {
			if ((mod_game.game_type == 3 || mod_game.game_type == 4) && mod_game.play_time > 0 && mod_game.play_time < g_game_count) {
				mod_system.return_value = 22;
				g_continue = 0;
			}
		}
		if (levelResult == 0) {
			if (g_win_player == -1) {
				g_nagari_count++;
				if (g_nagari_count > 3)
					g_nagari_count = 3;
			}
			goto_stage(4);
		}
	}
}
__asm__(".globl process_stage_E1E0");
#undef process_stage
#undef inform_frame
#undef levelResult
#undef mod_system
#undef mod_game
#undef g_bgm_file
#else
INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/game", process_stage_E1E0);
#endif

static void clear_stage()
{
	goto_stage(13);
}

static void goto_stage(int stage)
{
	D_00055818 = g_stage_status;
	g_stage_status = stage;
	if (stage != D_00055818)
		stage_start_tick = get_tick();
	if (stage == 14)
		g_show_cursor = 0;
}

__asm__(".globl goto_stage");

static void wait_stage(int stage, int delay, void (*func)())
{
	goto_stage(11);
	g_next_stage = stage;
	g_delay = delay;
	if (sceKernelGetGPI() & 4)
		g_delay = 0;
	g_wait_func = func;
	if (sceKernelGetGPI() & 8) {
		animator.clear();
		goto_stage(stage);
	}
}

__asm__(".globl wait_stage");

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FC3C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FC4C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FC58);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FC6C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FC8C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FCB0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FCBC);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FCE0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FD04);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FD18);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FD28);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FD50);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FD78);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FDA0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FDDC);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FDF8);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FE18);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FE28);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FE40);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FE54);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FE74);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FE84);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FE98);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FED0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FEE4);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FF10);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FF40);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FF54);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FF80);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FF98);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FFA0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FFA4);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FFA8);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FFAC);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FFD4);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FFEC);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_0002FFFC);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_00030034);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_00030060);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_00030090);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_000300AC);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_000300C0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_000300D8);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_00030104);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_00030114);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_00030124);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/game", D_00030138);


