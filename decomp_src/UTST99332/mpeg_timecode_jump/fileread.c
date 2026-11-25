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


INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/fileread", read_create);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/fileread", read_reset);

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

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/fileread", read_isEnd);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/fileread", read_isFull);

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

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/fileread", read_checkConditionEnd);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/fileread", read_func);
