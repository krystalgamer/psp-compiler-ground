#include "common.h"
#include "m2c_macros.h"
M2C_UNK iom_evGetMethod();                          /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_evHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_attachHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_detachHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_addHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_stopHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_freeStateHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_initStateHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_setupStateHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_connectingStateHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_downloadStateHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_cacheStateHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_doneStateHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_setHttpRequestHeader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_httpToLocalError);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_httpCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_location);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_setCookie2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_evGetMethod);

#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_evPostMethod(void) {
    iom_evGetMethod();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_evHeadMethod);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_evLoadStop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_evLoadStop2);
