/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern int pCurrent;

extern unsigned char D_000FC050, D_000FC058, D_000FC0A8;
int rsvTerm();
int _memFree();

M2C_UNK taskKill(void *, int, int);
int taskKill();

void taskProc();

void consPrintf(const char *, ...);

void rsvMove();
M2C_UNK sortPrio(void **, M2C_UNK, M2C_UNK, M2C_UNK, void ***);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC050);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC058);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC068);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC070);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC08C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC098);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC0A8);

int taskTerm(int *task)
{
	consPrintf(&D_000FC050, "taskTerm");
	rsvTerm(task[0]);
	_memFree(task[1], &D_000FC058, 0x43);
	task[0] = 0;
	task[1] = 0;
	_memFree(task, &D_000FC058, 0x47);
	pCurrent = pCurrent == (int)task ? 0 : pCurrent;
	consPrintf(&D_000FC0A8);
	return 1;
}

int taskSwitchCntx(int arg0) {
    int temp_v0;

    temp_v0 = pCurrent;
    pCurrent = arg0;
    return temp_v0;
}

int taskRest(void)
{
	int r = 0;
	if (pCurrent)
		r = (*(int **)pCurrent)[7];
	return r;
}

int taskHead(void)
{
	int r = 0;
	if (pCurrent)
		r = **(int **)pCurrent;
	return r;
}

int taskHeadAlive(void)
{
	if (pCurrent)
		return rsvHeadAlive(*(int *)pCurrent);
	return 0;
}

void taskProc(arg0)
    void *arg0;
{
    M2C_FIELD(arg0, M2C_UNK (**)(), 8)();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskMake);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC0C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC0C8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskKill);

                 /* extern */

void taskKillReflexive(void *arg0, int arg1, int arg2) {
    void *temp_s0;
    void *var_v1;

    var_v1 = M2C_FIELD(arg0, void **, 0x1C);
    if (var_v1 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_v1, void **, 0x14);
            if (M2C_FIELD(var_v1, int *, 4) > 0) {
                taskKillReflexive(var_v1, arg1, arg2);
            }
            var_v1 = temp_s0;
        } while (temp_s0 != NULL);
    }
    taskKill(arg0, arg1, arg2);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskKillChild);

int taskDefaultMsg(int task, unsigned int msg, int p1, int p2)
{
	switch (msg) {
	case 0:
		return task;
	case 4:
		return task;
	case 5:
		return taskKill(task, p1, p2);
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskAllFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskSendProc);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC1C0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskSendTag);

int taskSendParent(int *t, int a, int b, int c)
{
	return taskSendTag(t, 0xA, t[4], -1, a, b, c);
}

int taskSendElder(int *t, int a, int b, int c)
{
	return taskSendTag(t, 0xB, t[5], 0x14, a, b, c);
}

int taskSendYoung(int *t, int a, int b, int c)
{
	return taskSendTag(t, 0xC, t[6], 0x18, a, b, c);
}

int taskSendChild(int *t, int a, int b, int c)
{
	return taskSendTag(t, 0xD, t[7], 0x14, a, b, c);
}

void taskSendReflexive(void *task, int a, int b, int c)
{
	void *t;
	void *next;
	for (t = M2C_FIELD(task, void **, 0x1C); t != NULL; t = next) {
		next = M2C_FIELD(t, void **, 0x14);
		if (M2C_FIELD(t, int *, 4) > 0) {
			taskSendReflexive(t, a, b, c);
		}
	}
	taskProc(task, a, b, c);
}

int taskProc_Move(int a, int b, int c)
{
	taskProc(a, 2, b, c);
	return 0;
}

int taskProc_Free(int a, int b, int c)
{
	taskProc(a, 1, b, c);
	return 0;
}

void taskMove(void *a, void *b, int c, int d)
{
	if (pCurrent)
		rsvMove(*(int *)pCurrent, a ? a : (void *)taskProc_Move, b ? b : (void *)taskProc_Free, c, d);
}

 /* extern */

int taskProc_Sort(void ***arg0, void **arg1) {
    void **temp_v0;
    void **temp_v0_2;
    void **var_a1;

    var_a1 = arg1;
    if (var_a1 != NULL) {
        do {
            temp_v0_2 = *arg0;
            *arg0 = var_a1;
            M2C_FIELD(var_a1, void ***, 0x20) = temp_v0_2;
            temp_v0 = rsvNextAlive(var_a1);
            var_a1 = temp_v0;
        } while (temp_v0 != NULL);
    }
    sortPrio(*arg0, 0x24, 0x20, 0x20, arg0);
    return 0;
}

int taskProc_Draw(int a, int b, int c)
{
	taskProc(a, 3, b, c);
	return 0;
}

void taskDraw(void (*sort)(char **, void *, int, int), void (*draw)(char *, int, int), int a, int b)
{
	char *list;
	char *t;
	void (*d)(char *, int, int);
	if (sort == NULL)
		sort = (void (*)(char **, void *, int, int))taskProc_Sort;
	d = draw;
	if (d == NULL)
		d = (void (*)(char *, int, int))taskProc_Draw;
	list = NULL;
	sort(&list, taskHeadAlive(), a, b);
	for (t = list; t; t = *(char **)(t + 0x20))
		d(t, a, b);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskSetRefer);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC1E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC1F0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskGetRefer);
