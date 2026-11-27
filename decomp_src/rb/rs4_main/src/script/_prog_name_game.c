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
extern int D_00112368[];

typedef struct { int x, y, z, w; } NamePos;
typedef struct { int res; int idx; } NameRes;
typedef struct { void *actor; void *anm; } NameWork;
typedef struct { char pad[0x30]; NameRes *res; } NameProg;
typedef struct { char pad[0x10]; NameProg *prog; char pad14[0x50 - 0x14]; float x; float y; } NameTask;

#define cassert(e, l) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/script/_prog_name_game.c", l, "_ProgName_InitGame", #e)

NameWork *_ProgName_InitGame(NameTask *Tp, void *actor, int no)
{
	NameProg *Pp = Tp->prog;
	NameWork *Wp = _memAllocZero(8, "src/script/_prog_name_game.c", 0x1F);
	int k;
	NameRes *r;
	int a, b;
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
	Wp->anm = bxAnmInit(resGetDatLocal(2, D_00112368[k]));
	bxAnmSetLoop(Wp->anm, 0);
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
