#include "common.h"
#include "m2c_macros.h"
int *sgxMalloc(M2C_UNK, M2C_UNK);                   /* extern */
M2C_UNK sgxFree(int *);                             /* extern */
M2C_UNK sceKernelResumeThread();                    /* extern */
M2C_UNK sceKernelSuspendThread();                   /* extern */
int sceUmdGetDriveStat();                           /* extern */
M2C_UNK sceUmdWaitDriveStat(M2C_UNK);               /* extern */
M2C_UNK sgxPrintfPref(int, M2C_UNK *, M2C_UNK, M2C_UNK *); /* extern */
extern unsigned char D_0010B074;
extern int gSgxDebugFlags;
extern int gSgxPrefErr;
M2C_UNK FreqAdd(int, M2C_UNK, int, int, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK FreqRemove();                               /* extern */
M2C_UNK FreqSync(int, M2C_UNK);                     /* extern */
M2C_UNK sgxPspVoGetEnvelope();                      /* extern */
M2C_UNK sgxPspVoGetVolume();                        /* extern */
M2C_UNK sgxPspVoGetPitch();                         /* extern */


void *At3GetSlot(int, const char *);
int At3Play(int, int, int, int, int, int, int, int, int);
void sgxPrintf(const char *, ...);
extern int gDICount;
extern int gDIStat;
int sceSasSetEffectVolume(int, int);
int sceKernelDelayThread(unsigned int);
int sceKernelWaitThreadEnd(int, void *);
int sceKernelDeleteThread(int);
int sceKernelCpuResumeIntr(int);
#define GW ((char *)gWork_1207F0)

void ssePrint(const char *s) {
    if (gSgxDebugFlags & 4) sgxPrintf(" %s", s);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspWaitReadyTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspTickProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxDI);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxEI);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);

int *sgxMutexCreate(signed char *arg0) {
    int *temp_v0;
    int *var_v1;
    int temp_v0_2;

    temp_v0 = sgxMalloc(4, 1);
    if ((temp_v0 == NULL) || (temp_v0_2 = sceKernelCreateSema(arg0, 0U, 1, 1, NULL), *temp_v0 = temp_v0_2, var_v1 = temp_v0, (temp_v0_2 < 0))) {
        sgxMutexDelete(temp_v0);
        var_v1 = NULL;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelDeleteSema(int semid);

void sgxMutexDelete(int *arg0) {
    int temp_v0;

    if (arg0 != NULL) {
        temp_v0 = *arg0;
        if (temp_v0 >= 0) {
            sceKernelDeleteSema(temp_v0);
        }
        sgxFree(arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
void sgxMutexLock(int *arg0) {
    if (arg0 != NULL) {
        sceKernelWaitSema(*arg0, 1, NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelSignalSema(int semid, int signal);
void sgxMutexUnlock(int *arg0) {
    if (arg0 != NULL) {
        sceKernelSignalSema(*arg0, 1);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelGetThreadId(void);
void sgxGetCurrentThreadID(void) {
    sceKernelGetThreadId();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void SuspendThread(int arg0, int arg1) {
    if (arg0 >= 0) {
        if (arg1 != 0) {
            sceKernelSuspendThread();
        } else {
            sceKernelResumeThread();
        }
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspSuspendThreadAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspEnumThreadID);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B074);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B080);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B094);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B0AC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", PcmSendInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", PcmSendTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", PcmSendMain);

extern int gWork_1207F0[];
int sgxPspSetMasterDecodeCallback(int cb)
{
    int old = gWork_1207F0[0x6C / 4];
    gWork_1207F0[0x6C / 4] = cb;
    return old;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SasInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SasTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SasDecode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SasFlush);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3AllocAtracID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3FreeAtracID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Init);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Term);

#ifndef NULL
#define NULL ((void *)0)
#endif
int At3BufGetFree(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x2094) - M2C_FIELD(arg0, int *, 0x2098);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
void *memcpy(void *d, const void *s, unsigned int n);
void At3BufWrite(void *arg0, int arg1, int arg2) {
    int temp_a0;
    int temp_s3;
    int temp_v1;
    int var_s0;
    int var_s2;
    unsigned int temp_s0;

    temp_s3 = arg2 * 4;
    var_s2 = 0;
    if (temp_s3 > 0) {
        var_s0 = M2C_FIELD(arg0, int *, 0x2094);
        do {
            temp_a0 = M2C_FIELD(arg0, int *, 0x208C);
            temp_s0 = __builtin_allegrex_min(var_s0 - temp_a0, temp_s3 - var_s2);
            memcpy(arg0 + temp_a0 + 0x209C, arg1 + var_s2, temp_s0);
            temp_v1 = M2C_FIELD(arg0, int *, 0x2094);
            var_s2 += temp_s0;
            var_s0 = temp_v1;
            M2C_FIELD(arg0, int *, 0x208C) = (int) ((int) (M2C_FIELD(arg0, int *, 0x208C) + temp_s0) % temp_v1);
        } while (var_s2 < temp_s3);
    }
    sceKernelWaitSema(M2C_FIELD(arg0, int *, 0x18), 1, NULL);
    M2C_FIELD(arg0, int *, 0x2098) = (int) (M2C_FIELD(arg0, int *, 0x2098) + temp_s3);
    sceKernelSignalSema(M2C_FIELD(arg0, int *, 0x18), 1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int At3BufGetLeft(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x2098);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3BufGetLinearLeftOfs);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *At3BufGetTop(void *arg0) {
    return arg0 + M2C_FIELD(arg0, int *, 0x2090) + 0x209C;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *At3BufGetTopOfs(void *arg0, int arg1) {
    return arg0 + ((int) (M2C_FIELD(arg0, int *, 0x2090) + arg1) % (int) M2C_FIELD(arg0, int *, 0x2094)) + 0x209C;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3BufInc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3ThMain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Play);

int At3PlayMem(int a, int b, int c, int d, int e, int f) {
    return At3Play(a, 0, b, c, d, 0, e, f, -1);
}

int At3PlayFile(int a, int b, int c, int d, int e, int f, int g, int h) {
    return At3Play(a, 1, b, c, d, e, f, g, h);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3GetSlot);

void At3Stop(int id) {
    char *p = At3GetSlot(id, "Stop");
    if (p != NULL) p[0x36] = 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3StopAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3SetVolume);

void At3SetPitch(int id, int v) {
    char *p = At3GetSlot(id, "SetPitch");
    if (p != NULL) *(short *)(p + 0x60A0) = (v <= 0) ? 1 : (v < 0x4000 ? v : 0x4000);
}

void At3Pause(int id, int v) {
    char *p = At3GetSlot(id, "Pause");
    if (p != NULL) p[0x37] = v;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3GetStatus);

long long At3GetPlaySamples(int id) {
    char *p = At3GetSlot(id, 0);
    if (p == NULL) return 0;
    return *(long long *)(p + 0x60A8);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Mix);

extern int gWork_1207F0[];
int sgxPspSetAt3DecodeCallback(int cb)
{
    int old = gWork_1207F0[0x45C / 4];
    gWork_1207F0[0x45C / 4] = cb;
    return old;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqTerm);

#ifndef NULL
#define NULL ((void *)0)
#endif
int memcmp(const void *a, const void *b, unsigned int n);
int IsPathUmd(void *arg0) {
    return memcmp(arg0, "disc0:", 6U) == 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void UmdWaitReadable(void) {
    if (!(sceUmdGetDriveStat() & 0x20)) {
        if (gSgxDebugFlags & 1) {
            sgxPrintfPref(gSgxPrefErr, &D_0010B074, 0xAB3, "wait UMD ...\n");
        }
        sceUmdWaitDriveStat(0x20);
        if (!(gSgxDebugFlags & 1)) {

        } else {
            sgxPrintfPref(gSgxPrefErr, &D_0010B074, 0xAB7, "UMD ready !!\n");
        }
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", WaitOneSec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FileCmdRopen);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FileCmdClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FileCmdRead);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqMain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqAdd);

int FreqRopen(int a, int b, int c, int d) {
    return FreqAdd(a, 0, b, c, d, 0, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void FreqClose(int arg0, int arg1, int arg2) {
    FreqRemove();
    FreqAdd(arg0, 1, arg1, arg2, 0, 0, 0);
    FreqSync(arg0, 1);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqRead);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqRemove);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqSync);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxVoAlloc);

extern char *D_00120860;
typedef struct { char pad[4]; unsigned char used:1; } SgxVo;
void sgxVoFree(int i)
{
    SgxVo *v = (SgxVo *)D_00120860;
    v = (SgxVo *)((char *)v + i * 48);
    v->used = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", VoVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", VoCtrlSas);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", VoCtrlAt3);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxVoCtrl);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", VoiceToDeviceIndex);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sgxPspGetVoiceCount(void) {
    sgxVoGetSlotNum();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B5DC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspVoGetEnvelope);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxPspGetVoiceEnvelope(void) {
    sgxPspVoGetEnvelope();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspVoGetVolume);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxPspGetVoiceVolume(void) {
    sgxPspVoGetVolume();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspVoGetPitch);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxPspGetVoicePitch(void) {
    sgxPspVoGetPitch();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspAt3GetLocalID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxEffSetType);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxEffSetDepth);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxEffSetParam);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxSin12);
