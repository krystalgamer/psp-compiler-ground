/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
extern MesObject *mes_classes[];
typedef struct StrChunk {
    struct StrChunk *next;
    unsigned short data[100];         /* 0x4 */
} StrChunk;
typedef struct StrUBuf {
    StrChunk *head;
    char pad4[0x10];
    int len;                          /* 0x14 */
} StrUBuf;
MesValue mes_number_alloc_int32(MesContext *ctx, int n);
MesValue mes_number_alloc_uint32(MesContext *ctx, unsigned int n);
unsigned int mes_eval_to_uint32(MesContext *ctx, MesValue v);
MesValue mes_eval_to_integer(MesContext *ctx, MesValue v);
int mes_eval_to_int32(MesContext *ctx, MesValue v);
void *mes_util_string_new(void);
void mes_util_string_put_string(void *s, MesValue v);
void mes_util_string_free(void *s);
MesValue mes_string_new3(MesContext *ctx, void *s);
unsigned short mes_util_to_lower(unsigned short c);
unsigned short mes_util_to_upper(unsigned short c);
extern unsigned int mes_ids[];
extern void *mes_string_table;
MesValue mes_string_constructor(MesContext *ctx, MesValue v);
MesValue mes_string_from_char_code(MesContext *ctx);
void *mes_native_new(MesContext *ctx, int a, void *fn, int nargs, int flags);
void mes_native_setup(MesContext *ctx, MesObject *o, void *table, int n);
void mes_object_set(MesObject *obj, unsigned int id, MesValue value, int flags);
typedef unsigned short UCSChar;
typedef struct MesStr {
    UCSChar *str;
    int len;
} MesStr;
typedef struct StrBuf {
    UCSChar *p;
    UCSChar *end;
} StrBuf;
extern MesValue mes_empty;
void *mes_gc_alloc(MesContext *ctx, int kind);
void mes_memory_copy(const void *src, void *dst, int n);
MesValue mes_eval_type_error(MesContext *ctx, ...);

void mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_string_method;


int mes_util_streq(const UCSChar *a, const UCSChar *b, int n);
MesValue mes_eval_to_number(MesContext *ctx, MesValue v);
MesValue mes_regexp_constructor(MesContext *ctx, MesValue pattern, MesValue flags);
void *mes_regexp_pattern_exec(MesContext *ctx, MesValue re, MesValue s, int i);
typedef struct SplArray { MesObject obj; unsigned int length; } SplArray;
typedef struct SplCap { int gc; int n; MesValue *vals; } SplCap;
typedef struct SplState { int gc; int end; int cap; } SplState;
SplArray *mes_array_new(MesContext *ctx, unsigned int len);
void mes_array_set(MesContext *ctx, SplArray *a, MesValue v);
typedef struct RepRx { int gc; char pad4[0x1C]; double lastIndex; int ncap; unsigned char global; } RepRx;
typedef struct RepState { int gc; int end; void *cap; } RepState;
void mes_util_string_put(void *s, unsigned short c);
MesValue mes_string_replace_sub(MesContext *ctx, MesValue repl, int isfunc, MesValue matched, void *m, int pos, MesValue str, MesValue thisv);
MesValue mes_string_new(MesContext *ctx, const void *str, int len)
{
    MesStr *s;
    UCSChar *d;

    if (len == 0 && mes_empty != 0)
        return mes_empty;
    s = mes_gc_alloc(ctx, 1);
    if (s == NULL)
        return 0;
    s->len = len;
    if (len > 0) {
        len *= 2;
        d = s->str = MEM_malloc(0, len);
        if (d == NULL)
            return 0;
        if (str != NULL)
            mes_memory_copy(str, d, len);
        return (MesValue)s | 3;
    }
    s->str = NULL;
    return (MesValue)s | 3;
}

MesValue mes_string_new2(MesContext *ctx, const char *str, int len)
{
    MesStr *s;
    const char *p;
    UCSChar *d;
    MesValue r;

    if (str != NULL && len == 0) {
        p = str;
        while (*p++ != 0)
            len++;
    }
    if (len == 0 && (r = mes_empty) != 0)
        return r;
    s = mes_gc_alloc(ctx, 1);
    if (s == NULL)
        return 0;
    s->len = len;
    if (len > 0) {
        d = s->str = MEM_malloc(0, len * 2);
        if (d == NULL)
            return 0;
        do {
            *d++ = *str++;
            len--;
        } while (len > 0);
    } else
        s->str = NULL;
    return (MesValue)s | 3;
}

MesValue mes_string_new3(MesContext *ctx, void *b)
{
    StrUBuf *buf = b;
    MesStr *s;
    int n, k;
    UCSChar *p;
    StrChunk *c;

    if (buf == NULL)
        return 0;
    if (buf->len == 0 && mes_empty != 0)
        return mes_empty;
    s = mes_gc_alloc(ctx, 1);
    if (s == NULL)
        return 0;
    n = buf->len;
    s->len = n;
    if (n > 0) {
        p = MEM_malloc(0, n * 2);
        s->str = p;
        if (p == NULL)
            return 0;
        for (c = buf->head; n > 0; c = c->next) {
            k = n;
            if (k > 100)
                k = 100;
            mes_memory_copy(c->data, p, k * 2);
            p += k;
            n -= k;
        }
    } else
        s->str = NULL;
    return (MesValue)s | 3;
}

int mes_string_compare(MesStr *a, MesStr *b)
{
    int n = a->len;
    UCSChar *p, *q;
    int d;

    if ((unsigned int)b->len < (unsigned int)n)
        n = b->len;
    p = a->str;
    q = b->str;
    for (; n > 0; n--, p++, q++) {
        d = *p - *q;
        if (d != 0)
            return d;
    }
    return a->len - b->len;
}

MesValue mes_string_add(MesContext *ctx, MesValue a, MesValue b)
{
    MesStr *r;
    MesStr *sa;
    int la;
    int lb;
    UCSChar *d;

    a = mes_eval_to_string(ctx, a);
    *--ctx->sp = a;
    b = mes_eval_to_string(ctx, b);
    *--ctx->sp = b;
    r = NULL;
    if ((a & 3) == 3 && (b & 3) == 3) {
        r = mes_gc_alloc(ctx, 1);
        if (r != NULL) {
            sa = (MesStr *)(a & ~3);
            la = sa->len;
            lb = ((MesStr *)(b & ~3))->len;
            r->len = la + lb;
            if (la + lb != 0) {
                r->str = MEM_malloc(0, (la + lb) * sizeof(UCSChar));
                d = r->str;
                if (d != NULL) {
                    if (la > 0) {
                        mes_memory_copy(sa->str, d, la * sizeof(UCSChar));
                        d += la;
                    }
                    if (lb > 0)
                        mes_memory_copy(((MesStr *)(b & ~3))->str, d, lb * sizeof(UCSChar));
                } else
                    r = NULL;
            } else
                r->str = NULL;
        } else
            ctx->f14 = (*(MesValue *)((char *)&mes_ids + 0x70));
    }
    ctx->sp += 2;
    if (r != NULL)
        return (MesValue)r | 3;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mes_string_equal(MesStr *a, MesStr *b)
{
    int r = 0;

    if (a->len == b->len && mes_string_compare(a, b) == 0)
        r = 1;
    return r;
}

int mes_string_buf_getc(StrBuf *b)
{
    if (b->p < b->end)
        return *b->p++;
    return -1;
}

void mes_string_free(MesValue v)
{
    MesStr *s = (MesStr *)(v & ~3);

    if (s->str != NULL)
        MEM_free(0, s->str);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_string_initialize(void) {
    mes_gc_register(&mes_string_method, 8, 0x64, 0x64);
}

MesValue mes_string_constructor(MesContext *ctx, MesValue v)
{
    MesArgs *a = ctx->frame->args;
    MesValue s;
    MesObject *o;

    if (a != NULL && a->argc != 0)
        s = mes_eval_to_string(ctx, v);
    else
        s = mes_empty;
    if (ctx->frame->construct) {
        *--ctx->sp = s;
        o = mes_object_new(ctx, 13, (*(MesObject * *)((char *)mes_classes + 0x34)));
        ctx->sp++;
        o->fC = s;
        mes_object_set(o, mes_ids[51], MES_INT(((MesStr *)(s & ~3))->len), 7);
        return (MesValue)o;
    }
    return s;
}

MesValue mes_string_from_char_code(MesContext *ctx)
{
    MesArgs *a = ctx->frame->args;
    MesValue s;
    UCSChar *p;
    unsigned int i;

    if (a == NULL)
        return mes_empty;
    s = mes_string_new(ctx, NULL, a->argc);
    p = ((MesStr *)(s & ~3))->str;
    *--ctx->sp = s;
    for (i = 0; i < a->argc; i++)
        *p++ = mes_eval_to_uint32(ctx, a->argv[i]);
    ctx->sp++;
    return s;
}

MesValue mes_string_value_of(MesContext *ctx)
{
    MesValue v = (MesValue)ctx->frame->thisobj;

    if (MES_IS_OBJECT(v))
        v = ((MesObject *)v)->fC;
    if ((v & 3) != 3)
        return mes_eval_type_error(ctx, v);
    return v;
}

MesValue mes_string_char_at(MesContext *ctx, MesValue pos)
{
    MesValue s = mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj);
    int i;

    *--ctx->sp = s;
    i = mes_eval_to_int32(ctx, pos);
    if (i < 0 || (unsigned int)i >= ((MesStr *)(s & ~3))->len)
        s = mes_empty;
    else
        s = mes_string_new(ctx, ((MesStr *)(s & ~3))->str + i, 1);
    ctx->sp++;
    return s;
}

MesValue mes_string_char_code_at(MesContext *ctx, MesValue pos)
{
    MesValue s = mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj);
    MesValue r = 0x1C;
    MesValue n;
    int i;

    *--ctx->sp = s;
    n = mes_eval_to_integer(ctx, pos);
    if (n != 0x1C && n != 0x14 && n != 0x18) {
        *--ctx->sp = n;
        i = mes_eval_to_int32(ctx, n);
        if (i >= 0 && (unsigned int)i < ((MesStr *)(s & ~3))->len)
            r = mes_number_alloc_uint32(ctx, ((MesStr *)(s & ~3))->str[i]);
        ctx->sp++;
    }
    ctx->sp++;
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_concat);

MesValue mes_string_index_of(MesContext *ctx, MesValue search)
{
    MesArgs *args = ctx->frame->args;
    MesValue s;
    MesValue p;
    int slen;
    UCSChar *sstr;
    int plen;
    UCSChar *pstr;
    int pos;

    s = mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj);
    slen = ((MesStr *)(s & ~3))->len;
    sstr = ((MesStr *)(s & ~3))->str;
    *--ctx->sp = s;
    p = mes_eval_to_string(ctx, search);
    plen = ((MesStr *)(p & ~3))->len;
    pstr = ((MesStr *)(p & ~3))->str;
    *--ctx->sp = p;
    if (args == NULL || (unsigned int)args->argc < 2)
        pos = 0;
    else {
        pos = mes_eval_to_int32(ctx, args->argv[1]);
        if (pos >= 0) {
            if (pos > slen)
                pos = slen;
        } else
            pos = 0;
    }
    ctx->sp += 2;
    for (; pos + plen <= slen; pos++)
        if (mes_util_streq(sstr + pos, pstr, plen))
            break;
    if (pos + plen <= slen)
        return mes_number_alloc_int32(ctx, pos);
    return mes_number_alloc_int32(ctx, -1);
}

MesValue mes_string_last_index_of(MesContext *ctx, MesValue search)
{
    MesArgs *args = ctx->frame->args;
    MesValue s;
    MesValue p;
    MesValue n;
    int slen;
    UCSChar *sstr;
    int plen;
    UCSChar *pstr;
    int pos;

    s = mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj);
    slen = ((MesStr *)(s & ~3))->len;
    sstr = ((MesStr *)(s & ~3))->str;
    *--ctx->sp = s;
    p = mes_eval_to_string(ctx, search);
    plen = ((MesStr *)(p & ~3))->len;
    pstr = ((MesStr *)(p & ~3))->str;
    *--ctx->sp = p;
    if (args != NULL && (unsigned int)args->argc >= 2) {
        n = mes_eval_to_number(ctx, args->argv[1]);
        if (n == 0x1C || n == 0x14)
            pos = slen - plen;
        else if (n == 0x10 || n == 0x18)
            pos = 0;
        else if ((n & 3) == 1)
            pos = n >> 2;
        else if ((n & 3) == 2)
            pos = mes_eval_to_int32(ctx, n);
        else
            pos = slen - plen;
        if (pos < 0)
            pos = 0;
        else if (pos > slen - plen)
            pos = slen - plen;
    } else
        pos = slen - plen;
    ctx->sp += 2;
    for (; pos >= 0; pos--)
        if (mes_util_streq(sstr + pos, pstr, plen))
            break;
    return mes_number_alloc_int32(ctx, pos);
}

MesValue mes_string_locale_compare(MesContext *ctx, MesValue that)
{
    MesValue s;

    if (ctx->frame->args == NULL)
        return 1;
    s = mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj);
    *--ctx->sp = s;
    that = mes_eval_to_string(ctx, that);
    ctx->sp++;
    return mes_number_alloc_int32(ctx, mes_string_compare((MesStr *)(s & ~3), (MesStr *)(that & ~3)));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_match);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_replace_sub);

MesValue mes_string_replace(MesContext *ctx, MesValue re, MesValue repl)
{
    int isfunc;
    int isre;
    UCSChar *str;
    MesValue s;
    int len;
    int i;
    void *buf;
    MesValue st;
    MesValue r;

    s = mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj);
    str = ((MesStr *)(s & ~3))->str;
    len = ((MesStr *)(s & ~3))->len;
    *--ctx->sp = s;
    if (MES_IS_OBJECT(repl) && (((MesObject *)repl)->gc->kind == 3 || ((MesObject *)repl)->gc->kind == 4))
        isfunc = 1;
    else {
        isfunc = 0;
        repl = mes_eval_to_string(ctx, repl);
    }
    *--ctx->sp = repl;
    if (MES_IS_OBJECT(re) && ((MesObject *)re)->gc->kind == 8)
        isre = 1;
    else {
        isre = 0;
        re = mes_eval_to_string(ctx, re);
    }
    *--ctx->sp = re;
    i = 0;
    if (isre)
        i = ((RepRx *)re)->lastIndex;
    buf = mes_util_string_new();
    while (i <= len) {
        st = (MesValue)mes_regexp_pattern_exec(ctx, re, s, i);
        if (st != 0) {
            *--ctx->sp = st;
            r = mes_string_new(ctx, str + i, ((RepState *)st)->end - i);
            *--ctx->sp = r;
            mes_util_string_put_string(buf, mes_string_replace_sub(ctx, repl, isfunc, r, ((RepState *)st)->cap, i, s, (MesValue)ctx->frame->thisobj));
            if ((((RepState *)st)->end == i) & (i < len)) {
                mes_util_string_put(buf, str[i++]);
            } else
                i = ((RepState *)st)->end;
            ctx->sp += 2;
            if (!isre || !((RepRx *)re)->global)
                break;
            ((RepRx *)re)->lastIndex = ((RepState *)st)->end;
        } else {
            if (i < len)
                mes_util_string_put(buf, str[i]);
            i++;
        }
    }
    while (i < len)
        mes_util_string_put(buf, str[i++]);
    if (isre && ((RepRx *)re)->global)
        ((RepRx *)re)->lastIndex = 0;
    ctx->sp += 3;
    r = mes_string_new3(ctx, buf);
    mes_util_string_free(buf);
    return r;
}

MesValue mes_string_search(MesContext *ctx, MesValue re)
{
    MesValue s;
    int len;
    int i;

    if (!MES_IS_OBJECT(re) || ((MesObject *)re)->gc->kind != 8)
        re = mes_regexp_constructor(ctx, re, 0);
    *--ctx->sp = re;
    s = mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj);
    *--ctx->sp = s;
    len = ((MesStr *)(s & ~3))->len;
    for (i = 0; i <= len; i++) {
        if (mes_regexp_pattern_exec(ctx, re, s, i) != NULL)
            break;
    }
    ctx->sp += 2;
    if (i <= len)
        return MES_INT(i);
    return -3;
}

MesValue mes_string_slice(MesContext *ctx, MesValue a, MesValue b)
{
    MesStr *s = (MesStr *)(mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj) & ~3);
    int len = s->len;
    UCSChar *str = s->str;
    int start, end;

    start = mes_eval_to_int32(ctx, a);
    if (start < 0) {
        start += len;
        if (start < 0)
            start = 0;
    } else
        start = len < start ? len : start;
    end = len;
    if (b != 0) {
        end = mes_eval_to_int32(ctx, b);
        if (end < 0) {
            end += len;
            if (end < 0)
                end = 0;
        } else
            end = len < end ? len : end;
    }
    if (start >= end)
        return mes_empty;
    return mes_string_new(ctx, str + start, end - start);
}

MesValue mes_string_split(MesContext *ctx, MesValue sep, MesValue limit)
{
    unsigned int lim;
    UCSChar *str;
    MesValue s;
    SplArray *arr;
    int len;
    int p;
    int i;
    SplState *st;
    int cap;
    int j;

    s = mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj);
    *--ctx->sp = s;
    arr = mes_array_new(ctx, 0);
    *--ctx->sp = (MesValue)arr;
    lim = -1;
    if (limit != 0)
        lim = mes_eval_to_uint32(ctx, limit);
    len = ((MesStr *)(s & ~3))->len;
    str = ((MesStr *)(s & ~3))->str;
    p = 0;
    if (sep != 0 && (!MES_IS_OBJECT(sep) || ((MesObject *)sep)->gc->kind != 8))
        sep = mes_eval_to_string(ctx, sep);
    *--ctx->sp = sep;
    if (lim != 0) {
        if (sep == 0)
            mes_array_set(ctx, arr, s);
        else if (len == 0) {
            if (mes_regexp_pattern_exec(ctx, sep, s, 0) == NULL)
                mes_array_set(ctx, arr, s);
        } else {
            for (i = p; i < len; i++) {
                st = mes_regexp_pattern_exec(ctx, sep, s, i);
                if (st == NULL || st->end <= p)
                    continue;
                *--ctx->sp = (MesValue)st;
                mes_array_set(ctx, arr, mes_string_new(ctx, str + p, i - p));
                ctx->sp++;
                if (arr->length >= lim)
                    break;
                p = st->end;
                cap = st->cap;
                if (cap == 0)
                    continue;
                *--ctx->sp = (MesValue)cap;
                for (j = 0; j < ((SplCap *)cap)->n && arr->length < lim; j++)
                    mes_array_set(ctx, arr, ((SplCap *)cap)->vals[j]);
                ctx->sp++;
                if (arr->length >= lim)
                    break;
            }
            if (i == len)
                mes_array_set(ctx, arr, mes_string_new(ctx, str + p, len - p));
        }
    }
    ctx->sp += 3;
    return (MesValue)arr;
}

MesValue mes_string_substring(MesContext *ctx, MesValue a, MesValue b)
{
    MesValue s = mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj);
    int len;
    UCSChar *str;
    int start, end, n;

    *--ctx->sp = s;
    len = ((MesStr *)(s & ~3))->len;
    str = ((MesStr *)(s & ~3))->str;
    start = len;
    if (a != 0x14) {
        n = mes_eval_to_int32(ctx, a);
        if (n < 0)
            start = 0;
        else
            start = len < n ? len : n;
    }
    end = len;
    if (b != 0) {
        if (b != 0x14) {
            n = mes_eval_to_int32(ctx, b);
            if (n < 0)
                end = 0;
            else
                end = len < n ? len : n;
        }
    }
    if (start < end)
        s = mes_string_new(ctx, str + start, end - start);
    else if (end < start)
        s = mes_string_new(ctx, str + end, start - end);
    else
        s = mes_empty;
    ctx->sp++;
    return s;
}

MesValue mes_string_substr(MesContext *ctx, MesValue a, MesValue b)
{
    MesValue s = mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj);
    int len;
    UCSChar *str;
    int start, n;

    *--ctx->sp = s;
    len = ((MesStr *)(s & ~3))->len;
    str = ((MesStr *)(s & ~3))->str;
    start = len;
    if (a != 0x14)
        start = mes_eval_to_int32(ctx, a);
    n = len;
    if (b != 0) {
        if (b != 0x14)
            n = mes_eval_to_int32(ctx, b);
        n = n < 0 ? 0 : n;
    }
    if (start < 0) {
        start += len;
        start = start < 0 ? 0 : start;
    }
    if (start >= len) {
        s = mes_empty;
        goto out;
    }
    n = len - start < n ? len - start : n;
    s = mes_string_new(ctx, str + start, n);
out:
    ctx->sp++;
    return s;
}

MesValue mes_string_to_lower_case(MesContext *ctx)
{
    MesStr *s = (MesStr *)(mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj) & ~3);
    int len = s->len;
    UCSChar *p = s->str;
    UCSChar *end = p + len;
    UCSChar *buf, *q;
    MesStr *r;

    buf = MEM_malloc(0, len * 2);
    q = buf;
    if (buf == NULL)
        return 0;
    while (p < end)
        *q++ = mes_util_to_lower(*p++);
    r = mes_gc_alloc(ctx, 1);
    if (r == NULL)
        return 0;
    r->len = len;
    r->str = buf;
    return (MesValue)r | 3;
}

MesValue mes_string_to_upper_case(MesContext *ctx)
{
    MesStr *s = (MesStr *)(mes_eval_to_string(ctx, (MesValue)ctx->frame->thisobj) & ~3);
    int len = s->len;
    UCSChar *p = s->str;
    UCSChar *end = p + len;
    UCSChar *buf, *q;
    MesStr *r;

    buf = MEM_malloc(0, len * 2);
    q = buf;
    if (buf == NULL)
        return 0;
    while (p < end)
        *q++ = mes_util_to_upper(*p++);
    r = mes_gc_alloc(ctx, 1);
    if (r == NULL)
        return 0;
    r->len = len;
    r->str = buf;
    return (MesValue)r | 3;
}

void mes_string_setup(MesContext *ctx)
{
    MesObject *proto;
    MesObject *ctor;

    proto = mes_object_new(ctx, 13, mes_classes[9]);
    mes_classes[13] = proto;
    proto->fC = mes_empty;
    mes_object_set(proto, mes_ids[51], MES_INT(0), 7);
    ctor = mes_native_new(ctx, mes_ids[13], mes_string_constructor, 1, 1);
    mes_object_set(ctx->global, mes_ids[13], (MesValue)ctor, 7);
    mes_object_set(ctor, mes_ids[44], (MesValue)mes_native_new(ctx, mes_ids[44], mes_string_from_char_code, 1, 0), 0);
    mes_object_set(ctor, mes_ids[59], (MesValue)proto, 7);
    mes_object_set(proto, mes_ids[40], (MesValue)ctor, 2);
    mes_native_setup(ctx, proto, &mes_string_table, 19);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", D_0013A7C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", D_0013A7C4);
