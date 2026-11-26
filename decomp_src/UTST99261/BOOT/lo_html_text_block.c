/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void html_Heading_inner(void *a0, void *a1, void *a2, int tag);
M2C_UNK applyCSSExtStyleSheetToBox(int, void *);    /* extern */
M2C_UNK applyCSSInlinePropertyToBox(int, void *);   /* extern */
M2C_UNK attr_ALIGN_text_block(int, void *);         /* extern */
void *createBlockBox();                             /* extern */
M2C_UNK initBoxProperty(void *);                    /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_block", html_Heading_inner);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_block", html_ADDRESS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_block", html_BLOCKQUOTE);

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_DIV(int arg0) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = createBlockBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x1C;
        initBoxProperty(temp_v0);
        attr_ALIGN_text_block(arg0, temp_v0);
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

void html_H1(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x26);
}

void html_H2(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x27);
}

void html_H3(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x28);
}

void html_H4(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x29);
}

void html_H5(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x2A);
}

void html_H6(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x2B);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_block", html_P);

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_PRE(int arg0) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = createBlockBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x48;
        initBoxProperty(temp_v0);
        M2C_FIELD(M2C_FIELD(temp_v0, void **, 0x24), signed char *, 0x74) = 1;
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}
