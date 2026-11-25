#include "common.h"
#include <stdio.h>
#include <stdarg.h>
#include <libgu.h>
#include "xpdebugprint.h"

/* the font tables of offset.h and font_data.h stay in the asm .data */

void xpDpPrintfSub(int nXpos, int nYpos, char *pStr);

extern int nSizeW;
extern int nSizeH;
extern int nFontColor;
extern int nFontCode;
extern short unsigned int kanji_0_table[20][2];
extern short unsigned int kanji_1_table[33][2];
extern unsigned int font_body[32768];
extern unsigned int font_clut[64];
extern unsigned char ASCII2SJIS[191];

int xpDpSetFontCode(int nCode)
{
	int nOldCode;

	nOldCode = nFontCode;
	nFontCode = nCode;
	return nOldCode;
}

void xpDpSetFontSize(int nWidth, int nHeight)
{
	nSizeW = nWidth;
	nSizeH = nHeight;
}

void xpDpGetFontSize(int *pWidth, int *pHeight)
{
	*pWidth = nSizeW;
	*pHeight = nSizeH;
}

int xpDpSetFontColor(int nColor)
{
	int nOldColor;

	nOldColor = nFontColor;
	nFontColor = nColor;
	return nOldColor;
}

int xpDpGetFontColor()
{
	return nFontColor;
}

void xpDpPrintf(int nXpos, int nYpos, char *pFormat, ...)
{
	va_list vlist;
	char strBuff[2048];

	va_start(vlist, pFormat);
	vsprintf(strBuff, pFormat, vlist);
	va_end(vlist);
	if (nFontCode == XP_DP_FONTCODE_EUC)
		xpDpEuc2Sjis(strBuff, strBuff);
	xpDpPrintfSub(nXpos, nYpos, strBuff);
}

int xpDpPrintfLineLimit(int nXpos, int nYpos, int nLimit, char *pFormat, ...)
{
	va_list vlist;
	int nLineNum;
	char strBuff[2048];
	char strBuff2[2730];

	va_start(vlist, pFormat);
	vsprintf(strBuff, pFormat, vlist);
	va_end(vlist);
	if (nFontCode == XP_DP_FONTCODE_EUC)
		xpDpEuc2Sjis(strBuff, strBuff);
	nLineNum = xpDpLineLimit(strBuff2, nLimit, strBuff);
	xpDpPrintfSub(nXpos, nYpos, strBuff2);
	return nLineNum;
}

int xpDpCheckLineLimit(int nLimit, char *pFormat, ...)
{
	va_list vlist;
	int nLineNum;
	char strBuff[2048];
	char strBuff2[2730];

	va_start(vlist, pFormat);
	vsprintf(strBuff, pFormat, vlist);
	va_end(vlist);
	if (nFontCode == XP_DP_FONTCODE_EUC)
		xpDpEuc2Sjis(strBuff, strBuff);
	nLineNum = xpDpLineLimit(strBuff2, nLimit, strBuff);
	return nLineNum;
}

int xpDpLineLimit(char *pOut, int nLimit, char *pIn)
{
	int nLineNum;
	int nCnt;

	nCnt = 0;
	nLineNum = 1;
	while (*pIn != 0) {
		if (*pIn & 0xe0) {
			if (*pIn < 0) {
				*pOut++ = *pIn++;
				nCnt++;
			}
			*pOut++ = *pIn++;
			nCnt++;
		} else if (*pIn == '\n') {
			*pOut = *pIn;
			nCnt = 0;
			nLineNum++;
			pIn++;
			pOut++;
		} else {
			pIn++;
		}
		if ((nCnt >= nLimit && *pIn != 0) || (*pIn < 0 && nCnt >= nLimit - 1)) {
			*pOut++ = '\n';
			nCnt = 0;
			nLineNum++;
		}
	}
	*pOut = 0;
	return nLineNum;
}

int xpDpCheckStrEx(char *pIn, int *pCol, int *pLine)
{
	int nLineNum;
	int nCol;
	int nCnt;

	nCnt = 0;
	nLineNum = 1;
	nCol = 0;
	while (*pIn != 0) {
		if (*pIn & 0xe0) {
			if (*pIn < 0) {
				pIn++;
				nCnt++;
			}
			pIn++;
			nCnt++;
		} else {
			if (*pIn == '\n') {
				if (nCnt > nCol)
					nCol = nCnt;
				nLineNum++;
				nCnt = 0;
			}
			pIn++;
		}
	}
	if (nCnt > nCol)
		nCol = nCnt;
	*pCol = nCol;
	*pLine = nLineNum;
	return nLineNum;
}

void xpDpEuc2Sjis(char *pEucIn, char *pSjisOut)
{
	unsigned char nCodeHigh;
	unsigned char nCodeLow;

	while (*pEucIn != 0) {
		nCodeHigh = *pEucIn++;
		if ((char)nCodeHigh >= 0) {
			*pSjisOut = nCodeHigh;
		} else if (nCodeHigh == 0x8e) {
			*pSjisOut = *pEucIn++;
		} else {
			nCodeLow = *pEucIn++;
			if (nCodeHigh & 1) {
				nCodeHigh >>= 1;
				if (nCodeHigh < 0x6f)
					nCodeHigh += 0x31;
				else
					nCodeHigh += 0x71;
				if (nCodeLow >= 0xe0)
					nCodeLow -= 0x60;
				else
					nCodeLow -= 0x61;
			} else {
				nCodeHigh >>= 1;
				if (nCodeHigh < 0x6f)
					nCodeHigh += 0x30;
				else
					nCodeHigh += 0x70;
				nCodeLow -= 2;
			}
			*pSjisOut++ = nCodeHigh;
			*pSjisOut = nCodeLow;
		}
		pSjisOut++;
	}
	*pSjisOut = 0;
}

#ifdef NON_MATCHING
/* Close: the main loop's blocks are laid out differently and nXpos is not
   spilled. */
void xpDpPrintfSub(int nXpos, int nYpos, char *pStr)
{
	int i;
	int x_pos;
	int y_pos;
	int nPrintW;
	int nCode;
	int nClut;
	int nU;
	int nV;
	unsigned char *pPtr;

	x_pos = nXpos;
	y_pos = nYpos;
	pPtr = (unsigned char *)pStr;
	sceGuEnable(9);
	sceGuTexMode(4, 0, 0, 1);
	sceGuTexImage(0, 512, 512, 512, font_body);
	sceGuTexFilter(1, 1);
	sceGuTexFunc(0, 1);
	sceGuTexWrap(1, 1);
	sceGuTexOffset(0.0f, 0.0f);
	sceGuTexScale(1.0f, 1.0f);
	sceGuClutMode(3, 0, 0xff, 0);
	sceGuClutLoad(32, font_clut);
	sceGuTexFlush();
	sceGuEnable(4);
	sceGuDepthFunc(1);
	sceGuDepthMask(1);
	sceGuAlphaFunc(6, 0, 0xff);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuColor(nFontColor);
	while (*pPtr != 0) {
		nCode = *pPtr;
		if ((nCode & 0xe0) == 0) {
			if (nCode == '\n') {
				x_pos = nXpos;
				y_pos += nSizeH;
			}
			pPtr++;
			continue;
		}
		if ((char)*pPtr < 0) {
			pPtr++;
			nPrintW = nSizeW;
			nCode = (nCode << 8) + *pPtr;
		} else {
			nCode = (ASCII2SJIS[(nCode - 0x20) * 2] << 8) | ASCII2SJIS[(nCode - 0x20) * 2 + 1];
			nPrintW = nSizeW >> 1;
		}
		if (nCode > 0x9872)
			nCode = 0x81a1;
		if (nCode < kanji_1_table[0][0]) {
			for (i = 1; nCode >= kanji_0_table[i][0]; i++)
				;
			i--;
			nCode = nCode - kanji_0_table[i][0] + kanji_0_table[i][1];
		} else {
			for (i = 1; nCode >= kanji_1_table[i][0]; i++)
				;
			i--;
			if ((kanji_1_table[i][0] & 0xff) < 0x80 && (nCode & 0xff) >= 0x80)
				nCode--;
			nCode = nCode - kanji_1_table[i][0] + kanji_1_table[i][1] + 0x20c;
		}
		nClut = nCode & 3;
		nCode >>= 2;
		nU = (nCode & 0xf) << 4;
		if (nCode & 0x200)
			nU += 0x100;
		sceGuClutMode(3, 0, 0xff, nClut);
		nV = nCode & 0x1f0;
		sceGuSpriteMode(16, 16, nPrintW, nSizeH);
		sceGuDrawSprite(x_pos, y_pos, 0x8000, nU, nV, 0, 0);
		x_pos += nPrintW;
		pPtr++;
	}
	sceGuDepthMask(0);
	sceGuDepthFunc(6);
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/xpdebugprint", xpDpPrintfSub);
#endif
