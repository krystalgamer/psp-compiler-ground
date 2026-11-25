#ifndef SOUND_H
#define SOUND_H
/* types recovered from DWARF */
typedef struct t_soundBuffer {
	SceUID lock_sema;
	SceInt32 *terminate_flag;
	SceChar8 **buf;
	SceUInt32 *pts;
	SceInt32 *write;
	SceInt32 *read;
	SceInt32 *count;
	SceInt32 *size;
	SceUID start_sema;
} t_soundBuffer;

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
SceInt32 soundbuf_setStartFlag(t_soundBuffer *pSound);
SceInt32 soundbuf_func(SceSize size, void *argp);
SceInt32 soundbuf_output(t_soundBuffer *pSound);
#endif
