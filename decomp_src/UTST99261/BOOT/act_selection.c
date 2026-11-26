/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void *createBox(void *ctx, int type);
void linkBox(void *box, void *parent, void *prev);
void initNoneContent(void *box, void *ctx);
extern char D_0013F038[];
int checkAtributeByName(void *node, char *name);
extern unsigned char _DOMcellpadding;
extern unsigned char _DOMcellspacing;
extern unsigned char _DOMhspace;
extern unsigned char _DOMmarginheight;
extern unsigned char _DOMmarginwidth;
extern unsigned char _DOMspan;
extern unsigned char _DOMvspace;
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

int equalsChar(char a, char b, int cs) {
    if (cs) {
        return a == b;
    }
    if ((unsigned)(a - 'a') < 26) {
        a -= 0x20;
    }
    if ((unsigned)(b - 'a') < 26) {
        b -= 0x20;
    }
    return a == b;
}

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

void attr_HSPACE(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMhspace);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x26) = v;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x22) = v;
    }
}

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

void attr_MARGINHEIGHT(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMmarginheight);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x28) = v;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x2C) = v;
    }
}

void attr_MARGINWIDTH(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMmarginwidth);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x2E) = v;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x2A) = v;
    }
}

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

void attr_VSPACE(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMvspace);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x20) = v;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x24) = v;
    }
}

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

void attr_CELLPADDING(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMcellpadding);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), int *, 0x4) = v;
    }
}

void attr_CELLSPACING(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMcellspacing);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), int *, 0x8) = v;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_COLSPAN);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_FRAME);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_HEIGHT_table);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_HEIGHT_tr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_HEIGHT_td);

void attr_NOWRAP_td(void *node, void *box) {
    if (M2C_FIELD(box, s16 *, 0x38) == 6) {
        if (checkAtributeByName(node, D_0013F038) == 0) {
            M2C_FIELD(M2C_FIELD(box, void **, 0x20), u16 *, 0x18) |= 1;
        } else {
            M2C_FIELD(M2C_FIELD(box, void **, 0x20), u16 *, 0x18) &= ~1;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_ROWSPAN);

void attr_SPAN(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMspan);
    if (v > 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), int *, 0x4) = v;
    }
}

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

void *html_HEAD(void *node, void *parent, void *prev) {
    void *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    M2C_FIELD(box, s16 *, 0x3C) = 0;
    M2C_FIELD(box, s16 *, 0x3A) = 0x2C;
    initNoneContent(box, node);
    return box;
}

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
