/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern void *D_00585334, *D_00585350, *D_00585364;
extern unsigned int D_005852A0;
struct EvCtx;
typedef struct EvSc {
    char pad[0x14];
    unsigned char type;               /* 0x14 */
    unsigned char flag;               /* 0x15 */
    char pad16[2];
    struct EvSc *next;                /* 0x18 */
    int value;                        /* 0x1C */
    int obj;                          /* 0x20 */
} EvSc;
void mes_eval_scope_put();
extern void *mes_classes[];
extern unsigned int mes_ids[];
int mes_number_to_special(int v);
int mes_number_to_string(struct EvCtx *ctx, int v);
int mes_eval_object_get(struct EvCtx *ctx, int obj, unsigned int id);
int mes_eval(struct EvCtx *ctx, int f, int *args, int thisobj, int flags);
void *mes_object_new(struct EvCtx *ctx, int cls, void *proto);
int mes_number_equal(int a, int b, int f);
int mes_string_compare(void *a, void *b);
int mes_eval_type_error(void *ctx, int v);
struct EvCtx;
extern const double D_0013B3E0;       /* 4294967296.0 */
extern const double D_0013B3E8;       /* 2147483648.0 */
extern const double D_0013B3F0;       /* 4294967296.0 */
extern unsigned int D_005852F8, D_005852C4, D_0058531C, D_00585264, D_00585328, D_00585284;
int mes_eval_to_primitive(struct EvCtx *ctx, int v, int hint);
unsigned int mes_context_index(int s);
double mes_number_fmod(double a, double b);
typedef struct EvStr {
    unsigned short *str;
    int len;                          /* 0x4 */
} EvStr;
typedef struct EvNum {
    int f0;
    int f4;
    double d;                         /* 0x8 */
} EvNum;
extern void *D_00585354;
void *mes_gc_alloc(struct EvCtx *ctx, int kind);
void mes_object_init(void *obj, int cls, void *proto);
void *mes_util_string_new(void);
void mes_util_string_free(void *s);
int mes_string_new3(struct EvCtx *ctx, void *s);
int mes_error_uri(struct EvCtx *ctx, int v);
int mes_eval_decode(void *buf, unsigned short *s, int len, const char *reserved);
int mes_eval_encode(void *buf, unsigned short *s, int len, const char *unescaped);
double mes_number_floor(double d);
int mes_number_alloc(struct EvCtx *ctx, double d);
#define MESB(x) ((x) == 0 ? 8 : 0xC)
typedef struct EvGc {
    int f0, kind, f8, fC, f10, f14, f18;
    int (*del)(void *ctx, void *obj, unsigned int id);
} EvGc;
typedef struct EvProp {
    unsigned int id;
    int value;
    unsigned char flags;
} EvProp;
int mes_eval_to_string(struct EvCtx *ctx, int v);
int mes_number_from_string(struct EvCtx *ctx, int s, int a, int b);
void mes_util_string_put(void *buf, unsigned short c);
char mes_util_hex_char(unsigned int v);
EvProp *mes_object_search(void *obj, unsigned int id);
void mes_object_delete(void *obj, unsigned int id);
typedef struct EvObj {
    struct { int f0; int kind; } *gc;
    int f4, f8, fC, f10;
    int f14;
} EvObj;
typedef struct EvScope {
    char pad[0x20];
    EvObj *obj;
} EvScope;
typedef struct EvFrame {
    char pad[0x1C];
    int thisobj;
} EvFrame;
typedef struct EvCtx {
    char pad[0x10];
    EvFrame *frame;
    int error;                        /* 0x14 */
    int *sp;                          /* 0x18 */
} EvCtx;
extern unsigned int D_005852E4;
int mes_eval_object_set(int a, int b, int c, int d, int flags);
int mes_eval_string(EvCtx *ctx, int s, int thisobj, int x);
int mes_eval_to_number(EvCtx *ctx, int v);
int mes_error_type();                               /* extern */
int mes_util_hex(unsigned short);                              /* extern */
void mes_gc_mark(int);                           /* extern */
void mes_util_vals_mark(int);                    /* extern */
void mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_eval_method;
void mes_native_setup(void *, int, M2C_UNK *, M2C_UNK); /* extern */
void mes_object_set(int, int, M2C_UNK, M2C_UNK); /* extern */
extern int D_00585320;
extern unsigned char mes_eval_native_table;

void mes_util_vals_free(int);                    /* extern */


int mes_util_is_alpha_digit(unsigned short c);
int mes_util_char_in(unsigned short c, const char *set);
int mes_string_buf_getc();
void *mes_line_new(int (*getc)(), void *buf, int n);
void *mes_lex_new(EvCtx *ctx, void *line);
void mes_lex_free(void *lex);
void *mes_parse_program(EvCtx *ctx, void *lex, int mode);
int mes_parse_node_free(void *node);
int mes_compile(EvCtx *ctx, void *node);
void mes_list_free2(int list, int keep);
int mes_error_syntax(EvCtx *ctx, int a);
typedef struct { unsigned int n; int items[1]; } EvArr;
typedef struct { char pad[0x20]; int obj; EvArr *args; EvArr *locals; EvArr *x2C; } EvScF;
typedef struct NatFn { char pad[0x18]; int (*fn)(); unsigned char nargs; } NatFn;
typedef struct NatArgs { unsigned int n; int v[1]; } NatArgs;
typedef struct NatFrame { char pad[0x20]; NatFn *func; NatArgs *args; } NatFrame;
typedef struct NatCtx { char pad[0x10]; NatFrame *frame; } NatCtx;
extern unsigned int D_005852C0;
EvArr *mes_util_vals(int n, int a);
int mes_util_is_white_space(unsigned short c);
int mes_string_new(EvCtx *ctx, unsigned short *s, int len);
typedef int (*EvGetFn)(EvCtx *, EvObj *, unsigned int);
void mes_object_mark(void *arg0);
void mes_object_free(void *arg0);
void *mes_eval_scope_new(EvCtx *ctx, int a, int b, int c)
{
    char *o = mes_gc_alloc(ctx, 5);

    if (o != NULL) {
        mes_object_init(o, 9, D_00585354);
        o[0x14] = a;
        o[0x15] = 0;
        o[0x16] = 0;
        *(int *)(o + 0x20) = b;
        *(int *)(o + 0x1C) = c;
        *(int *)(o + 0x24) = 0;
        *(int *)(o + 0x28) = 0;
        *(int *)(o + 0x2C) = 0;
        *(int *)(o + 0x18) = 0;
    }
    return o;
}

void *mes_eval_scope_bind(EvCtx *ctx, int f, EvArr *args, int thisobj)
{
    int kind;
    char *s;
    int n;

    if ((f & 3) != 0 || (unsigned int)f <= 0x20)
        goto fail;
    kind = (*(EvGc **)f)->kind;
    if (kind != 3 && (kind != 4 && kind != 8))
        goto fail;
    if (kind == 8) {
        thisobj = f;
        f = mes_eval_object_get(ctx, f, D_005852C0);
        if ((f & 3) != 0 || (unsigned int)f <= 0x20)
            goto fail;
        kind = (*(EvGc **)f)->kind;
        if (kind != 3) {
            if (kind != 4) {
fail:
                return NULL;
            }
        }
    }
    s = mes_eval_scope_new(ctx, 1, f, thisobj);
    if (s != NULL) {
        *(EvArr **)(s + 0x24) = args;
        if (kind == 3) {
            *(int *)(s + 0x18) = *(int *)(f + 0x28);
            if (*(unsigned short *)(f + 0x26) != 0)
                *(EvArr **)(s + 0x2C) = mes_util_vals(*(unsigned short *)(f + 0x26), 0);
            n = 0;
            if (args != NULL)
                n = args->n;
            if (n < *(unsigned short *)(f + 0x24))
                *(EvArr **)(s + 0x28) = mes_util_vals(*(unsigned short *)(f + 0x24) - n, 0);
        } else {
            *(int *)(s + 0x18) = M2C_FIELD(ctx, int *, 0x10);
        }
    }
    return s;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_scope_get);

void mes_eval_scope_put(EvCtx *ctx, EvScF *s, unsigned int id, int v)
{
    EvProp *p;
    EvArr *a;
    int i;

    if ((id & 3) == 1) {
        i = (int)id >> 2;
        if (i >= 0) {
            a = s->args;
            if (a == NULL) {
                a = s->locals;
            } else if (i >= a->n) {
                i -= a->n;
                a = s->locals;
            }
            if (a != NULL && i < a->n) {
                a->items[i] = v;
                return;
            }
        }
    }
    p = mes_object_search((void *)s->obj, id);
    if (p != NULL && (*(unsigned char *)((char *)p + 8) & 0x20)) {
        i = *(short *)((char *)p + 0xA);
        if (i >= 0) {
            a = s->args;
            if (a == NULL) {
                a = s->locals;
            } else if (i >= a->n) {
                i -= a->n;
                a = s->locals;
            }
        } else {
            a = s->x2C;
            i = ~i;
        }
        if (a != NULL && i < a->n) {
            a->items[i] = v;
            return;
        }
    }
    mes_object_set(s, id, v, 8);
}

int mes_eval_scope_canput(EvCtx *ctx, EvScope *scope, unsigned int id)
{
    EvObj *o;

    if (id == D_005852E4)
        return 0;
    o = scope->obj;
    if (o->gc->kind == 3 && id == o->f14)
        return 0;
    return 1;
}

int mes_eval_type(unsigned int v)
{
    int ret;

    switch (v & 3) {
    case 1:
    case 2:
        ret = 0x39;
        break;
    case 3:
        ret = 0x3E;
        break;
    case 0:
        ret = 0x42;
        if (v == 0)
            break;
        ret = 0x38;
        if (v == 4)
            break;
        ret = 0x24;
        if (v == 0xC || v == 8)
            break;
        ret = (v >= 0x10 && v <= 0x1C) ? 0x39 : 0x3A;
        break;
    default:
        ret = 0x42;
        break;
    }
    return ret;
}

int mes_eval_to_primitive(EvCtx *ctx, int v, int hint)
{
    int i;
    int f;
    int id;

    if ((v & 3) != 0 || (unsigned int)v <= 0x20)
        return v;
    i = 1;
    if (hint == 0) {
        hint = (*(EvGc **)v)->kind == 7 ? 0x3E : 0x39;
        i = 1;
    }
    do {
        if (hint == 0x39) {
            id = 0x43;
            hint = 0x3E;
        } else {
            id = 0x40;
            hint = 0x39;
        }
        f = mes_eval_object_get(ctx, v, mes_ids[id]);
        if ((f & 3) == 0 && (unsigned int)f > 0x20 && (unsigned int)((*(EvGc **)f)->kind - 3) < 2) {
            *--ctx->sp = f;
            f = mes_eval(ctx, f, NULL, v, 1);
            ctx->sp++;
            if ((f & 3) != 0 || (unsigned int)f <= 0x20)
                return f;
        }
    } while (i-- > 0);
    return mes_eval_type_error(ctx, v);
}

int mes_eval_to_boolean(EvCtx *ctx, int v)
{
    switch ((unsigned int)v & 3) {
    case 0:
        if (v == 0xC || v == 0x14 || v == 0x18)
            return 0xC;
        return MESB((unsigned int)v > 0x20);
    case 1:
        return MESB((v >> 2) != 0);
    case 2:
        return ((EvNum *)(v & ~3))->d == 0 ? 8 : 0xC;
    case 3:
        return MESB(((EvStr *)(v & ~3))->len != 0);
    }
    return 8;
}

int mes_eval_to_number(EvCtx *ctx, int v)
{
    switch ((unsigned int)v & 3) {
    case 0:
        if (v == 0)
            return 0x1C;
        if (v == 4 || v == 8)
            return 1;
        if (v == 0xC)
            return 5;
        if (v >= 0x10 && v <= 0x1C)
            return v;
        v = mes_eval_to_primitive(ctx, v, 0x39);
        *--ctx->sp = v;
        v = mes_eval_to_number(ctx, v);
        ctx->sp++;
        return v;
    case 1:
    case 2:
        return v;
    case 3:
        return mes_number_from_string(ctx, v, 0, 1);
    }
    return 1;
}

int mes_eval_to_integer(EvCtx *ctx, int v)
{
    v = mes_eval_to_number(ctx, v);
    if (v == 0x1C)
        return 1;
    if (v == 1 || v == 0x10 || v == 0x14 || v == 0x18)
        return v;
    if ((v & 3) == 2)
        v = mes_number_alloc(ctx, mes_number_floor(((EvNum *)(v & ~3))->d));
    return v;
}

int mes_eval_to_int32(EvCtx *ctx, int v)
{
    double d;
    double m;

    v = mes_eval_to_number(ctx, v);
    if ((v & 3) == 1)
        return v >> 2;
    if ((v & 3) != 2)
        return 0;
    d = ((EvNum *)(v & ~3))->d;
    d = mes_number_floor(d);
    m = D_0013B3E0;
    d = mes_number_fmod(d, m);
    if (d < 0)
        d += m;
    if (d >= D_0013B3E8)
        d -= D_0013B3E0;
    return (int)d;
}

unsigned int mes_eval_to_uint32(EvCtx *ctx, int v)
{
    double d;
    double m;

    v = mes_eval_to_number(ctx, v);
    if ((v & 3) == 1)
        return v >> 2;
    if ((v & 3) != 2)
        return 0;
    d = ((EvNum *)(v & ~3))->d;
    d = mes_number_floor(d);
    m = D_0013B3F0;
    d = mes_number_fmod(d, m);
    if (d < 0)
        d += m;
    return (unsigned int)d;
}

int mes_eval_to_string(EvCtx *ctx, int v)
{
    switch ((unsigned int)v & 3) {
    case 0:
        if (v == 0)
            return D_00585320;
        if (v == 0xC)
            return D_0058531C;
        if (v == 8)
            return D_005852C4;
        if (v == 4)
            return D_005852F8;
        if (v >= 0x10 && v <= 0x1C)
            return mes_number_to_special(v);
        v = mes_eval_to_primitive(ctx, v, 0x3E);
        *--ctx->sp = v;
        v = mes_eval_to_string(ctx, v);
        ctx->sp++;
        return v;
    case 1:
    case 2:
        return mes_number_to_string(ctx, v);
    case 3:
        return v;
    }
    return D_00585320;
}

int mes_eval_to_object(EvCtx *ctx, int v)
{
    int cls;
    EvObj *o;

    switch ((unsigned int)v & 3) {
    case 0:
    default:
        if (v == 0 || v == 4)
            return mes_eval_type_error(ctx, v);
        if (v == 0xC || v == 8) {
            cls = 1;
            break;
        }
        if (v >= 0x10 && v <= 0x1C) {
            cls = 8;
            break;
        }
        return v;
    case 1:
    case 2:
        cls = 8;
        break;
    case 3:
        cls = 13;
        break;
    }
    o = mes_object_new(ctx, cls, mes_classes[cls]);
    o->fC = v;
    if (cls == 13)
        mes_object_set((int)o, D_005852E4, (((EvStr *)(v & ~3))->len << 2) | 1, 7);
    return (int)o;
}

unsigned int mes_eval_to_index(EvCtx *ctx, int v)
{
    switch ((unsigned int)v & 3) {
    case 0:
        if (v == 0)
            return D_00585320;
        if (v == 4)
            return D_005852F8;
        if (v == 8)
            return D_005852C4;
        if (v == 0xC)
            return D_0058531C;
        if (v == 0x10)
            return 1;
        if (v == 0x14)
            return D_00585264;
        if (v == 0x18)
            return D_00585328;
        if (v == 0x1C)
            return D_00585284;
        break;
    case 1:
        return v;
    case 2:
        break;
    case 3:
        return mes_context_index(v);
    }
    v = mes_eval_to_string(ctx, v);
    return mes_context_index(v);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_get_var);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_get_base);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_set_var);

void mes_eval_def_var(EvCtx *ctx, EvSc *s, unsigned int id)
{
    if (mes_eval_get_var(ctx, s, id) != 0x20)
        return;
    for (; s != NULL; s = s->next) {
        if (*(unsigned short *)&s->type == 1 && (*(EvGc **)s->obj)->kind == 3) {
            mes_eval_scope_put(ctx, s, id, 0);
            return;
        }
    }
    mes_eval_object_set((int)ctx, *(int *)((char *)ctx + 0xC), id, 0, 2);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_delete_var);

int mes_eval_object_get(EvCtx *ctx, int obj, unsigned int id)
{
    EvGc *gc;
    EvProp *p;
    int n;
    int r;

    if (obj == 0)
        return 0x20;
    switch ((unsigned int)obj & 3) {
    case 0:
        if (obj == 4)
            return 0x20;
        if (obj == 0xC || obj == 8)
            obj = (int)D_00585334;
        else if ((unsigned int)(obj - 0x10) <= 0xC)
            obj = (int)D_00585350;
        break;
    case 1:
    case 2:
        obj = (int)D_00585350;
        break;
    case 3:
        if (id == D_005852E4)
            return (((EvStr *)(obj & ~3))->len << 2) | 1;
        if ((id & 3) == 1) {
            n = (int)id >> 2;
            if (n < 0 || (unsigned int)n >= ((EvStr *)(obj & ~3))->len)
                return 0;
            return mes_string_new(ctx, ((EvStr *)(obj & ~3))->str + n, 1);
        }
        obj = (int)D_00585364;
        break;
    }
    if (id == D_005852A0) {
        r = ((EvObj *)obj)->f8;
        if (r != 0)
            return r;
        return 4;
    }
    for (; obj != 0; obj = ((EvObj *)obj)->f8) {
        EvGetFn get;
        gc = (EvGc *)((EvObj *)obj)->gc;
        get = (EvGetFn)gc->f10;
        if (get != NULL) {
            r = get(ctx, (EvObj *)obj, id);
            if (r != 0x20)
                return r;
        } else {
            p = mes_object_search((void *)obj, id);
            if (p != NULL)
                return p->value;
        }
    }
    return 0x20;
}

int mes_eval_object_canput(EvCtx *ctx, EvObj *o, unsigned int id)
{
    int (*f)(EvCtx *, EvObj *, unsigned int);
    EvProp *p;

    if (o == NULL)
        return 0;
    do {
        f = (void *)((EvGc *)o->gc)->f18;
        if (f != NULL) {
            if (!f(ctx, o, id))
                return 0;
        } else {
            p = mes_object_search(o, id);
            if (p != NULL && (p->flags & 1))
                return 0;
        }
        o = (EvObj *)o->f8;
    } while (o != NULL);
    return 1;
}

int mes_eval_object_delete(EvCtx *ctx, void *obj, unsigned int id)
{
    EvProp *p;

    if (obj == NULL)
        return 8;
    if ((*(EvGc **)obj)->del != NULL)
        return (*(EvGc **)obj)->del(ctx, obj, id);
    p = mes_object_search(obj, id);
    if (p != NULL && !(p->flags & 4)) {
        mes_object_delete(obj, id);
        return 12;
    }
    return 8;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_object_set);

int mes_eval_object_put(int a, int b, int c, int d)
{
    return mes_eval_object_set(a, b, c, d, 8);
}

int mes_eval_object_put2(EvCtx *ctx, int obj, unsigned int id, int v)
{
    if (obj == 0)
        return 0;
    switch ((unsigned int)obj & 3) {
    case 0:
        if (obj == 4)
            return 0;
        if (obj == 0xC || obj == 8)
            return mes_eval_object_canput(ctx, (EvObj *)D_00585334, id);
        if ((unsigned int)(obj - 0x10) <= 0xC)
            return mes_eval_object_canput(ctx, (EvObj *)D_00585350, id);
        break;
    case 1:
    case 2:
        return mes_eval_object_canput(ctx, (EvObj *)D_00585350, id);
    case 3:
        if (id == D_005852E4)
            return 0;
        return mes_eval_object_canput(ctx, (EvObj *)D_00585364, id);
    }
    if (v == 0x20)
        return mes_eval_object_delete(ctx, (void *)obj, id) == 0xC;
    if (id == D_005852A0) {
        if (v == 0 || v == 4)
            M2C_FIELD(obj, int *, 8) = 0;
        else
            M2C_FIELD(obj, int *, 8) = mes_eval_to_object(ctx, v);
        return 1;
    }
    if ((*(EvGc **)obj)->f14 != 0) {
        ((int (*)(EvCtx *, int, unsigned int, int))(*(EvGc **)obj)->f14)(ctx, obj, id, v);
        return 1;
    }
    mes_object_set(obj, id, v, 8);
    return 1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3F4);

int mes_eval_abs_equal(EvCtx *ctx, int a, int b)
{
    int ta = mes_eval_type(a);
    int tb = mes_eval_type(b);
    int r;

    if (ta == tb) {
        switch (ta) {
        case 0x38:
        case 0x42:
            return 1;
        case 0x39:
            if (a == 0x1C || b == 0x1C)
                return 0;
            return mes_number_equal(a, b, 0);
        case 0x3E:
            return mes_string_compare((void *)(a & ~3), (void *)(b & ~3)) == 0;
        case 0x24:
        case 0x3A:
            return a == b;
        }
        return 0;
    }
    if ((ta == 0x42 && tb == 0x38) || (ta == 0x38 && tb == 0x42))
        return 1;
    if ((ta == 0x39 && tb == 0x3E) || tb == 0x24) {
        b = mes_eval_to_number(ctx, b);
        *--M2C_FIELD(ctx, int **, 0x18) = b;
        r = mes_eval_abs_equal(ctx, a, b);
        M2C_FIELD(ctx, int **, 0x18) += 1;
        return r;
    }
    if ((ta == 0x3E && tb == 0x39) || ta == 0x24) {
        a = mes_eval_to_number(ctx, a);
        *--M2C_FIELD(ctx, int **, 0x18) = a;
        r = mes_eval_abs_equal(ctx, a, b);
        M2C_FIELD(ctx, int **, 0x18) += 1;
        return r;
    }
    if ((ta == 0x39 || ta == 0x3E) && tb == 0x3A) {
        b = mes_eval_to_primitive(ctx, b, 0);
        *--M2C_FIELD(ctx, int **, 0x18) = b;
        r = mes_eval_abs_equal(ctx, a, b);
        M2C_FIELD(ctx, int **, 0x18) += 1;
        return r;
    }
    if ((tb == 0x39 || tb == 0x3E) && ta == 0x3A) {
        a = mes_eval_to_primitive(ctx, a, 0);
        *--M2C_FIELD(ctx, int **, 0x18) = a;
        r = mes_eval_abs_equal(ctx, a, b);
        M2C_FIELD(ctx, int **, 0x18) += 1;
        return r;
    }
    return 0;
}

int mes_eval_strict_equal(int a, int b)
{
    int t = mes_eval_type(a);

    if (t == mes_eval_type(b)) {
        switch (t) {
        case 0x38:
        case 0x42:
            return 1;
        case 0x39:
            if (a == 0x1C || b == 0x1C)
                return 0;
            return mes_number_equal(a, b, 0);
        case 0x3E:
            return mes_string_compare((void *)(a & ~3), (void *)(b & ~3)) == 0;
        case 0x24:
        case 0x3A:
            return a == b;
        }
    }
    return 0;
}

int mes_eval_native(NatCtx *ctx) {
    int a[7];
    NatFrame *f;
    NatFn *n;
    int *p;
    unsigned int i;
    int r;

    f = ctx->frame;
    n = f->func;
    i = 0;
    if (f->args != NULL) {
        p = f->args->v;
        for (; i < f->args->n && (int)i < 7; i++)
            a[i] = *p++;
    }
    for (; (int)i < n->nargs; i++)
        a[i] = 0;
    r = 0;
    switch (n->nargs) {
    case 0:
        r = n->fn(ctx);
        break;
    case 1:
        r = n->fn(ctx, a[0]);
        break;
    case 2:
        r = n->fn(ctx, a[0], a[1]);
        break;
    case 3:
        r = n->fn(ctx, a[0], a[1], a[2]);
        break;
    case 4:
        r = n->fn(ctx, a[0], a[1], a[2], a[3]);
        break;
    case 5:
        r = n->fn(ctx, a[0], a[1], a[2], a[3], a[4]);
        break;
    case 6:
        r = n->fn(ctx, a[0], a[1], a[2], a[3], a[4], a[5]);
        break;
    case 7:
        r = n->fn(ctx, a[0], a[1], a[2], a[3], a[4], a[5], a[6]);
        break;
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_byte);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval);

int mes_eval_string(EvCtx *ctx, int s, int thisobj, int x)
{
    unsigned short *b[2];
    int *sp;
    void *lex;
    int list;
    void *node;
    int r;

    if ((s & 3) != 3) {
        return s;
    }
    sp = ctx->sp;
    b[0] = ((EvStr *)(s & ~3))->str;
    b[1] = b[0] + ((EvStr *)(s & ~3))->len;
    lex = mes_lex_new(ctx, mes_line_new(mes_string_buf_getc, b, 0));
    list = M2C_FIELD(ctx, int *, 8);
    node = mes_parse_program(ctx, lex, 0);
    if (M2C_FIELD(lex, unsigned short *, 0x12) == 0) {
        r = mes_compile(ctx, node);
        mes_parse_node_free(node);
        mes_list_free2(M2C_FIELD(ctx, int *, 8), list);
        M2C_FIELD(ctx, int *, 8) = list;
        ctx->sp = sp;
        if (ctx->error == 0) {
            ctx->sp = sp - 1;
            sp[-1] = r;
            M2C_FIELD(r, int *, 0x28) = M2C_FIELD(ctx->frame, int *, 0x18);
            r = mes_eval(ctx, r, 0, thisobj, 1);
            ctx->sp++;
        }
    } else {
        if (node != NULL) {
            mes_parse_node_free(node);
        }
        mes_list_free2(M2C_FIELD(ctx, int *, 8), list);
        M2C_FIELD(ctx, int *, 8) = list;
        ctx->sp = sp;
        if (ctx->error == 0) {
            ctx->error = mes_error_syntax(ctx, 0);
        }
        r = 0;
    }
    mes_lex_free(lex);
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mes_eval_type_error(void *arg0, int arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(arg0, void **, 0x18) = (void *) (temp_v1 - 4);
    M2C_FIELD(temp_v1, int *, -4) = arg1;
    M2C_FIELD(arg0, int *, 0x14) = mes_error_type();
    M2C_FIELD(arg0, void **, 0x18) = (void *) (M2C_FIELD(arg0, void **, 0x18) + 4);
    return 0;
}

int mes_eval_eval(EvCtx *ctx, int s)
{
    return mes_eval_string(ctx, s, ctx->frame->thisobj, 0);
}

int mes_eval_parse_int(EvCtx *ctx, int v, int radix)
{
    int sign;
    int nodig;
    unsigned short *p;
    unsigned short *end;
    int r;
    double n;
    unsigned int c;
    int d;

    if (v == 0)
        return 0x1C;
    v = mes_eval_to_string(ctx, v);
    nodig = 1;
    *--M2C_FIELD(ctx, int **, 0x18) = v;
    p = *(unsigned short **)(v & ~3);
    end = p + ((int *)(v & ~3))[1];
    while (p < end && mes_util_is_white_space(*p))
        p++;
    sign = 1;
    if (p < end && *p == '-') {
        sign = -1;
        p++;
    }
    while (p < end && (*p == '+' || *p == '-'))
        p++;
    r = mes_eval_to_int32(ctx, radix);
    if (r != 0 && (r < 2 || r > 36)) {
        M2C_FIELD(ctx, int **, 0x18)++;
        return 0x1C;
    }
    if ((r == 0 || r == 16) && p + 1 < end && p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) {
        p += 2;
        r = 16;
    }
    if ((r == 0 || r == 8) && p + 1 < end && p[0] == '0' && (p[1] >= '0' && p[1] <= '7')) {
        p++;
        r = 8;
    }
    if (r == 0)
        r = 10;
    n = 0;
    while (p < end) {
        c = *p++;
        if (c >= '0' && (int)c < r + '0')
            d = c - '0';
        else if (c >= 'a' && (int)c < r + 'a' - 10)
            d = c - 'a' + 10;
        else if (c >= 'A' && (int)c < r + 'A' - 10)
            d = c - 'A' + 10;
        else
            break;
        n = n * r + d;
        nodig = 0;
    }
    M2C_FIELD(ctx, int **, 0x18)++;
    if (nodig)
        return 0x1C;
    if (sign < 0 && n == 0)
        return 0x10;
    return mes_number_alloc(ctx, n * sign);
}

int mes_eval_parse_float(EvCtx *ctx, int v)
{
    int s = mes_eval_to_string(ctx, v);
    int r;

    *--M2C_FIELD(ctx, int **, 0x18) = s;
    r = mes_number_from_string(ctx, s, 1, 0);
    M2C_FIELD(ctx, int **, 0x18)++;
    return r;
}

int mes_eval_is_nan(EvCtx *ctx, int v)
{
    return mes_eval_to_number(ctx, v) == 0x1C ? 12 : 8;
}

int mes_eval_is_finite(EvCtx *ctx, int v)
{
    int n = mes_eval_to_number(ctx, v);

    if (n == 0x10 || (n & 3) == 1 || (n & 3) == 2)
        return 12;
    return 8;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mes_eval_hex(void *arg0) {
    int temp_s1;
    int temp_v0;
    int var_a0;

    temp_s1 = mes_util_hex(M2C_FIELD(arg0, unsigned short *, 0));
    temp_v0 = mes_util_hex(M2C_FIELD(arg0, unsigned short *, 2));
    var_a0 = -1;
    if ((temp_v0 | temp_s1) >= 0) {
        var_a0 = (temp_s1 * 0x10) + temp_v0;
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_decode);

int mes_eval_decode_uri(EvCtx *ctx, int v)
{
    int s;
    void *buf;

    s = mes_eval_to_string(ctx, v);
    *--ctx->sp = s;
    buf = mes_util_string_new();
    if (mes_eval_decode(buf, ((EvStr *)(s & ~3))->str, ((EvStr *)(s & ~3))->len, ";/?:@&=+$,#"))
        ctx->error = mes_error_uri(ctx, s);
    ctx->sp++;
    s = mes_string_new3(ctx, buf);
    mes_util_string_free(buf);
    return s;
}

int mes_eval_decode_uri_component(EvCtx *ctx, int v)
{
    int s;
    void *buf;

    s = mes_eval_to_string(ctx, v);
    *--ctx->sp = s;
    buf = mes_util_string_new();
    if (mes_eval_decode(buf, ((EvStr *)(s & ~3))->str, ((EvStr *)(s & ~3))->len, NULL))
        ctx->error = mes_error_uri(ctx, s);
    ctx->sp++;
    s = mes_string_new3(ctx, buf);
    mes_util_string_free(buf);
    return s;
}

void mes_eval_url_hex(void *buf, int c)
{
    mes_util_string_put(buf, '%');
    mes_util_string_put(buf, mes_util_hex_char((c >> 4) & 0xF));
    mes_util_string_put(buf, mes_util_hex_char(c & 0xF));
}

int mes_eval_encode(void *buf, unsigned short *s, int len, const char *set)
{
    int c;
    int c2;

    while (len-- > 0) {
        c = *s++;
        if (mes_util_is_alpha_digit(c) || mes_util_char_in(c, set)) {
            mes_util_string_put(buf, c);
            continue;
        }
        if ((unsigned int)(c - 0xDC00) < 0x400) {
            return 1;
        }
        if ((unsigned int)(c - 0xD800) < 0x400) {
            if (len <= 0) {
                return 1;
            }
            c2 = *s++;
            len--;
            if ((unsigned int)(c2 - 0xDC00) >= 0x400) {
                return 1;
            }
            c = ((c & 0x3FF) << 10) + (c2 & 0x3FF) + 0x10000;
        }
        if (c < 0x80) {
            mes_eval_url_hex(buf, c);
        } else if (c < 0x800) {
            mes_eval_url_hex(buf, ((c >> 6) & 0x1F) | 0xC0);
            mes_eval_url_hex(buf, (c & 0x3F) | 0x80);
        } else if (c > 0xFFFF) {
            mes_eval_url_hex(buf, ((c >> 18) & 0x7) | 0xF0);
            mes_eval_url_hex(buf, ((c >> 12) & 0x3F) | 0x80);
            mes_eval_url_hex(buf, ((c >> 6) & 0x3F) | 0x80);
            mes_eval_url_hex(buf, (c & 0x3F) | 0x80);
        } else {
            mes_eval_url_hex(buf, ((c >> 12) & 0xF) | 0xE0);
            mes_eval_url_hex(buf, ((c >> 6) & 0x3F) | 0x80);
            mes_eval_url_hex(buf, (c & 0x3F) | 0x80);
        }
    }
    return 0;
}

int mes_eval_encode_uri(EvCtx *ctx, int v)
{
    int s;
    void *buf;

    s = mes_eval_to_string(ctx, v);
    *--ctx->sp = s;
    buf = mes_util_string_new();
    if (mes_eval_encode(buf, ((EvStr *)(s & ~3))->str, ((EvStr *)(s & ~3))->len, ";/?:@&=+$,-_.!~*'()#"))
        ctx->error = mes_error_uri(ctx, s);
    ctx->sp++;
    s = mes_string_new3(ctx, buf);
    mes_util_string_free(buf);
    return s;
}

int mes_eval_encode_uri_component(EvCtx *ctx, int v)
{
    int s;
    void *buf;

    s = mes_eval_to_string(ctx, v);
    *--ctx->sp = s;
    buf = mes_util_string_new();
    if (mes_eval_encode(buf, ((EvStr *)(s & ~3))->str, ((EvStr *)(s & ~3))->len, "-_.!~*'()"))
        ctx->error = mes_error_uri(ctx, s);
    ctx->sp++;
    s = mes_string_new3(ctx, buf);
    mes_util_string_free(buf);
    return s;
}

int mes_eval_escape(EvCtx *ctx, int v)
{
    int s;
    void *buf;
    unsigned short *p;
    unsigned short *end;
    unsigned short c;

    s = mes_eval_to_string(ctx, v);
    *--ctx->sp = s;
    p = ((EvStr *)(s & ~3))->str;
    end = p + ((EvStr *)(s & ~3))->len;
    buf = mes_util_string_new();
    while (p < end) {
        c = *p++;
        if (((unsigned int)(c - 'A') < 26) | ((unsigned int)(c - 'a') < 26) || (unsigned int)(c - '0') < 10 || mes_util_char_in(c, "@*_+-./")) {
            mes_util_string_put(buf, c);
        } else if (c < 0x100) {
            mes_util_string_put(buf, '%');
            mes_util_string_put(buf, mes_util_hex_char((c >> 4) & 0xF));
            mes_util_string_put(buf, mes_util_hex_char(c & 0xF));
        } else {
            mes_util_string_put(buf, '%');
            mes_util_string_put(buf, 'u');
            mes_util_string_put(buf, mes_util_hex_char(c >> 12));
            mes_util_string_put(buf, mes_util_hex_char((c >> 8) & 0xF));
            mes_util_string_put(buf, mes_util_hex_char((c >> 4) & 0xF));
            mes_util_string_put(buf, mes_util_hex_char(c & 0xF));
        }
    }
    ctx->sp++;
    s = mes_string_new3(ctx, buf);
    mes_util_string_free(buf);
    return s;
}

int mes_eval_unescape(EvCtx *ctx, int v)
{
    int s;
    void *buf;
    unsigned short *p;
    unsigned short *end;
    unsigned short *save;
    unsigned short c;
    int n;
    int h;

    s = mes_eval_to_string(ctx, v);
    *--ctx->sp = s;
    p = ((EvStr *)(s & ~3))->str;
    end = p + ((EvStr *)(s & ~3))->len;
    buf = mes_util_string_new();
    while (p < end) {
        c = *p++;
        if (c == '%') {
            save = p;
            if (p < end && *p == 'u') {
                p++;
                n = 4;
            } else {
                n = 2;
            }
            c = 0;
            while ((p < end) & (n > 0) && (h = mes_util_hex(*p)) >= 0) {
                c = c * 16 + h;
                p++;
                n--;
            }
            if (n > 0) {
                p = save;
                c = '%';
            }
        }
        mes_util_string_put(buf, c);
    }
    ctx->sp++;
    s = mes_string_new3(ctx, buf);
    mes_util_string_free(buf);
    return s;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_eval_mark(void *arg0) {
    mes_object_mark(arg0);
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x18));
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x1C));
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x20));
    mes_util_vals_mark(M2C_FIELD(arg0, int *, 0x24));
    mes_util_vals_mark(M2C_FIELD(arg0, int *, 0x28));
    mes_util_vals_mark(M2C_FIELD(arg0, int *, 0x2C));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_eval_free(void *arg0) {
    mes_util_vals_free(M2C_FIELD(arg0, int *, 0x24));
    mes_util_vals_free(M2C_FIELD(arg0, int *, 0x28));
    mes_util_vals_free(M2C_FIELD(arg0, int *, 0x2C));
    mes_object_free(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_eval_initialize(void) {
    mes_gc_register(&mes_eval_method, 0x30, 0x64, 0x64);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_eval_global_setup(void *arg0) {
    mes_object_set(M2C_FIELD(arg0, int *, 0xC), D_00585320, 0, 6);
    mes_native_setup(arg0, M2C_FIELD(arg0, int *, 0xC), &mes_eval_native_table, 0xB);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B708);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B710);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B71C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B728);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B73C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B748);
