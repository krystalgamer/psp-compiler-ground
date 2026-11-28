/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
extern const double D_0013B780;       /* 10.0 */
void mes_util_string_put(void *s, unsigned short c);
MesValue mes_number_to_special(MesValue v);
MesValue mes_number_to_string(MesContext *ctx, MesValue v);
int mes_eval_to_int32(MesContext *ctx, MesValue v);
MesValue mes_error_range(MesContext *ctx, MesValue v);
typedef struct MesSBuf {
    char pad[0x14];
    int len;                          /* 0x14 */
} MesSBuf;
double mes_number_fmod(double a, double b);
int mes_util_string_get(MesSBuf *s, int i);
extern MesObject *D_00585350;
int isnan(double d);
int isinf(double d);
MesValue mes_eval_to_number(MesContext *ctx, MesValue v);
extern unsigned int mes_ids[];
extern void *mes_number_table;
MesValue mes_number_constructor(MesContext *ctx, MesValue v);
MesValue mes_number_alloc(MesContext *ctx, double d);
MesValue mes_number_from_string(MesContext *ctx, MesValue s, int a, int b);
MesValue mes_string_new2(MesContext *ctx, const char *s, int len);
void *mes_native_new(MesContext *ctx, int a, void *fn, int nargs, int flags);
void mes_native_setup(MesContext *ctx, MesObject *o, void *table, int n);
void mes_object_set(MesObject *obj, unsigned int id, MesValue value, int flags);
typedef struct MesNum {
    void *gc;
    int f4;
    double d;
} MesNum;
extern const double D_0013B760;
double floor(double x);
void *mes_gc_alloc(MesContext *ctx, int kind);
MesValue mes_number_to_precision_sub(MesContext *ctx, double d, int prec);
MesValue mes_eval_type_error(MesContext *ctx, MesValue v);
int mes_is_number(MesValue v);
double mes_num(MesValue v);
extern unsigned char mes_number_method;

double fmod(double a, double b);


void mes_util_string_puts(void *s, const char *str);
void mes_util_string_puti(void *s, int n, int w, int base);
void *mes_util_string_new(void);
MesValue mes_string_new3(MesContext *ctx, void *s);
void mes_util_string_free(void *s);
extern const double D_0013B780;
extern const double D_0013B788;
extern const double D_0013B790;
double mes_util_expt(double b, int e);
extern const double D_0013B7A8;
extern const double D_0013B7B0;
extern const double D_0013B798;
extern const double D_0013B7A0;
void mes_gc_register(void *, int objsize, int perpage, int threshold);
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

MesValue mes_number_alloc(MesContext *ctx, double d)
{
    MesValue v;
    MesNum *o;

    if (isnan(d))
        return 0x1C;
    if (isinf(d)) {
        if (d < 0)
            return 0x18;
        return 0x14;
    }
    v = MES_INT((int)d);
    if ((v >> 2) == d)
        return v;
    o = mes_gc_alloc(ctx, 2);
    if (o == NULL)
        return 0;
    o->d = d;
    return (MesValue)o | 2;
}

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

double mes_num(MesValue v)
{
    if ((v & 3) == 1)
        return v >> 2;
    if ((v & 3) == 2)
        return ((MesNum *)(v & ~3))->d;
    return 0;
}

double mes_number_floor(double d)
{
    if (d < 0)
        return -floor(-d);
    return floor(d);
}

double mes_number_fdiv(double a, double b)
{
    return floor(a / b);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

double mes_number_fmod(double a, double b) {
    return fmod(a, b);
}

MesValue mes_number_add(MesContext *ctx, MesValue a, MesValue b)
{
    MesValue r;

    if (a == 0x1C || b == 0x1C)
        r = 0x1C;
    else if (a == 0x14)
        r = b == 0x18 ? 0x1C : 0x14;
    else if (a == 0x18)
        r = b == 0x14 ? 0x1C : 0x18;
    else if (b == 0x14)
        r = 0x14;
    else if (b == 0x18)
        r = 0x18;
    else if (a == 0x10 && b == 0x10)
        r = 0x10;
    else
        r = mes_number_alloc(ctx, mes_num(a) + mes_num(b));
    return r;
}

MesValue mes_number_sub(MesContext *ctx, MesValue a, MesValue b)
{
    MesValue r;

    if (a == 0x1C || b == 0x1C)
        r = 0x1C;
    else if (a == 0x14)
        r = b == a ? 0x1C : 0x14;
    else if (a == 0x18)
        r = b == a ? 0x1C : 0x18;
    else if (b == 0x14)
        r = 0x18;
    else if (b == 0x18)
        r = 0x14;
    else if (a == 0x10 && b == 1)
        r = 0x10;
    else
        r = mes_number_alloc(ctx, mes_num(a) - mes_num(b));
    return r;
}

MesValue mes_number_minus(MesContext *ctx, MesValue v)
{
    MesValue r;

    if (v == 0x1C)
        r = 0x1C;
    else if (v == 0x14)
        r = 0x18;
    else if (v == 0x18)
        r = 0x14;
    else if (v == 0x10)
        r = 1;
    else if (v == 1)
        r = 0x10;
    else
        r = mes_number_alloc(ctx, -mes_num(v));
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_mul);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_div);

MesValue mes_number_mod(MesContext *ctx, MesValue a, MesValue b)
{
    if (a == 0x1C || b == 0x1C)
        return 0x1C;
    if (a == 0x14 || a == 0x18 || b == 1 || b == 0x10)
        return 0x1C;
    if (b == 0x14 || b == 0x18)
        return a;
    if (a == 1 || a == 0x10)
        return a;
    return mes_number_alloc(ctx, mes_number_fmod(mes_num(a), mes_num(b)));
}

int mes_number_equal(MesValue a, MesValue b, int strict)
{
    int r;

    if (a == b)
        return 1;
    if (a == 0x10) {
        if (strict)
            return 0;
        return b == 1;
    }
    if (b == 0x10) {
        if (strict)
            return 0;
        return a == 1;
    }
    if ((a == 0x14) | (a == 0x18) || (b == 0x14) | (b == 0x18))
        return 0;
    strict = a & 3;
    if (strict == 1 && (b & 3) == strict)
        return ((b ^ a) >> 2) == 0;
    r = 0;
    if (mes_num(a) == mes_num(b))
        r = 1;
    return r;
}

int mes_number_less(MesValue a, MesValue b, int strict)
{
    int r;

    if (a == b)
        return 0;
    if ((a == 0x10) & (b == 1))
        return strict != 0;
    if ((a == 1) & (b == 0x10))
        return 0;
    if (a == 0x14)
        return 0;
    if (b == 0x14)
        return 1;
    if (b == 0x18)
        return 0;
    if (a == 0x18)
        return 1;
    strict = a & 3;
    if (strict == 1 && (b & 3) == strict)
        return (a >> 2) < (b >> 2);
    r = 0;
    if (mes_num(a) < mes_num(b))
        r = 1;
    return r;
}

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

MesValue mes_number_constructor(MesContext *ctx, MesValue v)
{
    MesArgs *a = ctx->frame->args;
    MesObject *o;

    if (a != NULL && a->argc != 0)
        v = mes_eval_to_number(ctx, v);
    else
        v = 1;
    if (ctx->frame->construct) {
        *--ctx->sp = v;
        o = mes_object_new(ctx, 8, D_00585350);
        ctx->sp++;
        o->fC = v;
        return (MesValue)o;
    }
    return v;
}

MesValue mes_number_to_special(MesValue v)
{
    MesValue ret;

    if (v == 0x10)
        ret = (*(MesValue *)((char *)&mes_ids + 0x114));
    else if (v == 0x14)
        ret = (*(MesValue *)((char *)&mes_ids + 0x4C));
    else if (v == 0x18)
        ret = (*(MesValue *)((char *)&mes_ids + 0x110));
    else if (v == 0x1C)
        ret = (*(MesValue *)((char *)&mes_ids + 0x6C));
    else
        ret = 0;
    return ret;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7C4);

MesValue mes_number_to_str(MesContext *ctx, MesValue radix)
{
    MesValue v = (MesValue)ctx->frame->thisobj;
    MesValue r;
    void *s;

    if (MES_IS_OBJECT(v))
        v = ((MesValue *)v)[3];
    r = mes_number_to_special(v);
    if (r != 0)
        return r;
    if ((v & 3) != 1 && (v & 3) != 2)
        return mes_eval_type_error(ctx, v);
    if ((v & 3) == 1 && (radix & 3) == 1 && (radix >>= 2) >= 2 && radix < 37) {
        v >>= 2;
        s = mes_util_string_new();
        if (s == NULL)
            return ctx->f14 = (*(MesValue *)((char *)&mes_ids + 0x70));
        if (v == 0)
            mes_util_string_put(s, '0');
        else {
            if (v < 0) {
                mes_util_string_put(s, '-');
                v = -v;
            }
            if (radix == 16)
                mes_util_string_puts(s, "0x");
            mes_util_string_puti(s, v, 1, radix);
        }
        v = mes_string_new3(ctx, s);
        mes_util_string_free(s);
        return v;
    }
    return mes_number_to_string(ctx, v);
}

MesValue mes_number_value_of(MesContext *ctx)
{
    MesValue v = (MesValue)ctx->frame->thisobj;

    if (MES_IS_OBJECT(v))
        v = ((MesObject *)v)->fC;
    if (!mes_is_number(v))
        return mes_eval_type_error(ctx, v);
    return v;
}

void mes_number_to_fixed_sub(MesSBuf *s, double d, int n, int dot)
{
    if (d >= D_0013B780 || n > 0)
        mes_number_to_fixed_sub(s, d / D_0013B780, n - 1, 1);
    mes_util_string_put(s, (int)fmod(d, D_0013B780) + '0');
    if (n == 0 && dot)
        mes_util_string_put(s, '.');
}

MesValue mes_number_to_fixed(MesContext *ctx, MesValue digits)
{
    MesValue v = (MesValue)ctx->frame->thisobj;
    MesValue r;
    double d;
    void *s;

    if (MES_IS_OBJECT(v))
        v = ((MesValue *)v)[3];
    r = mes_number_to_special(v);
    if (r != 0)
        return r;
    if ((v & 3) != 1 && (v & 3) != 2)
        return mes_eval_type_error(ctx, v);
    d = mes_num(v);
    digits = mes_eval_to_int32(ctx, digits);
    if ((unsigned int)digits > 20) {
        ctx->f14 = mes_error_range(ctx, v);
        return 0;
    }
    s = mes_util_string_new();
    if (s == NULL)
        return ctx->f14 = (*(MesValue *)((char *)&mes_ids + 0x70));
    if (d < 0) {
        d = -d;
        mes_util_string_put(s, '-');
    }
    mes_number_to_fixed_sub(s, floor(d * mes_util_expt(D_0013B788, digits) + D_0013B790), digits, 0);
    v = mes_string_new3(ctx, s);
    mes_util_string_free(s);
    return v;
}

void mes_number_to_exponential_sub(MesSBuf *s)
{
    while (s->len > 0 && mes_util_string_get(s, s->len - 1) == '0')
        s->len--;
    if (s->len > 0 && mes_util_string_get(s, s->len - 1) == '.')
        s->len--;
}

MesValue mes_number_to_exponential(MesContext *ctx, MesValue digits)
{
    MesValue v = (MesValue)ctx->frame->thisobj;
    MesValue r;
    void *s;
    double d;
    double lo;
    double hi;
    double t;
    int e;
    int n;

    if (MES_IS_OBJECT(v))
        v = ((MesValue *)v)[3];
    if ((v & 3) != 1 && (v & 3) != 2)
        return mes_eval_type_error(ctx, v);
    n = mes_eval_to_int32(ctx, digits);
    if ((unsigned int)n > 20) {
        ctx->f14 = mes_error_range(ctx, v);
        return 0;
    }
    r = mes_number_to_special(v);
    if (r != 0)
        return r;
    d = mes_num(v);
    s = mes_util_string_new();
    if (s == NULL)
        return ctx->f14 = (*(MesValue *)((char *)&mes_ids + 0x70));
    if (d < 0) {
        d = -d;
        mes_util_string_put(s, '-');
    }
    if (d == 0) {
        mes_util_string_put(s, '0');
    } else {
        e = 16;
        if (n)
            e = n;
        t = D_0013B798;
        lo = mes_util_expt(t, e);
        hi = lo * t;
        while (d < lo) {
            d *= D_0013B798;
            e--;
        }
        while (d >= hi) {
            d /= D_0013B798;
            e++;
        }
        lo = floor(d + D_0013B7A0);
        if (lo >= hi) {
            lo = floor(lo / D_0013B798);
            e++;
        }
        mes_number_to_fixed_sub(s, lo, n ? n : 16, 1);
        if (!n)
            mes_number_to_exponential_sub(s);
        mes_util_string_put(s, 'e');
        if (e < 0) {
            mes_util_string_put(s, '-');
            e = -e;
        } else {
            mes_util_string_put(s, '+');
        }
        mes_util_string_puti(s, e, 1, 10);
    }
    r = mes_string_new3(ctx, s);
    mes_util_string_free(s);
    return r;
}

MesValue mes_number_to_precision_sub(MesContext *ctx, double d, int prec)
{
    void *s;
    int e;
    double lo;
    double hi;
    double t;
    MesValue v;

    s = mes_util_string_new();
    if (s == NULL)
        return ctx->f14 = (*(MesValue *)((char *)&mes_ids + 0x70));
    if (d < 0) {
        d = -d;
        mes_util_string_put(s, '-');
    }
    if (d == 0) {
        mes_util_string_put(s, '0');
    } else {
        e = 15;
        if (prec)
            e = prec - 1;
        t = D_0013B7A8;
        lo = mes_util_expt(t, e);
        hi = lo * t;
        while (d < lo) {
            d *= D_0013B7A8;
            e--;
        }
        while (d >= hi) {
            d /= D_0013B7A8;
            e++;
        }
        lo = floor(d + D_0013B7B0);
        if (lo >= hi) {
            lo = floor(lo / D_0013B7A8);
            e++;
        }
        if (e < -6 || e >= (prec ? prec : 21)) {
            mes_number_to_fixed_sub(s, lo, prec ? prec - 1 : 15, 0);
            if (!prec)
                mes_number_to_exponential_sub(s);
            mes_util_string_put(s, 'e');
            if (e < 0) {
                mes_util_string_put(s, '-');
                e = -e;
            } else {
                mes_util_string_put(s, '+');
            }
            mes_util_string_puti(s, e, 1, 10);
        } else if (prec == 0) {
            if (e + 1 >= 16) {
                mes_number_to_fixed_sub(s, lo, 15 - e, 0);
                while (e + 1 >= 17) {
                    mes_util_string_put(s, '0');
                    e--;
                }
            } else {
                mes_number_to_fixed_sub(s, lo, 15 - e, 0);
                mes_number_to_exponential_sub(s);
            }
        } else {
            mes_number_to_fixed_sub(s, lo, prec - e - 1, 0);
        }
    }
    v = mes_string_new3(ctx, s);
    mes_util_string_free(s);
    return v;
}

MesValue mes_number_to_precision(MesContext *ctx, MesValue p)
{
    MesValue t = (MesValue)ctx->frame->thisobj;
    MesValue s;
    double d;
    int n;

    if (MES_IS_OBJECT(t))
        t = ((MesObject *)t)->fC;
    s = mes_number_to_special(t);
    if (s != 0)
        return s;
    if ((unsigned int)((t & 3) - 1) >= 2)
        return mes_eval_type_error(ctx, t);
    if (p == 0)
        return mes_number_to_string(ctx, t);
    d = mes_num(t);
    n = mes_eval_to_int32(ctx, p);
    if ((unsigned int)(n - 1) >= 21) {
        ctx->f14 = mes_error_range(ctx, t);
        return 0;
    }
    return mes_number_to_precision_sub(ctx, d, n);
}

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

void mes_number_setup(MesContext *ctx)
{
    MesObject *proto;
    MesObject *ctor;
    MesValue v;
    union {
        long long l;
        double d;
    } min;

    proto = mes_object_new(ctx, 8, mes_classes[9]);
    mes_classes[8] = proto;
    proto->fC = 1;
    ctor = mes_native_new(ctx, mes_ids[8], mes_number_constructor, 1, 1);
    mes_object_set(ctx->global, mes_ids[8], (MesValue)ctor, 7);
    v = mes_string_new2(ctx, "1.7976931348623157E+308", 0);
    *--ctx->sp = v;
    v = mes_number_from_string(ctx, v, 0, 0);
    ctx->sp++;
    mes_object_set(ctor, mes_ids[24], v, 7);
    min.l = 1;                        /* Number.MIN_VALUE */
    mes_object_set(ctor, mes_ids[25], mes_number_alloc(ctx, min.d), 7);
    mes_object_set(ctx->global, mes_ids[27], 0x1C, 6);
    mes_object_set(ctor, mes_ids[27], 0x1C, 7);
    mes_object_set(ctor, mes_ids[26], 0x18, 7);
    mes_object_set(ctx->global, mes_ids[19], 0x14, 6);
    mes_object_set(ctor, mes_ids[30], 0x14, 7);
    mes_object_set(ctor, mes_ids[59], (MesValue)proto, 7);
    mes_object_set(proto, mes_ids[40], (MesValue)ctor, 2);
    mes_native_setup(ctx, proto, &mes_number_table, 6);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B830);
