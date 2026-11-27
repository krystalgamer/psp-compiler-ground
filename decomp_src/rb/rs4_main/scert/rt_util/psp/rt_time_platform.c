#include "common.h"
#include "rb/rs4_main/scert/scert.h"

int rt_time_platform_init(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_time_platform", rt_time_platform_get_time_stamp);


int sceKernelDelayThread(unsigned int delay);
int rt_time_sleep_usecs_platform(arg0)
    unsigned int arg0;
{
    sceKernelDelayThread(arg0);
    return 0;
}
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_time_platform", rt_time_platform_update_date_time);

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
