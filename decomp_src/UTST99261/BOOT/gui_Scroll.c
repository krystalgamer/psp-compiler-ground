/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK MEM_agent(void *, M2C_UNK);                 /* extern */
M2C_UNK OS_thread_mutex_destroy(int);               /* extern */
M2C_UNK deallocate(void *, int);                    /* extern */
M2C_UNK mem_alloc(int, M2C_UNK, int);               /* extern */

extern int mem_defaultPool;
M2C_UNK mem_free(int);                              /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", GUI_ScrollPane_add);

#ifndef NULL
#define NULL ((void *)0)
#endif
int GUI_ScrollPane_remove(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", GUI_ScrollPane_getComponent);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", D_00131FB0);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", GUI_ScrollPane_setScrollPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", GUI_ScrollPane_getScrollPosition);

#ifndef NULL
#define NULL ((void *)0)
#endif
int GUI_ScrollPane_isVScrollbarVisible(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int GUI_ScrollPane_isHScrollbarVisible(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int GUI_ScrollPane_setVScrollbarVisible(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int GUI_ScrollPane_setHScrollbarVisible(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int GUI_ScrollPane_getVScrollbarWidth(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int GUI_ScrollPane_getHScrollbarHeight(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", GUI_ScrollPane_getViewportSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", GUI_ScrollPane_setContentSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", GUI_ScrollPane_getContentSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", GUI_ScrollPane_setVScrollbarMode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", GUI_ScrollPane_setHScrollbarMode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", MEM_init);

#ifndef NULL
#define NULL ((void *)0)
#endif

void MEM_destroy(void *arg0) {
    int temp_a0;
    int temp_a1;
    void *var_s0;

    var_s0 = arg0;
    if (arg0 == NULL) {
        var_s0 = mem_defaultPool;
    }
    if (var_s0 != NULL) {
        temp_a0 = M2C_FIELD(var_s0, int *, 0x20);
        M2C_FIELD(var_s0, int *, 0x20) = 0;
        OS_thread_mutex_destroy(temp_a0);
        temp_a1 = M2C_FIELD(var_s0, int *, 0x24);
        if (temp_a1 != 0) {
            deallocate(var_s0, temp_a1);
            M2C_FIELD(var_s0, int *, 0x24) = 0;
            M2C_FIELD(var_s0, int *, 0x28) = 0;
        }
        MEM_agent(var_s0, 1);
    }
    if (arg0 == NULL) {
        mem_defaultPool = NULL;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int MEM_attach(int arg0) {
    int var_v0;

    var_v0 = arg0;
    if (arg0 == 0) {
        var_v0 = mem_defaultPool;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void MEM_malloc(int arg0, int arg1) {
    int var_a0;

    var_a0 = arg0;
    if (var_a0 == 0) {
        var_a0 = mem_defaultPool;
    }
    mem_alloc(var_a0, 1, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void *MEM_calloc(int arg0, unsigned int arg1) {
    int var_a0;
    void *temp_v0;

    var_a0 = arg0;
    if (var_a0 == 0) {
        var_a0 = mem_defaultPool;
    }
    temp_v0 = mem_alloc(var_a0, 1, arg1);
    if (temp_v0 != NULL) {
        memset(temp_v0, 0, arg1);
    }
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", MEM_realloc);

#ifndef NULL
#define NULL ((void *)0)
#endif

void MEM_free(int arg0) {
    int var_a0;

    var_a0 = arg0;
    if (var_a0 == 0) {
        var_a0 = mem_defaultPool;
    }
    mem_free(var_a0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", MEM_addHaltCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", MEM_agent);

#ifndef NULL
#define NULL ((void *)0)
#endif
int MEM_checkViolation(void) {
    return 0;
}
