/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern int pCurrent;

extern unsigned char D_000FC050, D_000FC058, D_000FC0A8;
extern unsigned char D_000FC070, D_000FC0C4, D_000FC1C0, D_000FC1E4, D_000FC1F0;
int rsvTerm();
int _memFree();


int taskKill();

int taskProc(void *, int, void *, int);

void consPrintf(const char *, ...);

void rsvMove();
M2C_UNK sortPrio(void **, M2C_UNK, M2C_UNK, M2C_UNK, void ***);

void *_memAllocZero(int, void *, int);
int rsvInit(int, int);
extern unsigned char D_000FC068, D_000FC08C, D_000FC098;

int *taskInit(int n) {
    int *t;

    consPrintf(&D_000FC050, "taskInit");
    t = _memAllocZero(8, &D_000FC058, 0x2D);
    if (t == NULL) {
        consPrintf(&D_000FC070, &D_000FC058, 0x2E, "taskInit", &D_000FC068);
    }
    t[0] = rsvInit(0x160, n);
    t[1] = (int)_memAllocZero(n * 4, &D_000FC058, 0x31);
    if (t[0] == 0) {
        consPrintf(&D_000FC070, &D_000FC058, 0x32, "taskInit", &D_000FC08C);
    }
    if (t[1] == 0) {
        consPrintf(&D_000FC070, &D_000FC058, 0x33, "taskInit", &D_000FC098);
    }
    consPrintf(&D_000FC0A8);
    return t;
}

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

int taskProc(void *arg0, int msg, void *a, int b)
{
    return M2C_FIELD(arg0, int (**)(void *, int, void *, int), 8)(arg0, msg, a, b);
}

void *rsvCall(int);                                 /* extern */
int coreFunc();
extern signed char D_000FC0C8;

int taskMake(void *arg0, int (*func)(void *, int, int, int), int arg2, int arg3) {
    int st;
    void *t;
    void *c;

    if (pCurrent == 0) return 0;
    t = rsvCall(*(int *)pCurrent);
    if (t != NULL) {
        func = (void *)coreFunc(func);
        M2C_FIELD(t, void **, 8) = func;
        M2C_FIELD(t, int *, 0x1C) = 0;
        M2C_FIELD(t, int *, 0x18) = 0;
        if (arg0 != NULL) {
            st = M2C_FIELD(arg0, int *, 4);
            if (st == 0) {
                consPrintf(&D_000FC070, &D_000FC058, 0xA3, "taskMake", &D_000FC0C4);
            }
            if (st < 0) {
                consPrintf(&D_000FC0C8, "taskMake", M2C_FIELD(arg0, int *, 8));
                M2C_FIELD(t, void **, 0x10) = NULL;
                M2C_FIELD(t, void **, 0x14) = NULL;
            } else {
                c = M2C_FIELD(arg0, void **, 0x1C);
                M2C_FIELD(arg0, void **, 0x1C) = t;
                if (c != NULL) {
                    M2C_FIELD(c, void **, 0x18) = t;
                }
                M2C_FIELD(t, void **, 0x10) = arg0;
                M2C_FIELD(t, void **, 0x14) = c;
            }
        } else {
            M2C_FIELD(t, void **, 0x10) = NULL;
            M2C_FIELD(t, void **, 0x14) = NULL;
        }
    }
    return func(t, 0, arg2, arg3);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC0C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC0C8);

int rsvKill();

int taskKill(void *task, int arg1, int arg2) {
    int *t = task;
    int st;
    int r;
    int *c;
    int *p, *e, *y;

    st = t[1];
    if (st == 0) {
        consPrintf("%s : Warning !! : already free. : 0x%08x\n", "taskKill", t[2]);
        return -1;
    }
    if (st < 0) {
        consPrintf("%s : Warning !! : already killed. : 0x%08x\n", "taskKill", t[2]);
        return -1;
    }
    r = taskProc(t, 4, (void *)arg1, arg2);
    if (r == -1) {
        consPrintf(&D_000FC070, &D_000FC058, 0xD7, "taskKill", "Ret != -1");
    }
    if (r != 0) {
    if (rsvKill(t) != 1) {
        consPrintf("%s : Warning !! : Kill was recurrently done. : 0x%08x\n", "taskKill", t[2]);
        return -1;
    }
    taskSendParent(t, 8, (int) t, arg2);
    taskSendElder(t, 7, (int) t, arg2);
    taskSendYoung(t, 6, (int) t, arg2);
    taskSendChild(t, 5, (int) t, arg2);
    p = (int *)t[4];
    e = (int *)t[5];
    y = (int *)t[6];
    if (p != NULL && (int *)p[7] == t) {
        p[7] = (int)e;
    }
    if (e != NULL) {
        e[6] = (int)y;
    }
    if (y != NULL) {
        y[5] = (int)e;
    }
    for (c = (int *)t[7]; c != NULL; c = (int *)c[5]) {
        st = c[1];
        if (st == 0) {
            consPrintf(&D_000FC070, &D_000FC058, 0xF4, "taskKill", &D_000FC0C4);
        }
        if (st > 0) {
            c[4] = 0;
        }
    }
    t[4] = 0;
    t[5] = 0;
    t[6] = 0;
    t[7] = 0;
    }
    return r;
}

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

int rsvFree(int, M2C_UNK, int);                     /* extern */

void taskAllFree(void) {
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int var_s0;
    int var_s0_2;

    consPrintf(&D_000FC050, "taskAllFree");
    if (pCurrent != NULL) {
        temp_v0 = taskHeadAlive();
        var_s0 = temp_v0;
        if (temp_v0 != 0) {
            do {
                taskKill((void **) var_s0, 0, 0);
                temp_v0_2 = rsvNextAlive((void **) var_s0);
                var_s0 = temp_v0_2;
            } while (temp_v0_2 != 0);
        }
        temp_v0_3 = taskHead();
        var_s0_2 = temp_v0_3;
        if (temp_v0_3 != 0) {
            do {
                taskProc(var_s0_2, 1, 0, 0);
                temp_v0_4 = rsvFree(*(int *)pCurrent, 0, var_s0_2);
                var_s0_2 = temp_v0_4;
            } while (temp_v0_4 != 0);
        }
    }
    consPrintf(&D_000FC0A8);
}

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


int taskSetRefer(int arg0, int arg1) {
    int r = 0;

    if (pCurrent != 0) {
        if (arg0 < 0) {
            consPrintf(&D_000FC070, &D_000FC058, 0x27B, "taskSetRefer", &D_000FC1E4);
        }
        if (arg0 >= M2C_FIELD(M2C_FIELD(pCurrent, void **, 0), int *, 0x18)) {
            consPrintf(&D_000FC070, &D_000FC058, 0x27C, "taskSetRefer", &D_000FC1F0);
        }
        r = 1;
        M2C_FIELD(pCurrent, int **, 4)[arg0] = arg1;
    }
    return r;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC1E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC1F0);

int taskGetRefer(int arg0) {
    int r = 0;

    if (pCurrent != 0) {
        if (arg0 < 0) {
            consPrintf(&D_000FC070, &D_000FC058, 0x28D, "taskGetRefer", &D_000FC1E4);
        }
        if (arg0 >= M2C_FIELD(M2C_FIELD(pCurrent, void **, 0), int *, 0x18)) {
            consPrintf(&D_000FC070, &D_000FC058, 0x28E, "taskGetRefer", &D_000FC1F0);
        }
        r = M2C_FIELD(pCurrent, int **, 4)[arg0];
    }
    return r;
}
