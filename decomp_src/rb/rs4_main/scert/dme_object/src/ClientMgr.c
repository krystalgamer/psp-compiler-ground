#include "common.h"
#include "rb/rs4_main/scert/scert.h"

void *memset(void *s, int c, unsigned int n);
void NetInitializeClients(void) {
    NetClientPointerList = DMEmalloc(0x400);
    if (gObjectInterfacePtr != NULL) {
        M2C_FIELD(gObjectInterfacePtr, int *, 0x128) = 0;
    }
    memset(NetClientPointerList, 0, 0x400U);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", NetIGetClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", NetIGetClientStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", NetCreateClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", NetFreeClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", NetFreeClients);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", NetFreeAllClients);

void NetFreeClientPointers(void) {
    DmeFree(&NetClientPointerList);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", rcsid_10DB6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", headerfile_rcsid_10DBCC);
