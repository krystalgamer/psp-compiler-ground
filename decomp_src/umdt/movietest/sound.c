/* cflags: -O0 */
#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread.h>
#include <libwave.h>
#include "display.h"
#include "sound.h"
#include "avsync.h"

extern SceInt32 sound_terminate_flag;
extern SceInt32 sound_write;
extern SceInt32 sound_read;
extern SceInt32 sound_count;
extern SceInt32 sound_size;
extern int soundframe_count;
extern int soundframe_delay;
extern int soundLatestPts;

static SceInt32 soundbuf_isEnd(t_soundBuffer *pSound);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/sound", soundbuf_create);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/sound", soundbuf_init);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/sound", soundbuf_end);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/sound", soundbuf_getDrawbuf);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/sound", soundbuf_setBuf);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/sound", soundbuf_getCapacity);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/sound", soundbuf_getCurrentCount);

SceInt32 soundbuf_setDemuxEnd(t_soundBuffer *pSound)
{
	*pSound->terminate_flag = 1;
	return 0;
}

static SceInt32 soundbuf_isEnd(t_soundBuffer *pSound)
{
	return *pSound->terminate_flag;
}

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/sound", soundbuf_func);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/sound", soundbuf_output);
