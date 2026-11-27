/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
u16 *CSS_SkipQuotedString(u16 *p, u16 q);
#define CSS_ISALNUM(c) ((unsigned int)((c) - '0') < 10 || (unsigned int)((c) - 'A') < 26 || (u16)((c) - 'a') < 26)
int CSS_putcPoolBuf(void *p, u16 c);
void ParseCSSDeclaration(void *ctx, void *str, void **out);
void *UCS_strdup(void *s);
void CSS_mediaList(void *str, u16 *media);
extern u16 D_001F70A8[];
extern char D_0025BA4C[];
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
int CSS_getMediaTypeString(short);                    /* extern */
M2C_UNK newCSSRule(M2C_UNK, M2C_UNK, int, int);     /* extern */
M2C_UNK freeCSSRule(void *);                        /* extern */
void *MEM_calloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK popCSSNode();                               /* extern */

M2C_UNK CSS_ParseStyleSheet(short);                   /* extern */
M2C_UNK freeCSSStyleDeclaration(void *);            /* extern */
M2C_UNK addCSSRule();                               /* extern */


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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_ISmatchSelector_BCE14);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS2_getImportRuleList);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSStyleSheet_insertRule);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_getCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_setCssText);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_insertRule);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_getMediaTypeString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_SkipBlanks);

u16 *CSS_SkipWord(u16 *p) {
    while (CSS_ISALNUM(*p) || *p == '-' || *p == '%') {
        p++;
    }
    return p;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_SkipXWord);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_SkipBlanksAndComments);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_Skip_S_CDO_CDC);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_ident);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_nstring);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CToc);

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

void freeCSSNode(int arg0) {
    if (arg0 != 0) {
        popCSSNode();
        MEM_free(0, arg0);
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", popCSSNode);

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
