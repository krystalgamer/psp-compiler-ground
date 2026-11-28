/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxFree(int);                               /* extern */
extern unsigned char gWork_11FE60;
unsigned char *sgxBmgGetTail(short);                             /* extern */
M2C_UNK sgxBmgGetLeft(short);                         /* extern */
M2C_UNK sgxPortCommand(short, int);                   /* extern */
extern void *D_0011FE68;
extern int D_0011FE88;
extern int D_0011FEA0;
M2C_UNK sgxListEnumID(M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_0011FE74;
extern unsigned char D_0011FE8C;


void PortCommandGlobal(void *arg0, int arg1);
int sgxBmgRead(short, void *, int);
void UnitFree_81D64(void *);
void sgxSndSetSysReg(int, int);
int sgxSndGetSysReg(int);
void *SlotGetAt_81530(int, int);
typedef int (*SeqReadFn)(void *);
static inline char *SeqListFirst(char *l) {
    char *n = *(char **)(l + 4);
    return (*(int *)(n + 8) < 0) ? NULL : n;
}
static inline char *SeqListNext(char *e) {
    char *n = *(char **)(e + 4);
    return (*(int *)(n + 8) < 0) ? NULL : n;
}

void CmdPlaySeq(void *, int *);
void CmdRel(void *, int *);
void sgxSeqCommand(int, int *);
void sgxBmgFree(int);
void sgxPortFree(int);
void sgxResUnlock(int);
extern int gSgxPrefErr;
extern const char D_0010A814[];
extern int D_00113BB0[];
extern int D_00113B7C[];
void sgxPrintfPref(int, const char *, int, const char *, ...);
#define SGX_ERR(line, ...) if (gSgxDebugFlags & 1) sgxPrintfPref(gSgxPrefErr, D_0010A814, line, __VA_ARGS__)
typedef struct SeqNode { struct SeqNode *prev, *next; int id; } SeqNode;
static inline void SeqNodeUnlink(SeqNode *n) {
    SeqNode *p = n->prev;
    if (p != n) {
        p->next = n->next;
        n->next->prev = p;
    }
}
static inline void SeqNodeAddTail(SeqNode *l, SeqNode *n) {
    SeqNode *t = l->prev;
    n->next = l;
    t->next = n;
    n->prev = t;
    n->next->prev = n;
}

extern int gSgxDebugFlags;
extern int gSgxPrefWarn;
typedef struct { char pad[0x24]; char *slots; int num; } SeqWorkS;

int sgxBmgIsFinished(int);
int MidiCore();
int SesqCore();
int sgxBmgLock(int);
void *UnitAlloc();
extern const char D_0010A918[];

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010A814);

#define WW ((SeqWorkS *)&gWork_11FE60)
void *SlotGetAt_81530(int id, int namev)
{
    const char *name = (const char *)namev;
    if (id >= 0 && id <= WW->num - 1) {
        char *p = WW->slots + id * 0x24;
        if (*(int *)(p + 0xC) & 1) return p;
    }
    if (name != NULL && (gSgxDebugFlags & 2)) {
        sgxPrintfPref(gSgxPrefWarn, D_0010A814, 0xBD, "sgxSeq%s unknown ID (%d)\n", name, id);
        return NULL;
    }
    return NULL;
}
#undef WW

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", sgxSeqInit);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void sgxSeqTerm(void) {
    if (M2C_FIELD(&gWork_11FE60, int *, 0) == 0) {

    } else {
        sgxFree(M2C_FIELD(&gWork_11FE60, int *, 0x24));
        sgxFree(M2C_FIELD(&gWork_11FE60, int *, 0x3C));
        memset(&gWork_11FE60, 0, 0x44U);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", sgxSeqAlloc);

void sgxSeqFree(int id) {
    SeqNode *p = SlotGetAt_81530(id, 0);
    if (p == NULL) return;
    sgxSeqCommand(id, D_00113B7C);
    ((int *)p)[3] = 0;
    SeqNodeUnlink(p);
    SeqNodeAddTail((SeqNode *)&D_0011FE74, p);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned char GetData(void *arg0) {
    return *M2C_FIELD(arg0, unsigned char **, 0x44);
}

unsigned char GetDataOfs(void *t, int ofs)
{
    return *(M2C_FIELD(t, unsigned char **, 0x44) + ofs);
}

unsigned char IncData(void *t)
{
    return *M2C_FIELD(t, unsigned char **, 0x44)++;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int GetLeft(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x40) - (M2C_FIELD(arg0, int *, 0x44) - M2C_FIELD(arg0, int *, 0x3C));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

unsigned char GetDataStr(void *arg0) {
    return *sgxBmgGetTail(M2C_FIELD(arg0, short *, 0x1C));
}

int GetDataOfsStr(char *s, int ofs) {
    return sgxBmgGetTail(*(short *)(s + 0x1C))[ofs];
}

int IncDataStr(char *s) {
    unsigned char c[16];
    c[0] = 0;
    sgxBmgRead(*(short *)(s + 0x1C), c, 1);
    return c[0];
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void GetLeftStr(void *arg0) {
    sgxBmgGetLeft(M2C_FIELD(arg0, short *, 0x1C));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", UnitAlloc);

static inline void SeqNodeMove(SeqNode *l, SeqNode *n) { SeqNodeUnlink(n); SeqNodeAddTail(l, n); }
void UnitFree_81D64(void *uv)
{
    char *u = uv;
    if (*(short *)(u + 0x1C) >= 0) sgxBmgFree(*(short *)(u + 0x1C));
    if (*(short *)(u + 0x1A) >= 0) sgxPortFree(*(short *)(u + 0x1A));
    if (*(short *)(u + 0x18) >= 0) sgxResUnlock(*(short *)(u + 0x18));
    *(int *)(u + 0xC) = 0;
    SeqNodeMove((SeqNode *)&D_0011FE8C, (SeqNode *)u);
}

void UnitFreeAll_81DFC(u)
    char *u;
{
    char *l = u + 0x14;
    char *e;
    while ((e = SeqListFirst(l)) != NULL) UnitFree_81D64(e);
}

int UnitIsUse(char *u, int id) {
    char *e;
    for (e = SeqListFirst(u + 0x14); e != NULL; e = SeqListNext(e))
        if (*(int *)(e + 8) == id) return 1;
    return 0;
}

void UnitFreeByID_81E8C(void *sv, int id) {
    char *s = sv;
    char *e, *n;
    for (e = SeqListFirst(s + 0x14); e != NULL; e = n) {
        n = SeqListNext(e);
        if (*(int *)(e + 8) == id) UnitFree_81D64(e);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", LoopBegProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", LoopEndProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", CmdPlaySeq);

void CmdPlaySeqStr(char *s, int *cmd)
{
    int id = cmd[1];
    int c2 = cmd[2];
    int c3 = cmd[3];
    short bmg = *(short *)(*(char **)(s + 0x10) + 0x1E);
    char *u;
    UnitFreeByID_81E8C(s, id);
    if (!sgxBmgLock(bmg)) return;
    u = UnitAlloc(s, id, 1, c2, c3);
    if (u != NULL) {
        *(short *)(u + 0x1C) = bmg;
        return;
    }
    if (bmg >= 0) sgxBmgFree(bmg);
}

void CmdRel(void *pv, int *cmd)
{
    char *p = pv;
    char *u;
    int id = cmd[1];
    int a = cmd[2];
    for (u = SeqListFirst(p + 0x14); u != NULL; u = SeqListNext(u)) {
        if (*(int *)(u + 8) == id) {
            int c[12];
            c[0] = 6;
            c[1] = a;
            sgxPortCommand(*(short *)(u + 0x1A), (int)c);
            u[0x51] = 1;
        }
    }
}

void CmdRelAll_822E0(void *pv, int *cmd)
{
    char *p = pv;
    char *u;
    int a = cmd[1];
    for (u = SeqListFirst(p + 0x14); u != NULL; u = SeqListNext(u)) {
        int c[12];
        c[0] = 6;
        c[1] = a;
        sgxPortCommand(*(short *)(u + 0x1A), (int)c);
        u[0x51] = 1;
    }
}

void UnitFreeByID_81E8C(void *, int);
void CmdStop(void *t, void *cmd)
{
    UnitFreeByID_81E8C(t, M2C_FIELD(cmd, int *, 4));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CmdStopAll_82384(void) {
    UnitFreeAll_81DFC();
}

void CmdPause_823A0(void *pv, int cmd)
{
	char *p = pv;
	char *u;
	int a = ((int *)cmd)[1];
	if (a) cmd = *(int *)(p + 0xC) | 4;
	else cmd = *(int *)(p + 0xC) & ~4;
	if (*(int *)(p + 0xC) == cmd) return;
	*(int *)(p + 0xC) = cmd;
	for (u = SeqListFirst(p + 0x14); u != NULL; u = SeqListNext(u)) {
		int c[12];
		c[0] = 0x11;
		c[1] = a;
		sgxPortCommand(*(short *)(u + 0x1A), (int)c);
	}
}

void CmdWait(char *s, int *a) {
    unsigned int n;
    if (a[1] != 0) n = *(unsigned int *)(s + 0xC) | 0x200;
    else n = *(unsigned int *)(s + 0xC) & ~0x200;
    if (*(unsigned int *)(s + 0xC) != n) *(unsigned int *)(s + 0xC) = n;
}

typedef void (*SeqCmdFn)(void *, int *);
void sgxSeqCommand(int id, int *cmd) {
    int c = cmd[0];
    void *p = SlotGetAt_81530(id, (int)"Command");
    if (p == NULL) return;
    if ((unsigned int)c < 18) ((SeqCmdFn *)D_00113BB0)[c](p, cmd);
}

int sgxSeqGetStatus(int id) {
    char *p = SlotGetAt_81530(id, 0);
    if (p == NULL) return 0;
    return *(int *)(p + 0xC);
}

void SesqSetReg(char *s, int idx, int v) {
    if ((unsigned int)idx >= 40) return;
    if (idx < 32) sgxSndSetSysReg(idx, v);
    else *(int *)(*(char **)(*(char **)(s + 0x10) + 0x10) + idx * 4 + 0x2C) = v;
}

int SesqGetReg(char *s, int idx) {
    if ((unsigned int)idx >= 40) return 0;
    if (idx < 32) return sgxSndGetSysReg(idx);
    return *(int *)(*(char **)(*(char **)(s + 0x10) + 0x10) + idx * 4 + 0x2C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int SesqReadBcd(void *arg0, int arg1) {
    int temp_v0;
    int var_a1;
    int var_s0;
    int var_s1;

    var_a1 = arg1;
    var_s1 = 0;
    if (var_a1 > 0) {
        var_s0 = var_a1;
        do {
            var_s0 -= 1;
            temp_v0 = M2C_FIELD(arg0, int (**)(void *, int), 0x30)(arg0, var_a1);
            var_a1 = (var_s1 * 0x64) + ((temp_v0 >> 4) * 0xA);
            var_s1 = var_a1 + (temp_v0 & 0xF);
        } while (var_s0 != 0);
    }
    return var_s1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqReadData);

#ifndef NULL
#define NULL ((void *)0)
#endif
int SesqCalcTime(void *arg0, int arg1, float fparg0) {
    return (int) ((float) arg1 * M2C_FIELD(arg0, float *, 0x4C) * fparg0);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010A918);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010A930);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010A94C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010A954);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010AA94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010AAB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010AACC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010ACCC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010ACE8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010ACEC);

extern const float D_0010ACF0;
void SesqWait(char *s, int x) {
    *(int *)(s + 0x48) += SesqCalcTime(s, x, D_0010ACF0);
}
const float D_0010ACF0 = 1.0f;

int SesqJump(char *u, int n, int v)
{
    if (n == -1) {
        u[0x51] = 1;
        return 1;
    }
    if (n == -2) {
        *(int *)(u + 0x44) = v;
        *(int *)(u + 0x48) = 0;
        return 1;
    }
    if (n < 0 || n > *(int *)(u + 0x40) - 1) {
        SGX_ERR(0x447, D_0010A918, n);
        return 1;
    }
    *(int *)(u + 0x44) = *(int *)(u + 0x3C) + n;
    return 0;
}

void SesqLoopBreak(char *s, int a, int b)
{
    short key = **(short **)(s + 0x20);
    char *e, *c;
    for (e = SeqListFirst((char *)&D_0011FE68 - 4); e != NULL; e = SeqListNext(e)) {
        char *q = *(char **)(e + 0x10);
        if (*(short *)(q + 0xA4) == key && *(int *)(q + 0x14) == a && *(int *)(q + 0x18) == b) {
            c = SeqListFirst(e + 0x14);
            if (c != NULL) c[0x56] = 1;
        }
    }
}

int SesqPlay(char *s, int a, int b, int c, int d)
{
	int cmd[12];
	cmd[1] = a;
	cmd[0] = 0;
	cmd[2] = *(short *)*(int *)(s + 0x20);
	cmd[3] = b;
	cmd[4] = c;
	cmd[5] = d;
	return sgxPortCommand(*(short *)(s + 0x1A), (int)cmd);
}

void SesqPlayWave(char *s, int a, int b, int c, int d, int e, int f, int g)
{
    int cmd[12];
    cmd[0] = 1;
    cmd[1] = a;
    cmd[2] = **(short **)(s + 0x20);
    cmd[3] = b;
    cmd[4] = c;
    cmd[5] = d;
    cmd[6] = e;
    cmd[7] = f;
    cmd[8] = g;
    sgxPortCommand(*(short *)(s + 0x1A), (int)cmd);
}

void SesqPlayNoise(char *s, int a, int b, int c, int d, int e, int f, int g)
{
    int cmd[12];
    cmd[0] = 2;
    cmd[1] = a;
    cmd[2] = **(short **)(s + 0x20);
    cmd[3] = b;
    cmd[4] = c;
    cmd[5] = d;
    cmd[6] = e;
    cmd[7] = f;
    cmd[8] = g;
    sgxPortCommand(*(short *)(s + 0x1A), (int)cmd);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void PortCommandGlobal(void *arg0, int arg1) {
    short temp_s3;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *var_s0;
    void *var_s1;

    var_s1 = (M2C_FIELD(D_0011FE68, int *, 8) >= 0) ? D_0011FE68 : NULL;
    temp_s3 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0x10), short *, 0x12);
    if (var_s1 != NULL) {
        do {
            if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x10), short *, 0x12) == temp_s3) {
                temp_v1_2 = M2C_FIELD(var_s1, void **, 0x18);
                var_s0 = (M2C_FIELD(temp_v1_2, int *, 8) >= 0) ? temp_v1_2 : NULL;
                if (var_s0 != NULL) {
                    do {
                        sgxPortCommand(M2C_FIELD(var_s0, short *, 0x1A), arg1);
                        temp_v1_4 = M2C_FIELD(var_s0, void **, 4);
                        temp_v1_3 = (M2C_FIELD(temp_v1_4, int *, 8) < 0) ? NULL : temp_v1_4;
                        var_s0 = temp_v1_3;
                    } while (temp_v1_3 != NULL);
                }
            }
            temp_v1 = (M2C_FIELD(M2C_FIELD(var_s1, void **, 4), int *, 8) < 0) ? NULL : M2C_FIELD(var_s1, void **, 4);
            var_s1 = temp_v1;
        } while (temp_v1 != NULL);
    }
}

void SesqStop(char *s, int a, int b, int global) {
    int cmd[12];
    cmd[0] = b ? 4 : 7;
    cmd[1] = a;
    cmd[2] = 0;
    if (global) PortCommandGlobal(s, (int)cmd);
    else sgxPortCommand(*(short *)(s + 0x1A), (int)cmd);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqCtrl);

void SesqAdsr(char *s, int a, int b, int global) {
    int cmd[12];
    cmd[0] = 13;
    cmd[1] = a;
    cmd[2] = b;
    if (global) PortCommandGlobal(s, (int)cmd);
    else sgxPortCommand(*(short *)(s + 0x1A), (int)cmd);
}

void SesqBendW(char *s, int a, int b, int c, int global) {
    int cmd[12];
    cmd[0] = 13;
    cmd[1] = a;
    cmd[2] = b;
    cmd[3] = c;
    if (global) PortCommandGlobal(s, (int)cmd);
    else sgxPortCommand(*(short *)(s + 0x1A), (int)cmd);
}

int PortIsUsedGlobal(char *port, int id)
{
	char *p, *u;
	int res = *(short *)(*(char **)(*(char **)(port + 0x10) + 0x10) + 0x12);
	for (p = SeqListFirst((char *)&D_0011FE68 - 4); p != NULL; p = SeqListNext(p)) {
		if (*(short *)(*(char **)(p + 0x10) + 0x12) != res) continue;
		for (u = SeqListFirst(p + 0x14); u != NULL; u = SeqListNext(u)) {
			if (sgxPortGetUnitStatus(*(short *)(u + 0x1A), id) & 1) return 1;
		}
	}
	return 0;
}

int SesqMakeSubID(a0, s, id)
    void *a0;
    void *s;
    int id;
{
    return id | ((M2C_FIELD(s, unsigned char *, 0xB) + 1) << 24);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqSubPlay);

void SesqSubStop(char *s, char *a, int b, int flag) {
    int cmd[8];
    int id = SesqMakeSubID(s, a, b);
    if (flag) {
        cmd[0] = 2;
        cmd[1] = id;
        cmd[2] = 1;
    } else {
        cmd[0] = 4;
        cmd[1] = id;
        cmd[2] = 0;
    }
    CmdRel(s, cmd);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int SesqSubGetStatus(int arg0) {
    return (UnitIsUse(arg0, SesqMakeSubID()) == 0) ? 0 : 3;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int NoZero(int arg0, int arg1) {
    return (arg0 != 0) ? arg0 : arg1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqCore);

extern const char D_0010AAB8[];
void UnitSesqProc(int u, char *t, int dt) {
    int n = 0;
    while (t[0x51] == 0 && *(int *)(t + 0x48) <= 0 && (*(int (**)(void *))(t + 0x34))(t) > 0 && n < 0x4000) {
        n++;
        if (SesqCore(u, t, 1) == 0) return;
    }
    if (n < 0x4000) {
        if ((*(int (**)(void *))(t + 0x34))(t) > 0) {
            *(int *)(t + 0x48) -= dt;
            return;
        }
    } else {
        SGX_ERR(0x730, D_0010AAB8);
    }
    t[0x51] = 1;
}

void UnitSesqStrProc(void *a, char *u, int dec)
{
    while (u[0x51] == 0 && *(int *)(u + 0x48) <= 0 && sgxBmgGetLeft(*(short *)(u + 0x1C)) > 0) {
        if (!SesqCore(a, u, 0)) return;
    }
    if (sgxBmgIsFinished(*(short *)(u + 0x1C))) {
        u[0x51] = 1;
        return;
    }
    if (*(int *)(u + 0x48) > 0) *(int *)(u + 0x48) -= dec;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCMNoteOnOff);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCMCtrlChg);

void MidiCMProgChg(char *s, int ch) {
    int cmd[12];
    int v = (*(SeqReadFn *)(s + 0x30))(s);
    cmd[0] = 11;
    cmd[1] = ch;
    cmd[2] = 1;
    cmd[3] = v;
    sgxPortCommand(*(short *)(s + 0x1A), (int)cmd);
}

void MidiCMKeyPress(char *s) {
    (*(SeqReadFn *)(s + 0x30))(s);
    (*(SeqReadFn *)(s + 0x30))(s);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void MidiCMChPress(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x30)();
}

void MidiCMBend(char *s, int ch) {
    int cmd[12];
    int v;
    (*(SeqReadFn *)(s + 0x30))(s);
    v = (*(SeqReadFn *)(s + 0x30))(s);
    cmd[0] = 11;
    cmd[1] = ch;
    cmd[2] = 5;
    cmd[3] = v;
    sgxPortCommand(*(short *)(s + 0x1A), (int)cmd);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCMSysMes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCore);

static inline void MidiReadDelta_(char *t) {
    int v = 0;
    int c;
    do {
        c = (*(SeqReadFn *)(t + 0x30))(t);
        v = (v << 7) | (c & 0x7F);
    } while (c & 0x80);
    if (v > 0) *(int *)(t + 0x48) += (int)(v * *(float *)(t + 0x4C));
}
void UnitMidiProc(int u, char *t, int dt) {
    int n;
    if (*(int *)(t + 0x3C) == *(int *)(t + 0x44)) MidiReadDelta_(t);
    n = 0;
    while (t[0x51] == 0 && *(int *)(t + 0x48) <= 0 && (*(int (**)(void *))(t + 0x34))(t) > 0 && n < 0x4000) {
        if (MidiCore(u, t, 1) == 0) return;
        if (t[0x51] == 0) MidiReadDelta_(t);
        n++;
    }
    if (n < 0x4000) {
        if ((*(int (**)(void *))(t + 0x34))(t) > 0) {
            *(int *)(t + 0x48) -= dt;
            return;
        }
    } else {
        SGX_ERR(0x8EC, D_0010AAB8);
    }
    t[0x51] = 1;
}

void UnitMidiStrProc(void *a, char *u, int dec)
{
    while (u[0x51] == 0 && *(int *)(u + 0x48) <= 0 && sgxBmgGetLeft(*(short *)(u + 0x1C)) > 0) {
        if (!MidiCore(a, u, 0)) return;
    }
    if (sgxBmgIsFinished(*(short *)(u + 0x1C))) {
        u[0x51] = 1;
        return;
    }
    if (*(int *)(u + 0x48) > 0) *(int *)(u + 0x48) -= dec;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SlotUnitProc_84650);

void SlotUnitProc_84650(char *p, int t);
extern const float D_0010ACFC;
void sgxSeqTickProc(float dt)
{
	char *p;
	int t = dt * D_0010ACFC;
	for (p = SeqListFirst((char *)&D_0011FE68 - 4); p != NULL; p = SeqListNext(p)) {
		int f = *(int *)(p + 0xC);
		char *slot = *(char **)(p + 0x10) + 0x6C;
		*(int *)(p + 0xC) = f & ~0x140;
		if (f & 0x204) continue;
		{
			int tt = t;
			int fl = *(short *)(slot + 2);
			if (fl & 0x400) tt = (t * *(short *)(slot + 0x14)) >> 12;
			SlotUnitProc_84650(p, tt);
			if (SeqListFirst(p + 0x14) == NULL) *(int *)(p + 0xC) &= ~2;
		}
	}
}
const float D_0010ACFC = 1000000.0f;

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSeqGetMaxSlotCount(void) {
    return D_0011FE88;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSeqGetMaxUnitCount(void) {
    return D_0011FEA0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxSeqGetFreeSlotCount(void) {
    sgxListEnumID(&D_0011FE74, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxSeqGetFreeUnitCount(void) {
    sgxListEnumID(&D_0011FE8C, 0);
}
