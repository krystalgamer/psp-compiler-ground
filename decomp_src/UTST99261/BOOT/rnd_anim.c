/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char _DOMa;
extern unsigned char _DOMhref;
void *Util_getNodeByTagName(void *node, void *tag);
int Element_hasAttribute(void *node, void *name);
void *Node_getParentNode(void *node);
void *getBodyBox(void *);
M2C_UNK *MEM_malloc(M2C_UNK, M2C_UNK);              /* extern */
extern M2C_UNK *head;
void MEM_free(M2C_UNK, void *);                  /* extern */
int Node_getBox(int);                               /* extern */
M2C_UNK drawScroll(int, int, int);                  /* extern */
extern void *gESPRIT_LO_GLOBAL_NDA;

void clearSearchStrings();                       /* extern */
M2C_UNK searchStrings();                            /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
typedef struct RPOS { int x; int y; } RPOS;
void *rnd_findParentBoxnode(void *bn, int type);
int GUI_ScrollPane_getScrollPosition(void *pane, int *x, int *y);
void rnd_gdrawGetViewClientSize(void *pane, int *w, int *h);
typedef struct RLIST { struct RLIST *next; void *data; void *x8; void *xC; } RLIST;
typedef struct RNDGLOBAL { int x0; int x4; int x8; RLIST *xC; RLIST *x10; RLIST *x14; } RNDGLOBAL;
extern RNDGLOBAL rnd_global;
extern void *ui_global;
int OS_clock_gettime(int id, RPOS *ts);
int rnd_gdrawImageReset(void *img, RPOS *t);
int rnd_resetAnimImageBoxnode(void *bn);
int rnd_updateAnimTextBoxnode(void *bn);
int GUI_Component_update(void *c, int x, int y, int w, int h);
typedef struct RRECT { int x; int y; int w; int h; } RRECT;
extern const unsigned int D_00139028[];
int rnd_updateAnimMarqueeBoxnode(void *bn, RPOS *t);
int rnd_gdrawImageUpdate(void *img, RPOS *t);
int rnd_updateAnimImageBoxnode(void *bn);
void rnd_updateUpdateWidgetList(void);
void rnd_clearUpdateWidgetList(void);
typedef struct UWNODE { struct UWNODE *next; void *pane; RRECT *rect; } UWNODE;
int GUI_ScrollPane_getViewportSize(void *pane, int *w, int *h);
typedef struct MARQUEE { int dir; int pos; int start; int len; int amount; int x14; int interval; RPOS t; int x24; } MARQUEE;
typedef struct MARQATTR { int behavior; int direction; int amount; } MARQATTR;
typedef struct RDOMSTR { void *p; int len; int x8; int xC; } RDOMSTR;
extern unsigned char _DOMid;
extern unsigned char _DOMname;
int Node_getNodeType(int node);
int Element_getTagName(RDOMSTR *ret, int node);
int Element_getAttribute(RDOMSTR *ret, int node, void *name);
int DOMStringcasecmpFast(RDOMSTR *a, void *b);
char *DOMStringtoUTF8(RDOMSTR *s);
int strcmp(const char *, const char *);
int Util_Node_TraceNode(int node, int root);
int rnd_resetAnimMarqueeBoxnode(void *bn, RPOS *pos);
int checkParentBox(M2C_UNK *arg0, int arg1) {
    M2C_UNK *var_a0;
    int var_v0;

    var_a0 = arg0;
    var_v0 = 1;
    if (var_a0 != arg1) {
        var_v0 = 0;
        if (var_a0 != NULL) {
loop_2:
            var_a0 = *var_a0;
            var_v0 = 1;
            if (var_a0 != arg1) {
                if (var_a0 == NULL) {
                    var_v0 = 0;
                } else {
                    goto loop_2;
                }
            }
        }
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_deleteAnimBoxnode);

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_addUpdateWidgetList(int arg0, int arg1) {
    M2C_UNK *temp_v0;
    M2C_UNK *temp_v0_2;
    M2C_UNK *var_s0;
    M2C_UNK *var_v0;

    var_s0 = NULL;
    if (head == NULL) {
        temp_v0 = MEM_malloc(0, 0xC);
        head = temp_v0;
        *temp_v0 = NULL;
        M2C_FIELD(head, int *, 4) = 0;
        M2C_FIELD(head, int *, 8) = 0;
        var_s0 = head;
    }
    var_v0 = M2C_FIELD(head, M2C_UNK **, 0);
    if (var_v0 != NULL) {
        do {
            var_s0 = var_v0;
            var_v0 = *var_v0;
        } while (var_v0 != NULL);
    }
    temp_v0_2 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK **, 0) = NULL;
    M2C_FIELD(temp_v0_2, int *, 4) = arg0;
    M2C_FIELD(temp_v0_2, int *, 8) = arg1;
    *var_s0 = temp_v0_2;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_clearUpdateWidgetList(void) {
    void *temp_a1;
    void *temp_s1;
    void *var_s0;

    var_s0 = head;
    if (var_s0 != NULL) {
        do {
            temp_a1 = M2C_FIELD(var_s0, void **, 8);
            temp_s1 = M2C_FIELD(var_s0, void **, 0);
            if (temp_a1 != NULL) {
                MEM_free(0, temp_a1);
            }
            MEM_free(0, var_s0);
            var_s0 = temp_s1;
        } while (temp_s1 != NULL);
    }
    head = NULL;
}

void rnd_updateUpdateWidgetList(void) {
    UWNODE *n;
    int pane;
    int x0, y0, x1, y1;
    int sx, sy, vw, vh;

    pane = 0;
    if (head == NULL)
        return;
    n = *(UWNODE **)head;
    x0 = y0 = x1 = y1 = -1;
    for (; n != NULL; n = n->next) {
        pane = (int)n->pane;
        if (n->rect != NULL) {
            if (x0 < 0 || n->rect->x < x0)
                x0 = n->rect->x;
            if (y0 < 0 || n->rect->y < y0)
                y0 = n->rect->y;
            if (x1 < 0 || x1 < n->rect->x + n->rect->w)
                x1 = n->rect->x + n->rect->w;
            if (y1 < 0 || y1 < n->rect->y + n->rect->h)
                y1 = n->rect->y + n->rect->h;
        } else {
            if (x0 < 0)
                x0 = 0;
            if (y0 < 0)
                y0 = 0;
            if (x1 < 0)
                x1 = 0;
            if (y1 < 0)
                y1 = 0;
        }
    }
    if (pane != 0) {
    GUI_ScrollPane_getScrollPosition((void *)pane, &sx, &sy);
    GUI_ScrollPane_getViewportSize((void *)pane, &vw, &vh);
    if (x0 < sx)
        x0 = sx;
    if (y0 < sy)
        y0 = sy;
    if (x1 > sx + vw)
        x1 = sx + vw;
    if (y1 > sy + vh)
        y1 = sy + vh;
    GUI_Component_update((void *)pane, x0, y0, x1 - x0, y1 - y0);
    }
}

void rnd_updateAnimBoxnode(void) {
    RPOS now;
    RPOS d;
    RPOS ts;
    int changed;
    int flip;
    RLIST *l;
    RLIST *m;
    void *pane;
    RRECT *r;

    changed = 0;
    flip = 0;
    OS_clock_gettime(0, &ts);
    now = ts;
    for (l = rnd_global.x14; l != NULL; l = l->next) {
        changed |= rnd_updateAnimMarqueeBoxnode(l->data, &now);
        pane = M2C_FIELD(getBodyBox(l->data), void **, 0x2C);
        r = MEM_malloc(0, 0x10);
        r->x = M2C_FIELD(l->data, int *, 0x10);
        r->y = M2C_FIELD(l->data, int *, 0x14);
        r->w = M2C_FIELD(l->data, int *, 0x18);
        r->h = M2C_FIELD(l->data, int *, 0x1C);
        rnd_addUpdateWidgetList((int)pane, (int)r);
    }
    for (m = rnd_global.x10; m != NULL; m = m->next) {
        if (rnd_gdrawImageUpdate(m->data, &now) == 1) {
            for (l = m->x8; l != NULL; l = l->next) {
                if (rnd_updateAnimImageBoxnode(l->data) != 0) {
                    pane = M2C_FIELD(getBodyBox(l->data), void **, 0x2C);
                    r = MEM_malloc(0, 0x10);
                    r->x = M2C_FIELD(l->data, int *, 0x10);
                    r->y = M2C_FIELD(l->data, int *, 0x14);
                    r->w = M2C_FIELD(l->data, int *, 0x18);
                    r->h = M2C_FIELD(l->data, int *, 0x1C);
                    rnd_addUpdateWidgetList((int)pane, (int)r);
                    changed = 1;
                }
            }
        }
    }
    if (now.y >= rnd_global.x8) {
        d.x = now.x - rnd_global.x4;
        d.y = now.y - rnd_global.x8;
    } else {
        d.x = now.x - rnd_global.x4 - 1;
        d.y = now.y - rnd_global.x8 + 1000000000;
    }
    if (d.x * 1000 + d.y / 1000000 >= D_00139028[rnd_global.x0])
        flip = 1;
    if (flip == 1) {
        rnd_global.x0 ^= 1;
        rnd_global.x4 = now.x;
        rnd_global.x8 = now.y;
        for (l = rnd_global.xC; l != NULL; l = l->next) {
            changed |= rnd_updateAnimTextBoxnode(l->data);
            pane = M2C_FIELD(getBodyBox(l->data), void **, 0x2C);
            r = MEM_malloc(0, 0x10);
            r->x = M2C_FIELD(l->data, int *, 0x10);
            r->y = M2C_FIELD(l->data, int *, 0x14);
            r->w = M2C_FIELD(l->data, int *, 0x18);
            r->h = M2C_FIELD(l->data, int *, 0x1C);
            rnd_addUpdateWidgetList((int)pane, (int)r);
        }
    }
    if (changed)
        rnd_updateUpdateWidgetList();
    rnd_clearUpdateWidgetList();
}

void rnd_resetAnimBoxnode(void) {
    RPOS now;
    RPOS ts;
    int changed;
    RLIST *l;
    RLIST *m;

    changed = 0;
    OS_clock_gettime(0, &ts);
    now = ts;
    for (l = rnd_global.x14; l != NULL; l = l->next)
        changed |= rnd_resetAnimMarqueeBoxnode(l->data, &now);
    for (m = rnd_global.x10; m != NULL; m = m->next) {
        if (rnd_gdrawImageReset(m->data, &now) == 1) {
            for (l = m->x8; l != NULL && !changed; l = l->next)
                changed |= rnd_resetAnimImageBoxnode(l->data);
        }
    }
    l = rnd_global.xC;
    if (l != NULL) {
        rnd_global.x0 = 1;
        rnd_global.x8 = now.y;
        for (; l != NULL && !changed; l = l->next)
            changed |= rnd_updateAnimTextBoxnode(l->data);
    }
    if (changed)
        GUI_Component_update(M2C_FIELD(ui_global, void **, 0x90), 0, 0, 0, 0);
}

int rnd_newMarquee(void *box, void *anim) {
    MARQUEE *m;
    void *c;
    int w;
    int bw;

    m = MEM_malloc(0, 0x28);
    if (m == NULL)
        return -100;
    w = 0;
    for (c = M2C_FIELD(box, void **, 4); c != NULL; c = M2C_FIELD(c, void **, 0xC)) {
        if (w < M2C_FIELD(c, int *, 0x10) + M2C_FIELD(c, int *, 0x18))
            w = M2C_FIELD(c, int *, 0x10) + M2C_FIELD(c, int *, 0x18);
    }
    w -= M2C_FIELD(box, int *, 0x10);
    bw = M2C_FIELD(box, int *, 0x18);
    if (M2C_FIELD(box, MARQATTR **, 0x20)->behavior == 1) {
        RPOS ts;
        if (M2C_FIELD(box, MARQATTR **, 0x20)->direction == 1) {
            m->dir = -2;
            m->start = bw;
        } else {
            m->dir = 2;
            m->start = -w;
        }
        m->pos = m->start;
        m->len = w + bw;
        m->amount = M2C_FIELD(box, MARQATTR **, 0x20)->amount;
        m->x14 = 0;
        m->interval = 50000000;
        OS_clock_gettime(0, &ts);
        m->t = ts;
    } else if (M2C_FIELD(box, MARQATTR **, 0x20)->behavior == 2) {
        RPOS ts;
        if (M2C_FIELD(box, MARQATTR **, 0x20)->direction == 1) {
            m->dir = -2;
            m->start = bw;
        } else {
            m->dir = 2;
            m->start = -w;
        }
        m->pos = m->start;
        m->len = bw < w ? w : bw;
        m->amount = M2C_FIELD(box, MARQATTR **, 0x20)->amount;
        m->x14 = 0;
        m->interval = 50000000;
        OS_clock_gettime(0, &ts);
        m->t = ts;
    } else {
        RPOS ts;
        if (M2C_FIELD(box, MARQATTR **, 0x20)->direction == 1) {
            m->dir = -2;
            m->start = bw < w ? 0 : bw - w;
        } else {
            m->dir = 2;
            m->start = bw < w ? bw - w : 0;
        }
        m->pos = m->start;
        m->len = bw < w ? w - bw : bw - w;
        m->amount = M2C_FIELD(box, MARQATTR **, 0x20)->amount;
        m->amount = M2C_FIELD(box, MARQATTR **, 0x20)->amount;
        m->x14 = 0;
        m->interval = 50000000;
        OS_clock_gettime(0, &ts);
        m->t = ts;
    }
    m->x24 = 0;
    M2C_FIELD(box, MARQUEE **, 0x2C) = m;
    M2C_FIELD(anim, MARQUEE **, 0xC) = m;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_updateAnimMarqueeBoxnode);

int rnd_resetAnimMarqueeBoxnode(void *bn, RPOS *pos) {
    RPOS p;
    void *a;
    void *par;
    int sx, sy, w, h;

    p = *pos;
    a = M2C_FIELD(bn, void **, 0x2C);
    if (a == NULL)
        return 0;
    M2C_FIELD(a, int *, 0x1C) = p.x;
    M2C_FIELD(a, int *, 0x20) = p.y;
    M2C_FIELD(a, int *, 4) = M2C_FIELD(a, int *, 8);
    par = rnd_findParentBoxnode(bn, 1);
    if (par == NULL)
        return 0;
    GUI_ScrollPane_getScrollPosition(M2C_FIELD(par, void **, 0x2C), &sx, &sy);
    rnd_gdrawGetViewClientSize(M2C_FIELD(par, void **, 0x2C), &w, &h);
    return sx < M2C_FIELD(bn, int *, 0x10) + M2C_FIELD(bn, int *, 0x18)
        && M2C_FIELD(bn, int *, 0x10) < sx + w
        && sy < M2C_FIELD(bn, int *, 0x14) + M2C_FIELD(bn, int *, 0x1C)
        && M2C_FIELD(bn, int *, 0x14) < sy + h;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void actClearSearchString(void) {
    clearSearchStrings();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void actSearchString(void) {
    searchStrings();
}

void freeScrollStart(void *box, int x, int y) {
    void *body = getBodyBox(box);
    int *g = gESPRIT_LO_GLOBAL_NDA;
    g[1] = M2C_FIELD(body, int *, 0x28);
    g[2] = x;
    g[3] = y;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeScroll(int arg0, int arg1) {
    int temp_a0;
    int temp_s1;
    int temp_s2;
    void *temp_s0;

    temp_s0 = gESPRIT_LO_GLOBAL_NDA;
    temp_s2 = arg0 - M2C_FIELD(temp_s0, int *, 8);
    temp_s1 = arg1 - M2C_FIELD(temp_s0, int *, 0xC);
    temp_a0 = Node_getBox(M2C_FIELD(temp_s0, int *, 4));
    if ((temp_s2 | temp_s1) != 0) {
        drawScroll(temp_a0, -temp_s2, -temp_s1);
        M2C_FIELD(temp_s0, int *, 8) = arg0;
        M2C_FIELD(temp_s0, int *, 0xC) = arg1;
    }
}

int searchDestinationAnchor(int root, char *name) {
    int node;
    RDOMSTR tag;
    RDOMSTR attr;
    char *s;

    node = root;
    do {
        if (Node_getNodeType(node) == 1) {
            Element_getTagName(&tag, node);
            if (DOMStringcasecmpFast(&tag, &_DOMa) == 0) {
                Element_getAttribute(&attr, node, &_DOMname);
                if (attr.len == 0)
                    Element_getAttribute(&attr, node, &_DOMid);
            } else {
                Element_getAttribute(&attr, node, &_DOMid);
            }
            if (attr.len != 0) {
                s = DOMStringtoUTF8(&attr);
                if (strcmp(s, name) == 0 || (*s == '#' && strcmp(s + 1, name) == 0)) {
                    MEM_free(0, s);
                    return node;
                }
                MEM_free(0, s);
            }
        }
    } while ((node = Util_Node_TraceNode(node, root)) != 0);
    return 0;
}

void *getAncestorLink(void *node) {
    while (node != NULL) {
        node = Util_getNodeByTagName(node, &_DOMa);
        if (node == NULL) {
            return NULL;
        }
        if (Element_hasAttribute(node, &_DOMhref)) {
            return node;
        }
        node = Node_getParentNode(node);
    }
    return NULL;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", D_00139028);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", actLinkJumpInner);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", actLinkJump);
