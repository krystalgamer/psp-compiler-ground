/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern int D_00584CD4;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", lo_halt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", esp_loThread);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", initBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", addBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", delBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", delBoxLastList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", divideBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", initUrlList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", searchUrlList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", addUrlList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", copyBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", lo_fullUrl);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", lo_getActiveFrameBodybox);

#ifndef NULL
#define NULL ((void *)0)
#endif

void initSessionNumber(void) {
    D_00584CD4 = 0x08000001;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", getSessionNumber);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", setUiGlobal_window);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", setUiGlobal_browser);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", setLoGlobal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", getRNDSEM);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", getJSSEM);
