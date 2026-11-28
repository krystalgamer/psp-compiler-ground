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
MesValue mes_class_property_get2(MesContext *ctx, int obj, MesValue name);
void mes_class_property_set2(MesContext *ctx, int obj, MesValue name, MesValue v);
void mes_array_set(MesContext *ctx, MesValue arr, MesValue v);
void mes_eval_object_delete(MesContext *ctx, int obj, unsigned int id);
unsigned int mes_context_id3(MesContext *ctx, const DOMChar *s, int len);
MesValue mes_eval_object_get(MesContext *ctx, MesValue obj, MesValue id);
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

int setNewPropertyReference(MesContext *ctx, int a, int c, MesValue s, int b, int y)
{
    MesString *str = (MesString *)(s & ~3);
    MesValue old;
    MesValue arr;
    int r = 0;

    if (str->len != 0) {
        old = mes_class_property_get2(ctx, a, s);
        if (old == 0x20) {
            if (y == 1)
                mes_class_property_set2(ctx, a, s, b);
            mes_class_property_set2(ctx, c, s, b);
            r = 1;
        } else {
            if (y == 1) {
                if (mes_class_instance_of((MesObject *)old, mes_classes[0]) == 0) {
                    arr = mes_array_new(ctx, 0);
                    mes_array_set(ctx, arr, old);
                    mes_array_set(ctx, arr, b);
                    mes_class_property_set2(ctx, a, s, arr);
                } else
                    mes_array_set(ctx, old, b);
                mes_eval_object_delete(ctx, c, mes_context_id3(ctx, str->str, str->len));
            }
            r = 1;
        }
    }
    return r;
}

int deleteOldPropertyReference(MesContext *ctx, int a, int c, MesValue s, MesValue old, int b)
{
    MesString *str = (MesString *)(s & ~3);
    MesString *ostr = (MesString *)(old & ~3);
    MesValue v;
    MesValue e0, e1, e;
    MesValue arr;
    int n, i;
    int r = 0;

    if (str->len != 0) {
        v = mes_class_property_get2(ctx, a, s);
        if (v != 0x20) {
            if (mes_class_instance_of((MesObject *)v, mes_classes[0]) == 0) {
                if (v == b)
                    mes_eval_object_delete(ctx, a, mes_context_id3(ctx, str->str, str->len));
            } else {
                n = M2C_FIELD(v, int *, 0x14);
                if (n == 2) {
                    e0 = mes_eval_object_get(ctx, v, MES_INT(0));
                    e1 = mes_eval_object_get(ctx, v, MES_INT(1));
                    if ((e0 == b) | (e1 == b)) {
                        mes_eval_object_delete(ctx, a, mes_context_id3(ctx, str->str, str->len));
                        mes_class_property_set2(ctx, a, (int)str | 3, e0 == b ? e1 : e0);
                    }
                } else if (n >= 3) {
                    arr = mes_array_new(ctx, 0);
                    for (i = 0; i < n; i++) {
                        e = mes_eval_object_get(ctx, v, MES_INT(i));
                        if (e != b)
                            mes_array_set(ctx, arr, e);
                    }
                    mes_eval_object_delete(ctx, a, mes_context_id3(ctx, str->str, str->len));
                    mes_class_property_set2(ctx, a, (int)str | 3, arr);
                } else
                    return 0;
            }
        }
        mes_eval_object_delete(ctx, c, mes_context_id3(ctx, ostr->str, ostr->len));
        r = 1;
    }
    return r;
}

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
