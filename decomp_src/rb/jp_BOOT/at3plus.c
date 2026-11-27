#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <string.h>
#include <iofilemgr.h>
#include <thread.h>
#include <libwave.h>
#include "at3plus.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int sceAtracSetDataAndGetID(void *buf, SceSize bufsize);
int sceAtracSetLoopNum(int atracID, int nloops);
int sceAtracReleaseAtracID(int atracID);
int sceAtracGetRemainFrame(int atracID, int *piRemainFrame);
int sceAtracDecodeData(int atracID, SceUShort16 *pOutSamples, int *pNumSamples, int *pFinishFlag, int *piRemainFrame);
int sceAtracGetInternalErrorInfo(int atracID, int *piResult);
int sceAtracGetStreamDataInfo(int atracID, SceUChar8 **ppucWritePointer, SceUInt32 *puiWritableByte, SceUInt32 *puiReadPosition);
int sceAtracAddStreamData(int atracID, unsigned int uiAddByte);
int sceKernelSleepThread(void);
int sceKernelGetThreadId(void);

extern int iFadeFlag;
extern int finishflag;

static void release_at3playArgID(ScePlayArg *pPlayArg);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd);

SceInt32 init_atrac3plus(SceChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 ioutputChannel, ScePlayArg *pPlayArg)
{
	SceInt32 status;
	SceSSize filesize;

	iFadeFlag = 0;
	finishflag = 0;
	pPlayArg->atracId = -1;
	pPlayArg->fd = sceIoOpen(filename, 1, 0);
	if (pPlayArg->fd < 0) {
		status = pPlayArg->fd;
		printf("status = 0x%x (in sceIoOpen)\n", status);
		goto RELEASE_ARG;
	}
	filesize = sceIoRead(pPlayArg->fd, pucReadBuf, iInputBufferSize);
	if (filesize < 0) {
		status = filesize;
		printf("status = 0x%x(in sceIoRead)\n", status);
		goto RELEASE_ARG;
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

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/at3plus", play_atrac3plus);

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

static void at3plus_addData(SceInt32 atracId, SceInt32 fd)
{
	SceUChar8 *pucWritePointer;
	SceUInt32 uiWritableByte;
	SceUInt32 uiReadPosition;
	SceInt32 status;
	SceInt32 iAddByte;

	status = sceAtracGetStreamDataInfo(atracId, &pucWritePointer, &uiWritableByte, &uiReadPosition);
	if (status < 0)
		printf("status = 0x%x (in sceAtracGetStreamDataInfo)", status);
	status = sceIoLseek(fd, uiReadPosition, SCE_SEEK_SET);
	if (status < 0)
		printf("status = 0x%x (in sceIoLseek)", status);
	iAddByte = sceIoRead(fd, pucWritePointer, uiWritableByte);
	if (iAddByte < 0) {
		printf("status = 0x%x (in sceIoRead)", iAddByte);
		return;
	}
	status = sceAtracAddStreamData(atracId, iAddByte);
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
