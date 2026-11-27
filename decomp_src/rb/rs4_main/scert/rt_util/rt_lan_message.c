#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetDisableLanMessaging(void);
int NetLANSetDefaultEnableMessagingInParams(void *arg0);
extern unsigned char gLANMessage;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_lan_message", NetLANSetDefaultSendTextMessageInParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_lan_message", NetLANSendTextMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_lan_message", NetLANSetDefaultSendRawMessageInParams);

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
