/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK memmove();                                  /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiMemory", UDomiMemory_Allocate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiMemory", UDomiMemory_Free);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memcpy(void *d, const void *s, unsigned int n);
void UDomiMemory_Copy(void *arg0, void *arg1, unsigned int arg2) {
    memcpy(arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void UDomiMemory_Move(void) {
    memmove();
}
