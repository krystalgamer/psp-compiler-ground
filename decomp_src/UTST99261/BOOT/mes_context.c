/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct CtxStr {
    unsigned short *chars;                   /* 0x0 */
    int slen;                         /* 0x4 */
} CtxStr;
int mes_util_streq(const unsigned short *a, const unsigned short *b, int n);
int mes_util_streq2(const unsigned short *a, const char *b, int n);
int mes_string_new2(void *ctx, const char *s, int len);
int mes_string_new(void *ctx, const unsigned short *s, int len);
typedef unsigned short UCSChar;
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
int mes_util_string_eq(UString *s, int v);
int mes_string_new3(void *ctx, UString *s);
void mes_context_hash(int str, unsigned int hash);
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

void mes_context_hash(int str, unsigned int hash)
{
    HashEnt *e;

    if (str != 0) {
        e = MEM_malloc(0, 0xC);
        if (e != NULL) {
            e->hash = hash;
            e->str = (void *)str;
            e->next = mes_id_hash[hash % 0x71];
            mes_id_hash[hash % 0x71] = e;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_context", mes_context_index);

int mes_context_id(void *ctx, UString *s)
{
    unsigned int h = 0;
    int n, m;
    UChunk *ch;
    UCSChar *p;
    HashEnt *e;
    int v;

    n = s->len;
    ch = s->head;
    while (n > 0) {
        p = ch->data;
        m = n;
        if (m > 100)
            m = 100;
        n -= m;
        while (m-- > 0)
            h = h * 37 ^ *p++;
        ch = ch->next;
    }
    for (e = mes_id_hash[h % 0x71]; e != NULL; e = e->next) {
        if (e->hash == h && mes_util_string_eq(s, (int)e->str))
            return (int)e->str;
    }
    v = mes_string_new3(ctx, s);
    mes_context_hash(v, h);
    return v;
}

int mes_context_id2(void *ctx, const char *str)
{
    unsigned int h = 0;
    const char *p;
    int len;
    HashEnt *e;
    int v;

    for (p = str; *p != 0; p++)
        h = h * 37 ^ (UCSChar)*p;
    len = p - str;
    for (e = mes_id_hash[h % 0x71]; e != NULL; e = e->next) {
        if (e->hash == h && ((CtxStr *)((int)e->str & ~3))->slen == len
            && mes_util_streq2(((CtxStr *)((int)e->str & ~3))->chars, str, len))
            return (int)e->str;
    }
    v = mes_string_new2(ctx, str, len);
    mes_context_hash(v, h);
    return v;
}

int mes_context_id3(void *ctx, const UCSChar *str, int len)
{
    unsigned int h = 0;
    const UCSChar *p;
    HashEnt *e;
    int v;

    for (p = str; p < str + len; p++)
        h = h * 37 ^ *p;
    for (e = mes_id_hash[h % 0x71]; e != NULL; e = e->next) {
        if (e->hash == h && ((CtxStr *)((int)e->str & ~3))->slen == len
            && mes_util_streq(((CtxStr *)((int)e->str & ~3))->chars, str, len))
            return (int)e->str;
    }
    v = mes_string_new(ctx, str, len);
    mes_context_hash(v, h);
    return v;
}

void mes_context_mark(void)
{
    int i;

    for (i = 0; i < 0x46; i++)
        mes_gc_mark(mes_ids[i]);
    for (i = 0; i < 0x12; i++)
        mes_gc_mark(mes_classes[i]);
    mes_gc_mark(mes_empty);
}

void mes_context_gc(void)
{
    int i;
    HashEnt **pp;
    HashEnt *e;

    for (i = 0; i < 0x71; i++) {
        pp = &mes_id_hash[i];
        while ((e = *pp) != NULL) {
            if (*(int *)((int)e->str & ~3) & 1) {
                pp = &e->next;
            } else {
                *pp = e->next;
                MEM_free(0, e);
            }
        }
    }
}

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
