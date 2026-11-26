#include "common.h"

/* declarations recovered from DWARF (UTST99261 BOOT mpeg/display) */
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
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
typedef unsigned int SceSize;
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
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

extern SceInt32 display_write;
extern SceInt32 display_read;
extern SceInt32 display_count;
extern SceInt32 display_size;
extern SceInt32 display_mode;
extern SceInt32 frame_count;
extern SceInt32 frame_loss;

SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num);
SceInt32 dispbuf_init(t_displayBuffer *pDisp);
SceInt32 dispbuf_end(t_displayBuffer *pDisp);
SceInt32 dispbuf_getDrawbuf(t_displayBuffer *pDisp, SceChar8 **buffer);
SceInt32 dispbuf_setPts(t_displayBuffer *pDisp, SceUInt32 pts);
SceInt32 dispbuf_getPts(t_displayBuffer *pDisp, SceUInt32 *pPts);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp);
SceInt32 dispbuf_getCapacity(t_displayBuffer *pDisp);
SceInt32 dispbuf_getCurrentCount(t_displayBuffer *pDisp);
static SceInt32 dispbuf_isEnd(t_displayBuffer *pDisp);
SceInt32 dispbuf_setMode(t_displayBuffer *pDisp, SceInt32 mode);
SceInt32 dispbuf_getMode(t_displayBuffer *pDisp);
SceInt32 display_func(SceSize size, void *argp);
SceInt32 dispbuf_decode_sleep(t_displayBuffer *pDisp);
SceInt32 dispbuf_setStartFlag(t_displayBuffer *pDisp);
SceInt32 dispbuf_show(t_displayBuffer *pDisp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", swap_buffer);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_create);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_reset);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_delete);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_getDrawbuf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_setPts);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_getPts);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_dataSet);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_getCapacity);

int dispbuf_getCurrentCount(t_displayBuffer *pDisp) {
    return pDisp->count;
}

int dispbuf_setMode(t_displayBuffer *pDisp, int mode) {
    pDisp->displayMode = mode;
    return 0;
}

int dispbuf_getMode(t_displayBuffer *pDisp) {
    return pDisp->displayMode;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_display);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_show);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", D_0007AF20);
