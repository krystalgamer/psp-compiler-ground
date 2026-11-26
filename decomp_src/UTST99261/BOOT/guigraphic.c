/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfgui.h"

int GuigraphicsInit(void) {
    return 1;
}

int GuigraphicsExit(void) {
    return 1;
}

GUIGRAPHICS *GuigraphicsCreate(void) {
    GUIGRAPHICS *g;

    g = ESP_guiMemAlloc(sizeof(GUIGRAPHICS));
    if (g == NULL) {
        puts("[X1]GuigraphicsCreate");
        return NULL;
    }
    g->type = 2;
    GuigraphicsClear(g);
    _i_guigraphicsmalloc++;
    return g;
}

int GuigraphicsClear(GUIGRAPHICS *g) {
    if (g == NULL) {
        puts("[X1]GuigraphicsClear");
        return 0;
    }
    if (g->type != 2) {
        puts("[X2]GuigraphicsClear");
        return 0;
    }
    g->pixmap = NULL;
    g->x = 0;
    g->y = 0;
    g->ox = 0;
    g->oy = 0;
    g->font = D_00584B68;
    return 1;
}

int GuigraphicsDelete(GUIGRAPHICS *g) {
    if (g == NULL) {
        puts("[X1]GuigraphicsDelete");
        return 0;
    }
    if (g->type != 2) {
        puts("[X2]GuigraphicsDelete");
        return 0;
    }
    _i_guigraphicsmalloc--;
    g->type = 0;
    ESP_guiMemFree(g);
    return 1;
}
