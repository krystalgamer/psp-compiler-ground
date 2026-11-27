/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
typedef struct { int number; int offset; int index; } TtrEnt;
typedef struct { char pad[0x7C]; int num; } TtrHead;
void *resArg(void *r, unsigned int i);
extern const char D_000FE730[];
char *strrchr(const char *, int);
void *memset(void *, int, unsigned int);
char *strncpy(char *, const char *, unsigned int);
int atoi(const char *);
extern unsigned char D_000FE6D4, D_000FE6F0, D_000FE6F8, D_000FE718;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", D_000FE6D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", D_000FE6F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", D_000FE6F8);

int ttrGetIndexNum(char **p)
{
	char *ttr_buf = *p;
	char *head;
	if (ttr_buf == NULL)
		consPrintf(&D_000FE6D4, &D_000FE6F8, 0x39, "ttrGetIndexNum", &D_000FE6F0);
	head = ttr_buf;
	if (head == NULL)
		consPrintf(&D_000FE6D4, &D_000FE6F8, 0x3C, "ttrGetIndexNum", &D_000FE718);
	return *(int *)(head + 0x7C);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", D_000FE718);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", ttrGetMaxNumber);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", D_000FE730);

char *ttrGetStringByNumber(TtrHead **p, int number, int *index)
{
	TtrHead *h = *p;
	TtrEnt *tbl = (TtrEnt *)(h + 1);
	int i;
	for (i = 0; i < h->num; i++) {
		if (tbl[i].number == number) {
			if (index) *index = tbl[i].index;
			return (char *)h + tbl[i].offset;
		}
	}
	consPrintf(D_000FE730, "ttrGetStringByNumber", resArg(p, 0), number);
	return NULL;
}

char *ttrGetStringByIndex(TtrHead **p, int idx, int *index, int *number)
{
	TtrHead *h = *p;
	TtrEnt *tbl = (TtrEnt *)(h + 1);
	if (idx < h->num) {
		if (index) *index = tbl[idx].index;
		if (number) *number = tbl[idx].number;
		return (char *)h + tbl[idx].offset;
	}
	consPrintf(D_000FE730, "ttrGetStringByIndex", resArg(p, 0), idx);
	return NULL;
}

char *ttrGetString(TtrHead **p, char *name, int *index)
{
	char buf[128];
	TtrHead *h = *p;
	TtrEnt *tbl = (TtrEnt *)(h + 1);
	char *u;
	int n, i;
	u = strrchr(name, '_');
	if (u == NULL) {
		consPrintf("%s : id systax error `%s'\n", "ttrGetString", name);
		return NULL;
	}
	memset(buf, 0, 128);
	strncpy(buf, name, u - name);
	n = atoi(u + 1);
	for (i = 0; i < h->num; i++) {
		if (tbl[i].number == n) {
			if (index) *index = tbl[i].index;
			return (char *)h + tbl[i].offset;
		}
	}
	consPrintf("%s : index overflow `%s'\n", "ttrGetString", name);
	return NULL;
}
