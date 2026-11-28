/* cflags: -O1 */
#include "common.h"
#include <stdarg.h>
#include "psptypes.h"
#include "m2c_macros.h"
#include "dom_clib.h"
#define CFS(c, o) (*(char **)((char *)(c) + (o)))
extern ClibTm D_0025B580;
extern int D_001F44DC;
extern char D_0025B17C[];
extern int timezone;
extern int dylight;
int *CLIB_gmtime(int *t);
extern char D_00133E78[];
void MEM_free(M2C_UNK, int);                     /* extern */

M2C_UNK do_string();                                /* extern */
M2C_UNK __floatsidf(int);                           /* extern */


int strcasecmp(const char *, const char *);
void *memset(void *, int, unsigned int);
void *MEM_malloc(void *, unsigned int size);
char *strcpy(char *, const char *);
unsigned int strlen(const char *);
int sceKernelCreateSema(const char *, unsigned int, int, int, void *);
int sceKernelWaitSema(int, int, unsigned int *);
int write(int, const void *, unsigned int);
int sceKernelSignalSema(int, int);
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

int esp_defaultConfig(int *cfg) {
    memset(cfg, 0, 0x70);
    cfg[0] = 0x40000;
    cfg[1] = 1;
    cfg[3] = 0;
    cfg[5] = 0;
    cfg[6] = 1;
    cfg[9] = 3;
    cfg[11] = 0x1F90;
    cfg[22] = 0;
    CFS(cfg, 0x40) = MEM_malloc(0, 1);
    if (CFS(cfg, 0x40) == NULL) {
        return -1;
    }
    CFS(cfg, 0x40)[0] = 0;
    CFS(cfg, 0x44) = MEM_malloc(0, 1);
    if (CFS(cfg, 0x44) == NULL) {
        return -1;
    }
    CFS(cfg, 0x44)[0] = 0;
    CFS(cfg, 0x28) = MEM_malloc(0, 1);
    if (CFS(cfg, 0x28) == NULL) {
        return -1;
    }
    CFS(cfg, 0x28)[0] = 0;
    CFS(cfg, 0x30) = MEM_malloc(0, 0x15);
    if (CFS(cfg, 0x30) == NULL) {
        return -1;
    }
    strcpy(CFS(cfg, 0x30), "SCE PSP BROWSER 0100");
    CFS(cfg, 0x34) = MEM_malloc(0, 1);
    if (CFS(cfg, 0x34) == NULL) {
        return -1;
    }
    CFS(cfg, 0x34)[0] = 0;
    CFS(cfg, 0x38) = MEM_malloc(0, 6);
    if (CFS(cfg, 0x38) == NULL) {
        return -1;
    }
    strcpy(CFS(cfg, 0x38), "white");
    cfg[15] = 0x40;
    cfg[7] = 1;
    cfg[8] = 1;
    cfg[4] = 3;
    cfg[18] = 0;
    cfg[19] = 0;
    cfg[27] = 0;
    return 0;
}

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

int esp_copyConfig(char **dst, char **src) {
    *(EspCfgBlk *)dst = *(EspCfgBlk *)src;
    dst[16] = NULL;
    dst[17] = NULL;
    dst[10] = NULL;
    dst[12] = NULL;
    dst[13] = NULL;
    dst[14] = NULL;
    if (src[16] != NULL) {
        dst[16] = MEM_malloc(0, strlen(src[16]) + 1);
        if (dst[16] == NULL) {
            return -1;
        }
        strcpy(dst[16], src[16]);
    }
    if (src[17] != NULL) {
        dst[17] = MEM_malloc(0, strlen(src[17]) + 1);
        if (dst[17] == NULL) {
            return -1;
        }
        strcpy(dst[17], src[17]);
    }
    if (src[10] != NULL) {
        dst[10] = MEM_malloc(0, strlen(src[10]) + 1);
        if (dst[10] == NULL) {
            return -1;
        }
        strcpy(dst[10], src[10]);
    }
    if (src[12] != NULL) {
        dst[12] = MEM_malloc(0, strlen(src[12]) + 1);
        if (dst[12] == NULL) {
            return -1;
        }
        strcpy(dst[12], src[12]);
    }
    if (src[13] != NULL) {
        dst[13] = MEM_malloc(0, strlen(src[13]) + 1);
        if (dst[13] == NULL) {
            return -1;
        }
        strcpy(dst[13], src[13]);
    }
    if (src[14] != NULL) {
        dst[14] = MEM_malloc(0, strlen(src[14]) + 1);
        if (dst[14] == NULL) {
            return -1;
        }
        strcpy(dst[14], src[14]);
    }
    return 0;
}


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

int CLIB_printf(const char *fmt, ...) {
    va_list ap;
    int n;

    if (D_001F44DC < 0) {
        D_001F44DC = sceKernelCreateSema("pspBrowser-printf", 0, 1, 1, 0);
    }
    sceKernelWaitSema(D_001F44DC, 1, 0);
    va_start(ap, fmt);
    n = vsnprintf(D_0025B17C, 0x400, fmt, ap);
    write(0, D_0025B17C, n);
    sceKernelSignalSema(D_001F44DC, 1);
    return n;
}

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

int *CLIB_gmtime(int *t) {
    ScePspDateTime dt;
    int yday;
    int i;

    yday = 0;
    if (sceRtcSetTime_t(&dt, *t) < 0) {
        return NULL;
    }
    D_0025B580.isdst = dylight;
    D_0025B580.sec = dt.second;
    D_0025B580.min = dt.minute;
    D_0025B580.hour = dt.hour;
    D_0025B580.mday = dt.day;
    D_0025B580.mon = dt.month;
    D_0025B580.year = dt.year;
    D_0025B580.wday = sceRtcGetDayOfWeek(dt.year, dt.month, dt.day);
    for (i = 1; i < D_0025B580.mon; i++) {
        yday += sceRtcGetDaysInMonth(D_0025B580.year, i);
    }
    yday += D_0025B580.mday;
    D_0025B580.yday = yday - 1;
    if (D_0025B580.mon > 0) {
        D_0025B580.mon--;
    }
    if (D_0025B580.year > 1900) {
        D_0025B580.year -= 1900;
    }
    return (int *)&D_0025B580;
}

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

static inline int clib_setYear(ScePspDateTime *dt, int v)
{
    if (!((unsigned int)(v - 1) < 9999))
        return 0x800001FF;
    dt->year = v;
    return 0;
}
static inline int clib_setMonth(ScePspDateTime *dt, int v)
{
    if (!((unsigned int)(v - 1) < 12))
        return 0x800001FF;
    dt->month = v;
    return 0;
}
static inline int clib_setDay(ScePspDateTime *dt, int v)
{
    if (!((unsigned int)(v - 1) < 31))
        return 0x800001FF;
    dt->day = v;
    return 0;
}
static inline int clib_setHour(ScePspDateTime *dt, int v)
{
    if (!((unsigned int)v < 24))
        return 0x800001FF;
    dt->hour = v;
    return 0;
}
static inline int clib_setMinute(ScePspDateTime *dt, int v)
{
    if (!((unsigned int)v < 60))
        return 0x800001FF;
    dt->minute = v;
    return 0;
}
static inline int clib_setSecond(ScePspDateTime *dt, int v)
{
    if (!((unsigned int)v < 60))
        return 0x800001FF;
    dt->second = v;
    return 0;
}
int CLIB_mktime(int *tm)
{
    ScePspDateTime dt;
    int t;

    memset(&dt, 0, sizeof(dt));
    if (clib_setYear(&dt, tm[5] + 1900) < 0)
        return 0;
    if (clib_setMonth(&dt, tm[4] + 1) < 0)
        return 0;
    if (clib_setDay(&dt, tm[3]) < 0)
        return 0;
    if (clib_setHour(&dt, tm[2]) < 0)
        return 0;
    if (clib_setMinute(&dt, tm[1]) < 0)
        return 0;
    if (clib_setSecond(&dt, tm[0]) < 0)
        return 0;
    dt.microsecond = 0;
    if (sceRtcGetTime_t(&dt, &t) < 0)
        return 0;
    if (t - timezone < 0)
        return 0;
    return t - timezone;
}

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
