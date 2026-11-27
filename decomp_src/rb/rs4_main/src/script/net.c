/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, int, int); /* extern */
M2C_UNK ctrlSetVirtualType(M2C_UNK);                /* extern */
M2C_UNK ctrlSuspend(M2C_UNK);                       /* extern */
extern unsigned char D_000FF4B4;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", Script_NetStartCB);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4FC);

#ifndef NULL
#define NULL ((void *)0)
#endif

void Script_NetTermCB(int arg0, int arg1) {
    consPrintf(&D_000FF4B4, "Script_NetTermCB", arg0, arg1);
    ctrlSuspend(0);
    ctrlSetVirtualType(0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void Script_NetErrCB(int arg0, void *arg1) {
    consPrintf(&D_000FF4B4, "Script_NetErrCB", arg0, arg1);
    M2C_FIELD(arg1, int *, 0x44) = 0;
    ctrlSuspend(0);
    ctrlSetVirtualType(0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", Script_Net);
