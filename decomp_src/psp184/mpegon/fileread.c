#include "common.h"

/* declarations recovered from DWARF */
typedef struct t_ringBuffer t_ringBuffer;
struct t_ringBuffer;
typedef int SceInt32;
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct SceMpegRingbuffer;
typedef SceInt32 (*SceMpegRBCallback)(void *, SceInt32, void *);
struct SceMpegRingbuffer { /* size 0x2c */
    SceInt32 m_iBufsize;
    SceInt32 m_iRpos;
    SceInt32 m_iWpos;
    SceInt32 m_iInlen;
    SceInt32 m_iTypeSize;
    void *m_pBuf;
    SceMpegRBCallback callback;
    void *m_CallbackData;
    void *pPack;
    SceInt32 iSemaRB;
    void *mp;
};
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
typedef int SceUID;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
struct t_ringBuffer { /* size 0x10 */
    SceInt32 dataLen;
    SceInt32 statusFlag;
    SceMpegRingbuffer *pRingbuf;
    t_conditionCtrl *pCtrl;
};
typedef unsigned int SceUInt32;
typedef unsigned int SceSize;



SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB, t_conditionCtrl *pCtrl);
SceInt32 read_reset(t_ringBuffer *pRing, SceInt32 fileSize);
SceInt32 read_isEnd(t_ringBuffer *pRing);
SceInt32 read_isFull(t_ringBuffer *pRing);
SceInt32 read_checkConditionEnd(t_ringBuffer *pRing);
int read_func(SceSize size, void *argp);


SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB, t_conditionCtrl *pCtrl)
{
	pRing->pRingbuf = pRB;
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
    return 0;
}

int read_getStatus(t_ringBuffer *pRing) {
    return pRing->statusFlag;
}

int read_setStatus(t_ringBuffer *pRing, int status) {
    pRing->statusFlag = status;
    return 0;
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
	if ((pattern & 0xFF) == 0xFF)
		read_setStatus(pRing, 3);
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/fileread", read_func);
