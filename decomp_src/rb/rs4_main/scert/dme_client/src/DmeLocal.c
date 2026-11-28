#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void * DMEmalloc(int);
void DmeFree(void **);
void EchoRequestCallback();
int FindFreePingSlot(void);
int GetSoftwareID(void);
void IncomingMessageFunc(char *, int, int, int);
void LANFindSetLocalServer(int, int);
int MapMsgClientFailureReason(int *, unsigned int);
void MsgClientDisconnectCallback(char *);
void MsgClientSystemMessageCallback(int, unsigned char, int, int, int, int, int);
int NetBitMaskToSendMask(unsigned char *, unsigned int *, unsigned int);
int NetCheckForPingTimeouts(void);
int NetCleanupClientPingInfoArray(void);
int NetClientIndexToClientIndexPacket(int);
int NetConvertTransportFlags(signed char, unsigned short *);
int NetCreateClientInfo(void **, unsigned int, void **);
void * NetCreateConnInfoBare(void);
void NetDestroyClientInfo(void **, int);
void NetDestroyConnInfo(char *);
void NetDestroyConnInfoBare(void *);
int NetDisablePingIPs(void);
int NetGetClientConnectStatus(void *, unsigned int, int *);
void * NetGetClientInfo();
void * NetGetClientPingInfo(unsigned int);
void * NetGetConnInfo(unsigned int);
int NetGetMsgClientIndex(void *);
void NetGetMyAddressInfoInternal(void *);
int NetGetMyWorldID(void);
int NetGetP2PHandle(void *);
int NetIAssignLocalServer(int, int);
int NetIConnect(int *, int *);
int NetIGetAverageDelayToClient(int *, unsigned int);
int NetIGetBandwidthInfo(float *);
int NetIGetClientBufferStatus(char *, int, int *, int *, int *, int *);
int NetIGetClientIpAddress(void *, int, int);
int NetIGetConnectStatus(int *, char *);
int NetIGetConnectionStatus(int *, char *);
int NetIGetCurrentUDPSourceBinaryIP(void *);
int NetIGetHostByName(char *);
int NetIGetLocalTime(void);
int NetIGetMyClientIndex(int *, void *);
int NetIGetMyIpAddress(void *);
int NetIGetNetUpdateErrors(void *);
int NetIGetServerVersion(char *, char *);
int NetIGetTime(void *);
int NetIGetValidClientCount(int *, char **);
int NetIRegisterMemoryCallbacks(void **);
int NetISetDefaultResolveAddrParams(void *);
int NetISetMyClientReceiveBroadcast(char *, int);
int NetISetNATServiceAddr(void *);
int NetITick(void);
int NetIUpdate(void);
int NetMutexLock(void);
void NetMutexUnlock(void);
void NetResetTime(int);
int NetSetConnInfo(int, int);
int NetSetDefaultConnectParams(int *);
int NetSetDefaultHostPeerToPeerParams(int *);
int NetSetDefaultIncomingClientParams(int *);
void NetSetHeartbeatInterval(int);
int NetSetPeerToPeerHostChangeCallback(int, int);
int NetSetServerIpAddress(char *, void *);
int NetUseDme(void);
void ParseMessageList(void *, char *, int, int, int);
void RemoteClientDisconnects(int);
int RtMsgToDmeConnectionIndex(unsigned int);
void SendMyClientStatus(char *, int);
void p2p_broadcast_update_cb(unsigned short, int, char *);
void p2p_host_change_cb(unsigned short, char *);
void p2p_system_change_cb(int, int, void *);
unsigned int randomMT(void);
int rt_comm_echo_shutdown(void);
void rt_comm_get_metrics(void *);
int rt_comm_linkaddress_isequal();
int rt_comm_linkaddress_isnull();
void rt_comm_linkaddress_setnull(void *);
int rt_comm_linkaddress_toext();
void rt_comm_linkaddress_toint();
int rt_memory_allocate_init_zero(void **, unsigned int);
int rt_memory_free(void **);
int rt_memory_register_another_callback(int);
int rt_memory_register_callbacks(int, int);
int rt_mutex_lock(void *, int *);
int rt_mutex_unlock(void *, int *);
int rt_time_elapsed(void *, unsigned int *);
int rt_timebase_get_globaltime(int *);
int rt_timebase_restart(void);
void udp_data_cb(void);
void udp_event_cb(int, int, int);

int rt_time_get_local();
char *strncpy(char *, const char *, unsigned int);

extern char gNetUpdateErrors[];
void *memcpy(void *, const void *, unsigned long);

int NetGetNatService(M2C_UNK **arg0);

typedef struct { int ip; int port; } DmeLinkAddr;

typedef struct { int set; DmeLinkAddr ext; int port; } DmeMyAddr;
extern void *gObjectInterfacePtr;
extern void *gDmeGlobals;
extern void *gUDPInterfacePtr;
extern unsigned char gppConnInfo;
extern unsigned char gMyAddressInfo;
extern unsigned char gNatService;
extern int gbTimebaseEnabled;
extern int HEARTBEAT_INTERVAL;
extern int gpHostChangeCallbackData;
extern int gpfHostChangeCallback;

void NetSetHeartbeatInterval(int arg0) {
    HEARTBEAT_INTERVAL = arg0;
}

void NetGetMyAddressInfoInternal(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0);
    M2C_FIELD(arg0, int *, 4) = (int) M2C_FIELD(&gMyAddressInfo, int *, 4);
    M2C_FIELD(arg0, int *, 8) = (int) M2C_FIELD(&gMyAddressInfo, int *, 8);
    M2C_FIELD(arg0, int *, 0xC) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0xC);
    M2C_FIELD(arg0, int *, 0x10) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0x10);
    M2C_FIELD(arg0, int *, 0x14) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0x14);
    M2C_FIELD(arg0, int *, 0x18) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0x18);
    M2C_FIELD(arg0, int *, 0x1C) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0x1C);
}

extern void *gP2PInterfacePtr;
extern void *gMsgClientInterfacePtr;
int NetMapRtError();
typedef int (*DmeIfFn2)(int, int);
typedef void (*DmeObjBcFn)(void *, int);

typedef int (*DmeP2pHostFn)(int, unsigned short *);
typedef struct { char *c; int a, b, cc, d; } DmeDiscMsg;
typedef void (*DmeDiscCb)(DmeDiscMsg *);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetGetMyAddressInfo);

int NetGetP2PHandle(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x474);
}

int NetUseDme(void) {
    return 0;
}

int GetSoftwareID(void) {
    return *(int *)gDmeGlobals;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetMyIntIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetMyExtIP);

int NetGetMsgClientIndex(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x470);
}

typedef struct { void *dest; unsigned char type; char pad[3]; int a; int b; char pad2[0x34 - 0x10]; int c; int d; void *data; } DmeMsgSend2;
typedef struct { unsigned char b0, b1, b2, b3; unsigned short h4; short pad; int w8; int wC; } DmeClientStatus;
int NetGenerateClientList(); int NetISendMessage();
void SendMyClientStatus(char *ctx, int dest)
{
    DmeClientStatus st;
    DmeMsgSend2 m;
    char buf[0x30];
    char *c;
    int r = 0;

    if (*(int *)(ctx + 0x404) == 0x100) return;
    c = *(char **)(ctx + 0x400);
    if (c == NULL) return;
    st.b1 = NetClientIndexToClientIndexPacket(*(int *)(ctx + 0x404));
    st.b0 = *(int *)(c + 0xC);
    st.b2 = *(int *)(c + 0x10);
    st.b3 = *(int *)(c + 0x14);
    st.w8 = *(int *)(c + 0x1C);
    st.wC = *(int *)(ctx + 0x464);
    if (gObjectInterfacePtr != NULL)
        r = (*(int (**)())((char *)gObjectInterfacePtr + 0x18))(&st.h4);
    else
        st.h4 = 0;
    if (r != 0) return;
    memset(&m, 0, sizeof(m));
    m.type = 0x50;
    m.c = *(int *)(ctx + 0x460);
    m.a = 0x16;
    m.d = 0x10;
    m.dest = ctx;
    m.b = dest;
    m.data = &st;
    if (dest == -1) NetGenerateClientList(ctx, &m.b);
    NetISendMessage(&m, buf, 0);
}

int RtMsgToDmeConnectionIndex(unsigned int arg0) {
    return arg0 + (arg0 < 5U);
}

int NetIGetAverageDelayToClient(int *out, unsigned int idx)
{
    unsigned int t[100];
    unsigned int *pi;
    int i, j;
    unsigned int a, b;

    if (out == NULL) return 0x17;
    pi = NetGetClientPingInfo(idx);
    if (pi == NULL) return 0x16;
    for (i = 0; i < 100; i++)
        t[i] = pi[i];
    for (i = 99; i > 0; i--) {
        for (j = 0; j < i; j++) {
            a = t[j];
            b = t[j + 1];
            if (b < a) {
                t[j] = b;
                t[j + 1] = a;
            }
        }
    }
    *out = t[50];
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetBufferStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetISetSendAggregationInterval);

typedef struct { float f[16]; } DmeMetrics;
int NetIGetBandwidthInfo(float *bw)
{
    DmeMetrics m;

    if (bw == NULL) return 0x17;
    rt_comm_get_metrics(&m);
    bw[2] = m.f[6];
    bw[3] = m.f[7];
    bw[0] = m.f[3];
    bw[1] = m.f[4];
    bw[6] = m.f[12];
    bw[7] = m.f[13];
    bw[4] = m.f[9];
    bw[5] = m.f[10];
    return 0;
}

int NetIGetMyClientIndex(int *arg0, void *arg1) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0x100;
        if (arg1 != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(arg1, int *, 0x404);
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetPeerToPeerHostClientIndex);

int NetSetPeerToPeerHostChangeCallback(int arg0, int arg1) {
    gpfHostChangeCallback = arg0;
    gpHostChangeCallbackData = arg1;
    return 0;
}

void NetResetTime(int arg0) {
    M2C_FIELD(gDmeGlobals, int *, 0x10) = arg0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", rcsid_10E1A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", headerfile_rcsid_10E208);

int puts(const char *);
void *DMEmalloc(int size)
{
    void *p = NULL;
    if (rt_memory_allocate_init_zero(&p, size) != 0) puts("rt_memory_allocate failed ");
    return p;
}

void DmeFree(void **p)
{
    if (*p != NULL)
        rt_memory_free(p);
}

int NetIRegisterMemoryCallbacks(void **cb)
{
    int ret = 0x17;

    if (cb != NULL) {
        if (rt_memory_register_callbacks(cb[0], cb[2]) != 0)
            ret = 0x16;
        else if (rt_memory_register_another_callback(cb[1]) != 0)
            ret = 0x16;
        else
            ret = 0;
    }
    return ret;
}

int NetIGetMyIpAddress(void *out)
{
    char tmp[16];
    if (out == NULL) return 0x17;
    NetIGetMyExtIP(tmp);
    rt_comm_linkaddress_toext(out, tmp);
    return 0;
}

typedef struct { int type; DmeLinkAddr addr; int pad[2]; unsigned int port; } DmeNetAddr;
int NetIGetMyNetAddress(DmeNetAddr *out, char *ctx)
{
    unsigned short p;
    int r;

    NetIGetMyExtIP(&out->addr);
    out->type = 4;
    out->port = 0;
    if (gP2PInterfacePtr != NULL)
        out->port = *(unsigned short *)((char *)gUDPInterfacePtr + 0x84);
    if (ctx != NULL) {
        if (*(int *)(ctx + 0x468) == 2) {
            p = 0;
            r = (*(int (**)())((char *)gP2PInterfacePtr + 0x1C))(*(int *)(ctx + 0x474), &p);
            if (r != 0) return r;
            out->type = 6;
            out->port |= p << 16;
        } else
            out->port = 0;
    }
    return 0;
}

void *memset(void *s, int c, unsigned int n);
int NetIGetClientIpAddress(void *arg0, int arg1, int arg2) {
    int var_v1;
    void *temp_v0;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        memset(arg0, 0, 0x10U);
        temp_v0 = NetGetClientInfo(arg1, arg2);
        var_v1 = 8;
        if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, int *, 0x20) != 0)) {
            rt_comm_linkaddress_toext(arg0, temp_v0);
            var_v1 = 0;
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", RemoteClientConnects);

void RemoteClientDisconnects(int a)
{
    int *c = NetGetClientInfo(a);
    if (c != NULL) memset(c, 0, 0x2C);
}

int NetIGetCurrentUDPSourceBinaryIP(void *arg0) {
    int var_a2;

    var_a2 = 0x17;
    if (arg0 != NULL) {
        var_a2 = 0;
        M2C_FIELD(arg0, int *, 0) = (int) M2C_FIELD(gDmeGlobals, int *, 0x18);
        M2C_FIELD(arg0, int *, 4) = (int) M2C_FIELD(gDmeGlobals, int *, 0x1C);
    }
    return var_a2;
}

int NetIGetLocalTime(void)
{
    int t;

    rt_time_get_local(&t);
    return t;
}

int NetIGetTime(void *arg0) {
    int var_v1;

    var_v1 = 0x2F;
    if (M2C_FIELD(arg0, int *, 0x4A4) != 0) {
        if (gbTimebaseEnabled == 0) {

        } else {
            rt_timebase_get_globaltime(gDmeGlobals + 0x10);
        }
        var_v1 = M2C_FIELD(gDmeGlobals, int *, 0x10);
    }
    return var_v1;
}

int NetIGetConnectStatus(int *st, char *conn)
{
    unsigned int i;
    if (st == NULL) return 0x17;
    if (conn != NULL) {
        for (i = 0; i < 4; i++) {
            if (conn == ((char **)&gppConnInfo)[i]) {
                *st = *(int *)(conn + 0x454);
                return 0;
            }
        }
    }
    *st = 0;
    return 0x17;
}

int NetIGetValidClientCount(int *count, char **clients)
{
    unsigned int i = 0;

    if (count == NULL) return 0x17;
    *count = 0;
    if (clients == NULL) return 0x17;
    for (; i < 256; i++, clients++) {
        if (*clients == NULL) continue;
        if (*(int *)(*clients + 0x20) == 0) continue;
        (*count)++;
    }
    return 0;
}

int NetIGetConnectionStatus(int *st, char *c)
{
    int r;
    if (st == NULL) return 0x17;
    st[0] = 0;
    st[1] = 0;
    st[2] = 0;
    if (c == NULL) return 0x17;
    r = NetIGetConnectStatus(st, c);
    if (r != 0) return r;
    r = NetIGetValidClientCount(st + 1, c);
    if (r != 0) return r;
    st[2] = st[1] + *(int *)(c + 0x45C);
    return 0;
}

int NetIGetServerVersion(char *out, char *dme)
{
    int ret = 0x17;

    if (dme != NULL) {
        if (out != NULL) {
            strncpy(out, dme + 0x418, 16);
            ret = 0;
        }
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetISendTo);

int NetBitMaskToSendMask(unsigned char *out, unsigned int *in, unsigned int nbits)
{
    unsigned int i = 0, b;

    for (b = 0; b < nbits; b += 32, i++) {
        out[i * 4 + 0] = in[i] & 0xFF;
        out[i * 4 + 1] = (in[i] & 0xFF00) >> 8;
        out[i * 4 + 2] = (in[i] & 0xFF0000) >> 16;
        out[i * 4 + 3] = (in[i] & 0xFF000000) >> 24;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetSendMessageByUDP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetSendMessageByTCP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetFragSendCB);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetISendMessage);

int rt_parse_execute();
extern int gaParseErrors[];
void ParseMessageList(void *list, char *ctx, int a, int b, int c)
{
    int r = rt_parse_execute(ctx, list, a, b, c, 0);
    if (ctx != NULL) gaParseErrors[*(int *)(ctx + 0x46C)] = r;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", RemoteClientDisconnectEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", RemoteClientEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIInitialize);

int NetIAssignLocalServer(int a, int b)
{
    if (a == 0) return 0x17;
    LANFindSetLocalServer(a, b);
    *(int *)((char *)gDmeGlobals + 0xC) = b;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIEnableUDP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetCreateP2PInfo);

void IncomingMessageFunc(char *a, int b, int c, int d)
{
    if (d == 0) return;
    rt_comm_linkaddress_setnull((char *)gDmeGlobals + 0x18);
    *(int *)((char *)gDmeGlobals + 0x20) = 0;
    ParseMessageList((void *)NetGetMyWorldID(), a, b, c, d);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int MapMsgClientFailureReason(int *arg0, unsigned int arg1) {
    int var_v0;
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        switch (arg1) {
        case 0:
            *arg0 = 0;
block_4:
            var_v1 = 0;
            break;
        case 1:
            var_v0 = 1;
block_7:
            *arg0 = var_v0;
            goto block_4;
        case 2:
            var_v0 = 2;
            goto block_7;
        case 3:
            var_v0 = 3;
            goto block_7;
        case 4:
            var_v0 = 4;
            goto block_7;
        case 5:
            var_v0 = 5;
            goto block_7;
        case 6:
            var_v0 = 6;
            goto block_7;
        case 7:
            var_v0 = 7;
            goto block_7;
        case 8:
            var_v0 = 8;
            goto block_7;
        case 9:
            var_v0 = 9;
            goto block_7;
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", MyClientConnectsPeerToPeer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", MsgClientConnectCallback);

typedef struct { char *c; int a, b, cc, d; } DmeDiscMsg2;
void MsgClientDisconnectCallback(char *c)
{
    DmeDiscMsg2 m;

    if (*(DmeDiscCb *)(c + 0x430) == NULL) return;
    *(int *)(c + 0x454) = 4;
    m.c = c;
    m.a = 4;
    m.b = 1;
    m.cc = 0;
    m.d = *(int *)(c + 0x434);
    (*(DmeDiscCb *)(c + 0x430))((DmeDiscMsg *)&m);
}

int NetSetDefaultConnectParams(int *p)
{
    if (p == NULL) return 0x17;
    memset(p, 0, 0x164);
    p[1] = 0x100;
    p[2] = 0;
    if (gUDPInterfacePtr != NULL)
        p[0x148 / 4] = *(int *)((char *)gUDPInterfacePtr + 0x84) + 1;
    else
        p[0x148 / 4] = randomMT() % 1000 + 6000;
    p[0xA4 / 4] = 0;
    p[0xAC / 4] = 0;
    p[0xB4 / 4] = 0;
    p[0xBC / 4] = 0;
    p[0xC4 / 4] = 0;
    p[0xC8 / 4] = 0;
    p[0x14C / 4] = 0;
    p[0x150 / 4] = 0;
    p[0x158 / 4] = 1;
    p[0x154 / 4] = 0;
    p[0x15C / 4] = 0x2000;
    p[0x160 / 4] = 0x2000;
    NetSetDefaultStreamMediaParams(p + 0xD4 / 4);
    p[0] = 1;
    return 0;
}

int NetConnect_ClientServerTCP(); int NetConnect_PeerToPeerUDP();
int NetIConnect(int *ctx, int *out)
{
    int type;
    int *tp;

    if (out == NULL) return 0x17;
    if (ctx[0xA4 / 4] == 0) {
        out[1] = 0x17;
        return 0x17;
    }
    out[1] = 3;
    out[0] = 1;
    if (ctx == NULL) {
        out[1] = 0x17;
        return 0x17;
    }
    if (ctx[0] == 0) {
        out[1] = 0x26;
        return 0x26;
    }
    if (ctx[0x158 / 4] != 0) {
        if (gbTimebaseEnabled) {
            out[1] = 0x2F;
            return 0x2F;
        }
        rt_timebase_restart();
        gbTimebaseEnabled = 1;
    }
    tp = &ctx[2];
    type = *tp;
    if (type == 1 || type == 3 || type == 4)
        out[1] = NetConnect_ClientServerTCP(ctx, tp, out);
    else if (type == 2)
        out[1] = NetConnect_PeerToPeerUDP(ctx, tp, out);
    else
        out[1] = 0x17;
    return out[1];
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetConnect_ClientServerTCP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetConnect_PeerToPeerUDP);

int NetSetDefaultStreamMediaParams();
int NetSetDefaultHostPeerToPeerParams(int *p)
{
    int ret = 0x17;
    if (p != NULL) {
        memset(p, 0, 0xC0);
        p[11] = 8;
        p[42] = 0;
        p[43] = 0;
        p[45] = 1;
        p[44] = 0;
        p[46] = 0x2000;
        p[47] = 0x2000;
        NetSetDefaultStreamMediaParams(p + 12);
        p[0] = 1;
        ret = 0;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIHostPeerToPeer);

int NetISetNATServiceAddr(void *a)
{
    if (a == NULL) return 0x17;
    memcpy(&gNatService, a, 0x18);
    return 0;
}

int NetISetDefaultResolveAddrParams(void *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        M2C_FIELD(arg0, int *, 0x14) = 0;
        M2C_FIELD(arg0, int *, 0x18) = 0;
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        M2C_FIELD(arg0, int *, 0) = 1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIResolveAddr);

void *memset(void *s, int c, unsigned int n);
int NetSetDefaultIncomingClientParams(int *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        memset(arg0, 0, 0x74U);
        *arg0 = 1;
        var_v0 = 0;
    }
    return var_v0;
}

extern int gbUDPEnabled; int NetIsPeerToPeerHost(); int NetSetIncomingClient();
typedef struct { int a; int err; } DmeIncRes;
int NetIIncomingClient(int *in, DmeIncRes *out)
{
    int host = 0;

    if (out == NULL) return 0x17;
    out->err = 30;
    out->a = 1;
    if (in == NULL) {
        out->err = 0x17;
        return 0x17;
    }
    if (in[0] == 0) {
        out->err = 0x26;
        return 0x26;
    }
    if (gbUDPEnabled == 0) {
        out->err = 0x1A;
        return 0x1A;
    }
    out->err = NetIsPeerToPeerHost(NetGetConnInfo(0), &host);
    if (out->err == 0 && host != 0)
        NetSetIncomingClient(NetGetConnInfo(0), in, out);
    return out->err;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetSetIncomingClient);

int NetISetMyClientReceiveBroadcast(char *c, int v)
{
    int r;
    if (c == NULL) return 0x17;
    if (*(int *)(c + 0x468) == 2) {
        r = (*(DmeIfFn2 *)((char *)gP2PInterfacePtr + 0x4C))(*(int *)(c + 0x474), v);
        if (r != 0) return 0x25;
    } else {
        r = NetMapRtError((*(DmeIfFn2 *)((char *)gMsgClientInterfacePtr + 0x40))(*(int *)(c + 0x470), v));
        if (r != 0) return r;
    }
    return 0;
}

extern char gPingInfo[];
typedef struct { char pad[16]; int used; char pad2[12]; } PingSlot;
int FindFreePingSlot(void)
{
    int i;
    for (i = 0; i < 127; i++)
        if (((PingSlot *)gPingInfo)[i].used == 0) return i;
    return 127;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIPing);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIPingIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetUpdateAll);

int NetUpdateAll();
int NetProcessEchoRequests();
int NetITick(void)
{
    int r = NetUpdateAll(0);
    if (r != 0) return r;
    return NetProcessEchoRequests(0);
}

extern int gbTimebaseEnabled;
int rt_time_get_local(); int NetUpdateAll(); int NetProcessEchoRequests(); int rt_parse_update(); int NetProcessP2PDisconnect();
int NetIUpdate(void)
{
    int t;
    int r;
    char *g;

    rt_time_get_local(&t);
    r = NetUpdateAll(1);
    if (r != 0) return r;
    if (gbTimebaseEnabled)
        rt_timebase_get_globaltime((char *)gDmeGlobals + 0x10);
    if (gObjectInterfacePtr != NULL) {
        g = *(char **)((char *)gObjectInterfacePtr + 0x138);
        if (g != NULL && *(int *)(g + 0x454) == 1 && *(int *)(g + 0x404) < *(int *)(g + 0x460) &&
            *(int *)((char *)gObjectInterfacePtr + 0x124) != 0) {
            (*(void (**)())((char *)gObjectInterfacePtr + 0x98))();
            (*(void (**)())((char *)gObjectInterfacePtr + 0x9C))();
        }
    }
    r = NetCheckForPingTimeouts();
    if (r != 0) return r;
    r = NetProcessEchoRequests(1);
    if (r != 0) return r;
    if (gObjectInterfacePtr != NULL) {
        r = (*(int (**)())((char *)gObjectInterfacePtr + 0xA0))();
        if (r != 0) return r;
    }
    r = NetMapRtError(rt_parse_update());
    if (r != 0) return r;
    return NetProcessP2PDisconnect();
}

int NetIGetNetUpdateErrors(void *a)
{
    if (a == NULL) return 10;
    memcpy(a, gNetUpdateErrors, 0x28);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIDisconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetMapRtError);

extern void *gppClientPingInfo[];

void *NetGetClientPingInfo(unsigned int i)
{
    if (i >= 256) return NULL;
    if (gppClientPingInfo[i] == NULL) gppClientPingInfo[i] = DMEmalloc(0x1A0);
    return gppClientPingInfo[i];
}

extern void *gppClientPingInfo[256];

int NetCleanupClientPingInfoArray(void)
{
    int i;

    for (i = 0; i < 256; i++)
        DmeFree(&gppClientPingInfo[i]);
    return 0;
}

void *NetGetConnInfo(unsigned int idx)
{
    void *p = NULL;

    if (idx < 4)
        p = ((void **)&gppConnInfo)[idx];
    return p;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetCleanupConnInfo);

void *NetCreateConnInfoBare(void) {
    return DMEmalloc(0x4AC);
}

int NetSetConnInfo(int arg0, int arg1) {
    int *temp_a0;
    int var_v0;

    temp_a0 = (arg0 * 4) + &gppConnInfo;
    var_v0 = 0x17;
    if (*temp_a0 == 0) {
        *temp_a0 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

int NetCreateConnInfo(unsigned int idx, char **out)
{
    if (out == NULL) return 0x17;
    *out = NULL;
    if (idx >= 4) return 0x17;
    if (((char **)&gppConnInfo)[idx] == NULL) {
        ((char **)&gppConnInfo)[idx] = NetCreateConnInfoBare();
        if (((char **)&gppConnInfo)[idx] == NULL) return 0x16;
        *(unsigned int *)(((char **)&gppConnInfo)[idx] + 0x46C) = idx;
    }
    *out = ((char **)&gppConnInfo)[idx];
    return 0;
}

void NetDestroyConnInfoBare(void *p)
{
    DmeFree(&p);
}

void NetDestroyConnInfo(char *c)
{
    int i;
    if (c != NULL) {
        for (i = 0; i < 256; i++) NetDestroyClientInfo((void **)c, i);
        DmeFree((void **)&gppConnInfo + *(int *)(c + 0x46C));
    }
}

void *NetGetClientInfo(int arr, int idx)
{
    void *p = NULL;

    if (arr != 0 && (unsigned int)idx < 256)
        p = ((void **)arr)[idx];
    return p;
}

int NetCreateClientInfo(void **arr, unsigned int idx, void **out)
{
    void **slot;

    if (out == NULL) return 0x17;
    *out = NULL;
    if (idx >= 256) return 0x17;
    if (arr == NULL) return 0xA;
    slot = (void **)(idx * 4 + (int)arr);
    if (*slot == NULL) {
        *slot = DMEmalloc(0x2C);
        if (*slot == NULL) return 0x16;
    }
    *out = arr[idx];
    return 0;
}

void NetDestroyClientInfo(void **arr, int idx)
{
    if (arr != NULL)
        DmeFree(&arr[idx]);
}

typedef struct { int a, b; } LinkAddrS;

LinkAddrS NetGetServerIpAddress(char *c)
{
    LinkAddrS a;
    rt_comm_linkaddress_setnull(&a);
    if (c != NULL) a = *(LinkAddrS *)(c + 0x410);
    return a;
}

int NetSetServerIpAddress(char *dme, void *addr)
{
    int ret = 0x17;

    if (addr != NULL) {
        if (dme != NULL) {
            rt_comm_linkaddress_toint(dme + 0x410, addr);
            ret = 0;
        }
    }
    return ret;
}

typedef struct { int a[4]; void (*cb)(int, void *, int); int time; int pad[2]; } DmePingInfo;
int NetCheckForPingTimeouts(void)
{
    unsigned int i;
    char ext[16];
    struct { int t; int u; } now;
    DmePingInfo *pi;

    rt_time_get_local(&now);
    for (i = 0, pi = (DmePingInfo *)gPingInfo; i < 127; i++, pi++) {
        if (pi->cb != NULL && now.t - pi->time - 30000 > 0) {
            rt_comm_linkaddress_toext(ext, pi);
            *(int *)((char *)gDmeGlobals + 0x18) = pi->a[0];
            *(int *)((char *)gDmeGlobals + 0x1C) = pi->a[1];
            *(int *)((char *)gDmeGlobals + 0x20) = pi->a[2];
            pi->cb(0xE, ext, 0);
            pi->cb = NULL;
        }
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIsPeerToPeerHost);

typedef struct { unsigned char state; char pad[3]; DmeLinkAddr addr; char pad2[0x10]; void (*cb)(int, char *, int); } DmeEchoReq;
extern DmeEchoReq gPendingEchoRequest[256];
extern int gbEchoRequestsEnabled;

void EchoRequestCallback(DmeLinkAddr addr, int id)
{
    unsigned int i;
    DmeEchoReq *r;

    if (rt_comm_linkaddress_isnull(addr)) return;
    for (i = 0, r = gPendingEchoRequest; i < 256; i++, r++) {
        if (rt_comm_linkaddress_isequal(r->addr, addr) && r->state == 2 && ((id ^ *(int *)((char *)r + 0xC)) & 0xFFFF) == 0) {
            rt_time_elapsed((char *)r + 0x10, (char *)r + 0x18);
            r->state = 3;
            return;
        }
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetProcessEchoRequests);

int NetMapRtError();
int NetDisablePingIPs(void)
{
    char buf[16];
    unsigned int i;
    DmeEchoReq *e;
    int r;

    for (i = 0, e = gPendingEchoRequest; i < 256; i++, e++) {
        if ((unsigned char)(e->state - 1) < 2) e->state = 4;
        if (e->state == 4) {
            rt_comm_linkaddress_toext(buf, e->addr);
            if (e->cb != NULL) {
                e->cb(0xE, buf, 0);
                e->cb = NULL;
            }
            e->state = 0;
        }
    }
    if (gbEchoRequestsEnabled) {
        r = NetMapRtError(rt_comm_echo_shutdown());
        if (r != 0) return r;
        gbEchoRequestsEnabled = 0;
    }
    memset(gPendingEchoRequest, 0, sizeof(gPendingEchoRequest));
    return 0;
}

int NetGetClientConnectStatus(void *c, unsigned int idx, int *st)
{
    char *ci;

    if (c == NULL) return 0x17;
    if (idx >= 256) return 0x17;
    if (st == NULL) return 0x17;
    *st = 0xFFFFFF;
    ci = NetGetClientInfo(c, idx);
    if (ci == NULL) return 0x17;
    if (*(int *)(ci + 0x20) != 0)
        *st = 1;
    else
        *st = 0;
    return 0x1E;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetProcessP2PDisconnect);

int NetClientIndexToClientIndexPacket(int arg0) {
    return arg0 & 0xFF;
}

int NetGetNatService(M2C_UNK **arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        *arg0 = &gNatService;
        var_v0 = 0;
    }
    return var_v0;
}

int NetConvertTransportFlags(signed char f, unsigned short *out)
{
    if (out == NULL) return 0x17;
    *out = 0;
    if (f & 0x10) *out = 0x2000;
    if (f & 0x40) *out |= 0x4000;
    if (f < 0) *out |= 0x1000;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", p2p_connect_cb);

void p2p_disconnect_cb(int reason, char *c)
{
    DmeDiscMsg m;

    if (c == NULL) return;
    if (*(int *)(c + 0x468) != 2) return;
    if (*(DmeDiscCb *)(c + 0x430) == NULL) return;
    m.c = c;
    *(int *)(c + 0x454) = 4;
    m.a = 4;
    m.b = 1;
    m.cc = 0;
    m.d = 0;
    if (reason == 0xD4E9) m.cc = 14; else m.cc = 37;
    m.d = *(int *)(c + 0x434);
    (*(DmeDiscCb *)(c + 0x430))(&m);
}

void p2p_system_change_cb(int arg0, int arg1, void *arg2) {
    if ((arg2 == NULL) || (M2C_FIELD(arg2, int *, 0x468) != 2)) {
        return;
    }
    if (arg1 != 0) {
        M2C_FIELD(arg2, int *, 0x450) = (int) (M2C_FIELD(arg2, int *, 0x450) | arg0);
        return;
    }
    M2C_FIELD(arg2, int *, 0x450) = (int) (M2C_FIELD(arg2, int *, 0x450) & ~arg0);
}

typedef struct { char *ctx; int host; void *data; } DmeHostChangeEv;
extern void *gStreamMediaInterfacePtr;
void p2p_host_change_cb(unsigned short host, char *ctx)
{
    DmeHostChangeEv ev;

    if (ctx == NULL) return;
    if (*(int *)(ctx + 0x468) == 2) {
        ((struct { unsigned int b : 1; unsigned int r : 31; } *)(ctx + 0x450))->b = 0;
        if (gpfHostChangeCallback != 0) {
            ev.ctx = ctx;
            ev.host = host;
            ev.data = (void *)gpHostChangeCallbackData;
            ((void (*)(DmeHostChangeEv *))gpfHostChangeCallback)(&ev);
        }
        return;
    }
    if (gStreamMediaInterfacePtr != NULL) {
        if ((*(int (**)())((char *)gStreamMediaInterfacePtr + 0x18))(ctx))
            (*(int (**)())((char *)gStreamMediaInterfacePtr + 0x64))(ctx, host);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", udp_resolve_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", p2p_peer_update_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", p2p_incoming_data_cb);

int NetGetMyWorldID(void) {
    int var_v0;
    void *temp_v1;

    var_v0 = -1;
    if (gObjectInterfacePtr != NULL) {
        temp_v1 = M2C_FIELD(gObjectInterfacePtr, void **, 0x138);
        if (temp_v1 != NULL) {
            var_v0 = M2C_FIELD(temp_v1, int *, 0x458);
        }
    }
    return var_v0;
}

void udp_unconnected_data_cb(int udp, DmeLinkAddr *addr, int port, int data, int len)
{
    DmeLinkAddr a;

    a = *addr;
    *(DmeLinkAddr *)((char *)gDmeGlobals + 0x18) = a;
    *(int *)((char *)gDmeGlobals + 0x20) = port;
    ParseMessageList((void *)NetGetMyWorldID(), 0, 0x100, data, len);
}

void udp_event_cb(int a, int b, int ev)
{
    if (gUDPInterfacePtr != NULL) {
        if (ev == 0)
            (*(void (**)(int, int))((char *)gUDPInterfacePtr + 0x5C))(a, b);
        else
            (*(void (**)(int, int, int))((char *)gUDPInterfacePtr + 0x3C))(a, b, ev);
    }
}

void udp_data_cb(void) {
    if (gUDPInterfacePtr != NULL) {
        M2C_FIELD(gUDPInterfacePtr, M2C_UNK (**)(), 0x3C)();
    }
}

void p2p_broadcast_update_cb(unsigned short idx, int on, char *c)
{
    char *o;
    if (*(int *)(c + 0x468) != 2) return;
    o = gObjectInterfacePtr;
    if (o != NULL && on != 0) if (*(int *)(o + 0x124) != 0) if (c != NULL)
        (*(DmeObjBcFn *)(o + 0xE0))(c, idx);
}

typedef struct { int a; unsigned char b; int c; int d; unsigned char e; short f; int g; void *data; } DmeSysMsg;
extern void (*gpfSystemMessageCallback)(DmeSysMsg *);
extern void *gpSystemMessageCallbackData;
void MsgClientSystemMessageCallback(int a, unsigned char b, int c, int d, int e, int f, int g)
{
    DmeSysMsg m;
    if (gpfSystemMessageCallback == NULL) return;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;
    m.e = e;
    m.f = f;
    m.g = g;
    m.data = gpSystemMessageCallbackData;
    gpfSystemMessageCallback(&m);
}

int NetMutexLock(void)
{
    char *g = gDmeGlobals;
    if (*(int *)(g + 0x24) == 0) return 5;
    return rt_mutex_lock(g + 0x28, 0);
}

void NetMutexUnlock(void) {
    rt_mutex_unlock(gDmeGlobals + 0x28, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetISetFieldChanged);

int rt_comm_get_host_by_name_nb();
extern void *gpfLookupResponseCallback;
void NetDNSLookupCallback();
typedef struct { char name[0x100]; char addr[8]; void (*cb)(); } DmeDnsReq;
int NetIGetHostByName(char *req)
{
    DmeDnsReq r;
    int ret;

    if (req == NULL) return 0x17;
    if (*(void **)(req + 0x110) == NULL) return 0x17;
    memset(&r, 0, sizeof(r));
    strncpy(r.name, req, 0x100);
    rt_comm_linkaddress_toint(r.addr, req + 0x100);
    r.cb = NetDNSLookupCallback;
    ret = rt_comm_get_host_by_name_nb(&r);
    if (ret == 0)
        gpfLookupResponseCallback = *(void **)(req + 0x110);
    return NetMapRtError(ret);
}

int NetIGetClientBufferStatus(char *ctx, int idx, int *a, int *b, int *c, int *d)
{
    int v[4];

    if (*(int *)(ctx + 0x468) != 2) return 0xF;
    if ((*(int (**)())((char *)gP2PInterfacePtr + 0x24))(*(int *)(ctx + 0x474), (unsigned short)idx, &v[0], &v[1], &v[2], &v[3]) != 0) return 0x25;
    if (a != NULL) *a = v[0];
    if (c != NULL) *c = v[2];
    if (b != NULL) *b = v[1];
    if (d != NULL) *d = v[3];
    return 0;
}

typedef struct { char s[16][16]; int count; int err; } DmeLookupOut;
typedef struct { DmeLinkAddr addr[16]; int count; int err; } DmeLookupIn;
extern DmeLookupOut D_00132DA8;
int NetMapRtError();
void NetDNSLookupCallback(DmeLookupIn *in)
{
    int i;
    int e;

    for (i = 0; i < 16; i++)
        rt_comm_linkaddress_toext(D_00132DA8.s[i], in->addr[i]);
    e = in->err;
    D_00132DA8.count = in->count;
    D_00132DA8.err = NetMapRtError(e);
    ((void (*)(DmeLookupOut *))gpfLookupResponseCallback)(&D_00132DA8);
    gpfLookupResponseCallback = NULL;
}
