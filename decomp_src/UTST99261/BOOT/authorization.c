/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int strlen(char *s);
typedef struct AuthInfo {
    char *path;
    char *user;
    char *pass;
} AuthInfo;
typedef struct AuthEntry {
    struct AuthEntry *next;
    int x04;
    AuthInfo *info;
} AuthEntry;
int HST_initAuthorizationDB();                      /* extern */
extern int authdb;


int HST_initAuthorizationDB(void) {
    authdb = (int)MEM_malloc(0, 4);
    if (authdb == 0) {
        return -1;
    }
    *(AuthEntry **)authdb = NULL;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int HST_attachAuthorizationDB(void) {
    int var_v1;

    var_v1 = 0;
    if (authdb == 0) {
        var_v1 = HST_initAuthorizationDB();
    }
    return var_v1;
}

int HST_freeAuthorizationDB(void) {
    AuthEntry *e;
    AuthEntry *next;

    for (e = *(AuthEntry **)authdb; e != NULL; e = next) {
        next = e->next;
        MEM_free(0, e->info->path);
        MEM_free(0, e->info->user);
        MEM_free(0, e->info->pass);
        MEM_free(0, e->info);
        MEM_free(0, e);
    }
    *(AuthEntry **)authdb = NULL;
    MEM_free(0, authdb);
    authdb = 0;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/authorization", HST_addAuthorizationDB);

AuthInfo *HST_searchAuthorizationDB(char *url) {
    int len;
    int n;
    AuthEntry *e;

    len = urlpathlen(url);
    for (e = *(AuthEntry **)authdb; e != NULL; e = e->next) {
        n = strlen(e->info->path);
        if (n > len) {
            continue;
        }
        if (strncasecmp(e->info->path, url, n) == 0) {
            return e->info;
        }
    }
    return NULL;
}

char *stringdup(char *s, int n) {
    char *p;

    p = MEM_malloc(0, n + 1);
    if (p == NULL) {
        return NULL;
    }
    memcpy(p, s, n);
    p[n] = 0;
    return p;
}

int urlpathlen(char *url) {
    char *last;
    char *p;

    last = url + strlen(url);
    for (p = url; *p != 0; p++) {
        if (*p == '#' || *p == '?') {
            break;
        }
        if (*p == '/' && p[1] != '/') {
            last = p + 1;
        }
    }
    return last - url;
}
