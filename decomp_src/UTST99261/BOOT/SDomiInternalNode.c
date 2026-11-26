#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", CheckNewNode);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ChildFilter(void) {
    return 2;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", DomiInternalNode_BuildChildNodeList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", SDomiInternalNode_BuildNodeSet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiInternalNode_Finalize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiInternalNode_Changed);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiInternalNode_InheritObjInfo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiInternalNode_FreeTrash);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiInternalNode_get_childNodes);

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiInternalNode_get_firstChild(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiInternalNode_get_lastChild(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x24);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiInternalNode_insertBefore);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiInternalNode_removeChild);

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiInternalNode_hasChildNodes(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x20) != 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", SDomiInternalNode_Initialize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", SDomiInternalNode_CloneChildren);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiNamedNodeSet_getNamedItem);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiNamedNodeSet_setNamedItem);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiNamedNodeSet_removeNamedItem);

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNamedNodeSet_item(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNamedNodeSet_get_length(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiNamedNodeSet_getNamedItemNS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiNamedNodeSet_setNamedItemNS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiNamedNodeSet_removeNamedItemNS);
