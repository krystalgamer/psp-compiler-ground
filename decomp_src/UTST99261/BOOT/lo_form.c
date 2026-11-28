/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
#include "m2c_macros.h"
extern unsigned char _DOMform;
int Node_getNodeType(void *node);
void *Node_getParentNode(void *node);
int Element_getTagName(DOMString *s, void *node);
int DOMStringcasecmpFast(DOMString *s, void *str);
void MEM_free(M2C_UNK, void *);                  /* extern */

int Node_getBox(int);                               /* extern */
M2C_UNK resetFormData(int, M2C_UNK);                /* extern */
void clearSaveFormData(void);


typedef struct FormEnt { void *form; int pad; struct FormEnt *next; } FormEnt;
void *MEM_malloc(int, int);
typedef struct SaveForm { int type; void *data; struct SaveForm *next; } SaveForm;
typedef struct RadioEnt { int pad; struct RadioEnt *next; void *box; char *name; } RadioEnt;
int strcmp(const char *, const char *);
void *getBoxByHTML(void *box, int html);
extern int *gESPRIT_LO_GLOBAL_NDA;
extern char REQUEST_LLIST[];
void *getFocusTargetContentContext(void *g);
int checkBoxValidity(void *box);
void *make_msg_LP20(int a, int b, int c, int d, int e);
void putLLIST(void *l, void *m);
void *Node_getLastChild(void *node);
void *Node_getPreviousSibling(void *node);
int HST_getSessionID(void *h);
extern unsigned char _DOMinput, _DOMtype, _DOMbutton, _DOMcheckbox, _DOMfile, _DOMhidden, _DOMimage, _DOMpassword, _DOMradio, _DOMreset, _DOMsubmit, _DOMselect, _DOMtextarea;
int Node_getNodeName(DOMString *s, void *node);
int Element_getAttribute(DOMString *s, void *node, void *name);
typedef struct FormElem { void *elem; struct FormElem *next; } FormElem;
typedef struct { int type; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C; } LFMSG;
typedef struct { int unk0; LFMSG m; } LFBUF;
typedef struct { u8 unk0[0x80]; int rq; int sq; } LFGLOBAL;
extern LFGLOBAL lo_global;
int OS_mq_receive(int q, void *buf, int size, int flag);
int OS_mq_send(int q, void *buf, int size, int flag);
void proc_msg_PL2(LFMSG *m);
void proc_msg_TM(LFMSG *m);
typedef struct RadioItem { struct RadioItem *prev; struct RadioItem *next; void *box; } RadioItem;
void *getBodyBox(void *box);
typedef struct FBOX { u8 pad0[0x6C]; void *form; u8 pad70[0x38]; struct FBOX *parent; struct FBOX *child; struct FBOX *next; } FBOX;
unsigned int strlen(const char *);
char *strcpy(char *, const char *);
RadioEnt *getRadioListByName(void *ctx, void *box) {
    RadioEnt *r = M2C_FIELD(M2C_FIELD(ctx, void **, 0x20), RadioEnt **, 0x80);

    if (*M2C_FIELD(box, char ***, 0x20) == NULL)
        return NULL;
    for (; r != NULL; r = r->next) {
        if (strcmp(r->name, *M2C_FIELD(box, char ***, 0x20)) == 0
            && getBoxByHTML(M2C_FIELD(r->box, void **, 8), 0x23) == getBoxByHTML(box, 0x23))
            return r;
    }
    return r;
}

void addSaveFormData(void *hist, int type, void *data) {
    SaveForm *f;
    void *sd;

    f = MEM_malloc(0, sizeof(SaveForm));
    if (f == NULL)
        return;
    f->type = type;
    switch (type) {
    case 14:
    case 15:
        f->data = *(void **)data;
        break;
    case 13:
    case 18:
        f->data = data;
        break;
    default:
        MEM_free(0, f);
        return;
    }
    f->next = NULL;
    sd = (void *)getSessionSaveData(HST_getSessionID(hist));
    if (sd == NULL) {
        if ((type == 13 && data != NULL) || type == 18)
            MEM_free(0, data);
        MEM_free(0, f);
        return;
    }
    if (M2C_FIELD(sd, SaveForm **, 0x10) == NULL)
        M2C_FIELD(sd, SaveForm **, 0x10) = f;
    else
        M2C_FIELD(sd, SaveForm **, 0x14)->next = f;
    M2C_FIELD(sd, SaveForm **, 0x14) = f;
}

void clearSaveFormData(void) {
    void *sd = getSessionSaveData();
    SaveForm *f;
    SaveForm *next;

    if (sd != NULL) {
        for (f = M2C_FIELD(sd, SaveForm **, 0x10); f != NULL; f = next) {
            next = f->next;
            if (f->type == 0xD && f->data != NULL)
                MEM_free(0, f->data);
            else if (f->type == 0x12)
                MEM_free(0, f->data);
            MEM_free(0, f);
        }
        M2C_FIELD(sd, void **, 0x10) = NULL;
        M2C_FIELD(sd, int *, 0x14) = 0;
    }
}

void *getAncestorForm(void *node) {
    DOMString s;
    for (; node != NULL; node = Node_getParentNode(node)) {
        if (Node_getNodeType(node) == 1) {
            Element_getTagName(&s, node);
            if (DOMStringcasecmpFast(&s, &_DOMform) == 0) {
                return node;
            }
        }
    }
    return NULL;
}

void *getPreviousForm(void *start) {
    DOMString s;
    int up = 1;
    void *n;
    void *node = start;

    while (node != NULL) {
        if (!up && (n = Node_getLastChild(node)) != NULL) {
            node = n;
            continue;
        }
        {
            if (Node_getNodeType(node) == 1) {
                Element_getTagName(&s, node);
                if (DOMStringcasecmpFast(&s, &_DOMform) == 0)
                    return node;
            }
            if ((n = Node_getPreviousSibling(node)) != NULL) {
                node = n;
                up = 0;
            } else {
                node = Node_getParentNode(node);
                up = 1;
            }
        }
    }
    return NULL;
}

int getInputType(void *node) {
    DOMString name;
    DOMString type;
    int t = 0;

    Node_getNodeName(&name, node);
    if (DOMStringcasecmpFast(&name, &_DOMinput) == 0) {
        Element_getAttribute(&type, node, &_DOMtype);
        if (type.len == 0)
            return 11;
        if (DOMStringcasecmpFast(&type, &_DOMbutton) == 0)
            t = 1;
        else if (DOMStringcasecmpFast(&type, &_DOMcheckbox) == 0)
            t = 2;
        else if (DOMStringcasecmpFast(&type, &_DOMfile) == 0)
            t = 3;
        else if (DOMStringcasecmpFast(&type, &_DOMhidden) == 0)
            t = 4;
        else if (DOMStringcasecmpFast(&type, &_DOMimage) == 0)
            t = 5;
        else if (DOMStringcasecmpFast(&type, &_DOMpassword) == 0)
            t = 6;
        else if (DOMStringcasecmpFast(&type, &_DOMradio) == 0)
            t = 7;
        else if (DOMStringcasecmpFast(&type, &_DOMreset) == 0)
            t = 8;
        else if (DOMStringcasecmpFast(&type, &_DOMsubmit) == 0)
            t = 10;
        else
            t = 11;
    } else if (DOMStringcasecmpFast(&name, &_DOMbutton) == 0) {
        Element_getAttribute(&type, node, &_DOMtype);
        if (type.len == 0)
            return 10;
        if (DOMStringcasecmpFast(&type, &_DOMbutton) == 0)
            t = 1;
        else if (DOMStringcasecmpFast(&type, &_DOMreset) == 0)
            t = 8;
        else
            t = 10;
    } else if (DOMStringcasecmpFast(&name, &_DOMselect) == 0) {
        t = 9;
    } else if (DOMStringcasecmpFast(&name, &_DOMtextarea) == 0) {
        t = 12;
    }
    return t;
}

void addFormList(void *ctx, void *form) {
    FormEnt *e;
    FormEnt *p;

    if (ctx == NULL || form == NULL)
        return;
    e = MEM_malloc(0, 0xC);
    e->form = form;
    e->pad = 0;
    e->next = NULL;
    if (M2C_FIELD(M2C_FIELD(ctx, void **, 0x20), FormEnt **, 0x7C) == NULL) {
        M2C_FIELD(M2C_FIELD(ctx, void **, 0x20), FormEnt **, 0x7C) = e;
    } else {
        p = M2C_FIELD(M2C_FIELD(ctx, void **, 0x20), FormEnt **, 0x7C);
        while (p->next != NULL)
            p = p->next;
        p->next = e;
    }
}

void addFormElementList(void *ctx, void *form, void *elem) {
    FormEnt *f;
    FormElem *e;
    FormElem *p;

    if (ctx == NULL || elem == NULL)
        return;
    f = M2C_FIELD(M2C_FIELD(ctx, void **, 0x20), FormEnt **, 0x7C);
    if (form != NULL) {
        for (; f != NULL; f = f->next) {
            if (f->form == form)
                break;
        }
        if (f == NULL)
            return;
    } else {
        if (f == NULL)
            return;
        while (f->next != NULL)
            f = f->next;
    }
    e = MEM_malloc(0, sizeof(FormElem));
    e->elem = elem;
    e->next = NULL;
    p = (FormElem *)f->pad;
    if (p == NULL) {
        f->pad = (int)e;
    } else {
        while (p->next != NULL)
            p = p->next;
        p->next = e;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeFormList(void *arg0) {
    void *temp_s0;
    void *temp_s0_2;
    void *var_a1;
    void *var_s1;

    var_s1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x7C);
    if (var_s1 != NULL) {
        do {
            var_a1 = M2C_FIELD(var_s1, void **, 4);
            if (var_a1 != NULL) {
                do {
                    temp_s0_2 = M2C_FIELD(var_a1, void **, 4);
                    MEM_free(0, var_a1);
                    var_a1 = temp_s0_2;
                } while (temp_s0_2 != NULL);
            }
            temp_s0 = M2C_FIELD(var_s1, void **, 8);
            MEM_free(0, var_s1);
            var_s1 = temp_s0;
        } while (temp_s0 != NULL);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), int *, 0x7C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void clearAllFormData(void *arg0) {
    void *var_s0;

    if (arg0 != NULL) {
        var_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x7C);
        if (var_s0 != NULL) {
            do {
                resetFormData(Node_getBox(M2C_FIELD(var_s0, int *, 0)), 0);
                var_s0 = M2C_FIELD(var_s0, void **, 8);
            } while (var_s0 != NULL);
        }
    }
}

void freeCurPageFormList(FBOX *root)
{
    FBOX *n;
    FBOX *par;
    FBOX *stop;
    FBOX *c;

    if (root == NULL)
        return;
    n = root;
    par = root->parent;
    stop = root->next;
    if (n->form != NULL)
        clearAllFormData(n->form);
    while (n != NULL) {
        c = n->child;
        if (c != NULL) {
            n = c;
            goto clear;
        }
        c = n->next;
        if (c != NULL) {
            n = c;
            if (n == stop)
                return;
            goto clear;
        }
        n = n->parent;
        if ((n == par) | (n == root))
            return;
        while (n != NULL) {
            c = n->next;
            if (c != NULL) {
                n = c;
clear:
                if (n->form != NULL)
                    clearAllFormData(n->form);
                goto next;
            }
            n = n->parent;
            if ((n == par) | (n == root))
                return;
        }
        return;
next:;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *getFormList(void *arg0, int arg1) {
    void *var_a0;
    void *var_a2;
    void *var_v1;

    var_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x7C);
    var_a2 = NULL;
    if (var_a0 != NULL) {
loop_1:
        var_a2 = var_a0;
        if (M2C_FIELD(var_a0, int *, 0) != arg1) {
            var_v1 = M2C_FIELD(var_a0, void **, 4);
            if (var_v1 != NULL) {
loop_3:
                var_a2 = var_a0;
                if (M2C_FIELD(var_v1, int *, 0) != arg1) {
                    var_v1 = M2C_FIELD(var_v1, void **, 4);
                    if (var_v1 == NULL) {
                        goto block_5;
                    }
                    goto loop_3;
                }
            } else {
block_5:
                var_a0 = M2C_FIELD(var_a0, void **, 8);
                if (var_a0 == NULL) {
                    var_a2 = NULL;
                } else {
                    goto loop_1;
                }
            }
        }
    }
    return var_a2;
}

int confirmFepInfo(int a, int b, int c, int d, int e) {
    void *box;
    void *m;

    if ((box = M2C_FIELD(getFocusTargetContentContext(gESPRIT_LO_GLOBAL_NDA), void **, 0x6C)) == NULL || !checkBoxValidity(box))
        return -1;
    m = make_msg_LP20(a, b, c, d, e);
    if (m == NULL)
        return -1;
    putLLIST(REQUEST_LLIST, m);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", actFormInput);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", actSubmitForm);

void actResetForm(int form, M2C_UNK x) {
    resetFormData(form, x);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", actSaveForm);

int actRestoreForm(void *body, void *box) {
    void *sd;
    SaveForm *f;
    char *s;
    sd = getSessionSaveData(HST_getSessionID(M2C_FIELD(M2C_FIELD(body, void **, 0x20), void **, 0x20)));
    if (sd == NULL) {
        return 0;
    }
    if (M2C_FIELD(sd, SaveForm **, 0x10) == NULL) {
        return 0;
    }
    f = M2C_FIELD(M2C_FIELD(body, void **, 0x20), SaveForm **, 0x84);
    if (f == NULL) {
        f = M2C_FIELD(sd, SaveForm **, 0x10);
    } else {
        f = f->next;
    }
    if (f == NULL) {
        return 0;
    }
    if (f->type != M2C_FIELD(box, s16 *, 0x38)) {
        return 0;
    }
    switch (f->type) {
    case 14:
    case 15:
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), void **, 8) = f->data;
        break;
    case 13:
        if (f->data != NULL) {
            s = MEM_malloc(0, strlen(f->data) + 1);
            strcpy(s, f->data);
            M2C_FIELD(M2C_FIELD(box, void **, 0x20), char **, 0x14) = s;
        }
        break;
    case 18:
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), void **, 0xC) = f->data;
        break;
    }
    M2C_FIELD(M2C_FIELD(body, void **, 0x20), SaveForm **, 0x84) = f;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void actClearForm(void) {
    clearSaveFormData();
}

void addRadioList(void *box) {
    void *body = getBodyBox(box);
    RadioEnt *g;
    RadioEnt *p;
    RadioItem *t;
    RadioItem *e;
    if (M2C_FIELD(M2C_FIELD(body, void **, 0x20), RadioEnt **, 0x80) == NULL) {
        g = MEM_malloc(0, 0x10);
        g->pad = 0;
        g->next = NULL;
        g->box = NULL;
        g->name = NULL;
        g->name = *M2C_FIELD(box, char ***, 0x20);
        M2C_FIELD(M2C_FIELD(body, void **, 0x20), RadioEnt **, 0x80) = g;
    } else {
        p = M2C_FIELD(M2C_FIELD(body, void **, 0x20), RadioEnt **, 0x80);
        for (;;) {
            if (strcmp(p->name, *M2C_FIELD(box, char ***, 0x20)) == 0
                && getBoxByHTML(M2C_FIELD(p->box, void **, 8), 0x23) == getBoxByHTML(box, 0x23)) {
                g = p;
                break;
            }
            if (p->next == NULL) {
                g = MEM_malloc(0, 0x10);
                g->pad = 0;
                g->next = NULL;
                g->box = NULL;
                g->name = NULL;
                g->name = *M2C_FIELD(box, char ***, 0x20);
                p->next = g;
                g->pad = (int)p;
                break;
            }
            p = p->next;
        }
    }
    for (t = g->box; t != NULL; t = t->next) {
        if (t->next == NULL) {
            break;
        }
    }
    e = MEM_malloc(0, 0xC);
    e->prev = NULL;
    e->next = NULL;
    e->box = NULL;
    if (t == NULL) {
        g->box = e;
    } else {
        t->next = e;
        e->prev = t;
    }
    e->box = box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeRadioList(void *arg0) {
    void *temp_s0;
    void *temp_s2;
    void *var_a1;
    void *var_s1;

    var_s1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x80);
    if (var_s1 != NULL) {
        do {
            var_a1 = M2C_FIELD(var_s1, void **, 8);
            temp_s2 = M2C_FIELD(var_s1, void **, 4);
            if (var_a1 != NULL) {
                do {
                    temp_s0 = M2C_FIELD(var_a1, void **, 4);
                    MEM_free(0, var_a1);
                    var_a1 = temp_s0;
                } while (temp_s0 != NULL);
            }
            MEM_free(0, var_s1);
            var_s1 = temp_s2;
        } while (temp_s2 != NULL);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), int *, 0x80) = 0;
}

LFMSG layoutWaitMail(int cmd) {
    LFBUF buf;
    LFMSG m;
    for (;;) {
        OS_mq_receive(lo_global.rq, &buf, 0x24, 0);
        m = buf.m;
        if (m.unkC == cmd) {
            break;
        }
        if (m.unkC == 0x302) {
            proc_msg_PL2(&m);
            break;
        }
        if (m.type != 9) {
            OS_mq_send(lo_global.sq, &buf, 0x24, 0);
        } else {
            proc_msg_TM(&m);
        }
    }
    return m;
}
