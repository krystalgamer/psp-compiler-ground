/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int HST_initAuthorizationDB();                      /* extern */
extern int authdb;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", HST_initAuthorizationDB);

#ifndef NULL
#define NULL ((void *)0)
#endif

int HST_attachAuthorizationDB(void) {
    int var_v1;

    var_v1 = 0;
    if (authdb == 0) {
        var_v1 = HST_initAuthorizationDB();
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", HST_freeAuthorizationDB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", HST_addAuthorizationDB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", HST_searchAuthorizationDB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", stringdup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", urlpathlen);
