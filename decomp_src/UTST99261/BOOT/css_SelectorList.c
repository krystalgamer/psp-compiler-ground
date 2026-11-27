/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK freeCSSValue(void *);                       /* extern */
int CSSStyleDeclaration_toString(short *);            /* extern */
M2C_UNK CSS_freePoolBuf(void *);                    /* extern */
int CSS_getPoolBuf(void *);                         /* extern */
M2C_UNK CSS_putSPoolBuf(void *, M2C_UNK *);         /* extern */
M2C_UNK CSS_putsPoolBuf(void *, int);               /* extern */
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
extern unsigned char D_0013ED48;
extern unsigned char D_0013ED4C;
extern unsigned char D_0013ED50;
extern unsigned char D_0013ED54;
extern unsigned char D_0013ED58;



int CSS_ISmatchCSSChain(void *a, void *b);
int CSS_ISmatchCombine(void *a, void *b);
typedef struct CSSChain { struct CSSChain *next; void *name; } CSSChain;
typedef struct CSSDECLN { int pad[6]; struct CSSDECLN *next; s16 prio; s16 important; } CSSDECLN;
typedef struct CSSSELN { s16 type; s16 pad; int pad2[5]; struct CSSSELN *next; } CSSSELN;
typedef struct CSSSELLIST { s16 type; s16 pad; int x4; int n; CSSSELN *head; } CSSSELLIST;
char *CSSSelector_getCssText(CSSSELN *s);
int CSS_ISmatchCSSChain(void *pa, void *pb) {
    CSSChain *a = pa;
    CSSChain *b = pb;
    int r;

    while (a != NULL && b != NULL) {
        if (a->name == NULL && b->name == NULL)
            return 0;
        if (b->name == NULL)
            return 1;
        if (a->name == NULL)
            return -1;
        r = UCS_strcasecmp(a->name, b->name);
        if (r != 0)
            return r;
        a = a->next;
        b = b->next;
    }
    if (a == NULL && b == NULL)
        return 0;
    if (b != NULL)
        return -1;
    return 1;
}

int CSS_ISmatchCombine(void *pa, void *pb) {
    char *a = pa;
    char *b = pb;
    int r;

    while (a != NULL && b != NULL) {
        if ((r = UCS_strcasecmp(M2C_FIELD(a, void **, 0x24), M2C_FIELD(b, void **, 0x24))) != 0)
            return r;
        if ((r = CSS_ISmatchCSSChain(a + 0x28, b + 0x28)) != 0)
            return r;
        if ((r = CSS_ISmatchCSSChain(a + 0x30, b + 0x30)) != 0)
            return r;
        if ((r = CSS_ISmatchCSSChain(a + 0x40, b + 0x40)) != 0)
            return r;
        if ((r = CSS_ISmatchCSSChain(a + 0x38, b + 0x38)) != 0)
            return r;
        a = M2C_FIELD(a, char **, 0x20);
        b = M2C_FIELD(b, char **, 0x20);
    }
    if (a == NULL && b == NULL)
        return 0;
    if (b != NULL)
        return -1;
    return 1;
}

int CSS_ISmatchSelector_C9540(void *a, void *b) {
    int r;

    r = UCS_strcasecmp(M2C_FIELD(a, void **, 0x24), M2C_FIELD(b, void **, 0x24));
    if (r != 0)
        return r;
    r = CSS_ISmatchCSSChain((char *)a + 0x28, (char *)b + 0x28);
    if (r != 0)
        return r;
    r = CSS_ISmatchCSSChain((char *)a + 0x30, (char *)b + 0x30);
    if (r != 0)
        return r;
    r = CSS_ISmatchCSSChain((char *)a + 0x40, (char *)b + 0x40);
    if (r != 0)
        return r;
    r = CSS_ISmatchCSSChain((char *)a + 0x38, (char *)b + 0x38);
    if (r != 0)
        return r;
    return CSS_ISmatchCombine(M2C_FIELD(a, void **, 0x20), M2C_FIELD(b, void **, 0x20));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void newCSSSelectorList(void) {
    newCSSNode(8, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void freeCSSSelectorList(void *arg0) {
    void *temp_s0;
    void *var_a0;

    if (arg0 != NULL) {
        if (M2C_FIELD(arg0, short *, 0) == 8) {
            var_a0 = M2C_FIELD(arg0, void **, 0xC);
            if (var_a0 != NULL) {
                do {
                    temp_s0 = M2C_FIELD(var_a0, void **, 0x18);
                    freeCSSSelector(var_a0);
                    var_a0 = temp_s0;
                } while (temp_s0 != NULL);
            }
            freeCSSNode((int) arg0);
        }
    }
}

void addCSSSelectorList(void *list, void *rule, void *name) {
    void *n;
    void *s;
    void *sel;
    CSSDECLN *d;
    CSSDECLN *dn;
    CSSDECLN *e;
    CSSDECLN *en;
    int r;
    int k;

    if (list == NULL)
        return;
    if (M2C_FIELD(list, s16 *, 0) != 7 || rule == NULL || M2C_FIELD(rule, s16 *, 0) != 8)
        return;
    M2C_FIELD(rule, void **, 0x1C) = name;
    for (n = M2C_FIELD(list, void **, 0xC); n != NULL; n = M2C_FIELD(n, void **, 0x18)) {
        r = UCS_strcmp(M2C_FIELD(n, void **, 0x1C), name);
        if (r > 0) {
            insCSSNode(n, rule);
            break;
        }
        if (r == 0) {
            sel = M2C_FIELD(rule, void **, 0xC);
            for (s = M2C_FIELD(n, void **, 0xC); s != NULL; s = M2C_FIELD(s, void **, 0x18)) {
                r = CSS_ISmatchSelector_C9540(s, sel);
                if (r > 0) {
                    insCSSNode(s, sel);
                    break;
                }
                if (r == 0) {
                    for (d = M2C_FIELD(sel, CSSDECLN **, 0xC); d != NULL; d = dn) {
                        dn = d->next;
                        for (e = M2C_FIELD(s, CSSDECLN **, 0xC); e != NULL; e = en) {
                            en = e->next;
                            r = d->prio - e->prio;
                            if (r == 0) {
                                if (d->important != 0 || e->important == 0) {
                                    popCSSNode(d);
                                    insCSSNode(e, d);
                                    popCSSNode(e);
                                    freeCSSStyleDeclaration(e);
                                } else {
                                    popCSSNode(d);
                                    freeCSSStyleDeclaration(d);
                                }
                                break;
                            }
                            if (r < 0) {
                                popCSSNode(d);
                                insCSSNode(e, d);
                                break;
                            }
                        }
                        if (e == NULL) {
                            popCSSNode(d);
                            addCSSNode(s, d);
                        }
                    }
                    M2C_FIELD(sel, void **, 0xC) = NULL;
                    M2C_FIELD(sel, int *, 0x10) = 0;
                    freeCSSSelector(sel);
                    break;
                }
            }
            if (s == NULL)
                addCSSNode(n, sel);
            freeCSSNode(rule);
            break;
        }
    }
    if (n == NULL)
        addCSSNode(list, rule);
}

char *CSSSelectorList_getCssText(CSSSELLIST *l) {
    void *buf;
    char *t;
    int i;
    CSSSELN *s;

    if (l == NULL || l->type != 8)
        return NULL;
    buf = CSS_newPoolBuf();
    if (buf == NULL)
        return NULL;
    t = NULL;
    for (s = l->head, i = 0; s != NULL && i < l->n; s = s->next, i++) {
        if (s->type == 9) {
            t = CSSSelector_getCssText(s);
            if (t != NULL) {
                CSS_putsPoolBuf(buf, (int)t);
                MEM_free(0, t);
            }
        }
    }
    t = (char *)CSS_getPoolBuf(buf);
    CSS_freePoolBuf(buf);
    return t;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelectorList_getLength(void *arg0) {
    void *temp_v0;

    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 8) || (temp_v0 = M2C_FIELD(arg0, void **, 4), (temp_v0 == NULL))) {
        return 0;
    }
    return M2C_FIELD(temp_v0, int *, 8);
}

void *CSSSelectorList_item(void *x, int idx) {
    void *r;
    int i;
    if (x == NULL || M2C_FIELD(x, s16 **, 4) == NULL || *M2C_FIELD(x, s16 **, 4) != 7 ||
        idx >= M2C_FIELD(M2C_FIELD(x, void **, 4), int *, 8)) {
        return NULL;
    }
    for (r = M2C_FIELD(M2C_FIELD(x, void **, 4), void **, 0xC), i = 0; r != NULL && i < idx; i++) {
        r = M2C_FIELD(r, void **, 0x18);
    }
    if (i == idx) {
        return r;
    }
    return NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelectorList_getName(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 8)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelectorList_getCssSelectors(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 8)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0xC);
}

void *newCSSStyleDeclaration(int prop) {
    void *n = newCSSNode(0xA, 0x20);
    if (n != NULL) {
        M2C_FIELD(n, s16 *, 0x1C) = prop;
    }
    return n;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeCSSStyleDeclaration(void *arg0) {
    void *temp_s0;
    void *var_a0;

    if (arg0 != NULL) {
        if (M2C_FIELD(arg0, short *, 0) == 0xA) {
            var_a0 = M2C_FIELD(arg0, void **, 0xC);
            if (var_a0 != NULL) {
                do {
                    temp_s0 = M2C_FIELD(var_a0, void **, 0x18);
                    freeCSSValue(var_a0);
                    var_a0 = temp_s0;
                } while (temp_s0 != NULL);
            }
            freeCSSNode((int) arg0);
        }
    }
}

void addCSSStyleDeclaration(void *list, CSSDECLN *d) {
    CSSDECLN *n;
    int c;

    if (list == NULL)
        return;
    for (n = M2C_FIELD(list, CSSDECLN **, 0xC); n != NULL; n = n->next) {
        c = d->prio - n->prio;
        if (c == 0) {
            if (d->important != 0 || n->important == 0) {
                insCSSNode(n, d);
                popCSSNode(n);
                freeCSSStyleDeclaration(n);
            } else {
                freeCSSStyleDeclaration(d);
            }
            break;
        }
        if (c < 0) {
            insCSSNode(n, d);
            break;
        }
    }
    if (n == NULL)
        addCSSNode(list, d);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void addBrotherCSSStyleDeclaration(void *arg0, void *arg1) {
    if (arg0 != NULL) {
        addBrotherCSSNode(arg0, arg1);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSStyleDeclaration_getCssText(short *arg0) {
    short *var_s1;
    int temp_s0;
    int temp_v0_2;
    int var_v0;
    void *temp_v0;

    var_s1 = arg0;
    if ((arg0 == NULL) || (*arg0 != 0xA)) {
        return 0;
    }
    temp_v0 = CSS_newPoolBuf();
    var_v0 = 0;
    if (temp_v0 != NULL) {
        CSS_putSPoolBuf(temp_v0, &D_0013ED48);
        CSS_putSPoolBuf(temp_v0, &D_0013ED4C);
        if (var_s1 != NULL) {
            do {
                CSS_putSPoolBuf(temp_v0, &D_0013ED50);
                temp_v0_2 = CSSStyleDeclaration_toString(var_s1);
                CSS_putsPoolBuf(temp_v0, temp_v0_2);
                MEM_free(0, temp_v0_2);
                if (M2C_FIELD(var_s1, short **, 0x18) != NULL) {
                    CSS_putSPoolBuf(temp_v0, &D_0013ED54);
                }
                CSS_putSPoolBuf(temp_v0, &D_0013ED4C);
                var_s1 = M2C_FIELD(var_s1, short **, 0x18);
            } while (var_s1 != NULL);
        }
        CSS_putSPoolBuf(temp_v0, &D_0013ED58);
        CSS_putSPoolBuf(temp_v0, &D_0013ED4C);
        temp_s0 = CSS_getPoolBuf(temp_v0);
        CSS_freePoolBuf(temp_v0);
        var_v0 = temp_s0;
    }
    return var_v0;
}
