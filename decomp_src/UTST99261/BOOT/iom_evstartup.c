#include "common.h"
#include "m2c_macros.h"
M2C_UNK iom_freeMsg();                              /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evstartup", iom_evStartup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evstartup", iom_evExit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evstartup", iom_evEnd);

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_evException(void) {
    iom_freeMsg();
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evstartup", iom_accessLocalfile);
