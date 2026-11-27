#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxBmgAllocEx(M2C_UNK, int, int, int);      /* extern */
extern int D_0011FC34;
M2C_UNK sgxListEnumID(M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_0011FC20;
extern unsigned char D_0011FC10;


void *SlotGetAt_7A70C(int, const char *);
void sgxDI();
void sgxEI();

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", D_00109F94);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", SlotGetAt_7A70C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgAllocEx);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxBmgAlloc(int arg0, int arg1, int arg2) {
    sgxBmgAllocEx(-1, arg0, arg1, arg2);
}

int sgxBmgAllocSub(int a, int b)
{
    return sgxBmgAllocEx(a, 0, b, 0);
}

int sgxBmgLock(int id)
{
    char *p = SlotGetAt_7A70C(id, "Lock");
    if (p == NULL) return 0;
    sgxDI();
    (*(unsigned short *)(p + 0x10))++;
    sgxEI();
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgAlignBuf);

void *sgxBmgGetBuf(int id)
{
    char *p = SlotGetAt_7A70C(id, "GetBuf");
    if (p == NULL) return NULL;
    return *(void **)(p + 0x24);
}

int sgxBmgGetSize(int id)
{
    char *p = SlotGetAt_7A70C(id, "GetSize");
    if (p == NULL) return 0;
    return *(int *)(p + 0x28);
}

int sgxBmgGetRefCount(int id)
{
    char *p = SlotGetAt_7A70C(id, "GetRefCount");
    if (p == NULL) return 0;
    return *(short *)(p + 0x10);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgIncBuf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgDecBuf);

char *sgxBmgGetHead(int id)
{
    char *p = SlotGetAt_7A70C(id, "GetHead");
    if (p == NULL) return NULL;
    return *(char **)(p + 0x24) + *(int *)(p + 0x34);
}

char *sgxBmgGetTail(int id)
{
    char *p = SlotGetAt_7A70C(id, "GetTail");
    if (p == NULL) return NULL;
    return *(char **)(p + 0x24) + *(int *)(p + 0x38);
}

char *sgxBmgGetHeadOfs(int id, int ofs)
{
    char *p = SlotGetAt_7A70C(id, "GetHeadOfs");
    if (p == NULL) return NULL;
    return *(char **)(p + 0x24) + (*(int *)(p + 0x34) + ofs) % *(int *)(p + 0x28);
}

char *sgxBmgGetTailOfs(int id, int ofs)
{
    char *p = SlotGetAt_7A70C(id, "GetTailOfs");
    if (p == NULL) return NULL;
    return *(char **)(p + 0x24) + (*(int *)(p + 0x38) + ofs) % *(int *)(p + 0x28);
}

int sgxBmgGetFree(int id)
{
    char *p = SlotGetAt_7A70C(id, "GetFree");
    if (p == NULL) return 0;
    return *(int *)(p + 0x28) - *(int *)(p + 0x3C);
}

int sgxBmgGetLinearFree(int id)
{
    char *p = SlotGetAt_7A70C(id, "GetLinearFree");
    int a, b;
    if (p == NULL) return 0;
    b = *(int *)(p + 0x28) - *(int *)(p + 0x3C);
    a = *(int *)(p + 0x28) - *(int *)(p + 0x34);
    return b < a ? b : a;
}

int sgxBmgGetLeft(int id)
{
    char *p = SlotGetAt_7A70C(id, "GetLeft");
    if (p == NULL) return 0;
    return *(int *)(p + 0x3C);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetLinearLeft);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetLinearLeftOfs);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", D_0010A10C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgWrite);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgRead);

void sgxBmgWriteTerm(int id)
{
    char *p = SlotGetAt_7A70C(id, "WriteTerm");
    if (p != NULL) p[0x12] = 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgIsFinished);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgSetLowBufCallback);

typedef void (*BmgLowCb)(int, int);
void CheckLowBuf(char *b)
{
    BmgLowCb cb;
    sgxDI();
    cb = *(BmgLowCb *)(b + 0x44);
    if (cb != NULL && *(int *)(b + 0x3C) <= *(int *)(b + 0x50))
        cb(*(int *)(b + 0x4C), *(int *)(b + 0x48));
    sgxEI();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxBmgGetMaxSlotCount(void) {
    return D_0011FC34;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxBmgGetFreeSlotCount(void) {
    sgxListEnumID(&D_0011FC20, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxBmgEnumUseID(int arg0) {
    sgxListEnumID(&D_0011FC10, arg0);
}
