/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfgui.h"
#include "m2c_macros.h"
int make_dither_matrix(s8 *m, int n);
extern s8 dither_matrix[8][8];

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

int GUI_Component_requestFocus(GUIWIDGET *w, int flag) {
    s_windsystem_data.flags |= 4;
    s_windsystem_data.focus = flag ? w : s_windsystem_data.top;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

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

int GUI_Component_update(GUIWIDGET *w, int x, int y, int width, int height) {
    GUIWIDGET *c;
    int sx, sy;
    int dx, dy;
    if (w == NULL) {
        puts("[X1]GUI_Component_update");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Component_update");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    c = w;
    if ((x | y | width | height) == 0) {
        x = c->x;
        y = c->y;
        width = c->w;
        height = c->h;
        if ((c->flags & 0xF) == 0xC) {
            GUI_ScrollPane_getScrollPosition(w, &sx, &sy);
            x += sx;
            y += sy;
        }
    }
    if (!(c->flags & 0x800000)) {
        c->dirty[0] = x;
        c->dirty[1] = y;
        c->dirty[2] = width;
        c->dirty[3] = height;
    } else {
        dx = c->dirty[0];
        dy = c->dirty[1];
        if (x < dx) {
            c->dirty[0] = x;
            c->dirty[2] += dx - x;
        }
        if (y < dy) {
            c->dirty[1] = y;
            c->dirty[3] += dy - y;
        }
        if (c->dirty[0] + c->dirty[2] < x + width)
            c->dirty[2] = x + width - c->dirty[0];
        if (c->dirty[1] + c->dirty[3] < y + height)
            c->dirty[3] = y + height - c->dirty[1];
    }
    if ((c->flags & 0xF) == 0xC) {
        GUI_ScrollPane_getScrollPosition(w, &x, &y);
        GUI_ScrollPane_getViewportSize(c, &width, &height);
        if (c->dirty[0] + c->dirty[2] > x + width)
            c->dirty[2] -= c->dirty[0] + c->dirty[2] - (x + width);
        if (c->dirty[1] + c->dirty[3] > y + height)
            c->dirty[3] -= c->dirty[1] + c->dirty[3] - (y + height);
        if (c->dirty[0] < x) {
            c->dirty[2] -= x - c->dirty[0];
            c->dirty[0] = x;
        }
        if (c->dirty[1] < y) {
            c->dirty[3] -= y - c->dirty[1];
            c->dirty[1] = y;
        }
    }
    c->flags |= 0x800000;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return -1;
}

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

void *malloc(unsigned int n);
void free(void *p);

int make_dither_matrix(s8 *m, int n) {
    s8 base[4] = {0, 2, 3, 1};
    s8 *sub;
    int i;
    int j;
    int v;

    if (n & 1) {
        return 0;
    }
    if (n >= 3) {
        sub = malloc(n * n / 4);
        if (make_dither_matrix(sub, n / 2) == 0) {
            ESP_guiMemFree(sub);
            return 0;
        }
        for (i = 0; i < n / 2; i++) {
            for (j = 0; j < n / 2; j++) {
                m[j + i * n] = v = sub[j + i * n / 2] * 4;
                m[j + n / 2 + i * n] = v + 2;
                m[j + (i + n / 2) * n] = v + 3;
                m[j + n / 2 + (i + n / 2) * n] = v + 1;
            }
        }
        free(sub);
    } else {
        for (j = 0; j < n * n; j++) {
            m[j] = base[j];
        }
    }
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void dizInit(void) {
    make_dither_matrix(dither_matrix, 8);
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

s16 dizCg(int x, int y, u8 r, u8 g, u8 b) {
    int d;

    x %= 8;
    y %= 8;
    d = dither_matrix[y][x] - 32;
    r = MAX(MIN(r + d, 255), 0);
    g = MAX(MIN(g + d, 255), 0);
    b = MAX(MIN(b + d, 255), 0);
    return (r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10);
}

