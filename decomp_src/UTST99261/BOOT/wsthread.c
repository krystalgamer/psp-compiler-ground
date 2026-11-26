#include "common.h"

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", DeleteMbxMan);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", mqInfo2mqID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", mqID2mqInfo);
