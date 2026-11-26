#include "common.h"

/* declarations recovered from DWARF (UTST99332 mpeg_ezmpegstr strfile) */
struct _anon1;
typedef int SceUID;
typedef char SceChar8;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
typedef int SceInt32;
typedef void SceVoid;
typedef long long int SceOff;



SceInt32 strFileAssign(StrFile *file, const SceChar8 *filename);
SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags);
SceInt32 strFileClose(StrFile *file);
SceInt32 strFileUnassign(StrFile *file);
SceInt32 strFileRead(StrFile *file, SceVoid *buff, SceInt32 size);
SceInt32 strFileWrite(StrFile *file, SceVoid *buff, SceInt32 size);
SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", strFileAssign);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", strFileOpen);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", strFileOpenCB);

int sceIoClose(int fd);
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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", strFileUnassign);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", strFileRead);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", strFileReadCB);

int sceIoRead(int fd, void *buf, unsigned int nbyte);
int strFileReadNoRetry(StrFile *file, void *buff, unsigned int size) {
    return sceIoRead(file->fd, buff, size);
}

int sceIoWrite(int fd, const void *buf, unsigned int nbyte);
int strFileWrite(StrFile *file, void *buff, int size) {
    return sceIoWrite(file->fd, buff, (unsigned int) size);
}

SceOff sceIoLseek(SceUID fd, SceOff offset, int whence);
SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence)
{
	return sceIoLseek(file->fd, offset, whence);
}

int strFileUmdReadBreak(void) {
    DvdUmdIoTerm();
    return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", sceIoOpenCB);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", sceIoReadCB_1017C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", D_0007AF24);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", D_0007AF2C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", D_0007AF34);
