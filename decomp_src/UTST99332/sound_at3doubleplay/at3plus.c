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



SceInt32 init_atrac3plus(SceChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 ioutputChannel, ScePlayArg *pPlayArg);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int printf(const char *fmt, ...);


/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int sceIoOpen(const char *name, int flag, int mode);
int sceIoRead(int fd, void *buf, unsigned int nbyte);

int sceAtracSetDataAndGetID(void *buf, SceUInt32 bufsize);
int sceAtracSetLoopNum(SceInt32 atracID, SceInt32 iLoopNum);
void release_at3playArgID(ScePlayArg *pPlayArg);
SceInt32 init_atrac3plus(SceChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 ioutputChannel, ScePlayArg *pPlayArg)
{
	SceInt32 status;
	SceSSize filesize;

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

int sceAtracGetRemainFrame(SceInt32 atracId, SceInt32 *piRemainFrame);
int sceAtracDecodeData(SceInt32 atracId, short *pOutAddr, SceUInt32 *pSamples, SceUInt32 *pFinishFlag, SceInt32 *piRemainFrame);
int sceAtracGetInternalErrorInfo(SceInt32 atracId, SceInt32 *piResult);

int sceWaveAudioSetSample(int ch, int samples);
int sceWaveAudioWriteBlocking(int ch, int vl, int vr, void *buf);
void release_at3playArgID(ScePlayArg *pPlayArg);
int sceKernelExitThread(int status);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp)
{
	extern SceInt32 iFadeOutFlag;
	ScePlayArg *pPlayArg;
	SceInt32 status;
	SceUInt32 finishflag, uiWritePosition, uiPlayPosition;
	SceInt32 iRemainFrame;
	SceInt32 iReadThreshold;
	SceInt32 iVol;
	SceInt32 *outputBuf;
	SceInt32 aiOutputBuf[0x2010];

	pPlayArg = (ScePlayArg *)argp;
	uiWritePosition = 0;
	uiPlayPosition = 0;
	iVol = 0x8000;
	outputBuf = (SceInt32 *)((SceUInt32)(aiOutputBuf + 15) & ~63);

	status = sceAtracGetRemainFrame(pPlayArg->atracId, &iRemainFrame);
	if (status < 0)
		printf("sceAtracGetRemainFrame err 0x%x\n", status);
	iReadThreshold = iRemainFrame / 2;
	if (iReadThreshold < 1)
		iReadThreshold = 1;

	do {
		SceUInt32 sample;

		status = sceAtracDecodeData(pPlayArg->atracId, (short *)&outputBuf[uiWritePosition], &sample, &finishflag, &iRemainFrame);
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
			if (iFadeOutFlag) {
				iVol -= (output_samples << 8) >> 10;
				if (iVol < 0) {
					iVol = 0;
					break;
				}
			}
			sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, &outputBuf[uiPlayPosition]);
			uiPlayPosition += output_samples;
		}
		if (uiWritePosition >= 0x1800) {
			uiWritePosition -= uiPlayPosition;
			memcpy(outputBuf, &outputBuf[uiPlayPosition], uiWritePosition * 4);
			uiPlayPosition = 0;
		}
		if (iRemainFrame <= iReadThreshold && iRemainFrame != -1 && iRemainFrame != -2)
			at3plus_addData(pPlayArg->atracId, pPlayArg->fd);
	} while (!finishflag);

	if (iVol != 0 && uiPlayPosition < uiWritePosition) {
		SceInt32 paddingSize;

		paddingSize = uiWritePosition - uiPlayPosition;
		memset(&outputBuf[uiWritePosition], 0, (0x800 - paddingSize) * 4);
		sceWaveAudioSetSample(pPlayArg->outputChannel, 0x800);
		sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, &outputBuf[uiPlayPosition]);
	}
	sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, NULL);
	release_at3playArgID(pPlayArg);
	sceKernelExitThread(0);
	return 0;
}

void release_at3playArgID(ScePlayArg *pPlayArg) {
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    temp_v0 = pPlayArg->atracId;
    if ((temp_v0 < 0) || (temp_v0_2 = sceAtracReleaseAtracID(temp_v0), (temp_v0_2 >= 0))) {

    } else {
        printf("status = 0x%x (in sceAtracReleaseAtracID)\n", temp_v0_2);
    }
    if ((pPlayArg->fd < 0) || (temp_v0_3 = sceIoClose(pPlayArg->fd), (temp_v0_3 >= 0))) {

    } else {
        printf("status = 0x%x (in sceIoClose)\n", temp_v0_3);
    }
}

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
