#include "common.h"
#include "m2c_macros.h"
M2C_UNK sceUtilityDeleteNetParam(M2C_UNK);          /* extern */
extern int bCreateNetParam;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", apctl_handler_EB714);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _InitNecApNetwork);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _FreeNecApNetwork);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", CheckAccessPoint);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _NecApScanAP);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _NecApConnectAP);

#ifndef NULL
#define NULL ((void *)0)
#endif

void _NecApDisconnectAP(void) {
    if (bCreateNetParam != 0) {
        sceUtilityDeleteNetParam(0);
        bCreateNetParam = 0;
    }
}
