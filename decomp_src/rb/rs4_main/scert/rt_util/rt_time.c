#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_time_sleep_usecs_platform();
void rt_time_elapsed(void);
void rt_time_get_date_time(void);
void rt_time_get_gmtime(void);
void rt_time_get_local(void);
void rt_time_get_time_stamp(void);
void rt_time_get_time_string(void);
void rt_time_platform_get_gmtime(void);
void rt_time_sleep_usecs(void);
void rt_time_start(void);
M2C_UNK rt_time_platform_get_time_string();         /* extern */
M2C_UNK rt_time_platform_get_time_stamp();          /* extern */
M2C_UNK rt_time_platform_get_date_time();           /* extern */
M2C_UNK rt_time_elapsed_msecs();                    /* extern */
M2C_UNK rt_time_get_msecs();                        /* extern */

void rt_time_get_local(void) {
    rt_time_get_msecs();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_get_msecs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_get_secs);

void rt_time_start(void) {
    rt_time_get_time_stamp();
}

void rt_time_get_time_stamp(void) {
    rt_time_platform_get_time_stamp();
}

void rt_time_elapsed(void) {
    rt_time_elapsed_msecs();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_elapsed_secs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_elapsed_msecs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_elapsed_usecs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_delay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_initialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_reinitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_calc_diff);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_timestamp_to_secs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_timestamp_to_msecs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_timestamp_to_usecs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_get_base_diff);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_elapsed_timestamp);

void rt_time_sleep_usecs(void) {
    rt_time_sleep_usecs_platform();
}

void rt_time_get_time_string(void) {
    rt_time_platform_get_time_string();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rcsid_10EFB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", header_rcsid_10F010);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_time", rt_time_get_time_string_ptr);

void rt_time_get_date_time(void) {
    rt_time_platform_get_date_time();
}

void rt_time_get_gmtime(void) {
    rt_time_platform_get_gmtime();
}
