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
double pow(double x, double y);
double sqrt(double x);
static void start_ani();

/* SDK functions (tools/sdk_protos.h) */
void *memset(void *s, int c, unsigned int n);


static int is_flying(int pae)
{
	int i;

	for (i = 0; i < anipae_cnt; i++)
		if (paeParam[i].pae == pae && paeParam[i].status == 1)
			return 1;
	return 0;
}

__asm__(".globl is_flying");

void init_animator(void) {
    memset(paeParam, 0, 0x180U);
    moving_pae = 0;
    anipae_cnt = 0;
    memset(aniParam, 0, 0x118U);
    ani_cnt = 0;
    ani_rest = 0;
    ani_frame = 0;
}

void clear_animation(void) {
    g_delay = 0;
    init_animator();
}

float getCurrentPoint(Point *pt, PaeMoveParam *pp, float speed, int skipFrames)
{
	float cdist;
	float cratio;

	cdist = speed * (pp->frame - skipFrames);
	cratio = 0;

	if (pp->distance == 0) {
		pt->x = pp->src.x;
		pt->y = pp->src.y;
	} else {
		cratio = cdist / pp->distance;
		pt->x = pp->src.x + cratio * pp->move.x;
		pt->y = pp->src.y + cratio * pp->move.y;
	}
	return cdist;
}

/* rodata of the asm functions, in the sections C puts them in: doubles .rodata.cst8, floats
   .rodata.cst4 (asm_cst4/ copies), start_ani's strings after them (this object's section order) */
__asm__(".pushsection .rodata.cst8,\"aM\",@progbits,8\n"
	"\t.align 3\n"
	".globl D_0002F858\nD_0002F858:\n\t.word 0x00000000\n"
	".globl D_0002F85C\nD_0002F85C:\n\t.word 0x3FF00000\n"
	".globl D_0002F860\nD_0002F860:\n\t.word 0x00000000\n"
	".globl D_0002F864\nD_0002F864:\n\t.word 0x3FE00000\n"
	".globl D_0002F868\nD_0002F868:\n\t.word 0x00000000\n"
	".globl D_0002F86C\nD_0002F86C:\n\t.word 0x3FF80000\n"
	".globl D_0002F870\nD_0002F870:\n\t.word 0x00000000\n"
	".globl D_0002F874\nD_0002F874:\n\t.word 0x3FD00000\n"
	".globl D_0002F878\nD_0002F878:\n\t.word 0x9999999A\n"
	".globl D_0002F87C\nD_0002F87C:\n\t.word 0x3FB99999\n"
	".globl D_0002F880\nD_0002F880:\n\t.word 0x00000000\n"
	".globl D_0002F884\nD_0002F884:\n\t.word 0x3FF00000\n"
	".globl D_0002F888\nD_0002F888:\n\t.word 0x9999999A\n"
	".globl D_0002F88C\nD_0002F88C:\n\t.word 0x3FB99999\n"
	".globl D_0002F890\nD_0002F890:\n\t.word 0x00000000\n"
	".globl D_0002F894\nD_0002F894:\n\t.word 0x3FF80000\n"
	".globl D_0002F898\nD_0002F898:\n\t.word 0x00000000\n"
	".globl D_0002F89C\nD_0002F89C:\n\t.word 0x3FF00000\n"
	".globl D_0002F8A0\nD_0002F8A0:\n\t.word 0x00000000\n"
	".globl D_0002F8A4\nD_0002F8A4:\n\t.word 0x3FF80000\n"
	".globl D_0002F8A8\nD_0002F8A8:\n\t.word 0x00000000\n"
	".globl D_0002F8AC\nD_0002F8AC:\n\t.word 0x3FD00000\n"
	".globl D_0002F8B0\nD_0002F8B0:\n\t.word 0x9999999A\n"
	".globl D_0002F8B4\nD_0002F8B4:\n\t.word 0x3FB99999\n"
	".globl D_0002F8B8\nD_0002F8B8:\n\t.word 0x00000000\n"
	".globl D_0002F8BC\nD_0002F8BC:\n\t.word 0x3FF00000\n"
	"\t.popsection");

INCLUDE_ASM("decomp_src/flowars/flowars/asm_cst4", getResizedPostion);

INCLUDE_ASM("decomp_src/flowars/flowars/asm_cst4", me_to_pan);

INCLUDE_ASM("decomp_src/flowars/flowars/asm_cst4", me_to_bomb);

INCLUDE_ASM("decomp_src/flowars/flowars/asm_cst4", pan_to_collect);

INCLUDE_ASM("decomp_src/flowars/flowars/asm_cst4", collect_to_collect);

INCLUDE_ASM("decomp_src/flowars/flowars/asm_cst4", pan_to_hand);

INCLUDE_ASM("decomp_src/flowars/flowars/asm_cst4", play_bonus_pae);

static void add_pae(int pae, int sx, int sy, int dx, int dy, int delay, int sound)
{
	PaeMoveParam *p;

	p = &paeParam[anipae_cnt];
	p->pae = pae;
	p->status = 1;
	p->frame = 0;
	p->delay = delay;
	p->src.x = sx;
	p->src.y = sy;
	p->dst.x = dx;
	p->dst.y = dy;
	p->move.x = dx - sx;
	p->move.y = dy - sy;
	if (p->move.x > 480)
		p->move.x = 480;
	if (p->move.y > 272)
		p->move.y = 272;
	p->distance = sqrt(pow(p->move.x, 2) + pow(p->move.y, 2));
	p->sound = sound;
	anipae_cnt++;
	moving_pae++;
}

__asm__(".globl add_pae");

static void add_pae_bomb(int pae, int sx, int sy, int dx, int dy, int delay, int sound)
{
	PaeMoveParam *p;

	p = &paeParam[anipae_cnt];
	p->pae = pae;
	p->status = 1;
	p->frame = 0;
	if (anipae_cnt > 0) {
		sx = paeParam[anipae_cnt - 1].src.x + 10;
		sy = paeParam[anipae_cnt - 1].src.y;
	}
	p->delay = delay;
	p->src.x = sx;
	p->src.y = sy;
	p->dst.x = dx;
	p->dst.y = dy;
	p->move.x = dx - sx;
	p->move.y = dy - sy;
	if (p->move.x > 480)
		p->move.x = 480;
	if (p->move.y > 272)
		p->move.y = 272;
	p->distance = sqrt(pow(p->move.x, 2) + pow(p->move.y, 2));
	p->sound = sound;
	anipae_cnt++;
	moving_pae++;
}

__asm__(".globl add_pae_bomb");

static void add_ani(int ani, int x, int y, int flag_loop, int extand_frame, int sound)
{
	AniParam *p;

	p = &aniParam[ani_cnt];
	p->ani = ani;
	p->x = x;
	p->y = y;
	p->status = 1;
	p->sound = sound;
	p->flag_loop = flag_loop;
	p->extand_frame = extand_frame;
	ani_cnt++;
	ani_rest++;
}

__asm__(".globl add_ani");

__asm__(".pushsection .rodata.str,\"a\",@progbits\n\t.align 2\n.globl D_0002F918\nD_0002F918:\n\t.space 12\n\t.popsection");
INCLUDE_ASM("decomp_src/flowars/flowars/asm_cst4", start_ani);

int count_ani(void) {
    return ani_cnt;
}
