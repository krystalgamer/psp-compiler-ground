/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fopen);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fgets);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", fio_delfilelist);

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
