#include "common.h"

/* declarations recovered from DWARF */
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
typedef int SceUID;
typedef int SceInt32;
typedef char SceChar8;
typedef unsigned int SceUInt32;
struct t_soundBuffer { /* size 0x24 */
    SceUID lock_sema;
    SceInt32 *terminate_flag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 *write;
    SceInt32 *read;
    SceInt32 *count;
    SceInt32 *size;
    SceUID start_sema;
};
typedef unsigned int SceSize;
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
struct t_displayBuffer { /* size 0x38 */
    SceUID start_sema;
    SceUID lock_sema;
    SceUID display_wait_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 *write;
    SceInt32 *read;
    SceInt32 *count;
    SceInt32 *size;
    SceInt32 pixelFormat;
    SceInt32 *displayMode;
    SceInt32 *scale;
    SceInt32 *posx;
    SceInt32 *posy;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x14 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
};
struct t_avSyncControl { /* size 0x1c */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};

extern SceInt32 sound_terminate_flag;
extern SceInt32 sound_write;
extern SceInt32 sound_read;
extern SceInt32 sound_count;
extern SceInt32 sound_size;
extern int soundframe_count;
extern int soundframe_delay;
extern int soundLatestPts;

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 buf_size, SceInt32 buf_num);
SceInt32 soundbuf_init(t_soundBuffer *pSound);
SceInt32 soundbuf_end(t_soundBuffer *pSound);
SceInt32 soundbuf_getDrawbuf(t_soundBuffer *pSound, SceChar8 **buffer);
SceInt32 soundbuf_setPts(t_soundBuffer *pSound, SceUInt32 pts);
SceInt32 soundbuf_getPts(t_soundBuffer *pSound, SceUInt32 *pPts);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound);
SceInt32 soundbuf_getCapacity(t_soundBuffer *pSound);
SceInt32 soundbuf_getCurrentCount(t_soundBuffer *pSound);
SceInt32 soundbuf_setDemuxEnd(t_soundBuffer *pSound);
static SceInt32 soundbuf_isEnd(t_soundBuffer *pSound);
SceInt32 soundbuf_setStartFlag(t_soundBuffer *pSound);
SceInt32 soundbuf_func(SceSize size, void *argp);
SceInt32 soundbuf_output(t_soundBuffer *pSound);


int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);
void free(void *p);
INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/sound", func_00003B78);

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 buf_size, SceInt32 buf_num)
{
	SceInt32 i;
	SceInt32 ret = 0;

	pSound->buf = NULL;
	pSound->pts = NULL;

	if (sceWaveAudioSetSample(0, 2048) != 0) {
		ret = -1;
		goto ERROR;
	}

	pSound->lock_sema = sceKernelCreateSema("sound_lock_sema", 0, 1, 1, NULL);
	pSound->start_sema = sceKernelCreateSema("sound_start_sema", 0, 0, 1, NULL);

	pSound->buf = malloc(buf_num * sizeof(SceChar8 *));
	if (pSound->buf == NULL) {
		ret = -1;
		goto ERROR;
	}
	for (i = 0; i < buf_num; i++)
		pSound->buf[i] = NULL;
	for (i = 0; i < buf_num; i++) {
		pSound->buf[i] = memalign(64, buf_size);
		if (pSound->buf[i] == NULL) {
			ret = -1;
			goto ERROR;
		}
	}

	pSound->pts = malloc(16);
	if (pSound->pts == NULL) {
		ret = -1;
		goto ERROR;
	}

	pSound->terminate_flag = &sound_terminate_flag;
	pSound->write = &sound_write;
	pSound->read = &sound_read;
	pSound->count = &sound_count;
	pSound->size = &sound_size;
	sound_size = buf_num;
	return ret;

ERROR:
	if (pSound->buf) {
		for (i = 0; i < *pSound->size; i++) {
			if (pSound->buf[i])
				free(pSound->buf[i]);
		}
		free(pSound->buf);
	}
	if (pSound->pts)
		free(pSound->pts);
	return ret;
}

SceInt32 soundbuf_init(t_soundBuffer *pSound)
{
	soundframe_count = 0;
	soundframe_delay = 0;
	sceKernelPollSema(pSound->start_sema, 1);
	*pSound->terminate_flag = 0;
	*pSound->write = 0;
	*pSound->read = 0;
	*pSound->count = 0;
	return 0;
}

int sceKernelDeleteSema(int semid);
SceInt32 soundbuf_end(t_soundBuffer *pSound)
{
	SceInt32 i;

	sceKernelDeleteSema(pSound->lock_sema);
	sceKernelDeleteSema(pSound->start_sema);
	if (pSound->buf) {
		for (i = 0; i < *pSound->size; i++) {
			if (pSound->buf[i])
				free(pSound->buf[i]);
		}
		free(pSound->buf);
	}
	if (pSound->pts)
		free(pSound->pts);
	return 0;
}

SceInt32 soundbuf_getDrawbuf(t_soundBuffer *pSound, SceChar8 **buffer)
{
	SceInt32 ret;

	ret = soundbuf_getCapacity(pSound);
	if (ret > 0)
		*buffer = pSound->buf[*pSound->write];
	else
		*buffer = NULL;
	return ret;
}

SceInt32 soundbuf_setPts(t_soundBuffer *pSound, SceUInt32 pts)
{
	SceInt32 ret = 0;

	if (pts == (SceUInt32)-1)
		pts = soundLatestPts + 4180;
	soundLatestPts = pts;
	pSound->pts[*pSound->write] = pts;
	return ret;
}

SceInt32 soundbuf_getPts(t_soundBuffer *pSound, SceUInt32 *pPts)
{
	SceInt32 ret = 0;

	*pPts = pSound->pts[*pSound->read];
	return ret;
}

int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound)
{
	sceKernelWaitSema(pSound->lock_sema, 1, NULL);
	(*pSound->count)++;
	sceKernelSignalSema(pSound->lock_sema, 1);
	*pSound->write = (*pSound->write + 1) % *pSound->size;
	return 0;
}

SceInt32 soundbuf_getCapacity(t_soundBuffer *pSound)
{
	return *pSound->size - *pSound->count;
}

SceInt32 soundbuf_getCurrentCount(t_soundBuffer *pSound)
{
	return *pSound->count;
}

SceInt32 soundbuf_setDemuxEnd(t_soundBuffer *pSound)
{
	*pSound->terminate_flag = 1;
	return 0;
}

static SceInt32 soundbuf_isEnd(t_soundBuffer *pSound)
{
	return *pSound->terminate_flag;
}

SceInt32 soundbuf_setStartFlag(t_soundBuffer *pSound)
{
	return sceKernelSignalSema(pSound->start_sema, 1);
}

int sceKernelDelayThread(unsigned int delay);
SceInt32 soundbuf_func(SceSize size, void *argp)
{
	SceInt32 ret;
	SceInt32 first_flag;
	t_avSyncControl *pAvSync;
	t_soundBuffer *pSound;

	pAvSync = (t_avSyncControl *)argp;
	pSound = pAvSync->pSound;
	first_flag = 0;

	sceKernelWaitSema(pSound->start_sema, 1, NULL);

	while (!soundbuf_isEnd(pSound)) {
		if (soundbuf_getCurrentCount(pSound) > 0) {
			soundbuf_output(pSound);
			if (first_flag > 0) {
				sceKernelWaitSema(pSound->lock_sema, 1, NULL);
				(*pSound->count)--;
				sceKernelSignalSema(pSound->lock_sema, 1);
			} else {
				first_flag++;
			}
			soundframe_count++;
		} else {
			soundframe_delay++;
			sceKernelDelayThread(1000);
		}
	}

	while (soundbuf_getCurrentCount(pSound) > 0) {
		soundbuf_output(pSound);
		sceKernelWaitSema(pSound->lock_sema, 1, NULL);
		(*pSound->count)--;
		sceKernelSignalSema(pSound->lock_sema, 1);
		soundframe_count++;
	}

	sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, NULL);
	sceKernelExitThread(0);
	return 0;
}

SceInt32 soundbuf_output(t_soundBuffer *pSound)
{
	SceChar8 *currentBuf;

	currentBuf = pSound->buf[*pSound->read];
	sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, currentBuf);
	*pSound->read = (*pSound->read + 1) % *pSound->size;
	return 0;
}
