#include "common.h"

/* declarations recovered from DWARF */
typedef char SceChar8;
typedef int SceInt32;
struct _anon1;
typedef int SceUID;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
typedef void SceVoid;
typedef unsigned int SceSize;
typedef int SceSSize;
typedef long long int SceOff;
typedef long long int SceIores;

extern SceInt32 dvd_umdAssignFlag;

SceInt32 strFileAssign(const SceChar8 *filename);
SceInt32 strFileUnassign(void);
SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags);
SceInt32 strFileOpenCB(StrFile *file, const SceChar8 *filename, SceInt32 flags);
SceInt32 strFileReadCB(StrFile *file, SceVoid *buff, SceInt32 size);
static SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte);
SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int sceIoRead(int fd, void *buf, unsigned int nbyte);
int strcmp(const char *a, const char *b);


INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/strfile", D_00030A14);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/strfile", strFileAssign);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/strfile", strFileUnassign);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/strfile", strFileOpen);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/strfile", strFileOpenCB);

int strFileClose(StrFile *file) {
    int temp_v0;
    int var_v1;

    var_v1 = -1;
    temp_v0 = file->fd;
    if (temp_v0 >= 0) {
        var_v1 = sceIoClose(temp_v0);
    }
    return var_v1;
}

extern signed char D_00030A14;

int strFileRead(StrFile *file, void *buff, int size) {
    int var_v0;

    if (strcmp(file->assignName, &D_00030A14) == 0) {
        var_v0 = DvdUmdRetryRead(file->fd, buff, size);
    } else {
        var_v0 = sceIoRead(file->fd, buff, (unsigned int) size);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/strfile", strFileReadCB);

extern signed char D_00030A14;

int strFileReadNoRetry(StrFile *file, void *buff, int size) {
    int var_v0;

    if (strcmp(file->assignName, &D_00030A14) == 0) {
        var_v0 = DvdUmdReadNoRetry(file->fd, buff, size);
    } else {
        var_v0 = sceIoRead(file->fd, buff, (unsigned int) size);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/strfile", strFileLseek);

int strFileReadAsync(StrFile *file, void *buff, int size) {
    return sceIoReadAsync(file->fd);
}

int strFilePollAsync(StrFile *file, long long *result) {
    return sceIoPollAsync(file->fd);
}

int strFileWaitAsync(StrFile *file, long long *result) {
    return sceIoWaitAsync(file->fd);
}

int strFileRetryReadBreak(void) {
    return strFileUnassign();
}

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/strfile", D_00030AD4);
