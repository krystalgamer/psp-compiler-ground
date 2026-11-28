#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void * NetGetConnInfo(unsigned int);
int NetIGetCurrentUDPSourceBinaryIP(void *);
int NetIRegParseMessage();
void RegisterDMEmessages(void);
int RequestServersPacketHandler(int, int, int, int *);
int ServerResponsePacketHandler(void);
int ServerVersionPacketHandler(char *, int, int, const char *);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", ClientConnectsPacketHandler);

int ServerVersionPacketHandler(char *ctx, int a, int b, const char *ver)
{
    if (ctx == NULL) return -1;
    strncpy(ctx + 0x418, ver, 0x10);
    return 0x10;
}

typedef struct { unsigned int ip; unsigned int port; } DmeLinkAddr2;
typedef struct { struct { void *buf; int len; } e[8]; int total; int n; } DmeVec;
typedef struct { int port; DmeLinkAddr2 addr; } DmeSrvReply;
extern char *gUDPInterfacePtr; extern char *gDmeGlobals;
int NetIsPeerToPeerHost(); int NetIGetMyIntIP(); int NetISendTo();
int RequestServersPacketHandler(int a0, int a1, int a2, int *msg)
{
    DmeLinkAddr2 src;
    DmeVec vec;
    DmeSrvReply r;
    int p2p = 0;
    int port;

    if (!NetIsPeerToPeerHost(NetGetConnInfo(0), &p2p)) {
        NetIGetCurrentUDPSourceBinaryIP(&src);
        if ((*(int *)(gDmeGlobals + 0xC) != 0 || p2p != 0) && *msg == *(int *)gDmeGlobals) {
            port = 0;
            if (gUDPInterfacePtr != NULL) port = *(int *)(gUDPInterfacePtr + 0x84);
            if (*(int *)(gDmeGlobals + 0xC) != 0)
                r.addr = *(DmeLinkAddr2 *)(gDmeGlobals + 4);
            else
                NetIGetMyIntIP(&r.addr);
            if (p2p != 0)
                r.port = port;
            else
                r.port = *(int *)(gDmeGlobals + 0xC);
            vec.e[0].buf = &r;
            vec.e[0].len = 0xC;
            vec.total = 0xC;
            vec.n = 1;
            NetISendTo(&src, port, 0, 0x14, &vec);
        }
    }
    return 4;
}

int ServerResponsePacketHandler(void) {
    return 0xC;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", PingPacketHandler);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", rcsid_10E338);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", headerfile_rcsid_10E3A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", UpdateClientStatusPacketHandler);

int ClientConnectsPacketHandler(); int PingPacketHandler(); int UpdateClientStatusPacketHandler();
int LANFindPacketHandler(); int LANFindResultsPacketHandler(); int LANTextMessageHandler(); int LANRawMessageHandler();
extern char *gObjectInterfacePtr;
extern char *gStreamMediaInterfacePtr;
#define OIF(o) (*(void **)(gObjectInterfacePtr + (o)))
#define SIF(o) (*(void **)(gStreamMediaInterfacePtr + (o)))
void RegisterDMEmessages(void)
{
    NetIRegParseMessage(0, 0, ServerVersionPacketHandler);
    NetIRegParseMessage(1, 0, PingPacketHandler);
    NetIRegParseMessage(0x10, 0, ClientConnectsPacketHandler);
    NetIRegParseMessage(0x13, 0, RequestServersPacketHandler);
    NetIRegParseMessage(0x14, 0, ServerResponsePacketHandler);
    NetIRegParseMessage(0x16, 0, UpdateClientStatusPacketHandler);
    NetIRegParseMessage(0x19, 0, LANFindPacketHandler);
    NetIRegParseMessage(0x1A, 0, LANFindResultsPacketHandler);
    NetIRegParseMessage(0x21, 0, LANTextMessageHandler);
    NetIRegParseMessage(0x22, 0, LANRawMessageHandler);
    if (gObjectInterfacePtr != NULL) {
        NetIRegParseMessage(0xF, 0, OIF(0xEC));
        NetIRegParseMessage(0x12, 0, OIF(0xE8));
        NetIRegParseMessage(0x3, 0, OIF(0xAC));
        NetIRegParseMessage(0x4, 0, OIF(0xB0));
        NetIRegParseMessage(0x5, 0, OIF(0xB4));
        NetIRegParseMessage(0x9, 0, OIF(0xB8));
        NetIRegParseMessage(0xA, 0, OIF(0xBC));
        NetIRegParseMessage(0xB, 0, OIF(0xC0));
        NetIRegParseMessage(0xC, 0, OIF(0xC4));
        NetIRegParseMessage(0xD, 0, OIF(0xC8));
        NetIRegParseMessage(0xE, 0, OIF(0xCC));
        NetIRegParseMessage(0x15, 0, OIF(0xD0));
        NetIRegParseMessage(0x17, 0, OIF(0xD4));
    }
    if (gStreamMediaInterfacePtr != NULL) {
        NetIRegParseMessage(0x18, 0, SIF(0x48));
        NetIRegParseMessage(0x1B, 0, SIF(0x4C));
        NetIRegParseMessage(0x1C, 0, SIF(0x50));
        NetIRegParseMessage(0x1D, 0, SIF(0x54));
        NetIRegParseMessage(0x1E, 0, SIF(0x58));
        NetIRegParseMessage(0x1F, 0, SIF(0x5C));
        NetIRegParseMessage(0x20, 0, SIF(0x60));
        NetIRegParseMessage(0x23, 0, SIF(0x68));
        NetIRegParseMessage(0x24, 0, SIF(0x6C));
    }
}
