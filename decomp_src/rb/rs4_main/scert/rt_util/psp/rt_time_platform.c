#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_time_platform_init(void);
int rt_time_sleep_usecs_platform();
void rt_time_platform_fast_elapsed_msecs(void);
void rt_time_platform_fast_elapsed_secs(void);
void rt_time_platform_get_gmtime(void);
M2C_UNK rt_time_elapsed_secs();                     /* extern */
M2C_UNK rt_time_platform_get_date_time();           /* extern */
M2C_UNK rt_time_elapsed_msecs();                    /* extern */

int rt_time_platform_init(void) {
    return 0;
}

int sceKernelGetSystemTime();
int sceKernelSysClock2USec();
int rt_time_platform_get_time_stamp(unsigned int *ts)
{
    int clk[2];
    if (ts == NULL) return 2;
    sceKernelGetSystemTime(clk);
    sceKernelSysClock2USec(clk, ts, ts + 1);
    return 0;
}


int sceKernelDelayThread(unsigned int delay);
int rt_time_sleep_usecs_platform(arg0)
    unsigned int arg0;
{
    sceKernelDelayThread(arg0);
    return 0;
}
typedef struct { int sec, min, hour, mday, mon, year; } RtTm;
extern int gCurTimeDate[];
RtTm *localtime(void *);
void gmtime(void *);
int rt_time_get_msecs(void *);
int rt_time_platform_update_date_time(void)
{
    int t[4];
    RtTm *tm;
    gmtime(t);
    tm = localtime(t);
    gCurTimeDate[6] = tm->year + 1900;
    gCurTimeDate[5] = tm->mon + 1;
    gCurTimeDate[4] = tm->mday;
    gCurTimeDate[3] = tm->hour;
    gCurTimeDate[2] = tm->min;
    gCurTimeDate[1] = tm->sec;
    gCurTimeDate[8] = 0;
    gCurTimeDate[0] = 0;
    if (rt_time_get_msecs(&gCurTimeDate[8]) != 0) return 0x640;
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_time_platform", rcsid_10F07C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_time_platform", header_rcsid_10F0E8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_time_platform", rt_time_platform_get_time_string);

void rt_time_platform_get_gmtime(void) {
    rt_time_platform_get_date_time();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_time_platform", rt_time_platform_get_date_time);

void rt_time_platform_fast_elapsed_secs(void) {
    rt_time_elapsed_secs();
}

void rt_time_platform_fast_elapsed_msecs(void) {
    rt_time_elapsed_msecs();
}
