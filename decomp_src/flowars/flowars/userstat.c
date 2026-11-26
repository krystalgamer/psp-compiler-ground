#include "common.h"


/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x6c */
    int jabbuck_kind[2];
    int bbuck;
    int shake;
    int go;
    unsigned char turn_event;
    int sp_success[10];
    int sp_bisang[10];
    int game_money;
};
typedef struct _anon1 UserStat;
struct _anon2;
struct _anon2 { /* size 0x18 */
    int total;
    int gwang;
    int mung;
    int dan;
    int pi;
    int last_go;
};
typedef struct _anon2 UserScore;
struct _anon3;
struct _anon3 { /* size 0x28 */
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
typedef struct _anon3 PaeManager;
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
struct _anon4;
struct _anon4 { /* size 0x18 */
    void (*init)();
    void (*set_mission_state)(int);
    void (*assign)(int);
    int (*check_mission_success)(int);
    int (*reg_mission_pae)(int, int);
    int (*count_bingo_line)(int);
};
typedef struct _anon4 MissionManager;
struct _anon5;
struct _anon5 { /* size 0x4 */
    int user_level;
};
typedef struct _anon5 UserInfo;
struct _anon6;
struct _anon6 { /* size 0x44 */
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
typedef struct _anon6 ResultScore;
struct _anon7;
struct _anon7 { /* size 0x48 */
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
typedef struct _anon7 UserManager;
struct _anon8;
struct _anon8 { /* size 0x14 */
    void (*init)(void);
    void (*set_sp_status)(int, int, int);
    int (*judge)(int);
    int (*get_pae_priority)(int);
    void (*update_sp_status)(void);
};
typedef struct _anon8 AiManager;

extern int g_stage_status;
extern PaeManager paeManager;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
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
extern int g_round_count;
extern int g_nagari_count;
extern int g_bet_money;
extern int g_mission_state;
extern int g_mission_type;
extern int g_mission_baesu;
extern MissionManager missionManager;
extern UserInfo g_user_info;
extern ResultScore g_result_score;
extern UserManager userManager;
extern AiManager aiManager;
extern UserScore g_my_score;
extern UserScore g_opp_score;
extern UserScore g_opp2_score;
extern UserStat g_my_stat;
extern UserStat g_opp_stat;
extern UserStat g_opp2_stat;

static void set_turn_event(int flagPlayer, int flagEvent);
static void set_sp_success(int flagPlayer, int Event);
static void update_user_stat(int flagPlayer);
static void init_stat(void);
static void update_stat(void);
static int is_jabbuck(int flagPlayer, int kind);
static int check_event(int flagPlayer, int flagEvent);
static unsigned char get_event(int flagPlayer);
static int bbuck(int flagPlayer, int kind);
static int shake(int flagPlayer);
static int go(int flagPlayer);
static void get_user_score(int flagPlayer, UserScore *userScore);
static void get_user_stat(int flagPlayer, UserStat *userStat);
static void set_result_score(int win_user, int flag_think_gukjin);


extern int D_000656C8;
extern int D_00065750;
extern int D_00065818;
extern int D_00065668;
extern int D_000656F0;
extern int D_000657B8;
extern int D_0006566C;
extern int D_000656F4;
extern int D_000657BC;
extern int D_00065670;
extern int D_000656F8;
extern int D_000657C0;

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/userstat", set_turn_event);

void set_game_money(int flagPlayer, int money) {
    if (flagPlayer != 1) {
        if (flagPlayer != 2) {
            D_00065818 = money;
            return;
        }
        D_00065750 = money;
        return;
    }
    D_000656C8 = money;
}

void add_game_money(int flagPlayer, int money) {
    UserStat *var_v1;

    var_v1 = &g_opp_stat;
    if (flagPlayer != 1) {
        var_v1 = &g_opp2_stat;
        if (flagPlayer != 2) {
            g_my_stat.game_money += money;
            return;
        }
    }
    var_v1->game_money += money;
}

int get_game_money(int flagPlayer) {
    switch (flagPlayer) {                           /* irregular */
    case 2:
        return D_00065750;
    default:
        return D_00065818;
    case 1:
        return D_000656C8;
    }
}

static void set_sp_success(int flagPlayer, int Event)
{
	if (flagPlayer == 1)
		g_opp_stat.sp_success[Event] = 1;
	else if (flagPlayer == 2)
		g_opp2_stat.sp_success[Event] = 1;
	else
		g_my_stat.sp_success[Event] = 1;
}

__asm__(".globl set_sp_success");

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/userstat", update_user_stat);

static void init_stat(void)
{
	int money;

	money = g_my_stat.game_money;
	memset(&g_my_stat, 0, sizeof(UserStat));
	g_my_stat.game_money = money;
	money = g_opp_stat.game_money;
	memset(&g_opp_stat, 0, sizeof(UserStat));
	g_opp_stat.game_money = money;
	memset(&g_my_score, 0, sizeof(UserScore));
	memset(&g_opp_score, 0, sizeof(UserScore));
}

__asm__(".globl init_stat");

static void update_stat(void)
{
	update_user_stat(0);
	update_user_stat(1);
	aiManager.update_sp_status();
}

__asm__(".globl update_stat");

static int is_jabbuck(int flagPlayer, int kind)
{
	UserStat *stat;
	int ret = 0;

	if (flagPlayer == 1)
		stat = &g_opp_stat;
	else if (flagPlayer == 2)
		stat = &g_opp2_stat;
	else
		stat = &g_my_stat;
	if (stat->jabbuck_kind[0] == kind || stat->jabbuck_kind[1] == kind)
		ret = 1;
	return ret;
}

__asm__(".globl is_jabbuck");

static int check_event(int flagPlayer, int flagEvent)
{
	UserStat *stat;

	if (flagPlayer == 1)
		stat = &g_opp_stat;
	else if (flagPlayer == 2)
		stat = &g_opp2_stat;
	else
		stat = &g_my_stat;
	return (stat->turn_event & flagEvent) != 0;
}

__asm__(".globl check_event");

static unsigned char get_event(int flagPlayer)
{
	UserStat *stat;

	if (flagPlayer == 1)
		stat = &g_opp_stat;
	else if (flagPlayer == 2)
		stat = &g_opp2_stat;
	else
		stat = &g_my_stat;
	return stat->turn_event;
}

__asm__(".globl get_event");

static int bbuck(int flagPlayer, int kind)
{
	UserStat *stat;

	if (flagPlayer == 1)
		stat = &g_opp_stat;
	else if (flagPlayer == 2)
		stat = &g_opp2_stat;
	else
		stat = &g_my_stat;
	if (stat->jabbuck_kind[0] == 0)
		stat->jabbuck_kind[0] = kind;
	else
		stat->jabbuck_kind[1] = kind;
	return ++stat->bbuck;
}

__asm__(".globl bbuck");

int get_bbuck_count(int flagPlayer) {
    switch (flagPlayer) {                           /* irregular */
    case 2:
        return D_000656F0;
    default:
        return D_000657B8;
    case 1:
        return D_00065668;
    }
}

static int shake(int flagPlayer)
{
	int ret;

	if (flagPlayer == 1)
		ret = ++g_opp_stat.shake;
	else if (flagPlayer == 2)
		ret = ++g_opp2_stat.shake;
	else
		ret = ++g_my_stat.shake;
	return ret;
}

__asm__(".globl shake");

int get_shake_count(int flagPlayer) {
    switch (flagPlayer) {                           /* irregular */
    case 2:
        return D_000656F4;
    default:
        return D_000657BC;
    case 1:
        return D_0006566C;
    }
}

static int go(int flagPlayer)
{
	int ret;

	if (flagPlayer == 1) {
		ret = ++g_opp_stat.go;
		g_opp_score.last_go = g_opp_score.total;
	} else if (flagPlayer == 2) {
		ret = ++g_opp2_stat.go;
		g_opp2_score.last_go = g_opp2_score.total;
	} else {
		ret = ++g_my_stat.go;
		g_my_score.last_go = g_my_score.total;
	}
	return ret;
}

__asm__(".globl go");

int get_go_count(int flagPlayer) {
    switch (flagPlayer) {                           /* irregular */
    case 2:
        return D_000656F8;
    default:
        return D_000657C0;
    case 1:
        return D_00065670;
    }
}

static void get_user_score(int flagPlayer, UserScore *userScore)
{
	if (flagPlayer == 1)
		*userScore = g_opp_score;
	else if (flagPlayer == 2)
		*userScore = g_opp2_score;
	else
		*userScore = g_my_score;
}

__asm__(".globl get_user_score");

static void get_user_stat(int flagPlayer, UserStat *userStat)
{
	if (flagPlayer == 1)
		*userStat = g_opp_stat;
	else if (flagPlayer == 2)
		*userStat = g_opp2_stat;
	else
		*userStat = g_my_stat;
}

__asm__(".globl get_user_stat");

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/userstat", set_result_score);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/userstat", D_0002F850);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/userstat", D_0002F854);
