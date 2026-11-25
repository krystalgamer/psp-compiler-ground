#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x8 */
    int x;
    int y;
};
typedef struct _anon1 Point;
struct _anon2;
struct _anon2 { /* size 0x30 */
    int pae;
    int frame;
    int delay;
    int status;
    float distance;
    Point src;
    Point dst;
    Point move;
    int sound;
};
typedef struct _anon2 PaeMoveParam;
struct _anon3;
struct _anon3 { /* size 0x1c */
    int ani;
    int x;
    int y;
    int status;
    int sound;
    int flag_loop;
    int extand_frame;
};
typedef struct _anon3 AniParam;
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
struct _anon4;
struct _anon4 { /* size 0x38 */
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
typedef struct _anon4 Animator;

extern int g_delay;
extern Graphics graphics;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern SoundUtil soundUtil;
extern int g_take_don;
extern int g_player_index;
extern int g_turn;
extern Animator animator;
extern PaeMoveParam paeParam[8];
extern int anipae_cnt;
extern int moving_pae;
extern AniParam aniParam[10];
extern int ani_cnt;
extern int ani_rest;
extern int ani_frame;

static int is_flying(int pae);
float getCurrentPoint(Point *pt, PaeMoveParam *pp, float speed, int skipFrames);
void getResizedPostion(Point *pt, int pae_set, float xsize, float ysize);
static void me_to_pan();
static void me_to_bomb();
static void pan_to_collect();
static void collect_to_collect();
static void pan_to_hand();
static void play_bonus_pae();
static void add_pae(int pae, int sx, int sy, int dx, int dy, int delay, int sound);
static void add_pae_bomb(int pae, int sx, int sy, int dx, int dy, int delay, int sound);
static void add_ani(int ani, int x, int y, int flag_loop, int extand_frame, int sound);
static void start_ani();

/* SDK functions (tools/sdk_protos.h) */
void *memset(void *s, int c, unsigned int n);


INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", is_flying);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", init_animator);

void clear_animation(void) {
    g_delay = 0;
    init_animator();
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", getCurrentPoint);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F858);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F85C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F860);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F864);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F868);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F86C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F870);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F874);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F878);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F87C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F880);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F884);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F888);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F88C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F890);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F894);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F898);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F89C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8A0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8A4);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8A8);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8AC);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8B0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8B4);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8B8);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8BC);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8C0);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8C4);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8C8);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F8CC);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", getResizedPostion);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", me_to_pan);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", me_to_bomb);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", pan_to_collect);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", collect_to_collect);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", pan_to_hand);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", play_bonus_pae);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", add_pae);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", add_pae_bomb);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", add_ani);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/animator", D_0002F918);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/animator", start_ani);

int count_ani(void) {
    return ani_cnt;
}
