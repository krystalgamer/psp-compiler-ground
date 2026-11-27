/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "lo_focus.h"
#include "m2c_macros.h"
void *Node_getFirstChild(void *);
void *Node_getNextSibling(void *);
HISTNODE *HST_getChildHistoryNode(HISTNODE *);
int HST_getRequestFlag(HISTNODE *);
void *Node_getJSObj(void *);
void *Node_getParentNode(void *);
void *getMapList(void *, void *);
void *getAreaList(void *, void *, int, int);
int actDefaultClickAction(void *frame, void *box, void *a2, int a3, int t0);
void actLinkJump(void *frame, void *link, int a2);


void *getSelectListFromGadget(void *g);
void *getAncestorForm(void *n);
void *getPreviousForm(void *n);
int actFormInput(void *ev, void *box, void *sel, int kind);
BOX *lo_getActiveFrameBodybox(void);
void getTextSelectionRange(BOX *box, int *start, int *end);
void replaceTextStrings(BOX *box, char *s, int start, int end);
char *strchr(const char *s, int c);
void *make_msg_LP19(void *ev, int x, int y, int a, int b, int c, int d);
typedef struct { u8 unk0[0x30]; } LEHJSEVENT;
void initJSEvent(LEHJSEVENT *ev, int type, void *node, int a, int b);
int sendJSEvent(void *obj, LEHJSEVENT *ev);
void *getDOMDocument(void *node);
void actSetFocusByBox(void *frame, void *box, int arg);
int scrollToFocusPosition();
void *getBox_fromAccessKey(void *body, u16 key);
extern int D_00584CEC;
int isFocusInDisplay(void *frame, FOCUSLIST *l);
typedef struct { int sid; u8 u4[0xC]; int x10; BOX *x14; void *x18; u8 u1C[0xC]; BOX *x28; int x2C; int x30; int x34; int x38; } LEHG;
typedef struct { int u0; int x4; int x; int y; } LEHPT;
void *startBorder(BOX *box);
void freeScrollStart(BOX *box, int x, int y);
BOX *getTargetBox(BOX *box, int x, int y, int k);
void *Node_getOwnerDocument(void *node);
void moveBorder(void *b, int dx, int dy);
void freeScroll(int x, int y);
int sendJSBubbleUpEvent(void *node, LEHJSEVENT *ev);
int handlePointingMove(void *ev);
int handlePointingDown(void *ev);
int handlePointingUp(void *ev);
int handlePointingCheck(void *ev);
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", getTargetBox);

void *getEventTargetNode(BOX *box) {
    void *node;
    while ((node = M2C_FIELD(box, void **, 0x28)) == NULL) {
        box = box->parent;
    }
    while (Node_getJSObj(node) == NULL || Node_getBox(node) == NULL) {
        node = Node_getParentNode(node);
        if (node == NULL) {
            break;
        }
    }
    return node;
}

void *getTargetImageMapArea(void *a0, void *a1, void *a2, int a3, int t0) {
    void *list;
    void *area = NULL;
    list = getMapList(a0, a2);
    if (list != NULL) {
        area = getAreaList(list, a1, a3, t0);
    }
    return area;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handlePointingMove);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handlePointingDown);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handlePointingCheck);

int handleDragStart(void *ev) {
    LEHPT *m = M2C_FIELD(ev, LEHPT **, 0x1C);
    LEHG *g = (LEHG *)gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    BOX *body;
    void *n;
    int sid;
    LEHJSEVENT jev;
    if (g->x10 == 1) {
        return 0;
    }
    box = g->x14;
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    if (box->content == 3) {
        void *geom;
        g->x28 = box;
        geom = box->geom;
        M2C_FIELD(geom, void **, 4) = startBorder(box);
        g->x2C = g->x34 = m->x;
        g->x30 = g->x38 = m->y;
        return 0;
    }
    body = M2C_FIELD(HST_getHeadHistoryNode(), BOX **, 0x6C);
    if (body == NULL || (box = getTargetBox(body, m->x, m->y, m->x4)) == NULL) {
        return -1;
    }
    sid = M2C_FIELD(getBodyBox(box)->geom, int *, 0x38);
    if (sid != g->sid) {
        box = g->x14;
    }
    if (D_00584CEC == 0 && sid == g->sid && M2C_FIELD(box, s16 *, 0x3E) == 0) {
        n = getEventTargetNode(box);
        if (Node_getJSObj(n) == NULL) {
            n = getDOMDocument(n);
        }
        if (n != g->x18) {
            initJSEvent(&jev, 0xF, g->x18, m->x, m->y);
            sendJSBubbleUpEvent(g->x18, &jev);
            initJSEvent(&jev, 0x10, n, m->x, m->y);
            sendJSBubbleUpEvent(n, &jev);
        }
        initJSEvent(&jev, 0xE, n, m->x, m->y);
        sendJSEvent(Node_getJSObj(n), &jev);
        g->x18 = n;
    }
    if (D_00584CEC == 1) {
        freeScrollStart(box, m->x, m->y);
    }
    return 0;
}

int handleDragDoing(void *ev) {
    LEHPT *m = M2C_FIELD(ev, LEHPT **, 0x1C);
    LEHG *g = (LEHG *)gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    BOX *body;
    void *n;
    int dx;
    int dy;
    LEHJSEVENT jev;
    if (g->x10 == 1) {
        return 0;
    }
    if (g->x28 != NULL) {
        dx = 0;
        dy = 0;
        if (!checkBoxValidity(g->x28)) {
            return -1;
        }
        if (*(int *)g->x28->geom == 0) {
            dy = m->y - g->x38;
            g->x38 = m->y;
        } else {
            dx = m->x - g->x34;
            g->x34 = m->x;
        }
        moveBorder(M2C_FIELD(g->x28->geom, void **, 4), dx, dy);
        return 0;
    }
    box = g->x14;
    if (box == NULL || !checkBoxValidity(box)) {
        return -1;
    }
    if (D_00584CEC == 0) {
        body = M2C_FIELD(HST_getHeadHistoryNode(), BOX **, 0x6C);
        if (body == NULL || (box = getTargetBox(body, m->x, m->y, m->x4)) == NULL) {
            return -1;
        }
        if (M2C_FIELD(getBodyBox(box)->geom, int *, 0x38) == g->sid && M2C_FIELD(box, s16 *, 0x3E) == 0) {
            n = getEventTargetNode(box);
            if (n != NULL && Node_getJSObj(n) == NULL) {
                n = Node_getOwnerDocument(n);
            }
            if (n != g->x18) {
                if (g->x18 != NULL) {
                    initJSEvent(&jev, 0xF, g->x18, m->x, m->y);
                    sendJSBubbleUpEvent(g->x18, &jev);
                }
                if (n != NULL) {
                    initJSEvent(&jev, 0x10, n, m->x, m->y);
                    sendJSBubbleUpEvent(n, &jev);
                }
            }
            if (n != NULL) {
                initJSEvent(&jev, 0xE, n, m->x, m->y);
                sendJSEvent(Node_getJSObj(n), &jev);
            }
            g->x18 = n;
        }
    }
    if (D_00584CEC == 1) {
        freeScroll(m->x, m->y);
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int handleDragEnd(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handlePointingUp);

int handleEnter(void *ev) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    HISTNODE *node = NULL;
    HISTNODE *c;
    BOX *box;
    void *t;
    void *n;
    void *target;
    FOCUSLIST *f;
    LEHJSEVENT jev;
    if (*(int *)g != 0) {
        node = HST_searchSessionIDHistoryNode(*(int *)g);
    }
    if (node == NULL) {
        node = HST_getHeadHistoryNode();
        while ((c = HST_getChildHistoryNode(node)) != NULL && HST_getRequestFlag(c) >= 0) {
            node = c;
        }
    }
    box = M2C_FIELD(node, BOX **, 0x6C);
    if (box == NULL || !checkBoxValidity(box)) {
        return -1;
    }
    f = FFRAME(box)->cur;
    if (f == NULL) {
        return 0;
    }
    t = f->obj;
    if (M2C_FIELD(t, s16 *, 0x3E) == 1) {
        return 0;
    }
    if (isFocusInDisplay(box, f)) {
        return 0;
    }
    n = getEventTargetNode(t);
    if (D_00584CEC == 0) {
        t = n;
        if (Node_getJSObj(n) == NULL) {
            t = getDOMDocument(n);
        }
        initJSEvent(&jev, 4, t, 0, 0);
        if (sendJSEvent(Node_getJSObj(t), &jev) == 1) {
            return 0;
        }
    }
    return actDefaultClickActionWithFocus(ev, FFRAME(box)->cur, n);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int isKeyDeviceAvailable(void *g) {
    return 1;
}

void *getFocusTargetContentContext(void *g) {
    HISTNODE *node = NULL;
    HISTNODE *c;
    if (*(int *)g != 0) {
        node = HST_searchSessionIDHistoryNode(*(int *)g);
    }
    if (node != NULL) {
        return node;
    }
    node = HST_getHeadHistoryNode();
    while ((c = HST_getChildHistoryNode(node)) != NULL && HST_getRequestFlag(c) >= 0) {
        node = c;
    }
    return node;
}

int handle1DFocusUp(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    act1DMoveFocusUp(box, FFRAME(box)->head, cur);
    return 0;
}

int handle1DFocusDown(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    act1DMoveFocusDown(box, FFRAME(box)->head, cur);
    return 0;
}

int handle2DFocusUp(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    act2DMoveFocusUp(box, FFRAME(box)->head, cur);
    return 0;
}

int handle2DFocusDown(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    act2DMoveFocusDown(box, FFRAME(box)->head, cur);
    return 0;
}

int handle2DFocusLeft(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    act2DMoveFocusLeft(box, FFRAME(box)->head, cur);
    return 0;
}

int handle2DFocusRight(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    act2DMoveFocusRight(box, FFRAME(box)->head, cur);
    return 0;
}

int handle2DScrollUp(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    actScrollUp(box, FFRAME(box)->head, cur);
    return 0;
}

int handle2DScrollDown(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    actScrollDown(box, FFRAME(box)->head, cur);
    return 0;
}

int handle2DScrollLeft(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    actScrollLeft(box, FFRAME(box)->head, cur);
    return 0;
}

int handle2DScrollRight(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    actScrollRight(box, FFRAME(box)->head, cur);
    return 0;
}

int handlePageScrollUp(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    actPageScrollUp(box, FFRAME(box)->head, cur);
    return 0;
}

int handlePageScrollDown(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    actPageScrollDown(box, FFRAME(box)->head, cur);
    return 0;
}

int handleScrollTop(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    actScrollTop(box, FFRAME(box)->head, cur);
    return 0;
}

int handleScrollBottom(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    FOCUSLIST *cur;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    cur = FFRAME(box)->cur;
    actScrollBottom(box, FFRAME(box)->head, cur);
    return 0;
}

int handleFrameFocusDown(void) {
    void *g = gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    if (!isKeyDeviceAvailable(g)) {
        return 0;
    }
    box = M2C_FIELD(getFocusTargetContentContext(g), BOX **, 0x6C);
    if (box == NULL) {
        return -1;
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    actFrameFocusDown(box);
    return 0;
}

int handleChoiceSelect(void *ev) {
    BOX *box;
    void *sel;
    void *form;
    box = M2C_FIELD(getFocusTargetContentContext(gESPRIT_LO_GLOBAL_NDA), BOX **, 0x6C);
    if (box == NULL || !checkBoxValidity(box)) {
        return -1;
    }
    sel = getSelectListFromGadget(M2C_FIELD(M2C_FIELD(ev, void **, 0x1C), void **, 4));
    if (sel == NULL) {
        return -1;
    }
    if (M2C_FIELD(sel, void **, 0x28) == NULL) {
        return -1;
    }
    form = getAncestorForm(M2C_FIELD(sel, void **, 0x28));
    if (form == NULL) {
        form = getPreviousForm(M2C_FIELD(sel, void **, 0x28));
        if (form == NULL) {
            return -1;
        }
    }
    return actFormInput(ev, Node_getBox(form), sel, 9);
}

int actDefaultClickActionWithFocus(void *frame, FOCUSLIST *f, void *a2) {
    if (f->type == 0) {
        return actDefaultClickAction(frame, f->obj, a2, 0, 0);
    }
    actLinkJump(frame, M2C_FIELD(f->area->link, void **, 4), 0);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", actDefaultClickAction);

void *getNextNode(void *root, void *node) {
    void *c;
    c = Node_getFirstChild(node);
    if (c != NULL) {
        node = c;
    } else {
        c = Node_getNextSibling(node);
        if (c != NULL) {
            node = c;
        } else {
            for (node = Node_getParentNode(node); node != NULL; node = Node_getParentNode(node)) {
                if (node == root) {
                    return NULL;
                }
                c = Node_getNextSibling(node);
                if (c != NULL) {
                    node = c;
                    break;
                }
            }
        }
    }
    return node;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", D_00139084);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", getBox_fromAccessKey);

int handleAccessKey(void *frame) {
    void *data = M2C_FIELD(frame, void **, 0x1C);
    void *body;
    void *box;
    void *node;
    void *target;
    LEHJSEVENT ev;
    body = lo_getActiveFrameBodybox();
    if (body == NULL) {
        return -1;
    }
    box = getBox_fromAccessKey(body, M2C_FIELD(data, u16 *, 8));
    if (box == NULL) {
        return 0;
    }
    actSetFocusByBox(body, box, 1);
    scrollToFocusPosition();
    node = M2C_FIELD(box, void **, 0x28);
    if (D_00584CEC == 0) {
        target = node;
        if (Node_getJSObj(node) == NULL) {
            target = getDOMDocument(node);
        }
        initJSEvent(&ev, 4, target, 0, 0);
        if (sendJSEvent(Node_getJSObj(target), &ev) == 1) {
            return 0;
        }
    }
    return actDefaultClickAction(frame, box, node, 0, 0);
}

int handleInputText(void *ev) {
    int start = 0;
    int end = 0;
    void *data = M2C_FIELD(ev, void **, 0x1C);
    BOX *box;
    BOX *t;
    char *p;
    box = lo_getActiveFrameBodybox();
    if (box == NULL || M2C_FIELD(box->geom, void **, 0x70) == NULL) {
        return -1;
    }
    t = M2C_FIELD(M2C_FIELD(box->geom, void **, 0x70), BOX **, 0xC);
    if (t->content == 13) {
    if (*(int *)t->geom != 1) {
        p = strchr(M2C_FIELD(data, char **, 8), '\n');
        if (p != NULL) {
            *p = 0;
        }
    }
    getTextSelectionRange(t, &start, &end);
    replaceTextStrings(t, M2C_FIELD(data, char **, 8), start, end);
    }
    return 0;
}

int confirmScrollInfo(void *ev) {
    BOX *box;
    int x;
    int y;
    void *m;
    box = M2C_FIELD(getFocusTargetContentContext(gESPRIT_LO_GLOBAL_NDA), BOX **, 0x6C);
    if (box == NULL || !checkBoxValidity(box)) {
        return -1;
    }
    if (M2C_FIELD(box, void **, 0x2C) == NULL) {
        return -1;
    }
    getViewPort(box, &x, &y);
    {
        int *g = (int *)box->geom;
        int a = g[2];
        int bb = g[3];
        int c = g[4];
        int d = g[5];
        m = make_msg_LP19(ev, x, y, a, bb, c, d);
    }
    if (m == NULL) {
        return -1;
    }
    putLLIST(&REQUEST_LLIST, m);
    return 0;
}

int handleMouseEvent(void *ev) {
    u16 *d = M2C_FIELD(ev, u16 **, 0x1C);
    switch (*d) {
    case 3: handlePointingMove(ev); break;
    case 0: handlePointingDown(ev); break;
    case 1: handlePointingUp(ev); break;
    case 2: handlePointingCheck(ev); break;
    case 4: handleDragStart(ev); break;
    case 5: handleDragDoing(ev); break;
    case 8: handleEnter(ev); break;
    case 17: handle1DFocusUp(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 18: handle1DFocusDown(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 19: handle2DFocusUp(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 20: handle2DFocusDown(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 21: handle2DFocusLeft(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 22: handle2DFocusRight(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 9: handlePageScrollUp(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 10: handlePageScrollDown(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 13: handle2DScrollUp(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 14: handle2DScrollDown(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 15: handle2DScrollLeft(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 16: handle2DScrollRight(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 11: handleScrollTop(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 12: handleScrollBottom(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 23: handleFrameFocusDown(); confirmScrollInfo(M2C_FIELD(ev, void **, 4)); break;
    case 24: handleChoiceSelect(ev); break;
    case 7: handleAccessKey(ev); break;
    case 25: handleInputText(ev); break;
    }
    MEM_free(NULL, d);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", getDataAttribute);
