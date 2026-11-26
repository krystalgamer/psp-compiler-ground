#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", apctl_handler_EB714);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _InitNecApNetwork);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _FreeNecApNetwork);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", CheckAccessPoint);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _NecApScanAP);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _NecApConnectAP);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspnet", _NecApDisconnectAP);
