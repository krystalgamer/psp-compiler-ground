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

void sprite_set(int tex, int x, int y, int w, int h, int u, int v, int sx, int sy, int a0, int a1, int r, int g, int b, int a, int col, int m, int f, int al);
void spr_trans(int src, int dst, int x, int y, int u, int v, int w, int h);
void spr_trans_pal(int src, int dst, int x, int y, int u, int v, int w, int h, int pal);
void ASC_Disp(int *dst, int mode)
{
	ASCBUF *b = (ASCBUF *)&AscBuff;
	int i, x, y, col;
	unsigned int c, u, v;
	unsigned char *p;

	for (i = 0; i < numAscBuf; i++, b++) {
		x = b->x;
		y = b->y;
		for (p = (unsigned char *)b->str; *p != 0; p++, x += 8) {
			c = (unsigned char)(*p - 0x20);
			u = c & 15;
			v = c >> 4;
			if (b->mode & 4) {
				if (mode == 4) {
					if (b->a != 255)
						spr_trans_pal(((int *)ptexsrc_28FB64)[7], dst[7], x, y, u * 8, v * 8, 8, 8, b->a);
					else
						spr_trans(((int *)ptexsrc_28FB64)[7], dst[7], x, y, u * 8, v * 8, 8, 8);
				}
			} else if (b->mode & 8) {
				if (mode == 8) {
					if (b->a != 255)
						spr_trans_pal(((int *)ptexsrc_28FB64)[7], dst[7], x, y, u * 8, v * 8, 8, 8, b->a);
					else
						spr_trans(((int *)ptexsrc_28FB64)[7], dst[7], x, y, u * 8, v * 8, 8, 8);
				}
			} else {
				if (b->mode & 1)
					col = 255;
				else if (b->mode & 2)
					col = 10;
				else
					col = 0;
				sprite_set(tex, x, y, 8, 8, u * 8, v * 8, 100, 100, 0, 0, b->r, b->g, b->b, b->a, col, 2, 1, 255);
			}
		}
	}
}
