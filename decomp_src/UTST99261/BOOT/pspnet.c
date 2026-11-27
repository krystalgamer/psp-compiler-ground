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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", CheckAccessPoint);

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
