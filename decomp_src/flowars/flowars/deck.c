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

static void init_deck(void);
static int get_pae(void);
static int get_swap_pae(int pae);
static int show_pae(void);
static int count(void);
static void set_pae(int pos, int pae);


INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/deck", init_deck);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/deck", get_pae_AFE0);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/deck", get_swap_pae);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/deck", show_pae);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/deck", count_B0C4);

int count_all(void) {
    return g_back_remain;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/deck", set_pae);

void shuffle_deck(void) {
    shuffle(g_deck, 0x32);
}

void get_back_pos(int *x, int *y) {
    *x = 0xD7 - ((g_back_remain / 5) * 2);
    *y = 0x6E - ((g_back_remain / 5) * 2);
}
