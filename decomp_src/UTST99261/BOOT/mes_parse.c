/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void *mes_parse_node_set1(void *n, int i, void *v);
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK mes_parse_node_free(int);                   /* extern */
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
int mes_error_parse(void *, M2C_UNK *, unsigned short, unsigned short);   /* extern */
int mes_lex_peek(void *);                           /* extern */
int mes_parse_check_stop(unsigned char, int);                  /* extern */
void *mes_list_cons(void *);                        /* extern */
int mes_context_id(int, int);                       /* extern */
void *mes_parse_node_new(M2C_UNK, M2C_UNK);         /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_node_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_node_free);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_parse_node_list_free(void *arg0) {
    void *temp_s0;
    void *var_s1;

    var_s1 = arg0;
    if (arg0 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_s1, void **, 0);
            mes_parse_node_free(M2C_FIELD(var_s1, int *, 4));
            MEM_free(0, var_s1);
            var_s1 = temp_s0;
        } while (temp_s0 != NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *mes_parse_node_cons(int arg0, int arg1) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 8);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0) = arg0;
        M2C_FIELD(temp_v0, int *, 4) = arg1;
    } else {
        mes_parse_node_list_free(arg0);
        mes_parse_node_free(arg1);
    }
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_node_set);

void *mes_parse_node_set1(void *n, int i, void *v)
{
    if (n != NULL)
        M2C_FIELD(n, void ***, 8)[i] = v;
    else
        mes_parse_node_free(v);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_check_stop);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_parse_error_expect(void *arg0, unsigned int arg1, int arg2) {
    M2C_UNK *var_a1;
    void *temp_s0;

    M2C_FIELD(arg0, unsigned short *, 0x12) = (unsigned short) (M2C_FIELD(arg0, unsigned short *, 0x12) + 1);
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), int *, 0x14) == 0) {
        switch (arg1) {
        case 0x68:
            var_a1 = "expect expression";
            break;
        case 0x69:
            var_a1 = "expect constant";
            break;
        case 0x67:
            var_a1 = "expect identifier";
            break;
        case 0x66:
            var_a1 = "expect statement";
            break;
        case 0x9:
            var_a1 = "expect 'catch' or 'try'";
            break;
        case 0xC:
            var_a1 = "expect 'while'";
            break;
        case 0x34:
            var_a1 = "expect '('";
            break;
        case 0x35:
            var_a1 = "expect ')'";
            break;
        case 0x37:
            var_a1 = "expect ']'";
            break;
        case 0x32:
            var_a1 = "expect '{'";
            break;
        case 0x33:
            var_a1 = "expect '}'";
            break;
        case 0x39:
            var_a1 = "expect ';'";
            break;
        case 0x3A:
            var_a1 = "expect ','";
            break;
        case 0x54:
            var_a1 = "expect ':'";
            break;
        case 0x0:
            var_a1 = "too complex";
            break;
        default:
            var_a1 = "unknown";
            break;
        }
        temp_s0 = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_s0, int *, 0x14) = mes_error_parse(temp_s0, var_a1, M2C_FIELD(arg0, unsigned short *, 8), M2C_FIELD(arg0, unsigned short *, 0xA));
    }
    if ((arg2 >= 0) && (mes_lex_peek(arg0) != 0x66)) {
        if (mes_parse_check_stop(M2C_FIELD(arg0, unsigned char *, 0x10), arg2) == 0) {
            M2C_FIELD(arg0, unsigned char *, 0x10) = 0U;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_check_token);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_parse_push(void *arg0, int arg1) {
    void *var_v1;

    var_v1 = M2C_FIELD(arg0, void **, 8);
    if (var_v1 != NULL) {
loop_1:
        if (M2C_FIELD(var_v1, int *, 4) != arg1) {
            var_v1 = M2C_FIELD(var_v1, void **, 0);
            if (var_v1 == NULL) {
                goto block_3;
            }
            goto loop_1;
        }
    } else {
block_3:
        M2C_FIELD(arg0, void **, 8) = mes_list_cons(M2C_FIELD(arg0, void **, 8));
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *mes_parse_id(int arg0, void *arg1, int arg2) {
    int temp_v0;
    void *var_s0;

    if (mes_lex_peek(arg1) == 0x67) {
        var_s0 = mes_parse_node_new(0x67, 0);
        temp_v0 = mes_context_id(arg0, M2C_FIELD(arg1, int *, 0x14));
        if (temp_v0 != 0) {
            M2C_FIELD(var_s0, int *, 8) = temp_v0;
            mes_parse_push(arg0, temp_v0);
            M2C_FIELD(arg1, signed char *, 0x10) = 0;
        } else {
            mes_parse_node_free(var_s0);
            var_s0 = NULL;
            M2C_FIELD(arg1, signed char *, 0x10) = 0;
        }
        return var_s0;
    }
    mes_parse_error_expect(arg1, 0x67, arg2);
    return NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_constant);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_regex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_primary_expression);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_postfix_expression);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_unary_expression);

void *mes_parse_multiplicative_expression(void *p, void *lx, int flags)
{
    void *left = mes_parse_unary_expression(p, lx, flags);
    void *n;
    int t;

    while ((t = mes_lex_peek(lx)) == 0x45 || t == 0x61 || t == 0x46) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(t, 2);
        mes_parse_node_set1(n, 0, left);
        mes_parse_node_set1(n, 1, mes_parse_unary_expression(p, lx, flags));
        left = n;
    }
    return left;
}

void *mes_parse_additive_expression(void *p, void *lx, int flags)
{
    void *left = mes_parse_multiplicative_expression(p, lx, flags);
    void *n;
    int t;

    while ((t = mes_lex_peek(lx)) == 0x43 || t == 0x44) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(t, 2);
        mes_parse_node_set1(n, 0, left);
        mes_parse_node_set1(n, 1, mes_parse_multiplicative_expression(p, lx, flags));
        left = n;
    }
    return left;
}

void *mes_parse_shift_expression(void *p, void *lx, int flags)
{
    void *left = mes_parse_additive_expression(p, lx, flags);
    void *n;
    int t;

    while ((t = mes_lex_peek(lx)) == 0x49 || t == 0x4a || t == 0x4b) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(t, 2);
        mes_parse_node_set1(n, 0, left);
        mes_parse_node_set1(n, 1, mes_parse_additive_expression(p, lx, flags));
        left = n;
    }
    return left;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_relational_expression);

void *mes_parse_equality_expression(void *p, void *lx, int flags)
{
    void *left = mes_parse_relational_expression(p, lx, flags);
    void *n;
    int t;

    while ((t = mes_lex_peek(lx)) == 0x3f || t == 0x40 || t == 0x41 || t == 0x42) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(t, 2);
        mes_parse_node_set1(n, 0, left);
        mes_parse_node_set1(n, 1, mes_parse_relational_expression(p, lx, flags));
        left = n;
    }
    return left;
}

void *mes_parse_bitwise_and_expression(void *p, void *lx, int flags)
{
    void *left = mes_parse_equality_expression(p, lx, flags);
    void *n;

    while (mes_lex_peek(lx) == 0x4c) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(0x4c, 2);
        mes_parse_node_set1(n, 0, left);
        mes_parse_node_set1(n, 1, mes_parse_equality_expression(p, lx, flags));
        left = n;
    }
    return left;
}

void *mes_parse_bitwise_xor_expression(void *p, void *lx, int flags)
{
    void *left = mes_parse_bitwise_and_expression(p, lx, flags);
    void *n;

    while (mes_lex_peek(lx) == 0x4e) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(0x4e, 2);
        mes_parse_node_set1(n, 0, left);
        mes_parse_node_set1(n, 1, mes_parse_bitwise_and_expression(p, lx, flags));
        left = n;
    }
    return left;
}

void *mes_parse_bitwise_or_expression(void *p, void *lx, int flags)
{
    void *left = mes_parse_bitwise_xor_expression(p, lx, flags);
    void *n;

    while (mes_lex_peek(lx) == 0x4d) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(0x4d, 2);
        mes_parse_node_set1(n, 0, left);
        mes_parse_node_set1(n, 1, mes_parse_bitwise_xor_expression(p, lx, flags));
        left = n;
    }
    return left;
}

void *mes_parse_logical_and_expression(void *p, void *lx, int flags)
{
    void *left = mes_parse_bitwise_or_expression(p, lx, flags);
    void *n;

    while (mes_lex_peek(lx) == 0x51) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(0x51, 2);
        mes_parse_node_set1(n, 0, left);
        mes_parse_node_set1(n, 1, mes_parse_bitwise_or_expression(p, lx, flags));
        left = n;
    }
    return left;
}

void *mes_parse_logical_or_expression(void *p, void *lx, int flags)
{
    void *left = mes_parse_logical_and_expression(p, lx, flags);
    void *n;

    while (mes_lex_peek(lx) == 0x52) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(0x52, 2);
        mes_parse_node_set1(n, 0, left);
        mes_parse_node_set1(n, 1, mes_parse_logical_and_expression(p, lx, flags));
        left = n;
    }
    return left;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_conditional_expression);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_assignment_expression);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_expression);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_condition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_statement_list);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_case_clause);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_variable_declaration);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_variable_declaration_list);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_statement);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_formal_parameter);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_function);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_source_element);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_source_elements);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_program);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A6E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A6F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A6FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A704);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A70C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A718);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A720);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A728);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A734);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A744);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A74C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A754);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A75C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A764);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A76C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A778);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A780);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A78C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A7A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", D_0013A7AC);
