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
extern char D_000125D4[];
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
		printf(D_000125D4, ret, 166);
	sceIoClose(fd);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryReadFileCB);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryReadSector);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryReadSectorCB);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_000125B0);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_000125D4);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_000125F8);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryOpen);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_00012610);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_00012624);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryOpenCB);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryRead);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_0001266C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_00012684);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_000126A4);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryReadCB);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryGetStat);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryGetStatCB);
