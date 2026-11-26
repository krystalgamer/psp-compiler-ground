/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int iom_preferenceDownloadStop(void);



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evfilesave", iom_evFileSave);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evfilesave", iom_saveFilesave);

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
