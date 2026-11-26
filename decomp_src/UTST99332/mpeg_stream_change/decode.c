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
struct t_mpegStreamData { /* size 0x3a4 */
    SceMpeg *pMpeg;
    SceMpegStream *pVideoStream[16];
    SceMpegStream *pAudioStream[16];
    SceInt32 currentVideoStream;
    SceInt32 currentAudioStream;
    SceInt32 videoStreamNum;
    SceInt32 audioStreamNum;
    SceMpegAu avcAu[16];
    SceMpegAu audioAu[16];
    SceMpegHandle avcEsBuf;
    SceChar8 *pAudioEsBuf;
    SceInt32 audioOutSize;
    SceUInt32 startTimestamp;
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
SceInt32 decode_reset(t_mpegStreamData *pStreamData, SceInt32 videoStream, SceInt32 audioStream, SceUInt32 timestamp);
SceInt32 decode_delete(t_mpegStreamData *pStreamData);
SceInt32 decode_changeAuMode(t_mpegStreamData *pStreamData, SceMpegStrType type, SceInt32 number, SceInt32 flag);
SceInt32 decode_initAu(t_mpegStreamData *pStreamData, SceMpegStrType type, SceInt32 number);
SceInt32 decode_createAu(t_mpegStreamData *pStreamData, SceMpegStrType type);
SceInt32 decode_createAudioAu(t_mpegStreamData *pStreamData);
SceInt32 decode_setRegistStream(t_mpegStreamData *pStreamData, SceInt32 streamType, SceInt32 ch);
SceInt32 decode_unRegistStream(t_mpegStreamData *pStreamData, SceInt32 streamType);
SceInt32 decode_audioDecode(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 audio_init_flag);
SceInt32 decode_videoDecode(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_videoDecodeEnd(t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_getCurrentStream(t_mpegStreamData *pStreamData, SceMpegStrType type);

/* SDK functions (tools/sdk_protos.h) */
int puts(const char *s);
void free(void *p);


INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/decode", decode_create);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/decode", decode_reset);

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

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/decode", decode_changeAuMode);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/decode", decode_initAu);

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

int decode_createAvcAu(t_mpegStreamData *pStreamData) {
    int var_v1;
    unsigned char *temp_v0;

    temp_v0 = sceMpegMallocAvcEsBuf(pStreamData->pMpeg);
    pStreamData->avcEsBuf = temp_v0;
    var_v1 = 0;
    if (temp_v0 == NULL) {
        puts("fatal error : sceMpegMallocAvcEsBuf()");
        var_v1 = -1;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/decode", decode_createAudioAu);

int decode_deleteAu(t_mpegStreamData *pStreamData, int type) {
    signed char *temp_v0;
    unsigned char *temp_v0_2;

    switch (type) {                                 /* irregular */
    case 1:
        temp_v0 = pStreamData->pAudioEsBuf;
        if (temp_v0 != NULL) {
            free(temp_v0);
            pStreamData->pAudioEsBuf = NULL;
        }
        break;
    case 0:
        temp_v0_2 = pStreamData->avcEsBuf;
        if (temp_v0_2 != NULL) {
            sceMpegFreeAvcEsBuf(pStreamData->pMpeg, temp_v0_2);
            pStreamData->avcEsBuf = NULL;
        }
        break;
    }
    return 0;
}

int decode_getAudioOutSize(t_mpegStreamData *pStreamData) {
    return pStreamData->audioOutSize;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/decode", decode_setRegistStream);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/decode", decode_unRegistStream);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/decode", decode_audioDecode);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/decode", decode_videoDecode);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/decode", decode_videoDecodeEnd);

int decode_flushDecoder(t_mpegStreamData *pStreamData) {
    return sceMpegAvcDecodeFlush(pStreamData->pMpeg);
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
