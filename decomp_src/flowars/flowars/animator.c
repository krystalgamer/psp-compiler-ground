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
void sceKernelSetGPO(unsigned char gpo);
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



void getResizedPostion(Point *pt, int pae_set, float xsize, float ysize)
{
	int pae_width, pae_height;

	if (pae_set == 1) {
		pae_width = 36;
		pae_height = 57;
	} else if (pae_set == 2) {
		pae_width = 36;
		pae_height = 57;
	} else {
		pae_width = 16;
		pae_height = 26;
	}

	pt->x = pt->x - pae_width * (xsize - 1.0) * 0.5;
	pt->y = pt->y - pae_height * (ysize - 1.0) * 0.5;
	{
		int xlimit = 480 - pae_width * xsize;
		int ylimit = 272 - pae_height * ysize;

		if (pt->x < 0) pt->x = 0;
		if (pt->x > xlimit) pt->x = xlimit;
		if (pt->y < 0) pt->y = 0;
		if (pt->y > ylimit) pt->y = ylimit;
	}
}


static void me_to_pan()
{
	float distance;
	Point pt;
	int pae;
	int i, frame;
	float xsize, ysize;

	float speed = 25.0f;

	for (i = 0; i < anipae_cnt && paeParam[i].pae > 0; i++) {

		frame = paeParam[i].frame;
		if (frame < paeParam[i].delay)
			frame = 0;
		else
			frame -= paeParam[i].delay;

		if (frame < 4) {
			pae = 52;
			xsize = 1.5 - frame * 1.5 * 0.25;
			ysize = 1.5f;
			pt.x = paeParam[i].src.x;
			pt.y = paeParam[i].src.y;
		} else if (frame < 8) {
			pae = paeParam[i].pae;
			xsize = (frame - 4) * 1.5 * 0.25;
			ysize = 1.5f;
			pt.x = paeParam[i].src.x;
			pt.y = paeParam[i].src.y;
		} else if (frame < 16) {
			pae = paeParam[i].pae;
			xsize = ysize = 1.5f;
			pt.x = paeParam[i].src.x;
			pt.y = paeParam[i].src.y;
		} else {
			pae = paeParam[i].pae;
			distance = getCurrentPoint(&pt, &paeParam[i], speed, 16);

			if (paeParam[i].distance - speed <= distance) {
				pt.x = paeParam[i].dst.x;
				pt.y = paeParam[i].dst.y;
				xsize = ysize = 1.0f;

				if (paeParam[i].status == 1) {
					paeParam[i].status = 0;
					moving_pae--;
					if (paeParam[i].sound != -1)
						soundUtil.play(paeParam[i].sound, 127);
				}
			} else {
				xsize = ysize = 1.5 - (frame - 10) * 0.1;
				if (xsize < 1.0)
					xsize = 1.0f;
				if (ysize < 1.0)
					ysize = 1.0f;
			}
		}

		if (xsize >= 1.5 && ysize >= 1.5) {
			getResizedPostion(&pt, 1, xsize / 1.5, ysize / 1.5);
			graphics.draw_flying_pae2(pae, pt.x, pt.y, xsize / 1.5, ysize / 1.5, 1);
		} else {
			getResizedPostion(&pt, 2, xsize, ysize);
			graphics.draw_flying_pae2(pae, pt.x, pt.y, xsize, ysize, 2);
		}

		paeParam[i].frame++;
	}

	if (moving_pae <= 0) {
		clear_animation();
		g_delay = 700;
	}
}

__asm__(".globl me_to_pan");


static void me_to_bomb()
{
	float distance;
	Point pt;
	int pae;
	int i, frame;
	float xsize, ysize;

	float speed = 25.0f;

	for (i = 0; i < anipae_cnt && paeParam[i].pae > 0; i++) {

		frame = paeParam[i].frame;
		if (frame < paeParam[i].delay)
			frame = 0;
		else
			frame -= paeParam[i].delay;

		if (frame < 12) {
			pae = paeParam[i].pae;
			xsize = ysize = 1.5f;
			pt.x = paeParam[i].src.x + i * 10 - 10;
			pt.y = paeParam[i].src.y;
		} else {
			pae = paeParam[i].pae;
			distance = getCurrentPoint(&pt, &paeParam[i], speed, 12);

			if (paeParam[i].distance - speed <= distance) {
				pt.x = paeParam[i].dst.x;
				pt.y = paeParam[i].dst.y;
				xsize = ysize = 1.0f;

				if (paeParam[i].status == 1) {
					paeParam[i].status = 0;
					moving_pae--;
					if (paeParam[i].sound != -1)
						soundUtil.play(paeParam[i].sound, 127);
				}
			} else {
				xsize = ysize = 1.5 - (frame - 10) * 0.1;
				if (xsize < 1.0)
					xsize = 1.0f;
				if (ysize < 1.0)
					ysize = 1.0f;
			}
		}

		if (xsize >= 1.5 && ysize >= 1.5) {
			getResizedPostion(&pt, 1, xsize / 1.5, ysize / 1.5);
			graphics.draw_flying_pae2(pae, pt.x, pt.y, xsize / 1.5, ysize / 1.5, 1);
		} else {
			getResizedPostion(&pt, 2, xsize, ysize);
			graphics.draw_flying_pae2(pae, pt.x, pt.y, xsize, ysize, 2);
		}

		paeParam[i].frame++;
	}

	if (moving_pae <= 0) {
		clear_animation();
		g_delay = 1200;
	}
}

__asm__(".globl me_to_bomb");


static void pan_to_collect()
{
	float distance;
	Point pt;
	int frame;

	int i;

	float speed = 20.0f;

	for (i = 0; i < anipae_cnt && paeParam[i].pae > 0; i++) {
		frame = paeParam[i].frame;
		if (frame < paeParam[i].delay)
			frame = 0;
		else
			frame -= paeParam[i].delay;

		if (frame < 2) {


			pt.x = paeParam[i].src.x;
			pt.y = paeParam[i].src.y;

			graphics.draw_flying_pae2(paeParam[i].pae, pt.x, pt.y, 1.0f, 1.0f, 2);
		} else {
			distance = getCurrentPoint(&pt, &paeParam[i], speed, 1);

			if (paeParam[i].distance - speed - 10.0f <= distance) {
				pt.x = paeParam[i].dst.x;
				pt.y = paeParam[i].dst.y;

				if (paeParam[i].status == 1) {
					paeParam[i].status = 0;
					moving_pae--;
					if (paeParam[i].sound != -1)
						soundUtil.play(paeParam[i].sound, 127);
				}
			}
			graphics.draw_flying_pae2(paeParam[i].pae, pt.x, pt.y, 1.0f, 1.0f, 3);
		}

		paeParam[i].frame++;
	}

	if (moving_pae <= 0) {
		clear_animation();
	}
}

__asm__(".globl pan_to_collect");


static void collect_to_collect()
{
	float distance;
	Point pt;
	int i;

	float speed = 15.0f;

	for (i = 0; i < anipae_cnt && paeParam[i].pae > 0; i++) {
		if (paeParam[i].frame < 2) {
			pt.x = paeParam[i].src.x;
			pt.y = paeParam[i].src.y;
		} else {
			distance = getCurrentPoint(&pt, &paeParam[i], speed, 1);

			if (paeParam[i].distance - speed <= distance) {
				pt.x = paeParam[i].dst.x;
				pt.y = paeParam[i].dst.y;

				if (paeParam[i].status == 1) {
					paeParam[i].status = 0;
					moving_pae--;
					if (paeParam[i].sound != -1)
						soundUtil.play(paeParam[i].sound, 127);
				}
			}
		}
		graphics.draw_flying_pae2(paeParam[i].pae, pt.x, pt.y, 1.0f, 1.0f, 3);
		paeParam[i].frame++;
	}

	if (moving_pae <= 0) {
		clear_animation();
	}
}

__asm__(".globl collect_to_collect");


static void pan_to_hand()
{
	float distance;
	Point pt;
	int frame;
	int i;

	float speed = 20.0f;

	for (i = 0; i < anipae_cnt && paeParam[i].pae > 0; i++) {
		frame = paeParam[i].frame;

		if (frame < 2) {
			pt.x = paeParam[i].src.x;
			pt.y = paeParam[i].src.y;

			graphics.draw_flying_pae2(paeParam[i].pae, pt.x, pt.y, 1.0f, 1.0f, 2);
		} else {
			if (g_player_index != g_turn) {
				distance = getCurrentPoint(&pt, &paeParam[i], speed, 1);

				if (paeParam[i].distance - speed <= distance) {
					pt.x = paeParam[i].dst.x;
					pt.y = paeParam[i].dst.y;

					if (paeParam[i].status == 1) {
						paeParam[i].status = 0;
						moving_pae--;
						if (paeParam[i].sound != -1)
							soundUtil.play(paeParam[i].sound, 127);
					}
				}
				graphics.draw_flying_pae2(paeParam[i].pae, pt.x, pt.y, 1.0f, 1.0f, 3);
			} else {
				distance = getCurrentPoint(&pt, &paeParam[i], speed, 1);

				if (paeParam[i].distance - speed <= distance) {
					pt.x = paeParam[i].dst.x;
					pt.y = paeParam[i].dst.y;

					if (paeParam[i].status == 1) {
						paeParam[i].status = 0;
						moving_pae--;
						if (paeParam[i].sound != -1)
							soundUtil.play(paeParam[i].sound, 127);
					}
				}
				graphics.draw_flying_pae2(paeParam[i].pae, pt.x, pt.y, 1.0f, 1.0f, 2);
			}
		}

		paeParam[i].frame++;
	}

	if (moving_pae <= 0) {
		clear_animation();
	}
}

__asm__(".globl pan_to_hand");


static void play_bonus_pae()
{
	float distance;
	Point pt;
	int frame;
	float xsize, ysize;
	int i, pae;

	float speed = 20.0f;

	for (i = 0; i < anipae_cnt && paeParam[i].pae > 0; i++) {
		frame = paeParam[i].frame;
		if (frame < paeParam[i].delay)
			frame = 0;
		else
			frame -= paeParam[i].delay;

		if (paeParam[i].pae == 49 || paeParam[i].pae == 50) {
			if (frame < 2) {
				pt.x = paeParam[i].src.x;
				pt.y = paeParam[i].src.y;

				graphics.draw_flying_pae2(paeParam[i].pae, pt.x, pt.y, 1.0f, 1.0f, 2);
			} else {
				distance = getCurrentPoint(&pt, &paeParam[i], speed, 1);

				if (paeParam[i].distance - speed <= distance) {
					pt.x = paeParam[i].dst.x;
					pt.y = paeParam[i].dst.y;

					if (paeParam[i].status == 1) {
						paeParam[i].status = 0;
						moving_pae--;
						if (paeParam[i].sound != -1)
							soundUtil.play(paeParam[i].sound, 127);
					}
				}
				graphics.draw_flying_pae2(paeParam[i].pae, pt.x, pt.y, 1.0f, 1.0f, 3);
			}
		} else {
			if (frame < 4) {
				pae = 52;
				xsize = 1.5 - frame * 1.5 * 0.25;
				ysize = 1.5f;
				pt.x = paeParam[i].src.x;
				pt.y = paeParam[i].src.y;
			} else if (frame < 8) {
				pae = paeParam[i].pae;
				xsize = (frame - 4) * 1.5 * 0.25;
				ysize = 1.5f;
				pt.x = paeParam[i].src.x;
				pt.y = paeParam[i].src.y;
			} else if (frame < 16) {
				pae = paeParam[i].pae;
				xsize = ysize = 1.5f;
				pt.x = paeParam[i].src.x;
				pt.y = paeParam[i].src.y;
			} else {
				pae = paeParam[i].pae;
				distance = getCurrentPoint(&pt, &paeParam[i], speed, 16);

				if (paeParam[i].distance - speed <= distance) {
					pt.x = paeParam[i].dst.x;
					pt.y = paeParam[i].dst.y;
					xsize = ysize = 1.0f;

					if (paeParam[i].status == 1) {
						paeParam[i].status = 0;
						moving_pae--;
						if (paeParam[i].sound != -1)
							soundUtil.play(paeParam[i].sound, 127);
					}
				} else {
					xsize = ysize = 1.5 - (frame - 10) * 0.1;
					if (xsize < 1.0)
						xsize = 1.0f;
					if (ysize < 1.0)
						ysize = 1.0f;
				}
			}

			if (xsize >= 1.5 && ysize >= 1.5) {
				getResizedPostion(&pt, 1, xsize / 1.5, ysize / 1.5);
				graphics.draw_flying_pae2(pae, pt.x, pt.y, xsize / 1.5, ysize / 1.5, 1);
			} else {
				getResizedPostion(&pt, 2, xsize, ysize);
				graphics.draw_flying_pae2(pae, pt.x, pt.y, xsize, ysize, 2);
			}
		}

		paeParam[i].frame++;
	}

	if (moving_pae <= 0) {
		clear_animation();
	}
}

__asm__(".globl play_bonus_pae");


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

static void start_ani()
{
	int i, continued = 0;
	AniParam *p;
	int drawing = 0;

	for (i = 0; i <= ani_cnt; i++) {
		p = &aniParam[i];
		if (p->status == 1) {
			continued = 1;
			break;
		}
	}

	if (continued) {
		if (p->sound != -1) {
			if (p->sound == 49)
				soundUtil.play(19, 127);
			else if (p->sound == 50 || p->sound == 45 || p->sound == 46)
				soundUtil.play(23, 127);

			soundUtil.play(p->sound, 127);
			p->sound = -1;
		}

		sceKernelSetGPO(1);
		g_delay = 5000;

		if (p->ani != 99) {
			drawing = graphics.draw_animation(p->ani, p->x, p->y, p->flag_loop);

			if (((p->ani == 13 || p->ani == 14) || p->ani == 11) && g_take_don) {
				char strMoney[12] = "";
				if (g_take_don > 0)
					sprintf(strMoney, "+%d", g_take_don);
				else
					sprintf(strMoney, "%d", g_take_don);

				graphics.draw_number2(strMoney, p->x + 50, p->y + (p->ani == 11 ? 164 : 105), 0, 6, 2);
			}
		}

		if (!drawing) {
			sceKernelSetGPO(3);
			ani_frame++;
		}

		if (ani_frame >= p->extand_frame) {
			sceKernelSetGPO(1);
			p->status = 0;
			ani_rest--;
			ani_frame = 0;
			if (p->ani != 99)
				graphics.init_animation(p->ani);
		}
	} else {
		sceKernelSetGPO(0);
	}

	if (ani_rest <= 0) {
		g_delay = 0;
		ani_cnt = 0;
		g_take_don = 0;
		memset(aniParam, 0, 0x118);
	}
}

__asm__(".globl start_ani");





int count_ani(void) {
    return ani_cnt;
}
