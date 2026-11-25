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




int menuGetDevice(void);
int sceUmdCheckMedium(void);
int sceUmdWaitDriveStat(int stat);
int sceUmdActivate(int mode, const char *aliasname);
int sceUmdDeactivate(int mode, const char *aliasname);
int memcmp(const void *s1, const void *s2, unsigned int n);
char *strcpy(char *dst, const char *src);
int printf(const char *fmt, ...);
int puts(const char *s);

SceInt32 strFileAssign(StrFile *file, const SceChar8 *filename)
{
	SceInt32 ret;

	if (menuGetDevice() == 1) {
		strcpy(file->assignName, "host0:");
	} else {
		strcpy(file->assignName, "disc0:");
		if (sceUmdCheckMedium() == 0)
			sceUmdWaitDriveStat(2);
		ret = sceUmdActivate(1, "disc0:");
		if (ret < 0) {
			printf("fatal error : sceUmdActivate() 0x%x\n", ret);
			return -1;
		}
		sceUmdWaitDriveStat(0x20);
	}
	return 1;
}

SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags)
{
	SceInt32 ret;

	if (memcmp(filename, "host0:", 6) == 0 || memcmp(filename, "disc0:", 6) == 0
	    || memcmp(filename, "ms0:", 4) == 0) {
		file->fd = sceIoOpen(filename, flags, 0);
		ret = 1;
		if (file->fd < 0) {
			printf("fatal error : sceIoOpen() 0x%x\n", file->fd);
			ret = -1;
		}
	} else {
		puts("fatal error : not supported device");
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

SceInt32 strFileUnassign(StrFile *file)
{
	SceInt32 ret = 1;

	if (menuGetDevice() == 0)
		ret = sceUmdDeactivate(2, "disc0:");
	return ret;
}

int strFileRead(StrFile *file, void *buff, int size) {
    return sceIoRead(file->fd, buff, (unsigned int) size);
}

int strFileWrite(StrFile *file, void *buff, int size) {
    return sceIoWrite(file->fd, buff, (unsigned int) size);
}

SceOff sceIoLseek(SceUID fd, SceOff offset, int whence);

SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence)
{
	return sceIoLseek(file->fd, offset, whence);
}
