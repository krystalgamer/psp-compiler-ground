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
typedef struct ScePsmf_EntryPoint ScePsmf_EntryPoint;
struct ScePsmf_EntryPoint;
struct ScePsmf_EntryPoint { /* size 0x8 */
    SceUInt32 PTS_EP_start;
    SceUInt32 EP_start_offset;
};
typedef struct ScePsmf_Header ScePsmf_Header;
struct ScePsmf_Header;
typedef unsigned char SceUChar8;
struct ScePsmf_Header { /* size 0x50 */
    SceUChar8 type_indicator[4];
    SceUChar8 version_number[4];
    SceUChar8 stream_chunk_start_address[4];
    SceUChar8 stream_chunk_size[4];
    SceUChar8 reserved[64];
};
typedef SceUInt32 SceMpegStreamId;



SceInt32 scePsmfCreate(ScePsmf *psmf, SceVoid *addr);
SceInt32 scePsmfGetCurrentStreamType(ScePsmf *psmf, SceInt32 *type, SceInt32 *ch);
static SceInt32 scePsmfSpecifyGroupingPeriod(ScePsmf *psmf, SceInt32 gp_id);
static SceInt32 scePsmfSpecifyGroup(ScePsmf *psmf, SceInt32 group_id);
SceInt32 scePsmfSpecifyStream(ScePsmf *psmf, SceInt32 psmfStream_id);
SceInt32 scePsmfGetPresentationStartTime(ScePsmf *psmf, SceUInt32 *start_time);
SceInt32 scePsmfGetPresentationEndTime(ScePsmf *psmf, SceUInt32 *end_time);
SceInt32 scePsmfGetMUXRateBound(ScePsmf *psmf);
SceInt32 scePsmfGetStdDelayBound(ScePsmf *psmf);
SceInt32 scePsmfGetNumberOfStreams(ScePsmf *psmf);
static SceInt32 scePsmfGetStreamId(ScePsmf *psmf, SceUInt32 *stream_id);
static SceInt32 scePsmfGetPrivateStreamId(ScePsmf *psmf, SceUInt32 *private_id);
SceInt32 scePsmfGetNumberOfEP_entries(ScePsmf *psmf);
SceInt32 scePsmfGetSequenceInfo_Video(ScePsmf *psmf, ScePsmf_SequenceInfo_Video *pSInfo_video);
SceInt32 scePsmfGetSequenceInfo_Audio(ScePsmf *psmf, ScePsmf_SequenceInfo_Audio *pSInfo_audio);
SceInt32 scePsmfCheckEP_map(ScePsmf *psmf);
SceInt32 scePsmfGetEPWithId(ScePsmf *psmf, SceInt32 ep_id, ScePsmf_EntryPoint *pEntry);
SceInt32 scePsmfGetEPWithTimestamp(ScePsmf *psmf, SceUInt32 timestamp, ScePsmf_EntryPoint *pEntry);
SceInt32 scePsmfGetEP_idWithTimestamp(ScePsmf *psmf, SceUInt32 timestamp);
static SceInt32 _type_check(ScePsmf_Header *header);
static SceInt32 _version_check(ScePsmf_Header *header);
static SceInt32 _streamId2sceMpegStreamId(SceUInt32 stream_id, SceUInt32 private_id, SceMpegStreamId *str_id);
SceInt32 scePsmfQueryStreamOffset(const SceVoid *addr, SceUInt32 *offset);
SceInt32 scePsmfStartEntry(void);
SceInt32 scePsmfGetCurrentPsmfStreamId(ScePsmf *psmf);
SceInt32 scePsmfSpecifyStreamWithStreamType(ScePsmf *psmf, SceInt32 type, SceInt32 ch);
SceInt32 scePsmfQueryStreamSize(const SceVoid *addr, SceUInt32 *stream_size);
static SceInt32 scePsmfSpecifyStreamWithId(ScePsmf *psmf, SceUInt32 s_id, SceUInt32 p_id);


INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfCreate);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetCurrentStreamType);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfSpecifyGroupingPeriod);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfSpecifyGroup);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfSpecifyStream);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetPresentationStartTime);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetPresentationEndTime);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetMUXRateBound);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetStdDelayBound);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetNumberOfStreams);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetStreamId);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetPrivateStreamId);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetNumberOfEP_entries);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetSequenceInfo_Video);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetSequenceInfo_Audio);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfCheckEP_map);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetEPWithId);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetEPWithTimestamp);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetEP_idWithTimestamp);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", _type_check);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", _version_check);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", _streamId2sceMpegStreamId);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfQueryStreamOffset);

SceInt32 scePsmfStartEntry(void)
{
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfGetCurrentPsmfStreamId);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfSpecifyStreamWithStreamType);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfQueryStreamSize);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libpsmf", scePsmfSpecifyStreamWithId);
