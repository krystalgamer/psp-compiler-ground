/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int gConnectState;
extern int gScanEvent;
extern int gHandler_id;
int printf(const char *fmt, ...);
int sceNetInit(int a, int b, int c, int d, int e);
int sceNetInetInit(void);
int sceNetApctlInit(int a, int b);
int sceNetApctlAddHandler(void (*h)(int, int, int, int, void *), void *arg);
int sceNetApctlDelHandler(int id);
int sceNetApctlTerm(void);
int sceNetInetTerm(void);
int sceNetTerm(void);
M2C_UNK sceUtilityDeleteNetParam(M2C_UNK);          /* extern */
extern int bCreateNetParam;


typedef struct {
    char s[32];
} __attribute__((aligned(4))) APSSID; /* STAND-IN: aligned so the 32-byte copies are word moves; real type unknown */
typedef struct {
    unsigned int len;
    APSSID ssid;
    u8 unk24[4];
    u8 bssid[8];
    int unk30;
} APENTRY;
typedef struct {
    unsigned int n;
    APENTRY e[1];
} APLIST;
extern char gszStealth[];
int memcmp(const void *a, const void *b, unsigned int n);
unsigned int strlen(const char *s);
void *memset(void *p, int c, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
void apctl_handler_EB714(int old, int state, int event, int error, void *arg)
{
    if (old == 4 && state == 0 && event == 6)
        printf("Apctl error happened, error = 0x%x\n", error);
    gScanEvent = state;
    gConnectState = state;
}

int _InitNecApNetwork(void)
{
    int ret;

    gHandler_id = -1;
    ret = sceNetInit(0x20000, 0x20, 0x1000, 0x20, 0x1000);
    if (ret < 0) {
        printf("sceNetInit() failed. ret = 0x%x\n", ret);
        goto out;
    }
    ret = sceNetInetInit();
    if (ret < 0) {
        printf("sceNetInetInit() failed. ret = 0x%x\n", ret);
        goto out;
    }
    ret = sceNetApctlInit(0x8000, 0x21);
    if (ret < 0) {
        printf("sceNetApctlInit() failed. ret = 0x%x\n", ret);
        goto out;
    }
    ret = sceNetApctlAddHandler(apctl_handler_EB714, 0);
    if (ret < 0) {
        printf("sceNetApctlAddHandler() failed. ret = 0x%x\n", ret);
        goto out;
    }
    gHandler_id = ret;
    ret = 1;
out:
    return ret;
}

int _FreeNecApNetwork(void)
{
    int ret;

    if (gHandler_id >= 0) {
        ret = sceNetApctlDelHandler(gHandler_id);
        if (ret < 0) {
            printf("sceNetApctlDelHandler() failed. ret = 0x%x\n", ret);
            return ret;
        }
        gHandler_id = -1;
    }
    ret = sceNetApctlTerm();
    if (ret < 0) {
        printf("sceNetApctlTerm() failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceNetInetTerm();
    if (ret < 0) {
        printf("sceNetInetTerm() failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceNetTerm();
    if (ret < 0) {
        printf("sceNetTerm() failed. ret = 0x%x\n", ret);
        return ret;
    }
    return ret;
}

int CheckAccessPoint(APLIST *cur, APLIST *scan, int *idx)
{
    char buf[33];
    unsigned int i;
    unsigned int j;
    APENTRY *pc;
    APENTRY *ps;
    APENTRY *pc0;
    APENTRY *ps0;
    int curStealth;
    int scanStealth;
    int found;
    int ret;

    found = 0;
    i = 0;
    pc0 = pc = cur->e;
    ps0 = ps = scan->e;
    ret = 0;
    for (; i < cur->n; i++) {
        memset(buf, 0, sizeof(buf));
        j = 0;
        memcpy(buf, &pc->ssid, sizeof(APSSID));
        buf[pc->len] = 0;
        for (; j < scan->n; j++) {
            if (pc->len - 1 >= 32)
                break;
            if (memcmp(buf, ps->ssid.s, strlen(buf)) == 0 && memcmp(pc->bssid, ps->bssid, 4) == 0
                && pc->unk30 != ps->unk30 && pc->unk30 == 0) {
                found = 1;
                break;
            }
            ps++;
        }
        if (found)
            break;
        pc++;
        ps = ps0;
    }
    if (!found) {
        memset(buf, 0, sizeof(buf));
        pc = pc0;
        ps = ps0;
        curStealth = 0;
        scanStealth = 0;
        for (i = 0; i < scan->n; i++) {
            memcpy(buf, &ps->ssid, sizeof(APSSID));
            buf[ps->len] = 0;
            if (memcmp(buf, gszStealth, strlen(gszStealth)) == 0 && ps->unk30 == 0) {
                scanStealth = 1;
                break;
            }
            ps++;
        }
        for (i = 0; i < cur->n; i++) {
            memcpy(buf, &pc->ssid, sizeof(APSSID));
            buf[pc->len] = 0;
            if (strlen(buf) == strlen(gszStealth) && memcmp(buf, gszStealth, strlen(gszStealth)) == 0 && pc->unk30 == 0) {
                curStealth = 1;
                break;
            }
            pc++;
        }
        if (curStealth && !scanStealth)
            found = 1;
    }
    if (found) {
        *idx = i;
        ret = 1;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _NecApScanAP);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _NecApConnectAP);

#ifndef NULL
#define NULL ((void *)0)
#endif

void _NecApDisconnectAP(void) {
    if (bCreateNetParam != 0) {
        sceUtilityDeleteNetParam(0);
        bCreateNetParam = 0;
    }
}
