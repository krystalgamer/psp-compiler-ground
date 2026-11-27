#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int ServerResponsePacketHandler(void);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", ClientConnectsPacketHandler);

int ServerVersionPacketHandler(char *ctx, int a, int b, const char *ver)
{
    if (ctx == NULL) return -1;
    strncpy(ctx + 0x418, ver, 0x10);
    return 0x10;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", RequestServersPacketHandler);

int ServerResponsePacketHandler(void) {
    return 0xC;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", PingPacketHandler);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", rcsid_10E338);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", headerfile_rcsid_10E3A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", UpdateClientStatusPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMessage", RegisterDMEmessages);
