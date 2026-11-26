#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evfilesave", iom_evFileSave);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evfilesave", iom_saveFilesave);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evfilesave", iom_tellsizeFilesave);

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_removeFilesave(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evfilesave", iom_createFilesave);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evfilesave", iom_addFilesave);

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_closeFilesave(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_tmp2realFilesave(void) {
    return 0;
}
