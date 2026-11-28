#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetDisableLanMessaging(void);
int NetLANSetDefaultEnableMessagingInParams(void *);
int NetLANSetDefaultSendRawMessageInParams(int *);
int NetLANSetDefaultSendTextMessageInParams(int *);

extern unsigned char gLANMessage;

int NetLANSetDefaultSendTextMessageInParams(int *p)
{
    if (p == NULL) return 10;
    memset(p, 0, 32);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_lan_message", NetLANSendTextMessage);

int NetLANSetDefaultSendRawMessageInParams(int *p) {
    if (p == NULL) return 10;
    memset(p, 0, 32);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_lan_message", NetLANSendRawMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_lan_message", NetEnableLANMessaging);

int NetDisableLanMessaging(void) {
    M2C_FIELD(&gLANMessage, int *, 0) = 0;
    M2C_FIELD(&gLANMessage, int *, 8) = 0;
    return 0;
}

void *memset(void *s, int c, unsigned int n);
int NetLANSetDefaultEnableMessagingInParams(void *arg0) {
    int var_v1;

    var_v1 = 0xA;
    if (arg0 != NULL) {
        memset(arg0, 1, 0x10U);
        var_v1 = 0;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_lan_message", LANTextMessageHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_lan_message", LANRawMessageHandler);
