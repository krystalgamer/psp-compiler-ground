#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned char SceUChar8;
typedef int SceInt32;
struct _anon1;
typedef int SceUID;
struct _anon1 { /* size 0x14 */
    SceInt32 atracID;
    SceUID fd;
    SceUID finishflag;
    SceInt32 outputChannel;
    SceInt32 iEndSample;
};
typedef struct _anon1 SceAtracArg;
typedef int SceSSize;
typedef unsigned int SceSize;
typedef void *ScePVoid;
typedef unsigned int SceUInt32;



SceInt32 init_atrac3plus(SceUChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 iOutputChannel, SceAtracArg *pPlayArg);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd);
static void at3plus_DisplayDecodePosition(SceAtracArg *pPlayArg);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int printf(const char *fmt, ...);


/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int sceIoOpen(const char *name, int flag, int mode);
int sceIoRead(int fd, void *buf, unsigned int nbyte);

int sceAtracSetDataAndGetID(void *buf, SceUInt32 bufsize);
int sceAtracGetSecondBufferInfo(SceInt32 atracID, SceUInt32 *puiPosition, SceUInt32 *puiDataByte);
int sceAtracSetSecondBuffer(SceInt32 atracID, SceUChar8 *pucSecondBufferAddr, SceUInt32 uiSecondBufferByte);
int sceAtracGetSoundSample(SceInt32 atracID, SceInt32 *piEndSample, SceInt32 *piLoopStartSample, SceInt32 *piLoopEndSample);
int sceAtracSetLoopNum(SceInt32 atracID, SceInt32 iLoopNum);
SceUID sceKernelCreateEventFlag(const char *name, SceUInt32 attr, SceUInt32 initPattern, void *opt);
long long sceIoLseek(int fd, long long offset, int whence);
void release_arg(SceAtracArg *pPlayArg);
SceInt32 init_atrac3plus(SceUChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 iOutputChannel, SceAtracArg *pPlayArg)
{
	SceSSize filesize;
	SceInt32 status;
	SceInt32 iLoopStartSample, iLoopEndSample;

	pPlayArg->fd = -1;
	pPlayArg->atracID = -1;
	pPlayArg->finishflag = -1;
	pPlayArg->outputChannel = iOutputChannel;

	pPlayArg->fd = sceIoOpen((const char *)filename, 1, 0);
	if (pPlayArg->fd < 0) {
		status = pPlayArg->fd;
		printf("status = 0x%x(in sceIoOpen)\n", status);
		goto RELEASE_ARG;
	}
	filesize = sceIoRead(pPlayArg->fd, pucReadBuf, iInputBufferSize);
	if (filesize < 0) {
		status = filesize;
		printf("status = 0x%x(in sceIoRead)\n", status);
		goto RELEASE_ARG;
	}
	pPlayArg->atracID = sceAtracSetDataAndGetID(pucReadBuf, filesize);
	if (pPlayArg->atracID < 0) {
		status = pPlayArg->atracID;
		printf("status = 0x%x(in sceAtracSetDataAndGetID)\n", status);
		goto RELEASE_ARG;
	}
	pPlayArg->finishflag = sceKernelCreateEventFlag("finishflag", 0, 0, 0);
	if (pPlayArg->finishflag < 0) {
		status = pPlayArg->finishflag;
		printf("status = 0x%x(in sceKernelCreateEventflag)\n", status);
		goto RELEASE_ARG;
	}
	status = sceAtracGetSoundSample(pPlayArg->atracID, &pPlayArg->iEndSample, &iLoopStartSample, &iLoopEndSample);
	if (status < 0) {
		printf("status = 0x%x(in sceAtracGetSoundSample)\n", status);
		goto RELEASE_ARG;
	}
	status = sceAtracSetLoopNum(pPlayArg->atracID, -1);
	if (status < 0)
		printf("status = 0x%x(in sceAtracSetLoopNum)\n", status);
	return 0;

RELEASE_ARG:
	release_arg(pPlayArg);
	return status;
}

int sceAtracGetRemainFrame(SceInt32 atracID, SceInt32 *piRemainFrame);
int sceAtracDecodeData(SceInt32 atracID, short *pOutAddr, SceUInt32 *pSamples, SceUInt32 *pFinishFlag, SceInt32 *piRemainFrame);
int sceAtracGetInternalErrorInfo(SceInt32 atracID, SceInt32 *piResult);
int sceKernelPollEventFlag(SceUID evid, SceUInt32 bits, SceUInt32 wait, SceUInt32 *outBits);
int sceWaveAudioSetSample(int ch, int samples);
int sceWaveAudioWriteBlocking(int ch, int vl, int vr, void *buf);
void release_arg(SceAtracArg *pPlayArg);
int sceKernelExitThread(int status);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp)
{
	SceAtracArg *pPlayArg;
	SceInt32 status;
	SceUInt32 finishflag, uiWritePosition, uiPlayPosition;
	SceInt32 iRemainFrame;
	SceInt32 iReadThreshold;
	SceInt32 iVol;
	SceInt32 fadeoutflag;
	SceInt32 *outputBuf;
	SceInt32 aiOutputBuf[0x2010];

	pPlayArg = (SceAtracArg *)argp;
	uiWritePosition = 0;
	uiPlayPosition = 0;
	iVol = 0x8000;
	fadeoutflag = 0;
	outputBuf = (SceInt32 *)((SceUInt32)(aiOutputBuf + 15) & ~63);

	status = sceAtracGetRemainFrame(pPlayArg->atracID, &iRemainFrame);
	if (status < 0)
		printf("sceAtracGetRemainFrame err 0x%x\n", status);
	iReadThreshold = iRemainFrame / 2;
	if (iReadThreshold < 1)
		iReadThreshold = 1;

	do {
		SceUInt32 sample;

		at3plus_DisplayDecodePosition(pPlayArg);
		status = sceAtracDecodeData(pPlayArg->atracID, (short *)&outputBuf[uiWritePosition], &sample, &finishflag, &iRemainFrame);
		if (status < 0) {
			SceInt32 innerInfo;

			sceAtracGetInternalErrorInfo(pPlayArg->atracID, &innerInfo);
			printf("sceAtracDecodeData err 0x%x (%d)\n", status, innerInfo);
			break;
		}
		uiWritePosition += sample;
		if (uiWritePosition - uiPlayPosition >= 0x800) {
			SceInt32 output_samples;

			output_samples = (uiWritePosition - uiPlayPosition) & ~63;
			sceWaveAudioSetSample(pPlayArg->outputChannel, output_samples);
			if (fadeoutflag) {
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
			at3plus_addData(pPlayArg->atracID, pPlayArg->fd);
		if (!fadeoutflag) {
			status = sceKernelPollEventFlag(pPlayArg->finishflag, 1, 1, NULL);
			fadeoutflag = (status == 0);
			if (status < 0 && status != (SceInt32)0x800201AF)
				printf("status = 0x%x(in sceKernelPollEventFlag)\n", status);
		}
	} while (!finishflag);

	if (iVol != 0 && uiPlayPosition < uiWritePosition) {
		SceInt32 paddingSize;

		paddingSize = uiWritePosition - uiPlayPosition;
		memset(&outputBuf[uiWritePosition], 0, (0x800 - paddingSize) * 4);
		sceWaveAudioSetSample(pPlayArg->outputChannel, 0x800);
		sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, &outputBuf[uiPlayPosition]);
	}
	sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, NULL);
	release_arg(pPlayArg);
	sceKernelExitThread(0);
	return 0;
}

void finish_atrac3plus(SceAtracArg *pPlayArg) {
    int temp_v0;

    temp_v0 = sceKernelSetEventFlag(pPlayArg->finishflag, 1);
    if (temp_v0 >= 0) {

    } else {
        printf("status = 0x%x(in sceKernelSetEventFlag)\n", temp_v0);
    }
}

void release_arg(SceAtracArg *pPlayArg) {
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    temp_v0 = pPlayArg->atracID;
    if ((temp_v0 < 0) || (temp_v0_2 = sceAtracReleaseAtracID(temp_v0), (temp_v0_2 >= 0))) {

    } else {
        printf("status = 0x%x(in sceAtracReleaseID)\n", temp_v0_2);
    }
    if ((pPlayArg->fd < 0) || (temp_v0_3 = sceIoClose(pPlayArg->fd), (temp_v0_3 >= 0))) {

    } else {
        printf("status = 0x%x(in sceIoClose)\n", temp_v0_3);
    }
    if (pPlayArg->finishflag >= 0) {
        sceKernelDeleteEventFlag(pPlayArg->finishflag);
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
		printf("sceAtracGetStreamDataInfo = 0x%x\n", status);
	status = sceIoLseek(fd, uiReadPosition, 0);
	if (status < 0)
		printf("sceIoLseek Error = 0x%x\n", status);
	iAddByte = sceIoRead(fd, pucWritePointer, uiWritableByte);
	if (iAddByte < 0)
		printf("sceIoRead Error = 0x%x\n", iAddByte);
	status = sceAtracAddStreamData(atracId, (SceUInt32)iAddByte);
	if (status < 0)
		printf("sceAtracAddStreamData = 0x%x\n", status);
}

extern char decode_position[]; /* static char decode_position[] in at3plus_DisplayDecodePosition (.data is asm) */
int sprintf(char *buf, const char *fmt, ...);
int sceAtracGetNextDecodePosition(SceInt32 atracID, SceUInt32 *puiSamplePosition);

static void at3plus_DisplayDecodePosition(SceAtracArg *pPlayArg)
{
	SceUInt32 uiSamplePosition;
	SceInt32 status;

	status = sceAtracGetNextDecodePosition(pPlayArg->atracID, &uiSamplePosition);

	if (status < 0) {
		printf("sceAtracGetNextDecodePosition = 0x%x\n", status);
	}

	sprintf(decode_position, "Decoding Position  %10d/%10d\n", uiSamplePosition, pPlayArg->iEndSample);
}
