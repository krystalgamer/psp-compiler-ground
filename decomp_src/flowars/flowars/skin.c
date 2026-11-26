#include "common.h"


/* declarations recovered from DWARF */
typedef struct SceGimPicture SceGimPicture;
struct SceGimPicture;
struct _anon1;
struct _anon1 { /* size 0x14 */
    int width;
    int height;
    int totalframes;
    float fps;
    float step;
};
typedef struct _anon1 skin_ani_param;
struct _anon2;
struct _anon2 { /* size 0x30 */
    short unsigned int header_size;
    short unsigned int reference;
    short unsigned int format;
    short unsigned int order;
    short unsigned int width;
    short unsigned int height;
    short unsigned int bpp;
    short unsigned int pitch_align;
    short unsigned int height_align;
    short unsigned int dim_count;
    short unsigned int reserved;
    short unsigned int reserved2;
    unsigned int offsets;
    unsigned int images;
    unsigned int total;
    unsigned int plane_mask;
    short unsigned int level_type;
    short unsigned int level_count;
    short unsigned int frame_type;
    short unsigned int frame_count;
};
typedef struct _anon2 SceGimImageHeader;
struct _anon3;
typedef long long int long64;
struct _anon3 { /* size 0xe8 */
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
typedef struct _anon3 L_Mod_Player;
typedef struct _GRAPHICS Graphics;
struct _GRAPHICS;
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
struct _anon4;
struct _anon4 { /* size 0x78 */
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
typedef struct _anon4 ModGame;
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
typedef long long unsigned int u_long64;

extern int g_stage_status;
extern int g_bet_money;
extern L_Mod_Player l_mod_player;
extern int g_nagari_count;
extern Graphics graphics;
extern ModGame mod_game __asm__("PRX_ZERO");
extern SkinManager skinManager;
extern SceGimPicture *g_img_char[2][5];
extern SceGimPicture *g_img_stage;
extern SceGimPicture *g_img_face[4];
extern SceGimPicture *g_img_num_jum;
extern SceGimPicture *g_img_num_mission;
extern SceGimPicture *g_img_x2_mission;
extern SceGimPicture *g_img_level_mission;
extern SceGimPicture *g_img_level_mission_num;
extern SceGimPicture *g_img_num_go;
extern SceGimPicture *g_img_title_mission;
extern SceGimPicture *g_img_title_bingo;
extern SceGimPicture *g_img_turn;
extern SceGimPicture *g_img_sun;
extern SceGimPicture *g_img_bet_money;
extern SceGimPicture *g_img_nagari_num;
extern SceGimPicture *g_img_status_on;
extern SceGimPicture *g_img_status_off;
extern SceGimPicture *g_img_status_num_on;
extern SceGimPicture *g_img_status_num_off;
extern SceGimPicture *g_img_mission_cover;
extern u_long64 g_char_draw_tick[2];
extern u_long64 g_face_draw_tick;
extern int g_char_feel[2];
extern skin_ani_param g_char_param[2][5];
extern skin_ani_param g_face_param[4];
extern int draw_char_now[2];

SceGimPicture *load_picture2(int index, int *buff, int size);
static int load_character(int index, int party, int person);
static int sceGimImageGetWidth(const SceGimImageHeader *image, int level);
static int sceGimImageGetHeight(const SceGimImageHeader *image, int level);
static int sceGimImageGetFrameCount(const SceGimImageHeader *image);
static int load_skin(int party, int person);
static void term(void);
static void set_char_feel(int char_num, int feel);
static int draw_character(int char_num, int x, int y, int animate_term);
static int draw_face(int animate_term);
static int draw_stage();
static void draw_sun(int flagPlayer);
static void draw_level_mission(int index, int mission, int suc, int total);
static int draw_num_jum(int jum, int x, int y);
static int draw_title_mission(int x, int y);
static int draw_title_bingo(int x, int y);
static int draw_num_mission(int baesu, int x, int y);
static void draw_status(int x, int y, int bbuck, int p_bak, int shake, int g_bak);
static void draw_turn(int flagPlayer);

/* SDK functions (tools/sdk_protos.h) */
void sceGimPictureActivate(SceGimPicture *picture);
void sceGimPictureSetFrame(SceGimPicture *picture, float frame);
float sceGimPictureGetFrame(SceGimPicture *picture);
u_long64 get_tick();
int evaluated_rand(int range, ...);
SceGimPicture *sceGimPictureCreate(void *option);
int sceGimPictureLoadFile(SceGimPicture *picture, void *data, int size, int flag);
void print_nothing(const char *fmt, ...);
extern int D_0005AEAC;	/* static int animating (draw_face) */
extern int D_0005AEB0;	/* static int index (draw_face) */
void sceGimPictureAnimate(SceGimPicture *picture, float time);
void sceGimPictureDelete(SceGimPicture *picture);
void sceGuColor(unsigned int color);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);


INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/skin", load_picture2);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/skin", D_00030964);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/skin", load_character);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/skin", D_000309A0);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/skin", load_skin);

static void term()
{
	int i;
	int j;

	for (i = 0; i < 2; i++)
		for (j = 0; j < 5; j++)
			sceGimPictureDelete(g_img_char[i][j]);
	for (i = 0; i < 4; i++)
		sceGimPictureDelete(g_img_face[i]);
	sceGimPictureDelete(g_img_stage);
	sceGimPictureDelete(g_img_num_jum);
	sceGimPictureDelete(g_img_num_go);
	sceGimPictureDelete(g_img_num_mission);
	sceGimPictureDelete(g_img_x2_mission);
	sceGimPictureDelete(g_img_title_mission);
	sceGimPictureDelete(g_img_title_bingo);
	sceGimPictureDelete(g_img_level_mission);
	sceGimPictureDelete(g_img_level_mission_num);
}

__asm__(".globl term");

void change_skin(int party, int person) {
    skinManager.term();
    skinManager.load_skin(party, person);
    skinManager.load_character(0, l_mod_player.player_party, l_mod_player.player_character);
    skinManager.load_character(1, party, person);
}

void set_char_feel_156F8(unsigned int arg0, int arg1) {
    if (arg0 < 2U) {
        g_char_feel[arg0] = arg1;
        if (arg1 != 0) {
            draw_char_now[arg0] = 1;
        }
    }
}

static int draw_character(int char_num, int x, int y, int animate_term)
{
	int feel;
	SceGimPicture *ani;
	skin_ani_param *p;

	feel = g_char_feel[char_num];
	ani = g_img_char[char_num][feel];
	p = &g_char_param[char_num][feel];
	if (ani == NULL)
		return 0;
	if (g_char_draw_tick[char_num] == 0) {
		g_char_draw_tick[char_num] = get_tick();
		sceGimPictureSetFrame(ani, 0);
	}
	if ((int)(get_tick() - g_char_draw_tick[char_num]) / 1000000 >= animate_term || draw_char_now[char_num]) {
		if (sceGimPictureGetFrame(ani) < p->totalframes)
			sceGimPictureAnimate(ani, p->step);
		else {
			sceGimPictureSetFrame(ani, 0);
			g_char_draw_tick[char_num] = get_tick();
			draw_char_now[char_num] = 0;
		}
	}
	sceGimPictureActivate(ani);
	sceGuColor(0xFFFFFFFF);
	graphics.draw_sprite(x, y, p->width, p->height, 0);
	return 1;
}

__asm__(".globl draw_character");

static int draw_face(int animate_term)
{
	skin_ani_param *p;

	p = &g_face_param[D_0005AEB0];
	if (g_img_face == NULL)
		return 0;
	if (g_face_draw_tick == 0) {
		D_0005AEB0 = 0;
		g_face_draw_tick = get_tick();
		sceGimPictureSetFrame(g_img_face[D_0005AEB0], 0);
	}
	if ((int)(get_tick() - g_face_draw_tick) / 1000000 >= animate_term) {
		if (D_0005AEAC) {
			p = &g_face_param[D_0005AEB0];
			if (sceGimPictureGetFrame(g_img_face[D_0005AEB0]) < p->totalframes)
				sceGimPictureAnimate(g_img_face[D_0005AEB0], p->step);
			else {
				D_0005AEAC = 0;
				sceGimPictureSetFrame(g_img_face[D_0005AEB0], 0);
				g_face_draw_tick = get_tick();
			}
		} else {
			D_0005AEAC = 1;
			D_0005AEB0 = evaluated_rand(4, 4, 3, 2, 1);
			p = &g_face_param[D_0005AEB0];
			sceGimPictureAnimate(g_img_face[D_0005AEB0], p->step);
		}
	}
	sceGimPictureActivate(g_img_face[D_0005AEB0]);
	sceGuColor(0xFFFFFFFF);
	graphics.draw_sprite(480 - p->width, 0, p->width, p->height, 0);
	if (!D_0005AEAC)
		D_0005AEB0 = 0;
	return 1;
}

__asm__(".globl draw_face");

static int draw_stage()
{
	int index;

	sceGimPictureActivate(g_img_stage);
	sceGuColor(0xFFFFFFFF);
	graphics.draw_sprite(0, 0, 480, 272, 0);
	sceGimPictureActivate(g_img_bet_money);
	sceGuSpriteMode(42, 14, 42, 14);
	switch (g_bet_money) {
	case 10:
		index = 0;
		break;
	case 100:
		index = 1;
		break;
	case 500:
		index = 2;
		break;
	case 1000:
		index = 3;
		break;
	case 2000:
		index = 4;
		break;
	case 5000:
		index = 5;
		break;
	case 10000:
		index = 6;
		break;
	case 50000:
		index = 7;
		break;
	case 100000:
		index = 8;
		break;
	default:
		return 0;
	}
	sceGuDrawSprite(299, 190, 0, 0, index * 14, 0, 0);
	if (g_nagari_count >= 1 && g_nagari_count <= 3) {
		sceGimPictureActivate(g_img_nagari_num);
		graphics.draw_sprite2(118, 180, 81, 25, 0, (g_nagari_count - 1) * 25, 0);
	}
	if (mod_game.game_type == 2 || mod_game.game_type == 3) {
		sceGimPictureActivate(g_img_mission_cover);
		graphics.draw_sprite(347, 133, 129, 51, 0);
	}
	return 0;
}

__asm__(".globl draw_stage");

static void draw_sun(int flagPlayer)
{
	int x;
	int y;

	if (flagPlayer == 0) {
		x = 1;
		y = 207;
	} else if (flagPlayer == 1) {
		x = 1;
		y = 1;
	} else {
		x = 423;
		y = 1;
	}
	sceGimPictureActivate(g_img_sun);
	sceGuColor(0xFFFFFFFF);
	sceGuSpriteMode(15, 15, 15, 15);
	sceGuDrawSprite(x, y, 0, 0, 0, 0, 0);
}

__asm__(".globl draw_sun");

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/skin", draw_level_mission);

int draw_num_go(int go, int x, int y) {
    int var_v0;

    var_v0 = 0;
    if (g_img_num_go != NULL) {
        sceGimPictureActivate(g_img_num_go);
        sceGuSpriteMode(0x23, 0x12, 0x23, 0x12);
        sceGuDrawSprite(x, y, 0, 0, go * 0x12, 0, 0);
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/skin", draw_num_jum);

int draw_x2_mission(int x, int y) {
    int var_v0;

    var_v0 = 0;
    if (g_img_x2_mission != NULL) {
        sceGimPictureActivate(g_img_x2_mission);
        sceGuSpriteMode(0xF, 0xC, 0xF, 0xC);
        sceGuColor(-1U);
        sceGuDrawSprite(x, y, 0, 0, 0, 0, 0);
        var_v0 = 1;
    }
    return var_v0;
}

static int draw_title_mission(int x, int y)
{
	if (g_img_title_mission == NULL)
		return 0;
	sceGimPictureActivate(g_img_title_mission);
	sceGuColor(0xFFFFFFFF);
	graphics.draw_sprite(x, y, 102, 18, 0);
	return 1;
}

__asm__(".globl draw_title_mission");

static int draw_title_bingo(int x, int y)
{
	if (g_img_title_bingo == NULL)
		return 0;
	sceGimPictureActivate(g_img_title_bingo);
	sceGuColor(0xFFFFFFFF);
	graphics.draw_sprite(x, y, 48, 27, 0);
	return 1;
}

__asm__(".globl draw_title_bingo");

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/skin", draw_num_mission);

int draw_num_bingo(int linecnt, int x, int y) {
    int var_v0;

    var_v0 = 0;
    if ((g_img_num_mission != NULL) & ((unsigned int) linecnt < 0xAU)) {
        sceGimPictureActivate(g_img_num_mission);
        sceGuColor(-1U);
        sceGuSpriteMode(0x10, 0x17, 0x10, 0x17);
        sceGuDrawSprite(x, y, 0, linecnt * 0x10, 0, 0, 0);
        sceGuSpriteMode(0x10, 0x17, 0x10, 0x17);
        sceGuDrawSprite(x + 0xE, y, 0, 0xC0, 0, 0, 0);
        sceGuSpriteMode(0x10, 0x17, 0x10, 0x17);
        sceGuDrawSprite(x + 0x1E, y, 0, 0x20, 0, 0, 0);
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/skin", draw_status);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/skin", D_000309D8);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/skin", D_000309DC);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/skin", D_000309E0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/skin", D_000309E4);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/skin", D_000309E8);

static void draw_turn(int flagPlayer)
{
	int x;
	int y;

	if (flagPlayer == 0) {
		x = 1;
		y = 207;
	} else if (flagPlayer == 1) {
		x = 1;
		y = 1;
	} else {
		x = 423;
		y = 1;
	}
	sceGimPictureActivate(g_img_turn);
	sceGimPictureAnimate(g_img_turn, 1.0f / 60.0f);
	graphics.draw_sprite(x, y, 56, 63, 0);
}

__asm__(".globl draw_turn");
