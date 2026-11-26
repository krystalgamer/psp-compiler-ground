/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK applyCSSExtStyleSheetToBox(int, void *);    /* extern */
M2C_UNK applyCSSInlinePropertyToBox(int, void *);   /* extern */
void *createBlockBox();                             /* extern */
M2C_UNK initBoxProperty(void *);                    /* extern */
extern void *ui_global;
void *createInlineBox();                            /* extern */



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", getLINumber);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", createLIBox_li);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", createLIBox_head);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", getTypeAtAttr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_DL);

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_DT(int arg0) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = createBlockBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x1E;
        initBoxProperty(temp_v0);
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_DD(int arg0) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = createBlockBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x18;
        initBoxProperty(temp_v0);
        M2C_FIELD(M2C_FIELD(temp_v0, void **, 0x24), short *, 0x26) = (short) (M2C_FIELD(ui_global, int *, 0x74) * 4);
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_OL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_UL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_LI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_APPLET_inner);

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_APPLET(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_B);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_BIG);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_HR);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_I);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_SMALL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_SUB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_SUP);

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_TT(int arg0) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = createInlineBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x5E;
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_DEL(int arg0) {
    void *temp_v0;
    void *temp_v1;
    void *var_v0;

    temp_v0 = createInlineBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x19;
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

void *html_INS(int arg0) {
    void *temp_v0;
    void *temp_v1;
    void *var_v0;

    temp_v0 = createInlineBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0x33;
        temp_v1 = M2C_FIELD(temp_v0, void **, 0x24);
        M2C_FIELD(temp_v1, unsigned char *, 0x6C) = (unsigned char) (M2C_FIELD(temp_v1, unsigned char *, 0x6C) | 2);
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *html_BDO(int arg0) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = createInlineBox();
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, short *, 0x3A) = 0xA;
        applyCSSExtStyleSheetToBox(arg0, temp_v0);
        applyCSSInlinePropertyToBox(arg0, temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}
