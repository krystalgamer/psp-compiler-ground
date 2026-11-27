/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK OS_thread_mutex_destroy(int);               /* extern */
extern unsigned char msg_man;



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", addThreadTbl);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", delThreadTbl);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", srchThreadTbl);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_open);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_close);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_unlink);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_send);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_receive);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_getattr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_setattr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", CreateMbx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", DeleteMbx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", ReceiveMbx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", PollMbx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", SendMbx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", ReferMbxStatus);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", CreateMbxMan);

#ifndef NULL
#define NULL ((void *)0)
#endif

int DeleteMbxMan(void) {
    if (M2C_FIELD(&msg_man, int *, 0) == 0) {
        OS_thread_mutex_destroy(M2C_FIELD(&msg_man, int *, 4));
        M2C_FIELD(&msg_man, int *, 4) = 0;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int mqInfo2mqID(unsigned int arg0) {
    return arg0 >> 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mqID2mqInfo(int arg0) {
    return arg0 * 2;
}
