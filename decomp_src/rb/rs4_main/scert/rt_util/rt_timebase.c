#include "common.h"
#include "rb/rs4_main/scert/scert.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_timebase", rt_timebase_get_globaltime);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_timebase", rt_timebase_get_percentiledelay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_timebase", rt_timebase_is_query_ready);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_timebase", rt_timebase_start);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_timebase", rcsid_10F164);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_timebase", header_rcsid_10F1C0);
