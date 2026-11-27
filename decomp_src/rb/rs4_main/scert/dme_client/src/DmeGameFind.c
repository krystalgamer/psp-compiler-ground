#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void LANFindSetLocalServer(int arg0, int arg1);
extern int gnLocalServerPort;
extern int gpNetLocalServerConnection;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", NetLANFindEnableExchange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", NetLANFind);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", NetSetDefaultLANFindParams);

extern int gLANFinder[];
int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetLANFindCancel(void)
{
    int r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    gLANFinder[1] = 0;
    gLANFinder[2] = 0;
    gLANFinder[3] = 0;
    gLANFinder[0] = 0;
    return NetMapRtError(NetMutexUnlock());
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", NetILANFind);

void LANFindSetLocalServer(int arg0, int arg1) {
    gpNetLocalServerConnection = arg0;
    gnLocalServerPort = arg1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", LANFindGetMyPeerDesc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", LANFindPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", LANFindResultsPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", SendLANFindResultsOnExchange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", SendLANFindReply);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", InitLANFindRequest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", InitLANFindReply);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", OnReceivedLANFindRequest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", OnReceivedLANFindReply);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", rcsid_10DF90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", headerfile_rcsid_10DFF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", D_0010E058);
