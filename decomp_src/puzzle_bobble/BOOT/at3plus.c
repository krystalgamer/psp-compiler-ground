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
int sceAtracGetStreamDataInfo(int atracID, unsigned char **ppucWritePointer, unsigned int *puiWritableByte, unsigned int *puiReadPosition);
int sceAtracAddStreamData(int atracID, unsigned int uiAddByte);
int sceAtracGetNextDecodePosition(int atracID, unsigned int *puiSamplePosition);
SceOff_ sceIoLseek(int fd, SceOff_ offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceKernelPollEventFlag(int evid, unsigned int bits, unsigned int wait, unsigned int *outBits);


INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", init_atrac3plus);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EBF8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC18);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC44);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC70);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC98);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002ECC4);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", play_atrac3plus);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", reset_position);

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
