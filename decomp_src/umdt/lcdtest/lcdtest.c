/* cflags: -O0 */
#include "common.h"

int sprintf(char *buf, const char *fmt, ...);
unsigned int strlen(const char *s);
int sceIoWrite(int fd, const void *buf, unsigned int size);
int sceDisplayWaitVblankStart(void);
int sceCtrlReadLatch(unsigned int *latch);
void LcdDrawSetBrightness(int level, int unk);
void LcdDrawSetBackColor(unsigned int color);
void LcdDrawClr(void);
void LcdDrawPtnUpDownColor(unsigned int up, unsigned int down);
void LcdDrawPtnFLMoire(void);
void LcdDrawPtnFLMoire2(void);
void LcdDrawPtnColorBar(void);
void LcdDrawPtnColorscale16(void);
void LcdDrawPtnColorscaleMax(void);
void LcdDrawPtnGrayscale8(void);
void LcdDrawPtnGrayscale16(void);
void LcdDrawPtnGrayscaleMax(void);
void LcdDrawPtnHs(unsigned int fg, unsigned int bg);
void LcdDrawPtnHs2(unsigned int fg, unsigned int bg);

void LcdDrawPtn4Product(unsigned int ptn)
{
	switch (ptn) {
	case 1:
		LcdDrawSetBrightness(100, 0);
		LcdDrawSetBackColor(0);
		LcdDrawClr();
		break;
	case 2:
		LcdDrawPtnUpDownColor(0xFF, 0xFF0000);
		break;
	case 3:
		LcdDrawPtnUpDownColor(0xFF0000, 0xFF00);
		break;
	case 4:
		LcdDrawPtnUpDownColor(0xFF00, 0xFF);
		break;
	case 5:
		LcdDrawSetBrightness(100, 0);
		LcdDrawSetBackColor(0xFFFFFF);
		LcdDrawClr();
		break;
	case 6:
		LcdDrawSetBrightness(24, 0);
		LcdDrawSetBackColor(0xFFFFFF);
		LcdDrawClr();
		break;
	case 7:
		LcdDrawSetBrightness(100, 0);
		LcdDrawPtnFLMoire2();
		break;
	case 8:
		LcdDrawPtnColorBar();
		break;
	case 9:
		LcdDrawPtnColorscaleMax();
		break;
	case 0:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
		break;
	}
}


int LcdTest4Product(int product)
{
	int unused0;
	int unused1;
	int a = 1;
	int b = 1;
	int c = 25;
	int d = 25;
	int ptn = 1;
	unsigned int pad[4];
	unsigned int ctrl[4];
	char msg0[112];
	char msg1[112];

	sprintf(msg0, "LCD TEST Start\n");
	sceIoWrite(0, msg0, strlen(msg0));
	LcdDrawPtn4Product(ptn);
	while (ptn) {
		sceDisplayWaitVblankStart();
		if (sceCtrlReadLatch(ctrl)) {
			if (ctrl[1] & 0x80) {
				if (ptn != 1) {
					ptn--;
					LcdDrawPtn4Product(ptn);
				}
			} else if (ctrl[1] & 0x2000) {
				if (ptn == 9) {
					ptn = 0;
				} else {
					ptn++;
					LcdDrawPtn4Product(ptn);
				}
			}
		}
	}
	sprintf(msg1, "LCD TEST End\n");
	sceIoWrite(0, msg1, strlen(msg1));
	return 0;
}

void LcdDrawPtn(unsigned int ptn)
{
	switch (ptn) {
	case 1:
		LcdDrawPtnColorBar();
		break;
	case 2:
		LcdDrawPtnGrayscale8();
		break;
	case 3:
		LcdDrawPtnGrayscale16();
		break;
	case 4:
		LcdDrawPtnGrayscaleMax();
		break;
	case 5:
		LcdDrawPtnFLMoire();
		break;
	case 6:
		LcdDrawPtnFLMoire2();
		break;
	case 7:
		LcdDrawPtnHs(0xFFFFFF, 0);
		break;
	case 8:
		LcdDrawPtnHs(0, 0xFFFFFF);
		break;
	case 9:
		LcdDrawPtnHs2(0xFFFFFF, 0);
		break;
	case 10:
		LcdDrawPtnHs2(0, 0xFFFFFF);
		break;
	case 11:
		LcdDrawPtnColorscale16();
		break;
	case 12:
		LcdDrawPtnColorscaleMax();
		break;
	case 13:
		LcdDrawSetBackColor(0xFF);
		LcdDrawClr();
		break;
	case 14:
		LcdDrawSetBackColor(0xFF00);
		LcdDrawClr();
		break;
	case 15:
		LcdDrawSetBackColor(0xFF0000);
		LcdDrawClr();
		break;
	case 16:
		LcdDrawSetBackColor(0xFFFFFF);
		LcdDrawClr();
		break;
	case 17:
		LcdDrawSetBackColor(0);
		LcdDrawClr();
		break;
	}
}

void LcdTestVersion(char *buf)
{
	sprintf(buf, "Ver. 041028_1");
}

int LcdTest(int mode)
{
	int unused0;
	int unused1;
	int a = 1;
	int b = 1;
	int c = 25;
	int d = 25;
	int ptn = 1;
	unsigned int pad[4];
	unsigned int ctrl[4];
	char msg0[112];
	char msg1[112];

	sprintf(msg0, "LCD TEST Start\n");
	sceIoWrite(0, msg0, strlen(msg0));
	LcdDrawPtn(ptn);
	while (ptn) {
		sceDisplayWaitVblankStart();
		if (sceCtrlReadLatch(ctrl)) {
			if ((ctrl[1] & 0x10) && ptn != 17) {
				ptn++;
				LcdDrawPtn(ptn);
			}
			if ((ctrl[1] & 0x40) && ptn != 1) {
				ptn--;
				LcdDrawPtn(ptn);
			}
			if (ctrl[1] & 0x2000) {
				if (ptn == 17)
					ptn = 1;
				else
					ptn++;
				LcdDrawPtn(ptn);
			}
			if (ctrl[1] & 0x4000)
				ptn = 0;
		}
	}
	sprintf(msg1, "End\n");
	sceIoWrite(0, msg1, strlen(msg1));
	return 0;
}

int LcdTestEntry(int a, int b)
{
	return 0;
}

