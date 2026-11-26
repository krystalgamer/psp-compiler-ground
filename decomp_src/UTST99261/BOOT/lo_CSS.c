/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "lo_css.h"
#include "m2c_macros.h"
extern int *iomCookie;
void *UTL_peekqueue(void *q, int a1);
void iom_deleteCookie(void *c);
int iom_saveCookie(void);
void OS_thread_mutex_lock(int m);
void OS_thread_mutex_unlock(int m);



INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139910);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139914);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", innerCSSSetShortIntParam);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", innerCSSSetIntParam);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", innerCSSCallFunc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", innerCSSSetBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", innerCSSSetBorderStyle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", innerCSSSetBorderWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssDStrCmp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssDStrContains);

void cssBackgroundAttachment(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssBackgroundColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssBackgroundImage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssBackgroundRepeat);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssBackground);

void cssBorderBottomStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 5) {
        innerCSSSetBorderStyle(val->ident, &box->style->unk34, &box->style->unk4C,
                               parent != NULL ? parent->style->unk4C : 0);
    }
}

void cssBorderBottomWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk34;
    if (box->content != 5) {
        innerCSSSetBorderWidth(parent, val, &w, box->style->fontSize,
                               parent != NULL ? parent->style->unk34 : 0);
        if (w >= 0) {
            box->style->unk34 = w;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", innerCSSSetBorderColor);

void cssBorderTopColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetBorderColor(val, &box->style->unk30, &box->style->unk38,
                           parent != NULL ? parent->style->unk38 : box->style->unk54);
}

void cssBorderRightColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetBorderColor(val, &box->style->unk32, &box->style->unk3C,
                           parent != NULL ? parent->style->unk3C : box->style->unk54);
}

void cssBorderBottomColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetBorderColor(val, &box->style->unk34, &box->style->unk40,
                           parent != NULL ? parent->style->unk40 : box->style->unk54);
}

void cssBorderLeftColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetBorderColor(val, &box->style->unk36, &box->style->unk44,
                           parent != NULL ? parent->style->unk44 : box->style->unk54);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void setBoxArea0(void *ctx, BOX *box, CSSVALUE *val, int n) {
    cssBorderTopColor(ctx, box, val, n);
    cssBorderRightColor(ctx, box, val, n);
    cssBorderBottomColor(ctx, box, val, n);
    cssBorderLeftColor(ctx, box, val, n);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void setBoxArea1(void *ctx, BOX *box, CSSVALUE *val, int n) {
    CSSVALUE *v;
    cssBorderTopColor(ctx, box, val, n);
    cssBorderBottomColor(ctx, box, val, n);
    v = val->next;
    cssBorderRightColor(ctx, box, v, n);
    cssBorderLeftColor(ctx, box, v, n);
}

void setBoxArea2(void *ctx, BOX *box, CSSVALUE *val, int n) {
    cssBorderTopColor(ctx, box, val, n);
    val = val->next;
    cssBorderRightColor(ctx, box, val, n);
    cssBorderLeftColor(ctx, box, val, n);
    val = val->next;
    cssBorderBottomColor(ctx, box, val, n);
}

void setBoxArea3(void *ctx, BOX *box, CSSVALUE *val, int n) {
    cssBorderTopColor(ctx, box, val, n);
    val = val->next;
    cssBorderRightColor(ctx, box, val, n);
    val = val->next;
    cssBorderBottomColor(ctx, box, val, n);
    val = val->next;
    cssBorderLeftColor(ctx, box, val, n);
}

void cssBorderColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (n) {
    case 1:
        setBoxArea0(ctx, box, val, n);
        break;
    case 2:
        setBoxArea1(ctx, box, val, n);
        break;
    case 3:
        setBoxArea2(ctx, box, val, n);
        break;
    case 4:
        setBoxArea3(ctx, box, val, n);
        break;
    }
}

void cssBorderLeftStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 5) {
        innerCSSSetBorderStyle(val->ident, &box->style->unk36, &box->style->unk4E,
                               parent != NULL ? parent->style->unk4E : 0);
    }
}

void cssBorderLeftWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk36;
    if (box->content != 5) {
        innerCSSSetBorderWidth(parent, val, &w, box->style->fontSize,
                               parent != NULL ? parent->style->unk36 : 0);
        if (w >= 0) {
            box->style->unk36 = w;
        }
    }
}

void cssBorderRightStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 5) {
        innerCSSSetBorderStyle(val->ident, &box->style->unk32, &box->style->unk4A,
                               parent != NULL ? parent->style->unk4A : 0);
    }
}

void cssBorderRightWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk32;
    if (box->content != 5) {
        innerCSSSetBorderWidth(parent, val, &w, box->style->fontSize,
                               parent != NULL ? parent->style->unk32 : 0);
        if (w >= 0) {
            box->style->unk32 = w;
        }
    }
}

void cssBorderTopStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 5) {
        innerCSSSetBorderStyle(val->ident, &box->style->unk30, &box->style->unk48,
                               parent != NULL ? parent->style->unk48 : 0);
    }
}

void cssBorderStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    innerCSSCallFunc(ctx, box, val, n, 0);
}

void cssBorderTopWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk30;
    if (box->content != 5) {
        innerCSSSetBorderWidth(parent, val, &w, box->style->fontSize,
                               parent != NULL ? parent->style->unk30 : 0);
        if (w >= 0) {
            box->style->unk30 = w;
        }
    }
}

void cssBorderWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    innerCSSCallFunc(ctx, box, val, n, 1);
}

void cssBorderBottom(void *ctx, BOX *box, CSSVALUE *val, int n) {
    box->style->unk4C = 0;
    innerCSSSetBorder(ctx, box, val, n, 1);
}

void cssBorderRight(void *ctx, BOX *box, CSSVALUE *val, int n) {
    box->style->unk4A = 0;
    innerCSSSetBorder(ctx, box, val, n, 3);
}

void cssBorderLeft(void *ctx, BOX *box, CSSVALUE *val, int n) {
    box->style->unk4E = 0;
    innerCSSSetBorder(ctx, box, val, n, 2);
}

void cssBorderTop(void *ctx, BOX *box, CSSVALUE *val, int n) {
    box->style->unk48 = 0;
    innerCSSSetBorder(ctx, box, val, n, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cssBorder(void *ctx, BOX *box, CSSVALUE *val, int n) {
    cssBorderTop(ctx, box, val, n);
    cssBorderRight(ctx, box, val, n);
    cssBorderLeft(ctx, box, val, n);
    cssBorderBottom(ctx, box, val, n);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssFont);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", transFontSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssFontSize);

void cssFontStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (val->ident) {
    case 0x53:
    case 0x7D:
        box->style->unk6A |= 2;
        break;
    case 0x7A:
        box->style->unk6A &= ~2;
        break;
    }
    box->style->unk64 = ui_global->color[box->style->unk6A][box->style->fontSize];
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssFontWeight);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssHeight);

void cssLeft(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetShortIntParam(val, &box->style->unk52, parent, box->style->fontSize,
                             parent != NULL ? parent->style->unk52 : 0);
}

void cssMarginBottom(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 6) {
        innerCSSSetShortIntParam(val, &box->style->unk24, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk24 : 0);
    }
}

void cssMarginLeft(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 6) {
        innerCSSSetShortIntParam(val, &box->style->unk26, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk26 : 0);
    }
}

void cssMarginRight(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 6) {
        innerCSSSetShortIntParam(val, &box->style->unk22, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk22 : 0);
    }
}

void cssMarginTop(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 6) {
        innerCSSSetShortIntParam(val, &box->style->unk20, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk20 : 0);
    }
}

void cssMargin(void *ctx, BOX *box, CSSVALUE *val, int n) {
    innerCSSCallFunc(ctx, box, val, n, 2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cssMarkerOffset(void *ctx, BOX *box, CSSVALUE *val, int n) {
    cssMargin(ctx, box, val, n);
}

void cssPaddingBottom(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk2C;
    if (box->content != 4) {
        innerCSSSetShortIntParam(val, &w, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk2C : 0);
        if (w >= 0) {
            box->style->unk2C = w;
        }
    }
}

void cssPaddingLeft(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk2E;
    if (box->content != 4) {
        innerCSSSetShortIntParam(val, &w, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk2E : 0);
        if (w >= 0) {
            box->style->unk2E = w;
        }
    }
}

void cssPaddingRight(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk2A;
    if (box->content != 4) {
        innerCSSSetShortIntParam(val, &w, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk2A : 0);
        if (w >= 0) {
            box->style->unk2A = w;
        }
    }
}

void cssPaddingTop(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk28;
    if (box->content != 4) {
        innerCSSSetShortIntParam(val, &w, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk28 : 0);
        if (w >= 0) {
            box->style->unk28 = w;
        }
    }
}

void cssPadding(void *ctx, BOX *box, CSSVALUE *val, int n) {
    innerCSSCallFunc(ctx, box, val, n, 3);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssPosition);

void cssTextAlign(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (val->ident) {
    case 0x54:
        box->style->unk6F = 1;
        break;
    case 0x8D:
        box->style->unk6F = 3;
        break;
    case 0x1C:
        box->style->unk6F = 2;
        break;
    case 0x5A:
        box->style->unk6F = 1;
        break;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssTextDecoration);

void cssTop(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetShortIntParam(val, &box->style->unk50, parent, box->style->fontSize,
                             parent != NULL ? parent->style->unk50 : 0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssVerticalAlign);

void cssVisibility(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (val->ident) {
    case 0x46:
        box->style->unk73 = 1;
        break;
    case 0xC3:
        box->style->unk73 = 0;
        break;
    case 0x4D:
        box->style->unk73 = box->parent != NULL ? box->parent->style->unk73 : 0;
        break;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", matchesNode);

#ifndef NULL
#define NULL ((void *)0)
#endif
void applyCSSpostAction(void *arg0) {
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;

    temp_a1 = M2C_FIELD(arg0, void **, 0x24);
    if (M2C_FIELD(temp_a1, short *, 0x48) == 0) {
        M2C_FIELD(arg0, int *, 0x1C) = (int) (M2C_FIELD(arg0, int *, 0x1C) - M2C_FIELD(temp_a1, short *, 0x30));
        M2C_FIELD(temp_a1, short *, 0x30) = 0;
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), short *, 0x4A) == 0) {
        M2C_FIELD(arg0, int *, 0x18) = (int) (M2C_FIELD(arg0, int *, 0x18) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), short *, 0x32));
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), short *, 0x32) = 0;
    }
    temp_a1_2 = M2C_FIELD(arg0, void **, 0x24);
    if (M2C_FIELD(temp_a1_2, short *, 0x4C) == 0) {
        M2C_FIELD(arg0, int *, 0x1C) = (int) (M2C_FIELD(arg0, int *, 0x1C) - M2C_FIELD(temp_a1_2, short *, 0x34));
        M2C_FIELD(temp_a1_2, short *, 0x34) = 0;
    }
    temp_a1_3 = M2C_FIELD(arg0, void **, 0x24);
    if (M2C_FIELD(temp_a1_3, short *, 0x4E) == 0) {
        M2C_FIELD(arg0, int *, 0x18) = (int) (M2C_FIELD(arg0, int *, 0x18) - M2C_FIELD(temp_a1_3, short *, 0x36));
        M2C_FIELD(temp_a1_3, short *, 0x36) = 0;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", applyCSSExtStyleSheetToBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", applyCSSInlinePropertyToBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", iom_attachCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", iom_detachCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", iom_setCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", iom_getCookie);

void iom_destroyCookie(void) {
    void *e;
    OS_thread_mutex_lock(iomCookie[5]);
    while ((e = UTL_peekqueue(iomCookie + 1, 0)) != NULL) {
        iom_deleteCookie(M2C_FIELD(e, void **, 8));
    }
    if (iomCookie[0] != 0) {
        iom_saveCookie();
    }
    OS_thread_mutex_unlock(iomCookie[5]);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B34);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B68);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BA0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BB0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BCC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BEC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", set_cookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", get_cookie);
