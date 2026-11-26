#include "common.h"
#include "m2c_macros.h"
M2C_UNK SDomiNodeSLink_DeleteAll(int);              /* extern */
M2C_UNK AcsExterngDomiNodeSetEmpty();               /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

void SDomiDocument_EmptyTrash(int arg0) {
    SDomiNodeSLink_DeleteAll(arg0 + 0x38);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", ImportDeep);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_Finalize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_FreeTrash);

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiDocument_get_doctype(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_createElement);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_createDocumentFragment);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_createTextNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_createComment);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_createCDATASection);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_createProcessingInstruction);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_createAttribute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_createEntityReference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_getElementsByTagName);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", gDomiDocumentVt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_importNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_createElementNS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_createAttributeNS);

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiDocument_getElementsByTagNameNS(void) {
    AcsExterngDomiNodeSetEmpty();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiDocument_getElementById(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", SDomiDocument_Initialize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", SDomiDocument_createCharacterData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocumentFragment_cloneNode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", gDomiDocumentFragmentVt);
