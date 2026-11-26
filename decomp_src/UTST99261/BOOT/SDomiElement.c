#include "common.h"
#include "m2c_macros.h"
M2C_UNK SDomiElement_getAttributeNode(int);         /* extern */
M2C_UNK SDomiElement_setAttributeNode(int);         /* extern */
M2C_UNK SDomiPtrArray_GetItem(int);                 /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", TagFilter);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", PutAttribute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", NewAttribute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_CheckNewAttr);

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiElementNamedNodeSet_getNamedItem(void *arg0) {
    SDomiElement_getAttributeNode(M2C_FIELD(arg0, int *, 4));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiElementNamedNodeSet_setNamedItem(void *arg0) {
    SDomiElement_setAttributeNode(M2C_FIELD(arg0, int *, 4));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElementNamedNodeSet_removeNamedItem);

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiElementNamedNodeSet_item(void *arg0) {
    SDomiPtrArray_GetItem(M2C_FIELD(arg0, int *, 4) + 0x38);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElementNamedNodeSet_get_length);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElement_Finalize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElement_InheritObjInfo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElement_FreeTrash);

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiElement_get_attributes(int arg0) {
    return arg0 + 0x48;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElement_cloneNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElement_GetAttrNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElement_GetDefault);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElement_SetAttrNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElement_RemoveAttrNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElement_getElementsByTagName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_BuildTagElementList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_Initialize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_OwnAttr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_ReleaseAttr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_getAttribute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_setAttribute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_removeAttribute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_getAttributeNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_setAttributeNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_removeAttributeNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_hasAttribute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiEntity_Finalize);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gDomiElementVt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gSDomiElementNamedNodeSetVt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gCAwildcard);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gSwildcard);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gDomiEntityVt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gDomiEntityReferenceVt);
