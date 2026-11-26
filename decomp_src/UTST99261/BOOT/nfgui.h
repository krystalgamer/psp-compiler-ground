#ifndef NFGUI_H
#define NFGUI_H
/* browser GUI layer (guifont, guigraphic, guipixmap, guiwidget, gui_*) */

int puts(const char *s);
void *ESP_guiMemAlloc(int size);
void ESP_guiMemFree(void *p);

typedef struct { /* size 0xC */
    s8 type;            /* 4 */
    u16 size;
    u16 weight;
    u16 style;
    int extra;
} GUIFONT;

typedef struct {
    u8 unk0[0x10];
    u16 weight;         /* 0x10 */
    u16 size;           /* 0x12 */
    u16 style;          /* 0x14 */
} WINDSYSTEMCHAR;

extern WINDSYSTEMCHAR s_windsystemChar;
extern int _i_guifontmalloc;

int GuifontClear(GUIFONT *font);

typedef struct { /* size 0x20 */
    s8 type;            /* 2 */
    int unk4;
    int color;          /* 0x8 */
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    u8 unk14[0xC];
} GUIGRAPHICS;

typedef struct { /* size 0x10 */
    s8 type;            /* 3 */
    int unk4;
    int kind;           /* 0x8 */
    void *data;         /* 0xC */
} GUIPIXMAP;

extern int _i_guigraphicsmalloc;
extern int _i_guipixmapmalloc;
extern int D_00584B68;

int GuigraphicsClear(GUIGRAPHICS *g);
int GuipixmapClear(GUIPIXMAP *p);

#endif
