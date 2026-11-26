/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern int buf_ps_sts;

M2C_UNK sendMPU_RPL_DATA_ATTR();                    /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1900", sendMPU_RPL_DATA_ATTR);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l1903(void) {
    sendMPU_RPL_DATA_ATTR();
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l190F(void) {
    sendMPU_RPL_DATA_ATTR();
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1900", ps_l1913);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1900", ps_l1A03);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1900", ps_l1A06);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1900", ps_l1A07);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1900", ps_l1A08);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1900", ps_l1B12);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1900", D_00135C74);
