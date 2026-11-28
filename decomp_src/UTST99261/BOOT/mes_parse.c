/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct StopMap {
    unsigned short tok;
    unsigned short mask;
} StopMap;
extern StopMap mes_parse_stop_map[14];
void *mes_parse_node_set1(void *n, int i, void *v);
void MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK mes_parse_node_free(int);                   /* extern */
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
int mes_error_parse(void *, M2C_UNK *, unsigned short, unsigned short);   /* extern */
int mes_lex_peek(void *);                           /* extern */
int mes_parse_check_stop(int, int);
void *mes_list_cons(void *);                        /* extern */
int mes_context_id(int, int);                       /* extern */
void *mes_parse_node_new(int, int);


int mes_lex_peek_lf(void *);
void mes_memory_zero(void *arg0, unsigned int arg1);
int mes_string_new3(struct EvCtx *ctx, void *s);
int mes_lex_regex(void *, int eq);
int mes_lex_regex_flags(void *);
void *mes_parse_assignment_expression(void *p, void *lx, int flags);
int mes_stack_check(void *);
void *mes_parse_source_elements(void *p, void *lx, int flags);
void *mes_parse_node_new(int type, int n)
{
    void *node = MEM_malloc(0, 0x10);
    void *kids;

    if (node != NULL) {
        M2C_FIELD(node, unsigned short *, 0) = type;
        M2C_FIELD(node, unsigned short *, 2) = n;
        if (n > 0) {
            n *= 4;
            kids = MEM_malloc(0, n);
            M2C_FIELD(node, void **, 8) = kids;
            if (kids != NULL) {
                mes_memory_zero(kids, n);
                return node;
            }
            MEM_free(0, node);
            node = NULL;
        }
    }
    return node;
}

int mes_parse_node_free(int n)
{
    int i;

    if (n != 0) {
        if (M2C_FIELD(n, unsigned short *, 2) != 0) {
            for (i = 0; i < M2C_FIELD(n, unsigned short *, 2); i++)
                mes_parse_node_free(M2C_FIELD(n, int **, 8)[i]);
            MEM_free(0, M2C_FIELD(n, void **, 8));
        }
        MEM_free(0, (void *)n);
    }
}

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

void mes_parse_node_set(void *n, void *l)
{
    void *next;
    int *p;

    if (n != NULL) {
        p = M2C_FIELD(n, int **, 8) + M2C_FIELD(n, unsigned short *, 2);
        while (l != NULL) {
            next = M2C_FIELD(l, void **, 0);
            *--p = M2C_FIELD(l, int *, 4);
            MEM_free(0, l);
            l = next;
        }
    } else {
        while (l != NULL) {
            next = M2C_FIELD(l, void **, 0);
            MEM_free(0, l);
            l = next;
        }
    }
}

void *mes_parse_node_set1(void *n, int i, void *v)
{
    if (n != NULL)
        M2C_FIELD(n, void ***, 8)[i] = v;
    else
        mes_parse_node_free(v);
}

int mes_parse_check_stop(int tok, int mask)
{
    unsigned int i;

    for (i = 0; i < 14; i++) {
        if (mes_parse_stop_map[i].tok == tok)
            return mask & mes_parse_stop_map[i].mask;
    }
    return 0;
}

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

int mes_parse_check_token(void *lx, unsigned int tok, int flags)
{
    int t;
    int f;

    if (tok == 0x39) {
        t = mes_lex_peek_lf(lx);
        if (t == tok) {
            M2C_FIELD(lx, unsigned char *, 0x10) = 0;
            return 0;
        }
        f = t == 0x65;
        f |= t == 0x66;
        if (f) {
            M2C_FIELD(lx, unsigned char *, 0x10) = 0;
            return 0;
        }
        if ((M2C_FIELD(lx, unsigned char *, 0x11) == 0x65) | (t == 0x33))
            return 0;
    } else if (mes_lex_peek(lx) == tok) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        return 0;
    }
    mes_parse_error_expect(lx, tok, flags);
    return 1;
}

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

void *mes_parse_constant(void *p, void *lx, int flags)
{
    int t = mes_lex_peek(lx);
    int v;
    void *n;

    if (t == 0x67)
        return mes_parse_id((int)p, lx, 0);
    if (t == 0x68) {
        n = mes_parse_node_new(0x68, 0);
        M2C_FIELD(n, double *, 8) = M2C_FIELD(lx, double *, 0x18);
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        return n;
    }
    if (t == 0x69) {
        n = mes_parse_node_new(0x69, 0);
        v = mes_string_new3((int)p, M2C_FIELD(lx, int *, 0x14));
        if (v != 0) {
            M2C_FIELD(n, int *, 8) = v;
            mes_parse_push(p, v);
        } else {
            mes_parse_node_free((int)n);
            n = NULL;
        }
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        return n;
    }
    mes_parse_error_expect(lx, 0x69, flags);
    return NULL;
}

void *mes_parse_regex(void *p, void *lx, int flags, int x)
{
    void *n = mes_parse_node_new(0x6A, 2);
    void *s;
    int v;

    if (mes_lex_regex(lx, x) != 0x6A) {
        mes_parse_error_expect(lx, 0x6A, flags);
        mes_parse_node_free((int)n);
        return NULL;
    }
    s = mes_parse_node_new(0x69, 0);
    v = mes_string_new3((int)p, M2C_FIELD(lx, int *, 0x14));
    M2C_FIELD(s, int *, 8) = v;
    if (v != 0)
        mes_parse_push(p, v);
    mes_parse_node_set1(n, 0, s);
    if (mes_lex_regex_flags(lx)) {
        s = mes_parse_node_new(0x69, 0);
        v = mes_string_new3((int)p, M2C_FIELD(lx, int *, 0x14));
        M2C_FIELD(s, int *, 8) = v;
        if (v != 0)
            mes_parse_push(p, v);
        mes_parse_node_set1(n, 1, s);
    }
    M2C_FIELD(lx, unsigned char *, 0x10) = 0;
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_primary_expression);

void *mes_parse_postfix_expression(void *p, void *lx, int flags)
{
    void *e = mes_parse_primary_expression(p, lx, flags);
    void *n;
    int t = mes_lex_peek_lf(lx);

    if (t == 0x65) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        return e;
    }
    if (M2C_FIELD(lx, unsigned char *, 0x11) == 0x65)
        return e;
    if (t == 0x47 || t == 0x48) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(t, 1);
        mes_parse_node_set1(n, 0, e);
        return n;
    }
    return e;
}

void *mes_parse_unary_expression(void *p, void *lx, int flags)
{
    int t = mes_lex_peek(lx);
    void *n;

    if (t == 0x14 || (t == 8 || t == 0x19 || t == 0x47 || t == 0x48 || t == 0x43 || t == 0x44
        || t == 0x50 || t == 0x4F)) {

        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        if (t == 0x43)
            t = 0xA3;
        else if (t == 0x44)
            t = 0xA4;
        else if (t == 0x47)
            t = 0xA5;
        else if (t == 0x48)
            t = 0xA6;
        n = mes_parse_node_new(t, 1);
        mes_parse_node_set1(n, 0, mes_parse_unary_expression(p, lx, flags));
        return n;
    }
    return mes_parse_postfix_expression(p, lx, flags);
}

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

void *mes_parse_relational_expression(void *p, void *lx, int flags)
{
    void *left = mes_parse_shift_expression(p, lx, flags & ~0x4000);
    void *n;
    int t;

    while ((t = mes_lex_peek(lx)) == 0x3B || t == 0x3C || t == 0x3D || t == 0x3E || t == 0x18
           || (!(flags & 0x4000) && t == 0x15)) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(t, 2);
        mes_parse_node_set1(n, 0, left);
        mes_parse_node_set1(n, 1, mes_parse_shift_expression(p, lx, flags & ~0x4000));
        left = n;
    }
    return left;
}

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

void *mes_parse_conditional_expression(void *p, void *lx, int flags)
{
    void *c = mes_parse_logical_or_expression(p, lx, flags);
    void *n;

    if (mes_lex_peek(lx) != 0x53)
        return c;
    {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        n = mes_parse_node_new(0x53, 3);
        mes_parse_node_set1(n, 0, c);
        mes_parse_node_set1(n, 1, mes_parse_assignment_expression(p, lx, flags | 0x20));
        mes_parse_check_token(lx, 0x54, -1);
        mes_parse_node_set1(n, 2, mes_parse_assignment_expression(p, lx, flags));
    }
    return n;
}

void *mes_parse_assignment_expression(void *p, void *lx, int flags)
{
    void *e;
    int t;
    void *n;

    if (mes_stack_check(p)) {
        if (M2C_FIELD(lx, unsigned short *, 0x12) == 0)
            mes_parse_error_expect(lx, 0, -1);
        mes_lex_peek(lx);
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        return NULL;
    }
    e = mes_parse_conditional_expression(p, lx, flags);
    t = mes_lex_peek(lx);
    if (t >= 0x55) {
    if (t <= 0x60) {
    M2C_FIELD(lx, unsigned char *, 0x10) = 0;
    if (e == NULL || (M2C_FIELD(e, unsigned short *, 0) != 0x67 && M2C_FIELD(e, unsigned short *, 0) != 0xA1
                      && M2C_FIELD(e, unsigned short *, 0) != 0xA2)) {
        mes_parse_error_expect(lx, 0x67, flags);
        mes_parse_node_free((int)e);
        return NULL;
    }
    n = mes_parse_node_new(t, 2);
    mes_parse_node_set1(n, 0, e);
    mes_parse_node_set1(n, 1, mes_parse_assignment_expression(p, lx, flags));
    return n;
    }
    }
    return e;
}

void *mes_parse_expression(void *p, void *lx, int flags)
{
    int list;
    int n;
    void *e;

    list = 0;
    n = 0;
    if (mes_stack_check(p)) {
        if (M2C_FIELD(lx, unsigned short *, 0x12) == 0)
            mes_parse_error_expect(lx, 0, -1);
        mes_lex_peek(lx);
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        return NULL;
    }
    for (;;) {
        e = mes_parse_assignment_expression(p, lx, flags);
        if (mes_lex_peek(lx) != 0x3A)
            break;
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        list = (int)mes_parse_node_cons(list, (int)e);
        n++;
    }
    if (n <= 0)
        return e;
    list = (int)mes_parse_node_cons(list, (int)e);
    e = mes_parse_node_new(0x3A, n + 1);
    mes_parse_node_set(e, (void *)list);
    return e;
}

void *mes_parse_condition(void *p, void *lx, int flags)
{
    void *n;

    if (mes_parse_check_token(lx, 0x34, flags))
        return NULL;
    n = mes_parse_expression(p, lx, flags & ~0x4000);
    mes_parse_check_token(lx, 0x35, -1);
    return n;
}

void *mes_parse_statement_list(void *p, void *lx, int flags)
{
    void *list = NULL;
    int n = 0;
    int t;
    int pos;
    void *node;

    while ((t = mes_lex_peek(lx)) != 0x66 && t != 0x33 && t != 5 && t != 0x11) {
        pos = M2C_FIELD(lx, unsigned short *, 0x12);
        node = mes_parse_statement(p, lx, flags);
        if (node != NULL) {
            list = mes_parse_node_cons((int)list, (int)node);
            n++;
        } else if (pos < M2C_FIELD(lx, unsigned short *, 0x12))
            break;
    }
    if (n > 0) {
        node = mes_parse_node_new(0x9A, n);
        mes_parse_node_set(node, list);
        return node;
    }
    return NULL;
}

void *mes_parse_case_clause(void *p, void *lx, int flags)
{
    void *list = NULL;
    int n = 0;
    int f2;
    void *c;
    int t;

    if (mes_parse_check_token(lx, 0x32, flags))
        return NULL;
    f2 = flags | 0x20;
    while (mes_lex_peek(lx) != 0x33) {
        if (M2C_FIELD(lx, unsigned char *, 0x10) == 5) {
            M2C_FIELD(lx, unsigned char *, 0x10) = 0;
            c = mes_parse_node_new(5, 2);
            mes_parse_node_set1(c, 0, mes_parse_expression(p, lx, f2 & ~0x4000));
            mes_parse_check_token(lx, 0x54, -1);
            mes_parse_node_set1(c, 1, mes_parse_statement_list(p, lx, flags | 0xC00));
        } else if (M2C_FIELD(lx, unsigned char *, 0x10) == 0x11) {
            M2C_FIELD(lx, unsigned char *, 0x10) = 0;
            c = mes_parse_node_new(0x11, 1);
            mes_parse_check_token(lx, 0x54, -1);
            mes_parse_node_set1(c, 0, mes_parse_statement_list(p, lx, flags | 0xC00));
        } else
            break;
        list = mes_parse_node_cons((int)list, (int)c);
        n++;
    }
    mes_parse_check_token(lx, 0x33, -1);
    if (n > 0) {
        c = mes_parse_node_new(0x9A, n);
        mes_parse_node_set(c, list);
        return c;
    }
    return NULL;
}

void *mes_parse_variable_declaration(void *p, void *lx, int flags)
{
    void *id = mes_parse_id(p, lx, flags);
    void *n;

    if (id != NULL) {
        n = mes_parse_node_new(4, 2);
        mes_parse_node_set1(n, 0, id);
        if (mes_lex_peek(lx) == 0x55) {
            M2C_FIELD(lx, unsigned char *, 0x10) = 0;
            mes_parse_node_set1(n, 1, mes_parse_assignment_expression(p, lx, flags));
        }
        return n;
    }
    return NULL;
}

void *mes_parse_variable_declaration_list(void *p, void *lx, int flags)
{
    void *list = NULL;
    int count = 0;
    void *n;

    for (;;) {
        n = mes_parse_variable_declaration(p, lx, flags | 1);
        if (n == NULL)
            break;
        if (mes_lex_peek(lx) != 0x3A)
            break;
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        list = mes_parse_node_cons(list, n);
        count++;
    }
    if (count > 0) {
        list = mes_parse_node_cons(list, n);
        n = mes_parse_node_new(0x9D, count + 1);
        mes_parse_node_set(n, list);
    }
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_parse", mes_parse_statement);

void *mes_parse_formal_parameter(void *p, void *lx, int flags)
{
    void *list = NULL;
    int n = 0;
    void *node;

    while (mes_lex_peek(lx) == 0x67) {
        node = mes_parse_id((int)p, lx, flags | 0x10);
        list = mes_parse_node_cons((int)list, (int)node);
        n++;
        if (mes_lex_peek(lx) != 0x3A)
            break;
        mes_parse_check_token(lx, 0x3A, -1);
    }
    node = mes_parse_node_new(0x98, n);
    mes_parse_node_set(node, list);
    return node;
}

void *mes_parse_function(void *p, void *lx, int flags, int type)
{
    void *n = mes_parse_node_new(type, 3);

    if (type == 0x96 || mes_lex_peek(lx) == 0x67)
        mes_parse_node_set1(n, 0, mes_parse_id((int)p, lx, flags));
    mes_parse_check_token(lx, 0x34, -1);
    mes_parse_node_set1(n, 1, mes_parse_formal_parameter(p, lx, flags | 4));
    if (mes_parse_check_token(lx, 0x35, flags))
        return n;
    mes_parse_check_token(lx, 0x32, -1);
    mes_parse_node_set1(n, 2, mes_parse_source_elements(p, lx, flags | 2));
    mes_parse_check_token(lx, 0x33, flags);
    return n;
}

void *mes_parse_source_element(void *p, void *lx, int flags)
{
    if (mes_lex_peek(lx) == 0xE) {
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
        if (mes_lex_peek(lx) == 0x34)
            return mes_parse_function(p, lx, flags, 0x97);
        return mes_parse_function(p, lx, flags, 0x96);
    }
    return mes_parse_statement(p, lx, flags);
}

void *mes_parse_source_elements(void *p, void *lx, int flags)
{
    void *list = NULL;
    int n = 0;
    void *s = NULL;
    int line;

    flags |= 0x100;
    line = M2C_FIELD(lx, int *, 0xC);
    while (mes_lex_peek(lx) != 0x66 && M2C_FIELD(lx, unsigned char *, 0x10) != 0x33) {
        if (s != NULL) {
            list = mes_parse_node_cons((int)list, (int)s);
            n++;
        }
        s = mes_parse_source_element(p, lx, flags);
        if (mes_lex_peek(lx) != 0x66 && ((M2C_FIELD(lx, unsigned char *, 0x10) != 0x33) & (s == NULL))
            && M2C_FIELD(lx, int *, 0xC) == line) {
            mes_parse_error_expect(lx, 0x66, -1);
            M2C_FIELD(lx, unsigned char *, 0x10) = 0;
            mes_lex_peek(lx);
        }
        line = M2C_FIELD(lx, int *, 0xC);
    }
    if (n > 0) {
        if (s != NULL) {
            list = mes_parse_node_cons((int)list, (int)s);
            n++;
        }
        s = mes_parse_node_new(0x9A, n);
        mes_parse_node_set(s, list);
    }
    return s;
}

void *mes_parse_program(void *p, void *lx, int single)
{
    if (single)
        return mes_parse_source_element(p, lx, 0);
    if (mes_lex_peek(lx) == 0x33) {
        mes_parse_error_expect(lx, 0x66, -1);
        M2C_FIELD(lx, unsigned char *, 0x10) = 0;
    }
    return mes_parse_source_elements(p, lx, 0);
}

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
