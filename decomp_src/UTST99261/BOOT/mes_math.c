/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
MesValue mes_eval_to_number(MesContext *ctx, MesValue v);
double mes_num(MesValue v);
MesValue mes_number_alloc(MesContext *ctx, double d);
double sin(double x);
double cos(double x);
double tan(double x);
double exp(double x);
double sqrt(double x);
double log(double x);
double atan(double x);
double floor(double x);
int rand(void);
void srand(unsigned int seed);
int CLIB_time(void *t);
extern int D_0025BA10;
extern const double D_0013B948;
extern const double D_0013B950;
extern const double D_0013B9C0;
extern const double D_0013B9A0;

MesValue mes_math_abs(MesContext *ctx, MesValue v)
{
    MesValue n = mes_eval_to_number(ctx, v);
    double d;

    if (n == 0x1C)
        return 0x1C;
    if (n == 0x10)
        return 1;
    if (n == 0x14 || n == 0x18)
        return 0x14;
    d = mes_num(n);
    if (!(d >= 0))
        d = -d;
    return mes_number_alloc(ctx, d);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_acos);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_asin);

MesValue mes_math_atan(MesContext *ctx, MesValue v)
{
    MesValue n = mes_eval_to_number(ctx, v);
    MesValue ret;

    if (n == 0x1C)
        ret = 0x1C;
    else if (n == 1 || n == 0x10)
        ret = n;
    else if (n == 0x14)
        ret = mes_number_alloc(ctx, D_0013B948);
    else if (n == 0x18)
        ret = mes_number_alloc(ctx, D_0013B950);
    else
        ret = mes_number_alloc(ctx, atan(mes_num(n)));
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_atan2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_ceil);

MesValue mes_math_cos(MesContext *ctx, MesValue v)
{
    MesValue n = mes_eval_to_number(ctx, v);

    if (n == 0x1C || n == 0x14 || n == 0x18)
        return 0x1C;
    if (n == 1 || n == 0x10)
        return 5;
    return mes_number_alloc(ctx, cos(mes_num(n)));
}

MesValue mes_math_exp(MesContext *ctx, MesValue v)
{
    MesValue n = mes_eval_to_number(ctx, v);
    MesValue ret;

    if (n == 0x1C)
        ret = 0x1C;
    else if (n == 1 || n == 0x10)
        ret = 5;
    else if (n == 0x14)
        ret = 0x14;
    else if (n == 0x18)
        ret = 1;
    else
        ret = mes_number_alloc(ctx, exp(mes_num(n)));
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_floor);

MesValue mes_math_log(MesContext *ctx, MesValue v)
{
    MesValue n = mes_eval_to_number(ctx, v);
    MesValue ret;
    double d;

    if (n == 0x1C || n == 0x18)
        ret = 0x1C;
    else if (n == 1 || n == 0x10)
        ret = 0x18;
    else if (n == 5)
        ret = 1;
    else if (n == 0x14)
        ret = 0x14;
    else {
        d = mes_num(n);
        if (d < 0)
            ret = 0x1C;
        else
            ret = mes_number_alloc(ctx, log(d));
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_max);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_min);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_pow);

MesValue mes_math_random(MesContext *ctx)
{
    if (!D_0025BA10) {
        srand(CLIB_time(0));
        D_0025BA10 = 1;
    }
    return mes_number_alloc(ctx, rand() * D_0013B9C0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_round);

MesValue mes_math_sin(MesContext *ctx, MesValue v)
{
    MesValue n = mes_eval_to_number(ctx, v);

    if (n == 0x1C || n == 0x14 || n == 0x18)
        return 0x1C;
    if (n == 1 || n == 0x10)
        return n;
    return mes_number_alloc(ctx, sin(mes_num(n)));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_sqrt);

MesValue mes_math_tan(MesContext *ctx, MesValue v)
{
    MesValue n = mes_eval_to_number(ctx, v);

    if (n == 0x1C || n == 0x14 || n == 0x18)
        return 0x1C;
    if (n == 1 || n == 0x10)
        return n;
    return mes_number_alloc(ctx, tan(mes_num(n)));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", mes_math_setup);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B928);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B92C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B930);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B934);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B938);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B93C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B940);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B944);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B948);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B94C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B950);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B954);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B958);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B95C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B960);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B964);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B968);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B96C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B970);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B974);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B978);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B97C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B980);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B984);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B988);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B98C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B990);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B994);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B998);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B99C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013B9FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA34);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BA9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAA0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAB0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BABC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BACC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_math", D_0013BAD4);
