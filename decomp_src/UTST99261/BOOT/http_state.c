/* cflags: -O1 */
#include "common.h"
#include "http_os.h"
#include "m2c_macros.h"
void *srchThreadTbl(int id);
typedef struct DumyArg {
    void (*func)(void *);
    void *arg;
} DumyArg;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", http_state);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", htlib_setheaderkey);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", htlib_getheadervalue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", htlib_strnmcat);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", htlib_getstrheadervalue);

int dumyFunc(int a, DumyArg *p)
{
    p->func(p->arg);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_create);

void OS_thread_exit(void *ret)
{
    OSThread *t = (OSThread *)(OS_thread_self() * 2);

    t->retval = ret;
    sceKernelSignalSema(t->sema, 1);
    sceKernelExitThread(0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_join);

int OS_thread_self(void)
{
    int id = sceKernelGetThreadId();
    void *t;

    if (id < 0)
        return -1;
    if (id == 1)
        return 1;
    t = srchThreadTbl(id);
    if (t == NULL)
        return -1;
    return (int)t >> 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_init(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_destroy(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_setschedparam(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_getschedparam(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_setstacksize(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_getstacksize(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_setschedparam(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_getschedparam(void) {
    return 0;
}

OSMutex *OS_thread_mutex_create(void)
{
    return MEM_malloc(0, sizeof(OSMutex));
}

void OS_thread_mutex_destroy(OSMutex *m)
{
    if (m != NULL) {
        if (*m >= 0)
            sceKernelDeleteSema(*m);
        MEM_free(0, m);
    }
}

int OS_thread_mutex_init(OSMutex *m, void *attr)
{
    int id;

    if (m == NULL)
        return 6;
    id = sceKernelCreateSema("pspBrowser-mutex", 0, 1, 1, 0);
    if (id < 0)
        return 3;
    *m = id;
    return 0;
}

int OS_thread_mutex_lock(OSMutex *m)
{
    int ret = 6;

    if (m != NULL)
        ret = sceKernelWaitSema(*m, 1, 0) < 0 ? 7 : 0;
    return ret;
}

int OS_thread_mutex_trylock(OSMutex *m)
{
    int ret = 6;

    if (m != NULL)
        ret = sceKernelPollSema(*m, 1) < 0 ? 7 : 0;
    return ret;
}

int OS_thread_mutex_unlock(OSMutex *m)
{
    SceKernelSemaInfo info;
    int r;

    if (m == NULL)
        return 6;
    info.size = sizeof(info);
    r = sceKernelReferSemaStatus(*m, &info);
    if (info.currentCount != 1)
        r = sceKernelSignalSema(*m, 1);
    if (r < 0)
        return 1;
    return 0;
}
