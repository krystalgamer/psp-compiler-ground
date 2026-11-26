/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "UTST99261/BOOT/nfgui.h"

typedef struct GUIFRAME {
    struct GUIFRAME *next;
    s16 x;                      /* 0x4 */
    s16 y;
    s16 w;
    s16 h;
    int delay;                  /* 0xC */
    GUIPIXMAP *pixmap;          /* 0x10 */
} GUIFRAME;

typedef struct {
    s8 type;                    /* 5 */
    GUIFRAME *frames;           /* 0x4 */
    GUIFRAME *cur;              /* 0x8 */
    int count;                  /* 0xC */
    int unk10;
    int loop;                   /* 0x14 */
} GUIANIM;

void _GUI_Graphics_Push(GUIGRAPHICS *g);
void _GUI_Graphics_Pop(void);
void zWindDrawBox();
void zWindFontDraw();
extern int _zWindDrawTexClipOffX;
extern int _zWindDrawTexClipOffY;


GUIGRAPHICS *GUI_Graphics_createGraphics(GUIWIDGET *w) {
    GUIGRAPHICS *g;

    if (w == NULL) {
        puts("[X1]GUI_Graphics_createGraphics");
        return NULL;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Graphics_createGraphics");
        return NULL;
    }
    g = GuigraphicsCreate();
    g->x = 0;
    g->y = 0;
    g->ox = s_windsystem_init.width;
    g->oy = s_windsystem_init.height;
    g->color = 0xFFFF;
    g->pixmap = GuipixmapCreate();
    g->pixmap->kind = 10;
    g->pixmap->w = s_windsystem_init.width;
    g->pixmap->h = s_windsystem_init.height;
    g->pixmap->data = NULL;
    return g;
}

GUIGRAPHICS *GUI_Graphics_getGraphics(GUIGRAPHICS *g, GUIPIXMAP *pm) {
    WINDSYSTEMDATA *sd;
    GUIGRAPHICS *gr;

    if (pm == NULL) {
        puts("[X1]GUI_Graphics_getGraphics");
        return NULL;
    }
    if (pm->type != 3) {
        puts("[X2]GUI_Graphics_getGraphics");
        return NULL;
    }
    sd = &s_windsystem_data;
    if (sd->graphics != NULL && sd->pixmap2 == pm) {
        ((GUIGRAPHICS *)sd->graphics)->pixmap = pm;
        ((GUIGRAPHICS *)sd->graphics)->x = 0;
        ((GUIGRAPHICS *)sd->graphics)->y = 0;
        ((GUIGRAPHICS *)sd->graphics)->ox = pm->w;
        ((GUIGRAPHICS *)sd->graphics)->oy = pm->h;
        ((GUIGRAPHICS *)sd->graphics)->clip[0] = 0;
        ((GUIGRAPHICS *)sd->graphics)->clip[1] = 0;
        ((GUIGRAPHICS *)sd->graphics)->clip[2] = pm->w;
        ((GUIGRAPHICS *)sd->graphics)->clip[3] = pm->h;
        sd->graphics2 = sd->graphics;
        sd->graphics = NULL;
        return sd->graphics2;
    }
    gr = GuigraphicsCreate();
    if (gr == NULL) {
        puts("[X3]GUI_Graphics_getGraphics");
        return NULL;
    }
    gr->pixmap = pm;
    gr->x = 0;
    gr->y = 0;
    gr->ox = pm->w;
    gr->oy = pm->h;
    gr->clip[0] = 0;
    gr->clip[1] = 0;
    gr->clip[2] = pm->w;
    gr->clip[3] = pm->h;
    return gr;
}

int GUI_Graphics_freeGraphics(GUIGRAPHICS *g) {
    if (s_windsystem_data.graphics2 != NULL && s_windsystem_data.graphics2 == g) {
        s_windsystem_data.graphics = g;
        s_windsystem_data.graphics2 = NULL;
        return 0;
    }
    if (GuigraphicsDelete(g) == 0) {
        puts("[X1]GUI_Graphics_freeGraphics");
        return -1;
    }
    return 0;
}

GUIPIXMAP *GUI_Graphics_createPixmap(int w, int h) {
    WINDSYSTEMDATA *sd;
    GUIPIXMAP *pm;

    sd = &s_windsystem_data;
    if (sd->pixmap != NULL && w * h <= sd->width * sd->height) {
        ((GUIPIXMAP *)sd->pixmap)->w = w;
        ((GUIPIXMAP *)sd->pixmap)->h = h;
        sd->pixmap2 = sd->pixmap;
        sd->pixmap = NULL;
        return sd->pixmap2;
    }
    pm = GuipixmapCreate();
    if (pm == NULL) {
        puts("[X1]GUI_Graphics_createPixmap");
        return NULL;
    }
    pm->w = w;
    pm->h = h;
    pm->data = ESP_guiMemAlloc(w * h * 2);
    pm->kind = 0;
    if (pm->data == NULL) {
        puts("[X2]GUI_Graphics_createPixmap");
        GuipixmapDelete(pm);
        return NULL;
    }
    return pm;
}

void GUI_Graphics_freePixmap(GUIPIXMAP *p) {
    if (p == NULL) {
        puts("[X1]GUI_Graphics_freePixmap");
        return;
    }
    if (p->type != 3) {
        puts("[X2]GUI_Graphics_freePixmap");
        return;
    }
    if (s_windsystem_data.pixmap2 != NULL && s_windsystem_data.pixmap2 == p) {
        s_windsystem_data.pixmap = p;
        s_windsystem_data.pixmap2 = NULL;
    } else {
        GuipixmapDelete(p);
    }
}

int GUI_Graphics_setColor(GUIGRAPHICS *g, int *c) {
    if (g == NULL) {
        puts("[X1]GUI_Graphics_setColor");
        return -1;
    }
    if (g->type != 2) {
        puts("[X2]GUI_Graphics_setColor");
        return -1;
    }
    g->color = (c[0] >> 3) | ((c[1] >> 3) << 5) | ((c[2] >> 3) << 10);
    return 0;
}

int GUI_Graphics_setFont(GUIGRAPHICS *g, GUIFONT *font) {
    if (g == NULL || g->type != 2) {
        puts("[X1]GUI_Graphics_setFont");
        return -1;
    }
    g->font = font;
    return 0;
}

int GUI_Graphics_drawString(GUIGRAPHICS *g_, char *str, int len, int x, int y) {
    GUIGRAPHICS *g;

    if (g_ == NULL) {
        puts("[X1]GUI_Graphics_drawString");
        return -1;
    }
    g = g_;
    if (g->type != 2) {
        puts("[X2]GUI_Graphics_drawString");
        return -1;
    }
    _GUI_Graphics_Push(g);
    zWindFontDraw(g->font, x, y, str, *(s16 *)&g->color, len);
    _GUI_Graphics_Pop();
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getStringSize);

int GUI_Graphics_getStringBound(GUIFONT *font, char *s, int n, int d) {
    if (font == NULL || font->type != 4) {
        puts("[X1]GUI_Graphics_getStringBound");
        return -1;
    }
    return n * font->size / d;
}

int GUI_Graphics_drawRect(GUIGRAPHICS *g) {
    GUIPIXMAP *pm;

    if (g == NULL) {
        puts("[X1]GUI_Graphics_drawRect");
        return -1;
    }
    if (g->type != 2 || (pm = g->pixmap) == NULL) {
        puts("[X2]GUI_Graphics_drawRect");
        return -1;
    }
    if (pm->type != 3) {
        puts("[X3]GUI_Graphics_drawRect");
        return -1;
    }
    return 0;
}

int GUI_Graphics_fillRect(GUIGRAPHICS *g_, int x, int y, int w, int h) {
    GUIGRAPHICS *g;

    if (g_ == NULL) {
        puts("[X1]GUI_Graphics_fillRect");
        return -1;
    }
    g = g_;
    if (g->type != 2) {
        puts("[X2]GUI_Graphics_fillRect");
        return -1;
    }
    _GUI_Graphics_Push(g);
    zWindDrawBox(x, y, w, h, *(s16 *)&g->color);
    _GUI_Graphics_Pop();
    return 0;
}

int GUI_Graphics_setClip(GUIGRAPHICS *g, int x, int y, int w, int h) {
    if (g == NULL) {
        puts("[X1]GUI_Graphics_setClip");
        return -1;
    }
    if (g->type != 2) {
        puts("[X2]GUI_Graphics_setClip");
        return -1;
    }
    g->clip[0] = x;
    g->clip[1] = y;
    g->clip[2] = w;
    g->clip[3] = h;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getImageProperty);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getImage);

int GUI_Graphics_getPixmapSize(GUIPIXMAP *p, int *w, int *h) {
    *w = 0;
    *h = 0;
    if (p == NULL) {
        puts("[X1]GUI_Graphics_getPixmapSize");
        return -1;
    }
    if (p->type != 3) {
        puts("[X2]GUI_Graphics_getPixmapSize");
        return -1;
    }
    *w = p->w;
    *h = p->h;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_drawPixmap);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_drawTiledPixmap);

#ifndef NULL
#define NULL ((void *)0)
#endif
int puts(const char *s);
void GUI_Graphics_flush(signed char *arg0) {
    if ((arg0 == NULL) || (*arg0 != 2)) {
        puts("[X1]GUI_Graphics_flush");
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_createAnimationGIF);

void GUI_Graphics_startAnimationGIF(void) {
}

void GUI_Graphics_getAnimationGIFSize(void) {
}

void GUI_Graphics_freeAnimationGIF(GUIANIM *a_) {
    GUIFRAME *f;
    GUIFRAME *n;
    GUIANIM *a;

    if (a_ == NULL) {
        puts("[X1]GUI_Graphics_freeAnimationGIF");
        return;
    }
    a = a_;
    if (a->type != 5) {
        puts("[X2]GUI_Graphics_freeAnimationGIF");
        return;
    }
    a->type = 0;
    f = a->frames;
    while (f != NULL) {
        if (f->pixmap != NULL) {
            GuipixmapDelete(f->pixmap);
        }
        n = f;
        f = f->next;
        ESP_guiMemFree(n);
    }
    ESP_guiMemFree(a);
}

GUIPIXMAP *GUI_Graphics_getMaskPattern(int *c1, int *c2) {
    GUIPIXMAP *pm;
    u16 *d;

    pm = GuipixmapCreate();
    if (pm == NULL) {
        puts("[X1]GUI_Graphics_getMaskPattern");
        return NULL;
    }
    pm->w = 2;
    pm->h = 2;
    pm->data = ESP_guiMemAlloc(8);
    pm->kind = 0;
    d = pm->data;
    d[0] = d[3] = (c1[0] >> 3) | ((c1[1] >> 3) << 5) | ((c1[2] >> 3) << 10);
    d[1] = d[2] = (c2[0] >> 3) | ((c2[1] >> 3) << 5) | ((c2[2] >> 3) << 10);
    return pm;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getBrokenLinePattern);

void _GUI_Graphics_Push(GUIGRAPHICS *g) {
    GUIPIXMAP *pm;

    pm = g->pixmap;
    if (pm->kind == 0) {
        zWindDrawClipSetTex(pm->data, g->clip[0], g->clip[1], g->clip[2], g->clip[3], g->ox, g->oy);
    } else {
        _zWindDrawTexClipOffX = _zWindDrawTexClipOffAX;
        _zWindDrawTexClipOffY = _zWindDrawTexClipOffAY;
        zWindDrawClipSetTex(s_windsystem_init.image, g->x, g->y, g->ox, g->oy, g->ox, g->oy);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void _GUI_Graphics_Pop(void) {
    _zWindDrawTexClipOffX = 0;
    _zWindDrawTexClipOffY = 0;
}

void GUI_Graphics_getAnimationGIFGlobalProperty(void) {
}

GUIPIXMAP *GUI_Graphics_getAnimationGIFNextFrame(GUIANIM *a, int reset) {
    GUIFRAME *f;
    int n;

    if (a == NULL) {
        puts("[X1]GUI_Graphics_getAnimationGIFNextFrame");
        return NULL;
    }
    if (a->type != 5) {
        puts("[X2]GUI_Graphics_getAnimationGIFNextFrame");
        return NULL;
    }
    if (reset == 1) {
        a->cur = NULL;
        a->loop = 0;
        return NULL;
    }
    f = a->cur;
    if (f == NULL) {
        f = a->frames;
    } else if (f->next == NULL) {
        n = a->count;
        if (n == -1) {
            f = a->frames;
        } else if (a->loop == n) {
            return f->pixmap;
        } else {
            a->loop++;
            f = a->frames;
        }
    } else {
        f = f->next;
    }
    if (f == NULL) {
        puts("[X4]GUI_Graphics_getAnimationGIFNextFrame");
        return NULL;
    }
    a->cur = f;
    return f->pixmap;
}

void GUI_Graphics_getAnimationGIFFrameProperty(GUIANIM *a, int *x, int *y, int *w, int *h, int *delay) {
    GUIFRAME *f;
    int d;

    *x = 0;
    *y = 0;
    *w = 0;
    *h = 0;
    *delay = 0;
    if (a == NULL) {
        puts("[X1]GUI_Graphics_getAnimationGIFFrameProperty");
        return;
    }
    if (a->type != 5) {
        puts("[X2]GUI_Graphics_getAnimationGIFFrameProperty");
        return;
    }
    f = a->cur;
    if (f == NULL) {
        f = a->frames;
        if (f == NULL) {
            puts("[X3]GUI_Graphics_getAnimationGIFFrameProperty");
            return;
        }
    }
    *x = f->x;
    *y = f->y;
    *w = f->w;
    *h = f->h;
    if (a->loop != a->count || f->next != NULL) {
        d = f->delay;
    } else {
        d = -1;
    }
    *delay = d;
}

GUIWIDGET *GUI_createFrame(GUIWIDGET *parent, char *text) {
    GUIWIDGET *w;
    int len;
    char *buf;

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createFrame");
        return NULL;
    }
    len = 0;
    if (text != NULL) {
        len = strlen(text);
    }
    buf = NULL;
    if (len != 0) {
        buf = ESP_guiMemAlloc(len + 1);
        if (buf == NULL) {
            puts("[X2]GUI_createFrame");
            return NULL;
        }
        memcpy(buf, text, len + 1);
        buf[len] = 0;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        if (len != 0) {
            ESP_guiMemFree(buf);
        }
        puts("[X3]GUI_createFrame");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 1;
    w->unk4C = buf;
    w->x = 0;
    w->y = 0;
    w->w = 64;
    w->h = 20;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createPanel(GUIWIDGET *parent) {
    GUIWIDGET *w;

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createPanel");
        return NULL;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        puts("[X2]GUI_createPanel");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 2;
    w->x = 0;
    w->y = 0;
    w->w = 64;
    w->h = 20;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createButton(GUIWIDGET *parent, char *text , void *a, void *b) {
    GUIWIDGET *w;
    int len;
    char *buf;
    int sw;
    int sh;
    int fg[3];
    int bg[3];

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createButton");
        return NULL;
    }
    len = 0;
    if (text != NULL) {
        len = strlen(text);
    }
    buf = NULL;
    if (len != 0) {
        buf = ESP_guiMemAlloc(len + 1);
        if (buf == NULL) {
            puts("[X2]GUI_createButton");
            return NULL;
        }
        memcpy(buf, text, len + 1);
        buf[len] = 0;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        if (len != 0) {
            ESP_guiMemFree(buf);
        }
        puts("[X3]GUI_createButton");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 3;
    GUI_Graphics_getStringSize(w->font, buf, len, &sw, &sh);
    if (sw == 0) {
        sw = 64;
        sh = 20;
    }
    w->unk50.p = buf;
    w->u.choice.sel = len;
    w->unk4C = b;
    w->u.button.image = a;
    w->u.choice.unk56 = 0;
    w->x = 0;
    w->y = 0;
    w->w = sw + 4;
    w->h = sh + 4;
    fg[0] = 0;
    fg[1] = 0;
    fg[2] = 0;
    bg[0] = 0x80;
    bg[1] = 0x80;
    bg[2] = 0x80;
    GUI_Component_setColor(w, fg, bg);
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createCheckbox(GUIWIDGET *parent, char *text ) {
    GUIWIDGET *w;
    int len;
    char *buf;
    int sw;
    int sh;
    int fg[3];
    int bg[3];

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createCheckbox");
        return NULL;
    }
    len = 0;
    if (text != NULL) {
        len = strlen(text);
    }
    buf = NULL;
    if (len != 0) {
        buf = ESP_guiMemAlloc(len + 1);
        if (buf == NULL) {
            puts("[X2]GUI_createCheckbox");
            return NULL;
        }
        memcpy(buf, text, len + 1);
        buf[len] = 0;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        if (len != 0) {
            ESP_guiMemFree(buf);
        }
        puts("[X3]GUI_createCheckbox");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 4;
    GUI_Graphics_getStringSize(w->font, buf, len, &sw, &sh);
    w->unk4C = buf;
    w->u.list.state = 0;
    w->x = 0;
    w->y = 0;
    w->w = sw + 20;
    w->h = sh;
    fg[0] = 0;
    fg[1] = 0;
    fg[2] = 0;
    bg[0] = 0xdc;
    bg[1] = 0xdc;
    bg[2] = 0xdc;
    GUI_Component_setColor(w, fg, bg);
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createRadioboxGroup(GUIWIDGET *parent) {
    GUIWIDGET *w;

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createRadioboxGroup");
        return NULL;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        puts("[X2]GUI_createRadioboxGroup");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 5;
    w->x = 0;
    w->y = 0;
    w->w = 0;
    w->h = 0;
    w->unk50.p = NULL;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createRadiobox(GUIWIDGET *parent, char *text ) {
    GUIWIDGET *w;
    int len;
    char *buf;
    int sw;
    int sh;
    int fg[3];
    int bg[3];

    if (parent == NULL) {
        puts("[X1]GUI_createRadiobox");
        return NULL;
    }
    if (parent->type != 1) {
        puts("[X2]GUI_createRadiobox");
        return NULL;
    }
    len = 0;
    if (text != NULL) {
        len = strlen(text);
    }
    buf = NULL;
    if (len != 0) {
        buf = ESP_guiMemAlloc(len + 1);
        if (buf == NULL) {
            puts("[X3]GUI_createRadiobox");
            return NULL;
        }
        memcpy(buf, text, len + 1);
        buf[len] = 0;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        if (len != 0) {
            ESP_guiMemFree(buf);
        }
        puts("[X4]GUI_createRadiobox");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    if (parent->unk50.p == NULL) {
        parent->unk50.p = w;
    }
    w->flags = (w->flags & ~0xF) | 6;
    GUI_Graphics_getStringSize(w->font, buf, len, &sw, &sh);
    w->unk4C = buf;
    w->u.list.state = 0;
    w->x = 0;
    w->y = 0;
    w->w = sw + 20;
    w->h = sh;
    fg[0] = 0;
    fg[1] = 0;
    fg[2] = 0;
    bg[0] = 0xdc;
    bg[1] = 0xdc;
    bg[2] = 0xdc;
    GUI_Component_setColor(w, fg, bg);
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createLabel(GUIWIDGET *parent, char *text) {
    GUIWIDGET *w;
    int len;
    char *buf;

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createLabel");
        return NULL;
    }
    len = 0;
    if (text != NULL) {
        len = strlen(text);
    }
    buf = NULL;
    if (len != 0) {
        buf = ESP_guiMemAlloc(len + 1);
        if (buf == NULL) {
            puts("[X2]GUI_createLabel");
            return NULL;
        }
        memcpy(buf, text, len + 1);
        buf[len] = 0;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        if (len != 0) {
            ESP_guiMemFree(buf);
        }
        puts("[X3]GUI_createLabel");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 7;
    w->unk4C = buf;
    w->x = 0;
    w->y = 0;
    w->w = 64;
    w->h = 20;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createList(GUIWIDGET *parent, void *a) {
    GUIWIDGET *w;
    int fg[3];
    int bg[3];

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createList");
        return NULL;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        puts("[X2]GUI_createList");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 8;
    w->unk4C = a;
    w->unk50.p = NULL;
    w->u.list.state = 0;
    w->u.list.unk58 = 0;
    w->u.list.count = 0;
    w->u.list.unk5C = 0;
    w->x = 0;
    w->y = 0;
    w->w = 64;
    w->h = 20;
    fg[0] = 0;
    fg[1] = 0;
    fg[2] = 0;
    bg[0] = 0xdc;
    bg[1] = 0xdc;
    bg[2] = 0xdc;
    GUI_Component_setColor(w, fg, bg);
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createChoice(GUIWIDGET *parent) {
    GUIWIDGET *w;
    int fg[3];
    int bg[3];

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createChoice");
        return NULL;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        puts("[X2]GUI_createChoice");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 9;
    w->unk4C = NULL;
    w->unk50.p = NULL;
    w->u.choice.sel = -1;
    w->u.choice.unk56 = 0;
    w->u.choice.unk58 = 0;
    w->x = 0;
    w->y = 0;
    w->w = 64;
    w->h = 20;
    fg[0] = 0;
    fg[1] = 0;
    fg[2] = 0;
    bg[0] = 0xdc;
    bg[1] = 0xdc;
    bg[2] = 0xdc;
    GUI_Component_setColor(w, fg, bg);
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createTextField(GUIWIDGET *parent) {
    GUIWIDGET *w;
    int fg[3];
    int bg[3];

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createTextField");
        return NULL;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        puts("[X2]GUI_createTextField");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 10;
    w->unk4C = NULL;
    w->unk50.t.len = 0;
    w->unk50.t.max = -1;
    w->u.text.editable = 1;
    w->x = 0;
    w->y = 0;
    w->w = 64;
    w->h = 20;
    fg[0] = 0;
    fg[1] = 0;
    fg[2] = 0;
    bg[0] = 0x80;
    bg[1] = 0x80;
    bg[2] = 0x80;
    GUI_Component_setColor(w, fg, bg);
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createTextArea(GUIWIDGET *parent) {
    GUIWIDGET *w;
    int fg[3];
    int bg[3];

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createTextArea");
        return NULL;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        puts("[X2]GUI_createTextArea");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 11;
    w->unk4C = NULL;
    w->unk50.t.len = 0;
    w->unk50.t.max = 0;
    w->u.text.areaEditable = -1;
    w->x = 0;
    w->y = 0;
    w->w = 64;
    w->h = 20;
    fg[0] = 0;
    fg[1] = 0;
    fg[2] = 0;
    bg[0] = 0x80;
    bg[1] = 0x80;
    bg[2] = 0x80;
    GUI_Component_setColor(w, fg, bg);
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

GUIWIDGET *GUI_createContentView(GUIWIDGET *parent, void *a, void *b) {
    GUIWIDGET *w;

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createContentView");
        return NULL;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        puts("[X2]GUI_createContentView");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 12;
    w->unk4C = a;
    w->unk50.p = b;
    w->w = 64;
    w->h = 20;
    w->x = 0;
    w->y = 0;
    w->u.scroll.x = 0;
    w->u.scroll.y = 0;
    w->u.scroll.cw = 64;
    w->u.scroll.ch = 20;
    s_windsystem_data.unk28 = w;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

void GUI_ContentView_setArgument(GUIWIDGET *w, void * v) {
    if (w == NULL) {
        puts("[X1]GUI_ContentView_setArgument");
        return;
    }
    if (w->type != 1) {
        puts("[X2]GUI_ContentView_setArgument");
        return;
    }
    if ((w->flags & 0xF) != 12) {
        puts("[X3]GUI_ContentView_setArgument");
        return;
    }
    s_windsystem_data.flags |= 4;
    w->unk50.p = v;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
}

GUIWIDGET *GUI_createFrameBorder(GUIWIDGET *parent, void *a, void *b, int c) {
    GUIWIDGET *w;

    if (parent != NULL && parent->type != 1) {
        puts("[X1]GUI_createFrameBorder");
        return NULL;
    }
    s_windsystem_data.flags |= 4;
    w = GuiwidgetCreate(parent);
    if (w == NULL) {
        puts("[X2]GUI_createFrameBorder");
        s_windsystem_data.flags &= ~4;
        return NULL;
    }
    w->flags = (w->flags & ~0xF) | 13;
    w->unk4C = a;
    w->unk50.p = b;
    w->u.list.state = c;
    w->x = 0;
    w->y = 0;
    w->w = 64;
    w->h = 20;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return w;
}

int GUI_Button_setImage(GUIWIDGET *w, void * v) {
    if (w == NULL) {
        puts("[X1]GUI_Button_setImage");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Button_setImage");
        return -1;
    }
    if ((w->flags & 0xF) != 3) {
        puts("[X3]GUI_Button_setImage");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    w->u.button.image = v;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_Button_setLabel(GUIWIDGET *w_, char *label) {
    GUIWIDGET *w;
    int len;
    char *s;

    if (w_ == NULL) {
        puts("[X1]GUI_Button_setLabel");
        return -1;
    }
    w = w_;
    if (w->type != 1) {
        puts("[X2]GUI_Button_setLabel");
        return -1;
    }
    if ((w->flags & 0xF) != 3) {
        puts("[X3]GUI_Button_setLabel");
        return -1;
    }
    len = 0;
    if (label != NULL) {
        len = strlen(label);
    }
    s = NULL;
    if (len != 0) {
        s = ESP_guiMemAlloc(len + 1);
        if (s == NULL) {
            puts("[X4]GUI_Button_setLabel");
            return -1;
        }
        memcpy(s, label, len);
        s[len] = 0;
    }
    s_windsystem_data.flags |= 4;
    if (w->unk50.p != NULL) {
        ESP_guiMemFree(w->unk50.p);
    }
    w->unk50.p = s;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_RadioButton_setState(GUIWIDGET *w, int state) {
    if (w == NULL) {
        puts("[X1]GUI_RadioButton_setState");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_RadioButton_setState");
        return -1;
    }
    if ((w->flags & 0xF) != 6) {
        puts("[X3]GUI_RadioButton_setState");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    w->u.list.state = state;
    if (state == 1) {
        w->parent->unk50.p = w;
    }
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_RadioButton_getState(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_RadioButton_getState");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_RadioButton_getState");
        return -1;
    }
    if ((w->flags & 0xF) != 6) {
        puts("[X3]GUI_RadioButton_getState");
        return -1;
    }
    return w->u.list.state;
}

GUIWIDGET * GUI_RadioButton_getGroup(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_RadioButton_getGroup");
        return NULL;
    }
    if (w->type != 1) {
        puts("[X2]GUI_RadioButton_getGroup");
        return NULL;
    }
    if ((w->flags & 0xF) != 6) {
        puts("[X3]GUI_RadioButton_getGroup");
        return NULL;
    }
    return w->parent;
}

int GUI_Checkbox_setState(GUIWIDGET *w, int v) {
    if (w == NULL) {
        puts("[X1]GUI_Checkbox_setState");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Checkbox_setState");
        return -1;
    }
    if ((w->flags & 0xF) != 4) {
        puts("[X3]GUI_Checkbox_setState");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    w->u.list.state = v;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_Checkbox_getState(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_Checkbox_getState");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Checkbox_getState");
        return -1;
    }
    if ((w->flags & 0xF) != 4) {
        puts("[X3]GUI_Checkbox_getState");
        return -1;
    }
    return w->u.list.state;
}

void _GUI_List_no(GUIWIDGET *w) {
    GUILISTITEM *p;
    int n;

    n = 0;
    for (p = w->unk50.p; p != NULL; p = p->next) {
        n++;
    }
    w->u.list.count = n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_add);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_remove);

int GUI_List_removeAll(GUIWIDGET *w_) {
    GUIWIDGET *w;
    GUILISTITEM *p;
    GUILISTITEM *n;

    if (w_ == NULL) {
        puts("[X1]GUI_List_removeAll");
        return -1;
    }
    w = w_;
    if (w->type != 1) {
        puts("[X2]GUI_List_removeAll");
        return -1;
    }
    if ((w->flags & 0xF) != 8) {
        puts("[X3]GUI_List_removeAll");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    p = w->unk50.p;
    while (p != NULL) {
        n = p->next;
        ESP_guiMemFree(p->text);
        ESP_guiMemFree(p);
        p = n;
    }
    w->unk50.p = NULL;
    w->u.list.state = 0;
    w->u.list.unk58 = 0;
    _GUI_List_no(w);
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

char *GUI_List_getItem(GUIWIDGET *w, int idx) {
    GUILISTITEM *p;
    int i;
    int len;
    char *s;

    if (w == NULL) {
        puts("[X1]GUI_List_getItem");
        return NULL;
    }
    if (w->type != 1) {
        puts("[X2]GUI_List_getItem");
        return NULL;
    }
    if ((w->flags & 0xF) != 8) {
        puts("[X3]GUI_List_getItem");
        return NULL;
    }
    p = w->unk50.p;
    i = 0;
    while (i++ != idx) {
        if (p == NULL) {
            puts("[X5]GUI_List_getItem");
            return NULL;
        }
        if (i >= w->u.list.count) {
            puts("[X4]GUI_List_getItem");
            return NULL;
        }
        p = p->next;
    }
    len = p->len;
    s = ESP_guiMemAlloc(len + 1);
    if (s == NULL) {
        puts("[X5]GUI_List_getItem");
        return NULL;
    }
    if (len != 0) {
        memcpy(s, p->text, len);
    }
    s[len] = 0;
    return s;
}

int GUI_List_select(GUIWIDGET *w, int idx) {
    GUILISTITEM *p;
    int i;

    if (w == NULL) {
        puts("[X1]GUI_List_select");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_List_select");
        return -1;
    }
    if ((w->flags & 0xF) != 8) {
        puts("[X3]GUI_List_select");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    if (w->unk4C == NULL) {
        w->u.list.unk58 = idx;
    } else {
        p = w->unk50.p;
        i = 0;
        while (i++ != idx) {
            if (p == NULL) {
                s_windsystem_data.flags &= ~4;
                return -1;
            }
            if (i >= w->u.list.count) {
                s_windsystem_data.flags &= ~4;
                return -1;
            }
            p = p->next;
        }
        if (p == NULL) {
            s_windsystem_data.flags &= ~4;
            return -1;
        }
        p->state = 0;
    }
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_List_deselect(GUIWIDGET *w, int idx) {
    GUILISTITEM *p;
    int i;

    if (w == NULL) {
        puts("[X1]GUI_List_deselect");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_List_deselect");
        return -1;
    }
    if ((w->flags & 0xF) != 8) {
        puts("[X3]GUI_List_deselect");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    if ((int)w->unk4C == 1) {
        p = w->unk50.p;
        i = 0;
        while (i++ != idx) {
            if (p == NULL) {
                s_windsystem_data.flags &= ~4;
                return -1;
            }
            if (i >= w->u.list.count) {
                s_windsystem_data.flags &= ~4;
                return -1;
            }
            p = p->next;
        }
        if (p == NULL) {
            s_windsystem_data.flags &= ~4;
            return -1;
        }
        p->state = -1;
    }
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_isIndexSelected);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_insert);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_remove);

int GUI_Choice_removeAll(GUIWIDGET *w_) {
    GUIWIDGET *w;
    GUILISTITEM *p;
    GUILISTITEM *n;

    if (w_ == NULL) {
        puts("[X1]GUI_Choice_removeAll");
        return -1;
    }
    w = w_;
    if (w->type != 1) {
        puts("[X2]GUI_Choice_removeAll");
        return -1;
    }
    if ((w->flags & 0xF) != 9) {
        puts("[X3]GUI_Choice_removeAll");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    p = w->unk4C;
    while (p != NULL) {
        n = p->next;
        ESP_guiMemFree(p->text);
        ESP_guiMemFree(p);
        p = n;
    }
    w->u.choice.sel = -1;
    w->unk4C = NULL;
    w->unk50.p = NULL;
    w->u.choice.unk56 = 0;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

char *GUI_Choice_getItem(GUIWIDGET *w, int idx) {
    GUILISTITEM *p;
    int i;
    int len;
    char *s;

    if (w == NULL) {
        puts("[X1]GUI_Choice_getItem");
        return NULL;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Choice_getItem");
        return NULL;
    }
    if ((w->flags & 0xF) != 9) {
        puts("[X3]GUI_Choice_getItem");
        return NULL;
    }
    for (p = w->unk4C, i = 0; p != NULL; p = p->next, i++) {
        if (i == idx) {
            len = 0;
            if (p->text != NULL) {
                len = strlen(p->text);
            }
            s = ESP_guiMemAlloc(len + 1);
            if (s == NULL) {
                puts("[X4]GUI_Choice_getItem");
                return NULL;
            }
            if (len != 0) {
                memcpy(s, p->text, len);
            }
            s[len] = 0;
            return s;
        }
    }
    puts("[X5]GUI_Choice_getItem");
    return NULL;
}

int GUI_Choice_select(GUIWIDGET *w, int v) {
    if (w == NULL) {
        puts("[X1]GUI_Choice_select");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Choice_select");
        return -1;
    }
    if ((w->flags & 0xF) != 9) {
        puts("[X3]GUI_Choice_select");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    w->u.choice.sel = v;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_Choice_getSelectedItem(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_Choice_getSelectedItem");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Choice_getSelectedItem");
        return -1;
    }
    if ((w->flags & 0xF) != 9) {
        puts("[X3]GUI_Choice_getSelectedItem");
        return -1;
    }
    return w->u.choice.sel;
}
