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
typedef long long SceIores;
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
int sceIoWaitAsyncCB(SceUID fd, SceIores *res);
int memcmp(const void *s1, const void *s2, unsigned int n);
char *strcpy(char *dst, const char *src);
int printf(const char *fmt, ...);
int puts(const char *s);
int sceUmdActivate(int mode, const char *aliasname);
int DvdUmdIoInit(void);
SceUID sceIoOpen(const char *file, int flags, SceMode mode);
int sceIoOpenAsync(const char *file, int flags, SceMode mode);
SceUID DvdUmdRetryOpen(const char *file, int flags, SceMode mode);
SceUID DvdUmdRetryOpenCB(const char *file, int flags, SceMode mode);
int sceIoReadAsync(SceUID fd, void *buf, SceSize nbyte);
int DvdUmdRetryReadCB(SceUID fd, void *buf, SceSize nbyte);
int sceIoClose(int fd);
int sceIoRead(int fd, void *buf, unsigned int nbyte);
int sceIoWrite(int fd, const void *buf, unsigned int nbyte);
int strcmp(const char *a, const char *b);


SceInt32 strFileAssign(StrFile *file, const SceChar8 *filename)
{
	SceInt32 ret;

	if (memcmp(filename, "host0:", 6) == 0) {
		strcpy(file->assignName, "host0:");
	} else if (memcmp(filename, "disc0:", 6) == 0) {
		strcpy(file->assignName, "disc0:");
		ret = sceUmdActivate(1, "disc0:");
		if (ret < 0) {
			goto end;
		}
		DvdUmdIoInit();
	} else if (memcmp(filename, "ms0:", 4) == 0) {
		strcpy(file->assignName, "ms0:");
	} else {
		file->fd = -1;
		ret = -1;
		goto end;
	}
	ret = 0;
end:
	return ret;
}

SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags)
{
	if (memcmp(filename, "host0:", 6) == 0 || memcmp(filename, "ms0:", 4) == 0) {
		file->fd = sceIoOpen(filename, flags, 0);
		if (file->fd < 0) {
			return file->fd;
		}
	} else if (memcmp(filename, "disc0:", 6) == 0) {
		file->fd = DvdUmdRetryOpen(filename, flags, 0);
	} else {
		file->fd = -1;
		return -1;
	}
	return 0;
}

static __inline__ SceUID sceIoOpenCB(const char *filename, int flag, SceMode mode)
{
	SceUID fd;
	SceIores res;

	fd = sceIoOpenAsync(filename, flag, mode);
	if (fd < 0)
		return fd;
	fd = sceIoWaitAsyncCB(fd, &res);
	if (fd == 0)
		return (SceUID)res;
	return fd;
}

SceInt32 strFileOpenCB(StrFile *file, const SceChar8 *filename, SceInt32 flags)
{
	SceInt32 ret = 0;

	if (memcmp(filename, "host0:", 6) == 0 || memcmp(filename, "ms0:", 4) == 0) {
		file->fd = sceIoOpenCB(filename, flags, 0);
		if (file->fd < 0) {
			ret = file->fd;
		}
	} else if (memcmp(filename, "disc0:", 6) == 0) {
		file->fd = DvdUmdRetryOpenCB(filename, flags, 0);
		if (file->fd < 0) {
			ret = file->fd;
		}
	} else {
		file->fd = -1;
		ret = -1;
	}
	return ret;
}

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

int strFileUnassign(StrFile *file) {
    int temp_s0;
    int var_v0;

    if (strcmp(file->assignName, "disc0:") != 0) {
        var_v0 = 0;
    } else {
        temp_s0 = sceUmdDeactivate(2, "disc0:");
        DvdUmdIoTerm();
        var_v0 = temp_s0;
    }
    return var_v0;
}

int strFileRead(StrFile *file, void *buff, unsigned int size) {
    int var_v0;

    if (strcmp(file->assignName, "disc0:") == 0) {
        var_v0 = DvdUmdRetryRead(file->fd, buff, size);
    } else {
        var_v0 = sceIoRead(file->fd, buff, size);
    }
    return var_v0;
}

static __inline__ SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte)
{
	int res;
	SceIores iores;

	res = sceIoReadAsync(fd, buf, nbyte);
	if (res < 0)
		return res;
	res = sceIoWaitAsyncCB(fd, &iores);
	if (res == 0)
		return (SceSSize)iores;
	return res;
}

SceInt32 strFileReadCB(StrFile *file, SceVoid *buff, SceSize size)
{
	if (strcmp(file->assignName, "disc0:") == 0)
		return DvdUmdRetryReadCB(file->fd, buff, size);
	return sceIoReadCB(file->fd, buff, size);
}

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

int strFileGetStat(StrFile *file, signed char *filepath, SceIoStat *stbuf) {
    int var_v0;

    if (strcmp(file->assignName, "disc0:") == 0) {
        var_v0 = DvdUmdRetryGetStat(filepath, stbuf);
    } else {
        var_v0 = sceIoGetstat(filepath, stbuf);
    }
    return var_v0;
}

int strFileGetStatCB(StrFile *file, signed char *filepath, SceIoStat *stbuf) {
    int var_v0;

    if (strcmp(file->assignName, "disc0:") == 0) {
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

