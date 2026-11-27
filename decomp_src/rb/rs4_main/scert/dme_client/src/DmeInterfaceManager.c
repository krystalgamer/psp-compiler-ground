#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void ClearInterfacePointers(void);
extern void *gObjectInterfacePtr;
extern void *gCommPlatformInterfacePtr;
extern void *gUDPInterfacePtr;
extern int gACodecGSMInterfacePtr;
extern int gACodecLPC10InterfacePtr;
extern int gACodecLPCInterfacePtr;
extern int gCryptInterfacePtr;
extern int gMsgClientInterfacePtr;
extern int gP2PInterfacePtr;
extern int gStreamMediaInterfacePtr;
extern int gVCodecJPEGInterfacePtr;

void ClearInterfacePointers(void) {
    gMsgClientInterfacePtr = 0;
    gStreamMediaInterfacePtr = 0;
    gCommPlatformInterfacePtr = 0;
    gObjectInterfacePtr = 0;
    gP2PInterfacePtr = 0;
    gUDPInterfacePtr = 0;
    gCryptInterfacePtr = 0;
    gACodecGSMInterfacePtr = 0;
    gACodecLPCInterfacePtr = 0;
    gACodecLPC10InterfacePtr = 0;
    gVCodecJPEGInterfacePtr = 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeInterfaceManager", rcsid_10E068);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeInterfaceManager", header_rcsid_10E0D4);
