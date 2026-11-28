/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxFree(int);                               /* extern */
extern unsigned char gWork_11FC38;
M2C_UNK sgxDI();                                    /* extern */
M2C_UNK sgxEI();                                    /* extern */
extern int D_0011FC40;
int sgxListEnumID(M2C_UNK *, M2C_UNK);              /* extern */
extern unsigned char D_0011FC54;
extern unsigned char D_0011FC44;


#define SLOT_NAME(s) ((M2C_UNK)(s))
int *ResGetFileHeader(int *arg0);

void sgxResClose(int id);
static inline char *ResListFirst(void) {
    char *p = *(char **)(&D_0011FC44 + 4);
    return (*(int *)(p + 8) < 0) ? NULL : p;
}
void *sgxResFindWave(int id, int idx, int z);
int RoundWavePos(void *w, long long pos);

extern int gSgxDebugFlags;
extern int gSgxPrefErr;
extern const char D_0010A158[];
extern const char D_0010A228[];
void sgxPrintfPref(int, const char *, int, const char *, ...);
void sgxStrCpyN(char *, const char *, int);
void ResUpdateTuningSlot(void *);
void ResUpdateTuningSlotAll(void);
void sgxSndUseTuning(int);
#define SGX_ERR(line, ...) if (gSgxDebugFlags & 1) sgxPrintfPref(gSgxPrefErr, D_0010A158, line, __VA_ARGS__)
typedef struct { int pad[0x10]; int nOpen; int nOpen2; int nTune; } ResWorkT;

extern int gSgxPrefWarn;
typedef struct { char pad[4]; char *slots; int num; } ResWorkS;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxres", D_0010A158);

#define WW ((ResWorkS *)&gWork_11FC38)
void *ResGetSlot(int id, M2C_UNK namev)
{
    const char *name = (const char *)namev;
    if (id >= 0 && id <= WW->num - 1) {
        char *p = WW->slots + id * 0x184;
        if (*(int *)(p + 0xC) & 1) return p;
    }
    if (name != NULL && (gSgxDebugFlags & 2)) {
        sgxPrintfPref(gSgxPrefWarn, D_0010A158, 0x93, "sgxRes%s unknown ID (%d)\n", name, id);
        return NULL;
    }
    return NULL;
}
#undef WW

#ifndef NULL
#define NULL ((void *)0)
#endif
int *ResGetFileHeader(int *arg0) {
    int *var_v0;

    var_v0 = NULL;
    if (arg0 != NULL) {
        var_v0 = ((*arg0 ^ 0x44584753) != 0) ? NULL : arg0;
    }
    return var_v0;
}

void *ResFindChunk(char *res, int id) {
    int size = *(int *)(res + 8);
    int ofs = 0x10;
    while (ofs < size) {
        int *c = (int *)(res + ofs);
        ofs += 8;
        if (c[0] == id) return res + ofs;
        ofs += c[1];
    }
    return NULL;
}

extern void *D_0011FC48;

int MakeResList(void **arg0) {
    int var_a1;
    void **var_a0;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_v0;

    var_a0 = arg0;
    var_a1 = 0;
    temp_v1 = (M2C_FIELD(D_0011FC48, int *, 8) < 0) ? NULL : D_0011FC48;
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResInit);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void sgxResTerm(void) {
    if (M2C_FIELD(&gWork_11FC38, int *, 0) == 0) {

    } else {
        sgxFree(M2C_FIELD(&gWork_11FC38, int *, 4));
        memset(&gWork_11FC38, 0, 0x4CU);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResOpen);

int sgxResAttachBody(int id, int body) {
    char *p = ResGetSlot(id, SLOT_NAME("AttachBody"));
    if (p == NULL) return 0;
    *(int *)(p + 0x68) = 1;
    *(int *)(p + 0x70) = body;
    *(int *)(p + 0x6C) = 0;
    sceKernelDcacheWritebackInvalidateAll();
    return 1;
}

int sgxResAttachBodyFile(int id, const char *name, int size) {
    char *p = ResGetSlot(id, SLOT_NAME("AttachBodyFile"));
    if (p == NULL) return 0;
    *(int *)(p + 0x68) = 2;
    *(int *)(p + 0x6C) = size;
    sgxStrCpyN(p + 0x74, name, 0x100);
    *(char **)(p + 0x70) = p + 0x74;
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResCloseAll);

void *sgxResGetHeaderPtr(int id) {
    char *p = ResGetSlot(id, SLOT_NAME("GetHeader"));
    if (p == NULL) return NULL;
    return *(void **)(p + 0x14);
}

void *sgxResGetBodyPtr(int id, int *isFile) {
    char *p = ResGetSlot(id, SLOT_NAME("GetBody"));
    if (p == NULL) return NULL;
    if (isFile != NULL) *isFile = *(int *)(p + 0x68) == 2;
    return *(void **)(p + 0x70);
}

extern const char D_0010A21C[];
const char *sgxResGetName(int id) {
    char *p = ResGetSlot(id, SLOT_NAME("GetResName"));
    if (p == NULL) return D_0010A21C;
    return *(const char **)(p + 0x18);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxres", D_0010A21C);

void sgxResSetBank(int id, int idx, int v) {
    char *p = ResGetSlot(id, SLOT_NAME("SetBank"));
    if (p == NULL) return;
    if ((unsigned int)idx >= 4) {
        SGX_ERR(0x20B, D_0010A228, idx);
        return;
    }
    ((short *)(p + 0x178))[idx] = v;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxres", D_0010A228);

int sgxResGetBank(int id, int idx) {
    char *p = ResGetSlot(id, SLOT_NAME("GetBank"));
    if (p == NULL) return -1;
    if ((unsigned int)idx < 4) return ((short *)(p + 0x178))[idx];
    SGX_ERR(0x21A, D_0010A228, idx);
    return -1;
}

void sgxResSetUserData(int id, int data) {
    char *p = ResGetSlot(id, SLOT_NAME("SetUserData"));
    if (p != NULL) *(int *)(p + 0x180) = data;
}

int sgxResGetUserData(int id) {
    char *p = ResGetSlot(id, SLOT_NAME("GetUserData"));
    if (p == NULL) return 0;
    return *(int *)(p + 0x180);
}

void *sgxResGetBankPtr(int id) {
    char *p = ResGetSlot(id, SLOT_NAME("GetBankPtr"));
    if (p == NULL) return NULL;
    return p + 0x178;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindWave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindRgn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindSeq);

int sgxResFindAdsr(int id, int idx) {
    char *p = ResGetSlot(id, SLOT_NAME("FindAdsr"));
    char *t;
    if (p == NULL) return 0;
    t = *(char **)(p + 0x44);
    if (t == NULL) return 0;
    if (idx < 0) return 0;
    if (*(int *)(p + 0x48) - 1 < idx) return 0;
    return *(int *)(t + idx * 4 + 8);
}

void *sgxResOfsToData(int id, int ofs) {
    char *p = ResGetSlot(id, SLOT_NAME("OfsToData"));
    if (p == NULL || *(char **)(p + 0x14) == NULL || ofs == 0) return NULL;
    return *(char **)(p + 0x14) + ofs;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxResLock(int arg0) {
    int var_s0;
    void *temp_v0;

    sgxDI();
    temp_v0 = ResGetSlot(arg0, 0);
    var_s0 = 0;
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, signed char *, 0x10) == 0)) {
        var_s0 = 1;
        M2C_FIELD(temp_v0, int *, 0x174) = (int) (M2C_FIELD(temp_v0, int *, 0x174) + 1);
    }
    sgxEI();
    return var_s0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxResUnlock(int arg0) {
    void *temp_v0;

    sgxDI();
    temp_v0 = ResGetSlot(arg0, 0);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0x174) = (int) (M2C_FIELD(temp_v0, int *, 0x174) - 1);
    }
    sgxEI();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResSyncUse);

int sgxResGetRefCount(int id) {
    char *p = ResGetSlot(id, SLOT_NAME("GetRefCount"));
    if (p == NULL) return 0;
    return *(int *)(p + 0x174);
}

int sgxResIsClosing(int id) {
    char *p = ResGetSlot(id, SLOT_NAME("IsClosing"));
    if (p == NULL) return 0;
    return *(signed char *)(p + 0x10);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResReqToName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResNameToReq);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResNameToReqGlobal);

int sgxResCanPlayType(int id, int type) {
    char *p = ResGetSlot(id, SLOT_NAME("CanPlay"));
    if (p == NULL) return 0;
    switch (type) {
    case 0: return *(int *)(p + 0x30) > 0;
    case 1: return *(int *)(p + 0x20) > 0;
    case 2: return *(int *)(p + 0x38) > 0;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResEnumPlayName);

int sgxResGetWaveCount(int id) {
    char *p = ResGetSlot(id, SLOT_NAME("GetWaveCount"));
    if (p == NULL) return 0;
    return *(int *)(p + 0x30);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResIsWaveLoop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetWaveInfo);

int sgxResGetSeqCount(int id, int idx) {
    char *p = ResGetSlot(id, SLOT_NAME("GetSeqCount"));
    int *t;
    int o;
    if (p == NULL) return 0;
    t = *(int **)(p + 0x34);
    if (t == NULL) return 0;
    if (idx >= *(int *)(p + 0x38)) return 0;
    if (idx < 0) return *(int *)(p + 0x38);
    o = t[idx + 2];
    if (o == 0) return 0;
    return *(int *)(*(char **)(p + 0x14) + o + 4);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResIsSeqLoop);

void sgxResSetCategory(int id, int cat) {
    char *p = ResGetSlot(id, SLOT_NAME("SetCategory"));
    if (p == NULL) return;
    if ((unsigned int)cat >= 16) {
        SGX_ERR(0x462, "out of range category (%d)\n", cat);
        return;
    }
    *(short *)(p + 0x12) = cat;
}

int sgxResGetCategory(int id) {
    char *p = ResGetSlot(id, "GetCategory");
    if (p == NULL) return -1;
    return *(short *)(p + 0x12);
}

int sgxResGetWaveSurroundCount(int id, int idx) {
    char *p = ResGetSlot(id, SLOT_NAME("GetWaveSurroundCount"));
    char *t;
    if (p == NULL) return 0;
    t = *(char **)(p + 0x2C);
    if (t == NULL) return 0;
    if (idx < 0) return 0;
    if (*(int *)(p + 0x30) - 1 < idx) return 0;
    return *(int *)(t + idx * 8 + 8);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetWaveSurroundInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindWaveSurround);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindCopyWaveSurroundInfo);

int sgxResGetWaveMarkerCount(int id, int idx) {
    char *p = ResGetSlot(id, SLOT_NAME("GetWaveMarkerCount"));
    char *t;
    if (p == NULL) return 0;
    t = *(char **)(p + 0x28);
    if (t == NULL) return 0;
    if (idx < 0) return 0;
    if (*(int *)(p + 0x30) - 1 < idx) return 0;
    return *(int *)(t + idx * 8 + 8);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetWaveMarkerInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindWaveMarker);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", RoundWavePos);

int sgxResRoundWavePos(int id, int idx, long long pos) {
    void *w = sgxResFindWave(id, idx, 0);
    if (w == NULL) return -1;
    return RoundWavePos(w, pos);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResWaveTimeToPos);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResWavePosToTime);

void ResResetTuningInfo(int *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", ResAttachTuningInfo);

int ResAttachTuningInfo(void *, void *, const char *);
void ResUpdateTuningSlot(void *sv)
{
    char *s = sv;
    int n, i;
    char **list;
    ResResetTuningInfo((int *)(s + 0x54));
    if (*(char **)(s + 0x18) == NULL || **(char **)(s + 0x18) == 0) return;
    list = __builtin_alloca(((ResWorkS *)&gWork_11FC38)->num * sizeof(void *));
    n = MakeResList((void **)list);
    for (i = 0; i < n; i++) {
        char *r = list[i];
        if (*(int *)(r + 0x4C))
            ((ResWorkT *)&gWork_11FC38)->nOpen += ResAttachTuningInfo(s + 0x54, r, *(char **)(s + 0x18));
    }
}

int ResAttachTuningInfo(void *, void *, const char *);
void ResUpdateTuningSlotAll(void)
{
    int n, i;
    char **list;
    ResResetTuningInfo((int *)(&gWork_11FC38 + 0x2C));
    ((ResWorkT *)&gWork_11FC38)->nOpen = 0;
    ((ResWorkT *)&gWork_11FC38)->nOpen2 = 0;
    list = __builtin_alloca(((ResWorkS *)&gWork_11FC38)->num * sizeof(void *));
    n = MakeResList((void **)list);
    for (i = 0; i < n; i++) {
        char *r = list[i];
        ResUpdateTuningSlot(r);
        if (*(int *)(r + 0x4C))
            ((ResWorkT *)&gWork_11FC38)->nOpen2 += ResAttachTuningInfo(&gWork_11FC38 + 0x2C, r, D_0010A21C);
    }
}

#define TW ((ResWorkT *)&gWork_11FC38)
void ResTuningOpen(char *r)
{
    if (*(int *)(r + 0x4C)) {
        ResUpdateTuningSlotAll();
        TW->nTune++;
    }
    if (TW->nTune > 0) ResUpdateTuningSlot(r);
    if (TW->nOpen > 0 || TW->nOpen2 > 0) sgxSndUseTuning(1);
}
#undef TW

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", ResTuningClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", ResFindTuningData);

unsigned char *ResFindTuningData(void *, const char *, int *, int *);
int sgxResGetTuningVolume(int id, const char *name)
{
    int ofs;
    int def = -1;
    unsigned char *t;
    if (((ResWorkT *)&gWork_11FC38)->nOpen > 0 && id >= 0) {
        char *r = ResGetSlot(id, 0);
        if (r != NULL) {
            t = ResFindTuningData(r + 0x54, name, &ofs, &def);
            if (t != NULL) return t[ofs];
        }
    }
    if (((ResWorkT *)&gWork_11FC38)->nOpen2 > 0) {
        t = ResFindTuningData(&gWork_11FC38 + 0x2C, name, &ofs, &def);
        if (t != NULL) return t[ofs];
    }
    return def < 0 ? 0x80 : def;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sgxdGetHeaderSize(int *arg0) {
    int *temp_v0;
    int var_v1;

    temp_v0 = ResGetFileHeader(arg0);
    var_v1 = -1;
    if (temp_v0 != NULL) {
        var_v1 = M2C_FIELD(temp_v0, int *, 8);
    }
    return var_v1;
}

int sgxdGetBodySize(int *res) {
    int *h = ResGetFileHeader(res);
    if (h == NULL) return -1;
    return h[3] & 0x7FFFFFFF;
}

void *sgxdGetBodyPtr(char *res) {
    int *h = ResGetFileHeader((int *)res);
    if (h == NULL) return NULL;
    if (h[3] >= 0) return NULL;
    return res + h[2];
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxResGetMaxCount(void) {
    return D_0011FC40;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxResGetFreeCount(void) {
    int temp_s0;

    sgxDI();
    temp_s0 = sgxListEnumID(&D_0011FC54, 0);
    sgxEI();
    return temp_s0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxResEnumOpenID(int arg0) {
    int temp_s0;

    sgxDI();
    temp_s0 = sgxListEnumID(&D_0011FC44, arg0);
    sgxEI();
    return temp_s0;
}
