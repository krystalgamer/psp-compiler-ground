#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int SceSize;
typedef void *ScePVoid;
typedef int SceInt32;
typedef long long int SceIores;
typedef unsigned int SceUInt32;
typedef int SceUID;
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceInt32 atracId;
    SceInt32 fd;
    volatile int endflag;
    SceUInt32 pos;
};

extern char aucReadBuf[131074];
extern short int outputBuf[16384];
extern short int sasBuf[512];
extern struct _anon1 gPlayArg;

static SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
SceUID at3_bgm_play(const char *filename);
int at3_bgm_play_end(int fadeout_mode);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int printf(const char *fmt, ...);


/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int puts(const char *s);
int sceIoOpen(const char *name, int flag, int mode);
int sceIoRead(int fd, void *buf, unsigned int nbyte);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);

void release_arg(void) {
    int temp_v0;
    int temp_v0_2;

    if ((gPlayArg.fd < 0) || (temp_v0 = sceIoClose(gPlayArg.fd), (temp_v0 >= 0))) {

    } else {
        printf("error in sceIoClose (error code = 0x%X)\n", temp_v0);
    }
    if ((gPlayArg.atracId < 0) || (temp_v0_2 = sceAtracReleaseAtracID(gPlayArg.atracId), (temp_v0_2 >= 0))) {

    } else {
        printf("error in release ATRAC ID (error code = 0x%X)\n", temp_v0_2);
    }
}

int sceAtracGetRemainFrame(int atracID, int *piRemainFrame);
int sceAtracDecodeData(int atracID, short *pOutSamples, int *piNumSamples, unsigned int *puiFinishFlag, int *piRemainFrame);
int sceAtracGetStreamDataInfo(int atracID, unsigned char **ppucWritePointer, SceUInt32 *puiWritableByte, SceUInt32 *puiReadPosition);
int sceAtracAddStreamData(int atracID, unsigned int uiAddByte);
int sceAtracGetInternalErrorInfo(int atracID, int *piResult);
int sceIoReadAsync(SceUID fd, void *data, SceSize size);
int sceIoPollAsync(SceUID fd, SceIores *res);
long long sceIoLseek(int fd, long long offset, int whence);
int sceWaveAudioSetSample(int ch, int samples);
int sceWaveAudioWriteBlocking(int ch, int vol1, int vol2, void *buf);
int sceSasCore(short *pOut);
int sceKernelExitThread(int status);
static SceInt32 play_atrac3plus(SceSize args, ScePVoid argp)
{
	int remainFrame;
	SceIores addDataSize;
	unsigned char *writePointer;
	SceUInt32 writableByte, readPosition;
	int status;
	unsigned int finishflag;
	int iVol;
	int loadingFlag;
	int writePosition, playPosition;
	int readThreshold;

	finishflag = 0;
	loadingFlag = 0;
	writePosition = 0;
	playPosition = 0;
	sceAtracGetRemainFrame(gPlayArg.atracId, &remainFrame);
	readThreshold = remainFrame / 2;
	if (readThreshold < 1) readThreshold = 1;
	sceWaveAudioSetSample(0, 0x200);
	iVol = 0x8000;
	while (1) {
		int i;

		i = writePosition - playPosition;
		if (i < 0) i += 0x1800;
		do {
			if (i >= 0xE00) break;
			int sample;

			if (loadingFlag) {
				if (sceIoPollAsync(gPlayArg.fd, &addDataSize) == 0) {
					puts("done");
					status = sceAtracAddStreamData(gPlayArg.atracId, addDataSize);
					gPlayArg.pos += addDataSize;
					if (status < 0) {
						printf("add stream data error 0x%x\n", status);
						break;
					}
					loadingFlag = 0;
					sceAtracGetRemainFrame(gPlayArg.atracId, &remainFrame);
				}
			}
			if (remainFrame == 0 || finishflag != 0) {
				if (loadingFlag) puts("oops...file read is too slow !");
				memset(&outputBuf[writePosition * 2], 0, 0x2000);
				sample = 0x800;
			} else {
				if (!loadingFlag && remainFrame <= readThreshold && remainFrame != -1 && remainFrame != -2) {
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
				status = sceAtracDecodeData(gPlayArg.atracId, &outputBuf[writePosition * 2], &sample, &finishflag, &remainFrame);
				if (status < 0) {
					SceInt32 innerInfo;
					sceAtracGetInternalErrorInfo(gPlayArg.atracId, &innerInfo);
					printf("decode err 0x%x (%d)\n", status, innerInfo);
					break;
				}
			}
			writePosition += sample;
			if (writePosition >= 0x1800) {
				writePosition -= 0x1800;
				memcpy(outputBuf, &outputBuf[0x1800 * 2], writePosition * 4);
			}
			i = writePosition - playPosition;
			if (i < 0) i += 0x1800;
		} while (i < 0x200);
		for (i = 0; i < 0x400; ) {
			int end;

			end = i + 0x200;
			sceSasCore(sasBuf);
			for (; i < end; i++) {
				int m;

				m = outputBuf[playPosition * 2 + i] + sasBuf[i - end + 0x200];
				if (m > 0x7fff) m = 0x7fff;
				if (m < -0x8000) m = -0x8000;
				outputBuf[playPosition * 2 + i] = m;
			}
		}
		sceWaveAudioWriteBlocking(0, iVol, iVol, &outputBuf[playPosition * 2]);
		playPosition += 0x200;
		if (playPosition >= 0x1800) playPosition -= 0x1800;
		if (gPlayArg.endflag != 0) {
			if (gPlayArg.endflag < 0) break;
			iVol -= (gPlayArg.endflag * 0x200) >> 8;
			if (iVol < 0) break;
		}
	}
	if (iVol > 0) {
		if (writePosition - playPosition > 0) {
			int paddingSize;

			paddingSize = playPosition - writePosition + 0x200;
			memset(&outputBuf[writePosition], 0, paddingSize * 2);
			sceWaveAudioSetSample(0, 0x200);
			sceWaveAudioWriteBlocking(0, iVol, iVol, &outputBuf[playPosition * 2]);
		}
	}
	release_arg();
	sceKernelExitThread(0);
	return 0;
}

SceUID at3_bgm_play(const char *filename)
{
	SceInt32 status;
	SceUInt32 readsize;
	SceUID thid;

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
	thid = sceKernelCreateThread("ATRAC3 play thread", play_atrac3plus, 0x12, 0x4000, 0, NULL);
	if (thid < 0) {
		printf("error in sceKernelCreateThread (error code 0x%X)\n", thid);
		return -1;
	}
	status = sceKernelStartThread(thid, 0, 0);
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
