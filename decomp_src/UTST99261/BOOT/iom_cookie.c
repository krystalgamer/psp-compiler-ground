/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK cookieFile_init();                          /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_cookieFile_init(void) {
    cookieFile_init();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", cookieFile_fstab);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", cookieFile_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", cookieFile_open);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", cookieFile_close);

#ifndef NULL
#define NULL ((void *)0)
#endif
int cookieFile_pos(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cookieFile_len(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cookieFile_seek(void *arg0, int arg1) {
    int var_v1;

    var_v1 = -1;
    if (M2C_FIELD(arg0, int *, 8) >= arg1) {
        M2C_FIELD(arg0, int *, 0x10) = arg1;
        var_v1 = arg1;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", cookieFile_getc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", cookieFile_read);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", cookieFile_write);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_loadCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_saveCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_updateCookie);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C60);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_addCookie);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139CA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139CA8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_getCookieData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_deleteCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_freeCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_deleteDomainCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_domainCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_subdomainCookie);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139CB4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", esp_iomThread);
