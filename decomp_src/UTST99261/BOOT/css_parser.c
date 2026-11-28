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
u16 *CSS_mediaList(u16 *p, int *m);
void CSS_StyleSheetRuleList(void *ss, u16 *text);
void *newCSSStyleRule();
u16 *CSS_selectorList(void *r, u16 *p);
u16 *CSS_SkipRule(u16 *p);
void freeCSSCharsetRule();                       /* extern */
void freeCSSImportRule();                        /* extern */
void freeCSSStyleRule();                         /* extern */
void freeCSSUnknownRule();                       /* extern */
void addCSSNode(int, void *);                    /* extern */
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
void CSSStyleRule_setCssText();                  /* extern */
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
void MEM_free(M2C_UNK, int);                     /* extern */
void freeCSSStyleDeclaration(void *);            /* extern */
M2C_UNK MEM_calloc(M2C_UNK, M2C_UNK);               /* extern */



typedef struct CSSNODE { int x0; int x4; int x8; void *xC; int x10; int x14; struct CSSNODE *next; } CSSNODE;
void *newCSSUnknownRule(void *a0, void *a1);
void addCSSUnknownRule(void *r);
int UCS_strlen(u16 *s);
void *MEM_malloc(int pool, int size);
void *UCS_strcpy(void *d, u16 *s);
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
extern u16 CSSSTR_screen[];
extern u16 CSSSTR_tty[];
extern u16 CSSSTR_tv[];
extern u16 CSSSTR_projection[];
extern u16 CSSSTR_handheld[];
extern u16 CSSSTR_print[];
extern u16 CSSSTR_braille[];
extern u16 CSSSTR_embossed[];
extern u16 CSSSTR_aural[];
extern u16 CSSSTR_page[];
int UCS_strcasecmp(u16 *a, u16 *b);
typedef struct CSSSEL { int x0; int x4; int x8; int xC; int x10; struct CSSSEL *next; int x18; s16 x1C; s16 flags; struct CSSSEL *prev; } CSSSEL;
void *newCSSSelector(void);
void freeCSSSelector(void *arg0);
void addCSSSelector(s16 *list, s16 *sel);
u16 *CSS_simpleSelector(void *sel, u16 *p);
extern u16 CSSSTR_charset[];
extern u16 CSSSTR_import[];
extern u16 CSSSTR_media[];
extern u16 CSSSTR_font_face[];
#define CSS_ATRULE(s) ((n = UCS_strlen(s)) != 0 && UCS_strncasecmp(p, s, n) == 0 && (p[n] == ' ' || p[n] == '\t' || (p[n] == '\r' || p[n] == '\n') || p[n] == 0xC || p[n] == 0xFEFF))
u16 *CSS_Skip_S_CDO_CDC(u16 *p);
#define CSS_ISSPACE_AT(q) ((q) == ' ' || (q) == '\t' || ((q) == '\r' || (q) == '\n') || (q) == 0xC || (q) == 0xFEFF)
extern const char _ctype_[];
void *newCSSChain(void);
void addCSSChain(M2C_UNK *arg0, M2C_UNK *arg1);
u16 *CSS_attrib(u16 *p, u16 **out);
extern u16 CSSSTR_ASTERISK[];
#define CSS_CT(c) ((_ctype_ + 1)[(int)(c)])
#define CSS_TOLOWER(c) ({ int __x = (c); (CSS_CT(__x) & 1) ? __x - 'A' + 'a' : __x; })
u16 *CSS_charsetRule(void *a0, void *a1, u16 *p);
u16 *CSS_importRule(void *a0, void *a1, u16 *p);
u16 *CSS_styleRule(void *a0, void *a1, u16 *p);
u16 *CSS_mediaRule(void *a0, void *a1, u16 *p);
u16 *CSS_pageRule(void *a0, void *a1, u16 *p);
u16 *CSS_fontfaceRule(void *a0, void *a1, u16 *p);
u16 *CSS_unknownRule(void *a0, void *a1, u16 *p);
u16 *CSS_pseudo(u16 *p, u16 **out);
int CSSMediaRule_getParentStyleSheet(void *arg0);
int CSSMediaRule_getParentRule(void *arg0);
void freeCSSChain(void **arg0);
void freeCSSNode(void *n);
void CSS_StyleSheetRuleList(void *ss, u16 *p) {
    u16 c;
    u16 t;
    int n;
    p = CSS_SkipBlanksAndComments(p);
    if (*p == '@') {
        n = UCS_strlen(CSSSTR_charset);
        if (UCS_strncasecmp(p, CSSSTR_charset, n) == 0 && CSS_ISSPACE_AT(p[n])) {
            p = CSS_charsetRule(ss, NULL, p + n);
        }
    }
    p = CSS_Skip_S_CDO_CDC(p);
    t = *p;
    if (t == '@') {
        n = UCS_strlen(CSSSTR_import);
        while (*p == '@') {
            if (UCS_strncasecmp(p, CSSSTR_import, n) == 0 && CSS_ISSPACE_AT(p[n])) {
                p = CSS_importRule(ss, NULL, p + n);
                p = CSS_Skip_S_CDO_CDC(p);
            } else {
                break;
            }
        }
    }
    while ((c = *p) != 0) {
        if (c == '.' || c == ':' || c == '*' || c == '[' || c == '#' || ((unsigned int)(c - 'A') < 26 || (unsigned int)(c - 'a') < 26) || (c == '_' || c == '-') || c == '@') {
            if (c != '@') {
                p = CSS_styleRule(ss, NULL, p);
            } else {
                n = UCS_strlen(CSSSTR_media);
                if (UCS_strncasecmp(p, CSSSTR_media, n) == 0 && CSS_ISSPACE_AT(p[n])) {
                    p = CSS_mediaRule(ss, NULL, p + n);
                } else {
                    n = UCS_strlen(CSSSTR_page);
                    if (UCS_strncasecmp(p, CSSSTR_page, n) == 0 && CSS_ISSPACE_AT(p[n])) {
                        p = CSS_pageRule(ss, NULL, p + n);
                    } else {
                        n = UCS_strlen(CSSSTR_font_face);
                        if (UCS_strncasecmp(p, CSSSTR_font_face, n) == 0 && CSS_ISSPACE_AT(p[n])) {
                            p = CSS_fontfaceRule(ss, NULL, p + n);
                        } else {
                            p = CSS_unknownRule(ss, NULL, p);
                        }
                    }
                }
            }
            p = CSS_Skip_S_CDO_CDC(p);
        } else {
            p++;
        }
        p = CSS_Skip_S_CDO_CDC(p);
    }
}

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
        p = CSS_mediaList(p, &m);
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
    int m;
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

u16 *CSS_mediaRuleList(void *a0, void *a1, u16 *p) {
    u16 c;
    int n;
    p = CSS_SkipBlanksAndComments(p);
    while ((c = *p) != 0) {
        if (c == '.' || c == ':' || c == '*' || c == '[' || c == '#' || ((unsigned int)(c - 'A') < 26 || (unsigned int)(c - 'a') < 26) || (c == '_' || c == '-') || c == '@') {
            if (c != '@') {
                p = CSS_styleRule(a0, a1, p);
            } else {
                n = UCS_strlen(CSSSTR_page);
                if (UCS_strncasecmp(p, CSSSTR_page, n) == 0 && (p[n] == ' ' || p[n] == '\t' || (p[n] == '\r' || p[n] == '\n') || p[n] == 0xC || p[n] == 0xFEFF)) {
                    p = CSS_pageRule(a0, a1, p + n);
                } else {
                    p = CSS_unknownRule(a0, a1, p);
                }
            }
        } else {
            return p;
        }
        p = CSS_SkipBlanksAndComments(p);
    }
    return p;
}

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

u16 *CSS_selector(s16 *list, u16 *p) {
    CSSSEL *s;
    CSSSEL *prev;
    u16 c;
    s = newCSSSelector();
    if (s == NULL) {
        return p;
    }
    while (p = CSS_simpleSelector(s, p), p = CSS_SkipBlanksAndComments(p), (c = *p) != 0 &&
           ((c == '.' || c == ':') || (c == '*' || c == '[') || c == '#' || ((unsigned int)(c - 'A') < 26 || (unsigned int)(c - 'a') < 26) || (c == '_' || c == '-') || (c == '+' || c == '>'))) {
        prev = s;
        s = newCSSSelector();
        if (s == NULL) {
            s = prev;
            break;
        }
        s->prev = prev;
        prev->next = s;
        if (c == '+') {
            prev->x1C |= 4;
            p++;
            p = CSS_SkipBlanksAndComments(p);
        } else if (c == '>') {
            prev->x1C |= 2;
            p++;
            p = CSS_SkipBlanksAndComments(p);
        } else {
            prev->x1C |= 1;
        }
    }
    if (c == ',' || c == '{') {
        if (s->prev != NULL) {
            s->prev->next = NULL;
        }
        addCSSSelector(list, (s16 *)s);
        return p;
    }
    freeCSSSelector(s);
    while (*p != 0 && *p != ',' && *p != '{') {
        p++;
    }
    return p;
}

u16 *CSS_simpleSelector(void *sel, u16 *p) {
    u16 *name = NULL;
    u16 *v;
    u16 *q;
    u16 c;
    void **ch;
    p = CSS_ident(CSS_SkipBlanksAndComments(p), &name);
    if (name == NULL) {
        M2C_FIELD(sel, u16 **, 0x24) = UCS_strdup(CSSSTR_ASTERISK);
        if (*p == '*') {
            p++;
        }
    } else {
        M2C_FIELD(sel, u16 **, 0x24) = name;
    }
    p = CSS_SkipBlanksAndComments(p);
    while ((c = *p) != 0) {
        v = NULL;
        if (c == '#') {
            p++;
            p = CSS_ident(p, &v);
            if (v == NULL) {
                continue;
            }
            for (q = v; *q != 0; q++) {
                if (CSS_CT(*q) & 3) {
                    *q = CSS_TOLOWER(*q);
                }
            }
            M2C_FIELD(sel, u16 *, 0x1C) |= 0x20;
            if (M2C_FIELD(sel, void **, 0x34) != NULL) {
                ch = newCSSChain();
                if (ch == NULL) {
                    MEM_free(0, (int)v);
                    continue;
                }
                ch[1] = v;
                addCSSChain((M2C_UNK *)((char *)sel + 0x30), (M2C_UNK *)ch);
            } else {
                M2C_FIELD(sel, void **, 0x34) = v;
            }
        } else if (c == '.') {
            p++;
            p = CSS_ident(p, &v);
            if (v == NULL) {
                continue;
            }
            for (q = v; *q != 0; q++) {
                if (CSS_CT(*q) & 3) {
                    *q = CSS_TOLOWER(*q);
                }
            }
            M2C_FIELD(sel, u16 *, 0x1C) |= 0x10;
            if (M2C_FIELD(sel, void **, 0x2C) != NULL) {
                ch = newCSSChain();
                if (ch == NULL) {
                    MEM_free(0, (int)v);
                    continue;
                }
                ch[1] = v;
                addCSSChain((M2C_UNK *)((char *)sel + 0x28), (M2C_UNK *)ch);
            } else {
                M2C_FIELD(sel, void **, 0x2C) = v;
            }
        } else if (c == ':') {
            p++;
            p = CSS_pseudo(p, &v);
            if (v == NULL) {
                continue;
            }
            M2C_FIELD(sel, u16 *, 0x1C) |= 0x40;
            if (M2C_FIELD(sel, void **, 0x3C) != NULL) {
                ch = newCSSChain();
                if (ch == NULL) {
                    MEM_free(0, (int)v);
                    continue;
                }
                ch[1] = v;
                addCSSChain((M2C_UNK *)((char *)sel + 0x38), (M2C_UNK *)ch);
            } else {
                M2C_FIELD(sel, void **, 0x3C) = v;
            }
        } else if (c == '[') {
            p++;
            p = CSS_attrib(p, &v);
            if (v == NULL) {
                continue;
            }
            M2C_FIELD(sel, u16 *, 0x1C) |= 0x80;
            if (M2C_FIELD(sel, void **, 0x44) != NULL) {
                ch = newCSSChain();
                if (ch == NULL) {
                    MEM_free(0, (int)v);
                    continue;
                }
                ch[1] = v;
                addCSSChain((M2C_UNK *)((char *)sel + 0x40), (M2C_UNK *)ch);
            } else {
                M2C_FIELD(sel, void **, 0x44) = v;
            }
        } else {
            break;
        }
    }
    return p;
}

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
        CSS_mediaList(media, &m);
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

u16 *CSS_mediaList(u16 *p, int *m) {
    u16 *name;
    u16 *q;
    *m = 0;
    for (;;) {
        p = CSS_SkipBlanksAndComments(p);
        q = CSS_ident(p, &name);
        if (name == NULL) {
            break;
        }
        if (UCS_strcasecmp(name, CSSSTR_screen) == 0) {
            *m |= 1;
        } else if (UCS_strcasecmp(name, CSSSTR_tty) == 0) {
            *m |= 2;
        } else if (UCS_strcasecmp(name, CSSSTR_tv) == 0) {
            *m |= 4;
        } else if (UCS_strcasecmp(name, CSSSTR_projection) == 0) {
            *m |= 8;
        } else if (UCS_strcasecmp(name, CSSSTR_handheld) == 0) {
            *m |= 0x10;
        } else if (UCS_strcasecmp(name, CSSSTR_print) == 0) {
            *m |= 0x20;
        } else if (UCS_strcasecmp(name, CSSSTR_braille) == 0) {
            *m |= 0x40;
        } else if (UCS_strcasecmp(name, CSSSTR_embossed) == 0) {
            *m |= 0x80;
        } else if (UCS_strcasecmp(name, CSSSTR_aural) == 0) {
            *m |= 0x100;
        }
        MEM_free(0, (int)name);
        p = CSS_SkipBlanksAndComments(q);
        if (*p != ',') {
            break;
        }
        p++;
    }
    if (*m == 0) {
        *m = 0x1FF;
    }
    return p;
}

void CSS_StyleSheetRuleSingle(void *ss, u16 *p) {
    u16 c;
    int n;
    p = CSS_SkipBlanksAndComments(p);
    c = *p;
    if (c == '.' || c == ':' || c == '*' || c == '[' || c == '#' || ((unsigned int)(c - 'A') < 26 || (unsigned int)(c - 'a') < 26) || (c == '_' || c == '-') || c == '@') {
        if (c != '@') {
            CSS_styleRule(ss, NULL, p);
        } else if (CSS_ATRULE(CSSSTR_charset)) {
            CSS_charsetRule(ss, NULL, p + n);
        } else if (CSS_ATRULE(CSSSTR_import)) {
            CSS_importRule(ss, NULL, p + n);
        } else if (CSS_ATRULE(CSSSTR_media)) {
            CSS_mediaRule(ss, NULL, p + n);
        } else if (CSS_ATRULE(CSSSTR_page)) {
            CSS_pageRule(ss, NULL, p + n);
        } else if (CSS_ATRULE(CSSSTR_font_face)) {
            CSS_fontfaceRule(ss, NULL, p + n);
        } else {
            CSS_unknownRule(ss, NULL, p);
        }
    }
}

u16 *CSS_mediaRuleSingle(void *a0, void *a1, u16 *p) {
    u16 c;
    int n;
    p = CSS_SkipBlanksAndComments(p);
    c = *p;
    if (c == '.' || c == ':' || c == '*' || c == '[' || c == '#' || ((unsigned int)(c - 'A') < 26 || (unsigned int)(c - 'a') < 26) || (c == '_' || c == '-') || c == '@') {
        if (c != '@') {
            p = CSS_styleRule(a0, a1, p);
        } else {
            n = UCS_strlen(CSSSTR_page);
            if (UCS_strncasecmp(p, CSSSTR_page, n) == 0 && (p[n] == ' ' || p[n] == '\t' || (p[n] == '\r' || p[n] == '\n') || p[n] == 0xC || p[n] == 0xFEFF)) {
                p = CSS_pageRule(a0, a1, p + n);
            } else {
                p = CSS_unknownRule(a0, a1, p);
            }
        }
    }
    return p;
}

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

void *newCSSSelector(void) {
    void *temp_v0;

    temp_v0 = newCSSNode(9, 0x48);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x1C) = 0;
    }
    return temp_v0;
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

void *newCSSChain(void) {
    return (void *)MEM_calloc(0, 8);
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
