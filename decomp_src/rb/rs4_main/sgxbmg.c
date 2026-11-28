/* cflags: -O2 -fno-strict-aliasing */
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

extern const char D_00109F94[];
extern unsigned char gWork_11FC0C;
extern int gSgxDebugFlags;
extern int gSgxPrefWarn;
int sgxPrintfPref(int, const void *, int, const char *, ...);
typedef struct { char pad[0x24]; char *slots; int num; } BmgWorkS;

void sgxBmgFree(int);
void sgxFree(void *);
void *memset(void *, int, unsigned int);
extern unsigned char D_0011FC10;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", D_00109F94);

#define WW ((BmgWorkS *)&gWork_11FC0C)
void *SlotGetAt_7A70C(int id, const char *name)
{
    if (id >= 0 && id <= WW->num - 1) {
        char *p = WW->slots + id * 0x54;
        if (*(int *)(p + 0xC) & 1) return p;
    }
    if (name != NULL && (gSgxDebugFlags & 2)) {
        sgxPrintfPref(gSgxPrefWarn, D_00109F94, 0x69, "sgxBmg%s unknown ID (%d)\n", name, id);
        return NULL;
    }
    return NULL;
}
#undef WW

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

void sgxBmgAlignBuf(int id, int al, int sz)
{
    char *p = SlotGetAt_7A70C(id, "AlignBuf");
    int base, top, len;
    if (p == NULL) return;
    base = *(int *)(p + 0x1C);
    top = base;
    if (al > 0) top = (base + al - 1) / al * al;
    len = *(int *)(p + 0x20) - (top - base);
    if (sz > 0) len = len / sz * sz;
    *(int *)(p + 0x24) = top;
    *(int *)(p + 0x28) = len;
    *(int *)(p + 0x2C) = al;
    *(int *)(p + 0x30) = sz;
}

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

int sgxBmgIncBuf(int id, int n)
{
    char *p = SlotGetAt_7A70C(id, "IncBuf");
    int pos;
    if (p == NULL) return 0;
    n = ((n < sgxBmgGetFree(id) ? n : sgxBmgGetFree(id)) < 0 ? 0 : (n < sgxBmgGetFree(id) ? n : sgxBmgGetFree(id)));
    sgxDI();
    pos = *(int *)(p + 0x34) + n;
    while (pos >= *(int *)(p + 0x28)) pos = pos - *(int *)(p + 0x28);
    *(int *)(p + 0x34) = pos;
    *(volatile int *)(p + 0x3C) += n;
    sgxEI();
    return n;
}

int sgxBmgDecBuf(int id, int n)
{
    char *p = SlotGetAt_7A70C(id, "DecBuf");
    int pos;
    if (p == NULL) return 0;
    n = ((n < sgxBmgGetLeft(id) ? n : sgxBmgGetLeft(id)) < 0 ? 0 : (n < sgxBmgGetLeft(id) ? n : sgxBmgGetLeft(id)));
    sgxDI();
    pos = *(int *)(p + 0x38) + n;
    while (pos >= *(int *)(p + 0x28)) pos = pos - *(int *)(p + 0x28);
    *(int *)(p + 0x38) = pos;
    *(volatile int *)(p + 0x3C) -= n;
    sgxEI();
    CheckLowBuf(p);
    return n;
}

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

extern const char D_0010A10C[];
int sgxBmgGetLinearLeft(int id)
{
    char *b = SlotGetAt_7A70C(id, D_0010A10C);
    int n, r;
    if (b == NULL) return 0;
    r = *(int *)(b + 0x3C);
    n = *(int *)(b + 0x28) - *(int *)(b + 0x38);
    return r < n ? r : n;
}

extern const char D_0010A10C[];
int sgxBmgGetLinearLeftOfs(int id, int ofs)
{
    char *b = SlotGetAt_7A70C(id, D_0010A10C);
    int n, r;
    if (b == NULL) return 0;
    n = *(int *)(b + 0x28) - (*(int *)(b + 0x38) + ofs) % *(int *)(b + 0x28);
    r = *(int *)(b + 0x3C) - ofs;
    return r < n ? r : n;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", D_0010A10C);

int sgxBmgWrite(int id, char *src, int size)
{
    int done, n;
    if (SlotGetAt_7A70C(id, "Write") == NULL) return 0;
    for (done = 0; done < size; done += n) {
        n = size - done < sgxBmgGetLinearFree(id) ? size - done : sgxBmgGetLinearFree(id);
        if (n <= 0) break;
        memcpy(sgxBmgGetHead(id), src + done, n);
        sgxBmgIncBuf(id, n);
    }
    return done;
}

int sgxBmgRead(int id, char *dst, int size)
{
    int done, n;
    if (SlotGetAt_7A70C(id, "Read") == NULL) return 0;
    for (done = 0; done < size; done += n) {
        n = size - done < sgxBmgGetLinearLeft(id) ? size - done : sgxBmgGetLinearLeft(id);
        if (n <= 0) break;
        memcpy(dst + done, sgxBmgGetTail(id), n);
        sgxBmgDecBuf(id, n);
    }
    return done;
}

void sgxBmgWriteTerm(int id)
{
    char *p = SlotGetAt_7A70C(id, "WriteTerm");
    if (p != NULL) p[0x12] = 1;
}

int sgxBmgIsFinished(int id)
{
    char *p = SlotGetAt_7A70C(id, "IsFinished");
    if (p == NULL) return 0;
    if (*(signed char *)(p + 0x12) && sgxBmgGetLeft(id) <= 0) return 1;
    return 0;
}

void CheckLowBuf(char *b);
void sgxBmgSetLowBufCallback(int id, void *cb, int arg, int lvl, int arg2)
{
    char *p = SlotGetAt_7A70C(id, "SetLowBufCallback");
    if (p == NULL) return;
    {
        int n = *(int *)(p + 0x28);
        n = lvl < n ? lvl : n;
        lvl = n < 0 ? 0 : n;
    }
    sgxDI();
    *(void **)(p + 0x44) = cb;
    *(int *)(p + 0x4C) = arg;
    *(int *)(p + 0x48) = arg2;
    *(int *)(p + 0x50) = lvl;
    sgxEI();
    CheckLowBuf(p);
}

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
