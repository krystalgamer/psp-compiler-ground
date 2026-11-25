/* cflags: -O0 */
#include "common.h"

typedef struct {
	int x;
	int y;
	int unk8;
	int unkC;
} LcdPos;

typedef struct {
	unsigned int mask;
	int x;
	int y;
	char name[8];
} HpDrawData;

int sprintf(char *buf, const char *fmt, ...);
unsigned int strlen(const char *s);
void LcdDrawSetForeColor(unsigned int color);
void LcdDrawSetBackColor(unsigned int color);
unsigned int LcdDrawGetForeColor(void);
unsigned int LcdDrawGetBackColor(void);
void LcdDrawClr(void);
LcdPos *SetPosition(LcdPos *pos, int x, int y);
void LcdDrawChars(LcdPos *pos, const char *str, int size);
void LcdDrawCharsFine(LcdPos *pos, const char *str, int size);
void LcdDrawFillCircle(void *center, unsigned short radius);

void DrawHpremoteMenu(void)
{
	LcdPos pos;

	LcdDrawSetForeColor(0);
	LcdDrawSetBackColor(0xFFFFFF);
	LcdDrawClr();
	LcdDrawChars(SetPosition(&pos, 10000, 0), "Hp Remote Test", 4);
	LcdDrawChars(SetPosition(&pos, 4, 1), "[X]      -> Exit", 4);
	LcdDrawChars(SetPosition(&pos, 4, 2), "[SQUARE] -> Suspend", 4);
}




const HpDrawData _hp_draw_data[6] = {
	{ 0x01, 220, 140, "PLAY" },
	{ 0x04, 260, 110, "FF" },
	{ 0x08, 180, 110, "FR" },
	{ 0x10, 300, 140, "+" },
	{ 0x20, 300, 170, "-" },
	{ 0x80, 300, 110, "HOLD" },
};

void _DrawHp(unsigned int bits, int color)
{
	unsigned int i;
	unsigned int j;
	unsigned int fg;
	unsigned int bg;
	LcdPos pos;

	for (i = 0; i < 32; i++) {
		for (j = 0; j < 6; j++) {
			if (((1 << i) & bits) == _hp_draw_data[j].mask) {
				LcdDrawFillCircle((void *)&_hp_draw_data[j].x, color);
				fg = LcdDrawGetForeColor();
				bg = LcdDrawGetBackColor();
				LcdDrawSetForeColor(bg);
				LcdDrawSetBackColor(fg);
				SetPosition(&pos, _hp_draw_data[j].x - strlen(_hp_draw_data[j].name) * 6 / 2, _hp_draw_data[j].y - 4);
				LcdDrawCharsFine(&pos, _hp_draw_data[j].name, 3);
				LcdDrawSetForeColor(fg);
				LcdDrawSetBackColor(bg);
			}
		}
	}
}

void DrawHpOn(unsigned int bits)
{
	LcdDrawSetForeColor(0xFFFF);
	LcdDrawSetBackColor(0xFFFFFF);
	_DrawHp(bits, 15);
}

void DrawHpOff(unsigned int bits)
{
	LcdDrawSetForeColor(0xFF);
	LcdDrawSetBackColor(0xFFFFFF);
	_DrawHp(bits, 15);
}

void DrawHpRemoteExist(int exist)
{
	LcdPos pos;
	char buf[32];

	LcdDrawSetForeColor(0);
	LcdDrawSetBackColor(0xFFFFFF);
	sprintf(buf, "Remote Exist : %d", exist);
	LcdDrawChars(SetPosition(&pos, 5, 9), buf, 4);
}

void DrawHpHeadphoneExist(int exist)
{
	LcdPos pos;
	char buf[32];

	LcdDrawSetForeColor(0);
	LcdDrawSetBackColor(0xFFFFFF);
	sprintf(buf, "Headphone Exist : %d", exist);
	LcdDrawChars(SetPosition(&pos, 5, 10), buf, 4);
}

void DrawHpMicrophoneExist(int exist)
{
	LcdPos pos;
	char buf[32];

	LcdDrawSetForeColor(0);
	LcdDrawSetBackColor(0xFFFFFF);
	sprintf(buf, "Microphone Exist : %d", exist);
	LcdDrawChars(SetPosition(&pos, 5, 11), buf, 4);
}
