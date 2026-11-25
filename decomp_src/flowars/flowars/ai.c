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


INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", init_ai);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", update_sp_status);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/ai", D_00030878);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/ai", D_000308BC);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", set_sp_status);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", is_bisang);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", get_rest_pae);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", set_pae_priority);

int get_pae_priority(int pae) {
    return g_try_priority[pae];
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", set_priority);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/ai", judge);
