/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
#include "m2c_macros.h"
extern unsigned char _DOMform;
int Node_getNodeType(void *node);
void *Node_getParentNode(void *node);
void Element_getTagName(DOMString *s, void *node);
int DOMStringcasecmpFast(DOMString *s, void *str);
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", addSaveFormData);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", getPreviousForm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", getInputType);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", addFormElementList);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", freeCurPageFormList);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", actRestoreForm);

#ifndef NULL
#define NULL ((void *)0)
#endif

void actClearForm(void) {
    clearSaveFormData();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", addRadioList);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", layoutWaitMail);
