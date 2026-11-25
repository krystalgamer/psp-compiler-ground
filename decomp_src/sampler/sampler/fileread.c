#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <thread.h>
#include <libmpeg.h>
#include <stdio.h>
#include "fileread.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

extern SceInt32 file_terminate_flag;

SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB)
{
	pRing->pRingbuf = pRB;
	pRing->end_flag = &file_terminate_flag;
	pRing->ringbuf_sema = sceKernelCreateSema("decode_sleep_sema", 0, 0, 1, NULL);
	return 0;
}

SceInt32 read_init(t_ringBuffer *pRing, int fileSize)
{
	*pRing->end_flag = 0;
	pRing->data_len = fileSize;
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
	return *pRing->end_flag;
}

SceInt32 read_isFull(t_ringBuffer *pRing)
{
	SceInt32 ret = 0;

	if (*pRing->end_flag == 1 || read_getCapacity(pRing) == 0)
		ret = 1;
	return ret;
}

SceInt32 read_setDemuxEnd(t_ringBuffer *pRing)
{
	*pRing->end_flag = 2;
	return 0;
}

SceInt32 read_getCapacity(t_ringBuffer *pRing)
{
	return sceMpegRingbufferAvailableSize(pRing->pRingbuf);
}

#ifdef NON_MATCHING
/* only the data_len - readSize subtraction is scheduled after the branch */
SceInt32 read_func(SceSize size, void *argp)
{
	t_ringBuffer *pRing;
	SceInt32 readSize;

	pRing = argp;
	readSize = 0;
	while (read_isEnd(pRing) != 2) {
		SceInt32 iReadSize;
		SceInt32 iCapacitySize;
		SceInt32 getSize;

		iCapacitySize = sceMpegRingbufferAvailableSize(pRing->pRingbuf);
		if (iCapacitySize > 0 && readSize < pRing->data_len) {
				iReadSize = 32;
				if (iCapacitySize < 32)
					iReadSize = MIN(iCapacitySize, pRing->data_len - readSize);
				getSize = sceMpegRingbufferPut(pRing->pRingbuf, iReadSize, iCapacitySize);
				if (getSize < 0) {
					printf("error error error\n %d total = %d\n", getSize, readSize);
					*pRing->end_flag = 3;
					sceKernelSignalSema(pRing->ringbuf_sema, 1);
					break;
				}
		} else
			getSize = 0;
		readSize += getSize * 2048;
		sceKernelSignalSema(pRing->ringbuf_sema, 1);
		if (readSize >= pRing->data_len && *pRing->end_flag == 0)
			*pRing->end_flag = 1;
	}
	sceKernelExitThread(0);
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/fileread", read_func);
#endif
