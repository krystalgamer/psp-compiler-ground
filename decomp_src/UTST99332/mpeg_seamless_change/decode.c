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


INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_create);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_reset);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_delete);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_changeAuMode);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_initAu);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_createAu);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_createAvcAu);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_createAudioAu);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_deleteAu);

int decode_getAudioOutSize(t_mpegStreamData *pStreamData) {
    return pStreamData->audioOutSize;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_setRegistStream);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_unRegistStream);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_setReservedMode);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_getAudioAu);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_audioDecode);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_getVideoAu);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_videoDecode);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_reservedVideoDecode);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", D_00011C18);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_videoDecodeEnd);

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

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/decode", decode_getReservedVideoAuTimestamp);

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
