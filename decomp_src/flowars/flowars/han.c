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

static void draw_han_font(int ax, int ay, int px, int py, int code, int color, float scale_x, float scale_y);
static int draw_eng_font(int ax, int ay, int px, int py, int code, int color, float scale_x, float scale_y);
void printhanln_scale(int ax, int ay, int color, char *str, float scale_x, float scale_y);
short int map_wansung_to_johab(unsigned char first, unsigned char last);
void wansung_to_johab(char *dst, char *src);

/* SDK functions (tools/sdk_protos.h) */
unsigned int strlen(const char *s);
void *malloc(unsigned int size);
void free(void *p);


INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/han", draw_han_font);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/han", draw_eng_font);

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

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/han", map_wansung_to_johab);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/han", wansung_to_johab);
