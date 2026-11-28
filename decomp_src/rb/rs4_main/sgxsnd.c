#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxFree(int);                               /* extern */
extern unsigned char gWork_11FC84;
M2C_UNK SlotPlay(M2C_UNK, int, int, M2C_UNK, int, M2C_UNK); /* extern */
extern unsigned char D_0010A4D4;
extern unsigned char D_0010A4E4;
void *SlotGetAt_7DD48(int, const char *);
extern const char D_0010A5E4[];
extern const char D_0010A5F0[];
extern const char D_0010A618[];
extern const char D_0010A644[];
extern const char D_0010A65C[];
extern const char D_0010A68C[];
extern const char D_0010A6A8[];
extern const char D_0010A78C[];
extern const char D_0010A79C[];
void SlotStop(int, int, float, const void *);
void SlotStopRes(int, int, float);
void SlotStopName(int, int, float);
void SlotStopCategory(int, int, float);
void SlotStopAll(int, float);
void SlotDoFade(int, int, int);
void sgxSndSetStrBufCB(int, int, int, int);
extern const char D_0010A504[];
extern const char D_0010A50C[];
extern int D_0011FCAC;
M2C_UNK sgxDI();                                    /* extern */
M2C_UNK sgxEI();                                    /* extern */
int sgxListEnumID(M2C_UNK *, M2C_UNK);              /* extern */
extern unsigned char D_0011FC98;


#include <stdarg.h>
int vsprintf(char *, const char *, va_list);
void sgxBmgWriteTerm(int);
int sgxBmgGetFree(int);
int sgxBmgGetLeft(int);
int sgxBmgWrite(int, const void *, int);
void sgxAttrSetValueSafe(void *, int, int);
void sgxSndPlayName(int, const char *, int);

extern int gSgxDebugFlags;
extern int gSgxPrefErr;
extern const char D_0010A400[];
extern const char D_0010A598[];
void sgxPrintfPref(int, const char *, int, const char *, ...);
void sgxPrintf(const char *, ...);
void sgxCbRegist(int, int, void *, int, int);
void sgxBmgSetLowBufCallback(int, int, int, int, int);
#define SGX_ERR(line, ...) if (gSgxDebugFlags & 1) sgxPrintfPref(gSgxPrefErr, D_0010A400, line, __VA_ARGS__)
#define SNDW ((char *)&gWork_11FC84)

extern const char D_0010A5BC[];
extern const char D_0010A5C8[];
void SlotUpdateVolume(void *, int);
void sgxAttrCopyUpdate(void *, void *);
static inline char *SndListFirst2(char *l) { char *n = *(char **)(l + 4); return (*(int *)(n + 8) < 0) ? NULL : n; }

extern int gSgxPrefWarn;
extern const char D_0010A40C[];
typedef struct { char pad[0x24]; char *slots; int num; } SndWorkS;

#define WW ((SndWorkS *)&gWork_11FC84)
void *SlotGetAt_7DD48(int id, const char *name)
{
    if (id >= 0 && id <= WW->num - 1) {
        char *p = WW->slots + id * 0xFC;
        if ((*(int *)(p + 0xC) & 1) && !(p[0x87] & 2) && ((signed char *)p)[0xE5] == 0) return p;
    }
    if (name != NULL && (gSgxDebugFlags & 2)) {
        sgxPrintfPref(gSgxPrefWarn, D_0010A400, 0x54, D_0010A40C, name, id);
        return NULL;
    }
    return NULL;
}
#undef WW

#define WW ((SndWorkS *)&gWork_11FC84)
void *SlotGetAtStop(int id, const char *name)
{
    if (id >= 0 && id <= WW->num - 1) {
        char *p = WW->slots + id * 0xFC;
        if ((*(int *)(p + 0xC) & 1) && !(p[0x87] & 2)) return p;
    }
    if (name != NULL && (gSgxDebugFlags & 2)) {
        sgxPrintfPref(gSgxPrefWarn, D_0010A400, 0x63, D_0010A40C, name, id);
        return NULL;
    }
    return NULL;
}
#undef WW

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A400);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A40C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndInit);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void sgxSndTerm(void) {
    if (M2C_FIELD(&gWork_11FC84, int *, 0) == 0) {

    } else {
        sgxFree(M2C_FIELD(&gWork_11FC84, int *, 0x24));
        memset(&gWork_11FC84, 0, 0x1B8U);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotUpdateVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndFlush);

extern void *D_0011FC8C;

int MakeSlotList(void **arg0) {
    int var_a1;
    void **var_a0;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_v0;

    var_a0 = arg0;
    var_a1 = 0;
    temp_v1 = (M2C_FIELD(D_0011FC8C, int *, 8) < 0) ? NULL : D_0011FC8C;
    var_v0 = temp_v1;
    if (temp_v1 != NULL) {
        do {
            *var_a0 = var_v0;
            var_a1 += 1;
            var_a0 += 1;
            temp_v1_3 = M2C_FIELD(var_v0, void **, 4);
            temp_v1_2 = (M2C_FIELD(temp_v1_3, int *, 8) < 0) ? NULL : temp_v1_3;
            var_v0 = temp_v1_2;
        } while (temp_v1_2 != NULL);
    }
    return var_a1;
}

int CheckSync(char *s, float dt)
{
    int st = sgxSndGetStatus(*(short *)(s + 0xE6));
    if (*(signed char *)(s + 0xE4)) {
        if (st & 2) {
            *(signed char *)(s + 0xE4) = 0;
            *(float *)(s + 0xF8) += dt;
            return 1;
        }
    } else {
        if (!(st & 2)) {
            *(signed char *)(s + 0xE4) = 1;
            return 1;
        }
    }
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A44C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A464);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A468);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A478);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A47C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A49C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A4C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A4D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A4E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A4F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A504);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A50C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A518);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A520);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A528);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A534);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A540);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A548);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A550);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A55C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A568);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A574);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A590);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A598);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A5B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A5BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A5C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A5E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A5F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A5F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A604);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A618);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A62C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A644);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A65C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A674);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A68C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A6A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A6C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A6CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A6DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A6E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A6F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A6F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A70C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A728);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A73C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A74C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A75C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A76C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A77C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A78C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A79C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A7B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", D_0010A7DC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndTickProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndTickProcPost);

extern const char D_0010A44C[];
typedef struct { char pad[0x134]; int sysreg[32]; } SndWorkSR;
void sgxSndSetSysReg(int idx, int v) {
    if ((unsigned int)idx >= 32) {
        SGX_ERR(0x253, D_0010A44C, idx);
        return;
    }
    ((SndWorkSR *)&gWork_11FC84)->sysreg[idx] = v;
}

int sgxSndGetSysReg(int idx) {
    if ((unsigned int)idx >= 32) {
        SGX_ERR(0x25E, D_0010A44C, idx);
        return 0;
    }
    return ((SndWorkSR *)&gWork_11FC84)->sysreg[idx];
}

extern const char D_0010A464[];
extern const char D_0010A468[];
extern const char D_0010A478[];
void sgxSndUseTuning(int on) {
    char *w = SNDW;
    if (*(int *)(w + 0x1B4) != on) {
        *(int *)(w + 0x1B4) = on;
        if (gSgxDebugFlags & 4) sgxPrintf(D_0010A468, on ? D_0010A464 : D_0010A478);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotPlay);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxSndPlayWave(int arg0, int arg1, int arg2) {
    SlotPlay(0, arg0, arg1, 0, arg2, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxSndPlayWaveStr(int arg0, int arg1, int arg2, int arg3) {
    SlotPlay(3, -1, (arg0 << 0x10) | arg1, arg2, arg3, &D_0010A4D4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxSndPlayNote(int arg0, int arg1, int arg2, int arg3) {
    SlotPlay(1, arg0, arg1, arg2, arg3, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxSndPlaySeq(int arg0, int arg1, int arg2, int arg3) {
    SlotPlay(2, arg0, arg1, arg2, arg3, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxSndPlaySeqStr(int arg0, int arg1, int arg2) {
    SlotPlay(4, -1, arg0, arg1, arg2, &D_0010A4E4);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndPlayName);

void sgxSndPlayNameF(int a, const char *fmt, int c, ...) {
    char buf[1024];
    va_list ap;
    va_start(ap, c);
    vsprintf(buf, fmt, ap);
    sgxSndPlayName(a, buf, c);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotStop);

void sgxSndStop(int id, int a1)
{
    SlotStop(id, a1, 0.0f, D_0010A504);
}

void sgxSndStopFade(int id, float fade)
{
    SlotStop(id, 0, fade, D_0010A50C);
}

void SlotStopRes(int res, int a, float f)
{
    int n, i;
    char **list;
    sgxDI();
    list = __builtin_alloca(D_0011FCAC * sizeof(void *));
    n = MakeSlotList((void **)list);
    sgxEI();
    for (i = 0; i < n; i++)
        if (*(short *)(list[i] + 0x12) == res)
            SlotStop(*(int *)(list[i] + 8), a, f, 0);
}

void sgxSndStopRes(int id, int a1)
{
    SlotStopRes(id, a1, 0.0f);
}

void sgxSndStopFadeRes(int id, float fade)
{
    SlotStopRes(id, 0, fade);
}

int sgxIsStrIncWC(const char *);
int sgxIsStrMatch(const char *, const char *);
int sgxIsStrMatchWC(const char *, const char *);
void SlotStopName(int namev, int a, float f)
{
    const char *name = (const char *)namev;
    int n, i;
    char **list;
    int (*cmp)(const char *, const char *);
    sgxDI();
    list = __builtin_alloca(D_0011FCAC * sizeof(void *));
    n = MakeSlotList((void **)list);
    sgxEI();
    if (sgxIsStrIncWC(name)) cmp = sgxIsStrMatchWC;
    else cmp = sgxIsStrMatch;
    for (i = 0; i < n; i++) {
        char *p = list[i];
        if (*(char **)(p + 0x90) && cmp(name, *(char **)(p + 0x90)))
            SlotStop(*(int *)(p + 8), a, f, 0);
    }
}

void sgxSndStopName(int id, int a1)
{
    SlotStopName(id, a1, 0.0f);
}

void sgxSndStopFadeName(int id, float fade)
{
    SlotStopName(id, 0, fade);
}

void sgxSndStopNameF(const char *fmt, int x, ...) {
    char buf[1024];
    va_list ap;
    va_start(ap, x);
    vsprintf(buf, fmt, ap);
    SlotStopName((int)buf, x, 0.0f);
}

void sgxSndStopFadeNameF(float fade, const char *fmt, ...) {
    char buf[1024];
    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    SlotStopName((int)buf, 0, fade);
}

void SlotStopCategory(int res, int a, float f)
{
    int n, i;
    char **list;
    sgxDI();
    list = __builtin_alloca(D_0011FCAC * sizeof(void *));
    n = MakeSlotList((void **)list);
    sgxEI();
    for (i = 0; i < n; i++)
        if (*(short *)(list[i] + 0x1C) == res)
            SlotStop(*(int *)(list[i] + 8), a, f, 0);
}

void sgxSndStopCategory(int id, int a1)
{
    SlotStopCategory(id, a1, 0.0f);
}

void sgxSndStopFadeCategory(int id, float fade)
{
    SlotStopCategory(id, 0, fade);
}

void SlotStopAll(int a, float f)
{
    int n, i;
    void **list;
    sgxDI();
    list = __builtin_alloca(D_0011FCAC * sizeof(void *));
    n = MakeSlotList(list);
    sgxEI();
    for (i = 0; i < n; i++)
        SlotStop(*(int *)((char *)list[i] + 8), a, f, 0);
}

void sgxSndStopAll(int a0)
{
    SlotStopAll(a0, 0.0f);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxSndStopFadeAll(float fade) {
    SlotStopAll(0, fade);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int ConvVol12(int arg0) {
    return arg0 << 5;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndRelease);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndPause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetPr2Pan);

extern const char D_0010A540[];
void sgxSndSetDry(int id, int v) {
    char *p = SlotGetAt_7DD48(id, D_0010A540);
    if (p == NULL) return;
    sgxAttrSetValueSafe(p + 0x38, 6, ConvVol12(v < -128 ? -128 : (v > 128 ? 128 : v)));
}

extern const char D_0010A548[];
void sgxSndSetWet(int id, int v) {
    char *p = SlotGetAt_7DD48(id, D_0010A548);
    if (p == NULL) return;
    sgxAttrSetValueSafe(p + 0x38, 7, ConvVol12(v < -128 ? -128 : (v > 128 ? 128 : v)));
}

extern const char D_0010A550[];
extern const float D_0010A808;
void sgxSndSetPitch(int id, float f) {
    char *p = SlotGetAt_7DD48(id, D_0010A550);
    if (p != NULL) sgxAttrSetValueSafe(p + 0x38, 9, (int)(f * D_0010A808));
}
const float D_0010A808 = 4096.0f;

extern const char D_0010A55C[];
extern const float D_0010A80C;
void sgxSndSetSpeed(int id, float f) {
    char *p = SlotGetAt_7DD48(id, D_0010A55C);
    if (p != NULL) sgxAttrSetValueSafe(p + 0x38, 10, (int)(f * D_0010A80C));
}
const float D_0010A80C = 4096.0f;

extern const char D_0010A568[];
void sgxSndCancelLock(int id) {
    unsigned char *p = SlotGetAt_7DD48(id, D_0010A568);
    if (p != NULL) p[0x11] &= ~1;
}

void sgxSndSetStrBuf(int a0, int a1, int a2)
{
    sgxSndSetStrBufCB(a0, a1, a2, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetStrBufCB);

extern const char D_0010A580[];
void sgxSndSetStrLowBufCB(int id, int cb, int a, int b) {
    char *p = SlotGetAt_7DD48(id, D_0010A580);
    if (p == NULL) return;
    if (*(short *)(p + 0x1E) < 0) return;
    sgxBmgSetLowBufCallback(*(short *)(p + 0x1E), cb, *(int *)(p + 8), a, b);
}

int sgxSndGetStatus(int id)
{
    void *s = SlotGetAt_7DD48(id, NULL);
    if (s == NULL)
        return 0;
    return M2C_FIELD(s, int *, 0xC);
}

extern const char D_0010A590[];
void sgxSndSetReg(int id, int idx, int v) {
    char *p = SlotGetAt_7DD48(id, D_0010A590);
    if (p == NULL) return;
    if ((unsigned int)idx >= 8) {
        SGX_ERR(0x675, D_0010A598, idx);
        return;
    }
    ((int *)(p + 0xAC))[idx] = v;
}

extern const char D_0010A5B4[];
int sgxSndGetReg(int id, int idx) {
    char *p = SlotGetAt_7DD48(id, D_0010A5B4);
    if (p == NULL) return 0;
    if ((unsigned int)idx < 8) return ((int *)(p + 0xAC))[idx];
    SGX_ERR(0x684, D_0010A598, idx);
    return -1;
}

void sgxSndSetCategory(int id, unsigned int cat)
{
    char *p = SlotGetAt_7DD48(id, D_0010A5BC);
    if (p == NULL) return;
    if (cat >= 16) {
        SGX_ERR(0x695, D_0010A5C8, cat);
        return;
    }
    if (*(short *)(p + 0x1C) != cat) {
        *(short *)(p + 0x1C) = cat;
        SlotUpdateVolume(p, 1);
    }
}

int sgxSndGetCategory(int id)
{
    void *s = SlotGetAt_7DD48(id, D_0010A5E4);
    if (s == NULL)
        return 0;
    return M2C_FIELD(s, short *, 0x1C);
}

int sgxSndGetName(int id)
{
    void *s = SlotGetAt_7DD48(id, D_0010A5F0);
    if (s == NULL)
        return 0;
    return M2C_FIELD(s, int *, 0x90);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetPlayInfo);

extern const char D_0010A604[];
void *sgxSndSetMarkerCallback(int id, void *cb) {
    char *p = SlotGetAt_7DD48(id, D_0010A604);
    void *old;
    if (p == NULL) return NULL;
    old = *(void **)(p + 0xCC);
    *(void **)(p + 0xCC) = cb;
    return old;
}

int sgxSndGetMarkerCallback(int id)
{
    void *s = SlotGetAt_7DD48(id, D_0010A618);
    if (s == NULL)
        return 0;
    return M2C_FIELD(s, int *, 0xCC);
}

void sgxSndDoMarkerCallback(int id, int x) {
    char *p = SlotGetAt_7DD48(id, 0);
    if (p == NULL) return;
    if (*(void **)(p + 0xCC) != NULL) sgxCbRegist(0, 0, *(void **)(p + 0xCC), id, x);
}

extern const char D_0010A62C[];
void sgxSndSetMidiMsgMarkerRange(int id, int lo, int hi) {
    char *p = SlotGetAt_7DD48(id, D_0010A62C);
    if (p == NULL) return;
    if (lo < 0 || hi < 0) lo = hi = 0;
    p[0xE0] = lo;
    p[0xE1] = hi;
}

int sgxSndGetMidiMsgMarkerRangeLo(int id)
{
    void *s = SlotGetAt_7DD48(id, D_0010A644);
    if (s == NULL)
        return -1;
    return M2C_FIELD(s, unsigned char *, 0xE0);
}

int sgxSndGetMidiMsgMarkerRangeHi(int id)
{
    void *s = SlotGetAt_7DD48(id, D_0010A65C);
    if (s == NULL)
        return -1;
    return M2C_FIELD(s, unsigned char *, 0xE1);
}

extern const char D_0010A674[];
void sgxSndSetMidiCtrlMarkerRange(int id, int lo, int hi) {
    char *p = SlotGetAt_7DD48(id, D_0010A674);
    if (p == NULL) return;
    if (lo < 0 || hi < 0) lo = hi = -1;
    p[0xE2] = lo;
    p[0xE3] = hi;
}

int sgxSndGetMidiCtrlMarkerRangeLo(int id)
{
    void *s = SlotGetAt_7DD48(id, D_0010A68C);
    if (s == NULL)
        return -1;
    return M2C_FIELD(s, signed char *, 0xE2);
}

int sgxSndGetMidiCtrlMarkerRangeHi(int id)
{
    void *s = SlotGetAt_7DD48(id, D_0010A6A8);
    if (s == NULL)
        return -1;
    return M2C_FIELD(s, signed char *, 0xE3);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotDoFade);

void sgxSndDoFade(int a0, int a1)
{
    SlotDoFade(a0, a1, 0);
}

extern const char D_0010A6CC[];
int sgxSndGetFadeLevel(int id) {
    char *p = SlotGetAt_7DD48(id, D_0010A6CC);
    if (p == NULL) return 0;
    return *(short *)(p + 0x26) >> 5;
}

extern const char D_0010A6DC[];
extern const float D_0010A810;
float sgxSndGetFadePos(int id) {
    char *p = SlotGetAt_7DD48(id, D_0010A6DC);
    if (p == NULL) return 0.0f;
    return (*(float *)(p + 0x30) == 0.0f) ? D_0010A810 : *(float *)(p + 0x2C) / *(float *)(p + 0x30);
}
const float D_0010A810 = 1.0f;

extern const char D_0010A6E8[];
void sgxSndSetBank(int id, int idx, int v) {
    char *p = SlotGetAt_7DD48(id, D_0010A6E8);
    if (p == NULL) return;
    if ((unsigned int)idx >= 4) {
        SGX_ERR(0x76F, D_0010A598, idx);
        return;
    }
    ((short *)(p + 0xA4))[idx] = v;
}

extern const char D_0010A6F0[];
int sgxSndGetBank(int id, int idx) {
    char *p = SlotGetAt_7DD48(id, D_0010A6F0);
    if (p == NULL) return -1;
    if ((unsigned int)idx < 4) return ((short *)(p + 0xA4))[idx];
    SGX_ERR(0x77E, D_0010A598, idx);
    return -1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetChannelVolume);

extern const char D_0010A728[];
extern const char D_0010A70C[];
typedef struct { char pad[0xD0]; unsigned char chvol[16]; } SndSlotCV;
int sgxSndGetChannelVolume(int id, int ch) {
    SndSlotCV *p = SlotGetAt_7DD48(id, D_0010A728);
    if (p == NULL) return 0;
    if ((unsigned int)ch >= 16) {
        SGX_ERR(0x7A6, D_0010A70C, ch);
        return 0;
    }
    return p->chvol[ch];
}

extern const char D_0010A73C[];
int sgxSndWriteStrData(int id, const void *data, int size) {
    char *p = SlotGetAt_7DD48(id, D_0010A73C);
    if (p == NULL) return 0;
    return sgxBmgWrite(*(short *)(p + 0x1E), data, size);
}

extern const char D_0010A74C[];
void sgxSndWriteStrTerm(int id) {
    char *p = SlotGetAt_7DD48(id, D_0010A74C);
    if (p != NULL) sgxBmgWriteTerm(*(short *)(p + 0x1E));
}

extern const char D_0010A75C[];
int sgxSndGetStrFreeSize(int id) {
    char *p = SlotGetAt_7DD48(id, D_0010A75C);
    if (p == NULL) return -1;
    return sgxBmgGetFree(*(short *)(p + 0x1E));
}

extern const char D_0010A76C[];
int sgxSndGetStrLeftSize(int id) {
    char *p = SlotGetAt_7DD48(id, D_0010A76C);
    if (p == NULL) return -1;
    return sgxBmgGetLeft(*(short *)(p + 0x1E));
}

extern const char D_0010A77C[];
void sgxSndSetSyncMaster(int id, int v) {
    char *p = SlotGetAt_7DD48(id, D_0010A77C);
    if (p != NULL) *(short *)(p + 0xE6) = v;
}

int sgxSndGetSyncMaster(int id)
{
    void *s = SlotGetAt_7DD48(id, D_0010A78C);
    if (s == NULL)
        return -1;
    return M2C_FIELD(s, short *, 0xE6);
}

int sgxSndGetSyncSignalCount(int id)
{
    void *s = SlotGetAt_7DD48(id, D_0010A79C);
    if (s == NULL)
        return 0;
    return M2C_FIELD(s, int *, 0xE8);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndCheckMarkerLoop);

typedef struct { char pad[0x2C]; int mv0, mv1; } SndWorkMV;
void sgxSndSetMasterVolume(int a, int b)
{
    int va, vb;
    a = a < -128 ? -128 : (a > 128 ? 128 : a);
    b = b < -128 ? -128 : (b > 128 ? 128 : b);
    va = ConvVol12(a);
    vb = ConvVol12(b);
    if (((SndWorkMV *)SNDW)->mv0 != va || ((SndWorkMV *)SNDW)->mv1 != vb) {
        ((SndWorkMV *)SNDW)->mv0 = va;
        ((SndWorkMV *)SNDW)->mv1 = vb;
        sgxSndUpdateSlotVolumeAll(0);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndUpdateSlotVolumeAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxCategorySetSoundRange);

typedef struct { int lo, hi; } SndRange;
typedef struct { char pad[0xB4]; SndRange cat[16]; } SndWorkCat;
int sgxCategoryGetSoundRangeLo(unsigned int c) {
    if (c >= 16) return -1;
    return ((SndWorkCat *)&gWork_11FC84)->cat[c].lo;
}

int sgxCategoryGetSoundRangeHi(unsigned int c) {
    if (c >= 16) return -1;
    return ((SndWorkCat *)&gWork_11FC84)->cat[c].hi;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxCategorySetVolume);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSndGetMaxCount(void) {
    return D_0011FCAC;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSndGetFreeCount(void) {
    int temp_s0;

    sgxDI();
    temp_s0 = sgxListEnumID(&D_0011FC98, 0);
    sgxEI();
    return temp_s0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndEnumUseID);
