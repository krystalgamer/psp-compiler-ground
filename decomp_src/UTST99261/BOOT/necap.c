/* cflags: -O2 */
#include "common.h"
typedef struct NecApParam {
    int w[14];
} NecApParam;
extern NecApParam _gNecApConfigParam;
extern int _gNecApState;
extern int _gNecApTimeout;
extern int _gNecApResult;
extern int _bNecApCanceled;
extern int gNecApThreadId;
extern int bInitNecApNetwork;
extern unsigned long long D_002DD080;
int sceRtcGetCurrentTick(unsigned long long *t);
int _InitNecApNetwork(void);
int _FreeNecApNetwork(void);
int sceWlanGetSwitchState(void);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stack, int attr, void *opt);
int sceKernelStartThread(int id, int len, void *arg);
int sceKernelDeleteThread(int id);
int sceKernelDelayThread(int us);
int _AutoConfigThread();
int printf(const char *fmt, ...);
int puts(const char *s);

unsigned int _NecApGetTickCount(void)
{
    unsigned long long t;

    if (D_002DD080 == 0) {
        sceRtcGetCurrentTick(&t);
        D_002DD080 = t;
    }
    sceRtcGetCurrentTick(&t);
    return (t - D_002DD080) / 1000;
}

int necApConfigStart(int prio)
{
    int r;

    r = _InitNecApNetwork();
    if (r < 0)
        return -2;
    r = sceWlanGetSwitchState();
    if (r == 0) {
        puts("Wireless LAN switch has been turned off.");
        return -10;
    }
    bInitNecApNetwork = r;
    r = sceKernelCreateThread("nec_ap_set", _AutoConfigThread, prio, 0x1000, 0, NULL);
    if (r < 0) {
        printf("AUTOCFG:Error can not start thread %04X\n", r);
        return -1;
    }
    gNecApThreadId = r;
    _gNecApState = 1;
    _gNecApTimeout = _NecApGetTickCount() + 60000;
    _bNecApCanceled = 0;
    _gNecApConfigParam.w[0] = 0;
    _gNecApConfigParam.w[1] = 0;
    _gNecApConfigParam.w[2] = 0;
    _gNecApConfigParam.w[3] = 0;
    _gNecApConfigParam.w[4] = 0;
    _gNecApConfigParam.w[5] = 0;
    _gNecApConfigParam.w[6] = 0;
    _gNecApConfigParam.w[7] = 0;
    _gNecApConfigParam.w[8] = 0;
    _gNecApConfigParam.w[9] = 0;
    _gNecApConfigParam.w[10] = 0;
    _gNecApConfigParam.w[11] = 0;
    _gNecApConfigParam.w[12] = 0;
    _gNecApConfigParam.w[13] = 0;
    sceKernelStartThread(gNecApThreadId, 0, NULL);
    return 1;
}

int necApConfigEnd(void)
{
    int r = -5;

    if (gNecApThreadId >= 0) {
        _bNecApCanceled = 1;
        while ((unsigned int)(_gNecApState - 1) < 3)
            sceKernelDelayThread(100000);
        sceKernelDeleteThread(gNecApThreadId);
        gNecApThreadId = 0;
    }
    if (bInitNecApNetwork > 0) {
        r = _FreeNecApNetwork();
        bInitNecApNetwork = 0;
    }
    return r;
}

int necApConfigGetState(int *st)
{
    int t = _gNecApTimeout;

    st[0] = _gNecApState;
    if (t == -1)
        st[1] = t;
    else
        st[1] = _gNecApTimeout - _NecApGetTickCount();
    st[2] = _gNecApResult;
    return 1;
}

int necApConfigGetResult(NecApParam *p)
{
    *p = _gNecApConfigParam;
    return 1;
}

int necApConfigGetVersion(void)
{
    return 0x100;
}
