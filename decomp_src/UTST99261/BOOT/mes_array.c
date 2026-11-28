/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct ArrStr {
    unsigned short *chars;            /* 0x0 */
    int slen;                         /* 0x4 */
} ArrStr;
int mes_util_digit(int c);
int mes_eval_type_error(MesContext *ctx, MesValue v);
extern const double D_0013B890;
MesValue mes_eval_object_get(MesContext *ctx, MesValue o, unsigned int id);
MesValue mes_eval_object_put(MesContext *ctx, MesValue o, unsigned int id, MesValue v);
int mes_eval_object_delete(MesContext *ctx, MesValue o, unsigned int id);
unsigned int mes_eval_to_uint32(MesContext *ctx, MesValue v);
extern unsigned int mes_ids[];
extern void *mes_array_table;
MesValue mes_array_constructor(MesContext *ctx, MesValue v);
void *mes_native_new(MesContext *ctx, int a, void *fn, int nargs, int flags);
void mes_native_setup(MesContext *ctx, MesObject *o, void *table, int n);
typedef struct MesArray {
    struct MesObject obj;
    unsigned int length;              /* 0x14 */
} MesArray;
extern MesObject *mes_classes[];
void *mes_gc_alloc(MesContext *ctx, int kind);
void mes_object_init(MesObject *obj, int cls, MesObject *proto);
void mes_object_set(MesObject *obj, unsigned int id, MesValue value, int flags);
MesValue mes_object_get(MesObject *obj, unsigned int id);
int mes_object_canput(MesObject *obj, unsigned int id);
MesValue mes_number_alloc_uint32(MesContext *ctx, unsigned int n);
MesValue mes_array_join(MesContext *ctx, int sep);
void *mes_util_string_new(void);
void mes_util_string_puti(void *s, int n, int w, int base);
MesValue mes_string_new3(MesContext *ctx, void *s);
void mes_util_string_free(void *s);
unsigned int mes_context_index(MesValue v);
void mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_array_method;


int mes_eval_to_int32(MesContext *ctx, MesValue v);
int mes_array_sort_compare(MesContext *ctx, MesValue fn, MesValue x, MesValue y);
int *mes_util_vals(int n, int a);
MesValue mes_eval(MesContext *ctx, MesValue fn, int *args, MesObject *thisobj, int f);
int mes_string_compare(void *a, void *b);
void mes_util_string_put(void *s, unsigned short c);
void mes_util_string_put_string(void *s, MesValue v);
MesValue mes_eval_to_object(MesContext *ctx, MesValue v);
MesValue mes_error_range(MesContext *ctx, MesValue v);
extern const double D_0013B898;
void mes_object_delete(void *obj, unsigned int id);
MesArray *mes_array_new(MesContext *ctx, unsigned int len)
{
    MesArray *a = mes_gc_alloc(ctx, 6);

    if (a != NULL) {
        mes_object_init(&a->obj, 0, mes_classes[0]);
        a->length = len;
    }
    return a;
}

void mes_array_set(MesContext *ctx, MesArray *a, MesValue v)
{
    if (a != NULL) {
        if (v != MES_UNDEFINED)
            mes_object_set(&a->obj, MES_INT(a->length), v, 0);
        a->length++;
    }
}

MesValue mes_array_get(MesContext *ctx, MesArray *a, unsigned int id)
{
    if (id == mes_ids[51])
        return mes_number_alloc_uint32(ctx, a->length);
    return mes_object_get(&a->obj, id);
}

unsigned int mes_array_number_index(MesContext *ctx, int n)
{
    unsigned int v = (n << 2) | 1;
    unsigned int ret;
    void *s;

    if (MES_INT(v) != n) {
        s = mes_util_string_new();
        if (s == NULL) {
            ctx->f14 = (*(MesValue *)((char *)&mes_ids + 0x70));
            ret = 0;
        } else {
            mes_util_string_puti(s, n, 0, 10);
            v = mes_string_new3(ctx, s);
            mes_util_string_free(s);
            ret = mes_context_index(v);
        }
    } else {
        ret = v;
    }
    return ret;
}

unsigned int mes_array_length(MesContext *ctx, MesValue v)
{
    unsigned int n;
    double x;
    int i;

    if (MES_IS_OBJECT(v) && ((unsigned char *)v)[0x10] == 8)
        v = ((MesValue *)v)[3];
    if (v == 0x10)
        return 0;
    if ((v & 3) == 1 && (i = v >> 2) >= 0)
        return i;
    if ((v & 3) == 2 && *(double *)((v & ~3) + 8) >= 0) {
        n = *(double *)((v & ~3) + 8);
        x = (int)n;
        if ((int)n < 0)
            x = x + D_0013B890;
        if (x == *(double *)((v & ~3) + 8))
            return n;
    }
    mes_eval_type_error(ctx, v);
    return 0;
}

void mes_array_put(MesContext *ctx, MesArray *a, unsigned int id, MesValue v)
{
    unsigned int n;
    int i;
    int d;
    unsigned short *p;

    if (id == mes_ids[51]) {
        n = mes_array_length(ctx, v);
        if (n < a->length) {
            for (i = n; i < a->length; i++)
                mes_object_delete(&a->obj, mes_array_number_index(ctx, i));
        }
        a->length = n;
        return;
    }
    if ((id & 3) == 1) {
        i = (int)id >> 2;
        if (i >= 0) {
            n = i;
            goto check;
        }
        goto set;
    }
    i = ((ArrStr *)(id & ~3))->slen;
    p = ((ArrStr *)(id & ~3))->chars;
    if (i <= 0 || mes_util_digit(*p) < 0)
        goto set;
    n = 0;
    if (*p == '0') {
        mes_object_set(&a->obj, id, v, 8);
        return;
    }
    while (i > 0 && (d = mes_util_digit(*p)) >= 0) {
        if (n > 0x19999999)
            break;
        if (n == 0x19999999 && (unsigned int)(d + 1) >= 6)
            break;
        n = n * 10 + d;
        p++;
        i--;
    }
    if (i != 0)
        goto set;
check:
    if (n >= a->length)
        a->length = n + 1;
set:
    mes_object_set(&a->obj, id, v, 8);
}

int mes_array_canput(MesContext *ctx, MesArray *a, unsigned int id)
{
    int ret = 1;

    if (id != mes_ids[51])
        ret = mes_object_canput(&a->obj, id);
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_array_initialize(void) {
    mes_gc_register(&mes_array_method, 0x18, 0x20, 0x20);
}

MesValue mes_array_constructor(MesContext *ctx, MesValue v)
{
    MesArgs *args;
    MesArray *a;
    unsigned int n;
    unsigned int i;
    unsigned int m;
    double x;

    args = ctx->frame->args;
    if (args == NULL || args->argc == 0)
        return (MesValue)mes_array_new(ctx, 0);
    if (args->argc == 1 && (v == 0x10 || (v & 3) == 1 || (v & 3) == 2)) {
        if (v == 0x10)
            v = 1;
        if ((v & 3) == 1) {
            if (v < 0)
                goto err;
            n = v >> 2;
        } else {
            if (*(double *)((v & ~3) + 8) < 0)
                goto err;
            m = *(double *)((v & ~3) + 8);
            x = (int)m;
            if ((int)m < 0)
                x = x + D_0013B898;
            if (x != *(double *)((v & ~3) + 8)) {
            err:
                ctx->f14 = mes_error_range(ctx, v);
                return 0;
            }
            n = *(double *)((v & ~3) + 8);
        }
        return (MesValue)mes_array_new(ctx, n);
    }
    a = mes_array_new(ctx, 0);
    for (i = 0; i < args->argc; i++)
        mes_array_set(ctx, a, args->argv[i]);
    return (MesValue)a;
}

MesValue mes_array_join(MesContext *ctx, int sep)
{
    MesValue t = (MesValue)ctx->frame->thisobj;
    MesValue v;
    unsigned int n;
    unsigned int i;
    void *s;

    v = mes_eval_object_get(ctx, t, mes_ids[51]);
    n = 0;
    if (v != 0x20)
        n = mes_eval_to_uint32(ctx, v);
    if (sep != 0)
        sep = mes_eval_to_string(ctx, sep);
    *--ctx->sp = sep;
    s = mes_util_string_new();
    for (i = 0; i < n; i++) {
        if (i != 0) {
            if ((sep & 3) == 3)
                mes_util_string_put_string(s, sep);
            else
                mes_util_string_put(s, ',');
        }
        v = mes_eval_object_get(ctx, t, MES_INT(i));
        if (v != 0 && v != 0x20) {
            if (v != 4)
                v = mes_eval_to_string(ctx, v);
        }
        if ((v & 3) == 3)
            mes_util_string_put_string(s, v);
    }
    ctx->sp++;
    v = mes_string_new3(ctx, s);
    mes_util_string_free(s);
    return v;
}

MesValue mes_array_to_string(MesContext *ctx)
{
    return mes_array_join(ctx, 0);
}

MesValue mes_array_to_locale_string(MesContext *ctx)
{
    MesValue t = (MesValue)ctx->frame->thisobj;
    MesValue v;
    MesValue f;
    unsigned int n;
    unsigned int i;
    void *s;

    v = mes_eval_object_get(ctx, t, mes_ids[51]);
    n = 0;
    if (v != 0x20)
        n = mes_eval_to_uint32(ctx, v);
    s = mes_util_string_new();
    for (i = 0; i < n; i++) {
        if (i != 0)
            mes_util_string_put(s, ',');
        v = mes_eval_object_get(ctx, t, MES_INT(i));
        if (v != 0 && v != 0x20 && v != 4) {
            v = mes_eval_to_object(ctx, v);
            *--ctx->sp = v;
            f = mes_eval_object_get(ctx, v, mes_ids[0xFC / 4]);
            if (MES_IS_OBJECT(f) && (((MesObject *)f)->gc->kind == 3 || ((MesObject *)f)->gc->kind == 4)) {
                *--ctx->sp = f;
                f = mes_eval(ctx, f, NULL, (MesObject *)v, 0);
                ctx->sp++;
                if ((f & 3) == 3)
                    mes_util_string_put_string(s, f);
            }
            ctx->sp++;
        }
    }
    v = mes_string_new3(ctx, s);
    mes_util_string_free(s);
    return v;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_concat);

MesValue mes_array_pop(MesContext *ctx)
{
    MesValue t = (MesValue)ctx->frame->thisobj;
    MesValue v;
    unsigned int n;

    v = mes_eval_object_get(ctx, t, mes_ids[51]);
    n = 0;
    if (v != 0x20)
        n = mes_eval_to_uint32(ctx, v);
    v = 0;
    if (n != 0) {
        n--;
        v = mes_eval_object_get(ctx, t, MES_INT(n));
        mes_eval_object_delete(ctx, t, MES_INT(n));
    }
    *--ctx->sp = v;
    mes_eval_object_put(ctx, t, mes_ids[51], MES_INT(n));
    ctx->sp++;
    return v;
}

MesValue mes_array_push(MesContext *ctx)
{
    MesValue t = (MesValue)ctx->frame->thisobj;
    MesArgs *a;
    MesValue v;
    unsigned int n;
    unsigned int i;

    v = mes_eval_object_get(ctx, t, mes_ids[51]);
    n = 0;
    if (v != 0x20)
        n = mes_eval_to_uint32(ctx, v);
    a = ctx->frame->args;
    if (a != NULL)
        for (i = 0; i < a->argc; i++, n++)
            mes_eval_object_put(ctx, t, MES_INT(n), a->argv[i]);
    v = MES_INT(n);
    mes_eval_object_put(ctx, t, mes_ids[51], v);
    return v;
}

MesValue mes_array_reverse(MesContext *ctx)
{
    MesValue t = (MesValue)ctx->frame->thisobj;
    MesValue x;
    MesValue y;
    unsigned int n;
    unsigned int half;
    unsigned int i;
    unsigned int j;
    unsigned int ia;
    unsigned int ib;

    x = mes_eval_object_get(ctx, t, mes_ids[51]);
    n = 0;
    if (x != 0x20)
        n = mes_eval_to_uint32(ctx, x);
    half = n / 2;
    j = n;
    j--;
    for (i = 0; i < half; i++, j--) {
        ia = MES_INT(i);
        x = mes_eval_object_get(ctx, t, ia);
        ib = MES_INT(j);
        y = mes_eval_object_get(ctx, t, ib);
        mes_eval_object_put(ctx, t, ia, y);
        mes_eval_object_put(ctx, t, ib, x);
    }
    return t;
}

MesValue mes_array_shift(MesContext *ctx)
{
    MesValue t = (MesValue)ctx->frame->thisobj;
    MesValue v;
    MesValue first;
    unsigned int n;
    unsigned int i;

    v = mes_eval_object_get(ctx, t, mes_ids[51]);
    if (v != 0x20 && (n = mes_eval_to_uint32(ctx, v)) != 0) {
        first = mes_eval_object_get(ctx, t, MES_INT(0));
        for (i = 1; i < n; i++) {
            v = mes_eval_object_get(ctx, t, MES_INT(i));
            mes_eval_object_put(ctx, t, MES_INT(i - 1), v);
        }
        n--;
        mes_eval_object_put(ctx, t, mes_ids[51], MES_INT(n));
        return first;
    }
    return 0;
}

MesValue mes_array_slice(MesContext *ctx, MesValue start, MesValue end)
{
    MesArray *a;
    MesValue t;
    MesValue v;
    unsigned int n;
    int s;
    int e;

    a = mes_array_new(ctx, 0);
    *--ctx->sp = (MesValue)a;
    t = (MesValue)ctx->frame->thisobj;
    v = mes_eval_object_get(ctx, t, mes_ids[51]);
    n = 0;
    if (v != 0x20)
        n = mes_eval_to_uint32(ctx, v);
    s = mes_eval_to_int32(ctx, start);
    if (s < 0) {
        s += n;
        if (s < 0)
            s = 0;
    } else if (s > n)
        s = n;
    e = mes_eval_to_int32(ctx, end);
    if (e < 0) {
        e += n;
        if (e < 0)
            e = 0;
    } else if (e > n)
        e = n;
    for (; s < e; s++) {
        v = mes_eval_object_get(ctx, t, MES_INT(s));
        mes_array_set(ctx, a, v);
    }
    ctx->sp++;
    return (MesValue)a;
}

int mes_array_sort_compare(MesContext *ctx, MesValue fn, MesValue x, MesValue y)
{
    int *args;
    MesValue r;
    double d;

    if (x == 0x20) {
        if (y == 0x20)
            return 0;
        return 1;
    }
    if (y == 0x20)
        return -1;
    if (x == 0)
        return y != 0;
    if (y == 0)
        return -1;
    if (fn != 0) {
        args = mes_util_vals(2, 0);
        if (args != NULL) {
            args[1] = x;
            args[2] = y;
            x = mes_eval(ctx, fn, args, ctx->frame->thisobj, 0);
            if ((x & 3) == 2) {
                d = *(double *)((x & ~3) + 8);
                if (d < 0)
                    return -1;
                if (d > 0)
                    return 1;
                return 0;
            }
            if ((x & 3) == 1)
                return x >> 2;
            return 0;
        }
        M2C_FIELD(ctx, MesValue *, 0x14) = (*(MesValue *)((char *)&mes_ids + 0x70));
        return 0;
    }
    x = mes_eval_to_string(ctx, x);
    *--ctx->sp = x;
    y = mes_eval_to_string(ctx, y);
    ctx->sp++;
    return mes_string_compare((void *)(x & ~3), (void *)(y & ~3));
}

MesValue mes_array_sort(MesContext *ctx, MesValue fn)
{
    MesValue t = (MesValue)ctx->frame->thisobj;
    MesValue x;
    MesValue y;
    unsigned int n;
    unsigned int i;
    unsigned int ia;
    unsigned int ib;
    int sorted;

    x = mes_eval_object_get(ctx, t, mes_ids[51]);
    n = 0;
    if (x != 0x20)
        n = mes_eval_to_uint32(ctx, x);
    do {
        sorted = 1;
        for (i = 1; i < n; i++) {
            ia = MES_INT(i - 1);
            x = mes_eval_object_get(ctx, t, ia);
            ib = MES_INT(i);
            y = mes_eval_object_get(ctx, t, ib);
            if (mes_array_sort_compare(ctx, fn, x, y) > 0) {
                mes_eval_object_put(ctx, t, ia, y);
                mes_eval_object_put(ctx, t, ib, x);
                sorted = 0;
            }
        }
    } while (!sorted);
    return t;
}

MesValue mes_array_splice(MesContext *ctx, MesValue start, MesValue count)
{
    MesArray *a;
    MesArgs *args;
    MesValue t;
    MesValue v;
    unsigned int n;
    unsigned int nitems;
    unsigned int i;
    int s;
    int c;
    int d;

    a = mes_array_new(ctx, 0);
    *--ctx->sp = (MesValue)a;
    args = ctx->frame->args;
    t = (MesValue)ctx->frame->thisobj;
    if (args != NULL && (unsigned int)args->argc >= 3)
    {
        nitems = args->argc;
        nitems -= 2;
    }
    else
        nitems = 0;
    v = mes_eval_object_get(ctx, t, mes_ids[51]);
    n = 0;
    if (v != 0x20)
        n = mes_eval_to_uint32(ctx, v);
    s = mes_eval_to_int32(ctx, start);
    if (s < 0) {
        s += n;
        if (s < 0)
            s = 0;
    } else if (s > n)
        s = n;
    c = mes_eval_to_int32(ctx, count);
    if (c < 0)
        c = 0;
    else if (c > n - s)
        c = n - s;
    for (i = 0; i < c; i++)
        mes_array_set(ctx, a, mes_eval_object_get(ctx, t, MES_INT(s + i)));
    d = nitems - c;
    if (d < 0) {
        for (i = s + c; i < n; i++) {
            v = mes_eval_object_get(ctx, t, MES_INT(i));
            mes_eval_object_put(ctx, t, MES_INT(i + d), v);
        }
    } else if (d > 0) {
        for (i = n; i > s + c; ) {
            i--;
            v = mes_eval_object_get(ctx, t, MES_INT(i));
            mes_eval_object_put(ctx, t, MES_INT(i + d), v);
        }
    }
    n += d;
    for (i = 0; i < nitems; i++)
        mes_eval_object_put(ctx, t, MES_INT(s + i), args->argv[i + 2]);
    mes_eval_object_put(ctx, t, mes_ids[51], MES_INT(n));
    ctx->sp++;
    return (MesValue)a;
}

MesValue mes_array_unshift(MesContext *ctx)
{
    MesValue t = (MesValue)ctx->frame->thisobj;
    MesArgs *a;
    MesValue v;
    unsigned int n;
    unsigned int i;

    v = mes_eval_object_get(ctx, t, mes_ids[51]);
    n = 0;
    if (v != 0x20)
        n = mes_eval_to_uint32(ctx, v);
    a = ctx->frame->args;
    if (a == NULL)
        return MES_INT(n);
    i = n;
    while (i != 0) {
        i--;
        v = mes_eval_object_get(ctx, t, MES_INT(i));
        mes_eval_object_put(ctx, t, MES_INT(i + a->argc), v);
    }
    for (i = 0; i < a->argc; i++)
        mes_eval_object_put(ctx, t, MES_INT(i), a->argv[i]);
    v = MES_INT(n + a->argc);
    mes_eval_object_put(ctx, t, mes_ids[51], v);
    return v;
}

void mes_array_setup(MesContext *ctx)
{
    MesObject *proto;
    MesObject *ctor;

    proto = &mes_array_new(ctx, 0)->obj;
    proto->proto = mes_classes[9];
    mes_classes[0] = proto;
    ctor = mes_native_new(NULL, mes_ids[0], mes_array_constructor, 1, 1);
    mes_object_set(ctx->global, mes_ids[0], (MesValue)ctor, 7);
    mes_object_set(ctor, mes_ids[59], (MesValue)proto, 7);
    mes_object_set(proto, mes_ids[40], (MesValue)ctor, 2);
    mes_native_setup(ctx, proto, &mes_array_table, 12);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B890);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B894);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B898);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B89C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B900);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B908);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B910);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B91C);
