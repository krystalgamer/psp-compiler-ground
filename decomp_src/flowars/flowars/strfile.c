#include "common.h"

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


int memcmp(const void *s1, const void *s2, unsigned int n);
int strcmp(const char *s1, const char *s2);
char *strcpy(char *dst, const char *src);
int printf(const char *fmt, ...);
int puts(const char *s);
SceInt32 sceUmdActivate(SceInt32 mode, const char *aliasname);
SceInt32 sceUmdDeactivate(SceInt32 mode, const char *aliasname);
SceUID sceIoOpen(const char *name, SceInt32 flag, SceInt32 mode);
SceInt32 sceIoClose(SceUID fd);
SceSSize sceIoRead(SceUID fd, void *buf, SceSize nbyte);
SceInt32 sceIoReadAsync(SceUID fd, void *buf, SceSize nbyte);
SceInt32 sceIoWaitAsyncCB(SceUID fd, SceIores *res);
SceInt32 sceIoWaitAsync(SceUID fd, SceIores *res);
SceInt32 sceIoPollAsync(SceUID fd, SceIores *res);
SceOff sceIoLseek(SceUID fd, SceOff offset, SceInt32 whence);
SceInt32 DvdUmdIoInit(void);
SceInt32 DvdUmdIoTerm(void);
SceUID DvdUmdRetryOpen(const char *name, SceInt32 flag, SceInt32 mode);
SceUID DvdUmdRetryOpenCB(const char *name, SceInt32 flag, SceInt32 mode);
SceSSize DvdUmdRetryRead(SceUID fd, void *buf, SceSize nbyte);
SceSSize DvdUmdRetryReadCB(SceUID fd, void *buf, SceSize nbyte);
SceSSize DvdUmdReadNoRetry(SceUID fd, void *buf, SceSize nbyte);

SceInt32 strFileAssign(const SceChar8 *filename)
{
	SceInt32 ret;

	if (memcmp(filename, "disc0:", 6) == 0 && dvd_umdAssignFlag == 0) {
		dvd_umdAssignFlag = 1;
		ret = sceUmdActivate(1, "disc0:");
		if (ret < 0) {
			printf("fatal error : sceUmdActivate() 0x%x\n", ret);
			return -1;
		}
		ret = DvdUmdIoInit();
		if (ret < 0) {
			printf("fatal error : DvdUmdIoInit() 0x%x\n", ret);
			return 0;
		}
	}
	return 0;
}

SceInt32 strFileUnassign(void)
{
	SceInt32 ret = 1;

	if (dvd_umdAssignFlag != 0) {
		ret = sceUmdDeactivate(2, "disc0:");
		if (ret < 0)
			printf("fatal error : sceUmdDeactivate() 0x%x\n", ret);
		else
			dvd_umdAssignFlag = 0;
		ret = DvdUmdIoTerm();
		if (ret < 0)
			printf("fatal error : DvdUmdIoTerm() 0x%x\n", ret);
	}
	return ret;
}

SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags)
{
	if (memcmp(filename, "disc0:", 6) == 0) {
		strcpy(file->assignName, "disc0:");
		file->fd = DvdUmdRetryOpen(filename, flags, 0);
		if (file->fd < 0) {
			printf("fatal error : file->fd = 0x%x\n", file->fd);
			return -1;
		}
		return 0;
	}
	puts("fatal error : not supported device");
	return -1;
}

SceInt32 strFileOpenCB(StrFile *file, const SceChar8 *filename, SceInt32 flags)
{
	if (memcmp(filename, "disc0:", 6) != 0) {
		puts("fatal error : not supported device");
		return -1;
	}
	file->fd = DvdUmdRetryOpenCB(filename, flags, 0);
	return 1;
}

SceInt32 strFileClose(StrFile *file)
{
	SceInt32 ret = -1;

	if (file->fd >= 0)
		ret = sceIoClose(file->fd);
	return ret;
}

SceInt32 strFileRead(StrFile *file, SceVoid *buff, SceInt32 size)
{
	SceInt32 readsize;

	if (strcmp(file->assignName, "disc0:") == 0)
		readsize = DvdUmdRetryRead(file->fd, buff, size);
	else
		readsize = sceIoRead(file->fd, buff, size);
	return readsize;
}

static __inline__ SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte)
{
	SceIores res;
	SceInt32 ret;

	ret = sceIoReadAsync(fd, buf, nbyte);
	if (ret < 0)
		return ret;
	ret = sceIoWaitAsyncCB(fd, &res);
	if (ret == 0)
		return res;
	return ret;
}

SceInt32 strFileReadCB(StrFile *file, SceVoid *buff, SceInt32 size)
{
	SceInt32 readsize;

	if (strcmp(file->assignName, "disc0:") == 0)
		readsize = DvdUmdRetryReadCB(file->fd, buff, size);
	else
		readsize = sceIoReadCB(file->fd, buff, size);
	return readsize;
}

SceInt32 strFileReadNoRetry(StrFile *file, SceVoid *buff, SceInt32 size)
{
	SceInt32 readsize;

	if (strcmp(file->assignName, "disc0:") == 0)
		readsize = DvdUmdReadNoRetry(file->fd, buff, size);
	else
		readsize = sceIoRead(file->fd, buff, size);
	return readsize;
}

SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence)
{
	return sceIoLseek(file->fd, offset, whence);
}

SceInt32 strFileReadAsync(StrFile *file, SceVoid *buff, SceInt32 size)
{
	return sceIoReadAsync(file->fd, buff, size);
}

SceInt32 strFilePollAsync(StrFile *file, SceIores *result)
{
	return sceIoPollAsync(file->fd, result);
}

SceInt32 strFileWaitAsync(StrFile *file, SceIores *result)
{
	return sceIoWaitAsync(file->fd, result);
}

SceInt32 strFileRetryReadBreak(void)
{
	return strFileUnassign();
}
