#include "common.h"

/* declarations recovered from DWARF */
typedef char SceChar8;
typedef unsigned char SceUChar8;
typedef int SceInt32;
struct _anon1;
struct _anon1 { /* size 0xc */
    SceInt32 atracId;
    SceInt32 fd;
    SceInt32 outputChannel;
};
typedef struct _anon1 ScePlayArg;
typedef int SceSSize;
typedef unsigned int SceSize;
typedef void *ScePVoid;
typedef unsigned int SceUInt32;

extern int iFadeFlag;
extern int finishflag;

SceInt32 init_atrac3plus(SceChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 ioutputChannel, ScePlayArg *pPlayArg);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
static void release_at3playArgID(ScePlayArg *pPlayArg);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd);
void at3plus_setfade(int fade);
void at3plus_finish(void);


SceInt32 init_atrac3plus(SceChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 ioutputChannel, ScePlayArg *pPlayArg)
{
	SceInt32 status;
	SceSSize filesize;

	iFadeFlag = 0;
	finishflag = 0;
	pPlayArg->atracId = -1;
OPEN:
	pPlayArg->fd = sceIoOpen(filename, 1, 0);
	if (pPlayArg->fd < 0) {
		status = pPlayArg->fd;
		printf("status = 0x%x (in sceIoOpen)\n", status);
		goto OPEN;
	}
READ:
	filesize = sceIoRead(pPlayArg->fd, pucReadBuf, iInputBufferSize);
	if (filesize < 0) {
		status = filesize;
		printf("status = 0x%x(in sceIoRead)\n", status);
		goto READ;
	}
	pPlayArg->atracId = sceAtracSetDataAndGetID(pucReadBuf, filesize);
	if (pPlayArg->atracId < 0) {
		status = pPlayArg->atracId;
		printf("status = 0x%x(in sceAtracSetDataAndGetID)\n", status);
		goto RELEASE_ARG;
	}
	pPlayArg->outputChannel = ioutputChannel;
	status = sceAtracSetLoopNum(pPlayArg->atracId, -1);
	if (status < 0)
		printf("status = 0x%x(in sceAtracLoopNum)\n", status);
	return 0;

RELEASE_ARG:
	release_at3playArgID(pPlayArg);
	return status;
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/at3plus", play_atrac3plus);

int sceIoClose(int fd);
int printf(const char *fmt, ...);
static void release_at3playArgID(ScePlayArg *pPlayArg)
{
	SceInt32 status;

	if (pPlayArg->atracId >= 0) {
		status = sceAtracReleaseAtracID(pPlayArg->atracId);
		if (status < 0)
			printf("status = 0x%x (in sceAtracReleaseAtracID)\n", status);
	}
	if (pPlayArg->fd >= 0) {
		status = sceIoClose(pPlayArg->fd);
		if (status < 0)
			printf("status = 0x%x (in sceIoClose)\n", status);
	}
}

int sceIoRead(int fd, void *buf, unsigned int nbyte);
int sceAtracGetStreamDataInfo(SceInt32 atracID, SceUChar8 **ppucWritePointer, SceUInt32 *puiWritableByte, SceUInt32 *puiReadPosition);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceAtracAddStreamData(SceInt32 atracID, SceUInt32 uiAddByte);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd)
{
	SceUChar8 *pucWritePointer;
	SceUInt32 uiWritableByte, uiReadPosition;
	SceInt32 status, iAddByte;

	status = sceAtracGetStreamDataInfo(atracId, &pucWritePointer, &uiWritableByte, &uiReadPosition);
	if (status < 0)
		printf("status = 0x%x (in sceAtracGetStreamDataInfo)", status);
	status = sceIoLseek(fd, uiReadPosition, 0);
	if (status < 0)
		printf("status = 0x%x (in sceIoLseek)", status);
	iAddByte = sceIoRead(fd, pucWritePointer, uiWritableByte);
	if (iAddByte < 0) {
		printf("status = 0x%x (in sceIoRead)", iAddByte);
		return;
	}
	status = sceAtracAddStreamData(atracId, (SceUInt32)iAddByte);
	if (status < 0)
		printf("status = 0x%x (in sceAtracAddStreamData)", status);
}

void at3plus_setfade(int fade)
{
	iFadeFlag = fade;
}

void at3plus_finish(void)
{
	finishflag = 1;
}
