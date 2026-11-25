#include "common.h"

/* declarations recovered from DWARF */
struct t_streamInfo;
struct ScePsmf;
typedef int SceInt32;
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
typedef SceInt32 SceMpegStrType;
struct ScePsmfEntryPoint;
typedef unsigned int SceUInt32;
struct ScePsmfEntryPoint { /* size 0x8 */
    SceUInt32 pts;
    SceUInt32 offset;
};
typedef struct ScePsmfEntryPoint ScePsmfEntryPoint;



SceInt32 sInfo_reset(t_streamInfo *pStreamInfo, SceInt32 videoId, SceInt32 audioId);
SceInt32 sInfo_getNumberOfStreams(t_streamInfo *pStreamInfo, SceInt32 streamType);
SceInt32 sInfo_setCurrentStream(t_streamInfo *pStreamInfo, SceMpegStrType streamType, SceInt32 streamTypeId);
SceInt32 sInfo_getCurrentStreamCh(t_streamInfo *pStreamInfo, SceInt32 *ch, SceMpegStrType streamType);
SceInt32 sInfo_getCurrentStreamTypeNumber(t_streamInfo *pStreamInfo, SceMpegStrType type);
SceInt32 sInfo_getEPOffset(t_streamInfo *pStreamInfo, SceInt32 timestamp, SceInt32 *offset, SceInt32 *odd);
SceInt32 sInfo_getNextEPTimestamp(t_streamInfo *pStreamInfo, SceUInt32 timestamp, SceUInt32 *pEPTimestamp);


int sInfo_setPsmf(t_streamInfo *pStreamInfo, ScePsmf *pVideoPsmf, ScePsmf *pAudioPsmf, int audioFlag) {
    pStreamInfo->pVideoPsmf = pVideoPsmf;
    pStreamInfo->pAudioPsmf = pAudioPsmf;
    setNumberOfStreams(pStreamInfo, 0);
    if (audioFlag == 0) {
        pStreamInfo->numberOfAudioStreams = 0;
    } else {
        setNumberOfStreams(pStreamInfo, 1);
    }
    sInfo_setCurrentStream(pStreamInfo, 0, 0);
    if (pStreamInfo->numberOfAudioStreams != 0) {
        pStreamInfo->currentAudioStreamTypeId = -1;
    } else {
        sInfo_setCurrentStream(pStreamInfo, 1, 0);
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/parsePsmf", sInfo_reset);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/parsePsmf", sInfo_getNumberOfStreams);

int setNumberOfStreams(t_streamInfo *pStreamInfo, int streamType) {
    int var_s1;

    var_s1 = 0;
    if (streamType != 0) {
        if (streamType != 1) {
            var_s1 = -1;
        } else {
            pStreamInfo->numberOfAudioStreams = scePsmfGetNumberOfSpecificStreams(pStreamInfo->pAudioPsmf);
        }
    } else {
        pStreamInfo->numberOfAvcStreams = scePsmfGetNumberOfSpecificStreams(pStreamInfo->pVideoPsmf);
    }
    return var_s1;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/parsePsmf", sInfo_setCurrentStream);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/parsePsmf", sInfo_getCurrentStreamCh);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/parsePsmf", sInfo_getCurrentStreamTypeNumber);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/parsePsmf", D_00011D34);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/parsePsmf", D_00011D64);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/parsePsmf", sInfo_getEPOffset);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/parsePsmf", sInfo_getNextEPTimestamp);

int sInfo_getStartTimestamp(t_streamInfo *pStreamInfo, unsigned int *pTimestamp) {
    return scePsmfGetPresentationStartTime(pStreamInfo->pVideoPsmf);
}
