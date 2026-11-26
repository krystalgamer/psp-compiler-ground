#include "common.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS2_freeCSSProperty);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS2_freeCSSImportRuleList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", newCSSStyleSheet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", freeCSSStyleSheet);

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSStyleSheet(void) {
    addCSSNode();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_getType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_getStyleType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_getDisable);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_setDisable);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_getOwnerNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_getParentStyleSheet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_getHref);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_getTitle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", StyleSheet_getMedia);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSStyleSheet_getOwnerRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSStyleSheet_getCssRules);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSStyleSheet_insertRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSStyleSheet_deleteRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSStyleSheet_isReadOnly);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSStyleSheet_setReadOnly);

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSStyleSheet_setOwnerRule(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 0)) {
        M2C_FIELD(arg0, int *, 0x38) = arg1;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", newCSSMediaRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", freeCSSMediaRule);

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSMediaRule(void) {
    addCSSRule();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_getType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_getCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_setCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_getParentStyleSheet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_getParentRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_getMedia);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_getMediaType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSSMediaRule_getCssRules);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_newPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_freePoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_putcPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_putsPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_putCPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_putSPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", CSS_getPoolBuf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", newCSSNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", freeCSSNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", addCSSNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", pushCSSNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", popCSSNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_API", insCSSNode);

#ifndef NULL
#define NULL ((void *)0)
#endif
void addBrotherCSSNode(void *arg0, void *arg1) {
    if (((arg0 == NULL) | (arg1 == NULL)) == 0) {
        M2C_FIELD(arg0, void **, 0x18) = arg1;
        M2C_FIELD(arg1, void **, 0x14) = arg0;
    }
}
