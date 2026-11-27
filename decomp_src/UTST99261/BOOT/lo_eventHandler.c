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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handleDragStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handleDragDoing);

#ifndef NULL
#define NULL ((void *)0)
#endif
int handleDragEnd(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handlePointingUp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handleEnter);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handleAccessKey);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handleMouseEvent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", getDataAttribute);
