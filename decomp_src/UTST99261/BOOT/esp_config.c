/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK do_string();                                /* extern */
M2C_UNK __floatsidf(int);                           /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", do_bool);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_00133E78);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", do_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_defaultConfig);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_freeConfig);

#ifndef NULL
#define NULL ((void *)0)
#endif
int esp_loadConfig(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int esp_saveConfig(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_copyConfig);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_00133EB0);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_setBoolConfig);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_getBoolConfig);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_setIntConfig);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_getIntConfig);

#ifndef NULL
#define NULL ((void *)0)
#endif

void esp_setStringConfig(void) {
    do_string();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_getStringConfig);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_system_callback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_setDialogReply);

#ifndef NULL
#define NULL ((void *)0)
#endif
int esp_getMemoURLatIndex(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int esp_getMemoURLatID(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int esp_getMemoNum(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int esp_loadMemoList(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int esp_saveMemoList(void) {
    return -1;
}

void esp_freeMemoList(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CLIB_getenv(void) {
    return 0;
}

void CLIB_abort(void) {
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", monthdays);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", CLIB_printf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", CLIB_tzset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", CLIB_time);

#ifndef NULL
#define NULL ((void *)0)
#endif

void CLIB_difftime(int arg0, int arg1) {
    __floatsidf(arg0 - arg1);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", CLIB_gmtime);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", CLIB_localtime);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", CLIB_mktime);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_0013428C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_00134294);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001342F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_00134328);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_00134330);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_00134338);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_00134340);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_0013434C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_00134358);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_00134360);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_0013436C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", CLIB_strftime);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", CLIB_gettimeofday);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343F8);
