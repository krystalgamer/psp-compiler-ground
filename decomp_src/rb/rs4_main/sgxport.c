#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxFree(int);                               /* extern */
extern unsigned char gWork_11FEA4;
M2C_UNK UnitFreeAll_85854();                        /* extern */
M2C_UNK ResetMidiChData(int);                       /* extern */
M2C_UNK AttrSetValue(int, short, int);                /* extern */
M2C_UNK FadeFree(void *);                           /* extern */
extern int D_0011FECC;
extern int D_0011FEE4;
extern int D_0011FEFC;
M2C_UNK sgxListEnumID(M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_0011FEB8;
extern unsigned char D_0011FED0;
extern unsigned char D_0011FEE8;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AD00);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", SlotGetAt_848F0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", ResetMidiChData);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", AttrClear);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", AttrSetValue);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", AttrGetValue);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", FadeAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", FadeFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", FadeFreeAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", FadeFreeByAttr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", AllocTakenVoice);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitTakenVoice);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitVoiceAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitFree_85774);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitFreeAll_85854);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitFreeByID_8589C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitFreeAtAfter);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitPlayWave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPlayNote);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPlayWave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPlayNoise);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPlayMidi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdRelAny);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdRelAll_86218);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdStopAny);

#ifndef NULL
#define NULL ((void *)0)
#endif

void CmdStopAll_86320(void) {
    UnitFreeAll_85854();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdCtrlID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdCtrlMidi);

#ifndef NULL
#define NULL ((void *)0)
#endif

void CmdCtrlMidiReset(int arg0, void *arg1) {
    ResetMidiChData(arg0 + (M2C_FIELD(arg1, int *, 4) * 6) + 0x38);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdAdsrID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdBendWID);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPause_866D0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortCommand);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortGetStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortGetUnitStatus);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", IsLfoActive);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AE38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AEC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AECC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", LfoProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", LfoCalc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitVolumeProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitPitchProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitMergeVoiceStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", SlotUnitProc_8716C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", SlotUnitPauseProc);

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
