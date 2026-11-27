/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int *mes_util_vals(int n, int a);
typedef struct MesList {
    struct MesList *next;
    int v;
} MesList;
typedef struct MesTail {
    MesList *head;
    MesList *last;
    int count;
} MesTail;
void *MEM_malloc(int heap, unsigned int size);
int mes_list_tail_add(MesTail *t, int v);
M2C_UNK MEM_free(M2C_UNK, M2C_UNK *);               /* extern */
M2C_UNK mes_gc_mark(int);                           /* extern */



#ifndef NULL
#define NULL ((void *)0)
#endif

MesList *mes_list_cons(MesList *next, int v)
{
    MesList *l = MEM_malloc(0, sizeof(MesList));

    if (l != NULL) {
        l->next = next;
        l->v = v;
    }
    return l;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_list_member(void *arg0, int arg1) {
    int var_v1;
    void *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    if (var_a0 != NULL) {
loop_1:
        var_v1 = 1;
        if (M2C_FIELD(var_a0, int *, 4) != arg1) {
            var_a0 = M2C_FIELD(var_a0, void **, 0);
            if (var_a0 == NULL) {
                var_v1 = 0;
            } else {
                goto loop_1;
            }
        }
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_list_free(M2C_UNK *arg0) {
    M2C_UNK *temp_s0;
    M2C_UNK *var_a1;

    var_a1 = arg0;
    if (arg0 != NULL) {
        do {
            temp_s0 = *var_a1;
            MEM_free(0, var_a1);
            var_a1 = temp_s0;
        } while (temp_s0 != NULL);
    }
}

void mes_list_free2(MesList *l, MesList *end)
{
    MesList *n;

    while (l != NULL && l != end) {
        n = l->next;
        MEM_free(0, l);
        l = n;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_list_mark(void *arg0) {
    void *var_s0;

    var_s0 = arg0;
    if (arg0 != NULL) {
        do {
            mes_gc_mark(M2C_FIELD(var_s0, int *, 4));
            var_s0 = M2C_FIELD(var_s0, void **, 0);
        } while (var_s0 != NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_list_tail_new(void) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0xC);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0) = 0;
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, int *, 8) = 0;
    }
}

int mes_list_tail_add(MesTail *t, int v)
{
    MesList *l;

    if (t == NULL)
        return -1;
    l = mes_list_cons(NULL, v);
    if (l == NULL)
        return -1;
    if (t->head == NULL)
        t->head = l;
    else
        t->last->next = l;
    t->last = l;
    return t->count++;
}

int mes_list_tail_find(MesTail *t, int v)
{
    MesList *l;
    int i;

    if (t == NULL)
        return -1;
    for (i = 0, l = t->head; l != NULL; l = l->next, i++) {
        if (l->v == v)
            return i;
    }
    return mes_list_tail_add(t, v);
}

int *mes_list_tail_to_vals(MesTail *t)
{
    int *vals;
    int *p;
    MesList *l;
    MesList *next;

    if (t == NULL)
        return NULL;
    vals = NULL;
    if (t->count > 0) {
        vals = mes_util_vals(t->count, 0);
        p = vals != NULL ? vals + 1 : NULL;
        for (l = t->head; l != NULL; l = next) {
            next = l->next;
            if (p != NULL)
                *p++ = l->v;
            MEM_free(0, l);
        }
    }
    MEM_free(0, t);
    return vals;
}
