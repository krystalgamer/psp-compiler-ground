#include "common.h"


/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x44 */
    int ogwang[5];
    int godori[3];
    int hongdan[3];
    int chungdan[3];
    int chodan[3];
};
typedef struct _anon1 SpecialPae;
struct _anon2;
struct _anon2 { /* size 0x28 */
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
typedef struct _anon2 PaeManager;
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
typedef struct _PAN PanManager;
struct _PAN;
struct _anon3;
struct _anon3 { /* size 0x8 */
    int x;
    int y;
};
typedef struct _anon3 Point;
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
struct _anon4;
struct _anon4 { /* size 0x4 */
    int user_level;
};
typedef struct _anon4 UserInfo;
struct _anon5;
struct _anon5 { /* size 0x14 */
    void (*init)(void);
    void (*set_sp_status)(int, int, int);
    int (*judge)(int);
    int (*get_pae_priority)(int);
    void (*update_sp_status)(void);
};
typedef struct _anon5 AiManager;
struct _anon6;
struct _anon6 { /* size 0x8 */
    int active;
    int num;
};
typedef struct _anon6 SpStatus;

extern PaeManager paeManager;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern CollectManager collectManager;
extern PanManager panManager;
extern HandManager handManager;
extern int g_my_hand[10];
extern int g_opp_hand[2][10];
extern int g_mission_state;
extern int g_mission_pae_num;
extern int g_mission_pae[9];
extern UserInfo g_user_info;
extern AiManager aiManager;
extern SpecialPae g_sp_pae;
extern SpecialPae g_sp_who;
extern SpStatus g_sp_status[6];
extern int g_try_priority[52];
extern char spname[6][5];

static void init_ai();
static void update_sp_status();
static void set_sp_status(int flagPlayer, int pae, int sp_kind);
static int is_bisang(int flagPlayer, int special_kind);
static int get_rest_pae(int special_kind);
static void set_pae_priority(int pae, int priority, int group_priority);
static void set_priority(int flagPlayer);
static int judge(int flagPlayer);


static void init_ai()
{
	int i;
	SpecialPae definePae = {
		{ 1, 9, 29, 41, 45 },
		{ 5, 13, 30 },
		{ 2, 6, 10 },
		{ 22, 34, 38 },
		{ 14, 18, 26 }
	};
	SpecialPae defineWho = {
		{ -1, -1, -1, -1, -1 },
		{ -1, -1, -1 },
		{ -1, -1, -1 },
		{ -1, -1, -1 },
		{ -1, -1, -1 }
	};

	g_sp_pae = definePae;
	g_sp_who = defineWho;
	for (i = 0; i < 6; i++) {
		g_sp_status[i].active = -2;
		g_sp_status[i].num = 0;
	}
	for (i = 0; i < 52; i++)
		g_try_priority[i] = 999;
}

__asm__(".globl init_ai");

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", update_sp_status);



static void set_sp_status(int flagPlayer, int pae, int sp_kind)
{
	int index;
	int oppPlayer;

	switch (sp_kind) {
	case 5:
		index = find_array(pae, g_sp_pae.ogwang, 5);
		if (index >= 0)
			g_sp_who.ogwang[index] = flagPlayer;
		break;
	case 1:
		index = find_array(pae, g_sp_pae.hongdan, 3);
		if (index >= 0)
			g_sp_who.hongdan[index] = flagPlayer;
		break;
	case 2:
		index = find_array(pae, g_sp_pae.chungdan, 3);
		if (index >= 0)
			g_sp_who.chungdan[index] = flagPlayer;
		break;
	case 3:
		index = find_array(pae, g_sp_pae.chodan, 3);
		if (index >= 0)
			g_sp_who.chodan[index] = flagPlayer;
		break;
	case 4:
		index = find_array(pae, g_sp_pae.godori, 3);
		if (index >= 0)
			g_sp_who.godori[index] = flagPlayer;
		break;
	}
}

__asm__(".globl set_sp_status");

static int is_bisang(int flagPlayer, int special_kind)
{
	int n;
	int cnt;

	cnt = g_sp_status[special_kind].num;
	if (special_kind == 5)
		n = 5;
	else
		n = 3;
	if (g_sp_status[special_kind].active == flagPlayer && cnt > 0 && cnt < n)
		return cnt;
	return 0;
}

static int get_rest_pae(int special_kind)
{
	int index;

	switch (special_kind) {
	case 5:
		index = find_array(-1, g_sp_who.ogwang, 5);
		if (index < 0)
			return 0;
		return g_sp_pae.ogwang[index];
	case 1:
		index = find_array(-1, g_sp_who.hongdan, 3);
		if (index < 0)
			return 0;
		return g_sp_pae.hongdan[index];
	case 2:
		index = find_array(-1, g_sp_who.chungdan, 3);
		if (index < 0)
			return 0;
		return g_sp_pae.chungdan[index];
	case 3:
		index = find_array(-1, g_sp_who.chodan, 3);
		if (index < 0)
			return 0;
		return g_sp_pae.chodan[index];
	case 4:
		index = find_array(-1, g_sp_who.godori, 3);
		if (index < 0)
			return 0;
		return g_sp_pae.godori[index];
	}
	return 0;
}

static void set_pae_priority(int pae, int priority, int group_priority)
{
	int i;
	int start;

	start = (pae - 1) / 4 * 4 + 1;
	for (i = 0; i < 4; i++) {
		if (start + i == pae) {
			if (priority < g_try_priority[start + i])
				g_try_priority[start + i] = priority;
		} else if (group_priority > 0 && group_priority < g_try_priority[start + i])
			g_try_priority[start + i] = group_priority;
	}
}

int get_pae_priority(int pae) {
    return g_try_priority[pae];
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", set_priority);

static int judge(int flagPlayer)
{
	int index, i, max, retVal = -1;
	int pae, kind;
	int *hand = flagPlayer == 0 ? g_my_hand : g_opp_hand[0];
	int oppPlayer = flagPlayer == 0;
	int pan_cnt;
	int ps[4] = { 0 };


	set_priority(flagPlayer);
	int cnt = count_array(hand, 10);

	int min = 1998, pr1, pr2;

	for (i = 0; i < cnt; i++) {
		pae = hand[i];
		kind = paeManager.get_pae_kind(pae);
		if (handManager.is_fixed(flagPlayer, kind) == 1) {
			pr1 = g_try_priority[pae];
			pan_cnt = panManager.get_kind(kind, ps);
			for (index = 0; index < pan_cnt; index++) {
				pae = ps[index];
				pr2 = g_try_priority[pae];

				if (pr1 + pr2 < min) {
					min = pr1 + pr2;
					retVal = i;
				}
			}
		}
	}

	if (min < 1998)
		return retVal;


	min = 1998;
	for (i = 0; i < cnt; i++) {
		pae = hand[i];
		kind = paeManager.get_pae_kind(pae);
		if (handManager.is_fixed(flagPlayer, kind) == 2) {
			pr1 = g_try_priority[pae];
			pan_cnt = panManager.get_kind(kind, ps);
			for (index = 0; index < pan_cnt; index++) {
				pae = ps[index];
				pr2 = g_try_priority[pae];

				if (pr1 + pr2 < min) {
					min = pr1 + pr2;
					retVal = i;
				}
			}
		}
	}

	if (min < 1998)
		return retVal;



	for (i = 0, max = 0; i < cnt; i++) {
		pae = hand[i];
		kind = paeManager.get_pae_kind(pae);

		if (kind == 13)
			return i;

		if (handManager.count_kind(flagPlayer, kind) == 2) {

			if (collectManager.count_kind(flagPlayer, kind) + collectManager.count_kind(oppPlayer, kind) == 2) {
				if (max < g_try_priority[pae]) {
					max = g_try_priority[pae];
					retVal = i;
				}
			}
		}
	}

	if (max > 0)
		return retVal;


	for (i = 0, max = 0; i < cnt; i++) {
		pae = hand[i];
		kind = paeManager.get_pae_kind(pae);

		if (kind == 14)
			return i;

		if (collectManager.count_kind(flagPlayer, kind) + collectManager.count_kind(oppPlayer, kind) == 2) {
			if (max < g_try_priority[pae]) {
				max = g_try_priority[pae];
				retVal = i;
			}
		}
	}

	if (max > 0)
		return retVal;


	for (i = 0, max = 0; i < cnt; i++) {
		int pae = hand[i];
		if (!handManager.is_fixed(flagPlayer, paeManager.get_pae_kind(pae))) {
			if (max < g_try_priority[pae]) {
				max = g_try_priority[pae];
				retVal = i;
			}
		}
	}

	if (max > 0)
		return retVal;

	return rand() % cnt;
}

__asm__(".globl judge");

