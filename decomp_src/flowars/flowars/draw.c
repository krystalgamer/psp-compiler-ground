#include "common.h"


/* declarations recovered from DWARF */
typedef struct SceGimPicture SceGimPicture;
struct SceGimPicture;
struct _anon1;
struct _anon1 { /* size 0x10 */
    int width;
    int height;
    float fps;
    float step;
};
typedef struct _anon1 ani_param;
struct _anon2;
struct _anon2 { /* size 0x8 */
    int width;
    int height;
};
typedef struct _anon2 Dlg_param;
struct _anon3;
struct _anon3 { /* size 0x30 */
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
typedef struct _anon3 SceGimImageHeader;
struct _anon4;
struct _anon4 { /* size 0x6c */
    int jabbuck_kind[2];
    int bbuck;
    int shake;
    int go;
    unsigned char turn_event;
    int sp_success[10];
    int sp_bisang[10];
    int game_money;
};
typedef struct _anon4 UserStat;
typedef long long int long64;
struct _anon5;
struct _anon5 { /* size 0x28 */
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
typedef struct _anon5 PaeManager;
struct _anon6;
struct _anon6 { /* size 0x20 */
    int pos;
    int count;
    int pae[6];
};
typedef struct _anon6 PanPaes;
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
struct _anon7;
struct _anon7 { /* size 0x38 */
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
typedef struct _anon7 Animator;
struct _anon8;
struct _anon9;
struct _anon9 { /* size 0x18 */
    int total;
    int gwang;
    int mung;
    int dan;
    int pi;
    int last_go;
};
typedef struct _anon9 UserScore;
struct _anon8 { /* size 0x44 */
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
typedef struct _anon8 ResultScore;
struct _anon10;
struct _anon10 { /* size 0x48 */
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
typedef struct _anon10 UserManager;
struct _anon11;
struct _anon11 { /* size 0x78 */
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
typedef struct _anon11 ModGame;
struct _anon12;
struct _anon12 { /* size 0xe8 */
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
typedef struct _anon12 L_Mod_Player;
struct _anon13;
struct _anon13 { /* size 0x4c */
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
typedef struct _anon13 SkinManager;
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
struct _anon14;
struct _anon14 { /* size 0x8 */
    int width;
    int height;
};
typedef struct _anon14 Font_scale;

extern int g_stage_status;
extern int g_timer_pause;
extern PaeManager paeManager;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern PanPaes g_pan[13];
extern HandManager handManager;
extern int g_my_hand[10];
extern int g_opp_hand[2][10];
extern CollectManager collectManager;
extern int g_my_collection_gwang[5];
extern int g_my_collection_mung[9];
extern int g_my_collection_dan[10];
extern int g_my_collection_pi[25];
extern int g_opp_collection_gwang[5];
extern int g_opp_collection_mung[9];
extern int g_opp_collection_dan[10];
extern int g_opp_collection_pi[25];
extern int g_opp2_collection_gwang[5];
extern int g_opp2_collection_mung[9];
extern int g_opp2_collection_dan[10];
extern int g_opp2_collection_pi[25];
extern Animator animator;
extern ResultScore g_result_score;
extern UserManager userManager;
extern int g_win_player;
extern int g_player_index;
extern int g_turn;
extern ModGame mod_game __asm__("PRX_ZERO");
extern int g_opp_party[1];
extern int g_opp_char[1];
extern int g_level_mission[11];
extern L_Mod_Player l_mod_player;
extern SkinManager skinManager;
extern Graphics graphics;
extern int g_draw_vs_switch;
extern int g_deck[50];
extern int g_back_remain;
extern int g_img_loaded;
extern int g_img_loaded_done;
extern Font_scale font_scale[12];
extern int g_img_index;
extern int draw_collect_seq[10];
extern int sce_newlib_heap_kb_size;
extern char disp_list[131072];
extern SceGimPicture *g_font_han;
extern SceGimPicture *g_font_eng;
extern SceGimPicture *img_load_ani;
extern SceGimPicture *img_load_bg;
extern SceGimPicture *pic_pae_l1;
extern SceGimPicture *pic_pae_l2;
extern SceGimPicture *pic_pae_m;
extern SceGimPicture *pic_pae_s;
extern SceGimPicture *g_icons[4];
extern SceGimPicture *g_icon_ox;
extern SceGimPicture *g_cursor_hand;
extern SceGimPicture *g_timer;
extern SceGimPicture *g_animation[22];
extern SceGimPicture *g_font[12];
extern SceGimPicture *g_icon_result[2];
extern SceGimPicture *g_img_win_lose;
extern SceGimPicture *g_img_black_back;
extern SceGimPicture *g_img_warning;
extern SceGimPicture *g_img_warning2;
extern SceGimPicture *g_img_all_in;
extern SceGimPicture *g_img_button;
extern SceGimPicture *g_img_sun;
extern SceGimPicture *g_img_turn;
extern SceGimPicture *g_img_bet_money;
extern SceGimPicture *g_img_nagari_num;
extern SceGimPicture *g_img_status_on;
extern SceGimPicture *g_img_status_off;
extern SceGimPicture *g_img_status_num_on;
extern SceGimPicture *g_img_status_num_off;
extern SceGimPicture *g_img_mission_cover;
extern SceGimPicture *g_vs_back;
extern SceGimPicture *g_vs_light;
extern SceGimPicture *g_vs_char[2];
extern SceGimPicture *g_vs_char_report;
extern SceGimPicture *g_vs_mission_board;
extern SceGimPicture *g_vs_mission_item;
extern SceGimPicture *g_vs_level_num;
extern SceGimPicture *g_vs_text_v;
extern SceGimPicture *g_vs_text_s;
extern SceGimPicture *g_vs_text_vs;
extern SceGimPicture *pic_dlg[12];
extern Dlg_param dlg_param[12];
extern ani_param g_ani_param[22];
extern unsigned int g_vs_frame;

static void graphic_init();
SceGimPicture *load_picture(int index, int *buff, int size);
void sceGimPictureSetFrame(SceGimPicture *picture, float frame);
void sceGimPictureActivate(SceGimPicture *picture);
void sceGimPictureDelete(SceGimPicture *picture);
void sceGuTerm(void);
void printhanln(int ax, int ay, int color, const char *str);
void printwanln(int ax, int ay, int color, const char *str);
void sceGimPictureAnimate(SceGimPicture *picture, float time);
static void draw_sprite2(int x, int y, int w, int h, int ix, int iy, int flip);
static void draw_black_back(int x, int y, int w, int h, unsigned int col);
static void load();
static int sceGimImageGetWidth(const SceGimImageHeader *image, int level);
static int sceGimImageGetHeight(const SceGimImageHeader *image, int level);
static void run_draw_vs();
static void draw_vs_menu();
static void draw_button(int x, int y, int btn);
static void draw_pause();
static void draw_ox(int ox, int x, int y);
static void draw_pae(int pae, int x, int y, float scale, int set);
static void draw_pae2(int pae, int x, int y, float scale, int set);
static void draw_back_pae(int x, int y, float scale, int set);
static void draw_flying_pae(int pae, int x, int y, float scale, int set);
static void draw_flying_pae2(int pae, int x, int y, float xscale, float yscale, int set);
static void draw_checked_pae(int pae, int x, int y, float scale);
static void draw_my_hand(void);
static void draw_opp_hand1();
static void draw_pae_num(int num, int x, int y);
static void draw_my_collection(void);
static void draw_opp_collection1(void);
static void draw_cursor(int cursor_pos);
static void init_animation(int ani);
static int draw_animation(int ani, int x, int y, int flag_loop);
static __inline__ int sceGimImageGetFrameCount(const SceGimImageHeader *image);
SceGimImageHeader *sceGimPictureGetImage(SceGimPicture *picture);
float sceGimPictureGetFrame(SceGimPicture *picture);
static void draw_loading(int alpha);
static void graphic_destroy();
static void draw_dialog_box(int dlgnum, int *p);
static void show_gostop_info();
static void show_result_dialog();
static void draw_number(long64 num, int x, int y, int space, int font_size, int align);
static void draw_number2(char *str, int x, int y, int space, int font_size, int align);
static void draw_win_lose(int x, int y, unsigned int win, unsigned int lose);
static void draw_collect_paes(int flagPlayer);
static void fade_out(unsigned int alpha);
static void draw_char_name(int x, int y, const char *cname);
static void draw_all_in(int flagPlayer);
static void draw_save();
static void show_warning(const char *msg, unsigned int alpha);

/* SDK functions (tools/sdk_protos.h) */
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);


extern SceGimPicture *D_00054EA0;


void make_num_format(char *strOut, long64 num);
unsigned int strlen(const char *s);
void *memset(void *s, int c, unsigned int n);
int sprintf(char *buf, const char *fmt, ...);
void sceGuInit(void);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
int sceGuDisplay(int state);
void *malloc(unsigned int size);
void free(void *p);
void *malloc16(unsigned int size);
void free16(void *addr);
void sceGimPictureSetMemoryManager(void *(*alloc_func)(unsigned int), void (*free_func)(void *));
void sceGimPictureSetMemoryManager2(void *(*alloc_func)(unsigned int), void (*free_func)(void *));
extern int D_00034DE8;	/* static int fo_frame (draw_loading) */
SceGimPicture *load_image(const char *filename, ...);
int rand(void);
void sceGimPictureSetFrameRate(SceGimPicture *picture, float fps);

static __inline__ int sceGimImageGetFrameCount(const SceGimImageHeader *image)
{
	return image->frame_count;
}

static void graphic_init()
{
	print_nothing("0\n");
	sceGimPictureSetMemoryManager(malloc, free);
	sceGimPictureSetMemoryManager2(malloc16, free16);
	sceGuInit();
	print_nothing("1\n");
	sceGuStart(0, disp_list, 0x20000);
	sceGuDrawBuffer(1, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x44000, 512);
	sceGuDepthBuffer((void *)0x88000, 512);
	sceGuOffset(0, 0);
	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);
	print_nothing("2\n");
	sceGuTexFilter(7, 0);
	sceGuTexFunc(0, 1);
	sceGuTexWrap(0, 0);
	sceGuEnable(9);
	print_nothing("3\n");
	sceGuAlphaFunc(6, 80, 255);
	sceGuEnable(0);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
	print_nothing("4\n");
	sceGuClearColor(0xedad82);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	print_nothing("5\n");
	sceGuFinish();
	sceGuSync(0, 0);
	sceGuDisplay(1);
	print_nothing("6\n");
}

__asm__(".globl graphic_init");

SceGimPicture *load_picture(int index, int *buff, int size)
{
	SceGimPicture *pic = sceGimPictureCreate(0);

	if (pic == NULL) {
		print_nothing("picture create failed\n");
		return NULL;
	}
	if (!sceGimPictureLoadFile(pic, buff, size, index)) {
		print_nothing("picture load failed : %d\n", index);
		sceGimPictureDelete(pic);
		return NULL;
	}
	g_img_loaded++;
	return pic;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/draw", draw_sprite2);

void draw_sprite(int x, int y, int w, int h, int flip) {
    draw_sprite2(x, y, w, h, 0, 0, flip);
}

static void draw_black_back(int x, int y, int w, int h, unsigned int col)
{
	int i;

	sceGimPictureActivate(g_img_black_back);
	sceGuColor(col);
	for (i = 0; i < w; i += 32) {
		sceGuSpriteMode(5, 5, 32, h);
		sceGuDrawSprite(x + i, y, 0, 0, 0, 0, 0);
	}
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/draw", load_8F0);

/* load_8F0's float constants (asm until load_8F0 is C): .rodata.cst4, like C floats */
__asm__(".pushsection .rodata.cst4,\"aM\",@progbits,4\n"
	"\t.align 2\n"
	".globl D_0002F30C\nD_0002F30C:\n\t.word 0x40A00000\n"
	".globl D_0002F310\nD_0002F310:\n\t.word 0x3C888889\n"
	".globl D_0002F314\nD_0002F314:\n\t.word 0x41200000\n"
	"\t.popsection");

/* the "" initializer constant that C emits first in run_draw_vs; show_result_dialog (asm) uses it */
__asm__(".globl D_0002F270\nD_0002F270 = 0x0002F270");

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F198);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F1B4);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F1CC);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F1E4);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F20C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F224);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F240);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F25C);

static void run_draw_vs()
{
	unsigned int alpha;

	if (g_draw_vs_switch == 0)
		return;
	alpha = g_vs_frame * 8.0f;
	if (alpha >= 255)
		alpha = 255;
	sceGimPictureActivate(g_vs_back);
	sceGuColor((alpha << 24) | 0xffffff);
	draw_sprite(0, 0, 480, 28, 0);
	alpha = g_vs_frame * 4.0f;
	if (alpha >= 127)
		alpha = 127;
	draw_black_back(0, 28, 480, 244, (alpha << 24) | 0xffffff);
	sceGuColor(0xffffffff);
	if (g_vs_frame >= 20) {
		int x = g_vs_frame * 16 - 560;
		int y;

		if (x > 0)
			x = 0;
		sceGimPictureActivate(g_vs_light);
		draw_sprite(x, 28, 240, 124, 0);
		draw_sprite(240 - x, 28, 240, 124, 1);
	}
	if (g_vs_frame >= 30) {
		int x;
		int y = g_vs_frame * 4 - 142;

		if (y > 3)
			y = 3;
		sceGimPictureActivate(g_vs_level_num);
		draw_sprite2(192, y, 93, 22, 0, (l_mod_player.level - 1) * 22, 0);
	}
	if (g_vs_frame >= 40) {
		int x = g_vs_frame * 30 - 1252;
		int y;

		if (x > 194)
			x = 194;
		sceGimPictureActivate(g_vs_text_v);
		draw_sprite(x, 58, 52, 63, 0);
		x = g_vs_frame * -30 + 1680;
		if (x <= 240)
			x = 240;
		sceGimPictureActivate(g_vs_text_s);
		draw_sprite(x, 58, 52, 63, 0);
	}
	if (g_vs_frame >= 35) {
		int x, y;

		x = g_vs_frame * -20 + 1180;
		if (x <= 278)
			x = 278;
		sceGimPictureActivate(g_vs_char_report);
		draw_sprite2(x, 155, 198, 112, 0, g_opp_char[0] * 112, 0);
		x -= 5;
		sceGimPictureActivate(g_vs_char[1]);
		draw_sprite(x, -28, 210, 219, 0);
		x = 270 - x;
		sceGimPictureActivate(g_vs_char[0]);
		draw_sprite(x, -28, 210, 219, 1);

		int boardx, boardy;

		boardy = g_vs_frame * -20 + 972;
		if (boardy <= 161)
			boardy = 161;
		sceGimPictureActivate(g_vs_mission_board);
		draw_sprite(10, boardy, 256, 100, 0);

		int i, index, tot, suc;

		for (i = 0, index = 0; i < 11; i++) {
			tot = g_level_mission[i];
			if (tot > 0) {
				suc = l_mod_player.success_level_mission[i];
				if (suc > tot)
					suc = tot;
				{
					int tx = (index / 2) * 126 + 23;
					int ty = boardy + (index % 2) * 20 + 56;

					index++;
					sceGimPictureActivate(g_vs_mission_item);
					draw_sprite2(tx, ty, 59, 18, 0, i * 18, 0);
					char strNum[5] = "";

					sprintf(strNum, "%d+%d", suc, tot);
					graphics.draw_number2(strNum, tx + 67, ty + 1, 1, 11, 0);
				}
			}
		}
	}
	if (g_vs_frame <= 1000)
		g_vs_frame++;
}

static void draw_vs_menu()
{
	if (g_draw_vs_switch == 0) {
		g_vs_frame = 0;
		g_draw_vs_switch = 1;
		g_timer_pause = 1;
	}
	run_draw_vs();
}

__asm__(".globl draw_vs_menu");

void draw_button(int x, int y, int btn) {
    sceGimPictureActivate(g_img_button);
    sceGuColor(-1U);
    draw_sprite2(x, y, 0x48, 0x12, 0, btn * 0x12, 0);
}

__asm__(".globl draw_button");

static void draw_pause()
{
	draw_black_back(0, 0, 480, 272, 0xbbffffff);
	sceGimPictureActivate(g_img_warning2);
	sceGuColor(0xffffffff);
	draw_sprite(111, 60, 237, 140, 0);
	printwanln(132, 85, 0xff000000, "\xb0\xd4\xc0\xd3\xc0\xcc \xc1\xa4\xc1\xf6\xb5\xc7\xbe\xfa\xbd\xc0\xb4\xcf\xb4\xd9\n\n\xb0\xe8\xbc\xd3 \xc7\xcf\xbd\xc3\xb7\xc1\xb8\xe9 Continue\xb8\xa6 \xb4\xa9\xb8\xa3\xbc\xbc\xbf\xe4");
	draw_button(193, 174, 1);
	draw_button(280, 174, 3);
}

__asm__(".globl draw_pause");

void stop_vs_menu(void) {
    if (g_draw_vs_switch != 1) {
        return;
    }
    g_vs_frame = 0;
    g_draw_vs_switch = 0;
    g_timer_pause = 0;
}

void draw_pae_mark(int n, int x, int y) {
    sceGimPictureActivate(g_icons[n]);
    sceGuSpriteMode(9, 9, 9, 9);
    sceGuColor(-1U);
    sceGuDrawSprite(x, y, 0, 0, 0, 0, 0);
}

void draw_ox(int ox, int x, int y) {
    sceGimPictureActivate(g_icon_ox);
    sceGuSpriteMode(0x10, 0x1A, 0x10, 0x1A);
    sceGuColor(-1U);
    sceGuDrawSprite(x, y, 0, ox * 0x10, 0, 0, 0);
}

__asm__(".globl draw_ox");

static void draw_pae(int pae, int x, int y, float scale, int set)
{
	if (animator.is_flying(pae))
		return;
	if (set == 1) {
		if (pae < 29) {
			sceGimPictureActivate(pic_pae_l1);
			sceGuSpriteMode(36, 57, (int)(scale * 36.0f), (int)(scale * 57.0f));
			sceGuColor(0xFFFFFFFF);
			sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 36, ((pae - 1) / 4) * 57, 0, 0);
		} else {
			sceGimPictureActivate(pic_pae_l2);
			sceGuSpriteMode(36, 57, (int)(scale * 36.0f), (int)(scale * 57.0f));
			sceGuColor(0xFFFFFFFF);
			sceGuDrawSprite(x, y, 0, ((pae - 29) % 4) * 36, ((pae - 29) / 4) * 57, 0, 0);
		}
	} else if (set == 2) {
		sceGimPictureActivate(pic_pae_m);
		sceGuSpriteMode(24, 38, (int)(scale * 24.0f), (int)(scale * 38.0f));
		sceGuColor(0xFFFFFFFF);
		sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 24, ((pae - 1) / 4) * 38, 0, 0);
	} else if (set == 3) {
		sceGimPictureActivate(pic_pae_s);
		sceGuSpriteMode(16, 26, (int)(scale * 16.0f), (int)(scale * 26.0f));
		sceGuColor(0xFFFFFFFF);
		sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 16, ((pae - 1) / 4) * 26, 0, 0);
	}
	set_pae_pos(pae, x, y);
}

__asm__(".globl draw_pae");

static void draw_pae2(int pae, int x, int y, float scale, int set)
{
	if (set == 1) {
		if (pae < 29) {
			sceGimPictureActivate(pic_pae_l1);
			sceGuSpriteMode(36, 57, (int)(scale * 36.0f), (int)(scale * 57.0f));
			sceGuColor(0xFFFFFFFF);
			sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 36, ((pae - 1) / 4) * 57, 0, 0);
		} else {
			sceGimPictureActivate(pic_pae_l2);
			sceGuSpriteMode(36, 57, (int)(scale * 36.0f), (int)(scale * 57.0f));
			sceGuColor(0xFFFFFFFF);
			sceGuDrawSprite(x, y, 0, ((pae - 29) % 4) * 36, ((pae - 29) / 4) * 57, 0, 0);
		}
	} else if (set == 2) {
		sceGimPictureActivate(pic_pae_m);
		sceGuSpriteMode(24, 38, (int)(scale * 24.0f), (int)(scale * 38.0f));
		sceGuColor(0xFFFFFFFF);
		sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 24, ((pae - 1) / 4) * 38, 0, 0);
	} else if (set == 3) {
		sceGimPictureActivate(pic_pae_s);
		sceGuSpriteMode(16, 26, (int)(scale * 16.0f), (int)(scale * 26.0f));
		sceGuColor(0xFFFFFFFF);
		sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 16, ((pae - 1) / 4) * 26, 0, 0);
	}
}

__asm__(".globl draw_pae2");

static void draw_back_pae(int x, int y, float scale, int set)
{
	switch (set) {
	case 2:
		sceGimPictureActivate(pic_pae_m);
		sceGuSpriteMode(24, 38, (int)(scale * 24.0f), (int)(scale * 38.0f));
		sceGuColor(0xFFFFFFFF);
		sceGuDrawSprite(x, y, 0, 72, 456, 0, 0);
		break;
	case 3:
		sceGimPictureActivate(pic_pae_s);
		sceGuSpriteMode(16, 26, (int)(scale * 16.0f), (int)(scale * 26.0f));
		sceGuColor(0xFFFFFFFF);
		sceGuDrawSprite(x, y, 0, 48, 312, 0, 0);
		break;
	}
}

__asm__(".globl draw_back_pae");

static void draw_flying_pae(int pae, int x, int y, float scale, int set)
{
	if (animator.is_flying(pae) != 1)
		return;
	if (set == 1) {
		if (pae < 29) {
			sceGimPictureActivate(pic_pae_l1);
			sceGuSpriteMode(36, 57, (int)(scale * 36.0f), (int)(scale * 57.0f));
						sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 36, ((pae - 1) / 4) * 57, 0, 0);
		} else {
			sceGimPictureActivate(pic_pae_l2);
			sceGuSpriteMode(36, 57, (int)(scale * 36.0f), (int)(scale * 57.0f));
						sceGuDrawSprite(x, y, 0, ((pae - 29) % 4) * 36, ((pae - 29) / 4) * 57, 0, 0);
		}
	} else if (set == 2) {
		sceGimPictureActivate(pic_pae_m);
		sceGuSpriteMode(24, 38, (int)(scale * 24.0f), (int)(scale * 38.0f));
		sceGuColor(0xFFFFFFFF);
		sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 24, ((pae - 1) / 4) * 38, 0, 0);
	} else if (set == 3) {
		sceGimPictureActivate(pic_pae_s);
		sceGuSpriteMode(16, 26, (int)(scale * 16.0f), (int)(scale * 26.0f));
		sceGuColor(0xFFFFFFFF);
		sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 16, ((pae - 1) / 4) * 26, 0, 0);
	}
}

__asm__(".globl draw_flying_pae");

static void draw_flying_pae2(int pae, int x, int y, float xscale, float yscale, int set)
{
	if (set == 1) {
		if (pae < 29) {
			sceGimPictureActivate(pic_pae_l1);
			sceGuSpriteMode(36, 57, (int)(xscale * 36.0f), (int)(yscale * 57.0f));
			sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 36, ((pae - 1) / 4) * 57, 0, 0);
		} else {
			sceGimPictureActivate(pic_pae_l2);
			sceGuSpriteMode(36, 57, (int)(xscale * 36.0f), (int)(yscale * 57.0f));
			sceGuDrawSprite(x, y, 0, ((pae - 29) % 4) * 36, ((pae - 29) / 4) * 57, 0, 0);
		}
	} else if (set == 2) {
		sceGimPictureActivate(pic_pae_m);
		sceGuSpriteMode(24, 38, (int)(xscale * 24.0f), (int)(yscale * 38.0f));
		sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 24, ((pae - 1) / 4) * 38, 0, 0);
	} else if (set == 3) {
		sceGimPictureActivate(pic_pae_s);
		sceGuSpriteMode(16, 26, (int)(xscale * 16.0f), (int)(yscale * 26.0f));
		sceGuDrawSprite(x, y, 0, ((pae - 1) % 4) * 16, ((pae - 1) / 4) * 26, 0, 0);
	}
}

__asm__(".globl draw_flying_pae2");

static void draw_checked_pae(int pae, int x, int y, float scale)
{
	int fixed;

	if (animator.is_flying(pae))
		return;
	draw_pae(pae, x, y, scale, 2);
	fixed = handManager.is_fixed(0, paeManager.get_pae_kind(pae));
	if (fixed)
		draw_pae_mark(fixed == 2 ? 2 : 1, x, y);
}

__asm__(".globl draw_checked_pae");

static void draw_my_hand(void)
{
	int i;
	int x;
	int y;
	int pae;

	for (i = 0; i < 10; i++) {
		pae = g_my_hand[i];
		x = (i % 5) * 26 + 348;
		y = (i / 5) * 40 + 190;
		if (pae != 0) {
			if (g_stage_status == 14 && g_player_index == g_turn)
				draw_checked_pae(pae, x, y, 1.0f);
			else
				draw_pae(pae, x, y, 1.0f, 2);
		}
	}
}

__asm__(".globl draw_my_hand");

static void draw_opp_hand1(void)
{
	int i;

	for (i = 0; i < 10; i++) {
		if (g_opp_hand[0][i] == 0)
			break;
		draw_pae(52, 133 + i * 6, 3, 0.88f, 3);
	}
}

void draw_opp_hand(void) {
    draw_opp_hand1();
}

static void draw_pae_num(int num, int x, int y)
{
	x += 7;
	y += 19;
	if (num >= 10)
		graphics.draw_number(num / 10, x, y, 1, 10, 0);
	x += 4;
	graphics.draw_number(num % 10, x, y, 1, 10, 0);
}

/* float rodata in .rodata.cst4, as C emits it */
INCLUDE_ASM("decomp_src/flowars/flowars/asm_cst4", draw_my_collection);

/* float rodata in .rodata.cst4, as C emits it */
INCLUDE_ASM("decomp_src/flowars/flowars/asm_cst4", draw_opp_collection1);

void draw_opp_collection(void) {
    draw_opp_collection1();
}

void printDebugMsg(int x, int y, signed char *str) {
    sceGuDebugPrint(x, y, -1U, str);
}

void printDebugMsg2(int x, int y, int color, signed char *str) {
    sceGuDebugPrint(x, y, (unsigned int) color, str);
}

static void draw_cursor(int cursor_pos)
{
	sceGimPictureAnimate(g_cursor_hand, 1.0f / 60.0f);
	sceGimPictureActivate(g_cursor_hand);
	sceGuSpriteMode(28, 42, 28, 42);
	sceGuDrawSprite((cursor_pos % 5) * 26 + 346, (cursor_pos / 5) * 40 + 188, 0, 0, 0, 0, 0);
}

__asm__(".globl draw_cursor");

void init_animation(int ani) {
    sceGimPictureSetFrame(g_animation[ani], 0);
}

__asm__(".globl init_animation");

static int draw_animation(int ani, int x, int y, int flag_loop)
{
	SceGimImageHeader *h;
	int totalframes;
	int continued;

	h = sceGimPictureGetImage(g_animation[ani]);
	totalframes = sceGimImageGetFrameCount(h);
	if (sceGimPictureGetFrame(g_animation[ani]) < totalframes - 1) {
		continued = 1;
		sceGimPictureAnimate(g_animation[ani], g_ani_param[ani].step);
	} else {
		continued = 0;
		if (flag_loop)
			sceGimPictureAnimate(g_animation[ani], g_ani_param[ani].step);
	}
	sceGimPictureActivate(g_animation[ani]);
	sceGuColor(0xFFFFFFFF);
	draw_sprite(x, y, g_ani_param[ani].width, g_ani_param[ani].height, 0);
	return continued;
}

__asm__(".globl draw_animation");

static void draw_loading(int alpha)
{
	if (D_00034DE8 <= 40) {
		if (alpha == 0) {
			img_load_bg = load_image("img/loading.gim");
			img_load_ani = load_image("img/loading%02d.gim", rand() % 12 + 1);
			sceGimPictureSetFrameRate(img_load_ani, 1.0f);
		} else {
			sceGimPictureActivate(img_load_bg);
			if (g_img_loaded_done == 1) {
				alpha = (int)(255.0 - D_00034DE8 / 40.0 * 255.0);
				sceGuColor(0xff000000 | (alpha << 16) | (alpha << 8) | alpha);
				D_00034DE8++;
			} else
				sceGuColor(0xffffffff);
			draw_sprite(0, 0, 480, 272, 0);
			sceGimPictureAnimate(img_load_ani, 0.075f);
			sceGimPictureActivate(img_load_ani);
			draw_sprite(187, 94, 94, 82, 0);
			if (D_00034DE8 >= 40) {
				sceGuColor(0xffffffff);
				g_stage_status = 3;
				sceGimPictureDelete(img_load_ani);
				sceGimPictureDelete(img_load_bg);
			}
		}
	}
}

__asm__(".globl draw_loading");

void init_sprite(void) {
    sceGuStart(0, disp_list, 0x20000);
    sceGuClear(7);
}

void sync_sprite(void) {
    sceGuFinish();
    sceGuSync(0, 0);
    if (sceUtilitySavedataGetStatus() != 2) {

    } else {
        sceUtilitySavedataUpdate(1);
    }
}

static void graphic_destroy()
{
	int i;

	sceGimPictureDelete(pic_pae_l1);
	sceGimPictureDelete(pic_pae_l2);
	sceGimPictureDelete(pic_pae_m);
	sceGimPictureDelete(pic_pae_s);
	sceGimPictureDelete(g_icon_ox);
	sceGimPictureDelete(g_img_win_lose);
	sceGimPictureDelete(g_cursor_hand);
	sceGimPictureDelete(g_timer);
	sceGimPictureDelete(g_img_all_in);
	sceGimPictureDelete(g_img_button);
	for (i = 0; i < 4; i++)
		sceGimPictureDelete(g_icons[i]);
	for (i = 0; i < 21; i++)
		if (i != 0 && i != 11)
			sceGimPictureDelete(g_animation[i]);
	for (i = 0; i < 12; i++)
		sceGimPictureDelete(g_font[i]);
	sceGimPictureDelete(g_font_han);
	sceGimPictureDelete(g_font_eng);
	for (i = 0; i < 2; i++)
		sceGimPictureDelete(g_icon_result[i]);
	sceGimPictureDelete(g_img_turn);
	sceGimPictureDelete(g_img_sun);
	sceGimPictureDelete(g_img_bet_money);
	sceGimPictureDelete(g_img_nagari_num);
	sceGimPictureDelete(g_img_status_on);
	sceGimPictureDelete(g_img_status_off);
	sceGimPictureDelete(g_img_status_num_on);
	sceGimPictureDelete(g_img_status_num_off);
	sceGimPictureDelete(g_img_black_back);
	sceGimPictureDelete(g_img_warning);
	sceGimPictureDelete(g_img_warning2);
	if (mod_game.game_type == 1) {
		sceGimPictureDelete(g_vs_back);
		sceGimPictureDelete(g_vs_light);
		sceGimPictureDelete(g_vs_char[0]);
		sceGimPictureDelete(g_vs_char[1]);
		sceGimPictureDelete(g_vs_char_report);
		sceGimPictureDelete(g_vs_mission_board);
		sceGimPictureDelete(g_vs_mission_item);
		sceGimPictureDelete(g_vs_level_num);
		sceGimPictureDelete(g_vs_text_v);
		sceGimPictureDelete(g_vs_text_s);
		sceGimPictureDelete(g_vs_text_vs);
	} else
		sceGimPictureDelete(g_img_mission_cover);
	sceGuTerm();
}

__asm__(".globl graphic_destroy");

void swap_buffers(void) {
    sceGuSwapBuffers();
}

static void draw_dialog_box(int dlgnum, int *p)
{
	int x, y, w, h;
	int i, n;

	w = dlg_param[dlgnum].width;
	h = dlg_param[dlgnum].height;
	x = (225 - w) / 2 + 117;
	y = (151 - h) / 2 + 55;
	sceGimPictureActivate(pic_dlg[dlgnum]);
	sceGuColor(0xffffffff);
	draw_sprite(x, y, w, h, 0);
	if (p != NULL) {
		n = count_array(p, 4);
		if (n >= 4) {
			x = (225 - w) / 2 + 154;
			y = (151 - h) / 2 + 110;
			for (i = 0; i < 4; i++) {
				draw_pae(p[i], x, y, 1.0f, 2);
				x += 26;
			}
		} else if (n == 3) {
			x = (225 - w) / 2 + 167;
			y = (151 - h) / 2 + 110;
			for (i = 0; i < n; i++) {
				draw_pae(p[i], x, y, 1.0f, 2);
				x += 26;
			}
		} else if (n == 2) {
			x = (225 - w) / 2 + 161;
			y = (151 - h) / 2 + 110;
			for (i = 0; i < n; i++) {
				draw_pae(p[i], x, y, 1.0f, 2);
				x += 64;
			}
		} else {
			draw_pae(p[0], (225 - w) / 2 + 193, (151 - h) / 2 + 110, 1.0f, 2);
		}
	}
}

__asm__(".globl draw_dialog_box");

void draw_result_icon(int flagWin, int index, int x, int y) {
    SceGimPicture *var_a0;

    if (flagWin != 0) {
        var_a0 = D_00054EA0;
    } else {
        var_a0 = *g_icon_result;
    }
    sceGimPictureActivate(var_a0);
    sceGuSpriteMode(0x25, 0x11, 0x25, 0x11);
    sceGuColor(-1U);
    sceGuDrawSprite(x, y, 0, 0, index * 0x11, 0, 0);
}

static void show_gostop_info()
{
	UserStat ustat;

	userManager.get_stat(0, &ustat);
	int base_x = (225 - dlg_param[2].width) / 2;
	int base_y = (151 - dlg_param[2].height) / 2;

	graphics.draw_number(ustat.go, base_x + 130, base_y + 87, 1, 2, 0);
	char buff[50] = "";

	sprintf(buff, "%d\xc1\xa1", g_result_score.score.total);
	printwanln(base_x + 147, base_y + 117, 0xffffffff, buff);
	char strNum[15] = "";

	make_num_format(strNum, g_result_score.money_sum);
	sprintf(buff, "(%s\xbf\xf8)", strNum);
	printwanln(base_x + 147, base_y + 133, 0xffffffff, buff);
}

__asm__(".globl show_gostop_info");

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/draw", show_result_dialog);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F2F0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F2F4);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/draw", D_0002F2F8);


static void draw_number(long64 num, int x, int y, int space, int font_size, int align)
{
	int c, cnum, i, x_start;
	char buff[30] = "";
	int w = font_scale[font_size].width;
	int h = font_scale[font_size].height;

	sceGimPictureActivate(g_font[font_size]);
	sceGuColor(0xffffffff);
	make_num_format(buff, num);
	if (align == 1) {
		x_start = x + (space - strlen(buff)) * w;
	} else if (align == 2) {
		x_start = x - strlen(buff) * w / 2;
		if (x_start < 0)
			x_start = 0;
	} else
		x_start = x;
	for (i = 0; i < (int)strlen(buff) && i < 29; i++) {
		c = buff[i];
		cnum = c - '0';
		if (c < '0' || buff[i] > '9') {
			if (c == ',')
				cnum = 13;
			else if (c == '-')
				cnum = 11;
			else
				continue;
		}
		sceGuSpriteMode(w, h, w, h);
		sceGuDrawSprite(x_start + i * w, y, 0, w * cnum, 0, 0, 0);
	}
}

__asm__(".globl draw_number");

static void draw_number2(char *str, int x, int y, int space, int font_size, int align)
{
	int c, cnum, i, x_start;
	int w = font_scale[font_size].width;
	int h = font_scale[font_size].height;

	sceGimPictureActivate(g_font[font_size]);
	sceGuColor(0xffffffff);
	if (align == 1) {
		x_start = x + (space - strlen(str)) * w;
	} else if (align == 2) {
		x_start = x - strlen(str) * w / 2;
		if (x_start < 0)
			x_start = 0;
	} else
		x_start = x;
	for (i = 0; i < (int)strlen(str) && i < 9; i++) {
		c = str[i];
		if (c >= '0' && str[i] <= '9')
			cnum = c - '0';
		else if (c == '+')
			cnum = 10;
		else if (c == '-')
			cnum = 11;
		else if (c == 'x' || c == 'X')
			cnum = 12;
		else if (c == ',')
			cnum = 13;
		else
			continue;
		sceGuSpriteMode(w, h, w, h);
		sceGuDrawSprite(x_start + i * w, y, 0, w * cnum, 0, 0, 0);
	}
}

__asm__(".globl draw_number2");

void draw_timer(int sec) {
    sceGimPictureActivate(g_timer);
    sceGuColor(-1U);
    draw_sprite2(0x172, 0x64, 0x66, 0x50, (5 - sec) * 0x66, 0, 0);
}

static void draw_win_lose(int x, int y, unsigned int win, unsigned int lose)
{
	char strNum[10] = "";
	int winx, losex;

	sprintf(strNum, "%d", win);
	graphics.draw_number2(strNum, x, y, 1, 1, 0);
	winx = x + font_scale[1].width * strlen(strNum);
	sprintf(strNum, "%d", lose);
	graphics.draw_number2(strNum, winx + 10, y, 1, 1, 0);
	losex = winx + font_scale[1].width * strlen(strNum) + 10;
	sceGimPictureActivate(g_img_win_lose);
	sceGuSpriteMode(10, 10, 10, 10);
	sceGuDrawSprite(winx, y, 0, 0, 0, 0, 0);
	sceGuDrawSprite(losex, y, 0, 10, 0, 0, 0);
}

__asm__(".globl draw_win_lose");

static void draw_collect_paes(int flagPlayer)
{
	draw_black_back(0, 0, 480, 272, 0xccffffff);
	int start_x, start_y;

	if (flagPlayer == -1) {
		int i, pos;
		int start_x, start_y;
		int index;

		pos = 0;
		for (index = 0; index < 13; index++) {
			if (g_pan[index].count > 0) {
				for (i = 0; i < g_pan[index].count; i++)
					graphics.draw_pae2(g_pan[index].pae[i], (pos % 2) * 180 + 100 + i * 28, (pos / 2) * 42 + 12, 1.0f, 2);
				pos++;
			}
		}
	} else if (flagPlayer == -3) {
		int i;

		for (i = 0; i < handManager.count(1); i++)
			graphics.draw_pae2(handManager.get_pae_at(1, i), 20 + i * 20, 100, 1.0f, 2);
		for (i = 0; i < g_back_remain; i++)
			graphics.draw_pae2(g_deck[i] + 1, 20 + i * 15, 200, 1.0f, 2);
	} else {
		int *collection_gwang = NULL;
		int *collection_mung = NULL;
		int *collection_dan = NULL;
		int *collection_pi = NULL;

		switch (flagPlayer) {
		case 0:
			skinManager.draw_character(0, 0, 208, 7);
			collection_gwang = g_my_collection_gwang;
			collection_mung = g_my_collection_mung;
			collection_dan = g_my_collection_dan;
			collection_pi = g_my_collection_pi;
			break;
		case 1:
			skinManager.draw_character(1, 0, 0, 5);
			collection_gwang = g_opp_collection_gwang;
			collection_mung = g_opp_collection_mung;
			collection_dan = g_opp_collection_dan;
			collection_pi = g_opp_collection_pi;
			break;
		case 2:
			skinManager.draw_character(2, 418, 0, 6);
			collection_gwang = g_opp2_collection_gwang;
			collection_mung = g_opp2_collection_mung;
			collection_dan = g_opp2_collection_dan;
			collection_pi = g_opp2_collection_pi;
			break;
		}
		int i, cnt;

		start_x = 100;
		cnt = count_array(collection_gwang, 5);
		start_y = 20;
		for (i = 0; i < cnt; i++)
			draw_pae2(collection_gwang[i], start_x + i * 28, start_y, 1.0f, 2);
		cnt = count_array(collection_mung, 9);
		start_y += 42;
		for (i = 0; i < cnt; i++)
			draw_pae2(collection_mung[i], start_x + i * 28, start_y, 1.0f, 2);
		cnt = count_array(collection_dan, 10);
		start_y += 42;
		for (i = 0; i < cnt; i++)
			draw_pae2(collection_dan[i], start_x + i * 28, start_y, 1.0f, 2);
		cnt = count_array(collection_pi, 25);
		start_y += 42;
		for (i = 0; i < cnt; i++)
			draw_pae2(collection_pi[i], start_x + (i % 10) * 28, start_y + (i / 10) * 42, 1.0f, 2);
	}
}

__asm__(".globl draw_collect_paes");

void fade_out(unsigned int alpha)
{
	if (alpha >= 255)
		alpha = 255;
	draw_black_back(0, 0, 480, 272, (alpha << 24) | 0xFFFFFF);
}

__asm__(".globl fade_out");

static void draw_char_name(int x, int y, const char *cname)
{
	printhanln(x, y, 0xFF000000, cname);
}

__asm__(".globl draw_char_name");

static void draw_all_in(int flagPlayer)
{
	int x;
	int y;

	if (flagPlayer == 0) {
		x = -1;
		y = 214;
	} else if (flagPlayer == 1) {
		x = -1;
		y = 8;
	} else {
		x = 409;
		y = 8;
	}
	sceGimPictureActivate(g_img_all_in);
	sceGuColor(0xFFFFFFFF);
	draw_sprite(x, y, 64, 41, 0);
}

__asm__(".globl draw_all_in");

static void draw_save()
{
	graphics.show_warning("\xc0\xfa\xc0\xe5\xc1\xdf....", 255);
}

__asm__(".globl draw_save");

static void show_warning(const char *msg, unsigned int alpha)
{
	sceGimPictureActivate(g_img_warning);
	if (alpha >= 20)
		alpha = 255;
	alpha <<= 24;
	sceGuColor(alpha | 0xFFFFFF);
	draw_sprite(152, 98, 176, 76, 0);
	printwanln(165, 130, alpha, msg);
	sceGuColor(0xFFFFFFFF);
}

__asm__(".globl show_warning");

void draw_error(signed char *msg) {
    draw_black_back(0, 0, 0x1E0, 0x110, 0x5FFFFFFFU);
    sceGimPictureActivate(g_img_warning2);
    sceGuColor(-1U);
    draw_sprite(0x6F, 0x3C, 0xED, 0x8C, 0);
    printwanln(0x84, 0x50, 0xFF000000, msg);
    draw_button(0xCD, 0xAE, 0);
    draw_button(0x109, 0xAE, 2);
}

int get_img_loaded(void) {
    return g_img_loaded;
}

