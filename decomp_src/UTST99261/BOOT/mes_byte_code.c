/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct BcChunk {
    struct BcChunk *next;
    unsigned char data[0x40];
} BcChunk;
typedef struct ByteCode {
    BcChunk *head;
    BcChunk *cur;
    int f8;
    int size;
    int off;
    int f14;
    int labels;
    signed char reachable;
} ByteCode;
void mes_byte_code_put(ByteCode *bc, unsigned char c);
void mes_byte_code_label_add(ByteCode *bc, int label, unsigned char op);
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK MEM_free(M2C_UNK, M2C_UNK *);               /* extern */



#ifndef NULL
#define NULL ((void *)0)
#endif

void *mes_byte_code_new(void) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x20);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, int *, 0) = 0;
        M2C_FIELD(temp_v0, int *, 0xC) = 0;
        M2C_FIELD(temp_v0, int *, 0x10) = 0x40;
        M2C_FIELD(temp_v0, int *, 8) = 0;
        M2C_FIELD(temp_v0, int *, 0x18) = 0;
        M2C_FIELD(temp_v0, signed char *, 0x1C) = 1;
    }
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_put);

void mes_byte_code_op(ByteCode *bc, unsigned char op)
{
    mes_byte_code_put(bc, op);
    if (bc != NULL) {
        if (op == 0x12 || op == 0x15 || op == 0x13)
            bc->reachable = 0;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_opw);

void mes_byte_code_opn(ByteCode *bc, unsigned char op, double d)
{
    union {
        double d;
        unsigned char b[8];
    } u;
    unsigned int i;

    mes_byte_code_put(bc, op);
    u.d = d;
    for (i = 0; i < 8; i++)
        mes_byte_code_put(bc, u.b[i]);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_byte_code_label_new(void *arg0) {
    int var_v0;

    var_v0 = -1;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 0x18) + 1;
        M2C_FIELD(arg0, int *, 0x18) = var_v0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_label_add);

void mes_byte_code_label_def(ByteCode *bc, int label)
{
    mes_byte_code_label_add(bc, label, 0);
    if (bc != NULL)
        bc->reachable = 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned char mes_byte_code_reachable(void *arg0) {
    unsigned char var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, unsigned char *, 0x1C);
    }
    return var_v0;
}

void mes_byte_code_jump(ByteCode *bc, unsigned char op, int label)
{
    if (bc != NULL) {
        mes_byte_code_label_add(bc, label, op);
        bc->size += 5;
        if (op == 0xD3)
            bc->reachable = 0;
    }
}

int mes_byte_code_jump_size(int from, int to)
{
    int d;

    d = to - from - 2;
    if (d >= -128) {
        if (d < 128)
            return 1;
    }
    d = to - from - 3;
    if (d >= -32768) {
        if (d <= 32767)
            return 2;
    }
    return 4;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_label_fix);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_byte_code_free(M2C_UNK *arg0) {
    M2C_UNK *temp_s0;
    M2C_UNK *temp_s0_2;
    M2C_UNK *var_a1;
    M2C_UNK *var_a1_2;

    var_a1 = M2C_FIELD(arg0, M2C_UNK **, 0);
    if (var_a1 != NULL) {
        do {
            temp_s0 = *var_a1;
            MEM_free(0, var_a1);
            var_a1 = temp_s0;
        } while (temp_s0 != NULL);
    }
    var_a1_2 = M2C_FIELD(arg0, M2C_UNK **, 8);
    if (var_a1_2 != NULL) {
        do {
            temp_s0_2 = *var_a1_2;
            MEM_free(0, var_a1_2);
            var_a1_2 = temp_s0_2;
        } while (temp_s0_2 != NULL);
    }
    MEM_free(0, arg0);
}

unsigned char mes_byte_code_chunk_get(ByteCode *bc)
{
    while (bc->off >= 0x40) {
        bc->cur = bc->cur->next;
        bc->off -= 0x40;
    }
    return bc->cur->data[bc->off++];
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_pack);
