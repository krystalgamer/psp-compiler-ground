/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern u16 CSSSTR_ASTERISK[];
void insCSSNode(void *pos, void *node);
void pushCSSNode(void *list, void *node);
void *CSS_mediaRuleSingle(void *ss, void *rule, u16 *text);
u16 *CSSRule_getCssText(void *rule);
void CSS_StyleSheetRuleSingle(void *ss, u16 *text);
typedef struct {
    void *url;
    u16 mediatypes;
    void *rule;
} CSSIMPORTITEM;
extern u16 CSSSTR_CDO[];
extern u16 CSSSTR_CDC[];
int UCS_strlen(u16 *s);
int UCS_strncasecmp(u16 *a, u16 *b, int n);
void *memcpy(void *d, const void *s, unsigned int n);
u16 *CSS_SkipBlanks(u16 *p);
void popCSSNode(void *node);
#define CN_PARENT(n) M2C_FIELD(n, void **, 4)
#define CN_PREV(n) M2C_FIELD(n, void **, 0x14)
#define CN_NEXT(n) M2C_FIELD(n, void **, 0x18)
#define CL_COUNT(l) M2C_FIELD(l, int *, 8)
#define CL_HEAD(l) M2C_FIELD(l, void **, 0xC)
#define CL_TAIL(l) M2C_FIELD(l, void **, 0x10)
u16 *CSS_SkipQuotedString(u16 *p, u16 q);
#define CSS_ISALNUM(c) ((unsigned int)((c) - '0') < 10 || (unsigned int)((c) - 'A') < 26 || (u16)((c) - 'a') < 26)
int CSS_putcPoolBuf(void *p, u16 c);
void ParseCSSDeclaration(void *ctx, void *str, void **out);
void *UCS_strdup(void *s);
void *CSS_mediaList(void *str, u16 *media);
extern u16 D_001F70A8[];
extern char D_0025BA4C[];
void MEM_free(M2C_UNK, void *);                  /* extern */
u16 *CSS_getMediaTypeString(short);                 /* extern */
M2C_UNK newCSSRule(M2C_UNK, M2C_UNK, int, int);     /* extern */
void freeCSSRule(void *);                        /* extern */
void *MEM_calloc(M2C_UNK, M2C_UNK);                 /* extern */

M2C_UNK CSS_ParseStyleSheet(short);                   /* extern */
void freeCSSStyleDeclaration(void *);            /* extern */
void addCSSRule();                               /* extern */


int UCS_strcasecmp(void *, void *);
void freeCSSStyleSheet(void *ss);
void *newCSSNode(int type, int size);
void freeCSSNode(void *n);
void addCSSNode(void *list, void *node);
void *CSS_newPoolBuf(void);
int CSS_putSPoolBuf(void *pb, u8 *s);
int CSSMediaRule_getMedia(void *arg0);
int CSS_putsPoolBuf(void *pb, u16 *s);
int CSS_getPoolBuf(unsigned short *);
void CSS_freePoolBuf(u16 *pb);
void *MEM_malloc(void *, unsigned int size);
void *UCS_strncpy(void *, void *, int n);
int CSS_matchChainMenber(u16 *name, void **e) {
    int found = 0;
    for (; e != NULL && e[1] != NULL; e = *e) {
        if (UCS_strcasecmp(name, e[1]) == 0) {
            found = 1;
            break;
        }
    }
    return found;
}

int CSS_ISmatchSelector_BCE14(void *sel, void **e, int unused) {
    int ret = 0;
    int m;
    if (M2C_FIELD(sel, void **, 0x20) == NULL) {
        m = 0;
        if (e[1] != NULL) {
            if (CSS_matchChainMenber(e[1], (void **)((char *)sel + 0x30))) {
                m = 1;
            }
        } else if (M2C_FIELD(sel, void **, 0x34) == NULL) {
            m = 1;
        }
        if (e[2] != NULL) {
            if (CSS_matchChainMenber(e[2], (void **)((char *)sel + 0x28))) {
                m |= 2;
            }
        } else if (M2C_FIELD(sel, void **, 0x2C) == NULL) {
            m |= 2;
        }
        if (e[3] != NULL) {
            if (CSS_matchChainMenber(e[3], (void **)((char *)sel + 0x38))) {
                m |= 4;
            }
        } else if (M2C_FIELD(sel, void **, 0x3C) == NULL) {
            m |= 4;
        }
        if (M2C_FIELD(sel, void **, 0x44) == NULL) {
            m |= 8;
        }
        if (m == 0xF) {
            ret = 1;
        }
    }
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CSS2_Parse(short arg0) {
    CSS_ParseStyleSheet(arg0);
}

void *CSS2_AttributeParse(void *ctx, void *str) {
    void *out;
    ParseCSSDeclaration(0, str, &out);
    return out;
}

int *CSS2_getImportRuleList(void *ss) {
    int i;
    int *list = NULL;
    void *r;
    int n;
    CSSIMPORTITEM *it;
    if (ss == NULL || M2C_FIELD(ss, s16 *, 0) != 0) {
        return list;
    }
    {
        n = 0;
        for (r = M2C_FIELD(ss, void **, 0xC); r != NULL; r = M2C_FIELD(r, void **, 0x18)) {
            if (M2C_FIELD(r, s16 *, 0) == 3) {
                n++;
            }
        }
        if (n == 0) {
            return list;
        }
        {
            list = MEM_calloc(0, n * sizeof(CSSIMPORTITEM) + 4);
            if (list == NULL) {
                return NULL;
            }
            {
                list[0] = n;
                it = (CSSIMPORTITEM *)(list + 1);
                for (r = M2C_FIELD(ss, void **, 0xC), i = 0; r != NULL && i < n; r = M2C_FIELD(r, void **, 0x18)) {
                    if (M2C_FIELD(r, s16 *, 0) == 3) {
                        it->url = M2C_FIELD(r, void **, 0x24);
                        it->mediatypes = M2C_FIELD(r, u16 *, 0x28);
                        it->rule = r;
                        it++;
                        i++;
                    }
                }
            }
        }
    }
    return list;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS2_getProperty);

#ifndef NULL
#define NULL ((void *)0)
#endif

void CSS2_freeCSSStyleSheet(void *ss) {
    freeCSSStyleSheet(ss);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CSS2_freeCSSAttribute(void *arg0) {
    void *temp_s0;
    void *var_a0;

    var_a0 = arg0;
    if (var_a0 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_a0, void **, 0x18);
            freeCSSStyleDeclaration(var_a0);
            var_a0 = temp_s0;
        } while (temp_s0 != NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CSS2_freeCSSProperty(void *arg0) {
    void *temp_s0;
    void *var_a1;

    var_a1 = arg0;
    if (arg0 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_a1, void **, 0x18);
            MEM_free(0, var_a1);
            var_a1 = temp_s0;
        } while (temp_s0 != NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CSS2_freeCSSImportRuleList(int arg0) {
    if (arg0 != 0) {
        MEM_free(0, arg0);
    }
}

void *newCSSStyleSheet(int type) {
    void *n = newCSSNode(0, 0x3C);
    if (n != NULL) {
        M2C_FIELD(n, s16 *, 0x1C) = type;
    }
    return n;
}

void freeCSSStyleSheet(void *ss) {
    void *r;
    void *next;
    if (ss != NULL && M2C_FIELD(ss, s16 *, 0) == 0) {
        for (r = M2C_FIELD(ss, void **, 0xC); r != NULL; r = next) {
            next = M2C_FIELD(r, void **, 0x18);
            freeCSSRule(r);
        }
        freeCSSNode(ss);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSStyleSheet(void *list, void *ss) {
    addCSSNode(list, ss);
}

void *StyleSheet_getType(void *ss) {
    if (ss == NULL || M2C_FIELD(ss, s16 *, 0) != 0) {
        return NULL;
    }
    return UCS_strdup(D_001F70A8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
short StyleSheet_getStyleType(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return -1;
    }
    return M2C_FIELD(arg0, short *, 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
short StyleSheet_getDisable(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return -1;
    }
    return M2C_FIELD(arg0, short *, 0x34);
}

void StyleSheet_setDisable(void *ss, int v) {
    if (ss != NULL && M2C_FIELD(ss, s16 *, 0) == 0) {
        M2C_FIELD(ss, s16 *, 0x34) = v;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int StyleSheet_getOwnerNode(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x24);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int StyleSheet_getParentStyleSheet(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int StyleSheet_getHref(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x2C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int StyleSheet_getTitle(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x30);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int StyleSheet_getMedia(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return 0;
    }
    return CSS_getMediaTypeString(M2C_FIELD(arg0, short *, 0x28));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void StyleSheet_setOwnerNode(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 0)) {
        M2C_FIELD(arg0, int *, 0x24) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void StyleSheet_setParentStyleSheet(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 0)) {
        M2C_FIELD(arg0, int *, 0x20) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void StyleSheet_setHref(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 0)) {
        M2C_FIELD(arg0, int *, 0x2C) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void StyleSheet_setTitle(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 0)) {
        M2C_FIELD(arg0, int *, 0x30) = arg1;
    }
}

void StyleSheet_setMedia(void *ss, void *str) {
    u16 media;
    if (ss != NULL && M2C_FIELD(ss, s16 *, 0) == 0) {
        CSS_mediaList(str, &media);
        M2C_FIELD(ss, u16 *, 0x28) = media;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSStyleSheet_getOwnerRule(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x38);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSStyleSheet_getCssRules(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0xC);
}

int CSSStyleSheet_insertRule(void *ss, u16 *text, int idx) {
    int ret = -1;
    void *tmp;
    void *r;
    void *n;
    int i;
    if (ss != NULL && M2C_FIELD(ss, s16 *, 0) == 0 && M2C_FIELD(ss, s16 *, 0x36) == 0) {
        tmp = newCSSNode(0, 0x3C);
        if (tmp != NULL) {
            CSS_StyleSheetRuleSingle(tmp, text);
            r = M2C_FIELD(tmp, void **, 0xC);
            if (r != NULL) {
                if (M2C_FIELD(r, s16 *, 0) == 2) {
                    if (idx == 0 || M2C_FIELD(M2C_FIELD(ss, void **, 0xC), s16 *, 0) != 2) {
                        ret = 0;
                    }
                } else if (M2C_FIELD(r, s16 *, 0) == 3) {
                    if (M2C_FIELD(ss, int *, 8) >= idx) {
                        if (idx == 0) {
                            ret = 0;
                        }
                    }
                }
                if (ret == 0) {
                    popCSSNode(r);
                    for (n = M2C_FIELD(ss, void **, 0xC), i = 0; n != NULL && i < idx; i++) {
                        n = M2C_FIELD(n, void **, 0x18);
                    }
                    if (n != NULL) {
                        insCSSNode(n, r);
                    } else {
                        pushCSSNode(ss, r);
                    }
                    ret = i;
                }
            }
            freeCSSStyleSheet(tmp);
        }
    }
    return ret;
}

void CSSStyleSheet_deleteRule(void *ss, int idx) {
    void *r;
    int i;
    if (ss != NULL && M2C_FIELD(ss, s16 *, 0) == 0 && M2C_FIELD(ss, s16 *, 0x36) == 0) {
        for (r = M2C_FIELD(ss, void **, 0xC), i = 0; r != NULL && i < idx; i++) {
            r = M2C_FIELD(r, void **, 0x18);
        }
        if (i == idx) {
            freeCSSRule(r);
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
short CSSStyleSheet_isReadOnly(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return -1;
    }
    return M2C_FIELD(arg0, short *, 0x36);
}

void CSSStyleSheet_setReadOnly(void *ss, int v) {
    if (ss != NULL && M2C_FIELD(ss, s16 *, 0) == 0) {
        M2C_FIELD(ss, s16 *, 0x36) = v;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSStyleSheet_setOwnerRule(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 0)) {
        M2C_FIELD(arg0, int *, 0x38) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void newCSSMediaRule(int arg0, int arg1) {
    newCSSRule(4, 0x28, arg0, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeCSSMediaRule(void *arg0) {
    void *temp_s0;
    void *var_a0;

    if (arg0 != NULL) {
        if (M2C_FIELD(arg0, short *, 0) == 4) {
            var_a0 = M2C_FIELD(arg0, void **, 0xC);
            if (var_a0 != NULL) {
                do {
                    temp_s0 = M2C_FIELD(var_a0, void **, 0x18);
                    freeCSSRule(var_a0);
                    var_a0 = temp_s0;
                } while (temp_s0 != NULL);
            }
            freeCSSNode(arg0);
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSMediaRule(void) {
    addCSSRule();
}

int CSSMediaRule_getType(void *r) {
    if (r != NULL) {
        if (M2C_FIELD(r, s16 *, 0) == 4) {
            return M2C_FIELD(r, s16 *, 0);
        }
    }
    return -1;
}

u16 *CSSMediaRule_getCssText(void *rule) {
    void *pb;
    u16 *s;
    void *r;
    int i;
    if (rule == NULL || M2C_FIELD(rule, s16 *, 0) != 4) {
        return NULL;
    }
    pb = CSS_newPoolBuf();
    if (pb == NULL) {
        return NULL;
    }
    CSS_putSPoolBuf(pb, "@media ");
    s = (u16 *)CSSMediaRule_getMedia(rule);
    if (s != NULL) {
        CSS_putsPoolBuf(pb, s);
        MEM_free(0, s);
    }
    CSS_putSPoolBuf(pb, " {");
    CSS_putSPoolBuf(pb, "\n");
    for (r = M2C_FIELD(rule, void **, 0xC), i = 0; r != NULL && i < M2C_FIELD(rule, int *, 8); r = M2C_FIELD(r, void **, 0x18), i++) {
        s = CSSRule_getCssText(r);
        if (s != NULL) {
            CSS_putsPoolBuf(pb, s);
            MEM_free(0, s);
        }
    }
    CSS_putSPoolBuf(pb, "}");
    CSS_putSPoolBuf(pb, "\n");
    s = CSS_getPoolBuf(pb);
    CSS_freePoolBuf(pb);
    return s;
}

int CSSMediaRule_setCssText(void *rule, u16 *text) {
    int ret = -1;
    void *ss;
    void *r;
    if (rule != NULL && M2C_FIELD(rule, void **, 0x1C) != NULL && M2C_FIELD(M2C_FIELD(rule, void **, 0x1C), s16 *, 0x36) == 0) {
        ss = newCSSNode(0, 0x3C);
        if (ss != NULL) {
            CSS_StyleSheetRuleSingle(ss, text);
            r = M2C_FIELD(ss, void **, 0xC);
            if (r != NULL && M2C_FIELD(r, s16 *, 0) == 4) {
                popCSSNode(r);
                addCSSNode(M2C_FIELD(rule, void **, 0x1C), r);
                ret = 0;
            }
            freeCSSStyleSheet(ss);
        }
    }
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSMediaRule_getParentStyleSheet(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 4)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSMediaRule_getParentRule(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 4)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSMediaRule_getMedia(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 4)) {
        return 0;
    }
    return CSS_getMediaTypeString(M2C_FIELD(arg0, short *, 0x24));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
short CSSMediaRule_getMediaType(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 4)) {
        return -1;
    }
    return M2C_FIELD(arg0, short *, 0x24);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSMediaRule_getCssRules(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 4)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0xC);
}

int CSSMediaRule_insertRule(void *rule, u16 *text, int idx) {
    void *ss;
    void *r;
    void *cur;
    void *n;
    int i;
    int cnt;
    if (rule == NULL || M2C_FIELD(rule, void **, 0x1C) == NULL || M2C_FIELD(M2C_FIELD(rule, void **, 0x1C), s16 *, 0x36) != 0) {
        return -1;
    }
    ss = newCSSNode(0, 0x3C);
    if (ss != NULL) {
        CSS_mediaRuleSingle(ss, rule, text);
        r = M2C_FIELD(ss, void **, 0xC);
        if (r != NULL) {
            popCSSNode(r);
            cnt = M2C_FIELD(rule, int *, 8);
            cur = M2C_FIELD(rule, void **, 0xC);
            n = cur;
            i = 0;
            while (n != NULL && i < cnt && i < idx) {
                cur = n;
                n = M2C_FIELD(n, void **, 0x18);
                i++;
            }
            idx = i;
            if (cur != NULL) {
                insCSSNode(cur, r);
            } else {
                pushCSSNode(rule, r);
            }
        } else {
            idx = -1;
        }
        freeCSSStyleSheet(ss);
    } else {
        idx = -1;
    }
    return idx;
}

int CSSMediaRule_deleteRule(void *rule, int idx) {
    void *r;
    int i;
    int n;
    if (rule == NULL || M2C_FIELD(rule, void **, 0x1C) == NULL || M2C_FIELD(M2C_FIELD(rule, void **, 0x1C), s16 *, 0x36) != 0) {
        return -1;
    }
    n = M2C_FIELD(rule, int *, 8);
    if (n < idx) {
        return -1;
    }
    for (r = M2C_FIELD(rule, void **, 0xC), i = 0; r != NULL && i < n && i < idx; i++) {
        r = M2C_FIELD(r, void **, 0x18);
    }
    if (i != idx) {
        return -1;
    }
    freeCSSRule(r);
    return i;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSMediaRule_setParentStyleSheet(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 4)) {
        M2C_FIELD(arg0, int *, 0x1C) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSMediaRule_setParentRule(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 4)) {
        M2C_FIELD(arg0, int *, 0x20) = arg1;
    }
}

u16 *CSS_getMediaTypeString(s16 type) {
    void *pb;
    u16 *ret;
    int sep = 0;
    pb = CSS_newPoolBuf();
    if (pb == NULL) {
        return NULL;
    }
    ret = NULL;
    if (type != 0) {
        if (type == 0x1FF) {
            CSS_putSPoolBuf(pb, " all");
        } else {
            if (type & 1) {
                CSS_putSPoolBuf(pb, " screen");
                sep = 1;
            }
            if (type & 0x2) {
                if (sep) {
                    CSS_putSPoolBuf(pb, ", tty");
                } else {
                    CSS_putSPoolBuf(pb, " tty");
                    sep = 1;
                }
            }
            if (type & 0x4) {
                if (sep) {
                    CSS_putSPoolBuf(pb, ", tv");
                } else {
                    CSS_putSPoolBuf(pb, " tv");
                    sep = 1;
                }
            }
            if (type & 0x8) {
                if (sep) {
                    CSS_putSPoolBuf(pb, ", projection");
                } else {
                    CSS_putSPoolBuf(pb, " projection");
                    sep = 1;
                }
            }
            if (type & 0x10) {
                if (sep) {
                    CSS_putSPoolBuf(pb, ", handheld");
                } else {
                    CSS_putSPoolBuf(pb, " handheld");
                    sep = 1;
                }
            }
            if (type & 0x20) {
                if (sep) {
                    CSS_putSPoolBuf(pb, ", print");
                } else {
                    CSS_putSPoolBuf(pb, " print");
                    sep = 1;
                }
            }
            if (type & 0x40) {
                if (sep) {
                    CSS_putSPoolBuf(pb, ", braille");
                } else {
                    CSS_putSPoolBuf(pb, " braille");
                    sep = 1;
                }
            }
            if (type & 0x80) {
                if (sep) {
                    CSS_putSPoolBuf(pb, ", embossed");
                } else {
                    CSS_putSPoolBuf(pb, " embossed");
                    sep = 1;
                }
            }
            if (type & 0x100) {
                if (sep) {
                    CSS_putSPoolBuf(pb, ", aural");
                } else {
                    CSS_putSPoolBuf(pb, " aural");
                }
            }
        }
        ret = CSS_getPoolBuf(pb);
    }
    CSS_freePoolBuf(pb);
    return ret;
}

u16 *CSS_SkipBlanks(u16 *p) {
    while (*p != 0 && (*p == ' ' || *p == '\t' || (*p == '\r' || *p == '\n') || *p == 0xC || *p == 0xFEFF)) {
        p++;
    }
    return p;
}

u16 *CSS_SkipWord(u16 *p) {
    while (CSS_ISALNUM(*p) || *p == '-' || *p == '%') {
        p++;
    }
    return p;
}

u16 *CSS_SkipXWord(u16 *p) {
    while (*p != ' ' && *p != '\t' && (*p != '\r' && *p != '\n') && *p != 0xC && *p != 0xFEFF && *p != 0 && *p != ';' && *p != '}') {
        p++;
    }
    return p;
}

u16 *CSS_SkipBlanksAndComments(u16 *p) {
    p = CSS_SkipBlanks(p);
    while (p[0] == '/' && p[1] == '*') {
        p += 2;
        while (*p != 0 && !(p[0] == '*' && p[1] == '/')) {
            p++;
        }
        if (*p != 0) {
            p += 2;
        }
        p = CSS_SkipBlanks(p);
    }
    return p;
}

u16 *CSS_Skip_S_CDO_CDC(u16 *p) {
    int cdo = UCS_strlen(CSSSTR_CDO);
    int cdc = UCS_strlen(CSSSTR_CDC);
    while (*p != 0) {
        p = CSS_SkipBlanksAndComments(p);
        if (UCS_strncasecmp(p, CSSSTR_CDO, cdo) == 0) {
            p += cdo;
            continue;
        }
        if (UCS_strncasecmp(p, CSSSTR_CDC, cdc) == 0) {
            p += cdc;
            continue;
        }
        break;
    }
    return p;
}

u16 *CSS_SkipQuotedString(u16 *p, u16 q) {
    int done = 0;
    u16 c;
    while (!done) {
        c = *p;
        if (c == q) {
            p++;
            done = 1;
        } else if (c == 0) {
            done = 1;
        } else {
            c = *p++;
            if (c == '\\') {
                if (CSS_ISALNUM(*p)) {
                    p++;
                    if (CSS_ISALNUM(*p)) {
                        p++;
                    }
                } else {
                    p++;
                }
            }
        }
    }
    return p;
}

u16 *CSS_SkipRule(u16 *p) {
    int depth = 0;
    u16 c;
    while ((c = *p) != 0) {
        p++;
        if (c == '{') {
            depth++;
        } else if (c == '}') {
            if (depth == 0) {
                break;
            }
            depth--;
            if (depth == 0) {
                return p;
            }
        } else if (c == '\'' || c == '"') {
            p = CSS_SkipQuotedString(p, c);
        }
    }
    return p;
}

u16 *CSS_SkipProperty(u16 *p) {
    u16 c;
    while ((c = *p) != 0) {
        if (c == ';' || c == '}') {
            break;
        }
        p++;
        if (c == '\'' || c == '"') {
            p = CSS_SkipQuotedString(p, c);
        }
    }
    return p;
}

u16 *CSS_SkipToEqual(u16 *p) {
    u16 c;
    while (c = *p, c != 0 && c != '=' && c != '\r' && c != '\n') {
        p++;
    }
    return p;
}

u16 *CSS_ident(u16 *s, u16 **out) {
    u16 *p;
    u16 *buf;
    int n;
    u16 c;
    *out = NULL;
    p = s;
    n = 0;
    if ((u16)(*p - 'A') < 26 || (u16)(*p - 'a') < 26 || *p == '_' || *p == '-') {
        p++;
        n++;
        while ((c = *p) != 0) {
            if ((u16)(c - 'A') < 26 || (u16)(c - 'a') < 26 || c == '_' || c == '-' || (u16)(c - '0') < 10 || c == '-') {
                p++;
                n++;
            } else {
                break;
            }
        }
        if (n != 0) {
            buf = MEM_malloc(0, (n + 1) * 2);
            if (buf != NULL) {
                UCS_strncpy(buf, s, n);
                buf[n] = 0;
                *out = buf;
            }
        }
    }
    return p;
}

u16 *CSS_string(u16 *s, u16 **out) {
    u16 *p;
    u16 *start;
    u16 *d;
    int len;
    u16 c;
    *out = NULL;
    p = s;
    c = *s;
    if (c == '\'' || c == '"') {
        p = s + 1;
        start = p;
        p = CSS_SkipQuotedString(p, c);
        if (start < p) {
            p--;
            c = *p;
            *p = 0;
            len = UCS_strlen(start);
            *p = c;
            p++;
            if (len != 0) {
                d = MEM_malloc(0, (len + 1) * 2);
                if (d != NULL) {
                    *out = d;
                    while (c = *start, *start++ != 0 && len != 0) {
                        len--;
                        if (c == '\\') {
                            if (len != 0) {
                                if (*start == '\r' || *start == '\n') {
                                    len--;
                                    start++;
                                    if (len != 0) {
                                        if (*start == '\r' || *start == '\n') {
                                            len--;
                                            start++;
                                        }
                                    }
                                    continue;
                                }
                            }
                        }
                        *d++ = c;
                    }
                    *d = 0;
                }
            }
        }
    }
    return p;
}

u16 *CSS_nstring(u16 *s, u16 **out) {
    u16 *p;
    u16 *buf;
    int n;
    u16 c;
    *out = NULL;
    p = s;
    n = 0;
    while ((c = *p) != 0 && !(c == ')' || c == ';' || c == '}' || (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == 0xC || c == 0xFEFF))) {
        p++;
        n++;
    }
    if (n == 0) {
        return p;
    }
    buf = MEM_malloc(0, (n + 1) * 2);
    if (buf != NULL) {
        UCS_strncpy(buf, s, n);
        buf[n] = 0;
        *out = buf;
    }
    return p;
}

char *CToc(u16 *s) {
    int i = 0;
    while (*s != 0 && i < 0x1FF) {
        D_0025BA4C[i] = *s;
        s++;
        i++;
    }
    D_0025BA4C[i] = 0;
    return D_0025BA4C;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *CSS_newPoolBuf(void) {
    void *temp_v0;
    void *temp_v0_2;
    void *var_v0;

    temp_v0 = MEM_calloc(0, 0xC);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        temp_v0_2 = MEM_calloc(0, 0x208);
        if (temp_v0_2 == NULL) {
            MEM_free(0, temp_v0);
            return NULL;
        }
        M2C_FIELD(temp_v0, short *, 0) = 1;
        M2C_FIELD(temp_v0, void **, 4) = temp_v0_2;
        M2C_FIELD(temp_v0, void **, 8) = temp_v0_2;
        var_v0 = temp_v0;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

void CSS_freePoolBuf(u16 *pb) {
    void **b;
    void **next;
    if (pb == NULL) {
        return;
    }
    b = M2C_FIELD(pb, void ***, 4);
    if (b != NULL && *pb != 0) {
        do {
            next = *b;
            MEM_free(0, b);
            (*pb)--;
            b = next;
        } while (b != NULL && *pb != 0);
    }
    MEM_free(0, pb);
}

int CSS_putcPoolBuf(void *pb, u16 c) {
    void *b;
    void *n;
    if (pb == NULL) {
        return -1;
    }
    b = M2C_FIELD(pb, void **, 8);
    if (b == NULL) {
        return -1;
    }
    if (M2C_FIELD(b, u16 *, 4) >= 0x100) {
        n = MEM_calloc(0, 0x208);
        if (n == NULL) {
            return -1;
        }
        M2C_FIELD(b, void **, 0) = n;
        M2C_FIELD(pb, void **, 8) = n;
        M2C_FIELD(pb, u16 *, 0)++;
        b = n;
    }
    ((u16 *)((char *)b + 6))[M2C_FIELD(b, u16 *, 4)++] = c;
    return 0;
}

int CSS_putsPoolBuf(void *pb, u16 *s) {
    int r = 0;
    if (pb == NULL || s == NULL) {
        return -1;
    }
    for (; *s != 0; s++) {
        r = CSS_putcPoolBuf(pb, *s);
        if (r < 0) {
            break;
        }
    }
    return r;
}

void CSS_putCPoolBuf(void *p, int c) {
    CSS_putcPoolBuf(p, (u8)c);
}

int CSS_putSPoolBuf(void *pb, u8 *s) {
    int r = 0;
    if (pb == NULL || s == NULL) {
        return -1;
    }
    for (; *s != 0; s++) {
        r = CSS_putcPoolBuf(pb, *s);
        if (r < 0) {
            break;
        }
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_getPoolBuf);

void *newCSSNode(int type, int size) {
    void *n = MEM_calloc(0, size);
    if (n != NULL) {
        M2C_FIELD(n, s16 *, 0) = type;
    }
    return n;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeCSSNode(void *n) {
    if (n != NULL) {
        popCSSNode(n);
        MEM_free(0, n);
    }
}

void addCSSNode(void *list, void *node) {
    void *last;
    if (list != NULL) {
        last = M2C_FIELD(list, void **, 0x10);
        if (last != NULL) {
            M2C_FIELD(last, void **, 0x18) = node;
            M2C_FIELD(node, void **, 0x14) = last;
            M2C_FIELD(list, void **, 0x10) = node;
        } else {
            M2C_FIELD(list, void **, 0xC) = node;
            M2C_FIELD(list, void **, 0x10) = node;
            M2C_FIELD(list, int *, 8) = 0;
        }
        M2C_FIELD(node, void **, 4) = list;
        M2C_FIELD(list, int *, 8)++;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void pushCSSNode(void *arg0, void *arg1) {
    void *temp_v0;

    if (arg0 != NULL) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, void **, 0x14) = arg1;
            M2C_FIELD(arg1, void **, 0x18) = temp_v0;
            M2C_FIELD(arg0, void **, 0xC) = arg1;
        } else {
            M2C_FIELD(arg0, void **, 0xC) = arg1;
            M2C_FIELD(arg0, void **, 0x10) = arg1;
            M2C_FIELD(arg0, int *, 8) = 0;
        }
        M2C_FIELD(arg1, void **, 4) = arg0;
        M2C_FIELD(arg0, int *, 8) = (int) (M2C_FIELD(arg0, int *, 8) + 1);
    }
}

void popCSSNode(void *node) {
    void *list;
    void *prev;
    void *next;
    void *p;
    if (node == NULL) {
        return;
    }
    prev = CN_PREV(node);
    next = CN_NEXT(node);
    if (prev != NULL) {
        if (next != NULL) {
            CN_NEXT(prev) = next;
            CN_PREV(CN_NEXT(node)) = prev;
            list = CN_PARENT(node);
            if (list != NULL) {
                CL_COUNT(list)--;
            }
            CN_NEXT(node) = NULL;
        } else {
            p = CN_PREV(node);
            CN_NEXT(p) = NULL;
            list = CN_PARENT(node);
            if (list != NULL) {
                CL_TAIL(list) = p;
                CL_COUNT(list)--;
            }
        }
        CN_PREV(node) = NULL;
    } else if (next != NULL) {
        CN_PREV(next) = NULL;
        list = CN_PARENT(node);
        if (list != NULL) {
            CL_HEAD(list) = next;
            CL_COUNT(list)--;
        }
        CN_NEXT(node) = NULL;
    } else {
        list = CN_PARENT(node);
        if (list != NULL && CL_HEAD(list) == node) {
            CL_HEAD(list) = NULL;
            CL_TAIL(list) = NULL;
            CL_COUNT(list) = 0;
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void insCSSNode(void *arg0, void *arg1) {
    void *temp_a0;
    void *temp_v0;
    void *temp_v0_2;

    if (((arg0 == NULL) | (arg1 == NULL)) == 0) {
        M2C_FIELD(arg1, void **, 4) = (void *) M2C_FIELD(arg0, void **, 4);
        temp_v0 = M2C_FIELD(arg0, void **, 0x14);
        M2C_FIELD(arg0, void **, 0x14) = arg1;
        if (temp_v0 != NULL) {
            M2C_FIELD(arg1, void **, 0x18) = arg0;
            M2C_FIELD(arg1, void **, 0x14) = temp_v0;
            M2C_FIELD(temp_v0, void **, 0x18) = arg1;
        } else {
            M2C_FIELD(arg1, void **, 0x18) = arg0;
            temp_v0_2 = M2C_FIELD(arg0, void **, 4);
            if (temp_v0_2 != NULL) {
                M2C_FIELD(temp_v0_2, void **, 0xC) = arg1;
            }
        }
        temp_a0 = M2C_FIELD(arg0, void **, 4);
        if (temp_a0 != NULL) {
            M2C_FIELD(temp_a0, int *, 8) = (int) (M2C_FIELD(temp_a0, int *, 8) + 1);
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void addBrotherCSSNode(void *arg0, void *arg1) {
    if (((arg0 == NULL) | (arg1 == NULL)) == 0) {
        M2C_FIELD(arg0, void **, 0x18) = arg1;
        M2C_FIELD(arg1, void **, 0x14) = arg0;
    }
}
