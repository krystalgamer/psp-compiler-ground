/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void *HST_searchSessionIDHistoryNode(int);          /* extern */
extern int buf_ps_sts;

M2C_UNK ps_dmy();                                   /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_cleaning_mq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1105);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1203);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1211);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1213);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1307);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l1308(void *arg0) {
    void *temp_v0;

    temp_v0 = HST_searchSessionIDHistoryNode(M2C_FIELD(arg0, int *, 4));
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0x3C) = 5;
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1310);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l1312(void *arg0) {
    M2C_FIELD(HST_searchSessionIDHistoryNode(M2C_FIELD(arg0, int *, 4)), int *, 0x3C) = 5;
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l1403(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l140E(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l1413(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l1503(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l150D(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l1513(void) {
    ps_dmy();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1703);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1706);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1707);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1708);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1717);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", D_00135C58);
