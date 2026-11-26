#include "common.h"

struct _anon1 {
	int atracId;
	int fd;
	volatile int endflag;
	unsigned int pos;
};
extern struct _anon1 gPlayArg;

int sceIoWaitAsync(int fd, long long *res);
int sceIoClose(int fd);
int sceAtracReleaseAtracID(int atracID);
int printf(const char *fmt, ...);

/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int puts(const char *s);
int sceIoOpen(const char *name, int flag, int mode);
int sceIoRead(int fd, void *buf, unsigned int nbyte);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);

void release_arg(void)
{
	int status;

	if (gPlayArg.fd >= 0) {
		long long dummy;

		sceIoWaitAsync(gPlayArg.fd, &dummy);

		status = sceIoClose(gPlayArg.fd);
		if (status < 0) {
			printf("error in sceIoClose (error code = 0x%X)\n", status);
		}
	}

	if (gPlayArg.atracId >= 0) {
		status = sceAtracReleaseAtracID(gPlayArg.atracId);
		if (status < 0) {
			printf("error in release ATRAC ID (error code = 0x%X)\n", status);
		}
	}
}

extern short outputBuf[];
int sceAtracGetRemainFrame(int atracID, int *piRemainFrame);
int sceAtracDecodeData(int atracID, short *pOutSamples, int *piNumSamples, unsigned int *puiFinishFlag, int *piRemainFrame);
int sceAtracGetStreamDataInfo(int atracID, unsigned char **ppucWritePointer, unsigned int *puiWritableByte, unsigned int *puiReadPosition);
int sceAtracAddStreamData(int atracID, unsigned int uiAddByte);
int sceAtracGetInternalErrorInfo(int atracID, int *piResult);
int sceIoReadAsync(int fd, void *data, unsigned int size);
int sceIoPollAsync(int fd, long long *res);
long long sceIoLseek(int fd, long long offset, int whence);
int sceWaveAudioSetSample(int ch, int samples);
int sceWaveAudioWriteBlocking(int ch, int vol1, int vol2, void *buf);
int sceKernelExitThread(int status);
static int play_atrac3plus(unsigned int args, void *argp)
{
	int sample;
	int remainFrame;
	long long addDataSize;
	unsigned char *writePointer;
	unsigned int writableByte, readPosition;
	int status;
	unsigned int finishflag;
	int iVol;
	int loadingFlag;
	int writePosition, playPosition;
	int readThreshold;

	sceAtracGetRemainFrame(gPlayArg.atracId, &remainFrame);
	readThreshold = remainFrame / 2;
	if (readThreshold < 1) readThreshold = 1;
	sceWaveAudioSetSample(0, 0x400);
	iVol = 0x8000;
	loadingFlag = 0;
	writePosition = 0;
	playPosition = 0;
	while (1) {
		status = sceAtracDecodeData(gPlayArg.atracId, &outputBuf[writePosition * 2], &sample, &finishflag, &remainFrame);
		if (status < 0) {
			int innerInfo;
			sceAtracGetInternalErrorInfo(gPlayArg.atracId, &innerInfo);
			printf("decode err 0x%x (%d)\n", status, innerInfo);
			break;
		}
		if (loadingFlag == 0 && remainFrame <= readThreshold && remainFrame != -1 && remainFrame != -2) {
			sceAtracGetStreamDataInfo(gPlayArg.atracId, &writePointer, &writableByte, &readPosition);
			if (writableByte > 0x400) writableByte = 0x400;
			printf("reading %d bytes\n", writableByte);
			if (gPlayArg.pos != readPosition) {
				sceIoLseek(gPlayArg.fd, readPosition, 0);
				gPlayArg.pos = readPosition;
			}
			sceIoReadAsync(gPlayArg.fd, writePointer, writableByte);
			loadingFlag = 1;
		}
		writePosition += sample;
		if (writePosition - playPosition >= 0x400) {
			int outsamples;

			outsamples = (writePosition - playPosition) & ~0x3f;
			sceWaveAudioSetSample(0, outsamples);
			sceWaveAudioWriteBlocking(0, iVol, iVol, &outputBuf[playPosition * 2]);
			if (gPlayArg.endflag != 0) {
				if (gPlayArg.endflag < 0) break;
				iVol -= (gPlayArg.endflag * outsamples) >> 10;
				if (iVol < 0) break;
			}
			playPosition += outsamples;
		}
		if (writePosition >= 0x1800) {
			writePosition -= playPosition;
			memcpy(outputBuf, &outputBuf[playPosition * 2], writePosition * 4);
			playPosition = 0;
		}
		if (remainFrame == 0 && loadingFlag > 0) {
			if (finishflag == 0) puts("oops...file read is too slow !");
			sceIoWaitAsync(gPlayArg.fd, &addDataSize);
			loadingFlag = -1;
		} else if (sceIoPollAsync(gPlayArg.fd, &addDataSize) == 0) {
			puts("done");
			loadingFlag = -1;
		}
		if (loadingFlag < 0) {
			loadingFlag = 0;
			sceAtracAddStreamData(gPlayArg.atracId, addDataSize);
			gPlayArg.pos += addDataSize;
		}
		if (finishflag) break;
	}
	if (iVol > 0) {
		if (writePosition - playPosition > 0) {
			int paddingSize;

			paddingSize = playPosition - writePosition + 0x400;
			memset(&outputBuf[writePosition * 2], 0, paddingSize * 4);
			sceWaveAudioSetSample(0, 0x400);
			sceWaveAudioWriteBlocking(0, iVol, iVol, &outputBuf[playPosition * 2]);
		}
	}
	release_arg();
	sceKernelExitThread(0);
	return 0;
}

static int play_atrac3plus(unsigned int args, void *argp);
extern char aucReadBuf[];
int at3_bgm_play(const char *filename)
{
	int status;
	unsigned int readsize;
	int thid;

	gPlayArg.fd = sceIoOpen(filename, 1, 0);
	if (gPlayArg.fd < 0) {
		printf("cannot open %s\n", filename);
		return -1;
	}
	readsize = sceIoRead(gPlayArg.fd, aucReadBuf, 0x20000);
	gPlayArg.pos = readsize;
	gPlayArg.endflag = 0;
	gPlayArg.atracId = sceAtracSetDataAndGetID(aucReadBuf, readsize);
	if (gPlayArg.atracId < 0) {
		printf("cannot get ATRAC ID (error code 0x%X)\n", gPlayArg.atracId);
		release_arg();
		return -1;
	}
	status = sceAtracSetLoopNum(gPlayArg.atracId, -1);
	if (status < 0) {
		printf("status = 0x%x(in sceAtracLoopNum)\n", status);
		printf("maybe no loop data or 'A->B->C' type loop data\n");
	}
	thid = sceKernelCreateThread("ATRAC3 play thread", play_atrac3plus, 0x12, 0x8000, 0, NULL);
	if (thid < 0) {
		printf("error in sceKernelCreateThread (error code 0x%X)\n", thid);
		return -1;
	}
	status = sceKernelStartThread(thid, sizeof(gPlayArg), &gPlayArg);
	if (status != 0) {
		printf("error in sceKernelStartThread (error code 0x%X)\n", status);
		return -1;
	}
	return thid;
}


int at3_bgm_play_end(int fadeout_mode)
{
	if (fadeout_mode) {
		gPlayArg.endflag = 0x100;
	} else {
		gPlayArg.endflag = -1;
	}

	return 0;
}
