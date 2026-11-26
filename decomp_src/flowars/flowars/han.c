#include "common.h"


/* declarations recovered from DWARF */
typedef struct SceGimPicture SceGimPicture;
struct SceGimPicture;

extern short int johab_table[2350];
extern int bul_cho1[30];
extern int bul_cho2[30];
extern int bul_jung[21];
extern int bul_jong[30];
extern int letter_table[7][27];
extern SceGimPicture *g_font_han;
extern SceGimPicture *g_font_eng;


/* SDK functions (tools/sdk_protos.h) */
unsigned int strlen(const char *s);
void *malloc(unsigned int size);
void free(void *p);


char *strcpy(char *dst, const char *src);
static void draw_han_font(int ax, int ay, int px, int py, int code, int color, float scale_x, float scale_y);
static int draw_eng_font(int ax, int ay, int px, int py, int code, int color, float scale_x, float scale_y);
void printhanln_scale(int ax, int ay, int color, char *str, float scale_x, float scale_y);
int sceGimPictureActivate(SceGimPicture *picture);
void sceGuColor(unsigned int color);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);
short int map_wansung_to_johab(unsigned char first, unsigned char last);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/han", draw_han_font);

static int draw_eng_font(int ax, int ay, int px, int py, int code, int color, float scale_x, float scale_y)
{
	int x;
	int y;

	code -= 32;
	x = (code % 16) * 6;
	y = (code / 16) * 12;
	if (code < 0 || code > 96)
		return 0;
	sceGimPictureActivate(g_font_eng);
	sceGuSpriteMode(6, 12, 6, 12);
	sceGuColor(color);
	sceGuDrawSprite(ax + px * 6, ay + py * 12, 0, x, y, 0, 0);
	return 1;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/han", printhanln_scale);

void printhanln(int ax, int ay, int color, signed char *str) {
    printhanln_scale(ax, ay, color, str, 1.0f, 1.0f);
}

void printwanln(int ax, int ay, int color, signed char *str) {
    signed char *temp_v0;

    temp_v0 = malloc(strlen(str) + 1);
    wansung_to_johab(temp_v0, str);
    printhanln_scale(ax, ay, color, temp_v0, 1.0f, 1.0f);
    free(temp_v0);
}

unsigned int make_han(unsigned int cho, unsigned int jung, unsigned int jong) {
    unsigned int temp_v0;

    temp_v0 = ((cho << 0xA) | (jung << 5) | jong | 0x8000) & 0xFFFF;
    return (temp_v0 >> 8) | ((temp_v0 << 8) & 0xFF00);
}

short int map_wansung_to_johab(unsigned char first, unsigned char last)
{
	unsigned int index1;
	unsigned int index2;
	unsigned int index;

	index1 = first - 0xB0;
	index2 = last - 0xA1;
	index = index1 * 94 + index2;
	if (index < 2350)
		return johab_table[index];
	return 0;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/han", wansung_to_johab);
