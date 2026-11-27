#include "common.h"

/* declarations recovered from DWARF */
typedef struct t_ringBuffer t_ringBuffer;
struct t_ringBuffer;
typedef int SceInt32;
typedef int SceUID;
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct SceMpegRingbuffer;
typedef void SceVoid;
typedef SceInt32 (*SceMpegRBCallback)(SceVoid *, SceInt32, SceVoid *);
struct SceMpegRingbuffer { /* size 0x2c */
    SceInt32 m_iBufsize;
    SceInt32 m_iRpos;
    SceInt32 m_iWpos;
    SceInt32 m_iInlen;
    SceInt32 m_iTypeSize;
    SceVoid *m_pBuf;
    SceMpegRBCallback callback;
    SceVoid *m_CallbackData;
    SceVoid *pPack;
    SceInt32 iSemaRB;
    SceVoid *mp;
};
struct t_ringBuffer { /* size 0x10 */
    SceInt32 data_len;
    SceUID ringbuf_sema;
    SceMpegRingbuffer *pRingbuf;
    SceInt32 *end_flag;
};
typedef unsigned int SceSize;

extern SceInt32 file_terminate_flag;

SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB);
SceInt32 read_init(t_ringBuffer *pRing, int fileSize);
SceInt32 read_end(t_ringBuffer *pRing);
SceInt32 read_decode_sleep(t_ringBuffer *pRing);
SceInt32 read_isEnd(t_ringBuffer *pRing);
SceInt32 read_isFull(t_ringBuffer *pRing);
SceInt32 read_setDemuxEnd(t_ringBuffer *pRing);
SceInt32 read_getCapacity(t_ringBuffer *pRing);
SceInt32 read_func(SceSize size, void *argp);


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

int sceKernelDeleteSema(int semid);
SceInt32 read_end(t_ringBuffer *pRing)
{
	sceKernelDeleteSema(pRing->ringbuf_sema);
	return 0;
}

int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
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

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/fileread", read_func);
