/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct MesNum {
    void *gc;
    int f4;
    double d;
} MesNum;
extern MesValue D_0058532C, D_00585264, D_00585328, D_00585284;
extern const double D_0013B760;
double floor(double x);
void *mes_gc_alloc(MesContext *ctx, int kind);
MesValue mes_number_to_precision_sub(MesContext *ctx, double d, int prec);
MesValue mes_eval_type_error(MesContext *ctx, MesValue v);
int mes_is_number(MesValue v);
double mes_num(MesValue v);
extern unsigned char mes_number_method;

M2C_UNK fmod();                                     /* extern */


MesValue mes_number_alloc_int32(MesContext *ctx, int n)
{
    MesValue v = MES_INT(n);
    MesNum *o;

    if ((v >> 2) == n)
        return v;
    o = mes_gc_alloc(ctx, 2);
    if (o == NULL)
        return 0;
    o->d = n;
    return (MesValue)o | 2;
}

MesValue mes_number_alloc_uint32(MesContext *ctx, unsigned int n)
{
    MesValue v;
    MesNum *o;
    double d;

    if ((int)n >= 0) {
        v = MES_INT(n);
        if ((v >> 2) == n)
            return v;
    }
    o = mes_gc_alloc(ctx, 2);
    if (o == NULL)
        return 0;
    d = (int)n;
    if ((int)n < 0)
        d += D_0013B760;
    o->d = d;
    return (MesValue)o | 2;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_alloc);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_is_number(int arg0) {
    int var_a0;
    unsigned int temp_v0;

    temp_v0 = arg0 & 3;
    var_a0 = (unsigned int) (arg0 - 0x10) < 0xDU;
    if (temp_v0 != 0) {
        var_a0 = 0;
        if (temp_v0 < 3U) {
            var_a0 = 1;
        }
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_num);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_floor);

double mes_number_fdiv(double a, double b)
{
    return floor(a / b);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_number_fmod(void) {
    fmod();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_add);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_minus);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_mul);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_div);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_mod);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_equal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_less);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B760);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B764);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B768);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B76C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B770);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B774);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B778);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B77C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B780);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B784);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B788);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B78C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B790);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B794);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B798);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B79C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7B4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_from_string);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_number_initialize(void) {
    mes_gc_register(&mes_number_method, 0x10, 0x64, 0x64);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_constructor);

MesValue mes_number_to_special(MesValue v)
{
    MesValue ret;

    if (v == 0x10)
        ret = D_0058532C;
    else if (v == 0x14)
        ret = D_00585264;
    else if (v == 0x18)
        ret = D_00585328;
    else if (v == 0x1C)
        ret = D_00585284;
    else
        ret = 0;
    return ret;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7C4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_str);

MesValue mes_number_value_of(MesContext *ctx)
{
    MesValue v = (MesValue)ctx->frame->thisobj;

    if (MES_IS_OBJECT(v))
        v = ((MesObject *)v)->fC;
    if (!mes_is_number(v))
        return mes_eval_type_error(ctx, v);
    return v;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_fixed_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_fixed);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_exponential_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_exponential);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_precision_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_precision);

MesValue mes_number_to_string(MesContext *ctx, MesValue v)
{
    MesValue s = mes_number_to_special(v);

    if (s != 0)
        return s;
    return mes_number_to_precision_sub(ctx, mes_num(v), 0);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B80C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_setup);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B830);
