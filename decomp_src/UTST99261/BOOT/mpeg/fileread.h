#ifndef FILEREAD_H
#define FILEREAD_H
/* types recovered from DWARF */
typedef struct t_ringBuffer {
	SceInt32 data_len;
	SceUID ringbuf_sema;
	SceMpegRingbuffer *pRingbuf;
	SceInt32 *status_flag;
} t_ringBuffer;

SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB);
SceInt32 read_init(t_ringBuffer *pRing, int fileSize);
SceInt32 read_getStatus(t_ringBuffer *pRing);
SceInt32 read_setStatus(t_ringBuffer *pRing, int status);
SceInt32 read_end(t_ringBuffer *pRing);
SceInt32 read_decode_sleep(t_ringBuffer *pRing);
SceInt32 read_isEnd(t_ringBuffer *pRing);
SceInt32 read_isFull(t_ringBuffer *pRing);
SceInt32 read_setDemuxEnd(t_ringBuffer *pRing);
SceInt32 read_getCapacity(t_ringBuffer *pRing);
SceInt32 read_func(SceSize size, void *argp);
#endif
