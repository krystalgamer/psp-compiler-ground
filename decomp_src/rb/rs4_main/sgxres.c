#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxFree(int);                               /* extern */
extern unsigned char gWork_11FC38;
void *ResGetSlot(int, M2C_UNK);                     /* extern */
M2C_UNK sgxDI();                                    /* extern */
M2C_UNK sgxEI();                                    /* extern */
extern int D_0011FC40;
int sgxListEnumID(M2C_UNK *, M2C_UNK);              /* extern */
extern unsigned char D_0011FC54;
extern unsigned char D_0011FC44;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxres", D_0010A158);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", ResGetSlot);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", ResFindChunk);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResAttachBody);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResAttachBodyFile);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResCloseAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetHeaderPtr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetBodyPtr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetName);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxres", D_0010A21C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResSetBank);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxres", D_0010A228);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetBank);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResSetUserData);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetUserData);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetBankPtr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindWave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindRgn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindSeq);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindAdsr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResOfsToData);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetRefCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResIsClosing);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResReqToName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResNameToReq);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResNameToReqGlobal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResCanPlayType);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResEnumPlayName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetWaveCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResIsWaveLoop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetWaveInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetSeqCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResIsSeqLoop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResSetCategory);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetCategory);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetWaveSurroundCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetWaveSurroundInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindWaveSurround);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindCopyWaveSurroundInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetWaveMarkerCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetWaveMarkerInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResFindWaveMarker);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", RoundWavePos);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResRoundWavePos);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", ResUpdateTuningSlot);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", ResUpdateTuningSlotAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", ResTuningOpen);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", ResTuningClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", ResFindTuningData);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxResGetTuningVolume);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxdGetBodySize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxres", sgxdGetBodyPtr);

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
