/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
void *getBodyBox(int);                              /* extern */
int lo_fullUrl(int, signed char *);                          /* extern */
M2C_UNK requestImageData(int, int, int);            /* extern */
extern unsigned char _DOMbackground;
extern void *ui_global;
int colorValue(signed char *);                               /* extern */
extern unsigned char _DOMbgcolor;
extern unsigned char _DOMlink;
extern unsigned char _DOMtext;
extern unsigned char _DOMvlink;
extern unsigned char _DOMbordercolor;
extern unsigned char _DOMfocuscolor;



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", addSelectionTarget);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", insertSelectionTarget);

#ifndef NULL
#define NULL ((void *)0)
#endif

void clearSelectionTarget(void *arg0) {
    void *temp_s0;
    void *var_a1;

    var_a1 = M2C_FIELD(arg0, void **, 0);
    if (var_a1 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_a1, void **, 0);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(var_a1, void **, 8), void **, 0x20), int *, 4) = 0;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(var_a1, void **, 8), void **, 0x20), int *, 8) = 0;
            MEM_free(0, var_a1);
            var_a1 = temp_s0;
        } while (temp_s0 != NULL);
    }
    M2C_FIELD(arg0, void **, 0) = NULL;
    M2C_FIELD(arg0, int *, 4) = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", forwardSearchTarget);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", backwardSearchTarget);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", forwardStrings);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", backwardStrings);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", equalsChar);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_ALIGN_text_block);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_ALIGN_hr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_ALIGN_image);

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_BACKGROUND(void *arg0, int arg1) {
    int temp_v0_2;
    signed char *temp_v0;
    void *temp_s2;

    temp_s2 = getBodyBox(arg1);
    if (M2C_FIELD(ui_global, int *, 0x98) == 0) {
        temp_v0 = getDOMAttributeValue(arg0, &_DOMbackground);
        if (temp_v0 != NULL) {
            temp_v0_2 = lo_fullUrl(arg1, temp_v0);
            if (temp_v0_2 != 0) {
                requestImageData(arg1, temp_v0_2, M2C_FIELD(M2C_FIELD(temp_s2, void **, 0x20), int *, 0x38));
                MEM_free(0, temp_v0_2);
            }
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_BGCOLOR(void *arg0, void *arg1) {
    int *temp_s0;
    signed char *temp_v0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMbgcolor);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(arg1, int **, 0x24);
        M2C_FIELD(temp_s0, int *, 0) = colorValue(temp_v0);
        M2C_FIELD(M2C_FIELD(arg1, int **, 0x24), signed char *, 0x10) = 1;
        MEM_free(0, temp_v0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_BORDER_image);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_WIDTH_image);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_HEIGHT_image);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_HSPACE);

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_LINK(void *arg0, void *arg1) {
    signed char *temp_v0;
    void *temp_s0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMlink);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(arg1, void **, 0x24);
        M2C_FIELD(temp_s0, int *, 0x58) = colorValue(temp_v0);
        MEM_free(0, temp_v0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_MARGINHEIGHT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_MARGINWIDTH);

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_TEXT(void *arg0, void *arg1) {
    signed char *temp_v0;
    void *temp_s0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMtext);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(arg1, void **, 0x24);
        M2C_FIELD(temp_s0, int *, 0x54) = colorValue(temp_v0);
        MEM_free(0, temp_v0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_VLINK(void *arg0, void *arg1) {
    signed char *temp_v0;
    void *temp_s0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMvlink);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(arg1, void **, 0x24);
        M2C_FIELD(temp_s0, int *, 0x5C) = colorValue(temp_v0);
        MEM_free(0, temp_v0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_VSPACE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_ALIGN_table);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_ALIGN_td);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_ALIGN_tr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_ALIGN_trgroup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_BORDER_table);

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_BORDERCOLOR(void *arg0, void *arg1) {
    int temp_v0_2;
    signed char *temp_v0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMbordercolor);
    if (temp_v0 != NULL) {
        temp_v0_2 = colorValue(temp_v0);
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x38) = temp_v0_2;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x3C) = temp_v0_2;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x40) = temp_v0_2;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x44) = temp_v0_2;
        MEM_free(0, temp_v0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_CELLPADDING);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_CELLSPACING);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_COLSPAN);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_FRAME);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_HEIGHT_table);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_HEIGHT_tr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_HEIGHT_td);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_NOWRAP_td);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_ROWSPAN);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_SPAN);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_VALIGN_td);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_VALIGN_tr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_VALIGN_trgroup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_WIDTH_col);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_WIDTH_table);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_WIDTH_td);

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_FOCUSCOLOR(void *arg0, void *arg1) {
    int temp_v0_2;
    signed char *temp_v0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMfocuscolor);
    if (temp_v0 != NULL) {
        temp_v0_2 = colorValue(temp_v0);
        if (temp_v0_2 != 0) {
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x60) = temp_v0_2;
        } else {
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x60) = 0;
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), signed char *, 0x6E) = 1;
        }
        MEM_free(0, temp_v0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", html_BODY);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", html_HEAD);

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_HTML(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_TITLE(void) {
    return 0;
}
