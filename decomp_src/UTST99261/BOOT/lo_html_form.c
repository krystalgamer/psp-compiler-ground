/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
extern unsigned char _DOMtabindex;
char *getDOMAttributeValue(void *node, void *name);
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
void *getBodyBox(void *);                           /* extern */
int getRawTextFromDomTree(int);                     /* extern */
int getSessionSaveData(int);                        /* extern */

M2C_UNK html_OPTION_sub();                          /* extern */
M2C_UNK processArea();                              /* extern */


int getTabindex(void *node) {
    char *s;
    s16 n = 0;
    s = getDOMAttributeValue(node, &_DOMtabindex);
    if (s != NULL) {
        n = strtol(s, NULL, 10);
        if (n < 0) {
            n = 0;
        }
        MEM_free(0, s);
    }
    return n;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void html_TEXTAREA_after(int arg0, void *arg1) {
    int temp_a1;
    int temp_v0;

    if (getSessionSaveData(HST_getSessionID(M2C_FIELD(M2C_FIELD(getBodyBox(arg1), void **, 0x20), void **, 0x20))) == 0) {
        temp_a1 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), int *, 0x14);
        if (temp_a1 != 0) {
            MEM_free(0, temp_a1);
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), int *, 0x14) = 0;
        }
        temp_v0 = getRawTextFromDomTree(arg0);
        if (temp_v0 != 0) {
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), int *, 0x14) = temp_v0;
        }
    }
}

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
