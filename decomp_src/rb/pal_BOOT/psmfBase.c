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

typedef struct ScePsmf_GroupStream {
	SceUChar8 stream_id;
	SceUChar8 private_stream_id;
	SceUChar8 p_std_buffer_scale_and_size[2];
	SceUChar8 ep_map_for_one_stream_id_start_address[4];
	SceUChar8 number_of_EP_entries[4];
} ScePsmf_GroupStream;

typedef struct ScePsmf_SequenceInfo_Static {
	SceUChar8 type;
} ScePsmf_SequenceInfo_Static;

#define SCE_PSMF_ERROR_NO_EP_MAP	0x80615025
#define SCE_PSMF_ERROR_INVALID_ID	0x80615100
#define SCE_PSMF_ERROR_NOT_FOUND	0x80615500
#define SCE_PSMF_ERROR_UNKNOWN_STREAM	0x80000100

#define PSMF_STREAM_SIZE	16

SceUShort16 sceMpegSwap2(SceVoid *p);
SceInt32 scePsmfCheckStreamType_Base(SceUInt32 stream_id, SceUInt32 private_stream_id);
static SceInt32 _GetRelavantEP_map(ScePsmf_EP *pEp_map, SceUInt32 ep_id, SceUInt32 timestamp);

/* scePsmfGetNumberOfEP_entries_Base and scePsmfCheckEP_map_Base, as inlined (-finline-functions)
   into the functions defined after them */

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfSpecifyStream_Base);

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

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetEPWithId_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetEPWithTimestamp_Base);

SceInt32 scePsmfCheckStreamType_Base(SceUInt32 stream_id, SceUInt32 private_stream_id)
{
	if (stream_id >= 0xE0 && stream_id <= 0xEF)
		return 0;
	if (stream_id == 0xBD && private_stream_id < 0x10)
		return 1;
	return SCE_PSMF_ERROR_UNKNOWN_STREAM;
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", _GetRelavantEP_map);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfSpecifyGroupingPeriod_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfSpecifyGroup_Base);

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

SceInt32 scePsmfGetSequenceInfo_Audio_Base(ScePsmf *psmf, ScePsmf_SequenceInfo_Audio *pSInfo_Audio)
{
	ScePsmf_SequenceInfo_Static *s_static;
	SceInt32 ret = 0;
	SceInt32 type;

	type = scePsmfCheckStreamType_Base(((SceUChar8 *)psmf->currentStream)[0], ((SceUChar8 *)psmf->currentStream)[1]);
	s_static = (ScePsmf_SequenceInfo_Static *)((SceUChar8 *)psmf->currentStream + 12);
	if (type == 1) {
		pSInfo_Audio->channel_configuration = ((SceUChar8 *)s_static)[2];
		pSInfo_Audio->sampling_frequency = ((SceUChar8 *)s_static)[3];
	} else {
		ret = SCE_PSMF_ERROR_INVALID_ID;
	}
	return ret;
}

SceInt32 scePsmfCheckEP_map_Base(ScePsmf *psmf)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NO_EP_MAP;
	if (sceMpegSwap4((SceUChar8 *)psmf->currentStream + 8) != 0)
		ret = 0;
	return ret;
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetEP_idWithTimestamp_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetStreamType_Base);
