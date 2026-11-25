#ifndef AT3PLUS_H
#define AT3PLUS_H
typedef struct {
	SceInt32 atracId;
	SceInt32 fd;
	SceInt32 outputChannel;
} ScePlayArg;

SceInt32 init_atrac3plus(SceChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 ioutputChannel, ScePlayArg *pPlayArg);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
void at3plus_setfade(int fade);
void at3plus_finish(void);
#endif
