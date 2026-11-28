#ifndef NFLAYOUT_H
#define NFLAYOUT_H
/* browser layout engine (layoutMain, lo_*): only the fields used so far */

#include "lo_box.h"

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
    u8 unk40[0x8];
    int timer;                  /* 0x48 */
    u8 unk4C[0x8];
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
