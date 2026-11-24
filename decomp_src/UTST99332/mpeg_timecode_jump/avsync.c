#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_create);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_reset);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_delete);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_init_video);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_setStartPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_setVideoStartPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_video_getLatestPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_video_setPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_video_getPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_Compare);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_video_createNextPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_sound_createNextPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_video_getAuTimestamp);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/avsync", avsync_sound_getAuTimestamp);
