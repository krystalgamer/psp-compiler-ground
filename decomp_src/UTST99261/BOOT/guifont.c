/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfgui.h"

int GuifontInit(void) {
    return 1;
}

int GuifontExit(void) {
    return 1;
}

GUIFONT *GuifontCreate(void) {
    GUIFONT *font;

    font = ESP_guiMemAlloc(sizeof(GUIFONT));
    if (font == NULL) {
        puts("[X1]GuifontCreate");
        return NULL;
    }
    font->type = 4;
    GuifontClear(font);
    _i_guifontmalloc++;
    return font;
}

GUIFONT *GuifontCreateOne(void) {
    GUIFONT *font;

    font = ESP_guiMemAlloc(sizeof(GUIFONT));
    if (font == NULL) {
        puts("[X1]GuifontCreate");
        return NULL;
    }
    font->type = 4;
    font->size = s_windsystemChar.size;
    font->weight = s_windsystemChar.weight;
    font->style = s_windsystemChar.style;
    font->extra = 0;
    GuifontClear(font);
    _i_guifontmalloc++;
    return font;
}

int GuifontClear(GUIFONT *font) {
    if (font == NULL) {
        puts("[X1]GuifontClear");
        return 0;
    }
    if (font->type != 4) {
        puts("[X2]GuifontClear");
        return 0;
    }
    return 1;
}

int GuifontDelete(GUIFONT *font) {
    return 1;
}
