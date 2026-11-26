#include "common.h"

/* declarations recovered from DWARF */
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
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
typedef unsigned int SceSize;
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_displayBuffer t_displayBuffer;
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
extern SceChar8 *outputBuf[2];

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 bufSize, SceInt32 bufNum, t_conditionCtrl *pCtrl);
SceInt32 soundbuf_reset(t_soundBuffer *pSound);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound);
static SceInt32 soundbuf_checkDecodeEnd(t_soundBuffer *pSound);
int soundbuf_func(SceSize size, void *argp);
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf);
SceInt32 soundbuf_output(t_soundBuffer *pSound);


INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/sound", soundbuf_create);

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

SceInt32 control_setCondition(t_conditionCtrl *pCtrl, SceInt32 cond);
SceInt32 control_waitConditionSoundStart(t_conditionCtrl *pCtrl);
int sceWaveAudioGetRestSample(int channel);
int sceKernelExitThread(int status);
int sceKernelDelayThread(unsigned int delay);
int sceKernelWaitSema(SceUID semid, int signal, unsigned int *timeout);
int sceKernelSignalSema(SceUID semid, int signal);
int printf(const char *fmt, ...);

const char D_00012444[] = "sound count = %d\n";
const char D_00012458[] = "sound delay = %d\n";

int soundbuf_func(SceSize size, void *argp)
{
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
	while (sceWaveAudioGetRestSample(0) != 0)
		sceKernelDelayThread(1000);
	printf(D_00012444, soundframeCount);
	printf(D_00012458, soundframeDelay);
	control_setCondition(pSound->pCtrl, 0x20);
	sceKernelExitThread(0);
	return 0;
}

void *memcpy(void *d, const void *s, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
#define currentBuf D_00013738	/* soundbuf_swapbuf's static */
extern SceInt32 currentBuf;
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf)
{
	memcpy(outputBuf[currentBuf], buf, pSound->bufSize);
	pSound->read = (pSound->read + 1) % pSound->size;
	sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, outputBuf[currentBuf]);
	currentBuf ^= 1;
	return 0;
}

SceInt32 soundbuf_output(t_soundBuffer *pSound)
{
	SceChar8 *buf = pSound->buf[pSound->read];

	soundbuf_swapbuf(pSound, buf);
	return 0;
}
