/* cflags: -O2 */
#include "common.h"

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C81C);

typedef struct { int f0; char name[5][10]; int score[5]; } HISCORE_DISP;
typedef struct { int y[5]; } HSY_T;
extern const HSY_T D_0007C81C;
int sprintf(char *buf, const char *fmt, ...);
int ASC_StringRen(char *s);
void ASC_SetStringRGBA(int font, char *str, int x, int y, int r, int g, int b, int a);
int inv_font_ascii_check_w(char *s, int size);
void inv_font_ascii(char *str, int x, int y, int w, int h, int r, int g, int b, int a);
void inv_hiscore_disp(HISCORE_DISP *d)
{
	char buf[64];
	HSY_T pos = D_0007C81C;
	int i;

	if (d->f0 == 1) {
		inv_font_ascii("Hi score", (480 - inv_font_ascii_check_w("Hi score", 100)) / 2, 40, 100, 100, 255, 255, 255, 255);
		inv_font_ascii("NAME", 0x38, 0x50, 100, 100, 255, 255, 255, 255);
		inv_font_ascii("SCORE", 0x148, 0x50, 100, 100, 255, 255, 255, 255);
		inv_font_ascii("1", 0x20, 0x68, 100, 100, 255, 255, 255, 255);
		inv_font_ascii("2", 0x18, 0x80, 100, 100, 255, 255, 255, 255);
		inv_font_ascii("3", 0x18, 0x98, 100, 100, 255, 255, 255, 255);
		inv_font_ascii("4", 0x18, 0xB0, 100, 100, 255, 255, 255, 255);
		inv_font_ascii("5", 0x18, 0xC8, 100, 100, 255, 255, 255, 255);
		for (i = 0; i < 5; i++) {
			sprintf(buf, "%08d", d->score[i]);
			inv_font_ascii(buf, 0x148, pos.y[i], 60, 100, 255, 255, 255, 255);
		}
		for (i = 0; i < 5; i++)
			inv_font_ascii(d->name[i], 0x38, pos.y[i], 60, 100, 255, 255, 255, 255);
	} else if (d->f0 == 0) {
		ASC_SetStringRGBA(1, "HI-SCORE", (480 - ASC_StringRen("HI-SCORE")) / 2, 40, 255, 255, 255, 255);
		ASC_SetStringRGBA(1, "NAME", 0x80, 0x50, 255, 255, 255, 255);
		ASC_SetStringRGBA(1, "SCORE", 0x138, 0x50, 255, 255, 255, 255);
		ASC_SetStringRGBA(1, "1", 0x60, 0x68, 255, 255, 255, 255);
		ASC_SetStringRGBA(1, "2", 0x60, 0x80, 255, 255, 255, 255);
		ASC_SetStringRGBA(1, "3", 0x60, 0x98, 255, 255, 255, 255);
		ASC_SetStringRGBA(1, "4", 0x60, 0xB0, 255, 255, 255, 255);
		ASC_SetStringRGBA(1, "5", 0x60, 0xC8, 255, 255, 255, 255);
		for (i = 0; i < 5; i++) {
			sprintf(buf, "%08d", d->score[i]);
			ASC_SetStringRGBA(1, buf, 0x138, pos.y[i], 255, 255, 255, 255);
		}
		for (i = 0; i < 5; i++)
			ASC_SetStringRGBA(1, d->name[i], 0x80, pos.y[i], 255, 255, 255, 255);
	}
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C874);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C87C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C890);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C898);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C8A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C8AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C8B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C8C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C8CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C8D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C8DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C8EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C8F8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C900);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C908);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C90C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C920);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C93C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C954);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C968);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C97C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C990);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_hiscore", D_0007C9A4);
