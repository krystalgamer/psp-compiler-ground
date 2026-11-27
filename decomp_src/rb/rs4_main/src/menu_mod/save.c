/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
   /* extern */

M2C_UNK taskDefaultMsg();
void taskKill();

void menuSaveTask(void) {
    taskDefaultMsg();
}

typedef struct {
	int f0;
	int f4;
	unsigned lo:4;
	unsigned prio:4;
	int pri:8;
	unsigned b16:1;
	unsigned b17:1;
	unsigned b18:1;
	unsigned b19:1;
	unsigned ent:1;
	unsigned rest:11;
	int fC, f10, f14, f18;
} AnmPrm;
int taskMake(int, void (*)(), void *, int);
int gameGetEntry(void);
void *memset(void *, int, unsigned int);
void ezAnmTask();
void GameAnmInit(int parent, int *pt, int arg, int fl, int pri)
{
	AnmPrm q;
	AnmPrm p;
	int t = pt != NULL ? *pt : 0;
	if (t != 0)
		taskKill(t, 0, 0);
	memset(&p, 0, sizeof(p));
	p.f4 = arg;
	p.prio = 1;
	p.pri = pri;
	p.b16 = fl & 1;
	p.b17 = (fl >> 2) & 1;
	p.b18 = (fl >> 1) & 1;
	p.b19 = (fl >> 3) & 1;
	p.ent = gameGetEntry();
	q = p;
	t = taskMake(parent, ezAnmTask, &q, 0);
	if (pt != NULL)
		*pt = t;
}

void GameAnmTerm(int a, int *p)
{
	if (p) {
		int t = *p;
		*p = 0;
		if (t)
			taskKill(t, 0, 0);
	}
}
