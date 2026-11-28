/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK MEM_malloc(M2C_UNK, int);                   /* extern */
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */

extern void *esp_context;


double CLIB_difftime(int a, int b);
typedef struct IomTm { int sec; int min; int hour; int mday; int mon; int year; int wday; } IomTm;
typedef struct IomMonths { char *m[12]; } IomMonths;
typedef struct IomWdays { char *d[7]; } IomWdays;
extern const IomMonths D_00139FA8;
extern const IomWdays D_00139FD8;
extern char D_00139FF4[];
extern char D_0025B5F4[];
IomTm *CLIB_gmtime(int *t);
int sprintf(char *buf, const char *fmt, ...);
void *FIO_opendir(char *path);
char *FIO_readdir(void *d);
void FIO_closedir(void *d);
void FIO_remove(char *path);
int strcmp(const char *a, const char *b);
int strncasecmp(const char *a, const char *b, unsigned int n);
char *iom_strnmcat(char *dst, int n, ...);
int iom_preferenceCache(void) {
    int r;

    if (esp_context != NULL) {
        r = M2C_FIELD(esp_context, int *, 0x7C);
        if (r >= 0)
            return r;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_preferenceCookie(void) {
    int var_v1;

    var_v1 = 0;
    if ((esp_context != NULL) && (M2C_FIELD(esp_context, int *, 0x80) != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_preferenceOnline(void) {
    int var_v1;

    var_v1 = 0;
    if ((esp_context != NULL) && (M2C_FIELD(esp_context, int *, 0x9C) != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_preferenceHttpVersion(void) {
    int var_v1;

    var_v1 = 0xA;
    if (esp_context != NULL) {
        var_v1 = 0xB;
        if (M2C_FIELD(esp_context, int *, 0x94) == 0) {
            var_v1 = 0xA;
        }
    }
    return var_v1;
}

char *iom_preferenceUserAgent(void) {
    char *r;

    if (esp_context != NULL) {
        r = M2C_FIELD(esp_context, char **, 0xAC);
        if (r != NULL)
            return r;
    }
    return NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

signed char *iom_preferenceUnitId(void) {
    signed char *var_v1;

    var_v1 = NULL;
    if ((esp_context != NULL) && ((var_v1 = M2C_FIELD(esp_context, signed char **, 0xB0), (var_v1 == NULL)) || (*var_v1 == 0))) {
        var_v1 = NULL;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_preferenceProxy(void *arg0) {
    signed char *temp_v0;

    if ((esp_context == NULL) || (M2C_FIELD(esp_context, int *, 0x90) == 0) || (temp_v0 = M2C_FIELD(esp_context, signed char **, 0xA4), (temp_v0 == NULL)) || (*temp_v0 == 0)) {
        if (arg0 != NULL) {
            M2C_FIELD(arg0, signed char **, 0) = NULL;
            M2C_FIELD(arg0, int *, 4) = 0;
        }
        return 0;
    }
    if (arg0 != NULL) {
        M2C_FIELD(arg0, signed char **, 0) = (signed char *) M2C_FIELD(esp_context, signed char **, 0xA4);
        M2C_FIELD(arg0, int *, 4) = (int) M2C_FIELD(esp_context, int *, 0xA8);
    }
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_preferenceDownloadStop(void) {
    int var_v1;

    var_v1 = 0;
    if ((esp_context != NULL) && (M2C_FIELD(esp_context, int *, 0xD8) != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *iom_malloc(int size) {
    return (void *)MEM_malloc(0, size);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_mfree(int arg0) {
    if (arg0 != 0) {
        MEM_free(0, arg0);
    }
    return 0;
}

char *iom_getheadervalue(char *buf, int len, char *name)
{
    int nlen;
    int i;
    char *p;
    char *v;
    int vlen;
    char *r;

    nlen = strlen(name);
    while (len > 0) {
        i = 0;
        while (i < len && buf[i] != '\n')
            i++;
        if (len < i)
            break;
        if (buf[i] == '\0' || buf[i] == '\n') {
            if (i > nlen && strncasecmp(buf, name, nlen) == 0) {
                p = buf + nlen;
                while (*p == ' ' || *p == '\t')
                    p++;
                p += (*p == ':');
                while (*p == ' ' || *p == '\t')
                    p++;
                v = p;
                while (*p != '\0' && *p != '\r' && *p != '\n')
                    p++;
                len = p - v;
                r = iom_malloc(len + 1);
                if (r == NULL)
                    return NULL;
                iom_strnmcat(r, 1, len, v);
                return r;
            }
            len -= i;
            len--;
            buf += i + 1;
        } else
            break;
    }
    return NULL;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139DF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139E9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139ECC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139ED0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139EFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139F08);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", iom_str2time);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139FA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139FD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_00139FF4);

char *iom_time2str(int t) {
    IomMonths mon = D_00139FA8;
    IomWdays wd = D_00139FD8;
    IomTm *tm;

    if (t == 0 || t == -1)
        return D_00139FF4;
    tm = CLIB_gmtime(&t);
    sprintf(D_0025B5F4, "%s, %02d %s %04d %02d:%02d:%02d GMT", wd.d[tm->wday], tm->mday, mon.m[tm->mon], tm->year + 1900, tm->hour, tm->min, tm->sec);
    return D_0025B5F4;
}

int iom_diffexpire(int a, int b) {
    if (a == 0 || b == 0) {
        if (a == 0 && b != 0)
            return -1;
        return a != 0 && b == 0;
    }
    if (a != -1 && b != -1) {
        if (CLIB_difftime(a, b) < 0.0)
            return -1;
        else if (CLIB_difftime(a, b) > 0.0)
            return 1;
        else
            return 0;
    }
    if (a == -1 && b != -1)
        return -1;
    return a != -1 && b == -1;
}

int iom_rmdir(char *path) {
    int len;
    void *d;
    char *e;
    char *name;
    char *s;

    len = strlen(path);
    d = FIO_opendir(path);
    if (d == NULL)
        return -0x12F;
    while ((e = FIO_readdir(d)) != NULL) {
        name = e + 0x58;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
            continue;
        s = iom_malloc(len + strlen(name) + 2);
        if (s == NULL)
            break;
        sprintf(s, "%s/%s", path, name);
        FIO_remove(s);
        iom_mfree((int)s);
    }
    FIO_closedir(d);
    if (e != NULL)
        return -0x12D;
    FIO_remove(path);
    return 0;
}

char *iom_strnmcat(char *dst, int n, ...) {
    __builtin_va_list ap;
    char *d;
    int i, j, len;
    char *s;

    __builtin_va_start(ap, n);
    d = dst;
    for (i = 0; i < n; i++) {
        len = __builtin_va_arg(ap, int);
        s = __builtin_va_arg(ap, char *);
        if (s != NULL) {
            for (j = 0; j < len && s[j] != 0; j++)
                *d++ = s[j];
        }
    }
    *d = 0;
    return dst;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A02C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A034);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A03C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A044);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A050);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A058);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A060);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A064);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A06C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A074);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A078);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A084);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A088);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A08C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A098);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A09C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A0FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A108);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A110);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A118);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A120);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A128);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A130);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A13C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A144);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A14C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A154);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A15C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A164);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A16C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A174);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A180);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A188);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A18C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A198);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A1FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_preference", D_0013A208);
