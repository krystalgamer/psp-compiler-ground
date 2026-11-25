#include "common.h"
#include <libfont.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pspBrowser.h"
#include "main.h"
#include "message.h"

int utf8ToUcs2(SceFont_t_charCode *ucs2, char *utf8, int len);

extern char myImageBuffer[16384];
extern SceFont_t_fontId fontID;
extern SceFont_t_libId libFontID;
extern SceFont_t_fontInfo fontInfo;

/* fontPrint's and fontPassword's "static SceFont_t_charCode moji[...]",
   kept in the asm .bss for now */
extern SceFont_t_charCode D_002198F0[320];
extern SceFont_t_charCode D_001EDEC0[2];

static SceFont_t_pointer cb_Alloc(SceFont_t_pointer pMyData, SceFont_t_u32 size)
{
	return malloc(size);
}

static void cb_Free(SceFont_t_pointer pMyData, SceFont_t_pointer p)
{
	free(p);
}

int fontInit(void)
{
	int i;
	SceFont_t_error errorCode;
	SceFont_t_initRec initParams = {
		NULL, 4, NULL, cb_Alloc, cb_Free, NULL, NULL, NULL, NULL, NULL, NULL,
	};
	SceFont_t_int numFontList;
	SceFont_t_fontStyleInfo aFontStyleInfoList[30];

	puts("sceFontNewLib");
	libFontID = sceFontNewLib(&initParams, &errorCode);
	if (errorCode != 0) {
		fprintf(stderr, "A, %8.8x\n", errorCode);
		return -1;
	}
	numFontList = sceFontGetNumFontList(libFontID, &errorCode);
	printf("sceFontGetNumFontList[ %d\n", numFontList);
	if (errorCode != 0) {
		fprintf(stderr, "B, %8.8x\n", errorCode);
		return -1;
	}
	puts("sceFontGetFontList");
	errorCode = sceFontGetFontList(libFontID, aFontStyleInfoList, numFontList);
	if (errorCode != 0) {
		fprintf(stderr, "C, %8.8x\n", errorCode);
		return -1;
	}
	for (i = 0; i < numFontList; i++)
		printf("FONT[ %d ] %f, %f, %s[ %s ]\n", i, aFontStyleInfoList[i].hSize, aFontStyleInfoList[i].vSize,
		       aFontStyleInfoList[i].fontName, aFontStyleInfoList[i].fileName);
	puts("sceFontOpen");
	fontID = sceFontOpen(libFontID, 0, 0, &errorCode);
	if (errorCode != 0) {
		fprintf(stderr, "D, %8.8x\n", errorCode);
		return -1;
	}
	puts("sceFontGetFontInfo");
	errorCode = sceFontGetFontInfo(fontID, &fontInfo);
	if (errorCode != 0) {
		fprintf(stderr, "E, %8.8x\n", errorCode);
		return -1;
	}
	return 0;
}

int fontExit(void)
{
	SceFont_t_error errorCode;

	errorCode = sceFontClose(fontID);
	if (errorCode != 0) {
		fprintf(stderr, "H, %8.8x\n", errorCode);
		return -1;
	}
	errorCode = sceFontDoneLib(libFontID);
	if (errorCode != 0) {
		fprintf(stderr, "I, %8.8x\n", errorCode);
		return -1;
	}
	return 0;
}

int fontCls(int in_start, int in_size)
{
	memset(myImageBuffer + in_start / 2, 0, in_size / 2);
	return 0;
}

int fontColorSet(int r, int g, int b)
{
	return 0;
}

int fontImgaeSet(char *image, int width, int height)
{
	return 0;
}

#define moji D_002198F0
int fontPrint(int x, int y, char *str, int s_size, int ww, int hh)
{
	int aa;
	int i;
	int ax;
	SceFont_t_error errorCode;
	SceFont_t_charInfo charInfo;
	SceFont_t_userImageBufferRec myImage;

	aa = utf8ToUcs2(moji, str, s_size);
	ax = x;
	for (i = 0; i < aa; i++) {
		errorCode = sceFontGetCharInfo(fontID, moji[i], &charInfo);
		if (errorCode != 0)
			return -1;
		myImage.pixelFormat = 0;
		myImage.rect.width = 256;
		myImage.rect.height = 128;
		myImage.bytesPerLine = 128;
		myImage.reserved = 0;
		myImage.buffer = (SceFont_t_u8 *)myImageBuffer;
		if (ww < ax + charInfo.bitmapWidth) {
			ax = x;
			y += fontInfo.maxIGlyphMetrics.verticalAdvance64 / 64;
		}
		myImage.xPos64 = ax * 64;
		myImage.yPos64 = (y - charInfo.bitmapTop) * 64 + fontInfo.maxIGlyphMetrics.ascender64;
		errorCode = sceFontGetCharGlyphImage(fontID, moji[i], &myImage);
		if (errorCode != 0)
			return -1;
		ax += charInfo.bitmapWidth;
	}
	return 0;
}
#undef moji

#define moji D_001EDEC0
int fontPassword(int x, int y, char *str, int s_size, int ww, int hh)
{
	int aa;
	int i;
	int ax;
	SceFont_t_error errorCode;
	SceFont_t_charInfo charInfo;
	SceFont_t_userImageBufferRec myImage;

	aa = utf8ToUcs2(NULL, str, s_size);
	errorCode = sceFontGetCharInfo(fontID, moji[0], &charInfo);
	ax = x;
	if (errorCode != 0)
		return -1;
	for (i = 0; i < aa; i++) {
		myImage.pixelFormat = 0;
		myImage.rect.width = 256;
		myImage.rect.height = 128;
		myImage.bytesPerLine = 128;
		myImage.reserved = 0;
		myImage.buffer = (SceFont_t_u8 *)myImageBuffer;
		if (ww < ax + charInfo.bitmapWidth) {
			ax = x;
			y += fontInfo.maxIGlyphMetrics.verticalAdvance64 / 64;
		}
		myImage.xPos64 = ax * 64;
		myImage.yPos64 = (y - charInfo.bitmapTop) * 64 + fontInfo.maxIGlyphMetrics.ascender64;
		errorCode = sceFontGetCharGlyphImage(fontID, moji[0], &myImage);
		if (errorCode != 0)
			return -1;
		ax += charInfo.bitmapWidth;
	}
	return 0;
}
#undef moji

int fontDraw(short int *im, int in_start, int in_size)
{
	short int scolor[16] = {
		0x0000, 0x0421, 0x0842, 0x0c63, 0x1084, 0x14a5, 0x18c6, 0x2108,
		0x2529, 0x294a, 0x2d6b, 0x318c, 0x35ad, 0x39ce, 0x3def, 0x3def,
	};
	int i;
	char *cc;
	char c;

	i = in_size / 2;
	cc = myImageBuffer;
	cc += in_start / 2;
	im += in_start;
	for (; i > 0; i--) {
		c = *cc++;
		*im++ = scolor[c & 0xf];
		*im++ = scolor[(c >> 4) & 0xf];
	}
	return 0;
}
