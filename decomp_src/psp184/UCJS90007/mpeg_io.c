#include "common.h"

/* declarations recovered from DWARF */
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

SceInt32 DvdUmdRetryReadFile(const char *filepath, SceSize filesize, void *filebuf);
SceInt32 DvdUmdRetryReadFileCB(const char *filepath, SceSize filesize, void *filebuf);
SceInt32 DvdUmdRetryReadSector(SceUInt32 lba, SceSize lbanum, void *lbabuf);
static int DvdUmdRetryWaitSema(void);
static int DvdUmdRetrySignalSema(void);
SceInt32 DvdUmdRetryReadSectorCB(SceUInt32 lba, SceSize lbanum, void *lbabuf);
SceInt32 DvdUmdRetryOpen(const char *filepath, int flag, SceMode mode);
SceInt32 DvdUmdRetryOpenCB(const char *filepath, int flag, SceMode mode);
static int DvdUmdRetryWaitSemaCB(void);
SceInt32 DvdUmdRetryRead(SceUID fd, void *readbuf, SceSize readsize);
SceInt32 DvdUmdRetryReadCB(SceUID fd, void *readbuf, SceSize readsize);
static SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte);
SceInt32 DvdUmdRetryGetStat(const char *filepath, SceIoStat *stbuf);
SceInt32 DvdUmdRetryGetStatCB(const char *filepath, SceIoStat *stbuf);

/* SDK functions (tools/sdk_protos.h) */
extern char D_0002F114[];
extern const char D_0002F11C[];
extern char D_0002F12C[];
extern char D_0002F140[];
extern const char D_0002F164[];
extern const char D_0002F24C[];
extern const char D_0002F260[];
int sceUmdWaitDriveStat(int stat);
int sceUmdWaitDriveStatCB(int stat, unsigned int timeout);
int sceUmdGetDriveStat(void);
int sceKernelWaitSema(SceUID semid, int signal, unsigned int *timeout);
int sceKernelWaitSemaCB(SceUID semid, int signal, unsigned int *timeout);
int sceKernelSignalSema(SceUID semid, int signal);
SceOff sceIoLseek(SceUID fd, SceOff offset, int whence);
SceUID sceIoOpen(const char *file, int flags, SceMode mode);
int sceIoGetstat(const char *file, SceIoStat *stat);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
int sceKernelDeleteSema(int semid);
int puts(const char *s);


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

int DvdUmdIoTerm(void) {
    int temp_s0;

    if (gDvdUmdIoSemaphoreId >= 0) {
        sceUmdCancelWaitDriveStat();
        temp_s0 = gDvdUmdIoSemaphoreId;
        gDvdUmdIoSemaphoreId = -1;
        puts("POLL SEMA");
        sceKernelDeleteSema(temp_s0);
    }
    return 0;
}

int DvdUmdRetryPollSema(void) {
    return sceKernelPollSema(gDvdUmdIoSemaphoreId, 1);
}

int sceIoClose(int fd);
int printf(const char *fmt, ...);
int printf(const char *fmt, ...);
extern char D_0002F0CC[];
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
	if (ret < 0)
		printf(D_0002F0CC, ret, 166);
	sceIoClose(fd);
	return ret;
}

extern char D_0002F0F0[];
int sceIoClose(SceUID fd);
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
	if (ret < 0)
		printf(D_0002F0F0, ret, 203);
	sceIoClose(fd);
	return ret;
}

static __inline__ int DvdUmdRetryWaitSema(void)
{
	return sceKernelWaitSema(gDvdUmdIoSemaphoreId, 1, NULL);
}

static __inline__ int DvdUmdRetrySignalSema(void)
{
	return sceKernelSignalSema(gDvdUmdIoSemaphoreId, 1);
}

static __inline__ int DvdUmdRetryWaitSemaCB(void)
{
	return sceKernelWaitSemaCB(gDvdUmdIoSemaphoreId, 1, NULL);
}

SceInt32 DvdUmdRetryReadSector(SceUInt32 lba, SceSize lbanum, void *lbabuf)
{
	int ret = 0;
	SceUID fd;

	if (lbabuf == NULL) {
		return 0x80010016;
	}

	ret = sceUmdWaitDriveStat(0x30);
	if (ret < 0) {
		return ret;
	}

	ret = DvdUmdRetryOpen(D_0002F114, 1, 0644);
	if (ret < 0) {
		return ret;
	}

	fd = ret;
	ret = DvdUmdRetryWaitSema();

	if (ret < 0) {
		sceIoClose(fd);
		return ret;
	}

	ret = sceIoLseek(fd, (SceOff)lba, 1);

	if (ret < 0) {
		DvdUmdRetrySignalSema();
		sceIoClose(fd);
		return ret;
	}

	ret = DvdUmdRetryRead(fd, lbabuf, lbanum);
	if (ret < 0) {
		printf(D_0002F0CC, ret, 258);
	}

	DvdUmdRetrySignalSema();
	sceIoClose(fd);

	return ret;
}

SceInt32 DvdUmdRetryReadSectorCB(SceUInt32 lba, SceSize lbanum, void *lbabuf)
{
	int ret = 0;
	SceUID fd;

	if (lbabuf == NULL) {
		return 0x80010016;
	}

	ret = sceUmdWaitDriveStatCB(0x30, 0);
	if (ret < 0) {
		return ret;
	}

	ret = DvdUmdRetryOpenCB(D_0002F114, 1, 0644);
	if (ret < 0) {
		return ret;
	}

	fd = ret;
	ret = DvdUmdRetryWaitSema();

	if (ret < 0) {
		sceIoClose(fd);
		return ret;
	}

	ret = sceIoLseek(fd, (SceOff)lba, 1);

	if (ret < 0) {
		DvdUmdRetrySignalSema();
		sceIoClose(fd);
		return ret;
	}

	ret = DvdUmdRetryReadCB(fd, lbabuf, lbanum);
	if (ret < 0) {
		printf(D_0002F0F0, ret, 321);
	}

	DvdUmdRetrySignalSema();
	sceIoClose(fd);

	return ret;
}

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_io", D_0002F0CC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_io", D_0002F0F0);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_io", D_0002F114);

const char D_0002F11C[] = "DvdUmdRetryOpen";

SceInt32 DvdUmdRetryOpen(const char *filepath, int flag, SceMode mode)
{
	int ret = 0;

	for (;;) {
		if ((sceUmdGetDriveStat() & 0x20) == 0) {
			printf(D_0002F12C, D_0002F11C, 348);
			ret = sceUmdWaitDriveStat(0x20);
			if (ret < 0) {
				break;
			}
		}
		ret = DvdUmdRetryWaitSema();
		if (ret < 0) {
			break;
		}

		ret = sceIoOpen(filepath, flag, mode);

		DvdUmdRetrySignalSema();

		if (ret >= 0) {
			break;
		}
		else if (ret == (int)0x8001B002 ||
			 ret == (int)0x80010013 ||
			 ret == (int)0x8001000C ||
			 ret == (int)0x80010016 ||
			 ret == (int)0x8001005B) {
			printf(D_0002F140, ret);
		}
	}

	return ret;
}

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_io", D_0002F12C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_io", D_0002F140);

const char D_0002F164[] = "DvdUmdRetryOpenCB";

SceInt32 DvdUmdRetryOpenCB(const char *filepath, int flag, SceMode mode)
{
	int ret = 0;

	for (;;) {
		if ((sceUmdGetDriveStat() & 0x20) == 0) {
			printf(D_0002F12C, D_0002F164, 401);
			ret = sceUmdWaitDriveStatCB(0x20, 0);
			if (ret < 0) {
				break;
			}
		}
		ret = DvdUmdRetryWaitSemaCB();
		if (ret < 0) {
			break;
		}

		ret = sceIoOpen(filepath, flag, mode);

		DvdUmdRetrySignalSema();

		if (ret >= 0) {
			break;
		}
		else if (ret == (int)0x8001B002 ||
			 ret == (int)0x80010013 ||
			 ret == (int)0x8001000C ||
			 ret == (int)0x80010016 ||
			 ret == (int)0x8001005B) {
			printf(D_0002F140, ret);
		}
	}

	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_io", DvdUmdRetryRead);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_io", D_0002F188);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_io", D_0002F1A0);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_io", D_0002F1C0);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_io", DvdUmdRetryReadCB);

const char D_0002F24C[] = "DvdUmdRetryGetStat";

SceInt32 DvdUmdRetryGetStat(const char *filepath, SceIoStat *stbuf)
{
	int ret = 0;

	if (filepath == NULL || stbuf == NULL) {
		return 0x80010016;
	}

	for (;;) {
		if ((sceUmdGetDriveStat() & 0x20) == 0) {
			printf(D_0002F12C, D_0002F24C, 591);
			ret = sceUmdWaitDriveStat(0x20);
			if (ret < 0) {
				break;
			}
		}
		ret = DvdUmdRetryWaitSema();
		if (ret < 0) {
			break;
		}

		ret = sceIoGetstat(filepath, stbuf);

		DvdUmdRetrySignalSema();

		if (ret >= 0) {
			break;
		}
		else if (ret == (int)0x8001B002 ||
			 ret == (int)0x80010013 ||
			 ret == (int)0x80010002 ||
			 ret == (int)0x80010016 ||
			 ret == (int)0x8001005B) {
			printf(D_0002F140, ret);
		}
	}

	return ret;
}

const char D_0002F260[] = "DvdUmdRetryGetStatCB";

SceInt32 DvdUmdRetryGetStatCB(const char *filepath, SceIoStat *stbuf)
{
	int ret = 0;

	if (filepath == NULL || stbuf == NULL) {
		return 0x80010016;
	}

	for (;;) {
		if ((sceUmdGetDriveStat() & 0x20) == 0) {
			printf(D_0002F12C, D_0002F260, 642);
			ret = sceUmdWaitDriveStatCB(0x20, 0);
			if (ret < 0) {
				break;
			}
		}
		ret = DvdUmdRetryWaitSemaCB();
		if (ret < 0) {
			break;
		}

		ret = sceIoGetstat(filepath, stbuf);

		DvdUmdRetrySignalSema();

		if (ret >= 0) {
			break;
		}
		else if (ret == (int)0x8001B002 ||
			 ret == (int)0x80010013 ||
			 ret == (int)0x80010002 ||
			 ret == (int)0x80010016 ||
			 ret == (int)0x8001005B) {
			printf(D_0002F140, ret);
		}
	}

	return ret;
}
