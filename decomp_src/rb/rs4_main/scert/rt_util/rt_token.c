#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
typedef struct { unsigned short owner; unsigned short pending; } RtTokEnt;
typedef struct { int count; unsigned int size; RtTokEnt *ents; } RtTokTab;
int rt_token_is_valid(unsigned int arg0);
void rt_token_shutdown(int *arg0);
M2C_UNK rt_memory_free(void *);                     /* extern */

int rt_token_start(int **t)
{
    if (*t != NULL) return 0xDAC5;
    if (rt_memory_allocate_init_zero(t, 0xC) != 0) return 0xDAC4;
    (*t)[0] = 0;
    (*t)[1] = 0;
    (*t)[2] = 0;
    return 0;
}

void rt_token_shutdown(int *arg0) {
    int temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        rt_token_destroy_table(temp_v0);
        rt_memory_free(arg0);
        *arg0 = 0;
    }
}

int rt_token_is_valid(unsigned int arg0) {
    if (arg0 > 0xFFFEU) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", rt_token_is_mine);

int rt_token_is_free(unsigned int idx, RtTokTab *t)
{
    int ret;
    if (t == NULL) {
        rt_token_start(&t);
        ret = 1;
    } else {
        ret = 1;
        if (t->count != 0) {
            ret = 0;
            if (idx < t->size) {
                if (t->ents[idx].owner == 0xFFFF)
                    ret = 1;
            } else
                ret = 1;
        }
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", rt_token_is_pending);

void rt_token_set_pending_state(unsigned int idx, RtTokTab *t)
{
    RtTokEnt *e;

    if (t == NULL) rt_token_start(&t);
    if (t->size == 0) {
        if (rt_token_create_table(idx, t) != 0) return;
    } else if (idx >= t->size) {
        if (rt_token_expand_table(idx, t) != 0) return;
    }
    e = (RtTokEnt *)(idx * sizeof(RtTokEnt) + (int)t->ents);
    if (e->owner == 0xFFFF)
        e->pending = 1;
}

void rt_token_free_owner(int owner, RtTokTab *t)
{
    unsigned int i;

    if (t == NULL) rt_token_start(&t);
    if (owner == 0xFFFF) return;
    if (t->count == 0) return;
    for (i = 0; i < t->size; i++)
        if (t->ents[i].owner == owner)
            rt_token_remove_ownership(i, t);
}

int rt_token_start();
void rt_token_get_table_size(int *out, int *t)
{
    int *tt = t;
    if (tt == NULL) rt_token_start(&tt);
    *out = tt[1];
}

void *memcpy(void *, const void *, unsigned long);
int rt_token_get_table(void *out, unsigned int *n, RtTokTab *t)
{
    if (t == NULL) rt_token_start(&t);
    if (*n < t->size) {
        memcpy(out, t->ents, *n * 4);
        return 0xDAC3;
    }
    if (t->ents != NULL)
        memcpy(out, t->ents, t->size * 4);
    *n = t->size;
    return 0;
}

void rt_token_get_token_count(int *out, int *t)
{
    int *tt = t;
    if (tt == NULL) rt_token_start(&tt);
    *out = tt[0];
}

void rt_token_check_ownership(unsigned int idx, int *owner, RtTokTab *t)
{
    if (t == NULL) rt_token_start(&t);
    if (t->count != 0 && idx < t->size && t->ents[idx].owner != 0xFFFF)
        *owner = t->ents[idx].owner;
    else
        *owner = 0xFFFF;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", rt_token_grant_ownership);

int rt_token_release_ownership(unsigned int idx, int owner, RtTokTab *t)
{
    if (t == NULL) rt_token_start(&t);
    if (owner == 0xFFFF) return 0xDAC2;
    if (t->count == 0) return 0xDAC2;
    if (idx >= t->size) return 0xDAC2;
    if (t->ents[idx].owner != owner) return 0xDAC2;
    rt_token_remove_ownership(idx, t);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", rt_token_update_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", rt_token_list_check_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", rt_token_list_grant_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", rt_token_list_release_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", rt_token_list_update_ownership);

int rt_memory_allocate_init_zero();
int rt_token_create_table(unsigned int n, RtTokTab *t)
{
    unsigned int i;

    if (t == NULL) return 0xDAC2;
    t->size = (n >> 4) * 16 + 16;
    rt_memory_free(&t->ents);
    if (rt_memory_allocate_init_zero(&t->ents, t->size * 4) != 0) return 0xDAC4;
    for (i = 0; i < t->size; i++)
        t->ents[i].owner = 0xFFFF;
    return 0;
}

int rt_token_expand_table(unsigned int n, RtTokTab *t)
{
    RtTokEnt *old;
    unsigned int sz;

    if (t == NULL) return 0xDAC2;
    if (rt_memory_allocate_init_zero(&old, t->size * 4) != 0) return 0xDAC4;
    sz = t->size * 4;
    memcpy(old, t->ents, sz);
    rt_memory_free(&t->ents);
    if (rt_token_create_table(n, t) != 0) return 0xDAC4;
    memcpy(t->ents, old, sz);
    rt_memory_free(&old);
    return 0;
}

void rt_token_destroy_table(int *t)
{
    if (t == NULL) return;
    if (t[2] != 0) rt_memory_free(&t[2]);
    t[2] = 0;
    t[1] = 0;
    t[0] = 0;
}

void rt_token_add_ownership(int idx, int owner, int *t) {
    if (t == NULL) return;
    if (t[1] == 0) return;
    if (t[2] == 0) return;
    ((short *)t[2])[idx * 2] = owner;
    t[0]++;
}

void rt_token_remove_ownership(int idx, RtTokTab *t)
{
    RtTokEnt *e = (RtTokEnt *)(idx * sizeof(RtTokEnt) + (int)t->ents);

    if (e->owner == 0xFFFF) return;
    e->owner = 0xFFFF;
    e->pending = 0;
    if (--t->count == 0)
        rt_token_destroy_table((int *)t);
}

void rt_msg_set_u2byte();
int rt_token_build_token_msg(char *out, unsigned int outsz, unsigned int *outlen, unsigned char type, unsigned short id, int owner)
{
    unsigned char buf[0x200];
    unsigned char *p = buf;
    unsigned int len;

    if ((type < 1 || type > 3) && type != 7 && type != 8 && type != 10 && type != 9) return 2;
    *p = type;
    p++;
    rt_msg_set_u2byte(p, id);
    p += 2;
    len = 3;
    if (type == 7) {
        rt_msg_set_u2byte(p, (unsigned short)owner);
        len = 5;
    }
    if (outsz < len || out == NULL) return 2;
    memcpy(out, buf, len);
    *outlen = len;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", rt_token_build_token_list_msg);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", rcsid_10F21C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_token", header_rcsid_10F274);
