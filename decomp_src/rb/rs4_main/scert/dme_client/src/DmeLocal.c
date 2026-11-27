#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetClientIndexToClientIndexPacket(int arg0);
int NetGetMsgClientIndex(void *arg0);
int NetGetMyWorldID(void);
int NetGetNatService(M2C_UNK **arg0);
int NetGetP2PHandle(void *arg0);
int NetIGetClientIpAddress(void *arg0, int arg1, int arg2);
int NetIGetCurrentUDPSourceBinaryIP(void *arg0);
int NetIGetMyClientIndex(int *arg0, void *arg1);
int NetIGetTime(void *arg0);
int NetISetDefaultResolveAddrParams(void *arg0);
int NetSetConnInfo(int arg0, int arg1);
int NetSetDefaultIncomingClientParams(int *arg0);
int NetSetPeerToPeerHostChangeCallback(int arg0, int arg1);
int NetUseDme(void);
int RtMsgToDmeConnectionIndex(unsigned int arg0);
void NetCreateConnInfoBare(void);
void NetGetMyAddressInfoInternal(void *arg0);
void NetMutexUnlock(void);
void NetResetTime(int arg0);
void NetSetHeartbeatInterval(int arg0);
void p2p_system_change_cb(int arg0, int arg1, void *arg2);
void udp_data_cb(void);
void *DMEmalloc(M2C_UNK);                           /* extern */
void *NetGetClientInfo(int, int);                   /* extern */
M2C_UNK rt_comm_linkaddress_toext(void *, void *);  /* extern */
M2C_UNK rt_mutex_unlock(int, M2C_UNK);              /* extern */
M2C_UNK rt_timebase_get_globaltime(void *);         /* extern */
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetGetMyAddressInfo);

int NetGetP2PHandle(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x474);
}

int NetUseDme(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", GetSoftwareID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetMyIntIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetMyExtIP);

int NetGetMsgClientIndex(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x470);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", SendMyClientStatus);

int RtMsgToDmeConnectionIndex(unsigned int arg0) {
    return arg0 + (arg0 < 5U);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetAverageDelayToClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetBufferStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetISetSendAggregationInterval);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetBandwidthInfo);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", DMEmalloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", DmeFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIRegisterMemoryCallbacks);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetMyIpAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetMyNetAddress);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", RemoteClientDisconnects);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetLocalTime);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetConnectStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetValidClientCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetConnectionStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetServerVersion);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetISendTo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetBitMaskToSendMask);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetSendMessageByUDP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetSendMessageByTCP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetFragSendCB);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetISendMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", ParseMessageList);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", RemoteClientDisconnectEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", RemoteClientEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIInitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIAssignLocalServer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIEnableUDP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetCreateP2PInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", IncomingMessageFunc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", MapMsgClientFailureReason);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", MyClientConnectsPeerToPeer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", MsgClientConnectCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", MsgClientDisconnectCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetSetDefaultConnectParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIConnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetConnect_ClientServerTCP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetConnect_PeerToPeerUDP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetSetDefaultHostPeerToPeerParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIHostPeerToPeer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetISetNATServiceAddr);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIIncomingClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetSetIncomingClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetISetMyClientReceiveBroadcast);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", FindFreePingSlot);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIPing);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIPingIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetUpdateAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetITick);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetNetUpdateErrors);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIDisconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetMapRtError);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetGetClientPingInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetCleanupClientPingInfoArray);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetGetConnInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetCleanupConnInfo);

void NetCreateConnInfoBare(void) {
    DMEmalloc(0x4AC);
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetCreateConnInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetDestroyConnInfoBare);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetDestroyConnInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetGetClientInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetCreateClientInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetDestroyClientInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetGetServerIpAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetSetServerIpAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetCheckForPingTimeouts);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIsPeerToPeerHost);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", EchoRequestCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetProcessEchoRequests);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetDisablePingIPs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetGetClientConnectStatus);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetConvertTransportFlags);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", p2p_connect_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", p2p_disconnect_cb);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", p2p_host_change_cb);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", udp_unconnected_data_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", udp_event_cb);

void udp_data_cb(void) {
    if (gUDPInterfacePtr != NULL) {
        M2C_FIELD(gUDPInterfacePtr, M2C_UNK (**)(), 0x3C)();
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", p2p_broadcast_update_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", MsgClientSystemMessageCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetMutexLock);

void NetMutexUnlock(void) {
    rt_mutex_unlock(gDmeGlobals + 0x28, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetISetFieldChanged);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetHostByName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetIGetClientBufferStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeLocal", NetDNSLookupCallback);
