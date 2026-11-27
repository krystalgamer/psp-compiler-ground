/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int sceKernelWaitSema(int id, int signal, void *timeout);
int OS_mq_send(int a, int b, int n, int c);
void OS_thread_exit(int r);
void *MEM_calloc(int heap, unsigned int size);
void *OS_thread_mutex_create(void);
int OS_thread_mutex_init(void *m, int a);
int OS_thread_create(void *id, int a, void *fn, int b);
int esp_timerThread(void);
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



int timer_create(int *out)
{
    int sema = sceKernelCreateSema("pspBrowser-timer", 0, 0, 1, 0);
    int a;

    if (sema < 0)
        return -1;
    sema_id_timer = sema;
    a = sceKernelSetAlarm(10000, timer_handler, 0);
    if (a < 0) {
        sceKernelDeleteSema(sema_id_timer);
        return -1;
    }
    *out = a;
    return 0;
}

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

int esp_timerThread(void)
{
    TimeSpec ts;
    int elapsed;
    int ds, dn;
    char *t;
    void **p;
    void **q;

    for (;;) {
        if (sceKernelWaitSema(sema_id_timer, 1, 0) < 0)
            break;
        p = sys_timer;
        p[3] = (void *)sceKernelSetAlarm(10000, timer_handler, 0);
        if ((int)sys_timer[3] < 0)
            break;
        OS_thread_mutex_lock((int)sys_timer[2]);
        if (sys_timer[0] == NULL) {
            if ((int)sys_timer[3] < 0)
                break;
            sceKernelCancelAlarm((int)sys_timer[3]);
            sys_timer[3] = (void *)-1;
            break;
        }
        clock_gettime(&ts);
        q = sys_timer;
        ds = ts.sec - (int)q[4];
        dn = ts.nsec - (int)q[5];
        elapsed = ds * 1000 + dn / 1000000;
        q[4] = (void *)ts.sec;
        q[5] = (void *)ts.nsec;
        for (t = M2C_FIELD(sys_timer[0], char **, 0x18); t != NULL; t = M2C_FIELD(t, char **, 0x18)) {
            if (M2C_FIELD(t, unsigned short *, 6) & 1) {
                M2C_FIELD(t, int *, 0x14) -= elapsed;
                if (M2C_FIELD(t, int *, 0x14) <= 0) {
                    if (M2C_FIELD(t, unsigned short *, 4) == 1)
                        OS_mq_send(M2C_FIELD(t, int *, 8), M2C_FIELD(t, int *, 0xC), 0x24, 0);
                    else if (!(M2C_FIELD(t, unsigned short *, 6) & 0x100)) {
                        OS_mq_send(M2C_FIELD(t, int *, 8), M2C_FIELD(t, int *, 0xC), 0x24, 0);
                        M2C_FIELD(t, unsigned short *, 6) |= 0x100;
                    }
                    M2C_FIELD(t, int *, 0x14) = M2C_FIELD(t, int *, 0x10);
                }
            }
        }
        OS_thread_mutex_unlock((int)sys_timer[2]);
    }
    thread_id_timer = -1;
    sceKernelDeleteSema(sema_id_timer);
    sema_id_timer = -1;
    OS_thread_mutex_unlock((int)sys_timer[2]);
    OS_thread_exit(0);
    return 0;
}

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

int OS_timer_init(void)
{
    int *head;
    void **p;

    if (sys_timer != NULL)
        return -1;
    sys_timer = MEM_calloc(0, 0x18);
    if (sys_timer == NULL)
        return -1;
    p = sys_timer;
    p[2] = OS_thread_mutex_create();
    if (OS_thread_mutex_init(sys_timer[2], 0) != 0) {
        MEM_free(0, sys_timer);
        return -1;
    }
    head = MEM_calloc(0, 0x1C);
    head[0] = (unsigned int)head >> 1;
    sys_timer[0] = head;
    clock_gettime((TimeSpec *)&sys_timer[4]);
    if (timer_create((int *)&sys_timer[3]) < 0) {
        OS_thread_mutex_destroy((int)sys_timer[2]);
        MEM_free(0, sys_timer);
        return -1;
    }
    if (OS_thread_create(&sys_timer[1], 0, esp_timerThread, 0) != 0) {
        timer_delete((int)sys_timer[3]);
        OS_thread_mutex_destroy((int)sys_timer[2]);
        MEM_free(0, sys_timer);
        return -1;
    }
    thread_id_timer = (int)sys_timer[1];
    return 0;
}

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

int OS_timer_set(int a, int b, int c, int d, int e)
{
    int *ev;
    int *t;

    if (sys_timer == NULL)
        return -1;
    ev = MEM_calloc(0, 0x24);
    if (ev == NULL)
        return -1;
    t = MEM_calloc(0, 0x1C);
    if (t == NULL) {
        MEM_free(0, ev);
        return -1;
    }
    t[0] = (unsigned int)t >> 1;
    ((short *)t)[2] = b;
    ((short *)t)[3] = 0;
    t[2] = a;
    t[3] = (int)ev;
    t[4] = c;
    t[5] = c;
    ev[1] = 9;
    ev[2] = d;
    ev[3] = e;
    ev[4] = 0;
    ev[5] = t[0];
    OS_thread_mutex_lock((int)sys_timer[2]);
    addTimer(t);
    OS_thread_mutex_unlock((int)sys_timer[2]);
    return t[0];
}

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
