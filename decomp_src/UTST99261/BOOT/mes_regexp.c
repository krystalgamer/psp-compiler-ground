/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned int D_0058530C, D_005852D0, D_005852D4, D_005852F0;
int mes_number_alloc(void *ctx, double d);
int mes_object_get(void *obj, unsigned int id);
void *mes_util_string_new(void);
void mes_util_string_put(void *s, unsigned short c);
void mes_util_string_put_string(void *s, int v);
void mes_util_string_free(void *s);
int mes_string_new3(void *ctx, void *s);
void *mes_regexp_alternative();
typedef struct RxStr {
    unsigned short *str;
    int len;                          /* 0x4 */
} RxStr;
typedef struct RxObj {
    int gc;
    int f4;
    int f8;
    int fC;
    int f10;
    int source;                       /* 0x14 */
    void *node;                       /* 0x18 */
    int f1C;
    double lastIndex;                 /* 0x20 */
    int ncap;                         /* 0x28 */
    unsigned char global;             /* 0x2C */
    unsigned char icase;              /* 0x2D */
    unsigned char multiline;          /* 0x2E */
} RxObj;
typedef struct RxComp {
    void *ctx;
    RxObj *re;                        /* 0x4 */
    unsigned short *p;                /* 0x8 */
    unsigned short *end;              /* 0xC */
    int len;                          /* 0x10 */
    int ncap;                         /* 0x14 */
} RxComp;
typedef struct RxClosure {
    int gc;
    int type;                         /* 0x4 */
    int *vals;                        /* 0x8 */
} RxClosure;
typedef struct RxCap {
    int gc;
    int n;                            /* 0x4 */
    int *vals;                        /* 0x8 */
} RxCap;
typedef struct RxState {
    int gc;
    int f4;
    unsigned short *str;              /* 0x8 */
    int fC;
    int len;                          /* 0x10 */
} RxState;
extern unsigned int D_005852E0;       /* "lastIndex" */
void *mes_gc_alloc(void *ctx, int kind);
int *mes_util_vals(int n, int a);
int mes_util_is_word_char(unsigned short c);
int mes_util_digit(unsigned short c);
int mes_object_canput(void *obj, unsigned int id);
int mes_eval_to_number(void *ctx, int v);
double mes_num(int v);
void *mes_regexp_disjunction(RxComp *c);
RxClosure *mes_closure_new(void *ctx, int type, int n);
extern unsigned int mes_ids[];
extern void *mes_classes[];
extern unsigned int D_005852B8;
extern int mes_empty;
extern unsigned int mes_regexp_dollar[];
extern void *mes_regexp_table;
int mes_regexp_constructor();
void *mes_object_new(void *ctx, int cls, void *proto);
void *mes_native_new(void *ctx, int a, void *fn, int nargs, int flags);
void mes_native_setup(void *ctx, void *o, void *table, int n);
void mes_object_set(void *obj, unsigned int id, int value, int flags);
unsigned int mes_context_id2(void *ctx, const char *name);
void mes_gc_mark(int);                           /* extern */
void mes_util_vals_mark(int);                    /* extern */
void MEM_free(M2C_UNK, int);                     /* extern */
void mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_cap_method;
extern unsigned char mes_closure_method;
extern unsigned char mes_regexp_method;
extern unsigned char mes_state_method;

void mes_util_vals_free(int);                    /* extern */


int mes_regexp_execute(void *ctx, RxObj *re, int s, int flag);
int mes_eval_object_get(void *ctx, int obj, unsigned int id);
int mes_eval_to_string(void *ctx, int v);
RxState *mes_regexp_pattern_exec(void *ctx, RxObj *re, int s, int i);
extern const double D_0013BFE0;
void *mes_array_new(void *ctx, int n);
int mes_string_new(void *ctx, const void *str, int len);
extern const double D_0013BFD8;
void mes_object_init(void *o, int cls, int proto);
int mes_error_syntax(void *ctx, int s);
extern int D_00585360;
int mes_util_is_line_terminator(unsigned short c);
typedef struct RxVals { int v0; int v1; int v2; } RxVals;
int mes_util_octal(unsigned short c);
int mes_util_hex(unsigned short c);
int mes_util_char_in(unsigned short c, const char *s);
void mes_object_mark(void *arg0);
void *MEM_malloc(void *, unsigned int size);
RxObj *mes_regexp_new(void *ctx, int source, int flags) {
    RxObj *re;
    unsigned short *p;
    int n;

    re = mes_gc_alloc(ctx, 8);
    if (re != NULL) {
        mes_object_init(re, 0xC, D_00585360);
        re->source = source;
        re->node = NULL;
        re->lastIndex = 0;
        re->global = 0;
        re->icase = 0;
        re->multiline = 0;
        re->ncap = 0;
        if ((flags & 3) == 3) {
            p = ((RxStr *)(flags & ~3))->str;
            n = ((RxStr *)(flags & ~3))->len;
            while (n-- > 0) {
                switch (*p++) {
                case 'g':
                    re->global = 1;
                    break;
                case 'i':
                    re->icase = 1;
                    break;
                case 'm':
                    re->multiline = 1;
                    break;
                default:
                    M2C_FIELD(ctx, int *, 0x14) = mes_error_syntax(ctx, flags);
                    break;
                }
            }
        }
    }
    return re;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_regexp_mark(void *arg0) {
    mes_object_mark(arg0);
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x14));
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x18));
}

int mes_regexp_get(void *ctx, RxObj *re, unsigned int id)
{
    int r;

    if (id == D_0058530C) {
        r = re->source;
    } else if (id == D_005852D0) {
        r = re->global ? 12 : 8;
    } else if (id == D_005852D4) {
        r = re->icase ? 12 : 8;
    } else if (id == D_005852F0) {
        r = re->multiline ? 12 : 8;
    } else if (id == D_005852E0) {
        r = mes_number_alloc(ctx, re->lastIndex);
    } else {
        r = mes_object_get(re, id);
    }
    return r;
}

void mes_regexp_put(void *ctx, RxObj *re, unsigned int id, int v)
{
    if (id == D_005852E0)
        re->lastIndex = mes_num(mes_eval_to_number(ctx, v));
    else
        mes_object_set(re, id, v, 8);
}

int mes_regexp_canput(void *ctx, RxObj *re, unsigned int id)
{
    if (id == D_005852E0)
        return 1;
    if (id == mes_ids[61] || id == mes_ids[46] || id == mes_ids[47] || id == mes_ids[54])
        return 0;
    return mes_object_canput(re, id);
}

RxClosure *mes_closure_new(void *ctx, int type, int n)
{
    RxClosure *cl = mes_gc_alloc(ctx, 9);

    if (cl != NULL) {
        cl->type = type;
        if (n == 0)
            cl->vals = NULL;
        else {
            cl->vals = mes_util_vals(n, 0);
            if (cl->vals == NULL)
                return NULL;
        }
    }
    return cl;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_closure_mark(void *arg0) {
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0);
    if (!(temp_v1 & 1)) {
        M2C_FIELD(arg0, int *, 0) = (int) (temp_v1 | 1);
        mes_util_vals_mark(M2C_FIELD(arg0, int *, 8));
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_closure_free(void *arg0) {
    mes_util_vals_free(M2C_FIELD(arg0, int *, 8));
}

RxCap *mes_cap_new(void *ctx, int n, RxCap *src)
{
    RxCap *c;
    int *p;
    int i;

    c = mes_gc_alloc(ctx, 10);
    if (c != NULL) {
        if (src != NULL)
            n = src->n;
        c->n = n;
        if (n > 0) {
            p = MEM_malloc(0, n * 4);
            c->vals = p;
            if (p == NULL)
                return NULL;
            if (src != NULL) {
                for (i = 0; i < n; i++)
                    *p++ = src->vals[i];
                return c;
            } else {
                for (i = 0; i < n; i++)
                    *p++ = 0;
                return c;
            }
        } else {
            c->vals = NULL;
        }
    }
    return c;
}

void mes_cap_mark(RxCap *cap)
{
    int i;
    int *p;

    if (cap->gc & 1)
        return;
    cap->gc |= 1;
    p = cap->vals;
    for (i = 0; i < cap->n; i++)
        mes_gc_mark(*p++);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_cap_free(void *arg0) {
    if (M2C_FIELD(arg0, int *, 4) > 0) {
        MEM_free(0, M2C_FIELD(arg0, int *, 8));
    }
}

void *mes_state_new(void *ctx, int a, int b)
{
    RxClosure *o = mes_gc_alloc(ctx, 11);

    if (o != NULL) {
        o->type = a;
        o->vals = (int *)b;
    }
    return o;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_state_mark(void *arg0) {
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0);
    if (!(temp_v1 & 1)) {
        M2C_FIELD(arg0, int *, 0) = (int) (temp_v1 | 1);
        mes_gc_mark(M2C_FIELD(arg0, int *, 8));
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_regexp_initialize(void) {
    mes_gc_register(&mes_regexp_method, 0x30, 0x10, 0x10);
    mes_gc_register(&mes_closure_method, 0xC, 0x10, 0x10);
    mes_gc_register(&mes_cap_method, 0xC, 0x10, 0x10);
    mes_gc_register(&mes_state_method, 0xC, 0x10, 0x10);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_charset_match);

int mes_regexp_decimal_digits(RxComp *c)
{
    int n = -1;
    int d;

    while (c->p < c->end && (d = mes_util_digit(*c->p)) >= 0) {
        if (n < 0)
            n = 0;
        n = n * 10 + d;
        c->p++;
    }
    return n;
}

RxClosure *mes_regexp_atom(RxComp *c) {
    void *ctx;
    unsigned short *p;
    RxClosure *cl;
    RxClosure *a;
    int n;
    int ch;
    int type;

    ctx = c->ctx;
    p = c->p;
    if (p >= c->end) {
        return NULL;
    }
    ch = *p;
    if (ch == '.') {
        c->p++;
        return mes_closure_new(ctx, 0x14, 0);
    } else if (ch == '\\') {
        p = c->p++;
        if (c->p < c->end && *c->p != '0' && (n = mes_regexp_decimal_digits(c)) > 0) {
            cl = mes_closure_new(ctx, 0x13, 1);
            if (cl != NULL) {
                cl->vals[1] = (n << 2) | 1;
            }
            return cl;
        }
        c->p = p;
        p++;
        if (p < c->end) {
            if (*p == '0') {
                p++;
                if (p < c->end && mes_util_octal(*p) >= 0) {
                    n = *p < '4';
                    n += 2;
                    while (n-- > 0 && p < c->end && mes_util_octal(*p) >= 0) {
                        p++;
                    }
                }
            } else if (*p == 'c') {
                p += 2;
            } else if (*p == 'x') {
                p++;
                for (n = 0; n < 2; n++) {
                    if (p + n >= c->end || mes_util_hex(p[n]) < 0) {
                        break;
                    }
                }
                if (n == 2) {
                    p += 2;
                }
            } else if (*p == 'u') {
                p++;
                for (n = 0; n < 4; n++) {
                    if (p + n >= c->end || mes_util_hex(p[n]) < 0) {
                        break;
                    }
                }
                if (n == 4) {
                    p += 4;
                }
            } else {
                p++;
            }
        }
        if (p > c->end) {
            p = c->end;
        }
        cl = mes_closure_new(ctx, 0x12, 2);
        if (cl != NULL) {
            *--M2C_FIELD(ctx, int **, 0x18) = (int)cl;
            ((RxVals *)cl->vals)->v1 = mes_string_new(ctx, c->p, p - c->p);
            cl->vals[2] = 8;
            M2C_FIELD(ctx, int **, 0x18)++;
        }
        c->p = p;
        return cl;
    } else if (ch == '[') {
        c->p++;
        type = 8;
        if (c->p < c->end && *c->p == '^') {
            c->p++;
            type = 0xC;
        }
        p = c->p;
        while (p < c->end && *p != ']') {
            if (*p == '\\' && p + 1 < c->end) {
                p += 2;
            } else {
                p++;
            }
        }
        cl = mes_closure_new(ctx, 0x12, 2);
        if (cl != NULL) {
            *--M2C_FIELD(ctx, int **, 0x18) = (int)cl;
            ((RxVals *)cl->vals)->v1 = mes_string_new(ctx, c->p, p - c->p);
            cl->vals[2] = type;
            M2C_FIELD(ctx, int **, 0x18)++;
        }
        if (p < c->end) {
            c->p = p + 1;
        } else {
            M2C_FIELD(ctx, int *, 0x14) = mes_error_syntax(ctx, (int)c->re);
            c->p = p;
        }
        return cl;
    } else if (ch == '(') {
        c->p++;
        if (c->p + 1 < c->end && *c->p == '?' && ((ch = c->p[1]) == ':' || ch == '=' || ch == '!')) {
            c->p += 2;
            cl = mes_regexp_disjunction(c);
            if (c->p < c->end && *c->p == ')') {
                c->p++;
            } else {
                M2C_FIELD(ctx, int *, 0x14) = mes_error_syntax(ctx, (int)c->re);
            }
            if (ch == ':') {
                return cl;
            }
            if (ch == '=') {
                *--M2C_FIELD(ctx, int **, 0x18) = (int)cl;
                a = mes_closure_new(ctx, 0xD, 1);
            } else {
                *--M2C_FIELD(ctx, int **, 0x18) = (int)cl;
                a = mes_closure_new(ctx, 0xF, 1);
            }
            if (a != NULL) {
                a->vals[1] = (int)cl;
                cl = a;
            }
            M2C_FIELD(ctx, int **, 0x18)++;
            return cl;
        }
        n = ++c->ncap;
        cl = mes_regexp_disjunction(c);
        if (c->p < c->end && *c->p == ')') {
            c->p++;
        } else {
            M2C_FIELD(ctx, int *, 0x14) = mes_error_syntax(ctx, (int)c->re);
        }
        *--M2C_FIELD(ctx, int **, 0x18) = (int)cl;
        a = mes_closure_new(ctx, 0xB, 2);
        if (a != NULL) {
            a->vals[1] = (int)cl;
            a->vals[2] = (n << 2) | 1;
            cl = a;
        }
        M2C_FIELD(ctx, int **, 0x18)++;
        return cl;
    } else {
        if (p < c->end && !mes_util_char_in(*p, "()|\\.[^$")) {
            p++;
        }
        while (p < c->end && !mes_util_char_in(*p, "*+?{()|\\.[^$")) {
            p++;
        }
        if (c->p < p) {
            if (c->p + 1 < p && p < c->end && mes_util_char_in(*p, "*+?{")) {
                p--;
            }
            cl = mes_closure_new(ctx, 0x11, 1);
            if (cl != NULL) {
                *--M2C_FIELD(ctx, int **, 0x18) = (int)cl;
                ((RxVals *)cl->vals)->v1 = mes_string_new(ctx, c->p, p - c->p);
                M2C_FIELD(ctx, int **, 0x18)++;
            }
            c->p = p;
            return cl;
        }
        return NULL;
    }
}

int mes_regexp_is_word_char(RxState *s, int i)
{
    if (i < 0 || i == s->len)
        return 0;
    return mes_util_is_word_char(s->str[i]);
}

int mes_regexp_assertion_tester(RxState *st, unsigned short ch, RxState *x)
{
    int i = x->f4;
    int r;
    int a, b;

    switch (ch) {
    case '^':
        r = 0;
        if (i == 0 || (M2C_FIELD(st, RxObj **, 4)->multiline && mes_util_is_line_terminator(st->str[i - 1])))
            r = 1;
        return r;
    case '$':
        r = 0;
        if (i == st->len || (M2C_FIELD(st, RxObj **, 4)->multiline && mes_util_is_line_terminator(st->str[i])))
            r = 1;
        return r;
    case 'b':
        a = mes_regexp_is_word_char(st, i - 1);
        b = mes_regexp_is_word_char(st, i);
        return (a && !b) || (!a && b);
    case 'B':
        a = mes_regexp_is_word_char(st, i - 1);
        b = mes_regexp_is_word_char(st, i);
        return (!a || b) && (a || !b);
    }
    return 0;
}

RxClosure *mes_regexp_assertion(RxComp *c, unsigned short ch)
{
    RxClosure *cl = mes_closure_new(c->ctx, 10, 1);

    if (cl != NULL)
        cl->vals[1] = (ch << 2) | 1;
    return cl;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_term);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_alternative);

void *mes_regexp_disjunction(RxComp *c)
{
    void *ctx = c->ctx;
    void *a = mes_regexp_alternative(c);
    void *b;
    RxClosure *cl;

    if (c->p < c->end && *c->p == '|') {
        c->p++;
        *--M2C_FIELD(ctx, int **, 0x18) = (int)a;
        b = mes_regexp_disjunction(c);
        *--M2C_FIELD(ctx, int **, 0x18) = (int)b;
        cl = mes_closure_new(ctx, 2, 2);
        M2C_FIELD(ctx, int **, 0x18) += 2;
        if (cl != NULL) {
            cl->vals[1] = (int)a;
            cl->vals[2] = (int)b;
        }
        return cl;
    }
    return a;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_eval);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_pattern_exec);

void mes_regexp_compile(void *ctx, RxObj *re)
{
    RxComp c;
    RxStr *s;

    c.ctx = ctx;
    c.re = re;
    s = (RxStr *)(re->source & ~3);
    c.p = s->str;
    c.len = s->len;
    c.end = c.p + c.len;
    c.ncap = 0;
    re->node = mes_regexp_disjunction(&c);
    re->ncap = c.ncap;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_constructor);

int mes_regexp_execute(void *ctx, RxObj *re, int s, int array) {
    int len;
    int i;
    int j;
    RxState *st;
    void *arr;

    len = ((RxStr *)(s & ~3))->len;
    i = 0;
    if (re->global) {
        if (re->lastIndex > D_0013BFD8)
            i = 0x7FFFFFFF;
        else
            i = re->lastIndex;
    }
    for (; i >= 0 && i <= len; i++) {
        st = mes_regexp_pattern_exec(ctx, re, s, i);
        if (st != NULL) {
            if (re->global)
                re->lastIndex = st->f4;
            *--M2C_FIELD(ctx, int **, 0x18) = (int)st;
            if (array) {
                arr = mes_array_new(ctx, re->ncap + 1);
                if (arr != NULL) {
                    *--M2C_FIELD(ctx, int **, 0x18) = (int)arr;
                    mes_object_set(arr, mes_ids[0xC0 / 4], (i << 2) | 1, 8);
                    mes_object_set(arr, mes_ids[0xC4 / 4], s, 8);
                    mes_object_set(arr, 1, mes_string_new(ctx, ((RxStr *)(s & ~3))->str + i, st->f4 - i), 8);
                    st = M2C_FIELD(st, RxState **, 8);
                    if (st != NULL) {
                        for (j = 0; j < ((RxCap *)st)->n; j++)
                            mes_object_set(arr, ((j + 1) << 2) | 1, ((RxCap *)st)->vals[j], 8);
                    }
                    M2C_FIELD(ctx, int **, 0x18)++;
                }
            } else
                arr = (void *)mes_string_new(ctx, ((RxStr *)(s & ~3))->str + i, st->f4 - i);
            M2C_FIELD(ctx, int **, 0x18)++;
            return (int)arr;
        }
    }
    re->lastIndex = 0;
    return 0;
}

int mes_regexp_exec(void *ctx, int v) {
    void *re;
    int *args;
    int s;
    int r;

    re = M2C_FIELD(M2C_FIELD(ctx, void **, 0x10), void **, 0x1C);
    args = M2C_FIELD(M2C_FIELD(ctx, void **, 0x10), int **, 0x24);
    if (args == NULL || *args == 0) {
        s = mes_eval_object_get(ctx, mes_eval_object_get(ctx, M2C_FIELD(ctx, int *, 0xC), mes_ids[0x30 / 4]), mes_ids[0xC4 / 4]);
        if (s != 0x20)
            v = s;
    }
    v = mes_eval_to_string(ctx, v);
    *--M2C_FIELD(ctx, int **, 0x18) = v;
    r = mes_regexp_execute(ctx, re, v, 1);
    if (r == 0)
        r = 4;
    M2C_FIELD(ctx, int **, 0x18)++;
    return r;
}

int mes_regexp_test(void *ctx, int v) {
    RxObj *re;
    int *args;
    int s;
    int len;
    int i;
    RxState *st;

    re = M2C_FIELD(M2C_FIELD(ctx, void **, 0x10), RxObj **, 0x1C);
    args = M2C_FIELD(M2C_FIELD(ctx, void **, 0x10), int **, 0x24);
    if (args == NULL || *args == 0) {
        s = mes_eval_object_get(ctx, mes_eval_object_get(ctx, M2C_FIELD(ctx, int *, 0xC), mes_ids[0x30 / 4]), mes_ids[0xC4 / 4]);
        if (s != 0x20)
            v = s;
    }
    v = mes_eval_to_string(ctx, v);
    *--M2C_FIELD(ctx, int **, 0x18) = v;
    len = ((RxStr *)(v & ~3))->len;
    i = 0;
    if (re->global) {
        if (re->lastIndex > D_0013BFE0)
            i = 0x7FFFFFFF;
        else
            i = re->lastIndex;
    }
    for (; i >= 0 && i <= len; i++) {
        st = mes_regexp_pattern_exec(ctx, re, v, i);
        if (st != NULL) {
            if (re->global)
                re->lastIndex = st->f4;
            M2C_FIELD(ctx, int **, 0x18)++;
            return 12;
        }
    }
    re->lastIndex = 0;
    M2C_FIELD(ctx, int **, 0x18)++;
    return 8;
}

int mes_regexp_to_string(void *ctx)
{
    RxObj *re = (RxObj *)M2C_FIELD(M2C_FIELD(ctx, void **, 0x10), void **, 0x1C);
    void *s = mes_util_string_new();

    mes_util_string_put(s, '/');
    mes_util_string_put_string(s, re->source);
    mes_util_string_put(s, '/');
    if (re->global)
        mes_util_string_put(s, 'g');
    if (re->icase)
        mes_util_string_put(s, 'i');
    if (re->multiline)
        mes_util_string_put(s, 'm');
    re = (RxObj *)mes_string_new3(ctx, s);
    mes_util_string_free(s);
    return (int)re;
}

void mes_regexp_setup(void *ctx)
{
    void *proto;
    void *ctor;
    char buf[3];
    int i;
    unsigned int id;

    proto = mes_object_new(ctx, 9, mes_classes[9]);
    mes_classes[12] = proto;
    ctor = mes_native_new(ctx, mes_ids[12], mes_regexp_constructor, 2, 1);
    mes_object_set(*(void **)((char *)ctx + 0xC), mes_ids[12], (int)ctor, 7);
    mes_object_set(ctor, mes_ids[59], (int)proto, 7);
    buf[0] = '$';
    buf[2] = 0;
    for (i = 1; i < 10; i++) {
        buf[1] = '0' + i;
        id = mes_context_id2(ctx, buf);
        mes_regexp_dollar[i - 1] = id;
        mes_object_set(ctor, id, mes_empty, 0);
    }
    mes_object_set(proto, D_005852B8, (int)ctor, 2);
    mes_native_setup(ctx, proto, &mes_regexp_table, 3);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C000);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C008);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C014);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C020);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C030);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C038);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C040);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C048);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C054);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C064);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C06C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C074);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C080);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C08C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C098);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C108);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C10C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C120);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C128);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C130);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C13C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C148);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C150);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C158);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C160);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C168);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C174);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C180);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C188);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C190);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C200);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C208);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C210);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C218);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C224);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C22C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C234);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C23C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C24C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C258);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C260);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C26C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C274);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C280);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C284);
