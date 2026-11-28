/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int iom_preferenceDownloadStop(void);



void UTL_mfileseek(void *f, int pos);
int UTL_mfileread(void *f, void *buf, int len);
int iom_sendReceiveStatus(void *a, int b, int c, int d);
typedef struct { void *f; int pos; unsigned int size; } FSSRC;
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evfilesave", iom_evFileSave);

int iom_saveFilesave(void *a, int b, void *ctx, FSSRC *src, int half) {
    char buf[0x800];
    int (*write)(char *, int) = M2C_FIELD(ctx, void **, 0x14);
    int total;
    int n;
    int off;
    int chunk;
    int w;

    UTL_mfileseek(src->f, src->pos);
    total = 0;
    while (total < src->size) {
        if (iom_preferenceDownloadStop()) {
            return -0x133;
        }
        n = UTL_mfileread(src->f, buf, 0x800);
        if (n <= 0) {
            break;
        }
        for (off = 0; off < n; off += w) {
            chunk = n - off;
            if (chunk > 0x800) {
                chunk = 0x800;
            }
            w = write(buf + off, chunk);
            if (w < 0) {
                return -0x12F;
            }
        }
        total += n;
        if (half == 0) {
            iom_sendReceiveStatus(a, b, total, src->size);
        } else {
            iom_sendReceiveStatus(a, b, total / 2 + src->size / 2, src->size);
        }
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_tellsizeFilesave(void *arg0, int *arg1) {
    *arg1 = M2C_FIELD(arg0, int *, 0x40);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_removeFilesave(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_createFilesave(void *arg0) {
    M2C_FIELD(arg0, int *, 0x40) = 0;
    return 0;
}

int iom_addFilesave(void *ctx, char *buf, unsigned int len) {
    int (*write)(char *, int) = M2C_FIELD(ctx, void **, 0x3C);
    unsigned int off;
    int chunk;
    int n;
    if (iom_preferenceDownloadStop()) {
        return -0x133;
    }
    for (off = 0; off < len; off += n) {
        chunk = len - off;
        if (chunk > 0x800) {
            chunk = 0x800;
        }
        n = write(buf + off, chunk);
        if (n < 0) {
            return -0x12F;
        }
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_closeFilesave(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_tmp2realFilesave(void) {
    return 0;
}
