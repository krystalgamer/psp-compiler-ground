#include "common.h"

/* declarations recovered from DWARF (UTST99261 BOOT mpeg/sound) */
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
typedef int SceUID;
typedef int SceInt32;
typedef char SceChar8;
typedef unsigned int SceUInt32;
struct t_soundBuffer { /* size 0x24 */
    SceUID lock_sema;
    SceInt32 *terminate_flag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 *write;
    SceInt32 *read;
    SceInt32 *count;
    SceInt32 *size;
    SceUID start_sema;
};
typedef unsigned int SceSize;
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
struct t_displayBuffer { /* size 0x28 */
    SceUID start_sema;
    SceUID lock_sema;
    SceUID display_wait_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 *write;
    SceInt32 *read;
    SceInt32 *count;
    SceInt32 *size;
    SceInt32 *displayMode;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x14 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
};
struct t_avSyncControl { /* size 0x1c */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};

extern SceInt32 sound_terminate_flag;
extern SceInt32 sound_write;
extern SceInt32 sound_read;
extern SceInt32 sound_count;
extern SceInt32 sound_size;
extern int soundframe_count;
extern int soundframe_delay;
extern int soundLatestPts;

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 buf_size, SceInt32 buf_num);
SceInt32 soundbuf_init(t_soundBuffer *pSound);
SceInt32 soundbuf_end(t_soundBuffer *pSound);
SceInt32 soundbuf_getDrawbuf(t_soundBuffer *pSound, SceChar8 **buffer);
SceInt32 soundbuf_setPts(t_soundBuffer *pSound, SceUInt32 pts);
SceInt32 soundbuf_getPts(t_soundBuffer *pSound, SceUInt32 *pPts);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound);
SceInt32 soundbuf_getCapacity(t_soundBuffer *pSound);
SceInt32 soundbuf_getCurrentCount(t_soundBuffer *pSound);
SceInt32 soundbuf_setDemuxEnd(t_soundBuffer *pSound);
static SceInt32 soundbuf_isEnd(t_soundBuffer *pSound);
SceInt32 soundbuf_setStartFlag(t_soundBuffer *pSound);
SceInt32 soundbuf_func(SceSize size, void *argp);
SceInt32 soundbuf_output(t_soundBuffer *pSound);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_create);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_reset);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_delete);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_getDrawbuf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_setPts);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_getPts);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_setBuf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_getCapacity);

int soundbuf_getCurrentCount(t_soundBuffer *pSound) {
    return pSound->count;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_setDemuxEnd);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_getStatus);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_checkDemuxEnd);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_setStartFlag);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_func);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_swapbuf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_output);
