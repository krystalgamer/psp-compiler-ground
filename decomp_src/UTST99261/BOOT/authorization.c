/* cflags: -O1 */
#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", HST_initAuthorizationDB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", HST_attachAuthorizationDB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", HST_freeAuthorizationDB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", HST_addAuthorizationDB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", HST_searchAuthorizationDB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", stringdup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", urlpathlen);
