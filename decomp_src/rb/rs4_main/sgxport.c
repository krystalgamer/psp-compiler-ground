/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxFree(int);                               /* extern */
extern unsigned char gWork_11FEA4;
void AttrSetValue(short *, int, int);
extern int D_0011FECC;
extern int D_0011FEE4;
extern int D_0011FEFC;
M2C_UNK sgxListEnumID(M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_0011FEB8;
extern unsigned char D_0011FED0;
extern unsigned char D_0011FEE8;


void *SlotGetAt_848F0(int, const char *);
void UnitFreeByID_8589C(void *, int, int);
void UnitFree_85774(void *);
void sgxVoFree(int);
void FadeFreeAll(char *);
extern int D_00113C94[];
static inline char *PortListFirst(char *l) {
    char *n = *(char **)(l + 4);
    return (*(int *)(n + 8) < 0) ? NULL : n;
}
static inline char *PortListNext(char *e) {
    char *n = *(char **)(e + 4);
    return (*(int *)(n + 8) < 0) ? NULL : n;
}

typedef struct SgxPNode { struct SgxPNode *prev, *next; int id; } SgxPNode;
static inline void SgxPNodeUnlink(SgxPNode *n) {
    SgxPNode *p = n->prev;
    if (p != n) {
        p->next = n->next;
        n->next->prev = p;
    }
}
static inline void SgxPNodeAddTail(SgxPNode *l, SgxPNode *n) {
    SgxPNode *t = l->prev;
    n->next = l;
    t->next = n;
    n->prev = t;
    n->next->prev = n;
}
static inline void SgxPNodeMove(SgxPNode *l, SgxPNode *n) { SgxPNodeUnlink(n); SgxPNodeAddTail(l, n); }

int UnitMergeVoiceStatus(void *);
void sgxPortCommand(int id, int *cmd);
extern int D_00113CC8[];

extern int gSgxDebugFlags;
extern int gSgxPrefWarn;
int sgxPrintfPref(int, const void *, int, const char *, ...);
typedef struct { char pad[0x24]; char *slots; int num; } PortWorkS;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AD00);

extern const char D_0010AD00[];
#define WW ((PortWorkS *)&gWork_11FEA4)
void *SlotGetAt_848F0(int id, const char *name)
{
    if (id >= 0 && id <= WW->num - 1) {
        char *p = WW->slots + id * 0xA0;
        if (*(int *)(p + 0xC) & 1) return p;
    }
    if (name != NULL && (gSgxDebugFlags & 2)) {
        sgxPrintfPref(gSgxPrefWarn, D_0010AD00, 0x16A, "sgxPort%s unknown ID (%d)\n", name, id);
        return NULL;
    }
    return NULL;
}
#undef WW

void ResetMidiChData(int arg0)
{
    unsigned char *p = (unsigned char *)arg0;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0x80;
    p[3] = 0x80;
    p[4] = 0x40;
    p[5] = 0x40;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortInit);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void sgxPortTerm(void) {
    if (M2C_FIELD(&gWork_11FEA4, int *, 0) == 0) {

    } else {
        sgxFree(M2C_FIELD(&gWork_11FEA4, int *, 0x24));
        sgxFree(M2C_FIELD(&gWork_11FEA4, int *, 0x3C));
        sgxFree(M2C_FIELD(&gWork_11FEA4, int *, 0x54));
        memset(&gWork_11FEA4, 0, 0xBCU);
    }
}

void AttrClear(short *a) {
    int i;
    a[0] = 0;
    a[1] = 0;
    for (i = 0; i < 24; i++) a[13 + i] = 0;
    for (i = 0; i < 4; i++) {
        a[17 + i * 6] = 0x1000;
        a[18 + i * 6] = 1000;
    }
}

void AttrSetValue(short *a, int idx, int v)
{
    if (idx >= 13 && idx < 37) {
        a[idx] = v;
    } else if (idx >= 2 && idx < 13) {
        if (!((a[1] >> idx) & 1) || a[idx] != v) {
            a[idx] = v;
            int t0 = a[0], t1 = a[1];
            a[0] = t0 | (1 << idx);
            a[1] = t1 | (1 << idx);
        }
    }
}

int AttrGetValue(short *a, int idx) {
    if ((unsigned int)(idx - 13) < 24) return a[idx];
    if ((a[1] >> idx) & 1) return a[idx];
    return D_00113C94[idx];
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortAlloc);

void sgxPortFree(int id) {
    char *p = SlotGetAt_848F0(id, 0);
    if (p == NULL) return;
    sgxPortCommand(id, D_00113CC8);
    FadeFreeAll(p + 0x28);
    ((int *)p)[3] = 0;
    SgxPNodeMove((SgxPNode *)&D_0011FEB8, (SgxPNode *)p);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", FadeAlloc);

void FadeFree(char *f)
{
    if (*(int *)(f + 0x10) != 0) AttrSetValue(*(int *)(f + 0x10), *(short *)(f + 0x14), *(short *)(f + 0x16));
    SgxPNodeUnlink((SgxPNode *)f);
    SgxPNodeAddTail((SgxPNode *)&D_0011FEE8, (SgxPNode *)f);
}

void FadeFreeAll(char *l) {
    char *e;
    while ((e = PortListFirst(l)) != NULL) FadeFree(e);
}

void FadeFreeByAttr(char *l, int attr) {
    char *e;
    for (e = PortListFirst(l); e != NULL; e = PortListNext(e)) {
        if (*(short *)(e + 0x14) == attr) {
            FadeFree(e);
            return;
        }
    }
}

void AllocTakenVoice(int v, short *tbl, int flag) {
    int i;
    for (i = 0; i < 2; i++, tbl++) {
        if (*tbl == v) {
            if (flag) sgxVoFree(*tbl);
            *tbl = -1;
            return;
        }
    }
}

typedef struct { char pad[0x30]; struct { int a; short res; signed char nv; char p; short v[8]; } s; } UnitT;
void UnitTakenVoice(int voice, void *uv, int stop) {
    UnitT *u = uv;
    char *e;
    int i;
    for (i = 0; i < u->s.nv; i++) {
        if (u->s.v[i] == voice) {
            if (stop) {
                sgxVoCtrl(u->s.v[i], 2, 0, 0);
                sgxVoFree(u->s.v[i]);
            }
            u->s.v[i] = -1;
            break;
        }
    }
    for (e = PortListFirst(*(char **)((char *)u + 0x10) + 0x18); e != NULL; e = PortListNext(e)) {
        UnitT *o = (UnitT *)e;
        if (o != u && *(int *)(e + 8) == *(int *)((char *)u + 8)) {
            for (i = 0; i < o->s.nv; i++) {
                if (o->s.v[i] >= 0) {
                    sgxVoCtrl(o->s.v[i], 2, 0, 0);
                    sgxVoFree(o->s.v[i]);
                    o->s.v[i] = -1;
                }
            }
        }
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitVoiceAlloc);

void UnitFree_85774(void *uv)
{
    UnitT *u = uv;
    int i;
    FadeFreeAll((char *)u + 0x14);
    for (i = 0; i < u->s.nv; i++) {
        if (u->s.v[i] >= 0) {
            sgxVoCtrl(u->s.v[i], 2, 0, 0);
            sgxVoFree(u->s.v[i]);
        }
    }
    if (u->s.res >= 0) sgxResUnlock(u->s.res);
    *(int *)((char *)u + 0xC) = 0;
    SgxPNodeMove((SgxPNode *)&D_0011FED0, (SgxPNode *)u);
}

void UnitFreeAll_85854(p)
    char *p;
{
    char *l = p + 0x18;
    char *e;
    while ((e = PortListFirst(l)) != NULL) UnitFree_85774(e);
}

void UnitFreeByID_8589C(void *port, int id, int sh)
{
    char *e, *n;
    for (e = PortListFirst((char *)port + 0x18); e != NULL; e = n) {
        n = PortListNext(e);
        if ((*(int *)(e + 8) >> sh) == id) UnitFree_85774(e);
    }
}

void UnitFreeAtAfter(void *port, char *u) {
    char *e, *n;
    if (u == NULL) return;
    for (e = PortListNext(u); e != NULL; e = n) {
        n = PortListNext(e);
        UnitFree_85774(e);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitPlayWave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPlayNote);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPlayWave);

void *UnitPlayWave(void *, int, int, int, int, int, int, int); /* extern */

void CmdPlayNoise(void *arg0, void *arg1) {
    int temp_fp;
    int temp_s0;
    int temp_s1;
    int temp_s3;
    int temp_s4;
    int temp_s5;
    int temp_s6;
    int temp_s7;
    void *temp_v0;

    temp_s1 = M2C_FIELD(arg1, int *, 4);
    temp_s7 = M2C_FIELD(arg1, int *, 8);
    temp_s0 = M2C_FIELD(arg1, int *, 0xC);
    temp_s6 = M2C_FIELD(arg1, int *, 0x20);
    temp_s3 = M2C_FIELD(arg1, int *, 0x14);
    temp_s4 = M2C_FIELD(arg1, int *, 0x18);
    temp_s5 = M2C_FIELD(arg1, int *, 0x1C);
    temp_fp = M2C_FIELD(arg1, int *, 0x10);
    UnitFreeByID_8589C(arg0, temp_s1, 0);
    if (sgxResLock(temp_s7) == 0) {

    } else {
        temp_v0 = UnitPlayWave(arg0, temp_s1, temp_s7, temp_s0 - 0x3E8, temp_s3, temp_s4, temp_s5, temp_s6);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, short *, 0x40) = (short) temp_fp;
        }
        sgxResUnlock(temp_s7);
    }
}

void CmdPlayNote();
typedef struct { unsigned char prog, vol, x[4]; } MidiChX;
void CmdPlayMidi(char *port, int *cmd)
{
    int c[12];
    int id = cmd[1], a = cmd[2], b = cmd[3];
    MidiChX *ch = (MidiChX *)((id >> 24) * 6 + (int)port + 0x38);
    int n = ((short *)(*(char **)(port + 0x10) + 0xA4))[ch->prog];
    int v = ch->vol;
    c[0] = 0;
    c[1] = id;
    c[2] = n;
    c[3] = v;
    c[4] = a;
    c[5] = b;
    CmdPlayNote(port, c);
}

void CmdRelAny(char *port, int *cmd)
{
    UnitT *u;
    int sh = cmd[0] == 4 ? 0 : 24;
    int id = cmd[1];
    int f = cmd[2];
    for (u = (UnitT *)PortListFirst(port + 0x18); u != NULL; u = (UnitT *)PortListNext((char *)u)) {
        int i;
        if ((*(int *)((char *)u + 8) >> sh) != id) continue;
        for (i = 0; i < u->s.nv; i++) {
            if (u->s.v[i] >= 0) {
                sgxVoCtrl(u->s.v[i], 1, 0, 0);
                if (f) {
                    sgxVoFree(u->s.v[i]);
                    u->s.v[i] = -1;
                }
            }
        }
    }
}

void CmdRelAll_86218(char *port, int *cmd)
{
    UnitT *u;
    int f = cmd[1];
    for (u = (UnitT *)PortListFirst(port + 0x18); u != NULL; u = (UnitT *)PortListNext((char *)u)) {
        int i;
        for (i = 0; i < u->s.nv; i++) {
            if (u->s.v[i] >= 0) {
                sgxVoCtrl(u->s.v[i], 1, 0, 0);
                if (f) {
                    sgxVoFree(u->s.v[i]);
                    u->s.v[i] = -1;
                }
            }
        }
    }
}

void CmdStopAny(void *port, int *cmd) {
    UnitFreeByID_8589C(port, cmd[1], (cmd[0] == 7) ? 0 : 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CmdStopAll_86320(void) {
    UnitFreeAll_85854();
}

void CmdCtrlID(char *port, int *cmd)
{
    char *u;
    int id = cmd[1], a = cmd[2], b = cmd[3], c = cmd[4], d = cmd[5];
    for (u = PortListFirst(port + 0x18); u != NULL; u = PortListNext(u)) {
        if (*(int *)(u + 8) == id)
            FadeAlloc(u + 0x14, u + 0x54, a, b, c, d);
    }
}

void CmdCtrlMidi(char *port, int *cmd)
{
	int ch = cmd[1];
	unsigned int type = cmd[2];
	int val = cmd[3];
	switch (type) {
	case 0:
		val = val < 0 ? 0 : (val > 3 ? 3 : val);
		break;
	case 1:
		val = val < 0 ? 0 : val;
		break;
	case 2:
	case 3:
	case 4:
		*(int *)(port + 0x98) |= 1 << ch;
		if (val == 127) val = 128;
		break;
	case 5:
		*(int *)(port + 0x9C) |= 1 << ch;
		if (val == 127) val = 128;
		break;
	}
	((unsigned char *)((MidiChX *)(port + 0x38) + ch))[type] = val;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CmdCtrlMidiReset(int arg0, void *arg1) {
    ResetMidiChData(arg0 + (M2C_FIELD(arg1, int *, 4) * 6) + 0x38);
}

void CmdAdsrID(char *port, int *cmd)
{
	UnitT *u;
	int id = cmd[1];
	int adsr = cmd[2];
	int res = *(short *)(*(char **)(port + 0x10) + 0x12);
	unsigned int a;
	if (sgxResLock(res) == 0) return;
	a = sgxResFindAdsr(*(short *)(*(char **)(port + 0x10) + 0x12), adsr);
	for (u = (UnitT *)PortListFirst(port + 0x18); u != NULL; u = (UnitT *)PortListNext((char *)u)) {
		int i;
		if (*(int *)((char *)u + 8) != id) continue;
		for (i = 0; i < u->s.nv; i++) {
			if (u->s.v[i] >= 0)
				sgxVoCtrl(u->s.v[i], 6, (a >> 16) & 0xFFFF, a & 0xFFFF);
		}
	}
	sgxResUnlock(res);
}

void CmdBendWID(char *port, int *cmd) {
    char *e;
    int id = cmd[1];
    int a = cmd[2];
    int b = cmd[3];
    for (e = PortListFirst(port + 0x18); e != NULL; e = PortListNext(e)) {
        if (*(int *)(e + 8) == id) {
            e[0x52] = a;
            e[0x53] = b;
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CmdBusIDID(void *arg0) {
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *var_v0;

    temp_v1 = M2C_FIELD(arg0, void **, 0x1C);
    temp_v1_2 = (M2C_FIELD(temp_v1, int *, 8) < 0) ? NULL : temp_v1;
    var_v0 = temp_v1_2;
    if (temp_v1_2 != NULL) {
        do {
            temp_v1_4 = M2C_FIELD(var_v0, void **, 4);
            temp_v1_3 = (M2C_FIELD(temp_v1_4, int *, 8) < 0) ? NULL : temp_v1_4;
            var_v0 = temp_v1_3;
        } while (temp_v1_3 != NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CmdFilterTypeID(void *arg0) {
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *var_v0;

    temp_v1 = M2C_FIELD(arg0, void **, 0x1C);
    temp_v1_2 = (M2C_FIELD(temp_v1, int *, 8) < 0) ? NULL : temp_v1;
    var_v0 = temp_v1_2;
    if (temp_v1_2 != NULL) {
        do {
            temp_v1_4 = M2C_FIELD(var_v0, void **, 4);
            temp_v1_3 = (M2C_FIELD(temp_v1_4, int *, 8) < 0) ? NULL : temp_v1_4;
            var_v0 = temp_v1_3;
        } while (temp_v1_3 != NULL);
    }
}

void CmdPause_866D0(char *port, int cmd)
{
	UnitT *u;
	int a = ((int *)cmd)[1];
	if (a) cmd = *(int *)(port + 0xC) | 4;
	else cmd = *(int *)(port + 0xC) & ~4;
	if (*(int *)(port + 0xC) == cmd) return;
	*(int *)(port + 0xC) = cmd;
	for (u = (UnitT *)PortListFirst(port + 0x18); u != NULL; u = (UnitT *)PortListNext((char *)u)) {
		int i;
		for (i = 0; i < u->s.nv; i++) {
			if (u->s.v[i] >= 0)
				sgxVoCtrl(u->s.v[i], 5, a, 0);
		}
	}
}

extern int D_00113CCC[];
typedef void (*PortCmdFn)(void *, int *);
void sgxPortCommand(int id, int *cmd)
{
    int c = cmd[0];
    void *p = SlotGetAt_848F0(id, "Command");
    if (p == NULL) return;
    if ((unsigned int)c < 18) ((PortCmdFn *)D_00113CCC)[c](p, cmd);
}

int sgxPortGetStatus(int id) {
    char *p = SlotGetAt_848F0(id, 0);
    if (p == NULL) return 0;
    return *(int *)(p + 0xC);
}

int sgxPortGetUnitStatus(int id, int uid) {
    char *p = SlotGetAt_848F0(id, 0);
    char *e;
    if (p == NULL) return -1;
    for (e = PortListFirst(p + 0x18); e != NULL; e = PortListNext(e))
        if (*(int *)(e + 8) == uid) return 3;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10], gap at: 0x8. */
void FadeProc(void *arg0, float fparg0) {
    float temp_f2;
    float temp_f5;
    void *temp_s0;
    void *temp_v1;
    void *temp_v1_2;
    void *var_a2;

    temp_v1 = M2C_FIELD(arg0, void **, 4);
    var_a2 = (M2C_FIELD(temp_v1, int *, 8) >= 0) ? temp_v1 : NULL;
    if (var_a2 != NULL) {
        do {
            temp_v1_2 = M2C_FIELD(var_a2, void **, 4);
            temp_f5 = M2C_FIELD(var_a2, float *, 0x1C) + fparg0;
            temp_s0 = (M2C_FIELD(temp_v1_2, int *, 8) >= 0) ? temp_v1_2 : NULL;
            M2C_FIELD(var_a2, float *, 0x1C) = temp_f5;
            if (M2C_FIELD(var_a2, float *, 0x20) < temp_f5) {
                FadeFree(var_a2);
            } else {
                temp_f2 = (float) M2C_FIELD(var_a2, short *, 0x18);
                AttrSetValue(M2C_FIELD(var_a2, int *, 0x10), M2C_FIELD(var_a2, short *, 0x14), (int) (temp_f2 + (((float) M2C_FIELD(var_a2, short *, 0x16) - temp_f2) * temp_f5 * M2C_FIELD(var_a2, float *, 0x24))));
            }
            var_a2 = temp_s0;
        } while (temp_s0 != NULL);
    }
}

int IsLfoActive(int arg0) {
    short *var_a0;
    short temp_v0;
    int var_a1;
    int var_a2;

    var_a0 = arg0 + 0x20;
    var_a1 = 0;
loop_1:
    temp_v0 = *var_a0;
    var_a1 += 1;
    var_a0 += 6;
    var_a2 = 1;
    if (temp_v0 == 0) {
        if (var_a1 >= 4) {
            var_a2 = 0;
        } else {
            goto loop_1;
        }
    }
    return var_a2;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AE38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AEC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AECC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", LfoProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", LfoCalc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitVolumeProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitPitchProc);

signed char sgxVoGetStatus(int v);
long long sgxVoGetPlayUnitSamples(int v);
int sgxSndCheckMarkerLoop(int snd, int a, int b, int c, int d, int samples, int *status);
int UnitMergeVoiceStatus(void *p)
{
	UnitT *u = (UnitT *)p;
	int st = 0;
	int i;
	for (i = 0; i < u->s.nv; i++) {
		if (u->s.v[i] >= 0) st |= sgxVoGetStatus(u->s.v[i]);
	}
	if (st & 2) st |= 0x40;
	if (u->s.nv > 0 && u->s.v[0] >= 0) {
		*(int *)((char *)u + 0x3C) = sgxSndCheckMarkerLoop(*(int *)(*(char **)(*(char **)((char *)u + 0x10) + 0x10) + 8), *(int *)((char *)u + 0x28), *(int *)((char *)u + 0x2C), *(int *)((char *)u + 0x30), *(int *)((char *)u + 0x3C), sgxVoGetPlayUnitSamples(u->s.v[0]), &st);
	}
	return st;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", SlotUnitProc_8716C);

void SlotUnitPauseProc(char *s)
{
    char *e;
    for (e = PortListFirst(s + 0x18); e != NULL; e = PortListNext(e)) {
        *(int *)(s + 0xC) |= UnitMergeVoiceStatus(e) & 0x160;
        { int m = *(short *)(*(char **)(s + 0x10) + 0x6C); int t = *(short *)(e + 0x54); *(short *)(e + 0x54) = t | m; }
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortTickProc);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxPortGetMaxSlotCount(void) {
    return D_0011FECC;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxPortGetMaxUnitCount(void) {
    return D_0011FEE4;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxPortGetMaxFadeCount(void) {
    return D_0011FEFC;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxPortGetFreeSlotCount(void) {
    sgxListEnumID(&D_0011FEB8, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxPortGetFreeUnitCount(void) {
    sgxListEnumID(&D_0011FED0, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxPortGetFreeFadeCount(void) {
    sgxListEnumID(&D_0011FEE8, 0);
}
