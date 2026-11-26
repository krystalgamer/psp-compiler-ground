/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK OS_timer_clear(int);                        /* extern */
M2C_UNK OS_timer_stop(int);                         /* extern */
extern void *D_00584CDC;
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
int OS_timer_set(int, int, int, int, int, int, int); /* extern */
M2C_UNK OS_timer_start(int);                        /* extern */
void *HST_searchSessionIDHistoryNode(int);          /* extern */
int checkBoxValidity(int);                          /* extern */
void *Node_getBox(int);                             /* extern */
M2C_UNK actSetFocusByBox(int, void *, M2C_UNK);     /* extern */
int getBodyBox(void *);                             /* extern */
int getInputType(int);                              /* extern */
M2C_UNK selectText(void *);                         /* extern */

int make_msg_LP1();                                 /* extern */
M2C_UNK putLLIST(M2C_UNK *, int);                   /* extern */
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
    u8 unk48[0x38];
    int unk80;
} TLOGLOBAL;

typedef struct {
    int unk0;
    int target;
} JSEVENT;

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



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", divOverText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", divOverText_pre);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", createTextBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", divTextBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", divPreTextBox);

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

    temp_s2 = D_00584CDC;
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

    temp_s0 = D_00584CDC;
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", initJSEnv);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", destroyJSEnv);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", initJSEvent);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL5);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL11);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL14);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL15);
