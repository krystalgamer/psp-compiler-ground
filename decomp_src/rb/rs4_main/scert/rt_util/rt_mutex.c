#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
typedef struct { unsigned char state; char pad[3]; int count; int owner; } RtMutexU;
int rt_mutex_platform_get_thread_id();

int rt_mutex_platform_create();
int rt_mutex_create(char *m)
{
    int r;
    if (m == NULL) return 2;
    m[0] = 0;
    *(int *)(m + 4) = 0;
    *(int *)(m + 8) = 0;
    r = rt_mutex_platform_create(m);
    if (r != 0) return r;
    m[0] = 1;
    return 0;
}

int rt_mutex_platform_destroy();
int rt_mutex_destroy(unsigned char *m)
{
    int r;
    if (m == NULL) return 2;
    if (m[0] != 1) return 2;
    r = rt_mutex_platform_destroy(m);
    if (r != 0) return r;
    m[0] = 0;
    return 0;
}

int rt_mutex_platform_lock();
int rt_mutex_lock(RtMutexU *m, int *count)
{
    int ret;
    int tid;

    if (m == NULL) return 2;
    if (m->state != 1) return 2;
    ret = rt_mutex_platform_get_thread_id(&tid);
    if (ret != 0) return ret;
    if (m->count != 0 && tid == m->owner) {
        m->count++;
    } else {
        ret = rt_mutex_platform_lock(m);
        if (ret != 0) return ret;
        ret = rt_mutex_platform_get_thread_id(&m->owner);
        if (ret != 0) return ret;
        m->count++;
    }
    if (count != NULL) *count = m->count;
    return 0;
}

int rt_mutex_platform_lock_no_block();
int rt_mutex_lock_no_block(RtMutexU *m, int *count)
{
    int ret;
    unsigned char got;
    int tid;

    got = 0;
    if (m == NULL) return 2;
    if (m->state != 1) return 2;
    if (count == NULL) return 2;
    *count = 0;
    ret = rt_mutex_platform_get_thread_id(&tid);
    if (ret != 0) return ret;
    if (m->count != 0 && tid == m->owner) {
        m->count++;
        *count = m->count;
    } else {
        ret = rt_mutex_platform_lock_no_block(m, &got);
        if (ret != 0) return ret;
        if (got == 1) {
            ret = rt_mutex_platform_get_thread_id(&m->owner);
            if (ret != 0) return ret;
            m->count++;
            *count = m->count;
        }
    }
    return 0;
}

int rt_mutex_platform_get_thread_id();
int rt_mutex_platform_unlock();
int rt_mutex_unlock(RtMutexU *m, int *count)
{
    int ret;
    int tid;

    if (m == NULL) return 2;
    if (m->state != 1) return 2;
    ret = rt_mutex_platform_get_thread_id(&tid);
    if (ret != 0) return ret;
    if (tid != m->owner) return 0x385;
    if (m->count == 0) return 0x386;
    m->count--;
    if (count != NULL) *count = m->count;
    if (m->count == 0) {
        m->owner = 0;
        ret = rt_mutex_platform_unlock(m);
        if (ret != 0) return ret;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK rt_mutex_platform_begin_critical_section(); /* extern */

void rt_mutex_begin_critical_section(void) {
    rt_mutex_platform_begin_critical_section();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void rt_mutex_end_critical_section(void) {
    rt_mutex_platform_begin_critical_section();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mutex", rcsid_10EBFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mutex", header_rcsid_10EC54);
