#include "common.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", MEM_destroy);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", MEM_malloc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", MEM_calloc);

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
