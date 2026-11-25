#include "common.h"


/* declarations recovered from DWARF */
typedef struct _DECK DeckManager;
struct _DECK;
struct _DECK { /* size 0x24 */
    void (*init)(void);
    int (*get_pae)(void);
    int (*get_swap_pae)(int);
    int (*count)(void);
    int (*count_all)(void);
    void (*shuffle)(void);
    int (*show_pae)(void);
    void (*get_back_pos)(int *, int *);
    void (*set_pae)(int, int);
};

extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern int g_deck[50];
extern int g_back_remain;
extern DeckManager deckManager;



#define get_pae get_pae_AFE0
#define count count_B0C4

static int get_pae(void);

static void init_deck(void)
{
	int i;

	g_back_remain = 50;
	for (i = 0; i < 50; i++)
		g_deck[i] = i;
}

__asm__(".globl init_deck");

static int get_pae(void)
{
	int pae;

	if (g_back_remain > 0)
		pae = g_deck[--g_back_remain] + 1;
	else
		pae = 0;
	return pae;
}

__asm__(".globl get_pae_AFE0");

static int get_swap_pae(int pae)
{
	int i;

	pae--;
	for (i = 0; i < g_back_remain; i++) {
		if (g_deck[i] == pae) {
			g_deck[i] = g_deck[g_back_remain - 1];
			g_deck[g_back_remain - 1] = pae;
			return get_pae();
		}
	}
	return get_pae();
}

__asm__(".globl get_swap_pae");

static int show_pae(void)
{
	int pae = 0;

	if (g_back_remain > 0)
		pae = g_deck[g_back_remain - 1] + 1;
	return pae;
}

__asm__(".globl show_pae");

static int count(void)
{
	int i;
	int n = 0;

	for (i = 0; i < g_back_remain; i++)
		if (g_deck[i] != 48 && g_deck[i] != 49)
			n++;
	return n;
}

__asm__(".globl count_B0C4");

int count_all(void) {
    return g_back_remain;
}

static void set_pae(int pos, int pae)
{
	int i;

	pae--;
	for (i = 0; i < 50 && g_deck[i] != pae; i++)
		;
	g_deck[i] = g_deck[pos];
	g_deck[pos] = pae;
}

__asm__(".globl set_pae");

void shuffle_deck(void) {
    shuffle(g_deck, 0x32);
}

void get_back_pos(int *x, int *y) {
    *x = 0xD7 - ((g_back_remain / 5) * 2);
    *y = 0x6E - ((g_back_remain / 5) * 2);
}
