/* cflags: -O1 */
#include "common.h"
#include "parse_hist.h"
#include "m2c_macros.h"
#define HL(o) M2C_FIELD(history, int *, o)
extern char D_00134D78[];
extern char D_00134D7C[];
void *getReqFlagCSSHistURI(void *arg0, int arg1);
void *HST_getReqFlagJSHistURI(void *arg0, int arg1);
int HST_initHistory();                              /* extern */
extern int history;
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK OS_thread_mutex_lock(int);                  /* extern */
M2C_UNK OS_thread_mutex_unlock(int);                /* extern */
int HST_httpHeaderDuplicate(int);                   /* extern */
M2C_UNK HST_httpHeaderFree(int);                    /* extern */
void MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK HST_deleteHistoryNode(int);                 /* extern */



typedef struct HEnt { HstNode *root; struct HEnt *prev; struct HEnt *next; } HEnt;
int strncmp(const char *a, const char *b, unsigned int n);
typedef struct { void *x0; void *x4; } HPAIR;
typedef struct HCOOK { void *x0; void *x4; void *x8; void *xC; void *x10; int x14; struct HCOOK *next; } HCOOK;
typedef struct { void *x00; int x04; int x08; void *x0C; void *x10; void *x14; void *x18; void *x1C; void *x20; HPAIR *x24; HPAIR *x28; HCOOK *x2C; } HHDRF;
void *OS_thread_mutex_create(void);
int OS_thread_mutex_init(void *, void *attr);
void addHistoryGarbage(void *p);
void deleteHistory(void *arg0);
void OS_thread_mutex_destroy(void *);
int HST_freePostData(void *arg0);
void *memcpy(void *, const void *, unsigned int);
void URL_splitURL(void **parts, char *url);
unsigned int strlen(const char *);
char *strcpy(char *, const char *);
int strcmp(const char *, const char *);
void *memset(void *, int, unsigned int);
typedef struct HDCOOK { char *x0; char *x4; char *x8; char *xC; char *x10; int secure : 1; struct HDCOOK *next; } HDCOOK;
typedef struct HDPAIR { char *x0; char *x4; } HDPAIR;
typedef struct HDHDR { char *x00; int x04; int x08; char *x0C; char *x10; char *x14; char *x18; char *x1C; char *x20; HDPAIR *x24; HDPAIR *x28; HDCOOK *x2C; int x30; } HDHDR;
char *strlinedup();
int HST_initHistory(void) {
    int *p;
    int *h;

    history = (int)MEM_malloc(0, 0xC);
    if (history == 0) {
        return -1;
    }
    p = (int *)history;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    h = (int *)history;
    h[2] = OS_thread_mutex_create();
    if (h[2] == 0) {
        return -1;
    }
    if (OS_thread_mutex_init(HL(8), 0) != 0) {
        return -1;
    }
    addHistoryGarbage(-1);
    return 0;
}

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

int HST_freeHistory(void) {
    int *top;
    int *p;
    int *next;

    if (history == 0) {
        return -1;
    }
    OS_thread_mutex_lock(HL(8));
    top = (int *)HL(0);
    if (top != NULL) {
        while (top[1] != 0) {
            deleteHistory(top[1]);
        }
        while (top[2] != 0) {
            deleteHistory(top[2]);
        }
        deleteHistory(top);
        HL(0) = 0;
    }
    for (p = (int *)HL(4); p != NULL; p = next) {
        next = (int *)p[1];
        MEM_free(0, p);
    }
    OS_thread_mutex_unlock(HL(8));
    OS_thread_mutex_destroy(HL(8));
    MEM_free(0, history);
    history = 0;
    return 0;
}

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

int HST_deleteHistoryNode(int arg) {
    HstNode *n = (HstNode *)arg;
    HstNode *parent;
    HstNode *next;
    HstNode *prev;

    next = n->next;
    prev = M2C_FIELD(n, HstNode **, 0xB4);
    parent = n->parent;
    if (next != NULL) {
        M2C_FIELD(next, HstNode **, 0xB4) = prev;
    }
    if (prev != NULL) {
        prev->next = next;
    }
    if (parent != NULL) {
        if (parent->child == n) {
            parent->child = next;
        }
    }
    n->next = NULL;
    M2C_FIELD(n, HstNode **, 0xB4) = NULL;
    n->parent = NULL;
    while (n != NULL) {
        if (M2C_FIELD(n, void **, 0) != NULL) {
            MEM_free(0, M2C_FIELD(n, void **, 0));
        }
        if (M2C_FIELD(n, void **, 0x10) != NULL) {
            MEM_free(0, M2C_FIELD(n, void **, 0x10));
        }
        if (M2C_FIELD(n, void **, 0x18) != NULL) {
            MEM_free(0, M2C_FIELD(n, void **, 0x18));
        }
        if (M2C_FIELD(n, void **, 0x28) != NULL) {
            MEM_free(0, M2C_FIELD(n, void **, 0x28));
        }
        if (M2C_FIELD(n, void **, 0x50) != NULL) {
            MEM_free(0, M2C_FIELD(n, void **, 0x50));
        }
        if (M2C_FIELD(n, void **, 0x58) != NULL) {
            MEM_free(0, M2C_FIELD(n, void **, 0x58));
        }
        if (M2C_FIELD(n, int *, 0x60) != 0) {
            HST_httpHeaderFree(M2C_FIELD(n, int *, 0x60));
        }
        if (M2C_FIELD(n, void **, 0x64) != NULL) {
            HST_freePostData(n);
        }
        if (M2C_FIELD(n, void **, 0x8C) != NULL) {
            freeFragmentIDs(M2C_FIELD(n, void **, 0x8C));
        }
        addHistoryGarbage((void *)n->x48);
        if (n->child != NULL) {
            n = n->child;
        } else if (n->next != NULL) {
            next = n->next;
            MEM_free(0, n);
            n = next;
        } else {
            parent = n->parent;
            MEM_free(0, n);
            for (n = parent; n != NULL; n = parent) {
                next = n->next;
                parent = n->parent;
                MEM_free(0, n);
                if (next != NULL) {
                    n = next;
                    goto cont;
                }
            }
            return;
        }
cont:;
    }
}

int HST_registHistoryNode(void *node) {
    int *e;
    int *cur;
    int *p;
    int i;

    e = MEM_malloc(0, 0xC);
    if (e == NULL) {
        return -1;
    }
    OS_thread_mutex_lock(HL(8));
    cur = (int *)HL(0);
    if (cur != NULL) {
        while (cur[1] != 0) {
            deleteHistory(cur[1]);
        }
        i = 2;
        p = cur;
        if (cur[2] != 0) {
            do {
                p = (int *)p[2];
                i++;
            } while (p[2] != 0 && i < 16);
        }
        while (p[2] != 0) {
            deleteHistory(p[2]);
        }
        cur[1] = (int)e;
    }
    e[0] = (int)node;
    e[1] = 0;
    e[2] = (int)cur;
    HL(0) = (int)e;
    OS_thread_mutex_unlock(HL(8));
    return 0;
}

void *HST_getHeadHistoryNode(void) {
    void *cur = M2C_FIELD(history, void **, 0);

    return cur != NULL ? M2C_FIELD(cur, void **, 0) : NULL;
}

int HST_getHistoryLength(void) {
    int n;
    void *p;

    n = 0;
    OS_thread_mutex_lock(M2C_FIELD(history, int *, 8));
    if (M2C_FIELD(history, void **, 0) == NULL) {
        OS_thread_mutex_unlock(M2C_FIELD(history, int *, 8));
        return 0;
    }
    n++;
    p = M2C_FIELD(history, void **, 0);
    while (p != NULL && M2C_FIELD(p, void **, 8) != NULL) {
        p = M2C_FIELD(p, void **, 8);
        n++;
    }
    p = M2C_FIELD(history, void **, 0);
    while (p != NULL && M2C_FIELD(p, void **, 4) != NULL) {
        p = M2C_FIELD(p, void **, 4);
        n++;
    }
    OS_thread_mutex_unlock(M2C_FIELD(history, int *, 8));
    return n;
}

int HST_getCurrentIndex(void) {
    int n = 0;
    void *p;

    OS_thread_mutex_lock(M2C_FIELD(history, int *, 8));
    if (M2C_FIELD(history, void **, 0) == NULL) {
        OS_thread_mutex_unlock(M2C_FIELD(history, int *, 8));
        return -1;
    }
    for (p = M2C_FIELD(history, void **, 0); p != NULL && M2C_FIELD(p, void **, 8) != NULL; p = M2C_FIELD(p, void **, 8)) {
        n++;
    }
    OS_thread_mutex_unlock(M2C_FIELD(history, int *, 8));
    return n;
}

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

int HST_setBaseURI(void *node, char *url, int len) {
    int u[12];
    char *p;

    p = MEM_malloc(0, len + 1);
    if (p == NULL) {
        return -1;
    }
    if (M2C_FIELD(node, char **, 8) != NULL) {
        MEM_free(0, M2C_FIELD(node, char **, 8));
    }
    memcpy(p, url, len);
    p[len] = 0;
    URL_splitURL(u, p);
    if (u[0] == 0 || u[2] == 0) {
        MEM_free(0, p);
        M2C_FIELD(node, char **, 8) = NULL;
        M2C_FIELD(node, int *, 0xC) = 0;
    } else {
        M2C_FIELD(node, char **, 8) = p;
        M2C_FIELD(node, int *, 0xC) = len;
    }
    return 0;
}

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

void *HST_getJSURI(void *node, int idx) {
    char *p;
    int i;

    p = NULL;
    if (M2C_FIELD(node, int *, 0x78) == 0) {
        return (void *)M2C_FIELD(node, int *, 0x74);
    }
    if (M2C_FIELD(node, int *, 0x78) > 0) {
        p = (char *)M2C_FIELD(node, int *, 0x74);
        for (i = 1; i < idx; i++) {
            p = (char *)M2C_FIELD(p, int *, 0xB0);
        }
        return p;
    }
    return p;
}

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

void *HST_getCSSURI(void *node, int idx) {
    char *p;
    int i;

    p = NULL;
    if (M2C_FIELD(node, int *, 0x80) == 0) {
        return (void *)M2C_FIELD(node, int *, 0x7C);
    }
    if (M2C_FIELD(node, int *, 0x80) > 0) {
        p = (char *)M2C_FIELD(node, int *, 0x7C);
        for (i = 1; i < idx; i++) {
            p = (char *)M2C_FIELD(p, int *, 0xB0);
        }
        return p;
    }
    return p;
}

int HST_deleteCSSURI(void *node) {
    void *p, *next;

    if (M2C_FIELD(node, void **, 0x7C) == NULL) {
        return 0;
    }
    for (p = M2C_FIELD(node, void **, 0x7C); p != NULL; p = next) {
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

int HST_setPostData(void *node, void *data, int len, void *type, int tlen) {
    int *pd;
    void *d;
    void *t;

    d = NULL;
    t = NULL;
    pd = MEM_malloc(0, 0x10);
    if (pd == NULL) {
        goto fail;
    }
    if (len > 0) {
        d = MEM_malloc(0, len);
        if (d == NULL) {
            goto fail;
        }
        memcpy(d, data, len);
    }
    if (tlen > 0) {
        t = MEM_malloc(0, tlen);
        if (t == NULL) {
            goto fail;
        }
        memcpy(t, type, tlen);
    }
    HST_freePostData(node);
    pd[0] = (int)d;
    pd[1] = (int)t;
    pd[2] = len;
    pd[3] = tlen;
    M2C_FIELD(node, int **, 0x64) = pd;
    return 0;
fail:
    if (pd != NULL) {
        MEM_free(0, pd);
    }
    if (d != NULL) {
        MEM_free(0, d);
    }
    if (t != NULL) {
        MEM_free(0, t);
    }
    return -1;
}

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

int HST_createFragmentIDs(void *node) {
    HstFrag *f;
    HstFrag **pp;
    int i;

    f = MEM_malloc(0, sizeof(HstFrag));
    if (f == NULL) {
        return -1;
    }
    f->next = NULL;
    f->prev = NULL;
    f->a = 0;
    f->b = 0;
    f->c = 0;
    f->name = NULL;
    if (M2C_FIELD(node, int *, 0x88) == 0) {
        freeFragmentIDs(M2C_FIELD(node, HstFrag **, 0x8C));
        f->prev = (HstFrag **)((char *)node + 0x8C);
        M2C_FIELD(node, HstFrag **, 0x8C) = f;
    } else {
        pp = (HstFrag **)((char *)node + 0x8C);
        for (i = 0; i < M2C_FIELD(node, int *, 0x88); i++) {
            pp = (HstFrag **)*pp;
        }
        freeFragmentIDs(*pp);
        f->prev = pp;
        *pp = f;
    }
    M2C_FIELD(node, int *, 0x88)++;
    M2C_FIELD(node, int *, 0x84) = M2C_FIELD(node, int *, 0x88);
    return 0;
}

int HST_setFragmentIDs(void *node, int a, int b, int c, char *name) {
    HstFrag *f;
    int i;

    f = (HstFrag *)((char *)node + 0x8C);
    if (name == NULL) {
        return -1;
    }
    for (i = 0; i < M2C_FIELD(node, int *, 0x88); i++) {
        f = f->next;
    }
    f->name = MEM_malloc(0, strlen(name) + 1);
    if (f->name == NULL) {
        return -1;
    }
    f->a = a;
    f->b = b;
    f->c = c;
    strcpy(f->name, name);
    return 0;
}

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

void *HST_searchSessionIDHistoryNode(int sid) {
    void *r;

    r = NULL;
    if (sid != 0) {
        r = searchHistoryNodeInner(1, &sid, 0);
    }
    return r;
}

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

HstNode *HST_searchUriHistoryNode(char *url, int n) {
    HEnt *e;
    HstNode *h;
    HstNode *c;

    if (url == NULL) {
        return NULL;
    }
    e = *(HEnt **)history;
    for (;;) {
        if (e == NULL) {
            break;
        }
        h = e->root;
        while (h != NULL) {
            if (*(char **)h != NULL && strncmp(*(char **)h, url, n) == 0) {
                return h;
            }
            if ((c = h->child) != NULL) {
                h = c;
            } else if ((c = h->next) != NULL) {
                h = c;
            } else {
                h = h->parent;
                while (h != NULL) {
                    if ((c = h->next) != NULL) {
                        h = c;
                        break;
                    }
                    h = h->parent;
                }
            }
        }
        e = e->next;
    }
    e = *(HEnt **)history;
    for (;;) {
        if (e == NULL) {
            break;
        }
        h = e->root;
        while (h != NULL) {
            if (*(char **)h != NULL && strncmp(*(char **)h, url, n) == 0) {
                return h;
            }
            if ((c = h->child) != NULL) {
                h = c;
            } else if ((c = h->next) != NULL) {
                h = c;
            } else {
                h = h->parent;
                while (h != NULL) {
                    if ((c = h->next) != NULL) {
                        h = c;
                        break;
                    }
                    h = h->parent;
                }
            }
        }
        e = e->prev;
    }
    return NULL;
}

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

int searchExtFileSessionID(HstNode *node, int sid, char *type) {
    HstNode *p;

    p = NULL;
    if (strcmp(type, D_00134D78) == 0) {
        p = (HstNode *)node->x7C;
    } else if (strcmp(type, D_00134D7C) == 0) {
        p = (HstNode *)node->x74;
    }
    for (; p != NULL; p = p->next) {
        if (sid == p->x48) {
            return 1;
        }
    }
    return 0;
}

HstNode *searchExtFileHistoryURI(HstNode *node, int sid, char *type) {
    HstNode *p;

    p = NULL;
    if (strcmp(type, D_00134D78) == 0) {
        p = (HstNode *)node->x7C;
    } else if (strcmp(type, D_00134D7C) == 0) {
        p = (HstNode *)node->x74;
    }
    for (; p != NULL; p = p->next) {
        if (sid == p->x48) {
            return p;
        }
    }
    return NULL;
}

int HST_getParentExtSessionID(HstNode *top, int sid, char *type) {
    HstNode *node;

    node = top;
    if (searchExtFileSessionID(node, sid, type) == 1) {
        return node->x48;
    }
    while (node != NULL) {
        if (node->child != NULL) {
            node = node->child;
        } else if (node->next != NULL) {
            node = node->next;
        } else {
            goto climb;
        }
        if (searchExtFileSessionID(node, sid, type) == 1) {
            return node->x48;
        }
        continue;
    climb:
        node = node->parent;
        while (node != NULL) {
            if (node->next != NULL) {
                node = node->next;
                if (searchExtFileSessionID(node, sid, type) == 1) {
                    return node->x48;
                }
                goto cont;
            }
            node = node->parent;
        }
        return -1;
    cont:;
    }
    return -1;
}

HstNode *HST_getParentExtHistoryURI(HstNode *top, int sid, char *type) {
    HstNode *node;

    node = top;
    if (searchExtFileSessionID(node, sid, type) == 1) {
        return node;
    }
    while (node != NULL) {
        if (node->child != NULL) {
            node = node->child;
        } else if (node->next != NULL) {
            node = node->next;
        } else {
            goto climb;
        }
        if (searchExtFileSessionID(node, sid, type) == 1) {
            return node;
        }
        continue;
    climb:
        node = node->parent;
        while (node != NULL) {
            if (node->next != NULL) {
                node = node->next;
                if (searchExtFileSessionID(node, sid, type) == 1) {
                    return node;
                }
                goto cont;
            }
            node = node->parent;
        }
        return NULL;
    cont:;
    }
    return NULL;
}

void *HST_getExtHistoryURI(HstNode *top, int sid, char *type) {
    HstNode *node;
    HstNode *r;

    node = top;
    r = searchExtFileHistoryURI(node, sid, type);
    if (r != NULL) {
        return r;
    }
    while (node != NULL) {
        if (node->child != NULL) {
            node = node->child;
        } else if (node->next != NULL) {
            node = node->next;
        } else {
            node = node->parent;
            if (node == NULL) {
                break;
            }
        climb:
            if (node->next == NULL) {
                goto up;
            }
            node = node->next;
        }
        r = searchExtFileHistoryURI(node, sid, type);
        if (r != NULL) {
            return r;
        }
        continue;
    up:
        node = node->parent;
        if (node != NULL) {
            goto climb;
        }
        break;
    }
    return NULL;
}

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

void *HST_searchCSSRequestFlag(HstNode *top, int flag) {
    HstNode *node;
    void *r;

    node = top;
    r = getReqFlagCSSHistURI((void *)node->x7C, flag);
    if (r != NULL) {
        return r;
    }
    while (node != NULL) {
        if (node->child != NULL) {
            node = node->child;
        } else if (node->next != NULL) {
            node = node->next;
        } else {
            node = node->parent;
            if (node == NULL) {
                break;
            }
        climb:
            if (node->next == NULL) {
                goto up;
            }
            node = node->next;
        }
        r = getReqFlagCSSHistURI((void *)node->x7C, flag);
        if (r != NULL) {
            return r;
        }
        continue;
    up:
                node = node->parent;
        if (node != NULL) {
            goto climb;
        }
        break;
    }
    return NULL;
}

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

void *HST_searchJSRequestFlag(HstNode *top, int flag) {
    HstNode *node;
    void *r;

    node = top;
    r = HST_getReqFlagJSHistURI((void *)node->x74, flag);
    if (r != NULL) {
        return r;
    }
    while (node != NULL) {
        if (node->child != NULL) {
            node = node->child;
        } else if (node->next != NULL) {
            node = node->next;
        } else {
            node = node->parent;
            if (node == NULL) {
                break;
            }
        climb:
            if (node->next == NULL) {
                goto up;
            }
            node = node->next;
        }
        r = HST_getReqFlagJSHistURI((void *)node->x74, flag);
        if (r != NULL) {
            return r;
        }
        continue;
    up:
                node = node->parent;
        if (node != NULL) {
            goto climb;
        }
        break;
    }
    return NULL;
}

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

void freeFragmentIDs(void *fp) {
    HstFrag *f;
    HstFrag *p;

    if (fp == NULL) {
        return;
    }
    f = fp;
    do {
        p = f;
        f = f->next;
        if (p->name != NULL) {
            MEM_free(0, p->name);
        }
        MEM_free(0, p);
    } while (f != NULL);
}

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

int HST_httpHeaderDuplicate(int arg)
{
    HDHDR *src = (HDHDR *)arg;
    HDHDR *h;
    HDCOOK *c;
    HDCOOK *n;
    HDCOOK *prev;

    h = MEM_malloc(0, sizeof(HDHDR));
    if (h == NULL)
        return 0;
    memset(h, 0, sizeof(HDHDR));
    if (src->x00 != NULL) {
        h->x00 = strlinedup(src->x00, strlen(src->x00));
        if (h->x00 == NULL)
            return 0;
    }
    h->x04 = src->x04;
    h->x08 = src->x08;
    if (src->x0C != NULL) {
        h->x0C = strlinedup(src->x0C, strlen(src->x0C));
        if (h->x0C == NULL)
            goto fail;
    }
    if (src->x10 != NULL) {
        h->x10 = strlinedup(src->x10, strlen(src->x10));
        if (h->x10 == NULL)
            goto fail;
    }
    if (src->x14 != NULL) {
        h->x14 = strlinedup(src->x14, strlen(src->x14));
        if (h->x14 == NULL)
            goto fail;
    }
    if (src->x18 != NULL) {
        h->x18 = strlinedup(src->x18, strlen(src->x18));
        if (h->x18 == NULL)
            goto fail;
    }
    if (src->x1C != NULL) {
        h->x1C = strlinedup(src->x1C, strlen(src->x1C));
        if (h->x1C == NULL)
            goto fail;
    }
    if (src->x20 != NULL) {
        h->x20 = strlinedup(src->x20, strlen(src->x20));
        if (h->x20 == NULL)
            goto fail;
    }
    if (src->x24 != NULL) {
        h->x24 = MEM_malloc(0, sizeof(HDPAIR));
        if (h->x24 == NULL) {
            HST_httpHeaderFree((int)h);
            return 0;
        }
        memset(h->x24, 0, sizeof(HDPAIR));
        if (src->x24->x0 != NULL) {
            if ((h->x24->x0 = strlinedup(src->x24->x0, strlen(src->x24->x0))) == NULL)
                goto fail;
        }
        if (src->x24->x4 != NULL) {
            if ((h->x24->x4 = strlinedup(src->x24->x4, strlen(src->x24->x4))) == NULL)
                goto fail;
        }
    }
    if (src->x28 != NULL) {
        h->x28 = MEM_malloc(0, sizeof(HDPAIR));
        if (h->x28 == NULL) {
            HST_httpHeaderFree((int)h);
            return 0;
        }
        memset(h->x28, 0, sizeof(HDPAIR));
        if (src->x28->x0 != NULL) {
            if ((h->x28->x0 = strlinedup(src->x28->x0, strlen(src->x28->x0))) == NULL)
                goto fail;
        }
        if (src->x28->x4 != NULL) {
            if ((h->x28->x4 = strlinedup(src->x28->x4, strlen(src->x28->x4))) == NULL) {
fail:
                HST_httpHeaderFree((int)h);
                return 0;
            }
        }
    }
    prev = NULL;
    for (c = src->x2C; c != NULL; c = c->next) {
        n = MEM_malloc(0, sizeof(HDCOOK));
        if (n == NULL)
            goto fail;
        memset(n, 0, sizeof(HDCOOK));
        if (prev == NULL)
            h->x2C = n;
        else
            prev->next = n;
        prev = n;
        if (c->x0 != NULL) {
            n->x0 = strlinedup(c->x0, strlen(c->x0));
            if (n->x0 == NULL)
                goto fail;
        }
        if (c->x4 != NULL) {
            n->x4 = strlinedup(c->x4, strlen(c->x4));
            if (n->x4 == NULL)
                goto fail;
        }
        if (c->x8 != NULL) {
            n->x8 = strlinedup(c->x8, strlen(c->x8));
            if (n->x8 == NULL)
                goto fail;
        }
        if (c->xC != NULL) {
            n->xC = strlinedup(c->xC, strlen(c->xC));
            if (n->xC == NULL)
                goto fail;
        }
        if (c->x10 != NULL) {
            n->x10 = strlinedup(c->x10, strlen(c->x10));
            if (n->x10 == NULL)
                goto fail;
        }
        n->secure = c->secure;
    }
    h->x30 = src->x30;
    return (int)h;
}

int HST_httpHeaderFree(int arg) {
    HHDRF *h = (HHDRF *)arg;
    HCOOK *c;
    HCOOK *n;

    if (h->x00 != NULL) {
        MEM_free(0, h->x00);
    }
    if (h->x0C != NULL) {
        MEM_free(0, h->x0C);
    }
    if (h->x10 != NULL) {
        MEM_free(0, h->x10);
    }
    if (h->x14 != NULL) {
        MEM_free(0, h->x14);
    }
    if (h->x18 != NULL) {
        MEM_free(0, h->x18);
    }
    if (h->x1C != NULL) {
        MEM_free(0, h->x1C);
    }
    if (h->x20 != NULL) {
        MEM_free(0, h->x20);
    }
    if (h->x24 != NULL) {
        if (h->x24->x0 != NULL) {
            MEM_free(0, h->x24->x0);
        }
        if (h->x24->x4 != NULL) {
            MEM_free(0, h->x24->x4);
        }
        MEM_free(0, h->x24);
    }
    if (h->x28 != NULL) {
        if (h->x28->x0 != NULL) {
            MEM_free(0, h->x28->x0);
        }
        if (h->x28->x4 != NULL) {
            MEM_free(0, h->x28->x4);
        }
        MEM_free(0, h->x28);
    }
    for (c = h->x2C; c != NULL; c = n) {
        n = c->next;
        if (c->x0 != NULL) {
            MEM_free(0, c->x0);
        }
        if (c->x4 != NULL) {
            MEM_free(0, c->x4);
        }
        if (c->x8 != NULL) {
            MEM_free(0, c->x8);
        }
        if (c->xC != NULL) {
            MEM_free(0, c->xC);
        }
        if (c->x10 != NULL) {
            MEM_free(0, c->x10);
        }
        MEM_free(0, c);
    }
    MEM_free(0, h);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/history", D_00134D78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/history", D_00134D7C);
