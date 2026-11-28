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

int sceKernelCreateSema();
int rt_mutex_platform_create(int *m)
{
    int s;
    if (m == NULL) return 2;
    m[4] = 0;
    s = sceKernelCreateSema("rt_mutex_platform_create_sema", 0, 1, 1, 0);
    if (s < 0) return 900;
    m[3] = s;
    return 0;
}

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

int rt_mutex_platform_lock_no_block(unsigned char *m, unsigned char *got)
{
    unsigned char t;

    if (m == NULL) return 2;
    t = m[0];
    if (t == 1) {
        if (got == NULL) return 2;
        *got = 0;
        if (sceKernelPollSema(*(int *)(m + 0xC), 1) == 0) *got = t;
        return 0;
    }
    return 2;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelCpuSuspendIntr();                      /* extern */
extern int goldIntr;

int rt_mutex_platform_begin_critical_section(void) {
    goldIntr = sceKernelCpuSuspendIntr();
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK sceKernelCpuResumeIntr(int);                /* extern */

int rt_mutex_platform_end_critical_section(void) {
    sceKernelCpuResumeIntr(goldIntr);
    return 0;
}
