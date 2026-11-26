/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiEntityReference", SDomiEntityReference_Initialize);

#ifndef NULL
#define NULL ((void *)0)
#endif
void cmDomiExternalNode_SetParentNode(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x20) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void cmDomiExternalNode_SetPreviousSibling(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x24) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void cmDomiExternalNode_SetNextSibling(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x28) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiExternalNode_get_parentNode(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiExternalNode_get_previousSibling(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x24);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiExternalNode_get_nextSibling(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x28);
}
