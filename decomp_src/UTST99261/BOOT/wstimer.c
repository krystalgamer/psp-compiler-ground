/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern void **sys_timer;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK OS_thread_join(int, M2C_UNK);               /* extern */
M2C_UNK OS_thread_mutex_destroy(int);               /* extern */
M2C_UNK OS_thread_mutex_lock(int);                  /* extern */
M2C_UNK OS_thread_mutex_unlock(int);                /* extern */
M2C_UNK timer_delete(int);                          /* extern */
extern int sema_id_timer;
M2C_UNK delTimer(int);                              /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", timer_create);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", timer_delete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", clock_gettime);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", esp_timerThread);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", timer_handler);

#ifndef NULL
#define NULL ((void *)0)
#endif

void addTimer(void *arg0) {
    M2C_FIELD(arg0, int *, 0x18) = (int) M2C_FIELD(*sys_timer, int *, 0x18);
    M2C_FIELD(*sys_timer, void **, 0x18) = arg0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", delTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", chkTimer);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_timer_start);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_timer_stop);

#ifndef NULL
#define NULL ((void *)0)
#endif

void OS_timer_clear(int arg0) {
    OS_thread_mutex_lock(M2C_FIELD(sys_timer, int *, 8));
    delTimer(arg0);
    OS_thread_mutex_unlock(M2C_FIELD(sys_timer, int *, 8));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wstimer", OS_clock_gettime);
