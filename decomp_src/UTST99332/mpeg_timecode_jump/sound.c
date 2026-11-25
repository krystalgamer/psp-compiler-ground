#include "common.h"

/* declarations recovered from DWARF */
struct t_soundBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x4 */
    SceUID control_flag;
};
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_soundBuffer { /* size 0x28 */
    SceUID lockSema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 bufSize;
    t_conditionCtrl *pCtrl;
    SceUInt32 soundLatestPts;
};
typedef struct t_soundBuffer t_soundBuffer;
typedef unsigned int SceSize;
typedef void SceVoid;
struct t_avSyncControl;
struct t_displayBuffer;
struct t_displayBuffer { /* size 0x28 */
    SceUID lockSema;
    SceUID delayFlag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
    t_conditionCtrl *pCtrl;
};
typedef struct t_displayBuffer t_displayBuffer;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};
typedef struct t_avSyncControl t_avSyncControl;

extern SceInt32 soundframeCount;
extern SceInt32 soundframeDelay;
extern SceInt32 soundIntervalSize;
extern SceChar8 *outputBuf[2];

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 bufSize, SceInt32 buf_num, t_conditionCtrl *pCtrl);
SceInt32 soundbuf_reset(t_soundBuffer *pSound);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound);
static SceInt32 soundbuf_checkDecodeEnd(t_soundBuffer *pSound);
SceInt32 soundbuf_func(SceSize size, SceVoid *argp);
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf);
SceInt32 soundbuf_output(t_soundBuffer *pSound);


INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/sound", soundbuf_create);

SceInt32 soundbuf_reset(t_soundBuffer *pSound)
{
	soundframeCount = 0;
	soundframeDelay = 0;
	pSound->write = 0;
	pSound->read = 0;
	pSound->count = 0;
	return 0;
}

int sceKernelDeleteSema(int semid);
void free(void *p);
SceInt32 soundbuf_delete(t_soundBuffer *pSound)
{
	SceInt32 i;

	sceWaveExit();
	sceKernelDeleteSema(pSound->lockSema);
	if (pSound->buf) {
		for (i = 0; i < pSound->size; i++) {
			if (pSound->buf[i]) {
				free(pSound->buf[i]);
				pSound->buf[i] = NULL;
			}
		}
		free(pSound->buf);
		pSound->buf = NULL;
	}
	if (pSound->pts) {
		free(pSound->pts);
		pSound->pts = NULL;
	}
	for (i = 0; i < 2; i++) {
		if (outputBuf[i]) {
			free(outputBuf[i]);
			outputBuf[i] = NULL;
		}
	}
	return 0;
}

int soundbuf_getDrawbuf(t_soundBuffer *pSound, signed char **buffer) {
    int temp_v0;

    temp_v0 = soundbuf_getCapacity(pSound);
    if (temp_v0 > 0) {
        *buffer = pSound->buf[pSound->write];
    } else {
        *buffer = NULL;
    }
    return temp_v0;
}

int soundbuf_setStartPts(t_soundBuffer *pSound, unsigned int pts) {
    pSound->soundLatestPts = pts;
    return 0;
}

int soundbuf_setPts(t_soundBuffer *pSound, unsigned int pts) {
    unsigned int var_a1;

    var_a1 = pts;
    if (var_a1 == -1U) {
        var_a1 = pSound->soundLatestPts + soundIntervalSize;
    }
    pSound->soundLatestPts = var_a1;
    pSound->pts[pSound->write] = var_a1;
    return 0;
}

int soundbuf_getPts(t_soundBuffer *pSound, unsigned int *pPts) {
    *pPts = pSound->pts[pSound->read];
    return 0;
}

int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound)
{
	sceKernelWaitSema(pSound->lockSema, 1, NULL);
	pSound->count++;
	sceKernelSignalSema(pSound->lockSema, 1);
	pSound->write = (pSound->write + 1) % pSound->size;
	return 0;
}

int soundbuf_getCapacity(t_soundBuffer *pSound) {
    return pSound->size - pSound->count;
}

int soundbuf_getCurrentCount(t_soundBuffer *pSound) {
    return pSound->count;
}

static SceInt32 soundbuf_checkDecodeEnd(t_soundBuffer *pSound)
{
	SceUInt32 pattern;

	control_getCondition(pSound->pCtrl, &pattern);
	if (pattern & 0x8)
		return 1;
	return 0;
}

int sceKernelDelayThread(unsigned int delay);
int printf(const char *fmt, ...);
SceInt32 soundbuf_func(SceSize size, SceVoid *argp)
{
	SceInt32 ret;
	t_avSyncControl **ppAvSync;
	t_avSyncControl *pAvSync;
	t_soundBuffer *pSound;

	ppAvSync = argp;
	pAvSync = *ppAvSync;
	pSound = pAvSync->pSound;
	control_waitConditionSoundStart(pSound->pCtrl);
	while (soundbuf_checkDecodeEnd(pSound) != 1 || soundbuf_getCurrentCount(pSound) != 0) {
		if (soundbuf_getCurrentCount(pSound) > 0) {
			soundbuf_output(pSound);
			sceKernelWaitSema(pSound->lockSema, 1, NULL);
			pSound->count--;
			sceKernelSignalSema(pSound->lockSema, 1);
			soundframeCount++;
		} else {
			soundframeDelay++;
			sceKernelDelayThread(1000);
		}
	}
	sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, NULL);
	printf("sound count = %d\n", soundframeCount);
	printf("sound delay = %d\n", soundframeDelay);
	control_setCondition(pSound->pCtrl, 0x20);
	sceKernelExitThread(0);
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/sound", soundbuf_swapbuf);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/sound", soundbuf_output);

int soundbuf_createNextPts(t_soundBuffer *pSound, unsigned int pts, unsigned int *pNextPts) {
    unsigned int var_a1;

    var_a1 = pts;
    if (var_a1 == -1U) {
        var_a1 = pSound->soundLatestPts + soundIntervalSize;
    }
    *pNextPts = var_a1;
    return 0;
}

int soundbuf_getAuTimestamp(t_soundBuffer *pSound) {
    return soundIntervalSize;
}
