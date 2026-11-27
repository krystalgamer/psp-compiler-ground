/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct PropName {
    const char *name;                 /* 0x0 pn */
    int f4;                           /* 0x4 pn */
} PropName;
int mes_util_streq2(const DOMChar *a, const char *b, int n);
unsigned int strlen(const char *s);
int setNewPropertyReference(MesContext *ctx, int a, int c, MesValue s, int b, int y);
typedef struct MesString {
    DOMChar *str;
    unsigned int len;
} MesString;




#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_obj_common_constructor_not_allowed(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

MesValue mes_obj_common_to_string(MesContext *ctx, MesValue v)
{
    MesValue r = mes_eval_to_string(ctx, v);

    *--ctx->sp = r;
    return r & ~3;
}

void mes_val2domstr(MesContext *ctx, MesValue v, DOMString *out)
{
    MesString *s = (MesString *)(mes_eval_to_string(ctx, v) & ~3);

    out->size = out->len = s->len;
    out->str = s->str;
}

int isAllowedAsPropertyName(MesString *s, PropName *t, int x)
{
    const char *nm;

    if (s->len == 0)
        return 0;
    for (; (nm = t->name) != NULL; t++) {
        if (mes_util_streq2(s->str, nm, s->len) == 1 && strlen(nm) == s->len)
            return 0;
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", setNewPropertyReference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", deleteOldPropertyReference);

int mes_obj_common_addNewReferenceByNameOrId(MesContext *ctx, int a, int b, int c, DOMString *pds, PropName *tbl, int x, int y)
{
    DOMString d = *pds;
    int r = 0;
    MesValue s;

    if (d.len != 0) {
        s = mes_string_new(ctx, d.str, d.len);
        *--ctx->sp = s;
        if (isAllowedAsPropertyName((MesString *)(s & ~3), tbl, x) == 1)
            r = setNewPropertyReference(ctx, a, c, s, b, y);
        ctx->sp++;
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", makeHref);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", D_0013F4C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", D_0013F4CC);
