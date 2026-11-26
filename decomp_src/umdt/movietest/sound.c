/* cflags: -O0 */
#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread.h>
#include <libwave.h>
#include "display.h"
#include "sound.h"
#include "avsync.h"

extern SceInt32 sound_terminate_flag;
extern SceInt32 sound_write;
extern SceInt32 sound_read;
extern SceInt32 sound_count;
extern SceInt32 sound_size;
extern int soundframe_count;
extern int soundframe_delay;
extern int soundLatestPts;
extern SceUID _fplid_7400[2];

static SceInt32 soundbuf_isEnd(t_soundBuffer *pSound);

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 buf_size, SceInt32 buf_num, SceUID sync_sema)
{
	SceInt32 i;
	void *addr;
	SceInt32 err;
	char msg1[112];
	char msg2[112];
	char msg3[112];

	pSound->buf = NULL;
	if (sceWaveInit()) {
		sprintf(msg1, "wave init error\n");
		sceIoWrite(0, msg1, strlen(msg1));
		return -1;
	}
	if (sceWaveAudioSetSample(0, 2048))
		return -1;
	pSound->lock_sema = sceKernelCreateSema("sound_lock_sema", 0, 1, 1, NULL);
	_fplid_7400[0] = sceKernelCreateFpl("MovieTestSound1Fpl", 2, 0x100, buf_num * 4, 1, NULL);
	if (_fplid_7400[0] < 0) {
		sprintf(msg1, "Sound sceKernelCreateFpl 1 = %08X", _fplid_7400[0]);
		sceIoWrite(0, msg1, strlen(msg1));
		_fplid_7400[0] = 0;
		return -1;
	}
	err = sceKernelTryAllocateFpl(_fplid_7400[0], (void **)&pSound->buf);
	if (err < 0) {
		sprintf(msg2, "Sound sceKernelTryAllocateFpl 1 = %08X", err);
		sceIoWrite(0, msg2, strlen(msg2));
		return -1;
	}
	_fplid_7400[1] = sceKernelCreateFpl("MovieTest2SoundFpl", 2, 0x100, buf_size * buf_num + 64, 1, NULL);
	if (_fplid_7400[1] < 0) {
		sprintf(msg2, "Sound sceKernelCreateFpl 2 = %08X", _fplid_7400[1]);
		sceIoWrite(0, msg2, strlen(msg2));
		_fplid_7400[1] = 0;
		return -1;
	}
	err = sceKernelTryAllocateFpl(_fplid_7400[1], &addr);
	if (err < 0) {
		sprintf(msg3, "Sound sceKernelTryAllocateFpl 2 = %08X", err);
		sceIoWrite(0, msg3, strlen(msg3));
		return -1;
	}
	addr = (void *)(((unsigned int)addr + 63) & ~63);
	for (i = 0; i < buf_num; i++)
		pSound->buf[i] = (SceChar8 *)addr + buf_size * i;
	pSound->terminate_flag = &sound_terminate_flag;
	pSound->write = &sound_write;
	pSound->read = &sound_read;
	pSound->count = &sound_count;
	pSound->size = &sound_size;
	pSound->sync_sema = sync_sema;
	*pSound->size = buf_num;
	return 0;
}

SceInt32 soundbuf_init(t_soundBuffer *pSound)
{
	soundframe_count = 0;
	soundframe_delay = 0;
	*pSound->terminate_flag = 0;
	*pSound->write = 0;
	*pSound->read = 0;
	*pSound->count = 0;
	return 0;
}

SceInt32 soundbuf_end(t_soundBuffer *pSound)
{
	sceWaveExit();
	sceKernelDeleteSema(pSound->lock_sema);
	if (_fplid_7400[0]) {
		sceKernelDeleteFpl(_fplid_7400[0]);
		_fplid_7400[0] = 0;
	}
	if (_fplid_7400[1]) {
		sceKernelDeleteFpl(_fplid_7400[1]);
		_fplid_7400[1] = 0;
	}
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

SceInt32 soundbuf_func(SceSize size, void *argp)
{
	SceInt32 cnt;
	t_soundBuffer *pSound;
	char msg1[112];
	char msg2[112];

	cnt = 0;
	pSound = (t_soundBuffer *)argp;
	sceKernelWaitSema(pSound->sync_sema, 1, NULL);
	while (!soundbuf_isEnd(pSound)) {
		if (soundbuf_getCurrentCount(pSound) > 0) {
			soundbuf_output(pSound);
			if (cnt <= 0) {
				cnt++;
			} else {
				sceKernelWaitSema(pSound->lock_sema, 1, NULL);
				(*pSound->count)--;
				sceKernelSignalSema(pSound->lock_sema, 1);
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
	sprintf(msg1, "sound count = %d\n", soundframe_count);
	sceIoWrite(0, msg1, strlen(msg1));
	sprintf(msg2, "sound delay = %d\n", soundframe_delay);
	sceIoWrite(0, msg2, strlen(msg2));
	sceKernelExitThread(0);
	return 0;
}

SceInt32 soundbuf_output(t_soundBuffer *pSound)
{
	SceChar8 *buffer;

	buffer = pSound->buf[*pSound->read];
	sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, buffer);
	*pSound->read = (*pSound->read + 1) % *pSound->size;
	return 0;
}
