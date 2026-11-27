#ifndef PSMF_H
#define PSMF_H
/* libpsmf internals (types recovered from DWARF) */
#include <libpsmf.h>

typedef SceInt32 SceMpegStrType;
typedef SceUInt32 SceMpegStreamId;

typedef struct ScePsmf_SequenceInfo_Video {
	SceInt32 horizontal_size;
	SceInt32 vertical_size;
} ScePsmf_SequenceInfo_Video;

typedef struct ScePsmf_SequenceInfo_Audio {
	SceInt32 channel_configuration;
	SceInt32 sampling_frequency;
} ScePsmf_SequenceInfo_Audio;

typedef struct ScePsmf_Header {
	SceUChar8 type_indicator[4];
	SceUChar8 version_number[4];
	SceUChar8 stream_chunk_start_address[4];
	SceUChar8 stream_chunk_size[4];
	SceUChar8 reserved[64];
} ScePsmf_Header;

SceMpegStreamId _sceMpegType2id(SceMpegStrType type, SceInt32 ch);
SceInt32 _sceMpegId2type(SceMpegStrType *type, SceInt32 *ch, SceUInt32 str_id);
SceUInt32 sceMpegSwap4(SceVoid *p);

SceInt32 scePsmfSpecifyStream(ScePsmf *psmf, SceInt32 psmfStream_id);
SceInt32 scePsmfGetPresentationStartTime_Base(ScePsmf *psmf, SceInt32 *start_time);
SceInt32 scePsmfGetPresentationEndTime_Base(ScePsmf *psmf, SceInt32 *end_time);
SceInt32 scePsmfGetMUXRateBound_Base(ScePsmf *psmf);
SceInt32 scePsmfGetStdDelayBound_Base(ScePsmf *psmf);
SceInt32 scePsmfGetNumberOfStreams_Base(ScePsmf *psmf);
SceInt32 scePsmfGetStreamId_Base(ScePsmf *psmf, SceUInt32 *stream_id);
SceInt32 scePsmfGetPrivateStreamId_Base(ScePsmf *psmf, SceUInt32 *private_id);
SceInt32 scePsmfGetNumberOfEP_entries_Base(ScePsmf *psmf);
SceInt32 scePsmfGetSequenceInfo_Video_Base(ScePsmf *psmf, ScePsmf_SequenceInfo_Video *pSInfo_video);
SceInt32 scePsmfGetSequenceInfo_Audio_Base(ScePsmf *psmf, ScePsmf_SequenceInfo_Audio *pSInfo_audio);
SceInt32 scePsmfCheckEP_map_Base(ScePsmf *psmf);
SceInt32 scePsmfGetEPWithId_Base(ScePsmf *psmf, SceInt32 ep_id, ScePsmf_EntryPoint *pEntry);
SceInt32 scePsmfGetEPWithTimestamp_Base(ScePsmf *psmf, SceUInt32 timestamp, ScePsmf_EntryPoint *pEntry);
SceInt32 scePsmfGetEP_idWithTimestamp_Base(ScePsmf *psmf, SceUInt32 timestamp);
SceInt32 scePsmfSpecifyGroupingPeriod_Base(ScePsmf *psmf, SceInt32 gp_id);
SceInt32 scePsmfSpecifyGroup_Base(ScePsmf *psmf, SceInt32 group_id);
SceInt32 scePsmfSpecifyStream_Base(ScePsmf *psmf, SceInt32 psmfStream_id);
SceInt32 scePsmfGetPsmfStreamIdWithStream_Base(ScePsmf *psmf, SceUInt32 s_id, SceUInt32 p_id);
#endif
