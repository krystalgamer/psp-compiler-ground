#include "common.h"
#include "m2c_macros.h"

int printf(const char *, ...);
int sceKernelSetEventFlag(int, M2C_UNK);            /* extern */
extern unsigned char D_0002ED40;
int sceAtracReleaseAtracID(int);                    /* extern */
int sceIoClose(int);                                /* extern */
M2C_UNK sceKernelDeleteEventFlag(int);              /* extern */
extern unsigned char playArg;
typedef long long SceOff_;
typedef struct {
	int atracId;
	int fd;
	int evf;
	int ch;
} AT3ARG;
int sceAtracGetStreamDataInfo(int atracID, unsigned char **ppucWritePointer, unsigned int *puiWritableByte, unsigned int *puiReadPosition);
int sceAtracAddStreamData(int atracID, unsigned int uiAddByte);
int sceAtracGetNextDecodePosition(int atracID, unsigned int *puiSamplePosition);
SceOff_ sceIoLseek(int fd, SceOff_ offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceKernelPollEventFlag(int evid, unsigned int bits, unsigned int wait, unsigned int *outBits);


#ifdef NON_MATCHING
/* Close (2 insns): the original's sceIoLseek error path enters the shared printf after the
 * a1 = status move, so that move cannot fill the delay slot; the four -1/ch stores and
 * buf/arg registers also differ. */
int sceIoOpen(const char *path, int flags, int mode);
int sceAtracSetDataAndGetID(void *buf, int size);
int sceAtracGetSecondBufferInfo(int atracId, unsigned int *pos, unsigned int *size);
int sceAtracSetSecondBuffer(int atracId, void *buf, unsigned int size);
int sceKernelCreateEventFlag(const char *name, int attr, int bits, void *opt);
int sceAtracGetSoundSample(int atracId, int *end, int *loopStart, int *loopEnd);
int sceAtracSetLoopNum(int atracId, int num);
extern char D_0002EBF8[], D_0002EC18[], D_0002EC44[], D_0002EC70[], D_0002EC98[], D_0002ECC4[];
void release_arg(void *arg);
int init_atrac3plus(const char *path, void *buf, int size, void *buf2, int size2, int ch, AT3ARG *arg)
{
	unsigned int pos, len;
	int ls, le;

	arg->evf = -1;
	arg->ch = ch;
	arg->fd = -1;
	arg->atracId = -1;
	arg->fd = sceIoOpen(path, 1, 0);
	if (arg->fd < 0) {
		size = arg->fd;
		printf(D_0002ECC4, size);
		release_arg(arg);
		return size;
	}
	size = sceIoRead(arg->fd, buf, size);
	if (size < 0) {
		printf("status = 0x%x(in sceIoRead)\n", size);
		release_arg(arg);
		return size;
	}
	size = arg->atracId = sceAtracSetDataAndGetID(buf, size);
	if (size < 0) {
		printf("status = 0x%x(in sceAtracSetDataAndGetID)\n", size);
		release_arg(arg);
		return size;
	}
	size = sceAtracGetSecondBufferInfo(arg->atracId, &pos, &len);
	if (size != (int)0x80630022) {
		if (size < 0) {
			printf("status = 0x%x(in sceAtracGetSecondBuffer)\n", size);
			release_arg(arg);
			return size;
		}
		size = sceIoLseek(arg->fd, pos, 0);
		if (size < 0) {
			printf(D_0002EBF8, size);
			release_arg(arg);
			return size;
		}
		size = sceAtracSetSecondBuffer(arg->atracId, buf2, sceIoRead(arg->fd, buf2, size2));
		if (size < 0) {
			printf(D_0002EC18, size);
			release_arg(arg);
			return size;
		}
	}
	size = arg->evf = sceKernelCreateEventFlag("statusflag", 0, 0, 0);
	if (size < 0) {
		printf(D_0002EC44, size);
		release_arg(arg);
		return size;
	}
	size = sceAtracGetSoundSample(arg->atracId, (int *)(arg + 1), &ls, &le);
	if (size < 0) {
		printf(D_0002EC98, size);
		release_arg(arg);
		return size;
	}
	size = sceAtracSetLoopNum(arg->atracId, -1);
	if (size < 0)
		printf(D_0002EC70, size);
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", init_atrac3plus);
#endif

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EBF8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC18);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC44);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC70);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC98);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002ECC4);

extern int NowBgm;
extern int PlayFlag;
int sceAtracGetRemainFrame(int atracId, int *remain);
int sceAtracDecodeData(int atracId, void *buf, int *samples, int *end, int *remain);
int sceAtracGetInternalErrorInfo(int atracId, int *err);
int sceWaveAudioSetSample(int ch, int samples);
int sceWaveAudioWriteBlocking(int ch, int l, int r, void *buf);
int sceKernelExitThread(int status);
void *memcpy(void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);
int puts(const char *);
void at3plus_addData(int atracId, int fd);
void at3plus_DisplayDecodePosition(int *arg);
void reset_position(AT3ARG *arg);
int getPlayMode(int evf, int mode);
void fadeoutOperation(short *buf, int n, int total);
void release_arg(void *arg);

int play_atrac3plus(unsigned int args, void *argp)
{
	unsigned char aucBuf[0x8000 + 0x40];
	int remain;
	int samples;
	int end;
	int err;
	int mode;
	AT3ARG *arg = argp;
	unsigned int *buf = (unsigned int *)(((unsigned int)aucBuf + 0x3c) & ~0x3f);
	int vol = 0x8000;
	unsigned int pos = 0;
	unsigned int done = 0;
	int border;
	int ret;
	unsigned int n, raw;

	ret = sceAtracGetRemainFrame(arg->atracId, &remain);
	mode = 0;
	if (ret < 0)
		printf("sceAtracGetRemainFrame err 0x%x\n", ret);
	border = remain / 2;
	if (border < 1)
		border = 1;
	do {
		at3plus_DisplayDecodePosition((int *)arg);
		ret = sceAtracDecodeData(arg->atracId, buf + pos, &samples, &end, &remain);
		if (ret < 0) {
			sceAtracGetInternalErrorInfo(arg->atracId, &err);
			printf("sceAtracDecodeData err 0x%x (%d)\n", ret, err);
			break;
		}
		pos += samples;
		raw = pos - done;
		if (raw >= 0x800) {
			n = raw & ~0x3f;
			if (mode == 1)
				fadeoutOperation((short *)(buf + done), n, raw);
			sceWaveAudioSetSample(arg->ch, n);
			sceWaveAudioWriteBlocking(arg->ch, vol, vol, buf + done);
			done += n;
			if (mode == 1) {
				reset_position(arg);
				mode = 0;
			}
		}
		if (pos >= 0x1800) {
			pos -= done;
			memcpy(buf, buf + done, pos * 4);
			done = 0;
		}
		if (remain <= border && remain != -1)
			at3plus_addData(arg->atracId, arg->fd);
		mode = getPlayMode(arg->evf, mode);
		if (mode == 2) {
			vol -= 0x400;
			if (vol < 0) {
				end = 1;
				vol = 0;
				puts("Fade out end....");
			}
		}
	} while (end == 0);
	if (vol != 0 && done < pos) {
		memset(buf + pos, 0, (0x800 - (pos - done)) * 4);
		sceWaveAudioSetSample(arg->ch, 0x800);
		sceWaveAudioWriteBlocking(arg->ch, vol, vol, buf + done);
	}
	sceWaveAudioWriteBlocking(arg->ch, vol, vol, 0);
	release_arg(arg);
	NowBgm = -1;
	PlayFlag = 0;
	sceKernelExitThread(0);
	return 0;
}

void finish_atrac3plus(void *arg0) {
    int temp_v0;

    temp_v0 = sceKernelSetEventFlag(M2C_FIELD(arg0, int *, 8), 2);
    if (temp_v0 >= 0) {

    } else {
        printf((const char *)&D_0002ED40, temp_v0);
    }
}

void restart_atrac3plus(void *arg0) {
    int temp_v0;

    temp_v0 = sceKernelSetEventFlag(M2C_FIELD(arg0, int *, 8), 1);
    if (temp_v0 >= 0) {

    } else {
        printf((const char *)&D_0002ED40, temp_v0);
    }
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002ED40);

void release_arg(void *arg0) {
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, int *, 0);
    if ((temp_v0 < 0) || (temp_v0_2 = sceAtracReleaseAtracID(temp_v0), (temp_v0_2 >= 0))) {

    } else {
        printf("status = 0x%x(in sceAtracReleaseID)\n", temp_v0_2);
    }
    if ((M2C_FIELD(arg0, int *, 4) < 0) || (temp_v0_3 = sceIoClose(M2C_FIELD(arg0, int *, 4)), (temp_v0_3 >= 0))) {

    } else {
        printf("status = 0x%x(in sceIoClose)\n", temp_v0_3);
    }
    if (M2C_FIELD(arg0, int *, 8) >= 0) {
        sceKernelDeleteEventFlag(M2C_FIELD(arg0, int *, 8));
    }
}

void at3plus_addData(int atracId, int fd)
{
	unsigned char *p;
	unsigned int writable;
	unsigned int readpos;
	int status;
	int add;

	status = sceAtracGetStreamDataInfo(atracId, &p, &writable, &readpos);
	if (status < 0)
		printf("sceAtracGetStreamDataInfo = 0x%x\n", status);
	status = sceIoLseek(fd, readpos, 0);
	if (status < 0)
		printf("sceIoLseek Error = 0x%x", status);
	add = sceIoRead(fd, p, writable);
	if (add < 0)
		printf("sceIoRead Error = 0x%x\n", add);
	status = sceAtracAddStreamData(atracId, add);
	if (status < 0)
		printf("sceAtracAddStreamData = 0x%x\n", status);
}

void at3plus_DisplayDecodePosition(int *arg)
{
	unsigned int pos;
	int status;

	status = sceAtracGetNextDecodePosition(arg[0], &pos);
	if (status < 0)
		printf("sceAtracGetNextDecodePosition = 0x%x\n", status);
}

#ifdef NON_MATCHING
/* Close: the error printf branches are laid out/delay-slot filled differently
 * (the original's SetLoopNum error shares the common printf tail). */
typedef struct {
	unsigned char *pWrite;
	unsigned int writable;
	unsigned int minWrite;
	unsigned int readPos;
} AT3BUFINFO;
int sceAtracGetBufferInfoForReseting(int atracId, unsigned int sample, AT3BUFINFO *info);
int sceAtracResetPlayPosition(int atracId, unsigned int sample, unsigned int first, unsigned int second);
int sceAtracSetLoopNum(int atracId, int num);
extern char D_0002EBF8[], D_0002EC70[];
void reset_position(AT3ARG *arg)
{
	AT3BUFINFO info[2];
	int first = 0, second = 0;
	int ret;

	ret = sceAtracGetBufferInfoForReseting(arg->atracId, 0, info);
	if (ret < 0)
		goto err_info;
	if (info[0].minWrite != 0) {
		ret = sceIoLseek(arg->fd, info[0].readPos, 0);
		if (ret < 0)
			goto err_seek;
		ret = first = sceIoRead(arg->fd, info[0].pWrite, info[0].writable);
		if (first < 0)
			goto err_info;
	}
	if (info[1].minWrite != 0) {
		ret = sceIoLseek(arg->fd, info[1].readPos, 0);
		if (ret < 0)
			goto err_seek;
		ret = second = sceIoRead(arg->fd, info[1].pWrite, info[1].writable);
		if (second < 0)
			goto err_info;
	}
	ret = sceAtracResetPlayPosition(arg->atracId, 0, first, second);
	if (ret < 0)
		printf("status = 0x%x (in sceAtracResetPlayPosition)\n", ret);
	ret = sceAtracSetLoopNum(arg->atracId, -1);
	if (ret < 0)
		printf(D_0002EC70, ret);
	return;
err_seek:
	printf(D_0002EBF8, ret);
	return;
err_info:
	printf("status = 0x%x(in sceAtracGetBufferInfoForResting)\n", ret);
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", reset_position);
#endif

int getPlayMode(int evf, int mode)
{
	int status;

	if (mode == 2)
		return 2;
	status = sceKernelPollEventFlag(evf, 1, 0x21, 0);
	if (status == 0)
		mode = 1;
	else if (status < 0 && status != (int)0x800201AF)
		printf("status = 0x%x(in sceKernelPollEventFlag)\n", status);
	status = sceKernelPollEventFlag(evf, 2, 0x21, 0);
	if (status == 0)
		mode = 2;
	else if (status < 0 && status != (int)0x800201AF)
		printf("status = 0x%x(in sceKernelPollEventFlag)\n", status);
	return mode;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EEE0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EF00);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EF0C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EF2C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EF40);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EF50);

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

int at3_bgm_play_end(void) {
    finish_atrac3plus(&playArg);
    return 0;
}

#ifdef NON_MATCHING
/* Close: on success the original stores BgmThread before setting v0 (ours fills the delay slot with the store). */
extern char D_0002EEE0[], D_0002EF00[], D_0002EF0C[], D_0002EF2C[], D_0002EF40[], D_0002EF50[];
extern unsigned char aucFirstBuf[], aucSecondBuf[];
extern int BgmThread;
int init_atrac3plus(char *path, void *buf1, int size1, void *buf2, int size2, int a5, void *arg);
int play_atrac3plus(unsigned int args, void *argp);
int sceKernelCreateThread(const char *name, void *entry, int initPriority, int stackSize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
int sceKernelDeleteThread(int thid);
int sceWaveExit(void);
int puts(const char *);
int at3_bgm_play(char *path)
{
	int ret;
	int thid;

	ret = init_atrac3plus(path, aucFirstBuf, 0x11A800, aucSecondBuf, 0x11A800, 0, &playArg);
	if (ret < 0) {
		printf(D_0002EEE0, ret);
	} else {
		if (BgmThread > 0)
			sceKernelDeleteThread(BgmThread);
		thid = sceKernelCreateThread(D_0002EF00, play_atrac3plus, 0x12, 0x10000, 0, 0);
		if (thid >= 0) {
			ret = sceKernelStartThread(thid, 0x14, &playArg);
			if (ret != 0) {
				printf(D_0002EF0C, ret);
			} else {
				printf(D_0002EF40, path);
				BgmThread = thid;
				return thid;
			}
		} else {
			printf(D_0002EF50, thid);
			ret = thid;
		}
	}
	if (sceWaveExit() != 0) {
		puts(D_0002EF2C);
		ret = -1;
	}
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", at3_bgm_play);
#endif
