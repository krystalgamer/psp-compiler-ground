#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dResourceTag__PurgeCache();               /* extern */
M2C_UNK I3dCacheManager__RemoveMemBlock(void *, void *); /* extern */
M2C_UNK I3dMemBlock__ChangeAttributeToGarbage(void *, void *); /* extern */
M2C_UNK I3dMemBlock__MoveList(void *, M2C_UNK, int); /* extern */
M2C_UNK I3dCacheManager__CreateNewMemBlockAsGarbage(int, int, int); /* extern */
M2C_UNK I3dCacheManager__ClearAllKeepAttr(int);     /* extern */
M2C_UNK I3dCacheManager__ClearAllMoveAttr(int);     /* extern */
M2C_UNK I3dCacheManager__ClearAllNewAttr();         /* extern */
M2C_UNK I3dMemBlock__Destruct(void *);              /* extern */
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__MoveList);

int I3dMemBlock__ChangeAttributeToCache(char *b, void *t)
{
	*(void **)(b + 0x40) = t;
	*(unsigned int *)(b + 0x30) = (*(unsigned int *)(b + 0x30) & ~1) | 0x10;
	return I3dResourceTag__SetMemBlock(t, b);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__ChangeAttributeToGarbage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__Construct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__Destruct);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__CreateNewMemBlockAsGarbage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__RemoveMemBlock);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ClearAllMarkAttr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ClearAllKeepAttr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ClearAllNewAttr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ClearAllMoveAttr);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__PurgeAllCache);

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
