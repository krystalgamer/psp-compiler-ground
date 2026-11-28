/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int strcasecmp(const char *, const char *);
unsigned int strlen(const char *);
typedef struct CookieDom { int pad[2]; char *name; } CookieDom;
typedef struct CFILE { u8 *buf; int cap; int len; int sum; int pos; } CFILE;
extern CFILE cookieFile;
void *memcpy(void *d, const void *s, unsigned int n);
void *UTL_peekqueue(int, void *);                   /* extern */
int iom_diffexpire(int, int);                       /* extern */
extern int iomCookie;
void UTL_relqueue(int, void *);                  /* extern */
int UTL_sizequeue(int);                             /* extern */

M2C_UNK cookieFile_init();                          /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

void *memset(void *, int, unsigned int);
typedef struct { int mq; int x4; int x8; int xC; } IOMHDR;
extern IOMHDR iom;
extern int (*D_00139CB4[])(void *msg);
void CLIB_tzset(void);
void iom_initializeEnvironment(void);
void iom_finalizeEnvironment(void);
int OS_mq_open(const char *name, int mode);
int OS_mq_getattr(int mq, void *attr);
void *iom_recvMsg(int mq);
int iom_translateMsg(void *msg);
void *iom_freeMsg(void *msg);
int iom_evStartup(void *msg);
void OS_thread_exit(void *r);
int CLIB_time(int *out);
void iom_deleteCookie(void *c);
void iom_freeCookie(void *arg0);
void iom_deleteDomainCookie(void *arg0);
int iom_mfree(int arg0);
typedef struct CkQueue { int w[4]; } CkQueue;
typedef struct Cookie { void *dom; char *domain; char *name; char *value; int expire; int secure; } Cookie;
extern char D_00139C98[];
void iom_cookieFile_init(void) {
    cookieFile_init();
}

int cookieFile_fstab(CFILE *f) {
    int *p = (int *)f->buf;
    int sum = f->cap + f->len;
    int i;
    for (i = 0; i < f->cap >> 2; i++) {
        sum += *p;
        p++;
    }
    return sum;
}

int cookieFile_init(int check, u8 *buf, int size) {
    u8 *p;

    if (check) {
        if (cookieFile.buf == NULL || cookieFile.cap < 0 || cookieFile.len < 0 || cookieFile.pos != 0)
            return -1;
        return (cookieFile_fstab(&cookieFile) == cookieFile.sum) - 1;
    }
    p = (u8 *)(((unsigned int)buf + 3) & ~3);
    size = (size - (p - buf)) & ~3;
    cookieFile.buf = p;
    cookieFile.cap = size;
    memset(p, 0xA5, size);
    cookieFile.len = 0;
    cookieFile.sum = cookieFile_fstab(&cookieFile);
    cookieFile.pos = 0;
    return 0;
}

CFILE *cookieFile_open(void) {
    cookieFile.pos = 0;
    return &cookieFile;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int cookieFile_close(CFILE *f) {
    f->sum = cookieFile_fstab(f);
    f->pos = 0;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cookieFile_pos(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cookieFile_len(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cookieFile_seek(void *arg0, int arg1) {
    int var_v1;

    var_v1 = -1;
    if (M2C_FIELD(arg0, int *, 8) >= arg1) {
        M2C_FIELD(arg0, int *, 0x10) = arg1;
        var_v1 = arg1;
    }
    return var_v1;
}

int cookieFile_getc(CFILE *f) {
    if (f->pos + 1 > f->len) {
        return -1;
    }
    return f->buf[f->pos++];
}

int cookieFile_read(CFILE *f, void *dst, int n) {
    if (f->len < n + f->pos) {
        return -1;
    }
    memcpy(dst, f->buf + f->pos, n);
    f->pos = n + f->pos;
    return n;
}

int cookieFile_write(CFILE *f, void *src, int n) {
    int p;
    if (f->cap < n + f->pos) {
        return -1;
    }
    memcpy(f->buf + f->pos, src, n);
    p = n + f->pos;
    f->pos = p;
    if (f->len < p) {
        f->len = p;
    }
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_loadCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_saveCookie);

#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_updateCookie(void) {
    void *temp_s0;
    void *temp_s1;
    void *temp_v0;
    void *var_s0;

    temp_v0 = UTL_peekqueue(iomCookie + 4, NULL);
    var_s0 = temp_v0;
    if (temp_v0 != NULL) {
        do {
            temp_s1 = UTL_peekqueue(iomCookie + 4, var_s0);
            temp_s0 = M2C_FIELD(var_s0, void **, 8);
            if (((unsigned int) (M2C_FIELD(temp_s0, int *, 0x10) + 1) >= 2U) && (iom_diffexpire(M2C_FIELD(temp_s0, int *, 0x10), CLIB_time(NULL)) < 0)) {
                M2C_FIELD(temp_s0, int *, 0x10) = 0;
            }
            if (M2C_FIELD(temp_s0, int *, 0x10) == 0) {
                iom_deleteCookie(temp_s0);
            }
            var_s0 = temp_s1;
        } while (temp_s1 != NULL);
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C60);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_addCookie);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139C9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139CA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139CA8);

int iom_getCookieData(char *dom, char *host, int secure, void *f, int first)
{
    CkQueue q;
    void *e;
    void *next;
    Cookie *c;
    int len;
    int ret;
    int f1;

    len = strlen(host);
    f1 = first != 0;
    UTL_initqueue(&q);
    for (e = UTL_peekqueue((int)dom + 0xC, NULL); e != NULL; e = next) {
        next = UTL_peekqueue((int)dom + 0xC, e);
        c = M2C_FIELD(e, Cookie **, 8);
        if (len < (int)strlen(c->domain))
            continue;
        if (strncasecmp(c->domain, host, strlen(c->domain)) != 0)
            continue;
        if (c->expire == 0)
            continue;
        if ((c->secure == 1) & (secure != 1))
            continue;
        if (f1 == 0) {
            if (UTL_mfileputs(f, D_00139C98) < 0)
                break;
        } else
            f1 = 0;
        if (UTL_mfilesize(f) > 0 && UTL_mfileputs(f, " ") < 0)
            break;
        if (UTL_mfileputs(f, c->name) < 0)
            break;
        if (c->value != NULL && *c->value != 0) {
            if (UTL_mfileputs(f, "=") < 0)
                break;
            if (UTL_mfileputs(f, c->value) < 0)
                break;
        }
        UTL_relqueue(iomCookie + 4, (char *)c + 0x1C);
        UTL_enqueue(&q, (char *)c + 0x1C);
    }
    if (e != NULL)
        ret = -0x12D;
    else
        ret = 0;
    while ((e = UTL_dequeue(&q)) != NULL)
        UTL_enqueue(iomCookie + 4, e);
    return ret;
}

void iom_deleteCookie(void *c) {
    void *e;
    if (c == NULL) {
        e = UTL_peekqueue(iomCookie + 4, 0);
        if (e == NULL) {
            return;
        }
        c = M2C_FIELD(e, void **, 8);
    }
    if (M2C_FIELD(c, int *, 0x10) != -1) {
        *(int *)iomCookie = 1;
    }
    iom_freeCookie(c);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_freeCookie(void *arg0) {
    UTL_relqueue(iomCookie + 4, arg0 + 0x1C);
    UTL_relqueue(M2C_FIELD(arg0, int *, 0) + 0xC, arg0 + 0x28);
    iom_deleteDomainCookie(M2C_FIELD(arg0, int *, 0));
    iom_mfree(M2C_FIELD(arg0, int *, 0x18));
    iom_mfree(M2C_FIELD(arg0, int *, 0xC));
    iom_mfree(M2C_FIELD(arg0, int *, 8));
    iom_mfree(M2C_FIELD(arg0, int *, 4));
    iom_mfree((int) arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_deleteDomainCookie(void *arg0) {
    if (UTL_sizequeue(arg0 + 0xC) <= 0) {
        UTL_relqueue(iomCookie + 0xC, arg0);
        iom_mfree(M2C_FIELD(arg0, int *, 8));
        iom_mfree((int) arg0);
    }
}

CookieDom *iom_domainCookie(char *domain) {
    CookieDom *d;

    for (d = UTL_peekqueue(iomCookie + 0xC, NULL); d != NULL; d = UTL_peekqueue(iomCookie + 0xC, d)) {
        if (strcasecmp(d->name, domain) == 0)
            return d;
    }
    return NULL;
}

CookieDom *iom_subdomainCookie(char *host, CookieDom *d) {
    int len = strlen(host);
    int n;
    char c;

    if (d == NULL)
        return NULL;
    while (d != NULL) {
        c = d->name[0];
        if (c == '.') {
            n = len - strlen(d->name);
            if (n > 0 && host[n] == c)
                if (strcasecmp(d->name, host + n) == 0)
                    return d;
        } else {
            n = len - strlen(d->name);
            if (n > 0 && host[n - 1] == '.')
                if (strcasecmp(d->name, host + n) == 0)
                    return d;
        }
        d = UTL_peekqueue(iomCookie + 0xC, d);
    }
    return NULL;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139CB4);

int esp_iomThread(void)
{
    char attr[16];
    void *m;
    int t;

    CLIB_tzset();
    memset(&iom, 0, 0x104);
    iom_initializeEnvironment();
    iom.mq = OS_mq_open("/tmp/mq_iom", 2);
    if (iom.mq < 0)
        return 0;
    OS_mq_getattr(iom.mq, attr);
    iom.xC = 0;
    for (;;) {
        m = iom_recvMsg(iom.mq);
        if (m == NULL)
            continue;
        t = iom_translateMsg(m);
        if (t < 0) {
            iom_freeMsg(m);
            continue;
        }
        if (t != 0) {
            iom_freeMsg(m);
            continue;
        }
        if (iom_evStartup(m) >= 0)
            break;
    }
    for (;;) {
        m = iom_recvMsg(iom.mq);
        if (m == NULL)
            continue;
        t = iom_translateMsg(m);
        if (t < 0) {
            iom_freeMsg(m);
            continue;
        }
        if (D_00139CB4[t](m) < 0)
            continue;
        if (t == 2) {
            iom_finalizeEnvironment();
            OS_thread_exit(NULL);
        }
    }
}
