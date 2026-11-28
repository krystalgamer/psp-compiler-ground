/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int HST_getHeadHistoryNode();                       /* extern */
M2C_UNK handleMouseEvent(int);                      /* extern */

typedef struct {
    int type;
    int unk4;
    int unk8;
    int unkC;
} PJSMSG;

typedef struct {
    int unk0;
    PJSMSG msg;                 /* 0x4 */
} PJSCTX;

typedef struct {
    int flags;                  /* 0x0 */
    u8 unk4[0x44];
    int timer;                  /* 0x48 */
    u8 unk4C[0x8];
    int unk54;
    u8 unk58[0x10];
    int unk68;
    int unk6C;
    int unk70;
    PJSCTX *js;                 /* 0x74 */
} PLOGLOBAL;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int len;                    /* 0x18 */
    void *data;                 /* 0x1C */
} PMSG;

typedef struct {
    int x;
    int y;
} PPOINT;

extern PLOGLOBAL lo_global;
extern void *ui_global;
extern unsigned char REQUEST_LLIST;
void MEM_free(int pool, void *p);
void *MEM_malloc(int pool, unsigned int size);
void *memcpy(void *d, const void *s, unsigned int n);
int lo_setTimer(int a, int b, int c, int d);
int getJSSEM(void);
int OS_thread_mutex_unlock(int m);
int JSDestroy(PJSCTX *js);
void initSessionSaveDataList(void);
int JSStart();
void getDataAttribute();
int make_msg_LP11();
void putLLIST();
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    u8 unk10[0x24];
    char *scrolling;            /* 0x34 */
    u8 unk38[0x8];
    int unk40;                  /* 0x40 */
    u8 unk44[0x24];
    struct PITEM *items;        /* 0x68 */
    int unk6C;
    void *focus;                /* 0x70 */
} PGEOM;
typedef struct {
    u8 unk0[0x20];
    PGEOM *geom;                /* 0x20 */
    void *unk24;
    int node;                   /* 0x28 */
    int widget;                 /* 0x2C */
    u8 unk30[0x8];
    s16 content;                /* 0x38 */
    u8 unk3A[4];
    s16 unk3E;                  /* 0x3E */
} PBOX;
typedef struct {
    u8 unk0[0xC];
    PBOX *box;                  /* 0xC */
} PFOCUS;
typedef struct {
    u8 unk0[0x48];
    int unk48;
    u8 unk4C[0x20];
    PBOX *body;                 /* 0x6C */
} PHIST;
typedef struct {
    int unk0;
    int unk4;
    int id;                     /* 0x8 */
    int x;
    int y;
} PFRAG;
PFRAG *HST_getFragmentIDs();
int HST_moveFragmentIDs();
int getViewPort();
int drawScroll();
int make_msg_LP4();
int make_msg_LP21();
int make_msg_LP12();
int make_msg_LP3();
int make_msg_LJ6();
int actSearchString();
PHIST *HST_getChildHistoryNode(PHIST *h);
PHIST *HST_getSiblingHistoryNode(PHIST *h);
PHIST *HST_getParentHistoryNode(PHIST *h);
int HST_getSessionID(PHIST *h);
void delLLISTByDocumentSession();
int make_msg_LI2();
int HST_getRequestFlag(PHIST *h);
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    int unk8;
    char *str;                  /* 0xC */
} PSRCH;
int Node_getJSObj();
int JSRun();
typedef struct {
    int node;
    int len;                    /* 0x4 */
    u16 *str;                   /* 0x8 */
} PJSRC;
typedef struct {
    int obj;
    u16 *str;
} PJSARG;
typedef struct {
    int type;
    int session;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int size;                   /* 0x18 */
    void *data;                 /* 0x1C */
} PJSRUN;
typedef struct {
    u8 unk0[0x24];
    int unk24;
} PPREF;
typedef struct {
    int session;
} PNDA;
extern PPREF *gPREF_UI;
extern PNDA *gESPRIT_LO_GLOBAL_NDA;
PHIST *HST_searchSessionIDHistoryNode(int id);
int checkBoxValidity(PBOX *b);
void setUiGlobal_browser(void);
void GUI_Toolkit_mutexLock(void);
void GUI_Toolkit_mutexUnlock(void);
void relayoutAtBody(PBOX *b, int f);
int drawPaint(PBOX *b);
PBOX *lo_getActiveFrameBodybox(void);
int setFocusFocusItem(PBOX *b, void *f, int n);
void drawFocusItem(void *f);
int make_msg_LJ7();
int setTextStrings(PBOX *b, char *s);
int getTextSelectionRange(PBOX *b, int *s, int *e);
int replaceTextStrings(PBOX *b, char *s, int st, int en);
extern char D_001338FC[];


typedef struct {
    u8 unk0[0x30];
} PJSEVENT;
void initJSEvent(PJSEVENT *ev, int type, int node, int a, int b);
void sendJSEvent(int obj, PJSEVENT *ev);

void sendJSUnloadEvent(PHIST *root) {
    PHIST *h;
    PHIST *n;
    PBOX *b;
    PJSEVENT ev;

    h = HST_getChildHistoryNode(root);
    if (h == NULL) {
        goto done;
    }
loop:
    while ((n = HST_getChildHistoryNode(h)) != NULL) {
        h = n;
    }
    if (HST_getRequestFlag(h) >= 0) {
        b = h->body;
        if (b != NULL && b->geom->unk40 != 4) {
            initJSEvent(&ev, 0x17, b->node, 0, 0);
            sendJSEvent(Node_getJSObj(b->node), &ev);
        }
    }
    n = HST_getSiblingHistoryNode(h);
    if (n == NULL) {
        h = HST_getParentHistoryNode(h);
        while (h != root) {
            b = h->body;
            if (b != NULL && b->geom->unk40 != 4) {
                initJSEvent(&ev, 0x17, b->node, 0, 0);
                sendJSEvent(Node_getJSObj(b->node), &ev);
            }
            n = HST_getSiblingHistoryNode(h);
            if (n != NULL) {
                break;
            }
            h = HST_getParentHistoryNode(h);
        }
        if (h == root) {
            goto done;
        }
    }
    h = n;
    if (h != NULL) {
        goto loop;
    }
done:
    b = root->body;
    initJSEvent(&ev, 0x17, b->node, 0, 0);
    sendJSEvent(Node_getJSObj(b->node), &ev);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", abortResourceLoading);

int HST_getDomObject(PHIST *h);

void setPageLoadedState(void) {
    PHIST *h;
    PHIST *n;
    PBOX *b;
    int dom;
    PJSEVENT ev;

    h = (PHIST *)HST_getHeadHistoryNode();
    if (h == NULL) {
        return;
    }
loop:
    n = HST_getChildHistoryNode(h);
    if (n == NULL || HST_getRequestFlag(n) < 0) {
        b = h->body;
        if (b != NULL && (unsigned int)(b->geom->unk40 - 1) < 2) {
            b->geom->unk40 = 3;
            dom = HST_getDomObject(h);
            if (dom != 0) {
                initJSEvent(&ev, 0xC, dom, 0, 0);
                sendJSEvent(Node_getJSObj(dom), &ev);
            }
        }
        n = HST_getSiblingHistoryNode(h);
        if (n == NULL || HST_getRequestFlag(n) < 0) {
            h = HST_getParentHistoryNode(h);
            while (h != NULL) {
                b = h->body;
                if (b != NULL && (unsigned int)(b->geom->unk40 - 1) < 2) {
                    b->geom->unk40 = 3;
                    dom = HST_getDomObject(h);
                    if (dom != 0) {
                        initJSEvent(&ev, 0xC, dom, 0, 0);
                        sendJSEvent(Node_getJSObj(dom), &ev);
                    }
                }
                n = HST_getSiblingHistoryNode(h);
                if (n != NULL && HST_getRequestFlag(n) >= 0) {
                    goto next;
                }
                h = HST_getParentHistoryNode(h);
            }
            return;
        }
    }
next:
    h = n;
    if (h != NULL) {
        goto loop;
    }
}

void proc_msg_PL1(void) {
    initSessionSaveDataList();
    JSStart();
    lo_global.timer = lo_setTimer(1, 50, 0, 0);
}

void proc_msg_PL2(PMSG *msg) {
    PJSMSG *m;

    MEM_free(0, ui_global);
    ui_global = NULL;
    m = &lo_global.js->msg;
    m->type = 4;
    m->unk4 = msg->unk4;
    m->unkC = 0x403;
    lo_global.flags |= 0x10;
    OS_thread_mutex_unlock(getJSSEM());
    JSDestroy(lo_global.js);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL3);

typedef struct PFORM {
    struct PFORM *next;
    int unk4;
    struct PFORM *link;         /* 0x8 */
    u8 unkC[0x8];
    int done;                   /* 0x14 */
    PBOX *box;                  /* 0x18 */
} PFORM;

extern PFORM *D_00584D34;
int make_msg_LP13();
int make_msg_LP23();
int make_msg_LJ9();
int checkRecieveLLIST();
void freeFormList();
void freeCurPageFormList();

void proc_msg_PL4(PMSG *m) {
    PFORM *p;
    PFORM *q;
    PHIST *h;
    PHIST *head;
    PBOX *body;
    PJSEVENT ev;

    lo_global.flags |= 8;
    if (m->unk10 == 0) {
        for (p = D_00584D34; p != NULL; p = p->next) {
            if (p->done != 0) {
                continue;
            }
            for (q = p; q != NULL; q = q->link) {
                if (q->box != NULL && q->box->node != 0) {
                    initJSEvent(&ev, 1, q->box->node, 0, 0);
                    sendJSEvent(Node_getJSObj(q->box->node), &ev);
                }
            }
        }
        putLLIST(&REQUEST_LLIST, make_msg_LI2(0));
        setPageLoadedState();
        putLLIST(&REQUEST_LLIST, make_msg_LP13(m));
    } else {
        if (m->unk4 != 0) {
            h = HST_searchSessionIDHistoryNode(m->unk4);
        } else {
            h = (PHIST *)HST_getHeadHistoryNode();
        }
        if (h == NULL || h->body == NULL) {
            putLLIST(&REQUEST_LLIST, make_msg_LP13(m));
            return;
        }
        body = h->body;
        body->geom->unk40 = 4;
        if (m->unk4 == 0) {
            if (checkRecieveLLIST(&REQUEST_LLIST) == 1) {
                putLLIST(&REQUEST_LLIST, make_msg_LI2(0));
            }
        } else {
            abortResourceLoading(h, 2);
        }
        putLLIST(&REQUEST_LLIST, make_msg_LP23(0));
        sendJSUnloadEvent(h);
        if (m->unk10 == 2) {
            if (m->unk4 != 0) {
                freeFormList(body);
            } else if ((head = (PHIST *)HST_getHeadHistoryNode()) != NULL) {
                freeCurPageFormList(head);
            }
        }
        putLLIST(&REQUEST_LLIST, make_msg_LJ9(m, h));
        lo_global.flags |= 0x20;
    }
    OS_thread_mutex_unlock(getJSSEM());
}

void proc_msg_PL5(PMSG *m) {
    PHIST *h;
    PBOX *body;

    h = (PHIST *)HST_getHeadHistoryNode();
    if (h == NULL) {
        return;
    }
    body = h->body;
    if (body == NULL) {
        return;
    }
    setUiGlobal_browser();
    GUI_Toolkit_mutexLock();
    if (m->unk10 == 0) {
        PPREF *pref;

        pref = gPREF_UI;
        lo_global.unk6C = pref->unk24;
        relayoutAtBody(body, 1);
        lo_global.unk68 = lo_global.unk6C;
    } else {
        relayoutAtBody(body, 0);
    }
    GUI_Toolkit_mutexUnlock();
    drawPaint(body);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_PL6(int arg0) {
    if (HST_getHeadHistoryNode() != 0) {
        handleMouseEvent(arg0);
    }
}

void proc_msg_PL7(PMSG *msg) {
    int *d;

    d = msg->data;
    getDataAttribute(d[0], d[1], d[2]);
    MEM_free(0, d);
}

void proc_msg_PL8(PMSG *m) {
    PHIST *h;
    PHIST *c;
    PBOX *body;
    PSRCH *s;
    int r;

    r = 0;
    s = m->data;
    h = HST_searchSessionIDHistoryNode(gESPRIT_LO_GLOBAL_NDA->session);
    if (h == NULL) {
        h = (PHIST *)HST_getHeadHistoryNode();
        if (h == NULL) {
            if (s != NULL) {
                MEM_free(0, s);
            }
            putLLIST(&REQUEST_LLIST, make_msg_LP3(m, 0));
            return;
        }
        while ((c = HST_getChildHistoryNode(h)) != NULL && HST_getRequestFlag(c) >= 0 && c->body != NULL
               && !checkBoxValidity(c->body)) {
            h = c;
        }
    }
    body = h->body;
    if (body != NULL && checkBoxValidity(body) && s->unk8 != 0) {
        r = actSearchString(body, s->str, s->unk2, s->unk4);
    }
    MEM_free(0, s);
    if (m->unk10 == 1) {
        putLLIST(&REQUEST_LLIST, make_msg_LJ6(m, r));
    } else {
        putLLIST(&REQUEST_LLIST, make_msg_LP3(m, r));
    }
}

void proc_msg_PL11(PMSG *m) {
    PHIST *h;
    PJSRC *d;
    PJSARG *a;
    u16 *buf;
    PJSRUN run;
    int *z;

    h = HST_searchSessionIDHistoryNode(m->unk4);
    if (h == NULL || h->body == NULL) {
        if (m->data != NULL) {
            MEM_free(0, m->data);
        }
        z = MEM_malloc(0, 0xC);
        z[0] = 0;
        z[1] = 0;
        z[2] = 0;
        m->data = z;
        m->len = 0xC;
        putLLIST(&REQUEST_LLIST, make_msg_LP12(m));
        return;
    }
    d = m->data;
    a = MEM_malloc(0, sizeof(PJSARG));
    if (a == NULL) {
        return;
    }
    buf = MEM_malloc(0, d->len * 2 + 2);
    if (buf == NULL) {
        MEM_free(0, a);
        return;
    }
    run.type = 4;
    run.session = m->unk4;
    run.unk8 = 0;
    run.unkC = 0x402;
    run.unk10 = 0;
    run.unk14 = 0;
    a->obj = Node_getJSObj(d->node);
    a->str = buf;
    memcpy(buf, d->str, d->len * 2);
    buf[d->len] = 0;
    run.size = 8;
    run.data = a;
    MEM_free(0, d);
    JSRun(&run);
}

void proc_msg_PL15(PMSG *m) {
    void *out;
    PBOX *b;
    void *f;

    out = NULL;
    b = lo_getActiveFrameBodybox();
    if (b != NULL && (f = b->geom->focus) != NULL) {
        setFocusFocusItem(b, f, 1);
        drawFocusItem(f);
    }
    if (lo_global.flags & 0x40) {
        lo_global.flags &= ~0x40;
        out = (void *)make_msg_LJ7(m);
    } else if (lo_global.flags & 0x80) {
        lo_global.flags &= ~0x80;
    }
    MEM_free(0, m->data);
    if (out != NULL) {
        putLLIST(&REQUEST_LLIST, out);
    }
}

typedef struct PITEM {
    int unk0;
    struct PITEM *next;         /* 0x4 */
    int unk8;
    PBOX *box;                  /* 0xC */
} PITEM;

extern int D_00584CEC;
void *Node_getBox(int node);
PBOX *getNextTerminalFrame(PBOX *b, int n);
void setFocus(PBOX *b, PBOX *t, int a, int c);
int GUI_Component_setEnabled(int w, int on);
int GUI_ScrollPane_setVScrollbarMode(int w, int mode);
int GUI_ScrollPane_setHScrollbarMode(int w, int mode);
int strcasecmp(const char *a, const char *b);

void proc_msg_PL13(PMSG *m) {
    PHIST *h;
    PBOX *box;
    PBOX *first;
    PBOX *f;
    PITEM *it;
    PBOX *b;
    char *s;
    int mode;

    D_00584CEC = m->unk10;
    h = (PHIST *)HST_getHeadHistoryNode();
    if (h == NULL) {
        return;
    }
    if (HST_getDomObject(h) == 0) {
        return;
    }
    box = Node_getBox(HST_getDomObject(h));
    if (box == NULL) {
        return;
    }
    first = getNextTerminalFrame(box, 0);
    f = first;
    relayoutAtBody(first, 0);
    drawPaint(first);
    if (first != NULL && first->geom->items->box != NULL) {
        setFocus(first, first->geom->items->box, 1, 1);
    }
    do {
        for (it = f->geom->items; it != NULL; it = it->next) {
            b = it->box;
            if ((b->content >= 13 && b->content <= 16) || b->content == 18) {
                if (lo_global.unk54 == 1) {
                    GUI_Component_setEnabled(b->widget, 0);
                } else {
                    GUI_Component_setEnabled(it->box->widget, 1);
                }
            } else if (b->content == 1) {
                if (lo_global.unk54 == 1) {
                    GUI_ScrollPane_setVScrollbarMode(b->widget, 0);
                    GUI_ScrollPane_setHScrollbarMode(it->box->widget, 0);
                } else {
                    s = it->box->geom->scrolling;
                    if (s != NULL && strcasecmp("no", s) == 0) {
                        mode = 0;
                    } else if (s != NULL && strcasecmp("yes", s) == 0) {
                        mode = 2;
                    } else {
                        mode = 1;
                    }
                    GUI_ScrollPane_setVScrollbarMode(it->box->widget, mode);
                    GUI_ScrollPane_setHScrollbarMode(it->box->widget, mode);
                }
            }
        }
        f = getNextTerminalFrame(f, 0);
    } while (f != first);
    if (m->data != NULL) {
        MEM_free(0, m->data);
    }
}

void proc_msg_PL16(PMSG *m) {
    PHIST *h;
    PBOX *body;
    PFOCUS *f;
    PBOX *t;
    int sel[2];
    char *s;
    PNDA *nda;

    nda = gESPRIT_LO_GLOBAL_NDA;
    if (m->unk10 == 0 && (h = HST_searchSessionIDHistoryNode(nda->session)) != NULL
        && (body = h->body) != NULL && checkBoxValidity(body)) {
        f = body->geom->focus;
        t = NULL;
        if (f != NULL) {
            t = f->box;
        }
        if (t != NULL && t->content == 13) {
            getTextSelectionRange(t, &sel[0], &sel[1]);
            if (m->data != NULL) {
                s = MEM_malloc(0, m->len + 1);
                memcpy(s, m->data, m->len);
                s[m->len] = 0;
                replaceTextStrings(t, s, sel[0], sel[1]);
                MEM_free(0, s);
            } else {
                replaceTextStrings(t, D_001338FC, sel[0], sel[1]);
            }
        }
    }
    if (m->data != NULL) {
        MEM_free(0, m->data);
    }
}

void proc_msg_PL17(PMSG *m) {
    PHIST *head;
    PHIST *h;
    PFRAG *cur;
    PFRAG *dst;
    PBOX *body;
    int vp[2];
    void *r;

    head = (PHIST *)HST_getHeadHistoryNode();
    if (head == NULL) {
        return;
    }
    cur = HST_getFragmentIDs(head, 0);
    dst = HST_getFragmentIDs(head, m->unk10);
    if (cur == NULL || dst == NULL) {
        return;
    }
    h = HST_searchSessionIDHistoryNode(dst->id);
    if (h == NULL) {
        return;
    }
    body = h->body;
    if (body == NULL) {
        return;
    }
    if (!checkBoxValidity(body)) {
        return;
    }
    HST_moveFragmentIDs(head, m->unk10);
    getViewPort(body, &vp[0], &vp[1]);
    cur->id = dst->id;
    cur->x = vp[0];
    cur->y = vp[1];
    drawScroll(body, dst->x - vp[0], dst->y - vp[1]);
    lo_global.flags &= ~8;
    r = (void *)make_msg_LP4(h->unk48, body->geom->unk8, body->geom->unkC);
    if (r == NULL) {
        return;
    }
    putLLIST(&REQUEST_LLIST, r);
    putLLIST(&REQUEST_LLIST, make_msg_LP21(h->unk48, body));
}

char *getInputDataFromMsg(PMSG *msg) {
    unsigned int *d;
    char *buf;

    d = msg->data;
    if (*d == 0) {
        return NULL;
    }
    buf = MEM_malloc(0, *d + 1);
    if (buf == NULL) {
        return NULL;
    }
    memcpy(buf, d + 1, *d);
    buf[*d] = 0;
    return buf;
}

void proc_msg_PL18(PMSG *m) {
    PHIST *h;
    PBOX *body;
    PFOCUS *f;
    PBOX *t;
    char *s;

    if (gESPRIT_LO_GLOBAL_NDA->session == 0) {
        return;
    }
    h = HST_searchSessionIDHistoryNode(gESPRIT_LO_GLOBAL_NDA->session);
    if (h == NULL) {
        return;
    }
    body = h->body;
    if (body == NULL) {
        return;
    }
    if (!checkBoxValidity(body)) {
        return;
    }
    f = body->geom->focus;
    if (f == NULL) {
        return;
    }
    t = f->box;
    if (t->unk3E == 1) {
        return;
    }
    s = getInputDataFromMsg(m);
    if (s != NULL) {
        setTextStrings(t, s);
        MEM_free(0, s);
    }
    if (m->data != NULL) {
        MEM_free(0, m->data);
    }
}

void proc_msg_PL19(PMSG *msg) {
    int *d;
    PPOINT p;

    d = msg->data;
    p.y = d[4];
    p.x = d[3];
    putLLIST(&REQUEST_LLIST, make_msg_LP11(1, d[1], d[2], &p, 0, d[0]));
    MEM_free(0, msg->data);
}

typedef struct {
    u8 unk0[0x10];
    char *frag;                 /* 0x10 */
} PURL;
void drawAnimation();
char *HST_getCurURI();
PURL *URL_new();
int URL_equals();
void URL_free();
void lo_clearTimer();
int HST_getTargetName();
int make_msg_LP8();
int strcmp();

void proc_msg_TM(PMSG *msg) {
    PMSG m;
    int *node;
    PBOX *body;
    char *cur;
    char *url;
    int mode;
    PURL *u1;
    PURL *u2;

    switch (msg->unk8) {
    case 0:
        drawAnimation();
        return;
    case 2:
        node = HST_searchSessionIDHistoryNode(msg->unk4);
        if (node != NULL && (body = (PBOX *)node[0x6C / 4]) != NULL && checkBoxValidity(body) == 1) {
        cur = HST_getCurURI(node);
        if (M2C_FIELD(M2C_FIELD(body, void **, 0x20), char **, 0x30) == NULL) {
            url = cur;
            mode = 1;
        } else {
            url = M2C_FIELD(M2C_FIELD(body, void **, 0x20), char **, 0x30);
            u1 = URL_new(cur);
            if (u1 == NULL) {
                return;
            }
            u2 = URL_new(url);
            if (u2 == NULL) {
                MEM_free(0, u1);
                return;
            }
            if (URL_equals(u1, u2) && (u1->frag != NULL || u2->frag != NULL)) {
                if (u1->frag != NULL && u2->frag != NULL) {
                    strcmp(u1->frag, u2->frag);
                }
            }
            URL_free(u1);
            URL_free(u2);
            mode = 2;
        }
        m.unk4 = msg->unkC;
        m.unk10 = 0;
        lo_clearTimer(msg->unk10);
        putLLIST(&REQUEST_LLIST, make_msg_LP8(&m, url, cur, HST_getTargetName(node), mode, 1, 0));
        break;
        }
    case 1:
        lo_clearTimer(msg->unk10);
        break;
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", D_001338FC);
