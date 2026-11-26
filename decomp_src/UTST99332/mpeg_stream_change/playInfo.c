#include "common.h"

/* declarations recovered from DWARF */
struct t_playInfo;
typedef int SceInt32;
typedef unsigned int SceUInt32;
struct t_streamInfo;
struct ScePsmf;
typedef void SceVoid;
struct ScePsmf { /* size 0x28 */
    SceInt32 type;
    SceInt32 groupingPeriodId;
    SceInt32 groupId;
    SceInt32 streamNumber;
    SceVoid *header;
    SceVoid *sequenceInfo;
    SceVoid *currentGroupingPeriod;
    SceVoid *currentGroup;
    SceVoid *currentStream;
    SceVoid *currentEPmap;
};
typedef struct ScePsmf ScePsmf;
struct t_streamInfo { /* size 0x18 */
    ScePsmf *pVideoPsmf;
    ScePsmf *pAudioPsmf;
    SceInt32 currentAvcStreamTypeId;
    SceInt32 currentAudioStreamTypeId;
    SceInt32 numberOfAvcStreams;
    SceInt32 numberOfAudioStreams;
};
typedef struct t_streamInfo t_streamInfo;
struct t_mpegStreamData;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
};
typedef struct SceMpeg SceMpeg;
struct SceMpegStream;
typedef SceUInt32 SceMpegStreamId;
typedef unsigned char SceUChar8;
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
struct t_playInfo { /* size 0x3cc */
    SceInt32 playMode;
    SceInt32 fileSize;
    SceInt32 offset;
    SceUInt32 timestamp;
    t_streamInfo sInfo;
    t_mpegStreamData streamData;
};
typedef struct t_playInfo t_playInfo;
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



SceInt32 playInfo_create(t_playInfo *pPlayInfo, SceMpeg *pMpeg, ScePsmf *pVideoPsmf, ScePsmf *pAudioPsmf, SceInt32 fileSize, SceInt32 audioFlag);
SceInt32 playInfo_reset(t_playInfo *pPlayInfo, SceUInt32 currentTimestamp);
SceInt32 playInfo_setOffset(t_playInfo *pPlayInfo);
SceInt32 playInfo_changeVideoStream(t_playInfo *pPlayInfo);
SceInt32 playInfo_changeAudioStream(t_playInfo *pPlayInfo);


INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/playInfo", playInfo_create);

int playInfo_delete(t_playInfo *pPlayInfo, int audioFlag) {
    t_mpegStreamData *temp_s1;

    temp_s1 = &pPlayInfo->streamData;
    decode_unRegistStream(temp_s1, 0);
    if (audioFlag == 1) {
        decode_unRegistStream(temp_s1, 1);
    }
    decode_delete(temp_s1);
    return 0;
}

SceInt32 playInfo_reset(t_playInfo *pPlayInfo, SceUInt32 currentTimestamp)
{
	SceInt32 ret;

	ret = sInfo_reset(&pPlayInfo->sInfo, sInfo_getCurrentStreamTypeNumber(&pPlayInfo->sInfo, 0), sInfo_getCurrentStreamTypeNumber(&pPlayInfo->sInfo, 1));
	if (ret != 0) {
		printf("fatal error : sInfo_init() 0x%x\n", ret);
		goto term;
	}

	ret = decode_reset(&pPlayInfo->streamData, decode_getCurrentStream(&pPlayInfo->streamData, 0), decode_getCurrentStream(&pPlayInfo->streamData, 1), currentTimestamp);
	if (ret != 0) {
		printf("fatal error : decode_iit() 0x%x\n", ret);
		goto term;
	}

	playInfo_setPts(pPlayInfo, currentTimestamp);

	playInfo_setOffset(pPlayInfo);

	pPlayInfo->playMode = 0;

term:
	return ret;
}

int playInfo_getAudioStreamNum(t_playInfo *pPlayInfo) {
    return sInfo_getNumberOfStreams(&pPlayInfo->sInfo, 1);
}

SceInt32 playInfo_setOffset(t_playInfo *pPlayInfo)
{
	SceInt32 offset;

	sInfo_getEPOffset(&pPlayInfo->sInfo, pPlayInfo->timestamp, &offset);

	pPlayInfo->offset = offset;

	return 0;
}

int playInfo_getOffset(t_playInfo *pPlayInfo) {
    return pPlayInfo->offset;
}

int playInfo_getPlayerMode(t_playInfo *pPlayInfo) {
    return pPlayInfo->playMode;
}

int playInfo_setPlayerMode(t_playInfo *pPlayInfo, int mode) {
    pPlayInfo->playMode = mode;
    return 0;
}

int playInfo_setPts(t_playInfo *pPlayInfo, unsigned int timestamp) {
    pPlayInfo->timestamp = timestamp;
    return 0;
}

int playInfo_getPts(t_playInfo *pPlayInfo, unsigned int *pTimestamp) {
    *pTimestamp = pPlayInfo->timestamp;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/playInfo", playInfo_changeVideoStream);

int playInfo_getAudioOutSize(t_playInfo *pPlayInfo) {
    return decode_getAudioOutSize(&pPlayInfo->streamData);
}

SceInt32 playInfo_changeAudioStream(t_playInfo *pPlayInfo)
{
	SceInt32 ret;
	SceInt32 audioStreamNum;
	SceInt32 currentAudioStream;
	SceInt32 nextAudioStream;

	audioStreamNum = sInfo_getNumberOfStreams(&pPlayInfo->sInfo, 1);
	if (audioStreamNum == 0) {
		return 0;
	}

	currentAudioStream = sInfo_getCurrentStreamTypeNumber(&pPlayInfo->sInfo, 1);

	nextAudioStream = (currentAudioStream + 1) % audioStreamNum;

	sInfo_setCurrentStream(&pPlayInfo->sInfo, 1, nextAudioStream);

	decode_setCurrentStream(&pPlayInfo->streamData, 1, nextAudioStream);

	ret = decode_changeAuMode(&pPlayInfo->streamData, 1, currentAudioStream, 0);
	if (ret != 0) {
		printf("fatal error : decode_changeAuMode() 0x%x\n", ret);
		goto term;
	}

	ret = decode_changeAuMode(&pPlayInfo->streamData, 1, nextAudioStream, 1);
	if (ret != 0) {
		printf("fatal error : decode_changeAuMode() 0x%x\n", ret);
		goto term;
	}

term:
	return ret;
}

int playInfo_flushDecoder(t_playInfo *pPlayInfo) {
    return decode_flushDecoder(&pPlayInfo->streamData);
}

int playInfo_audioDecode(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync, int audio_init_flag) {
    return decode_audioDecode(&pPlayInfo->streamData);
}

int playInfo_videoDecode(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync) {
    return decode_videoDecode(&pPlayInfo->streamData);
}

int playInfo_videoDecodeEnd(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync) {
    return decode_videoDecodeEnd(&pPlayInfo->streamData);
}

int playInfo_getStartTimestamp(t_playInfo *pPlayInfo, unsigned int *pTimestamp) {
    return sInfo_getStartTimestamp(&pPlayInfo->sInfo);
}
