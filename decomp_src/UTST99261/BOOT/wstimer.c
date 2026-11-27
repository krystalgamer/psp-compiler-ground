/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct TimeSpec {
    int sec;
    int nsec;
} TimeSpec;
typedef struct SemaInfo {
    int size;
    char name[32];
    unsigned int attr;
    int initCount;
    int currentCount;
    int maxCount;
    int numWaitThreads;
} SemaInfo;
extern int thread_id_timer;
int sceKernelCancelAlarm(int id);
int sceKernelGetSystemTime(void *clk);
int sceKernelSysClock2USec(void *clk, int *sec, int *usec);
int sceKernelReferSemaStatus(int id, SemaInfo *info);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *opt);
int sceKernelDeleteSema(int id);
int sceKernelSetAlarm(unsigned int clock, int (*handler)(void *), void *arg);
int clock_gettime();
int chkTimer(int id);
int timer_handler(void *arg);
extern void **sys_timer;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK OS_thread_join(int, M2C_UNK);               /* extern */
M2C_UNK OS_thread_mutex_destroy(int);               /* extern */
M2C_UNK OS_thread_mutex_lock(int);                  /* extern */
M2C_UNK OS_thread_mutex_unlock(int);                /* extern */

extern int sema_id_timer;



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", timer_create);

int timer_delete(int id)
{
    if (id >= 0) {
        if (sceKernelCancelAlarm(id) < 0)
            return -1;
    }
    return 0;
}

int clock_gettime(TimeSpec *ts)
{
    int clk[2];
    int sec, usec;

    sceKernelGetSystemTime(clk);
    sceKernelSysClock2USec(clk, &sec, &usec);
    ts->sec = sec;
    ts->nsec = usec * 1000;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", esp_timerThread);

int timer_handler(void *arg)
{
    SemaInfo info;

    if (thread_id_timer > 0) {
        info.size = sizeof(info);
        sceKernelReferSemaStatus(sema_id_timer, &info);
        if (info.currentCount != 1)
            sceKernelSignalSema(sema_id_timer, 1);
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void addTimer(void *arg0) {
    M2C_FIELD(arg0, int *, 0x18) = (int) M2C_FIELD(*sys_timer, int *, 0x18);
    M2C_FIELD(*sys_timer, void **, 0x18) = arg0;
}

void delTimer(int id)
{
    void *prev = *sys_timer;
    void *t;

    for (t = M2C_FIELD(prev, void **, 0x18); t != NULL; t = M2C_FIELD(t, void **, 0x18)) {
        if (M2C_FIELD(t, int *, 0) == id) {
            M2C_FIELD(prev, void **, 0x18) = M2C_FIELD(t, void **, 0x18);
            MEM_free(0, M2C_FIELD(t, void **, 0xC));
            MEM_free(0, t);
            return;
        }
        prev = t;
    }
}

int chkTimer(int id)
{
    void *t;

    if (*sys_timer == NULL)
        return -1;
    for (t = M2C_FIELD(*sys_timer, void **, 0x18); t != NULL; t = M2C_FIELD(t, void **, 0x18)) {
        if (M2C_FIELD(t, int *, 0) == id)
            return 0;
    }
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_timer_init);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelSignalSema(int semid, int signal);

void OS_timer_destroy(void) {
    void *temp_a1;
    void *temp_s1;
    void *var_s0;

    if (sys_timer != NULL) {
        OS_thread_mutex_lock(M2C_FIELD(sys_timer, int *, 8));
        var_s0 = M2C_FIELD(sys_timer, void **, 0);
        if (var_s0 != NULL) {
            do {
                temp_a1 = M2C_FIELD(var_s0, void **, 0xC);
                temp_s1 = M2C_FIELD(var_s0, void **, 0x18);
                if (temp_a1 != NULL) {
                    MEM_free(0, temp_a1);
                }
                MEM_free(0, var_s0);
                var_s0 = temp_s1;
            } while (temp_s1 != NULL);
        }
        M2C_FIELD(sys_timer, void **, 0) = NULL;
        sceKernelSignalSema(sema_id_timer, 1);
        OS_thread_mutex_unlock(M2C_FIELD(sys_timer, int *, 8));
        OS_thread_join(M2C_FIELD(sys_timer, int *, 4), 0);
        timer_delete(M2C_FIELD(sys_timer, int *, 0xC));
        OS_thread_mutex_destroy(M2C_FIELD(sys_timer, int *, 8));
        MEM_free(0, sys_timer);
        sys_timer = NULL;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_timer_set);

int OS_timer_start(int id)
{
    if (sys_timer == NULL)
        return -1;
    if (chkTimer(id) < 0)
        return -1;
    OS_thread_mutex_lock((int)sys_timer[2]);
    M2C_FIELD(id * 2, short *, 6) = 1;
    OS_thread_mutex_unlock((int)sys_timer[2]);
    return 0;
}

int OS_timer_stop(int id)
{
    if (sys_timer == NULL)
        return -1;
    if (chkTimer(id) < 0)
        return -1;
    OS_thread_mutex_lock((int)sys_timer[2]);
    M2C_FIELD(id * 2, short *, 6) = 0;
    OS_thread_mutex_unlock((int)sys_timer[2]);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void OS_timer_clear(int arg0) {
    OS_thread_mutex_lock(M2C_FIELD(sys_timer, int *, 8));
    delTimer(arg0);
    OS_thread_mutex_unlock(M2C_FIELD(sys_timer, int *, 8));
}

int OS_clock_gettime(int clk, TimeSpec *ts)
{
    TimeSpec t;

    if (ts == NULL)
        return -1;
    if (clock_gettime(&t) != 0)
        return -1;
    *ts = t;
    return 0;
}
