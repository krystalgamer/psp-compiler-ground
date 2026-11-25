#ifndef _LIBPSMF_H
#define _LIBPSMF_H
/* types recovered from DWARF; prototypes as used by the decompiled code */
#include <psptypes.h>
typedef struct ScePsmf {
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
} ScePsmf;
typedef struct ScePsmf_EntryPoint {
	SceUInt32 PTS_EP_start;
	SceUInt32 EP_start_offset;
} ScePsmf_EntryPoint;
SceInt32 scePsmfCreate(ScePsmf *psmf, SceVoid *pHeader);
SceInt32 scePsmfGetEP_idWithTimestamp(ScePsmf *psmf, SceUInt32 pts);
SceInt32 scePsmfGetEPWithId(ScePsmf *psmf, SceInt32 ep_id, ScePsmf_EntryPoint *ep);
#endif
