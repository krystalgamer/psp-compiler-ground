/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfgui.h"

int GuiwidgetInit(void) {
    s_windsystem_data.root = NULL;
    s_windsystem_data.focus = NULL;
    s_windsystem_data.unk8 = 0;
    return 1;
}

int GuiwidgetExit(void) {
    GuiwidgetAllOpening();
    return 1;
}

GUIWIDGET *GuiwidgetCreate(GUIWIDGET *parent) {
    GUIWIDGET *w;
    GUIWIDGET *p;

    if (parent == NULL) {
        GuiwidgetAllOpening();
        if (s_windsystem_data.font == NULL) {
            s_windsystem_data.font = GuifontCreateOne();
        }
    } else if (parent->type != 1) {
        puts("[X1]GuiwidgetCreate");
        return NULL;
    }
    w = ESP_guiMemAlloc(sizeof(GUIWIDGET));
    if (w == NULL) {
        puts("[X2]GuiwidgetCreate");
        return NULL;
    }
    GuiwidgetClear(w);
    w->parent = parent;
    if (parent == NULL) {
        s_windsystem_data.root = w;
    } else {
        p = parent->child;
        if (p == NULL) {
            parent->child = w;
        } else {
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = w;
        }
    }
    w->x = 0;
    w->y = 0;
    w->w = 16;
    w->h = 16;
    w->flags = 0;
    _i_guiwidgetmalloc++;
    w->focus15 = 25;
    w->type = 1;
    return w;
}

int GuiwidgetClear(GUIWIDGET *w) {
    w->parent = NULL;
    w->child = NULL;
    w->next = NULL;
    w->fg[0] = 0x88;
    w->fg[1] = 0x88;
    w->fg[2] = 0x88;
    w->bg[0] = 0xFF;
    w->bg[1] = 0xFF;
    w->bg[2] = 0xFF;
    w->x = 0;
    w->y = 0;
    w->w = s_windsystemChar.weight;
    w->h = s_windsystemChar.style;
    w->flags = 0x40000000;
    w->font = D_00584B68;
    return 1;
}

void _guiwidgetPurge(GUIWIDGET *w) {
    switch (w->flags & 0xF) {
    case 8:
        GUI_List_removeAll();
        if (s_windsystem_data.mode == 1 && s_windsystem_data.cur == w) {
            s_windsystem_data.mode = 0;
            s_windsystem_data.cur = NULL;
        }
        break;
    case 9:
        GUI_Choice_removeAll();
        if (s_windsystem_data.mode == 2 && s_windsystem_data.cur == w) {
            s_windsystem_data.mode = 0;
            s_windsystem_data.cur = NULL;
        }
        if (s_windsystem_data.mode == 3 && s_windsystem_data.cur == w) {
            s_windsystem_data.mode = 0;
            s_windsystem_data.cur = NULL;
        }
        break;
    case 11:
        if (s_windsystem_data.mode == 4 && s_windsystem_data.cur == w) {
            s_windsystem_data.mode = 0;
            s_windsystem_data.cur = NULL;
        }
    case 10:
        if (w->unk50.n != 0) {
            ESP_guiMemFree(w->unk4C);
        }
        break;
    case 3:
        if (w->unk50.p != NULL) {
            ESP_guiMemFree(w->unk50.p);
        }
        break;
    case 1:
    case 4:
    case 6:
    case 7:
        if (w->unk4C != NULL) {
            ESP_guiMemFree(w->unk4C);
        }
        break;
    case 12:
        if (s_windsystem_data.unk28 == w) {
            s_windsystem_data.unk28 = NULL;
        }
        break;
    }
    _i_guiwidgetmalloc--;
    w->type = 0;
    w->parent = NULL;
    if (s_windsystem_data.focus == w) {
        s_windsystem_data.focus = NULL;
    }
    ESP_guiMemFree(w);
}

void _GuiwidgetDelete(GUIWIDGET *w) {
    if (w != NULL && w->type == 1) {
        _GuiwidgetDelete(w->child);
        _GuiwidgetDelete(w->next);
        _guiwidgetPurge(w);
    }
}

int GuiwidgetDelete(GUIWIDGET *w) {
    GUIWIDGET *parent;
    GUIWIDGET *p;

    if (w == NULL) {
        puts("[X1]GuiwidgetDelete");
        return 0;
    }
    if (w->type != 1) {
        puts("[X2]GuiwidgetDelete");
        return 0;
    }
    s_windsystem_data.flags |= 4;
    parent = w->parent;
    if (parent != NULL) {
        p = parent->child;
        if (p == w) {
            parent->child = w->next;
        } else {
            for (; p->next != w; p = p->next)
                ;
            p->next = w->next;
        }
    }
    _GuiwidgetDelete(w->child);
    _guiwidgetPurge(w);
    s_windsystem_data.flags &= ~4;
    return 1;
}

void GuiwidgetAllOpening(void) {
    if (s_windsystem_data.root != NULL) {
        GuiwidgetDelete(s_windsystem_data.root);
    }
    GuiwidgetInit();
}
