#ifndef NFGUI_H
#define NFGUI_H
/* browser GUI layer (guifont, guigraphic, guipixmap, guiwidget, gui_*) */

int puts(const char *s);
void *ESP_guiMemAlloc(int size);
int strlen(const char *s);
void *memcpy(void *d, const void *s, unsigned int n);
void ESP_guiMemFree(void *p);

typedef struct { /* size 0xC */
    s8 type;            /* 4 */
    s16 size;
    s16 weight;
    s16 style;
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

typedef struct GUILISTITEM {
    int unk0;
    struct GUILISTITEM *next;
    char *text;                 /* 0x8 */
    s16 len;                    /* 0xC */
    s16 unkE;
    int state;                  /* 0x10 */
} GUILISTITEM;

typedef struct { /* size 0x10 */
    s8 type;            /* 3 */
    s16 w;              /* 0x2 */
    s16 h;              /* 0x4 */
    int kind;           /* 0x8 */
    void *data;         /* 0xC */
} GUIPIXMAP;

typedef struct { /* size 0x20 */
    s8 type;            /* 2 */
    GUIPIXMAP *pixmap;  /* 0x4 */
    GUIFONT *font;      /* 0x8 */
    s16 x;              /* 0xC */
    s16 y;
    s16 ox;             /* 0x10 */
    s16 oy;
    s16 clip[4];        /* 0x14 */
    int color;          /* 0x1C */
} GUIGRAPHICS;

extern int _i_guigraphicsmalloc;
extern int _i_guipixmapmalloc;
extern GUIFONT *D_00584B68;    /* default font */

int GuigraphicsClear(GUIGRAPHICS *g);
int GuigraphicsDelete(GUIGRAPHICS *g);
int GuipixmapDelete(GUIPIXMAP *p);
void zWindDrawClipSetTex();
extern int _zWindDrawTexClipOffX;
extern int _zWindDrawTexClipOffY;
extern int _zWindDrawTexClipOffAX;
extern int _zWindDrawTexClipOffAY;
int GuipixmapClear(GUIPIXMAP *p);

typedef struct GUIWIDGET { /* size 0x64 */
    s8 type;                    /* 1 */
    struct GUIWIDGET *parent;   /* 0x4 */
    struct GUIWIDGET *child;    /* 0x8 */
    struct GUIWIDGET *next;     /* 0xC */
    GUIFONT *font;              /* 0x10 */
    unsigned int flags;         /* 0x14: low 4 bits = kind */
    int fg[3];                  /* 0x18 */
    int bg[3];                  /* 0x24 */
    s16 fg15;                   /* 0x30 */
    s16 bg15;                   /* 0x32 */
    s16 focus15;                /* 0x34 */
    s16 unk36;
    s16 unk38;
    s16 x;                      /* 0x3A */
    s16 y;                      /* 0x3C */
    s16 w;                      /* 0x3E */
    s16 h;                      /* 0x40 */
    s16 dirty[4];               /* 0x42: x, y, w, h */
    void *unk4C;                /* text widgets: the text */
    union {
        void *p;
        s16 n;
        struct { s16 len; s16 max; } t;
    } unk50;
    union {
        struct {
            unsigned int editable;      /* 0x54 (TextField) */
            int areaEditable;           /* 0x58 (TextArea) */
        } text;
        struct {
            s16 sel;                    /* 0x54 */
            s16 unk56;
            s16 unk58;
        } choice;
        struct {
            int unk54;
            void *image;                /* 0x58 */
        } button;
        struct {
            int state;                  /* 0x54 */
            s16 unk58;
            s16 count;                  /* 0x5A */
            s16 unk5C;
        } list;
        struct {
            s16 x;                      /* 0x54 */
            s16 y;
            s16 cw;                     /* 0x58: content size */
            s16 ch;
            int hmode;                  /* 0x5C */
            int vmode;                  /* 0x60 */
        } scroll;
    } u;
} GUIWIDGET;

typedef struct {
    GUIWIDGET *root;            /* 0x0 */
    GUIWIDGET *focus;           /* 0x4 */
    int unk8;
    int flags;                  /* 0xC */
    int unk10;
    GUIWIDGET *top;             /* 0x14 */
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
    void *image;                /* 0x0: frame buffer */
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

GUIGRAPHICS *GUI_Graphics_createGraphics(GUIWIDGET *w);
GUIGRAPHICS *GuigraphicsCreate(void);
GUIPIXMAP *GuipixmapCreate(void);
GUIWIDGET *GuiwidgetCreate(GUIWIDGET *parent);
GUIPIXMAP *GUI_Graphics_createPixmap(int w, int h);
GUIGRAPHICS *GUI_Graphics_getGraphics(GUIGRAPHICS *g, GUIPIXMAP *pixmap);
void GUI_Graphics_freePixmap(GUIPIXMAP *pixmap);
int GUI_Graphics_freeGraphics(GUIGRAPHICS *g);
void dizInit(void);
int zWindDraw();
int GUI_ScrollPane_getScrollPosition(GUIWIDGET *w, int *x, int *y);
int GUI_ScrollPane_getViewportSize(GUIWIDGET *w, int *width, int *height);
void zWindExcEvent(GUIWIDGET *w, int type, GUIEVENT *ev, int a, int b);
GUIFONT *GuifontCreate(void);
int GuifontDelete(GUIFONT *font);

extern WINDSYSTEMDATA s_windsystem_data;
extern int _i_guiwidgetmalloc;

GUIFONT *GuifontCreateOne(void);
int GuiwidgetInit(void);
int GUI_Component_setColor(GUIWIDGET *w, int *fg, int *bg);
int GUI_Graphics_getStringSize(GUIFONT *font, char *s, int len, int *w, int *h);
int GuiwidgetClear(GUIWIDGET *w);
int GuiwidgetDelete(GUIWIDGET *w);
void GuiwidgetAllOpening(void);
int GUI_List_removeAll();
int GUI_Choice_removeAll();

#endif
