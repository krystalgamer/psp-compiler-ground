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
M2C_UNK UTL_relqueue(int, void *);                  /* extern */
int UTL_sizequeue(int);                             /* extern */

M2C_UNK cookieFile_init();                          /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", cookieFile_init);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_getCookieData);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", iom_subdomainCookie);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", D_00139CB4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cookie", esp_iomThread);
