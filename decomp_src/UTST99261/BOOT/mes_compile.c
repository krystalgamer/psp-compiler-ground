/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int mes_list_member(int l, int v);
int mes_compile_body(void *ctx, void *node, int id, void *args, void *vars);
void *mes_list_cons(void *l, int v);
void mes_util_vals_free(void *v);
int mes_list_tail_add(int l, int v);
typedef struct CompState {
    void *ctx;                        /* 0x0 cs */
    int f4;                           /* 0x4 cs */
    int f8;                           /* 0x8 cs */
    int fC;                           /* 0xC cs */
    int list;                         /* 0x10 cs */
    int code;                         /* 0x14 cs */
    int f18;                          /* 0x18 cs */
    int f1C;                          /* 0x1C cs */
    int f20;                          /* 0x20 cs */
    int f24;                          /* 0x24 cs */
} CompState;
int mes_byte_code_new(void);
void mes_compile_function_declaration(CompState *c, void *node);
void mes_compile_statement(CompState *c, void *node);
void *mes_gc_alloc(void *ctx, int kind);
void mes_object_init(void *obj, int cls, void *proto);
extern void *D_00585344;
int mes_byte_code_label_fix(int code);
int mes_byte_code_pack(int code);
typedef struct CNest {
    struct CNest *next;
    signed char type;
    signed char f5;
    int f8;
    int fC;
} CNest;
typedef struct Compiler {
    char pad[0x18];
    CNest *nest;
} Compiler;
typedef struct Vals {
    int n;
    int v[1];
} Vals;
typedef struct Node {
    unsigned short type;
    unsigned short count;
    int f4;
    void *f8;
} Node;
void *MEM_malloc(int heap, unsigned int size);
Vals *mes_util_vals(int n, int x);
M2C_UNK mes_compile_vars_list(int, int);            /* extern */
int mes_list_tail_new();                            /* extern */
M2C_UNK mes_list_tail_to_vals(int);                 /* extern */
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK mes_byte_code_jump(int, M2C_UNK, int);      /* extern */
M2C_UNK mes_byte_code_op(int, M2C_UNK);             /* extern */



void mes_byte_code_opw(int code, int op, int v);
int mes_list_tail_find(int l, int v);
void mes_compile_expression(CompState *c, Node *n, int keep);
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_vars_list);

#ifndef NULL
#define NULL ((void *)0)
#endif

Vals *mes_compile_vars(int arg0) {
    int temp_v0;

    temp_v0 = mes_list_tail_new();
    mes_compile_vars_list(arg0, temp_v0);
    return (Vals *)mes_list_tail_to_vals(temp_v0);
}

Vals *mes_compile_args(Node *n) {
    Vals *v;
    int i;
    int *d;
    Node *c;
    if (n != NULL) {
        if (n->type == 0x98 && n->count != 0) {
            v = mes_util_vals(n->count, 0);
            if (v != NULL) {
                d = v->v;
                for (i = 0; i < n->count; i++) {
                    c = ((Node **)n->f8)[i];
                    if (c != NULL && c->type == 0x67) {
                        *d = (int)c->f8;
                    } else {
                        *d = 0;
                    }
                    d++;
                }
            }
            return v;
        }
    }
    return NULL;
}

int mes_compile_find_vars(Vals *vals, int id)
{
    int i;

    if (vals != NULL) {
        for (i = vals->n - 1; i >= 0; i--) {
            if (vals->v[i] == id)
                return i;
        }
    }
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_compile_in_catch(void *arg0, int arg1) {
    int var_a0;
    void *var_v1;

    var_v1 = M2C_FIELD(arg0, void **, 0x1C);
    var_a0 = 0;
    if (var_v1 != NULL) {
loop_1:
        var_a0 = 1;
        if (M2C_FIELD(var_v1, int *, 4) != arg1) {
            var_v1 = M2C_FIELD(var_v1, void **, 0);
            if (var_v1 == NULL) {
                var_a0 = 0;
            } else {
                goto loop_1;
            }
        }
    }
    return var_a0;
}

void mes_compile_set_var(CompState *c, Node *n, int keep)
{
    int id;
    int i;

    if (n == NULL || n->type != 0x67)
        return;
    id = (int)n->f8;
    if (c->f20 == 0 && !mes_compile_in_catch(c, id)) {
        if ((i = mes_compile_find_vars((Vals *)c->f8, id)) >= 0) {
            mes_byte_code_opw(c->code, 0xC7, i);
            if (keep) {
                mes_byte_code_op(c->code, 0x16);
                mes_byte_code_op(c->code, 0x3A);
            }
            return;
        }
        if ((i = mes_compile_find_vars((Vals *)c->fC, id)) >= 0) {
            mes_byte_code_opw(c->code, 0xC7, ~i);
            if (keep) {
                mes_byte_code_op(c->code, 0x16);
                mes_byte_code_op(c->code, 0x3A);
            }
            return;
        }
    }
    i = mes_list_tail_find(c->list, id);
    if (keep) {
        mes_byte_code_opw(c->code, 0xC6, i);
        mes_byte_code_op(c->code, 0x3A);
    }
    mes_byte_code_opw(c->code, 0xC8, i);
}

void mes_compile_get_var(CompState *c, Node *n, int keep, int tof)
{
    int id;
    int i;

    if (n != NULL && n->type == 0x67) {
        id = (int)n->f8;
        if (c->f20 == 0 && !mes_compile_in_catch(c, id)) {
            if ((i = mes_compile_find_vars((Vals *)c->f8, id)) >= 0) {
                if (keep)
                    mes_byte_code_op(c->code, 0x16);
                mes_byte_code_opw(c->code, 0xC2, i);
                return;
            }
            if ((i = mes_compile_find_vars((Vals *)c->fC, id)) >= 0) {
                if (keep)
                    mes_byte_code_op(c->code, 0x16);
                mes_byte_code_opw(c->code, 0xC2, ~i);
                return;
            }
            if (id == c->f4) {
                if (keep)
                    mes_byte_code_op(c->code, 0x16);
                mes_byte_code_op(c->code, 0xC);
                return;
            }
        }
        i = mes_list_tail_find(c->list, id);
        if (keep)
            mes_byte_code_opw(c->code, 0xC6, i);
        if (tof)
            mes_byte_code_opw(c->code, 0xC5, i);
        else
            mes_byte_code_opw(c->code, 0xC4, i);
        return;
    }
    if (keep)
        mes_byte_code_op(c->code, 0x16);
    mes_byte_code_op(c->code, 1);
}

void mes_compile_get_inc(CompState *c, Node *n, int pre, int inc, int keep)
{
    int id;
    int i;

    if (n == NULL || n->type != 0x67)
        return;
    id = (int)n->f8;
    if (c->f20 == 0 && !mes_compile_in_catch(c, id)) {
        if ((i = mes_compile_find_vars((Vals *)c->f8, id)) >= 0) {
            if (pre) {
                if (inc)
                    mes_byte_code_opw(c->code, 0xCB, i);
                else
                    mes_byte_code_opw(c->code, 0xCC, i);
            } else {
                if (inc)
                    mes_byte_code_opw(c->code, 0xCD, i);
                else
                    mes_byte_code_opw(c->code, 0xCE, i);
            }
            return;
        }
        if ((i = mes_compile_find_vars((Vals *)c->fC, id)) >= 0) {
            i = ~i;
            if (keep)
                mes_byte_code_op(c->code, 0x16);
            if (pre) {
                if (inc)
                    mes_byte_code_opw(c->code, 0xCB, i);
                else
                    mes_byte_code_opw(c->code, 0xCC, i);
            } else {
                if (inc)
                    mes_byte_code_opw(c->code, 0xCD, i);
                else
                    mes_byte_code_opw(c->code, 0xCE, i);
            }
            return;
        }
    }
    i = mes_list_tail_find(c->list, id);
    if (keep)
        mes_byte_code_opw(c->code, 0xC6, i);
    if (pre) {
        if (inc)
            mes_byte_code_opw(c->code, 0xCF, i);
        else
            mes_byte_code_opw(c->code, 0xD0, i);
    } else {
        if (inc)
            mes_byte_code_opw(c->code, 0xD1, i);
        else
            mes_byte_code_opw(c->code, 0xD2, i);
    }
}

int mes_compile_op(int op) {
    int r;
    switch (op) {
    case 0x19:
        r = 0x1E;
        break;
    case 0x47:
    case 0xA5:
        r = 0x26;
        break;
    case 0x48:
    case 0xA6:
        r = 0x27;
        break;
    case 0x4F:
        r = 0x37;
        break;
    case 0x50:
        r = 0x2B;
        break;
    case 0x51:
        r = 0xD4;
        break;
    case 0x52:
        r = 0xD6;
        break;
    case 0xA3:
        r = 0x24;
        break;
    case 0xA4:
        r = 0x25;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_compile_op2(int arg0) {
    switch (arg0) {
    case 0x43:
    case 0x56:
        return 0x1F;
    case 0x44:
    case 0x57:
        return 0x20;
    case 0x45:
    case 0x58:
        return 0x21;
    case 0x46:
    case 0x59:
        return 0x23;
    case 0x49:
    case 0x5A:
        return 0x2C;
    case 0x4A:
    case 0x5B:
        return 0x2D;
    case 0x4B:
    case 0x5C:
        return 0x2E;
    case 0x4C:
    case 0x5D:
        return 0x28;
    case 0x4D:
    case 0x5E:
        return 0x29;
    case 0x4E:
    case 0x5F:
        return 0x2A;
    case 0x60:
    case 0x61:
        return 0x22;
    case 0x3B:
        return 0x36;
    case 0x3C:
        return 0x34;
    case 0x3D:
        return 0x35;
    case 0x3E:
        return 0x33;
    case 0x18:
        return 0x1D;
    case 0x15:
        return 0x1C;
    case 0x3F:
        return 0x2F;
    case 0x40:
        return 0x30;
    case 0x41:
        return 0x31;
    case 0x42:
        return 0x32;
    default:
        return 7;
    }
}

void mes_compile_function(Compiler *c, Node *n, int decl)
{
    Node *name = ((Node **)n->f8)[0];
    int id;
    Vals *args, *vars;
    int f;
    void *ctx;

    id = name != NULL && name->type == 0x67 ? (int)name->f8 : 0;
    args = (Vals *)mes_compile_args(((Node **)n->f8)[1]);
    vars = (Vals *)mes_compile_vars(((int *)n->f8)[2]);
    f = mes_compile_body(M2C_FIELD(c, void **, 0), ((Node **)n->f8)[2], id, args, vars);
    ctx = M2C_FIELD(c, void **, 0);
    M2C_FIELD(ctx, void **, 8) = mes_list_cons(M2C_FIELD(ctx, void **, 8), f);
    mes_util_vals_free(args);
    mes_util_vals_free(vars);
    mes_byte_code_opw(M2C_FIELD(c, int *, 0x14), 0xC3, mes_list_tail_add(M2C_FIELD(c, int *, 0x10), f));
    mes_byte_code_op(M2C_FIELD(c, int *, 0x14), 0x11);
    if (decl)
        mes_compile_set_var(c, name, 0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_expression);

void mes_compile_lhs_expression(CompState *c, Node *n, int keep)
{
    Node *m;
    int i;

    if (n != NULL) {
        if (n->type == 0xA1) {
            mes_compile_expression(c, ((Node **)n->f8)[0], 0);
            if (keep)
                mes_byte_code_op(c->code, 9);
            mes_compile_expression(c, ((Node **)n->f8)[1], 0);
            mes_byte_code_op(c->code, 0x38);
            return;
        }
        if (n->type == 0xA2) {
            mes_compile_expression(c, ((Node **)n->f8)[0], 0);
            if (keep)
                mes_byte_code_op(c->code, 9);
            m = ((Node **)n->f8)[1];
            if (m != NULL && m->type == 0x67) {
                i = mes_list_tail_find(c->list, (int)m->f8);
                mes_byte_code_opw(c->code, 0xC3, i);
            } else
                mes_byte_code_op(c->code, 1);
            return;
        }
        if (n->type == 0x67) {
            i = mes_list_tail_find(c->list, (int)n->f8);
            mes_byte_code_opw(c->code, 0xC6, i);
            if (keep)
                mes_byte_code_op(c->code, 9);
            mes_byte_code_opw(c->code, 0xC3, i);
            return;
        }
    }
    if (keep)
        mes_byte_code_op(c->code, 0x16);
    mes_byte_code_op(c->code, 1);
    mes_byte_code_op(c->code, 1);
}

void mes_compile_nest(Compiler *c, int type, int a, int b)
{
    CNest *n = MEM_malloc(0, sizeof(CNest));

    if (n != NULL) {
        n->next = c->nest;
        c->nest = n;
        n->type = type;
        n->f5 = 0;
        n->f8 = a;
        n->fC = b;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

signed char mes_compile_nest_pop(void *arg0) {
    signed char temp_s0;
    signed char var_v0;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x18);
    var_v0 = 0;
    if (temp_a1 != NULL) {
        temp_s0 = M2C_FIELD(temp_a1, signed char *, 5);
        M2C_FIELD(arg0, void **, 0x18) = (void *) M2C_FIELD(temp_a1, void **, 0);
        MEM_free(0, temp_a1);
        var_v0 = temp_s0;
    }
    return var_v0;
}

int mes_compile_nest_out(Compiler *c, int type, int label)
{
    CNest *nn;

    for (nn = c->nest; nn != NULL; nn = nn->next) {
        if (nn->type == type && mes_list_member(nn->f8, label))
            break;
    }
    if (nn == NULL)
        return -1;
    for (nn = c->nest; nn != NULL; nn = nn->next) {
        if (nn->type == type && mes_list_member(nn->f8, label))
            break;
        if (nn->type == 3)
            mes_byte_code_op(M2C_FIELD(c, int *, 0x14), 0x18);
        else if (nn->type == 4) {
            mes_byte_code_op(M2C_FIELD(c, int *, 0x14), 0x14);
            if (nn->fC >= 0)
                mes_byte_code_jump(M2C_FIELD(c, int *, 0x14), 0xDB, nn->fC);
        } else if (nn->type == 5)
            mes_byte_code_op(M2C_FIELD(c, int *, 0x14), 8);
    }
    nn->f5 = 1;
    return nn->fC;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_compile_nest_out_try(void *arg0) {
    int temp_a2;
    void *var_s0;

    var_s0 = M2C_FIELD(arg0, void **, 0x18);
    if (var_s0 != NULL) {
        do {
            if (M2C_FIELD(var_s0, signed char *, 4) == 4) {
                mes_byte_code_op(M2C_FIELD(arg0, int *, 0x14), 0x14);
                temp_a2 = M2C_FIELD(var_s0, int *, 0xC);
                if (temp_a2 >= 0) {
                    mes_byte_code_jump(M2C_FIELD(arg0, int *, 0x14), 0xDB, temp_a2);
                }
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0);
        } while (var_s0 != NULL);
    }
}

int mes_compile_nest_in_try(Compiler *c)
{
    CNest *n;

    for (n = c->nest; n != NULL; n = n->next) {
        if (n->type == 4)
            return 1;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_function_declaration);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_statement);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_body);

void *mes_compile(void *ctx, void *node)
{
    CompState c;
    int *sp = M2C_FIELD(ctx, int **, 0x18);
    void *f;

    c.ctx = ctx;
    c.f4 = 0;
    c.f8 = 0;
    c.fC = 0;
    c.list = mes_list_tail_new();
    c.code = mes_byte_code_new();
    c.f18 = 0;
    c.f1C = 0;
    c.f20 = 0;
    c.f24 = 0;
    mes_compile_function_declaration(&c, node);
    mes_byte_code_op(c.code, 1);
    mes_compile_statement(&c, node);
    f = mes_gc_alloc(ctx, 3);
    if (f != NULL) {
        *--M2C_FIELD(ctx, int **, 0x18) = (int)f;
        mes_object_init(f, 5, D_00585344);
        M2C_FIELD(f, int *, 0x14) = 0;
        M2C_FIELD(f, int *, 0x18) = mes_byte_code_label_fix(c.code);
        M2C_FIELD(f, int *, 0x1C) = mes_byte_code_pack(c.code);
        M2C_FIELD(f, int *, 0x20) = mes_list_tail_to_vals(c.list);
        M2C_FIELD(f, int *, 0x28) = 0;
    }
    M2C_FIELD(ctx, int **, 0x18) = sp;
    return f;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", D_0013B36C);
