/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
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



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_vars_list);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_compile_vars(int arg0) {
    int temp_v0;

    temp_v0 = mes_list_tail_new();
    mes_compile_vars_list(arg0, temp_v0);
    mes_list_tail_to_vals(temp_v0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_args);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_set_var);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_get_var);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_get_inc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_op);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_function);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_expression);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_lhs_expression);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_nest_out);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", D_0013B36C);
