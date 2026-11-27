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
void *ActorGetTask(void *, int);
int resGetSizeTable(int, int);
void *resGetPtrTable(int, int);
extern int D_00112374[];
extern int D_00112380[];
int *localeGetCntx(void);
int fontInit(int, int, int);
int fontTerm(void);
char *menuGetCntx(void);
int i3dImgGetWidth(void *);
int i3dImgGetHeight(void *);
void *memset(void *, int, unsigned int);
void *fontImgInit(void *);
float fontGetStrWidth(void *, void *, int);
float fontGetCharHeight(void *);
int fontSetPos(void *, void *);
int fontImgStr(void *, void *, int);
int fontImgTerm(void *);
typedef struct { float x, y, z, w; } NameFPos;

typedef struct { int x, y, z, w; } NamePos;
typedef struct { int res; int idx; } NameRes;
typedef struct { void *actor; void *anm; } NameWork;
typedef struct { char pad[0x30]; NameRes *res; } NameProg;
typedef struct { char pad[0x10]; NameProg *prog; char pad14[0x50 - 0x14]; float x; float y; } NameTask;

#define cassert(e, l) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/script/_prog_name_tgs.c", l, "_ProgName_InitTgs", #e)

NameWork *_ProgName_InitTgs(NameTask *Tp, void *actor, int no)
{
	NameProg *Pp = Tp->prog;
	NameWork *Wp = _memAllocZero(8, "src/script/_prog_name_tgs.c", 0x1F);
	int k;
	NameRes *r;
	int a, b;
	unsigned int i;
	int *t;
	NamePos *p;
	cassert(Wp, 0x20);
	k = no;
	if (no == 1) {
		switch (gameGetGameMode()) {
		case 0:
		case 3:
			k = 2;
			break;
		case 1:
		case 2:
		case 4:
			break;
		}
	}
	Wp->anm = bxAnmInit(resGetDatLocal(2, D_00112374[k]));
	bxAnmSetLoop(Wp->anm, 0);
	fontInit(localeGetCntx()[0x24 / 4], localeGetCntx()[0x28 / 4], localeGetCntx()[0x2C / 4]);
	for (i = 0; i < 2; i++) {
		char *mc = menuGetCntx() + i * 0x304 + 0x4C;
		void *img = resGetDatLocal(2, D_00112380[i]);
		void *f;
		float w = i3dImgGetWidth(img);
		float h = i3dImgGetHeight(img);
		NameFPos pos;
		memset(&pos, 0, 16);
		f = fontImgInit(img);
		w -= fontGetStrWidth(f, mc, 32);
		h -= fontGetCharHeight(f);
		pos.x = w * 0.5f;
		pos.y = h * 0.5f;
		fontSetPos(f, &pos);
		fontImgStr(f, mc, 32);
		fontImgTerm(f);
	}
	fontTerm();
	if (actor) {
		Wp->actor = actor;
		Tp->x = 95.0f;
		Tp->y = 0;
	} else {
		r = Pp->res;
		Wp->actor = ActorGetTask(r, no);
		a = r->res;
		b = r->idx;
		if (resGetSizeTable(a, b) >= 9) {
			t = resGetPtrTable(a, b);
			p = resGetPtrTable(a, t[8]);
			Tp->x = p[no].x;
			Tp->y = p[no].y;
		} else {
			Tp->y = 0;
			Tp->x = 95.0f;
		}
	}
	return Wp;
}
