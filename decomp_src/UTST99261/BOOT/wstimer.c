#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", timer_create);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", timer_delete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", clock_gettime);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", esp_timerThread);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", timer_handler);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", addTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", delTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", chkTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_timer_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_timer_destroy);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_timer_set);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_timer_start);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_timer_stop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_timer_clear);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_clock_gettime);
