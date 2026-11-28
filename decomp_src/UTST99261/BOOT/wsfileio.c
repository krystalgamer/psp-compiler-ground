/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int strlen(const char *s);
int utf8ToUcs2(unsigned short *d, const char *s, int n);
int ucs2ToEuc(char *d, unsigned short *s, int n);
typedef struct FioFile {
    struct FioFile *next;
    int f4;
    int fd;
} FioFile;
typedef struct FioMan {
    int f0;
    FioFile *list;
} FioMan;
int sceIoRead(int fd, void *buf, unsigned int n);
int sceIoWrite(int fd, const void *buf, unsigned int n);
long long sceIoLseek(int fd, long long off, int whence);
int sceIoRemove(const char *path);
int sceIoClose(int fd);
char *UTF8toEUC(const char *s);
int fio_delfilelist(FioFile *fp);
extern struct FioMan *gFIOMAN;
extern struct FioMan *pFioman;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */



int fio_getfd(FioFile *fp);
void fio_freeList(void *p);
void *MEM_calloc(int pool, unsigned int n);
int sceIoOpen(const char *path, int flags, int mode);
int strcmp(const char *a, const char *b);
char *strcpy(char *d, const char *s);
int OS_thread_mutex_lock(int m);
int OS_thread_mutex_unlock(int m);
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", UTF8toEUC);

int FIO_init(void)
{
    FioMan *m;

    pFioman = MEM_calloc(0, sizeof(FioMan));
    if (pFioman == NULL)
        return -1;
    m = pFioman;
    gFIOMAN = m;
    m->f0 = (int)OS_thread_mutex_create();
    if (m->f0 == 0)
        return -1;
    if (OS_thread_mutex_init(pFioman->f0, 0) != 0)
        return -1;
    return 0;
}

int FIO_destroy(void)
{
    FioFile *n;

    pFioman = gFIOMAN;
    if (pFioman == NULL)
        return -1;
    if (pFioman->list != NULL) {
        for (n = pFioman->list; n != NULL; n = n->next)
            ;
        return -1;
    }
    OS_thread_mutex_destroy(pFioman->f0);
    gFIOMAN = NULL;
    MEM_free(0, pFioman);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int FIO_attach(void) {
    pFioman = gFIOMAN;
    return (gFIOMAN != 0) - 1;
}

FioFile *FIO_fopen(char *name, char *mode)
{
    char *m;
    char *path;
    int flags;
    int fd;
    FioFile *fp;
    FioFile *p;
    char *nm;

    if (OS_thread_mutex_lock(pFioman->f0) != 0)
        return NULL;
    for (p = pFioman->list; p != NULL; p = p->next) {
        if (strcmp((char *)p->f4, name) == 0) {
            OS_thread_mutex_unlock(pFioman->f0);
            return NULL;
        }
    }
    m = UTF8toEUC(mode);
    if (m == NULL)
        return NULL;
    flags = 1;
    if (m[0] == 'r') {
        if ((m[1] == 'b' && m[2] == '+') || m[1] == '+')
            flags = 3;
    } else if (m[0] == 'w') {
        flags = 0x602;
        if ((m[1] == 'b' && m[2] == '+') || m[1] == '+')
            flags = 0x603;
    } else {
        flags = 0x300;
        if ((m[1] == 'b' && m[2] == '+') || m[1] == '+')
            flags = 0x303;
    }
    MEM_free(0, m);
    path = UTF8toEUC(name);
    if (path == NULL)
        return NULL;
    fd = sceIoOpen(path, flags, 0);
    if (fd < 0) {
        OS_thread_mutex_unlock(pFioman->f0);
        MEM_free(0, path);
        return NULL;
    }
    MEM_free(0, path);
    fp = MEM_calloc(0, 0xC);
    nm = MEM_calloc(0, strlen(name) + 1);
    if (fp == NULL || nm == NULL) {
        if (fp != NULL)
            MEM_free(0, fp);
        if (nm != NULL)
            MEM_free(0, nm);
        sceIoClose(fd);
        OS_thread_mutex_unlock(pFioman->f0);
        return NULL;
    }
    strcpy(nm, name);
    fp->f4 = (int)nm;
    fp->fd = fd;
    fp->next = NULL;
    if (pFioman->list == NULL) {
        pFioman->list = fp;
    } else {
        for (p = pFioman->list; p->next != NULL; p = p->next)
            ;
        p->next = fp;
    }
    OS_thread_mutex_unlock(pFioman->f0);
    return fp;
}

int FIO_fclose(FioFile *fp)
{
    int fd = fio_getfd(fp);

    if (fd < 0)
        return -1;
    if (fio_delfilelist(fp) < 0)
        return -1;
    if (sceIoClose(fd) < 0)
        return -1;
    return 0;
}

unsigned int FIO_fread(void *buf, unsigned int size, unsigned int n, FioFile *fp)
{
    int fd = fio_getfd(fp);
    int r;

    if (fd < 0)
        return 0;
    r = sceIoRead(fd, buf, size * n);
    if (r < 0)
        return 0;
    return (unsigned int)r / size;
}

unsigned int FIO_fwrite(const void *buf, unsigned int size, unsigned int n, FioFile *fp)
{
    int fd = fio_getfd(fp);

    if (fd < 0)
        return 0;
    return (unsigned int)sceIoWrite(fd, buf, size * n) / size;
}

int FIO_fgetc(FioFile *fp)
{
    unsigned char c;
    int fd = fio_getfd(fp);

    if (fd < 0)
        return -1;
    sceIoRead(fd, &c, 1);
    return c;
}

int FIO_fputc(int c, FioFile *fp)
{
    unsigned char b;
    int fd = fio_getfd(fp);

    if (fd < 0)
        return -1;
    b = c;
    sceIoWrite(fd, &b, 1);
    return c;
}

char *FIO_fgets(char *buf, int n, FioFile *fp)
{
    char *p = buf;
    unsigned int i;
    int c;

    for (i = 0; i < n - 1; i++) {
        c = FIO_fgetc(fp);
        if (c == 0)
            return NULL;
        if ((unsigned char)c == 0 || (unsigned char)c == '\n') {
            *p = 0;
            break;
        }
        *p++ = c;
    }
    return buf;
}

int FIO_fputs(const char *str, FioFile *fp)
{
    const char *s = str;
    int c;

    while (*s != 0) {
        c = FIO_fputc(*s, fp);
        if (c < 0)
            return -1;
        if ((unsigned char)c == '\n')
            break;
        s++;
    }
    return 0;
}

int FIO_fseek(FioFile *fp, int off, int whence)
{
    long long pos;
    int fd = fio_getfd(fp);

    if (fd < 0)
        return -1;
    pos = sceIoLseek(fd, off, whence);
    if (pos < 0)
        return -1;
    return pos;
}

int FIO_ftell(FioFile *fp)
{
    long long pos;
    int fd = fio_getfd(fp);

    if (fd < 0)
        return -1;
    pos = sceIoLseek(fd, 0, 1);
    if (pos < 0)
        return -1;
    return pos;
}

int FIO_remove(const char *path)
{
    char *p = UTF8toEUC(path);
    int r;

    if (p == NULL)
        return -1;
    r = sceIoRemove(p);
    if (r != 0)
        return -1;
    MEM_free(0, p);
    return r;
}

int FIO_mkdir(const char *path)
{
    char *p = UTF8toEUC(path);
    int r;

    if (p == NULL)
        return -1;
    r = sceIoMkdir(p, 0777);
    if (r != 0)
        return -1;
    MEM_free(0, p);
    return r;
}

int FIO_rmdir(const char *path)
{
    char *p = UTF8toEUC(path);
    int r;

    if (p == NULL)
        return -1;
    r = sceIoRmdir(p);
    if (r != 0)
        return -1;
    MEM_free(0, p);
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int FIO_opendir(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int FIO_closedir(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int FIO_readdir(void) {
    return 0;
}

int FIO_rename(const char *from, const char *to)
{
    char *a = UTF8toEUC(from);
    char *b;
    int r;

    if (a == NULL)
        return -1;
    b = UTF8toEUC(to);
    if (b == NULL)
        return -1;
    r = sceIoRename(a, b);
    if (r != 0)
        return -1;
    MEM_free(0, a);
    MEM_free(0, b);
    return r;
}

int fio_delfilelist(FioFile *fp) {
    int fd;
    FioFile *p;
    FioFile *q;

    if (pFioman->list == NULL)
        return -1;
    if (OS_thread_mutex_lock(pFioman->f0) != 0)
        return -1;
    fd = fio_getfd(fp);
    if (fd < 0)
        return 0;
    for (p = pFioman->list; p != NULL; p = p->next) {
        if (p->fd == fd)
            break;
    }
    if (p == NULL) {
        OS_thread_mutex_unlock(pFioman->f0);
        return -1;
    }
    if (pFioman->list == p) {
        pFioman->list = p->next;
    } else {
        for (q = pFioman->list; q->next != p; q = q->next)
            ;
        q->next = p->next;
    }
    fio_freeList(p);
    OS_thread_mutex_unlock(pFioman->f0);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void fio_freeList(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 4);
    if (temp_a1 != NULL) {
        MEM_free(0, temp_a1);
    }
    MEM_free(0, arg0);
}

int fio_getfd(FioFile *fp)
{
    int fd = -1;
    FioFile *n;

    if (pFioman->list == NULL)
        return -1;
    for (n = pFioman->list; n != NULL; n = n->next) {
        if (n == fp) {
            fd = n->fd;
            break;
        }
    }
    return fd;
}
