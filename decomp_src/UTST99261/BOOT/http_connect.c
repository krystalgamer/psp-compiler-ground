/* cflags: -O1 */
#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect_checkServer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect_SetAutoHead);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect_setAllReqHead);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect_error_end);
