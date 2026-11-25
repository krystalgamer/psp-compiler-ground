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
SceInt32 sceMpegRingbufferAvailableSize(SceMpegRingbuffer *pRingbuffer);
SceInt32 sceMpegRingbufferPut(SceMpegRingbuffer *pRingbuffer, SceInt32 iNumPackets, SceInt32 iAvailable);
#endif
