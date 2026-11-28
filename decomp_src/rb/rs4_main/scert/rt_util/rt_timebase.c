#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_time_start(void *);
int rt_timebase_get_globaltime(int *);
void rt_timebase_get_localtime(void);
void rt_timebase_reset_globaltime(int);
int rt_timebase_restart(void);
void rt_timebase_start(void);

int rt_time_get_local();

extern int gGlobalTimeBase;
extern int gLastNetTime;
extern unsigned char gLastQueryTimeStamp;
extern unsigned char gQueryRecord;

int rt_timebase_get_globaltime(int *out)
{
    int now;
    int r = rt_time_get_local(&now);
    gGlobalTimeBase += now - gLastNetTime;
    gLastNetTime = now;
    *out = gGlobalTimeBase;
    return r;
}

void rt_timebase_get_localtime(void) {
    rt_time_get_local();
}

void *memset(void *s, int c, unsigned int n);
int rt_timebase_restart(void) {
    memset(&gQueryRecord, 0, 0x198U);
    M2C_FIELD(&gLastQueryTimeStamp, int *, 0) = 0;
    M2C_FIELD(&gLastQueryTimeStamp, int *, 4) = 0;
    gLastNetTime = 0;
    gGlobalTimeBase = 0;
    return 0;
}

void rt_timebase_reset_globaltime(int arg0) {
    gGlobalTimeBase = arg0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_timebase", rt_timebase_update_globaltime);

typedef struct { unsigned int d[100]; unsigned int count; } RtQueryRecord;
int rt_timebase_get_percentiledelay(unsigned int *out)
{
    unsigned int s[100];
    unsigned int t;
    int i, j, n;

    for (i = 0; i < 100; i++)
        s[i] = ((RtQueryRecord *)&gQueryRecord)->d[i];
    for (i = ((RtQueryRecord *)&gQueryRecord)->count - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (s[j] > s[j + 1]) {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }
    n = ((RtQueryRecord *)&gQueryRecord)->count / 20;
    if (n < 1) n = 1;
    *out = s[n];
    return 0;
}

extern unsigned int g_timebase_check_interval;
int rt_time_platform_fast_elapsed_msecs();
void rt_timebase_is_query_ready(int *ready)
{
    unsigned int el;

    *ready = 0;
    rt_time_platform_fast_elapsed_msecs(&gLastQueryTimeStamp, &el);
    if (el >= g_timebase_check_interval) {
        *ready = 1;
        rt_time_start(&gLastQueryTimeStamp);
    }
}

extern int gbQueryRecordInitialized;

void *memset(void *, int, unsigned int);
void rt_timebase_start(void)
{
    if (gbQueryRecordInitialized == 0) {
        memset(&gQueryRecord, 0, 0x198);
        gbQueryRecordInitialized = 1;
    }
    rt_time_start(&gLastQueryTimeStamp);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_timebase", rcsid_10F164);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_timebase", header_rcsid_10F1C0);
