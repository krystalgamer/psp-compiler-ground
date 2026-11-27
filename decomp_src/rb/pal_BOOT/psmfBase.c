#include "common.h"

/* declarations recovered from DWARF */
typedef struct ScePsmf ScePsmf;
struct ScePsmf;
typedef int SceInt32;
typedef void SceVoid;
struct ScePsmf { /* size 0x28 */
    SceInt32 type;
    SceInt32 groupingPeriod_id;
    SceInt32 group_id;
    SceInt32 psmfStream_id;
    SceVoid *header;
    SceVoid *sequenceInfo;
    SceVoid *currentGroupingPeriod;
    SceVoid *currentGroup;
    SceVoid *currentStream;
    SceVoid *currentEP_map;
};
typedef unsigned int SceUInt32;
typedef struct ScePsmf_EntryPoint ScePsmf_EntryPoint;
struct ScePsmf_EntryPoint;
struct ScePsmf_EntryPoint { /* size 0x8 */
    SceUInt32 PTS_EP_start;
    SceUInt32 EP_start_offset;
};
typedef struct ScePsmf_EP ScePsmf_EP;
struct ScePsmf_EP;
typedef unsigned char SceUChar8;
struct ScePsmf_EP { /* size 0xa */
    SceUChar8 picture_copy_and_msb_pts_start[2];
    SceUChar8 pts_ep_start[4];
    SceUChar8 rpn_ep_start[4];
};
typedef struct ScePsmf_GroupingPeriod ScePsmf_GroupingPeriod;
struct ScePsmf_GroupingPeriod;
struct ScePsmf_GroupingPeriod { /* size 0x12 */
    SceUChar8 length_grouping_period[4];
    SceUChar8 msb_groupingperiod_start_time[2];
    SceUChar8 groupingperiod_start_time[4];
    SceUChar8 msb_groupingperiod_end_time[2];
    SceUChar8 groupingperiod_end_time[4];
    SceUChar8 reserved;
    SceUChar8 number_of_groups;
};
typedef struct ScePsmf_Group ScePsmf_Group;
struct ScePsmf_Group;
struct ScePsmf_Group { /* size 0x6 */
    SceUChar8 length_group[4];
    SceUChar8 reserved;
    SceUChar8 number_of_streams;
};
typedef struct ScePsmf_SequenceInfo_Video ScePsmf_SequenceInfo_Video;
struct ScePsmf_SequenceInfo_Video;
struct ScePsmf_SequenceInfo_Video { /* size 0x8 */
    SceInt32 horizontal_size;
    SceInt32 vertical_size;
};
typedef struct ScePsmf_SequenceInfo_Audio ScePsmf_SequenceInfo_Audio;
struct ScePsmf_SequenceInfo_Audio;
struct ScePsmf_SequenceInfo_Audio { /* size 0x8 */
    SceInt32 channel_configuration;
    SceInt32 sampling_frequency;
};



SceInt32 scePsmfSpecifyStream_Base(ScePsmf *psmf, SceInt32 psmfStream_id);
SceInt32 scePsmfGetPsmfStreamIdWithStream_Base(ScePsmf *psmf, SceUInt32 s_id, SceUInt32 p_id);
SceInt32 scePsmfGetEPWithId_Base(ScePsmf *psmf, SceInt32 ep_id, ScePsmf_EntryPoint *pEntry);
SceInt32 scePsmfCheckEP_map_Base(ScePsmf *psmf);
SceInt32 scePsmfGetNumberOfEP_entries_Base(ScePsmf *psmf);
SceInt32 scePsmfGetEPWithTimestamp_Base(ScePsmf *psmf, SceUInt32 timestamp, ScePsmf_EntryPoint *pEntry);
SceInt32 scePsmfCheckStreamType_Base(SceUInt32 stream_id, SceUInt32 private_stream_id);
static SceInt32 _GetRelavantEP_map(ScePsmf_EP *pEp_map, SceUInt32 ep_id, SceUInt32 timestamp);
SceInt32 scePsmfBaseStartEntry(void);
SceInt32 scePsmfSpecifyGroupingPeriod_Base(ScePsmf *psmf, SceInt32 gp_id);
static SceUInt32 _getOffset_GroupingPeriod(ScePsmf_GroupingPeriod *pGroupPeriod, SceInt32 gp_id);
SceInt32 scePsmfSpecifyGroup_Base(ScePsmf *psmf, SceInt32 group_id);
static SceUInt32 _getOffset_Group(ScePsmf_Group *pGroup, SceInt32 group_id);
SceInt32 scePsmfGetNumberOfTotalStream_Base(ScePsmf *psmf);
SceInt32 scePsmfGetNumberOfGroupingPeriod_Base(ScePsmf *psmf);
SceInt32 scePsmfGetPresentationStartTime_Base(ScePsmf *psmf, SceInt32 *start_time);
SceInt32 scePsmfGetPresentationEndTime_Base(ScePsmf *psmf, SceInt32 *end_time);
SceInt32 scePsmfGetMUXRateBound_Base(ScePsmf *psmf);
SceInt32 scePsmfGetStdDelayBound_Base(ScePsmf *psmf);
SceInt32 scePsmfGetPresentationStartTime_GP_Base(ScePsmf *psmf, SceUInt32 *start_timestamp);
SceInt32 scePsmfGetPresentationEndTime_GP_Base(ScePsmf *psmf, SceUInt32 *end_timestamp);
SceInt32 scePsmfGetNumberOfGroups_Base(ScePsmf *psmf);
SceInt32 scePsmfGetNumberOfStreams_Base(ScePsmf *psmf);
SceInt32 scePsmfGetStreamId_Base(ScePsmf *psmf, SceUInt32 *stream_id);
SceInt32 scePsmfGetPrivateStreamId_Base(ScePsmf *psmf, SceUInt32 *private_id);
SceInt32 scePsmfGetP_STD_buffer_scale_Base(ScePsmf *psmf);
SceInt32 scePsmfGetP_STD_buffer_size_Base(ScePsmf *psmf);
SceInt32 scePsmfGetSequenceInfo_Video_Base(ScePsmf *psmf, ScePsmf_SequenceInfo_Video *pSInfo_Video);
SceInt32 scePsmfGetSequenceInfo_Audio_Base(ScePsmf *psmf, ScePsmf_SequenceInfo_Audio *pSInfo_Audio);
SceInt32 scePsmfGetEP_idWithTimestamp_Base(ScePsmf *psmf, SceUInt32 timestamp);
SceInt32 scePsmfGetStreamType_Base(ScePsmf *psmf, SceInt32 psmfStream_id);


INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfSpecifyStream_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetPsmfStreamIdWithStream_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetEPWithId_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetEPWithTimestamp_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfCheckStreamType_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", _GetRelavantEP_map);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfSpecifyGroupingPeriod_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfSpecifyGroup_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetNumberOfTotalStream_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetNumberOfGroupingPeriod_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetPresentationStartTime_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetPresentationEndTime_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetMUXRateBound_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetStdDelayBound_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetPresentationStartTime_GP_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetPresentationEndTime_GP_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetNumberOfGroups_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetNumberOfStreams_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetStreamId_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetPrivateStreamId_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetP_STD_buffer_scale_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetP_STD_buffer_size_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetNumberOfEP_entries_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetSequenceInfo_Video_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetSequenceInfo_Audio_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfCheckEP_map_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetEP_idWithTimestamp_Base);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/psmfBase", scePsmfGetStreamType_Base);
