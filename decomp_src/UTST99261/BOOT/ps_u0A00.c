/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern int buf_ps_sts;

M2C_UNK sendMPL_REQ_DATA_ATTR();                    /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", sendMPL_REQ_DATA_ATTR);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0A03(void) {
    sendMPL_REQ_DATA_ATTR();
    return 0xF;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0A06(void) {
    sendMPL_REQ_DATA_ATTR();
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_u0B03);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_u0C03);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", getBuffSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_u0E13);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_u3103(void) {
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_u3216);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_u3517);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_l1001);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", D_00135A50);
