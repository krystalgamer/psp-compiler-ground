/* cflags: -O0 */
#include "common.h"

typedef struct {
	int x;
	int y;
} LcdPos;

typedef struct {
	char name[20];
	int (*func)(int);
	int arg;
} GraphicsMenu;

int sprintf(char *buf, const char *fmt, ...);
int sceDisplayWaitVblankStart(void);
int sceCtrlReadLatch(unsigned int *latch);
void LcdDrawSetForeColor(unsigned int color);
void LcdDrawSetBackColor(unsigned int color);
void LcdDrawClr(void);
LcdPos *SetPosition(LcdPos *pos, int x, int y);
void LcdDrawChars(LcdPos *pos, const char *str, int size);

extern GraphicsMenu _graphics_menu[3];

static void _DrawModeMenu(int index, const char *name, int selected)
{
	LcdPos pos;

	if (selected)
		LcdDrawSetForeColor(0xFF0000);
	else
		LcdDrawSetForeColor(0);
	LcdDrawChars(SetPosition(&pos, 1, index + 2), name, 4);
}

static void _DrawAllMenu(int sel)
{
	int i;
	LcdPos pos;

	LcdDrawSetForeColor(0xFF00);
	LcdDrawSetBackColor(0xFFFFFF);
	LcdDrawClr();
	LcdDrawChars(SetPosition(&pos, 10000, 0), "Graphics TEST", 4);
	LcdDrawChars(SetPosition(&pos, 40, 3), "up,down: menu select", 2);
	LcdDrawChars(SetPosition(&pos, 40, 4), "[O]:     execute    ", 2);
	LcdDrawChars(SetPosition(&pos, 40, 5), "[X]:     exit       ", 2);
	for (i = 0; i < 3; i++) {
		if (i == sel)
			_DrawModeMenu(i, _graphics_menu[i].name, 1);
		else
			_DrawModeMenu(i, _graphics_menu[i].name, 0);
	}
}

void GraphicsTestVersion(char *buf)
{
	sprintf(buf, "Ver. 041026_1");
}

int GraphicsTest(int arg)
{
	unsigned int latch[4];
	int sel;
	char buf[32];

	sel = 0;
	_DrawAllMenu(sel);
	for (;;) {
		while (1) {
			if (sceCtrlReadLatch(latch))
				break;
			sceDisplayWaitVblankStart();
		}
		if (latch[1] & 0x10) {
			if (sel != 0) {
				_DrawModeMenu(sel, _graphics_menu[sel].name, 0);
				sel--;
				_DrawModeMenu(sel, _graphics_menu[sel].name, 1);
			}
		} else if (latch[1] & 0x40) {
			if (sel != 2) {
				_DrawModeMenu(sel, _graphics_menu[sel].name, 0);
				sel++;
				_DrawModeMenu(sel, _graphics_menu[sel].name, 1);
			}
		} else if (latch[1] & 0x2000) {
			_graphics_menu[sel].func(_graphics_menu[sel].arg);
			_DrawAllMenu(sel);
		} else if (latch[1] & 0x4000) {
			break;
		} else {
			/* an insn without code: keeps cfg cleanup from forwarding this edge (orig keeps beqz; j exit; j top) */
			__asm__ volatile ("");
		}
	}
	return 0;
}

int GraphicsTestEntry(int a, int b)
{
	return 0;
}
