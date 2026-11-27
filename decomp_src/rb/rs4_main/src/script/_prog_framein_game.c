/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

void consPrintf(const char *, ...);
void *_memAllocZero(int, const char *, int);
void *resGetDatLocal(int, int);
void *bxAnmInit(void *);
void bxAnmSetLoop(void *, int);
int gameGetGameMode(void);
int gameGetAdvantage(void);
int gameGetEntry(void);
int *gameGetCntx(void);
int *localeGetCntx(void);
int fontInit(int, int, int);
int fontTerm(void);
int i3dImgGetWidth(void *);
int i3dImgGetHeight(void *);
void *memset(void *, int, unsigned int);
void *fontImgInit(void *);
float fontGetStrWidth(void *, void *, int);
float fontGetCharHeight(void *);
int fontSetPos(void *, void *);
int fontImgStr(void *, void *, int);
int fontImgTerm(void *);

typedef struct { char d[0xB60]; } FICard;
int cardlistGetOneByInstructID(FICard *, int);
typedef struct { unsigned short off; unsigned short res; float sx; int len; } FIEnt;
extern int D_00112208[];
extern FIEnt D_00112210[2][7];
typedef struct { float x, y, z, w; } FIPos;
typedef struct { void *a0; void *a1; void *a2; } FIWork;

#define cassert(e, l) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/script/_prog_framein_game.c", l, "_ProgFrameIn_InitGame", #e)

FIWork *_ProgFrameIn_InitGame(void)
{
	FICard card;
	FIPos pos;
	FIWork *Wp = _memAllocZero(12, "src/script/_prog_framein_game.c", 0x11);
	int k, side;
	unsigned int i;
	void *a0, *a1;
	cassert(Wp, 0x12);
	k = 0x15A;
	side = gameGetAdvantage() != gameGetEntry();
	if (gameGetGameMode() == 1)
		k = gameGetEntry() == 0 ? 0x15B : 0x15D;
	a0 = bxAnmInit(resGetDatLocal(2, 0x1AF));
	a1 = bxAnmInit(resGetDatLocal(2, D_00112208[side]));
	Wp->a2 = bxAnmInit(resGetDatLocal(2, k));
	Wp->a1 = a1;
	Wp->a0 = a0;
	bxAnmSetLoop(a0, 0);
	cardlistGetOneByInstructID(&card, gameGetCntx()[0x4C / 4]);
	fontInit(localeGetCntx()[0x24 / 4], localeGetCntx()[0x28 / 4], localeGetCntx()[0x2C / 4]);
	for (i = 0; i < 7; i++) {
		FIEnt *e = &D_00112210[side][i];
		char *str = card.d + e->off;
		void *img = resGetDatLocal(2, e->res);
		void *f;
		float w = i3dImgGetWidth(img);
		float h = i3dImgGetHeight(img);
		memset(&pos, 0, 16);
		f = fontImgInit(img);
		w -= fontGetStrWidth(f, str, e->len);
		h -= fontGetCharHeight(f);
		pos.x = w * e->sx;
		pos.y = h * 0.5f;
		fontSetPos(f, &pos);
		fontImgStr(f, str, e->len);
		fontImgTerm(f);
	}
	fontTerm();
	return Wp;
}
