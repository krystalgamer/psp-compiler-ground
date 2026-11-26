/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern int timezone;
extern int dylight;
typedef struct ClibClock {
    short year;
    short month;
    short day;
    short hour;
    short minute;
    short second;
    int usec;
} ClibClock;
int *CLIB_gmtime(int *t);
extern char D_00133E78[];
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */

M2C_UNK do_string();                                /* extern */
M2C_UNK __floatsidf(int);                           /* extern */


int do_bool(int *cfg, int id, char *str) {
    int val;

    val = 0;
    if (strcasecmp(str, D_00133E78) == 0) {
        val = 1;
    }
    switch (id) {
    case 0:
        cfg[1] = val;
        break;
    case 1:
        cfg[6] = val;
        break;
    case 2:
        cfg[5] = val;
        break;
    case 3:
        cfg[22] = val == 0;
        break;
    default:
        return -1;
    }
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_00133E78);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", do_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", esp_defaultConfig);

#ifndef NULL
#define NULL ((void *)0)
#endif

void esp_freeConfig(void *arg0) {
    MEM_free(0, M2C_FIELD(arg0, int *, 0x40));
    MEM_free(0, M2C_FIELD(arg0, int *, 0x44));
    MEM_free(0, M2C_FIELD(arg0, int *, 0x28));
    MEM_free(0, M2C_FIELD(arg0, int *, 0x30));
    MEM_free(0, M2C_FIELD(arg0, int *, 0x34));
    MEM_free(0, M2C_FIELD(arg0, int *, 0x38));
}

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

int esp_setBoolConfig(int *cfg, int id, int val) {
    return do_bool(cfg, id, val ? D_00133E78 : "false");
}

int esp_getBoolConfig(int *cfg, int id, int *out) {
    switch (id) {
    case 0:
        *out = cfg[1];
        break;
    case 1:
        *out = cfg[6];
        break;
    case 2:
        *out = cfg[5];
        break;
    case 3:
        *out = cfg[22] == 0;
        break;
    default:
        return -1;
    }
    return 0;
}

int esp_setIntConfig(int *cfg, int id, int val) {
    switch (id) {
    case 0x1000:
        cfg[0] = val;
        break;
    case 0x1001:
        cfg[3] = val;
        break;
    case 0x1002:
        cfg[9] = val;
        break;
    case 0x1003:
        cfg[11] = val;
        break;
    case 0x1004:
        cfg[8] = val;
        break;
    case 0x1005:
        cfg[15] = val;
        break;
    default:
        return -1;
    }
    return 0;
}

int esp_getIntConfig(int *cfg, int id, int *out) {
    switch (id) {
    case 0x1000:
        *out = cfg[0];
        break;
    case 0x1001:
        *out = cfg[3];
        break;
    case 0x1002:
        *out = cfg[9];
        break;
    case 0x1003:
        *out = cfg[11];
        break;
    case 0x1004:
        *out = cfg[8];
        break;
    case 0x1005:
        *out = cfg[15];
        break;
    default:
        return -1;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void esp_setStringConfig(void) {
    do_string();
}

int esp_getStringConfig(int *cfg, int id, int *out) {
    switch (id) {
    case 0x2000:
        *out = cfg[16];
        break;
    case 0x2001:
        *out = cfg[17];
        break;
    case 0x2002:
        *out = cfg[10];
        break;
    case 0x2003:
        *out = cfg[12];
        break;
    case 0x2004:
        *out = cfg[13];
        break;
    case 0x2005:
        *out = cfg[14];
        break;
    default:
        return -1;
    }
    return 0;
}

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

void CLIB_tzset(void) {
    ClibClock clk;
    int utc;
    int local;

    if (sceRtcGetCurrentClock(&clk, 0) < 0) {
        return;
    }
    if (sceRtcGetTime_t(&clk, &utc) < 0) {
        return;
    }
    if (sceRtcGetCurrentClockLocalTime(&clk) < 0) {
        return;
    }
    if (sceRtcGetTime_t(&clk, &local) < 0) {
        return;
    }
    timezone = local - utc;
    dylight = 0;
}

int CLIB_time(int *out) {
    ClibClock clk;
    int t;

    if (sceRtcGetCurrentClock(&clk, 0) < 0) {
        return 0;
    }
    if (sceRtcGetTime_t(&clk, &t) < 0) {
        return 0;
    }
    if (t < 0) {
        t = 0;
    }
    if (out != NULL) {
        *out = t;
    }
    return t;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CLIB_difftime(int arg0, int arg1) {
    __floatsidf(arg0 - arg1);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", CLIB_gmtime);

int *CLIB_localtime(int *t) {
    int lt;
    int *tm;

    lt = *t + timezone;
    if (lt < 0) {
        lt = 0;
    }
    tm = CLIB_gmtime(&lt);
    tm[8] = dylight;
    return tm;
}

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

int CLIB_gettimeofday(int *tv, int *tz) {
    ClibClock clk;
    int t;

    if (sceRtcGetCurrentClock(&clk, 0) < 0) {
        return 0;
    }
    if (sceRtcGetTime_t(&clk, &t) < 0) {
        return 0;
    }
    tv[0] = t;
    tv[1] = clk.usec;
    if (tz != NULL) {
        tz[0] = timezone / 60;
        tz[1] = dylight;
    }
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_config", D_001343F8);
