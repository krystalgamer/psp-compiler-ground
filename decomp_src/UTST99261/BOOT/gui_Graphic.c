/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "UTST99261/BOOT/nfgui.h"
extern int _zWindDrawTexClipOffX;
extern int _zWindDrawTexClipOffY;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_createGraphics);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createPanel);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createButton);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createCheckbox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createRadioboxGroup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createRadiobox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createLabel);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createChoice);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createTextField);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createTextArea);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createContentView);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_ContentView_setArgument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createFrameBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Button_setImage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Button_setLabel);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_RadioButton_setState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_RadioButton_getState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_RadioButton_getGroup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Checkbox_setState);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_select);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_getSelectedItem);
