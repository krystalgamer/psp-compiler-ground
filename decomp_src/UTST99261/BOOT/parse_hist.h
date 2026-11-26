/* history (HST_*) types, recovered from the asm */
#ifndef PARSE_HIST_H
#define PARSE_HIST_H

typedef struct HstStr {
    char *p;
    int len;
} HstStr;

typedef struct HstFrag {
    struct HstFrag *next;
    struct HstFrag **prev;
    int a;
    int b;
    int c;
    char *name;
} HstFrag;

typedef struct HstNode {
    HstStr uri;                 /* 0x00 */
    HstStr s08;                 /* 0x08 */
    int x10;
    int x14;
    int x18;
    int x1C;
    HstStr s20;                 /* 0x20 */
    HstStr s28;                 /* 0x28 */
    int x30;
    int x34;
    int x38;
    int flag;                   /* 0x3C */
    int x40;
    int x44;
    int x48;
    int x4C[7];
    void *doc;                  /* 0x68 */
    int x6C;
    void *css;                  /* 0x70 */
    int x74;
    int x78;
    int x7C;
    int x80;
    int x84[8];
    int xA4;
    struct HstNode *parent;     /* 0xA8 */
    struct HstNode *child;      /* 0xAC */
    struct HstNode *next;       /* 0xB0 */
} HstNode;

void freeFragmentIDs(void *f);
void *searchHistoryNodeInner(int type, void *a, void *b);

#endif
