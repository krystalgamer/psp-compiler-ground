#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_mutex_platform_destroy(void *arg0);
int rt_mutex_platform_get_thread_id(int *arg0);
int rt_mutex_platform_lock(void *arg0);
int rt_mutex_platform_unlock(void *arg0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_mutex_platform", rcsid_10ECAC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_mutex_platform", header_rcsid_10ED10);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_mutex_platform", rt_mutex_platform_create);

int sceKernelDeleteSema(int semid);
int rt_mutex_platform_destroy(void *arg0) {
    int var_v1;

    var_v1 = 2;
    if (arg0 != NULL) {
        var_v1 = (sceKernelDeleteSema(M2C_FIELD(arg0, int *, 0xC)) == 0) ? 0 : 0x384;
    }
    return var_v1;
}

int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int rt_mutex_platform_lock(void *arg0) {
    int var_v1;

    var_v1 = 2;
    if (arg0 != NULL) {
        var_v1 = (sceKernelWaitSema(M2C_FIELD(arg0, int *, 0xC), 1, NULL) == 0) ? 0 : 0x384;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_mutex_platform", rt_mutex_platform_lock_no_block);

int sceKernelSignalSema(int semid, int signal);
int rt_mutex_platform_unlock(void *arg0) {
    int var_v1;

    var_v1 = 2;
    if (arg0 != NULL) {
        var_v1 = (sceKernelSignalSema(M2C_FIELD(arg0, int *, 0xC), 1) == 0) ? 0 : 0x384;
    }
    return var_v1;
}

int sceKernelGetThreadId(void);
int rt_mutex_platform_get_thread_id(int *arg0) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        *arg0 = sceKernelGetThreadId();
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_mutex_platform", rt_mutex_platform_begin_critical_section);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/psp/rt_mutex_platform", rt_mutex_platform_end_critical_section);
