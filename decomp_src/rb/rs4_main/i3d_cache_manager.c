#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dResourceTag__PurgeCache();               /* extern */
M2C_UNK I3dVecClear(int);                           /* extern */
M2C_UNK I3dPicture__FlushCache(void *);             /* extern */
M2C_UNK sceGimPictureDelete(int);                   /* extern */


typedef struct MBLnk2 { struct MBk2 *next, *prev; } MBLnk2;
typedef struct MBk2 { MBLnk2 l[1]; } MBk2;
void I3dMemBlock__RemoveList(MBk2 *b, int i)
{
	MBk2 *n = b->l[i].next;
	n->l[i].prev = b->l[i].prev;
	b->l[i].prev->l[i].next = n;
	b->l[i].prev = b;
	b->l[i].next = b;
}

typedef struct MBLnk { struct MBk *next, *prev; } MBLnk;
typedef struct MBk { MBLnk l[1]; } MBk;
void I3dMemBlock__InsertList(MBk *b, int i, MBk *h)
{
	MBk *p = h->l[i].prev;
	p->l[i].next = b;
	b->l[i].prev = p;
	b->l[i].next = h;
	h->l[i].prev = b;
}

typedef struct MBLnk3 { struct MBk3 *next, *prev; } MBLnk3;
typedef struct MBk3 { MBLnk3 l[1]; } MBk3;
void I3dMemBlock__MoveList(MBk3 *b, int i, MBk3 *h)
{
	MBk3 *n = b->l[i].next;
	MBk3 *p;
	n->l[i].prev = b->l[i].prev;
	b->l[i].prev->l[i].next = n;
	b->l[i].prev = b;
	p = h->l[i].prev;
	p->l[i].next = b;
	b->l[i].prev = p;
	b->l[i].next = h;
	h->l[i].prev = b;
}

int I3dMemBlock__ChangeAttributeToCache(char *b, void *t)
{
	*(void **)(b + 0x40) = t;
	*(unsigned int *)(b + 0x30) = (*(unsigned int *)(b + 0x30) & ~1) | 0x10;
	return I3dResourceTag__SetMemBlock(t, b);
}

void I3dMemBlock__ChangeAttributeToGarbage(b)
	char *b;
{
	int t = *(int *)(b + 0x40);
	*(unsigned int *)(b + 0x30) = (*(unsigned int *)(b + 0x30) & ~0x10) | 1;
	if (t != 0) {
		I3dResourceTag__SetMemBlock(t, 0);
		*(int *)(b + 0x40) = 0;
	}
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__Construct);

int I3dMemBlock__Destruct(void *b)
{
	unsigned int i;
	for (i = 0; i < 6; i++)
		I3dMemBlock__RemoveList(b, i);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void I3dResourceTag__SetMemBlock(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 8) = arg1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dResourceTag__PurgeCache);

int I3dResourceTag__Construct(int *t)
{
	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = 0;
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dResourceTag__Destruct(void) {
    I3dResourceTag__PurgeCache();
    return 0;
}

int I3dCacheManager__CreateNewMemBlockAsGarbage(int *cm, int size, void *head)
{
	char *b;
	cm[24]--;
	b = (char *)((int *)cm[23])[cm[24]];
	I3dMemBlock__Construct(b);
	*(int *)(b + 0x38) = size;
	I3dMemBlock__InsertList(b, 0, head);
	I3dMemBlock__InsertList(b, 1, (void *)cm[8]);
	return (int)b;
}

int I3dCacheManager__RemoveMemBlock(int *cm, void *b)
{
	I3dMemBlock__ChangeAttributeToGarbage(b, b);
	I3dMemBlock__Destruct(b);
	((int *)cm[23])[cm[24]] = (int)b;
	cm[24]++;
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dCacheManager__MarkMemBlock(int arg0, void *arg1) {
    M2C_FIELD(arg1, int *, 0x30) = (int) (M2C_FIELD(arg1, int *, 0x30) | 0x1000);
    I3dMemBlock__InsertList(arg1, 3, arg0 + 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dCacheManager__KeepMemBlock(void *arg0, void *arg1) {
    M2C_FIELD(arg1, int *, 0x30) = (int) (M2C_FIELD(arg1, int *, 0x30) | 0x100);
    I3dMemBlock__InsertList(arg1, 2, arg0 + 0x18);
    M2C_FIELD(arg0, int *, 8) = (int) (M2C_FIELD(arg0, int *, 8) + M2C_FIELD(arg1, int *, 0x38));
}

typedef struct MBLnk4 { struct MBk4 *next, *prev; } MBLnk4;
typedef struct MBk4 { MBLnk4 l[6]; unsigned int attr; } MBk4;
int I3dCacheManager__ClearAllMarkAttr(char *cm)
{
	MBk4 *h = (MBk4 *)(cm + 0x18);
	MBk4 *b = ((MBk4 *)(cm + 0x18))->l[3].prev;
	MBk4 *n;
	while (b != h) {
		n = b->l[3].prev;
		b->attr &= ~0x1000;
		I3dMemBlock__RemoveList(b, 3);
		b = n;
	}
	return 0;
}

typedef struct MBLnk8 { struct MBk8 *next, *prev; } MBLnk8;
typedef struct MBk8 { MBLnk8 l[6]; unsigned int attr; int f34; int size; } MBk8;
int I3dCacheManager__ClearAllKeepAttr(char *cm)
{
	MBk8 *h = (MBk8 *)(cm + 0x18);
	MBk8 *b = ((MBk8 *)(cm + 0x18))->l[2].prev;
	MBk8 *n;
	while (b != h) {
		b->attr &= ~0x100;
		n = b->l[2].prev;
		I3dMemBlock__RemoveList(b, 2);
		*(int *)(cm + 8) -= b->size;
		b = n;
	}
	return 0;
}

typedef struct MBLnk6 { struct MBk6 *next, *prev; } MBLnk6;
typedef struct MBk6 { MBLnk6 l[6]; unsigned int attr; } MBk6;
int I3dCacheManager__ClearAllNewAttr(cm)
	char *cm;
{
	MBk6 *h = (MBk6 *)(cm + 0x18);
	MBk6 *b = ((MBk6 *)(cm + 0x18))->l[4].prev;
	MBk6 *n;
	while (b != h) {
		n = b->l[4].prev;
		b->attr &= ~0x10000;
		I3dMemBlock__RemoveList(b, 4);
		b = n;
	}
	return 0;
}

typedef struct MBLnk7 { struct MBk7 *next, *prev; } MBLnk7;
typedef struct MBk7 { MBLnk7 l[6]; unsigned int attr; } MBk7;
int I3dCacheManager__ClearAllMoveAttr(char *cm)
{
	MBk7 *h = (MBk7 *)(cm + 0x18);
	MBk7 *b = ((MBk7 *)(cm + 0x18))->l[5].prev;
	MBk7 *n;
	while (b != h) {
		n = b->l[5].prev;
		b->attr &= ~0x100000;
		I3dMemBlock__RemoveList(b, 5);
		b = n;
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ChangeGarbageToCache);

#ifndef NULL
#define NULL ((void *)0)
#endif

void *I3dCacheManager__ChangeContinuousBlockToGarbage(void *arg0, void *arg1, int arg2) {
    void *temp_s0;
    void *var_a1;

    var_a1 = M2C_FIELD(arg1, void **, 4);
    if (var_a1 != arg2) {
        do {
            temp_s0 = M2C_FIELD(var_a1, void **, 4);
            M2C_FIELD(arg1, int *, 0x38) = (int) (M2C_FIELD(arg1, int *, 0x38) + M2C_FIELD(var_a1, int *, 0x38));
            I3dCacheManager__RemoveMemBlock(arg0, var_a1);
            var_a1 = temp_s0;
        } while (temp_s0 != arg2);
    }
    I3dMemBlock__ChangeAttributeToGarbage(arg1, var_a1);
    I3dMemBlock__MoveList(arg1, 1, M2C_FIELD(arg0, int *, 0x20));
    return arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dCacheManager__ChangeMarkedBlockToGarbage(int arg0, int arg1) {
    int var_s3;
    void *temp_s0;
    void *temp_s1;
    void *var_v1;

    var_s3 = 0;
    temp_s1 = arg0 + 0x18;
    var_v1 = M2C_FIELD(temp_s1, void **, 0x1C);
    if (var_v1 != temp_s1) {
        do {
            temp_s0 = M2C_FIELD(var_v1, void **, 0x1C);
            var_s3 += M2C_FIELD(var_v1, int *, 0x38);
            I3dCacheManager__RemoveMemBlock(arg0, var_v1);
            var_v1 = temp_s0;
        } while (temp_s0 != temp_s1);
    }
    I3dCacheManager__CreateNewMemBlockAsGarbage(arg0, var_s3, arg1);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__GarbageCollect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__CheckMarkedBlockSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__SearchMinimumMarkedRange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__AllocCacheMemBlock);

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dCacheManager__Begin(int arg0) {
    I3dCacheManager__ClearAllNewAttr();
    I3dCacheManager__ClearAllMoveAttr(arg0);
    I3dCacheManager__ClearAllKeepAttr(arg0);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__Request);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__End);

int I3dCacheManager__CreateNewMemBlockAsGarbage();
int I3dCacheManager__CreateOriginGarbage(char *cm)
{
	return I3dCacheManager__CreateNewMemBlockAsGarbage(cm, *(int *)(cm + 4), cm + 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dCacheManager__SetBaseAddress(int *arg0, int arg1) {
    *arg0 = arg1;
    I3dCacheManager__PurgeAllCache();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dCacheManager__SetTotalMemSize(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 4) = arg1;
    I3dCacheManager__PurgeAllCache();
}

typedef struct MBLnk5 { struct MBk5 *next, *prev; } MBLnk5;
typedef struct MBk5 { MBLnk5 l[6]; unsigned int attr; } MBk5;
int I3dCacheManager__ClearAllKeepAttr();
int I3dCacheManager__PurgeAllCache(char *cm)
{
	MBk5 *h = (MBk5 *)(cm + 0x18);
	MBk5 *b, *n;
	I3dCacheManager__ClearAllKeepAttr(cm);
	for (b = h->l[0].prev; h != b; b = n) {
		n = b->l[0].prev;
		I3dCacheManager__RemoveMemBlock(cm, b);
	}
	I3dCacheManager__CreateOriginGarbage(cm);
	return 0;
}

int I3dCacheManager__ResetProfile(char *c)
{
	*(int *)(c + 0x64) = 0;
	*(int *)(c + 0x68) = 0;
	*(int *)(c + 0x6C) = 0;
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__Construct);

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dCacheManager__Destruct(void *arg0) {
    int var_s1;
    unsigned int var_s2;

    var_s2 = 0;
    if (M2C_FIELD(arg0, unsigned int *, 0x14) != 0) {
        var_s1 = 0;
        do {
            var_s2 += 1;
            I3dMemBlock__Destruct(M2C_FIELD(arg0, int *, 0x10) + var_s1);
            var_s1 += 0x44;
        } while (var_s2 < (unsigned int) M2C_FIELD(arg0, unsigned int *, 0x14));
    }
    I3dMemBlock__Destruct(arg0 + 0x18);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dCacheManager__CombineSideGarbage(int arg0, void *arg1) {
    int temp_s2;
    int var_s1;
    void *temp_s0;
    void *temp_s0_2;
    void *var_v1;
    void *var_v1_2;

    temp_s2 = arg0 + 0x18;
    var_v1 = M2C_FIELD(arg1, void **, 4);
    var_s1 = M2C_FIELD(arg1, int *, 0x38);
    if (var_v1 != temp_s2) {
loop_1:
        temp_s0 = M2C_FIELD(var_v1, void **, 4);
        if (M2C_FIELD(var_v1, int *, 0x30) & 1) {
            var_s1 += M2C_FIELD(var_v1, int *, 0x38);
            I3dCacheManager__RemoveMemBlock(arg0, var_v1);
            var_v1 = temp_s0;
            if (temp_s0 != temp_s2) {
                goto loop_1;
            }
        }
    }
    var_v1_2 = M2C_FIELD(arg1, void **, 0);
    if (var_v1_2 != temp_s2) {
loop_4:
        temp_s0_2 = M2C_FIELD(var_v1_2, void **, 0);
        if (M2C_FIELD(var_v1_2, int *, 0x30) & 1) {
            var_s1 += M2C_FIELD(var_v1_2, int *, 0x38);
            I3dCacheManager__RemoveMemBlock(arg0, var_v1_2);
            var_v1_2 = temp_s0_2;
            if (temp_s0_2 != temp_s2) {
                goto loop_4;
            }
        }
    }
    M2C_FIELD(arg1, int *, 0x38) = var_s1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dScaleTransF4__Clear(int arg0) {
    I3dVecClear(arg0 + 0x10);
    I3dVecClear(arg0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dScaleTransF4__ImportMatrix);

int I3dPicture__Construct(int *p)
{
	memset(p, 0, 0xA0);
	I3dResourceTag__Construct(p);
	p[4] = 0;
	p[5] = 0;
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dPicture__Destruct(void *arg0) {
    if (M2C_FIELD(arg0, unsigned char *, 0x8C) != 3) {
        M2C_FIELD(arg0, unsigned char *, 0x8C) = 0U;
    } else {
        sceGimPictureDelete(M2C_FIELD(arg0, int *, 0x18));
        M2C_FIELD(arg0, unsigned char *, 0x8C) = 0U;
    }
    I3dPicture__FlushCache(arg0);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dPicture__SetupFromGim_PSP);
