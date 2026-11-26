#ifndef NFLAYOUT_H
#define NFLAYOUT_H
/* browser layout engine (layoutMain, lo_*): only the fields used so far */

typedef struct {
    int x;
    int y;
    u8 unk8[0x38];
    int unk40;
} BOXGEOM;

typedef struct {
    u8 unk0[0x14];
    unsigned int flags;         /* 0x14: bits 2-3 height type */
    u8 unk18[0xA];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
} BOXSTYLE;

typedef struct BOX {
    struct BOX *parent;         /* 0x0 */
    u8 unk4[0x14];
    int width;                  /* 0x18 */
    int unk1C;
    BOXGEOM *geom;              /* 0x20 */
    BOXSTYLE *style;            /* 0x24 */
    u8 unk28[0x8];
    void *region;               /* 0x30 */
    u8 unk34[0x4];
    s16 content;                /* 0x38: 1 body, 2 frameset, 4 table, 5 tr, 6 td, 8 list, 17 ... */
    s16 html;                   /* 0x3A */
    s16 display;                /* 0x3C */
} BOX;

typedef struct LISTNODE {
    struct LISTNODE *next;
    struct LISTNODE *prev;
    void *data;
} LISTNODE;

typedef struct {
    LISTNODE *head;
    LISTNODE *tail;
    int count;
} LIST;

typedef struct {
    u8 unk0[0x6C];
    BOX *body;                  /* 0x6C */
} HISTNODE;

typedef struct {
    unsigned int flags;         /* 0x0 */
    u8 unk4[0x10];
    void *img14;                /* 0x14: default images */
    void *img18;
    u8 unk1C[0x8];
    void *img24;
    void *img28;
    void *img2C;
    u8 unk30[0xC];
    int session;                /* 0x3C */
    u8 unk40[0x14];
    int unk54;
    u8 unk58[0x10];
    int unk68;
    int unk6C;
} LOGLOBAL;

typedef struct {
    u8 unk0[0x10];
    int unk10;
    u8 unk14[0x10];
    int unk24;                  /* 0x24: font index */
    u8 unk28[0x20];
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
} PREFUI;

typedef struct {
    int color[4][7];
    int font;                   /* 0x70 */
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
} UIGLOBAL;

typedef struct {
    int color[4 * 7];
    int unk70;
    int unk74;
} UIINS;

extern LOGLOBAL lo_global;
extern PREFUI *gPREF_UI;
extern UIGLOBAL *ui_global;
extern UIINS *ui_ins;
extern UIINS *gBEINSI_UI;
extern int *gESPRIT_LO_GLOBAL_NDA;

void *MEM_malloc(void *pool, unsigned int size);
void MEM_free(void *pool, void *p);
int strcmp(const char *a, const char *b);
BOX *getBodyBox(BOX *box);
char *URL_toAbsoluteURL(char *base, char *url);
HISTNODE *HST_searchSessionIDHistoryNode(int id);
HISTNODE *HST_getHeadHistoryNode(void);
int checkBoxValidity(BOX *box);
void initBoxList(LIST *list);
void addBoxList(LIST *list, void *data);
int searchUrlList(LIST *list, char *url);

#endif
