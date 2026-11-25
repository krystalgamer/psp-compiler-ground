#ifndef XPDEBUGPRINT_H
#define XPDEBUGPRINT_H
/* types recovered from DWARF (tools/dwarfhdr.py) */
enum {
	XP_DP_FONTCODE_SJIS = 0,
	XP_DP_FONTCODE_EUC = 1,
};

int xpDpSetFontCode(int nCode);
void xpDpSetFontSize(int nWidth, int nHeight);
void xpDpGetFontSize(int *pWidth, int *pHeight);
int xpDpSetFontColor(int nColor);
int xpDpGetFontColor();
void xpDpPrintf(int nXpos, int nYpos, char *pFormat, ...);
int xpDpPrintfLineLimit(int nXpos, int nYpos, int nLimit, char *pFormat, ...);
int xpDpCheckLineLimit(int nLimit, char *pFormat, ...);
int xpDpLineLimit(char *pOut, int nLimit, char *pIn);
int xpDpCheckStrEx(char *pIn, int *pCol, int *pLine);
void xpDpEuc2Sjis(char *pEucIn, char *pSjisOut);
#endif
