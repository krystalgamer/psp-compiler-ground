#include "common.h"


/* declarations recovered from DWARF */
typedef unsigned int u_int32;
typedef struct SceCtrlData SceCtrlData;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
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
struct _anon1;
struct _anon1 { /* size 0x10 */
    void (*init)(void);
    void (*process_stage)(void);
    void (*goto_stage)(int);
    void (*wait_stage)(int, int, void (*)());
};
typedef struct _anon1 GameManager;
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
struct _anon2;
struct _anon2 { /* size 0xe8 */
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
typedef struct _anon2 L_Mod_Player;
struct _anon3;
typedef int SceUID;
struct _anon3 { /* size 0x90 */
    SceUID caller_id;
    int return_value;
    int prev_menu;
    char movie_file[128];
    int network_type;
};
typedef struct _anon3 ModSystem;
struct _anon4;
struct _anon4 { /* size 0x8f0 */
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
typedef struct _anon4 ModPlayer;
struct _anon5;
struct _anon5 { /* size 0x78 */
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
typedef struct _anon5 ModGame;

extern int g_stage_status;
extern int g_confirm;
extern int g_confirm2;
extern int g_continue;
extern int g_timer_pause;
extern int g_show_collect_paes;
extern InputManager inputManager;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern int g_my_hand[10];
extern GameManager gameManager;
extern int g_player_index;
extern int g_turn;
extern int g_player_pae_pos;
extern int g_game_paused;
extern Graphics graphics;
extern int g_draw_vs_switch;
extern L_Mod_Player l_mod_player;
extern ModSystem mod_system __asm__("mod_system_zero");
__asm__("mod_system_zero = 0");
extern ModPlayer mod_player __asm__("_init");
extern ModGame mod_game __asm__("PRX_ZERO");
extern int key_pressed;
extern unsigned int counter;
extern unsigned int delay;
extern u_int32 g_press_button;
extern int key_enable[8];
extern char warning_msg[100];

static void set_key_enable(int key, int flag);
int sceCtrlSetSamplingMode(unsigned int uiMode);
void stop_timer(void);
int count_array(int *a, int a_size);
int sceKernelGetGPI(void);
int sceCtrlReadBufferPositive(SceCtrlData *pad_data, int count);
void init_all(void);
void printGlobal(char *msg);
char *strcpy(char *dst, const char *src);
static void init();
static void init_63EC();
static void press_circle();
static int pad_read();


static void set_key_enable(int key, int flag)
{
	int i;

	if (key == -1) {
		for (i = 1; i < 8; i++)
			key_enable[i] = flag;
	} else
		key_enable[key] = flag;
}

__asm__(".globl set_key_enable");

int get_key_enable(int key) {
    return key_enable[key];
}

static void init_63EC()
{
	sceCtrlSetSamplingMode(1);
	inputManager.g_cursor_pos = 0;
	memset(key_enable, 0, sizeof(key_enable));
}

__asm__(".globl init_63EC");

static void press_circle()
{
	if (g_stage_status == 14 && g_player_index == g_turn) {
		g_player_pae_pos = inputManager.g_cursor_pos;
		gameManager.goto_stage(15);
		stop_timer();
	}
	if (g_stage_status == 28) {
		stop_timer();
		g_confirm = 2;
		gameManager.goto_stage(15);
		set_key_enable(3, 0);
	} else if (g_stage_status == 27) {
		stop_timer();
		g_confirm = 2;
		gameManager.goto_stage(14);
		set_key_enable(3, 0);
	} else if (g_stage_status == 29) {
		stop_timer();
		print_nothing("input changed confirm to 1\n");
		g_confirm = 2;
		gameManager.goto_stage(61);
		set_key_enable(3, 0);
	} else if (g_stage_status == 31) {
		stop_timer();
		print_nothing("input changed confirm to 2\n");
		g_confirm = 2;
		gameManager.goto_stage(18);
		set_key_enable(3, 0);
	} else if (g_stage_status == 32) {
		stop_timer();
		print_nothing("input changed confirm2 to 2\n");
		g_confirm2 = 2;
		gameManager.goto_stage(20);
		set_key_enable(3, 0);
	} else if (g_stage_status == 71) {
		stop_timer();
		g_confirm = 2;
		gameManager.goto_stage(61);
		set_key_enable(3, 0);
	} else if (g_stage_status == 94) {
		set_key_enable(4, 0);
		gameManager.goto_stage(93);
	} else if (g_stage_status == 95) {
		stop_timer();
		gameManager.goto_stage(96);
		set_key_enable(3, 0);
		set_key_enable(4, 0);
	} else if (g_stage_status == 97) {
		stop_timer();
		mod_system.return_value = 7;
		g_continue = 0;
	}
}

__asm__(".globl press_circle");


extern int D_000554AC;	/* static int prev_padd (pad_read) */
extern int D_000554B0;	/* static int cheat_money (pad_read) */
#define prev_padd D_000554AC
#define cheat_money D_000554B0

static int pad_read()
{
	counter++;







	int limit;
	u_int32 padd, analog_x;
	SceCtrlData buf;


	sceCtrlReadBufferPositive(&buf, 1);








	padd = buf.Buttons;
	if (g_press_button) {
		padd |= g_press_button;
		g_press_button = 0;
	}



	analog_x = buf.Lx;
	limit = count_array(g_my_hand, 10);

















	if (sceKernelGetGPI() & 0xC)
		press_circle();





	if (padd && key_pressed) {
		if (delay > 0) delay--;
		if (delay > 0) return 1;

		if (counter % 3 != 0) return 1;
	}


	if (padd) {
		key_pressed = 1;
	} else {
		key_pressed = 0;
		delay = 20;
	}


















	if (prev_padd == padd) return;
	prev_padd = padd;


	if ((padd & 0x8) && key_enable[5]) {

		g_game_paused = !g_game_paused;
		g_timer_pause = !g_timer_pause;

		set_key_enable(5, 0);
	}


	if (g_game_paused == 1) {
		if ((padd & 0x2000) && key_enable[1]) {
			g_game_paused = 0;
			g_timer_pause = 0;
			set_key_enable(1, 0);



		} else if ((padd & 0x4000) && key_enable[4]) {
			g_game_paused = 0;
			strcpy(warning_msg, "  \xb0\xd4\xc0\xd3\xc0\xbb \xc1\xbe\xb7\xe1\xc7\xd5\xb4\xcf\xb4\xd9.\n\n  \xb8\xde\xb4\xba\xb7\xce \xb5\xb9\xbe\xc6\xb0\xa9\xb4\xcf\xb4\xd9");
			mod_system.return_value = 6;
			g_continue = 0;
			set_key_enable(-1, 0);
		}

		return 1;
	}




	if (padd & 0x200) {
		if (mod_game.game_type == 1 && g_stage_status != 8 && g_show_collect_paes == -2) {
			if (g_draw_vs_switch == 1) {
				graphics.stop_vs_menu();
				g_draw_vs_switch = 0;
				g_timer_pause = 0;
			} else {

				g_draw_vs_switch = 1;
				g_timer_pause = 1;
			}
		}
	}




	if (g_draw_vs_switch == 1) return 1;

	if (padd & 0x100) {
		switch (g_show_collect_paes) {
		case -2:
			g_show_collect_paes = 0;
			break;









		case 0:
			g_show_collect_paes = 1;
			break;

		case 1:
			g_show_collect_paes = -1;
			break;

		case 2:
			g_show_collect_paes = 1;
			break;









		case -1:
		default:
			g_show_collect_paes = -2;
			break;
		}
	}


	if (g_show_collect_paes != -2) return 1;







	if (analog_x < 80) {
		if (cheat_money == 0) cheat_money = l_mod_player.opp_money / 200;
		l_mod_player.my_money -= cheat_money;
		l_mod_player.opp_money += cheat_money;
	}

	if (analog_x > 170) {
		if (cheat_money == 0) cheat_money = l_mod_player.opp_money / 200;
		l_mod_player.my_money += cheat_money;
		l_mod_player.opp_money -= cheat_money;
	}



	if ((padd & 0x80) && key_enable[7]) {
		if (g_stage_status != 14) return 1;
		inputManager.g_cursor_pos--;
		set_key_enable(7, 0);
	}


	if ((padd & 0x20) && key_enable[7]) {
		if (g_stage_status != 14) return 1;
		inputManager.g_cursor_pos++;
		set_key_enable(7, 0);
	}


	if ((padd & 0x10) && key_enable[7]) {
		if (inputManager.g_cursor_pos >= 5)
			inputManager.g_cursor_pos -= 5;

		set_key_enable(7, 0);
	}


	if ((padd & 0x40) && key_enable[7]) {

		if (inputManager.g_cursor_pos < 5 && limit >= 5)
			inputManager.g_cursor_pos += 5;

		set_key_enable(7, 0);
	}


	if (inputManager.g_cursor_pos <= 0)
		inputManager.g_cursor_pos = 0;

	if (inputManager.g_cursor_pos >= limit)
		inputManager.g_cursor_pos = limit - 1;















	if ((padd & 0x1000) && key_enable[2]) {
		stop_timer();




		init_all();
		gameManager.goto_stage(4);

		set_key_enable(2, 0);
	}



	if ((padd & 0x4000) && key_enable[4]) {

		set_key_enable(4, 0);

		if (g_stage_status == 94) {
			set_key_enable(1, 0);

			gameManager.goto_stage(95);
			return;



		} else if (g_stage_status == 95) {












			if (mod_game.game_type == 1 && mod_player.level[mod_player.active_player] >= 13) {
				stop_timer();
				gameManager.goto_stage(96);
				set_key_enable(3, 0);
				set_key_enable(4, 0);
				return;
			}

			mod_system.return_value = 6;
			g_continue = 0;
		}




		strcpy(warning_msg, "  \xb0\xd4\xc0\xd3\xc0\xbb \xc1\xbe\xb7\xe1\xc7\xd5\xb4\xcf\xb4\xd9.\n\n  \xb8\xde\xb4\xba\xb7\xce \xb5\xb9\xbe\xc6\xb0\xa9\xb4\xcf\xb4\xd9");
	}



	if ((padd & 0x8000) && key_enable[3]) {

		stop_timer();

		if (g_stage_status == 28) {












			g_confirm = 1;
			gameManager.goto_stage(15);








			set_key_enable(1, 0);
			set_key_enable(3, 0);
			return 1;
		} else if (g_stage_status == 27) {







			g_confirm = 1;
			gameManager.goto_stage(14);

			set_key_enable(1, 0);
			set_key_enable(3, 0);
			return 1;
		} else if (g_stage_status == 31) {
			print_nothing("input changed confirm to 1\n");






			g_confirm = 1;
			gameManager.goto_stage(18);

			set_key_enable(1, 0);
			set_key_enable(3, 0);
			return 1;
		} else if (g_stage_status == 29) {
			print_nothing("input changed confirm to 1\n");






			g_confirm = 1;
			gameManager.goto_stage(61);

			set_key_enable(1, 0);
			set_key_enable(3, 0);
			return 1;
		} else if (g_stage_status == 32) {
			print_nothing("input changed confirm2 to 1\n");






			g_confirm2 = 1;
			gameManager.goto_stage(20);

			set_key_enable(1, 0);
			set_key_enable(3, 0);
			return 1;
		} else if (g_stage_status == 71) {






			g_confirm = 1;

			gameManager.goto_stage(61);

			set_key_enable(1, 0);
			set_key_enable(3, 0);
			return 1;
		} else {
			printGlobal("from input");
			set_key_enable(3, 0);
		}
	}



	if ((padd & 0x2000) && key_enable[1]) {
		press_circle();
		set_key_enable(1, 0);
	}



	return 1;
}

__asm__(".globl pad_read");



