#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxFree(int);                               /* extern */
extern unsigned char gWork_11FC84;
M2C_UNK SlotPlay(M2C_UNK, int, int, M2C_UNK, int, M2C_UNK); /* extern */
extern unsigned char D_0010A4D4;
extern unsigned char D_0010A4E4;
M2C_UNK SlotStopAll(M2C_UNK);                       /* extern */
extern int D_0011FCAC;
M2C_UNK sgxDI();                                    /* extern */
M2C_UNK sgxEI();                                    /* extern */
int sgxListEnumID(M2C_UNK *, M2C_UNK);              /* extern */
extern unsigned char D_0011FC98;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotGetAt_7DD48);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotGetAtStop);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", CheckSync);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetSysReg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetSysReg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndUseTuning);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndPlayNameF);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotStop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStopFade);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotStopRes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStopRes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStopFadeRes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotStopName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStopName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStopFadeName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStopNameF);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStopFadeNameF);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotStopCategory);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStopCategory);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStopFadeCategory);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotStopAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndStopAll);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxSndStopFadeAll(void) {
    SlotStopAll(0);
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetDry);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetWet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetPitch);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetSpeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndCancelLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetStrBuf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetStrBufCB);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetStrLowBufCB);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetReg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetReg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetCategory);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetCategory);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetPlayInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetMarkerCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetMarkerCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndDoMarkerCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetMidiMsgMarkerRange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetMidiMsgMarkerRangeLo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetMidiMsgMarkerRangeHi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetMidiCtrlMarkerRange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetMidiCtrlMarkerRangeLo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetMidiCtrlMarkerRangeHi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", SlotDoFade);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndDoFade);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetFadeLevel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetFadePos);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetBank);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetBank);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetChannelVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetChannelVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndWriteStrData);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndWriteStrTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetStrFreeSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetStrLeftSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetSyncMaster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetSyncMaster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndGetSyncSignalCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndCheckMarkerLoop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndSetMasterVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxSndUpdateSlotVolumeAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxCategorySetSoundRange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxCategoryGetSoundRangeLo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsnd", sgxCategoryGetSoundRangeHi);

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
