#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxFree(int);                               /* extern */
extern unsigned char gWork_11FE60;
unsigned char *sgxBmgGetTail(short);                             /* extern */
M2C_UNK sgxBmgGetLeft(short);                         /* extern */
M2C_UNK UnitFreeAll_81DFC();                        /* extern */
M2C_UNK sgxPortCommand(short, int);                   /* extern */
extern void *D_0011FE68;
int UnitIsUse(int, int);                            /* extern */
extern int D_0011FE88;
extern int D_0011FEA0;
M2C_UNK sgxListEnumID(M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_0011FE74;
extern unsigned char D_0011FE8C;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", D_0010A814);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SlotGetAt_81530);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", sgxSeqFree);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", GetDataOfsStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", IncDataStr);

#ifndef NULL
#define NULL ((void *)0)
#endif

void GetLeftStr(void *arg0) {
    sgxBmgGetLeft(M2C_FIELD(arg0, short *, 0x1C));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", UnitAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", UnitFree_81D64);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", UnitFreeAll_81DFC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", UnitIsUse);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", UnitFreeByID_81E8C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", LoopBegProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", LoopEndProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", CmdPlaySeq);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", CmdPlaySeqStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", CmdRel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", CmdRelAll_822E0);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", CmdPause_823A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", CmdWait);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", sgxSeqCommand);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", sgxSeqGetStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqSetReg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqGetReg);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqWait);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqJump);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqLoopBreak);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqPlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqPlayWave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqPlayNoise);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqStop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqCtrl);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqAdsr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqBendW);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", PortIsUsedGlobal);

int SesqMakeSubID(a0, s, id)
    void *a0;
    void *s;
    int id;
{
    return id | ((M2C_FIELD(s, unsigned char *, 0xB) + 1) << 24);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqSubPlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SesqSubStop);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", UnitSesqProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", UnitSesqStrProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCMNoteOnOff);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCMCtrlChg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCMProgChg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCMKeyPress);

#ifndef NULL
#define NULL ((void *)0)
#endif
void MidiCMChPress(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x30)();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCMBend);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCMSysMes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", MidiCore);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", UnitMidiProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", UnitMidiStrProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", SlotUnitProc_84650);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxseq", sgxSeqTickProc);

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
