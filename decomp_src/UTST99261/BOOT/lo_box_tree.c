/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int Node_getBox();                                  /* extern */
void htmlTagBranchAfter(int);                    /* extern */
int Util_HTMLDocument_getBody(int);                 /* extern */
void applyCSSExtStyleSheetToBox(int, int);       /* extern */
void applyCSSInlinePropertyToBox(int, int);      /* extern */
void attr_BACKGROUND(int, int);                  /* extern */
void attr_BGCOLOR(int, int);                     /* extern */
void attr_LINK(int, int);                        /* extern */
void attr_MARGINHEIGHT(int, int);                /* extern */
void attr_MARGINWIDTH(int, int);                 /* extern */
void attr_TEXT(int, int);                        /* extern */
void attr_VLINK(int, int);                       /* extern */
void nodeTreeLoop(void *, int);
int getTargetBodyBox();                             /* extern */


typedef struct TBPAGE { char *url; int len; int pad[15]; int x44; int pad2[8]; void *doc; void *body; } TBPAGE;
void *createBodyBox(TBPAGE *pg, int a, int b);
int HST_getSessionID(TBPAGE *pg);
int *getSessionSaveData(int id);
void *MEM_malloc(int, unsigned int);
void *memcpy(void *, const void *, unsigned int);
void *createBox(void *node, int type);
void linkBox(void *box, int a, int b);
void initBodyContent(void *box, void *node);
void initBoxProperty(void *box);
void Node_setBox(void *node, void *box);
void *lfm_createPageRegion(void *box, int w);
int Node_getParentNode(int node);
void *getBodyBox(void *box);
void *htmlTagBranch(int node, void *parent, void *last);
void addBoxList(void *list, void *data);
void *createBodyBox(TBPAGE *pg, int a, int b) {
    void *doc;
    void *box;

    doc = pg->doc;
    if (doc == NULL || Util_HTMLDocument_getBody((int)doc) == 0)
        return NULL;
    box = createBox(doc, 1);
    if (box == NULL)
        return NULL;
    linkBox(box, a, b);
    initBodyContent(box, doc);
    initBoxProperty(box);
    M2C_FIELD(box, s16 *, 0x3C) = 0;
    M2C_FIELD(box, s16 *, 0x3A) = 0xF;
    M2C_FIELD(box, int *, 0x18) = M2C_FIELD(M2C_FIELD(box, void **, 0x20), int *, 8);
    M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x28) = 0;
    M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x2A) = 0;
    M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x2C) = 0;
    M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x2E) = 0;
    Node_setBox(doc, box);
    pg->body = box;
    M2C_FIELD(M2C_FIELD(box, void **, 0x20), int *, 0x64) = pg->x44;
    if (M2C_FIELD(box, void **, 0x30) == NULL)
        M2C_FIELD(box, void **, 0x30) = lfm_createPageRegion(box, M2C_FIELD(M2C_FIELD(box, void **, 0x20), int *, 8));
    return box;
}

void nodeProc(int node) {
    void *parent;
    void *last;
    void *body;
    void *box;
    void *b;
    int n;

    if (node == 0)
        return;
    if (Node_getBox(node) != 0)
        return;
    parent = NULL;
    for (n = Node_getParentNode(node); n != 0; n = Node_getParentNode(n)) {
        parent = (void *)Node_getBox(n);
        if (parent != NULL)
            break;
    }
    if (parent == NULL)
        return;
    last = M2C_FIELD(parent, void **, 4);
    if (last != NULL) {
        while (M2C_FIELD(last, void **, 0xC) != NULL)
            last = M2C_FIELD(last, void **, 0xC);
    }
    if (M2C_FIELD(parent, short *, 0x38) == 1)
        body = parent;
    else
        body = getBodyBox(parent);
    if (body != NULL && M2C_FIELD(M2C_FIELD(body, void **, 0x20), int *, 0x88) == 1)
        return;
    box = htmlTagBranch(node, parent, last);
    if (box == NULL)
        return;
    if (M2C_FIELD(M2C_FIELD(box, void **, 0x24), s8 *, 0x71) != 0 || M2C_FIELD(M2C_FIELD(box, void **, 0x24), u8 *, 0x72) >= 2)
        addBoxList((char *)M2C_FIELD(body, void **, 0x20) + 0x9C, box);
    for (b = M2C_FIELD(box, void **, 0); b != NULL; b = M2C_FIELD(b, void **, 0)) {
        if (M2C_FIELD(b, short *, 0x38) == 4 || M2C_FIELD(b, short *, 0x38) == 6)
            M2C_FIELD(b, unsigned short *, 0x40) |= 1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void nodeProcAfter(int arg0) {
    if (arg0 != 0) {
        if (Node_getBox() != 0) {
            htmlTagBranchAfter(arg0);
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_tree", nodeTreeLoop);

#ifndef NULL
#define NULL ((void *)0)
#endif

void makeBodyBoxTree(void *arg0, int arg1, int arg2) {
    int temp_s2;
    int temp_v0;

    temp_s2 = M2C_FIELD(arg0, int *, 0x68);
    temp_v0 = Util_HTMLDocument_getBody(temp_s2);
    if (temp_v0 != 0) {
        attr_MARGINWIDTH(temp_v0, arg1);
        attr_MARGINHEIGHT(temp_v0, arg1);
        attr_BGCOLOR(temp_v0, arg1);
        attr_BACKGROUND(temp_v0, arg1);
        attr_TEXT(temp_v0, arg1);
        attr_LINK(temp_v0, arg1);
        attr_VLINK(temp_v0, arg1);
        applyCSSExtStyleSheetToBox(temp_v0, arg1);
        applyCSSInlinePropertyToBox(temp_v0, arg1);
    }
    nodeTreeLoop(temp_s2, arg2);
}

int getTargetBodyBox(pg)
    TBPAGE *pg;
{
    void *b;
    char *s;
    int *d;
    void *g;

    if (pg->body != NULL)
        return (int)pg->body;
    b = createBodyBox(pg, 0, 0);
    if (b == NULL)
        return 0;
    M2C_FIELD(M2C_FIELD(b, void **, 0x20), TBPAGE **, 0x20) = pg;
    M2C_FIELD(M2C_FIELD(b, void **, 0x20), int *, 0x64) = pg->x44;
    s = MEM_malloc(0, pg->len + 1);
    memcpy(s, pg->url, pg->len);
    s[pg->len] = 0;
    M2C_FIELD(M2C_FIELD(b, void **, 0x20), char **, 0x28) = s;
    g = M2C_FIELD(b, void **, 0x20);
    M2C_FIELD(g, int *, 0x38) = HST_getSessionID(pg);
    d = getSessionSaveData(HST_getSessionID(pg));
    if (d != NULL) {
        M2C_FIELD(M2C_FIELD(b, void **, 0x20), int *, 0x18) = d[1];
        M2C_FIELD(M2C_FIELD(b, void **, 0x20), int *, 0x1C) = d[2];
    }
    return (int)b;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void makeBoxTree(void *arg0, int arg1) {
    int temp_v0;

    temp_v0 = getTargetBodyBox();
    if (temp_v0 != 0) {
        if (M2C_FIELD(arg0, int *, 0x6C) == 0) {
            M2C_FIELD(arg0, int *, 0x6C) = temp_v0;
        }
        makeBodyBoxTree(arg0, temp_v0, arg1);
    }
}
