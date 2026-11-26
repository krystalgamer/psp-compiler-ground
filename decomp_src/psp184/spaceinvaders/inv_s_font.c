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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_font", ASC_SetStringRGBALEN);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_font", ASC_SetStringRGBA);

#ifndef NULL
#define NULL ((void *)0)
#endif

void ASC_SetString(int arg0, int arg1, int arg2) {
    ASC_SetStringRGBA(8, arg0, arg1, arg2, 0xFF, 0xFF, 0xFF, 0xFF);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_font", ASC_Disp);
