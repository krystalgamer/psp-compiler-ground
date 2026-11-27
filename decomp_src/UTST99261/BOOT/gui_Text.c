/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfgui.h"

int GUI_TextField_setText(GUIWIDGET *w, char *s) {
    int len;
    char *buf;
    GUIWIDGET *t;

    if (w == NULL) {
        puts("[X1]GUI_TextField_setText");
        return -1;
    }
    t = w;
    if (w->type != 1) {
        puts("[X2]GUI_TextField_setText");
        return -1;
    }
    if ((w->flags & 0xF) != 10) {
        puts("[X3]GUI_TextField_setText");
        return -1;
    }
    len = 0;
    if (s != NULL) {
        len = strlen(s);
    }
    if (t->unk50.t.max != -1) {
        len = t->unk50.t.max < len ? t->unk50.t.max : len;
    }
    buf = NULL;
    if (len != 0) {
        buf = ESP_guiMemAlloc(len + 1);
        if (buf == NULL) {
            return -1;
        }
        memcpy(buf, s, len);
        buf[len] = 0;
    }
    if (t->unk50.t.len != 0) {
        ESP_guiMemFree(t->unk4C);
    }
    s_windsystem_data.flags |= 4;
    t->unk4C = buf;
    t->unk50.t.len = len;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

char *GUI_TextField_getText(GUIWIDGET *w) {
    int len;
    char *buf;
    GUIWIDGET *t;

    if (w == NULL) {
        puts("[X1]GUI_TextField_getText");
        return NULL;
    }
    t = w;
    if (w->type != 1) {
        puts("[X2]GUI_TextField_getText");
        return NULL;
    }
    if ((t->flags & 0xF) != 10) {
        puts("[X3]GUI_TextField_getText");
        return NULL;
    }
    len = *(short *)((char *)t + 0x50);
    buf = ESP_guiMemAlloc(len + 1);
    if (buf == NULL) {
        puts("[X5]GUI_TextField_getText");
        return NULL;
    }
    if (len != 0) {
        memcpy(buf, t->unk4C, len);
    }
    buf[len] = 0;
    return buf;
}

int GUI_TextField_select(GUIWIDGET *w, int start, int end) {
    if (w == NULL) {
        puts("[X1]GUI_TextField_select");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_TextField_select");
        return -1;
    }
    if ((w->flags & 0xF) != 10) {
        puts("[X3]GUI_TextField_select");
        return -1;
    }
    return 0;
}

int GUI_TextField_selectAll(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_TextField_selectAll");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_TextField_selectAll");
        return -1;
    }
    if ((w->flags & 0xF) != 10) {
        puts("[X3]GUI_TextField_selectAll");
        return -1;
    }
    return 0;
}

int GUI_TextField_getSelection(GUIWIDGET *w, int *start, int *end) {
    if (w == NULL) {
        puts("[X1]GUI_TextField_getSelection");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_TextField_getSelection");
        return -1;
    }
    if ((w->flags & 0xF) != 10) {
        puts("[X3]GUI_TextField_getSelection");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    *start = 0;
    *end = 0;
    s_windsystem_data.flags &= ~4;
    return 0;
}

char *GUI_TextField_getSelectedText(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_TextField_getSelectedText");
        return NULL;
    }
    if (w->type != 1) {
        puts("[X2]GUI_TextField_getSelectedText");
        return NULL;
    }
    if ((w->flags & 0xF) != 10) {
        puts("[X3]GUI_TextField_getSelectedText");
        return NULL;
    }
    return NULL;
}

int GUI_TextField_insert(GUIWIDGET *w, char *s, int start, int end) {
    if (w == NULL) {
        puts("[X1]GUI_TextField_insert");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_TextField_insert");
        return -1;
    }
    if ((w->flags & 0xF) != 10) {
        puts("[X3]GUI_TextField_insert");
        return -1;
    }
    return 0;
}

int GUI_TextField_setEditable(GUIWIDGET *w, int editable) {
    GUIWIDGET *t;

    if (w == NULL) {
        puts("[X1]GUI_TextField_setEditable");
        return -1;
    }
    t = w;
    if (w->type != 1) {
        puts("[X2]GUI_TextField_setEditable");
        return -1;
    }
    if ((w->flags & 0xF) != 10) {
        puts("[X3]GUI_TextField_setEditable");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    t->u.text.editable = editable | (t->u.text.editable & 0xFFFF0000);
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_TextField_setEchoChar(GUIWIDGET *w, int c) {
    GUIWIDGET *t;

    if (w == NULL) {
        puts("[X1]GUI_TextField_setEchoChar");
        return -1;
    }
    t = w;
    if (w->type != 1) {
        puts("[X2]GUI_TextField_setEchoChar");
        return -1;
    }
    if ((w->flags & 0xF) != 10) {
        puts("[X3]GUI_TextField_setEchoChar");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    t->u.text.editable |= 0x10000;
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_TextField_setMaxlength(GUIWIDGET *w, int max) {
    char *buf;
    GUIWIDGET *t;

    if (w == NULL) {
        puts("[X1]GUI_TextField_setMaxlength");
        return -1;
    }
    t = w;
    if (w->type != 1) {
        puts("[X2]GUI_TextField_setMaxlength");
        return -1;
    }
    if ((w->flags & 0xF) != 10) {
        puts("[X3]GUI_TextField_setMaxlength");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    if (t->unk50.t.len > 0) {
        buf = ESP_guiMemAlloc(max + 1);
        if (buf == NULL) {
            return -1;
        }
        memcpy(buf, t->unk4C, max);
        buf[max] = 0;
        ESP_guiMemFree(t->unk4C);
        t->unk4C = buf;
        t->unk50.t.len = max;
    }
    t->unk50.t.max = max;
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_TextArea_setText(GUIWIDGET *w, char *s) {
    int len;
    char *buf;
    GUIWIDGET *t;

    if (w == NULL) {
        puts("[X1]GUI_TextArea_setText");
        return -1;
    }
    t = w;
    if (w->type != 1) {
        puts("[X2]GUI_TextArea_setText");
        return -1;
    }
    if ((w->flags & 0xF) != 11) {
        puts("[X3]GUI_TextArea_setText");
        return -1;
    }
    if (s != NULL) {
        len = strlen(s);
    } else {
        len = 0;
    }
    buf = NULL;
    if (len != 0) {
        buf = ESP_guiMemAlloc(len + 1);
        if (buf == NULL) {
            puts("[X3]GUI_TextArea_setText");
            return -1;
        }
        memcpy(buf, s, len);
        buf[len] = 0;
    }
    if (t->unk50.t.len != 0) {
        ESP_guiMemFree(t->unk4C);
    }
    s_windsystem_data.flags |= 4;
    t->unk4C = buf;
    t->unk50.t.len = len;
    zWindDraw();
    s_windsystem_data.flags &= ~4;
    return 0;
}

char *GUI_TextArea_getText(GUIWIDGET *w) {
    int len;
    char *buf;
    GUIWIDGET *t;

    if (w == NULL) {
        puts("[X1]GUI_TextArea_getText");
        return NULL;
    }
    t = w;
    if (w->type != 1) {
        puts("[X2]GUI_TextArea_getText");
        return NULL;
    }
    if ((w->flags & 0xF) != 11) {
        puts("[X3]GUI_TextArea_getText");
        return NULL;
    }
    len = 0;
    if (t->unk4C != NULL) {
        len = strlen(t->unk4C);
    }
    buf = ESP_guiMemAlloc(len + 1);
    if (buf == NULL) {
        puts("[X4]GUI_TextArea_getText");
        return NULL;
    }
    s_windsystem_data.flags |= 4;
    if (len != 0) {
        memcpy(buf, t->unk4C, len);
    }
    buf[len] = 0;
    s_windsystem_data.flags &= ~4;
    return buf;
}

int GUI_TextArea_setSelection(GUIWIDGET *w, int start, int end) {
    if (w == NULL) {
        puts("[X1]GUI_TextArea_setSelection");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_TextArea_setSelection");
        return -1;
    }
    if ((w->flags & 0xF) != 11) {
        puts("[X3]GUI_TextArea_setSelection");
        return -1;
    }
    return 0;
}

int GUI_TextArea_getSelection(GUIWIDGET *w, int *start, int *end) {
    if (w == NULL) {
        puts("[X1]GUI_TextArea_getSelection");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_TextArea_getSelection");
        return -1;
    }
    if ((w->flags & 0xF) != 11) {
        puts("[X3]GUI_TextArea_getSelection");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    *start = 0;
    *end = 0;
    s_windsystem_data.flags &= ~4;
    return 0;
}

char *GUI_TextArea_getSelectedText(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_TextArea_getSelectedText");
        return NULL;
    }
    if (w->type != 1) {
        puts("[X2]GUI_TextArea_getSelectedText");
        return NULL;
    }
    if ((w->flags & 0xF) != 11) {
        puts("[X3]GUI_TextArea_getSelectedText");
        return NULL;
    }
    return NULL;
}

int GUI_TextArea_insert(GUIWIDGET *w, char *s, int start, int end) {
    if (w == NULL) {
        puts("[X1]GUI_TextArea_insert");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_TextArea_insert");
        return -1;
    }
    if ((w->flags & 0xF) != 11) {
        puts("[X3]GUI_TextArea_insert");
        return -1;
    }
    return 0;
}

int GUI_TextArea_setEditable(GUIWIDGET *w, int editable) {
    GUIWIDGET *t;

    if (w == NULL) {
        puts("[X1]GUI_TextArea_setEditable");
        return -1;
    }
    t = w;
    if (w->type != 1) {
        puts("[X2]GUI_TextArea_setEditable");
        return -1;
    }
    if ((w->flags & 0xF) != 11) {
        puts("[X3]GUI_TextArea_setEditable");
        return -1;
    }
    s_windsystem_data.flags |= 4;
    t->u.text.areaEditable = editable;
    s_windsystem_data.flags &= ~4;
    return 0;
}

int GUI_TextArea_selectAll(GUIWIDGET *w) {
    if (w == NULL) {
        puts("[X1]GUI_TextArea_selectAll");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_TextArea_selectAll");
        return -1;
    }
    if ((w->flags & 0xF) != 11) {
        puts("[X3]GUI_TextArea_selectAll");
        return -1;
    }
    return 0;
}
