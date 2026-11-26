/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int HST_getHeadHistoryNode();                       /* extern */
int HST_getHistoryWithOffset(M2C_UNK);              /* extern */
int parseDeleteMultiBuffer();                       /* extern */
M2C_UNK parseRoundHistoryNode(int, int);            /* extern */

M2C_UNK HST_moveBackHistory();                      /* extern */
M2C_UNK HST_moveFrontHistory();                     /* extern */
M2C_UNK parseHST_deleteHistoryNode(M2C_UNK, M2C_UNK); /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseFreeItem);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseDeleteHistoryItem);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseHST_deleteHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseRegistURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseReplaceURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseReloadURI);

#ifndef NULL
#define NULL ((void *)0)
#endif

int parseMoveFrontURI(int arg0) {
    int temp_s0;
    int var_s1;

    var_s1 = arg0;
    if (arg0 != 0) {
        var_s1 = parseDeleteMultiBuffer();
    }
    temp_s0 = HST_getHistoryWithOffset(1);
    parseRoundHistoryNode(temp_s0, HST_getHeadHistoryNode());
    HST_moveFrontHistory();
    return var_s1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int parseMoveBackURI(int arg0) {
    int temp_s0;
    int var_s1;

    var_s1 = arg0;
    if (arg0 != 0) {
        var_s1 = parseDeleteMultiBuffer();
    }
    temp_s0 = HST_getHistoryWithOffset(-1);
    parseRoundHistoryNode(temp_s0, HST_getHeadHistoryNode());
    HST_moveBackHistory();
    return var_s1;
}

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
