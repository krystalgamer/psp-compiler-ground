#include "common.h"

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfCreate);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetCurrentStreamType);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfSpecifyGroupingPeriod);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfSpecifyGroup);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfSpecifyStream);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetPresentationStartTime);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetPresentationEndTime);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetMUXRateBound);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetStdDelayBound);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetNumberOfStreams);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetStreamId);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetPrivateStreamId);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetNumberOfEP_entries);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetSequenceInfo_Video);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetSequenceInfo_Audio);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfCheckEP_map);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetEPWithId);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetEPWithTimestamp);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetEP_idWithTimestamp);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", _type_check);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", _version_check);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", _streamId2sceMpegStreamId);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfQueryStreamOffset);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfStartEntry);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfGetCurrentPsmfStreamId);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfSpecifyStreamWithStreamType);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfQueryStreamSize);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libpsmf", scePsmfSpecifyStreamWithId);
