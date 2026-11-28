#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void LANFindSetLocalServer(int, int);
int NetLANFind(void *);
int NetLANFindCancel(void);
int NetMutexLock(void);
int SendLANFindResultsOnExchange(int *, int *, int);

extern int gnLocalServerPort;
extern int gpNetLocalServerConnection;

extern void *gpExchangeCallbackUserData;
extern void (*gpfnLANFindExchangeCallback)(int *, int *, int);
int SendLANFindReply();

extern void *gDmeGlobals;
extern int gbEnableLANFindExchange;
int NetLANFindEnableExchange(int en, void (*cb)(int *, int *, int), void *ud)
{
    int r;
    if (*(int *)((char *)gDmeGlobals + 0x3C) != 2) return 0x10;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    gbEnableLANFindExchange = en;
    gpfnLANFindExchangeCallback = cb;
    gpExchangeCallbackUserData = ud;
    return NetMapRtError(NetMutexUnlock());
}

extern void *gDmeGlobals;
int NetILANFind();
int NetLANFind(void *p)
{
    int r, e;
    if (*(int *)((char *)gDmeGlobals + 0x3C) != 2) return 0x10;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetILANFind(p);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

extern void *gUDPInterfacePtr;
int NetSetDefaultLANFindParams(int *p)
{
    memset(p, 0, 0x20);
    p[0] = 1;
    p[2] = 3;
    p[1] = 0;
    if (gUDPInterfacePtr != NULL)
        p[5] = *(int *)((char *)gUDPInterfacePtr + 0x84);
    return 0;
}

extern int gLANFinder[];

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

int SendLANFindResultsOnExchange(int *res, int *flag, int c)
{
    void (*cb)(int *, int *, int) = gpfnLANFindExchangeCallback;
    res[0x2D] = (int)gpExchangeCallbackUserData;
    *flag = 1;
    res[0] = c;
    if (cb != NULL) {
        cb(res, flag, c);
        if (*flag == 0) return 0;
    }
    return SendLANFindReply(flag + 1, res[1], c);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", SendLANFindReply);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", InitLANFindRequest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", InitLANFindReply);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", OnReceivedLANFindRequest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", OnReceivedLANFindReply);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", rcsid_10DF90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", headerfile_rcsid_10DFF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeGameFind", D_0010E058);
