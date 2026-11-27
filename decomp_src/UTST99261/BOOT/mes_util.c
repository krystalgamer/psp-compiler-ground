/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef unsigned short UCSChar;
typedef struct UStr {
    UCSChar *str;
    int len;
} UStr;
typedef struct UVals {
    unsigned int n;
    int v[1];
} UVals;
int mes_util_is_white_space(UCSChar c);
int mes_util_is_line_terminator(UCSChar c);
M2C_UNK MEM_free(M2C_UNK, M2C_UNK *);               /* extern */
M2C_UNK *MEM_malloc(M2C_UNK, M2C_UNK);              /* extern */



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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_streq3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_streq4);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_pos);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_put);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_puts);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_puti);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_put_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_eq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_eq2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_expt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_is_white_space);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_vals);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_to_upper);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_to_lower);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", D_0013A450);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", D_0013A454);
