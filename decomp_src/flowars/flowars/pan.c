#include "common.h"

struct _anon1;
struct _anon1 { /* size 0x8 */
    int x;
    int y;
};
typedef struct _anon1 Point;
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
typedef struct _PAN PanManager;
struct _PAN;
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
struct _anon3;
struct _anon3 { /* size 0x20 */
    int pos;
    int count;
    int pae[6];
};
typedef struct _anon3 PanPaes;

extern int g_stage_status;
extern PaeManager paeManager;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern PanManager panManager;
extern PanPaes g_pan[13];

static int count_pan();
static int get_max_depth(int kind);
static int count_kind_pan(int kind);
static int get_empty_pos();
static int get_kind_pos(int kind);
static int get_kind_pan(int kind, int *ps);
static int add_pan(int pae, Point *pt, int *sound);
static int add_pan_kind(int pae, int kind, Point *pt, int *sound);
static int remove_pos_pan(int pos);
static int remove_pae_pan(int pae);
static int remove_bonus_pae(int kind);
static void compact_pan();
static int check_chongtong();
static int is_exec(int pae);

#define check_chongtong check_chongtong_7608

static int count_pan()
{
	int i;
	int cnt = 0;

	for (i = 0; i < 13; i++)
		cnt += g_pan[i].count;
	return cnt;
}

__asm__(".globl count_pan");

static int get_max_depth(int kind)
{
	return g_pan[kind - 1].count;
}

__asm__(".globl get_max_depth");

static int count_kind_pan(int kind)
{
	int i;
	int cnt = 0;
	int p;

	for (i = 0; i < g_pan[kind - 1].count; i++) {
		p = g_pan[kind - 1].pae[i];
		if (p != 49 && p != 50)
			cnt++;
	}
	return cnt;
}

__asm__(".globl count_kind_pan");

static int get_empty_pos()
{
	int index;
	int pos[13] = { 0 };
	int p;

	for (index = 0; index < 13; index++)
		if (g_pan[index].count > 0)
			pos[g_pan[index].pos]++;
	for (index = 0; index < 13; index++)
		if (pos[index] == 0)
			return index;
	return 0;
}

__asm__(".globl get_empty_pos");

static int get_kind_pos(int kind)
{
	if (g_pan[kind - 1].count > 0)
		return g_pan[kind - 1].pos;
	return -1;
}

__asm__(".globl get_kind_pos");

static int get_kind_pan(int kind, int *ps)
{
	int i;
	int p;
	int n;

	ps[0] = 0;
	ps[1] = 0;
	ps[2] = 0;
	ps[3] = 0;
	n = 0;
	for (i = 0; i < g_pan[kind - 1].count; i++) {
		p = g_pan[kind - 1].pae[i];
		if (p != 49 && p != 50) {
			*ps++ = p;
			n++;
		}
	}
	return n;
}

__asm__(".globl get_kind_pan");

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/pan", add_pan);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/pan", add_pan_kind);

static int remove_pos_pan(int pos)
{
	int index;
	int pae;
	int depth;

	for (index = 0; index < 13; index++) {
		if (g_pan[index].pos == pos && g_pan[index].count > 0) {
			depth = --g_pan[index].count;
			pae = g_pan[index].pae[depth];
			g_pan[index].pae[depth] = 0;
			return pae;
		}
	}
	return 0;
}

__asm__(".globl remove_pos_pan");

static int remove_pae_pan(int pae)
{
	int i;
	int kind;

	kind = paeManager.get_pae_kind(pae);
	for (i = 0; i < g_pan[kind - 1].count; i++) {
		if (g_pan[kind - 1].pae[i] == pae) {
			g_pan[kind - 1].pae[i] = 0;
			g_pan[kind - 1].count--;
			compact_array(g_pan[kind - 1].pae, 6);
			return pae;
		}
	}
	return 0;
}

__asm__(".globl remove_pae_pan");

static int remove_bonus_pae(int kind)
{
	int i;
	int pae;

	for (i = 0; i < g_pan[kind - 1].count; i++) {
		pae = g_pan[kind - 1].pae[i];
		if (pae == 49 || pae == 50) {
			g_pan[kind - 1].pae[i] = 0;
			g_pan[kind - 1].count--;
			compact_array(g_pan[kind - 1].pae, 6);
			return pae;
		}
	}
	return 0;
}

__asm__(".globl remove_bonus_pae");

void compact_pan(void) {
}

__asm__(".globl compact_pan");

static int check_chongtong()
{
	int i;

	for (i = 1; i < 13; i++)
		if (count_kind_pan(i) >= 4)
			return i;
	return 0;
}

__asm__(".globl check_chongtong_7608");

static int is_exec(int pae)
{
	int i;
	int kind;

	kind = paeManager.get_pae_kind(pae);
	for (i = 0; i < count_kind_pan(kind); i++)
		if (g_pan[kind - 1].pae[i] == pae)
			return 1;
	return 0;
}

__asm__(".globl is_exec");
