#include "common.h"

typedef int SceInt32;
typedef int SceUID;
typedef int SceMode;
typedef unsigned int SceSize;
typedef int SceSSize;

extern SceUID gDvdUmdIoSemaphoreId;

typedef long long SceIores;

SceUID sceKernelCreateSema(const char *name, unsigned int attr, int initVal, int maxVal, void *option);
int sceKernelDeleteSema(SceUID semid);
int sceKernelWaitSema(SceUID semid, int needCount, unsigned int *timeout);
int sceKernelWaitSemaCB(SceUID semid, int needCount, unsigned int *timeout);
int sceKernelSignalSema(SceUID semid, int signalCount);
int sceUmdGetDriveStat(void);
int sceUmdWaitDriveStat(int stat);
int sceUmdWaitDriveStatCB(int stat, unsigned int timeout);
int sceUmdCancelWaitDriveStat(void);
SceUID sceIoOpen(const char *name, int flag, SceMode mode);
SceSSize sceIoRead(SceUID fd, void *buf, SceSize nbyte);
int sceIoReadAsync(SceUID fd, void *buf, SceSize nbyte);
int sceIoWaitAsyncCB(SceUID fd, SceIores *res);

#define WAIT_PRINT() print_nothing("WAITTING: %s(%d)\n", __FUNCTION__, __LINE__)

SceInt32 DvdUmdIoInit(void)
{
	int ret = 0;

	if (gDvdUmdIoSemaphoreId >= 0)
		return 0;
	ret = sceKernelCreateSema("UMD_SAMPLE_IO_SEMA", 0, 1, 1, 0);
	if (ret < 0)
		return ret;
	gDvdUmdIoSemaphoreId = ret;
	return 0;
}

SceInt32 DvdUmdIoTerm(void)
{
	if (gDvdUmdIoSemaphoreId >= 0) {
		SceUID uid;

		sceUmdCancelWaitDriveStat();
		sceKernelWaitSema(gDvdUmdIoSemaphoreId, 1, 0);
		uid = gDvdUmdIoSemaphoreId;
		gDvdUmdIoSemaphoreId = -1;
		sceKernelDeleteSema(uid);
	}
	return 0;
}

int DvdUmdRetryWaitSemaCB(void)
{
	return sceKernelWaitSemaCB(gDvdUmdIoSemaphoreId, 1, 0);
}

static __inline__ int DvdUmdRetryWaitSema(void)
{
	return sceKernelWaitSema(gDvdUmdIoSemaphoreId, 1, 0);
}

static __inline__ int DvdUmdRetrySignalSema(void)
{
	return sceKernelSignalSema(gDvdUmdIoSemaphoreId, 1);
}

SceInt32 DvdUmdRetryOpen(const char *filepath, int flag, SceMode mode)
{
	int ret = 0;

	for (;;) {
		if (!(sceUmdGetDriveStat() & 0x20)) {
			print_nothing("WAITTING: %s(%d)\n", "DvdUmdRetryOpen", 157);
			ret = sceUmdWaitDriveStat(0x20);
			if (ret < 0)
				break;
		}
		ret = DvdUmdRetryWaitSema();
		if (ret < 0)
			break;
		ret = sceIoOpen(filepath, flag, mode);
		DvdUmdRetrySignalSema();
		if (ret >= 0 || ret == (int)0x8001B002 || ret == (int)0x80010002 || ret == (int)0x80010013
			 || ret == (int)0x8001000C || ret == (int)0x80010016 || ret == (int)0x80010024)
			break;
	}
	return ret;
}

SceInt32 DvdUmdRetryRead(SceUID fd, unsigned char *readbuf, SceSize readsize)
{
	int ret = 0;

	for (;;) {
		if (!(sceUmdGetDriveStat() & 0x20)) {
			print_nothing("WAITTING: %s(%d)\n", "DvdUmdRetryRead", 229);
			ret = sceUmdWaitDriveStat(0x20);
			if (ret < 0)
				break;
		}
		ret = DvdUmdRetryWaitSema();
		if (ret < 0)
			break;
		ret = sceIoRead(fd, readbuf, readsize);
		DvdUmdRetrySignalSema();
		if (ret >= 0 || ret == (int)0x80010009 || ret == (int)0x80010016 || ret == (int)0x80010013
			 || ret == (int)0x8001B003 || ret == (int)0x8001000E || ret == (int)0x80210002
			 || ret == (int)0x8001B001 || ret == (int)0x80010024)
			break;
		print_nothing("*** %s(0x%08x) *** \n", "DvdUmdRetryRead", ret);
		if (ret == (int)0x80210003 || ret == (int)0x80210001 || (sceUmdGetDriveStat() & 1)) {
			print_nothing("WAITTING: %s(%d)\n", "DvdUmdRetryRead", 267);
			ret = sceUmdWaitDriveStat(2);
			if (ret < 0)
				break;
		}
		ret = sceUmdWaitDriveStat(0x20);
		if (ret < 0)
			break;
	}
	return ret;
}

SceInt32 DvdUmdRetryOpenCB(const char *filepath, int flag, SceMode mode)
{
	int ret = 0;

	for (;;) {
		if (!(sceUmdGetDriveStat() & 0x20)) {
			print_nothing("WAITTING: %s(%d)\n", "DvdUmdRetryOpenCB", 302);
			ret = sceUmdWaitDriveStatCB(0x20, 0);
			if (ret < 0)
				break;
		}
		ret = DvdUmdRetryWaitSemaCB();
		if (ret < 0)
			break;
		ret = sceIoOpen(filepath, flag, mode);
		DvdUmdRetrySignalSema();
		if (ret >= 0 || ret == (int)0x8001B002 || ret == (int)0x80010013
			 || ret == (int)0x8001000C || ret == (int)0x80010016 || ret == (int)0x80010024)
			break;
	}
	return ret;
}

SceInt32 DvdUmdReadNoRetry(SceUID fd, unsigned char *readbuf, SceSize readsize)
{
	int ret = 0;

	if (sceUmdGetDriveStat() & 0x20)
		ret = sceIoRead(fd, readbuf, readsize);
	return ret;
}

static __inline__ SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte)
{
	SceIores res;
	int ret;

	ret = sceIoReadAsync(fd, buf, nbyte);
	if (ret < 0)
		return ret;
	ret = sceIoWaitAsyncCB(fd, &res);
	if (ret == 0)
		return res;
	return ret;
}

SceInt32 DvdUmdRetryReadCB(SceUID fd, unsigned char *readbuf, SceSize readsize)
{
	int ret = 0;

	for (;;) {
		if (!(sceUmdGetDriveStat() & 0x20)) {
			print_nothing("WAITTING: %s(%d)\n", "DvdUmdRetryReadCB", 396);
			ret = sceUmdWaitDriveStatCB(0x20, 0);
			if (ret < 0)
				break;
		}
		ret = DvdUmdRetryWaitSemaCB();
		if (ret < 0)
			break;
		ret = sceIoReadCB(fd, readbuf, readsize);
		DvdUmdRetrySignalSema();
		if (ret >= 0 || ret == (int)0x80010009 || ret == (int)0x80010016 || ret == (int)0x80010013
			 || ret == (int)0x8001B003 || ret == (int)0x8001000E || ret == (int)0x80210002
			 || ret == (int)0x8001B001 || ret == (int)0x80010024)
			break;
		print_nothing("*** %s(0x%08x) *** \n", "DvdUmdRetryReadCB", ret);
		if (ret == (int)0x80210003 || ret == (int)0x80210001 || (sceUmdGetDriveStat() & 1)) {
			print_nothing("WAITTING: %s(%d)\n", "DvdUmdRetryReadCB", 434);
			ret = sceUmdWaitDriveStatCB(2, 0);
			if (ret < 0)
				break;
		}
		ret = sceUmdWaitDriveStatCB(0x20, 0);
		if (ret < 0)
			break;
	}
	return ret;
}

