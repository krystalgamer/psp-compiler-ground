/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK SDomiStringH_Finalize(int);                 /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
int RecoverPtr(int arg0) {
    return arg0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", DeleteDocHolder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", isDocID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", FindInTrash);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocHolder_Initialize);

#ifndef NULL
#define NULL ((void *)0)
#endif

void SDomiDocHolder_Finalize(int arg0) {
    SDomiStringH_Finalize(arg0 + 8);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocManager_Initialize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocManager_Finalize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocManager_Free);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocManager_AddDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocManager_ReuseDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocManager_TrashActiveDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocManager_TrashDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocManager_DiscardDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocManager_EmptyTrash);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocManager", SDomiDocManager_DeleteDocuments);
