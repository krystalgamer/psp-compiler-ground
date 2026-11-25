#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef int SceUID;
typedef char SceChar8;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
typedef int SceInt32;
typedef int SceMode;
typedef void SceVoid;
typedef unsigned int SceSize;
typedef int SceSSize;
typedef long long int SceOff;
typedef struct SceIoStat SceIoStat;
struct SceIoStat;
typedef struct ScePspDateTime ScePspDateTime;
struct ScePspDateTime;
struct ScePspDateTime { /* size 0x10 */
    short unsigned int year;
    short unsigned int month;
    short unsigned int day;
    short unsigned int hour;
    short unsigned int minute;
    short unsigned int second;
    unsigned int microsecond;
};
struct SceIoStat { /* size 0x58 */
    SceMode st_mode;
    unsigned int st_attr;
    SceOff st_size;
    ScePspDateTime st_ctime;
    ScePspDateTime st_atime;
    ScePspDateTime st_mtime;
    unsigned int st_private[6];
};



SceInt32 strFileAssign(StrFile *file, const SceChar8 *filename);
SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags);
SceInt32 strFileOpenCB(StrFile *file, const SceChar8 *filename, SceInt32 flags);
static SceUID sceIoOpenCB(const char *filename, int flag, SceMode mode);
SceInt32 strFileReadCB(StrFile *file, SceVoid *buff, SceSize size);
static SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte);
SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int sceIoRead(int fd, void *buf, unsigned int nbyte);
int sceIoWrite(int fd, const void *buf, unsigned int nbyte);
int strcmp(const char *a, const char *b);


INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/strfile", D_0001253C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/strfile", D_00012544);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/strfile", D_0001254C);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/strfile", strFileAssign);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/strfile", strFileOpen);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/strfile", strFileOpenCB);

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

extern signed char D_00012544;

int strFileUnassign(StrFile *file) {
    int temp_s0;
    int var_v0;

    if (strcmp(file->assignName, &D_00012544) != 0) {
        var_v0 = 0;
    } else {
        temp_s0 = sceUmdDeactivate(2, &D_00012544);
        DvdUmdIoTerm();
        var_v0 = temp_s0;
    }
    return var_v0;
}

extern signed char D_00012544;

int strFileRead(StrFile *file, void *buff, unsigned int size) {
    int var_v0;

    if (strcmp(file->assignName, &D_00012544) == 0) {
        var_v0 = DvdUmdRetryRead(file->fd, buff, size);
    } else {
        var_v0 = sceIoRead(file->fd, buff, size);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/strfile", strFileReadCB);

int strFileReadNoRetry(StrFile *file, void *buff, unsigned int size) {
    return sceIoRead(file->fd, buff, size);
}

int strFileWrite(StrFile *file, void *buff, unsigned int size) {
    return sceIoWrite(file->fd, buff, size);
}

SceOff sceIoLseek(SceUID fd, SceOff offset, int whence);
SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence)
{
	return sceIoLseek(file->fd, offset, whence);
}

extern signed char D_00012544;

int strFileGetStat(StrFile *file, signed char *filepath, SceIoStat *stbuf) {
    int var_v0;

    if (strcmp(file->assignName, &D_00012544) == 0) {
        var_v0 = DvdUmdRetryGetStat(filepath, stbuf);
    } else {
        var_v0 = sceIoGetstat(filepath, stbuf);
    }
    return var_v0;
}

extern signed char D_00012544;

int strFileGetStatCB(StrFile *file, signed char *filepath, SceIoStat *stbuf) {
    int var_v0;

    if (strcmp(file->assignName, &D_00012544) == 0) {
        var_v0 = DvdUmdRetryGetStatCB(filepath, stbuf);
    } else {
        var_v0 = sceIoGetstat(filepath, stbuf);
    }
    return var_v0;
}

int strFileUmdReadBreak(void) {
    DvdUmdIoTerm();
    return 0;
}

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/strfile", D_0001257C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/strfile", D_000125A0);
