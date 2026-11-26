/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int RecoverNodePtr(int arg0) {
    int var_v0;

    var_v0 = arg0 - 8;
    if (arg0 == 0) {
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeSLink", SDomiNodeSLink_RemoveFirst);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeSLink", SDomiNodeSLink_DeleteAll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeSLink", cmDomiNotation_Finalize);
