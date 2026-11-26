/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK HST_moveBackHistory();                      /* extern */
M2C_UNK HST_moveFrontHistory();                     /* extern */
M2C_UNK parseHST_deleteHistoryNode(M2C_UNK, M2C_UNK); /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseFreeItem);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseDeleteHistoryItem);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseHST_deleteHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseRegistURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseReplaceURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseReloadURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseMoveFrontURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseMoveBackURI);

#ifndef NULL
#define NULL ((void *)0)
#endif

void parseSavedContents(void) {
    HST_moveBackHistory();
    parseHST_deleteHistoryNode(0, 0);
    HST_moveFrontHistory();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseCopyHistoryEntities);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseCopyHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", uricmp_722F8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", flushRequestFlag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", fillRequestFlag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", copyEntities);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseRoundHistoryNode);
