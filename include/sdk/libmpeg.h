#ifndef _LIBMPEG_H
#define _LIBMPEG_H
/* types recovered from DWARF; prototypes as used by the decompiled code */
#include <psptypes.h>
#include <kerneltypes.h>
typedef SceInt32 (*SceMpegRBCallback)(SceVoid *pData, SceInt32 iNum, SceVoid *pParam);
typedef struct SceMpegRingbuffer {
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
} SceMpegRingbuffer;
typedef struct SceMpeg {
	SceVoid *sys;
} SceMpeg;
typedef SceUInt32 SceMpegStreamId;
typedef struct SceMpegStream {
	SceMpegStreamId qStreamId;
	SceMpegStreamId qStreamIdMask;
	SceVoid *m_pRAPICtrlStream;
	SceUChar8 *m_pRAPI;
	SceInt32 m_iAuNum;
	SceInt32 m_iPesPacketForwardSize;
	SceInt32 m_iPesPacketForwardFlag;
	SceShort16 m_iPesPacketAULocator;
	SceShort16 reserved;
	SceInt32 m_iPesPacketNum;
	SceInt32 m_iAuSize;
	SceInt32 m_iBoundarySize;
	SceInt32 m_iAuSizeOfProceed;
	SceUInt32 m_iGetAuMode;
	SceInt32 m_iPayloadHeaderRemainderFlag;
	SceInt32 m_iPayloadHeaderRemainderSize;
	SceChar8 m_cPayloadHeaderBuf[4];
} SceMpegStream;
typedef struct SceMpegTimeStamp {
	SceUInt32 MSB_ts;
	SceUInt32 ts;
} SceMpegTimeStamp;
typedef struct SceMpegAu {
	SceMpegTimeStamp pts;
	SceMpegTimeStamp dts;
	SceUChar8 *pEsBuf;
	SceInt32 iEsSize;
} SceMpegAu;
typedef struct {
	SceInt32 iDecodeMode;
	SceInt32 iPixelFormat;
} SceMpegAvcMode;
typedef SceUChar8 *SceMpegHandle;
SceInt32 sceMpegInit(void);
SceInt32 sceMpegFinish(void);
SceInt32 sceMpegRingbufferQueryMemSize(SceInt32 iPackNum);
SceInt32 sceMpegRingbufferConstruct(SceMpegRingbuffer *pRingbuffer, SceInt32 iPackNum, SceVoid *pBuf, SceInt32 iSize, SceMpegRBCallback Callback, SceVoid *pCallbackData);
SceInt32 sceMpegRingbufferDestruct(SceMpegRingbuffer *pRingbuffer);
SceInt32 sceMpegQueryMemSize(SceInt32 iReserved);
SceInt32 sceMpegCreate(SceMpeg *pMpeg, SceVoid *pData, SceInt32 iSize, SceMpegRingbuffer *pRingbuffer, SceInt32 iFrameWidth, SceInt32 iReserved1, SceInt32 iReserved2);
SceInt32 sceMpegDelete(SceMpeg *pMpeg);
SceInt32 sceMpegAvcDecodeMode(SceMpeg *pMpeg, SceMpegAvcMode *pMode);
SceInt32 sceMpegFlushAllStream(SceMpeg *pMpeg);
SceMpegStream *sceMpegRegistStream(SceMpeg *pMpeg, SceInt32 iStreamID, SceInt32 iUnk);
SceMpegHandle sceMpegMallocAvcEsBuf(SceMpeg *pMpeg);
SceInt32 sceMpegInitAu(SceMpeg *pMpeg, SceMpegHandle hEsBuf, SceMpegAu *pAu);
SceInt32 sceMpegQueryAtracEsSize(SceMpeg *pMpeg, SceInt32 *iEsSize, SceInt32 *iOutSize);
SceInt32 sceMpegFreeAvcEsBuf(SceMpeg *pMpeg, SceMpegHandle hEsBuf);
SceInt32 sceMpegUnRegistStream(SceMpeg *pMpeg, SceMpegStream *pStream);
SceInt32 sceMpegQueryStreamOffset(SceMpeg *pMpeg, SceVoid *pBuffer, SceInt32 *iOffset);
SceInt32 sceMpegQueryStreamSize(SceVoid *pBuffer, SceInt32 *iSize);
SceInt32 sceMpegRingbufferAvailableSize(SceMpegRingbuffer *pRingbuffer);
SceInt32 sceMpegRingbufferPut(SceMpegRingbuffer *pRingbuffer, SceInt32 iNumPackets, SceInt32 iAvailable);
#endif
