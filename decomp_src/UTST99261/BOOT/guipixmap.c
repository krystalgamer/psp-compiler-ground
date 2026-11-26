/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfgui.h"

int GuipixmapInit(void) {
    return 1;
}

int GuipixmapExit(void) {
    return 1;
}

GUIPIXMAP *GuipixmapCreate(void) {
    GUIPIXMAP *p;

    p = ESP_guiMemAlloc(sizeof(GUIPIXMAP));
    if (p == NULL) {
        puts("[X1]GuipixmapCreate");
        return NULL;
    }
    p->type = 3;
    GuipixmapClear(p);
    _i_guipixmapmalloc++;
    return p;
}

int GuipixmapClear(GUIPIXMAP *p) {
    if (p == NULL) {
        puts("[X1]GuipixmapClear");
        return 0;
    }
    if (p->type != 3) {
        puts("[X2]GuipixmapClear");
        return 0;
    }
    p->kind = 0;
    p->data = NULL;
    return 1;
}

int GuipixmapDelete(GUIPIXMAP *p) {
    if (p == NULL) {
        puts("[X1]GuipixmapDelete");
        return 0;
    }
    if (p->type != 3) {
        puts("[X2]GuipixmapDelete");
        return 0;
    }
    if (p->kind == 0) {
        ESP_guiMemFree(p->data);
    }
    if (p->kind == 1) {
        ESP_guiMemFree(p->data);
    }
    p->type = 0;
    ESP_guiMemFree(p);
    _i_guipixmapmalloc--;
    return 1;
}
