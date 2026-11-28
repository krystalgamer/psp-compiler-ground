#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_time_delay(unsigned int);
int rt_time_elapsed(void *, unsigned int *);
int rt_time_elapsed_msecs(void *, unsigned int *);
int rt_time_elapsed_secs(void *, unsigned int *);
int rt_time_elapsed_timestamp(void *, void *);
int rt_time_elapsed_usecs(void *, unsigned int *);
int rt_time_get_base_diff(unsigned int *);
void rt_time_get_date_time(void);
void rt_time_get_gmtime(void);
void rt_time_get_local(void);
int rt_time_get_msecs();
int rt_time_get_secs(unsigned int *);
int rt_time_get_time_stamp(void *);
int rt_time_get_time_string(char *);
char * rt_time_get_time_string_ptr(void);
int rt_time_initialize(void);
int rt_time_platform_get_date_time();
void rt_time_platform_get_gmtime(void);
int rt_time_platform_get_time_stamp(unsigned int *);
int rt_time_platform_get_time_string(char *);
int rt_time_platform_init(void);
int rt_time_reinitialize(void);
void rt_time_sleep_usecs(void);
int rt_time_start(void *);
int rt_time_timestamp_to_msecs(unsigned int *, unsigned int *);
int rt_time_timestamp_to_secs(unsigned int *, unsigned int *);
int rt_time_timestamp_to_usecs(unsigned int *, unsigned int *);
int rt_time_sleep_usecs_platform();

void rt_time_get_local(void) {
    rt_time_get_msecs();
}

int rt_time_get_msecs(unsigned int *ms)
{
    unsigned int ts[2];
    int r;
    if (ms == NULL) return 2;
    r = rt_time_get_base_diff(ts);
    if (r != 0) return r;
    return rt_time_timestamp_to_msecs(ts, ms);
}

int rt_time_get_secs(unsigned int *s)
{
    unsigned int ts[2];
    int r;
    if (s == NULL) return 2;
    r = rt_time_get_base_diff(ts);
    if (r != 0) return r;
    return rt_time_timestamp_to_secs(ts, s);
}

int rt_time_start(void *t) {
    return rt_time_get_time_stamp(t);
}

int rt_time_get_time_stamp(void *t) {
    return rt_time_platform_get_time_stamp(t);
}

int rt_time_elapsed(void *t, unsigned int *out) {
    return rt_time_elapsed_msecs(t, out);
}

int rt_time_elapsed_secs(void *start, unsigned int *out)
{
    unsigned int ts[2];
    int r;
    if (start == NULL) return 2;
    if (out == NULL) return 2;
    r = rt_time_elapsed_timestamp(start, ts);
    if (r != 0) return r;
    return rt_time_timestamp_to_secs(ts, out);
}

int rt_time_elapsed_msecs(void *start, unsigned int *out)
{
    unsigned int ts[2];
    int r;
    if (start == NULL) return 2;
    if (out == NULL) return 2;
    r = rt_time_elapsed_timestamp(start, ts);
    if (r != 0) return r;
    return rt_time_timestamp_to_msecs(ts, out);
}

int rt_time_elapsed_usecs(void *start, unsigned int *out)
{
    unsigned int ts[2];
    int r;
    if (start == NULL) return 2;
    if (out == NULL) return 2;
    r = rt_time_elapsed_timestamp(start, ts);
    if (r != 0) return r;
    return rt_time_timestamp_to_usecs(ts, out);
}

extern unsigned char gbBaseTimeInitialized;
extern int gBaseTimeStamp[];

int rt_time_delay(unsigned int ms)
{
    int t[4];
    unsigned int el;
    int r;
    el = 0;
    r = rt_time_start(t);
    if (r != 0) return r;
    while (el < ms) {
        r = rt_time_elapsed(t, &el);
        if (r != 0) return r;
    }
    return 0;
}

int rt_time_initialize(void)
{
    int r;
    if (gbBaseTimeInitialized == 1) return 0x640;
    rt_time_platform_init();
    r = rt_time_get_time_stamp(gBaseTimeStamp);
    if (r != 0) return r;
    gbBaseTimeInitialized = 1;
    return 0;
}

int rt_time_reinitialize(void)
{
    int r;
    if (gbBaseTimeInitialized == 0) return 1;
    r = rt_time_get_time_stamp(gBaseTimeStamp);
    if (r != 0) return r;
    gbBaseTimeInitialized = 1;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_calc_diff);

int rt_time_timestamp_to_secs(unsigned int *ts, unsigned int *secs)
{
    if (ts == NULL) return 2;
    if (secs == NULL) return 2;
    *secs = ts[0];
    *secs += ts[1] / 1000000;
    return 0;
}

int rt_time_timestamp_to_msecs(unsigned int *ts, unsigned int *ms)
{
    if (ts == NULL) return 2;
    if (ms == NULL) return 2;
    if (ts[0] > 0x418935) return 0x641;
    *ms = ts[0] * 1000 + ts[1] / 1000;
    return 0;
}

int rt_time_timestamp_to_usecs(unsigned int *ts, unsigned int *usecs)
{
    if (ts == NULL) return 2;
    if (usecs == NULL) return 2;
    if (ts[0] >= 0x10C5) return 0x641;
    *usecs = ts[0] * 1000000 + ts[1];
    return 0;
}

int rt_time_get_base_diff(unsigned int *out)
{
    int r;
    if (out == NULL) return 2;
    if (gbBaseTimeInitialized == 0) {
        r = rt_time_initialize();
        if (r != 0) return r;
    }
    return rt_time_elapsed_timestamp(gBaseTimeStamp, out);
}

int rt_time_calc_diff();
int rt_time_elapsed_timestamp(void *start, void *out)
{
    unsigned int now[2];
    int r;
    if (start == NULL) return 2;
    if (out == NULL) return 2;
    r = rt_time_get_time_stamp(now);
    if (r != 0) return r;
    return rt_time_calc_diff(start, now, out);
}

void rt_time_sleep_usecs(void) {
    rt_time_sleep_usecs_platform();
}

int rt_time_get_time_string(char *b) {
    return rt_time_platform_get_time_string(b);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rcsid_10EFB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", header_rcsid_10F010);

extern int D_00135BC4[];
char *strcpy(char *, const char *);
char *rt_time_get_time_string_ptr(void)
{
    if (rt_time_get_time_string((char *)D_00135BC4) != 0) strcpy((char *)D_00135BC4, "00:00:00");
    return (char *)D_00135BC4;
}

void rt_time_get_date_time(void) {
    rt_time_platform_get_date_time();
}

void rt_time_get_gmtime(void) {
    rt_time_platform_get_gmtime();
}
