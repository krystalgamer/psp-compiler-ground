/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
typedef struct MesErrNative {
    int idx;
    void *fn;
} MesErrNative;
extern MesValue mes_empty;
extern void *mes_error_table;
extern MesErrNative mes_error_native_table[];
MesObject *mes_error_constructor(MesContext *ctx, MesValue msg);
MesObject *mes_native_new(MesContext *ctx, int a, void *fn, int nargs, int flags);
void mes_native_setup(MesContext *ctx, MesObject *o, void *table, int n);
void *mes_util_string_new(void);
void mes_util_string_puts(void *s, const char *t);
void mes_util_string_put_string(void *s, MesValue v);
void mes_util_string_puti(void *s, int v, int a, int radix);
void mes_util_string_free(void *s);
MesValue mes_string_new3(MesContext *ctx, void *s);
MesValue mes_eval_object_get(MesContext *ctx, MesValue o, unsigned int id);
extern MesObject *mes_classes[];
extern unsigned int mes_ids[];
MesValue mes_error_syntax(MesContext *ctx, MesValue msg);
extern MesObject *D_0058533C;
MesValue mes_error_native(MesContext *ctx, MesValue msg, int type);
MesValue mes_string_new2(MesContext *ctx, const char *s, int len);
MesObject *mes_object_new(MesContext *ctx, int cls, MesObject *proto);
void mes_object_set(MesObject *obj, unsigned int id, MesValue value, int flags);
MesValue mes_error_internal(MesContext *ctx, MesValue msg);

MesObject *mes_error_constructor(MesContext *ctx, MesValue msg)
{
    MesObject *o = mes_object_new(ctx, 3, D_0058533C);

    if (msg != 0) {
        *--ctx->sp = (MesValue)o;
        msg = mes_eval_to_string(ctx, msg);
        mes_object_set(o, mes_ids[53], msg, 0);
        ctx->sp++;
    }
    return o;
}

MesValue mes_error_to_string(MesContext *ctx)
{
    MesValue t = (MesValue)ctx->frame->thisobj;
    void *s;
    MesValue v;
    MesValue r;

    if (MES_IS_OBJECT(t)) {
    s = mes_util_string_new();
    v = mes_eval_object_get(ctx, t, mes_ids[55]);
    if (v != 0x20) {
        *--ctx->sp = v;
        mes_util_string_put_string(s, mes_eval_to_string(ctx, v));
        ctx->sp++;
    } else
        mes_util_string_puts(s, "Error");
    v = mes_eval_object_get(ctx, t, mes_ids[53]);
    if (v != 0x20) {
        mes_util_string_puts(s, ": ");
        *--ctx->sp = v;
        mes_util_string_put_string(s, mes_eval_to_string(ctx, v));
        ctx->sp++;
    }
    v = mes_eval_object_get(ctx, t, mes_ids[52]);
    if ((v & 3) == 1) {
        mes_util_string_puts(s, " at line ");
        mes_util_string_puti(s, v >> 2, 1, 10);
        v = mes_eval_object_get(ctx, t, mes_ids[39]);
        if ((v & 3) == 1) {
            mes_util_string_puts(s, " column ");
            mes_util_string_puti(s, v >> 2, 1, 10);
        }
    }
    r = mes_string_new3(ctx, s);
    mes_util_string_free(s);
    return r;
    }
    return 0;
}

MesValue mes_error_native(MesContext *ctx, MesValue msg, int type)
{
    MesObject *o = mes_object_new(ctx, 3, mes_classes[type]);

    if (msg != 0) {
        *--ctx->sp = (MesValue)o;
        msg = mes_eval_to_string(ctx, msg);
        mes_object_set(o, mes_ids[53], msg, 0);
        ctx->sp++;
    }
    return (MesValue)o;
}

MesValue mes_error_eval(MesContext *ctx, MesValue msg)
{
    return mes_error_native(ctx, msg, 4);
}

MesValue mes_error_range(MesContext *ctx, MesValue msg)
{
    return mes_error_native(ctx, msg, 10);
}

MesValue mes_error_reference(MesContext *ctx, MesValue msg)
{
    return mes_error_native(ctx, msg, 11);
}

MesValue mes_error_syntax(MesContext *ctx, MesValue msg)
{
    return mes_error_native(ctx, msg, 14);
}

MesValue mes_error_parse(MesContext *ctx, const char *s, int line, int col)
{
    MesValue m = mes_string_new2(ctx, s, 0);
    MesValue e;

    *--ctx->sp = m;
    e = mes_error_syntax(ctx, m);
    ctx->sp++;
    mes_object_set((MesObject *)e, mes_ids[52], MES_INT(line), 0);
    mes_object_set((MesObject *)e, mes_ids[39], MES_INT(col), 0);
    return e;
}

MesValue mes_error_type(MesContext *ctx, MesValue msg)
{
    if ((msg & 3) != 3)
        msg = 0;
    return mes_error_native(ctx, msg, 15);
}

MesValue mes_error_uri(MesContext *ctx, MesValue msg)
{
    return mes_error_native(ctx, msg, 16);
}

MesValue mes_error_internal(MesContext *ctx, MesValue msg)
{
    return mes_error_native(ctx, msg, 6);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", D_0013BDD4);

MesValue mes_error_stack(MesContext *ctx, int overflow)
{
    MesValue s = mes_string_new2(ctx, overflow ? "stack overflow" : "stack underflow", 0);
    MesValue r;

    *--ctx->sp = s;
    r = mes_error_internal(ctx, s);
    ctx->sp++;
    return r;
}

void mes_error_setup(MesContext *ctx)
{
    MesObject *proto;
    MesObject *ctor;
    unsigned int id;
    unsigned int i;

    proto = mes_object_new(ctx, 3, mes_classes[9]);
    mes_classes[3] = proto;
    mes_object_set(proto, mes_ids[53], mes_empty, 0);
    ctor = mes_native_new(ctx, mes_ids[3], mes_error_constructor, 1, 1);
    mes_object_set(ctx->global, mes_ids[3], (MesValue)ctor, 7);
    mes_object_set((MesObject *)ctor, mes_ids[59], (MesValue)proto, 7);
    mes_object_set(proto, mes_ids[40], (MesValue)ctor, 2);
    mes_native_setup(ctx, proto, &mes_error_table, 1);
    mes_object_set(proto, mes_ids[55], mes_ids[3], 0);
    for (i = 0; i < 7; i++) {
        id = mes_ids[mes_error_native_table[i].idx];
        proto = mes_object_new(ctx, 3, mes_classes[3]);
        mes_classes[mes_error_native_table[i].idx] = proto;
        mes_object_set(proto, mes_ids[53], mes_empty, 0);
        ctor = mes_native_new(ctx, id, mes_error_native_table[i].fn, 1, 1);
        mes_object_set(ctx->global, id, (MesValue)ctor, 7);
        mes_object_set((MesObject *)ctor, mes_ids[59], (MesValue)proto, 7);
        mes_object_set(proto, mes_ids[40], (MesValue)ctor, 2);
        mes_object_set(proto, mes_ids[55], id, 0);
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", D_0013BE00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", D_0013BE08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", D_0013BE10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", D_0013BE14);
