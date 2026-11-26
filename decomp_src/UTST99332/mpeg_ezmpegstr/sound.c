#include "common.h"

/* declarations recovered from DWARF */
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
typedef struct t_soundBuffer t_soundBuffer;
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
typedef struct SceKernelEventFlagInfo SceKernelEventFlagInfo;
struct t_avSyncControl;
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
extern SceChar8 *output_buf[2];

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 buf_size, SceInt32 buf_num);
SceInt32 soundbuf_reset(t_soundBuffer *pSound);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound);
static SceInt32 soundbuf_getStatus(t_soundBuffer *pSound, SceUInt32 *pPattern);
static SceInt32 soundbuf_checkDemuxEnd(t_soundBuffer *pSound);
SceInt32 soundbuf_func(SceSize size, void *argp);
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf);
SceInt32 soundbuf_output(t_soundBuffer *pSound);


SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 buf_size, SceInt32 buf_num)
{
	SceInt32 i, ret;

	pSound->buf = NULL;
	pSound->pts = NULL;

	ret = 0;

	if (sceWaveInit() != 0) {
		printf("fatal error : sceWaveInit()\n");
		ret = -1;
		goto error;
	}

	if (sceWaveAudioSetSample(0, 2048) != 0) {
		ret = -1;
		goto error;
	}

	pSound->lock_sema = sceKernelCreateSema("sound_lock_sema", 0, 1, 1, NULL);

	pSound->status_flag = sceKernelCreateEventFlag("sound_status_eventflag", 0, 0, 0);

	pSound->buf = malloc(buf_num * sizeof(SceChar8 *));
	if (pSound->buf == NULL) {
		ret = -1;
		goto error;
	}

	for (i = 0; i < buf_num; i++) {
		pSound->buf[i] = NULL;
	}

	for (i = 0; i < buf_num; i++) {
		pSound->buf[i] = memalign(64, buf_size);
		if (pSound->buf[i] == NULL) {
			ret = -1;
			goto error;
		}
	}

	pSound->pts = malloc(buf_num * sizeof(SceUInt32));
	if (pSound->pts == NULL) {
		ret = -1;
		goto error;
	}

	for (i = 0; i < 2; i++) {
		output_buf[i] = malloc(buf_size);
		if (output_buf[i] == NULL) {
			goto error;
		}
	}

	pSound->buf_size = buf_size;
	pSound->size = buf_num;

	soundIntervalSize = 4179;

	goto term;

error:
	if (pSound->buf != NULL) {
		for (i = 0; i < pSound->size; i++) {
			if (pSound->buf[i] != NULL) {
				free(pSound->buf[i]);
			}
		}

		free(pSound->buf);
	}

	if (pSound->pts != NULL) {
		free(pSound->pts);
	}

	for (i = 0; i < 2; i++) {
		if (output_buf[i] != NULL) {
			free(output_buf[i]);
		}
	}

term:
	return ret;
}

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

SceInt32 soundbuf_delete(t_soundBuffer *pSound)
{
	SceInt32 i;

	sceWaveExit();

	sceKernelDeleteSema(pSound->lock_sema);
	sceKernelDeleteEventFlag(pSound->status_flag);

	if (pSound->buf != NULL) {
		for (i = 0; i < pSound->size; i++) {
			if (pSound->buf[i] != NULL) {
				free(pSound->buf[i]);
			}
		}
		free(pSound->buf);
	}

	if (pSound->pts != NULL) {
		free(pSound->pts);
	}

	for (i = 0; i < 2; i++) {
		if (output_buf[i] != NULL) {
			free(output_buf[i]);
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

int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
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

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/sound", soundbuf_func);

void *memcpy(void *d, const void *s, unsigned int n);
extern int D_0001033C;
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf)
{
	memcpy(output_buf[D_0001033C], buf, pSound->buf_size);
	pSound->read = (pSound->read + 1) % pSound->size;
	sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, output_buf[D_0001033C]);
	D_0001033C ^= 1;
	return 0;
}

SceInt32 soundbuf_output(t_soundBuffer *pSound)
{
	SceChar8 *buf = pSound->buf[pSound->read];

	soundbuf_swapbuf(pSound, buf);
	return 0;
}
