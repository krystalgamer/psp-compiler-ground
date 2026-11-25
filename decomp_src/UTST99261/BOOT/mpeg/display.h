#ifndef DISPLAY_H
#define DISPLAY_H
/* types recovered from DWARF */
typedef struct t_displayBuffer {
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
} t_displayBuffer;

SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num);
SceInt32 dispbuf_init(t_displayBuffer *pDisp);
SceInt32 dispbuf_end(t_displayBuffer *pDisp);
SceInt32 dispbuf_getDrawbuf(t_displayBuffer *pDisp, SceChar8 **buffer);
SceInt32 dispbuf_setPts(t_displayBuffer *pDisp, SceUInt32 pts);
SceInt32 dispbuf_getPts(t_displayBuffer *pDisp, SceUInt32 *pPts);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp);
SceInt32 dispbuf_getCapacity(t_displayBuffer *pDisp);
SceInt32 dispbuf_getCurrentCount(t_displayBuffer *pDisp);
SceInt32 dispbuf_setMode(t_displayBuffer *pDisp, SceInt32 mode);
SceInt32 dispbuf_getMode(t_displayBuffer *pDisp);
SceInt32 display_func(SceSize size, void *argp);
SceInt32 dispbuf_decode_sleep(t_displayBuffer *pDisp);
SceInt32 dispbuf_setStartFlag(t_displayBuffer *pDisp);
SceInt32 dispbuf_show(t_displayBuffer *pDisp);
#endif
