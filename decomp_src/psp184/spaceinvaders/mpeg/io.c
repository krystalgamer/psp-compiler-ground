/* cflags: -O2 */
#include "common.h"
#define sceIoReadCB sceIoReadCB_10B3C

/* declarations recovered from DWARF (psp184 mpegon io) */
typedef int SceInt32;
typedef int SceUID;
typedef unsigned int SceSize;
typedef unsigned int SceUInt32;
typedef int SceMode;
typedef int SceSSize;
typedef struct SceIoStat SceIoStat;
struct SceIoStat;
typedef long long int SceOff;
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

extern SceUID gDvdUmdIoSemaphoreId;

SceInt32 DvdUmdIoInit(void);
SceInt32 DvdUmdIoTerm(void);
SceInt32 DvdUmdRetryPollSema(void);
static int DvdUmdRetryWaitSema(void);
static int DvdUmdRetrySignalSema(void);
SceInt32 DvdUmdRetryOpen(const char *filepath, int flag, SceMode mode);
SceInt32 DvdUmdRetryOpenCB(const char *filepath, int flag, SceMode mode);
static int DvdUmdRetryWaitSemaCB(void);
SceInt32 DvdUmdRetryRead(SceUID fd, void *readbuf, SceSize readsize);
SceInt32 DvdUmdRetryReadCB(SceUID fd, void *readbuf, SceSize readsize);
static SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte);
SceInt32 DvdUmdRetryGetStat(const char *filepath, SceIoStat *stbuf);
SceInt32 DvdUmdRetryGetStatCB(const char *filepath, SceIoStat *stbuf);

int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
int DvdUmdIoInit(void) {
    int temp_v0;
    int var_v1;

    var_v1 = 0;
    if (gDvdUmdIoSemaphoreId < 0) {
        temp_v0 = sceKernelCreateSema("UMD_SAMPLE_IO_SEMA", 0U, 1, 1, NULL);
        var_v1 = temp_v0;
        if (temp_v0 >= 0) {
            gDvdUmdIoSemaphoreId = temp_v0;
            var_v1 = 0;
        }
    }
    return var_v1;
}

int sceKernelDeleteSema(int semid);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
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

int sceUmdWaitDriveStatCB(int stat, int timeout);
int sceUmdWaitDriveStat(int stat);
long long sceIoLseek(SceUID fd, long long offset, int whence);
int sceIoReadAsync(SceUID fd, void *buf, SceSize nbyte);
int sceIoWaitAsyncCB(SceUID fd, long long *res);
int sceIoClose(SceUID fd);
SceInt32 DvdUmdRetryReadFile(const char *filepath, SceSize filesize, void *filebuf)
{
	int ret;
	SceUID fd;

	if (filepath == NULL || filesize == 0 || filebuf == NULL)
		return 0x80010016;
	ret = DvdUmdRetryOpen(filepath, 1, 0644);
	if (ret < 0)
		return ret;
	fd = ret;
	ret = DvdUmdRetryRead(fd, filebuf, filesize);
	sceIoClose(fd);
	return ret;
}

SceInt32 DvdUmdRetryReadFileCB(const char *filepath, SceSize filesize, void *filebuf)
{
	int ret;
	SceUID fd;

	if (filepath == NULL || filesize == 0 || filebuf == NULL)
		return 0x80010016;
	ret = DvdUmdRetryOpenCB(filepath, 1, 0644);
	if (ret < 0)
		return ret;
	fd = ret;
	ret = DvdUmdRetryReadCB(fd, filebuf, filesize);
	sceIoClose(fd);
	return ret;
}

SceInt32 DvdUmdRetryReadSector(SceUInt32 lba, SceSize lbanum, void *lbabuf)
{
	int ret;
	SceUID fd;

	if (lbabuf == NULL)
		return 0x80010016;
	ret = sceUmdWaitDriveStat(0x30);
	if (ret < 0)
		return ret;
	ret = DvdUmdRetryOpen("umd1:", 1, 0644);
	if (ret < 0)
		return ret;
	fd = ret;
	ret = sceIoLseek(fd, lba, 1);
	if (ret < 0) {
		sceIoClose(fd);
		return ret;
	}
	ret = DvdUmdRetryRead(fd, lbabuf, lbanum);
	sceIoClose(fd);
	return ret;
}

SceInt32 DvdUmdRetryReadSectorCB(SceUInt32 lba, SceSize lbanum, void *lbabuf)
{
	int ret;
	SceUID fd;

	if (lbabuf == NULL)
		return 0x80010016;
	ret = sceUmdWaitDriveStatCB(0x30, 0);
	if (ret < 0)
		return ret;
	ret = DvdUmdRetryOpenCB("umd1:", 1, 0644);
	if (ret < 0)
		return ret;
	fd = ret;
	ret = sceIoLseek(fd, lba, 1);
	if (ret < 0) {
		sceIoClose(fd);
		return ret;
	}
	ret = DvdUmdRetryReadCB(fd, lbabuf, lbanum);
	sceIoClose(fd);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryOpen);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryOpenCB);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryRead);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryReadCB);

static SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte)
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

