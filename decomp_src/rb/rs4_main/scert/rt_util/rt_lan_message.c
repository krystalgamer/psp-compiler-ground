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

typedef struct { char d[0xA4]; int len; char *text; int user; } RtLanInfo;
typedef struct { void *buf; int len; } RtLanIov;
typedef struct { RtLanIov e[8]; int total; int n; } RtLanVec;
typedef struct { int ip, port; } RtLanAddr;
int LANFindGetMyPeerDesc(); int NetAddressToBinaryAddress(); int NetISendTo();
int NetLANSendTextMessage(char *p)
{
    RtLanAddr addr;
    unsigned short pa, pb;
    RtLanVec vec;
    RtLanInfo info;
    int type;
    int len;

    if (p == NULL) return 10;
    len = *(int *)(p + 0x18) + 0xB4;
    {
        int r = LANFindGetMyPeerDesc(&info, 0);
        if (r != 0) return r;
    }
    vec.e[1].len = 0xB0;
    vec.e[2].len = 4;
    vec.e[2].buf = &len;
    vec.e[0].buf = *(char **)(p + 0x1C);
    vec.total = *(int *)(p + 0x18) + 0xB4;
    vec.e[0].len = *(int *)(p + 0x18);
    info.len = *(int *)(p + 0x18);
    vec.e[1].buf = &info;
    vec.n = 3;
    info.text = NULL;
    info.user = 0;
    NetAddressToBinaryAddress(p, &type, &addr, &pa, &pb);
    return NetISendTo(addr, *(unsigned short *)(p + 0x14), 0, 0x21, &vec);
}

int NetLANSetDefaultSendRawMessageInParams(int *p) {
    if (p == NULL) return 10;
    memset(p, 0, 32);
    return 0;
}

int NetLANSendRawMessage(char *p)
{
    RtLanAddr addr;
    unsigned short pa, pb;
    RtLanVec vec;
    RtLanInfo info;
    int type;
    int len;

    if (p == NULL) return 10;
    len = *(int *)(p + 0x18) + 0xB4;
    {
        int r = LANFindGetMyPeerDesc(&info, 0);
        if (r != 0) return r;
    }
    vec.e[1].len = 0xB0;
    vec.e[2].len = 4;
    vec.e[2].buf = &len;
    vec.e[0].buf = *(char **)(p + 0x1C);
    vec.total = *(int *)(p + 0x18) + 0xB4;
    vec.e[0].len = *(int *)(p + 0x18);
    info.len = *(int *)(p + 0x18);
    vec.e[1].buf = &info;
    vec.n = 3;
    info.text = NULL;
    info.user = 0;
    NetAddressToBinaryAddress(p, &type, &addr, &pa, &pb);
    return NetISendTo(addr, *(unsigned short *)(p + 0x14), 0, 0x22, &vec);
}

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
