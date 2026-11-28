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
int actDefaultClickAction(void *frame, BOX *box, void *node, int x, int y);
void actLinkJump(void *frame, void *link, char *a2);


void *getSelectListFromGadget(void *g);
void *getAncestorForm(void *n);
void *getPreviousForm(void *n);
int actFormInput(void *ev, void *box, void *sel, int kind);
BOX *lo_getActiveFrameBodybox(void);
int getTextSelectionRange(BOX *box, int *start, int *end);
int replaceTextStrings(BOX *box, char *s, int start, int end);
char *strchr(const char *s, int c);
void *make_msg_LP19(void *ev, int x, int y, int a, int b, int c, int d);
typedef struct { u8 unk0[0x30]; } LEHJSEVENT;
void initJSEvent(LEHJSEVENT *ev, int type, void *node, int a, int b);
int sendJSEvent(void *obj, LEHJSEVENT *ev);
void *getDOMDocument(void *node);
void actSetFocusByBox(void *frame, void *box, int arg);
int scrollToFocusPosition();
void *getBox_fromAccessKey(void *body, int key);
int isFocusInDisplay(void *frame, FOCUSLIST *l);
typedef struct { int sid; u8 u4[0xC]; int x10; BOX *x14; void *x18; u8 u1C[0xC]; BOX *x28; int x2C; int x30; int x34; int x38; } LEHG;
typedef struct { int u0; int x4; int x; int y; } LEHPT;
void *startBorder(BOX *box);
void freeScrollStart(BOX *box, int x, int y);
BOX *getTargetBox(BOX *box, int x, int y, int k);
void *Node_getOwnerDocument(void *node);
int moveBorder(void *b, int dx, int dy);
void freeScroll(int x, int y);
int sendJSBubbleUpEvent(void *node, LEHJSEVENT *ev);
int handlePointingMove(void *ev);
int handlePointingDown(void *ev);
int handlePointingUp(void *ev);
int handlePointingCheck(void *ev);
int deleteBorder(void *b);
void moveFrameBorder(BOX *box, int d);
typedef struct { int u0; int x4; int x; int y; s16 kind; } LEHPT2;
char *getDOMAttributeValue(void *node, void *name);
extern u8 _DOMusemap[];
void getBodyAbsolutePos(BOX *box, int *px, int *py);
FOCUSLIST *getFocusListWithArea(void *frame, void *obj, void *link);
void getDataAttribute(BOX *box, int x, int y);
typedef struct { int sid; u8 u4[0xC]; int x10; BOX *x14; void *x18; void *x1C; int x20; int x24; BOX *x28; } LEHG2;
typedef struct LEHLINK { struct LEHLINK *next; int x4; BOX *box; } LEHLINK;
typedef struct { int size; unsigned int len; void *str; } LEHDS;
int Node_getNodeName(LEHDS *s, void *node);
int Element_getAttribute(LEHDS *s, void *elem, void *name);
int DOMStringcasecmpFast(LEHDS *s, void *str);
int DOMStringcasecmpChar(LEHDS *s, char *str);
int Node_getNodeType(void *node);
int sprintf(char *buf, const char *fmt, ...);
extern u8 _DOMa[], _DOMarea[], _DOMbutton[], _DOMtextarea[], _DOMinput[], _DOMtype[], _DOMcheckbox[], _DOMimage[], _DOMpassword[], _DOMradio[], _DOMreset[], _DOMsubmit[], _DOMtext[], _DOMfile[], _DOMaccesskey[];
typedef struct { u8 u0[0x20]; void *target; u8 u24[0xC]; } LEHJSEVENT2;
int Element_hasAttribute(void *node, void *name);
void *getAncestorLink(void *node);
void **getFormList(void *body, void *node);
int getInputType(void *node);
extern u8 _DOMismap[];
int getChildBox(void *arg0);
int getBrotherBox(void *arg0);
void *Node_getBox(void *);
int actDefaultClickActionWithFocus(void *frame, FOCUSLIST *f, void *a2);
FOCUSLIST *act1DMoveFocusUp(void *frame, FOCUSLIST *def, FOCUSLIST *cur);
FOCUSLIST *act1DMoveFocusDown(void *frame, FOCUSLIST *def, FOCUSLIST *cur);
FOCUSLIST *act2DMoveFocusUp(void *frame, FOCUSLIST *a1, FOCUSLIST *cur);
FOCUSLIST *act2DMoveFocusDown(void *frame, FOCUSLIST *a1, FOCUSLIST *cur);
FOCUSLIST *act2DMoveFocusLeft(void *frame, FOCUSLIST *a1, FOCUSLIST *cur);
FOCUSLIST *act2DMoveFocusRight(void *frame, FOCUSLIST *a1, FOCUSLIST *cur);
int actScrollUp(int arg0, int arg1, int arg2);
int actScrollDown(int arg0, int arg1, int arg2);
int actScrollLeft(int arg0, int arg1, int arg2);
int actScrollRight(int arg0, int arg1, int arg2);
FOCUSLIST *actPageScrollUp(void *frame, FOCUSLIST *def, FOCUSLIST *cur);
FOCUSLIST *actPageScrollDown(void *frame, FOCUSLIST *def, FOCUSLIST *cur);
FOCUSLIST *actScrollTop(void *frame, FOCUSLIST *l, FOCUSLIST *cur);
FOCUSLIST *actScrollBottom(void *frame, FOCUSLIST *l, FOCUSLIST *cur);
BOX *getTargetBox(BOX *box, int x, int y, int k) {
    BOX *found = NULL;
    BOX *r;
    void *geom;
    LEHLINK *l;
    int w, h;
    int vx, vy;
    if (box->content == 1) {
        geom = box->geom;
        if (x < M2C_FIELD(geom, int *, 0) || x >= M2C_FIELD(geom, int *, 0) + M2C_FIELD(geom, int *, 8) || y < M2C_FIELD(geom, int *, 4) || y >= M2C_FIELD(geom, int *, 4) + M2C_FIELD(geom, int *, 0xC) || M2C_FIELD(geom, int *, 0x40) == 4) {
            return NULL;
        }
        getViewClientSize(box, &w, &h);
        geom = box->geom;
        if (x >= M2C_FIELD(geom, int *, 0) + w || y >= M2C_FIELD(geom, int *, 4) + h) {
            return box;
        }
        getViewPort(box, &vx, &vy);
        x = x - M2C_FIELD(box->geom, int *, 0) + vx;
        y = y - M2C_FIELD(box->geom, int *, 4) + vy;
        found = box;
        for (l = M2C_FIELD(box->geom, LEHLINK **, 0x9C); l != NULL; l = l->next) {
            if (x >= l->box->x && x < l->box->x + l->box->width && y >= l->box->y && y < l->box->y + l->box->height) {
                found = l->box;
                box = l->box;
                break;
            }
        }
    } else if (box->content == 5) {
    } else if (box->content == 0x11) {
        if (x >= box->x && x < box->x + box->width && y >= box->y && y < box->y + box->height) {
            return box;
        }
        return NULL;
    } else if (box->content == 2) {
    } else if (box->content == 0) {
    } else {
        if (x >= box->x && x < box->x + box->width && y >= box->y && y < box->y + box->height) {
            found = box;
        } else if (box->display == 3) {
            return NULL;
        }
    }
    for (box = getChildBox(box); box != NULL; box = getBrotherBox(box)) {
        r = getTargetBox(box, x, y, k);
        if (r != NULL) {
            return r;
        }
    }
    return found;
}

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

int handlePointingMove(void *ev) {
    LEHPT2 *m = M2C_FIELD(ev, LEHPT2 **, 0x1C);
    LEHG2 *g = (LEHG2 *)gESPRIT_LO_GLOBAL_NDA;
    void *head;
    BOX *body;
    BOX *box;
    void *n;
    char *map;
    void *area;
    void *hn;
    int x, y;
    int w, h;
    int px, py;
    int vx, vy;
    LEHJSEVENT jev;
    g->x14 = NULL;
    if (g->x28 != NULL) {
        deleteBorder(M2C_FIELD(g->x28->geom, void **, 4));
        g->x28 = NULL;
    }
    head = HST_getHeadHistoryNode();
    if (head == NULL) {
        return -1;
    }
    body = M2C_FIELD(head, BOX **, 0x6C);
    if (body == NULL || (box = getTargetBox(body, m->x, m->y, m->x4)) == NULL) {
        return -1;
    }
    getEventTargetNode(box);
    if (!checkBoxValidity(box)) {
        return -1;
    }
    if (box->content == 1) {
        getBodyAbsolutePos(box, &x, &y);
        getViewClientSize(box, &w, &h);
        if (m->x >= x + w || m->y >= y + h) {
            g->x10 = 1;
            return 0;
        }
    }
    g->x10 = 0;
    if (lo_global.unk54 != 0) {
        return 0;
    }
    if (box->content == 3) {
        g->x14 = box;
        return 0;
    }
    if (M2C_FIELD(box, s16 *, 0x3E) == 1) {
        return 0;
    }
    n = getEventTargetNode(box);
    if (Node_getJSObj(n) == NULL) {
        n = getDOMDocument(n);
    }
    if (n != g->x18) {
        hn = NULL;
        if (g->sid != 0) {
            hn = HST_searchSessionIDHistoryNode(g->sid);
        }
        if (hn != NULL && g->x18 != NULL) {
            if (g->x1C != NULL) {
                initJSEvent(&jev, 0xF, g->x18, g->x20, g->x24);
                g->x1C = NULL;
            } else {
                initJSEvent(&jev, 0xF, g->x18, m->x, m->y);
            }
            sendJSBubbleUpEvent(g->x18, &jev);
        }
        initJSEvent(&jev, 0x10, n, m->x, m->y);
        sendJSBubbleUpEvent(n, &jev);
        g->x18 = n;
        return 0;
    } else {
        if (box->content == 10 && box->html != 0x32) {
            getBodyAbsolutePos(body, &px, &py);
            getViewPort(body, &vx, &vy);
            x = m->x - px + vx;
            y = m->y - py + vy;
            map = getDOMAttributeValue(getEventTargetNode(box), _DOMusemap);
            if (map != NULL && *map == '#') {
                area = getTargetImageMapArea(body, box, map + 1, x, y);
                if (area == NULL) {
                    if (g->x1C != NULL) {
                        initJSEvent(&jev, 0xF, g->x18, g->x20, g->x24);
                        sendJSBubbleUpEvent(n, &jev);
                    }
                    g->x1C = NULL;
                } else {
                    if (g->x1C == NULL) {
                        initJSEvent(&jev, 0x10, n, m->x, m->y);
                        sendJSBubbleUpEvent(g->x18, &jev);
                        g->x1C = area;
                    } else if (g->x1C == area) {
                        initJSEvent(&jev, 0xE, n, m->x, m->y);
                        sendJSBubbleUpEvent(n, &jev);
                    } else {
                        initJSEvent(&jev, 0xF, g->x18, g->x20, g->x24);
                        sendJSBubbleUpEvent(n, &jev);
                        initJSEvent(&jev, 0x10, n, m->x, m->y);
                        sendJSBubbleUpEvent(n, &jev);
                        g->x1C = area;
                    }
                    g->x20 = x;
                    g->x24 = y;
                }
                if (map != NULL) {
                    MEM_free(NULL, map);
                }
            }
        } else {
            g->x1C = NULL;
        }
    }
    initJSEvent(&jev, 0xE, n, m->x, m->y);
    sendJSBubbleUpEvent(n, &jev);
    g->x18 = n;
    return 0;
}

int handlePointingDown(void *ev) {
    LEHPT2 *m = M2C_FIELD(ev, LEHPT2 **, 0x1C);
    LEHG *g = (LEHG *)gESPRIT_LO_GLOBAL_NDA;
    FOCUSLIST *fl = NULL;
    void *head;
    BOX *body;
    BOX *box;
    void *n;
    char *map;
    void *area;
    void *hn;
    void *tn;
    int px, py;
    int vx, vy;
    int x, y;
    int w, h;
    LEHJSEVENT jev;
    g->x14 = NULL;
    if (g->x28 != NULL) {
        deleteBorder(M2C_FIELD(g->x28->geom, void **, 4));
        g->x28 = NULL;
    }
    if (m->kind != 1) {
        return -1;
    }
    head = HST_getHeadHistoryNode();
    if (head == NULL) {
        return -1;
    }
    body = M2C_FIELD(head, BOX **, 0x6C);
    if (body == NULL || (box = getTargetBox(body, m->x, m->y, m->x4)) == NULL) {
        return -1;
    }
    tn = getEventTargetNode(box);
    if (box->content == 10 && box->html != 0x32) {
        map = getDOMAttributeValue(tn, _DOMusemap);
        getBodyAbsolutePos(body, &px, &py);
        getViewPort(body, &vx, &vy);
        x = m->x - px + vx;
        y = m->y - py + vy;
        if (map != NULL && *map == '#') {
            area = getTargetImageMapArea(body, box, map + 1, x, y);
            if (area != NULL) {
                fl = getFocusListWithArea(body, box, area);
            }
        }
        if (map != NULL) {
            MEM_free(NULL, map);
        }
    }
    if (!checkBoxValidity(box)) {
        return -1;
    }
    if (box->content == 1) {
        getBodyAbsolutePos(box, &x, &y);
        getViewClientSize(box, &w, &h);
        if (m->x >= x + w || m->y >= y + h) {
            g->x10 = 1;
            return 0;
        }
    }
    g->x10 = 0;
    if (lo_global.unk54 != 0) {
        g->x14 = box;
        return 0;
    }
    if (box->content == 3) {
        g->x14 = box;
        return 0;
    }
    if (M2C_FIELD(box, s16 *, 0x3E) == 1) {
        return 0;
    }
    n = getEventTargetNode(box);
    if (Node_getJSObj(n) == NULL) {
        n = getDOMDocument(n);
    }
    if (n != g->x18) {
        hn = NULL;
        if (g->sid != 0) {
            hn = HST_searchSessionIDHistoryNode(g->sid);
        }
        if (hn != NULL && g->x18 != NULL) {
            initJSEvent(&jev, 0xF, g->x18, m->x, m->y);
            sendJSBubbleUpEvent(g->x18, &jev);
        }
        initJSEvent(&jev, 0x10, n, m->x, m->y);
        sendJSBubbleUpEvent(n, &jev);
    }
    initJSEvent(&jev, 0xD, n, m->x, m->y);
    sendJSBubbleUpEvent(n, &jev);
    g->x18 = n;
    if (fl != NULL) {
        actSetFocusByFocusList(body, fl, 1);
    } else {
        actSetFocusByBox(getBodyBox(box), box, 1);
    }
    g->x14 = box;
    return 0;
}

int handlePointingCheck(void *ev) {
    LEHPT2 *m = M2C_FIELD(ev, LEHPT2 **, 0x1C);
    LEHG *g = (LEHG *)gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    void *n;
    int r;
    LEHJSEVENT jev;
    if (g->x10 == 1) {
        g->x10 = 0;
        return 0;
    }
    if (m->kind == 3) {
        getDataAttribute(NULL, m->x, m->y);
        return 0;
    }
    if (g->sid == 0) {
        return -1;
    }
    box = g->x14;
    if (box == NULL || !checkBoxValidity(box)) {
        g->x14 = NULL;
        return -1;
    }
    if (box->content == 3) {
        g->x14 = NULL;
        return 0;
    }
    if (lo_global.unk54 == 0) {
        n = g->x18;
        if (n == NULL) {
            return -1;
        }
        initJSEvent(&jev, 0x11, n, m->x, m->y);
        sendJSBubbleUpEvent(n, &jev);
        initJSEvent(&jev, 4, n, m->x, m->y);
        r = sendJSBubbleUpEvent(n, &jev);
        g->x18 = NULL;
        if (r == 1) {
            return 0;
        }
    }
    g->x14 = NULL;
    if (lo_global.unk54 == 1) {
        return 0;
    }
    return actDefaultClickAction(ev, box, getEventTargetNode(box), m->x, m->y);
}

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
    if (lo_global.unk54 == 0 && sid == g->sid && M2C_FIELD(box, s16 *, 0x3E) == 0) {
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
    if (lo_global.unk54 == 1) {
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
    if (lo_global.unk54 == 0) {
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
    if (lo_global.unk54 == 1) {
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

int handlePointingUp(void *ev) {
    LEHPT *m = M2C_FIELD(ev, LEHPT **, 0x1C);
    LEHG *g = (LEHG *)gESPRIT_LO_GLOBAL_NDA;
    BOX *box;
    BOX *body;
    void *n;
    int doDefault;
    LEHJSEVENT jev;
    if (g->x10 == 1) {
        g->x10 = 0;
        return 0;
    }
    if (g->x28 != NULL) {
        if (checkBoxValidity(g->x28)) {
            deleteBorder(M2C_FIELD(g->x28->geom, void **, 4));
            if (*(int *)g->x28->geom == 0) {
                moveFrameBorder(g->x28, m->y - g->x30);
            } else {
                moveFrameBorder(g->x28, m->x - g->x2C);
            }
        }
        g->x28 = NULL;
        g->x14 = NULL;
        return 0;
    }
    box = g->x14;
    if (box == NULL || !checkBoxValidity(box)) {
        return -1;
    }
    if (lo_global.unk54 == 0) {
        body = M2C_FIELD(HST_getHeadHistoryNode(), BOX **, 0x6C);
        if (body == NULL || (box = getTargetBox(body, m->x, m->y, m->x4)) == NULL) {
            g->x18 = NULL;
            return -1;
        }
        if (M2C_FIELD(getBodyBox(box)->geom, int *, 0x38) == g->sid && M2C_FIELD(box, s16 *, 0x3E) == 0 && box->content != 3) {
            doDefault = 1;
            n = getEventTargetNode(box);
            if (box->content != 18) {
                if (Node_getJSObj(n) == NULL) {
                    n = Node_getOwnerDocument(n);
                }
                initJSEvent(&jev, 0x11, n, m->x, m->y);
                sendJSBubbleUpEvent(n, &jev);
            } else {
                n = g->x18;
                initJSEvent(&jev, 0x11, n, m->x, m->y);
                sendJSBubbleUpEvent(n, &jev);
                actDefaultClickAction(ev, box, n, m->x, m->y);
                if (!doDefault) {
                    g->x18 = NULL;
                    return 0;
                }
            }
        }
    }
    if (g->x14->content == 0x10) {
        if (g->x14 == getTargetBox(M2C_FIELD(HST_getHeadHistoryNode(), BOX **, 0x6C), m->x, m->y, m->x4)) {
            handlePointingCheck(ev);
        }
        return 0;
    }
    g->x14 = NULL;
    return 0;
}

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
    if (lo_global.unk54 == 0) {
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

int actDefaultClickAction(void *frame, BOX *box, void *node, int x, int y) {
    char buf[16];
    LEHJSEVENT2 jev;
    BOX *body;
    BOX *n;
    char *map;
    void *area;
    void *link;
    void *form;
    void **fl;
    int type;
    int r;
    int mx, my;
    int px, py;
    int vx, vy;
    if (box == NULL || node == NULL) {
        return -1;
    }
    if (M2C_FIELD(box, int *, 0x38) == 0x32000D && box->next != NULL) {
        if (!(box->x + box->width >= x && box->x < x && box->y + box->height >= y && box->y < y)) {
            n = box->next;
            if (n->x + n->width >= x && n->x < x && n->y + n->height >= y && n->y < y) {
                box = n;
            }
        }
    }
    body = getBodyBox(box);
    if (box->content == 10 && box->html != 0x32) {
        map = getDOMAttributeValue(node, _DOMusemap);
        getBodyAbsolutePos(body, &px, &py);
        getViewPort(body, &vx, &vy);
        mx = x - px + vx;
        my = y - py + vy;
        if (map != NULL && *map == '#') {
            area = getTargetImageMapArea(body, box, map + 1, mx, my);
            if (area != NULL) {
                actLinkJump(frame, M2C_FIELD(area, void **, 4), NULL);
            }
        } else if (Element_hasAttribute(node, _DOMismap) && (link = getAncestorLink(node)) != NULL) {
            sprintf(buf, "?%d,%d", mx - box->x, my - box->y);
            actLinkJump(frame, link, buf);
        } else if ((link = getAncestorLink(node)) != NULL) {
            actLinkJump(frame, link, NULL);
        }
        if (map != NULL) {
            MEM_free(NULL, map);
        }
        return 0;
    }
    fl = getFormList(body, node);
    form = NULL;
    if (fl != NULL) {
        form = *fl;
    }
    if (form != NULL && (type = getInputType(node)) != 0) {
        if (lo_global.unk54 == 0) {
            r = 0;
            if (type == 10 || type == 5) {
                initJSEvent((LEHJSEVENT *)&jev, 0x16, form, x, y);
                jev.target = node;
                r = sendJSEvent(Node_getJSObj(form), (LEHJSEVENT *)&jev);
            } else if (type == 8) {
                initJSEvent((LEHJSEVENT *)&jev, 0x13, form, x, y);
                jev.target = node;
                r = sendJSEvent(Node_getJSObj(form), (LEHJSEVENT *)&jev);
            }
            if (r == 1) {
                return 0;
            }
        }
        actFormInput(frame, Node_getBox(form), box, type);
        return 0;
    }
    link = getAncestorLink(node);
    if (link != NULL) {
        actLinkJump(frame, link, NULL);
    }
    return 0;
}

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


void *getBox_fromAccessKey(void *frame, int key) {
    void *node = M2C_FIELD(frame, void **, 0x28);
    char buf[16];
    LEHDS name;
    LEHDS attr;
    u8 r[6] = { '0', '9', 'A', 'Z', 0, 0 };
    int i;
    for (i = 0; r[i * 2] != 0; i++) {
        if (key >= r[i * 2] && key <= r[i * 2 + 1]) {
            break;
        }
    }
    if (r[i * 2] == 0) {
        return NULL;
    }
    sprintf(buf, "%c", key);
    for (; node != NULL; node = getNextNode(M2C_FIELD(frame, void **, 0x28), node)) {
        if (Node_getNodeType(node) == 1) {
        Node_getNodeName(&name, node);
        if (DOMStringcasecmpFast(&name, _DOMa) == 0 || DOMStringcasecmpFast(&name, _DOMarea) == 0 || DOMStringcasecmpFast(&name, _DOMbutton) == 0 || DOMStringcasecmpFast(&name, _DOMtextarea) == 0) {
            Element_getAttribute(&attr, node, _DOMaccesskey);
            if (DOMStringcasecmpChar(&attr, buf) == 0) {
                return Node_getBox(node);
            }
        } else if (DOMStringcasecmpFast(&name, _DOMinput) == 0) {
            Element_getAttribute(&attr, node, _DOMtype);
            if (DOMStringcasecmpFast(&attr, _DOMbutton) == 0 || DOMStringcasecmpFast(&attr, _DOMcheckbox) == 0 || DOMStringcasecmpFast(&attr, _DOMimage) == 0 || DOMStringcasecmpFast(&attr, _DOMpassword) == 0 || DOMStringcasecmpFast(&attr, _DOMradio) == 0 || DOMStringcasecmpFast(&attr, _DOMreset) == 0 || DOMStringcasecmpFast(&attr, _DOMsubmit) == 0 || DOMStringcasecmpFast(&attr, _DOMtext) == 0) {
                Element_getAttribute(&attr, node, _DOMaccesskey);
                if (DOMStringcasecmpChar(&attr, buf) == 0) {
                    return Node_getBox(node);
                }
            } else if (DOMStringcasecmpFast(&attr, _DOMfile) == 0) {
                Element_getAttribute(&attr, node, _DOMaccesskey);
                if (DOMStringcasecmpChar(&attr, buf) == 0) {
                    return M2C_FIELD(Node_getBox(node), void **, 0xC);
                }
            }
        }
        }
    }
    return NULL;
}

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
    if (lo_global.unk54 == 0) {
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
