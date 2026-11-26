/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "lo_focus.h"
#include "m2c_macros.h"
HISTNODE *HST_getChildHistoryNode(HISTNODE *);
int HST_getRequestFlag(HISTNODE *);
void *Node_getJSObj(void *);
void *Node_getParentNode(void *);
void *getMapList(void *, void *);
void *getAreaList(void *, void *, int, int);
int actDefaultClickAction(void *frame, void *box, void *a2, int a3, int t0);
void actLinkJump(void *frame, void *link, int a2);


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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handleChoiceSelect);

int actDefaultClickActionWithFocus(void *frame, FOCUSLIST *f, void *a2) {
    if (f->type == 0) {
        return actDefaultClickAction(frame, f->obj, a2, 0, 0);
    }
    actLinkJump(frame, M2C_FIELD(f->area->link, void **, 4), 0);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", actDefaultClickAction);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", getNextNode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", D_00139084);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", getBox_fromAccessKey);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handleAccessKey);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handleInputText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", confirmScrollInfo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", handleMouseEvent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_eventHandler", getDataAttribute);
