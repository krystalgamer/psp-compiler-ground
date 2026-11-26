/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int ps_sessionGen();                                /* extern */
M2C_UNK setParseMassageToDestTask(M2C_UNK, int, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern int buf_localUI;
extern int buf_sessionUI;
extern int buf_ps_sts;

M2C_UNK ps_dmy();                                   /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0000(void *arg0) {
    buf_sessionUI = M2C_FIELD(arg0, int *, 4);
    buf_localUI = M2C_FIELD(arg0, int *, 0x14);
    setParseMassageToDestTask(4, ps_sessionGen(), 0, 0x301, 0, 0, 0, 0);
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0103);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0203);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0206);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0207);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0208);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0212);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0217);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0303(void *arg0) {
    buf_sessionUI = M2C_FIELD(arg0, int *, 4);
    buf_localUI = M2C_FIELD(arg0, int *, 0x14);
    setParseMassageToDestTask(4, ps_sessionGen(), 0, 0x305, M2C_FIELD(arg0, int *, 0x10), 0, 0, 0);
    return 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0306(void *arg0) {
    buf_sessionUI = M2C_FIELD(arg0, int *, 4);
    buf_localUI = M2C_FIELD(arg0, int *, 0x14);
    setParseMassageToDestTask(4, ps_sessionGen(), 0, 0x305, M2C_FIELD(arg0, int *, 0x10), 0, 0, 0);
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0506);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0507);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0508);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0509);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0512);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0514);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_u0703(void) {
    return 3;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_u0803(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_u0806(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_u0903(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_u0906(void) {
    ps_dmy();
}
