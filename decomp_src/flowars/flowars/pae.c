#include "common.h"

typedef struct _pae_attribute pae_attribute;
struct _pae_attribute;
struct _pae_attribute { /* size 0x24 */
    int kind;
    int gwang;
    int mung;
    int dan;
    int pi;
    int hong;
    int chung;
    int cho;
    int godori;
};
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
struct _anon2 { /* size 0x20 */
    int pos;
    int count;
    int pae[6];
};
typedef struct _anon2 PanPaes;
struct _anon3;
struct _anon4;
struct _anon4 { /* size 0x8 */
    int x;
    int y;
};
typedef struct _anon4 Point;
struct _anon3 { /* size 0x8 */
    Point pos;
};
typedef struct _anon3 Paes;

extern PaeManager paeManager;
extern int g_turn_pae;
extern int g_pan_pos[13][4];
extern int g_last_pae;
extern int g_last_turn_pae;
extern PanPaes g_pan[13];
extern pae_attribute g_pae_attrib[52];
extern pae_attribute *g_pa;
extern Paes paes[52];

void set_pae_pos(int pae, int x, int y);
void get_pae_pos(int pae, int *x, int *y);
void pae_init(void);
static int get_pae_kind(int pae);
static int get_pae_value(int pae);
static int is_gwang(int pae);
static int is_mung(int pae);
static int is_dan(int pae);
static int is_pi(int pae);
static int is_hong(int pae);
static int is_chung(int pae);
static int is_cho(int pae);
static int is_godori(int pae);

void *memset(void *s, int c, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);

/* referenced from the data (function tables) */
__asm__(".globl get_pae_kind");
__asm__(".globl get_pae_value");
__asm__(".globl is_gwang");
__asm__(".globl is_mung");
__asm__(".globl is_dan");
__asm__(".globl is_pi");
__asm__(".globl is_hong");
__asm__(".globl is_chung");
__asm__(".globl is_cho");
__asm__(".globl is_godori");

void set_pae_pos(int pae, int x, int y)
{
	paes[pae - 1].pos.x = x;
	paes[pae - 1].pos.y = y;
}

void get_pae_pos(int pae, int *x, int *y)
{
	*x = paes[pae - 1].pos.x;
	*y = paes[pae - 1].pos.y;
}

void pae_init(void)
{
	memset(paes, 0, sizeof(paes));
	pae_attribute tmpattr[52] = {
		{ 1, 2, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 1, 0, 1, 0, 0, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 2, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 2, 0, 0, 1, 0, 1, 0, 0, 0 },
		{ 2, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 2, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 3, 2, 0, 0, 0, 0, 0, 0, 0 },
		{ 3, 0, 0, 1, 0, 1, 0, 0, 0 },
		{ 3, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 3, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 4, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 4, 0, 0, 1, 0, 0, 0, 1, 0 },
		{ 4, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 4, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 5, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 5, 0, 0, 1, 0, 0, 0, 1, 0 },
		{ 5, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 5, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 6, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 6, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 6, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 6, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 7, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 7, 0, 0, 1, 0, 0, 0, 1, 0 },
		{ 7, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 7, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 8, 2, 0, 0, 0, 0, 0, 0, 0 },
		{ 8, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 8, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 8, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 9, 0, 1, 0, 2, 0, 0, 0, 0 },
		{ 9, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 9, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 9, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 10, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 10, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 10, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 10, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 11, 2, 0, 0, 0, 0, 0, 0, 0 },
		{ 11, 0, 0, 0, 2, 0, 0, 0, 0 },
		{ 11, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 11, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 12, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 12, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 12, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 12, 0, 0, 0, 2, 0, 0, 0, 0 },
		{ 13, 0, 0, 0, 2, 0, 0, 0, 0 },
		{ 13, 0, 0, 0, 3, 0, 0, 0, 0 },
		{ 14, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 15, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	int tmppos[13][4] = {
		{ 230, 65, 0, 0 },
		{ 200, 155, 0, 0 },
		{ 165, 110, 0, 0 },
		{ 260, 110, 0, 0 },
		{ 177, 65, 0, 0 },
		{ 253, 155, 0, 0 },
		{ 275, 65, 0, 0 },
		{ 155, 155, 0, 0 },
		{ 133, 65, 0, 0 },
		{ 297, 155, 0, 0 },
		{ 320, 65, 0, 0 },
		{ 110, 155, 0, 0 },
		{ 295, 110, 0, 0 },
	};

	memcpy(g_pae_attrib, tmpattr, sizeof(tmpattr));
	memset(g_pan, 0, sizeof(g_pan));
	g_turn_pae = 0;
	memcpy(g_pan_pos, tmppos, sizeof(tmppos));
	g_last_pae = 0;
	g_last_turn_pae = 0;
}

static int get_pae_kind(int pae)
{
	return g_pae_attrib[pae - 1].kind;
}

static int get_pae_value(int pae)
{
	if (is_gwang(pae))
		return 4;
	if (is_mung(pae))
		return 3;
	if (is_dan(pae))
		return 2;
	if (is_pi(pae))
		return 1;
	return 0;
}

static int is_gwang(int pae)
{
	return g_pae_attrib[pae - 1].gwang;
}

static int is_mung(int pae)
{
	return g_pae_attrib[pae - 1].mung;
}

static int is_dan(int pae)
{
	return g_pae_attrib[pae - 1].dan;
}

static int is_pi(int pae)
{
	return g_pae_attrib[pae - 1].pi;
}

static int is_hong(int pae)
{
	return g_pae_attrib[pae - 1].hong;
}

static int is_chung(int pae)
{
	return g_pae_attrib[pae - 1].chung;
}

static int is_cho(int pae)
{
	return g_pae_attrib[pae - 1].cho;
}

static int is_godori(int pae)
{
	return g_pae_attrib[pae - 1].godori;
}
