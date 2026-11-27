/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern const double D_0013A450;
void mes_memory_copy(const void *src, void *dst, int n);
typedef unsigned short UCSChar;

typedef struct UStr {
    UCSChar *str;
    int len;
} UStr;

typedef struct UChunk {
    struct UChunk *next;
    UCSChar data[100];
} UChunk;

typedef struct UString {
    UChunk *head;
    UChunk *f4;
    UChunk *cur;
    int cap;
    int base;
    int len;
} UString;

int mes_util_string_pos(UString *s, int pos);
UCSChar mes_util_to_lower(UCSChar c);

typedef struct UVals {
    unsigned int n;
    int v[1];
} UVals;

int mes_util_is_white_space(UCSChar c);
int mes_util_is_line_terminator(UCSChar c);



int mes_util_streq(const UCSChar *a, const UCSChar *b, int n)
{
    while (n-- > 0) {
        if (*a != *b)
            return 0;
        a++;
        b++;
    }
    return 1;
}

int mes_util_streq2(const UCSChar *a, const char *b, int n)
{
    while (n-- > 0) {
        if (*a != *b)
            return 0;
        a++;
        b++;
    }
    return 1;
}

int mes_util_streq3(const UCSChar *a, const char *b, int n)
{
    UCSChar c;

    while (n-- > 0) {
        c = mes_util_to_lower(*a);
        if (c != mes_util_to_lower(*b))
            return 0;
        a++;
        b++;
    }
    return 1;
}

int mes_util_streq4(const UCSChar *a, const UCSChar *b, int n, int ci)
{
    UCSChar c;

    if (ci) {
        while (n-- > 0) {
            c = mes_util_to_lower(*a);
            if (c != mes_util_to_lower(*b))
                return 0;
            a++;
            b++;
        }
    } else {
        while (n-- > 0) {
            if (*a != *b)
                return 0;
            a++;
            b++;
        }
    }
    return 1;
}

UCSChar *mes_util_strcp(UCSChar *d, const char *s)
{
    char c;

    while ((c = *s++) != 0)
        *d++ = c;
    return d;
}

UCSChar *mes_util_strcp2(UCSChar *d, UStr *s)
{
    int n = s->len;
    UCSChar *p = s->str;

    while (n-- > 0)
        *d++ = *p++;
    return d;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *mes_util_string_new(void) {
    M2C_UNK *temp_v0;
    M2C_UNK *temp_v0_2;

    temp_v0_2 = MEM_malloc(0, 0xCC);
    if (temp_v0_2 != NULL) {
        *temp_v0_2 = NULL;
        temp_v0 = MEM_malloc(0, 0x18);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, M2C_UNK **, 8) = temp_v0_2;
            M2C_FIELD(temp_v0, M2C_UNK **, 4) = temp_v0_2;
            M2C_FIELD(temp_v0, M2C_UNK **, 0) = temp_v0_2;
            M2C_FIELD(temp_v0, int *, 0x14) = 0;
            M2C_FIELD(temp_v0, int *, 0x10) = 0;
            M2C_FIELD(temp_v0, int *, 0xC) = 0x64;
            return temp_v0;
        }
        MEM_free(0, temp_v0_2);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return NULL;
    }
    return NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_util_string_free(M2C_UNK *arg0) {
    M2C_UNK *temp_s0;
    M2C_UNK *var_a1;

    if (arg0 != NULL) {
        var_a1 = *arg0;
        if (var_a1 != NULL) {
            do {
                temp_s0 = *var_a1;
                MEM_free(0, var_a1);
                var_a1 = temp_s0;
            } while (temp_s0 != NULL);
        }
        MEM_free(0, arg0);
    }
}

int mes_util_string_pos(UString *s, int pos)
{
    UChunk *ch;

    while (pos >= s->cap) {
        ch = MEM_malloc(0, sizeof(UChunk));
        if (ch == NULL)
            return 0;
        ch->next = NULL;
        s->f4->next = ch;
        s->f4 = ch;
        s->cap += 100;
    }
    if (pos < s->base) {
        s->base = 0;
        s->cur = s->head;
    }
    while (pos >= s->base + 100) {
        s->cur = s->cur->next;
        s->base += 100;
    }
    return 1;
}

void mes_util_string_put(UString *s, UCSChar c)
{
    if (s != NULL && mes_util_string_pos(s, s->len) != 0) {
        s->cur->data[s->len - s->base] = c;
        s->len++;
    }
}

void mes_util_string_puts(UString *s, const char *str)
{
    UCSChar c;

    while ((c = *str++) != 0)
        mes_util_string_put(s, c);
}

void mes_util_string_puti(UString *s, unsigned int n, unsigned int w, unsigned int base)
{
    unsigned int c;

    if (w > 1 || n >= base)
        mes_util_string_puti(s, n / base, w ? w - 1 : 0, base);
    c = (UCSChar)(n % base);
    if (c < 10)
        c += '0';
    else
        c += 'a' - 10;
    mes_util_string_put(s, c);
}

void mes_util_string_put_string(UString *s, int v)
{
    int len, m;
    UCSChar *p;

    if (s != NULL) {
        len = ((UStr *)(v & ~3))->len;
        p = ((UStr *)(v & ~3))->str;
        while (len > 0) {
            mes_util_string_pos(s, s->len);
            m = s->base - s->len + 100;
            if (m > len)
                m = len;
            mes_memory_copy(p, &s->cur->data[s->len - s->base], m * 2);
            len -= m;
            p += m;
            s->len += m;
        }
    }
}

UCSChar mes_util_string_get(UString *s, int pos)
{
    if (s != NULL && mes_util_string_pos(s, pos) != 0)
        return s->cur->data[pos - s->base];
    return 0;
}

int mes_util_string_eq(UString *s, int v)
{
    int n = ((UStr *)(v & ~3))->len;
    UChunk *ch;
    UCSChar *q, *p;
    int m;

    if (n != s->len)
        return 0;
    q = ((UStr *)(v & ~3))->str;
    ch = s->head;
    while (n > 0) {
        m = n;
        if (m > 100)
            m = 100;
        n -= m;
        p = ch->data;
        while (m-- > 0) {
            if (*q++ != *p++)
                return 0;
        }
        ch = ch->next;
    }
    return 1;
}

int mes_util_string_eq2(UString *s, const char *str)
{
    int n = s->len;
    UChunk *ch = s->head;
    int m;
    UCSChar *p;

    while (n > 0) {
        m = n;
        if (m > 100)
            m = 100;
        n -= m;
        p = ch->data;
        while (m-- > 0) {
            if (*str++ != *p++)
                return 0;
        }
        ch = ch->next;
    }
    return *str == 0;
}

double mes_util_expt(double x, int n)
{
    double r;

    if (n == 0)
        return D_0013A450;
    if (n < 0)
        return mes_util_expt(D_0013A450 / x, -n);
    r = mes_util_expt(x * x, n / 2);
    if (n / 2 * 2 == n - 1)
        r = r * x;
    return r;
}

int mes_util_is_white_space(UCSChar c)
{
    int ret = 0;

    if (c == 9 || c == 0xB || c == 0xC || c == 0x20 || c == 0xA0 || c == 0x2000 || c == 0x2001)
        ret = 1;
    return ret;
}

int mes_util_is_line_terminator(UCSChar c)
{
    int ret = 0;

    if (c == '\n' || c == '\r' || c == 0x2028 || c == 0x2029)
        ret = 1;
    return ret;
}

int mes_util_is_blank(UCSChar c)
{
    int ret = 0;

    if (mes_util_is_white_space(c))
        ret = 1;
    else if (mes_util_is_line_terminator(c))
        ret = 1;
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_util_is_alpha_digit(int arg0) {
    int temp_a0;
    int var_a1;

    temp_a0 = arg0 & 0xFFFF;
    var_a1 = 0;
    if (((((unsigned int) (temp_a0 - 0x30) < 0xAU) | ((unsigned int) (temp_a0 - 0x41) < 0x1AU)) != 0) || ((unsigned int) (temp_a0 - 0x61) < 0x1AU)) {
        var_a1 = 1;
    }
    return var_a1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_util_is_word_char(int arg0) {
    int temp_a0;
    int var_a1;

    temp_a0 = arg0 & 0xFFFF;
    var_a1 = 0;
    if (((((unsigned int) (temp_a0 - 0x61) < 0x1AU) | ((unsigned int) (temp_a0 - 0x41) < 0x1AU)) != 0) || ((((unsigned int) (temp_a0 - 0x30) < 0xAU) | (temp_a0 == 0x5F)) != 0)) {
        var_a1 = 1;
    }
    return var_a1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_util_digit(int arg0) {
    int var_a0;

    var_a0 = (arg0 & 0xFFFF) - 0x30;
    if ((unsigned int) (var_a0 & 0xFFFF) >= 0xAU) {
        var_a0 = -1;
    }
    return var_a0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_util_octal(int arg0) {
    int var_a0;

    var_a0 = (arg0 & 0xFFFF) - 0x30;
    if ((unsigned int) (var_a0 & 0xFFFF) >= 8U) {
        var_a0 = -1;
    }
    return var_a0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_util_hex(int arg0) {
    int temp_a0;
    int var_v1;

    temp_a0 = arg0 & 0xFFFF;
    var_v1 = temp_a0 - 0x30;
    if ((unsigned int) (var_v1 & 0xFFFF) >= 0xAU) {
        var_v1 = temp_a0 - 0x57;
        if ((unsigned int) (temp_a0 - 0x61) >= 6U) {
            var_v1 = temp_a0 - 0x37;
            if ((unsigned int) (temp_a0 - 0x41) >= 6U) {
                var_v1 = -1;
            }
        }
    }
    return var_v1;
}

char mes_util_hex_char(unsigned int v)
{
    if (v < 10)
        return v + '0';
    if (v - 10 < 26)
        return v + 'A' - 10;
    return '?';
}

UVals *mes_util_vals(int n, int init)
{
    UVals *v;
    int i;

    if (n <= 0)
        return NULL;
    v = MEM_malloc(0, n * 4 + 4);
    if (v != NULL) {
        v->n = n;
        if (init != 0x20) {
            for (i = 0; i < n; i++)
                v->v[i] = init;
        }
    }
    return v;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_util_vals_free(int arg0) {
    if (arg0 != 0) {
        MEM_free(0, arg0);
    }
}

void mes_util_vals_mark(UVals *v)
{
    unsigned int i;

    if (v != NULL) {
        for (i = 0; i < v->n; i++)
            mes_gc_mark(v->v[i]);
    }
}

int mes_util_char_in(UCSChar c, const char *s)
{
    char ch;

    if (s == NULL)
        return 0;
    while ((ch = *s++) != 0) {
        if (ch == c)
            return 1;
    }
    return 0;
}

UCSChar mes_util_to_upper(UCSChar c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 0x20;
    else if ((c >= 0xE0 && c <= 0xF6) || (c >= 0xF8 && c <= 0xFE))
        c = c - 0x20;
    else if (c == 0xFF)
        c = 0x178;
    else if (c == 0x131)
        c = 0x49;
    else if (((c >= 0x100 && c <= 0x137) || (c >= 0x14A && c <= 0x177)) && c % 2 == 1)
        c = c - 1;
    else if (((c >= 0x139 && c <= 0x148) || (c >= 0x179 && c <= 0x17E)) && c % 2 == 0)
        c = c - 1;
    else if (c == 0x17F)
        c = 0x53;
    else if (c >= 0x200 && c <= 0x217 && c % 2 == 1)
        c = c - 1;
    else if (c >= 0x430 && c <= 0x44F)
        c = c - 0x20;
    else if ((c >= 0x451 && c <= 0x45C) || (c >= 0x45E && c <= 0x45F))
        c = c - 0x50;
    else if (c >= 0x460 && c <= 0x47F && c % 2 == 1)
        c = c - 1;
    else if (c >= 0x561 && c <= 0x586)
        c = c - 0x30;
    else if (c >= 0xFF41 && c <= 0xFF5A)
        c = c - 0x20;
    return c;
}

UCSChar mes_util_to_lower(UCSChar c)
{
    if (c >= 'A' && c <= 'Z')
        c = c + 0x20;
    else if ((c >= 0xC0 && c <= 0xD6) || (c >= 0xD8 && c <= 0xDE))
        c = c + 0x20;
    else if (c == 0x130)
        c = 0x69;
    else if (((c >= 0x100 && c <= 0x137) || (c >= 0x14A && c <= 0x177)) && c % 2 == 0)
        c = c + 1;
    else if (c == 0x178)
        return 0xFF;
    else if (((c >= 0x139 && c <= 0x148) || (c >= 0x179 && c <= 0x17E)) && c % 2 == 1)
        c = c + 1;
    else if (c >= 0x200 && c <= 0x217 && c % 2 == 0)
        c = c + 1;
    else if ((c >= 0x401 && c <= 0x40C) || (c >= 0x40E && c <= 0x40F))
        c = c + 0x50;
    else if (c >= 0x410 && c <= 0x42F)
        c = c + 0x20;
    else if (c >= 0x460 && c <= 0x47F && c % 2 == 0)
        c = c + 1;
    else if (c >= 0x531 && c <= 0x556)
        c = c + 0x30;
    else if (c >= 0x10A0 && c <= 0x10C5)
        c = c + 0x30;
    else if (c >= 0xFF21 && c <= 0xFF3A)
        c = c + 0x20;
    return c;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", D_0013A450);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", D_0013A454);
