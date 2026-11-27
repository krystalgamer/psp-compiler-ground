/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct HashEnt {
    struct HashEnt *next;
    void *str;
    unsigned int hash;
} HashEnt;
extern HashEnt *mes_id_hash[0x71];
extern int mes_ids[0x46];
extern int mes_classes[0x12];
extern int mes_empty;
void *MEM_malloc(M2C_UNK, int);                     /* extern */
extern void *mes_context_head;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK mes_list_free(int);                         /* extern */


void mes_context_global_initialize(void)
{
    int i;

    mes_context_head = NULL;
    for (i = 0; i < 0x71; i++)
        mes_id_hash[i] = NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_context", mes_context_hash);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_context", mes_context_index);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_context", mes_context_id);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_context", mes_context_id2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_context", mes_context_id3);

void mes_context_mark(void)
{
    int i;

    for (i = 0; i < 0x46; i++)
        mes_gc_mark(mes_ids[i]);
    for (i = 0; i < 0x12; i++)
        mes_gc_mark(mes_classes[i]);
    mes_gc_mark(mes_empty);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_context", mes_context_gc);

void mes_context_hash_free(void)
{
    int i;
    HashEnt *e, *n;

    for (i = 0; i < 0x71; i++) {
        for (e = mes_id_hash[i]; e != NULL; e = n) {
            n = e->next;
            MEM_free(0, e);
        }
        mes_id_hash[i] = NULL;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *mes_context_new(int arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, (arg0 * 4) + 0x20);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, void **, 0) = (void *) mes_context_head;
        M2C_FIELD(temp_v0, int *, 4) = 0;
        if (mes_context_head != NULL) {
            M2C_FIELD(mes_context_head, void **, 4) = temp_v0;
        }
        mes_context_head = temp_v0;
        M2C_FIELD(temp_v0, int *, 0x1C) = arg0;
        M2C_FIELD(temp_v0, void **, 0x18) = (void *) (temp_v0 + (arg0 * 4) + 0x20);
        M2C_FIELD(temp_v0, int *, 0xC) = 0;
        M2C_FIELD(temp_v0, int *, 0x10) = 0;
        M2C_FIELD(temp_v0, int *, 0x14) = 0;
        M2C_FIELD(temp_v0, int *, 8) = 0;
    }
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_context_free(void *arg0) {
    void **temp_v1;
    void *temp_v1_2;

    if (mes_context_head == arg0) {
        mes_context_head = M2C_FIELD(arg0, void **, 0);
    }
    temp_v1 = M2C_FIELD(arg0, void ***, 4);
    if (temp_v1 != NULL) {
        *temp_v1 = M2C_FIELD(arg0, void **, 0);
    }
    temp_v1_2 = M2C_FIELD(arg0, void **, 0);
    if (temp_v1_2 != NULL) {
        M2C_FIELD(temp_v1_2, void ***, 4) = (void **) M2C_FIELD(arg0, void ***, 4);
    }
    mes_list_free(M2C_FIELD(arg0, int *, 8));
    MEM_free(0, arg0);
}
