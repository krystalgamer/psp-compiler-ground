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
    SceInt32 currentVideoStreamTypeId;
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
struct t_playInfo { /* size 0x454 */
    SceInt32 playMode;
    SceInt32 fileSize;
    SceUInt32 timestamp;
    t_streamInfo sInfo;
    t_mpegStreamData streamData;
    SceUInt32 nextIdrTimestamp;
    SceInt32 videoChangeMode;
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



SceInt32 playInfo_create(t_playInfo *pPlayInfo, SceMpeg *pMpeg, ScePsmf *pVideoPsmf, ScePsmf *pAudioPsmf, SceInt32 audioFlag);
SceInt32 playInfo_reset(t_playInfo *pPlayInfo);
SceInt32 playInfo_changeVideoStream(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync);
SceInt32 playInfo_audioDecode(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync, SceInt32 audio_init_flag);
SceInt32 playInfo_videoDecode(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync);
SceInt32 playInfo_changeAudioStream(t_playInfo *pPlayInfo);


extern const char D_000117B4[]; /* "...sInfo_setCurrentStream() 0x%x\n" (rodata after this function) */
extern const char D_000117E4[]; /* "...decode_setRegistStream() audio 0x%x\n" */

SceInt32 playInfo_create(t_playInfo *pPlayInfo, SceMpeg *pMpeg, ScePsmf *pVideoPsmf, ScePsmf *pAudioPsmf, SceInt32 audioFlag)
{
	SceInt32 ch;
	SceInt32 i;
	SceInt32 ret;

	pPlayInfo->playMode = 0;

	ret = sInfo_setPsmf(&pPlayInfo->sInfo, pVideoPsmf, pAudioPsmf, audioFlag);
	if (ret != 0) {
		printf("fatal error : sInfo_setPsmf() 0x%x\n", ret);
		goto term;
	}

	ret = decode_create(&pPlayInfo->streamData, pMpeg);
	if (ret != 0) {
		printf("fatal error : decode_create() 0x%x\n", ret);
		goto term;
	}

	ret = decode_setCurrentStream(&pPlayInfo->streamData, 0, 0);
	if (ret != 0) {
		printf("fatal error : decode_setCurrentStream() M4AVC 0x%x\n", ret);
		goto term;
	}

	ret = decode_setCurrentStream(&pPlayInfo->streamData, 1, 0);
	if (ret != 0) {
		printf("fatal error : decode_setCurrentStream() ATRAC 0x%x\n", ret);
		goto term;
	}

	for (i = 0; i < sInfo_getNumberOfStreams(&pPlayInfo->sInfo, 0); i++) {
		ret = sInfo_setCurrentStream(&pPlayInfo->sInfo, 1, i);
		if (ret != 0) {
			printf(D_000117B4, ret);
			goto term;
		}

		ret = sInfo_getCurrentStreamCh(&pPlayInfo->sInfo, &ch, 1);
		if (ret != 0) {
			printf("fatal error : sInfo_getCurrentStreamCh() 0x%x\n", ret);
			goto term;
		}

		ret = decode_setRegistStream(&pPlayInfo->streamData, 0, ch);
		if (ret != 0) {
			printf("fatal error : decode_setRegistStream() video 0x%x\n", ret);
			goto term;
		}
	}

	for (i = 0; i < sInfo_getNumberOfStreams(&pPlayInfo->sInfo, 1); i++) {
		ret = sInfo_setCurrentStream(&pPlayInfo->sInfo, 1, i);
		if (ret != 0) {
			printf(D_000117B4, ret);
			goto term;
		}

		ret = sInfo_getCurrentStreamCh(&pPlayInfo->sInfo, &ch, 1);
		if (ret != 0) {
			printf("fatal error : sInfo_getCurrentStreamCh() 0x%x\n", ret);
			goto term;
		}

		ret = decode_setRegistStream(&pPlayInfo->streamData, 1, ch);
		if (ret != 0) {
			printf(D_000117E4, ret);
			goto term;
		}
	}

	sInfo_setCurrentStream(&pPlayInfo->sInfo, 0, 0);
	sInfo_setCurrentStream(&pPlayInfo->sInfo, 1, 0);

	ret = 0;

term:
	return ret;
}

int playInfo_delete(t_playInfo *pPlayInfo) {
    t_mpegStreamData *temp_s0;

    temp_s0 = &pPlayInfo->streamData;
    decode_unRegistStream(temp_s0, 0);
    decode_unRegistStream(temp_s0, 1);
    decode_delete(temp_s0);
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/playInfo", D_000117B4);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/playInfo", D_000117E4);

SceInt32 playInfo_reset(t_playInfo *pPlayInfo)
{
	SceInt32 ret;

	sInfo_getStartTimestamp(&pPlayInfo->sInfo, &pPlayInfo->timestamp);

	ret = sInfo_reset(&pPlayInfo->sInfo, sInfo_getCurrentStreamTypeNumber(&pPlayInfo->sInfo, 0), sInfo_getCurrentStreamTypeNumber(&pPlayInfo->sInfo, 1));
	if (ret != 0) {
		printf("fatal error : sInfo_init() 0x%x\n", ret);
		goto term;
	}

	ret = decode_reset(&pPlayInfo->streamData, decode_getCurrentStream(&pPlayInfo->streamData, 0), decode_getCurrentStream(&pPlayInfo->streamData, 1));
	if (ret != 0) {
		printf("fatal error : decode_iit() 0x%x\n", ret);
		goto term;
	}

	pPlayInfo->playMode = 0;

	pPlayInfo->videoChangeMode = 0;

term:
	return ret;
}

int playInfo_getAudioStreamNum(t_playInfo *pPlayInfo) {
    return sInfo_getNumberOfStreams(&pPlayInfo->sInfo, 1);
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

extern const char D_000117B4[]; /* shared rodata string */
SceInt32 playInfo_changeVideoStream(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync)
{
	SceInt32 ret;
	SceUInt32 pts;
	SceUInt32 idrPts;
	SceInt32 currentVideoNumber;
	SceInt32 reservedVideoNumber;

	if (pPlayInfo->videoChangeMode != 0) {
		return 0;
	}

	if (sInfo_getNumberOfStreams(&pPlayInfo->sInfo, 0) < 2) {
		return 0;
	}

	pPlayInfo->videoChangeMode = 1;

	avsync_video_getLatestPts(pAvSync, &pts);

	currentVideoNumber = decode_getCurrentStream(&pPlayInfo->streamData, 0);

	reservedVideoNumber = (currentVideoNumber + 1) % sInfo_getNumberOfStreams(&pPlayInfo->sInfo, 0);

	ret = sInfo_setCurrentStream(&pPlayInfo->sInfo, 0, reservedVideoNumber);
	if (ret != 0) {
		printf(D_000117B4, ret);
		goto term;
	}

	sInfo_getNextEPTimestamp(&pPlayInfo->sInfo, pts, &idrPts);

	decode_setReservedMode(&pPlayInfo->streamData, 0, reservedVideoNumber);

	pPlayInfo->nextIdrTimestamp = idrPts;

term:
	return ret;
}

SceInt32 playInfo_audioDecode(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync, SceInt32 audio_init_flag)
{
	SceInt32 ret;

	ret = decode_getAudioAu(&pPlayInfo->streamData, pAvSync);
	if (ret != 0) {
		if (ret != 1) {
			printf("fatal error : decode_getAudioAu() 0x%x\n", ret);
		}
		goto term;
	}

	ret = decode_audioDecode(&pPlayInfo->streamData, pAvSync, audio_init_flag);

term:
	return ret;
}

SceInt32 playInfo_videoDecode(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync)
{
	SceInt32 ret;
	SceUInt32 timestamp;

	ret = decode_getVideoAu(&pPlayInfo->streamData);
	if (ret != 0) {
		if (ret == 1) {
			goto term;
		}
		printf("fatal error : decode_getAvcAu() 0x%x\n", ret);
		goto term;
	}

	if (pPlayInfo->videoChangeMode == 1) {
		ret = decode_checkReservedVideoGetAu(&pPlayInfo->streamData);
		if (ret != 0) {
			ret = 0;
			goto term;
		}

		ret = decode_getReservedVideoAuTimestamp(&pPlayInfo->streamData, &timestamp);
		if (ret != 0) {
			goto term;
		}

		if (timestamp != 0xFFFFFFFF && pPlayInfo->nextIdrTimestamp < timestamp) {
			SceUInt32 nextTimestamp;

			ret = sInfo_getNextEPTimestamp(&pPlayInfo->sInfo, timestamp, &nextTimestamp);
			if (ret != 0) {
				printf("fatal error : sInfo_getNextEPTimestamp() 0x%x\n", ret);
				goto term;
			}

			pPlayInfo->nextIdrTimestamp = nextTimestamp;
		}

		if (timestamp == pPlayInfo->nextIdrTimestamp) {
			playInfo_flushDecoder(pPlayInfo);

			decode_changeCurrentStreamGetAuMode(&pPlayInfo->streamData, 1);

			ret = decode_reservedVideoDecode(&pPlayInfo->streamData, pAvSync);
			if (ret != 0) {
				if (ret != 1) {
					printf("fatal error : decode_reservedVideoDecode() 0x%x\n", ret);
				}
				goto term;
			}

			sInfo_setCurrentStream(&pPlayInfo->sInfo, 0, decode_getCurrentReservedStream(&pPlayInfo->streamData));

			decode_setCurrentStream(&pPlayInfo->streamData, 0, decode_getCurrentReservedStream(&pPlayInfo->streamData));

			decode_setReservedVideoStream(&pPlayInfo->streamData, -1);

			decode_initAu(&pPlayInfo->streamData, 0, decode_getCurrentStream(&pPlayInfo->streamData, 0), 0);

			pPlayInfo->videoChangeMode = 0;

			goto term;
		}
	}

	ret = decode_videoDecode(&pPlayInfo->streamData, pAvSync);
	if (ret != 0) {
		if (ret != 1) {
			if (ret != (SceInt32)0x80618001) {
				printf("fatal error : decode_videoDecode() 0x%x\n", ret);
			}
		}
	}

term:
	return ret;
}

int playInfo_videoDecodeEnd(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync) {
    return decode_videoDecodeEnd(&pPlayInfo->streamData);
}

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
