/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
                            /* extern */
void consPrintf(const char *, ...);
typedef struct RsvNode { struct RsvNode *Next; int Key; } RsvNode;
typedef struct { RsvNode *Head; RsvNode *Tail; RsvNode *Free; int Key; RsvNode *Top; int Size; int Num; int Rest; } RsvCntx;

extern unsigned char D_000FB180, D_000FB19C, D_000FB210;
void *rsvNextAlive();
void consPrintf(const char *, ...);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB180);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB19C);

void *_memAlloc(int size, const char *file, int line);
extern unsigned char D_000FB1D0, D_000FB1C8;
RsvCntx *rsvInit(int Size, int Num)
{
	RsvCntx *pCntx;
	RsvNode *p, *pNext;
	int size;
	int n;

	if (Size <= 0)
		consPrintf(&D_000FB180, &D_000FB19C, 0x19, "rsvInit", "Size > 0");
	if (Num <= 0)
		consPrintf(&D_000FB180, &D_000FB19C, 0x1A, "rsvInit", "Num > 0");
	size = Size * Num + 0x20;
	pCntx = _memAlloc(size, &D_000FB19C, 0x1E);
	if (pCntx == NULL)
		consPrintf(&D_000FB180, &D_000FB19C, 0x1F, "rsvInit", &D_000FB1C8);
	consPrintf(&D_000FB1D0, "rsvInit", pCntx, size);
	p = (RsvNode *)(pCntx + 1);
	pCntx->Key = 0x7FFFFFFF;
	pCntx->Head = NULL;
	pCntx->Tail = NULL;
	pCntx->Free = p;
	pCntx->Top = p;
	pCntx->Size = Size;
	pCntx->Num = Num;
	pCntx->Rest = Num;
	for (n = Num; n != 0; n--) {
		pNext = n < 2 ? NULL : (RsvNode *)((char *)p + Size);
		p->Next = pNext;
		p->Key = 0;
		p = pNext;
	}
	return pCntx;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB1C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB1D0);

extern unsigned char D_000FB1C8;
int _memFree(void *, void *, int);
int rsvTerm(void *p)
{
	if (p == NULL)
		consPrintf(&D_000FB180, &D_000FB19C, 0x43, "rsvTerm", &D_000FB1C8);
	consPrintf("%s : 0x%08x\n", "rsvTerm", p);
	_memFree(p, &D_000FB19C, 0x47);
	return 1;
}

void *rsvHeadAlive(void **arg0) {
    void *p = *arg0;
    int s;
    if (p == NULL) return NULL;
    s = M2C_FIELD(p, int *, 4);
    if (s == 0) {
        consPrintf(&D_000FB180, &D_000FB19C, 0x56, "rsvHeadAlive", &D_000FB210);
    }
    if (s > 0) return p;
    return rsvNextAlive(p);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB210);

void *rsvNextAlive(void **p) {
    int s;
    if (p != NULL) {
        while ((p = *p) != NULL) {
            s = ((int *)p)[1];
            if (s == 0) {
                consPrintf(&D_000FB180, &D_000FB19C, 0x67, "rsvNextAlive", &D_000FB210);
            }
            if (s > 0) break;
        }
    }
    return p;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", rsvCall);

int rsvKill(void *arg0) {
    int temp_s0;
    int var_v0;

    temp_s0 = M2C_FIELD(arg0, int *, 4);
    if (temp_s0 == 0) {
        consPrintf(&D_000FB180, &D_000FB19C, 0xA1, "rsvKill", &D_000FB210);
    }
    var_v0 = 0;
    if (temp_s0 > 0) {
        M2C_FIELD(arg0, int *, 4) = (int) ~temp_s0;
        var_v0 = 1;
    }
    return var_v0;
}

RsvNode *rsvFree(RsvCntx *pCntx, RsvNode *pPrev, RsvNode *p)
{
	RsvNode *pNext;

	pCntx->Rest++;
	if (pCntx->Rest <= 0)
		consPrintf(&D_000FB180, &D_000FB19C, 0xB6, "rsvFree", "pCntx->Rest > 0");
	if (pCntx->Rest > pCntx->Num)
		consPrintf(&D_000FB180, &D_000FB19C, 0xB7, "rsvFree", "pCntx->Rest <= pCntx->Num");
	pNext = p->Next;
	if (pPrev != NULL)
		pPrev->Next = pNext;
	else
		pCntx->Head = pNext;
	if (pNext == NULL)
		pCntx->Tail = pPrev;
	p->Key = 0;
	{
		RsvNode *f = pCntx->Free;
		pCntx->Free = p;
		p->Next = f;
	}
	return pNext;
}

int rsvDummy(void) {
    return 0;
}

void rsvMove(RsvCntx *pCntx, void (*fnAlive)(void *, int, int), void (*fnDead)(void *, int, int), int a, int b)
{
	RsvNode *pPrev = NULL;
	RsvNode *p;
	int s;
	void (*fa)(void *, int, int);
	void (*fd)(void *, int, int);
	void (*f0)(void *, int, int);

	f0 = (void (*)(void *, int, int))rsvDummy;
	fa = fnAlive ? fnAlive : f0;
	fd = fnDead ? fnDead : f0;
	p = pCntx->Head;
	while (p != NULL) {
		s = p->Key;
		if (s == 0)
			consPrintf(&D_000FB180, &D_000FB19C, 0xED, "rsvMove", &D_000FB210);
		if (s > 0) {
			pPrev = p;
			fa(p, a, b);
			p = p->Next;
		} else {
			fd(p, a, b);
			p = rsvFree(pCntx, pPrev, p);
		}
	}
}

void rsvLoop(void **head, void (*fn)(void *, int, int), int a, int b)
{
	void **p;
	int s;
	void (*f)(void *, int, int);
	f = (void (*)(void *, int, int))rsvDummy;
	if (fn)
		f = fn;
	for (p = *head; p; p = *p) {
		s = ((int *)p)[1];
		if (s == 0)
			consPrintf(&D_000FB180, &D_000FB19C, 0x109, "rsvLoop", &D_000FB210);
		if (s > 0)
			f(p, a, b);
	}
}

int rsvKeyState(int *p, int k)
{
	if (k <= 0)
		return 1;
	if (!p)
		return 0;
	if ((k ^ p[1]) == 0)
		return 2;
	if ((k ^ p[1]) == -1)
		return 3;
	return 4;
}
