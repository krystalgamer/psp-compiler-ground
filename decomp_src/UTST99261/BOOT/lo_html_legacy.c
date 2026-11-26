/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK applyCSSExtStyleSheetToBox(int, void *);    /* extern */
M2C_UNK applyCSSInlinePropertyToBox(int, void *);   /* extern */
void *createBlockBox();                             /* extern */
M2C_UNK initBoxProperty(void *);                    /* extern */
void *createInlineBox();                            /* extern */
M2C_UNK font_attr(int, void *);                     /* extern */



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_legacy", font_attr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_legacy", html_BASEFONT);

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_CENTER(int arg0) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = createBlockBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x13;
        initBoxProperty(temp_v0);
        M2C_FIELD(M2C_FIELD(temp_v0, void **, 0x24), signed char *, 0x6F) = 2;
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_FONT(int arg0) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = createInlineBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x22;
        font_attr(arg0, temp_v0);
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_ISINDEX(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_S(int arg0) {
    void *temp_v0;
    void *temp_v1;
    void *var_v0;

    temp_v0 = createInlineBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x50;
        temp_v1 = M2C_FIELD(temp_v0, void **, 0x24);
        M2C_FIELD(temp_v1, unsigned char *, 0x6C) = (unsigned char) (M2C_FIELD(temp_v1, unsigned char *, 0x6C) | 4);
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_STRIKE(int arg0) {
    void *temp_v0;
    void *temp_v1;
    void *var_v0;

    temp_v0 = createInlineBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x50;
        temp_v1 = M2C_FIELD(temp_v0, void **, 0x24);
        M2C_FIELD(temp_v1, unsigned char *, 0x6C) = (unsigned char) (M2C_FIELD(temp_v1, unsigned char *, 0x6C) | 4);
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_U(int arg0) {
    void *temp_v0;
    void *temp_v1;
    void *var_v0;

    temp_v0 = createInlineBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x5F;
        temp_v1 = M2C_FIELD(temp_v0, void **, 0x24);
        M2C_FIELD(temp_v1, unsigned char *, 0x6C) = (unsigned char) (M2C_FIELD(temp_v1, unsigned char *, 0x6C) | 2);
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_legacy", html_BLINK);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_legacy", html_MARQUEE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_legacy", html_NOBR);
