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
extern ModSystem mod_system __asm__("PRX_ZERO");
extern ModPlayer mod_player __asm__("PRX_ZERO");
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
/* "input changed confirm to 1\n", shared with pad_read (still asm) */
extern char D_0002F7A8[];
void print_nothing(const char *fmt, ...);
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
		print_nothing(D_0002F7A8);
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

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/input", D_0002F7A8);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/input", pad_read);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/input", D_0002F7F0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/input", D_0002F81C);
