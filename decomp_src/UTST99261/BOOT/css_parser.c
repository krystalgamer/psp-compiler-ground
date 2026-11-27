/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void *newCSSCharsetRule();
void addCSSCharsetRule(void *r);
u16 *CSS_SkipBlanksAndComments(u16 *p);
u16 *CSS_string(u16 *s, u16 **out);
u16 *CSS_ident(u16 *s, u16 **out);
void *UCS_strdup(void *s);
void *newCSSStyleSheet(int type);
u16 *CSS_mediaList(u16 *p, u16 *m);
void CSS_StyleSheetRuleList(void *ss, u16 *text);
void *newCSSStyleRule();
u16 *CSS_selectorList(void *r, u16 *p);
u16 *CSS_SkipRule(u16 *p);
M2C_UNK freeCSSCharsetRule();                       /* extern */
M2C_UNK freeCSSImportRule();                        /* extern */
M2C_UNK freeCSSStyleRule();                         /* extern */
M2C_UNK freeCSSUnknownRule();                       /* extern */
M2C_UNK addCSSNode(int, void *);                    /* extern */
int CSSCharsetRule_getType();                       /* extern */
int CSSImportRule_getType();                        /* extern */
int CSSMediaRule_getType();                         /* extern */
int CSSStyleRule_getType();                         /* extern */
int CSSUnknownRule_getType();                       /* extern */
int CSSCharsetRule_getCssText();                    /* extern */
int CSSImportRule_getCssText();                     /* extern */
int CSSMediaRule_getCssText();                      /* extern */
int CSSStyleRule_getCssText();                      /* extern */
int CSSUnknownRule_getCssText();                    /* extern */
M2C_UNK CSSCharsetRule_setCssText();                /* extern */
M2C_UNK CSSImportRule_setCssText();                 /* extern */
M2C_UNK CSSMediaRule_setCssText();                  /* extern */
M2C_UNK CSSStyleRule_setCssText();                  /* extern */
M2C_UNK CSSUnknownRule_setCssText();                /* extern */
int CSSCharsetRule_getParentStyleSheet();           /* extern */
int CSSImportRule_getParentStyleSheet();            /* extern */
int CSSStyleRule_getParentStyleSheet();             /* extern */
int CSSUnknownRule_getParentStyleSheet();           /* extern */
int CSSCharsetRule_getParentRule();                 /* extern */
int CSSImportRule_getParentRule();                  /* extern */
int CSSStyleRule_getParentRule();                   /* extern */
int CSSUnknownRule_getParentRule();                 /* extern */
void *newCSSNode(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
M2C_UNK freeCSSStyleDeclaration(void *);            /* extern */
M2C_UNK MEM_calloc(M2C_UNK, M2C_UNK);               /* extern */



typedef struct CSSNODE { int x0; int x4; int x8; void *xC; int x10; int x14; struct CSSNODE *next; } CSSNODE;
void *newCSSUnknownRule(void *a0, void *a1);
void addCSSUnknownRule(void *r);
int UCS_strlen(u16 *s);
void *MEM_malloc(int pool, int size);
void UCS_strcpy(void *d, u16 *s);
u16 *ParseCSSDeclaration(void *parent, u16 *p, CSSNODE **out);
u16 *CSS_SkipProperty(u16 *p);
void *newCSSImportRule(void *a0, void *a1);
void addCSSImportRule(void *r);
extern u16 CSSSTR_url[];
int UCS_strncasecmp(u16 *a, u16 *b, int n);
u16 *CSS_nstring(u16 *s, u16 **out);
void *newCSSMediaRule(void *a0, void *a1);
void addCSSMediaRule(void *r);
void freeCSSMediaRule(void *r);
u16 *CSS_mediaRuleList(void *a0, void *r, u16 *p);
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_StyleSheetRuleList);

u16 *CSS_unknownRule(void *a0, void *a1, u16 *p) {
    void *r;
    u16 *q;
    u16 c;
    u16 *s;
    r = newCSSUnknownRule(a0, a1);
    if (r == NULL) {
        return p;
    }
    q = p;
    while (*q != 0 && *q != ';' && *q != '{') {
        q++;
        q = CSS_SkipBlanksAndComments(q);
    }
    if (*q == '{') {
        q = CSS_SkipRule(q);
    }
    c = *q;
    *q = 0;
    s = MEM_malloc(0, UCS_strlen(p) * 2 + 2);
    if (s == NULL) {
        *q = c;
        return q;
    }
    UCS_strcpy(s, p);
    M2C_FIELD(r, u16 **, 0x24) = s;
    *q = c;
    addCSSUnknownRule(r);
    return q;
}

u16 *CSS_charsetRule(void *a0, void *a1, u16 *p) {
    u16 *str;
    void *r = newCSSCharsetRule(a0, a1);
    if (r == NULL) {
        return p;
    }
    p = CSS_string(CSS_SkipBlanksAndComments(p), &str);
    if (str != NULL) {
        M2C_FIELD(r, u16 **, 0x24) = str;
    }
    p = CSS_SkipBlanksAndComments(p);
    if (*p == ';') {
        p++;
    }
    addCSSCharsetRule(r);
    return p;
}

u16 *CSS_importRule(void *a0, void *a1, u16 *p) {
    void *r;
    u16 *s;
    int m;
    int n;
    r = newCSSImportRule(a0, a1);
    if (r == NULL) {
        return p;
    }
    p = CSS_SkipBlanksAndComments(p);
    n = UCS_strlen(CSSSTR_url);
    if (UCS_strncasecmp(p, CSSSTR_url, n) == 0) {
        p = CSS_SkipBlanksAndComments(p + n);
        if (*p == '(') {
            p++;
        }
    }
    p = CSS_string(CSS_SkipBlanksAndComments(p), &s);
    if (s != NULL) {
        M2C_FIELD(r, u16 **, 0x24) = s;
    } else {
        p = CSS_nstring(p, &s);
        M2C_FIELD(r, u16 **, 0x24) = s;
    }
    p = CSS_SkipBlanksAndComments(p);
    if (*p == ')') {
        p++;
    }
    p = CSS_SkipBlanksAndComments(p);
    if (*p != ';') {
        p = CSS_mediaList(p, (u16 *)&m);
        M2C_FIELD(r, u16 *, 0x28) = *(u16 *)&m;
    }
    p = CSS_SkipBlanksAndComments(p);
    if (*p == ';') {
        p++;
    }
    addCSSImportRule(r);
    return p;
}

u16 *CSS_mediaRule(void *a0, void *a1, u16 *p) {
    CSSNODE *r;
    u16 m;
    r = newCSSMediaRule(a0, a1);
    if (r == NULL) {
        return p;
    }
    p = CSS_mediaList(CSS_SkipBlanksAndComments(p), &m);
    M2C_FIELD(r, u16 *, 0x24) = m;
    p = CSS_SkipBlanksAndComments(p);
    while (*p != '{' && *p != 0) {
        p++;
        p = CSS_SkipBlanksAndComments(p);
    }
    if (*p == '{') {
        p++;
    }
    p = CSS_SkipBlanksAndComments(CSS_mediaRuleList(a0, r, CSS_SkipBlanksAndComments(p)));
    p = CSS_SkipBlanksAndComments(p);
    while (*p != '}' && *p != 0) {
        p++;
        p = CSS_SkipBlanksAndComments(p);
    }
    if (*p == '}') {
        p++;
    }
    if (r->x8 != 0 && (*(s16 *)r->xC != 7 || ((CSSNODE *)r->xC)->x8 != 0)) {
        addCSSMediaRule(r);
    } else {
        freeCSSMediaRule(r);
    }
    return p;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_mediaRuleList);

u16 *CSS_pageRule(void *a0, void *a1, u16 *p) {
    return CSS_SkipRule(p);
}

u16 *CSS_fontfaceRule(void *a0, void *a1, u16 *p) {
    return CSS_SkipRule(p);
}

u16 *CSS_styleRule(void *a0, void *a1, u16 *p) {
    void *r = newCSSStyleRule(a0, a1);
    if (r == NULL) {
        return p;
    }
    return CSS_selectorList(r, p);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_selectorList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_selector);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_simpleSelector);

u16 *CSS_pseudo(u16 *p, u16 **out) {
    u16 *name = NULL;
    u16 *q;
    u16 *r;
    u16 c;
    q = CSS_ident(p, &name);
    if (name != NULL) {
        r = CSS_SkipBlanksAndComments(q);
        if (*r == '(') {
            do {
                r++;
            } while (*r != 0 && *r != ')' && *r != ',' && *r != '}');
            if (*r == ')') {
                r++;
            }
            q = r;
        }
        MEM_free(0, (int)name);
    }
    if (p < q) {
        c = *q;
        *q = 0;
        *out = UCS_strdup(p);
        *q = c;
        p = q;
    }
    return p;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_attrib);

u16 *CSS_styleDeclaration(CSSNODE *rule, u16 *p) {
    CSSNODE *d;
    CSSNODE *n;
    u16 *r;
    if (rule == NULL) {
        return p;
    }
    p = CSS_SkipBlanksAndComments(p);
    if (*p != '{') {
        return CSS_SkipProperty(p);
    }
    p++;
    p = CSS_SkipBlanksAndComments(p);
    r = ParseCSSDeclaration(rule->xC, p, &d);
    if (rule->xC == NULL && d != NULL) {
        do {
            n = d->next;
            freeCSSStyleDeclaration(d);
            d = n;
        } while (n != NULL);
    }
    if (d != NULL) {
        for (rule = rule->next; rule != NULL; rule = rule->next) {
            ParseCSSDeclaration(rule->xC, p, &d);
            if (rule->xC == NULL && d != NULL) {
                do {
                    n = d->next;
                    freeCSSStyleDeclaration(d);
                    d = n;
                } while (n != NULL);
            }
        }
    }
    p = CSS_SkipBlanksAndComments(r);
    if (*p == '}') {
        p++;
        p = CSS_SkipBlanksAndComments(p);
    }
    return p;
}

void *CSS_ParseStyleSheet(short type, u16 *text, void *a2, void *ss, void *t0, void *t1, void *t2, u16 *media) {
    void *n;
    int m;
    if (ss == NULL) {
        n = newCSSStyleSheet(type);
        if (n == NULL) {
            return NULL;
        }
    M2C_FIELD(n, void **, 0x20) = ss;
    M2C_FIELD(n, void **, 0x24) = a2;
    m = 0;
    if (media != NULL) {
        CSS_mediaList(media, (u16 *)&m);
    }
    M2C_FIELD(n, u16 *, 0x28) = *(u16 *)&m;
    M2C_FIELD(n, void **, 0x2C) = t1;
    M2C_FIELD(n, void **, 0x30) = t2;
    M2C_FIELD(n, void **, 0x38) = t0;
        CSS_StyleSheetRuleList(n, text);
        return n;
    }
    CSS_StyleSheetRuleList(ss, text);
    return ss;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_mediaList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_StyleSheetRuleSingle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_mediaRuleSingle);

void *newCSSRule(int type, int size, void *a2, void *a3) {
    void *n = newCSSNode(type, size);
    if (n != NULL) {
        M2C_FIELD(n, void **, 0x1C) = a2;
        M2C_FIELD(n, void **, 0x20) = a3;
    }
    return n;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeCSSRule(short *arg0) {
    short temp_v1;

    temp_v1 = *arg0;
    switch (temp_v1) {
    case 7:
        freeCSSStyleRule();
        return;
    case 3:
        freeCSSImportRule();
        return;
    case 4:
        freeCSSMediaRule(arg0);
        return;
    case 1:
        freeCSSUnknownRule();
        return;
    case 2:
        freeCSSCharsetRule();
        /* fallthrough */
    default:
        return;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSRule(void *arg0) {
    int temp_a0;

    if (arg0 != NULL) {
        temp_a0 = M2C_FIELD(arg0, int *, 0x1C);
        if (temp_a0 != 0) {
            addCSSNode(temp_a0, arg0);
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSRuleList_getLength(void *arg0) {
    void *temp_v0;

    if (arg0 != NULL) {
        temp_v0 = M2C_FIELD(arg0, void **, 4);
        if (temp_v0 != NULL) {
            return M2C_FIELD(temp_v0, int *, 8);
        }
    }
    return 0;
}

void *CSSRuleList_item(void *list, int idx) {
    void *r;
    int i;
    if (list == NULL || M2C_FIELD(list, void **, 4) == NULL || M2C_FIELD(M2C_FIELD(list, void **, 4), void **, 8) == NULL) {
        return NULL;
    }
    i = 0;
    for (r = list; r != NULL && i < idx; i++) {
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

int CSSRule_getType(short *arg0) {
    short temp_v1;

    temp_v1 = *arg0;
    switch (temp_v1) {
    case 7:
        return CSSStyleRule_getType();
    case 3:
        return CSSImportRule_getType();
    case 4:
        return CSSMediaRule_getType();
    case 1:
        return CSSUnknownRule_getType();
    case 2:
        return CSSCharsetRule_getType();
    default:
        return 1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSRule_getCssText(short *arg0) {
    short temp_v1;

    temp_v1 = *arg0;
    switch (temp_v1) {
    case 7:
        return CSSStyleRule_getCssText();
    case 3:
        return CSSImportRule_getCssText();
    case 4:
        return CSSMediaRule_getCssText();
    case 1:
        return CSSUnknownRule_getCssText();
    case 2:
        return CSSCharsetRule_getCssText();
    default:
        return 0;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CSSRule_setCssText(short *arg0) {
    short temp_v1;

    temp_v1 = *arg0;
    switch (temp_v1) {
    case 7:
        CSSStyleRule_setCssText();
        return;
    case 3:
        CSSImportRule_setCssText();
        return;
    case 4:
        CSSMediaRule_setCssText();
        return;
    case 1:
        CSSUnknownRule_setCssText();
        return;
    case 2:
        CSSCharsetRule_setCssText();
        /* fallthrough */
    default:
        return;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSRule_getParentStyleSheet(short *arg0) {
    short temp_v1;

    temp_v1 = *arg0;
    switch (temp_v1) {
    case 7:
        return CSSStyleRule_getParentStyleSheet();
    case 3:
        return CSSImportRule_getParentStyleSheet();
    case 4:
        return CSSMediaRule_getParentStyleSheet(arg0);
    case 1:
        return CSSUnknownRule_getParentStyleSheet();
    case 2:
        return CSSCharsetRule_getParentStyleSheet();
    default:
        return 0;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSRule_getParentRule(short *arg0) {
    short temp_v1;

    temp_v1 = *arg0;
    switch (temp_v1) {
    case 7:
        return CSSStyleRule_getParentRule();
    case 3:
        return CSSImportRule_getParentRule();
    case 4:
        return CSSMediaRule_getParentRule(arg0);
    case 1:
        return CSSUnknownRule_getParentRule();
    case 2:
        return CSSCharsetRule_getParentRule();
    default:
        return 0;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void newCSSSelector(void) {
    void *temp_v0;

    temp_v0 = newCSSNode(9, 0x48);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x1C) = 0;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeCSSSelector(void *arg0) {
    int temp_a1;
    int temp_a1_10;
    int temp_a1_2;
    int temp_a1_3;
    int temp_a1_4;
    int temp_a1_5;
    int temp_a1_6;
    int temp_a1_7;
    int temp_a1_8;
    int temp_a1_9;
    void *temp_a0;
    void *temp_s0;
    void *temp_s2;
    void *var_a0;
    void *var_s0;

    if (arg0 != NULL) {
        if (M2C_FIELD(arg0, short *, 0) == 9) {
            var_a0 = M2C_FIELD(arg0, void **, 0xC);
            if (var_a0 != NULL) {
                do {
                    temp_s0 = M2C_FIELD(var_a0, void **, 0x18);
                    freeCSSStyleDeclaration(var_a0);
                    var_a0 = temp_s0;
                } while (temp_s0 != NULL);
            }
            temp_a0 = M2C_FIELD(arg0, void **, 0x20);
            if (temp_a0 != NULL) {
                var_s0 = temp_a0;
                do {
                    temp_a1 = M2C_FIELD(var_s0, int *, 0x24);
                    temp_s2 = M2C_FIELD(var_s0, void **, 0x20);
                    if (temp_a1 != 0) {
                        MEM_free(0, temp_a1);
                    }
                    temp_a1_2 = M2C_FIELD(var_s0, int *, 0x2C);
                    if (temp_a1_2 != 0) {
                        MEM_free(0, temp_a1_2);
                        freeCSSChain(var_s0 + 0x28);
                    }
                    temp_a1_3 = M2C_FIELD(var_s0, int *, 0x34);
                    if (temp_a1_3 != 0) {
                        MEM_free(0, temp_a1_3);
                        freeCSSChain(var_s0 + 0x30);
                    }
                    temp_a1_4 = M2C_FIELD(var_s0, int *, 0x3C);
                    if (temp_a1_4 != 0) {
                        MEM_free(0, temp_a1_4);
                        freeCSSChain(var_s0 + 0x38);
                    }
                    temp_a1_5 = M2C_FIELD(var_s0, int *, 0x44);
                    if (temp_a1_5 != 0) {
                        MEM_free(0, temp_a1_5);
                        freeCSSChain(var_s0 + 0x40);
                    }
                    freeCSSNode((int) var_s0);
                    var_s0 = temp_s2;
                } while (temp_s2 != NULL);
            }
            temp_a1_6 = M2C_FIELD(arg0, int *, 0x24);
            if (temp_a1_6 != 0) {
                MEM_free(0, temp_a1_6);
            }
            temp_a1_7 = M2C_FIELD(arg0, int *, 0x2C);
            if (temp_a1_7 != 0) {
                MEM_free(0, temp_a1_7);
                freeCSSChain(arg0 + 0x28);
            }
            temp_a1_8 = M2C_FIELD(arg0, int *, 0x34);
            if (temp_a1_8 != 0) {
                MEM_free(0, temp_a1_8);
                freeCSSChain(arg0 + 0x30);
            }
            temp_a1_9 = M2C_FIELD(arg0, int *, 0x3C);
            if (temp_a1_9 != 0) {
                MEM_free(0, temp_a1_9);
                freeCSSChain(arg0 + 0x38);
            }
            temp_a1_10 = M2C_FIELD(arg0, int *, 0x44);
            if (temp_a1_10 != 0) {
                MEM_free(0, temp_a1_10);
                freeCSSChain(arg0 + 0x40);
            }
            freeCSSNode((int) arg0);
        }
    }
}

void addCSSSelector(s16 *list, s16 *sel) {
    if (list != NULL) {
        if (*list != 8 || sel == NULL) {
            return;
        }
        if (*sel == 9) {
            addCSSNode(list, sel);
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void newCSSChain(void) {
    MEM_calloc(0, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeCSSChain(void **arg0) {
    void *temp_a1;
    void *temp_s0;
    void *var_s1;

    if (arg0 != NULL) {
        var_s1 = *arg0;
        if (var_s1 != NULL) {
            do {
                temp_a1 = M2C_FIELD(var_s1, void **, 4);
                if (temp_a1 != NULL) {
                    MEM_free(0, temp_a1);
                }
                temp_s0 = M2C_FIELD(var_s1, void **, 0);
                MEM_free(0, var_s1);
                var_s1 = temp_s0;
            } while (temp_s0 != NULL);
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void addCSSChain(M2C_UNK *arg0, M2C_UNK *arg1) {
    M2C_UNK *var_a0;

    var_a0 = arg0;
    if (((var_a0 == NULL) | (arg1 == NULL)) == 0) {
        if (*var_a0 != NULL) {
            do {
                var_a0 = *var_a0;
            } while (*var_a0 != NULL);
        }
        *var_a0 = arg1;
    }
}
