/* cflags: -O0 */
#include "common.h"

typedef struct {
	int x;
	int y;
} LcdPos;

void LcdDrawSetForeColor(unsigned int color);
void LcdDrawSetBackColor(unsigned int color);
void LcdDrawClr(void);
LcdPos *SetPosition(LcdPos *pos, int x, int y);
void LcdDrawLine(LcdPos *from, LcdPos *to);
void LcdDrawFillRect(LcdPos *from, LcdPos *to);

typedef struct {
	unsigned int color;
	LcdPos from;
	LcdPos to;
} LcdBar;

const unsigned char h_pattern[8] = { 0x00, 0x44, 0x44, 0x44, 0x7C, 0x44, 0x44, 0x44 };

void LcdDrawPtnH(int x, int y)
{
	LcdPos p[2];

	SetPosition(&p[0], x * 8 + 1, y * 8 + 1);
	SetPosition(&p[1], x * 8 + 1, y * 8 + 7);
	LcdDrawLine(&p[0], &p[1]);
	SetPosition(&p[0], x * 8 + 5, y * 8 + 1);
	SetPosition(&p[1], x * 8 + 5, y * 8 + 7);
	LcdDrawLine(&p[0], &p[1]);
	SetPosition(&p[0], x * 8 + 1, y * 8 + 4);
	SetPosition(&p[1], x * 8 + 5, y * 8 + 4);
	LcdDrawLine(&p[0], &p[1]);
}

void LcdDrawPtnHs(unsigned int fg, unsigned int bg)
{
	int y = 0;
	int x = 0;

	LcdDrawSetForeColor(fg);
	LcdDrawSetBackColor(bg);
	LcdDrawClr();
	for (y = 0; y < 34; y++) {
		for (x = 0; x < 60; x++)
			LcdDrawPtnH(x, y);
	}
}

void LcdDrawPtnH2(int x, int y)
{
	LcdPos p[2];

	SetPosition(&p[0], x * 16 + 2, y * 16 + 2);
	SetPosition(&p[1], x * 16 + 3, y * 16 + 15);
	LcdDrawFillRect(&p[0], &p[1]);
	SetPosition(&p[0], x * 16 + 10, y * 16 + 2);
	SetPosition(&p[1], x * 16 + 11, y * 16 + 15);
	LcdDrawFillRect(&p[0], &p[1]);
	SetPosition(&p[0], x * 16 + 2, y * 16 + 8);
	SetPosition(&p[1], x * 16 + 11, y * 16 + 9);
	LcdDrawFillRect(&p[0], &p[1]);
}

void LcdDrawPtnHs2(unsigned int fg, unsigned int bg)
{
	int y = 0;
	int x = 0;

	LcdDrawSetForeColor(fg);
	LcdDrawSetBackColor(bg);
	LcdDrawClr();
	for (y = 0; y < 17; y++) {
		for (x = 0; x < 30; x++)
			LcdDrawPtnH2(x, y);
	}
}

void LcdDrawPtnUpDownColor(unsigned int fg, unsigned int bg)
{
	LcdPos p[2] = { { 0, 0 }, { 479, 135 } };

	LcdDrawSetForeColor(fg);
	LcdDrawSetBackColor(bg);
	LcdDrawClr();
	LcdDrawFillRect(&p[0], &p[1]);
}

void LcdDrawPtnColorscale16(void)
{
	unsigned int i;
	LcdPos p[2];

	for (i = 0; i < 16; i++) {
		LcdDrawSetForeColor(i * 255 / 15);
		SetPosition(&p[0], (int)(i * 479) / 16, 0);
		SetPosition(&p[1], (int)(i * 479 + 479) / 16, 90);
		LcdDrawFillRect(&p[0], &p[1]);
	}
	for (i = 0; i < 16; i++) {
		LcdDrawSetForeColor((i * 255 / 15) << 8);
		SetPosition(&p[0], (int)(i * 479) / 16, 91);
		SetPosition(&p[1], (int)(i * 479 + 479) / 16, 180);
		LcdDrawFillRect(&p[0], &p[1]);
	}
	for (i = 0; i < 16; i++) {
		LcdDrawSetForeColor((i * 255 / 15) << 16);
		SetPosition(&p[0], (int)(i * 479) / 16, 181);
		SetPosition(&p[1], (int)(i * 479 + 479) / 16, 271);
		LcdDrawFillRect(&p[0], &p[1]);
	}
}

void LcdDrawPtnColorscaleMax(void)
{
	unsigned int i;
	LcdPos p[2];

	for (i = 0; i < 481; i++) {
		LcdDrawSetForeColor(i * 255 / 479);
		SetPosition(&p[0], i, 0);
		SetPosition(&p[1], i, 90);
		LcdDrawLine(&p[0], &p[1]);
	}
	for (i = 0; i < 481; i++) {
		LcdDrawSetForeColor((i * 255 / 479) << 8);
		SetPosition(&p[0], i, 91);
		SetPosition(&p[1], i, 180);
		LcdDrawLine(&p[0], &p[1]);
	}
	for (i = 0; i < 481; i++) {
		LcdDrawSetForeColor((i * 255 / 479) << 16);
		SetPosition(&p[0], i, 181);
		SetPosition(&p[1], i, 271);
		LcdDrawLine(&p[0], &p[1]);
	}
}

void LcdDrawPtnGrayscale8(void)
{
	unsigned int i;
	LcdPos p[2];

	for (i = 0; i < 8; i++) {
		LcdDrawSetForeColor(((i * 255 / 7) << 16) | ((i * 255 / 7) << 8) | (i * 255 / 7));
		SetPosition(&p[0], (int)(i * 479) / 8, 0);
		SetPosition(&p[1], (int)(i * 479 + 479) / 8, 271);
		LcdDrawFillRect(&p[0], &p[1]);
	}
}

void LcdDrawPtnGrayscale16(void)
{
	unsigned int i;
	LcdPos p[2];

	for (i = 0; i < 16; i++) {
		LcdDrawSetForeColor(((i * 255 / 15) << 16) | ((i * 255 / 15) << 8) | (i * 255 / 15));
		SetPosition(&p[0], (int)(i * 479) / 16, 0);
		SetPosition(&p[1], (int)(i * 479 + 479) / 16, 135);
		LcdDrawFillRect(&p[0], &p[1]);
	}
	for (i = 0; i < 16; i++) {
		LcdDrawSetForeColor(((255 - i * 255 / 15) << 16) | ((255 - i * 255 / 15) << 8) | (255 - i * 255 / 15));
		SetPosition(&p[0], (int)(i * 479) / 16, 136);
		SetPosition(&p[1], (int)(i * 479 + 479) / 16, 271);
		LcdDrawFillRect(&p[0], &p[1]);
	}
}

void LcdDrawPtnGrayscaleMax(void)
{
	unsigned int i = 0;
	LcdPos p[2];

	for (i = 0; i < 481; i++) {
		LcdDrawSetForeColor(((i * 255 / 479) << 16) | ((i * 255 / 479) << 8) | (i * 255 / 479));
		SetPosition(&p[0], i, 0);
		SetPosition(&p[1], i, 271);
		LcdDrawLine(&p[0], &p[1]);
	}
}

void LcdDrawPtnColorBar(void)
{
	LcdBar bar[11] = {
		{ 0xFFFFFF, { 0, 0 }, { 68, 198 } },
		{ 0x00FFFF, { 69, 0 }, { 136, 198 } },
		{ 0xFFFF00, { 137, 0 }, { 204, 198 } },
		{ 0x00FF00, { 205, 0 }, { 273, 198 } },
		{ 0xFF00FF, { 274, 0 }, { 342, 198 } },
		{ 0xFF0000, { 343, 0 }, { 410, 198 } },
		{ 0x0000FF, { 411, 0 }, { 479, 198 } },
		{ 0x808080, { 0, 199 }, { 89, 271 } },
		{ 0xFFFFFF, { 90, 199 }, { 179, 271 } },
		{ 0xC0C0C0, { 180, 199 }, { 269, 271 } },
		{ 0x000000, { 270, 199 }, { 479, 271 } },
	};
	unsigned int i;

	for (i = 0; i < 11; i++) {
		LcdDrawSetForeColor(bar[i].color);
		LcdDrawFillRect(&bar[i].from, &bar[i].to);
	}
}

void LcdDrawPtnFLMoire(void)
{
	int y;
	LcdPos p[2];

	LcdDrawSetForeColor(0xFEFEFE);
	LcdDrawSetBackColor(0);
	LcdDrawClr();
	for (y = 0; y < 272; y += 2)
		LcdDrawLine(SetPosition(&p[0], 0, y), SetPosition(&p[1], 479, y));
}

void LcdDrawPtnFLMoire2(void)
{
	int y;
	LcdPos p[2];

	LcdDrawPtnGrayscale8();
	for (y = 0; y < 272; y += 2) {
		LcdDrawSetForeColor(0);
		LcdDrawLine(SetPosition(&p[0], 0, y), SetPosition(&p[1], 479, y));
	}
}
