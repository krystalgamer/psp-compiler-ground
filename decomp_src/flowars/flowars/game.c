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









INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/game", process_stage_E1E0);

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


