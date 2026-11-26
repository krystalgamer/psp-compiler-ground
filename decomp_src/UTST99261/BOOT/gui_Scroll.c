/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfgui.h"
#include "UTST99261/BOOT/wsmem.h"

extern int D_00584BCC;
extern char D_00131FB0[];  /* "[X1]GUI_ScrollPane_setScrollPosition" */
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
