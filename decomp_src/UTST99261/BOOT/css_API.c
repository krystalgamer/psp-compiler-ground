/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
int CSS_getMediaTypeString(short);                    /* extern */
M2C_UNK newCSSRule(M2C_UNK, M2C_UNK, int, int);     /* extern */
M2C_UNK freeCSSRule(void *);                        /* extern */
void *MEM_calloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK popCSSNode();                               /* extern */

M2C_UNK CSS_ParseStyleSheet(short);                   /* extern */
M2C_UNK freeCSSStyleSheet();                        /* extern */
M2C_UNK freeCSSStyleDeclaration(void *);            /* extern */
M2C_UNK addCSSNode();                               /* extern */
M2C_UNK addCSSRule();                               /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_matchChainMenber);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_ISmatchSelector_BCE14);

#ifndef NULL
#define NULL ((void *)0)
#endif

void CSS2_Parse(short arg0) {
    CSS_ParseStyleSheet(arg0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS2_AttributeParse);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS2_getImportRuleList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS2_getProperty);

#ifndef NULL
#define NULL ((void *)0)
#endif

void CSS2_freeCSSStyleSheet(void) {
    freeCSSStyleSheet();
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", newCSSStyleSheet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", freeCSSStyleSheet);

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSStyleSheet(void) {
    addCSSNode();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_getType);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_setDisable);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_setMedia);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSStyleSheet_deleteRule);

#ifndef NULL
#define NULL ((void *)0)
#endif
short CSSStyleSheet_isReadOnly(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 0)) {
        return -1;
    }
    return M2C_FIELD(arg0, short *, 0x36);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSStyleSheet_setReadOnly);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_getType);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_deleteRule);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_SkipWord);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_SkipXWord);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_SkipBlanksAndComments);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_Skip_S_CDO_CDC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_SkipQuotedString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_SkipRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_SkipProperty);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_SkipToEqual);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_freePoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_putcPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_putsPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_putCPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_putSPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_getPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", newCSSNode);

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeCSSNode(int arg0) {
    if (arg0 != 0) {
        popCSSNode();
        MEM_free(0, arg0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", addCSSNode);

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
