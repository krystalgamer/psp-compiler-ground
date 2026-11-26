/* cflags: -O2 */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 mpeg_ezmpegstr sound) */
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
struct t_soundBuffer { /* size 0x28 */
    SceUID lock_sema;
    SceUID status_flag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 buf_size;
    SceUInt32 soundLatestTimestamp;
};
typedef struct SceKernelEventFlagInfo SceKernelEventFlagInfo;
struct SceKernelEventFlagInfo;
typedef unsigned int SceSize;
typedef unsigned int SceUInt;
struct SceKernelEventFlagInfo { /* size 0x34 */
    SceSize size;
    char name[32];
    SceUInt attr;
    SceUInt initPattern;
    SceUInt currentPattern;
    int numWaitThreads;
};
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
struct t_displayBuffer { /* size 0x28 */
    SceUID start_sema;
    SceUID lock_sema;
    SceUID display_wait_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};

extern SceInt32 soundframeCount;
extern SceInt32 soundframeDelay;
extern SceInt32 soundIntervalSize;
extern SceChar8 *output_buf[2];

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 buf_size, SceInt32 buf_num);
SceInt32 soundbuf_setPts(t_soundBuffer *pSound, SceUInt32 pts);
SceInt32 soundbuf_getPts(t_soundBuffer *pSound, SceUInt32 *pPts);
SceInt32 soundbuf_getCapacity(t_soundBuffer *pSound);
SceInt32 soundbuf_getCurrentCount(t_soundBuffer *pSound);
SceInt32 soundbuf_setDemuxEnd(t_soundBuffer *pSound);
SceInt32 soundbuf_setStartFlag(t_soundBuffer *pSound);
SceInt32 soundbuf_output(t_soundBuffer *pSound);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_create);

SceInt32 soundbuf_reset(t_soundBuffer *pSound)
{
	soundframeCount = 0;
	soundframeDelay = 0;
	sceKernelClearEventFlag(pSound->status_flag, 0);
	pSound->write = 0;
	pSound->read = 0;
	pSound->count = 0;
	pSound->soundLatestTimestamp = 0;
	return 0;
}

void psp_free(void *p);
SceInt32 soundbuf_delete(t_soundBuffer *pSound)
{
	int i;

	sceWaveExit();
	sceKernelDeleteSema(pSound->lock_sema);
	sceKernelDeleteEventFlag(pSound->status_flag);
	if (pSound->buf != NULL) {
		for (i = 0; i < pSound->size; i++) {
			if (pSound->buf[i] != NULL) {
				psp_free(pSound->buf[i]);
			}
		}
		psp_free(pSound->buf);
	}
	if (pSound->pts != NULL) {
		psp_free(pSound->pts);
	}
	for (i = 0; i < 2; i++) {
		if (output_buf[i] != NULL) {
			psp_free(output_buf[i]);
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

int soundbuf_setPts(t_soundBuffer *pSound, unsigned int pts) {
    unsigned int var_a1;

    var_a1 = pts;
    if (var_a1 == -1U) {
        var_a1 = pSound->soundLatestTimestamp + soundIntervalSize;
    }
    pSound->soundLatestTimestamp = var_a1;
    pSound->pts[pSound->write] = var_a1;
    return 0;
}

int soundbuf_getPts(t_soundBuffer *pSound, unsigned int *pPts) {
    *pPts = pSound->pts[pSound->read];
    return 0;
}

SceInt32 soundbuf_setBuf(t_soundBuffer *pSound)
{
	sceKernelWaitSema(pSound->lock_sema, 1, 0);
	pSound->count++;
	sceKernelSignalSema(pSound->lock_sema, 1);
	pSound->write = (pSound->write + 1) % pSound->size;
	return 0;
}

int soundbuf_getCapacity(t_soundBuffer *pSound) {
    return pSound->size - pSound->count;
}

int soundbuf_getCurrentCount(t_soundBuffer *pSound) {
    return pSound->count;
}

int soundbuf_setDemuxEnd(t_soundBuffer *pSound) {
    sceKernelSetEventFlag(pSound->status_flag, 3);
    return 0;
}

static SceInt32 soundbuf_getStatus(t_soundBuffer *pSound, SceUInt32 *pPattern)
{
	SceKernelEventFlagInfo info;

	info.size = sizeof(info);
	sceKernelReferEventFlagStatus(pSound->status_flag, &info);
	*pPattern = info.currentPattern;
	return 0;
}

static SceInt32 soundbuf_checkDemuxEnd(t_soundBuffer *pSound)
{
	SceUInt32 pattern;

	soundbuf_getStatus(pSound, &pattern);
	if ((pattern & 3) == 3) {
		return 0;
	}
	return -1;
}

int soundbuf_setStartFlag(t_soundBuffer *pSound) {
    return sceKernelSetEventFlag(pSound->status_flag, 1);
}

SceInt32 soundbuf_func(SceSize size, void *argp)
{
	t_soundBuffer *pSound = (*(t_avSyncControl **)argp)->pSound;
	SceUInt32 pattern;

	sceKernelWaitEventFlag(pSound->status_flag, 1, 1, &pattern, 0);
	while (soundbuf_checkDemuxEnd(pSound) != 0 || soundbuf_getCurrentCount(pSound) != 0) {
		if (soundbuf_getCurrentCount(pSound) > 0) {
			soundbuf_output(pSound);
			sceKernelWaitSema(pSound->lock_sema, 1, NULL);
			pSound->count--;
			sceKernelSignalSema(pSound->lock_sema, 1);
			soundframeCount++;
		} else {
			soundframeDelay++;
			sceKernelDelayThread(1000);
		}
	}
	while (sceWaveAudioGetRestSample(0) != 0) {
		sceKernelDelayThread(1000);
	}
	sceKernelExitThread(0);
	return 0;
}

extern int D_00288EA8;
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf)
{
	memcpy(output_buf[D_00288EA8], buf, pSound->buf_size);
	pSound->read = (pSound->read + 1) % pSound->size;
	sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, output_buf[D_00288EA8]);
	D_00288EA8 ^= 1;
	return 0;
}

SceInt32 soundbuf_output(t_soundBuffer *pSound)
{
	SceChar8 *buf = pSound->buf[pSound->read];

	soundbuf_swapbuf(pSound, buf);
	return 0;
}
