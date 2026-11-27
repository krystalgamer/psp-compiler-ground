#include "common.h"

/* declarations recovered from DWARF */
struct t_mpegStreamData;
struct SceMpeg;
typedef void SceVoid;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
};
typedef struct SceMpeg SceMpeg;
struct SceMpegStream;
typedef unsigned int SceUInt32;
typedef SceUInt32 SceMpegStreamId;
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
typedef SceUChar8 *SceMpegHandle;
struct t_mpegStreamData { /* size 0x428 */
    SceMpeg *pMpeg;
    SceMpegStream *pVideoStream[16];
    SceMpegStream *pAudioStream[16];
    SceInt32 currentVideoStream;
    SceInt32 reservedVideoStream;
    SceInt32 currentAudioStream;
    SceInt32 videoStreamNum;
    SceInt32 audioStreamNum;
    SceMpegAu pAvcAu[16];
    SceMpegAu pAudioAu[16];
    SceMpegHandle avcEsBuf1;
    SceMpegHandle avcEsBuf2;
    SceChar8 *pAudioEsBuf;
    SceInt32 videoDemuxFlag[16];
    SceInt32 audioDemuxFlag[16];
    SceInt32 audioOutSize;
};
typedef struct t_mpegStreamData t_mpegStreamData;
typedef SceInt32 SceMpegStrType;
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

SceInt32 decode_create(t_mpegStreamData *pStreamData, SceMpeg *pMpeg);
SceInt32 decode_reset(t_mpegStreamData *pStreamData, SceInt32 videoStreamNumber, SceInt32 audioStreamNumber);
SceInt32 decode_delete(t_mpegStreamData *pStreamData);
SceInt32 decode_changeAuMode(t_mpegStreamData *pStreamData, SceMpegStrType type, SceInt32 number, SceInt32 flag);
SceInt32 decode_initAu(t_mpegStreamData *pStreamData, SceMpegStrType type, SceInt32 number, SceInt32 flag);
SceInt32 decode_createAu(t_mpegStreamData *pStreamData, SceMpegStrType type);
SceInt32 decode_createAvcAu(t_mpegStreamData *pStreamData);
SceInt32 decode_createAudioAu(t_mpegStreamData *pStreamData);
SceInt32 decode_deleteAu(t_mpegStreamData *pStreamData, SceMpegStrType type);
SceInt32 decode_setRegistStream(t_mpegStreamData *pStreamData, SceMpegStrType streamType, SceInt32 ch);
SceInt32 decode_unRegistStream(t_mpegStreamData *pStreamData, SceMpegStrType streamType);
SceInt32 decode_setReservedMode(t_mpegStreamData *pStreamData, SceMpegStrType type, SceInt32 number);
SceInt32 decode_getAudioAu(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_audioDecode(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 audio_init_flag);
SceInt32 decode_getVideoAu(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_videoDecode(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_reservedVideoDecode(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_videoDecodeEnd(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_checkReservedVideoGetAu(t_mpegStreamData *pStreamData);
SceInt32 decode_getReservedVideoAuTimestamp(t_mpegStreamData *pStreamData, SceUInt32 *pTimestamp);
SceInt32 decode_getCurrentStream(t_mpegStreamData *pStreamData, SceMpegStrType type);


/* SDK prototypes (tools/sdk_protos.h) */
int puts(const char *s);

SceInt32 decode_create(t_mpegStreamData *pStreamData, SceMpeg *pMpeg)
{
	SceInt32 i;
	SceInt32 ret;

	pStreamData->pMpeg = pMpeg;

	pStreamData->audioStreamNum = 0;
	pStreamData->videoStreamNum = 0;

	pStreamData->currentVideoStream = -1;
	pStreamData->reservedVideoStream = -1;
	pStreamData->currentAudioStream = -1;

	for (i = 0; i < 16; i++) {
		pStreamData->videoDemuxFlag[i] = 0;
		pStreamData->audioDemuxFlag[i] = 0;
	}

	ret = decode_createAu(pStreamData, 0);
	if (ret != 0) {
		printf("fatal error : decode_createAu() M4AVC 0x%x\n", ret);
		goto term;
	}

	ret = decode_createAu(pStreamData, 1);
	if (ret != 0) {
		printf("fatal error : decode_createAu() ATRAC 0x%x\n", ret);
		goto term;
	}

term:
	return ret;
}

SceInt32 decode_reset(t_mpegStreamData *pStreamData, SceInt32 videoStreamNumber, SceInt32 audioStreamNumber)
{
	SceInt32 i;
	SceInt32 flag;
	SceInt32 ret;

	pStreamData->currentVideoStream = videoStreamNumber;
	pStreamData->currentAudioStream = audioStreamNumber;
	pStreamData->reservedVideoStream = -1;

	for (i = 0; i < pStreamData->videoStreamNum; i++) {
		ret = decode_initAu(pStreamData, 0, i, 0);
		if (ret != 0) {
			goto term;
		}
	}

	for (i = 0; i < pStreamData->videoStreamNum; i++) {
		if (i == pStreamData->currentVideoStream) {
			flag = 1;
		} else {
			flag = 0;
		}

		ret = decode_changeAuMode(pStreamData, 0, i, flag);
		if (ret != 0) {
			goto term;
		}
	}

	for (i = 0; i < pStreamData->audioStreamNum; i++) {
		ret = decode_initAu(pStreamData, 1, i, 0);
		if (ret != 0) {
			goto term;
		}
	}

	for (i = 0; i < pStreamData->audioStreamNum; i++) {
		if (i == pStreamData->currentAudioStream) {
			flag = 1;
		} else {
			flag = 0;
		}

		ret = decode_changeAuMode(pStreamData, 1, i, flag);
		if (ret != 0) {
			goto term;
		}
	}

	ret = 0;

term:
	return ret;
}

SceInt32 decode_delete(t_mpegStreamData *pStreamData)
{
	SceInt32 ret;

	ret = decode_deleteAu(pStreamData, 0);
	if (ret != 0) {
		printf("fatal error : decode_deleteAu() M4AVC 0x%x\n", ret);
	}

	ret = decode_deleteAu(pStreamData, 1);
	if (ret != 0) {
		printf("fatal error : decode_deleteAu() ATRAC 0x%x\n", ret);
	}

	return ret;
}

SceInt32 decode_changeAuMode(t_mpegStreamData *pStreamData, SceMpegStrType type, SceInt32 number, SceInt32 flag)
{
	SceInt32 ret;

	switch (type) {
	case 0:
		if (flag == 1) {
			ret = sceMpegChangeGetAuMode(pStreamData->pMpeg, pStreamData->pVideoStream[number], 0);
			if (ret != 0) {
				goto term;
			}
		} else {
			ret = sceMpegChangeGetAuMode(pStreamData->pMpeg, pStreamData->pVideoStream[number], 1);
			if (ret != 0) {
				goto term;
			}
		}
		break;
	case 1:
		if (flag == 1) {
			ret = sceMpegChangeGetAuMode(pStreamData->pMpeg, pStreamData->pAudioStream[number], 0);
			if (ret != 0) {
				goto term;
			}
		} else {
			ret = sceMpegChangeGetAuMode(pStreamData->pMpeg, pStreamData->pAudioStream[number], 1);
			if (ret != 0) {
				goto term;
			}
		}
		break;
	default:
		ret = 0;
		goto term;
	}

	ret = 0;

term:
	return ret;
}

SceInt32 decode_initAu(t_mpegStreamData *pStreamData, SceMpegStrType type, SceInt32 number, SceInt32 flag)
{
	SceInt32 ret;

	switch (type) {
	case 0:
		if (flag == 0) {
			ret = sceMpegInitAu(pStreamData->pMpeg, pStreamData->avcEsBuf1, &pStreamData->pAvcAu[number]);
		} else {
			ret = sceMpegInitAu(pStreamData->pMpeg, pStreamData->avcEsBuf2, &pStreamData->pAvcAu[number]);
		}

		if (ret != 0) {
			printf("fatal error : sceMpegInitAu() AVC 0x%x\n", ret);
			goto term;
		}
		break;
	case 1:
		ret = sceMpegInitAu(pStreamData->pMpeg, pStreamData->pAudioEsBuf, &pStreamData->pAudioAu[number]);
		if (ret != 0) {
			printf("fatal error : sceMpegInitAu() 0x%x\n", ret);
			goto term;
		}
		break;
	default:
		ret = -1;
		goto term;
	}

	ret = 0;

term:
	return ret;
}

SceInt32 decode_createAu(t_mpegStreamData *pStreamData, SceMpegStrType type)
{
	SceInt32 ret;

	switch (type) {
	case 0:
		ret = decode_createAvcAu(pStreamData);
		break;
	case 1:
		ret = decode_createAudioAu(pStreamData);
		break;
	default:
		ret = -1;
		break;
	}

	return ret;
}

SceInt32 decode_createAvcAu(t_mpegStreamData *pStreamData)
{
	SceInt32 ret;

	ret = -1;
	pStreamData->avcEsBuf1 = sceMpegMallocAvcEsBuf(pStreamData->pMpeg);
	if (pStreamData->avcEsBuf1 == 0) {
		printf("fatal error : sceMpegMallocAvcEsBuf()\n");
		goto error;
	}

	ret = 0;
	pStreamData->avcEsBuf2 = sceMpegMallocAvcEsBuf(pStreamData->pMpeg);
	if (pStreamData->avcEsBuf2 == 0) {
		printf("fatal error : sceMpegMallocAvcEsBuf()\n");
		ret = -1;
		goto error;
	}

	goto term;

error:
	if (pStreamData->avcEsBuf1) {
		sceMpegFreeAvcEsBuf(pStreamData->pMpeg, pStreamData->avcEsBuf1);
		pStreamData->avcEsBuf1 = 0;
	}

	if (pStreamData->avcEsBuf2) {
		sceMpegFreeAvcEsBuf(pStreamData->pMpeg, pStreamData->avcEsBuf2);
		pStreamData->avcEsBuf2 = 0;
	}

term:
	return ret;
}

SceInt32 decode_createAudioAu(t_mpegStreamData *pStreamData)
{
	SceInt32 ret;
	SceInt32 audioEsSize, audioOutSize;

	ret = sceMpegQueryAtracEsSize(pStreamData->pMpeg, &audioEsSize, &audioOutSize);
	if (ret != 0) {
		printf("fatal error : sceQueryAtracEsSize() 0x%x\n", ret);
		goto term;
	}

	pStreamData->audioOutSize = audioOutSize;

	pStreamData->pAudioEsBuf = memalign(64, audioEsSize);
	if (pStreamData->pAudioEsBuf == NULL) {
		printf("fatal error : memalign audioEsSize\n");
		ret = -1;
		goto error;
	}

	goto term;

error:
	if (pStreamData->pAudioEsBuf) {
		free(pStreamData->pAudioEsBuf);
		pStreamData->pAudioEsBuf = NULL;
	}

term:
	return ret;
}

SceInt32 decode_deleteAu(t_mpegStreamData *pStreamData, SceMpegStrType type)
{
	SceInt32 ret;

	switch (type) {
	case 0:
		if (pStreamData->avcEsBuf1) {
			sceMpegFreeAvcEsBuf(pStreamData->pMpeg, pStreamData->avcEsBuf1);
			pStreamData->avcEsBuf1 = 0;
		}
		if (pStreamData->avcEsBuf2) {
			sceMpegFreeAvcEsBuf(pStreamData->pMpeg, pStreamData->avcEsBuf2);
			pStreamData->avcEsBuf2 = 0;
		}
		break;
	case 1:
		if (pStreamData->pAudioEsBuf) {
			free(pStreamData->pAudioEsBuf);
			pStreamData->pAudioEsBuf = NULL;
		}
		break;
	}

	return 0;
}

int decode_getAudioOutSize(t_mpegStreamData *pStreamData) {
    return pStreamData->audioOutSize;
}

SceInt32 decode_setRegistStream(t_mpegStreamData *pStreamData, SceMpegStrType streamType, SceInt32 ch)
{
	SceInt32 ret;
	SceMpegStream *pStream;

	ret = 0;

	switch (streamType) {
	case 0:
		if (pStreamData->videoStreamNum < 16) {
			pStream = sceMpegRegistStream(pStreamData->pMpeg, streamType, ch);
			if (pStream == NULL) {
				printf("fatal error : sceMpegRegistStream()\n");
				ret = -1;
				goto term;
			}

			pStreamData->pVideoStream[pStreamData->videoStreamNum] = pStream;

			pStreamData->videoStreamNum++;
		} else {
			return -1;
		}
		break;
	case 1:
		if (pStreamData->audioStreamNum < 16) {
			pStream = sceMpegRegistStream(pStreamData->pMpeg, streamType, ch);
			pStreamData->pAudioStream[pStreamData->audioStreamNum] = pStream;

			pStreamData->audioStreamNum++;
		} else {
			ret = -1;
		}
		break;
	}

term:
	return ret;
}

SceInt32 decode_unRegistStream(t_mpegStreamData *pStreamData, SceMpegStrType streamType)
{
	SceInt32 i;
	SceInt32 ret;

	ret = 0;

	switch (streamType) {
	case 0:
		for (i = 0; i < pStreamData->videoStreamNum; i++) {
			sceMpegUnRegistStream(pStreamData->pMpeg, pStreamData->pVideoStream[i]);
		}
		pStreamData->videoStreamNum = 0;
		break;
	case 1:
		for (i = 0; i < pStreamData->audioStreamNum; i++) {
			sceMpegUnRegistStream(pStreamData->pMpeg, pStreamData->pAudioStream[i]);
		}
		pStreamData->audioStreamNum = 0;
		break;
	default:
		ret = -1;
		break;
	}

	return ret;
}

SceInt32 decode_setReservedMode(t_mpegStreamData *pStreamData, SceMpegStrType type, SceInt32 number)
{
	SceInt32 ret;

	switch (type) {
	case 0:
		sceMpegChangeGetAuMode(pStreamData->pMpeg, pStreamData->pVideoStream[number], 0);

		pStreamData->reservedVideoStream = number;

		ret = decode_initAu(pStreamData, 0, number, 1);
		if (ret != 0) {
			printf("fatal error : decode_initAu () 0x%x\n", ret);
			goto term;
		}
		break;
	case 1:
		ret = -1;
		break;
	default:
		ret = -1;
		break;
	}

term:
	return ret;
}

SceInt32 decode_getAudioAu(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync)
{
	SceInt32 ret;
	SceInt32 i;
	SceVoid *atracBody;

	if (soundbuf_getCapacity(pAvSync->pSound) == 0) {
		ret = 1;
		goto term;
	}

	for (i = 0; i < pStreamData->audioStreamNum; i++) {
		ret = sceMpegGetAtracAu(pStreamData->pMpeg, pStreamData->pAudioStream[i], &pStreamData->pAudioAu[i], &atracBody);
		if (ret == 0) {
			pStreamData->audioDemuxFlag[i] = 1;
		} else if (ret == (SceInt32)0x80618001) {
			pStreamData->audioDemuxFlag[i] = 0;
		} else {
			goto term;
		}
	}

	ret = 0;

term:
	return ret;
}

SceInt32 decode_audioDecode(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 audio_init_flag)
{
	SceInt32 ret;
	SceChar8 *pSoundBuf;

	ret = 1;
	if (soundbuf_getCapacity(pAvSync->pSound) == 0) {
		goto term;
	}

	ret = 0x80618001;
	if (pStreamData->audioDemuxFlag[pStreamData->currentAudioStream] != 1) {
		goto term;
	}

	soundbuf_getDrawbuf(pAvSync->pSound, &pSoundBuf);

	ret = sceMpegAtracDecode(pStreamData->pMpeg, &pStreamData->pAudioAu[pStreamData->currentAudioStream], pSoundBuf, audio_init_flag);
	if (ret != 0) {
		printf("fatal error : sceMpegAtracDecode() 0x%x\n", ret);
		goto term;
	}

	soundbuf_setPts(pAvSync->pSound, pStreamData->pAudioAu[pStreamData->currentAudioStream].pts.ts);

	if (audio_init_flag == 0) {
		soundbuf_setBuf(pAvSync->pSound);
	}

term:
	return ret;
}

SceInt32 decode_getVideoAu(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync)
{
	SceInt32 ret;
	SceInt32 avcAttr;
	SceInt32 i;

	ret = 1;
	if (dispbuf_getCapacity(pAvSync->pDisp) == 0) {
		goto term;
	}

	for (i = 0; i < pStreamData->videoStreamNum; i++) {
		ret = sceMpegGetAvcAu(pStreamData->pMpeg, pStreamData->pVideoStream[i], &pStreamData->pAvcAu[i], &avcAttr);
		if (ret == 0) {
			pStreamData->videoDemuxFlag[i] = 1;
		} else if (ret == (SceInt32)0x80618001) {
			pStreamData->videoDemuxFlag[i] = 0;
		} else {
			printf("fatal error : sceMpegGetAvcAu() 0x%x\n", ret);
			goto term;
		}
	}

	ret = 0;

term:
	return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_videoDecode);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_reservedVideoDecode);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", D_00011C18);

SceInt32 decode_videoDecodeEnd(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync)
{
	SceChar8 *pVideoBuf;
	SceUInt32 pts;
	SceInt32 rgbNum;
	SceInt32 ret;

	ret = 1;
	if (dispbuf_getCapacity(pAvSync->pDisp) == 0) {
		goto term;
	}

	dispbuf_getDrawbuf(pAvSync->pDisp, &pVideoBuf);

	dispbuf[0] = pVideoBuf;

	ret = sceMpegAvcDecodeStop(pStreamData->pMpeg, 512, dispbuf, &rgbNum);
	if (ret != 0) {
		printf("fatal error : sceMpegGetAvcDecodeStop() 0x%x\n", ret);
		goto term;
	}

	if (rgbNum > 0) {
		avsync_video_getPts(pAvSync, &pts);
		dispbuf_setPts(pAvSync->pDisp, pts);
		dispbuf_dataSet(pAvSync->pDisp);
	}

term:
	return ret;
}

int decode_flushDecoder(t_mpegStreamData *pStreamData) {
    return sceMpegAvcDecodeFlush(pStreamData->pMpeg);
}

SceInt32 decode_checkReservedVideoGetAu(t_mpegStreamData *pStreamData)
{
	SceInt32 ret;

	if (pStreamData->videoDemuxFlag[pStreamData->reservedVideoStream] == 1) {
		ret = 0;
	} else {
		ret = -1;
	}

	return ret;
}

SceInt32 decode_getReservedVideoAuTimestamp(t_mpegStreamData *pStreamData, SceUInt32 *pTimestamp)
{
	SceInt32 ret;

	ret = decode_checkReservedVideoGetAu(pStreamData);
	if (ret != 0) {
		goto term;
	}

	*pTimestamp = pStreamData->pAvcAu[pStreamData->reservedVideoStream].pts.ts;

term:
	return ret;
}

int decode_getCurrentReservedStream(t_mpegStreamData *pStreamData) {
    return pStreamData->reservedVideoStream;
}

int decode_setReservedVideoStream(t_mpegStreamData *pStreamData, int streamNumber) {
    pStreamData->reservedVideoStream = streamNumber;
    return 0;
}

int decode_setCurrentStream(t_mpegStreamData *pStreamData, int type, int number) {
    int var_v1;

    var_v1 = 0;
    switch (type) {                                 /* irregular */
    case 1:
        pStreamData->currentAudioStream = number;
        break;
    default:
        var_v1 = -1;
        break;
    case 0:
        pStreamData->currentVideoStream = number;
        break;
    }
    return var_v1;
}

SceInt32 decode_getCurrentStream(t_mpegStreamData *pStreamData, SceMpegStrType type)
{
	SceInt32 ret;

	switch (type) {
	case 0:
		ret = pStreamData->currentVideoStream;
		break;
	case 1:
		ret = pStreamData->currentAudioStream;
		break;
	default:
		ret = -1;
		break;
	}

	return ret;
}

int decode_changeCurrentStreamGetAuMode(t_mpegStreamData *pStreamData, int mode) {
    sceMpegChangeGetAuMode(pStreamData->pMpeg, pStreamData->pVideoStream[pStreamData->currentVideoStream], mode);
    return 0;
}
