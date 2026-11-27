#include "common.h"
#include "rb/rs4_main/scert/scert.h"

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
