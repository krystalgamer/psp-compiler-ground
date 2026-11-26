/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfgui.h"
#include "m2c_macros.h"
M2C_UNK make_dither_matrix(M2C_UNK *, M2C_UNK);     /* extern */
extern unsigned char dither_matrix;

extern int _iZwindDizF;


int GUI_Component_setFont(GUIWIDGET *w, GUIFONT *font) {
    if (w == NULL) {
        puts("[X1]GUI_Component_setFont");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_setFont");
        return -1;
    }
    if (font == NULL) {
        puts("[X3]GUI_Component_setFont");
        return -1;
    }
    if (font->type != 4) {
        puts("[X4]GUI_Component_setFont");
        return -1;
    }
    w->font = font;
    return 0;
}

int GUI_Component_setColor(GUIWIDGET *w, int *fg, int *bg) {
    if (w == NULL) {
        puts("[X1]GUI_Component_setColor");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_setColor");
        return -1;
    }
    w->fg[0] = fg[0];
    w->fg[1] = fg[1];
    w->fg[2] = fg[2];
    w->bg[0] = bg[0];
    w->bg[1] = bg[1];
    w->bg[2] = bg[2];
    w->fg15 = (fg[0] >> 3) | ((fg[1] >> 3) << 5) | ((fg[2] >> 3) << 10);
    w->bg15 = (bg[0] >> 3) | ((bg[1] >> 3) << 5) | ((bg[2] >> 3) << 10);
    return 0;
}

int GUI_Component_getColor(GUIWIDGET *w, int *fg, int *bg) {
    if (w == NULL) {
        puts("[X1]GUI_Component_getColor");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_getColor");
        return -1;
    }
    fg[0] = w->fg[0];
    fg[1] = w->fg[1];
    fg[2] = w->fg[2];
    bg[0] = w->bg[0];
    bg[1] = w->bg[1];
    bg[2] = w->bg[2];
    return 0;
}

GUIWIDGET *GUI_Component_getParent(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_Component_getParent");
        return NULL;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_getParent");
        return NULL;
    }
    return w->parent;
}

int GUI_Component_remove(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_Component_remove");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_remove");
        return -1;
    }
    GuiwidgetDelete(w);
    return 0;
}

int GUI_Component_setLocation(GUIWIDGET *w, int x, int y) {
    if (w == NULL) {
        puts("[X1]GUI_Component_setLocation");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_setLocation");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    w->x = x;
    w->y = y;
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_Component_getLocation(GUIWIDGET *w, int *x, int *y) {
    if (w == NULL) {
        puts("[X1]GUI_Component_getLocation");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_getLocation");
        return -1;
    }
    *x = w->x;
    *y = w->y;
    return 0;
}

int GUI_Component_setSize(GUIWIDGET *w, int width, int height) {
    if (w == NULL || w->type != 1) {
        puts("[X1]GUI_Component_setSize");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    w->w = width;
    w->h = height;
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_Component_getSize(GUIWIDGET *w, int *width, int *height) {
    if (w == NULL) {
        puts("[X1]GUI_Component_getSize");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_getSize");
        return -1;
    }
    *width = w->w;
    *height = w->h;
    return 0;
}

int GUI_Component_getPrefSize(GUIWIDGET *w, int *width, int *height) {
    if (w == NULL) {
        puts("[X1]GUI_Component_getPrefSize");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_getPrefSize");
        return -1;
    }
    *width = w->w;
    *height = w->h;
    return 0;
}

int GUI_Component_getMinimumSize(GUIWIDGET *w, int *width, int *height) {
    if (w == NULL) {
        puts("[X1]GUI_Component_getMinimumSize");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_getMinimumSize");
        return -1;
    }
    *width = w->w;
    *height = w->h;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_requestFocus);

int GUI_Component_setEnabled(GUIWIDGET *w, int enabled) {
    if (w == NULL) {
        puts("[X1]GUI_Component_setEnabled");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_setEnabled");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    w->flags = (w->flags & ~0x40000000) | ((enabled == 0) << 30);
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_Component_setVisible(GUIWIDGET *w, int visible) {
    if (w == NULL) {
        puts("[X1]GUI_Component_setVisible");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_setVisible");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    w->flags |= 0x20000000;
    s_windsystem_data.flags &= ~4;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_update);

int GUI_Component_setFocusColor(GUIWIDGET *w, int *color) {
    if (w == NULL) {
        puts("[X1]GUI_Component_setFocusColor");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_setFocusColor");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    w->focus15 = (color[0] >> 3) | ((color[1] >> 3) << 5) | ((color[2] >> 3) << 10) | 0x8000;
    if (color[0] == 0 && color[1] == 0 && color[2] == 0) {
        w->focus15 = 0;
    }
    zWindDraw(w);
    s_windsystem_data.flags &= ~4;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void zWindSetDiz(int arg0) {
    _iZwindDizF = arg0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", make_dither_matrix);

#ifndef NULL
#define NULL ((void *)0)
#endif

void dizInit(void) {
    make_dither_matrix(&dither_matrix, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int MAX(int arg0, int arg1) {
    return __builtin_allegrex_max(arg0, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int MIN(int arg0, int arg1) {
    return __builtin_allegrex_min(arg0, arg1);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", dizCg);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", D_00130A20);
