/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char AscBuff;
extern int fntCnt;
extern int numAscBuf;
extern M2C_UNK *ptrAscBuf;


extern int ptexsrc_28FB64;
extern int tex;
void ASC_Reset(void);
void *memset(void *, int, unsigned int);

extern int ptexsrc_28FB64;
extern int tex;
void ASC_Reset(void);
void *memset(void *, int, unsigned int);
void ASC_Init(int src, int t)
{
	memset(&AscBuff, 0, 0x780);
	ASC_Reset();
	ptexsrc_28FB64 = src;
	tex = t;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ASC_Reset(void) {
    ptrAscBuf = &AscBuff;
    numAscBuf = 0;
    fntCnt = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);
int ASC_StringRen(signed char *arg0) {
    return strlen(arg0) * 8;
}

typedef struct { char str[32]; int x, y, r, g, b, a, mode; } ASCBUF;
void *memcpy(void *d, const void *s, unsigned int n);
unsigned int strlen(const char *s);
void ASC_SetStringRGBALEN(int mode, char *s, int x, int y, int r, int g, int b, int a, int len)
{
	int l;

	if (numAscBuf >= 32)
		return;
	if (len == 0)
		return;
	l = strlen(s);
	if (l < len)
		return;
	if (len > 31)
		len = 31;
	((ASCBUF *)ptrAscBuf)->x = x;
	((ASCBUF *)ptrAscBuf)->y = y;
	((ASCBUF *)ptrAscBuf)->mode = mode;
	((ASCBUF *)ptrAscBuf)->r = r;
	((ASCBUF *)ptrAscBuf)->g = g;
	((ASCBUF *)ptrAscBuf)->b = b;
	((ASCBUF *)ptrAscBuf)->a = a;
	memcpy(ptrAscBuf, s, len);
	((char *)ptrAscBuf)[l] = 0;
	fntCnt += strlen((char *)ptrAscBuf);
	ptrAscBuf = (M2C_UNK *)((char *)ptrAscBuf + sizeof(ASCBUF));
	numAscBuf++;
}

void ASC_SetStringRGBA(int mode, char *s, int x, int y, int r, int g, int b, int a)
{
	int n;

	if (numAscBuf >= 32)
		return;
	((ASCBUF *)ptrAscBuf)->mode = mode;
	((ASCBUF *)ptrAscBuf)->a = a;
	((ASCBUF *)ptrAscBuf)->y = y;
	((ASCBUF *)ptrAscBuf)->r = r;
	((ASCBUF *)ptrAscBuf)->g = g;
	((ASCBUF *)ptrAscBuf)->b = b;
	((ASCBUF *)ptrAscBuf)->x = x;
	n = strlen(s);
	if (n > 31)
		n = 31;
	memcpy(ptrAscBuf, s, n);
	((char *)ptrAscBuf)[n] = 0;
	fntCnt += strlen((char *)ptrAscBuf);
	ptrAscBuf = (M2C_UNK *)((char *)ptrAscBuf + sizeof(ASCBUF));
	numAscBuf++;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ASC_SetString(int arg0, int arg1, int arg2) {
    ASC_SetStringRGBA(8, arg0, arg1, arg2, 0xFF, 0xFF, 0xFF, 0xFF);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_font", ASC_Disp);
