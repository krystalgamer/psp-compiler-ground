/* cflags: -O1 */
#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_new", http_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_new", http_msg_send_request);

void http_msg_endThread(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_new", http_sndreq_main);
