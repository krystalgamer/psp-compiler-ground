/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfgui.h"
#include "UTST99261/BOOT/wsmem.h"

extern int D_00584BCC;
extern char D_00131FB0[];  /* "[X1]GUI_ScrollPane_setScrollPosition"; do_fixed's length_tab - 257 */
void *memset(void *p, int c, unsigned int n);
int GUI_Component_update(GUIWIDGET *w, int x, int y, int width, int height);
void MEM_agent(MEMHEAP *pool, int flag);



int GUI_ScrollPane_add(GUIWIDGET *w, GUIWIDGET *c) {
    if (w == NULL) {
        puts("[X1]GUI_ScrollPane_add");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_ScrollPane_add");
        return -1;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int GUI_ScrollPane_remove(void) {
    return 0;
}

GUIWIDGET *GUI_ScrollPane_getComponent(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_ScrollPane_getComponent");
        return NULL;
    }
    if (w->type != 1) {
        puts("[X2]GUI_ScrollPane_getComponent");
        return NULL;
    }
    if ((w->flags & 0xF) != 12) {
        puts("[X3]GUI_ScrollPane_getComponent");
        return NULL;
    }
    return w;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", D_00131FB0);

int GUI_ScrollPane_setScrollPosition(GUIWIDGET *w, int x, int y) {
    GUIWIDGET *t;

    if (w == NULL) {
        puts(D_00131FB0);
        return -1;
    }
    t = w;
    if (w->type != 1) {
        puts("[X2]GUI_ScrollPane_setScrollPosition");
        return -1;
    }
    if ((w->flags & 0xF) != 12) {
        puts("[X3]GUI_ScrollPane_setScrollPosition");
        return -1;
    }
    if (D_00584BCC & 0x2000000) {
        x = x < 0 ? 0 : x;
        t->u.scroll.x = x;
    }
    if (D_00584BCC & 0x4000000) {
        y = y < 0 ? 0 : y;
        t->u.scroll.y = y;
    }
    GUI_Component_update(w, 0, 0, 0, 0);
    zWindDraw();
    return 0;
}

int GUI_ScrollPane_getScrollPosition(GUIWIDGET *w, int *x, int *y) {
    *x = 0;
    *y = 0;
    if (w == NULL) {
        puts("[X1]GUI_ScrollPane_getScrollPosition");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_ScrollPane_getScrollPosition");
        return -1;
    }
    if ((w->flags & 0xF) != 12) {
        puts("[X3]GUI_ScrollPane_getScrollPosition");
        return -1;
    }
    *x = w->u.scroll.x;
    *y = w->u.scroll.y;
    return 0;
}

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

int GUI_ScrollPane_getViewportSize(GUIWIDGET *w, int *width, int *height) {
    if (w == NULL) {
        puts("[X1]GUI_ScrGUI_ScrollPane_getViewportSizeollPane_getScrollPosition");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_ScrollPane_getViewportSize");
        return -1;
    }
    if ((w->flags & 0xF) != 12) {
        puts("[X3]GUI_ScrollPane_getViewportSize");
        return -1;
    }
    *width = w->w;
    *height = w->h;
    return 0;
}

int GUI_ScrollPane_setContentSize(GUIWIDGET *w, int width, int height) {
    if (w == NULL) {
        puts("[X1]GUI_ScrollPane_setContentSize");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_ScrollPane_setContentSize");
        return -1;
    }
    if ((w->flags & 0xF) != 12) {
        puts("[X3]GUI_ScrollPane_setContentSize");
        return -1;
    }
    w->u.scroll.cw = width;
    w->u.scroll.ch = height;
    return 0;
}

int GUI_ScrollPane_getContentSize(GUIWIDGET *w, int *width, int *height) {
    if (w == NULL) {
        puts("[X1]GUI_ScrollPane_getContentSize");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_ScrollPane_getContentSize");
        return -1;
    }
    if ((w->flags & 0xF) != 12) {
        puts("[X3]GUI_ScrollPane_getContentSize");
        return -1;
    }
    *width = w->u.scroll.cw;
    *height = w->u.scroll.ch;
    return 0;
}

int GUI_ScrollPane_setVScrollbarMode(GUIWIDGET *w, int mode) {
    if (w == NULL) {
        puts("[X1]GUI_ScrollPane_setVScrollbarMode");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_ScrollPane_setVScrollbarMode");
        return -1;
    }
    if ((w->flags & 0xF) != 12) {
        puts("[X3]GUI_ScrollPane_setVScrollbarMode");
        return -1;
    }
    w->u.scroll.vmode = mode;
    return 0;
}

int GUI_ScrollPane_setHScrollbarMode(GUIWIDGET *w, int mode) {
    if (w == NULL) {
        puts("[X1]GUI_ScrollPane_setHScrollbarMode");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_ScrollPane_setHScrollbarMode");
        return -1;
    }
    if ((w->flags & 0xF) != 12) {
        puts("[X3]GUI_ScrollPane_setHScrollbarMode");
        return -1;
    }
    w->u.scroll.hmode = mode;
    return 0;
}

int MEM_init(MEMHEAP *pool, void *mem, unsigned int size) {
    if (pool == NULL) {
        mem_defaultPool = mem;
    }
    if (mem_init(mem, size) < 0) {
        if (pool == NULL) {
            mem_defaultPool = NULL;
        }
        return -1;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void MEM_destroy(MEMHEAP *pool) {
    MEMHEAP *h;
    int m;

    h = pool;
    if (pool == NULL) {
        h = mem_defaultPool;
    }
    if (h != NULL) {
        m = h->mutex;
        h->mutex = 0;
        OS_thread_mutex_destroy(m);
        if (h->reserve != NULL) {
            deallocate(h, h->reserve);
            h->reserve = NULL;
            h->reserveSize = 0;
        }
        MEM_agent(h, 1);
    }
    if (pool == NULL) {
        mem_defaultPool = NULL;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

MEMHEAP *MEM_attach(MEMHEAP *pool) {
    if (pool == NULL) {
        pool = mem_defaultPool;
    }
    return pool;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *MEM_malloc(MEMHEAP *pool, unsigned int size) {
    if (pool == NULL) {
        pool = mem_defaultPool;
    }
    return mem_alloc(pool, 1, size);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *MEM_calloc(MEMHEAP *pool, unsigned int size) {
    void *p;

    if (pool == NULL) {
        pool = mem_defaultPool;
    }
    p = mem_alloc(pool, 1, size);
    if (p != NULL) {
        memset(p, 0, size);
    }
    return p;
}

void *MEM_realloc(MEMHEAP *pool, void *p, unsigned int size) {
    void *n;
    MEMHEAP *h;

    h = pool ? pool : mem_defaultPool;
    if (p == NULL) {
        return mem_alloc(h, 1, size);
    }
    if (size == 0) {
        mem_free(h, p);
        return NULL;
    }
    n = mem_alloc(h, 1, size);
    if (n == NULL) {
        return NULL;
    }
    memcpy(n, p, size);
    mem_free(h, p);
    return n;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void MEM_free(MEMHEAP *pool, void *p) {
    if (pool == NULL) {
        pool = mem_defaultPool;
    }
    mem_free(pool, p);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Scroll", MEM_addHaltCallback);

void MEM_agent(MEMHEAP *pool, int flag) {
    MEMBLOCK *b;
    unsigned int max;
    unsigned int min;

    if (pool == NULL) {
        pool = mem_defaultPool;
    }
    if (pool->mutex != 0) {
        OS_thread_mutex_lock(pool->mutex);
    }
    min = 0xFFFFFFFF;
    max = 0;
    for (b = pool->freelist; b != NULL; b = b->next) {
        if (max < b->size) {
            max = b->size;
        }
        if (b->size < min && b->size != 0) {
            min = b->size;
        }
    }
    if (pool->mutex != 0) {
        OS_thread_mutex_unlock(pool->mutex);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int MEM_checkViolation(void) {
    return 0;
}
