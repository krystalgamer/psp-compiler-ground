/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
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

M2C_UNK mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_string_method;


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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_new2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_new3);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_add);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_constructor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_from_char_code);

MesValue mes_string_value_of(MesContext *ctx)
{
    MesValue v = (MesValue)ctx->frame->thisobj;

    if (MES_IS_OBJECT(v))
        v = ((MesObject *)v)->fC;
    if ((v & 3) != 3)
        return mes_eval_type_error(ctx, v);
    return v;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_char_at);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_char_code_at);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_concat);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_index_of);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_last_index_of);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_locale_compare);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_match);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_replace_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_replace);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_search);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_slice);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_split);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_substring);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_substr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_to_lower_case);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_to_upper_case);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", mes_string_setup);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", D_0013A7C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_string", D_0013A7C4);
