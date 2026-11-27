#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <string.h>
#include <iofilemgr.h>
#include <umduser.h>
#include "strfile.h"

SceInt32 strFileAssign(StrFile *file, const SceChar8 *filename, SceInt32 flags)
{
	SceInt32 ret;

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
	} else {
		puts("fatal error : not supported device");
		return -1;
	}
	return 1;
}

SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags)
{
	SceInt32 ret;

	if (memcmp(filename, "host0", 5) == 0 || memcmp(filename, "disc0", 5) == 0
	    || memcmp(filename, "prfat0", 6) == 0 || memcmp(filename, "ms0", 3) == 0) {
		file->fd = sceIoOpen(filename, flags, 644);
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
		ret = sceIoClose(file->fd);
	return ret;
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

SceInt32 strFileRead(StrFile *file, void *buff, SceInt32 size)
{
	return sceIoRead(file->fd, buff, size);
}

SceInt32 strFileWrite(StrFile *file, void *buff, SceInt32 size)
{
	return sceIoWrite(file->fd, buff, size);
}

SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence)
{
	return sceIoLseek(file->fd, offset, whence);
}
