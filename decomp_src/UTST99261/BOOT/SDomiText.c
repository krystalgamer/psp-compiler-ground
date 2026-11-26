#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiText", SDomiText_splitText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiText", cmDomiTrunkNode_Changed);

#ifndef NULL
#define NULL ((void *)0)
#endif
void cmDomiTrunkNode_SetParentNode(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x2C) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void cmDomiTrunkNode_SetPreviousSibling(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x30) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void cmDomiTrunkNode_SetNextSibling(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x34) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiTrunkNode_get_parentNode(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x2C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiTrunkNode_get_previousSibling(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x30);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiTrunkNode_get_nextSibling(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x34);
}
