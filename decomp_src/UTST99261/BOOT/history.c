/* cflags: -O1 */
#include "common.h"
#include "parse_hist.h"
#include "m2c_macros.h"
int HST_initHistory();                              /* extern */
extern int history;
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK OS_thread_mutex_lock(int);                  /* extern */
M2C_UNK OS_thread_mutex_unlock(int);                /* extern */
int HST_httpHeaderDuplicate(int);                   /* extern */
M2C_UNK HST_httpHeaderFree(int);                    /* extern */
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK HST_deleteHistoryNode(int);                 /* extern */



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_initHistory);

#ifndef NULL
#define NULL ((void *)0)
#endif

int HST_attachHistory(void) {
    int var_v1;

    var_v1 = 0;
    if (history == 0) {
        var_v1 = HST_initHistory();
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_freeHistory);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void *HST_createHistoryNode(void) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = MEM_malloc(0, 0xB8);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        memset(temp_v0, 0, 0xB8U);
        var_v0 = temp_v0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_deleteHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_registHistoryNode);

void *HST_getHeadHistoryNode(void) {
    void *cur = M2C_FIELD(history, void **, 0);

    return cur != NULL ? M2C_FIELD(cur, void **, 0) : NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getHistoryLength);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getCurrentIndex);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_addSiblingHistoryNode(void *arg0, void *arg1) {
    void *var_a0;

    var_a0 = arg0;
    if (M2C_FIELD(var_a0, int *, 0xB0) != 0) {
        do {
            var_a0 = M2C_FIELD(var_a0, void **, 0xB0);
        } while (M2C_FIELD(var_a0, int *, 0xB0) != 0);
    }
    M2C_FIELD(var_a0, void **, 0xB0) = arg1;
    M2C_FIELD(arg1, int *, 0xA8) = (int) M2C_FIELD(var_a0, int *, 0xA8);
    M2C_FIELD(arg1, void **, 0xB4) = var_a0;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getSiblingHistoryNode(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xB0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getPrevSiblingHistoryNode(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xB4);
}

int HST_addChildHistoryNode(void *parent, void *child) {
    if (M2C_FIELD(parent, void **, 0xAC) != NULL) {
        return HST_addSiblingHistoryNode(M2C_FIELD(parent, void **, 0xAC), child);
    }
    M2C_FIELD(parent, void **, 0xAC) = child;
    M2C_FIELD(child, void **, 0xA8) = parent;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getChildHistoryNode(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xAC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getParentHistoryNode(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xA8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int HST_moveFrontHistory(void) {
    void *temp_v0;

    OS_thread_mutex_lock(M2C_FIELD(history, int *, 8));
    temp_v0 = M2C_FIELD(history, void **, 0);
    if ((temp_v0 == NULL) || (M2C_FIELD(temp_v0, int *, 4) == 0)) {
        OS_thread_mutex_unlock(M2C_FIELD(history, int *, 8));
        return -1;
    }
    M2C_FIELD(history, void **, 0) = (void *) M2C_FIELD(M2C_FIELD(history, void **, 0), void **, 4);
    OS_thread_mutex_unlock(M2C_FIELD(history, int *, 8));
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int HST_moveBackHistory(void) {
    void *temp_v0;

    OS_thread_mutex_lock(M2C_FIELD(history, int *, 8));
    temp_v0 = M2C_FIELD(history, void **, 0);
    if ((temp_v0 == NULL) || (M2C_FIELD(temp_v0, int *, 8) == 0)) {
        OS_thread_mutex_unlock(M2C_FIELD(history, int *, 8));
        return -1;
    }
    M2C_FIELD(history, void **, 0) = (void *) M2C_FIELD(M2C_FIELD(history, void **, 0), void **, 8);
    OS_thread_mutex_unlock(M2C_FIELD(history, int *, 8));
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int HST_getHistoryWithOffset(int arg0) {
    int *var_s0;
    int var_a0;
    int var_a1;
    int var_v0;

    OS_thread_mutex_lock(M2C_FIELD(history, int *, 8));
    if (arg0 >= 0) {
        var_s0 = M2C_FIELD(history, int **, 0);
        var_a1 = arg0;
        if ((var_s0 != NULL) & (arg0 > 0)) {
            do {
                var_s0 = M2C_FIELD(var_s0, int **, 4);
                var_a1 -= 1;
            } while ((var_s0 != NULL) & (var_a1 > 0));
        }
    } else {
        var_a0 = -arg0;
        var_s0 = M2C_FIELD(history, int **, 0);
        if ((var_s0 != NULL) & (var_a0 > 0)) {
            do {
                var_s0 = M2C_FIELD(var_s0, int **, 8);
                var_a0 -= 1;
            } while ((var_s0 != NULL) & (var_a0 > 0));
        }
    }
    OS_thread_mutex_unlock(M2C_FIELD(history, int *, 8));
    var_v0 = 0;
    if (var_s0 != NULL) {
        var_v0 = *var_s0;
    }
    return var_v0;
}

int HST_setCurURI(HstStr *s, const char *src, int len) {
    char *p = MEM_malloc(0, len + 1);

    if (p == NULL) {
        return -1;
    }
    if (s->p != NULL) {
        MEM_free(0, s->p);
    }
    memcpy(p, src, len);
    p[len] = 0;
    s->p = p;
    s->len = len;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getCurURI(int *arg0) {
    return *arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getCurURIlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setBaseURI);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getBaseURI(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getBaseURIlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xC);
}

int HST_setRefURI(void *node, const char *src, int len) {
    char *p = MEM_malloc(0, len + 1);

    if (p == NULL) {
        return -1;
    }
    if (M2C_FIELD(node, char **, 0x10) != NULL) {
        MEM_free(0, M2C_FIELD(node, char **, 0x10));
    }
    memcpy(p, src, len);
    p[len] = 0;
    M2C_FIELD(node, char **, 0x10) = p;
    M2C_FIELD(node, int *, 0x14) = len;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getRefURI(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getRefURIlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x14);
}

int HST_setTargetName(void *node, const char *src, int len) {
    char *p = MEM_malloc(0, len + 1);

    if (p == NULL) {
        return -1;
    }
    if (M2C_FIELD(node, char **, 0x18) != NULL) {
        MEM_free(0, M2C_FIELD(node, char **, 0x18));
    }
    memcpy(p, src, len);
    p[len] = 0;
    M2C_FIELD(node, char **, 0x18) = p;
    M2C_FIELD(node, int *, 0x1C) = len;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getTargetName(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getTargetNamelen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x1C);
}

int HST_setDefaultTarget(void *node, const char *src, int len) {
    char *p = MEM_malloc(0, len + 1);

    if (p == NULL) {
        return -1;
    }
    if (M2C_FIELD(node, char **, 0x20) != NULL) {
        MEM_free(0, M2C_FIELD(node, char **, 0x20));
    }
    memcpy(p, src, len);
    p[len] = 0;
    M2C_FIELD(node, char **, 0x20) = p;
    M2C_FIELD(node, int *, 0x24) = len;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getDefaultTarget(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getDefaultTargetlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x24);
}

int HST_setTitle(void *node, const char *src, int len) {
    char *p = MEM_malloc(0, len + 1);

    if (p == NULL) {
        return -1;
    }
    if (M2C_FIELD(node, char **, 0x28) != NULL) {
        MEM_free(0, M2C_FIELD(node, char **, 0x28));
    }
    memcpy(p, src, len);
    p[len] = 0;
    M2C_FIELD(node, char **, 0x28) = p;
    M2C_FIELD(node, int *, 0x2C) = len;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getTitle(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x28);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getTitlelen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x2C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setJSURI(void *arg0, void *arg1) {
    int temp_v0;
    int var_v0;
    void *var_v1;

    temp_v0 = M2C_FIELD(arg0, int *, 0x78);
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, void **, 0x74) = arg1;
        var_v0 = 1;
        goto block_6;
    }
    if (temp_v0 > 0) {
        var_v1 = M2C_FIELD(arg0, void **, 0x74);
        if (M2C_FIELD(var_v1, int *, 0xB0) != 0) {
            do {
                var_v1 = M2C_FIELD(var_v1, void **, 0xB0);
            } while (M2C_FIELD(var_v1, int *, 0xB0) != 0);
        }
        M2C_FIELD(var_v1, void **, 0xB0) = arg1;
        var_v0 = M2C_FIELD(arg0, int *, 0x78) + 1;
block_6:
        M2C_FIELD(arg0, int *, 0x78) = var_v0;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getJSURIlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x78);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getJSURI);

int HST_deleteJSURI(void *node) {
    void *p, *next;

    if (M2C_FIELD(node, void **, 0x74) == NULL) {
        return 0;
    }
    for (p = M2C_FIELD(node, void **, 0x74); p != NULL; p = next) {
        MEM_free(0, M2C_FIELD(p, void **, 0));
        if (M2C_FIELD(p, void **, 0x10) != NULL) {
            MEM_free(0, M2C_FIELD(p, void **, 0x10));
        }
        next = M2C_FIELD(p, void **, 0xB0);
        MEM_free(0, p);
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setCSSURI(void *arg0, void *arg1) {
    int temp_v0;
    int var_v0;
    void *var_v1;

    temp_v0 = M2C_FIELD(arg0, int *, 0x80);
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, void **, 0x7C) = arg1;
        var_v0 = 1;
        goto block_6;
    }
    if (temp_v0 > 0) {
        var_v1 = M2C_FIELD(arg0, void **, 0x7C);
        if (M2C_FIELD(var_v1, int *, 0xB0) != 0) {
            do {
                var_v1 = M2C_FIELD(var_v1, void **, 0xB0);
            } while (M2C_FIELD(var_v1, int *, 0xB0) != 0);
        }
        M2C_FIELD(var_v1, void **, 0xB0) = arg1;
        var_v0 = M2C_FIELD(arg0, int *, 0x80) + 1;
block_6:
        M2C_FIELD(arg0, int *, 0x80) = var_v0;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getCSSURIlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x80);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getCSSURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_deleteCSSURI);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setStyleSheet(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x70) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getStyleSheet(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x70);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setSourceType(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x30) = (int) (arg1 != 0);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getSourceType(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x30);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setMemoIndex(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x34) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getMemoIndex(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x34);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setMethodType(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x38) = (int) (arg1 != 0);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getMethodType(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x38);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setRequestFlag(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x3C) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getRequestFlag(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x3C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setCharSet(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x44) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getCharSet(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x44);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setSessionID(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x48) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getSessionID(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x48);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setUnitId(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x4C) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getUnitId(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x4C);
}

int HST_setAuthUsername(void *node, const char *src, int len) {
    char *p = MEM_malloc(0, len + 1);

    if (p == NULL) {
        return -1;
    }
    if (M2C_FIELD(node, char **, 0x50) != NULL) {
        MEM_free(0, M2C_FIELD(node, char **, 0x50));
    }
    memcpy(p, src, len);
    p[len] = 0;
    M2C_FIELD(node, char **, 0x50) = p;
    M2C_FIELD(node, int *, 0x54) = len;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getAuthUsername(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x50);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getAuthUsernamelen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x54);
}

int HST_setAuthPassword(void *node, const char *src, int len) {
    char *p = MEM_malloc(0, len + 1);

    if (p == NULL) {
        return -1;
    }
    if (M2C_FIELD(node, char **, 0x58) != NULL) {
        MEM_free(0, M2C_FIELD(node, char **, 0x58));
    }
    memcpy(p, src, len);
    p[len] = 0;
    M2C_FIELD(node, char **, 0x58) = p;
    M2C_FIELD(node, int *, 0x5C) = len;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getAuthPassword(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x58);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getAuthPasswordlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x5C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int HST_setHttpHeader(void *arg0, int arg1) {
    int temp_a0;
    int temp_v0;
    int var_v0;

    temp_v0 = HST_httpHeaderDuplicate(arg1);
    var_v0 = -1;
    if (temp_v0 != 0) {
        temp_a0 = M2C_FIELD(arg0, int *, 0x60);
        if (temp_a0 != 0) {
            HST_httpHeaderFree(temp_a0);
        }
        M2C_FIELD(arg0, int *, 0x60) = temp_v0;
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getHttpHeader(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x60);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setPostData);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getPostData(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x64);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int HST_freePostData(void *arg0) {
    void *temp_a1;
    void *temp_a1_2;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x64);
    if (temp_s0 != NULL) {
        temp_a1 = M2C_FIELD(temp_s0, void **, 0);
        if (temp_a1 != NULL) {
            MEM_free(0, temp_a1);
        }
        temp_a1_2 = M2C_FIELD(temp_s0, void **, 4);
        if (temp_a1_2 != NULL) {
            MEM_free(0, temp_a1_2);
        }
        MEM_free(0, temp_s0);
        M2C_FIELD(arg0, void **, 0x64) = NULL;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setDomObject(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x68) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getDomObject(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x68);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_createFragmentIDs);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setFragmentIDs);

#ifndef NULL
#define NULL ((void *)0)
#endif

void HST_deleteFragmentIDs(void *arg0) {
    freeFragmentIDs(M2C_FIELD(arg0, int *, 0x8C));
    M2C_FIELD(arg0, int *, 0x8C) = 0;
    M2C_FIELD(arg0, int *, 0x88) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *HST_getFragmentIDs(void *arg0, int arg1) {
    M2C_UNK *var_a2;
    int temp_a1;
    int var_v1;

    temp_a1 = arg1 + M2C_FIELD(arg0, int *, 0x88);
    var_a2 = arg0 + 0x8C;
    if ((temp_a1 < 0) || (M2C_FIELD(arg0, int *, 0x84) < temp_a1)) {
        return NULL;
    }
    var_v1 = 0;
    if (temp_a1 > 0) {
        do {
            var_v1 += 1;
            var_a2 = *var_a2;
        } while (var_v1 < temp_a1);
    }
    return var_a2;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getFragmentIDsPosition(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x88);
}

int HST_moveFragmentIDs(void *node, int d) {
    int i = M2C_FIELD(node, int *, 0x88) + d;

    if (i < 0 || M2C_FIELD(node, int *, 0x84) < i) {
        return 0;
    }
    M2C_FIELD(node, int *, 0x88) = i;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setTransStatus(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0xA4) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getTransStatus(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xA4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchSessionIDHistoryNode);

void *HST_searchRequestFlagHistoryNode(int flag) {
    int key = flag;

    return searchHistoryNodeInner(2, &key, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void HST_searchDocumentHistoryNode(int arg0) {
    searchHistoryNodeInner(3, arg0, 0);
}

void *HST_searchTargetNameHistoryNode(void *a, void *b) {
    void *key = b;

    return searchHistoryNodeInner(4, a, &key);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchUriHistoryNode);

#ifndef NULL
#define NULL ((void *)0)
#endif

int HST_getHistoryGarbageList(void) {
    return M2C_FIELD(history, int *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void HST_flushHistoryGarbageList(void) {
    void *temp_s0;
    void *var_a1;

    var_a1 = M2C_FIELD(M2C_FIELD(history, void **, 4), void **, 4);
    if (var_a1 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_a1, void **, 4);
            MEM_free(0, var_a1);
            var_a1 = temp_s0;
        } while (temp_s0 != NULL);
    }
    M2C_FIELD(M2C_FIELD(history, void **, 4), int *, 4) = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", searchExtFileSessionID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", searchExtFileHistoryURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getParentExtSessionID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getParentExtHistoryURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getExtHistoryURI);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *getReqFlagCSSHistURI(void *arg0, int arg1) {
    void *var_a0;
    void *var_v1;

    var_a0 = arg0;
    var_v1 = NULL;
    if (var_a0 != NULL) {
loop_1:
        var_v1 = var_a0;
        if (M2C_FIELD(var_a0, int *, 0x3C) != arg1) {
            var_a0 = M2C_FIELD(var_a0, void **, 0xB0);
            if (var_a0 == NULL) {
                var_v1 = NULL;
            } else {
                goto loop_1;
            }
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchCSSRequestFlag);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *HST_getReqFlagJSHistURI(void *arg0, int arg1) {
    void *var_a0;
    void *var_v1;

    var_a0 = arg0;
    var_v1 = NULL;
    if (var_a0 != NULL) {
loop_1:
        var_v1 = var_a0;
        if (M2C_FIELD(var_a0, int *, 0x3C) != arg1) {
            var_a0 = M2C_FIELD(var_a0, void **, 0xB0);
            if (var_a0 == NULL) {
                var_v1 = NULL;
            } else {
                goto loop_1;
            }
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchJSRequestFlag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_diffHistoryNodes);

#ifndef NULL
#define NULL ((void *)0)
#endif

void HST_deleteCurrentHistory(void) {
    void *temp_a0;
    void *temp_s1;

    OS_thread_mutex_lock(M2C_FIELD(history, int *, 8));
    temp_a0 = M2C_FIELD(history, void **, 0);
    temp_s1 = M2C_FIELD(temp_a0, void **, 8);
    deleteHistory(temp_a0);
    M2C_FIELD(history, void **, 0) = temp_s1;
    OS_thread_mutex_unlock(M2C_FIELD(history, int *, 8));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void deleteHistory(void *arg0) {
    void *temp_v1;
    void *temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, void **, 4);
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, void **, 8) = (void *) M2C_FIELD(arg0, void **, 8);
    }
    temp_v1_2 = M2C_FIELD(arg0, void **, 8);
    if (temp_v1_2 != NULL) {
        M2C_FIELD(temp_v1_2, void **, 4) = (void *) M2C_FIELD(arg0, void **, 4);
    }
    HST_deleteHistoryNode(M2C_FIELD(arg0, int *, 0));
    MEM_free(0, arg0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", searchHistoryNodeInner);

void addHistoryGarbage(void *p) {
    void **g = MEM_malloc(0, 8);
    void *q;

    g[0] = p;
    g[1] = NULL;
    if (M2C_FIELD(history, void **, 4) == NULL) {
        M2C_FIELD(history, void **, 4) = g;
        return;
    }
    for (q = M2C_FIELD(history, void **, 4); M2C_FIELD(q, void **, 4) != NULL; q = M2C_FIELD(q, void **, 4)) {
    }
    M2C_FIELD(q, void **, 4) = g;
}

int uricmp_5704C(HstStr *a, HstStr *b) {
    int i;

    if (a->len != b->len) {
        return 0;
    }
    for (i = 0; i < a->len; i++) {
        if (a->p[i] != b->p[i]) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", freeFragmentIDs);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_setRequestResult(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x40) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getRequestResult(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x40);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_httpHeaderDisassemble);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_httpHeaderDuplicate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_httpHeaderFree);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/history", D_00134D78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/history", D_00134D7C);
