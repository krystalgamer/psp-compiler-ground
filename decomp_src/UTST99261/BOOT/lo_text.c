/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void MEM_free(M2C_UNK, void *);                  /* extern */
void OS_timer_clear(int);                        /* extern */
M2C_UNK OS_timer_stop(int);                         /* extern */
void *MEM_malloc();
int OS_timer_set(int, int, int, int, int, int, int); /* extern */
M2C_UNK OS_timer_start(int);                        /* extern */
void *HST_searchSessionIDHistoryNode(int);          /* extern */
int checkBoxValidity(int);                          /* extern */
void *Node_getBox(int);                             /* extern */
void actSetFocusByBox(int, void *, M2C_UNK);     /* extern */
int getBodyBox(void *);                             /* extern */
int getInputType(int);                              /* extern */
M2C_UNK selectText(void *);                         /* extern */

int make_msg_LP1();                                 /* extern */
void putLLIST(M2C_UNK *, int);                   /* extern */
extern unsigned char REQUEST_LLIST;

typedef struct TIMER {
    int id;
    int timer;
    struct TIMER *next;
} TIMER;

typedef struct {
    int count;
    TIMER *head;
    int unk8;
} TIMERLIST;

typedef struct {
    int flags;                  /* 0x0 */
    u8 unk4[0x40];
    TIMERLIST *timers;          /* 0x44 */
    int unk48;
    void *unk4C;                /* 0x4C */
    void *msgbuf;               /* 0x50 */
    u8 unk54[0x28];
    int mq7C;                   /* 0x7C */
    int unk80;
    int mq84;
    int mq88;
    int mq8C;
    int mq90;
} TLOGLOBAL;

typedef struct {
    s16 type;
    s16 unk2;
    int target;                 /* 0x4 */
    s16 x;                      /* 0x8 */
    s16 y;
    s16 cx;                     /* 0xC */
    s16 cy;
    s16 sx;                     /* 0x10 */
    s16 sy;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 w;                      /* 0x1A */
    s16 h;
    s16 unk1E;
    int unk20;                  /* 0x20 */
} JSEVENT;

void *getViewClientSize();
void getBodyAbsolutePos();
int actDefaultClickAction();
void actFormInput();
void *HST_getHeadHistoryNode(void);
void GUI_Toolkit_mutexLock(void);
void GUI_Toolkit_mutexUnlock(void);
void delLLISTByHistoryTree();
void delLLISTByDocumentSession();
void freeBoxTree();
void reinitBodyBox();
void freeBox();
void delSelectListBySID();
int make_msg_LP13();
typedef struct {
    u8 unk0[0x22];
    s16 pad22;                  /* 0x22 */
    s16 unk24;
    s16 pad26;                  /* 0x26 */
    s16 unk28;
    s16 pad2A;                  /* 0x2A */
    s16 unk2C;
    s16 pad2E;                  /* 0x2E */
    s16 marginTop;              /* 0x30 */
    s16 pad32;                  /* 0x32 */
    s16 unk34;
    s16 pad36;                  /* 0x36 */
    u8 unk38[0x30];
    u8 unk68;                   /* 0x68 */
} TSTYLE;
typedef struct {
    char *str;
    int unk4;
    int unk8;
    int len;                    /* 0xC */
    union {
        int w;
        u8 b;
        u8 c[4];
        s8 sc[4];
    } unk10;
} TTEXT;
typedef struct {
    void *parent;
    u8 unk4[0xC];
    int x;                      /* 0x10 */
    int y;
    int w;
    int h;
    TTEXT *geom;                /* 0x20 */
    TSTYLE *style;              /* 0x24 */
    void *ctx;                  /* 0x28 */
    u8 unk2C[0xC];
    s16 content;                /* 0x38 */
    s16 unk3A;
    s16 html;                   /* 0x3C */
} TBOX;
TBOX *createBox();
void insLinkBox();
int newDOMString(const char *s, int len);
unsigned int strlen(const char *s);
typedef struct {
    u8 unk0[0x30];
    char *ua;                   /* 0x30 */
} TPREF;
extern TPREF *gPREF_UI;
typedef struct {
    int unk0;
    JSEVENT ev;                 /* 0x4 */
} JEVDATA;

typedef struct {
    int unk0;
    int unk4;
    void *unk8;
} TMSGDATA;

typedef struct {
    u8 unk0[0x14];
    int unk14;
    int unk18;
    void *data;                 /* 0x1C */
} TMSG;

extern TLOGLOBAL lo_global;
extern int *gJSI_NAVIGATOR_REC;
extern int *gJSI_SCREEN_REC;
void freeDOMString(int s);
int Node_getParentNode(int node);
int Node_getJSObj(int node);
int sendJSEvent(int obj, JSEVENT *ev);
int make_msg_LP12();
int make_msg_LP17();
int make_msg_LP18();
int make_msg_LJ6();
int HST_getDomObject();
int actSearchString();
int getJSSEM();
int getViewPort();
int drawScroll();
int getStringsVisibleLength();
void *memcpy(void *d, const void *s, unsigned int n);
typedef struct {
    int node;
    int unk4;
    int x;                      /* 0x8 */
    int y;
} JSCROLL;
typedef struct {
    u8 unk0[0x64];
    int font;                   /* 0x64 */
} JDOC;
typedef struct {
    u8 unk0[0x24];
    JDOC *doc;                  /* 0x24 */
} JBOX;

int OS_thread_mutex_unlock();
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 unk8[4];
    char *str;                  /* 0xC */
} JSRCH;
typedef struct {
    int unk0;
    int session;                /* 0x4 */
    u8 unk8[8];
    int unk10;
    u8 unk14[8];
    void *data;                 /* 0x1C */
} JMSG;
typedef struct {
    u8 unk0[0x6C];
    void *body;                 /* 0x6C */
} THIST;



int divOverText(char **out, JBOX *box, char *s, int len, int a1, int a2, int a3) {
    int n;
    int rest;
    char *p;
    if (s == NULL) {
        return 0;
    }
    n = getStringsVisibleLength(box->doc->font, s, len, a1, a2, a3);
    if (n == 0) {
        return len;
    }
    if (n == len) {
        return 0;
    }
    rest = len - n;
    p = MEM_malloc(0, rest + 1);
    memcpy(p, s + n, rest);
    p[rest] = 0;
    *out = p;
    return rest;
}

int divOverText_pre(char **out, JBOX *box, char *s, int len) {
    int i;
    int n;
    char *p;
    int off;

    if (s == NULL) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        if (s[i] == 0) {
            break;
        }
        if (s[i] == '\r') {
            if (s[i + 1] == '\n') {
                i++;
            }
            break;
        }
        if (s[i] == '\n') {
            break;
        }
    }
    n = len - i;
    n--;
    if (n <= 0) {
        return 0;
    }
    off = len - n;
    p = MEM_malloc(0, n + 1);
    memcpy(p, s + off, n);
    p[n] = 0;
    *out = p;
    return n;
}

TBOX *createTextBox(void *ctx, TBOX *parent, TBOX *prev, char *str, int len, int w) {
    TBOX *b;
    TTEXT *g;

    if (str == NULL) {
        return NULL;
    }
    b = createBox(ctx, 0);
    if (b == NULL) {
        return NULL;
    }
    insLinkBox(b, parent, prev);
    g = MEM_malloc(0, 0x14);
    g->str = NULL;
    g->unk4 = 0;
    g->unk8 = 0;
    g->len = 0;
    g->unk10.w = 0;
    b->geom = g;
    b->content = 9;
    b->html = 1;
    b->style = prev->style;
    b->geom->str = str;
    b->geom->len = len;
    b->geom->unk10.b = b->style->unk68;
    b->w = w + b->style->pad26 + b->style->pad36 + b->style->pad2E + b->style->pad2A + b->style->pad32 + b->style->pad22;
    b->h = prev->h;
    b->x += parent->style->pad36;
    b->y += parent->style->marginTop;
    return b;
}

void initTextBoxSize(TBOX *b);

TBOX *divTextBox(TBOX *box, int a1, int a2, int *a3) {
    void *parent;
    int len;
    int n;
    int w;
    char *rest;
    char *str;
    char *buf;
    TBOX *nb;

    *a3 = 0;
    parent = box->parent;
    if (parent == NULL) {
        return NULL;
    }
    str = box->geom->str;
    len = box->geom->len;
    if (len <= 0) {
        return NULL;
    }
    w = box->w;
    rest = NULL;
    n = divOverText(&rest, (JBOX *)box, str, len, a1, a2, a3);
    if (n < 1 || n >= len) {
        goto fail;
    }
    len -= n;
    buf = MEM_malloc(0, len + 1);
    memcpy(buf, box->geom->str, len);
    buf[len] = 0;
    MEM_free(0, box->geom->str);
    box->geom->str = buf;
    box->geom->len = len;
    initTextBoxSize(box);
    w -= box->w;
    nb = createTextBox(box->ctx, parent, box, rest, n, w);
    if (nb == NULL) {
fail:
        if (rest != NULL) {
            MEM_free(0, rest);
        }
        return NULL;
    }
    nb->geom->unk10.c[1] = 1;
    if (len < box->geom->unk8) {
        nb->geom->unk8 = box->geom->unk8 - len;
        box->geom->unk8 = len;
    }
    return nb;
}

void *memset(void *p, int c, unsigned int n);

TBOX *divPreTextBox(TBOX *box) {
    void *parent;
    char *str;
    int len;
    int n;
    char *rest;
    char *buf;
    TBOX *nb;

    parent = box->parent;
    if (parent == NULL) {
        return NULL;
    }
    str = box->geom->str;
    len = box->geom->len;
    rest = NULL;
    n = divOverText_pre(&rest, (JBOX *)box, str, len);
    if (n < 1 || n >= len) {
        goto fail;
    }
    len -= n;
    buf = MEM_malloc(0, len + 1);
    memset(buf, 0, len + 1);
    memcpy(buf, str, len);
    MEM_free(0, str);
    box->geom->str = buf;
    box->geom->len = len;
    nb = createTextBox(box->ctx, parent, box, rest, n, 0);
    if (nb == NULL) {
fail:
        if (rest != NULL) {
            MEM_free(0, rest);
        }
        return NULL;
    }
    nb->geom->unk10.c[1] = 1;
    return nb;
}

void delLinkBox();
void delBoxList();
int getCurrentLineCB();

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", integrateTextBox);

void lo_initTimer(void) {
    TIMERLIST *t;
    TIMER *n;

    t = MEM_malloc(0, sizeof(TIMERLIST));
    t->count = 0;
    n = MEM_malloc(0, sizeof(TIMER));
    n->id = t->count++;
    n->timer = 0;
    n->next = NULL;
    t->head = n;
    lo_global.timers = t;
    t->unk8 = lo_global.unk80;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void lo_freeTimer(void) {
    void *temp_s0;
    void *temp_s2;
    void *var_s1;

    temp_s2 = (*(void * *)((char *)&lo_global + 0x44));
    var_s1 = M2C_FIELD(M2C_FIELD(temp_s2, void **, 4), void **, 8);
    if (var_s1 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_s1, void **, 8);
            OS_timer_stop(M2C_FIELD(var_s1, int *, 4));
            OS_timer_clear(M2C_FIELD(var_s1, int *, 4));
            MEM_free(0, var_s1);
            var_s1 = temp_s0;
        } while (temp_s0 != NULL);
    }
    MEM_free(0, M2C_FIELD(temp_s2, void **, 4));
    MEM_free(0, temp_s2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int lo_setTimer(int arg0, int arg1, int arg2, int arg3) {
    int temp_v0;
    void *temp_s0;
    void *temp_v0_2;
    void *var_s0;

    temp_s0 = (*(void * *)((char *)&lo_global + 0x44));
    temp_v0 = OS_timer_set(M2C_FIELD(temp_s0, int *, 8), arg0, arg1, arg2, arg3, arg1, arg2);
    OS_timer_start(temp_v0);
    var_s0 = M2C_FIELD(temp_s0, void **, 4);
    if (M2C_FIELD(var_s0, int *, 8) != 0) {
        do {
            var_s0 = M2C_FIELD(var_s0, void **, 8);
        } while (M2C_FIELD(var_s0, int *, 8) != 0);
    }
    temp_v0_2 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0_2, int *, 0) = temp_v0;
    M2C_FIELD(temp_v0_2, int *, 4) = temp_v0;
    M2C_FIELD(temp_v0_2, int *, 8) = 0;
    M2C_FIELD(var_s0, void **, 8) = temp_v0_2;
    return temp_v0;
}

void lo_clearTimer(int id) {
    TIMER *prev;
    TIMER *p;

    prev = lo_global.timers->head;
    for (p = prev->next; p != NULL; p = p->next) {
        if (p->id == id) {
            prev->next = p->next;
            OS_timer_clear(p->timer);
            MEM_free(0, p);
            return;
        }
        prev = p;
    }
}

int initJSEnv(void) {
    int *nav;
    int *scr;
    TPREF *p;

    nav = MEM_malloc(0, 0x18);
    if (nav == NULL) {
        return -1;
    }
    nav[0] = 0;
    nav[1] = 0;
    nav[2] = 0;
    nav[3] = 0;
    nav[4] = 0;
    nav[5] = 0;
    nav[0] = newDOMString("SCE PSP BROWSER", 15);
    nav[1] = newDOMString("SCE PSP BROWSER", 15);
    nav[2] = newDOMString("1.0", 3);
    nav[3] = newDOMString("ja", 2);
    nav[4] = newDOMString("PSP", 3);
    p = gPREF_UI;
    if (p->ua != NULL) {
        nav[5] = newDOMString(p->ua, strlen(p->ua));
    } else {
        nav[5] = newDOMString("SCE PSP BROWSER 0100", 10);
    }
    gJSI_NAVIGATOR_REC = nav;
    scr = MEM_malloc(0, 0x20);
    if (scr == NULL) {
        MEM_free(0, nav);
        return -1;
    }
    scr[0] = 480;
    scr[1] = 272;
    scr[2] = 0;
    scr[3] = 0;
    scr[4] = 480;
    scr[5] = 272;
    scr[6] = 32;
    scr[7] = 32;
    gJSI_SCREEN_REC = scr;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", destroyJSEnv);

void initJSEvent(JSEVENT *ev, int type, int node, int x, int y) {
    void *body;
    int cw;
    int ch;
    int vx;
    int vy;
    int bx;
    int by;

    body = (void *)getBodyBox(Node_getBox(node));
    getViewClientSize(body, &cw, &ch);
    getViewPort(body, &vx, &vy);
    getBodyAbsolutePos(body, &bx, &by);
    ev->type = type;
    ev->target = node;
    ev->x = x;
    ev->y = y;
    ev->cx = x - bx + vx;
    ev->cy = y - by + vy;
    ev->sx = x;
    ev->sy = y;
    ev->unk14 = 1;
    ev->unk16 = 0;
    ev->unk18 = 0;
    ev->w = cw;
    ev->h = ch;
    ev->unk20 = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", sendJSEvent);

int sendJSBubbleUpEvent(int node, JSEVENT *ev) {
    int obj;
    int handled;

    handled = 0;
    for (; node != 0; node = Node_getParentNode(node)) {
        obj = Node_getJSObj(node);
        if (obj != 0) {
            ev->target = node;
            if (sendJSEvent(obj, ev) != 0) {
                handled = 1;
            }
        }
    }
    return handled;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_JL1(void) {
    putLLIST(&REQUEST_LLIST, make_msg_LP1());
}

void proc_msg_JL2(TMSG *msg) {
    TMSGDATA *d;

    if (msg->unk14 == 0) {
        putLLIST((M2C_UNK *)&REQUEST_LLIST, make_msg_LP12(msg));
        return;
    }
    d = msg->data;
    if (d->unk8 != NULL) {
        MEM_free(0, d->unk8);
    }
    MEM_free(0, d);
}

typedef struct {
    int unk0;
    JMSG m;
} JL3BUF;
int OS_thread_join();
void OS_thread_exit();
int OS_mq_close();
int OS_mq_unlink();
int OS_mq_send();
void OS_thread_mutex_destroy();
void actClearSearchString();
void freeSessionSaveDataList();
void destroySelectList();
void deleteDefaultImage();
void initUrlList();
void GUI_Toolkit_mutexUnlock();
extern int *gESPRIT_LO_GLOBAL_NDA;

void proc_msg_JL3(JMSG *m) {
    int ret;
    THIST *h;
    int *nda;
    JMSG *q;

    OS_thread_join((*(int *)((char *)&lo_global + 0x78)), &ret);
    h = HST_getHeadHistoryNode();
    if (h != NULL && h->body != NULL) {
        GUI_Toolkit_mutexLock();
        delLLISTByDocumentSession(&REQUEST_LLIST, 0);
        freeBoxTree(h->body, 0);
        freeBox(h->body, 0);
        GUI_Toolkit_mutexUnlock();
    }
    actClearSearchString();
    destroyJSEnv();
    OS_mq_close(lo_global.mq8C);
    OS_mq_unlink("/tmp/mq_js");
    if (lo_global.unk4C != NULL) {
        MEM_free(0, ((void **)lo_global.unk4C)[8]);
        MEM_free(0, lo_global.unk4C);
        lo_global.unk4C = NULL;
    }
    lo_freeTimer();
    freeSessionSaveDataList();
    destroySelectList();
    deleteDefaultImage();
    initUrlList(&(*(int *)((char *)&lo_global + 0x58)));
    nda = gESPRIT_LO_GLOBAL_NDA;
    OS_thread_mutex_destroy(nda[0x3C / 4]);
    OS_thread_mutex_destroy(nda[0x40 / 4]);
    MEM_free(0, nda);
    gESPRIT_LO_GLOBAL_NDA = NULL;
    q = &((JL3BUF *)lo_global.msgbuf)->m;
    q->unk0 = 4;
    q->session = m->session;
    ((int *)q)[3] = 0x11;
    OS_mq_send(lo_global.mq7C, lo_global.msgbuf, 0x24, 0);
    lo_global.msgbuf = NULL;
    OS_mq_close(lo_global.mq84);
    OS_mq_unlink("/tmp/mq_lo_reserve");
    OS_mq_close(lo_global.mq7C);
    OS_mq_close(lo_global.mq88);
    OS_mq_close(lo_global.unk80);
    OS_mq_close(lo_global.mq90);
    OS_thread_exit(ret);
}

void proc_msg_JL4(JMSG *m) {
    THIST *h;
    JSEVENT *ev;

    h = HST_searchSessionIDHistoryNode(m->session);
    if (h != NULL && h->body != NULL && checkBoxValidity((int)h->body)) {
        ev = &((JEVDATA *)m->data)->ev;
        if (ev->type == 4) {
            if (m->unk10 & 2) {
                m->unk10 = 0;
                actDefaultClickAction(m, Node_getBox(ev->target), ev->target, ev->x, ev->y);
            }
        } else if ((ev->type == 0x16 || ev->type == 0x13) && (m->unk10 & 2)) {
            actFormInput(m, Node_getBox(ev->target), Node_getBox(ev->unk20), getInputType(ev->unk20));
        }
    }
    MEM_free(0, m->data);
}

typedef struct {
    int unk0;
    int unk4;
    int len;                    /* 0x8 */
    u16 str[1];                 /* 0xC */
} JLINK;
int ucs2ToUtf8();
int strncasecmp();
char *lo_fullUrl();
void actLinkJumpInner();
int make_msg_LP8();

void proc_msg_JL5(JMSG *m) {
    THIST *h;
    JLINK *d;
    char *url;

    h = HST_searchSessionIDHistoryNode(m->session);
    if (h == NULL || h->body == NULL || checkBoxValidity(h->body) == 0) {
        MEM_free(0, m->data);
        return;
    }
    if (m->unk10 == 0) {
        d = m->data;
        url = MEM_malloc(0, d->len * 3 + 1);
        url[ucs2ToUtf8(url, d->str, d->len)] = 0;
        if (strncasecmp(url, "mailto:", 7) != 0) {
            if (*(int *)&m->unk14[0] != 0) {
                h = HST_searchSessionIDHistoryNode(*(int *)&m->unk14[0]);
            }
            url = lo_fullUrl(h->body, url);
            if (url == NULL) {
                return;
            }
        }
        actLinkJumpInner(m, HST_searchSessionIDHistoryNode(m->session), url, 0, 0, 0, d->unk0, d->unk4, 0);
        MEM_free(0, url);
    } else {
        putLLIST(&REQUEST_LLIST, make_msg_LP8(m, NULL, NULL, NULL, 0, 0, 0));
    }
    if (m->data != NULL) {
        MEM_free(0, m->data);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_JL6(void *arg0) {
    int temp_a0;
    void *temp_v0;

    temp_v0 = HST_searchSessionIDHistoryNode(M2C_FIELD(arg0, int *, 4));
    if (temp_v0 != NULL) {
        temp_a0 = M2C_FIELD(temp_v0, int *, 0x6C);
        if ((temp_a0 != 0) && (checkBoxValidity(temp_a0) != 0)) {
            putLLIST(&REQUEST_LLIST, make_msg_LP16(arg0));
        }
    }
}

void proc_msg_JL7(JMSG *m) {
    JSRCH *s;
    int r;
    int out;

    if (m->unk10 == 0) {
        s = m->data;
        r = actSearchString(Node_getBox(HST_getDomObject(HST_searchSessionIDHistoryNode(m->session))), s->str, s->unk2, s->unk4);
        MEM_free(0, m->data);
        out = make_msg_LJ6(m, r);
    } else {
        out = make_msg_LP17(m, 1);
        lo_global.flags |= 0x80;
    }
    putLLIST((M2C_UNK *)&REQUEST_LLIST, out);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_JL8(void *arg0) {
    M2C_UNK var_s2;
    int temp_a0;
    void *temp_v0;
    void *var_s0;

    var_s2 = 0;
    temp_v0 = Node_getBox(M2C_FIELD(arg0, int *, 0x1C));
    var_s0 = temp_v0;
    if (getInputType(M2C_FIELD(temp_v0, int *, 0x28)) == 3) {
        var_s0 = M2C_FIELD(var_s0, void **, 0xC);
    }
    temp_a0 = getBodyBox(var_s0);
    if (M2C_FIELD(arg0, int *, 0x10) == 0) {
        var_s2 = 1;
    }
    actSetFocusByBox(temp_a0, var_s0, var_s2);
}

void proc_msg_JL9(JMSG *m) {
    THIST *h;

    h = HST_searchSessionIDHistoryNode(m->session);
    if (h == NULL || h->body == NULL || !checkBoxValidity((int)h->body)) {
        goto fail;
    }
    getBodyBox(h->body);
    if (lo_global.flags & 0x18) {
fail:
        MEM_free(0, m->data);
        OS_thread_mutex_unlock(getJSSEM());
        return;
    }
    putLLIST((M2C_UNK *)&REQUEST_LLIST, make_msg_LP18(m));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_JL10(void *arg0) {
    void *temp_v0;

    temp_v0 = Node_getBox(M2C_FIELD(arg0, int *, 0x1C));
    if ((M2C_FIELD(temp_v0, short *, 0x38) == 0xD) && (M2C_FIELD(temp_v0, short *, 0x3E) == 0) && (getInputType(M2C_FIELD(temp_v0, int *, 0x28)) != 3)) {
        selectText(temp_v0);
        actSetFocusByBox(getBodyBox(temp_v0), temp_v0, 1);
    }
}

void actSubmitForm();
void actResetForm();
void actFormInput();
int getAncestorForm();
int getInputType();

void proc_msg_JL11(JMSG *m) {
    JSEVENT ev;
    int node;
    int form;
    int type;
    int r;

    node = M2C_FIELD(m, int *, 0x1C);
    if (m->unk10 == 0) {
        initJSEvent(&ev, 0x16, node, 0, 0);
        ev.unk20 = node;
        r = sendJSEvent(Node_getJSObj(node), &ev);
        if (r != 1)
            actSubmitForm(Node_getBox(node), 0, 0, 0);
    } else if (m->unk10 == 1) {
        initJSEvent(&ev, 0x13, node, 0, 0);
        ev.unk20 = node;
        if (sendJSEvent(Node_getJSObj(node), &ev) != 1)
            actResetForm(Node_getBox(node), 0);
    } else if (m->unk10 == 2) {
        form = getAncestorForm(node);
        if (form != 0) {
            type = getInputType(node);
            if (type != 0) {
                initJSEvent(&ev, 4, node, 0, 0);
                r = sendJSBubbleUpEvent(node, &ev);
                if (r != 1) {
                    if (type == 3)
                        actFormInput(m, Node_getBox(form), M2C_FIELD(Node_getBox(node), int *, 0xC), 3);
                    else
                        actFormInput(m, Node_getBox(form), Node_getBox(node), type);
                }
            }
        }
    }
}

void proc_msg_JL12(JMSG *m) {
    JSCROLL *d;
    void *box;
    int vx;
    int vy;

    if (m->data == NULL) {
        return;
    }
    d = m->data;
    box = Node_getBox(d->node);
    if (d->unk4 == 0) {
        getViewPort(box, &vx, &vy);
        drawScroll(box, d->x - vx, d->y - vy);
    } else {
        drawScroll(box, d->x, d->y);
    }
    MEM_free(0, m->data);
}

void proc_msg_JL13(TMSG *msg) {
    if (msg->data != NULL) {
        putLLIST((M2C_UNK *)&REQUEST_LLIST, make_msg_LP17(msg, 0));
        lo_global.flags |= 0x40;
        MEM_free(0, msg->data);
    }
}

typedef struct {
    int kind;
    int node;
    int len;                    /* 0x8 */
    u16 *str;                   /* 0xC */
} JIMGREQ;
typedef struct {
    int unk0;
    int user;
    int pass;
} JAUTH;
char *URL_toAbsoluteURL();
int requestImageData();
JAUTH *HST_searchAuthorizationDB();
void reserveGetRequest();
void relayoutAtBody();
int drawObject();
extern void *ui_global;

void proc_msg_JL14(JMSG *m) {
    THIST *h;
    JIMGREQ *r;
    void *body;
    void *box;
    char *buf;
    char *url;
    int ret;
    JAUTH *a;

    url = NULL;
    h = HST_searchSessionIDHistoryNode(m->session);
    if (h != NULL && h->body != NULL && checkBoxValidity(h->body) != 0) {
        r = m->data;
        body = h->body;
        box = NULL;
        if (r->kind == 1) {
            box = Node_getBox(r->node);
        }
        buf = MEM_malloc(0, r->len * 3 + 1);
        if (buf != NULL) {
            if (((int *)ui_global)[0x98 / 4] == 0) {
                buf[ucs2ToUtf8(buf, r->str, r->len)] = 0;
                url = URL_toAbsoluteURL(((int **)body)[8][0x28 / 4], buf);
                if (url != NULL) {
                    if (r->kind == 1) {
                        ret = requestImageData(box, url, ((int **)body)[8][0x38 / 4]);
                        if (ret == 1) {
                            drawObject(box);
                        } else if (ret == 2) {
                            relayoutAtBody(body, 0);
                            drawObject(body);
                        }
                    } else {
                        a = HST_searchAuthorizationDB(url);
                        if (a == NULL) {
                            reserveGetRequest(0, url, m->session, ((int *)h)[0x30 / 4], ((int *)h)[0xA4 / 4], 0, 0, 0);
                        } else {
                            reserveGetRequest(0, url, m->session, ((int *)h)[0x30 / 4], ((int *)h)[0xA4 / 4], 0, a->user, a->pass);
                        }
                    }
                }
            }
            if (url != NULL) {
                MEM_free(0, url);
            }
            MEM_free(0, buf);
        }
    }
    MEM_free(0, m->data);
}

void proc_msg_JL15(JMSG *m) {
    THIST *h;
    THIST *head;
    void *body;

    h = HST_searchSessionIDHistoryNode(m->session);
    head = HST_getHeadHistoryNode();
    if (head == NULL) {
        return;
    }
    if (h == NULL) {
        body = head->body;
    } else {
        body = h->body;
    }
    if (body == NULL) {
        return;
    }
    GUI_Toolkit_mutexLock();
    if (m->session != 0) {
        if (head != h) {
            delLLISTByHistoryTree(&REQUEST_LLIST, h);
            delLLISTByDocumentSession(&REQUEST_LLIST, m->session);
            freeBoxTree(body, 0);
            reinitBodyBox(body, 0);
        } else {
            delLLISTByDocumentSession(&REQUEST_LLIST, 0);
            freeBoxTree(body, 0);
            freeBox(body, 0);
            h->body = NULL;
        }
    } else {
        delLLISTByDocumentSession(&REQUEST_LLIST, 0);
        freeBoxTree(body, 0);
        freeBox(body, 0);
        head->body = NULL;
    }
    GUI_Toolkit_mutexUnlock();
    delSelectListBySID(m->session);
    lo_global.flags &= ~8;
    lo_global.flags &= ~0x20;
    putLLIST((M2C_UNK *)&REQUEST_LLIST, make_msg_LP13(m));
}
