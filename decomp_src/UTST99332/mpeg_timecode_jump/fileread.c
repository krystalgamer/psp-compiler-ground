#include "common.h"

/* declarations recovered from DWARF */
struct t_ringBuffer;
typedef int SceInt32;
typedef int SceUID;
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
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x4 */
    SceUID control_flag;
};
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_ringBuffer { /* size 0x14 */
    SceInt32 dataLen;
    SceUID ringbufSema;
    SceInt32 statusFlag;
    SceMpegRingbuffer *pRingbuf;
    t_conditionCtrl *pCtrl;
};
typedef struct t_ringBuffer t_ringBuffer;
typedef unsigned int SceUInt32;
typedef unsigned int SceSize;



SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB, t_conditionCtrl *pCtrl);
SceInt32 read_reset(t_ringBuffer *pRing, SceInt32 fileSize);
SceInt32 read_isEnd(t_ringBuffer *pRing);
SceInt32 read_isFull(t_ringBuffer *pRing);
SceInt32 read_checkConditionEnd(t_ringBuffer *pRing);
SceInt32 read_func(SceSize size, SceVoid *argp);

/* SDK functions (tools/sdk_protos.h) */
int sceKernelDeleteSema(int semid);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);


int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
/* SDK prototypes (tools/sdk_protos.h) */
int printf(const char *fmt, ...);
int sceKernelDelayThread(unsigned int delay);
int sceKernelSignalSema(int semid, int signal);

SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB, t_conditionCtrl *pCtrl)
{
	pRing->pRingbuf = pRB;
	pRing->ringbufSema = sceKernelCreateSema("decode_sleep_sema", 0, 0, 1, NULL);
	pRing->pCtrl = pCtrl;
	return 0;
}

SceInt32 read_reset(t_ringBuffer *pRing, SceInt32 fileSize)
{
	pRing->statusFlag = 1;
	pRing->dataLen = fileSize;
	return 0;
}

int read_delete(t_ringBuffer *pRing) {
    sceKernelDeleteSema(pRing->ringbufSema);
    return 0;
}

int read_getStatus(t_ringBuffer *pRing) {
    return pRing->statusFlag;
}

int read_setStatus(t_ringBuffer *pRing, int status) {
    pRing->statusFlag = status;
    return 0;
}

int read_decode_sleep(t_ringBuffer *pRing) {
    return sceKernelWaitSema(pRing->ringbufSema, 1, NULL);
}

SceInt32 read_isEnd(t_ringBuffer *pRing)
{
	SceUInt32 pattern;

	control_getCondition(pRing->pCtrl, &pattern);
	return (pattern & 0x4) ? 1 : 0;
}

SceInt32 read_isFull(t_ringBuffer *pRing)
{
	SceUInt32 pattern;
	SceInt32 ret;

	control_getCondition(pRing->pCtrl, &pattern);
	if (read_isEnd(pRing) == 1)
		ret = 1;
	else if (read_getCapacity(pRing) == 0)
		ret = 1;
	else
		ret = 0;
	return ret;
}

int read_getCapacity(t_ringBuffer *pRing) {
    return sceMpegRingbufferAvailableSize(pRing->pRingbuf);
}

int read_sendErrCondition(t_ringBuffer *pRing) {
    control_setCondition(pRing->pCtrl, 0xC00);
    return 0;
}

int read_sendEndCondition(t_ringBuffer *pRing) {
    control_setCondition(pRing->pCtrl, 4);
    return 0;
}

SceInt32 read_checkConditionEnd(t_ringBuffer *pRing)
{
	SceUInt32 pattern;

	control_getCondition(pRing->pCtrl, &pattern);
	if ((pattern & 0xff) == 0xff)
		read_setStatus(pRing, 4);
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/fileread", read_func);
