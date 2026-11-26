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
typedef struct _PAN PanManager;
struct _PAN;
struct _anon2;
struct _anon2 { /* size 0x8 */
    int x;
    int y;
};
typedef struct _anon2 Point;
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

extern PaeManager paeManager;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern int g_my_collection_gwang[5];
extern int g_my_collection_mung[9];
extern int g_my_collection_dan[10];
extern int g_my_collection_pi[25];
extern int g_opp_collection_gwang[5];
extern int g_opp_collection_mung[9];
extern int g_opp_collection_dan[10];
extern int g_opp_collection_pi[25];
extern PanManager panManager;
extern HandManager handManager;
extern int g_my_hand[10];
extern int g_opp_hand[2][10];

static void init_hand(void);
static int count_hand(int flagPlayer);
static int count_hand_kind(int flagPlayer, int kind);
static int get_first_kind_hand(int flagPlayer, int kind, int *index, int *pae);
static int get_kind_hand(int flagPlayer, int kind, int *ps);
static void sort_hand(int flagPlayer);
static int is_fixed(int flagPlayer, int kind);
static void add_hand(int flagPlayer, int pae);
static int get_pae(int flagPlayer, int pos);
static void remove_pae(int flagPlayer, int pos);
static int check_chongtong(int player);
int compact_array(int *a, int size);
void quick_sort(int *arr, int ilo, int ihi);

#define get_pae get_pae_936C
#define check_chongtong check_chongtong_9450

static void init_hand(void)
{
	memset(g_my_hand, 0, sizeof(g_my_hand));
	memset(g_opp_hand[0], 0, sizeof(g_opp_hand[0]));
	memset(g_opp_hand[1], 0, sizeof(g_opp_hand[1]));
}

__asm__(".globl init_hand");

static int count_hand(int flagPlayer)
{
	int i;
	int cnt = 0;

	if (flagPlayer == 1) {
		for (i = 0; i < 10; i++)
			if (g_opp_hand[0][i] > 0)
				cnt++;
	} else if (flagPlayer == 2) {
		for (i = 0; i < 10; i++)
			if (g_opp_hand[1][i] > 0)
				cnt++;
	} else if (flagPlayer == 0) {
		for (i = 0; i < 10; i++)
			if (g_my_hand[i] > 0)
				cnt++;
	}
	return cnt;
}

__asm__(".globl count_hand");

static int count_hand_kind(int flagPlayer, int kind)
{
	int i;
	int p;
	int cnt = 0;

	if (flagPlayer == 1) {
		for (i = 0; i < 10 && (p = g_opp_hand[0][i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
	} else if (flagPlayer == 2) {
		for (i = 0; i < 10 && (p = g_opp_hand[1][i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
	} else if (flagPlayer == 0) {
		for (i = 0; i < 10 && (p = g_my_hand[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				cnt++;
	}
	return cnt;
}

__asm__(".globl count_hand_kind");

static int get_first_kind_hand(int flagPlayer, int kind, int *index, int *pae)
{
	int i;
	int p;

	*index = 0;
	*pae = 0;
	if (flagPlayer == 1) {
		for (i = 0; i < 10 && (p = g_opp_hand[0][i]) != 0; i++) {
			if (kind == paeManager.get_pae_kind(p)) {
				*index = i;
				*pae = p;
				return 1;
			}
		}
	} else if (flagPlayer == 2) {
		for (i = 0; i < 10 && (p = g_opp_hand[1][i]) != 0; i++) {
			if (kind == paeManager.get_pae_kind(p)) {
				*index = i;
				*pae = p;
				return 1;
			}
		}
	} else if (flagPlayer == 0) {
		for (i = 0; i < 10 && (p = g_my_hand[i]) != 0; i++) {
			if (kind == paeManager.get_pae_kind(p)) {
				*index = i;
				*pae = p;
				return 1;
			}
		}
	}
	return 0;
}

__asm__(".globl get_first_kind_hand");

static int get_kind_hand(int flagPlayer, int kind, int *ps)
{
	int i;
	int p;
	int n = 0;

	ps[0] = 0;
	ps[1] = 0;
	ps[2] = 0;
	ps[3] = 0;
	if (flagPlayer == 1) {
		for (i = 0; i < 10 && (p = g_opp_hand[0][i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				ps[n++] = p;
	} else if (flagPlayer == 2) {
		for (i = 0; i < 10 && (p = g_opp_hand[1][i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				ps[n++] = p;
	} else if (flagPlayer == 0) {
		for (i = 0; i < 10 && (p = g_my_hand[i]) != 0; i++)
			if (kind == paeManager.get_pae_kind(p))
				ps[n++] = p;
	}
	return n;
}

__asm__(".globl get_kind_hand");

static void sort_hand(int flagPlayer)
{
	int pos;

	pos = count_hand(flagPlayer) - 1;
	if (flagPlayer == 1)
		quick_sort(g_opp_hand[0], 0, pos);
	else if (flagPlayer == 2)
		quick_sort(g_opp_hand[1], 0, pos);
	else
		quick_sort(g_my_hand, 0, pos);
}

__asm__(".globl sort_hand");

static int is_fixed(int flagPlayer, int kind)
{
	int i;
	int p;
	int cnt1;
	int cnt2 = 0;
	int cnt3;

	cnt1 = panManager.count_kind(kind);
	if (kind >= 13)
		return 0;
	for (i = 0; i < 5 && (p = g_my_collection_gwang[i]) != 0; i++)
		if (kind == paeManager.get_pae_kind(p))
			cnt2++;
	for (i = 0; i < 9 && (p = g_my_collection_mung[i]) != 0; i++)
		if (kind == paeManager.get_pae_kind(p))
			cnt2++;
	for (i = 0; i < 10 && (p = g_my_collection_dan[i]) != 0; i++)
		if (kind == paeManager.get_pae_kind(p))
			cnt2++;
	for (i = 0; i < 25 && (p = g_my_collection_pi[i]) != 0; i++)
		if (kind == paeManager.get_pae_kind(p))
			cnt2++;
	for (i = 0; i < 5 && (p = g_opp_collection_gwang[i]) != 0; i++)
		if (kind == paeManager.get_pae_kind(p))
			cnt2++;
	for (i = 0; i < 9 && (p = g_opp_collection_mung[i]) != 0; i++)
		if (kind == paeManager.get_pae_kind(p))
			cnt2++;
	for (i = 0; i < 10 && (p = g_opp_collection_dan[i]) != 0; i++)
		if (kind == paeManager.get_pae_kind(p))
			cnt2++;
	for (i = 0; i < 25 && (p = g_opp_collection_pi[i]) != 0; i++)
		if (kind == paeManager.get_pae_kind(p))
			cnt2++;
	cnt3 = count_hand_kind(flagPlayer, kind);
	if (cnt1 != 0 || cnt3 == 4) {
		if (cnt3 == 4 || cnt1 + cnt2 + cnt3 == 4)
			return 2;
		return 1;
	}
	return 0;
}

__asm__(".globl is_fixed");

static void add_hand(int flagPlayer, int pae)
{
	if (flagPlayer == 1)
		g_opp_hand[0][count_hand(1)] = pae;
	else if (flagPlayer == 2)
		g_opp_hand[1][count_hand(2)] = pae;
	else
		g_my_hand[count_hand(0)] = pae;
}

__asm__(".globl add_hand");

static int get_pae(int flagPlayer, int pos)
{
	if (flagPlayer == 1)
		return g_opp_hand[0][pos];
	else if (flagPlayer == 2)
		return g_opp_hand[1][pos];
	return g_my_hand[pos];
}

__asm__(".globl get_pae_936C");

static void remove_pae(int flagPlayer, int pos)
{
	if (flagPlayer == 1) {
		g_opp_hand[0][pos] = 0;
		compact_array(g_opp_hand[0], 10);
	} else if (flagPlayer == 2) {
		g_opp_hand[1][pos] = 0;
		compact_array(g_opp_hand[1], 10);
	} else {
		g_my_hand[pos] = 0;
		compact_array(g_my_hand, 10);
	}
}

__asm__(".globl remove_pae");

static int check_chongtong(int player)
{
	int index;
	int array_kind[13] = { 0 };
	int pae, kind;

	for (index = 0; index < 10 && (pae = get_pae(player, index)) != 0; index++) {
		kind = paeManager.get_pae_kind(pae);
		if (kind >= 1 && kind <= 12) {
			array_kind[kind]++;
			if (array_kind[kind] == 4)
				return kind;
		}
	}
	return 0;
}

__asm__(".globl check_chongtong_9450");
