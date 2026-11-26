#include "common.h"
#include "m2c_macros.h"
M2C_UNK SDomiStringH_Finalize(int);                 /* extern */
M2C_UNK AcsExterngDomiNodeSetEmpty();               /* extern */
M2C_UNK AcsExterngSnull();                          /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
void SDomiNamedNodeSet_Initialize(void *arg0, int arg1, int arg2) {
    M2C_FIELD(arg0, int *, 0) = arg1;
    M2C_FIELD(arg0, int *, 4) = arg2;
    M2C_FIELD(arg0, signed char *, 8) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiNode_Finalize(int arg0) {
    SDomiStringH_Finalize(arg0 + 0x10);
}

void cmDomiNode_Changed(void) {
}

void cmDomiNode_SetParentNode(void) {
}

void cmDomiNode_SetPreviousSibling(void) {
}

void cmDomiNode_SetNextSibling(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void cmDomiNode_InheritObjInfo(void *arg0, int arg1) {
    M2C_FIELD(arg0, unsigned char *, 4) = (unsigned char) (M2C_FIELD(arg0, unsigned char *, 4) | arg1);
}

void cmDomiNode_FreeTrash(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNamedNodeSet", cmDomiNode_get_nodeValue);

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_set_nodeValue(void) {
    return 7;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_get_parentNode(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiNode_get_childNodes(void) {
    AcsExterngDomiNodeSetEmpty();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_get_firstChild(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_get_lastChild(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_get_previousSibling(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_get_nextSibling(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_get_attributes(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_insertBefore(void) {
    return 3;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_removeChild(void) {
    return 8;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_hasChildNodes(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNamedNodeSet", cmDomiNode_cloneNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNamedNodeSet", cmDomiNode_isSupported);

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiNode_get_namespaceURI(void) {
    AcsExterngSnull();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiNode_get_prefix(void) {
    AcsExterngSnull();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_set_prefix(void) {
    return 0xE;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiNode_get_localName(void) {
    AcsExterngSnull();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiNode_hasAttributes(void) {
    return 0;
}
