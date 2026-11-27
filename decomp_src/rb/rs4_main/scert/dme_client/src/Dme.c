#include "common.h"
#include "rb/rs4_main/scert/scert.h"

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", rcsid_10DE3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", gszDmeVersionString);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", gBuildTimeStamp_10DEB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", gszrtBaseVersionString);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetClientVersion);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetDefaultInitializeParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetInitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetAverageDelayToClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetBufferStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetSendAggregationInterval);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetBandwidthInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetRegisterMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetRegisterApplicationMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSendMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSendApplicationMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetRegisterDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetDefaultMemoryCallbackParams);

void NetRegisterMemoryCallbacks(void) {
    NetIRegisterMemoryCallbacks();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetAssignLocalServer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetConnect);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetHostPeerToPeer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetNATServiceAddr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetDefaultResolveAddrParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetResolveAddr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetIncomingClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetMyClientReceiveBroadcast);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetPing);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetPingIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetPingNetAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetOpenDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetAddToDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetEndDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSendMyClientUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetClientStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetMyIpAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetMyNetAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetClientIpAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetMyClientIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetPeerToPeerHostClientIndex);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetConnectStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetValidClientCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetDefaultStreamMediaParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetConnectionStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetDataStreamBytesFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetServerVersion);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetNetUpdateErrors);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetTick);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetLeave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetDefaultDisconnectParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetDisconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetStreamMediaJoinChannel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetStreamMediaQuitChannel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetStreamMediaGetChannelInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetStreamMediaGetClientInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetStreamMediaEndRecording);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetStreamMediaGetCurrentChannelState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetStreamMediaSetDefaultIgnoreParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetStreamMediaSetIgnoreState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetJoin);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetFieldChanged);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSendFieldUpdates);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetHostByName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetClientBufferStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSetDefaultAppMessageParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetSendAppMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetLANSetUserName);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetGetLocalizationSettings);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", BinaryAddressToNetAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", StringAddressToNetAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetAddressToBinaryAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/Dme", NetIAddressToStringAddress);
