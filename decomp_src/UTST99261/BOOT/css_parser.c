#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_StyleSheetRuleList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_unknownRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_charsetRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_importRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_mediaRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_mediaRuleList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_pageRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_fontfaceRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_styleRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_selectorList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_selector);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_simpleSelector);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_pseudo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_attrib);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_styleDeclaration);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_ParseStyleSheet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_mediaList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_StyleSheetRuleSingle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSS_mediaRuleSingle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", newCSSRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", freeCSSRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", addCSSRule);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSSRuleList_item);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSSRule_getType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSSRule_getCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSSRule_setCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSSRule_getParentStyleSheet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", CSSRule_getParentRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", newCSSSelector);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", freeCSSSelector);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", addCSSSelector);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", newCSSChain);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", freeCSSChain);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_parser", addCSSChain);
