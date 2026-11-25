#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <thread.h>
#include <libmpeg.h>
#include <stdio.h>
#include "fileread.h"

extern SceInt32 file_status_flag;

SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB)
{
	pRing->pRingbuf = pRB;
	pRing->status_flag = &file_status_flag;
	pRing->ringbuf_sema = sceKernelCreateSema("decode_sleep_sema", 0, 0, 1, NULL);
	return 0;
}

SceInt32 read_init(t_ringBuffer *pRing, int fileSize)
{
	*pRing->status_flag = 0;
	pRing->data_len = fileSize;
	return 0;
}

SceInt32 read_getStatus(t_ringBuffer *pRing)
{
	return *pRing->status_flag;
}

SceInt32 read_setStatus(t_ringBuffer *pRing, int status)
{
	*pRing->status_flag = status;
	return 0;
}

SceInt32 read_end(t_ringBuffer *pRing)
{
	sceKernelDeleteSema(pRing->ringbuf_sema);
	return 0;
}

SceInt32 read_decode_sleep(t_ringBuffer *pRing)
{
	return sceKernelWaitSema(pRing->ringbuf_sema, 1, NULL);
}

SceInt32 read_isEnd(t_ringBuffer *pRing)
{
	return *pRing->status_flag == 2;
}

SceInt32 read_isFull(t_ringBuffer *pRing)
{
	SceInt32 ret = 0;

	if (*pRing->status_flag == 2 || read_getCapacity(pRing) == 0)
		ret = 1;
	return ret;
}

SceInt32 read_setDemuxEnd(t_ringBuffer *pRing)
{
	*pRing->status_flag = 0xff;
	return 0;
}

SceInt32 read_getCapacity(t_ringBuffer *pRing)
{
	return sceMpegRingbufferAvailableSize(pRing->pRingbuf);
}

SceInt32 read_func(SceSize size, void *argp)
{
	t_ringBuffer *pRing = argp;
	SceInt32 readSize = 0;

	while (*pRing->status_flag != 0xff) {
		SceInt32 ret = 0;
		SceInt32 avail = sceMpegRingbufferAvailableSize(pRing->pRingbuf);

		if (*pRing->status_flag == 0 && avail > 0) {
			SceInt32 num = 32;

			if (avail < 32) {
				num = avail;
				if (pRing->data_len - readSize < num)
					num = pRing->data_len - readSize;
			}
			ret = sceMpegRingbufferPut(pRing->pRingbuf, num, avail);
			if (ret < 0) {
				printf("fatal error: sceMpegRingbufferPut 0x%x total = %d\n", ret, readSize);
				ret = 0;
				*pRing->status_flag = 1;
			}
		}
		readSize += ret * 2048;
		sceKernelSignalSema(pRing->ringbuf_sema, 1);
		if (readSize == pRing->data_len && *pRing->status_flag == 0)
			*pRing->status_flag = 2;
	}
	sceKernelExitThread(0);
	return 0;
}
