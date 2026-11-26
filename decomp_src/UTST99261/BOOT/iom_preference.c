#include "common.h"
#include "m2c_macros.h"
extern void *esp_context;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_preferenceCache);

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_preferenceCookie(void) {
    int var_v1;

    var_v1 = 0;
    if ((esp_context != NULL) && (M2C_FIELD(esp_context, int *, 0x80) != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_preferenceOnline(void) {
    int var_v1;

    var_v1 = 0;
    if ((esp_context != NULL) && (M2C_FIELD(esp_context, int *, 0x9C) != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_preferenceHttpVersion(void) {
    int var_v1;

    var_v1 = 0xA;
    if (esp_context != NULL) {
        var_v1 = 0xB;
        if (M2C_FIELD(esp_context, int *, 0x94) == 0) {
            var_v1 = 0xA;
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_preferenceUserAgent);

#ifndef NULL
#define NULL ((void *)0)
#endif

signed char *iom_preferenceUnitId(void) {
    signed char *var_v1;

    var_v1 = NULL;
    if ((esp_context != NULL) && ((var_v1 = M2C_FIELD(esp_context, signed char **, 0xB0), (var_v1 == NULL)) || (*var_v1 == 0))) {
        var_v1 = NULL;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_preferenceProxy);

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_preferenceDownloadStop(void) {
    int var_v1;

    var_v1 = 0;
    if ((esp_context != NULL) && (M2C_FIELD(esp_context, int *, 0xD8) != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_malloc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_mfree);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_getheadervalue);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139ECC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139ED0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139F08);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_str2time);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139FA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139FD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139FF4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_time2str);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_diffexpire);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_rmdir);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_strnmcat);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A02C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A034);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A03C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A044);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A050);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A058);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A060);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A064);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A06C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A074);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A078);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A084);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A088);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A08C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A098);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A09C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A108);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A110);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A118);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A120);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A128);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A130);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A13C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A144);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A14C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A154);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A15C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A164);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A16C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A174);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A180);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A188);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A18C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A198);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A208);
