/* cflags: -O2 -frename-registers */
#include "common.h"
#include <psptypes.h>
#include <string.h>
#include "psmf.h"

#define SCE_MPEG_ERROR_INVALID_VALUE	0x806101FE
#define SCE_PSMF_ERROR_NOT_INITIALIZED	0x80615001
#define SCE_PSMF_ERROR_BAD_VERSION	0x80615004
#define SCE_PSMF_ERROR_INVALID_PSMF	0x80615501
#define SCE_PSMF_ERROR_INVALID_VALUE	0x806151FE

/* type: version << 4 | 8 (header) | 4 (grouping period) | 2 (group) | 1 (stream) */
#define PSMF_VERSION_OK(type)	((SceUInt32)((type) >> 4) < 3)

static SceInt32 scePsmfSpecifyGroupingPeriod(ScePsmf *psmf, SceInt32 gp_id);
static SceInt32 scePsmfSpecifyGroup(ScePsmf *psmf, SceInt32 group_id);
static SceInt32 scePsmfGetStreamId(ScePsmf *psmf, SceUInt32 *stream_id);
static SceInt32 scePsmfGetPrivateStreamId(ScePsmf *psmf, SceUInt32 *private_id);
static SceInt32 _type_check(ScePsmf_Header *header);
static SceInt32 _version_check(ScePsmf_Header *header);
static SceInt32 _streamId2sceMpegStreamId(SceUInt32 stream_id, SceUInt32 private_id, SceMpegStreamId *str_id);
static SceInt32 scePsmfSpecifyStreamWithId(ScePsmf *psmf, SceUInt32 s_id, SceUInt32 p_id);

SceInt32 scePsmfCreate(ScePsmf *psmf, SceVoid *addr)
{
	SceInt32 ret;

	psmf->type = 0;
	psmf->header = addr;
	ret = _type_check((ScePsmf_Header *)addr);
	if (ret != 0)
		goto error;
	ret = _version_check(psmf->header);
	if (ret < 0)
		goto error;
	psmf->sequenceInfo = (SceUChar8 *)addr + sizeof(ScePsmf_Header);
	psmf->type = (ret << 4) | 0x8;
	if (scePsmfSpecifyGroupingPeriod(psmf, 0) != 0) {
		ret = SCE_PSMF_ERROR_INVALID_PSMF;
		goto error;
	}
	if (scePsmfSpecifyGroup(psmf, 0) != 0) {
		ret = SCE_PSMF_ERROR_INVALID_PSMF;
		goto error;
	}
	if (scePsmfSpecifyStream(psmf, 0) != 0) {
		ret = SCE_PSMF_ERROR_INVALID_PSMF;
		goto error;
	}
	ret = 0;
	goto end;
error:
	psmf->type = 0;
end:
	return ret;
}

SceInt32 scePsmfGetCurrentStreamType(ScePsmf *psmf, SceInt32 *type, SceInt32 *ch)
{
	SceUInt32 stream_id;
	SceUInt32 private_id;
	SceMpegStreamId str_id;
	SceInt32 ret;

	ret = scePsmfGetStreamId(psmf, &stream_id);
	if (ret != 0)
		return ret;
	ret = scePsmfGetPrivateStreamId(psmf, &private_id);
	if (ret != 0)
		return ret;
	_streamId2sceMpegStreamId(stream_id, private_id, &str_id);
	if (_sceMpegId2type(type, ch, str_id) < 0)
		return SCE_PSMF_ERROR_INVALID_VALUE;
	return 0;
}

static SceInt32 scePsmfSpecifyGroupingPeriod(ScePsmf *psmf, SceInt32 gp_id)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if (psmf->type & 0x8) {
		ret = PSMF_VERSION_OK(psmf->type) ? scePsmfSpecifyGroupingPeriod_Base(psmf, gp_id) : SCE_PSMF_ERROR_BAD_VERSION;
		if (ret == 0) {
			psmf->type = (psmf->type >> 2 << 2) | 0x4;
			psmf->groupingPeriod_id = gp_id;
		} else {
			psmf->type = psmf->type >> 3 << 3;
		}
	}
	return ret;
}

static SceInt32 scePsmfSpecifyGroup(ScePsmf *psmf, SceInt32 group_id)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xC) == 0xC) {
		ret = PSMF_VERSION_OK(psmf->type) ? scePsmfSpecifyGroup_Base(psmf, group_id) : SCE_PSMF_ERROR_BAD_VERSION;
		if (ret == 0) {
			psmf->type = (psmf->type >> 1 << 1) | 0x2;
			psmf->group_id = group_id;
		} else {
			psmf->type = psmf->type >> 2 << 2;
		}
	}
	return ret;
}

SceInt32 scePsmfSpecifyStream(ScePsmf *psmf, SceInt32 psmfStream_id)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xE) == 0xE) {
		ret = PSMF_VERSION_OK(psmf->type) ? scePsmfSpecifyStream_Base(psmf, psmfStream_id) : SCE_PSMF_ERROR_BAD_VERSION;
		if (ret == 0) {
			psmf->type = (psmf->type) | 0x1;
			psmf->psmfStream_id = psmfStream_id;
		} else {
			psmf->type = psmf->type >> 1 << 1;
		}
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libpsmf", scePsmfGetPresentationStartTime);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libpsmf", scePsmfGetPresentationEndTime);

SceInt32 scePsmfGetMUXRateBound(ScePsmf *psmf)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if (psmf->type & 0x8) {
		ret = SCE_PSMF_ERROR_BAD_VERSION;
		if (PSMF_VERSION_OK(psmf->type))
			ret = scePsmfGetMUXRateBound_Base(psmf);
	}
	return ret;
}

SceInt32 scePsmfGetStdDelayBound(ScePsmf *psmf)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if (psmf->type & 0x8) {
		ret = SCE_PSMF_ERROR_BAD_VERSION;
		if (PSMF_VERSION_OK(psmf->type))
			ret = scePsmfGetStdDelayBound_Base(psmf);
	}
	return ret;
}

SceInt32 scePsmfGetNumberOfStreams(ScePsmf *psmf)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xE) == 0xE) {
		ret = SCE_PSMF_ERROR_BAD_VERSION;
		if (PSMF_VERSION_OK(psmf->type))
			ret = scePsmfGetNumberOfStreams_Base(psmf);
	}
	return ret;
}

static SceInt32 scePsmfGetStreamId(ScePsmf *psmf, SceUInt32 *stream_id)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if (!((psmf->type & 0xF) == 0xF)) {
		*stream_id = 0;
		return ret;
	}
	return PSMF_VERSION_OK(psmf->type) ? scePsmfGetStreamId_Base(psmf, stream_id) : SCE_PSMF_ERROR_BAD_VERSION;
}

static SceInt32 scePsmfGetPrivateStreamId(ScePsmf *psmf, SceUInt32 *private_id)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if (!((psmf->type & 0xF) == 0xF)) {
		*private_id = 0;
		return ret;
	}
	return PSMF_VERSION_OK(psmf->type) ? scePsmfGetPrivateStreamId_Base(psmf, private_id) : SCE_PSMF_ERROR_BAD_VERSION;
}

SceInt32 scePsmfGetNumberOfEP_entries(ScePsmf *psmf)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xF) == 0xF) {
		ret = SCE_PSMF_ERROR_BAD_VERSION;
		if (PSMF_VERSION_OK(psmf->type))
			ret = scePsmfGetNumberOfEP_entries_Base(psmf);
	}
	return ret;
}

SceInt32 scePsmfGetSequenceInfo_Video(ScePsmf *psmf, ScePsmf_SequenceInfo_Video *pSInfo_video)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xF) == 0xF) {
		ret = SCE_PSMF_ERROR_BAD_VERSION;
		if (PSMF_VERSION_OK(psmf->type))
			ret = scePsmfGetSequenceInfo_Video_Base(psmf, pSInfo_video);
	}
	return ret;
}

SceInt32 scePsmfGetSequenceInfo_Audio(ScePsmf *psmf, ScePsmf_SequenceInfo_Audio *pSInfo_audio)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xF) == 0xF) {
		ret = SCE_PSMF_ERROR_BAD_VERSION;
		if (PSMF_VERSION_OK(psmf->type))
			ret = scePsmfGetSequenceInfo_Audio_Base(psmf, pSInfo_audio);
	}
	return ret;
}

SceInt32 scePsmfCheckEP_map(ScePsmf *psmf)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xF) == 0xF) {
		ret = SCE_PSMF_ERROR_BAD_VERSION;
		if (PSMF_VERSION_OK(psmf->type))
			ret = scePsmfCheckEP_map_Base(psmf);
	}
	return ret;
}

SceInt32 scePsmfGetEPWithId(ScePsmf *psmf, SceInt32 ep_id, ScePsmf_EntryPoint *pEntry)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xF) == 0xF) {
		ret = SCE_PSMF_ERROR_BAD_VERSION;
		if (PSMF_VERSION_OK(psmf->type))
			ret = scePsmfGetEPWithId_Base(psmf, ep_id, pEntry);
	}
	return ret;
}

SceInt32 scePsmfGetEPWithTimestamp(ScePsmf *psmf, SceUInt32 timestamp, ScePsmf_EntryPoint *pEntry)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xF) == 0xF) {
		ret = SCE_PSMF_ERROR_BAD_VERSION;
		if (PSMF_VERSION_OK(psmf->type))
			ret = scePsmfGetEPWithTimestamp_Base(psmf, timestamp, pEntry);
	}
	return ret;
}

SceInt32 scePsmfGetEP_idWithTimestamp(ScePsmf *psmf, SceUInt32 timestamp)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xF) == 0xF) {
		ret = SCE_PSMF_ERROR_BAD_VERSION;
		if (PSMF_VERSION_OK(psmf->type))
			ret = scePsmfGetEP_idWithTimestamp_Base(psmf, timestamp);
	}
	return ret;
}

static SceInt32 _type_check(ScePsmf_Header *header)
{
	if (memcmp(header->type_indicator, "PSMF", 4) != 0)
		return SCE_PSMF_ERROR_INVALID_PSMF;
	return 0;
}

static SceInt32 _version_check(ScePsmf_Header *header)
{
	SceInt32 ret;

	if (memcmp(header->version_number, "0012", 4) == 0)
		ret = 0;
	else if (memcmp(header->version_number, "0013", 4) == 0)
		ret = 1;
	else if (memcmp(header->version_number, "0014", 4) == 0)
		ret = 2;
	else
		ret = SCE_PSMF_ERROR_BAD_VERSION;
	return ret;
}

static SceInt32 _streamId2sceMpegStreamId(SceUInt32 stream_id, SceUInt32 private_id, SceMpegStreamId *str_id)
{
	*str_id = (stream_id << 24) + (private_id << 16);
	return 0;
}

SceInt32 scePsmfQueryStreamOffset(const SceVoid *addr, SceUInt32 *offset)
{
	ScePsmf_Header *header = (ScePsmf_Header *)addr;
	SceInt32 ret;

	ret = _type_check(header);
	if (ret != 0)
		goto error;
	ret = _version_check(header);
	if (ret < 0)
		goto error;
	*offset = sceMpegSwap4(header->stream_chunk_start_address);
	if ((*offset & 0x7FF) == 0 && *offset != 0)
		return 0;
	ret = SCE_PSMF_ERROR_INVALID_VALUE;
error:
	*offset = 0;
	return ret;
}

SceInt32 scePsmfStartEntry(void)
{
	return 0;
}

SceInt32 scePsmfGetCurrentPsmfStreamId(ScePsmf *psmf)
{
	SceInt32 ret;

	ret = SCE_PSMF_ERROR_NOT_INITIALIZED;
	if ((psmf->type & 0xF) == 0xF)
		ret = psmf->psmfStream_id;
	return ret;
}

SceInt32 scePsmfSpecifyStreamWithStreamType(ScePsmf *psmf, SceInt32 type, SceInt32 ch)
{
	SceMpegStreamId str_id;

	str_id = _sceMpegType2id(type, ch);
	if (str_id == SCE_MPEG_ERROR_INVALID_VALUE)
		return SCE_PSMF_ERROR_INVALID_VALUE;
	return scePsmfSpecifyStreamWithId(psmf, str_id >> 24, (str_id >> 16) & 0xFF);
}

SceInt32 scePsmfQueryStreamSize(const SceVoid *addr, SceUInt32 *stream_size)
{
	ScePsmf_Header *header = (ScePsmf_Header *)addr;
	SceInt32 ret;

	ret = 0;
	*stream_size = sceMpegSwap4(header->stream_chunk_size);
	if (*stream_size & 0x7FF) {
		*stream_size = 0;
		ret = SCE_PSMF_ERROR_INVALID_VALUE;
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/libpsmf", scePsmfSpecifyStreamWithId);
