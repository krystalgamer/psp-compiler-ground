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

SceInt32 play_atrac3plus(SceSize args, ScePVoid argp)
{
	ScePlayArg *pPlayArg;
	SceInt32 status;
	SceUInt32 uiWritePosition;
	SceUInt32 uiPlayPosition;
	SceInt32 iRemainFrame;
	SceInt32 iReadThreshold;
	SceInt32 iVol;
	SceInt32 *outputBuf;
	SceInt32 aiOutputBuf[8206];

	pPlayArg = (ScePlayArg *)argp;
	iVol = 0;
	uiPlayPosition = 0;
	uiWritePosition = 0;
	outputBuf = (SceInt32 *)((int)(aiOutputBuf + 15) & ~63);
	status = sceAtracGetRemainFrame(pPlayArg->atracId, &iRemainFrame);
	if (status < 0)
		printf("sceAtracGetRemainFrame err 0x%x\n", status);
	iReadThreshold = MAX(iRemainFrame / 2, 1);
	sceKernelSleepThread();

	do {
		switch (iFadeFlag) {
		case 0:
			break;
		case 1:
			iVol += 0x300;
			if (iVol >= 0x6000) {
				iFadeFlag = 0;
				iVol = 0x6000;
				sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x3D);
			}
			break;
		case 2:
			iVol -= 0x300;
			if (iVol < 0) {
				iFadeFlag = 0;
				iVol = 0;
				sceKernelSleepThread();
			}
			break;
		}
		{
			SceUInt32 sample;

			status = sceAtracDecodeData(pPlayArg->atracId, (SceUShort16 *)(outputBuf + uiWritePosition),
						    (int *)&sample, &finishflag, &iRemainFrame);
			if (status < 0) {
				SceInt32 innerInfo;

				sceAtracGetInternalErrorInfo(pPlayArg->atracId, &innerInfo);
				printf("sceAtracDecodeData err 0x%x (%d)\n", status, innerInfo);
				break;
			}
			uiWritePosition += sample;
			if (uiWritePosition - uiPlayPosition >= 0x800) {
				SceInt32 output_samples;

				output_samples = (uiWritePosition - uiPlayPosition) & ~63;
				sceWaveAudioSetSample(pPlayArg->outputChannel, output_samples);
				sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, outputBuf + uiPlayPosition);
				uiPlayPosition += output_samples;
			}
		}
		if (uiWritePosition >= 0x1800) {
			uiWritePosition -= uiPlayPosition;
			memcpy(outputBuf, outputBuf + uiPlayPosition, uiWritePosition * 4);
			uiPlayPosition = 0;
		}
		if (iRemainFrame <= iReadThreshold) {
			if (iRemainFrame != -1) {
				if (iRemainFrame != -2)
					at3plus_addData(pPlayArg->atracId, pPlayArg->fd);
			}
		}
	} while (!finishflag);

	if (iVol != 0 && uiWritePosition > uiPlayPosition) {
		SceInt32 paddingSize;

		paddingSize = 0x800 - (uiWritePosition - uiPlayPosition);
		memset(outputBuf + uiWritePosition, 0, paddingSize * 4);
		sceWaveAudioSetSample(pPlayArg->outputChannel, 0x800);
		sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, outputBuf + uiPlayPosition);
	}
	sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, NULL);
	release_at3playArgID(pPlayArg);
	sceKernelExitThread(0);
	return 0;
}

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
