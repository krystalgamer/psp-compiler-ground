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
SceInt32 strFileWrite(StrFile *file, SceVoid *buff, SceInt32 size);
SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence);

extern char D_0007AF2C[];
int memcmp(const void *a, const void *b, unsigned int n);
char *strcpy(char *d, const char *s);
int strcmp(const char *a, const char *b);
int sceIoOpen(const char *name, int flags, int mode);
int sceUmdActivate(int mode, const char *aliasname);
int sceUmdDeactivate(int mode, const char *aliasname);
int sceIoOpenAsync(const char *name, int flags, int mode);
int sceIoReadAsync(int fd, void *buf, unsigned int nbyte);
int sceIoWaitAsyncCB(int fd, long long *res);
SceInt32 DvdUmdIoInit(void);
SceInt32 DvdUmdIoTerm(void);
SceInt32 DvdUmdRetryOpen(const char *filepath, int flag, int mode);
SceInt32 DvdUmdRetryOpenCB(const char *filepath, int flag, int mode);
SceInt32 DvdUmdRetryRead(SceUID fd, void *readbuf, unsigned int readsize);
SceInt32 DvdUmdRetryReadCB(SceUID fd, void *readbuf, unsigned int readsize);
static SceUID sceIoOpenCB(const char *name, int flags, int mode);
static int sceIoReadCB_1017C(SceUID fd, void *buf, unsigned int nbyte);

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

SceInt32 strFileUnassign(StrFile *file)
{
	SceInt32 ret;

	ret = 1;
	if (strcmp(file->assignName, D_0007AF2C) == 0) {
		ret = sceUmdDeactivate(2, D_0007AF2C);
		DvdUmdIoTerm();
	}
	return ret;
}

SceInt32 strFileRead(StrFile *file, SceVoid *buff, SceInt32 size)
{
	if (strcmp(file->assignName, D_0007AF2C) == 0)
		return DvdUmdRetryRead(file->fd, buff, size);
	return sceIoRead(file->fd, buff, size);
}

SceInt32 strFileReadCB(StrFile *file, SceVoid *buff, SceInt32 size)
{
	if (strcmp(file->assignName, D_0007AF2C) == 0)
		return DvdUmdRetryReadCB(file->fd, buff, size);
	return sceIoReadCB_1017C(file->fd, buff, size);
}

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

static SceUID sceIoOpenCB(const char *name, int flags, int mode)
{
	long long res;
	SceInt32 ret;
	SceUID fd;

	fd = sceIoOpenAsync(name, flags, mode);
	if (fd < 0)
		return fd;
	ret = sceIoWaitAsyncCB(fd, &res);
	if (ret == 0)
		ret = (SceInt32)res;
	return ret;
}

static int sceIoReadCB_1017C(SceUID fd, void *buf, unsigned int nbyte)
{
	long long res;
	SceInt32 ret;

	ret = sceIoReadAsync(fd, buf, nbyte);
	if (ret < 0)
		return ret;
	ret = sceIoWaitAsyncCB(fd, &res);
	if (ret == 0)
		ret = (SceInt32)res;
	return ret;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", D_0007AF24);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", D_0007AF2C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/strfile", D_0007AF34);
