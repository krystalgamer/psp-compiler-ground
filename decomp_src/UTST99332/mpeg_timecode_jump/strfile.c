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
typedef void SceVoid;
typedef long long int SceOff;



SceInt32 strFileAssign(StrFile *file, const SceChar8 *filename);
SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags);
SceInt32 strFileUnassign(StrFile *file);
SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int sceIoRead(int fd, void *buf, unsigned int nbyte);
int sceIoWrite(int fd, const void *buf, unsigned int nbyte);


INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/strfile", D_00010838);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/strfile", D_00010840);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/strfile", strFileAssign);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/strfile", strFileOpen);

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

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/strfile", strFileUnassign);

int strFileRead(StrFile *file, void *buff, int size) {
    return sceIoRead(file->fd, buff, (unsigned int) size);
}

int strFileWrite(StrFile *file, void *buff, int size) {
    return sceIoWrite(file->fd, buff, (unsigned int) size);
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/strfile", strFileLseek);
