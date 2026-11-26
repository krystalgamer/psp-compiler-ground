#include "common.h"
#include "m2c_macros.h"
M2C_UNK html_OPTION_sub();                          /* extern */
M2C_UNK processArea();                              /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", getTabindex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", createFileRefButton);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_OPTION_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", getLegendTextWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_FORM);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_INPUT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_SELECT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_SELECT_after);

#ifndef NULL
#define NULL ((void *)0)
#endif

void html_OPTION(void) {
    html_OPTION_sub();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_OPTION_after);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_TEXTAREA);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_TEXTAREA_after);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_BUTTON);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_FIELDSET);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_LABEL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_LEGEND);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_LEGEND_after);

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_OPTGROUP(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_IMG_inner);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_IMG);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", processArea);

#ifndef NULL
#define NULL ((void *)0)
#endif

int html_AREA(void) {
    processArea();
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_MAP);
