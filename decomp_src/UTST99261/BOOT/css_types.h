#ifndef CSS_TYPES_H
#define CSS_TYPES_H
/* CSS parser values (css_*) */

typedef struct CSSVALUE {
    u8 unk0[0x18];
    struct CSSVALUE *next;      /* 0x18 */
    s16 type;                   /* 0x1C */
    s16 unk1E;
    s16 unit;                   /* 0x20 */
    s16 unk22;
    int unk24;
    int ident;                  /* 0x28: keyword (or string) */
} CSSVALUE;

#endif
