/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct REGION { u8 unk0[0x10]; struct REGION *next; } REGION;
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */



#ifndef NULL
#define NULL ((void *)0)
#endif

void *newRegion(int arg0, int arg1, int arg2, int arg3) {
    void *temp_v0;
    void *var_v1;

    temp_v0 = MEM_malloc(0, 0x18);
    var_v1 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0x10) = 0;
        M2C_FIELD(temp_v0, int *, 0x14) = 0;
        M2C_FIELD(temp_v0, int *, 0) = arg0;
        M2C_FIELD(temp_v0, int *, 4) = arg1;
        M2C_FIELD(temp_v0, int *, 8) = arg2;
        M2C_FIELD(temp_v0, int *, 0xC) = arg3;
        var_v1 = temp_v0;
    }
    return var_v1;
}

void freeRegionList(REGION *r) {
    REGION *next;
    while (r != NULL) {
        next = r->next;
        MEM_free(0, r);
        if (next == r) {
            break;
        }
        r = next;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void insertRegion(void *arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg2, void **, 0x10) = (void *) M2C_FIELD(arg1, void **, 0x10);
    M2C_FIELD(arg2, void **, 0x14) = arg1;
    M2C_FIELD(M2C_FIELD(arg1, void **, 0x10), void **, 0x14) = arg2;
    M2C_FIELD(arg1, void **, 0x10) = arg2;
    if (arg1 == M2C_FIELD(arg0, void **, 0x10)) {
        M2C_FIELD(arg0, void **, 0x10) = arg2;
    }
}

void addRegion(void *mgr, REGION *r) {
    insertRegion(mgr, M2C_FIELD(mgr, void **, 0x10), r);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void removeRegion(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg1, void **, 0x14);
    M2C_FIELD(temp_v1, void **, 0x10) = (void *) M2C_FIELD(arg1, void **, 0x10);
    M2C_FIELD(M2C_FIELD(arg1, void **, 0x10), void **, 0x14) = temp_v1;
    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    if (temp_v0 == arg1) {
        temp_v0_2 = M2C_FIELD(temp_v0, void **, 0x14);
        if (temp_v0_2 != NULL) {
            M2C_FIELD(arg0, void **, 0x10) = temp_v0_2;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", overlayRegion);

void *lfm_createPageRegion(void *box, int w) {
    void *r;
    void *n;
    void *st;

    r = MEM_malloc(0, 0x14);
    if (r == NULL)
        return NULL;
    M2C_FIELD(r, void **, 0) = box;
    st = M2C_FIELD(box, void **, 0x24);
    M2C_FIELD(r, int *, 4) = w - M2C_FIELD(st, s16 *, 0x26) - M2C_FIELD(st, s16 *, 0x36) - M2C_FIELD(st, s16 *, 0x2E) - M2C_FIELD(st, s16 *, 0x2A) - M2C_FIELD(st, s16 *, 0x32) - M2C_FIELD(st, s16 *, 0x22);
    M2C_FIELD(r, int *, 8) = 0;
    M2C_FIELD(r, void **, 0xC) = MEM_malloc(0, 0x18);
    if (M2C_FIELD(r, void **, 0xC) == NULL) {
        MEM_free(0, r);
        return NULL;
    }
    n = MEM_malloc(0, 0x18);
    if (n == NULL) {
        MEM_free(0, M2C_FIELD(r, void **, 0xC));
        MEM_free(0, r);
        return NULL;
    }
    M2C_FIELD(M2C_FIELD(r, void **, 0xC), void **, 0x10) = n;
    M2C_FIELD(M2C_FIELD(r, void **, 0xC), int *, 0x14) = 0;
    M2C_FIELD(n, void **, 0x10) = n;
    M2C_FIELD(n, void **, 0x14) = M2C_FIELD(r, void **, 0xC);
    M2C_FIELD(r, void **, 0x10) = M2C_FIELD(r, void **, 0xC);
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void lfm_destroyPageRegion(void *arg0) {
    freeRegionList(M2C_FIELD(arg0, int *, 0xC));
    MEM_free(0, arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void lfm_resetPageRegion(void *arg0, int arg1) {
    void *temp_v0;
    void *temp_v0_2;

    M2C_FIELD(arg0, int *, 4) = arg1;
    M2C_FIELD(arg0, int *, 8) = 0;
    freeRegionList(M2C_FIELD(arg0, void **, 0xC));
    temp_v0 = MEM_malloc(0, 0x18);
    M2C_FIELD(arg0, void **, 0xC) = temp_v0;
    if (temp_v0 != NULL) {
        temp_v0_2 = MEM_malloc(0, 0x18);
        if (temp_v0_2 == NULL) {
            MEM_free(0, M2C_FIELD(arg0, void **, 0xC));
            return;
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x10) = temp_v0_2;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), int *, 0x14) = 0;
        M2C_FIELD(temp_v0_2, void **, 0x10) = temp_v0_2;
        M2C_FIELD(temp_v0_2, void **, 0x14) = (void *) M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(arg0, void **, 0x10) = (void *) M2C_FIELD(arg0, void **, 0xC);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_addFloat);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_getHorizontalArea);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_getVerticalPosition);

#ifndef NULL
#define NULL ((void *)0)
#endif
int lfm_getHeight(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", getNextTerminalFrame);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", setFocusBoxnode);
