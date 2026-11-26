#include "common.h"


struct _anon1;
struct _anon1 { /* size 0x28 */
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
typedef struct _anon1 PaeManager;
struct _anon2;
struct _anon2 { /* size 0x38 */
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
typedef struct _anon2 Animator;
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

extern PaeManager paeManager;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern Animator animator;
extern CollectManager collectManager;
extern int g_my_collection_gwang[5];
extern int g_my_collection_mung[9];
extern int g_my_collection_dan[10];
extern int g_my_collection_pi[25];
extern int g_opp_collection_gwang[5];
extern int g_opp_collection_mung[9];
extern int g_opp_collection_dan[10];
extern int g_opp_collection_pi[25];
extern int g_my_lastcollect_pos[5][2];
extern int g_opp_lastcollect_pos[5][2];
extern int g_my_collect_pos[10][2];
extern int g_opp2_collection_gwang[5];
extern int g_opp2_collection_mung[9];
extern int g_opp2_collection_dan[10];
extern int g_opp2_collection_pi[25];
extern int g_opp2_lastcollect_pos[5][2];

int count_array(int *a, int a_size);
int compact_array(int *a, int size);
void get_pae_pos(int pae, int *x, int *y);
void *memset(void *s, int c, unsigned int n);
#define count count_A300
static void set_lastcollect_pos(int flagPlayer, int flagPae, int x, int y);
static void get_lastcollect_pos(int flagPlayer, int flagPae, int *x, int *y);
int count_pi(int flagPlayer, int *danpi, int *ssangpi, int *sampi);
static void add_collect(int flagPlayer, int pae);
void move_collect(int fromPlayer, int toPlayer, int danpi, int ssangpi, int sampi);
/* locals of move_collect:
  int i;
  int jum;
  int p;
  int sx;
  int sy;
  int dx;
  int dy;
  int gap;
  int *from_collection_gwang;
  int *from_collection_mung;
  int *from_collection_dan;
  int *from_collection_pi;
  int *to_collection_gwang;
  int *to_collection_mung;
  int *to_collection_dan;
  int *to_collection_pi;
*/
static void init_collect();
static void take_from(int fromPlayer, int toPlayer, int jum);
static int find_gukjin(int flagPlayer);
static void move_gukjin(int flagPlayer);
static int count(int flagPlayer, int *gwang, int *mung, int *dan, int *pi);
static void count_not_flying(int flagPlayer, int *gwang, int *mung, int *dan, int *pi);
static int count_not_flying_pi(int flagPlayer);
static int count_kind(int flagPlayer, int kind);


static void set_lastcollect_pos(int flagPlayer, int flagPae, int x, int y)
{
	if (flagPlayer == 1) {
		g_opp_lastcollect_pos[flagPae][0] = x;
		g_opp_lastcollect_pos[flagPae][1] = y;
	} else if (flagPlayer == 2) {
		g_opp2_lastcollect_pos[flagPae][0] = x;
		g_opp2_lastcollect_pos[flagPae][1] = y;
	} else {
		g_my_lastcollect_pos[flagPae][0] = x;
		g_my_lastcollect_pos[flagPae][1] = y;
	}
}

__asm__(".globl set_lastcollect_pos");

static void get_lastcollect_pos(int flagPlayer, int flagPae, int *x, int *y)
{
	if (flagPlayer == 1) {
		*x = g_opp_lastcollect_pos[flagPae][0];
		*y = g_opp_lastcollect_pos[flagPae][1];
	} else if (flagPlayer == 2) {
		*x = g_opp2_lastcollect_pos[flagPae][0];
		*y = g_opp2_lastcollect_pos[flagPae][1];
	} else {
		*x = g_my_lastcollect_pos[flagPae][0];
		*y = g_my_lastcollect_pos[flagPae][1];
	}
}

__asm__(".globl get_lastcollect_pos");

int count_pi(int flagPlayer, int *danpi, int *ssangpi, int *sampi)
{
	int i;
	int p;
	int jum;
	int cnt = 0;

	*danpi = 0;
	*ssangpi = 0;
	*sampi = 0;
	if (flagPlayer == 1) {
		for (i = 0; i < 25 && (p = g_opp_collection_pi[i]) != 0; i++) {
			if (p != 33) {
				jum = paeManager.is_pi(p);
				if (jum == 3)
					(*sampi)++;
				else if (jum == 2)
					(*ssangpi)++;
				else
					(*danpi)++;
				cnt++;
			}
		}
	} else if (flagPlayer == 2) {
		for (i = 0; i < 25 && (p = g_opp2_collection_pi[i]) != 0; i++) {
			if (p != 33) {
				jum = paeManager.is_pi(p);
				if (jum == 3)
					(*sampi)++;
				else if (jum == 2)
					(*ssangpi)++;
				else
					(*danpi)++;
				cnt++;
			}
		}
	} else if (flagPlayer == 0) {
		for (i = 0; i < 25 && (p = g_my_collection_pi[i]) != 0; i++) {
			if (p != 33) {
				jum = paeManager.is_pi(p);
				if (jum == 3)
					(*sampi)++;
				else if (jum == 2)
					(*ssangpi)++;
				else
					(*danpi)++;
				cnt++;
			}
		}
	}
	return cnt;
}

static void add_collect(int flagPlayer, int pae)
{
	if (flagPlayer == 1) {
		if (paeManager.is_gwang(pae))
			g_opp_collection_gwang[count_array(g_opp_collection_gwang, 5)] = pae;
		else if (paeManager.is_mung(pae))
			g_opp_collection_mung[count_array(g_opp_collection_mung, 9)] = pae;
		else if (paeManager.is_dan(pae))
			g_opp_collection_dan[count_array(g_opp_collection_dan, 10)] = pae;
		else if (paeManager.is_pi(pae))
			g_opp_collection_pi[count_array(g_opp_collection_pi, 25)] = pae;
	} else if (flagPlayer == 2) {
		if (paeManager.is_gwang(pae))
			g_opp2_collection_gwang[count_array(g_opp2_collection_gwang, 5)] = pae;
		else if (paeManager.is_mung(pae))
			g_opp2_collection_mung[count_array(g_opp2_collection_mung, 9)] = pae;
		else if (paeManager.is_dan(pae))
			g_opp2_collection_dan[count_array(g_opp2_collection_dan, 10)] = pae;
		else if (paeManager.is_pi(pae))
			g_opp2_collection_pi[count_array(g_opp2_collection_pi, 25)] = pae;
	} else if (flagPlayer == 0) {
		if (paeManager.is_gwang(pae))
			g_my_collection_gwang[count_array(g_my_collection_gwang, 5)] = pae;
		else if (paeManager.is_mung(pae))
			g_my_collection_mung[count_array(g_my_collection_mung, 9)] = pae;
		else if (paeManager.is_dan(pae))
			g_my_collection_dan[count_array(g_my_collection_dan, 10)] = pae;
		else if (paeManager.is_pi(pae))
			g_my_collection_pi[count_array(g_my_collection_pi, 25)] = pae;
	}
}

__asm__(".globl add_collect");

void move_collect(int fromPlayer, int toPlayer, int danpi, int ssangpi, int sampi)
{
	int i, jum, p, sx, sy, dx, dy, gap = 0;
	int *from_collection_gwang = 0, *from_collection_mung = 0, *from_collection_dan = 0, *from_collection_pi = 0;
	int *to_collection_gwang = 0, *to_collection_mung = 0, *to_collection_dan = 0, *to_collection_pi = 0;

	switch (fromPlayer) {
	case 0:
		from_collection_gwang = g_my_collection_gwang;
		from_collection_mung = g_my_collection_mung;
		from_collection_dan = g_my_collection_dan;
		from_collection_pi = g_my_collection_pi;
		break;
	case 1:
		from_collection_gwang = g_opp_collection_gwang;
		from_collection_mung = g_opp_collection_mung;
		from_collection_dan = g_opp_collection_dan;
		from_collection_pi = g_opp_collection_pi;
		break;
	case 2:
		from_collection_gwang = g_opp2_collection_gwang;
		from_collection_mung = g_opp2_collection_mung;
		from_collection_dan = g_opp2_collection_dan;
		from_collection_pi = g_opp2_collection_pi;
		break;
	}

	switch (toPlayer) {
	case 0:
		to_collection_gwang = g_my_collection_gwang;
		to_collection_mung = g_my_collection_mung;
		to_collection_dan = g_my_collection_dan;
		to_collection_pi = g_my_collection_pi;
		gap = 4;
		break;
	case 1:
		to_collection_gwang = g_opp_collection_gwang;
		to_collection_mung = g_opp_collection_mung;
		to_collection_dan = g_opp_collection_dan;
		to_collection_pi = g_opp_collection_pi;
		gap = 1;
		break;
	case 2:
		to_collection_gwang = g_opp2_collection_gwang;
		to_collection_mung = g_opp2_collection_mung;
		to_collection_dan = g_opp2_collection_dan;
		to_collection_pi = g_opp2_collection_pi;
		gap = 1;
		break;
	}

	for (i = 0; i < 25 && (p = from_collection_pi[i]) != 0; i++) {
		jum = paeManager.is_pi(p);
		if (jum == 3 && sampi > 0) {
			from_collection_pi[i] = 0;
			add_collect(toPlayer, p);

			get_pae_pos(p, &sx, &sy);
			get_lastcollect_pos(toPlayer, paeManager.get_pae_value(p), &dx, &dy);
			animator.add_pae(p, sx, sy, dx + gap, dy, 0, -1);

			sampi--;
		} else if (jum == 2 && ssangpi > 0 && p != 33) {
			from_collection_pi[i] = 0;
			add_collect(toPlayer, p);

			get_pae_pos(p, &sx, &sy);
			get_lastcollect_pos(toPlayer, paeManager.get_pae_value(p), &dx, &dy);
			animator.add_pae(p, sx, sy, dx + gap, dy, 0, -1);

			ssangpi--;
		} else if (jum == 1 && danpi > 0) {
			from_collection_pi[i] = 0;
			add_collect(toPlayer, p);

			get_pae_pos(p, &sx, &sy);
			get_lastcollect_pos(toPlayer, paeManager.get_pae_value(p), &dx, &dy);
			animator.add_pae(p, sx, sy, dx + gap, dy, 0, -1);

			danpi--;
		}
	}

	compact_array(from_collection_pi, 25);
}


static void init_collect()
{
	int x_start, y_start;

	memset(g_my_collection_gwang, 0, sizeof(g_my_collection_gwang));
	memset(g_my_collection_mung, 0, sizeof(g_my_collection_mung));
	memset(g_my_collection_dan, 0, sizeof(g_my_collection_dan));
	memset(g_my_collection_pi, 0, sizeof(g_my_collection_pi));
	memset(g_opp_collection_gwang, 0, sizeof(g_opp_collection_gwang));
	memset(g_opp_collection_mung, 0, sizeof(g_opp_collection_mung));
	memset(g_opp_collection_dan, 0, sizeof(g_opp_collection_dan));
	memset(g_opp_collection_pi, 0, sizeof(g_opp_collection_pi));
	memset(g_my_lastcollect_pos, 0, sizeof(g_my_lastcollect_pos));
	memset(g_opp_lastcollect_pos, 0, sizeof(g_opp_lastcollect_pos));
	memset(g_opp2_collection_gwang, 0, sizeof(g_opp2_collection_gwang));
	memset(g_opp2_collection_mung, 0, sizeof(g_opp2_collection_mung));
	memset(g_opp2_collection_dan, 0, sizeof(g_opp2_collection_dan));
	memset(g_opp2_collection_pi, 0, sizeof(g_opp2_collection_pi));
	memset(g_opp2_lastcollect_pos, 0, sizeof(g_opp2_lastcollect_pos));

	x_start = 148;
	y_start = 211;
	set_lastcollect_pos(0, 4, x_start, y_start);
	x_start = 216;
	set_lastcollect_pos(0, 3, x_start, y_start);
	y_start = 246;
	set_lastcollect_pos(0, 2, x_start, y_start);
	x_start = 284;
	set_lastcollect_pos(0, 1, x_start, y_start);

	set_lastcollect_pos(1, 4, 186, 36);
	set_lastcollect_pos(1, 3, 239, 2);
	set_lastcollect_pos(1, 2, 239, 36);
	set_lastcollect_pos(1, 1, 292, 36);

	{
		int dx, dy;
		get_lastcollect_pos(0, 4, &dx, &dy);
	}
}

__asm__(".globl init_collect");


static void take_from(int fromPlayer, int toPlayer, int jum)
{
	int danpi;
	int ssangpi;
	int sampi;
	int cnt;
	int sum;

	count_pi(fromPlayer, &danpi, &ssangpi, &sampi);
	sum = danpi + ssangpi * 2 + sampi * 3;
	if (jum >= sum) {
		move_collect(fromPlayer, toPlayer, danpi, ssangpi, sampi);
		return;
	}
	while (jum > 0) {
		if (jum >= 3 && sampi > 0) {
			move_collect(fromPlayer, toPlayer, 0, 0, 1);
			jum -= 3;
			sampi--;
		} else if (jum >= 2 && ssangpi > 0) {
			move_collect(fromPlayer, toPlayer, 0, 1, 0);
			jum -= 2;
			ssangpi--;
		} else if (jum >= 1 && danpi > 0) {
			move_collect(fromPlayer, toPlayer, 1, 0, 0);
			jum -= 1;
			danpi--;
		} else if (ssangpi > 0) {
			move_collect(fromPlayer, toPlayer, 0, 1, 0);
			jum -= 2;
			ssangpi--;
		} else if (sampi > 0) {
			move_collect(fromPlayer, toPlayer, 0, 0, 1);
			jum -= 3;
			sampi--;
		} else
			break;
	}
}

__asm__(".globl take_from");

static int find_gukjin(int flagPlayer)
{
	int i;

	if (flagPlayer == 1) {
		for (i = 0; i < 9; i++)
			if (g_opp_collection_mung[i] == 33)
				return 1;
	} else if (flagPlayer == 2) {
		for (i = 0; i < 9; i++)
			if (g_opp2_collection_mung[i] == 33)
				return 1;
	} else {
		for (i = 0; i < 9; i++)
			if (g_my_collection_mung[i] == 33)
				return 1;
	}
	return 0;
}

__asm__(".globl find_gukjin");

static void move_gukjin(int flagPlayer)
{
	int i;

	if (flagPlayer == 1) {
		for (i = 0; i < 9; i++) {
			if (g_opp_collection_mung[i] == 33) {
				g_opp_collection_mung[i] = 0;
				g_opp_collection_pi[count_array(g_opp_collection_pi, 25)] = 33;
				compact_array(g_opp_collection_mung, 9);
				return;
			}
		}
	} else if (flagPlayer == 2) {
		for (i = 0; i < 9; i++) {
			if (g_opp2_collection_mung[i] == 33) {
				g_opp2_collection_mung[i] = 0;
				g_opp2_collection_pi[count_array(g_opp2_collection_pi, 25)] = 33;
				compact_array(g_opp2_collection_mung, 9);
				return;
			}
		}
	} else {
		for (i = 0; i < 9; i++) {
			if (g_my_collection_mung[i] == 33) {
				g_my_collection_mung[i] = 0;
				g_my_collection_pi[count_array(g_my_collection_pi, 25)] = 33;
				compact_array(g_my_collection_mung, 9);
				return;
			}
		}
	}
}

__asm__(".globl move_gukjin");

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/collect", count_A300);

static void count_not_flying(int flagPlayer, int *gwang, int *mung, int *dan, int *pi)
{
	int i;
	int cnt = 0;
	int p;

	if (flagPlayer == 1) {
		if (gwang) {
			for (i = 0; i < 5; i++) {
				p = g_opp_collection_gwang[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*gwang = cnt;
		}
		if (mung) {
			cnt = 0;
			for (i = 0; i < 9; i++) {
				p = g_opp_collection_mung[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*mung = cnt;
		}
		if (dan) {
			cnt = 0;
			for (i = 0; i < 10; i++) {
				p = g_opp_collection_dan[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*dan = cnt;
		}
		if (pi) {
			cnt = 0;
			for (i = 0; i < 25; i++) {
				p = g_opp_collection_pi[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*pi = cnt;
		}
	} else if (flagPlayer == 2) {
		if (gwang) {
			for (i = 0; i < 5; i++) {
				p = g_opp2_collection_gwang[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*gwang = cnt;
		}
		if (mung) {
			cnt = 0;
			for (i = 0; i < 9; i++) {
				p = g_opp2_collection_mung[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*mung = cnt;
		}
		if (dan) {
			cnt = 0;
			for (i = 0; i < 10; i++) {
				p = g_opp2_collection_dan[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*dan = cnt;
		}
		if (pi) {
			cnt = 0;
			for (i = 0; i < 25; i++) {
				p = g_opp2_collection_pi[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*pi = cnt;
		}
	} else {
		if (gwang) {
			for (i = 0; i < 5; i++) {
				p = g_my_collection_gwang[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*gwang = cnt;
		}
		if (mung) {
			cnt = 0;
			for (i = 0; i < 9; i++) {
				p = g_my_collection_mung[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*mung = cnt;
		}
		if (dan) {
			cnt = 0;
			for (i = 0; i < 10; i++) {
				p = g_my_collection_dan[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*dan = cnt;
		}
		if (pi) {
			cnt = 0;
			for (i = 0; i < 25; i++) {
				p = g_my_collection_pi[i];
				if (p > 0 && !animator.is_flying(p))
					cnt++;
			}
			*pi = cnt;
		}
	}
}

__asm__(".globl count_not_flying");

static int count_not_flying_pi(int flagPlayer)
{
	int cnt = 0;
	int p;
	int i;

	if (flagPlayer == 1) {
		for (i = 0; i < 25; i++) {
			p = g_opp_collection_pi[i];
			if (p > 0 && !animator.is_flying(p))
				cnt += paeManager.is_pi(p);
		}
	} else if (flagPlayer == 2) {
		for (i = 0; i < 25; i++) {
			p = g_opp2_collection_pi[i];
			if (p > 0 && !animator.is_flying(p))
				cnt += paeManager.is_pi(p);
		}
	} else {
		for (i = 0; i < 25; i++) {
			p = g_my_collection_pi[i];
			if (p > 0 && !animator.is_flying(p))
				cnt += paeManager.is_pi(p);
		}
	}
	return cnt;
}

__asm__(".globl count_not_flying_pi");

static int count_kind(int flagPlayer, int kind)
{
	int i;
	int p;
	int cnt = 0;

	if (flagPlayer == 1) {
		for (i = 0; i < 5 && (p = g_opp_collection_gwang[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
		for (i = 0; i < 9 && (p = g_opp_collection_mung[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
		for (i = 0; i < 10 && (p = g_opp_collection_dan[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
		for (i = 0; i < 25 && (p = g_opp_collection_pi[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
	} else if (flagPlayer == 2) {
		for (i = 0; i < 5 && (p = g_opp2_collection_gwang[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
		for (i = 0; i < 9 && (p = g_opp2_collection_mung[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
		for (i = 0; i < 10 && (p = g_opp2_collection_dan[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
		for (i = 0; i < 25 && (p = g_opp2_collection_pi[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
	} else if (flagPlayer == 0) {
		for (i = 0; i < 5 && (p = g_my_collection_gwang[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
		for (i = 0; i < 9 && (p = g_my_collection_mung[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
		for (i = 0; i < 10 && (p = g_my_collection_dan[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
		for (i = 0; i < 25 && (p = g_my_collection_pi[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
	}
	return cnt;
}

__asm__(".globl count_kind");
