#include "common.h"

/* declarations recovered from DWARF */
struct t_mpegStreamData;
struct SceMpegStream;
typedef unsigned int SceUInt32;
typedef SceUInt32 SceMpegStreamId;
typedef void SceVoid;
typedef unsigned char SceUChar8;
typedef int SceInt32;
typedef short int SceShort16;
typedef char SceChar8;
struct SceMpegStream { /* size 0x40 */
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
};
typedef struct SceMpegStream SceMpegStream;
struct SceMpegAu;
struct SceMpegTimeStamp;
struct SceMpegTimeStamp { /* size 0x8 */
    SceUInt32 MSB_ts;
    SceUInt32 ts;
};
typedef struct SceMpegTimeStamp SceMpegTimeStamp;
struct SceMpegAu { /* size 0x18 */
    SceMpegTimeStamp pts;
    SceMpegTimeStamp dts;
    SceUChar8 *pEsBuf;
    SceInt32 iEsSize;
};
typedef struct SceMpegAu SceMpegAu;
struct t_mpegStreamData { /* size 0x10 */
    SceMpegStream *pAvcStream;
    SceMpegAu *pAvcAu;
    SceMpegStream *pAtracStream;
    SceMpegAu *pAtracAu;
};
typedef struct t_mpegStreamData t_mpegStreamData;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
};
typedef struct SceMpeg SceMpeg;
struct t_avSyncControl;
struct t_displayBuffer;
typedef int SceUID;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x4 */
    SceUID control_flag;
};
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_displayBuffer { /* size 0x28 */
    SceUID lockSema;
    SceUID delayFlag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
    t_conditionCtrl *pCtrl;
};
typedef struct t_displayBuffer t_displayBuffer;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x28 */
    SceUID lockSema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 bufSize;
    t_conditionCtrl *pCtrl;
    SceUInt32 soundLatestPts;
};
typedef struct t_soundBuffer t_soundBuffer;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};
typedef struct t_avSyncControl t_avSyncControl;

extern SceChar8 *dispbuf[2];

SceInt32 decode_setStreamData(t_mpegStreamData *pStreamData, SceMpegStream *pStreamV, SceMpegAu *pAvcAu, SceMpegStream *pStreamA, SceMpegAu *pAtracAu);
SceInt32 decode_audioDecode(SceMpeg *pMpeg, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 audio_init_flag);
SceInt32 decode_videoDecode(SceMpeg *pMpeg, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_videoDecodeEnd(SceMpeg *pMpeg, t_avSyncControl *pAvSync);

/* SDK functions */
int printf(const char *fmt, ...);

SceInt32 decode_setStreamData(t_mpegStreamData *pStreamData, SceMpegStream *pStreamV, SceMpegAu *pAvcAu, SceMpegStream *pStreamA, SceMpegAu *pAtracAu)
{
	pStreamData->pAvcStream = pStreamV;
	pStreamData->pAtracStream = pStreamA;
	pStreamData->pAvcAu = pAvcAu;
	pStreamData->pAtracAu = pAtracAu;
	return 0;
}

SceInt32 decode_audioDecode(SceMpeg *pMpeg, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 audio_init_flag)
{
	SceInt32 ret;
	SceVoid *atracBody;
	SceChar8 *pSoundBuf;

	if (soundbuf_getCapacity(pAvSync->pSound) == 0) {
		ret = 1;
		goto term;
	}

	ret = sceMpegGetAtracAu(pMpeg, pStreamData->pAtracStream, pStreamData->pAtracAu, &atracBody);
	if (ret != 0) {
		goto term;
	}

	soundbuf_getDrawbuf(pAvSync->pSound, &pSoundBuf);

	ret = sceMpegAtracDecode(pMpeg, pStreamData->pAtracAu, pSoundBuf, audio_init_flag);
	if (ret != 0) {
		printf("fatal error : sceMpegAtracDecode() 0x%x\n", ret);
		goto term;
	}

	soundbuf_setPts(pAvSync->pSound, pStreamData->pAtracAu->pts.ts);

	if (audio_init_flag == 0) {
		soundbuf_setBuf(pAvSync->pSound);
	}

term:
	return ret;
}

SceInt32 decode_videoDecode(SceMpeg *pMpeg, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync)
{
	SceChar8 *pVideoBuf;
	SceUInt32 pts;
	SceInt32 rgbNum;
	SceInt32 ret;
	SceInt32 avcAttr;

	ret = 1;
	if (dispbuf_getCapacity(pAvSync->pDisp) == 0)
		goto END;
	ret = sceMpegGetAvcAu(pMpeg, pStreamData->pAvcStream, pStreamData->pAvcAu, &avcAttr);
	if (ret != 0)
		goto END;
	dispbuf_getDrawbuf(pAvSync->pDisp, &pVideoBuf);
	dispbuf[0] = pVideoBuf;
	ret = sceMpegAvcDecode(pMpeg, pStreamData->pAvcAu, 512, dispbuf, &rgbNum);
	if (ret != 0) {
		printf("fatal error : sceMpegAvcDecode() 0x%x\n", ret);
		goto END;
	}
	avsync_video_setPts(pAvSync, pStreamData->pAvcAu->pts.ts);
	if (rgbNum == 1) {
		avsync_video_getPts(pAvSync, &pts);
		dispbuf_setPts(pAvSync->pDisp, pts);
		dispbuf_dataSet(pAvSync->pDisp);
	}
END:
	return ret;
}

SceInt32 decode_videoDecodeEnd(SceMpeg *pMpeg, t_avSyncControl *pAvSync)
{
	SceChar8 *pVideoBuf;
	SceUInt32 pts;
	SceInt32 rgbNum;
	SceInt32 ret;

	ret = 1;
	if (dispbuf_getCapacity(pAvSync->pDisp) == 0)
		goto END;
	dispbuf_getDrawbuf(pAvSync->pDisp, &pVideoBuf);
	dispbuf[0] = pVideoBuf;
	ret = sceMpegAvcDecodeStop(pMpeg, 512, dispbuf, &rgbNum);
	if (ret != 0) {
		printf("fatal error : sceMpegGetAvcDecodeStop() 0x%x\n", ret);
		goto END;
	}
	if (rgbNum > 0) {
		avsync_video_getPts(pAvSync, &pts);
		dispbuf_setPts(pAvSync->pDisp, pts);
		dispbuf_dataSet(pAvSync->pDisp);
	}
END:
	return ret;
}
