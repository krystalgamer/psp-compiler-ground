/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int getRestImageTotalSquareSize(void) {
    return -1;
}

void incrementImageTotalSquareSize(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", addImageList);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", defImage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", noImage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", discImage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", makeHttpHeader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setRequestMessageBuffer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setImageToBoxBuffer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setImageInBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", imageDecodeSuccess);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", imageDecodeFailure);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", initDefaultImage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", deleteDefaultImage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", initImageList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", reserveGetRequest);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", checkImageList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", requestImageData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setImageData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setBrokenImageData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", calcHttpHeaderSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", initLLIST);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", putLLIST);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", delLLIST);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", putChildLLIST);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", getNextLLIST);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", searchLLISTByURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", searchLLISTBySESSION);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", checkRecieveLLIST);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", checkNoReceiveLLIST);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", delLLISTByDocumentSession);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", delLLISTByHistoryTree);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", countRequestedLLIST);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", msgBranch);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", proc_msg_IL1);

void proc_msg_IL2(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", proc_msg_IL3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", proc_msg_IL4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", proc_msg_IL5);
