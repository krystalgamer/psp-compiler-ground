#include "common.h"

typedef struct ScePsmf ScePsmf;
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
typedef unsigned int SceUInt32;
typedef float SceFloat;
typedef struct ScePsmfEntryPoint ScePsmfEntryPoint;
struct ScePsmfEntryPoint;
struct ScePsmfEntryPoint { /* size 0x8 */
    SceUInt32 pts;
    SceUInt32 offset;
};



SceInt32 changePsmfTimestamp(ScePsmf *pPsmf, SceUInt32 timestamp, SceUInt32 *psmfTimestamp);
SceInt32 getPlayTime(ScePsmf *pPsmf, SceUInt32 *totalTime);
SceInt32 getEPOffset(ScePsmf *pPsmf, SceInt32 timestamp, SceInt32 *offset);
int printf(const char *fmt, ...);
int scePsmfGetEPWithTimestamp(ScePsmf *psmf, SceUInt32 ts, ScePsmfEntryPoint *ep);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/parsePsmf", D_00010790);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/parsePsmf", D_000107C8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/parsePsmf", D_000107FC);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/parsePsmf", changePsmfTimestamp);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/parsePsmf", getPlayTime);

extern const char D_000107FC[]; /* "fatal error : scePsmfGetEPWithTimestamp() 0x%x\n", shared with an asm function */

SceInt32 getEPOffset(ScePsmf *pPsmf, SceInt32 timestamp, SceInt32 *offset)
{
	SceInt32 ret;
	SceUInt32 psmfTime;
	ScePsmfEntryPoint ep;

	ret = changePsmfTimestamp(pPsmf, timestamp, &psmfTime);
	if (ret != 0) {
		goto term;
	}

	ret = scePsmfGetEPWithTimestamp(pPsmf, psmfTime, &ep);
	if (ret != 0) {
		printf(D_000107FC, ret);
		goto term;
	}

	*offset = ep.offset;

term:
	return ret;
}
