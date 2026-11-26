#ifndef LO_CSS_H
#define LO_CSS_H
/* CSS properties applied to layout boxes (lo_CSS) */

typedef struct CSSVALUE {
    u8 unk0[0x18];
    struct CSSVALUE *next;      /* 0x18 */
    u8 unk1C[0xC];
    int ident;                  /* 0x28: keyword */
} CSSVALUE;

void cssBorderTopColor(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderTopStyle(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderTopWidth(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderTop(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssMarginTop(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssPaddingTop(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderRightColor(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderRightStyle(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderRightWidth(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderRight(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssMarginRight(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssPaddingRight(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderBottomColor(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderBottomStyle(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderBottomWidth(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderBottom(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssMarginBottom(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssPaddingBottom(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderLeftColor(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderLeftStyle(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderLeftWidth(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderLeft(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssMarginLeft(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssPaddingLeft(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssTop(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssLeft(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderStyle(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderWidth(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssMargin(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssPadding(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssMarkerOffset(void *ctx, BOX *box, CSSVALUE *val, int n);
void setBoxArea0(void *ctx, BOX *box, CSSVALUE *val, int n);
void setBoxArea1(void *ctx, BOX *box, CSSVALUE *val, int n);
void setBoxArea2(void *ctx, BOX *box, CSSVALUE *val, int n);
void setBoxArea3(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorderColor(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBorder(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssTextAlign(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssVisibility(void *ctx, BOX *box, CSSVALUE *val, int n);
void innerCSSCallFunc(void *ctx, BOX *box, CSSVALUE *val, int n, int kind);
void innerCSSSetBorder(void *ctx, BOX *box, CSSVALUE *val, int n, int side);
void innerCSSSetShortIntParam(CSSVALUE *val, s16 *out, BOX *parent, int fontSize, int inherit);
void innerCSSSetBorderColor(CSSVALUE *val, s16 *width, int *color, int inherit);
void innerCSSSetBorderStyle(int ident, s16 *width, s16 *style, int inherit);
void innerCSSSetBorderWidth(BOX *parent, CSSVALUE *val, s16 *out, int fontSize, int inherit);

#endif
