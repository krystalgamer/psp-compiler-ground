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

typedef struct GUIWIDGET { /* size 0x64 */
    s8 type;                    /* 1 */
    struct GUIWIDGET *parent;   /* 0x4 */
    struct GUIWIDGET *child;    /* 0x8 */
    struct GUIWIDGET *next;     /* 0xC */
    int color;                  /* 0x10 */
    unsigned int flags;         /* 0x14: low 4 bits = kind */
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    s16 unk34;
    s16 unk36;
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    int unk44;
    int unk48;
    void *unk4C;
    union { void *p; s16 n; } unk50;
    u8 unk54[0x10];
} GUIWIDGET;

typedef struct {
    GUIWIDGET *root;            /* 0x0 */
    GUIWIDGET *unk4;
    int unk8;
    int flags;                  /* 0xC */
    int unk10;
    int unk14;
    GUIFONT *font;              /* 0x18 */
    int unk1C;
    int mode;                   /* 0x20 */
    GUIWIDGET *cur;             /* 0x24 */
    GUIWIDGET *unk28;
    int unk2C;
    int unk30;
    int width;                  /* 0x34 */
    int height;                 /* 0x38 */
    void *pixmap;               /* 0x3C */
    void *graphics;             /* 0x40 */
    void *pixmap2;              /* 0x44 */
    void *graphics2;            /* 0x48 */
} WINDSYSTEMDATA;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int width;                  /* 0xC */
    int height;                 /* 0x10 */
} WINDSYSTEMINIT;

extern WINDSYSTEMINIT s_windsystem_init;

typedef struct {
    s16 type;
    GUIWIDGET *widget;
    int data;
} GUIEVENT;

void *GUI_Graphics_createGraphics(void);
void *GUI_Graphics_createPixmap(int w, int h);
void *GUI_Graphics_getGraphics(void *g, void *pixmap);
void GUI_Graphics_freePixmap(void *pixmap);
void GUI_Graphics_freeGraphics(void *g);
void dizInit(void);
void zWindExcEvent(GUIWIDGET *w, int type, GUIEVENT *ev, int a, int b);
GUIFONT *GuifontCreate(void);
int GuifontDelete(GUIFONT *font);

extern WINDSYSTEMDATA s_windsystem_data;
extern int _i_guiwidgetmalloc;

GUIFONT *GuifontCreateOne(void);
int GuiwidgetInit(void);
int GuiwidgetClear(GUIWIDGET *w);
int GuiwidgetDelete(GUIWIDGET *w);
void GuiwidgetAllOpening(void);
void GUI_List_removeAll(void);
void GUI_Choice_removeAll(void);

#endif
