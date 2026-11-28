/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
int *sgxMalloc(M2C_UNK, M2C_UNK);                   /* extern */
M2C_UNK sgxFree(int *);                             /* extern */
M2C_UNK sceKernelResumeThread();                    /* extern */
M2C_UNK sceKernelSuspendThread();                   /* extern */
int sceUmdGetDriveStat();                           /* extern */
M2C_UNK sceUmdWaitDriveStat(M2C_UNK);               /* extern */
int sgxPrintfPref(int, const void *, int, const char *, ...);
extern unsigned char D_0010B074;
extern int gSgxDebugFlags;
extern int gSgxPrefErr;
int FreqAdd(int, int, int, int, int, int, int);
void FreqRemove(int id);
int FreqSync(int id, int wait);
float sgxPspVoGetEnvelope(int);
float sgxPspVoGetVolume(int, int);
float sgxPspVoGetPitch(int);


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

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))
#define SGX_ERR(line, ...) if (gSgxDebugFlags & 1) sgxPrintfPref(gSgxPrefErr, &D_0010B074, line, __VA_ARGS__)
int sceKernelCpuSuspendIntr(void);
int sceSasExit(void);
int sceSasSetEffectParam(int, int);
int sceIoClose(int);
void VoCtrlSas(void *, int, int, int);
void VoCtrlAt3(void *, int, int, int);
int sgxVoAllocDevice(int, int, int, int, int, int);

typedef struct { char pad[0x44C]; char *slots; int num; } PspWorkS;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspInit);

extern int gWork_1207F0[];
void sgxPspWaitReadyTerm(void) {
    int i;
    for (i = 0; i < gWork_1207F0[0x450 / 4]; i++) {
        unsigned char *e = (unsigned char *)(gWork_1207F0[0x44C / 4] + i * 0x60B0);
        while (e[0x34]) sceKernelDelayThread(10000);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspTickProc);

extern int gWork_1207F0[];
void sgxDI(void) {
    int *w = gWork_1207F0;
    if (w[3] != 0) {
        sceKernelWaitSema(w[2], 1, NULL);
        return;
    }
    if (gDICount == 0) gDIStat = sceKernelCpuSuspendIntr();
    gDICount++;
}

extern int gWork_1207F0[];
void sgxEI(void) {
    int *w = gWork_1207F0;
    if (w[3] != 0) {
        sceKernelSignalSema(w[2], 1);
        return;
    }
    if (--gDICount == 0) sceKernelCpuResumeIntr(gDIStat);
}

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

void sgxPspSuspendThreadAll(int suspend)
{
    int i;
    for (i = 0; i < gWork_1207F0[0x60 / 4]; i++)
        SuspendThread(*(int *)(GW + 0x1C + i * 0x28), suspend);
    for (i = 0; i < gWork_1207F0[0x450 / 4]; i++)
        SuspendThread(*(int *)(gWork_1207F0[0x44C / 4] + i * 0x60B0 + 0x10), suspend);
}

int sgxPspEnumThreadID(int *out)
{
    int n = 0;
    int i;
    for (i = 0; i < gWork_1207F0[0x60 / 4]; i++) {
        if (out != NULL) out[n] = *(int *)(GW + 0x1C + i * 0x28);
        n++;
    }
    for (i = 0; i < gWork_1207F0[0x450 / 4]; i++) {
        if (out != NULL) out[n] = *(int *)(gWork_1207F0[0x44C / 4] + i * 0x60B0 + 0x10);
        n++;
    }
    return n;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B074);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B080);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B094);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B0AC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", PcmSendInit);

void PcmSendTerm(int *p) {
    if (p[0] == 0) return;
    sceKernelWaitThreadEnd(p[3], NULL);
    sceKernelDeleteThread(p[3]);
    p[3] = -1;
    sgxFree((int *)p[8]);
    p[9] = 0;
    p[8] = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", PcmSendMain);

extern int gWork_1207F0[];
int sgxPspSetMasterDecodeCallback(int cb)
{
    int old = gWork_1207F0[0x6C / 4];
    gWork_1207F0[0x6C / 4] = cb;
    return old;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SasInit);

void SasTerm(void) {
    int *w = gWork_1207F0;
    if (w[0x460 / 4] == 0) return;
    if (w[0x468 / 4] >= 0) {
        sceKernelDeleteSema(w[0x468 / 4]);
        w[0x468 / 4] = -1;
    }
    sceSasExit();
    if (w[0x47C / 4] != 0) {
        sgxFree((int *)w[0x47C / 4]);
        w[0x47C / 4] = 0;
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SasDecode);

typedef struct { int f0; int set[13]; int cur[13]; } SasFl;
int SasFlush(void) {
    int i, ret;
    sceKernelWaitSema(gWork_1207F0[0x468 / 4], 1, NULL);
    for (i = 0; i < gWork_1207F0[0x480 / 4]; i++) {
        SasFl *e = (SasFl *)(gWork_1207F0[0x47C / 4] + i * 0x6C);
        int *d = e->cur, *s = e->set;
        int m = s[0];
        if (m == 0) continue;
        {
            int j;
            for (j = 1; j < 13; j++)
                if ((m >> j) & 1) d[j] = s[j];
            d[0] |= m;
            s[0] = 0;
        }
    }
    ret = gWork_1207F0[0x488 / 4];
    sceKernelSignalSema(gWork_1207F0[0x468 / 4], 1);
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3AllocAtracID);

int sceAtracReleaseAtracID(int);
void At3FreeAtracID(signed char *s)
{
    if (s[0x30] >= 0) {
        sceAtracReleaseAtracID(s[0x30]);
        sceKernelDelayThread(10000);
        s[0x30] = -1;
        sceKernelWaitSema(gWork_1207F0[0x448 / 4], 1, NULL);
        switch (*(short *)(s + 0x2C)) {
        case 0x1000: (*(volatile int *)&gWork_1207F0[0x458 / 4])--; break;
        case 0x1001: (*(volatile int *)&gWork_1207F0[0x454 / 4])--; break;
        }
        sceKernelSignalSema(gWork_1207F0[0x448 / 4], 1);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Init);

void At3Term(void) {
    int i;
    if (gWork_1207F0[0x438 / 4] == 0) return;
    for (i = 0; i < gWork_1207F0[0x450 / 4]; i++) {
        int *e = (int *)(gWork_1207F0[0x44C / 4] + i * 0x60B0);
        if (e[4] >= 0) {
            e[3] = 0;
            sceKernelSignalSema(e[5], 1);
            sceKernelWaitThreadEnd(e[4], NULL);
            sceKernelDeleteThread(e[4]);
            e[4] = -1;
        }
        At3FreeAtracID((signed char *)e);
        FreqRemove(e[1]);
        if (e[10] >= 0) {
            FreqClose(e[1], e[7], e[10]);
            ((char *)e)[0x3B] = 0;
            e[10] = -1;
        }
        if (e[6] >= 0) {
            sceKernelDeleteSema(e[6]);
            e[6] = -1;
        }
        if (e[5] >= 0) {
            sceKernelDeleteSema(e[5]);
            e[5] = -1;
        }
    }
    if (gWork_1207F0[0x44C / 4] != 0) {
        sgxFree((int *)gWork_1207F0[0x44C / 4]);
        gWork_1207F0[0x44C / 4] = 0;
    }
    if (gWork_1207F0[0x448 / 4] >= 0) {
        sceKernelDeleteSema(gWork_1207F0[0x448 / 4]);
        gWork_1207F0[0x448 / 4] = -1;
    }
}

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

int At3BufGetLinearLeftOfs(char *b, int ofs) {
    int pos = *(int *)(b + 0x2090) + ofs;
    int size = *(int *)(b + 0x2094);
    int left = *(int *)(b + 0x2098) - ofs;
    int lin = size - pos % size;
    return left < lin ? left : lin;
}

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

void At3BufInc(char *b, int n) {
    *(long long *)(b + 0x60A8) += n;
    *(int *)(b + 0x2090) = (*(int *)(b + 0x2090) + n * 4) % *(int *)(b + 0x2094);
    sceKernelWaitSema(*(int *)(b + 0x18), 1, NULL);
    *(int *)(b + 0x2098) -= n * 4;
    sceKernelSignalSema(*(int *)(b + 0x18), 1);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3ThMain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Play);

int At3PlayMem(int a, int b, int c, int d, int e, int f) {
    return At3Play(a, 0, b, c, d, 0, e, f, -1);
}

int At3PlayFile(int a, int b, int c, int d, int e, int f, int g, int h) {
    return At3Play(a, 1, b, c, d, e, f, g, h);
}

#define WW ((PspWorkS *)gWork_1207F0)
void *At3GetSlot(int id, const char *name)
{
    if (id >= 0 && id <= WW->num - 1) {
        char *p = WW->slots + id * 0x60B0;
        if (p != NULL && ((unsigned char *)p)[0x36] == 0) return p;
    }
    if (name != NULL && (gSgxDebugFlags & 1)) {
        sgxPrintfPref(gSgxPrefErr, &D_0010B074, 0x8E1, "AT3 : '%s' unknown ID (%d)\n", name, id);
        return NULL;
    }
    return NULL;
}
#undef WW

void At3Stop(int id) {
    char *p = At3GetSlot(id, "Stop");
    if (p != NULL) p[0x36] = 1;
}

void At3Stop(int);
void At3StopAll(void)
{
    int i;
    for (i = 0; i < gWork_1207F0[0x450 / 4]; i++) {
        char *p = At3GetSlot(i, 0);
        if (p) At3Stop(i);
    }
}

void At3SetVolume(int id, int l, int r) {
    char *p = At3GetSlot(id, "SetVolume");
    if (p != NULL) {
        l = (l < -0x1000) ? -0x1000 : (l < 0x1000 ? l : 0x1000);
        r = (r < -0x1000) ? -0x1000 : (r < 0x1000 ? r : 0x1000);
        *(short *)(p + 0x3C) = l;
        *(short *)(p + 0x3E) = r;
    }
}

void At3SetPitch(int id, int v) {
    char *p = At3GetSlot(id, "SetPitch");
    if (p != NULL) *(short *)(p + 0x60A0) = (v <= 0) ? 1 : (v < 0x4000 ? v : 0x4000);
}

void At3Pause(int id, int v) {
    char *p = At3GetSlot(id, "Pause");
    if (p != NULL) p[0x37] = v;
}

int At3GetStatus(int id)
{
    char *p = At3GetSlot(id, 0);
    int st;
    if (p == NULL) return 0;
    st = 0;
    if (((unsigned char *)p)[0x34] && !((unsigned char *)p)[0x36]) {
        st = 1; if (p[0x35]) st = 3;
        if (p[0x37]) st |= 4;
        if (p[0x38] && !p[0x35]) st |= 0x10;
        if (p[0x39]) st |= 0x20;
    }
    return st;
}

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

void FreqTerm(void) {
    int *w = gWork_1207F0;
    if (w[0x4A4 / 4] == 0) return;
    if (w[0x4B4 / 4] >= 0) {
        w[0x4B0 / 4] = 0;
        sceKernelSignalSema(w[0x4B8 / 4], 1);
        sceKernelWaitThreadEnd(w[0x4B4 / 4], NULL);
        sceKernelDeleteThread(w[0x4B4 / 4]);
        w[0x4B4 / 4] = -1;
    }
    if (w[0x4C4 / 4] >= 0) {
        sceKernelDeleteEventFlag(w[0x4C4 / 4]);
        w[0x4C4 / 4] = -1;
    }
    if (w[0x4C0 / 4] >= 0) {
        sceKernelDeleteSema(w[0x4C0 / 4]);
        w[0x4C0 / 4] = -1;
    }
    if (w[0x4BC / 4] >= 0) {
        sceKernelDeleteSema(w[0x4BC / 4]);
        w[0x4BC / 4] = -1;
    }
    if (w[0x4B8 / 4] >= 0) {
        sceKernelDeleteSema(w[0x4B8 / 4]);
        w[0x4B8 / 4] = -1;
    }
    if (w[0x4C8 / 4] != 0) {
        sgxFree((int *)w[0x4C8 / 4]);
        w[0x4C8 / 4] = 0;
    }
    { int *s = &w[0x4DC / 4]; __builtin_memset(s, 0, 32); }
}

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

void WaitOneSec(volatile int *flag) {
    int wait = 100000;
    int n = 1000000 / wait;
    int i;
    for (i = 0; i < n; i++) {
        if (*flag) break;
        sceKernelDelayThread(wait);
    }
}

int sceIoOpen(const char *file, int flags, int mode);
long long sceIoLseek(int fd, long long offset, int whence);
static inline int FileOpenSize_(void *path, int *psize) {
    int fd = sceIoOpen(path, 1, 0);
    int r;
    if (fd < 0) return fd;
    *psize = sceIoLseek(fd, 0, 2);
    if (*psize < 0) {
        sceIoClose(fd);
        return *psize;
    }
    r = sceIoLseek(fd, 0, 0);
    if (r < 0) {
        sceIoClose(fd);
        return r;
    }
    return fd;
}
void FileCmdRopen(void *path, int *pfd, int *psize, volatile int *abort) {
    *pfd = -1;
    *psize = 0;
    while (*abort == 0) {
        int fd;
        if (IsPathUmd(path)) UmdWaitReadable();
        fd = FileOpenSize_(path, psize);
        *pfd = fd;
        if (fd >= 0) return;
        if (!IsPathUmd(path)) return;
        SGX_ERR(0xAE1, "open error (%s,%X)\n", path, *pfd);
        WaitOneSec(abort);
    }
}

void FileCmdClose(void *f, int fd, volatile int *abort) {
    int r;
    if (fd < 0) return;
    r = sceIoClose(fd);
    if (r < 0) SGX_ERR(0xAED, "close error (%d, %X)\n", fd, r);
}

long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, int size);
void FileCmdRead(void *path, int fd, int pos, void *buf, int size, volatile int *abort) {
    while (*abort == 0) {
        long long o;
        int r;
        if (IsPathUmd(path)) UmdWaitReadable();
        o = sceIoLseek(fd, pos, 0);
        r = o;
        if (o >= 0) r = sceIoRead(fd, buf, size);
        if (r == size) return;
        if (!IsPathUmd(path)) return;
        SGX_ERR(0xB03, "read error (%s,%X)\n", path, r);
        WaitOneSec(abort);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqMain);

int FreqAdd(int a0, int a1, int a2, int a3, int a4, int a5, int a6) {
    int *w = gWork_1207F0;
    int *e;
    sceKernelWaitSema(w[0x4BC / 4], 1, NULL);
    sceKernelWaitSema(w[0x4C0 / 4], 1, NULL);
    e = (int *)(w[0x4C8 / 4] + w[0x4D0 / 4] * 32);
    e[0] = a0;
    e[1] = a1;
    e[2] = a2;
    e[3] = a3;
    e[4] = a4;
    e[5] = a5;
    e[6] = a6;
    e[7] = 0;
    w[0x4D0 / 4] = (w[0x4D0 / 4] + 1) % w[0x4CC / 4];
    w[0x4D8 / 4]++;
    sceKernelSignalSema(w[0x4C0 / 4], 1);
    return sceKernelSignalSema(w[0x4B8 / 4], 1);
}

int FreqRopen(int a, int b, int c, int d) {
    return FreqAdd(a, 0, b, c, d, 0, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void FreqClose(int arg0, int arg1, int arg2) {
    FreqRemove(arg0);
    FreqAdd(arg0, 1, arg1, arg2, 0, 0, 0);
    FreqSync(arg0, 1);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqRead);

void FreqRemove(int id) {
    int i;
    sceKernelWaitSema(gWork_1207F0[0x4C0 / 4], 1, NULL);
    for (i = 0; i < gWork_1207F0[0x4D8 / 4]; i++) {
        int *e = (int *)(gWork_1207F0[0x4C8 / 4] + ((gWork_1207F0[0x4D4 / 4] + i) % gWork_1207F0[0x4CC / 4]) * 32);
        if (e[0] == id) {
            e[0] = -1;
            e[1] = -1;
        }
    }
    if (gWork_1207F0[0x4DC / 4] == id) ((volatile int *)gWork_1207F0)[0x4F8 / 4] = 1;
    sceKernelSignalSema(gWork_1207F0[0x4C0 / 4], 1);
    FreqSync(id, 1);
}

int FreqSync(int id, int wait) {
    int found;
    for (;;) {
        int i;
        sceKernelWaitSema(gWork_1207F0[0x4C0 / 4], 1, NULL);
        found = 0;
        for (i = 0; i < gWork_1207F0[0x4D8 / 4]; i++) {
            int *e = (int *)(gWork_1207F0[0x4C8 / 4] + ((gWork_1207F0[0x4D4 / 4] + i) % gWork_1207F0[0x4CC / 4]) * 32);
            if (e[0] == id) {
                found = 1;
                break;
            }
        }
        if (gWork_1207F0[0x4DC / 4] == id) found = 1;
        sceKernelSignalSema(gWork_1207F0[0x4C0 / 4], 1);
        if (found && wait) sceKernelWaitEventFlag(gWork_1207F0[0x4C4 / 4], 1 << id, 0x20, NULL, NULL);
        else break;
    }
    return found;
}

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

void sgxVoCtrl(int v, int a, int b, int c) {
    char *e = (char *)gWork_1207F0[0x70 / 4] + v * 48;
    switch (*(int *)(e + 0x18)) {
    case 0:
        break;
    case 1:
        VoCtrlSas(e, a, b, c);
        break;
    case 2:
        VoCtrlAt3(e, a, b, c);
        break;
    }
}

int VoiceToDeviceIndex(int v, int *dev, int *idx) {
    int *w = gWork_1207F0;
    int r = 0;
    if (v >= 0 && v <= w[0x74 / 4] - 1) {
        r = 1;
        *dev = *(int *)(w[0x70 / 4] + v * 48 + 0x18);
        *idx = *(int *)(w[0x70 / 4] + v * 48 + 0x1C);
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void sgxPspGetVoiceCount(void) {
    sgxVoGetSlotNum();
}


int sceSasGetEnvelope(int);
extern const float D_0010B604;
float sgxPspVoGetEnvelope(int v)
{
    int dev, idx;
    if (!VoiceToDeviceIndex(v, &dev, &idx)) return 0.0f;
    if (dev != 1) return 0.0f;
    return (float)(sceSasGetEnvelope(idx) >> 16) * D_0010B604;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

float sgxPspGetVoiceEnvelope(int v) {
    return sgxPspVoGetEnvelope(v);
}

typedef struct { char pad[0x78]; short vol[96][4]; short pitch[96]; } SgxPspVoTab;
extern const float D_0010B608;
float sgxPspVoGetVolume(int v, int ch)
{
    int dev, idx;
    if (!VoiceToDeviceIndex(v, &dev, &idx)) return 0.0f;
    return (float)((SgxPspVoTab *)gWork_1207F0)->vol[dev * 32 + idx][ch] * D_0010B608;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

float sgxPspGetVoiceVolume(int v, int ch) {
    return sgxPspVoGetVolume(v, ch);
}

extern const float D_0010B60C;
float sgxPspVoGetPitch(int v)
{
    int dev, idx;
    if (!VoiceToDeviceIndex(v, &dev, &idx)) return 0.0f;
    return (float)((SgxPspVoTab *)gWork_1207F0)->pitch[dev * 32 + idx] * D_0010B60C;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

float sgxPspGetVoicePitch(int v) {
    return sgxPspVoGetPitch(v);
}

int sgxPspAt3GetLocalID(int id) {
    int i;
    for (i = 0; i < gWork_1207F0[0x450 / 4]; i++) {
        unsigned char *e = (unsigned char *)(i * 0x60B0 + gWork_1207F0[0x44C / 4]);
        if (e[0x34] && *(int *)(e + 8) == id) return i;
    }
    return -1;
}

int sceSasSetEffect(int, int);
int sceSasSetEffectType(int);
void sgxEffSetType(int ch, unsigned int type)
{
	int t;
	switch (type) {
	case 0:
		sceSasSetEffect(1, 0);
		sceSasSetEffectVolume(0, 0);
		return;
	case 1: t = 0; break;
	case 2: t = 1; break;
	case 3: t = 2; break;
	case 4: t = 3; break;
	case 5: t = 4; break;
	case 6: t = 5; break;
	case 7: t = 6; break;
	case 8: t = 7; break;
	case 9: t = 8; break;
	default: return;
	}
	sceSasSetEffectType(t);
	sceSasSetEffect(1, 1);
	sceSasSetEffectVolume(gWork_1207F0[0x46C / 4], gWork_1207F0[0x470 / 4]);
	sceSasSetEffectParam(gWork_1207F0[0x474 / 4], gWork_1207F0[0x478 / 4]);
}
const float D_0010B604 = 1.0f / 16384.0f;
const float D_0010B608 = 1.0f / 4096.0f;
const float D_0010B60C = 1.0f / 4096.0f;

void sgxEffSetDepth(int ch, int l, int r)
{
    int a = CLAMP(l, 0, 128);
    int b = CLAMP(r, 0, 128);
    gWork_1207F0[0x46C / 4] = a << 5;
    gWork_1207F0[0x470 / 4] = b << 5;
    sceSasSetEffectVolume(a << 5, b << 5);
}

void sgxEffSetParam(int ch, int which, int v)
{
    int a;
    switch (which) {
    case 0: a = CLAMP(v, 0, 127); gWork_1207F0[0x474 / 4] = a; break;
    case 1: a = CLAMP(v, 0, 127); gWork_1207F0[0x478 / 4] = a; break;
    default: return;
    }
    sceSasSetEffectParam(gWork_1207F0[0x474 / 4], gWork_1207F0[0x478 / 4]);
}

extern short gaSgxSin90Tbl[];
int sgxSin12(int a)
{
    int i, f, y0, y1;
    a &= 0xFFF;
    i = a >> 3;
    f = a & 7;
    if (a < 0x400) {
        y0 = gaSgxSin90Tbl[i];
        y1 = gaSgxSin90Tbl[i + 1];
    } else if (a < 0x800) {
        y0 = gaSgxSin90Tbl[0x100 - i];
        y1 = gaSgxSin90Tbl[0xFF - i];
    } else if (a < 0xC00) {
        y0 = -gaSgxSin90Tbl[i - 0x100];
        y1 = -gaSgxSin90Tbl[i - 0xFF];
    } else {
        y0 = -gaSgxSin90Tbl[0x200 - i];
        y1 = -gaSgxSin90Tbl[0x1FF - i];
    }
    return y0 + (((y1 - y0) * f) >> 3);
}
