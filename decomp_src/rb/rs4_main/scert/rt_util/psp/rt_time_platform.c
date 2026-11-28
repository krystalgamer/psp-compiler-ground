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

typedef struct { unsigned int ms, sec, min, hour, mday, mon, year, wday, stamp; } RtTimeDate;
extern unsigned char gbTimeDateSet;

int sprintf(char *, const char *, ...);
int rt_time_platform_get_time_string(char *buf)
{
    RtTimeDate t;
    unsigned int now;

    if (buf == NULL) return 2;
    if (!gbTimeDateSet) {
        if (rt_time_platform_update_date_time() != 0) return 0x640;
        gbTimeDateSet = 1;
    }
    t = *(RtTimeDate *)gCurTimeDate;
    if (rt_time_get_msecs(&now) != 0) return 0x640;
    t.ms += now - ((RtTimeDate *)gCurTimeDate)->stamp;
    t.sec += t.ms / 1000;
    t.ms %= 1000;
    t.min += t.sec / 60;
    t.sec %= 60;
    t.hour += t.min / 60;
    t.min %= 60;
    t.hour %= 24;
    sprintf(buf, "%02d:%02d:%02d", t.hour, t.min, t.sec);
    return 0;
}

void rt_time_platform_get_gmtime(void) {
    rt_time_platform_get_date_time();
}

int rt_time_platform_get_date_time(RtTimeDate *out)
{
    RtTimeDate t;
    unsigned int now;

    if (out == NULL) return 2;
    if (!gbTimeDateSet) {
        if (rt_time_platform_update_date_time() != 0) return 0x640;
        gbTimeDateSet = 1;
    }
    t = *(RtTimeDate *)gCurTimeDate;
    if (rt_time_get_msecs(&now) != 0) return 0x640;
    t.ms += now - ((RtTimeDate *)gCurTimeDate)->stamp;
    t.sec += t.ms / 1000;
    t.ms %= 1000;
    t.min += t.sec / 60;
    t.sec %= 60;
    t.hour += t.min / 60;
    t.min %= 60;
    if (t.hour >= 24) {
        if (rt_time_platform_update_date_time() != 0) return 0x640;
        t = *(RtTimeDate *)gCurTimeDate;
    }
    out->year = t.year;
    out->mon = t.mon;
    out->mday = t.mday;
    out->hour = t.hour;
    out->min = t.min;
    out->sec = t.sec;
    out->ms = t.ms;
    out->stamp = t.stamp;
    return 0;
}

void rt_time_platform_fast_elapsed_secs(void) {
    rt_time_elapsed_secs();
}

void rt_time_platform_fast_elapsed_msecs(void) {
    rt_time_elapsed_msecs();
}
