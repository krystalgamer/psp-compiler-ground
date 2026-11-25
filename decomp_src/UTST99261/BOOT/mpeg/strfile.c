#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <string.h>
#include <iofilemgr.h>
#include <umduser.h>
#include "strfile.h"

int NetMgrHttpOpen(const char *uri, int flag, SceMode mode);
SceSSize NetMgrHttpRead(SceUID fd, void *buff, SceSize size);
SceOff NetMgrHttpSeek(int fd, SceOff offset, SceInt32 whence);
int NetMgrHttpClose(int fd);

extern FUNC_OPEN localOpen_1EDEC8;
extern FUNC_CLOSE localClose_1EDECC;
extern FUNC_LSEEK localLseek_1EDED0;
extern FUNC_READ localRead_1EDED4;
#define localOpen localOpen_1EDEC8
#define localClose localClose_1EDECC
#define localLseek localLseek_1EDED0
#define localRead localRead_1EDED4

SceInt32 strFileAssign(StrFile *file, const SceChar8 *filename, SceInt32 flags)
{
	SceInt32 ret;

	localOpen = sceIoOpen;
	localClose = sceIoClose;
	localLseek = sceIoLseek;
	localRead = sceIoRead;

	if (memcmp(filename, "host0", 5) == 0) {
		strcpy(file->assignName, "host0:");
	} else if (memcmp(filename, "disc0", 5) == 0) {
		strcpy(file->assignName, "disc0:");
		if (sceUmdCheckMedium() == 0)
			sceUmdWaitDriveStat(2);
		ret = sceUmdActivate(1, "disc0:");
		if (ret < 0) {
			printf("fatal error : sceUmdActivate() 0x%x\n", ret);
			return -1;
		}
		sceUmdWaitDriveStat(0x20);
	} else if (memcmp(filename, "prfat0", 6) == 0) {
		strcpy(file->assignName, "prfat0:");
		ret = sceIoAssign(file->assignName, "msstor0p1:/", "fatms0:", flags, NULL, 0);
		if (ret != 0) {
			printf("fatal error : sceIoAssign(%x)\n", ret);
			return -1;
		}
	} else if (memcmp(filename, "ms0:", 3) == 0) {
		strcpy(file->assignName, "ms0:");
	} else if (memcmp(filename, "http", 4) == 0) {
		strcpy(file->assignName, "http");
		localOpen = NetMgrHttpOpen;
		localClose = NetMgrHttpClose;
		localLseek = NetMgrHttpSeek;
		localRead = NetMgrHttpRead;
	} else {
		puts("fatal error : not supported device");
		return -1;
	}
	return 1;
}

SceInt32 strFileUnassign(StrFile *file)
{
	SceInt32 ret = 1;

	if (strcmp(file->assignName, "prfat0:") == 0) {
		sceIoUnassign(file->assignName);
		ret = -1;
	} else if (strcmp(file->assignName, "disc0:") == 0) {
		ret = sceUmdDeactivate(2, "disc0:");
	}
	return ret;
}

SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags)
{
	SceInt32 ret;

	if (memcmp(filename, "host0", 5) == 0 || memcmp(filename, "disc0", 5) == 0
	    || memcmp(filename, "prfat0", 6) == 0 || memcmp(filename, "ms0", 3) == 0
	    || memcmp(filename, "http", 4) == 0) {
		file->fd = localOpen(filename, flags, 644);
		ret = -1;
		if (file->fd >= 0)
			ret = 1;
	} else {
		puts("fatal error : not supported device");
		ret = -1;
	}
	return ret;
}

SceInt32 strFileClose(StrFile *file)
{
	SceInt32 ret = -1;

	if (file->fd >= 0)
		ret = localClose(file->fd);
	return ret;
}

SceInt32 strFileRead(StrFile *file, void *buff, SceInt32 size)
{
	return localRead(file->fd, buff, size);
}

SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence)
{
	return localLseek(file->fd, offset, whence);
}
