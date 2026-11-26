#include "common.h"

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryReadFile);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryReadFileCB);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryReadSector);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryReadSectorCB);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryOpen);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryOpenCB);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryRead);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", DvdUmdRetryReadCB);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", sceIoReadCB_10B3C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/io", D_0007AF50);
