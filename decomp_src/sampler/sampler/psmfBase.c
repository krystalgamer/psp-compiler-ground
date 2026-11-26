/* cflags: -O2 -frename-registers */
#include "common.h"
#include <psptypes.h>
#include "psmf.h"

typedef struct ScePsmf_EP {
	SceUChar8 picture_copy_and_msb_pts_start[2];
	SceUChar8 pts_ep_start[4];
	SceUChar8 rpn_ep_start[4];
} ScePsmf_EP;

typedef struct ScePsmf_GroupingPeriod {
	SceUChar8 length_grouping_period[4];
	SceUChar8 msb_groupingperiod_start_time[2];
	SceUChar8 groupingperiod_start_time[4];
	SceUChar8 msb_groupingperiod_end_time[2];
	SceUChar8 groupingperiod_end_time[4];
	SceUChar8 reserved;
	SceUChar8 number_of_groups;
} ScePsmf_GroupingPeriod;

typedef struct ScePsmf_Group {
	SceUChar8 length_group[4];
	SceUChar8 reserved;
	SceUChar8 number_of_streams;
} ScePsmf_Group;

#define SCE_PSMF_ERROR_NO_EP_MAP	0x80615025
#define SCE_PSMF_ERROR_INVALID_ID	0x80615100
#define SCE_PSMF_ERROR_NOT_FOUND	0x80615500
#define SCE_PSMF_ERROR_UNKNOWN_STREAM	0x80000100

#define PSMF_STREAM_SIZE	16

SceUShort16 sceMpegSwap2(SceVoid *p);
SceInt32 scePsmfCheckStreamType_Base(SceUInt32 stream_id, SceUInt32 private_stream_id);
static SceInt32 _GetRelavantEP_map(ScePsmf_EP *pEp_map, SceUInt32 ep_id, SceUInt32 timestamp);

#ifdef NON_MATCHING
SceInt32 scePsmfSpecifyStream_Base(ScePsmf *psmf, SceInt32 psmfStream_id)
{
	ScePsmf_Group *pGroup = psmf->currentGroup;
	SceUChar8 *pStream = (SceUChar8 *)pGroup + sizeof(ScePsmf_Group) + psmfStream_id * PSMF_STREAM_SIZE;
	SceUInt32 offset;

	if (psmfStream_id < pGroup->number_of_streams) {
		psmf->currentStream = pStream;
		offset = sceMpegSwap4(pStream + 4);
		if (offset != 0)
			psmf->currentEP_map = (SceUChar8 *)psmf->header + offset;
		else
			psmf->currentEP_map = NULL;
		return 0;
	}
	psmf->currentEP_map = NULL;
	psmf->currentStream = NULL;
	return SCE_PSMF_ERROR_INVALID_ID;
}
#else
INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/psmfBase", scePsmfSpecifyStream_Base);
#endif

SceInt32 scePsmfGetPsmfStreamIdWithStream_Base(ScePsmf *psmf, SceUInt32 s_id, SceUInt32 p_id)
{
	ScePsmf_Group *pGroup = psmf->currentGroup;
	SceUChar8 *pStream = (SceUChar8 *)pGroup + sizeof(ScePsmf_Group);
	SceInt32 ret;
	SceInt32 i;

	ret = SCE_PSMF_ERROR_INVALID_ID;
	for (i = 0; i < pGroup->number_of_streams; i++, pStream += PSMF_STREAM_SIZE) {
		if (pStream[0] == s_id && pStream[1] == p_id) {
			ret = i;
			break;
		}
	}
	return ret;
}

#ifdef NON_MATCHING
SceInt32 scePsmfGetEPWithId_Base(ScePsmf *psmf, SceInt32 ep_id, ScePsmf_EntryPoint *pEntry)
{
	ScePsmf_EP *pEp;
	SceInt32 ret;

	ret = 0;
	if (sceMpegSwap4((SceUChar8 *)psmf->currentStream + 8) == 0) {
		ret = SCE_PSMF_ERROR_NO_EP_MAP;
	} else if (ep_id >= (SceInt32)sceMpegSwap4((SceUChar8 *)psmf->currentStream + 8)) {
		ret = SCE_PSMF_ERROR_INVALID_ID;
	} else {
		pEp = (ScePsmf_EP *)psmf->currentEP_map + ep_id;
		pEntry->EP_start_offset = sceMpegSwap4(pEp->rpn_ep_start) << 11;
		pEntry->PTS_EP_start = sceMpegSwap4(pEp->pts_ep_start);
	}
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/psmfBase", scePsmfGetEPWithId_Base);
#endif

#ifdef NON_MATCHING
SceInt32 scePsmfGetEPWithTimestamp_Base(ScePsmf *psmf, SceUInt32 timestamp, ScePsmf_EntryPoint *pEntry)
{
	ScePsmf_EP *pEp;
	SceInt32 ep_id;
	SceInt32 ret;

	ret = 0;
	if (sceMpegSwap4((SceUChar8 *)psmf->currentStream + 8) == 0) {
		ret = SCE_PSMF_ERROR_NO_EP_MAP;
	} else {
		ep_id = _GetRelavantEP_map(psmf->currentEP_map, sceMpegSwap4((SceUChar8 *)psmf->currentStream + 8), timestamp);
		pEp = (ScePsmf_EP *)psmf->currentEP_map + ep_id;
		if (ep_id < 0) {
			ret = ep_id;
		} else {
			pEntry->EP_start_offset = sceMpegSwap4(pEp->rpn_ep_start) << 11;
			pEntry->PTS_EP_start = sceMpegSwap4(pEp->pts_ep_start);
		}
	}
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/psmfBase", scePsmfGetEPWithTimestamp_Base);
#endif

SceInt32 scePsmfCheckStreamType_Base(SceUInt32 stream_id, SceUInt32 private_stream_id)
{
	if (stream_id >= 0xE0 && stream_id <= 0xEF)
		return 0;
	if (stream_id == 0xBD && private_stream_id < 0x10)
		return 1;
	return SCE_PSMF_ERROR_UNKNOWN_STREAM;
}

static SceInt32 _GetRelavantEP_map(ScePsmf_EP *pEp_map, SceUInt32 ep_id, SceUInt32 timestamp)
{
	SceInt32 i;
	ScePsmf_EP *pEp;

	pEp = pEp_map;
	for (i = 0; i < (SceInt32)ep_id; i++, pEp++) {
		if (timestamp < sceMpegSwap4(pEp->pts_ep_start))
			break;
	}
	if (i > 0)
		i--;
	else if (i == 0)
		i = SCE_PSMF_ERROR_NOT_FOUND;
	return i;
}

SceInt32 scePsmfBaseStartEntry(void)
{
	return 0;
}

static __inline__ SceUInt32 _getOffset_GroupingPeriod(ScePsmf_GroupingPeriod *pGroupPeriod, SceInt32 gp_id)
{
	SceUInt32 offset;
	SceInt32 i;

	offset = 0;
	for (i = 0; i < gp_id; i++)
		offset += sceMpegSwap4((SceUChar8 *)pGroupPeriod + offset);
	return offset;
}

SceInt32 scePsmfSpecifyGroupingPeriod_Base(ScePsmf *psmf, SceInt32 gp_id)
{
	SceUChar8 *pSeq = psmf->sequenceInfo;
	ScePsmf_GroupingPeriod *pGroupPeriod;

	if (gp_id >= pSeq[0x19])
		return SCE_PSMF_ERROR_INVALID_ID;
	pGroupPeriod = (ScePsmf_GroupingPeriod *)(pSeq + 0x1A);
	psmf->currentGroupingPeriod = (SceUChar8 *)pGroupPeriod + _getOffset_GroupingPeriod(pGroupPeriod, gp_id);
	return 0;
}

static __inline__ SceUInt32 _getOffset_Group(ScePsmf_Group *pGroup, SceInt32 group_id)
{
	SceUInt32 offset;
	SceInt32 i;

	offset = 0;
	for (i = 0; i < group_id; i++)
		offset += sceMpegSwap4((SceUChar8 *)pGroup + offset);
	return offset;
}

SceInt32 scePsmfSpecifyGroup_Base(ScePsmf *psmf, SceInt32 group_id)
{
	ScePsmf_GroupingPeriod *pGroupPeriod = psmf->currentGroupingPeriod;
	ScePsmf_Group *pGroup;

	if (group_id >= pGroupPeriod->number_of_groups)
		return SCE_PSMF_ERROR_INVALID_ID;
	pGroup = (ScePsmf_Group *)((SceUChar8 *)pGroupPeriod + sizeof(ScePsmf_GroupingPeriod));
	psmf->currentGroup = (SceUChar8 *)pGroup + _getOffset_Group(pGroup, group_id);
	return 0;
}

SceInt32 scePsmfGetNumberOfTotalStream_Base(ScePsmf *psmf)
{
	return ((SceUChar8 *)psmf->sequenceInfo)[0x18];
}

SceInt32 scePsmfGetNumberOfGroupingPeriod_Base(ScePsmf *psmf)
{
	return ((SceUChar8 *)psmf->sequenceInfo)[0x19];
}

SceInt32 scePsmfGetPresentationStartTime_Base(ScePsmf *psmf, SceInt32 *start_time)
{
	*start_time = sceMpegSwap4((SceUChar8 *)psmf->sequenceInfo + 0x6);
	return 0;
}

SceInt32 scePsmfGetPresentationEndTime_Base(ScePsmf *psmf, SceInt32 *end_time)
{
	*end_time = sceMpegSwap4((SceUChar8 *)psmf->sequenceInfo + 0xC);
	return 0;
}

SceInt32 scePsmfGetMUXRateBound_Base(ScePsmf *psmf)
{
	return sceMpegSwap4((SceUChar8 *)psmf->sequenceInfo + 0x10);
}

SceInt32 scePsmfGetStdDelayBound_Base(ScePsmf *psmf)
{
	return sceMpegSwap4((SceUChar8 *)psmf->sequenceInfo + 0x14);
}

SceInt32 scePsmfGetPresentationStartTime_GP_Base(ScePsmf *psmf, SceUInt32 *start_timestamp)
{
	*start_timestamp = sceMpegSwap4(((ScePsmf_GroupingPeriod *)psmf->currentGroupingPeriod)->groupingperiod_start_time);
	return 0;
}

SceInt32 scePsmfGetPresentationEndTime_GP_Base(ScePsmf *psmf, SceUInt32 *end_timestamp)
{
	*end_timestamp = sceMpegSwap4(((ScePsmf_GroupingPeriod *)psmf->currentGroupingPeriod)->groupingperiod_end_time);
	return 0;
}

SceInt32 scePsmfGetNumberOfGroups_Base(ScePsmf *psmf)
{
	return ((ScePsmf_GroupingPeriod *)psmf->currentGroupingPeriod)->number_of_groups;
}

SceInt32 scePsmfGetNumberOfStreams_Base(ScePsmf *psmf)
{
	return ((ScePsmf_Group *)psmf->currentGroup)->number_of_streams;
}

SceInt32 scePsmfGetStreamId_Base(ScePsmf *psmf, SceUInt32 *stream_id)
{
	*stream_id = ((SceUChar8 *)psmf->currentStream)[0];
	return 0;
}

SceInt32 scePsmfGetPrivateStreamId_Base(ScePsmf *psmf, SceUInt32 *private_id)
{
	*private_id = ((SceUChar8 *)psmf->currentStream)[1];
	return 0;
}

SceInt32 scePsmfGetP_STD_buffer_scale_Base(ScePsmf *psmf)
{
	return ((SceUChar8 *)psmf->currentStream)[2] >> 5;
}

SceInt32 scePsmfGetP_STD_buffer_size_Base(ScePsmf *psmf)
{
	SceUChar8 *pStream = psmf->currentStream;
	SceUChar8 buf[2];

	buf[0] = pStream[2] & 0x1F;
	buf[1] = pStream[3];
	return sceMpegSwap2(buf);
}

SceInt32 scePsmfGetNumberOfEP_entries_Base(ScePsmf *psmf)
{
	return sceMpegSwap4((SceUChar8 *)psmf->currentStream + 8);
}

SceInt32 scePsmfGetSequenceInfo_Video_Base(ScePsmf *psmf, ScePsmf_SequenceInfo_Video *pSInfo_Video)
{
	SceUChar8 *pStream = psmf->currentStream;
	SceInt32 ret;

	ret = 0;
	if (scePsmfCheckStreamType_Base(pStream[0], pStream[1]) == 0) {
		pSInfo_Video->horizontal_size = pStream[0xC] << 4;
		pSInfo_Video->vertical_size = pStream[0xD] << 4;
	} else {
		ret = SCE_PSMF_ERROR_INVALID_ID;
	}
	return ret;
}

#ifdef NON_MATCHING
SceInt32 scePsmfGetSequenceInfo_Audio_Base(ScePsmf *psmf, ScePsmf_SequenceInfo_Audio *pSInfo_Audio)
{
	SceUChar8 *pStream;
	SceInt32 ret;

	ret = 0;
	pStream = psmf->currentStream;
	if (scePsmfCheckStreamType_Base(pStream[0], pStream[1]) == 1) {
		pStream += 0xC;
		pSInfo_Audio->channel_configuration = pStream[2];
		pSInfo_Audio->sampling_frequency = pStream[3];
	} else {
		ret = SCE_PSMF_ERROR_INVALID_ID;
	}
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/psmfBase", scePsmfGetSequenceInfo_Audio_Base);
#endif

SceInt32 scePsmfCheckEP_map_Base(ScePsmf *psmf)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NO_EP_MAP;
	if (sceMpegSwap4((SceUChar8 *)psmf->currentStream + 8) != 0)
		ret = 0;
	return ret;
}

#ifdef NON_MATCHING
SceInt32 scePsmfGetEP_idWithTimestamp_Base(ScePsmf *psmf, SceUInt32 timestamp)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NO_EP_MAP;
	if (sceMpegSwap4((SceUChar8 *)psmf->currentStream + 8) != 0)
		ret = _GetRelavantEP_map(psmf->currentEP_map, sceMpegSwap4((SceUChar8 *)psmf->currentStream + 8), timestamp);
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/psmfBase", scePsmfGetEP_idWithTimestamp_Base);
#endif

#ifdef NON_MATCHING
SceInt32 scePsmfGetStreamType_Base(ScePsmf *psmf, SceInt32 psmfStream_id)
{
	ScePsmf_Group *pGroup = psmf->currentGroup;
	SceUChar8 *pStream = (SceUChar8 *)pGroup + sizeof(ScePsmf_Group) + psmfStream_id * 12;
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_INVALID_ID;
	if (psmfStream_id < pGroup->number_of_streams)
		ret = scePsmfCheckStreamType_Base(pStream[0], pStream[1]);
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/psmfBase", scePsmfGetStreamType_Base);
#endif
