#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetAddToDataStream(int, int, int);
int NetAssignLocalServer(int, int);
int NetConnect(char *, int);
int NetDataStreamBytesFree(int, int);
int NetDisconnect(int);
int NetEndDataStream(int);
int NetGetAverageDelayToClient(int, int);
int NetGetBandwidthInfo(void *);
int NetGetBufferStatus(int, int, int, int, int);
int NetGetBuildTimeStamp(signed char *);
int NetGetClient(int *, int, int);
int NetGetClientBufferStatus(int, int, int, int, int, int);
int NetGetClientIpAddress(int, int, int);
int NetGetClientStatus(int, int, int);
int NetGetClientVersion(signed char *);
int NetGetConnectStatus(int, int);
int NetGetConnectionStatus(int, int);
int NetGetDataStream(int *, int);
int NetGetHostByName(int);
int NetGetLANBroadcastCommSetting(int *);
int NetGetLocalTime(int *);
int NetGetLocalizationSettings(int *);
int NetGetMyClientIndex(int, int);
int NetGetMyIpAddress(int);
int NetGetMyNetAddress(int, int);
int NetGetNetUpdateErrors(int);
int NetGetPeerToPeerHostClientIndex(int, int);
int NetGetServerVersion(int, int);
int NetGetTime(void *, int *);
int NetGetUPnPMemoryCeiling(int *);
int NetGetUdpBindPort(int *);
int NetGetValidClientCount(int, int);
int NetHostPeerToPeer(char *, int);
int NetIAssignLocalServer(int, int);
int NetIConnect(int *, int *);
int NetIGetAverageDelayToClient(int *, unsigned int);
int NetIGetBandwidthInfo(float *);
int NetIGetClientBufferStatus(char *, int, int *, int *, int *, int *);
int NetIGetClientIpAddress(void *, int, int);
int NetIGetConnectStatus(int *, char *);
int NetIGetConnectionStatus(int *, char *);
int NetIGetHostByName(char *);
int NetIGetLocalTime(void);
int NetIGetMyClientIndex(int *, void *);
int NetIGetMyIpAddress(void *);
int NetIGetMyNetAddress(void *, char *);
int NetIGetNetUpdateErrors(void *);
int NetIGetServerVersion(char *, char *);
int NetIGetTime(void *);
int NetIGetValidClientCount(int *, char **);
int NetIRegisterApplicationMessage(int, int);
int NetIRegisterMemoryCallbacks();
int NetIRegisterMessage();
int NetISetDefaultResolveAddrParams(void *);
int NetISetMyClientReceiveBroadcast(char *, int);
int NetISetNATServiceAddr(void *);
int NetITick(void);
int NetIUpdate(void);
int NetIncomingClient(int, int);
int NetJoin(int, int);
int NetLANSetUserName(const char *, int);
int NetLeave(int);
int NetMutexLock(void);
int NetOpenDataStream();
int NetPing(int, int, int);
int NetPingIP(void *, int);
int NetRegisterApplicationMessage(int, int);
int NetRegisterDataStream(int, int, int, int);
void NetRegisterMemoryCallbacks(void);
int NetRegisterMessage(int, int, int);
int NetResolveAddr(int, int);
int NetSendAppMessage(int, int);
int NetSendApplicationMessage(char, char *, int, int, int, void *);
int NetSendFieldUpdates(int);
int NetSendMessage(char, char *, int, int, int, int, void *);
int NetSendMyClientUpdate(int, int);
int NetSetDefaultAppMessageParams(int *);
int NetSetDefaultDisconnectParams(int *);
int NetSetDefaultInitializeParams(int *);
int NetSetDefaultJoinParams(void *);
int NetSetDefaultLookupParams(void *);
int NetSetDefaultMemoryCallbackParams(int *);
int NetSetDefaultNetUsePeerToPeerInParams(void *);
int NetSetDefaultResolveAddrParams(int);
int NetSetFieldChanged(int, int);
int NetSetMyClientReceiveBroadcast(int, int);
int NetSetNATServiceAddr(int);
int NetSetSendAggregationInterval(int, int, int);
int NetStreamMediaEndRecording(int, int);
int NetStreamMediaGetChannelInfo(int, int, int);
int NetStreamMediaGetClientInfo(int, int, int);
int NetStreamMediaGetCurrentChannelState(int, int);
int NetStreamMediaJoinChannel(int, int);
int NetStreamMediaQuitChannel(int, int);
int NetStreamMediaSetDefaultIgnoreParams(int *);
int NetStreamMediaSetIgnoreState(int);
int NetTick(void);
int NetUpdate(void);
void rt_comm_linkaddress_toint();
int rt_mutex_lock(void *, int *);
int rt_mutex_unlock(void *, int *);
void rt_time_get_gmtime();
void seedMT();

extern signed char gBuildTimeStamp_10DEB4;
extern void *gUDPInterfacePtr;

typedef int (*NetIfFn)();
typedef struct { void *dest; unsigned char type; char pad[3]; int a; int b; char pad2[0x34 - 0x10]; int c; int d; void *data; } DmeSendMsg;
int NetISendMessage();
void *memset(void *, int, unsigned int);
extern void *gObjectInterfacePtr;
extern void *gStreamMediaInterfacePtr;
int NetMapRtError();
extern int gbInitialized_132A84;
extern void *gDmeGlobals;

#define DME_LOCK(r) \
    if (gbInitialized_132A84 != 1) return 0x11; \
    if (*(int *)((char *)gDmeGlobals + 0x24) != gbInitialized_132A84) return 0x2B; \
    r = NetMapRtError(rt_mutex_lock((char *)gDmeGlobals + 0x28, 0)); \
    if (r != 0) return r
#define DME_UNLOCK(r) \
    r = NetMapRtError(rt_mutex_unlock((char *)gDmeGlobals + 0x28, 0)); \
    if (r != 0) return r

int NetMutexUnlock();
int NetMapRtError();

int NetIPingIP();

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", rcsid_10DE3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", gszDmeVersionString);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", gBuildTimeStamp_10DEB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", gszrtBaseVersionString);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sprintf(char *buf, const char *fmt, ...);
int NetGetClientVersion(signed char *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        sprintf(arg0, "%d.%02d.%04d", 2, 0xA, 0x68);
        var_v1 = 0;
    }
    return var_v1;
}

char *strcpy(char *d, const char *s);
int NetGetBuildTimeStamp(signed char *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        strcpy(arg0, &gBuildTimeStamp_10DEB4);
        var_v1 = 0;
    }
    return var_v1;
}

int NetSetDefaultInitializeParams(int *p)
{
    int tm[12];
    int ret = 0x17;
    if (p != NULL) {
        memset(p, 0, 0x6C);
        rt_time_get_gmtime(tm);
        seedMT(tm[8]);
        ret = 0;
        p[3] = -1;
        p[0] = 1;
        p[0x60 / 4] = 0;
        p[0x5C / 4] = 0;
        p[1] = 0;
        p[2] = 1;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetInitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetClose);

int NetMutexUnlock();
int NetMapRtError();

int NetGetAverageDelayToClient(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetAverageDelayToClient(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();
int NetIGetBufferStatus();
int NetGetBufferStatus(int a0, int a1, int a2, int a3, int a4)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetBufferStatus(a0, a1, a2, a3, a4);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();
int NetISetSendAggregationInterval();
int NetSetSendAggregationInterval(int a0, int a1, int a2)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetISetSendAggregationInterval(a0, a1, a2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetGetBandwidthInfo(void *a0)
{
    int r, e;
    if (a0 == NULL) return 0x17;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetBandwidthInfo(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetRegisterMessage(int a0, int a1, int a2)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIRegisterMessage(a0, a1, a2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetRegisterApplicationMessage(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIRegisterApplicationMessage(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetSendMessage(char type, char *o, int b, int x, int a, int d, void *data)
{
    int r, e;
    DmeSendMsg m;
    char buf[0x30];

    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    memset(&m, 0, sizeof(m));
    m.a = a;
    m.b = b;
    m.type = type;
    m.c = *(int *)(o + 0x460);
    m.d = d;
    m.data = data;
    m.dest = o;
    e = NetISendMessage(&m, buf, x);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetSendApplicationMessage(char type, char *o, int b, int a, int d, void *data)
{
    int r, e;
    DmeSendMsg m;
    char buf[0x30];

    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    memset(&m, 0, sizeof(m));
    m.a = a;
    m.b = b;
    m.type = type;
    m.c = *(int *)(o + 0x460);
    m.d = d;
    m.data = data;
    m.dest = o;
    e = NetISendMessage(&m, buf, 2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetRegisterDataStream(int a0, int a1, int a2, int a3)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0x20))(a0, a1, a2, a3);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetSetDefaultMemoryCallbackParams(int *p)
{
    int ret = 0x17;

    if (p != NULL) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        ret = 0;
    }
    return ret;
}

void NetRegisterMemoryCallbacks(void) {
    NetIRegisterMemoryCallbacks();
}

int NetMutexUnlock();
int NetMapRtError();

int NetAssignLocalServer(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIAssignLocalServer(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

extern int gbTimebaseEnabled;
int NetConnect(char *a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIConnect(a0, a1);
    if (*(int *)(a0 + 0x158) != 0 && e != 0) gbTimebaseEnabled = 0;
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

void *memset(void *s, int c, unsigned int n);
int NetSetDefaultJoinParams(void *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        memset(arg0, 0, 0x48U);
        M2C_FIELD(arg0, int *, 0x1C) = 2;
        M2C_FIELD(arg0, int *, 0) = 1;
        var_v1 = 0;
    }
    return var_v1;
}

int NetIHostPeerToPeer();
int NetHostPeerToPeer(char *a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIHostPeerToPeer(a0, a1);
    if (*(int *)(a0 + 0xB4) != 0 && e != 0) gbTimebaseEnabled = 0;
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetSetNATServiceAddr(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetISetNATServiceAddr(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetSetDefaultResolveAddrParams(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetISetDefaultResolveAddrParams(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();
int NetIResolveAddr();
int NetResolveAddr(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIResolveAddr(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();
int NetIIncomingClient();
int NetIncomingClient(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIIncomingClient(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetSetMyClientReceiveBroadcast(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetISetMyClientReceiveBroadcast(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();
int NetIPing();
int NetPing(int a0, int a1, int a2)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIPing(a0, a1, a2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetPingIP(void *addr, int cb)
{
    int buf[4];
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    rt_comm_linkaddress_toint(buf, addr);
    e = NetIPingIP(buf, cb);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetPingNetAddress);

int NetOpenDataStream(a, b, c, d, e, f, g, h, i)
{
    int r, v;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    v = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0x14))(a, b, c, d, e, f, g, h, i);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return v;
}

int NetAddToDataStream(int a0, int a1, int a2)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0x4))(a0, a1, a2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetEndDataStream(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0x10))(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetSendMyClientUpdate(int a0, int a1)
{
    int r, e = 0x10;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    if (gObjectInterfacePtr != NULL)
        e = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0xE0))(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetGetDataStream(int *out, int a1)
{
    int r;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    if (out == NULL) return 0x17;
    *out = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0x34))(a1);
    return NetMapRtError(NetMutexUnlock());
}

int NetGetClientStatus(int a0, int a1, int a2)
{
    int r, e = 0x10;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    if (gObjectInterfacePtr != NULL)
        e = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0xE4))(a0, a1, a2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetGetClient(int *out, int a1, int a2)
{
    int r;
    if (a1 == 0) return 0x17;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    if (out == NULL) return 0x17;
    if (gObjectInterfacePtr != NULL)
        *out = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0x48))(a1, a2);
    return NetMapRtError(NetMutexUnlock());
}

int NetMutexUnlock();
int NetMapRtError();

int NetGetMyIpAddress(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetMyIpAddress(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetGetMyNetAddress(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetMyNetAddress(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetGetClientIpAddress(int a0, int a1, int a2)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetClientIpAddress(a0, a1, a2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetGetMyClientIndex(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetMyClientIndex(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();
int NetIGetPeerToPeerHostClientIndex();
int NetGetPeerToPeerHostClientIndex(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetPeerToPeerHostClientIndex(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetGetLocalTime(int *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        *arg0 = NetIGetLocalTime();
        var_v0 = 0;
    }
    return var_v0;
}

int NetGetTime(void *arg0, int *arg1) {
    int var_v0;

    var_v0 = 0x17;
    if (arg1 != NULL) {
        if (arg0 != NULL) {
            *arg1 = NetIGetTime(arg0);
            var_v0 = 0;
        }
    }
    return var_v0;
}

int NetMutexUnlock();
int NetMapRtError();

int NetGetConnectStatus(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetConnectStatus(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetGetValidClientCount(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetValidClientCount(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetDefaultStreamMediaParams);

int NetMutexUnlock();
int NetMapRtError();

int NetGetConnectionStatus(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetConnectionStatus(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetDataStreamBytesFree(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0x0))(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetGetServerVersion(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetServerVersion(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetUpdate(void)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIUpdate();
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetGetNetUpdateErrors(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetNetUpdateErrors(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexUnlock();
int NetMapRtError();

int NetTick(void)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetITick();
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetLeave(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0x1C))(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetSetDefaultDisconnectParams(int *p)
{
    int ret = 0x17;

    if (p != NULL) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        ret = 0;
    }
    return ret;
}

int NetMutexUnlock();
int NetMapRtError();
int NetIDisconnect();
int NetDisconnect(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIDisconnect(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetStreamMediaJoinChannel(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gStreamMediaInterfacePtr + 0x2C))(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetStreamMediaQuitChannel(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gStreamMediaInterfacePtr + 0x30))(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetStreamMediaGetChannelInfo(int a0, int a1, int a2)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gStreamMediaInterfacePtr + 0x34))(a0, a1, a2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetStreamMediaGetClientInfo(int a0, int a1, int a2)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gStreamMediaInterfacePtr + 0x38))(a0, a1, a2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetStreamMediaEndRecording(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gStreamMediaInterfacePtr + 0x3C))(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetStreamMediaGetCurrentChannelState(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gStreamMediaInterfacePtr + 0x40))(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetStreamMediaSetDefaultIgnoreParams(int *p)
{
    int r;
    if (p == NULL) return 0x17;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    p[0] = 1;
    p[2] = 0;
    p[3] = 0;
    p[1] = 0;
    return NetMapRtError(NetMutexUnlock());
}

int NetStreamMediaSetIgnoreState(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gStreamMediaInterfacePtr + 0x44))(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetJoin(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0x2C))(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetISetFieldChanged();
int NetSetFieldChanged(int a0, int a1)
{
    int r, e;
    DME_LOCK(r);
    e = NetISetFieldChanged(a0, a1);
    DME_UNLOCK(r);
    return e;
}

int NetSendFieldUpdates(int a0)
{
    int r, e;
    if (gbInitialized_132A84 != 1) return 0x11;
    if (*(int *)((char *)gDmeGlobals + 0x24) != gbInitialized_132A84) return 0x2B;
    if (gObjectInterfacePtr == NULL) return 0x11;
    r = NetMapRtError(rt_mutex_lock((char *)gDmeGlobals + 0x28, 0));
    if (r != 0) return r;
    e = (*(NetIfFn *)((char *)gObjectInterfacePtr + 0xDC))(a0);
    DME_UNLOCK(r);
    return e;
}

void *memset(void *s, int c, unsigned int n);
int NetSetDefaultLookupParams(void *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        memset(arg0, 0, 0x114U);
        var_v1 = 0;
    }
    return var_v1;
}

int NetGetHostByName(int a0)
{
    int r, e;
    DME_LOCK(r);
    e = NetIGetHostByName(a0);
    DME_UNLOCK(r);
    return e;
}

int NetGetClientBufferStatus(int a0, int a1, int a2, int a3, int a4, int a5)
{
    int r, e;
    DME_LOCK(r);
    e = NetIGetClientBufferStatus(a0, a1, a2, a3, a4, a5);
    DME_UNLOCK(r);
    return e;
}

int NetSetDefaultAppMessageParams(int *p)
{
    if (p == NULL) return 0x17;
    memset(p, 0, 0x40);
    p[0xC / 4] = 0x100;
    p[0x34 / 4] = 0x100;
    return 0;
}

int NetISendMessage();
int NetSendAppMessage(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetISendMessage(a0, a1, 2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

extern void *gDmeGlobals;
void *memcpy(void *, const void *, unsigned long);
int NetMapRtError();
int NetLANSetUserName(const char *name, int len)
{
    int r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    if (len > 32) return 0x17;
    memcpy((char *)gDmeGlobals + 0x90, name, len);
    return NetMapRtError(NetMutexUnlock());
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetAddressToStringAddress);

int NetSetDefaultNetUsePeerToPeerInParams(void *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0) = 0;
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0x10000;
        var_v0 = 0;
    }
    return var_v0;
}

int NetGetUdpBindPort(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gUDPInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gUDPInterfacePtr, int *, 0x84);
        }
    }
    return var_v1;
}

int NetGetUPnPMemoryCeiling(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gUDPInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gUDPInterfacePtr, int *, 0x88);
        }
    }
    return var_v1;
}

int NetGetLANBroadcastCommSetting(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gUDPInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gUDPInterfacePtr, int *, 0x90);
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetGlobalBufferPoolStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetConnectivityType);

int NetGetLocalizationSettings(int *p)
{
    int ret = 0x17;
    if (p != NULL) {
        memset(p, 0, 8);
        ret = 0x11;
        if (*(int *)((char *)gDmeGlobals + 0x24) != 0) {
            ret = 0;
            p[0] = *(int *)((char *)gDmeGlobals + 0x40);
            p[1] = *(int *)((char *)gDmeGlobals + 0x44);
        }
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", BinaryAddressToNetAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", StringAddressToNetAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetAddressToBinaryAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetIAddressToStringAddress);
