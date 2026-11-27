/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesObject *D_0058533C;
extern unsigned int D_005852EC;       /* "message" */
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
        mes_object_set(o, D_005852EC, msg, 0);
        ctx->sp++;
    }
    return o;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", mes_error_to_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", mes_error_native);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", mes_error_parse);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", mes_error_type);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", mes_error_setup);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", D_0013BE00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", D_0013BE08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", D_0013BE10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_error", D_0013BE14);
