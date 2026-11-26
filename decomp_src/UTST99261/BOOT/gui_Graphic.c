/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "UTST99261/BOOT/nfgui.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getGraphics);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_createPixmap);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_drawString);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_fillRect);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_freeAnimationGIF);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getMaskPattern);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getAnimationGIFNextFrame);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getAnimationGIFFrameProperty);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createFrame);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createButton);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createCheckbox);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createRadiobox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createLabel);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Button_setLabel);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_removeAll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_getItem);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_select);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_deselect);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_isIndexSelected);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_insert);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_remove);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_removeAll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_getItem);

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
