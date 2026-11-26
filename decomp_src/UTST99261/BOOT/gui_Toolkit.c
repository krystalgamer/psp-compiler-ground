/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfgui.h"

int GUI_Toolkit_initializeSystem(GUIWIDGET *w, int arg1) {
    if (w == NULL) {
        puts("[X1]GUI_Toolkit_initializeSystem");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Toolkit_initializeSystem");
        return -1;
    }
    s_windsystem_data.top = w;
    s_windsystem_data.unk10 = arg1;
    s_windsystem_data.unk1C = (int)GUI_Graphics_createGraphics();
    s_windsystem_data.width = s_windsystem_init.width;
    s_windsystem_data.height = s_windsystem_init.height;
    s_windsystem_data.pixmap = GUI_Graphics_createPixmap(s_windsystem_init.width, s_windsystem_init.height);
    if (s_windsystem_data.pixmap == NULL) {
        puts("[X3]GUI_Toolkit_initializeSystem");
        return -1;
    }
    s_windsystem_data.graphics = GUI_Graphics_getGraphics(NULL, s_windsystem_data.pixmap);
    if (s_windsystem_data.graphics == NULL) {
        GUI_Graphics_freePixmap(s_windsystem_data.pixmap);
        s_windsystem_data.pixmap = NULL;
        puts("[X4]GUI_Toolkit_initializeSystem");
        return -1;
    }
    s_windsystem_data.pixmap2 = NULL;
    s_windsystem_data.graphics2 = NULL;
    dizInit();
    return 0;
}

void GUI_Toolkit_terminateSystem(void) {
    void *p;

    if ((p = s_windsystem_data.graphics) != NULL) {
        s_windsystem_data.graphics = NULL;
        GUI_Graphics_freeGraphics(p);
    }
    if ((p = s_windsystem_data.graphics2) != NULL) {
        s_windsystem_data.graphics2 = NULL;
        GUI_Graphics_freeGraphics(p);
    }
    if ((p = s_windsystem_data.pixmap) != NULL) {
        s_windsystem_data.pixmap = NULL;
        GUI_Graphics_freePixmap(p);
    }
    if ((p = s_windsystem_data.pixmap2) != NULL) {
        s_windsystem_data.pixmap2 = NULL;
        GUI_Graphics_freePixmap(p);
    }
}

void GUI_Toolkit_getScreenSize(int *w, int *h) {
    *w = s_windsystem_init.width;
    *h = s_windsystem_init.height;
}

GUIFONT *GUI_Toolkit_loadFont(char *name, int size, int extra) {
    GUIFONT *font;

    font = GuifontCreate();
    font->size = s_windsystemChar.size;
    font->weight = s_windsystemChar.weight;
    font->style = s_windsystemChar.style;
    font->extra = extra;
    return font;
}

void GUI_Toolkit_freeFont(GUIFONT *font) {
    if (font == NULL) {
        puts("[X1]GUI_Toolkit_freeFont");
        return;
    }
    if (font->type != 4) {
        puts("[X2]GUI_Toolkit_freeFont");
        return;
    }
    GuifontDelete(font);
}

int GUI_Toolkit_postEvent(GUIWIDGET *w, int type, int data) {
    GUIEVENT ev;

    if (w == NULL) {
        puts("[X1]GUI_Toolkit_postEvent");
        return -1;
    }
    if (w->type != 1) {
        puts("[X2]GUI_Toolkit_postEvent");
        return -1;
    }
    ev.type = type;
    ev.widget = w;
    ev.data = data;
    zWindExcEvent(w, type, &ev, -1, -1);
    return 0;
}

void GUI_Toolkit_mutexLock(void) {
    s_windsystem_data.flags |= 8;
}

void GUI_Toolkit_mutexUnlock(void) {
    s_windsystem_data.flags &= ~8;
}
