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
struct t_soundBuffer { /* size 0x2c */
    SceUID lock_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 write2;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 buf_size;
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
extern SceChar8 *output_buf[2];

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 buf_size, SceInt32 buf_num, t_conditionCtrl *pCtrl);
SceInt32 soundbuf_reset(t_soundBuffer *pSound);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound);
static SceInt32 soundbuf_checkDecodeEnd(t_soundBuffer *pSound);
SceInt32 soundbuf_func(SceSize size, SceVoid *argp);
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf);
SceInt32 soundbuf_output(t_soundBuffer *pSound);


/* SDK prototypes (tools/sdk_protos.h) */
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);
int printf(const char *fmt, ...);
int puts(const char *s);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
int sceKernelDelayThread(unsigned int delay);

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 buf_size, SceInt32 buf_num, t_conditionCtrl *pCtrl)
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

	if (sceWaveAudioSetSample(0, 320) != 0) {
		ret = -1;
		goto error;
	}

	pSound->lock_sema = sceKernelCreateSema("sound_lock_sema", 0, 1, 1, NULL);

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
	pSound->pCtrl = pCtrl;

	soundIntervalSize = 653;

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

	pSound->write = 0;
	pSound->write2 = 0;
	pSound->read = 0;
	pSound->count = 0;

	return 0;
}

SceInt32 soundbuf_delete(t_soundBuffer *pSound)
{
	SceInt32 i;

	sceWaveExit();

	sceKernelDeleteSema(pSound->lock_sema);

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
        *buffer = pSound->buf[pSound->write] + (pSound->write2 * 0x140);
    } else {
        *buffer = NULL;
    }
    return temp_v0;
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

SceInt32 soundbuf_setBuf(t_soundBuffer *pSound)
{
	pSound->write2 = (pSound->write2 + 1) % 4;

	if (pSound->write2 == 0) {
		sceKernelWaitSema(pSound->lock_sema, 1, NULL);
		pSound->count++;
		sceKernelSignalSema(pSound->lock_sema, 1);

		pSound->write = (pSound->write + 1) % pSound->size;
	}

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

SceInt32 soundbuf_func(SceSize size, void *argp)
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
			sceKernelWaitSema(pSound->lock_sema, 1, NULL);
			pSound->count--;
			sceKernelSignalSema(pSound->lock_sema, 1);
			soundframeCount++;
		} else {
			soundframeDelay++;
			sceKernelDelayThread(1000);
		}
	}
	printf("sound count = %d\n", soundframeCount);
	printf("sound delay = %d\n", soundframeDelay);
	control_setCondition(pSound->pCtrl, 0x20);
	sceKernelExitThread(0);
	return 0;
}

void *memcpy(void *d, const void *s, unsigned int n);
extern int D_00010BD0;
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf)
{
	memcpy(output_buf[D_00010BD0], buf, pSound->buf_size);
	pSound->read = (pSound->read + 1) % pSound->size;
	sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, output_buf[D_00010BD0]);
	D_00010BD0 ^= 1;
	return 0;
}

SceInt32 soundbuf_output(t_soundBuffer *pSound)
{
	SceChar8 *buf = pSound->buf[pSound->read];

	soundbuf_swapbuf(pSound, buf);
	return 0;
}
