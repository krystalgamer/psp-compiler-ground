/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char gSv2;
extern unsigned char gSv1;
M2C_UNK SDomiNodeSLink_DeleteAll(int);              /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", SDomiExternalNode_Initialize);

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *AcsExterngSv2(void) {
    return &gSv2;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *AcsExterngSv1(void) {
    return &gSv1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiImplementation_Finalize(int arg0) {
    SDomiNodeSLink_DeleteAll(arg0 + 4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", cmDomiImplementation_hasFeature);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", cmDomiImplementation_createDocumentType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", cmDomiImplementation_createDocument);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gCACore);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gCAv1);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gCAv2);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gSCore);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gSv1);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gSv2);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gImplementationVt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gDomiNotationVt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gDomiProcessingInstructionVt);
