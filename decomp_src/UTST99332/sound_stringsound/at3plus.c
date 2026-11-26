#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned char SceUChar8;
typedef int SceInt32;
struct _anon1;
typedef int SceUID;
struct _anon1 { /* size 0x14 */
    SceInt32 atracID;
    SceUID fd;
    SceUID statusflag;
    SceInt32 outputChannel;
    SceInt32 iEndSample;
};
typedef struct _anon1 SceAtracArg;
typedef int SceSSize;
typedef unsigned int SceUInt32;
typedef unsigned int SceSize;
typedef void *ScePVoid;
struct _anon2;
struct _anon2 { /* size 0x20 */
    SceUChar8 *pucWritePositionFirstBuf;
    SceUInt32 uiWritableByteFirstBuf;
    SceUInt32 uiMinWriteByteFirstBuf;
    SceUInt32 uiReadPositionFirstBuf;
    SceUChar8 *pucWritePositionSecondBuf;
    SceUInt32 uiWritableByteSecondBuf;
    SceUInt32 uiMinWriteByteSecondBuf;
    SceUInt32 uiReadPositionSecondBuf;
};
typedef struct _anon2 SceBufferInfo;
typedef short int SceShort16;
typedef float SceFloat;



SceInt32 init_atrac3plus(SceUChar8 *filename, SceUChar8 *pucFirstBuf, SceInt32 iFirstBufferSize, SceUChar8 *pucSecondBuf, SceInt32 iSecondBufSize, SceInt32 iOutputChannel, SceAtracArg *pPlayArg);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd);
static void at3plus_DisplayDecodePosition(SceAtracArg *pPlayArg);
static void reset_position(SceAtracArg *pPlayArg);
static SceUInt32 getPlayMode(SceUID statusflag, SceUInt32 playMode);
static void fadeoutOperation(SceShort16 *pusValue, SceInt32 iFadeoutBorderSample, SceInt32 iMuteBorderSample);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int printf(const char *fmt, ...);


/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int sceIoOpen(const char *name, int flag, int mode);
int sceIoRead(int fd, void *buf, unsigned int nbyte);

extern char D_0001F6C0[];
extern char D_0001F6E0[];
extern char D_0001F70C[];
extern char D_0001F738[];
extern char D_0001F760[];
extern char D_0001F78C[];
int sceAtracSetDataAndGetID(void *buf, SceUInt32 bufsize);
int sceAtracGetSecondBufferInfo(SceInt32 atracID, SceUInt32 *puiPosition, SceUInt32 *puiDataByte);
int sceAtracSetSecondBuffer(SceInt32 atracID, SceUChar8 *pucSecondBufferAddr, SceUInt32 uiSecondBufferByte);
int sceAtracGetSoundSample(SceInt32 atracID, SceInt32 *piEndSample, SceInt32 *piLoopStartSample, SceInt32 *piLoopEndSample);
int sceAtracSetLoopNum(SceInt32 atracID, SceInt32 iLoopNum);
SceUID sceKernelCreateEventFlag(const char *name, SceUInt32 attr, SceUInt32 initPattern, void *opt);
long long sceIoLseek(int fd, long long offset, int whence);
void release_arg(SceAtracArg *pPlayArg);
SceInt32 init_atrac3plus(SceUChar8 *filename, SceUChar8 *pucFirstBuf, SceInt32 iFirstBufferSize, SceUChar8 *pucSecondBuf, SceInt32 iSecondBufSize, SceInt32 iOutputChannel, SceAtracArg *pPlayArg)
{
	SceSSize filesize;
	SceInt32 status;
	SceInt32 iLoopStartSample, iLoopEndSample;
	SceUInt32 uiSecondBufferPosition;
	SceUInt32 uiDataByte;

	pPlayArg->fd = -1;
	pPlayArg->atracID = -1;
	pPlayArg->statusflag = -1;
	pPlayArg->outputChannel = iOutputChannel;

	pPlayArg->fd = sceIoOpen((const char *)filename, 1, 0);
	if (pPlayArg->fd < 0) {
		status = pPlayArg->fd;
		printf(D_0001F78C, status);
		goto RELEASE_ARG;
	}
	filesize = sceIoRead(pPlayArg->fd, pucFirstBuf, iFirstBufferSize);
	if (filesize < 0) {
		status = filesize;
		printf("status = 0x%x(in sceIoRead)\n", status);
		goto RELEASE_ARG;
	}
	pPlayArg->atracID = sceAtracSetDataAndGetID(pucFirstBuf, filesize);
	if (pPlayArg->atracID < 0) {
		status = pPlayArg->atracID;
		printf("status = 0x%x(in sceAtracSetDataAndGetID)\n", status);
		goto RELEASE_ARG;
	}
	status = sceAtracGetSecondBufferInfo(pPlayArg->atracID, &uiSecondBufferPosition, &uiDataByte);
	if (status != (SceInt32)0x80630022) {
		if (status < 0) {
			printf("status = 0x%x(in sceAtracGetSecondBuffer)\n", status);
			goto RELEASE_ARG;
		}
		status = sceIoLseek(pPlayArg->fd, uiSecondBufferPosition, 0);
		if (status < 0) {
			printf(D_0001F6C0, status);
			goto RELEASE_ARG;
		}
		{
			SceInt32 iReadSize;

			iReadSize = sceIoRead(pPlayArg->fd, pucSecondBuf, iSecondBufSize);
			if (iReadSize < 0) {
				status = iReadSize;
				printf("status = 0x%x(in sceIoRead)\n", status);
				goto RELEASE_ARG;
			}
			status = sceAtracSetSecondBuffer(pPlayArg->atracID, pucSecondBuf, iReadSize);
			if (status < 0) {
				printf(D_0001F6E0, status);
				goto RELEASE_ARG;
			}
		}
	}
	pPlayArg->statusflag = sceKernelCreateEventFlag("statusflag", 0, 0, 0);
	if (pPlayArg->statusflag < 0) {
		status = pPlayArg->statusflag;
		printf(D_0001F70C, status);
		goto RELEASE_ARG;
	}
	status = sceAtracGetSoundSample(pPlayArg->atracID, &pPlayArg->iEndSample, &iLoopStartSample, &iLoopEndSample);
	if (status < 0) {
		printf(D_0001F760, status);
		goto RELEASE_ARG;
	}
	status = sceAtracSetLoopNum(pPlayArg->atracID, -1);
	if (status < 0)
		printf(D_0001F738, status);
	return 0;

RELEASE_ARG:
	release_arg(pPlayArg);
	return status;
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F6C0);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F6E0);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F70C);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F738);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F760);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F78C);

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", play_atrac3plus);

extern signed char D_0001F7F4;

void finish_atrac3plus(SceAtracArg *pPlayArg) {
    int temp_v0;

    temp_v0 = sceKernelSetEventFlag(pPlayArg->statusflag, 2);
    if (temp_v0 >= 0) {

    } else {
        printf(&D_0001F7F4, temp_v0);
    }
}

extern signed char D_0001F7F4;

void restart_atrac3plus(SceAtracArg *pPlayArg) {
    int temp_v0;

    temp_v0 = sceKernelSetEventFlag(pPlayArg->statusflag, 1);
    if (temp_v0 >= 0) {

    } else {
        printf(&D_0001F7F4, temp_v0);
    }
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F7F4);

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
    if (pPlayArg->statusflag >= 0) {
        sceKernelDeleteEventFlag(pPlayArg->statusflag);
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

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", reset_position);

int sceKernelPollEventFlag(SceUID evid, SceUInt32 bits, SceUInt32 wait, SceUInt32 *outBits);
static SceUInt32 getPlayMode(SceUID statusflag, SceUInt32 playMode)
{
	SceInt32 status;

	if (playMode == 2)
		return 2;
	status = sceKernelPollEventFlag(statusflag, 1, 0x21, NULL);
	if (status == 0)
		playMode = 1;
	else if (status < 0 && status != (SceInt32)0x800201AF)
		printf("status = 0x%x(in sceKernelPollEventFlag)\n", status);
	status = sceKernelPollEventFlag(statusflag, 2, 0x21, NULL);
	if (status == 0)
		playMode = 2;
	else if (status < 0 && status != (SceInt32)0x800201AF)
		printf("status = 0x%x(in sceKernelPollEventFlag)\n", status);
	return playMode;
}

void fadeoutOperation(short *buf, int n, int total)
{
	int i;
	float step = 1.0f / n;
	float f;

	for (i = 0; i < n; i++) {
		f = (n - 1 - i) * step;
		buf[i * 2] = buf[i * 2] * f;
		buf[i * 2 + 1] = buf[i * 2 + 1] * f;
	}
	for (; i < total; i++) {
		buf[i * 2] = 0;
		buf[i * 2 + 1] = 0;
	}
}
